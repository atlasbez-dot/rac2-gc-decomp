/* 0 of 1 place match - last line: 02_maktar_nebula: instruction at +0x0 differs
   The 0x7FFF-masked id-list walk of the family already matched in L01_003CAFE0-g8.c
   (func_L01_003D87B8) and L04_00422A00-g8.c, transcribed from that skeleton and measured once:
   p = table[arg0[0x21]]; do { v = *p; e = base + ((v & 0x7FFF) << 8); if (!e) return; p++;
   *(int *)(e + 0x98) = *(int *)(*(int *)(e + 0x24) + 0x10); } while (guards).
   It does not land here, and the reason is visible in the first four words: retail reaches the
   loop with `daddu $a2,$a0,$zero` and keeps the walk pointer in $a1, ours uses $a3 for the
   object and $a2 for the walk pointer, and - the structural part - this cc1 ROTATES the loop,
   hoisting the `*(s16 *)(p-1) >= 0` test to the top and emitting `bgezl` + `lhu` where retail
   leaves them at the bottom as `lh -0x2($a1)` + `bgezl` + `lhu` after a forward entry
   `b COND`. Retail also emits a plain `beqz $a1` + `nop` for the null-pointer guard where this
   cc1 makes it a `bnel`.
   Retail's shape, for the next attempt: the entry jumps FORWARD over the body to the guard
   block; the body runs at the lower address; the guards end
   `lh $v0,-0x2($a1) ; bgezl -> body / lhu $v0,0x0($a1)` then
   `lw $a0,table[index] ; beql $a1,$a0, -> body / lhu $v0,0x0($a1)`; the byte at arg0+0x21 is
   re-loaded every iteration and the small-data word is read as `lw $v0,0x45C8($gp)`.
   What unblocks it: a spelling that stops the rotation, or the two-names-for-one-pointer
   recipe the sixth wave used for func_L08_00328BB0. */

#include "include_asm.h"

INCLUDE_ASM("asm/levels", func_L02_003EB098);
