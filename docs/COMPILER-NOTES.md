# Compiler and assembler compatibility notes

This reference groups qualified compiler mechanisms and useful C source shapes by
topic. Open cases belong in [MATCHING-BLOCKERS.md](MATCHING-BLOCKERS.md). The source
recipe, per-file flags and complete linked build take precedence over historical
observations; this document is not a progress report or a reconstruction of the
unknown shipping toolchain.

Source-shape observations cited from [PR #295](https://github.com/OpenRAC/rac2-decomp/pull/295)
were measured on both USA releases. Their integration status and PAL qualification
belong to that PR; they are not additional project-progress claims.

## Identity, tools and reproduction

| Input | Maintained implementation | Role |
| --- | --- | --- |
| Game C | [tools/compiler/build.sh](../tools/compiler/build.sh) | Public GNU EE 2.9-ee-991111b cpp/cc1, pinned Lombyte sce-991111b patches and measured transformers |
| SDK C | [tools/compiler/sdk/build.py](../tools/compiler/sdk/build.py) | Public-source Sony EE-GCC 2.9-ee-991111-01, selected with the sdk prefix in config/cflags.txt |
| Assembly from either C frontend | Source-built game GNU as | Qualified immediate, hazard and padding rules |
| Remaining assembly reconstructed from the disc | Locally supplied SN ProDG 2.0 Ps2EeAs.exe | Separate from the GNU-assembled C-object path |
| Final link | Locally supplied SN ld.exe | Places the objects before comparison against retail |

The GNU archive is `gnu-ee-binutils-gcc-1.1.tar.gz`, SHA-256
`1f518043e252d6eda726386971d52eda26541ab936ea73a9783d73712b595f92`, target
`mips64r5900-sf-elf`. [CREDITS.md](../CREDITS.md) records the public sources.
Proprietary SDK source, samples and headers are not inputs.

Matching bodies establishes compatibility, not Insomniac's exact original binary,
patch set, flags or directives. The earlier SN 2.95.3 profile matched simple leaves
but disagreed on saves, sibling calls and block moves. Leaf-only controls do not
exercise those mechanisms.

Prefixes such as `8bed6eae` identify historical local binaries, not compiler versions
or selectable tools. Binary hashes depend on the host. The maintained recipe owns
the patch order and source-hash checkpoints; do not replay obsolete hash tables,
copied shell recipes or the removed `scripts/` workflow.

```sh
bash tools/compiler/build.sh
python3 tools/compiler/sdk/build.py
python3 tools/check.py func_XXXXXXXX --diff
python3 tools/build.py all --strict --jobs 8
```

See [BUILDING.md](BUILDING.md) for setup and [VERSIONS.md](VERSIONS.md) for releases.
Flags are per file in [config/cflags.txt](../config/cflags.txt). A `*-g8.c` sibling
gets `-G8` unless an earlier explicit rule matches. Qualify every C definition in a
unit after changing its profile.

The old tools need 32-bit Linux support and bison 1.28. Generate `insn-flags.h`,
`insn-codes.h` and `insn-config.h` before parallel compilation: the 1999 Makefile
omits the `flow.o` dependency. Linux filesystem intermediates avoid old 32-bit
`stat` failures on Windows filesystem inodes. The maintained recipe/container
handles these constraints.

## Selecting a profile

Read the retail frame and instructions before changing C. Do not compensate for a
wrong profile with extra operations or knowingly false prototypes.

| Observed difference | Profile or mechanism | Measured example |
| --- | --- | --- |
| Ordinary 8-byte GPR saves | Default game -O2 -G0 -ffunction-sections | func_002889B8 |
| Missing GP-relative access | Game compiler, -G8 sibling and correct known-size declaration | func_L00_003206B8 |
| Public SDK/libgcc source differs under game compiler | sdk profile, accurate types and inline declarations | func_00122800, func_00122B00 |
| Whole GPR save area uses sq/lq | -mastra-quad-saves | func_00119BC8, func_00115F28, func_00115C90 |
| Two-word truncation cannot fill return slot | -mastra-split-trunc-slot | func_0012E8C8 |
| Arguments spilled and branch to common epilogue | Measured -O0 unit, not an invented varargs helper | func_001175F0 |
| Absolute load must reuse its destination as address temporary | -mno-split-addresses and assembler symbol model | func_001339B0, func_L20_0043F460 |
| Register addresses and grouped 16-byte transfer | -frac2-qcopy | func_L20_0039E158, func_L20_0039F210 |
| Correct copy, wrong motion across it | -frac2-qcopy-barrier, with qcopy | func_002B5E48, func_002EE988 |
| Float min/max expands into compare and branch | -ffast-math; optimization level still affects allocation | func_L01_003BD560, func_L00_002EE050 |

`-G8` can change allocation even without GP accesses: `func_L17_003BCBC8` puts
colour constants in different registers. A successful profile is not proof of the
original SDK flags.

## Frames, calls and ABI

### Save order and loop padding

The default game profile uses 8-byte GPR slots and ascending GPR save/restore order.
FPR order stays descending. Source emission is **GPR before FPR on both saves and
restores**; scheduling may interleave them. The former FPR-first reconstruction
was a regression, not an alternate rule to restore.

In the original 28-program mixed-frame survey, 92.5% of 31,278 frames began with a
GPR save, but only 34.8% of the tutorial's mixed frames kept the whole GPR block
before every FPR save. Emission order is not final scheduled order. Fixing a frame
does not fix unrelated entry-block allocation or address formation.

The implementations are
[neutralise_timode_anchor.py](../tools/compiler/transformers/neutralise_timode_anchor.py),
[ascending_save_order.py](../tools/compiler/transformers/ascending_save_order.py) and
[reorder_save_blocks.py](../tools/compiler/transformers/reorder_save_blocks.py).
The reorder consumes the ascending-order transformer's output. Replacing `mips.c`
with an older file also removes the zero-fold code called by `toplev.c`.

[disable_frame_order_default.py](../tools/compiler/transformers/disable_frame_order_default.py)
keeps generic frame scheduling by default; `-mastra-keep-frame-order` is an explicit
experiment. `func_002B7170` needs the generic order plus measured source lifetimes
and stores. No frame-order option fixes arbitrary entry-block allocation.

Short-loop padding must run after delay-slot scheduling: this C pipeline uses GNU
`as`, rather than the assembler assumed by patch 0054.
[enable_loop_padding.py](../tools/compiler/transformers/enable_loop_padding.py)
restores the hook.
[count_trap_length.py](../tools/compiler/transformers/count_trap_length.py) counts a
`TRAP_IF` by its machine-description length: a division guard is branch plus break,
not one word. Counting one overpads `func_0028B950`; `func_0034FB20` is the 168-byte
polling-loop witness.

### Quadword saves and return slots

Patch 0058 enables `-mastra-quad-saves` per file: all GPR slots widen to TImode and
the GPR order retains the released descending walk; default output is unchanged.
Witnesses include `func_00119BC8` (48 bytes), `func_00115F28` (80) and
`func_00115C90` (92). The last also needs its failure value compared as unsigned
`0xFFFFFFFF` to preserve the immediate sequence.

Patch 0057 enables `-mastra-split-trunc-slot`: split `truncdisi2` after reload and
before scheduling so its second shift can fill the return slot. `func_0012E8C8`
changes from 32 to retail's 28 bytes. Dedicated files prevent either option from
silently changing neighbouring definitions.

### Prototypes, lifetimes and varargs

- Preserve actual argument count and return width. A value-returning call defines
  `$v0` and can move the next constant to `$v1` (`func_00339F28`, `func_00343A30`).
  Do not invent a void return or an assembler-name alias to steer allocation.
- A 64-bit colour/result must keep its ABI width. `func_001175F0` forwards a long
  result; explicit 32-bit truncation adds two instructions.
- Integer and FP arguments use separate register banks. Their declaration order
  can affect setup while preserving the measured ABI: `func_0030E700` and existing
  Barlow effect-helper declarations are witnesses. Check the whole call site.
- A pointer live across a call can need a saved register and a larger frame.
  Creating it later, or keeping genuinely distinct guard and walk variables,
  can recover the live ranges (`func_L08_00328BB0`).
- Preserve a public upstream helper's `static __inline__`; omitting it may emit a
  real call (`func_00123C28`).
- This compiler is C89: declarations precede statements in their block. Put
  typedefs before externs using them. Do not name a typedef `TI`: it conflicts
  with a later `mode(TI)` attribute. `TI128` avoids the collision.

The recipe installs its public `gcc/ginclude/*.h`. Here `va_start` uses
`__builtin_next_arg(last)`, the **stack arguments**, while some retail shims pass
the **register save area**: `sp+0x50` in a 0x80 frame with two named arguments, or
`sp+0x58` in a 0x90 frame with one. The area above named arguments is
`(8 - named_count) * 8` bytes. Witnesses: `src/core/0011E0D8.c`, `func_00115CF0`,
`func_00115D48`, `func_00115DA8`. Do not use this to explain an ordinary -O0 shim.

## Symbols, addresses and small data

Use catalogue function identities, resident `D_XXXXXXXX` below the selected level
base, and level `D_LNN_XXXXXXXX` data names. When a callee/data pairing changes by
program, use `ref_LNN_XXXXXXXX_kk`. Zero-padding a level address is not enough to
identify its canonical function. See [LEVELS.md](LEVELS.md).

GP and overlay base depend on the release. USA v1.01 uses GP `0x001AEFF0`; take
other releases' constants from the selected layout, not a copied literal.

The backend's symbol model, declaration size, -G threshold and assembler mode all
matter; neither `sda` nor `nosda` is a universal opcode selector:

- At -G0 a macro symbol operand may expand to `lui` plus low-half access in ordinary
  flow, or one GP instruction in a `.set nomacro` delay slot.
- `sda` can restore the backend's one-instruction model. At -G8, a suitable known
  size and emitted `.extern NAME,size` enable GP addressing. An incomplete array
  prevented it in `func_00132DF0`; a sized two-element array provided the control.
- `nosda` can preserve an absolute access but can also add a temporary or hoist
  the address across a call. It is not neutral at -G8.
- `-mno-split-addresses` changes pseudos, not all GP loads uniformly. An FP repair
  can permute the prologue. Witnesses include `func_L00_003959C0`,
  `func_L05_00397F48` and `func_L01_00416A50`.
- A body using both GP and absolute forms needs measured declarations/bindings,
  not a guessed global rule. Split-address uses can keep `%hi` in a saved register
  and add `%lo` at each use (`src/levels/shared/L00_002C2DE8.c`).
- Base evaluation and pointer construction can have different orders. In
  `func_002980D0`, forming both bases first and then the pointers preserves both.

Odd-address byte globals are valid absolute bindings (`0x001A7B94/95`,
`0x001A7BB2/B3`); there is no universal four-byte alignment requirement. A low half
with bit 15 set also needs the correct signed-low-half relocation. Compare bound
addresses and words, not just textual `lui` operands.

## Quadword copies

### Address formation and grouped lowering

A `mode(TI)` integer assignment reaches `lq`/`sq`; an aggregate may instead use
scalar/unaligned transfers or `memcpy`. `find_best_addr` prefers a register plus
small constant over a register at equal address cost; reload accepts TImode
displacements in `[-32768, 32752]`. An intended `addiu; sq 0(reg)` therefore folds
into a displaced store. This is not evidence of handwritten assembly.

An out-of-range displacement, memory-loaded pointer, loop-carried pointer or join
with distinct incoming values can retain a register address. An artificial volatile
pointer adds a stack round trip and is not a production remedy. Never change the
real offset or add fake barriers just to force that shape.

[qcopy_pattern.py](../tools/compiler/transformers/qcopy_pattern.py) implements the
default-off, per-file `-frac2-qcopy`: aligned TImode memory-to-memory assignments,
register addresses, grouped lq/sq and a declared `$v0` scratch. Memory flags/alias
sets survive; it adds no memory barrier. The MD length is two instructions. Scalar
moves, zero stores and explicitly unaligned accesses retain ordinary lowering.
`-fno-rac2-qcopy` restores the default.

Witnesses: `func_L20_0039E158` (140 bytes), `func_L20_0039F210` (32), one place
each. The latter also needs `-fno-schedule-insns` and measured field-store order.
Restricting every TImode address to a register gave sizes without correct allocation.
The ordinary folded-copy witness `func_L00_00395240` stays on its default profile.

### Scheduling around copies

[qcopy_barrier.py](../tools/compiler/transformers/qcopy_barrier.py) adds
`-frac2-qcopy-barrier`, effective only with qcopy. Its TImode memory-to-memory SET
plus `(clobber (reg:TI 2))` gets both schedulers' volatile-copy dependences, cost 1
and unit classification. Operands, allocation inputs and memory flags stay unchanged;
`-fno-rac2-qcopy-barrier` disables it.

The original twelve witnesses total 3,616 bytes at 59 places: `func_002B5E48`,
`func_002EE988`, `func_L02_003DB158`, `func_L02_003D47B0`, `func_L02_00401BF8`,
`func_L12_00413CE0`, `func_L23_00418650`, `func_L23_003C01F8`,
`func_L23_00418DC0`, `func_L23_004256F0`, `func_L23_0041D0A0`,
`func_L26_003D4930`. Named destination pointers and the point where the second
copy's address is taken remain source requirements in two cases.

This models the schedulers, not every optimizer effect of inline assembly. Incoming
links retain producer latencies; interblock motion sees a store; jump2 can remove a
move that a volatile operation retains. `func_002B50E0` retained three argument-move
differences. Artificial clobbers, register pins and inline assembly remain forbidden.

The retained `func_00335370` exposes another latency gap: sched2 moves an independent
return-address restore between a field load and address formation. Correct copy size
alone did not qualify its epilogue; a repaired tail with scheduling disabled changed
the prologue instead. Its measured reopening conditions remain in the blocker notes.

Stack layout is separate: `func_L00_0032A1A8` needs one `char buf[32]` for `sp+0`
and `sp+0x10`; two separate locals reverse their placement.

## Quadword zero stores

### Default fold and live return values

[fold_zero_ti_store.py](../tools/compiler/transformers/fold_zero_ti_store.py) folds a
materialized zero to `sq $zero,0(reg)` only for a bare register address and no other
live reader. Its bounded search stops at calls/jumps/labels and looks back at most
twelve instructions. Shared zeros feeding several stores keep their register.
Displaced stores keep por and register-source sq even when the zero dies there.

The fold runs after reload **before sched2**, through
`MACHINE_DEPENDENT_REORG_AFTER_RELOAD`. Running it later changes `func_002E5FE0`'s
loop store order. Positive controls: `func_00282C88` (8 bytes), `func_002E5FE0`
(168). Negative control: three-store family `41eb487e64fb6b76`. Displaced-store
witnesses: `func_L20_0044AB68` (204), `func_L20_00443908` (264),
`func_L00_003ACC88` (112 at 27 places).

[fold_zero_ti_return_value.py](../tools/compiler/transformers/fold_zero_ti_return_value.py)
admits exactly one reconstructible function-value USE of that same
`REG_FUNCTION_VALUE_P` register, without an intervening call/jump. The store fold
and conversion of USE back into an explicit zero return SET form one
`validate_change`/`apply_change_group` transaction. If either is unrecognized,
abandon both. Other readers still prevent the fold.

Ignoring USE without restoring the zero return silently returns a preceding call's
value. Re-admitting J globally in `movti_internal` also regresses shared-register
stores by letting CSE substitute zero everywhere. The retired
`allow_zero_ti_store.patch` must not be restored. These are correctness conditions,
not harmless one-word differences.

### Clear scheduling and materialized stack zeros

| Option | Effect | Limit |
| --- | --- | --- |
| -frac2-zero-ti-barrier | Selected isolated zero stores get a scheduling barrier | The pre-reload heuristic also selects some displaced clears; it is not a recovered macro detector |
| -frac2-zero-ti-por | Suppress zero folding at bare 0($sp) | Other register addresses still fold; mixed forms at the same address cannot be distinguished per file |

[zero_ti_store_barrier.py](../tools/compiler/transformers/zero_ti_store_barrier.py)
selects before reload an isolated const-zero TImode store between calls/labels/jumps;
shared zeros keep normal C lowering. After reload it selects an architectural-zero
TImode store. Lowering ready cost alone did not reproduce the dependences.
`func_L00_003BFF68` matches 12/12 with the switch and 0/12 without it.

[zero_ti_por.py](../tools/compiler/transformers/zero_ti_por.py) is a statement about
a unit's stack clears, not a detector. The control-flow-aware retail census found
183 register-fed zero stores in 153 functions, all at `0($sp)`, but also 396
architectural-zero stores in 263 functions, including 82 at `0($sp)`. The address
alone cannot decide the form a particular function needs.

Witnesses include `func_L02_003DB200` (236 bytes), `func_L02_00423520` (788),
`func_L23_00422798` (532), `func_L02_003DBA70` (252), `func_L23_00429DC8` (560):
2,368 bytes at five places. The first needs a scalar, rather than an incomplete
array declaration, for its absolute load. The last also needs measured payload,
store and halfword ordering and its closing loop's independent counter.
The fno forms restore defaults. A nonzero offset, computed stack address or mixed
forms at the same address remains distinct: `func_L07_003E4BD0` mixes both at
`0($sp)`, and `func_L02_003E7370` exposes the displaced-clear scheduler heuristic.
Combining both switches affects sched1/sched2 differently and needs its own proof.

## Control flow and delay slots

### Useful C shapes

- Read branch direction and operand width: signed countdowns and unsigned increment
  loops need not share a layout. A switch can retain branches that if/else folds
  into sltu/xori/conditional moves (`func_L18_002E4090`).
- A single final return after a guarded body can preserve the saved-pointer move
  (`func_L00_00338D28`). An early null return changes the exit structure.
- A named threshold can retain addiu+slt where a literal becomes slti:
  `func_L00_00410840` needs this at its lower thresholds, not the highest test.
- `x = load; if (flag) x = 0.0f;` differs from a ternary in branch polarity and
  likely slots (`func_L00_0042A460`). Store order affects allocation, but there is
  no universal reversal or permutation rule.
- A delay-slot store runs **before** the callee. Put the source write before the
  call (`D_L00_001B0CA0 = obj` in `func_L00_004005B0`).
- **All branch-likely forms execute their slot when taken and annul it when not
  taken**, including beql/bnel and bc1tl/bc1fl. Earlier opposite statements were
  wrong. A jal slot also executes before control enters its callee.
- Loop heads/jump tables can receive eight-byte `.p2align 3`, ordinary merge labels
  four-byte alignment. Preserve genuine structure; an artificial empty loop is
  not an acceptable alignment device.
- Initializing a counter after its guards, retaining real guard/walk variables,
  a found-block break instead of return, or indexing rather than pointer walking
  can reproduce a specific loop (`func_002EE6E0`, `func_002ED368`). Duplicating a
  genuine tail can preserve another layout (`func_00116300`). Stop unchanged
  retries under AGENTS.md rather than treating these examples as universal rules.

One measured zero-valued guard uses `x & ~x` in a different block from the test:
this old front end leaves that expression for combine, after GCSE, so GCSE does
not propagate a constant zero into the loop. Same-block CSE folds it earlier.
The observations on `func_L20_0039E0A0`, `func_L20_0039DBC8`,
`func_L20_00440398` and `func_L20_0044AC38` describe pass ordering, not permission
to add a fictitious guard just to prevent optimization.

### Compiler control-flow passes

[tidy_condjump_fallthru.py](../tools/compiler/transformers/tidy_condjump_fallthru.py)
lets flow remove a conditional jump to its immediate successor and its now-dead
input load. The rule follows GCC fixes from April/August 1999; witnesses include
`func_L02_003FD070`, `func_L02_003FC268`, `func_L02_003FC518`, `func_L02_003FD228`,
`func_L02_003CD4A8`, `func_L02_003CD298`.

| Per-file option | Change | Witnesses |
| --- | --- | --- |
| -frac2-gcse-unsplit-edges | Build predecessor/successor lists without Cygnus critical-edge splitting; PRE inserts at the preceding block | func_L02_003E79F8, 352 bytes/1 place; func_002CD720, 340/28 |
| -frac2-keep-block-order | Skip cygnus_merge_blocks; keep default-last switch body and its branch | func_L18_004283F0, 56 bytes/3 places |
| Both | Compose the two independent changes | func_L02_003FCCA0 |

Implementations: [gcse_unsplit_edges.py](../tools/compiler/transformers/gcse_unsplit_edges.py),
[keep_block_order.py](../tools/compiler/transformers/keep_block_order.py). These are
inferences from retail and comparison with GCC 2.95, not the recovered original
patches. A lone lui at a branch target is not a unique signature of edge splitting.

### Wide stores and annulled slots

[no_annulled_wide_stores.py](../tools/compiler/transformers/no_annulled_wide_stores.py)
adds `-frac2-no-annulled-wide-stores`. Thread search stops at a wide store that
cannot occupy an ordinary slot; target-delay-list stealing refuses it for an
annulled slot. Searching past the store selects a different instruction.

This default-off policy is **not a hardware prohibition**. Ordinary slots and
`optimize_skip` remain unchanged: matched `func_00116460` has two bnel/sd pairs.
The original 7,825-function game census found no sd/sq in branch-likely slots,
497/547 in ordinary slots, and wide loads in likely slots. SDK/handwritten code
was excluded; do not promote a scoped census into an ISA rule.

Witnesses: `func_L23_00422668` (300 bytes/1 place, also qcopy) and
`func_L02_0042EDD0` (476/2, -G8 and zero-ti-barrier). Ordinary wide stores, scalar
stores and wide loads are controls. The fno form disables the option.

## Floating-point instructions and hazards

### Literals and min/max

Compare actual constant words rather than rounded mathematical values. Measured
retail examples include `1.0471977f` (`0x3F860A93`) and `0.78539824f`
(`0x3F490FDC`). The old assembler also converted some long decimal spellings
unexpectedly; check the final lui/ori/mtc1 words before blaming allocation.

Min.s/max.s **are reachable with -ffast-math**: fold admits floating MIN/MAX_EXPR
under that option. `func_L01_003BD560` is a min.s witness. For the 8-byte maximum
`func_L00_002EE050`, -O1 -ffast-math retains the argument registers, whereas -O2
adds a move and gives 12 bytes. The older blanket impossibility claim is false.

### Transfer hazards

Mtc1 uses the next instruction's FPR read, not distance from the GPR's last write.
The expanded retail survey found 915 immediate dependencies: 897 delayed, 18 not;
the original 598 sites (587 delayed) are a subset. Cleared assembler history can
occur within a function and is not a function-boundary detector.

[u4_mtc1_helper.py](../tools/compiler/transformers/u4_mtc1_helper.py) and
[restrict_mtc1_exemption.py](../tools/compiler/transformers/restrict_mtc1_exemption.py)
retain two measured cleared-history exemptions: a0 to f0 before cvt.s.w f0,f0,
and zero to f0 before c.lt.s f12,f0. Eight first-transfer witnesses split four
requiring a nop and four not. A distance-two producer rule failed `func_002A7878`.

Ten original no-nop sites in `0x00283C28`, `0x002A677C`, `0x002E0408`,
`0x002E0558` can also be reproduced with explicit instruction ordering; ISA
selection offers another sufficient mechanism. Original directives remain unknown.
The private 89-case fixture history does not qualify every transfer in the game.

Mfc1 is interlocked on R5900: the measured boot text had 88 immediate readers in
47 functions; its only extra-nop example used handwritten VU code.
[r5900_mfc1_interlock.py](../tools/compiler/transformers/r5900_mfc1_interlock.py)
removes the MIPS-I coprocessor-load delay in append_insn for mfc1 only. Cfc2 and
label padding are not waived. `func_002ED4B8` and `func_00290680` match at 28 places.

### Labels on hazard nops

[hazard_labels.py](../tools/compiler/transformers/hazard_labels.py) adds
`-frac2-hazard-labels`: cc1 emits `.set rac2_hazard_labels`, and gas retains labels
on the needed nop rather than moving them behind it, including the noreorder
flush. This connects a per-file option to the assembler without patching output.

The retail census found 198 relevant targets in 148 functions (71 compares,
127 mtc1 readers), all forward and on the nop. Aligned loop-head fill whose next
instruction does not read the producer is not a hazard counterexample. No needed
target reached only backward, or branch target after ctc1/cfc1/COP2, was sampled.

SN 2.0 authored controls retained labels for forward/backward branches, j, data
.word references, multiple labels, li.s and alignment. This supports the rule,
not the shipping assembler's identity. Witnesses: `func_L18_004308F0` (1,384/1),
`func_L02_00411530` (80/7). The fno option restores default behaviour.

### Division/root scheduling and padding

Compose these three mechanisms; none replaces the others:

1. [neutralise_div_dslot.py](../tools/compiler/transformers/neutralise_div_dslot.py)
   keeps single-precision division/root operations out of compiler-selected delay
   slots. Retail had 0 of 19,806 div.s in slots, but 61 integer HI/LO divisions.
   Sqrt.s/rsqrt.s are extrapolated: neither occurred in that retail census and GNU
   as does not assemble rsqrt.s.
2. [pad_div_erratum_nops.py](../tools/compiler/transformers/pad_div_erratum_nops.py)
   models a measured SN 3.01 two-slot incoming floor after code labels for div.s,
   sqrt.s and rsqrt.s. Needed hazard nops count toward it; labels stay on padding.
   Sync.p imposes one nop, unlike sync/sync.l.
3. [pad_div_erratum_branch.py](../tools/compiler/transformers/pad_div_erratum_branch.py)
   extends the floor to branch groups: bc1t/ld/div.s gains two nops; one intervening
   instruction gains one, two gain none. Conditional/likely branches and b trigger
   it; j/jal/jr/jalr do not. Integer division is unaffected. It consumes the label
   transformer's anchors, so order matters.

The genuine SDK 3.01 oracle Ps2EeAs has SHA-256
`cb5adda955e64626564212ef7e0c1434708c4e1ef423344a92ec8033306ed3aa`.
The SN 2.0 full-image assembler has SHA-256
`c839dd63facabe7b76573c114056be61eaa7b3aa2329dd546930ab8f98898c76`.
They disagree on 44 of 97 synthetic outputs; neither is proven to be the shipping
assembler, and a matching subset does not establish equivalence to both.

The strict 97-fixture battery gave **84 pass, 13 fail, 0 error**, comparing text,
labels, branches, delay words and relocations. An earlier 49-case subset reached
47 strict passes after fixing eleven displaced labels. Remaining failures: two
integer macros, two local-relocation addends, three post-division noreorder hazards,
four other SDK-version-dependent noreorder cases, and two cross-fragment
alignment/.word-distance cases. No masking/cropping converts these into matches.

SDK 3.01 **warns and still returns success** when it cannot pad a branch delay
slot; it does not refuse object creation. General fragment/alignment behaviour
and ordinary noreorder padding are not established. Many retail pre-division nops
follow sequences the oracle does not pad and need a separate source/compiler
explanation. A correct division region did not make the retained 572-/220-byte
witness families match.

## 64-bit immediates and SDK helper types

Patch 0052 selects bounded R5900 dli value classes:

| Class | Expansion or boundary |
| --- | --- |
| Isolated sign bit | Signed default addiu -1, then dsll32 31 |
| Sign bit plus contiguous low run of at least 32 ones | Existing sign-extending lui path |
| Positive contiguous run wider than 32 bits, zero at both ends | Shift construction: three instructions for 0x0FFFFFFFFFFFFFFE instead of seven |
| Runs at most 32 bits, holes, neighbouring masks | Preserve previous paths; 20-bit 0x00FFFFF000000000 must stay unchanged |

The selector uses unsigned arithmetic without division/undefined shifts and is
keyed to a value class, never a game address or function. SDK-profile witnesses:
`_fpadd_parts` / `func_00122800` (576 bytes), `_strtol_r` / `func_00117278` (884),
`__pack_d` / `func_00122630` (300). Do not substitute the game profile.

`dpmul` / `func_00122B00` (680) needs the public fraction union in the shared
24-byte DoubleParts declaration:

```c
union { unsigned long long ll; unsigned int l[2]; }
```

Its member access has alias-set zero under the SDK compiler. Restoring the union
creates the real store dependence for rounding and the bnel fraction-store slot.
The scalar simplification lost that dependence; barriers/pins are not a remedy.
Four existing users retained identical object sections. Disabling sched1 fixed
only the tail and grew it to 688 bytes; disabling sched2 changed the prologue.

Two sign-bit loads need a zero-extending seed. Patch 0059 exposes per-object
`--r5900-sign-bit=unsigned`; pass it with `-Wa,--r5900-sign-bit=unsigned` in the
same per-file flag table. Explicit signed restores default; invalid/missing values
fail. Same value does not mean the same retail encoding.

## Reading output and identifying limits

Compare R5900 words and resolved relocations, not mnemonics alone. Move can become
daddu; immediate addu becomes addiu; immediate sltu becomes sltiu. R5900 c.lt.s
and generic-MIPS c.olt.s may name the same word. A listing may display raw file
bytes in opposite order from a numeric instruction word.

Mult/mult1 can write a GPR: decode rd (bits 15-11) and follow its consumers.
Missing mflo does not imply a dead multiply. Por, lq/sq, unaligned doubleword
transfers and broad MMI prefixes alone are not handwritten-code evidence. Neither
compiler supplies a sync pattern; ASM_FUNC classification still needs the
evidence/review required by AGENTS.md.

A positive stack adjustment at an entry may be residual epilogue/fill. Establish
surrounding flow/returns and incoming references; missing jr alone is insufficient.
Change the generator in tools/levels.py, never the generated catalogue by hand.

Tools/check.py can pass while linking fails: other local C sections, symbol-value
consistency and data placement are whole-program constraints. A C switch's new
.rodata/.sdata can be unplaceable. A table already in retail can use its measured
symbol and computed goto; a static label-address array keeps legitimate arms in
discarded data. It must describe the right arms and earns no matched-data credit.
Do not assume every jtbl_/D_ spelling binds identically across releases.

## Qualification and controls

Rebuild the complete recipe after toolchain changes. Compose transforms, rather
than restoring an earlier file that drops a division/frame/zero fix. The recipe
pins sources, checks insertion points and runs authored EE controls. Never edit
generated compiler output.

For opt-ins compare default, enabled and explicitly disabled modes, including
negative controls; then compare the same configured corpus under both tools.
Separate non-debug differences from .mdebug. Synthetic fixtures have no retail
oracle, and a same-size draft screen is not a match or current progress.

| Mechanism | Maintained controls |
| --- | --- |
| Zero folding/clear scheduling | [test_zero_ti_store.py](../tests/test_zero_ti_store.py) |
| CSE edges/block order | [test_gcse_unsplit_edges.py](../tests/test_gcse_unsplit_edges.py), [test_keep_block_order.py](../tests/test_keep_block_order.py) |
| Copies and RTL contract | [test_qcopy.py](../tests/test_qcopy.py), [test_qcopy_rtl.py](../tests/test_qcopy_rtl.py) |
| Copy scheduling | [test_qcopy_barrier.py](../tests/test_qcopy_barrier.py) |
| Annulled wide stores | [test_no_annulled_wide_stores.py](../tests/test_no_annulled_wide_stores.py) |
| Stack por form | [test_zero_ti_por.py](../tests/test_zero_ti_por.py) |
| Masks/sign seed | [test_dli_masks.py](../tests/test_dli_masks.py) |
| Hazard labels | [test_hazard_labels.py](../tests/test_hazard_labels.py), [hazard_labels.s](../tests/fixtures/hazard_labels.s) |

Copy controls cover volatile/unaligned/scalar/quadword memory, calls, integer/FP
branches, loop placement and complete pairs outside slots. Clear controls cover
shared/live/returned zeros and signed displacements. The mask test covers 465
positive long-run intervals in four registers plus 30 boundary controls: 1,980
outputs in each default/signed/unsigned profile.

Historical same-source scopes measured on 21 October 2026, not current totals:

| Change | Scope and result |
| --- | --- |
| Clear scheduling | 767 preceding units: 756 identical, ten debug-only, one witness code change |
| Displaced zero fold | 775 preceding units: no non-debug change, eleven debug-only |
| CSE/block-order options | 775 preceding units: identical with options off, individually forced and combined |
| Grouped copies/masks | 779 units: four new witness units change non-debug sections; eleven debug-only |
| Positive long-run masks | 780 units: only new double-adder changes non-debug sections; eleven debug-only |
| Fraction union/sign seed | 781 units: only new multiplier changes code; eleven debug-only |
| Hazard labels | 779 other units: no code change even when forced; one debug-only |
| Copy barrier | 794 preceding units plus twelve default witnesses identical; forcing eight existing qcopy units also changes none |
| Wide-store policy | 796 preceding units: default unchanged; forced option changes only two new witnesses |
| Stack por option | 806 preceding units: default unchanged; forced option changes four former architectural-zero stack-clear units |

These scopes qualify mechanisms, not an unknown shipping toolchain. Default
neutrality does not prove that enabling an option in another unit is safe.

Final acceptance is tools/build.py with --strict for every affected program: all
C placements accepted and every loaded byte, segment property and entry point
equal to the matching private reference. Check every applicable release under
VERSIONS.md. Progress consistency uses --check; regeneration is separate.
Keep unresolved attempts and reopening evidence in nonmatching/ and the shared
blocker document, rather than appending session diaries here.
