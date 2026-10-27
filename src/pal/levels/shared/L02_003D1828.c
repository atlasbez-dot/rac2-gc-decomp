#include "include_asm.h"

INCLUDE_ASM("asm/pal/levels", func_PAL_L02_003D1828);

INCLUDE_ASM("asm/pal/levels", func_PAL_L02_003D18D8);

INCLUDE_ASM("asm/pal/levels", func_PAL_L02_003D24B8);

#include "common.h"
extern void func_L02_00333438(char *, char *);
extern int func_L01_00321178(char *, char *);
extern int func_002B4FF0(char *, float *, float);
extern int D_L02_001A8FF0 __attribute__((sda));

/* Runs the kind's entry hook: the first when the level flag is set, the second when the third
   argument is clear, the third with the object's own angle otherwise. */
void func_PAL_L02_003D2898(char *a0, char *a1, int a2) {
    char *p = *(char **)(a0 + 0x68);

    if (D_L02_001A8FF0)
        func_L02_00333438(a0, a1);
    else if (a2 == 0)
        func_L01_00321178(a0, a1);
    else
        func_002B4FF0(a0, (float *)a1, *(float *)(p + 0x31C));
}

INCLUDE_ASM("asm/pal/levels", func_PAL_L02_003D28F0);
