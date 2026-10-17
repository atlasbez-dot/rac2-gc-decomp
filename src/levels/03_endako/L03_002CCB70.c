#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_002CCB70);

INCLUDE_ASM("asm/levels", func_L03_002D3498);

INCLUDE_ASM("asm/levels", func_L03_002FDE30);

extern u8 *D_L03_001B2918;

s32 func_L03_003112F8(void)
{
    u8 *p = D_L03_001B2918;
    u8 *q;
    s32 n = 0;

    if (p == 0)
        return 1;
    q = p;
    while (*(s16 *)q != 0) {
        if (*(s16 *)(q + 0x24) == 1) {
            if ((*(u16 *)(q + 0x10) & 2) == 0)
                n++;
        }
        q += 0x28;
    }
    return n;
}

INCLUDE_ASM("asm/levels", func_L03_00329ED0);

INCLUDE_ASM("asm/levels", func_L03_0032CFD8);

INCLUDE_ASM("asm/levels", func_L03_00383FE8);


INCLUDE_ASM("asm/levels", func_L03_003844D8);

INCLUDE_ASM("asm/levels", func_L03_0038AA20);

INCLUDE_ASM("asm/levels", func_L03_00393838);

INCLUDE_ASM("asm/levels", func_L03_00393C50);
