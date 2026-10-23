/* func_L00_00303418 - NON MATCHEE (wave 8, agent w8-09).
 *
 * The body is three walks over three per-level tables, all of them calling
 * func_L00_00303388 (the table scan that now matches) on each entry and
 * comparing the returned index with the caller's argument.  What the retail
 * bytes say:
 *
 *  - frame 0x20, $s0/$s1/$ra saved; $s1 is the caller's argument, $s0 the
 *    walk pointer;
 *  - the first table runs from 0x1B002514 to 0x1B002518 with a stride of 0x20
 *    (`lui $s0,0x1B ; lw $s0,0x2514($s0)` and the same for 0x2518), the flag
 *    byte is at +0x1E of the entry, and the store is
 *    `andi $v0,$v0,0xFB ; sb $v0,0x1E($s0)`;
 *  - the second table runs from 0x1B0023F8 to 0x1B0023FC, the same stride, and
 *    its flag byte is at +0x16 with the mask 0xFE and the bit 0x01; its walk
 *    pointer starts in a $gp cell (`lw $s0,0x2EAC($gp)` in the beql delay
 *    slot);
 *  - the third table runs from 0x1B001E9C to 0x1B001EA0 with a stride of 0x100
 *    and an inner test on the halfword at +0xAA (`lh $v0,0xAA($s0)`); the flag
 *    is the halfword at +0x34 with the mask 0xFF7F and the bit 0x80;
 *  - in each table the entry is passed to func_L00_00303388 as `a0` (the
 *    third table passes the entry + 0x10), and the result is compared with
 *    $s1 before the flag is written.
 *
 * Two things block the transcription here:
 *
 *  - the retail keeps a dead `ori $v0,$v0,0x4` between the unconditional
 *    branch and the `andi` in the first table (the branch jumps over it), so
 *    the "else" path stores the byte unchanged; a plain C spelling folds the
 *    `| 0x04` away and this compiler never keeps a dead word there;
 *  - the three walks are spelled three different ways in retail (a `beq` guard
 *    on the first, a `beql` on the second, a nested test on the third) and the
 *    register assignment of the walk pointers has to follow exactly.
 */

#include "include_asm.h"

extern int func_L00_00303388(void *);
