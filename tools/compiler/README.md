# The game's C compiler

The retail code was built with GNU EE-GCC 2.9-ee-991111b. `build.sh` rebuilds its `cpp`,
`cc1` and `as` from the public source archive:

- `patches/`: Lombyte's `sce-991111b` stack (MIT, github.com/mateuszklysz/Lombyte) and the
  project's opt-in `0057` and `0058` extensions, applied in
  the order `build.sh` lists, with two pinned versions: `0034`, which Lombyte has since
  retired, and the earlier `0020` (Lombyte c260794). `0001` is applied and then reversed: the
  retail saves registers in 8-byte slots.
- `transformers/`: the source edits measured for this game, each a script carrying its exact
  replacement text, in the order `build.sh` runs them. `u3_frame_order_on.py` and
  `u4_mtc1_helper.py` are two earlier steps the later ones build on.
  `r5900_mfc1_interlock.py` drops gas's coprocessor-load `nop` after `mfc1` on the R5900,
  which interlocks it. `tidy_condjump_fallthru.py` lets flow delete a conditional jump to the
  next block, as GCC 2.95 does. `zero_ti_store_barrier.py` adds the opt-in
  `-frac2-zero-ti-barrier` model of the inferred quadword-clear macro
  (docs/COMPILER-NOTES.md); default compilation retains ordinary scheduling.
  `gcse_unsplit_edges.py` and `keep_block_order.py` add the opt-in
  `-frac2-gcse-unsplit-edges` and `-frac2-keep-block-order`, which leave out two
  Cygnus-local pieces of this tree that GCC 2.95 does not have.

Patch `0057` adds the opt-in `-mastra-split-trunc-slot` switch. It splits the
two-word `truncdisi2` pattern after reload, before delay-slot scheduling, so
the sign-extension can occupy a return slot. The default compiler output is
unchanged. Use the switch only on a dedicated C file in `config/cflags.txt`;
`src/core/0012E8C8.c` is the measured witness.

Patch `0058` adds the opt-in `-mastra-quad-saves` switch. It widens every GPR save slot to
TImode, so the prologue and the epilogue emit `sq`/`lq` as the two measured `src/core` units
are saved, and it keeps the released descending save order for those units (the default profile
keeps the ascending order measured for the 8-byte slots). Without the switch the output is
unchanged. Use it only on a dedicated C file in `config/cflags.txt`; `src/core/00119BC8.c`,
`src/core/00115F28.c` and `src/core/00115C90.c` are the measured witnesses.

The clear model is enabled per file in `config/cflags.txt`, currently for
`src/levels/shared/L00_003B9CB8.c`. It is a measured heuristic, including for
nonzero-displacement stores, not proof of a recovered original macro. Qualify
every function in a unit before enabling it there. `-fno-rac2-zero-ti-barrier`
disables it again. `build.sh` runs `tests/test_zero_ti_store.py` against the newly
built tools: selector boundaries, isolated/shared/offset clears, calls, branches
and the default/disabled controls. The host selector tests also run in ordinary
CI; the EE output tests require the public-built compiler, never game data.

The separate `fold_zero_ti_store.py` pass folds a materialized zero only when
the store address is a register with no displacement. Offset stores keep their
`por` producer and register-source `sq`, as measured in the retained vector
helpers. This address rule applies in every scheduling profile; it does not
enable `-frac2-zero-ti-barrier` for additional files. Authored positive and
negative offset controls verify it alongside the zero-displacement controls.

`-frac2-gcse-unsplit-edges` lets gcse's block LCM run on the unsplit flow graph: this tree's
`gcse_main` first splits each critical edge that needs no new jump (Cygnus, 1998), so a
hoisted `%hi` gets a block of its own in front of a label reached only by jumps; GCC 2.95's
does not split, and its PRE inserts at the end of a block. `-frac2-keep-block-order` skips
`cygnus_merge_blocks` (Cygnus, 1998), which moves a block reached only by a jump up behind
its predecessor after the early jump passes; GCC 2.95 has no such pass. A switch whose
default is its last case keeps its `b default` and the default body last with it. Both are
inferred from retail's code, so both are off by default and enabled per file in
`config/cflags.txt`: the gcse switch for `src/levels/02_maktar_nebula/L02_003DB310-g8.c`
and `src/game/002CD620.c`, the block-order switch for `src/levels/shared/L18_00427BE0.c`,
and both for `src/levels/02_maktar_nebula/L02_003F5430-g8.c`. `build.sh` runs
`tests/test_gcse_unsplit_edges.py` and `tests/test_keep_block_order.py` against the newly
built tools: each transformer's insertion points, the case each switch changes, controls
that keep ordinary output, and the default/disabled equality.

`qcopy_pattern.py` adds `-frac2-qcopy`, enabled only for qualified files in
`config/cflags.txt`. It lowers an aligned TImode memory assignment to a grouped
`lq`/`sq` pair with register addresses and a declared `$v0` scratch. Sources
remain ordinary C assignments. The default keeps normal displacement addressing;
`-fno-rac2-qcopy` restores that default. Memory flags and alias sets are retained,
explicitly unaligned accesses take the ordinary path, and no memory barrier is
added. Scalar transfers and zero stores are not selected by this pattern.
Qualify every function in an opted-in unit; address formation alone does not
settle allocation or scheduling. The recipe requires the authored copy controls
and RTL-contract tests, including volatile accesses and integer/FPU branches.

`hazard_labels.py` adds `-frac2-hazard-labels`, enabled only for qualified files in
`config/cflags.txt`. cc1 then writes `.set rac2_hazard_labels` at the top of its output, and
gas keeps a code label in front of the coprocessor hazard `nop` it inserts after the label
(an FPU compare before its `bc1f`/`bc1t`, an `mtc1` before a reader of the register), where
GNU `as` moves the label behind the nop. Retail has the label on the nop at all 198 such
branch targets, and SN ProDG 2.0's `Ps2EeAs` keeps it there for forward, backward, `j` and
`.word` references alike (docs/COMPILER-NOTES.md). Without the switch neither program's
output changes. `src/levels/18_damosel/L18_004308F0.c` and `src/levels/shared/L02_00411530.c`
are the measured witnesses; forcing the switch on every unit changes only the `.mdebug` of
one `-g` unit. `tests/test_hazard_labels.py` covers the fixed cases and the controls.

Patch `0052` also preserves the original sign-extending expansion for the isolated
64-bit sign bit and a sign bit followed by a contiguous low run of at least 32
ones. Positive contiguous runs wider than 32 bits, with zero bits at both ends,
use the existing shift-based mask expansion. This includes
`0x0FFFFFFFFFFFFFFE`: three instructions instead of seven. Runs of 32 bits or
fewer retain their previous expansion, including the 20-bit shifted mask used
by already-matched C. Regression controls exercise every shifted long-run
interval, neighboring masks, holes and four destination registers.

Some SDK objects use the zero-extending seed for the isolated sign bit instead.
Patch `0059` adds `--r5900-sign-bit=unsigned` for those measured cases;
`--r5900-sign-bit=signed` explicitly restores the default. Only the isolated
64-bit sign-bit constant changes, from `addiu -1; dsll32 31` to
`ori 0x8000; dsll32 16`. Other constants keep their previous encoding.

Pass assembler options per file through standard `-Wa,` syntax in
`config/cflags.txt`, for example:

```text
src/core/00122B00.c	sdk -O2 -G2 -ffunction-sections -Wa,--r5900-sign-bit=unsigned
```

Both compiler profiles stop at assembly, so `tools/build.py` separates these
arguments and forwards them to the assembler explicitly. The complete flag
string and assembler binary remain part of the object-cache key. Empty options
are rejected, and the tests exercise actual argument transport for both
frontends, default/explicit profiles, invalid values and unchanged controls.

`build.sh` stops unless `mips.c`, `mips.h`, `mips.md`, `toplev.c`, `flags.h`,
`haifa-sched.c`, `gcse.c`, `flow.c` and `tc-mips.c` hash as it
lists. The binaries' own hashes depend on the build host and path, so check a compiler by its
output: `tools/build.py` compiles every matched function to the retail bytes.
