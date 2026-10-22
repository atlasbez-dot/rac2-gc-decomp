#include "include_asm.h"

typedef signed int s32;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;

typedef int TI128 __attribute__((mode(TI)));

extern s32 func_00342228(u8 *a0, s32 a1);
extern void func_0030C948(u8 *a0, s32 a1, s32 a2, s32 a3);
extern void func_0030ED98(u8 *a0, u8 *a1, u8 *a2);
extern void func_0030F8B8(u8 *a0, u8 *a1);
extern void func_0030F298(u8 *a0, u8 *a1, u8 *a2);
extern f32 func_0030FE40(f32 x, f32 y);
extern f32 func_0030F3A0(f32 x);
extern f32 func_0030F3B8(f32 x);

extern u8 D_L04_00254E10[];

INCLUDE_ASM("asm/levels", func_L04_0040F8F0);

INCLUDE_ASM("asm/levels", func_L04_00410518);

INCLUDE_ASM("asm/levels", func_L04_00410788);

/* Scans the 0x20 slots at +0x110 of the state block for the first whose stored id the
   matcher accepts, and records its index in +0x270. */
void func_L04_00410F10(u8 *arg0) {
    u8 *s2 = *(u8 **)(arg0 + 0x68);
    s32 *p = (s32 *)(s2 + 0x110);
    s32 i;

    for (i = 0; i < 0x20; i++) {
        if (func_00342228(arg0 + 0x10, *p) != 0) {
            *(s32 *)(s2 + 0x270) = i;
            return;
        }
        p++;
    }
}

INCLUDE_ASM("asm/levels", func_L04_00410F80);

INCLUDE_ASM("asm/levels", func_L04_00411298);

INCLUDE_ASM("asm/levels", func_L04_00412130);

INCLUDE_ASM("asm/levels", func_L04_00412308);

INCLUDE_ASM("asm/levels", func_L04_00412C58);

float func_00283180(float);
float func_00283198(float);
float func_00283B98(float, float);

void func_L04_00412E38(void *arg0, void *arg1, float fparg0, float fparg1) {
    float temp_f0;
    float temp_f1;
    float temp_f20;

    temp_f0 = func_00283B98((*(float *)((unsigned char *)arg1 + 0x38C)), fparg0);
    *(float *)((unsigned char *)arg1 + 0x38C) = temp_f0;
    temp_f20 = func_00283180(temp_f0) * fparg1;
    temp_f1 = (*(float *)((unsigned char *)arg0 + 0xF4)) + (func_00283198((*(float *)((unsigned char *)arg1 + 0x38C))) * fparg1);
    *(float *)((unsigned char *)arg0 + 0xF0) = (float) ((*(float *)((unsigned char *)arg0 + 0xF0)) + temp_f20);
    *(float *)((unsigned char *)arg0 + 0xF4) = temp_f1;
}

INCLUDE_ASM("asm/levels", func_L04_00412EC0);

INCLUDE_ASM("asm/levels", func_L04_004135B8);

INCLUDE_ASM("asm/levels", func_L04_00413A38);

INCLUDE_ASM("asm/levels", func_L04_00414698);

/* func_L04_00415E28 is a near miss: nonmatching/levels/func_L04_00415E28.c */
INCLUDE_ASM("asm/levels", func_L04_00415E28);

/* func_L04_00415EA8 is a near miss: nonmatching/levels/func_L04_00415EA8.c */

INCLUDE_ASM("asm/levels", func_L04_00415EE8);

INCLUDE_ASM("asm/levels", func_L04_00416018);

INCLUDE_ASM("asm/levels", func_L04_00416390);

INCLUDE_ASM("asm/levels", func_L04_004167B0);

INCLUDE_ASM("asm/levels", func_L04_00416E38);

INCLUDE_ASM("asm/levels", func_L04_00417028);
