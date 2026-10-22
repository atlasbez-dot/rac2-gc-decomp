#include "include_asm.h"

INCLUDE_ASM("asm/pal/levels", func_PAL_L06_004245B0);

INCLUDE_ASM("asm/pal/levels", func_PAL_L06_004248E8);

INCLUDE_ASM("asm/pal/levels", func_PAL_L06_00424AE0);

INCLUDE_ASM("asm/pal/levels", func_PAL_L06_00424E88);

INCLUDE_ASM("asm/pal/levels", func_PAL_L06_0042FC88);

INCLUDE_ASM("asm/pal/levels", func_PAL_L06_004347BC);

INCLUDE_ASM("asm/pal/levels", func_PAL_L06_004351A8);

INCLUDE_ASM("asm/pal/levels", func_PAL_L06_00447DC8);

INCLUDE_ASM("asm/pal/levels", func_PAL_L06_004485C0);

extern void func_36C158();
extern void func_36C1B0(float);

void func_PAL_L06_00448968(char *a0, int a1, int a2)
{
    char *p = *(char **)(a0 + 0x68);

    if (a2 == 0) {
        func_36C158();
    } else {
        func_36C1B0(*(float *)(p + 0x31C));
    }
}

