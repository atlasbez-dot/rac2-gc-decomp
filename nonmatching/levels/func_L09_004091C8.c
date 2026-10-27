/* func_L09_004091C8 (320 B), M31 26 Oct 2026: 332 of 320 bytes as L09_004091C8-zp.c with
   -O2 -G0 -ffunction-sections -frac2-zero-ti-por (por qzero). Everything up to the i&1 test
   matches. Retail hoists the odd call setup above the branch and the even arm reuses
   a0/a1/a2 (pos, vel, 0x77FF0060), re-setting only a3/t0..t3; cc1 re-materialises a0..a2
   in the second arm. Ternaries give movn, a shared call gives 300 B. */
#include "include_asm.h"
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern float func_00283CE0(int);
extern void func_0029FCC0(void *, int, void *);
extern float func_002A7878(float, float);
extern void func_002BAE50(void *, void *, u32, s32, s32, s32, s32, s32);

void func_L09_004091C8(void *self) {
    float pos[4] __attribute__((aligned(16)));
    float vel[4] __attribute__((aligned(16)));
    float v[4] __attribute__((aligned(16)));
    s32 i;

    *(TI128 *)v = 0;
    i = 0;
    v[2] = -(func_002A7878(3.5f, 4.5f) * 0.016666668f);
    *(TI128 *)vel = *(TI128 *)v;
    do {
        func_0029FCC0(self, 2, pos);
        pos[2] = pos[2] + func_00283CE0(i) * 0.015f;
        if (!(i & 1)) {
            func_002BAE50(pos, vel, 0x77FF0060, 0xFF0000, 0x13, 0xDC, -100, 1);
        } else {
            func_002BAE50(pos, vel, 0x77FF0060, 0xFF0060, 0x11, 0x96, -100, 1);
        }
        i++;
        func_002BAE50(pos, vel, 0x77FFFFFF, 0xFF0000, 10, 0x50, -0x50, 1);
    } while (i < 2);
}
