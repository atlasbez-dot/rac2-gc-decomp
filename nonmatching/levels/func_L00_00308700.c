/* func_L00_00308700 - NON MATCHEE (wave 8, agent w8-09).
 *
 * Not attempted as a C body: the retail body is a table scan with a 128-bit
 * block copy in the middle and ten saved registers, and the register
 * assignment of the quad pair is the difficulty.  What the retail bytes say,
 * for the next attempt:
 *
 *  - frame 0x30, $s0-$s4 and $ra saved; the level's table base is 0x1D000000
 *    (`lui $v1,0x1D`), $s4 holds it, and the walk pointer is 0x1D000000 -
 *    0x6C60 (`addiu $v1,$v1,-0x6C60`);
 *  - the first word of the block at +0x28 decides the entry point
 *    (`lw $v0,0x28($v1) ; bnez $v0,found`);
 *  - the scan reads the word at +0x30 of the block, compares it with the
 *    first argument and then walks eight entries of 0x10 bytes
 *    (`sll $v1,$s2,4 ; addu $v1,$v1,$a3`), keeping the best match in $s2 with
 *    a `movn` (`movn $s2,$a2,$a0`);
 *  - the found entry is then processed: func_307FB8 is called with
 *    (object, the entry word, the entry + 0x38, the entry + 0x10);
 *  - a 128-bit copy (`lq`/`sq`, the R5900 0x1E/0x1F opcodes) moves the block
 *    at 0x1D000000 - 0x6C30 + (index << 4) into the block the entry names;
 *  - the function ends by storing the word at 0x1B0018D8 into the cell at
 *    0x1D000000 - 0x6C60 + 0x34.
 *
 * The ten saved registers and the quad pair's registers are the blockers.
 */

#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));
