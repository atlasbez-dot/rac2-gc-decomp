# Matching blockers

This is the shared, versioned reference for matching blockers and measured remedies.
**Every contributor may edit any entry**, including findings originally written by someone
else. Work in this repository through a fork or topic branch and submit a pull request.
Maintainers review and merge contributions; they are not the only people who can write here.
A coding AI can edit this Markdown file with ordinary file and Git commands.

Discuss proposed changes in the relevant code or documentation PR.
[Issue #157](https://github.com/OpenRAC/rac2-gc-decomp/issues/157) is retired and preserved
only as historical provenance. [Issue #152](https://github.com/OpenRAC/rac2-gc-decomp/issues/152)
remains the reservation noticeboard. Neither a personal comment nor the wiki is a second knowledge
register. The code and qualified linked builds remain the authority for matching status.

## How to contribute

1. Read the relevant entry, `AGENTS.md`, the retained C in `nonmatching/` and current master.
   Reopen an attempt only with a new hypothesis, changed input or additional evidence.
2. Edit the existing entry directly in your branch. Add a section only for a distinct blocker.
   Do not create one file or one record per contributor, agent, session or experiment.
3. Record the target/family, applicable release and placements, compiler/assembler profile,
   hypothesis, measured outcome, remaining difference and next useful experiment. Negative
   results are useful when they rule something out; repeated identical attempts add no facts.
4. Distinguish **hypothesis**, **retained near miss**, **local match**, **PR pending** and
   **merged fix**. Link the PR/commit and the real checks. Equal size is not a match. Preserve
   superseded measurements as dated history and explain which later evidence supersedes them.
5. Submit a normal PR, in English. Anyone can propose a correction to any entry. Only the
   merge is reviewed by a maintainer; no special documentation ownership is required.

Keep game data, generated assembly, SDK material, trial objects and logs private. Do not
copy them into a PR or this document. Knowledge edits do not waive the source policy or
matching gates. Discuss an uncertain finding in the relevant PR, then incorporate the
agreed result here. A persistent personal issue comment is no longer required for blocker notes.

## Recent verified updates

The imported observations below are dated measurements, not a fresh census. In particular,
older claims that the following mechanisms are universally impossible are superseded:

| Topic | Verified update |
| --- | --- |
| Vector-copy address formation and scheduling | [#262](https://github.com/OpenRAC/rac2-gc-decomp/pull/262) and [#275](https://github.com/OpenRAC/rac2-gc-decomp/pull/275) provide opt-in copy profiles. They solve qualified witnesses, not every copy/allocation case. |
| Wide-store annulled slots | [#279](https://github.com/OpenRAC/rac2-gc-decomp/pull/279) restricts two search paths with an opt-in profile; it is not a hardware prohibition. |
| A register-fed clear of `0($sp)` | [#281](https://github.com/OpenRAC/rac2-gc-decomp/pull/281) is merged; older source notes calling it proposed are historical. |
| `_fpadd_parts` and `dpmul` | [#265](https://github.com/OpenRAC/rac2-gc-decomp/pull/265) and [#267](https://github.com/OpenRAC/rac2-gc-decomp/pull/267) are merged SDK-profile matches. |
| `game/00308600` follow-up | [#287](https://github.com/OpenRAC/rac2-gc-decomp/pull/287) adds `func_0030E700`, 424 bytes at 28/28 places in each USA release, with 28 strict programs per release and 139 tests passing. `func_00308600` remains retained at 356/360 bytes, 0/28 USA v1.01 places. |

These summaries do not award additional matching credit or replace the build. Check current
source before relying on any older count, profile or pending-PR label in the imported notes.

## Topic index

The 52 original section numbers are preserved for existing references. Anyone may improve
these entries; their original authors do not hold exclusive editing ownership.

| Entry | Topic |
| --- | --- |
| [01](#blocker-01) | Register allocation on long bodies (the dominant wall) |
| [02](#blocker-02) | LICM: the retail re-materialises a base inside a loop |
| [03](#blocker-03) | If-conversion |
| [04](#blocker-04) | `nop` before `jr $ra` |
| [05](#blocker-05) | `nop nop` before `div.s` |
| [06](#blocker-06) | Switch tables that travel with the function |
| [07](#blocker-07) | Annulled integer branch delay slots |
| [08](#blocker-08) | Single-register `%hi`/`%lo` addresses |
| [09](#blocker-09) | Folded addresses where retail materialises the base |
| [10](#blocker-10) | Equal-address branch folding |
| [11](#blocker-11) | MMI and undecodable words |
| [12](#blocker-12) | A catalogue entry whose body differs between programs |
| [13](#blocker-13) | Floating-point literals are calibrated, not computed |
| [14](#blocker-14) | Store order is not one universal rotation |
| [15](#blocker-15) | A `nop` after `mfc1` that retail does not have |
| [16](#blocker-16) | If-conversion of constant selections |
| [17](#blocker-17) | A 128-bit zero: por plus sq against sq zero |
| [18](#blocker-18) | Catalogue entries that are not functions |
| [19](#blocker-19) | The delay slot's filler is chosen by the scheduler, not by you |
| [20](#blocker-20) | Two exits where cc1 keeps one |
| [21](#blocker-21) | Varargs: the saveregs prologue is exact, the call is not |
| [22](#blocker-22) | Vector copies: address materialisation is only part of the mismatch |
| [23](#blocker-23) | Keeping a branch in step with master (tooling, not a wall) |
| [24](#blocker-24) | Prologue and entry-block ordering |
| [25](#blocker-25) | Small constants: rematerialised against reused (both directions) |
| [26](#blocker-26) | A dead store or dead load that retail keeps |
| [27](#blocker-27) | The missing `andi reg,0xFF` |
| [28](#blocker-28) | Commutative `addu`: base first against index first |
| [29](#blocker-29) | Loop-form canonicalisation: countdown and one-step unroll |
| [30](#blocker-30) | Loop-alignment padding |
| [31](#blocker-31) | lui at / low-half access: an existing per-file profile |
| [32](#blocker-32) | The output for a body depends on the other functions of its unit |
| [33](#blocker-33) | The 64-bit difference in specific attempts |
| [34](#blocker-34) | The catalogue's fingerprint merges two bodies |
| [35](#blocker-35) | The catalogue's linker-fill rows |
| [36](#blocker-36) | -mno-split-addresses also keeps some symbol addresses together |
| [37](#blocker-37) | Decode the exact R5900 instruction, not a broad prefix |
| [38](#blocker-38) | What this cc1 has no spelling for |
| [39](#blocker-39) | Source shapes that moved a body |
| [40](#blocker-40) | Smaller things worth knowing |
| [41](#blocker-41) | The productive route |
| [42](#blocker-42) | Register-allocation ties: a stopping signal for tested forms |
| [43](#blocker-43) | Block ordering: distinguish source structure from unavailable flags |
| [44](#blocker-44) | Relocated instructions are validated in a separate pass |
| [45](#blocker-45) | Source shapes that move a body |
| [46](#blocker-46) | The `dli` expansion of all-ones masks |
| [47](#blocker-47) | Catalogue filler rules applied; mixed prefixes remain separate |
| [48](#blocker-48) | The wave 12 census: historical sample, not today's inventory |
| [49](#blocker-49) | The wave 13 census: correct the screens before selecting work |
| [50](#blocker-50) | Five specifically audited residual extents — resolved by PR #253 |
| [51](#blocker-51) | The wave 14 census: a call inside one object, and a screen that was too broad |
| [52](#blocker-52) | What a C body cannot carry: the measurement, and the rule |

The following material was moved from issue #157 on 22 October 2026 (UTC). Its dates,
counts and conclusions retain their original scope. The old issue summary is retained
below as historical context; the newer verified updates above take precedence where they
explicitly supersede it. Earlier issue revisions and original contributor comments remain
available through GitHub history and their source links.

## Imported issue observations and historical measurements

## Status — 21 October 2026

The numbered history below is retained, with obsolete conclusions and incorrect mechanisms corrected directly. A historical failure applies to its source, compiler, profile and placements; it does not prove that a whole instruction class is unreachable from C.

| Topic | Current status |
|---|---|
| Extra nop after mfc1 | Resolved by the qualified **gas** interlock correction in [PR #222](https://github.com/OpenRAC/rac2-gc-decomp/pull/222). [Issue #247](https://github.com/OpenRAC/rac2-gc-decomp/issues/247) is closed as completed following strict validation. The named witness func_L22_003A2DF8 passes 2/2. |
| Cache invalidation and assembly fallback | [PR #252](https://github.com/OpenRAC/rac2-gc-decomp/pull/252) is merged. Toolchain changes invalidate objects; `tools/build.py all --strict` rejects C fallback to assembly. |
| Catalogue filler/residues | Earlier measured rules landed through [#239](https://github.com/OpenRAC/rac2-gc-decomp/pull/239)/[#241](https://github.com/OpenRAC/rac2-gc-decomp/pull/241). [PR #253](https://github.com/OpenRAC/rac2-gc-decomp/pull/253) is now merged for the five specific extents in section 50 and matching level placements. Other mixed boundaries remain separate. |
| Clear scheduling | [PR #251](https://github.com/OpenRAC/rac2-gc-decomp/pull/251) is merged: `-frac2-zero-ti-barrier` is qualified, default-off and per file. It does not solve every single-zero/nonzero-offset case. |
| Displaced zero stores | [PR #258](https://github.com/OpenRAC/rac2-gc-decomp/pull/258) corrects the fold from [issue #248](https://github.com/OpenRAC/rac2-gc-decomp/issues/248): only a register-only store address can fold to architectural zero. A/B over 775 preceding units found zero non-debug section changes and 11 `.mdebug` differences. Three clean witnesses match 204/204 bytes at 1/1, 264/264 at 1/1, and 112/112 at 27/27. The final tree passes all 28 programs with --strict and all 57 tests. Vector-copy address materialization remains open. |
| Reviewed source additions | [PR #246](https://github.com/OpenRAC/rac2-gc-decomp/pull/246) is merged at 5f4ced8; [PR #249](https://github.com/OpenRAC/rac2-gc-decomp/pull/249) at 8444cb6. [PR #244](https://github.com/OpenRAC/rac2-gc-decomp/pull/244) is merged at fc02388 with 38 additions across 307/307 placements. The combined strict build passes all 28 programs with no rejected C placements. |
| Diagnostics and source-policy checks | [PR #257](https://github.com/OpenRAC/rac2-gc-decomp/pull/257) is merged. The differ explicitly decodes R5900 instructions, tests cover EE operands and relocated instruction bits, and the repository check rejects empty source barriers. AGENTS.md now distinguishes missing returns and live three-operand multiplies from evidence of fragments or handwritten code. |
| Old examples rechecked | 27 already-C witnesses cited below pass 192/192 placements under the qualified compiler. Other named cases were covered by the PR #244/#246 touched-unit reviews. These results resolve those examples, not every similar historical near miss. |

**Acceptance is the full linked build with every expected C placement accepted.** Use `tools/build.py all --strict`; an image rebuilt with assembly fallback is not a new C match. Inline assembly, fake barriers, register pins, fabricated symbol identities and knowingly false prototypes are not remedies. Missing jr, mult without mflo, or por/lq/sq/ldl/ldr alone does not establish handwritten assembly or a catalogue fragment.

**Historical scope.** The original 12 October report covered six waves, approximately eight workers in each of the first five and 49 in the sixth, 521 functions in all (PRs #149/#151/#153/#155/#156/#159). Wave 8 added 40 workers and 122 attempts. Later counts describe later dated samples, not today's unfinished-work inventory.

<a id="blocker-01"></a>

## 1. Register allocation on long bodies (the dominant wall)

Historically 148 of 240 notes mentioned allocation disagreements. A common signature was identical instruction order/size with different caller-saved registers, or an entry copy coalesced away. The approximate 250-byte threshold was a sample observation, not a compiler limit.

Named counterexamples now pass: func_L09_004081F0 and func_L12_0041BDF8 each 1/1; func_L17_003E6F20 1/1; func_L22_003A2CB8 2/2. Other examples included func_L01_00416B30(five unsuccessful attempts), func_L07_003F8C38(a declaration-order observation), func_L20_00444018, and func_L00_00409480. Their status is not inferred from these successes.

The wave 8 allocator investigation remains useful: global.c prioritizes approximately floor_log2(n_refs)*n_refs/live_length, with loop-weighted references; cc1 -dl exposes refs/live_length. In two samples, changing actual references moved a saved-register assignment while 15 declaration permutations did not. Inspect real live ranges and distinct pseudos before editing reference counts. Several identical compiles justify stopping one approach, not declaring every other meaningful source/profile impossible.

<a id="blocker-02"></a>

## 2. LICM: the retail re-materialises a base inside a loop

**Signature:** retail emits `lui $r,%hi(D)` + `lw`/`addiu` *inside* the loop body; cc1 hoists the address into a callee-saved register, so the loop loses an instruction, the 8-byte alignment `nop` before the label disappears, and the frame grows by two saves.

**Measured:** `for` and `do/while` both fold. Those tested loop forms did not move the original attempts. Later source/profile remedies mean this is not a universal impossibility claim; wave 8 recorded the two observations below.

`__attribute__((sda))` in a `-G0` file on an **absolute** symbol stops the hoist: `lui %hi ; lw %lo` stay inside the loop as retail has them (side effect: the prologue's index/base register pair swaps). And there is a sub-case of its own: an **absolute global addressed in a loop that contains calls** - cc1 hoists the address into a callee-saved register (`lui $s1,%hi`, frame 0x20, two extra saves) where retail re-materialises `lui $v1,%hi ; lw $v1,%lo($v1)` at every iteration with one register (`func_L11_00440868`, one instruction off; `func_L11_004411C8`, 8 bytes off - bodies otherwise identical instruction for instruction). In those tested units the attribute produced an unwanted `$gp` form; qualify the actual unit instead of generalizing the declaration rule.

<a id="blocker-03"></a>

## 3. If-conversion

**Signature:** a trailing `if (X) r = 1;` in an if/else chain comes out as `sltu`/`xori`/`sltiu`/`movz` where retail keeps `beql`/`bnez` plus the assignment in the delay slot; or `if (X) return A; return B;` folds to `movn` where retail keeps the branch.

**Workarounds that worked:** a `switch` keeps the retail shape in some bodies; `if (...) goto done;` with one shared `done:` label keeps two separate compares where `&&` folds them into a range test; `if (c) GLOBAL = A; else GLOBAL = B;` (two memory stores) keeps the branch where the local-variable form is if-converted.

**What is not if-converted:** `movz`/`movn` are emitted by this cc1 (`c ? a : b` gives `movz $2,$5,$6`, `if (b) r = 0;` gives `movz $2,$4,$5`), so a retail body that uses them is reachable - the shape to try is section 16's, not a constant selection.

<a id="blocker-04"></a>

## 4. `nop` before `jr $ra`

**Scope:** these load/return/label observations are separate from the resolved mfc1 case (section 15) and the qualified `-mastra-split-trunc-slot` profile (PR #184). A historical volatile experiment is not authorization to invent a memory effect for matching.

**Signature:** retail has a residual load-delay `nop` then fills the branch slot (`lwc1 ; nop ; jr $ra ; mul.s`); the pinned compiler emits the compact three-instruction form. A single-word discrepancy; reachability requires actual control-flow evidence.

**Not always a wall:** `*(volatile TI128 *)out = *(TI128 *)p0;` makes the two missing `nop`s reappear in the two early-return delay slots - measured on the three members of the family `2ae8dc3c64a3dcc0`: 280 bytes without, 288 (exact) with.

**A second form of the class stays a wall:** on `func_L02_00411530` the missing `nop` is a **cop1 latency fill between `mtc1` and `sub.s`**, and retail places the join label *before* it while cc1 glues the nop to the reload. Twenty-nine source variants tested, none moves the label.

<a id="blocker-05"></a>

## 5. `nop nop` before `div.s`

Several historical attempts lost two nops before float division. This is not uniformly unreachable today: compiler notes describe qualified division-padding rules and a separate debug-label remedy. `func_002B5EF8` uses a dedicated `-g` unit with division on its own source line, allowing gas to reproduce label-related padding.

Other division/label-boundary failures remain bounded near misses. Retain exact source, line layout and profile; do not add dummy instructions or manual padding.

<a id="blocker-06"></a>

## 6. Switch tables that travel with the function

Five early-wave bodies passed quick checks but failed full placement with “needs .rodata at its place, which is not C.” Generated rodata/sdata dependencies remain a linking limitation; strict mode rejects fallback. A named retail table is different, but its dispatch match alone does not validate every computed-goto target or internal case-label placement.

A switch's comparison tree is also a separate source problem: func_L19_00423CC0 resisted the tested case permutations, whereas explicit comparisons/gotos matched func_L20_00442C10. Wave8 associated one tree form with three labels, one sharing default; this is a bounded recipe.

Historical boot candidates func_00119BF8(3072 bytes, table 0x13A7B0) and func_00118D98(3368 bytes, table 0x13A6C0) remain markers. The recorded binary comparison distinguished their vfprintf-family implementation from the public newlib tree: PRINT used memcpy/writer calls instead of iovecs/sprint; cvt returned via a static buffer rather than a digit pointer; the observed Inf/NaN strings differed. func_001185E8's attempted reconstruction was 1508 versus 1496 bytes. These are historical implementation clues, not permission to use prohibited SDK sources or headers.

<a id="blocker-07"></a>

## 7. Annulled integer branch delay slots

Historical mismatches involved bnel/beql with a taken-path slot where retail used a normal branch and fall-through work, often one word different. The wave 9 correction counted 342 then-matched functions containing a likely branch: the compiler does emit them from ordinary C. That count is historical, not today's corpus size.

Hoisting genuinely shared work before the condition changed slot selection in some bodies. It is a measured source lever, not a guarantee that every likely branch can be rewritten to a normal one. Five workers had previously discarded 9, 10, 11, 14 and 15 targets using that signature alone; those exclusions were not justified without exact decoding/profile checks.

Integer BEQL/BNEL execute the slot on taken paths and annul it on non-taken paths. The earlier unconditional/inverted-slot claim is withdrawn. This was checked against the [official PCSX2 R5900 interpreter](https://github.com/PCSX2/pcsx2/blob/0f71e668b8adc950db7de1b1b15c2f5080c102e9/pcsx2/Interpreter.cpp#L387-L410), not a new hardware experiment. Do not generalize this statement to a differently decoded instruction.

<a id="blocker-08"></a>

## 8. Single-register `%hi`/`%lo` addresses

**Signature:** retail may use base == destination, a separate address register, a `$at` macro, or `$gp`. Declaration type/size, unit flags, cc1 output and assembler macro context all participate. Earlier waves inferred contradictory universal rules from different units; those universal rules are withdrawn.

**Measured levers:** scalar/array forms, complete/incomplete array size, sda/nosda, a -g8 sibling, and per-file -mno-split-addresses. Check every existing C function using an affected declaration: historically one attribute change turned an existing 2/2 into 0/2 and was reverted.

The historical sample is retained: 47 of 240 notes mentioned gp/sda/G8; one 23-target survey used 11 plain-G0, six G0+sda and six G8 units. Those counts are not a selection algorithm. Inspect relocations and retail accesses. GP is 0x001AEFF0 in boot and levels; a small-data declaration needs a known eligible size.

**Current witnesses:** func_L05_0030C930, formerly listed as unresolved, is C, as are func_L05_00444D60, func_L00_00427290 and func_L00_002E73E0. PR #246's func_L20_00444138 passes 1/1 in its dedicated G8/mno-split-addresses unit with separate sda/nosda declarations for one measured bound.

Two documented names may express different addressing forms of one real global. They must derive the same true identity; malformed names, invented addresses or aliases hiding inconsistent bindings are not remedies. PR #244's review corrected such naming defects. Use ref_LNN_XXXXXXXX_kk where a target's identity genuinely varies by placement, not as a substitute for a known correct data name.

<a id="blocker-09"></a>

## 9. Folded addresses where retail materialises the base

**Qualified route:** [PR #262](https://github.com/OpenRAC/rac2-gc-decomp/pull/262) adds the default-off per-file `-frac2-qcopy`
profile for aligned TImode C assignments. It keeps addresses in registers and
groups `lq`/`sq` with a declared temporary; memory flags/alias sets are retained,
unaligned accesses take the ordinary path, and no source asm or memory barrier
is added. `func_L20_0039E158` (140 bytes) and `func_L20_0039F210` (32 bytes) now
match completely. Default folded copies remain intact. Three improved near
misses still differ in ordinary allocation/scheduling; the profile is not an
automatic match for all historical candidates. Issue #248 records the full
scope. All 28 programs pass --strict and all 71 tests pass in the final tree.

**Signature:** retail `addiu $v1,$base,N ; lq/sq $v0,0($v1)` where cc1 folds to `lq $v0,N($base)`. One instruction, and it drags the register allocation with it.

**Not a workaround, on the contrary:** `qcopy(dst, src)` / `qzero(p)` from `include/common.h` do force
the address into a register, but they are inline assembly, and AGENTS.md's "Plain C" rule (no
inline assembly in a function) rules that out as a matching route - docs/COMPILER-NOTES.md says it
explicitly. Seventeen bodies that had been landed with them were removed from `src/` on 2026-10-13
and sit in `nonmatching/` with their notes, waiting for a plain-C spelling. The remaining levers are
`mode(TI)` assignment (offset folded, wrong when retail materialises) and an aggregate/`memcpy`
spelling (neither reproduced it in the waves' attempts). A sibling shape was re-confirmed on the `func_L00_003B0AB0` / `B0A28` / `B0CE8` family in wave 8: retail keeps `lui %hi(D) ; addiu %lo(D) ; addiu rd,rs,CONST` with the constant in a **separate** `addiu`, and all seven source forms tried (`D+0xC+idx*0x1C`, `(char *)&D[idx*0x1C]+0x10`, `((char (*)[0x1C])D)[idx]+0x10`, a local base, ...) folded `D+CONST` into the `%lo`. Those seven forms did not close that family; this is a bounded result, not a proof about every legal source form.

<a id="blocker-10"></a>

## 10. Equal-address branch folding

**Signature:** two case arms whose addresses are algebraically identical (`base+idx*4+0x210` vs `base+(idx-0x14)*4+0x260`) are merged by cc1 into one; retail keeps both branches. The recorded forms did not preserve both arms; this observation alone does not establish universal impossibility.

<a id="blocker-11"></a>

## 11. MMI and undecodable words

The wave 8 correction correctly identified 0x700014A9 as por, not mtsa or an undecodable word. The recorded mtsa zero encoding was 0x00000029. A por-plus-sq zero mismatch remains separate from a decoder error (section 17).

lq/sq are not VU0/COP2 and can be emitted from a TImode C assignment. Four targets were nearly misclassified because the reader used a generic instruction category. Use `rabbitizer.Instruction(word, address, rabbitizer.InstrCategory.R5900).disassemble()`; not every generic INVALID word is lq/sq, so decode each exact word. qcopy/qzero inline assembly is not an allowed matching route.

<a id="blocker-12"></a>

## 12. A catalogue entry whose body differs between programs

**Current scope:** func_L00_00424BB8 remains a marker. The 23/27 report is historical; section 34 describes different field offsets. Re-extract the current extents before changing their grouping.

**Signature:** `tools/check.py` reports a partial count (`23 of 27 places match`) and
`instruction at +0xNN differs` on an `addiu` **immediate** or a **store displacement** - a word
that carries no relocation, so it is a real difference, not the usual unrelocated column. The C
is right in most programs and retail genuinely holds other constants in the rest.

**Measured example:** `func_L00_00424BB8` (`src/levels/shared/L00_004224D0.c`) is `q + 0x60` with
fields `+0xE4/+0xE8` in 23 programs, and `q + 0x20` with `+0x1C/+0x20` in `16_snivelak`,
`22_dobbo_orbit`, `23_damosel_orbit` and `26_jamming_array`.

**Consequence:** placement is per program. Rejected C can fall back to assembly in an affected program while it still prints OK; rejection does not mean every other program dropped the function. Merged PR #252 adds `tools/build.py all --strict`, which rejects fallback. A wave's own count is therefore only true if you read the
`do not match` numbers too. `ref_LNN_XXXXXXXX_kk` cannot help here: it names a symbol *value*,
not an immediate constant. Report the entry and keep the marker in place.

<a id="blocker-13"></a>

## 13. Floating-point literals are calibrated, not computed

The decimal in your C is parsed by the pinned 1999 `cc1` with its own rounding, which does not
always agree with a correctly-rounded decimal -> binary32 conversion. The retail word is what
counts, so read the constant's bits and bisect the decimal until the compiled word is equal -
a placed body is the only proof. The usual way to lose a body by one word is writing the short
decimal that "obviously" means the same (`0.000290888f` for `0.000290888245f`).

Two literals verified against this toolchain, their bodies placed by the build (so `cc1`'s word
*is* the retail word): `0.017453294f` (pi/180) in `src/levels/12_todano/L12_00398E50.c`, and
`0.055268768f` in `src/levels/shared/L01_00397110.c`.

<a id="blocker-14"></a>

## 14. Store order is not one universal rotation

Some historical integer-store blocks emitted the last source store first; blocks interleaving TI/FPU stores behaved differently. Calibrate per block and verify final bytes instead of applying a universal rotation.

The 436-byte family func_L00_003DC910/003E0088/003E0F58 was recorded at 27 places each: retail-order source matched first try where inverse rotation failed on a sw/sd pair. That is a historical witness, not a rule for every store block or a fresh all-family check.

<a id="blocker-15"></a>

## 15. A `nop` after `mfc1` that retail does not have

**Historical signature:** func_L22_003A2DF8 was four bytes too long because a nop followed mfc1 before its integer consumer.

**Resolved:** gas inserted the delay, not cc1's R5900 latency model. The qualified r5900_mfc1_interlock.py transformer exempts mfc1 on R5900 from the MIPS-I coprocessor-load delay in append_insn. PR #222 landed it, and issue #247 is now closed as completed. The named witness passes 2/2 placements.

Qualification recorded 88 immediate mfc1 readers in the boot text. Scope is mfc1, not every coprocessor move: cfc2 and label-boundary padding remain separate. The old “unreachable; walk away” conclusion is withdrawn.

<a id="blocker-16"></a>

## 16. If-conversion of constant selections

**Signature:** retail keeps two compares and a branch to choose between two constants; cc1
if-converts, giving `sltiu`/`movz` (plus a word, or the same size with one instruction
exchanged). Seen where a value equal to 5 or 7 selects constants: a `switch` did not keep the
branches either. If `--diff` shows `movz` where retail has a branch, try the spelling below once, then walk away.

**Workaround measured in wave 8 - the only one of 14+ spellings that held:** two `goto`s and two `return`s.

```c
if (c) goto one; goto zero;
one: r = 1; return r;
zero: r = 0; return r;
```

That keeps `bnez` + `addiu $2,zero,1` + `daddu $2,zero,$zero` where `if/else`, two `return`s and the ternary all collapse to `sltu`. It matched a body first try.

<a id="blocker-17"></a>

## 17. A 128-bit zero: por plus sq against sq zero

Separate zero materialisation, register-to-zero store folding, and scheduling of a clear relative to other memory operations.

Historically rac2_fold_zero_ti_store removed por when its store was the final use. A naturally shared zero feeding multiple stores could retain materialisation; later inspection also identified block boundaries, scan distance and intervening control flow. Do not manufacture a second use solely to force codegen.

Merged PR #251 provides the qualified, default-off per-file `-frac2-zero-ti-barrier` clear-scheduling profile. It is a heuristic, not proof of an original macro. Qualify every function in an opted-in unit and the full build. It does not resolve every single por plus nonzero-displacement store.

[PR #258](https://github.com/OpenRAC/rac2-gc-decomp/pull/258) restricts the existing fold to a register-only memory address, retaining materialized zero registers for offset stores. Its 775-unit A/B run found no non-debug section changes and 11 mdebug differences. The integrated clean witnesses are func_L20_0044AB68 (204 bytes, 1/1 placement), func_L20_00443908 (264 bytes, 1/1) and func_L00_003ACC88 (112 bytes, 27/27 in its G8 unit). All 28 programs pass --strict and all 57 tests pass. This corrects the zero-store rule; it does not resolve all TI-copy address families or all historically screened near misses.

**Separate copy-epilogue residue:** `func_00335370` remains 88/88 bytes, 0/28 with `-frac2-qcopy`. Before `sched2`, the copy and restores already have retail order; `sched2` fills the field-load-to-address latency gap with the independent return-address restore. The source-pointer restore has a real anti-dependence on the copy. `-mastra-keep-frame-order` is byte-identical because these restores are not frame-related; disabling sched2 repairs the tail but changes the prologue. Keep the retained C. Reopen with independent evidence for an original epilogue/scheduling policy or a meaningful source dependency, not an artificial clobber or barrier.

<a id="blocker-18"></a>

## 18. Catalogue entries that are not functions

A start inside a prior epilogue, measured linker filler, or an implausible entry warrants an extent/reference audit before matching.

No jr, two returns, a short size, or a register read before its local definition is not proof by itself. Trap/tail-call bodies may lack jr; ABI-defined live-ins must be considered. A four-byte residue needs its surrounding completed return and reference evidence, not just its size.

The 49-worker wave reported roughly 30 suspects. Those are historical candidates; later rules in PRs #239/#241/#253 resolve specific filler/residue cases. Mixed prefix/body boundaries and the appendix's other proposals remain separate individually evidenced tasks.

<a id="blocker-19"></a>

## 19. The delay slot's filler is chosen by the scheduler, not by you

**Named examples now resolved:** func_L18_0042FAA8, func_L02_003D69F0 and func_L23_003C0E98 each pass1/1. Their older measurements below are retained as history, not current blockers.

**Signature:** the multiset of instructions is right and the size is right (or off by one), but
the instruction that sits in a branch or `jal` delay slot is not the one retail put there - our
column has the load/store/copy *before* the branch where retail has it *in* the slot, or the
other way round. Also shows up as a store landing in the second `jal` delay slot instead of the
first. This is `reorg`'s forward-fill choice and it is the single most common near miss in the
six waves' drafts (37 of 240 worker notes mention a delay slot).

**Measured examples:** `func_L18_0042FAA8` (56 bytes, 13 of 14 instructions identical, "the delay-slot filler takes" the other value); `func_L02_003D69F0` (48 against 44, the
`sw $zero` lands in the second `jal` delay slot instead of the first); `func_L23_003C0E98`
(prologue reordered, the `lw` in the slot instead of before it).

**Workaround that sometimes works:** section 7's - hoist the instruction the paths share above
the `if` so the scheduler can fill the slot itself. Otherwise retain the exact near miss/profile and a bounded stopping reason; a few unchanged forms do not prove that no meaningful source/profile lever exists.

<a id="blocker-20"></a>

## 20. Two exits where cc1 keeps one

Historical symptoms included merged versus duplicated epilogues, reversed branch polarity, out-of-line versus inlined returns, or an early return folded to a constant. Examples were func_L08_00318F90(68 versus 76 bytes), func_L08_003289D0, func_L23_0041E220, func_L19_0041C328 and func_L14_00427210.

func_L08_003289D0 now passes 2/2 and func_L23_0041E220 1/1; the other cases are not assumed resolved. Meaningful recipes included separate literal returns carrying the real computed value, both condition polarities, and an inverted early guard placing a longer block out of line. A shared goto sometimes merged tails further.

PR #238's conditional-fallthrough cleanup is narrower: it removes a jump to the immediately following block early enough for flow to remove its dead input in documented rotated id-list walks. Neither that fix nor one successful return shape solves arbitrary epilogue/block ordering.

<a id="blocker-21"></a>

## 21. Varargs: the saveregs prologue is exact, the call is not

**Named example resolved:** func_L08_0033CD18 now passes 2/2 using the register-save-area recipe below. The offset depends on the ABI/named arguments; do not transplant it blindly.

**Signature:** `__builtin_saveregs()` gives the retail's register-save prologue exactly, then
one `jal`+`nop` too many remains where retail passes the save area directly
(`addiu $a2,$sp,0x50`).

**Measured example:** `func_L08_0033CD18` (76 against 68: "the varargs register-save prologue
from `__builtin_saveregs()` is EXACT; one jal+nop too many remains: retail materialises
`addiu a2,sp,0x50` directly"). **Recipe, measured in wave 8 (matched 2 of 2 first try):** hand the save area to the callee directly instead of rebuilding it -

```c
void f(s32 a0, s32 a1, ...) { worker(a0, a1, (char *)__builtin_next_arg(a1) - 0x30); }
```

reproduces retail's `sd a2..t3` + `swc1 f12..f18` save prologue **and** the frame, and passes the save area the way the missing `addiu $a2,$sp,0x50` above does; the `-0x30` is six registers of eight bytes. Prefer it to `__builtin_saveregs()`, and reach for it before declaring a varargs body stuck.

<a id="blocker-22"></a>

## 22. Vector copies: address materialisation is only part of the mismatch

Historical Tabora near misses remain separate: func_L08_003D3D80(128-byte target), func_L08_003D8290(96) and func_L08_003D0508(192) differed in pointer materialisation, copy order, frame or scheduling. They are still markers. qcopy/qzero experiments are not acceptable source promotions because they use inline assembly.

Plain TI-mode C can emit lq/sq; some struct/memcpy spellings instead emitted scalar or unaligned copies. Roughly twenty forms under game/SDK profiles did not close these candidates. Fixed offsets commonly folded into the access, but “only opaque pointer parameters can work” is too broad: current notes also document held/loop-carried/memory-loaded/join-dependent pointers and out-of-range offsets. These observations neither solve the three candidates nor prove all fixed-offset copies impossible.

<a id="blocker-23"></a>

## 23. Keeping a branch in step with master (tooling, not a wall)

Contributor PRs leave the generated README progress table and progress/report.json alone. A maintainer regenerates them on master after the strict build. The old advice to regenerate them on every contributor branch is superseded by AGENTS.md. Resolve source/nonmatching conflicts against current master while preserving concurrent work.

When a maintainer does regenerate on Windows, inspect the actual diff and line endings; do not assume Git normalized them or rewrite files unnecessarily.

Merged PR #252 invalidates cached objects on toolchain changes and supplies `tools/build.py all --strict`. It rejects C fallback even if the reconstructed program otherwise equals retail. Cached output, a quick check or an OK line with rejected C is not sufficient acceptance evidence.

<a id="blocker-24"></a>

## 24. Prologue and entry-block ordering

**All named examples now resolved:** func_L01_002F1888 passes 5/5, func_L00_003ECB00 passes 27/27 and func_L20_0039DE88 passes 1/1 in the PR #246 touched-unit review. Old ordering differences do not establish a current universal wall.

**Signature:** the same instructions, in the opposite order at the top of the function: retail
`addiu $sp,$sp,-0x10` then `lui`, or `sd $s1,0x8($sp)` before `sd $ra,0x10($sp)` where cc1 emits
the reverse; also a constant materialised before the frame adjustment in retail and after it
here. About 18 of the 240 worker notes carry this shape, in bodies that are otherwise exact.

**Measured examples:** `func_L01_002F1888` ("retail does `addiu sp,sp,-0x10` THEN `lui
v0,0x1B`; gcc reorders it"); `func_L20_0039DE88` (retail `sd $s1,0x8($sp); sd $ra,0x10($sp);
jal ...; daddu $s0,$a0,$zero` against ours `sd $ra,0x10($sp); daddu $s0,$a0,$zero; sd
$s1,0x8($sp)`); `func_L00_003ECB00` (retail `addiu $v1,$zero,0x3` before `lui $v0,0x1B`).

**Current approach:** compare matched source lifetimes and per-file profiles. The accepted -mastra-keep-frame-order option controls frame-related scheduling, not every prologue/block-order discrepancy; qualify the entire affected unit.

<a id="blocker-25"></a>

## 25. Small constants: rematerialised against reused (both directions)

**Signature:** retail materialises a small constant once and keeps it in a register, often also
using that register as a later call argument; cc1 rematerialises it at each use. The reverse also
happens: retail materialises the same constant twice and cc1 CSEs the two into one.

**Measured examples:** `func_L14_00425C08` (retail materialises `addiu $t0,$zero,0x1` once and
`$t0` is argument 5); `func_L11_00456438` (the constant 1 materialised twice in retail, `$t0` for
the stores and `$a3` for the argument, where cc1 reuses `$a3`); `func_L18_00437AA0` (retail
materialises `0xFF` **twice**, `addiu $v0` then `addiu $v1`, cc1 keeps one).

**Historical result:** these attempts did not close the named cases, which remain markers. Temporaries sometimes changed materialisation; that is a case-specific observation, neither a guaranteed repair nor proof that none exists.

<a id="blocker-26"></a>

## 26. A dead store or dead load that retail keeps

**First example resolved:** func_L20_004095D0 is C and passes 1/1 with two measured addressing forms of the same real global. func_L18_00432630 remains open; its liveness diagnosis must include exact R5900 operands and control flow.

**Signature:** cc1 proves a store (or a load whose result is never read) dead and deletes it;
retail keeps it. The body is then one instruction short in the tested source. Establish genuine deadness under the ABI/control flow before assigning a cause.

**Measured examples:** `func_L20_004095D0` ("gcc removes the first store (a dead store to the
same symbol); retail keeps both"); `func_L18_00432630` ("`lh $v0,0x7FC($v1)` is missing -
it is a DEAD load in retail (`$v0` never read again), which the old note treated as a dead-load blocker; that inference needs its exact ABI/control-flow evidence").

**Consequence:** retain unresolved attempts and their bounded stopping reasons. Do not label the whole category unexpressible or add volatile/artificial uses solely to preserve an operation.

<a id="blocker-27"></a>

## 27. The missing `andi reg,0xFF`

**All three named examples now resolved:** func_L12_003DE4B0, func_L18_00432E28 and func_L12_00404778 each pass1/1. The missing-mask descriptions below are historical.

**Signature:** retail narrows an incoming byte with `andi $v1,$a1,0xFF` - the mask comes from the
`u8` to `int` promotion, compared in SImode - while cc1 folds the mask away and the body comes
out one instruction short.

**Measured examples:** `func_L12_003DE4B0` ("the `andi $a0,$v1,0xFF` instruction is missing: retail
compares the WIDENED value in SImode (the mask comes from the u8 -> int promotion), and this
compiler folds it away"); `func_L18_00432E28`; `func_L12_00404778` (the same mask missing).

**Current conclusion:** consult each matched source/profile. Those earlier folds did not prove every legal extension form would fail. Other bodies need their own measurements.

<a id="blocker-28"></a>

## 28. Commutative `addu`: base first against index first

**Current update:** func_L00_002AE070 is among PR #244's newly reviewed additions and passes 27/27. This resolves that example, not all commutative allocation ties.

**Signature:** retail computes `addu dst,base,index`, cc1 emits `addu dst,index,base` (or the
register numbers differ for the same reason). The instruction count and everything else are
right.

**Measured examples:** `func_L23_00419088` (`addu $v1,$a3,$v1` against `addu $v3,$v3,$a3`);
`func_L00_002A7DE8` (three `addu` with the scaled index first where retail puts the base first);
`func_L00_002AE070`.

**Workaround, measured later:** `p += ((a1 << 5) + 0x10); p[2] = v;` gives `addu $a0,$a0,$v1` (destination = the base register, as retail writes it) where the inline `p + 0x12 + (a1 << 5)` gives `addu $v1,$v1,$a0`; the pointer-increment form is the one to reach for when retail writes into the base. Otherwise none - "every other spelling tried (flat, `[idx]`, int pointer, index-first) gave the same order". **Wave 8 measured two more for the materialised-base case:** hoist the pointer - `char *q = st + idx * 4;` then `*(int *)(q + 0x70)` gives `addu $a0,$a2,$a0` (base first, as retail writes it) where the inline `st + idx*4 + 0x70` gives `addu $a0,$a0,$a2` - and a `(u32)` cast on the pointer (`(u32)D_x`) forces base first where the indexed spelling gives index first. The first matched a body first try.

<a id="blocker-29"></a>

## 29. Loop-form canonicalisation: countdown and one-step unroll

**Signature:** retail keeps an ascending signed counter with `slti` + `bnez`; cc1 rewrites the
loop as a countdown, or unrolls the body once. Distinct from section 2: nothing is hoisted here,
the loop's own form is changed.

**Measured examples:** `func_L05_0041C7E8` (retail runs 0,1,2 with `slti $v0,$a1,0x3` + `bnez`,
every source shape compiles to a countdown); `func_L00_00403CB8` ("the scanning loop is compiled
as a loop unrolled once by cc1").

**Historical result:** the tested while/for/do-while forms folded for those versions. Current notes also record a guard/count-up/break shape for func_002ED368. No loop syntax alone guarantees emission order. But one **skeleton** measured in wave 8 is not rewritten: a pointer loop written as `for (cur = G_start; cur != G_end; cur += 0x100)` - **both bounds read from the globals in the condition** - comes out as written, neither counted down nor unrolled; keep the comparison against the globals in the test rather than copying them into locals first.

<a id="blocker-30"></a>

## 30. Loop-alignment padding

**Partial resolution:** func_L22_003A48F8 passes 2/2 and func_L23_00419CA0 passes 1/1. The qcopy experiment below concerns prohibited inline assembly, not an acceptable matching route.

**Signature:** the `nop`s the R5900 pass puts in front of a loop head are missing, or there is
one too many, shifting the loop by a word. The pass is named in one note
(`mips_r5900_pad_loops`).

**Measured examples:** `func_L05_003D02C8` ("the 8-byte loop-alignment nop before the loop label
does not appear"); `func_L23_00419CA0` (64-byte target, attempt comes out 68 - one extra `nop`);
`func_L22_003A48F8`.

**Mechanism, measured 2026-10-13:** the R5900 pass (`mips_r5900_pad_loops`, a post-DBR hook)
pads every loop to seven **counted** instructions, and an `asm_operands` - which is what
`qcopy` is - counts as one while emitting two words (`lq`+`sq`). A retail loop that counts
seven therefore gets a parasitic `nop` when the body uses `qcopy`. Writing the same loop in
`mode(TI)` drops the pad but makes cc1 strength-reduce the counter to the decrementing form
(`addiu -1`/`bgez`) where retail increments with `slti`/`bnez`: the two levers fight, and no tested source closed that particular combination in the recorded attempts.

**Current guidance:** retain exact unresolved loop/profile evidence. Do not add dummy statements or instructions for alignment; qualify a meaningful source/profile change.

<a id="blocker-31"></a>

## 31. lui at / low-half access: an existing per-file profile

Wave 8 probes found -mno-split-addresses produced the required absolute-access form in particular units, and originally presented it as future infrastructure.

The infrastructure now exists: many dedicated units already use the flag in config/cflags.txt. It is not the only way to produce every at-based access; declaration size/attributes, profile and assembler context still matter (section 8). A probe's “only” must not become a universal rule.

PR #246's func_L20_00444138 is a current 1/1 witness in a G8/mno-split-addresses unit, also using the two true addressing forms of one bound. Isolate incompatible profiles in separate files and recheck all C in a changed unit.

<a id="blocker-32"></a>

## 32. The output for a body depends on the other functions of its unit

**Current update:** func_0032B3E0 now passes 1/1 in its actual reviewed PR #244 unit, with touched-unit regression checks passing. func_0032FDD0 is also C, but was not separately rechecked in this audit. Other listed attempts are not assumed resolved.

**Signature:** a body that `tools/check.py` reports as exact in one file comes out several words
over in another file, with **identical sources and identical declarations**. The compiler emits a
different body for the same source depending on what else the file holds.

**Measured (waves 10 and 11, on the upstream merge):** `func_00328F18` 444 bytes against 436,
`func_0032B3E0` 452 against 436, `func_0032FDD0` 228 against 216, `func_L00_003CC030` 424
against 360, `func_L00_003E6F48` 160 against 124, `func_L00_003E70B8` 500 against 436,
`func_L01_002E1680` 428 against 416, and `func_L00_002F46C8` one instruction off at +0x20. Each
matched first try in the agent's own file; the upstream file holds more functions than the
agent's did.

**Consequence:** a match has to be **re-checked in the file it will live in**, and the check
that counts is `tools/build.py`, not `tools/check.py` in the worker's tree. Where a body's own
unit cannot hold it, it needs a file of its own.

<a id="blocker-33"></a>

## 33. The 64-bit difference in specific attempts

Three historical candidates differed in pointer/index width, retained copies, sign extension or constant expansion: func_00349610, func_0028AB20 and func_00288970. They remain markers. Approximately twenty source forms per selected case and the SDK profile did not close those attempts.

Those results do not establish that all retail 64-bit arithmetic differs from the reconstructed compiler or that most shared game rows are blocked. Existing exact C uses 64-bit packet fields and operations; opt-in conversion support also covers measured patterns. Preserve each candidate's exact ABI, instructions and profile before assigning a mechanism; a variable's inferred 64-bit type is not by itself an impossibility test.

<a id="blocker-34"></a>

## 34. The catalogue's fingerprint merges two bodies

**Unresolved hypothesis:** the 23/27 report was not remeasured here. Its field offsets differ from section 12's description; re-extract current extents before a generator change. The 82 historical candidates are not 82 proven collisions.

**Suspected mechanism:** address-taint masking can group constants treated as address fields. The current generator compares ordinary untainted small immediates; it does not blindly mask every small immediate. Same-fingerprint candidates require byte-level review.

**Measured:** `func_L00_00424BB8` is the level's float setter in 23 levels (base `q + 0x60`,
fields at `+0xDC`/`+0xE0`) and another body in levels 16, 22, 23 and 26 (base `q + 0x20`,
fields at `+0x1C`/`+0x20`); the matching body in level 16 sits at `0x0042FB58` in its own row,
`func_L16_0042FB58`. No source shape can produce both, because the offsets are constants.

**Extent:** 82 of the 2,509 single-place rows carry the fingerprint of a multi-place row and are
candidates for the same collision (`func_L01_003BAFB0` against `func_L00_0037E668`,
`func_L02_003E9BB0` against `func_L00_003973E8`, `func_L02_00401298` against
`func_L00_002E94B8`). It is a `tools/levels.py` fix - the masking of the small immediates on a
non-tainted base - not a C problem.

<a id="blocker-35"></a>

## 35. The catalogue's linker-fill rows

The historical scan estimated about 6,000 of the then 106,337 placements opened with stack-adjustment/nop forms. Those are dated observations, not today's remaining denominator.

The old claim that C always ends in jr is false: trap and tail-call functions can have no jr. func_00115E90 is a concrete matched trap-ending example. Removal needs measured words/operands and surrounding extent/reference evidence.

The earlier filler and immediate epilogue-residue rules are implemented through PRs #239/#241; section 47 retains their historical counts. A mixed filler prefix followed by real code needs a boundary correction, not wholesale deletion.

<a id="blocker-36"></a>

## 36. -mno-split-addresses also keeps some symbol addresses together

The flag can keep lui and its low-half calculation together where the tested default profile split them. This is a measured unit-level effect, not a universal address rule.

Current witnesses: func_L00_003EA7D0 has its dedicated profile and passes 27/27; func_002A90C8 passes 23/23 in its existing profile. Older examples func_002B0C28 and func_002B0CE0 remain markers and are not resolved by those successes.

Section31's proposed infrastructure is present. Requalify every C function when changing a unit's flags; isolate incompatible profiles.

<a id="blocker-37"></a>

## 37. Decode the exact R5900 instruction, not a broad prefix

The earlier classification and formula were wrong. lq/sq are load/store major opcodes 0x1E/0x1F, not MMI1/MMI3. Their encoding is `opcode << 26 | base << 21 | target << 16 | (offset & 0xFFFF)`. Thus 0x78A20010 is lq v0,0x10(a1) and 0x7FA20020 is sq v0,0x20(sp). 0x78/0x7C are high-byte shapes, not six-bit opcodes to shift by 26.

**0x700014A9 is por v0,zero,zero, not pcpyld.** Major opcode 0x1C contains multiple EE operations, including compiler-emitted cases. It is not a universal “MMI0, no C spelling” category.

Use `rabbitizer.Instruction(word, address, rabbitizer.InstrCategory.R5900).disassemble()`. Generic INVALID output, a broad 0x7000 prefix, or por/lq/sq/ldl/ldr alone is not handwritten-assembly evidence. Inspect exact operands and control flow.

<a id="blocker-38"></a>

## 38. What this cc1 has no spelling for

**Scope correction:** these are particular builtin/source probes. A missing builtin makes that route unavailable, not every equivalent arithmetic expression impossible. Re-evaluate mfc1 observations under the qualified fix; no blanket floor/sync solution is claimed.

- **No `__sync` builtin.** `__sync_synchronize()` becomes a call to an undefined external and only
  inline asm emits the `sync` instruction, so that particular builtin does not lower to sync in this compiler. Inline assembly remains prohibited in matched C.
- **No floor builtin.** `floorf`, `__builtin_floor` and `__builtin_floorf` all become calls to
  undefined symbols, and a `(s32)` cast is a plain truncating `cvt.w.s`, so those forms did not reproduce the recorded branchless-floor sequence; other ordinary-C formulations are not thereby disproved.
- **The tree-level fold merges `pi + pi`** into one 2¤Ç constant, where retail doubles ¤Ç at run
  time (`add.s $f1,$f14,$f14`); two separate statements are not folded, so the retail's two
  `add.s` need them.
- **A float's sign bit comes out as `mfc1` plus a sign extension** where retail has `mfc1` plus
  `sra`; the tested union, cast and file-scope forms did not remove it in their recorded profile.

<a id="blocker-39"></a>

## 39. Source shapes that moved a body

These are measured source/ABI effects, not permission to invent barriers or false types:

- func_002FC560's stored second argument needed its measured 64-bit type; changing it to int changed emission.
- Two true names for one measured global sometimes preserved repeated address materialisation; a separately retained base sometimes preserved a later addiu. Every alias must state the real identity and pass all bindings.
- Named masks and block-local lifetimes sometimes changed allocation/frame size. Outcomes are per body, not universal declaration-order rules.
- A guard that genuinely exits can leave a different delay slot from one followed by live work. Some store permutations also moved scheduling; other blocks behaved differently.
- Return declarations affect v0/f0 availability, even when a caller ignores a result. Ignoring it does not prove the callee is void: use ABI evidence, not knowingly false prototypes.
- A dead-store observation differed between ordinary code and a delay slot in the sample. Reconfirm actual liveness and control flow; do not manufacture a memory effect to preserve it.

<a id="blocker-40"></a>

## 40. Smaller things worth knowing

- **The fifth to the eighth arguments travel in `$t0`-`$t3`,** not on the stack. A body that
  reads `$t0` without a fifth parameter is not a catalogue defect.
- **The dialect is C89:** `long` and `long long` are 64-bit, `int` and pointers are 32-bit, and
  there is no declaration after a statement.
- **The patched gas expands `move $rd,$zero` into `daddu $rd,$zero,$zero` and `li $v0,1` into
  `addiu $v0,$zero,1`:** in a disassembly neither is a difference.
- **A `sda` declaration needs a size,** and the relevant extern/assembler behavior depends on the unit profile and context; the recorded G8 result is not a universal declaration rule.
- **`__attribute__((sda))` on a global in a `-G0` unit gives retail's `lui %hi ; sw %lo($at)`
  form.**
- **Integer branch-likely slots execute on taken paths:** `beql`/`bnel` run their delay slot only
  when the branch is **taken**, which is taken-only behavior, not an inverted-annul rule. Do not generalize this to a differently decoded instruction.
- **`movz`/`movn` are emitted** (`c ? a : b` gives `movz $2,$5,$6`, `if (b) r = 0;` gives
  `movz $2,$4,$5`), so a retail body that uses them is reachable. Where `--diff` shows one
  against a retail branch, section 16's spelling is the thing to try.

<a id="blocker-41"></a>

## 41. The productive route

Historically 16 of wave 8's 24 matches came from matched siblings/fingerprints. Four workers over 104 already-attempted functions found no match in that survey.

The conclusion that the entire near-miss corpus is exhausted is withdrawn. New source forms, qualified profiles and diagnostics can change old results. PR #244's reviewed seven-function delta includes five matches obtained by permuting earlier near misses. That does not promise every old attempt now matches; it does show why one dated sample cannot exclude the corpus permanently.

Use measured siblings, final unit/profile checks and a bounded budget. Reopen a stopping point with concrete new evidence, not merely more equivalent spellings.

<a id="blocker-42"></a>

## 42. Register-allocation ties: a stopping signal for tested forms

**Current counterexample:** func_L22_00328220 passes 2/2. The other named attempts remain open. Eight identical variants establish a stopping point for those variants, not the absence of every source/profile lever.

**Signature:** two values compete and the tested source forms did not change their allocation. The
`.lreg` dump (`cc1 -dl`; each pseudo carries `refs`, `live_length`, `crosses N calls`) shows the
tie: two pseudos with *identical* statistics, and `local-alloc` breaks it by pseudo number.

**Measured:** `func_L05_0037AC00` and `func_L22_00328220` - **eight** source spellings of the
same arithmetic produce the same allocation. On `func_L05_004424B8` the `.lreg` RTL shows `cse`
folded `head = a1 + 0x30` into `(plus (reg 84) (const_int 48))` at every use, so `a1` and `head`
are **one** pseudo living across three calls: no reference count can make it eligible for `$a1`.

**Consequence:** check the `.lreg` for a separate pseudo before touching reference counts. A value present only as `(plus (reg N) K)` explains why edits to a nonexistent separate pseudo cannot help; it is not a universal impossibility proof.

<a id="blocker-43"></a>

## 43. Block ordering: distinguish source structure from unavailable flags

Historically seven loop forms in two five-member families retained a different block order from retail, changing branch polarity and delay slots. The proposed freorder-blocks/fno-reorder-blocks remedy was a hypothesis, not an available flag or a measured fix.

The qualified cc1 rejects **both** `-freorder-blocks` and `-fno-reorder-blocks` as Invalid option(exit 33). Do not add them to cflags.txt. `-mastra-keep-frame-order` is accepted, but controls frame-related scheduling rather than arbitrary block ordering.

Meaningful return/break arrangements have matched some loops. PR #238's tidy_condjump_fallthru.py removes a jump to the next block early enough for flow to remove its dead input in six documented rotated id-list walks. Neither remedy establishes a solution for every block-order mismatch.

<a id="blocker-44"></a>

## 44. Relocated instructions are validated in a separate pass

Placement.derive initially skips raw comparison of words carrying relocations because their address fields are not linked. It then validates unaffected opcode/register fields of HI16, LO16 and GPREL16, opcode bits of jumps, derived symbol values and relocation consistency. R_MIPS_32 is a full-word address relocation, not an instruction relocation.

A relocated register mismatch is therefore **not invisible**. The old claim that check.py skips instruction validation is withdrawn. The first reported mismatch is not an exhaustive list of all differences.

The displayed object column is unrelocated, so zero call/address addends can look different without being wrong. Use explicit size/instruction/relocation/binding rejection reasons and the full linked build. A quick per-function pass does not validate dependent sections or the whole program.

<a id="blocker-45"></a>

## 45. Source shapes that move a body

Historical examples, to requalify in the final unit:

- Removing a seemingly unused duplicate extern changed 180 to 188 bytes because the remaining declaration followed the call and implicit-int/default promotions altered floating arguments. Preserve correct visible prototypes.
- Mixed integer/float parameter order changed setup order even when final argument registers agreed. Determine the real ABI rather than choosing a false signature for scheduling.
- Else-if versus independent ifs changed float-constant rematerialisation; signedness changed immediate/branch forms. These were bounded examples, not guaranteed transformations.
- Stack-local ordering/layout examples remain in L00_002B91C0.c and L09_003F9468.c. A measured aligned struct containing TI128 plus a byte array expressed a frame that separate locals did not reproduce.
- func_L16_00404A60(988 bytes) matched after 24 store permutations; the winning order was neither retail order nor simple reversal. Do not infer one universal scheduler permutation.
- **Encoding correction:**0x700014A9 is por v0,zero,zero, not pcpyld. TI zero materialisation is reachable in appropriate cases; retention/folding depends on current source/profile(section 17). The word alone neither proves handwritten assembly nor proves a complete C match.

<a id="blocker-46"></a>

## 46. The `dli` expansion of all-ones masks

**The named witnesses are resolved**, with bounded rules rather than a universal mask heuristic:

- [PR #262](https://github.com/OpenRAC/rac2-gc-decomp/pull/262): `func_00117278` (`_strtol_r`, 884 bytes) and `func_00122630` (`__pack_d`, 300 bytes), one placement each. The isolated sign bit uses the sign-extending seed; a sign bit plus a contiguous low run of at least 32 ones retains the existing sign-extending `lui` path. `_strtol_r`'s wrapper forwards its actual long return; an explicit 32-bit truncation adds two instructions absent from retail.
- [PR #265](https://github.com/OpenRAC/rac2-gc-decomp/pull/265): `func_00122800` (`_fpadd_parts`, 576 bytes), one placement. Two shifted masks take three instructions instead of seven, reducing the SDK-profile body from 608 to 576 bytes. Positive shifted runs wider than 32 bits use the existing mask path; shorter runs, holes and other sign-bit cases retain their prior paths. The width bound preserves a 20-bit mask used by already-matched game code.
- [PR #267](https://github.com/OpenRAC/rac2-gc-decomp/pull/267): `func_00122B00` (`dpmul`, 680 bytes), one placement. Two separate causes were resolved: the fraction union's alias dependence and the assembler's isolated-sign-bit seed.

**The union was essential.** Public `fp-bit.c` uses a fraction union. Simplifying it to a scalar removed a real store dependence: restoring the union makes the access alias-set zero, keeps the fraction store before the class constant during the first scheduling pass, and lets `reorg` emit the retail `bnel`/annulled-store pair. No scheduler patch is needed. Disabling pre-reload scheduling repaired only the tail and produced a 688-byte body. All four existing units use the shared record; their complete object sections remain identical after the union correction.

**Both sign-bit encodings occur.** The multiplier needs `ori 0x8000; dsll32 16` at two sites, while the default `addiu -1; dsll32 31` remains required by existing game code. Per-file `-Wa,--r5900-sign-bit=unsigned` selects this bounded assembler option; explicit `signed` restores the default. No output rewriting or function/address special case is involved.

Fresh recipe, 80 container tests and all 28 strict programs pass with zero C fallback. Same-source A/B across 781 units changes code only in the new multiplier; eleven units differ only in `.mdebug`. The 1,980 authored assembler cases are checked in each of three profiles. Details and source references are in [COMPILER-NOTES.md](https://github.com/OpenRAC/rac2-gc-decomp/blob/master/docs/COMPILER-NOTES.md). Progress regeneration remains deferred.

<a id="blocker-47"></a>

## 47. Catalogue filler rules applied; mixed prefixes remain separate

The historical 21 October scan removed 257 level and 225 boot rows with the measured padding forms. A separate immediate-epilogue-residue rule removed 25 level and 26 boot rows. These are correction counts, not today's unfinished inventory. PRs #239/#241 implemented the generator changes and removed corresponding markers.

Words **and operands** matter: qualifying sp-by-sp adjustments, zero moves and nops are different from addu t0,t1,t2 or addiu sp,a0,16. Missing jr alone is insufficient. func_00115E90 is valid trap-ending C; func_0011F364 contains real code despite its padding-like prefix.

The four-byte residue rule also needs its measured position after a completed return and delay slot. PR #253 now handles five additional specifically audited mixed-instruction residues (section 50), not an opcode-only generalization.

An extent beginning inside a prior epilogue but containing a later real function needs an entry correction, not deletion. Positive stack adjustment is only a clue. Verify call/data/vtable entries, preserve ends and raw bytes, and preserve boot/level identity when regenerating fingerprints. Other mixed boundaries remain open.

<a id="blocker-48"></a>

## 48. The wave 12 census: historical sample, not today's inventory

The sample covered twelve game/shared files, 470 unfinished functions and 9,638 placements, with nine workers. Its 4,932 filler placements preceded the corrections above and are not current remaining work.

- **Exact instruction decoding comes first.** The sample reported 30 COP2/VU0 and 9 broadly classified MMI bodies in src/game/0027F128.c. Opcode families alone cannot determine C reachability or ASM_FUNC credit. 0x1C includes compiler-emitted operations, and one body does not disqualify its whole source file.
- **Trapping arithmetic is a specific compiler-origin clue.** The tested C additions emitted addu/addiu, and ftrapv was unsupported; func_00283150 has its own reviewed evidence. Do not classify every other row automatically.
- **Encoding correction:** COP1 major opcode is 0x11 and COP2 is 0x12; these are not opposite halves relative to ordinary MIPS. lq/sq base is bits 25–21, as in ordinary MIPS base-plus-offset loads/stores, not 15–11.
- **Conversion/OR observations were bounded.** Seventeen conversion spellings and the sampled OR forms failed. That does not prove every conversion must use a fresh FPR or every left-to-right OR sequence is unreachable.
- **TI offset materialisation:** fixed offsets folded in tested attempts, but opaque pointer arguments are not the only documented zero-displacement shape. Notes also record loop-carried pointers, memory-loaded pointers, join-dependent values and out-of-range offsets. These do not solve all remaining fixed-offset copies.
- **G0/G8 can change addressing and allocation.** Actual form also depends on declaration size/attributes and assembler context. Qualify the complete unit instead of inferring a universal recipe.

<a id="blocker-49"></a>

## 49. The wave 13 census: correct the screens before selecting work

The historical screen selected 145 proposed functions in fifteen files. Other files with many unfinished rows were dropped using broad opcode classes. Those are selection counts, not verified current reachability; a file of 81 functions was not proved to contain zero reachable functions.

- **The six alleged unused multiplies are live.** No mflo was the wrong criterion: R5900 mult/mult1 can write a GPR destination. The [maintainer follow-up](https://github.com/OpenRAC/rac2-gc-decomp/issues/157#issuecomment-6305695078) decodes rd and follows its uses in all six bodies. Withdraw the unused-result/compiler-origin hypothesis and any ASM_FUNC inference for those cases.
- **Decode exact operations.** 0x1A/0x1B are ldl/ldr, not COP2/VU0. 0x1C covers multiple EE operations, including compiler-emitted ones; it is not universally unreachable MMI0. lq/sq use 0x1E/0x1F. Inspect operands/control flow and never reject unrelated bodies by association.
- **TI folding remains a bounded problem.** Roughly thirty historical forms folded a fixed offset. This does not prove all computed addresses unreachable; distinguish documented pointer/loop/join shapes from unresolved fixed-offset copies and issue #248's narrower zero-store experiment.
- **Allocation can cascade.** One stack-local-address difference changed saves, scratch FPRs and branch-likely choice in a sample. That does not establish that allocation is never source-sensitive.
- **Types and volatile must describe semantics.** The sample changed codegen by altering a return declaration or loop-bound qualifier. An ignored return does not prove void, and a forced memory read is not a justified matching barrier without real semantics.
- **Split addressing does not inherently change the address.** Correct relocation/addend handling can make lui-plus-load and lui-plus-addiu-plus-field refer to the same data. Derive validates the compiled form; a false symbol identity is a defect, not another valid binding.
- **Not all level data needs ref_.** D_LNN_XXXXXXXX is the normal level-data name; its canonical address and other placements are checked/bound under repository rules. Ref_ is for genuinely variable target identity. Preserve resident-data and boot/level naming conventions.

Use current R5900 decoding, profile evidence and bounded per-function checks. This section is not justification for a blanket file exclusion or unreviewed handwritten classification.

<a id="blocker-50"></a>

## 50. Five specifically audited residual extents — resolved by PR #253

The wave 13 report found five suspects. Missing jr or local register definitions were clues, not proof. Subsequent review checked positions after completed returns and direct-target/aligned-pointer references at every affected placement. That audit does not prove absence of all computed indirect targets and must not become a general deletion rule.

| Historical row | Recorded extent | Resolution |
|---|---|---|
| func_00289018 |4 bytes, isolated store after return |Measured residue mapping |
| func_002A77C0 |28 bytes, orphan float operations |Measured residue mapping |
| func_002FED78 |12 bytes, unmatched restore context |Measured residue mapping |
| func_002FF0B0 |36 bytes, restore/GP-store context |Measured residue mapping |
| func_002FDB40 |148 bytes, restores/orphan store, 22 level copies |Boot and matching 22 level placements |

PR #253 is merged. Generator, catalogue, markers and tests account for these specific extents while preserving reconstructed program bytes. They are catalogue corrections, not new C or handwritten-function credit. Other historical boundary proposals below remain independent.


<a id="blocker-51"></a>

## 51. The wave 14 census: a call inside one object, and a screen that was too broad

The wave 14 reserved forty-three files of `src/game/` and `src/levels/shared/` and
479 unfinished functions, screened **per function** on the retail bytes (8,883
placements). Ten workers, one file each, no two workers on one file.

**The result: three matches, 59 placements**, and one more match handed to the
contributor that holds the body.

| function | places | unit |
|---|---:|---|
| `func_L00_003E70B8` | 27 | `src/levels/shared/L00_003E70B8.c` (a unit of its own) |
| `func_L05_00418508` | 4 | `src/levels/shared/L05_003D33E8.c` |
| `func_00291788` | 28 | `src/game/00291758.c` |

Twenty-nine near misses were deposited in `nonmatching/`, each with the difference
that was measured and the spellings that were tried. The census is those
measurements, not the three matches.

### A call inside one object fixes the distance between the two

`func_L00_003E70B8` calls two bodies that `L00_003E3258.c` holds, and it was written
in that file. The assembler resolves a call to a body of the same object to an
offset, so the two are placed together — and the retail does not keep them
together in every level. The body was placed in **18 of the 27 levels** and dropped
in the other nine, and the build gave it no credit there, even though
`tools/check.py` said the bytes matched at every place. `tools/check.py` reads the
symbol values from the retail's bytes under the relocations; `tools/build.py`
compares the **linked** addresses, and a local call cannot move.

**The rule, measured over the whole tree: no C function of `src/levels/shared/`
calls another C function of the same file.** Not one of the 180 shared files does
it. A body that needs a sibling gets a sibling file, and a call that crosses a file
is a global one the linker places per program.

### The bodies the game linked more than once

The retail keeps **more than one copy** of some shared bodies: three copies of the
reset routine `func_L00_003E6FC8` (also `func_L00_003F0A20` and `func_L00_003F1DC8`),
two of the scale routine `func_L00_003E7050` (also `func_L00_003F0AA8`), and the
caller itself has seven twins. Which copy a program calls changes from one program
to the next, so a C that names one copy is right in 18 programs and wrong in 9.

**The way out is the `ref_` name**: `ref_L00_003E70B8_00` and `ref_L00_003E70B8_01`
for the two calls, whose value the build reads from the retail's bytes, with no
address in the name. That is what the project already does for a call whose target
moves between programs (`src/levels/shared/L00_002E5918-g8.c` and its neighbours).
With the body in a unit of its own and the two calls renamed, it is 27 of 27.

**How to see which calls need a `ref_` name.** For every call of a body, read the
retail's jump word in every program and look up which catalogue row the target
belongs to. A call whose target is the same row everywhere takes the row's name; a
call whose target moves between rows takes a `ref_` name. Measured on
`func_L00_003E70B8`: eight of its ten calls name one row in all 27 programs, and the
other two move.

### The screen of sections 48 and 49 was too broad

Those sections dropped a body that carried *any* word of a list of opcodes (COP2/VU0,
COP3, COP2X, COP3X, the whole MMI space, and the double-precision FPU words the PS2
does not have). In the forty-three files of the wave there are **1,184** unfinished
bodies: 479 were kept, 705 were dropped, and of the 705 only **101** carry an
instruction no C body can carry (section 52). The other **604 are reachable** and
were left on the table for nothing. The over-broad classes are:

* **0x1A and 0x1B** are `ldl` and `ldr`, the R5900's quad load. A 16-byte struct copy
  reaches them: the compiler emits them.
* **The MMI space** (0x1C) holds the compiler's own `por $rd,$zero,$rt` (section 17)
  and the constant words a literal pool leaves in the instruction stream. A body
  carrying one of those is not hand-written.
* A **literal pool inside a function** is data. A float constant can decode as an
  MMI word; a branch's delay slot can hold one.

### The walls this wave measured, in order of cost

* **The 128-bit copy, and the way out of it.** Retail materialises the address of a
  16-byte copy (`addiu $a2,$s2,0x10 ; sq $v0,0x0($a2)`); this cc1 always folds a
  constant offset into the `lq`/`sq` pair. About forty spellings were measured across
  three workers and all of them fold. Two spellings keep the address in a register: a
  plain pointer with no offset, and a symbol address. The opt-in profile
  `-frac2-qcopy` reaches the retail's shape; it is already in `config/cflags.txt` for
  two files, and the need for the others is reported here rather than applied, because
  `config/cflags.txt` is not a worker's file.
* **The floating-point register allocation is not a source detail.**
  `func_L00_003E9540` and `func_L00_003BC108` have retail's size and retail's
  instruction sequence, and differ only in which of $f2..$f8 holds which value.
  Eleven and nine spellings were measured. The allocation follows the first textual
  use of a value, so the source's *expression tree* decides it, and a permutation
  search over the statement order is the lever.
* **The frame's register set follows from the address form.** `func_L05_004268E8`
  and its three colour twins come out with nine callee-saved registers against the
  retail's eight, because the retail has no register at all for the base of the int
  array: it re-materialises it in the loop (`addiu $v1,$s4,0x20`) and adds the offset
  to it, while a base held in a local lets the compiler fold the offset into the store.
* **A dead `mult` is a body this compiler did not write.** `func_L00_002FCF18` and
  `func_L00_003FEAC8` carry a `mult` whose result the retail never reads; cc1 does
  not emit a multiply whose result is unused.
* **An indirect call has no sibling-call form.** `func_002B9380` is a tail call in the
  retail (`jr $v0`) and comes out as `jalr $v0` with an epilogue; five spellings were
  measured and `-mastra-sibcall` does not change the indirect target.
* **A body that a worker could not close in a hundred spellings is a wall to record**,
  not a near miss to retry.

### The catalogue defects this wave found

(the fix belongs in `tools/levels.py`, outside every worker's lane):
`func_L00_00400F30`, `func_003495B8`, `func_0034CE88`, `func_002EEBB0`,
`func_L00_002DA390`, `func_0031E6D8`, `func_0031D350`, `func_00326CA8`,
`func_L00_003D1B48`, `func_002B80B8`, `func_L00_0037B408`, `func_L00_0037B4B8`,
`func_L00_0037B5C0`, `func_00280660`. They are the same shape: a four- to
sixteen-byte extent that reads a register it never sets, or branches outside its own
bytes, or is the linker's padding between two bodies. Each is deposited with its
evidence.


<a id="blocker-52"></a>

## 52. What a C body cannot carry: the measurement, and the rule

`AGENTS.md` allows the `ASM_FUNC` marker for a body that "uses instructions the
compiler never emits". That needs a measurement, not an impression: the wave 14
workers reported such bodies and left them unclassified, and the wave's own screen
(section 51) was too broad for the same reason.

**The measurement.** Every C object of the project was scanned, word by word, over
the code of each function (the body cut at its `jr $ra` and its delay slot, so a
literal pool after the epilogue is not counted as code):

```
the C objects: 861
   VU0 (COP2) 0
   COP3       0
   MMI        12, of which 12 are the compiler's own form
```

So **the compiler emits no VU0 instruction at all**, and no COP3 one. Of the MMI
unit it emits only two things:

* the R5900's own SPECIAL2 arithmetic — `mult1` and `madd` (opcode 0x1C, the
  `R5900_MMI` category), and
* the form `por $rd,$zero,$rt`, which copies or zeroes a register. Section 17
  already records it: `src/levels/shared/L00_002B91C0.c` is a **matched** function
  and its `por $v0,$zero,$zero` is the compiler's own, zeroing the GPR half of a
  128-bit store before the `sq`.

Every other MMI word — `pmaxw`, `pminw`, `pcpyld`, `pcpyud`, `pexch`, `pextlw` —
never comes out of a C body.

**The rule that follows, and the traps it avoids:**

* A word of opcode 0x12 (COP2) is evidence. Nothing else is needed: a function that
  has one cannot be C.
* A word of opcode 0x1C is evidence **unless** it is the SPECIAL2 arithmetic or the
  `por $rd,$zero,$rt` form. A body that carries only a `por` is not hand-written:
  `func_00308768` and `func_00322138` carry one and are ordinary C with a 128-bit
  store.
* `lq`/`sq` (0x1E/0x1F) and `ldl`/`ldr` (0x1A/0x1B) are **not** evidence: a
  `mode(TI)` type and a 16-byte struct copy reach them. Section 11 and this section
  replace the wave 13 screen's opcode list, which dropped 604 reachable bodies for
  nothing.
* **Decode with the R5900 category and the real address.**
  `rabbitizer.Instruction(word, address, rabbitizer.InstrCategory.R5900)`.
  Without the category a valid MMI word is printed `INVALID`, and a data word is
  printed as an instruction; both misclassifications happen.
* **A constant in a literal pool is data, not code.** It sits in the instruction
  stream, between two instructions, and decodes as an MMI word. The matched functions
  show the shape: `por $v0,$zero,$zero` before a `sq`.
* The six bodies that rest on an MMI word alone were read by hand, in their context,
  before being classified: two `pminw` in a sixteen-byte body, a `pmaxw` in a
  branch's delay slot, eleven `pcpyld` in a row, a `pcpyld` in a body, and a `pmaxw`
  in the block a row holds after its tail call.

**What it buys.** 101 bodies in the forty-three files of the wave 14 are hand-written.
56 of them are marked `ASM_FUNC` in pull request #270; the other 45 are in another
contributor's reservation, and the measurement is handed over with them, because the
holder of a body is the one who decides its marker. The marker changes no link — the
build takes those bodies from the game's own assembly whatever the marker says — it
only changes the count `tools/progress.py` reports, as rac1-decomp counts them.


## Historical catalogue-boundary proposals and follow-up

The old appendix is an investigation record, not a current work queue. Filler removals, mixed entry corrections and different-callee bindings must remain separate:

- func_L02_0035BD60 was reported 288 bytes with a proposed entry 0035BD70/268 bytes after a preceding tail. This audit does not adopt that correction without current extent/reference verification.
- Fourteen level 23 candidates were reported eight bytes early: 2F7478,306630,327208,32F798,33F9B0,3427C8,36CE80,3D8EC8,3DFC20,4277B0,441DC8,442300,443788,44D7B8. The recorded positive witness was a vtable/data pointer to 004277B8 for func_L23_004277B0. Level 30 candidates003557F0,003E1BA0,00404608 were reported similarly; the prior caller referenced 00404610. These remain individually checked boundary proposals, not blanket deletion rules.
- func_L16_00424B48 was reported as an eight-byte restore/nop prefix plus a 160-byte body at 00424B50. func_L11_00440790 was reported 212 bytes with a candidate 192-byte body and an apparently unreachable block. Neither an old size nor an apparently dead block alone proves handwritten code or authorizes a catalogue edit.
- **Differing-callee case resolved:** func_L00_003F5660 now uses ref_L00_003F5660_00 and passes 27/27, including levels 08,09,19,30. The old assertion that no single definition could represent it was wrong. Genuine nonrelocated immediate differences remain a different problem.

The historical full core scan reported 60 fill-starting entries rather than the earlier 26. Many simple cases were subsequently removed; mixed examples such as func_001158F4, func_0011A7F8, func_0011E920, func_0011ED28, func_0011F364, func_0011FB8C, func_00120354, func_00125D94, func_0012646C, func_0012F998 and func_00130A8C need their own boundary evidence. The old table and prose disagreed on func_0011F364: 28-byte prefix/608-byte body at 11F380 versus 4/632 at 11F368. Neither historical figure is adopted here as a verified correction. Preserve the real code until the discrepancy is resolved.

A known entry pointer is strong positive evidence; one pointer lookup is not proof that all other entry points or indirect targets are absent. Verify every affected placement and preserve raw bytes.

## Reading --diff correctly

The object column is unrelocated, so a zero call/address addend can differ visually without being wrong. Derive separately validates relocated opcode/register fields and consistent symbol bindings (section 44). All explicit size, instruction, relocation and binding rejection reasons matter. The first diagnostic is not exhaustive. Final acceptance requires the full strict linked build and every expected C placement.

## Aranos follow-up — historical linked results and current limits

PR #168 recorded 30 plain-C definitions (five level-specific, 25 shared), a 28-program build and a placement-preservation audit. This records that work's original measurements, not a newly rerun full build or a current pending-review claim.

Current checks reconfirm func_L00_002D4A38 at 27/27 using its real opaque absolute symbol, func_L00_003618D8 at 1/1 and func_L00_003E7768 at 1/1. The last body's historical size was 1308 bytes. These meaningful source/ABI witnesses do not authorize attributing every global or falsifying callee returns.

The original near misses remain distinct: func_L00_0038D750 improved from a retained pointer's 8 references/107 live instructions/9 calls to 7/58/7, but remained 1036/1044 bytes; func_L00_003D54B0 had a 4404/4424 attempt at 0/2; 003EE288 was 564/564 but differed; 00412E68 was 384/400 with a zero-store difference. Equal size also hid func_L00_0040EAA0's 0x60 versus 0x50 frame, bit-test and retained-constant differences. None of those historical attempts is promoted here.

The generator's Aranos corrections 00354DE8→00354DF8, 003D54A8→003D54B0 and 0040EA98→0040EAA0 preserve ends and are present in current source. Their positive evidence was actual data/vtable references; skipped prefixes remain assembly. The 4424-byte body then grouped with Siberius 003EBC90, changing the historical 9101 total to 9100 before later catalogue work. These old totals are not current progress. Other suspected boundaries were not resolved by that change.

## Additional measured findings

These attributed notes were imported from the existing contributor comments. They are now
shared entries that any contributor may correct through a PR. Their original dates and
pending labels are historical; reconcile them with current source and the updates above.
The original comment-workflow introductions are omitted because the shared editing rules
above replace them. The technical measurements are retained.

### Findings contributed by llesieur99

Source: [original contributor comment](https://github.com/OpenRAC/rac2-gc-decomp/issues/157#issuecomment-6305695078). The measurements below are
attributed for provenance, not exclusive ownership.

### Current findings

| Function / family | Status | Evidence and next action |
| --- | --- | --- |
| `_fpadd_parts`, `func_00122800` | **Merged, #265** | 576 bytes, 1/1 boot placement with the SDK profile. The assembler's bounded positive shifted-mask rule reduced two constants from seven to three instructions each. Full 28-program strict build passed. |
| `dpmul`, `func_00122B00` | **Merged, #267** | 680 bytes, 1/1 boot placement. Restoring the public fraction union restores the real alias dependence and the rounding `bnel`/store slot. Two sign-bit loads use the per-file unsigned assembler seed; the signed default remains unchanged. All 80 tests and 28 strict programs passed. |
| Copy epilogue, `func_00335370` | **Retained, not matched** | 88/88 bytes, 0/28 placements with `-frac2-qcopy`. `sched2` fills the field-load-to-address latency gap with the independent ra restore. Frame-order is byte-neutral; disabling sched2 repairs only the tail and changes the prologue. The copy profile merged in #275 is now a concrete reopening experiment. This retained function was not requalified in this review, so no match credit is claimed; keep the measured source and avoid artificial clobbers or barriers. |

For #267, a same-source comparison of 781 configured units changed code only in the new multiplier; eleven differences were debug-only. The shared union changed no object section in the four existing users. Source, flags and durable explanations are in the merged repository; partial C remains in `nonmatching/`. No progress report was regenerated.

### Newly qualified compiler profiles and review findings

- **Copy scheduling, merged #275:** `-frac2-qcopy-barrier` supplies the schedulers' conservative volatile-copy dependence model while game sources remain ordinary C assignments. Twelve witnesses pass 59 placements. Independently checked: 113 tests, all 28 strict programs, and an 814-unit comparison with no code changes by default; only the twelve selected units change. This models scheduling, not every optimizer effect of inline assembly, and does not establish the original macro or justify `ASM_FUNC` classification.
- **Wide-store delay-slot searches, merged #279:** `-frac2-no-annulled-wide-stores` restricts two thread/target search paths; optimize_skip and ordinary delay slots remain unchanged. Two witnesses pass three placements. Independently checked with #275: 123 tests, all 28 strict programs and 816 units with no default code changes; only the two newly selected units change. The PR's census counts were not independently reproduced in this review. This is an opt-in compiler policy, not a hardware prohibition.
- **Names and interfaces:** new calls must use catalogue identities rather than abbreviated level-address aliases. The new predicate caller in #277 now shares one two-argument definition with its callee, leaving the candidate pointer unused, instead of using an assembler-name alias with a different parameter count. Both the 88-byte callee and 832-byte caller remain exact.

The review integrated #272, #273, #274, #275, #277, #278 and #279: 57 new functions, 24,940 distinct bytes at 198 placements. The final target/unit check covers 86 functions at 414 placements. Partial work remains retained; no progress report was regenerated. Contributors need a compiler rebuilt from the new recipe before using the new per-file options.

### Historical catalogue and multiply audit

The audit below preceded the catalogue correction subsequently merged in #253. Its measurements are preserved as history; the five residue rows are no longer a pending generator task. The six multiply bodies were not evidence of unused multiplication or handwritten assembly: their R5900 GPR destinations are consumed.

#### Original audit during PR #243

I checked the qualified USA v1.01 retail bytes and the current compiler while integrating #243.

#### The six multiplications are used

The two-operand disassembly omitted R5900 `mult`'s GPR destination (`rd`). All seven multiply sites in the six reported boot bodies write a nonzero destination register, which the following address calculation consumes:

| Function | Multiply site(s) | Destination | Observed use |
| --- | --- | --- | --- |
| `func_00291788` | `0x002917A0` | `$v1` | address addition at `0x002917AC` |
| `func_00288208` | `0x00288270` | `$v0` | address addition at `0x00288274` |
| `func_00288308` | `0x0028835C` | `$a0` | address addition at `0x00288368` |
| `func_002883E8` | `0x00288408` | `$v1` | address addition at `0x0028840C` |
| `func_002887B0` | `0x002887DC` | `$v0` | address addition at `0x002887E0` |
| `func_002B65B8` | `0x002B660C`, `0x002B6624` | `$a0` | both paths reach the address addition at `0x002B663C` |

The qualified GNU opcode table includes the `mult d,s,t` form with `WR_d`. As an independent control, the current compiler translates ordinary `return index * stride;` into a three-operand `mult` writing the return register, without `mflo`.

**Decision:** withdraw the unused-multiply/compiler-origin hypothesis for these six bodies. This evidence does not justify `ASM_FUNC` and is not a compiler barrier. The absence of `mflo` alone is insufficient; decode `rd` and follow its uses.

#### The five catalogue extents have evidence of residual code

| Row | Size | Placements checked | Preceding boot return |
| --- | ---: | ---: | --- |
| `func_00289018` | 4 | 1 | `0x0028900C` |
| `func_002A77C0` | 28 | 1 | `0x002A77AC` |
| `func_002FED78` | 12 | 1 | `0x002FED68` |
| `func_002FF0B0` | 36 | 1 | `0x002FF0A4` |
| `func_002FDB40` | 148 | 23 (boot + 22 levels) | `0x002FDB30` |

Every checked placement follows a preceding `jr $ra` and its delay slot. A scan of the corresponding program's text found no direct branch/jump target inside any of these extents; a scan of the loaded non-code sections found no aligned literal pointer into them. The mixed arithmetic/store fragments are therefore supported as catalogue residues by their surrounding code and reference audit, not merely by their lack of `jr $ra` or by FPU nops.

**Decision:** keep these as catalogue-correction cases, not C-matching targets or handwritten-function credit. #243 retains the observations but does not change the catalogue. A separate generator change should verify every affected placement, preserve the original image bytes, and include regression tests before dropping these rows. This static audit does not establish the absence of computed indirect targets, so do not generalize it into an opcode-only deletion rule.

### game/00308600 follow-up — PR #287 merged; original near miss retained

- `func_00308600` remains a near miss. The old draft incorrectly used the return of `func_002A0488` for the +0x30 byte, and wrote +0xBC after `func_002A0F48`; retail writes both before their calls. The corrected draft remains in `nonmatching`. With current master compiler sources, `-frac2-qcopy -frac2-qcopy-barrier -fno-gcse` produces 356/360 bytes, 0/28 USA v1.01 places. The copy pairs, saved f20/f21 and 0x50 frame agree, but the initial stores merge two retail 255 materializations and GPR allocation differs. Typed fields, a short argument and scheduling/CSE controls did not resolve it; the short argument's 360-byte result contains unwanted sign extension. Reopen with independent field-type or constant-lifetime evidence, rather than repeating those variants.
- `func_0030E700`, in the same source unit, is now a merged 424-byte plain-C implementation: 28/28 USA v1.01 places pass `tools/check.py` with default flags. The first candidate differed only around `func_002ABBB8` argument setup. Its integer/float interleaving already used in `src/levels/04_barlow/L04_00422A00-g8.c` resolves those differences without a compiler change. USA v1.01 `tools/build.py all --strict --jobs 8`: all 28 programs OK, no C fallback; 139 unit tests, repository checks under Ubuntu, progress --check and diff checks pass. Merged in [PR #287](https://github.com/OpenRAC/rac2-gc-decomp/pull/287), commit `76254265`. The qualified USA v2.00 input also passes all 28 target places and all 28 full strict builds, with zero C fallback. Both PR CI checks passed. This adds one distinct 424-byte C function, with 28 placements per applicable USA release; no report was regenerated. No PAL implementation or new matching credit is claimed.

### Findings contributed by bigmak94

Source: [original contributor comment](https://github.com/OpenRAC/rac2-gc-decomp/issues/157#issuecomment-6321947233). The measurements below are
attributed for provenance, not exclusive ownership.

| Function / family | Status | Evidence and next action |
| --- | --- | --- |
| **Vector copy as a scheduling barrier:** `func_002B5E48`, `func_002EE988`, `func_L23_00418650`, `func_L23_003C01F8`, `func_L23_00418DC0`, `func_L23_004256F0`, `func_L02_003DB158`, `func_L02_003D47B0`, `func_L26_003D4930`, `func_L12_00413CE0` (close: `func_002B50E0`, `func_L23_0041D0A0`); from today's first attempts at level 2, also `func_L02_00401BF8`, `func_L02_003F1A88`, `func_L02_003EE938`, `func_L02_003E8CE8` | Merged, #275 | Each is retail's size with `-frac2-qcopy` in a unit of its own. Each is exact when the copy is the volatile asm `lq $2,0(%1) ; sq $2,0(%0)`, in scratch copies only. The profile's grouped pair lets independent instructions cross it. About 50 single flags and many source orders, including `-frac2-zero-ti-barrier`, do not. #275 (merged) adds the opt-in `-frac2-qcopy-barrier`, the clear's block in `sched_analyze_insn` applied to the qcopy insn. Twelve witnesses landed with it. Twenty-three more near misses are exact with it as their records stand, in #283; two more follow. `func_002B50E0` is still 3 words off, a sched1 tie on argument moves. |
| **The barrier copy's link costs:** `func_L02_003F1A88` | Open, measured | With `-frac2-qcopy-barrier` it is 5 words off. The links into the copy keep their producers' latencies (an `add.s` link costs 3), where a volatile asm makes them cost 1 in `insn_cost`. A constant's load then outranks the state `lw` (priority 24 against 22). With the asm copy in a scratch copy, the priorities tie and it is exact. **Next:** give the barrier's incoming links the asm's cost, then re-check #275's twelve witnesses. |
| **A TImode zero reloaded as a register pair:** `func_L02_004388A0` | Open, measured | 5 words off with the barrier: its 16-byte zero clear is reloaded as a group of two general registers, though the R5900 holds it in one. That makes `$v1` a spill register, so a hoisted sentinel -1 left unassigned gets `$v1` where retail has `$v0`. Without the clear (diagnostic only), every -1 is in `$v0`. |
| **A register saved and never used:** `func_L02_003FF6E8` | Open, measured | Retail saves `$s2` and never uses it; 21 retail game functions do so, and none of them is C. A plain C spelling reproduces the frame and register roles but keeps the value in `$s2`, 700 bytes against 696. |
| **Clear through a register address at a nonzero offset:** `func_002B5678` | Open | Retail has `addiu $v0,$s1,0x60 ; sq $zero,0($v0)`, the clear macro's register operand. After #258, C gives `por` + `sq $v0,0x60($s1)`. **Next:** a profile that materializes the address of a displaced const-0 TImode store. |
| **A `por` clear at a zero displacement:** `func_L02_003DB200`, `func_L02_00423520`, `func_L23_00422798`, and with the copy barrier `func_L02_003DBA70`, `func_L23_00429DC8` | Proposed: PR #281 | These functions clear a stack vector with `por $v0,$zero,$zero` + `sq $v0,0($sp)`. Since #258, the fold still makes that `sq $zero,0($sp)`, because the address is register-only.<br><br>A finer retail count (one place per catalogue row, boot game code from 0x26EA00, a store counted when every path into it starts from the `por`) finds 183 `por`-fed stores at a zero displacement, in 153 functions. Every one of them is to `0($sp)`; none goes through another register. Against that, 396 `sq $zero,0(reg)` stores in 263 functions, of which 82 (58 functions) are also to `0($sp)`.<br><br>PR #281 adds the opt-in `-frac2-zero-ti-por`: with it, the fold leaves a store to `0($sp)` alone, and stores through any other register still fold. It is neutral by default (806 of 806 units). Forced on everywhere, it changes exactly the 4 units whose matched functions clear `0($sp)` with `sq $zero`. The five functions above are exact with it. `func_L23_003C16D8` stays out: three of its clears go through a computed stack address. |
| **A cse block boundary that leaves no instruction:** `func_L02_003D26B0`; the five 632-byte twins `func_L11_00436D08`, `func_L11_00449C70`, `func_L11_0044C850`, `func_L11_004530E0`, `func_L11_004566C0`; `func_L02_003F1BA8`, `func_L02_0040BBD8`; `func_L07_00378898` | Open | Retail keeps a gcse (PRE) copy, for example `daddu $s5,$s4,$zero` of `e + 0x10`, that this cc1 makes only when cse1 and cse2 both see a label at that spot. Adding `\|\| x == 7 \|\| y == 9` to the test reproduces it, with extra code. An empty `do { } while (0)` reproduces it exactly but is rejected (#257, fc4a6c6). For `func_L07_00378898`, `-fno-cse-follow-jumps -fno-cse-skip-blocks` reproduces the block, as a probe only. **Next:** the original's construct at that spot, or a measured cse rule. |
| **A non-empty `do { ... } while (0)` as a block barrier:** `func_L02_003FB000` (288 bytes) and `func_0033A520` (360 bytes, 28 places) | Question for maintainers | `func_L02_003FB000` is exact with its last store wrapped in `do { ... } while (0);`. The loop notes give the shared `jr $ra` retail's alignment `nop`, which cc1 adds only after a loop. `func_0033A520` needs a block boundary after its rounding of `D_001B23A4 * 300`; the wrapper gets that block right, and six allocation words remain.<br><br>Two merged functions use the same wrapper as a documented scheduling barrier: `func_00124818` and `func_L23_0041C8C0` (ours). The repository check rejects only the empty form. Since AGENTS.md rules out artificial barriers, we have not landed more. **Question:** is a non-empty wrapper acceptable as a macro-shaped statement, or should the two precedents be revisited? |
| **Jump tables the build cannot place:** `func_L06_003FDA08`, `func_L13_00422CB8`, `func_L03_003C4578`, `func_L02_003F9AF0`, `func_L02_003F9B70`, `func_L02_003FE1B0` | Solved, PR pending | A computed goto through retail's own table, in the form of `func_00310A40`, matches all six. The three level 2 records' in-order switches were wrong: retail's tables map the values to the bodies in another order. Decode the table before trusting a record's `switch`. |
| **Labels behind hazard nops:** `func_L18_004308F0`, `func_L02_00411530` | Merged, #264 | Opt-in `-frac2-hazard-labels`. 198 retail branch targets after a compare or `mtc1` sit on the nop, and SN's `Ps2EeAs` agrees. Forced on everywhere it is neutral (778 of 779, one `.mdebug`). |
| **gcse critical-edge split, Cygnus block merge:** `func_002CD720`, `func_L02_003E79F8`, `func_L02_003FCCA0`, `func_L18_004283F0` | Merged, #261 | Opt-in `-frac2-gcse-unsplit-edges` and `-frac2-keep-block-order`. `func_L23_0041B9F0` reaches retail's size with the gcse switch and still stops at the copy order. |
| **PRE keeps a load across a store to another offset:** `func_L02_003EEC58` (and `func_L23_0041C0E8`) | Open | Retail reloads the index after a store to a disjoint offset of the same base. A `volatile` read reproduces it, which is not allowed. **Next:** an opt-in PRE rule in which any store kills the load. |
| **Wide store in an annulled slot:** `func_L02_0042EDD0`, `func_L23_00422668`, `func_L02_003E7370` | Merged, #279 | Retail's game code has no `sd` or `sq` among the 2,895 stores in annulled slots. Ordinary slots hold 547 `sq` and 497 `sd`, and annulled slots do take wide loads.<br><br>PR #279 adds the opt-in `-frac2-no-annulled-wide-stores` (reorg's thread and steal paths; `optimize_skip` is kept). It is neutral by default (796 of 796 units); forced on in every game-compiler unit, it changes only the two witnesses. `func_L02_0042EDD0` (2 places, with the clear barrier) and `func_L23_00422668` (with `-frac2-qcopy`) are exact with it. `func_L02_003E7370` also needs the clear barrier in a call slot, and the barrier then also catches a plain C clear. |
| **Catalogue rows that are not functions:** `func_00288D40` (20 bytes), `func_00290718` (4), `func_00298D10` (20), `func_002B4068` (36), `func_002B49A0` (12), `func_002ED570` (4), `func_002FC460`, `func_002FC510`, `func_002FC618`, `func_002FC868` (4 each), `func_0033B538` (4) | Evidence, left as markers | Each row starts right after a complete function, its `jr $ra` and the delay slot, and ends at the next function. No branch or jump in any catalogued boot function reaches it (scan of every boot row). Their words, like `sw $v0,-0x3D14($gp)` or `addiu $sp,$sp,0x10 ; nop`, read as unreachable tails. **Next:** a `tools/levels.py` rule for unreachable inter-function words, if maintainers want one. |
| **Rows that begin inside the previous epilogue:** 113 unmatched level-catalogue rows, 8 of them reserved by me (`func_L02_003EA180`, `func_L02_004004D0`, `func_L02_00439CD8`, `func_L03_00421398`, `func_L19_003DCCC8`, `func_L19_003DD9D8`, `func_L23_00415988`, `func_L23_004277B0`) | Evidence for §47's entry corrections | Each row starts with 8 to 104 bytes of epilogue words (a positive `addiu $sp,$sp,N`, `nop`), then directly a prologue `addiu $sp,$sp,-N`. None of the 137 rows that begin with such words is C. In all 1,065 placements, no branch or jump reaches the leading words.<br><br>106 rows have a reference to the prologue (a code address pair, a data pointer or a call) and none into the leading words. Two also have a data word equal to a leading address. Five have no reference found.<br><br>`func_L02_004004D0` is one of them: `func_L02_003FAF28` passes `D_L02_004004D8` as a callback, and its C equals retail from +8 except for the copy barrier. **Next:** entry corrections such as `LEVEL_ENTRY_OFFSETS`, keyed so that boot and level identity holds. I can prepare them for my eight if wanted. The list is below the table. |

<details><summary>The 113 rows, with the reference found at the prologue (programs counted per row)</summary>

- `func_002BB050` (176 bytes, 8 leading): address pair in 25 programs
- `func_002BC508` (604 bytes, 8 leading): address pair in 27 programs
- `func_002BCA08` (244 bytes, 8 leading): address pair in 27 programs
- `func_002BEBC0` (688 bytes, 8 leading): address pair in 13 programs
- `func_002BEE70` (1312 bytes, 8 leading): address pair in 22 programs
- `func_002BF518` (468 bytes, 8 leading): address pair in 27 programs
- `func_002C00F0` (260 bytes, 8 leading): address pair in 27 programs
- `func_002C01F8` (244 bytes, 8 leading): address pair in 27 programs
- `func_002C0C70` (80 bytes, 8 leading): address pair in 17 programs
- `func_002C14D8` (488 bytes, 8 leading): address pair in 27 programs
- `func_002C1DB0` (160 bytes, 8 leading): address pair in 8 programs
- `func_002C1E50` (160 bytes, 8 leading): address pair in 26 programs
- `func_002C29A0` (228 bytes, 8 leading): address pair in 27 programs
- `func_002C38A0` (64 bytes, 8 leading): address pair in 26 programs
- `func_002C3B08` (632 bytes, 8 leading): address pair in 27 programs
- `func_002C43C8` (312 bytes, 8 leading): address pair in 27 programs
- `func_002C47E8` (808 bytes, 8 leading): address pair in 27 programs
- `func_002C4B50` (456 bytes, 8 leading): address pair in 24 programs
- `func_002C5068` (180 bytes, 8 leading): address pair in 27 programs
- `func_002C5400` (332 bytes, 8 leading): address pair in 27 programs
- `func_002C64D8` (196 bytes, 8 leading): address pair in 26 programs
- `func_002C7620` (296 bytes, 8 leading): address pair in 25 programs
- `func_002C8348` (224 bytes, 8 leading): address pair in 26 programs
- `func_002DB1B0` (524 bytes, 8 leading): pointer at 00:001AB158 (+134 more)
- `func_002DC900` (436 bytes, 8 leading): pointer at 00:002866DC (+26 more) **(a data word also equals a residue address: needs review)**
- `func_002DE0D0` (716 bytes, 16 leading): none **(no reference found)**
- `func_00304210` (2240 bytes, 104 leading): pointer at 00:002A2EFC (+23 more)
- `func_00335C60` (96 bytes, 16 leading): pointer at 00:001ADC34 (+26 more)
- `func_00336288` (128 bytes, 8 leading): pointer at 00:001ADDAC (+26 more)
- `func_00336468` (44 bytes, 8 leading): pointer at 00:001ADD4C (+26 more)
- `func_003367C0` (104 bytes, 8 leading): pointer at 00:001ADD8C (+26 more)
- `func_L00_002F74F0` (120 bytes, 64 leading): address pair in 27 programs **(a data word also equals a residue address: needs review)**
- `func_L00_003B3158` (756 bytes, 8 leading): pointer at 00:002A3190 (+26 more)
- `func_L00_003B3450` (1396 bytes, 8 leading): pointer at 00:002A319C (+26 more)
- `func_L00_003B7D48` (1008 bytes, 8 leading): pointer at 00:002A31D8 (+2 more)
- `func_L00_003CA650` (52 bytes, 8 leading): address pair in 27 programs
- `func_L00_003DC640` (476 bytes, 24 leading): address pair in 27 programs
- `func_L00_00410D20` (952 bytes, 8 leading): pointer at 00:002A3838 (+11 more)
- `func_L00_004195C8` (156 bytes, 8 leading): pointer at 00:002A38A4 (+5 more)
- `func_L00_00419A80` (212 bytes, 16 leading): pointer at 00:002A38B0 (+1 more)
- `func_L01_003B1F08` (1676 bytes, 8 leading): pointer at 01:002A562C (+2 more)
- `func_L01_003D8358` (1116 bytes, 8 leading): pointer at 01:002A5890
- `func_L01_00410AD0` (1548 bytes, 8 leading): pointer at 01:002A5BB4
- `func_L01_00412E00` (280 bytes, 8 leading): pointer at 01:002A5C98
- `func_L01_0041C890` (204 bytes, 8 leading): pointer at 01:002A5D1C (+7 more)
- `func_L02_003EA180` (772 bytes, 8 leading): pointer at 02:002A6670 (+1 more)
- `func_L02_004004D0` (384 bytes, 8 leading): address pair in 1 program
- `func_L02_00439CD8` (1548 bytes, 8 leading): pointer at 02:002A6AB4
- `func_L03_0038AA20` (268 bytes, 24 leading): address pair in 1 program
- `func_L03_003C5FE8` (540 bytes, 8 leading): pointer at 03:002A98DC
- `func_L03_003C7E20` (2008 bytes, 8 leading): pointer at 03:002A9900 (+2 more)
- `func_L03_00421398` (1428 bytes, 8 leading): pointer at 03:002AA008
- `func_L04_003AB458` (512 bytes, 104 leading): pointer at 04:002CA84C
- `func_L04_003EE7C0` (1056 bytes, 8 leading): pointer at 04:002CAC90 (+1 more)
- `func_L04_00404068` (152 bytes, 8 leading): address pair in 2 programs
- `func_L04_0041AD18` (968 bytes, 8 leading): pointer at 04:002CAE10 (+1 more)
- `func_L04_0044BC90` (612 bytes, 8 leading): pointer at 04:002CB104
- `func_L05_0033D3A0` (1848 bytes, 8 leading): none **(no reference found)**
- `func_L05_00414F90` (1548 bytes, 8 leading): pointer at 05:002BBF64
- `func_L05_00419888` (1084 bytes, 16 leading): pointer at 05:002BBFB8 (+3 more)
- `func_L05_0041A228` (2164 bytes, 8 leading): address pair in 4 programs
- `func_L05_00441F30` (1128 bytes, 8 leading): pointer at 05:002BC304 (+3 more)
- `func_L06_003E1040` (104 bytes, 8 leading): address pair in 2 programs
- `func_L06_004012B0` (1388 bytes, 8 leading): pointer at 06:002E2800
- `func_L06_00455BC0` (1548 bytes, 8 leading): pointer at 06:002E2CB0
- `func_L07_003791E8` (36 bytes, 8 leading): pointer at 07:002A3640
- `func_L07_003B72E8` (1264 bytes, 8 leading): address pair in 1 program
- `func_L07_00409300` (172 bytes, 8 leading): pointer at 07:002A3DE4 (+3 more)
- `func_L07_00416510` (2048 bytes, 8 leading): pointer at 07:002A3F70 (+3 more)
- `func_L09_003FEF00` (4028 bytes, 8 leading): pointer at 09:002A6FBC
- `func_L09_0041D650` (976 bytes, 8 leading): pointer at 09:002A7238
- `func_L10_00415A50` (1548 bytes, 8 leading): pointer at 10:002BE41C
- `func_L11_0046D660` (1548 bytes, 8 leading): pointer at 11:002BCA74
- `func_L11_0046F8F0` (2220 bytes, 8 leading): pointer at 11:002BCB58 (+1 more)
- `func_L11_0047A310` (2184 bytes, 8 leading): pointer at 11:002BCC18
- `func_L12_00417690` (1548 bytes, 8 leading): pointer at 12:002A9238
- `func_L12_00418418` (2144 bytes, 8 leading): address pair in 1 program
- `func_L12_00420660` (468 bytes, 8 leading): pointer at 12:002A93F4
- `func_L12_00429D60` (236 bytes, 8 leading): address pair in 3 programs
- `func_L13_003C5908` (456 bytes, 8 leading): pointer at 13:002AE20C (+1 more)
- `func_L13_0041CD18` (1548 bytes, 8 leading): pointer at 13:002AE710
- `func_L13_0041F8B8` (808 bytes, 8 leading): pointer at 13:002AE800
- `func_L14_003E4208` (2104 bytes, 8 leading): pointer at 14:002AAB38
- `func_L14_00421BC0` (1548 bytes, 8 leading): pointer at 14:002AAED4
- `func_L15_0041F2F8` (1548 bytes, 8 leading): pointer at 15:002BC54C
- `func_L16_003A8D58` (904 bytes, 8 leading): pointer at 16:002A4A78 (+2 more)
- `func_L16_003E70E0` (220 bytes, 8 leading): address pair in 1 program
- `func_L16_004165B0` (1880 bytes, 8 leading): pointer at 16:002A5084
- `func_L16_00424B48` (168 bytes, 8 leading): pointer at 16:002A51E0
- `func_L17_00417DB0` (1548 bytes, 8 leading): pointer at 17:002A4CA8
- `func_L17_0041A4C0` (468 bytes, 8 leading): pointer at 17:002A4DB0
- `func_L18_0042FBC8` (1568 bytes, 8 leading): pointer at 18:002C15C8
- `func_L18_00436B80` (1548 bytes, 8 leading): pointer at 18:002C1610
- `func_L18_00439960` (1636 bytes, 8 leading): pointer at 18:002C16F4
- `func_L18_0043C778` (896 bytes, 16 leading): pointer at 18:002C1730
- `func_L18_00447128` (2056 bytes, 16 leading): pointer at 18:002C1880
- `func_L19_003D2E38` (1308 bytes, 8 leading): pointer at 19:002A6EB4
- `func_L19_003DCCC8` (2568 bytes, 16 leading): none **(no reference found)**
- `func_L19_003DD9D8` (3336 bytes, 8 leading): none **(no reference found)**
- `func_L19_003DFD68` (4696 bytes, 8 leading): none **(no reference found)**
- `func_L19_00412140` (3316 bytes, 8 leading): address pair in 1 program
- `func_L19_0041C3D8` (148 bytes, 8 leading): pointer at 19:002A728C
- `func_L20_00438F98` (1548 bytes, 8 leading): pointer at 20:002B62A0
- `func_L20_004451C0` (1392 bytes, 16 leading): pointer at 20:002B6408
- `func_L22_003AD090` (280 bytes, 8 leading): pointer at 22:002A71A0 (+1 more)
- `func_L22_0040F1C0` (1548 bytes, 8 leading): pointer at 22:002A7668
- `func_L22_004135F8` (1388 bytes, 8 leading): pointer at 22:002A7758
- `func_L23_00415988` (1548 bytes, 8 leading): pointer at 23:002ABCE4
- `func_L23_004277B0` (52 bytes, 8 leading): pointer at 23:002ABE40
- `func_L24_003EFA38` (1376 bytes, 8 leading): pointer at 24:002A2948 (+1 more)
- `func_L30_003E1BA0` (724 bytes, 8 leading): pointer at 30:002AA3A0
- `func_L30_00404608` (236 bytes, 8 leading): address pair in 1 program
- `func_L30_0040E660` (236 bytes, 8 leading): address pair in 1 program

</details>
