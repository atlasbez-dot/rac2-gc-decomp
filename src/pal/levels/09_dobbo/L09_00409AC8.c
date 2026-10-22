#include "include_asm.h"

INCLUDE_ASM("asm/pal/levels", func_PAL_L09_00409AC8);

INCLUDE_ASM("asm/pal/levels", func_PAL_L09_00409B48);

INCLUDE_ASM("asm/pal/levels", func_PAL_L09_00409BC0);

#include "common.h"
extern void func_L01_00321178();
extern void func_002B4FF0(f32 a);
extern s32 func_325E78(char *a0, s32 a1);
extern f32 func_2EA578(char *a0, char *a1);
extern f32 func_2EA3E0(f32 x);

void func_PAL_L09_00409F00(char *a0, s32 a1, s32 a2) {
    char *p = *(char **)(a0 + 0x68);
    if (a2 == 0) {
        func_L01_00321178();
    } else {
        func_002B4FF0(*(f32 *)(p + 0x33C));
    }
}

INCLUDE_ASM("asm/pal/levels", func_PAL_L09_00409F38);
