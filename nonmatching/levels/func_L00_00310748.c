/* func_L00_00310748 - NON MATCHEE (wave 8, agent w8-09).
 *
 * Not attempted as a C body: the retail body mixes a mixed GPR/FPR frame, four
 * calls and a 128-bit copy, and this cc1's mixed-frame layout is a measured
 * wall in this repository.  What the retail bytes say, for the next attempt:
 *
 *  - frame 0xA0, $s0-$s3 and $ra saved, and $f20/$f21/$f22 saved in the frame
 *    (swc1 at 0x80/0x88/0x90, restored before the return);
 *  - $s1 is the first argument, $s3 the third, $s2 the object header word
 *    0x98($s1);
 *  - the guard is `sra $v0,$v0,5 ; slt $v0,$a1,$v0` - the count is the header
 *    word shifted right by five - and the body is skipped when it fails;
 *  - the scale is `lwc1 $f0,0x2C($s1)` divided into 1.0f (`lui $at,0x4480 ;
 *    mtc1 $at,$f20 ; div.s $f20,$f20,$f0`);
 *  - four calls follow: func_2EEBF8, func_2EE138, func_2EE5D8 and
 *    func_2EE178, the last one taking the quotient in $f12;
 *  - the result is stored as two floats at 0x1C($s2) and 0x4($s2), with
 *    `mul.s $f0,$f21,$f20` and `mul.s $f20,$f22,$f20`;
 *  - a 128-bit copy (`lq`/`sq`, the R5900 0x1E/0x1F opcodes) moves the block
 *    at 0x10($s2) to the block the object header points at.
 *
 * The mixed GPR+FPR frame is the known blocker: this compiler orders the two
 * save blocks and the scheduler interleaves them differently from retail.
 */

#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));
