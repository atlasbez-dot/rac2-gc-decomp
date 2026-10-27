/* mid-9 draft: all stores, constants, calls match; 428 B vs 420. Retail does not CSE self+0x10 (qcopy source, later arg of func_2F1AE8): it computes addiu v1,s0,0x10 for the lq and again later, so no $s2 and a 0x20 frame; here the shared pointer takes $s2 (0x30 frame). Needs -G8 -frac2-qcopy. */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern float D_L12_001B2C84 __attribute__((sda));
extern float D_L12_001B2C80 __attribute__((sda));
extern char D_L12_001B9E00[];

extern void func_31E1D0(char *, int, int);
extern void func_31DEF0(char *, int, int, int);
extern void func_330B70(char *, float, float, float, float);
extern float func_2F1AE8(void *, void *);
extern void func_320368(char *);

void func_L12_0041A2B8(char *self) {
    char *state = *(char **)(self + 0x68);

    if (*(u8 *)(self + 0x20) == 0) {
        *(u8 *)(self + 0x30) = 0xC8;
        *(u16 *)(self + 0x32) = 0xC8;
        *(TI128 *)(state + 0x210) = *(TI128 *)(self + 0x10);
        *(float *)(state + 0x21C) = *(float *)(self + 0xF8);
        *(int *)(self + 0x98) = 0;
        *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
        func_31E1D0(self, 1, 0);
        if (*(u8 *)(self + 0x43) != 0) {
            func_31DEF0(self, 0, 0, 0);
        }
        *(float *)(state + 0x128) = 0.5f;
        *(float *)(state + 0x124) = 0.5f;
        *(float *)(state + 0x130) = 3.14159012f;
        *(int *)(state + 0x15C) = -1;
        *(float *)(state + 0x14C) = 0.00555555569f;
        *(float *)(state + 0x150) = 0.261799425f;
        *(float *)(state + 0x12C) = 0.5f;
        *(float *)(state + 0x120) = 0.4f;
        *(float *)(state + 0x154) = 0.25f;
        func_330B70(self, 0.0088888891f, D_L12_001B2C84 * 0.016666668f, 0.00349065894f, 0.209439546f);
        *(int *)(state + 0x258) = 0;
        *(int *)(state + 0x11C) = 0;
        *(float *)(self + 0x2C) = *(float *)(*(char **)(self + 0x24) + 0x24) * D_L12_001B2C80;
        if (*(u8 *)(self + 0x31) != 0) {
            if (func_2F1AE8(self + 0x10, D_L12_001B9E00) < 24.0f) {
                func_320368(self);
                *(u8 *)(self + 0x6F) = 0x16;
            }
        }
    }
}
