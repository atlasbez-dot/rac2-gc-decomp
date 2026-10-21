#include "include_asm.h"

extern int ref_L00_002A3B80_00;

int func_L00_002A3B80(void)
{
    return ref_L00_002A3B80_00;
}

INCLUDE_ASM("asm/levels", func_L00_002A3B88);

INCLUDE_ASM("asm/levels", func_L00_002A4928);

INCLUDE_ASM("asm/levels", func_L00_002A4D18);

extern void func_002A1130(void *a0, int a1, int a2, int a3);

extern void func_00282B50(int a0, int a1, int a2);

extern void func_0011AEA0(int a0);

/* walks one loaded entry of an owner's list and hands it to the vector routine when the
   tag bits are set, else to the count-driven copy, then polls and returns the caller's
   handle */
int func_L00_002A4DB0(char *a0, int a1, int a2, int a3)
{
    char *owner = *(char **)(a0 + 0x24);
    char **rows = (char **)(owner + 0x48);
    char *row = rows[a1];
    int *words = (int *)(row + 0x1C);
    int entry = words[a2];

    if (entry & 0xF0000000)
        func_002A1130(row + 0x1C + (*(unsigned char *)(row + 0x10) << 2) - -(*(unsigned char *)(row + 0x13) << 2), entry, a3, *(unsigned char *)(owner + 8));
    else
        func_00282B50(a3, entry, (*(short *)(entry + 6) + 1) << 4);
    func_0011AEA0(0);
    return a3;
}


INCLUDE_ASM("asm/levels", func_L00_002A4E48);
