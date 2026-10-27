/* func_L04_0040BD50 (380 B, levels 04 and 11), M31 26 Oct 2026: 392 of 380 bytes at the
   default -G0. The body matches; cc1 hoists &size (the address-taken float parameter at
   0x20($sp)) into a fourth saved register where retail rebuilds addiu a1,sp,0x20 per
   iteration, so the frame grows by 0x10. Retail also tests bnez (a counted loop). */
#include "include_asm.h"
#include "common.h"

typedef int TI __attribute__((mode(TI)));

extern int func_00283CF0(float);
extern int func_002A77E0(int);
extern float func_002A7878(float, float);
extern void func_002C19D8(void *, void *, int, float, float);
extern void *func_00312D58(float *, float);

void func_L04_0040BD50(TI *at, s32 n, f32 size, f32 power) {
    f32 pos[4] __attribute__((aligned(16)));
    f32 p[4] __attribute__((aligned(16)));
    f32 *src = pos;
    s32 i;

    *(TI *)pos = *at;
    if (0.12f <= power) {
        if (func_002A77E0(func_00283CF0(1.0f / power) + 1) == 0) {
            func_00312D58(pos, func_002A7878(0.5f, 1.25f) * power * 9.0f);
        }
    }
    if (0.1f <= power) {
        for (i = 0; i < n; i++) {
            p[0] = src[0] + func_002A7878(-0.3f, 0.3f);
            p[1] = src[1] + func_002A7878(-0.3f, 0.3f);
            p[2] = src[2];
            func_002C19D8(p, &size, -1, func_002A7878(0.3f, 0.6f), 5250.0f);
        }
    }
}
