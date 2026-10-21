"""Tests for tools/carry.py and levels.cross_identity(): no game data, no toolchains."""
import struct
import sys
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import carry  # noqa: E402
import levels  # noqa: E402

JR_RA, NOP = 0x03E00008, 0


def code(*w: int) -> bytes:
    return struct.pack(f"<{len(w)}I", *w)


def lui(rt: int, imm: int) -> int:
    return 0x0F << 26 | rt << 16 | imm


def addiu(rt: int, rs: int, imm: int) -> int:
    return 0x09 << 26 | rs << 21 | rt << 16 | (imm & 0xFFFF)


def lw(rt: int, rs: int, imm: int) -> int:
    return 0x23 << 26 | rs << 21 | rt << 16 | (imm & 0xFFFF)


class CrossIdentity(unittest.TestCase):
    def test_addresses_are_masked_resident_too(self):
        a = code(lui(2, 0x1A), lw(2, 2, 0x7BB4), JR_RA, NOP)
        b = code(lui(2, 0x1A), lw(2, 2, 0x7C3C), JR_RA, NOP)
        self.assertEqual(levels.cross_identity(a), levels.cross_identity(b))
        c = code(lui(2, 0x13), lw(2, 2, 0x7BB4), JR_RA, NOP)     # resident within one release
        d = code(lui(2, 0x13), lw(2, 2, 0x7C3C), JR_RA, NOP)
        self.assertNotEqual(levels.identity(c, 0x200000), levels.identity(d, 0x200000))
        self.assertEqual(levels.cross_identity(c), levels.cross_identity(d))

    def test_fields_of_a_whole_address_are_compared(self):
        # lui + addiu make a pointer; the offsets on it are fields, not address halves
        a = code(lui(2, 0x1C), addiu(3, 2, -0x5380), lw(4, 3, 0x2AC), JR_RA, NOP)
        b = code(lui(2, 0x1C), addiu(3, 2, -0x5300), lw(4, 3, 0x2DC), JR_RA, NOP)
        self.assertNotEqual(levels.cross_identity(a), levels.cross_identity(b))
        c = code(lui(2, 0x1C), addiu(3, 2, -0x5300), lw(4, 3, 0x2AC), JR_RA, NOP)
        self.assertEqual(levels.cross_identity(a), levels.cross_identity(c))

    def test_jumps_and_gp_offsets_are_masked(self):
        a = code(3 << 26 | 0x100, 0x8F820010, JR_RA, NOP)        # jal; lw v0,0x10(gp)
        b = code(3 << 26 | 0x200, 0x8F820018, JR_RA, NOP)
        self.assertEqual(levels.cross_identity(a), levels.cross_identity(b))

    def test_constants_are_compared(self):
        self.assertNotEqual(levels.cross_identity(code(addiu(4, 0, 60), JR_RA, NOP)),
                            levels.cross_identity(code(addiu(4, 0, 50), JR_RA, NOP)))


class Carry(unittest.TestCase):
    def test_branch_target(self):
        self.assertEqual(carry.branch_target(0x10400003, 0x1000), 0x1010)   # beqz v0,+3
        self.assertEqual(carry.branch_target(0x1000FFFF, 0x1000), 0x1000)   # b .
        self.assertIsNone(carry.branch_target(0x0C000000, 0x1000))          # jal

    def test_cut_after_a_return(self):
        data = code(addiu(29, 29, -16), JR_RA, NOP, 0, addiu(29, 29, -32), JR_RA, NOP, 0)
        self.assertEqual(carry.cut(data, 0x1000, 0x1000, 0x1020, set()), [(0x1000, 12), (0x1010, 12)])

    def test_align_finds_moved_and_changed_functions(self):
        f = code(addiu(29, 29, -16), lw(2, 4, 8), JR_RA, NOP)
        g = code(addiu(4, 0, 60), addiu(5, 0, 1), JR_RA, NOP)
        h = code(addiu(29, 29, -32), lw(3, 4, 12), lw(2, 4, 16), JR_RA, NOP, 0)
        us = (0x1000, f + g + h)
        g_pal = code(addiu(4, 0, 50), addiu(5, 0, 1), JR_RA, NOP)
        v = (0x2000, code(0, 0) + f + g_pal + h)            # moved by 8 bytes, g changed
        ext = [(0x1000, 16, "f"), (0x1010, 16, "g"), (0x1020, 24, "h")]
        out = {e[0]: e[:4] for e in carry.align(us, ext, v)}
        self.assertEqual(out[0x2008], (0x2008, 16, "f", "same"))
        self.assertEqual(out[0x2018], (0x2018, 16, None, "changed"))
        self.assertEqual(out[0x2028], (0x2028, 24, "h", "same"))


if __name__ == "__main__":
    unittest.main()
