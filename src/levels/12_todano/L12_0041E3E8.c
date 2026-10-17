#include "common.h"

INCLUDE_ASM("asm/levels", func_L12_0041E3E8);

s32 func_L12_0041E8E8(u8 *a0) {
    return *(u8 *)(a0 + 0x20) == 3;
}


INCLUDE_ASM("asm/levels", func_L12_0041EA18);

INCLUDE_ASM("asm/levels", func_L12_0041EDB8);

INCLUDE_ASM("asm/levels", func_L12_00420660);

INCLUDE_ASM("asm/levels", func_L12_00420838);

INCLUDE_ASM("asm/levels", func_L12_00420950);

INCLUDE_ASM("asm/levels", func_L12_00420B78);

INCLUDE_ASM("asm/levels", func_L12_00421110);

INCLUDE_ASM("asm/levels", func_L12_004212C0);

INCLUDE_ASM("asm/levels", func_L12_00424370);

INCLUDE_ASM("asm/levels", func_L12_00425070);

INCLUDE_ASM("asm/levels", func_L12_00425178);

INCLUDE_ASM("asm/levels", func_L12_00425348);

extern int func_00282948(void *);
extern s32 func_002A7820(s32, s32);
extern s32 func_002E5CF8(s32, s32, void *);
extern s32 D_L12_001B20C0 __attribute__((sda));

/* Starts the sub-object's timer when it has finished, then tells the engine to
   advance to mode 1.  The sub-object word at 0x001B20C4 is an absolute literal:
   written as a symbol it takes an extra register, and the gp one at 0x30D0 needs
   its `sda` declaration (measured). */
void func_L12_00425448(u8 *a0) {
    u8 *s0 = *(u8 **)(a0 + 0x68);

    if (func_00282948(s0 + 0x2C0) != 0) {
        *(s32 *)(s0 + 0x2C0) = func_002A7820(D_L12_001B20C0, (s32)*(u8 **)0x001B20C4);
        func_002E5CF8(1, 0, a0);
    }
}


INCLUDE_ASM("asm/levels", func_L12_004285A8);

INCLUDE_ASM("asm/levels", func_L12_004293A0);

INCLUDE_ASM("asm/levels", func_L12_00429610);

INCLUDE_ASM("asm/levels", func_L12_00429868);
