#include "include_asm.h"

#include "common.h"
extern void func_3F7CD8(s32);
extern void func_3F7EF8(s32);
extern void func_3F80A0(s32);
extern void func_3F8A98(s32);
extern void func_3F8C08(s32);
extern s32 func_001163B0(void);
extern s32 func_00283CF0(float);
extern u8 *D_L18_001FF4D4;

void func_PAL_L18_003FBD28(s32 a0)
{
    u8 v = *(u8 *)(a0 + 0x20);

    if (v == 0) {
        func_3F7CD8(a0);
        return;
    }
    if (v == 1)
        return;
    func_3F7EF8(a0);
    func_3F80A0(a0);
    func_3F8A98(a0);
    func_3F8C08(a0);
}

INCLUDE_ASM("asm/pal/levels", func_PAL_L18_003FBD90);

INCLUDE_ASM("asm/pal/levels", func_PAL_L18_003FBFB0);

INCLUDE_ASM("asm/pal/levels", func_PAL_L18_003FC158);

INCLUDE_ASM("asm/pal/levels", func_PAL_L18_003FCB78);

INCLUDE_ASM("asm/pal/levels", func_PAL_L18_003FCCE8);
