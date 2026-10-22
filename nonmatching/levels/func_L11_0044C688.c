/* func_L11_0044C688 (396 bytes, to be placed in a dedicated source unit built with
 * -frac2-qcopy) -- BEST ATTEMPT
 * check.py: 11_joba: 15 instructions differ (the size is right: 396 bytes).
 * Measured with "-O2 -G0 -ffunction-sections -frac2-qcopy"; the -frac2-qcopy flag is
 * what gives the retail's "addiu $v1,$s0,0x470 ; lq $v0,0($s1) ; sq $v0,0($v1)":
 * without it this cc1 folds the constant offset into the sq.
 * What still differs:
 *   - the order in which the two float constants of a call are loaded (retail loads
 *     the $f12 one first, this cc1 loads the $f13 one first in two of the three
 *     calls); the constants themselves and their registers are right;
 *   - the second half's "add.s $f20,$f0,$f1" (the +8.0 of the k value) is scheduled
 *     after the lq/sq pair instead of before it.
 * Tried and measured without effect: the sum as "a + b" and as "a += b"; the
 * 15.0f and the -2.0f/2.0f spelled as doubles, as "+ -x" and with more digits;
 * the two float arguments of a call passed through locals; the 15.0f through a
 * local; -fno-schedule-insns, -fno-schedule-insns2 and -fno-gcse (all worse).
 * The block-scoped "float sum;" / "float sum, k;" declarations are what fixed the
 * $f20/$f21 allocation, so keep them.
 */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern float func_300BD0(float f12, float f13);
extern float func_32CB48(float f12, float f13);
extern float func_300B08(float f12);
extern float func_300B20(float f12);

void func_L11_0044C688(char *a0, TI128 *a1)
{
    char *s0 = *(char **)(a0 + 0x68);
    float f12, f13;
    if (*(s16 *)(s0 + 0x4D2) != 0) {
        float sum;
        f12 = *(float *)(a0 + 0x10) - *(float *)a1;
        f13 = *(float *)(a0 + 0x14) - *(float *)((char *)a1 + 4);
        sum = func_300BD0(f12, f13);
        sum += func_32CB48(-0.78539825f, 0.78539825f);
        *(TI128 *)(s0 + 0x470) = *a1;
        *(float *)(s0 + 0x470) = *(float *)(s0 + 0x470) + func_300B08(sum) * 15.0f;
        *(float *)(s0 + 0x474) = *(float *)(s0 + 0x474) + func_300B20(sum) * 15.0f;
        *(float *)(s0 + 0x478) = func_32CB48(0.0f, 4.0f) + 466.0f;
    } else {
        float sum, k;
        f12 = *(float *)(a0 + 0x10) - *(float *)a1;
        f13 = *(float *)(a0 + 0x14) - *(float *)((char *)a1 + 4);
        sum = func_300BD0(f12, f13);
        sum += func_32CB48(-0.78539825f, 0.78539825f);
        k = func_32CB48(-2.0f, 2.0f);
        k += 8.0f;
        *(TI128 *)(s0 + 0x470) = *a1;
        *(float *)(s0 + 0x470) = *(float *)(s0 + 0x470) + k * func_300B08(sum);
        *(float *)(s0 + 0x474) = *(float *)(s0 + 0x474) + k * func_300B20(sum);
    }
}
