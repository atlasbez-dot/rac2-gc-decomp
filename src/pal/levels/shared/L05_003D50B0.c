#include "include_asm.h"

INCLUDE_ASM("asm/pal/levels", func_PAL_L05_003D50B0);

INCLUDE_ASM("asm/pal/levels", func_PAL_L05_003D5330);

INCLUDE_ASM("asm/pal/levels", func_PAL_L05_003D5628);

extern char *func_379CA0(char *);
extern void func_379FA0(char *, int, int, int, float, float, float, float, int, int, int);
extern int func_332AB8(int);
extern void func_3719A8(int, int, char *, int);

/* Spawns the object's effect after three guards, then runs the timer. */
void func_PAL_L05_003D5738(char *object)
{
    char *s1 = *(char **)(object + 0x68);
    char *r;

    r = func_379CA0(object);
    if (r == 0)
        return;
    if (*(int *)(r + 0x120) == 0)
        return;
    if (*(int *)(s1 + 0x268) != 0)
        return;
    func_379FA0(object, 0x60000090, 1, 0, 0.6f, 2.0f, 1.0f, 1.3f, 0, -1, 0);
    if (func_332AB8(3) == 0)
        func_3719A8(0, 0, object, 0x97C);
    *(int *)(s1 + 0x268) = 0x32;
}

INCLUDE_ASM("asm/pal/levels", func_PAL_L05_003D5800);
