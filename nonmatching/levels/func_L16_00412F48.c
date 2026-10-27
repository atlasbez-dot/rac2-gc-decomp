#include "include_asm.h"
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern float D_L16_001B18A0 __attribute__((sda));
extern float D_L16_001B18A4;
extern u32 D_L16_001B18A8 __attribute__((sda));
extern u32 D_L16_001B18AC;
extern u32 D_L16_001B18B0;
extern u32 D_L16_001B18B4;
extern u32 D_L16_001B18B8;
extern u32 D_L16_001B18BC;
extern u32 D_L16_001B18C0 __attribute__((sda));
extern u32 D_L16_001B18C4;
extern u32 D_L16_001B18C8;
extern s32 D_L16_001B2648;

extern void func_0029FCC0(char *, int, void *);
extern float func_002A7878(float, float);
extern s32 func_002A7820(s32, s32);
extern void func_002BAE50(void *, void *, u32, s32, s32, s32, s32, s32);

/* func_L16_00412F48 - 356 bytes, 1 place. Opus near miss (M26): 356/356 B, 4 lines off with the
   L02_003F5430-g8.c profile (or plain -G8): the third func_002BAE50 call loads t0 before a1/a3
   where retail loads it after them, and the loop test lands in $v0 with bnel where retail uses
   $v1, bnez and the next pass's por in the slot. Loop direction, a do/while, dropping the w
   pointer, a local for the count and the rate local placement do not move them. */
/* The func_L02_00401D38 burst, from the object's two attachment points (func_0029FCC0)
   instead of a fixed pair of vectors. */
void func_L16_00412F48(char *a0) {
    float v0[4];
    float v1[4];
    float v2[4];
    float *w = v1;
    s32 i;
    float f;
    float rate = 0.016666668f;

    for (i = 0; i < 2; i++) {
        *(TI128 *)v2 = 0;
        f = func_002A7878(D_L16_001B18A0, D_L16_001B18A4);
        v2[2] = -(f * rate);
        *(TI128 *)v1 = *(TI128 *)v2;
        func_0029FCC0(a0, i, v0);
        if (D_L16_001B2648 & 1) {
            func_002BAE50(v0, w, D_L16_001B18A8, D_L16_001B18AC, func_002A7820(0x12, 0x16), D_L16_001B18C0, -10, 1);
        } else {
            func_002BAE50(v0, w, D_L16_001B18B0, D_L16_001B18B4, func_002A7820(0x14, 0x18), D_L16_001B18C4, -10, 1);
        }
        func_002BAE50(v0, w, D_L16_001B18B8, D_L16_001B18BC, func_002A7820(0xA, 0xF), D_L16_001B18C8, -10, 1);
    }
}
