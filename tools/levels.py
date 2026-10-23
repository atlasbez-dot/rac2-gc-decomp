#!/usr/bin/env python3
"""
The game's programs from the disc image, and the catalogue of their functions.

  python3 tools/levels.py dump        # baserom/SCUS_972.68 and baserom/levels/NN_name/ (local)
  python3 tools/levels.py catalogue   # config/levels/functions.tsv

`dump` reads baserom/SCUS_972.68.iso (USA v1.01) and writes the boot executable
to baserom/SCUS_972.68 and each level's program to baserom/levels/<NN_name>/, one
file per section plus manifest.json with their addresses. All of it is game data:
baserom/ is never committed.

A level's program is in its archive G/LEVELn.WAD: the word pair at +0x10 of the
archive's header gives the level data (sector offset, sector count); the data
opens with twelve (offset, size) slots, and slot 0 is the program, a list of
sections, each a 16-byte record (destination, size, type, entry point) followed by
its bytes (a NOBITS section's too). Every section of one program repeats the entry point; the list ends
where it changes (docs/LEVELS.md).

`catalogue` deduplicates the functions of the 27 programs against each other and
against the boot executable, comparing instructions with only their address
fields masked (identity()). Every distinct function gets one name:

  - a function the boot executable has keeps the boot's name (func_XXXXXXXX);
  - any other gets func_LNN_XXXXXXXX: its address in the lowest-numbered level
    that has it.

The catalogue holds names, sizes, fingerprints and addresses, never bytes, so it
is tracked.
"""
import gzip
import hashlib
import json
import os
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent

# The three releases (docs/VERSIONS.md). "us" (USA v1.01) is the primary target: its paths are
# the repository's original ones. The others keep their dumps, tables, build and report under
# a directory of their own, and their own C under src/<version>/.
VERSIONS = {
    "us": {"id": "SCUS_972.68", "iso": "baserom/SCUS_972.68.iso", "boot": "SCUS_972.68",
           "baserom": "baserom", "config": "config", "build": "build", "report": "progress/report.json",
           "tag": "", "release": "USA v1.01"},
    "pal": {"id": "SCES_516.07", "iso": "baserom/SCES_516.07.iso", "boot": "SCES_516.07",
            "baserom": "baserom/pal", "config": "config/pal", "build": "build/pal",
            "report": "progress/pal/report.json", "tag": "PAL", "release": "Europe/Australia v1.00"},
    "us2": {"id": "SCUS_972.68_v2", "iso": "baserom/SCUS_972.68_v2.00.iso", "boot": "SCUS_972.68",
            "baserom": "baserom/us2", "config": "config/us2", "build": "build/us2",
            "report": "progress/us2/report.json", "tag": "US2", "release": "USA v2.00 (Greatest Hits)"},
}
VERSION = "us"


def select(version: str) -> None:
    """Point the module's paths and constants at VERSION's disc, dumps and tables."""
    global VERSION, ISO, BOOT, DUMP, LEVELS, CATALOGUE, BOOT_FUNCTIONS, BOOT_PAIRS, LEVEL_BASE, GP
    if version not in VERSIONS:
        sys.exit(f"unknown version {version!r}: one of {', '.join(VERSIONS)}")
    v = VERSIONS[version]
    VERSION = version
    ISO = ROOT / v["iso"]
    BOOT = ROOT / v["baserom"] / v["boot"]
    DUMP = ROOT / v["baserom"] / "levels"
    LEVELS = ROOT / v["config"] / "levels"
    CATALOGUE = LEVELS / "functions.tsv"
    BOOT_FUNCTIONS = ROOT / v["config"] / "boot/functions.tsv"
    BOOT_PAIRS = LEVELS / "boot_pairs.tsv"
    LEVEL_BASE = LAYOUT[version]["level_base"]
    GP = LAYOUT[version]["gp"]
    os.environ["RAC2_VERSION"] = version


def version_argument(argv: list[str] | None = None) -> str:
    """Take `--version V` (or `--version=V`) out of ARGV (sys.argv by default) and select V;
    without it, $RAC2_VERSION or "us"."""
    argv = sys.argv if argv is None else argv
    version = os.environ.get("RAC2_VERSION", "us")
    for i, arg in enumerate(list(argv)):
        if arg == "--version" and i + 1 < len(argv):
            version = argv[i + 1]
            del argv[i:i + 2]
            break
        if arg.startswith("--version="):
            version = arg.split("=", 1)[1]
            del argv[i]
            break
    select(version)
    return version


def build_dir() -> Path:
    return ROOT / VERSIONS[VERSION]["build"]
SECTION_NAMES = ("lit", "bss", "data", "vtbl", "camvtbl", "sndvtbl", "text")

# The 27 levels: disc level number -> name.
NAMES = {
    0: "aranos_tutorial", 1: "oozla", 2: "maktar_nebula", 3: "endako", 4: "barlow",
    5: "feltzin_system", 6: "notak", 7: "siberius", 8: "tabora", 9: "dobbo",
    10: "hrugis_cloud", 11: "joba", 12: "todano", 13: "boldan", 14: "aranos_prison",
    15: "gorn", 16: "snivelak", 17: "smolg", 18: "damosel", 19: "grelbin", 20: "yeedil",
    22: "dobbo_orbit", 23: "damosel_orbit", 24: "ship_shack", 25: "wupash_nebula",
    26: "jamming_array", 30: "insomniac_museum",
}


def level_dir(number: int) -> str:
    return f"{number:02d}_{NAMES[number]}"


class Iso:
    """Just enough ISO9660 to find files by path."""

    def __init__(self, path: Path):
        self.f = open(path, "rb")

    def read(self, lba: int, size: int, offset: int = 0) -> bytes:
        self.f.seek(lba * 2048 + offset)
        return self.f.read(size)

    def entries(self, lba: int, size: int) -> dict[str, tuple[int, int]]:
        d = self.read(lba, size)
        out, i = {}, 0
        while i < len(d):
            if d[i] == 0:
                i = (i // 2048 + 1) * 2048
                continue
            at, length = struct.unpack_from("<I", d, i + 2)[0], struct.unpack_from("<I", d, i + 10)[0]
            name = d[i + 33:i + 33 + d[i + 32]].decode("latin1").split(";")[0]
            out[name] = (at, length)
            i += d[i]
        return out

    def find(self, path: str) -> tuple[int, int]:
        pvd = self.read(16, 2048)
        at, length = struct.unpack_from("<I", pvd, 158)[0], struct.unpack_from("<I", pvd, 166)[0]
        for part in path.split("/"):
            at, length = self.entries(at, length)[part]
        return at, length


def archives(iso: Iso) -> dict[int, int]:
    """level number -> LBA of its archive. The number is the archive's own (+0x08); it is
    the file's except for G/LEVEL21.WAD, which holds level 30."""
    out = {}
    for n in range(len(NAMES)):
        lba, _ = iso.find(f"G/LEVEL{n}.WAD")
        out[struct.unpack_from("<I", iso.read(lba, 16), 8)[0]] = lba
    if sorted(out) != sorted(NAMES):
        sys.exit(f"unexpected level numbers {sorted(out)}")
    return out


def program(iso: Iso, lba: int) -> dict:
    """The program in the level archive at LBA: {"entry", "sections": [{name, address, size,
    type, data}], "raw": the program's bytes as the archive stores them}."""
    head = iso.read(lba, 0x60)
    data_sector, _ = struct.unpack_from("<II", head, 0x10)
    slots = iso.read(lba, 0x60, data_sector * 2048)
    start = at = data_sector * 2048 + struct.unpack_from("<I", slots, 0)[0]
    sections, entry = [], None
    while True:
        dest, size, kind, ep = struct.unpack("<4I", iso.read(lba, 16, at))
        if entry is None:
            entry = ep
        if ep != entry or len(sections) == len(SECTION_NAMES):
            break
        # A NOBITS section (.bss) still has its bytes in the archive.
        body = iso.read(lba, size, at + 16)
        sections.append({"name": SECTION_NAMES[len(sections)], "address": dest, "size": size,
                         "type": kind, "data": body})
        at += 16 + size
    if len(sections) != len(SECTION_NAMES):
        sys.exit(f"archive at {lba}: {len(sections)} sections, expected {len(SECTION_NAMES)}")
    return {"entry": entry, "sections": sections, "raw": iso.read(lba, at - start, start)}


def pack_program(directory: Path) -> bytes:
    """A dumped level (manifest.json and its sections' files) in the archive's format again:
    the bytes `dump` checks against the disc. A .bss has no file: its bytes are zero."""
    m = json.loads((directory / "manifest.json").read_text())
    out = b""
    for s in m["sections"]:
        body = (directory / f"{s['name']}.bin").read_bytes() if s["type"] != 8 else bytes(s["size"])
        out += struct.pack("<4I", s["address"], s["size"], s["type"], m["entry"]) + body
    return out


PROGRAMS = ROOT / "config/programs.tsv"


def read_programs() -> dict[tuple[str, str], tuple[str, int, int]]:
    """(version, program) -> (SHA-1 as the disc stores it, size, entry point)."""
    out = {}
    if PROGRAMS.is_file():
        for line in PROGRAMS.read_text().splitlines():
            if line and not line.startswith("#"):
                version, prog, sha1, size, entry = line.split("\t")
                out[(version, prog)] = (sha1, int(size), int(entry, 16))
    return out


def dump() -> None:
    """Write the boot executable and every level's program of the selected version, check
    that each level converts back to the bytes the disc stores, and record their SHA-1s in
    config/programs.tsv (or, with --check, compare them with the recorded ones)."""
    iso = Iso(ISO)
    lba, size = iso.find(VERSIONS[VERSION]["boot"])
    boot = iso.read(lba, size)
    BOOT.parent.mkdir(parents=True, exist_ok=True)
    BOOT.write_bytes(boot)
    rows = {"boot": (hashlib.sha1(boot).hexdigest(), len(boot), struct.unpack_from("<I", boot, 0x18)[0])}
    for number, at in sorted(archives(iso).items()):
        p = program(iso, at)
        d = DUMP / level_dir(number)
        d.mkdir(parents=True, exist_ok=True)
        manifest = {"level": number, "name": NAMES[number], "entry": p["entry"], "sections": []}
        for s in p["sections"]:
            if s["type"] != 8:
                (d / f"{s['name']}.bin").write_bytes(s["data"])
            manifest["sections"].append({k: s[k] for k in ("name", "address", "size", "type")})
        (d / "manifest.json").write_text(json.dumps(manifest, indent=1) + "\n")
        if pack_program(d) != p["raw"]:
            sys.exit(f"{level_dir(number)}: the dump does not convert back to the disc's bytes")
        rows[level_dir(number)] = (hashlib.sha1(p["raw"]).hexdigest(), len(p["raw"]), p["entry"])
    print(f"wrote {BOOT.relative_to(ROOT)} and {len(NAMES)} levels to {DUMP.relative_to(ROOT)}; "
          f"every level converts back to the disc's bytes")
    known = read_programs()
    mine = {k[1]: v for k, v in known.items() if k[0] == VERSION}
    if mine and mine != rows:
        bad = sorted(k for k in rows if mine.get(k) != rows[k])
        sys.exit(f"differs from config/programs.tsv: {', '.join(bad)}")
    if not mine:
        known.update({(VERSION, k): v for k, v in rows.items()})
        order = list(VERSIONS)
        PROGRAMS.write_text("# version\tprogram\tsha1 (as the disc stores it)\tsize\tentry -- tools/levels.py dump\n" +
                            "".join(f"{v}\t{k}\t{s}\t{n}\t{e:08X}\n" for (v, k), (s, n, e)
                                    in sorted(known.items(), key=lambda r: (order.index(r[0][0]), r[0][1]))))
        print(f"recorded {len(rows)} programs in {PROGRAMS.relative_to(ROOT)}")
    else:
        print(f"all {len(rows)} programs equal config/programs.tsv")


def check() -> None:
    """The dumps in baserom/ against config/programs.tsv, without the disc image."""
    known = {k[1]: v for k, v in read_programs().items() if k[0] == VERSION}
    bad = []
    for prog, (sha1, size, entry) in sorted(known.items()):
        data = BOOT.read_bytes() if prog == "boot" else pack_program(DUMP / prog)
        if hashlib.sha1(data).hexdigest() != sha1:
            bad.append(prog)
    if bad or not known:
        sys.exit(f"{VERSION}: {len(bad)} dumps differ from config/programs.tsv: {', '.join(bad) or 'none recorded'}")
    print(f"{VERSION}: all {len(known)} dumps equal config/programs.tsv")


# Link-dependent instruction fields.
MEM = {0x1A, 0x1B, 0x1E, 0x1F, *range(0x20, 0x30), 0x31, 0x36, 0x37, 0x39, 0x3E, 0x3F}


def words(b: bytes) -> tuple:
    return struct.unpack(f"<{len(b) // 4}I", b[:len(b) // 4 * 4])


def trim(b: bytes) -> bytes:
    while b.endswith(b"\0\0\0\0"):
        b = b[:-4]
    return b


# Measured from each disc's boot executable: where a level's program starts (its .lit, over
# the boot's memory) and the $gp every program of the disc shares.
LAYOUT = {
    "us": {"level_base": 0x1A7C80, "gp": 0x001AEFF0},
    "pal": {"level_base": 0x1A7D00, "gp": 0x001AF070},
    "us2": {"level_base": 0x1A7C80, "gp": 0x001AEFF0},
}
LEVEL_BASE = 0x1A7C80          # a level's program replaces the boot's memory from here
GP = 0x001AEFF0
BOOT_HI = 0x1A                  # an address half below this points into memory every program shares


def identity(b: bytes, address: int = 0) -> bytes:
    """One function's words with only its address fields masked: what two copies must
    share to be the same function. Masked: jump targets, the high half of a RAM address
    (lui), $gp-relative offsets, and offsets on a register that holds an address (one a
    lui loaded with an address half, or copied or computed from one). Compared: every
    other immediate, so two routines that differ in a constant, a stack slot or a field
    offset on a pointer argument stay two functions. Large offsets on other registers
    stay masked, since an address half can reach one through a spill.

    An address in the memory below the levels' (the boot's resident code and data) is the same
    in every program, so a jump there, and a lui loading the high half of such an address with
    the offsets used on it, are compared: two routines that use different resident globals
    are two functions. ADDRESS is where the function starts, for its jump targets."""
    w = words(trim(b))
    tainted, grew = set(), True
    while grew:
        grew = False
        for x in w:
            op, rs, rt, rd = x >> 26, (x >> 21) & 31, (x >> 16) & 31, (x >> 11) & 31
            new = None
            if op == 0x0F and 0x10 <= x & 0xFFFF < 0x200:
                new = rt
            elif op in (0x09, 0x19) and rs in tainted:
                new = rt
            elif op == 0 and x & 0x3F in (0x21, 0x2D, 0x25) and (rs in tainted or rt in tainted):
                new = rd
            if new and new not in tainted:
                tainted.add(new)
                grew = True
    out, resident = [], {}         # register -> its lui loaded a resident address half
    for k, x in enumerate(w):
        op, rs, rt, imm = x >> 26, (x >> 21) & 31, (x >> 16) & 31, x & 0xFFFF
        if op in (2, 3):
            target = ((address + 4 * k) & 0xF0000000) | ((x & 0x3FFFFFF) << 2)
            if not (address and target < LEVEL_BASE):
                x &= 0xFC000000
        elif op == 0x0F:
            resident[rt] = 0x10 <= imm < BOOT_HI
            if 0x10 <= imm < 0x200 and not resident[rt]:
                x &= 0xFFFF0000
        elif rs in resident and resident[rs] and (op in MEM or op in (0x09, 0x0D, 0x19)) and rs != 29:
            pass                     # the low half of a resident address
        elif rs == 28 and op >= 8:
            x &= 0xFFFF0000
        elif rs == 28 and op >= 8:
            x &= 0xFFFF0000
        elif (op in MEM or op in (0x09, 0x0D, 0x19)) and rs != 29:
            small = imm < 0x1000 or imm >= 0xF000
            if rs in tainted or (rs != 0 and op != 0x0D and not small):
                x &= 0xFFFF0000
        out.append(x)
    return struct.pack(f"<{len(out)}I", *out)


def cross_identity(b: bytes) -> bytes:
    """One function's words with only what the linker fills in masked, to compare two releases
    (tools/carry.py): their memory is laid out differently, so every address is masked, the
    resident ones too, but nothing else. Masked: jump targets, the high half of an address
    (a lui of 0x10..0x1FF), $gp-relative offsets, and the low half of an address: the offset
    of a load, store or add on a register holding a high half (the lui's, or a sum with it).
    A register that already holds a whole address (an addiu of a high half) is a pointer:
    the offsets on it are fields and are compared, as are all constants and stack slots."""
    w = words(trim(b))
    high, grew = set(), True
    while grew:
        grew = False
        for x in w:
            op, rs, rt, rd = x >> 26, (x >> 21) & 31, (x >> 16) & 31, (x >> 11) & 31
            new = None
            if op == 0x0F and 0x10 <= x & 0xFFFF < 0x200:
                new = rt
            elif op == 0 and x & 0x3F in (0x21, 0x2D, 0x25) and (rs in high or rt in high):
                new = rd
            if new and new not in high:
                high.add(new)
                grew = True
    out = []
    for x in w:
        op, rs, rt, imm = x >> 26, (x >> 21) & 31, (x >> 16) & 31, x & 0xFFFF
        if op in (2, 3):
            x &= 0xFC000000
        elif op == 0x0F:
            if 0x10 <= imm < 0x200:
                x &= 0xFFFF0000
        elif rs == 28 and op >= 8:
            x &= 0xFFFF0000
        elif rs in high and (op in MEM or op in (0x09, 0x0D, 0x19)):
            x &= 0xFFFF0000
        out.append(x)
    return struct.pack(f"<{len(out)}I", *out)


def fingerprint(b: bytes, address: int = 0) -> str:
    return hashlib.sha1(identity(b, address)).hexdigest()[:16]



# The level's data/vtables point past these trailing instructions of the
# preceding bodies. Preserve each extent's end; the prefix remains assembly.
LEVEL_ENTRY_OFFSETS = {
    (0, 0x00354DE8): 16,  # data pointer at 0x00287070 -> 0x00354DF8
    (0, 0x003D54A8): 8,   # vtbl pointer at 0x002A3370 -> 0x003D54B0
    (0, 0x0040EA98): 8,   # vtbl pointer at 0x002A3718 -> 0x0040EAA0
    (23, 0x004277B0): 8,  # data pointer at 0x002ABE40 -> 0x004277B8; end unchanged
}


def level_extent(number: int, address: int, size: int) -> tuple[int, int]:
    """Correct measured level entry boundaries without moving their ends."""
    skip = LEVEL_ENTRY_OFFSETS.get((number, address), 0)
    if size <= skip:
        raise ValueError(f"{number}:{address:08X}: no body after {skip} entry bytes")
    return address + skip, size - skip


# The level's linker leaves padding between the bodies, and a body that ends in a
# `jr $ra` leaves the word after its delay slot behind.  Both are measured from the
# retail bytes, not from a list of addresses: an extent whose words are only stack
# adjustments and nops is padding, and a four-byte extent right after such an
# epilogue is its residue.

STACK_ADJUST = 0x09          # addiu
MOVE = 0x21                  # addu
ZERO = 0                     # $zero


def _is_padding(word: int) -> bool:
    """A nop, a stack adjustment of $sp by $sp, or a move of $zero.

    These are the words the linker leaves between two bodies.  The operands matter:
    `addu $t0,$t1,$t2` is arithmetic and `addiu $sp,$a0,16` writes through a
    register, and neither is filler."""
    if word == 0:
        return True
    op, rs, rt = word >> 26, (word >> 21) & 31, (word >> 16) & 31
    if op == STACK_ADJUST and rs == 29 and rt == 29:
        return True
    if op == 0 and word & 0x3F == MOVE and rs == ZERO and rt == ZERO:
        return True
    return False


def is_padding(body: bytes) -> bool:
    """True when the words are only stack adjustments and nops: filler, not code.

    A body that ends in a trap or a tail call has no `jr $ra` and is still code, so
    the absence of a return does not decide this: only the words do."""
    return all(_is_padding(w) for w in words(body))


def is_epilogue_residue(body: bytes, previous: bytes) -> bool:
    """True when the body is the word the previous body's epilogue left behind.

    The previous body ends with `jr $ra` and its delay slot; the word after them is
    the residue the compiler left, and a function of four bytes cannot hold it.  It
    is not the linker's filler - the words say otherwise - so it is measured here:
    the previous body's last `jr $ra` and its delay slot, and nothing else."""
    w = words(body)
    if len(w) != 1:
        return False
    p = words(previous)
    if len(p) < 2:
        return False
    if p[-2] >> 26 != 0 or p[-2] & 0x3F != 0x08:      # not a jr
        return False
    return True


# Measured residual instruction extents in USA v1.01, not callable entries.
# Each follows a completed return across alignment padding, with no direct
# branch/call or aligned pointer into the extent in any of its programs.
# Unlike is_padding, these include stores/float arithmetic; do not generalise
# their removal to arbitrary code without a return. See docs/LEVELS.md.
BOOT_RESIDUES = {
    0x00289018: 4,    # an isolated store using an uninitialised $v0
    0x002A77C0: 28,   # orphan float operations using live-in $f0/$f1
    0x002FDB40: 148,  # stack restores and an orphan store; also in 22 levels
    0x002FED78: 12,   # return-value assignment and an unmatched stack restore
    0x002FF0B0: 36,   # unmatched stack restores and an orphan GP store
}


def boot_image() -> tuple[bytes, list[tuple[int, int, int]]]:
    """The boot executable and its loadable segments (vaddr, file offset, file size)."""
    elf = BOOT.read_bytes()
    phoff, phnum = struct.unpack_from("<I", elf, 0x1C)[0], struct.unpack_from("<H", elf, 0x2C)[0]
    segs = []
    for i in range(phnum):
        kind, off, va, _, size = struct.unpack_from("<5I", elf, phoff + 32 * i)
        if kind == 1:
            segs.append((va, off, size))
    return elf, segs


def boot_bytes(address: int, size: int) -> bytes:
    elf, segs = boot_image()
    for va, off, n in segs:
        if va <= address < va + n:
            return elf[off + address - va: off + address - va + size]
    raise ValueError(f"{address:#x} is not in the boot executable")


def level_text(directory: Path) -> tuple[int, bytes]:
    m = json.loads((directory / "manifest.json").read_text())
    text = next(s for s in m["sections"] if s["name"] == "text")
    return text["address"], (directory / "text.bin").read_bytes()


def old_extents(program: str) -> list[tuple[int, int]]:
    """Function extents from the catalogues this project kept before (config/function-catalog/,
    one gzipped file per program): only for the first catalogue."""
    out = []
    for line in gzip.open(ROOT / f"config/function-catalog/{program}.ndjson.gz", "rt"):
        r = json.loads(line)
        if isinstance(r, list):
            out.append((r[0], r[1]))
    return out


def read_boot_functions() -> list[tuple[str, int, int]]:
    rows = []
    for line in BOOT_FUNCTIONS.read_text().splitlines():
        if not line.startswith("#"):
            name, address, size = line.split("\t")[:3]
            rows.append((name, int(address, 16), int(size)))
    return rows


def read_catalogue() -> list[tuple[str, str, int, str, list[tuple[int, int]]]]:
    rows = []
    for line in CATALOGUE.read_text().splitlines():
        if line.startswith("#"):
            continue
        name, kind, size, fp, _, places = line.split("\t")
        rows.append((name, kind, int(size), fp,
                     [(int(p.split(":")[0]), int(p.split(":")[1], 16)) for p in places.split(",")]))
    return rows


def catalogue() -> None:
    """config/boot/functions.tsv and config/levels/functions.tsv from the function extents:
    the old catalogues the first time (--from-old), these files after."""
    from_old = "--from-old" in sys.argv
    elf, segs = boot_image()
    text_va, text_off, text_size = segs[0]
    if from_old:
        boot = [(f"func_{a:08X}", a, n) for a, n in old_extents("boot")
                if text_va <= a < text_va + text_size]
    else:
        boot = read_boot_functions()
    boot_by_fp = {}
    # Compute from the pinned retail input even after the rows have been removed,
    # so catalogue regeneration is repeatable. Size and normalised bytes both
    # have to agree; a similar-looking or merely return-less function is kept.
    residue_keys = {(fingerprint(boot_bytes(a, n), a), n) for a, n in BOOT_RESIDUES.items()}
    corrected_boot = []
    last_end, last_body = None, b""
    for name, a, n in sorted(boot, key=lambda r: r[1]):
        body = boot_bytes(a, n)
        if (fingerprint(body, a), n) in residue_keys:
            continue
        if is_padding(body):
            continue                    # the linker's filler, not a function
        if len(words(body)) == 1 and last_end == a and is_epilogue_residue(body, last_body):
            continue                    # the residue of the previous body's epilogue
        corrected_boot.append((name, a, n))
        boot_by_fp.setdefault((fingerprint(body, a), n), []).append(name)
        last_end, last_body = a + n, body
    extents = {}
    if from_old:
        for number in NAMES:
            base, data = level_text(DUMP / level_dir(number))
            extents[number] = [(a, n) for a, n in old_extents(f"{number}_{NAMES[number]}")
                               if base <= a < base + len(data)]
    else:
        for name, kind, size, fp, places in read_catalogue():
            for number, a in places:
                extents.setdefault(number, []).append((a, size))
    found = {}
    for number in sorted(extents):
        base, data = level_text(DUMP / level_dir(number))
        # the previous extent of the same program, for the epilogue residue
        last_end, last_body = None, b""
        for a, n in sorted(extents[number]):
            a, n = level_extent(number, a, n)
            body = data[a - base:a - base + n]
            if (fingerprint(body, a), n) in residue_keys:
                continue
            if not trim(body) or is_padding(body):
                continue
            if len(words(body)) == 1 and last_end == a and is_epilogue_residue(body, last_body):
                continue                # the residue of the previous body's epilogue
            # the size too: the same instructions with different padding are two functions
            entry = found.setdefault((fingerprint(body, a), n), {"size": n, "places": []})
            entry["places"].append((number, a))
            last_end, last_body = a + n, body
    # Boot functions paired by hand with level places the code alone cannot tell apart.
    pairs = {}
    if BOOT_PAIRS.is_file():
        for line in BOOT_PAIRS.read_text().splitlines():
            if not line.startswith("#"):
                name, places = line.split("\t")
                for p in places.split(","):
                    pairs[(int(p[:2]), int(p[3:], 16))] = name
    # Two places in one program are two functions (identical code, e.g. two empty methods):
    # the k-th copy in each level, by address, is one function (the levels link their shared
    # code in one order). It is named after the boot's function only when there is one copy
    # each: the boot's order is not the levels'.
    rows = []
    for key, e in found.items():
        fp = key[0]
        per_level, paired = {}, {}
        for number, a in sorted(e["places"]):
            if (number, a) in pairs and pairs[(number, a)] in boot_by_fp.get(key, ()):
                paired.setdefault(pairs[(number, a)], []).append((number, a))
            else:
                per_level.setdefault(number, []).append(a)
        for name, places in sorted(paired.items()):
            rows.append((name, "boot", e["size"], fp, places))
        if not per_level:
            continue
        copies = max(len(v) for v in per_level.values())
        for k in range(copies):
            places = [(number, v[k]) for number, v in sorted(per_level.items()) if len(v) > k]
            if copies == 1 and len(boot_by_fp.get(key, ())) == 1 and not paired:
                name, kind = boot_by_fp[key][0], "boot"
            else:
                number, a = places[0]
                name = f"func_L{number:02d}_{a:08X}"
                kind = "level" if len({p[0] for p in places}) == 1 else "shared"
            rows.append((name, kind, e["size"], fp, places))
    rows.sort(key=lambda r: r[4][0])
    BOOT_FUNCTIONS.parent.mkdir(parents=True, exist_ok=True)
    BOOT_FUNCTIONS.write_text("# name\taddress\tsize\n" +
                              "".join(f"{n}\t{a:08X}\t{s}\n" for n, a, s in sorted(corrected_boot, key=lambda r: r[1])))
    LEVELS.mkdir(parents=True, exist_ok=True)
    lines = ["# name\tkind\tsize\tfingerprint\tlevels\tplaces (level:address)"]
    for name, kind, size, fp, places in rows:
        lines.append(f"{name}\t{kind}\t{size}\t{fp}\t{len({p[0] for p in places})}\t" +
                     ",".join(f"{l:02d}:{a:08X}" for l, a in places))
    CATALOGUE.write_text("\n".join(lines) + "\n")
    placed = sum(r[2] * len(r[4]) for r in rows)
    count = {k: sum(1 for r in rows if r[1] == k) for k in ("boot", "shared", "level")}
    size = {k: sum(r[2] for r in rows if r[1] == k) for k in ("boot", "shared", "level")}
    print(f"boot: {len(corrected_boot)} functions, {sum(r[2] for r in corrected_boot)} bytes")
    print(f"levels: {sum(len(r[4]) for r in rows)} placements, {placed} bytes; {len(rows)} distinct: " +
          ", ".join(f"{count[k]} {k} ({size[k]} bytes)" for k in count))


select(os.environ.get("RAC2_VERSION", "us"))


def main() -> None:
    version_argument()
    commands = {"dump": dump, "catalogue": catalogue, "check": check}
    if len(sys.argv) < 2 or sys.argv[1] not in commands:
        sys.exit(__doc__)
    commands[sys.argv[1]]()


if __name__ == "__main__":
    main()
