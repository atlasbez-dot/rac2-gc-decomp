#include "include_asm.h"

#include "common.h"
extern void func_32C9E0();
extern void func_32C700();
extern s32 func_441868(s32 a0, s32 a1);
extern s32 func_33C800(char *a0, s32 a1, s32 a2, s32 a3, float f12, float f13);

void func_PAL_L11_0044E398(char *a0)
{
    if (*(s32 *)(*(char **)(a0 + 0x68) + 0x354) != 0) {
        func_32C9E0(a0, 4, 2);
        if (*(u8 *)(a0 + 0x43) != 0)
            func_32C700(a0, 0, 0, 0x8);
    } else {
        func_32C9E0(a0, 5, 2);
        if (*(u8 *)(a0 + 0x43) != 1)
            func_32C700(a0, 1, 0, 0x8);
    }
}

INCLUDE_ASM("asm/pal/levels", func_PAL_L11_0044E538);
