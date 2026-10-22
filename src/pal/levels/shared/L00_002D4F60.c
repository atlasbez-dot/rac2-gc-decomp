#include "include_asm.h"

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_002D4F60);

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_002D5150);

extern char D_00189E20_4D98[];
extern char *func_0029EFD0(int);
extern void func_L00_002AA178(char *);
extern void func_L00_002B0968(char *);

/* One-shot spawn: arms the state word, and when the slot is free asks the allocator for a
   0x50A object, writes its flags, the packed constant at +0x38 and the level's tag, then runs
   the two level entry points on the argument. */
void func_PAL_L00_002D52C0(char *arg0) {
    char *base = D_00189E20_4D98;
    char *node;

    *(int *)(base + 0x12E8) = 0x2F;
    if (*(int *)(base + 0x12C0) == 0) {
        node = func_0029EFD0(0x50A);
        if (node != 0) {
            *(unsigned short *)(node + 0x32) = 0x20;
            *(unsigned short *)(node + 0x34) =
                *(unsigned short *)(node + 0x34) | 2;
            *(unsigned char *)(node + 0x31) = 1;
            *(unsigned long *)(node + 0x38) = 0x20202000000000UL;
            *(int *)(node + 0x64) = 0;
            if (*(unsigned char *)(*(int *)(node + 0x24) + 6) != 0)
                *(unsigned char *)(node + 0x63) = 0x10;
            *(unsigned short *)(node + 0x34) =
                *(unsigned short *)(node + 0x34) | 0x800;
            *(int *)(base + 0x12C0) = (int)node;
            *(int *)(base + 0x12E4) = 2;
        }
    }
    func_L00_002AA178(arg0);
    func_L00_002B0968(arg0);
}

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_002D5380);
