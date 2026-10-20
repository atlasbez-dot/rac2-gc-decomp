#include "include_asm.h"

/* This unit is built with -G8: every body here reaches a global through $gp.
   The markers below are the functions of L20_0039C448.c whose retail bodies access
   data through $gp; they are written in this file, which the build compiles with -G8. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* 0x1AEFF0 + 0x39F0 : this symbol is written through $gp (gas emits the
 * gp-relative form because the store sits in the bc1f delay slot), so the
 * file has to be compiled with -G8 and the symbol marked sda. */
extern float D_L20_001B29E0 __attribute__((sda));

/* 0x1AEFF0 + 0x39F0 again, under a second name: gcc must not see the two
 * stores as one dead store, and gas expands this one to lui $at / swc1. */
extern float D_L20_001B29E0_1;

void func_L20_004095D0(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);
    float v = *(float *)(state + 0xC) * 1.2f;

    D_L20_001B29E0 = v;
    if (v > 1.0f) {
        D_L20_001B29E0_1 = 1.0f;
    }
}

INCLUDE_ASM("asm/levels", func_L20_0039D680);

INCLUDE_ASM("asm/levels", func_L20_0039E368);

INCLUDE_ASM("asm/levels", func_L20_0039E5F0);

INCLUDE_ASM("asm/levels", func_L20_0039E890);

INCLUDE_ASM("asm/levels", func_L20_0039E9F8);

INCLUDE_ASM("asm/levels", func_L20_0039ED78);

INCLUDE_ASM("asm/levels", func_L20_003A0320);

INCLUDE_ASM("asm/levels", func_L20_003BFEB8);

INCLUDE_ASM("asm/levels", func_L20_003C0048);

INCLUDE_ASM("asm/levels", func_L20_00408D98);

INCLUDE_ASM("asm/levels", func_L20_00438F98);
