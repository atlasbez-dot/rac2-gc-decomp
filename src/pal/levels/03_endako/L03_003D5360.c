#include "include_asm.h"

INCLUDE_ASM("asm/pal/levels", func_PAL_L03_003D5360);

INCLUDE_ASM("asm/pal/levels", func_PAL_L03_003D56E8);

INCLUDE_ASM("asm/pal/levels", func_PAL_L03_003D5A98);

INCLUDE_ASM("asm/pal/levels", func_PAL_L03_003D5B68);

#include "common.h"
extern void func_324168(s32 a0, s32 a1);
extern void func_30D710(s32 a0, s32 a1);
extern s32  func_32AB10(char *a0);
extern s32  func_360A80(s32 a0, s32 a1, char *a2);
extern s32  func_312898(s32 a0, s32 a1, void *a2);
extern void func_30D710(s32 a0, s32 a1);

void func_PAL_L03_003D6150(char *a0)
{
    char *s0 = *(char **)(a0 + 0x68);

    func_324168(*(s32 *)(s0 + 0x18), *(s32 *)(s0 + 0x1C));
    func_30D710(0, -1);
    *(u16 *)(*(s32 *)(s0 + 0x2C) + 0x34) |= 0x41;
    *(u16 *)(*(s32 *)(s0 + 0x2C) + 0x34) &= ~0x1000;
    *(s32 *)(*(s32 *)(s0 + 0x2C) + 0x98) = 0;
    *(u16 *)(*(s32 *)(s0 + 0x2C) + 0x96) = 0;
}

INCLUDE_ASM("asm/pal/levels", func_PAL_L03_003D61B8);

INCLUDE_ASM("asm/pal/levels", func_PAL_L03_003D6298);

INCLUDE_ASM("asm/pal/levels", func_PAL_L03_003D6468);
