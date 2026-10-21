#include "include_asm.h"

INCLUDE_ASM("asm/pal/levels", func_PAL_L07_003FD5D0);

INCLUDE_ASM("asm/pal/levels", func_PAL_L07_003FD690);

#include "common.h"
extern u8 D_L07_001B31AF __attribute__((sda));
extern u8 *D_L07_001B22DC[] __attribute__((sda));
extern s32 D_L07_001B22F8[] __attribute__((sda));
extern s32 func_002A77E0(s32 n);
extern s32 func_00282948(s32 *counter);
extern u8 *func_L07_003F6B88(u8 *a);
extern void func_002A7470(u8 *a0, s32 a1, s32 a2, s32 a3);
extern u8 D_001A7BD0 __attribute__((sda));

void func_PAL_L07_003FD928(u8 *a0)
{
    u8 *p = *(u8 **)(a0 + 0x68);

    if (*(u32 *)(p + 0x420) == 0) {
        if (*(u8 *)(a0 + 0x43) != 2) {
            func_002A7470(a0, 2, 0, 8);
        }
        return;
    }
    if (*(u8 *)(a0 + 0x43) != 8) {
        func_002A7470(a0, 8, 0, 8);
    }
}

void func_PAL_L07_003FD988(u8 *a0)
{
    u8 *p = *(u8 **)(a0 + 0x68);

    if (*(u32 *)(p + 0x420) == 0) {
        if (*(u8 *)(a0 + 0x43) != 3) {
            func_002A7470(a0, 3, 0, 8);
        }
        return;
    }
    if (*(u8 *)(a0 + 0x43) != 9) {
        func_002A7470(a0, 9, 0, 8);
    }
}

