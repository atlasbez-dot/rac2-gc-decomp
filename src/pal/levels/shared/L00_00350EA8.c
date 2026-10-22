#include "include_asm.h"

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_00350EA8);

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_00350F30);

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_00351000);

extern int D_00138344;
extern void func_L00_0030E010(int a);

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_00351088);

extern void func_0027C540_1(long);
extern void func_L00_0030DFE0(void);
extern void func_0027C660_1(void);

/* Run the three measured setup calls with an explicit long zero, then return the defined integer zero. */
long long func_PAL_L00_003510B0(void)
{
    func_0027C540_1(0);
    func_L00_0030DFE0();
    func_0027C660_1();
    return 0;
}

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_003510E0);
