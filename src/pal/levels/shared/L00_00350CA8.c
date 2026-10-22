#include "include_asm.h"

extern int D_00138344;
extern void func_L00_0030E010(int a);

int func_PAL_L00_00350CA8(void)
{
    func_L00_0030E010(D_00138344);
    return 0;
}

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_00350CD0);
