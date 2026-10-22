#include "include_asm.h"

INCLUDE_ASM("asm/pal/levels", func_PAL_L06_0045F6D0);

INCLUDE_ASM("asm/pal/levels", func_PAL_L06_00460E58);

INCLUDE_ASM("asm/pal/levels", func_PAL_L06_004610E0);

INCLUDE_ASM("asm/pal/levels", func_PAL_L06_00461210);

#include "common.h"
extern int func_00273B70(char *);
extern void func_002A7750(char *, int, int);
extern void func_0029F338(char *);
extern void func_L06_0045C350(unsigned char *);

void func_PAL_L06_00461470(unsigned char *a0)
{
    switch (a0[0x20]) {
    case 0:
        if (func_00273B70((char *)a0) != 0) {
            func_002A7750((char *)a0, 1, -1);
            *(unsigned short *)(a0 + 0x34) |= 0x2800;
        }
        break;
    case 1:
        func_00273B70((char *)a0);
        if (a0[0x23] < 2) {
            func_0029F338((char *)a0);
        } else {
            a0[0x23] -= 2;
        }
        break;
    }
}

INCLUDE_ASM("asm/pal/levels", func_PAL_L06_00461504);

INCLUDE_ASM("asm/pal/levels", func_PAL_L06_00461850);

INCLUDE_ASM("asm/pal/levels", func_PAL_L06_00467544);

INCLUDE_ASM("asm/pal/levels", func_PAL_L06_00468998);
