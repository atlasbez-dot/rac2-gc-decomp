#include "include_asm.h"

INCLUDE_ASM("asm/pal/levels", func_PAL_L11_0043C288);

INCLUDE_ASM("asm/pal/levels", func_PAL_L11_0043C500);

INCLUDE_ASM("asm/pal/levels", func_PAL_L11_0043CB48);

extern unsigned char D_L11_00438880[];
extern void func_802F8AD0(void *a0, void *a1);
extern void func_80338398(void *a0, void *a1, int a2, int a3, float f12);
extern void func_L11_004395C8(char *p);
extern void func_L11_00437EA8(char *p);
extern void func_L11_00437FD0(char *p);
extern void func_L11_00438460(char *p);
extern void func_L11_004386B8(char *p);

/* Runs the ten rotors' update, one frame each, and restarts the entry timer. */
void func_PAL_L11_0043D280(char *p)
{
    char *q = *(char **)(p + 0x68);
    int i;

    func_802F8AD0((void *)D_L11_00438880, p);

    for (i = 12; i >= 0; i--)
        ;

    if (*(unsigned char *)(p + 0x20) >= 2) {
        func_L11_004395C8(p);
        func_L11_00437EA8(p);
        func_L11_00437FD0(p);
        func_L11_00438460(p);
        func_L11_004386B8(p);
    }
    if (*(unsigned short *)(p + 0x96) <= 0xFFFE) {
        (*(unsigned short *)(p + 0x96))++;
    }
    func_80338398(p, q + 0x80, 1, 1, 2.5f);
}

