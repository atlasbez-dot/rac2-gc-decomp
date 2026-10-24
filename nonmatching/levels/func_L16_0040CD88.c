/* -O2 -G0; US and US2: 16_snivelak: instruction at +0x48 differs; 0/1 each.
   PAL: absent from catalogue. Equal 528-byte body; initialization float registers and store order differ from +0x48. Reopen with a matching field-initializer ordering idiom. */
#include "common.h"
typedef int TI128 __attribute__((mode(TI)));
extern void func_002A7750(void *, s32, s32);
extern void func_002A7470(void *, s32, s32, void *);
extern float func_00282E48(void *, void *);
extern void func_002B60B0(void *, float, float, float, float);
extern s32 func_00283CF0(float);
extern void func_002A93B0(void *);
extern s32 func_002B0ED8(void *, void *, s32);
extern void func_L16_0040D188(u8 *);
extern s32 func_002B3BA8(void *, s32, float, float, s32, s32);
extern u8 D_L16_001B9B00[];

void func_L16_0040CD88(u8 *arg)
{
    u8 *state;
    float zero;
    state = *(u8 **)(arg + 0x68);
    if (arg[0x20] == 0) {
        *(s32 *)(state + 0x54) = 0;
        *(s32 *)(state + 0x7C) = 0;
        state[0x150] = 5;
        *(s32 *)(state + 0x188) = 3;
        *(float *)(state + 0x17C) = 0.15f;
        *(float *)(state + 0x50) = 1.8680000305175781f;
        *(float *)(state + 0x5C) = 0.5f;
        *(float *)(state + 0x60) = 3.1415929794311523f;
        *(float *)(state + 0x80) = 0.523598849773407f;
        *(float *)(state + 0x170) = 0.5f;
        *(float *)(state + 0x174) = 0.5f;
        *(float *)(state + 0x58) = 0.5f;
        func_002B60B0(arg, 0.002222222276031971f, 0.06666667014360428f, 0.0004363323678262532f, 0.03490659222006798f);
        *(s32 *)(state + 0x88) |= 2;
        if (*(s16 *)(state + 0x24) == 0) {
            *(s16 *)(state + 0x24) = 1;
            *(float *)(state + 0x20) = 1.0f;
        }
        func_002A7750(arg, 1, 0);
        if (arg[0x43]) func_002A7470(arg, 0, 0, 0);
        state[0x48] = func_00283CF0(18.0f);
        state[0x4A] = func_00283CF0(16.0f);
        *(float *)(state + 0x358) = *(float *)(arg + 0x18);
    }
    if (arg[0x31] && func_00282E48(arg + 0x10, D_L16_001B9B00) < 32.0f) {
        func_002A93B0(arg);
        arg[0x6F] = 30;
    }
    if (func_002B0ED8(arg, state + 0x140, 0)) func_L16_0040D188(arg);
    zero = 0.0f;
    *(s32 *)(state + 0x240) = func_002B3BA8(arg, *(s32 *)(state + 0x230), *(float *)(state + 0x234), zero, 0, 0);
    *(s32 *)(state + 0x354) = func_002B3BA8(arg, *(s32 *)(state + 0x350), zero, zero, 0, 0);
    *(float *)(arg + 0x18) = *(float *)(state + 0x358);
}
