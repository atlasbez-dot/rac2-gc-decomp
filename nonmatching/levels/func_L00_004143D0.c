/* Retained plain-C near miss; measured 23 October 2026, USA v1.01.
 * Profile: -O2 -G0 -ffunction-sections -mno-split-addresses -fno-gcse.
 * 368/368 bytes, 0/27 placements. First instruction mismatch +0x58: resident context
 * base/field load setup, then float scheduling. Corrects the initial delta guard,
 * short-range cast and second branch using start-45. Reopen with actual context
 * declaration and expression order.
 */
#include "include_asm.h"
typedef struct { char pad[0x150]; short a, b; } Context;
extern Context D_001A6480;
extern void func_002FC560(unsigned int, unsigned long long);
extern void func_0027DE50(int, int, int, int, unsigned int);
extern void func_L00_00415210(char *, int, int, float, float, float, float, float);

void func_L00_004143D0(char *object)
{
    char *state = *(char **)(object + 0x68);
    int delta;
    if (*(short *)(state + 2) - *(short *)state < 2 &&
        *(short *)(state + 4) != 0 && *(int *)(state + 0x1C) != 0) {
        func_002FC560(0x42, 0x48ULL);
        func_0027DE50(0, D_001A6480.b, 0,
                     D_001A6480.a, 0x80808080);
    }
    if (*(int *)(state + 0x18) != 0) {
        delta = *(short *)(state + 2) - *(short *)state;
        if (delta < 10) {
            float ratio = (float)delta * 0.1f;
            float current = *(float *)(state + 8);
            float target = *(float *)(state + 12);
            func_L00_00415210(object + 0x10, 60, 0,
                             current + (target - current) * ratio,
                             0.5f, 0.0f, 0.0f, 0.0f);
        } else if ((unsigned short)(*(short *)state - 46) < 4) {
            float current = *(float *)(state + 8);
            float target = *(float *)(state + 12);
            float ratio = (float)(*(short *)state - 45) * 0.1f;
            func_L00_00415210(object + 0x10, 60, 0,
                             current + (target - current) * ratio,
                             0.5f, 0.0f, 0.0f, 0.0f);
        }
    }
}
