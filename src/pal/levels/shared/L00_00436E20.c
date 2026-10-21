#include "include_asm.h"

extern void func_0033AB50(char *p);

/* Calls a helper with a pointer to the second 16-byte field of the record and returns the record pointer. */
char *func_PAL_L00_00436E20(char *object)
{
    func_0033AB50(object + 8);
    return object;
}

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_004371C0);

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_004374C0);

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_00437A48);

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_00437BA8);

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_004384D0);

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_00438798);

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_004387D0);

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_004388F8);

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_00438B60);

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_00438CC0);

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_00438E58);

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_00438E90);

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_00438FB8);

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_00439098);

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_004390D0);

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_004391F8);

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_004392D8);

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_00439630);

extern int func_0033AF48(char *p);

int func_PAL_L00_004397D0(char *p)
{
    return func_0033AF48(p + 8);
}

