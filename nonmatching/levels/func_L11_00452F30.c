/* func_L11_00452F30 (396 bytes, to be placed in a dedicated source unit built with
 * -frac2-qcopy) -- BEST ATTEMPT
 * check.py: 11_joba: 15 instructions differ (the size is right: 396 bytes).
 * This is the twin of func_L11_0044C688: the same body with the state's 0x4D2 test
 * at 0x2D8 and the 0x470 table at 0x2A0, so it has the same remaining deviations
 * (the order in which the two float constants of a call are loaded, and the place
 * of the second half's "add.s $f20,$f0,$f1").
 * See nonmatching/levels/func_L11_0044C688.c for the measured attempts.
 */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern float func_300BD0(float f12, float f13);
extern float func_32CB48(float f12, float f13);
extern float func_300B08(float f12);
extern float func_300B20(float f12);

void func_L11_00452F30(char *a0, TI128 *a1)
{
    char *s0 = *(char **)(a0 + 0x68);
    float f12, f13;
    if (*(s16 *)(s0 + 0x2D8) != 0) {
        float sum;
        f12 = *(float *)(a0 + 0x10) - *(float *)a1;
        f13 = *(float *)(a0 + 0x14) - *(float *)((char *)a1 + 4);
        sum = func_300BD0(f12, f13);
        sum += func_32CB48(-0.78539825f, 0.78539825f);
        *(TI128 *)(s0 + 0x2A0) = *a1;
        *(float *)(s0 + 0x2A0) = *(float *)(s0 + 0x2A0) + func_300B08(sum) * 15.0f;
        *(float *)(s0 + 0x2A4) = *(float *)(s0 + 0x2A4) + func_300B20(sum) * 15.0f;
        *(float *)(s0 + 0x2A8) = func_32CB48(0.0f, 4.0f) + 466.0f;
    } else {
        float sum, k;
        f12 = *(float *)(a0 + 0x10) - *(float *)a1;
        f13 = *(float *)(a0 + 0x14) - *(float *)((char *)a1 + 4);
        sum = func_300BD0(f12, f13);
        sum += func_32CB48(-0.78539825f, 0.78539825f);
        k = func_32CB48(-2.0f, 2.0f);
        k += 8.0f;
        *(TI128 *)(s0 + 0x2A0) = *a1;
        *(float *)(s0 + 0x2A0) = *(float *)(s0 + 0x2A0) + k * func_300B08(sum);
        *(float *)(s0 + 0x2A4) = *(float *)(s0 + 0x2A4) + k * func_300B20(sum);
    }
}
