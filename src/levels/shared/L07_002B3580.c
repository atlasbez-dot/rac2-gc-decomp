#include "include_asm.h"

extern char D_L07_001FDEC0[];
extern void func_338D68();

INCLUDE_ASM("asm/levels", func_L07_002B3580);

INCLUDE_ASM("asm/levels", func_L07_002B5738);

/* func_L07_00321D68 is in its qualified quadword-copy unit. */


int func_L07_00338D20(int a0)
{
    char *p;

    if (a0 == -1)
        return -1;
    p = *(char **)(D_L07_001FDEC0 + a0 * 4);
    if (p == 0)
        return -1;
    func_338D68(p);
    return 0;
}

INCLUDE_ASM("asm/levels", func_L07_0034AEC8);

INCLUDE_ASM("asm/levels", func_L07_003844C0);

INCLUDE_ASM("asm/levels", func_L07_003848D8);


extern unsigned short *D_L07_001FAD60[];

extern unsigned char *D_L07_001B22DC[] __attribute__((sda));

extern int D_L07_001B22F8[] __attribute__((sda));

/* Returns the first entity of the group's id list whose state byte is 1, or 0. */
unsigned char *func_L07_003F6B88(int group) {
    unsigned short *p;
    unsigned char *e;

    for (p = D_L07_001FAD60[group];
         (unsigned char)group != 0xFF && group <= D_L07_001B22F8[0] && p != 0 &&
         ((short)p[-1] >= 0 || p == D_L07_001FAD60[group]);
         p++) {
        e = D_L07_001B22DC[0] + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        if (e[0x20] == 1)
            return e;
    }
    return 0;
}

/* func_L07_003F6F00 is defined in L07_002B3580-g8.c (it reads five tuning words through $gp). */



INCLUDE_ASM("asm/levels", func_L07_00416510);
