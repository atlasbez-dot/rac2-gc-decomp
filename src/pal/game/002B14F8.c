#include "include_asm.h"

INCLUDE_ASM("asm/pal/game", func_PAL_002B14F8);

INCLUDE_ASM("asm/pal/game", func_PAL_002B1570);

void func_PAL_002B1588(int first, int second)
{
    extern int func_00288FB8(int);
    extern void func_0029CC98(int, int);
    func_0029CC98(func_00288FB8(first), second);
}

extern void func_0029CC50(int, int, int);

void func_PAL_002B15B8(int first, int second, int third) {
    func_0029CC50(first, second, third);
}

INCLUDE_ASM("asm/pal/game", func_PAL_002B15D8);
