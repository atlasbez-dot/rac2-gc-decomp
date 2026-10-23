/* func_L00_002FCF18 - NON MATCHEE (wave 8, agent w8-09).
 *
 * Not attempted as a C body: the retail body is a scan of an eight-entry table
 * with a 128-bit move and five float stores in the middle of it, and the
 * register assignment of the two 128-bit blocks is the whole difficulty.  What
 * the retail bytes say, for the next attempt:
 *
 *  - frame 0x20, $s0/$s1/$ra saved, the table base is 0x1C007040
 *    (`lui $v0,0x1C ; addiu $v0,$v0,0x7040`), the entries are 0x30 apart and
 *    start 0x10 into the table (`addiu $v1,$v0,0x10 ; addiu $v1,$v1,0x30`);
 *  - the loop counts the entries in $s1 and stops on the first entry whose
 *    first word is zero (`lw $v0,0x0($v1) ; bnel $v0,$zero,loop`); the entry
 *    count is bounded by 8 (`slti $v0,$s1,0x8`); when the count reaches 8 the
 *    function returns -1 (`addiu $v0,$zero,-0x1`);
 *  - on a hit the block at 0x1C006F40 + (index << 5) is rebuilt: a sixteen
 *    byte `lq`/`sq` moves the block at 0x1C006F50 + (index << 5) down to it
 *    (`lq $v0,0($a0) ; sq $v0,0($v1)`, the R5900 quad load and store, both
 *    plain 0x1E/0x1F opcodes), then $f13/$f12/$f14/$f15/$f16 are stored into
 *    it at +0xC/+0x1C/+0x0/+0x4/+0x8;
 *  - func_2EDE88 is then called with the block + 0x10 and the size 0x30
 *    (`daddu $a0,$s0,$zero ; addiu $a1,$zero,0x30`), and the entry gets the
 *    word 1 at +0x10 and the pointer 0x1C0071C0 + (index << 10) at +0xC
 *    (`sll $v1,$s1,10 ; addu $v1,$v1,$v0`);
 *  - the function returns the index in $v0.
 *
 * The three-operand multiply the retail uses (`mult $s1,$s0` with $s0 = 0x30)
 * is the R5900 three-register form this compiler can emit, so the index
 * scaling is not the blocker; the quad pair's registers are.
 */

#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

extern int D_L00_1C007040[];

extern int D_L00_1C006F40[];

extern int D_L00_1C006F50[];

extern int D_L00_1C0071C0[];

extern void func_2EDE88(void *, int);
