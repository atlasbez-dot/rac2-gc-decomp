/* func_L00_003EEE20: 100 bytes against 108; the whole body matches except the two
 * instructions retail has where this compiler has one.
 *
 * What is now measured about the two missing nops (scratch/hz.s assembled with the
 * game's assembler):
 *   - the copy of the divisor is `mtc1 $s0,$f12 ; cvt.s.w $f12,$f12`; the game's
 *     assembler puts one hazard nop after the mtc1 and none between the cvt.s.w and
 *     the div.s, so retail's two nops in front of the div.s are NOT a hazard nop;
 *   - they are the division floor of pad_div_erratum_nops.py: with a code label right
 *     before the div.s the assembler emits exactly two nops before it, and with no
 *     label it emits none. Retail's label sits in front of its two nops.
 * So the missing piece is a source form that makes the compiler emit a label right
 * before the div.s, and that keeps the mtc1 out of the first call's delay slot (retail
 * has a nop there, this compiler fills the slot with the mtc1).
 *
 * The retail body: the integer remainder of a0 by 16 decides the path; on a non-zero
 * remainder the float result of func_00283CE0 is divided by the int 16 converted to
 * float (the mtc1 + cvt.s.w pair), the result goes through func_00283CF0, and the
 * return value is (that + 1) << 4.
 *
 * Tried: the divisor as a variable, as (float)d, as a separate float variable, the
 * modulo in a variable, the division before the test, the cast through double, the
 * increment as a separate statement, -fno-schedule-insns, -frac2-keep-block-order,
 * -frac2-gcse-unsplit-edges and -frac2-hazard-labels. The SDK profile (2.9-ee) gives a
 * different body (beq instead of beql, a 32-byte frame, the div.s in a delay slot).
 */
extern float func_00283CE0(int a0);

extern int func_00283CF0(float f);

int func_L00_003EEE20(int a0)
{
    int d = 16;

    if (a0 % d != 0) {
        a0 = (func_00283CF0(func_00283CE0(a0) / d) + 1) << 4;
    }
    return a0;
}
