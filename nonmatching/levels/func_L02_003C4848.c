/* func_L02_003C4848 - 344 bytes, 8 place(s), level 02_maktar_nebula (also 03_endako,
   04_barlow, 09_dobbo, 12_todano, 17_smolg, 20_yeedil, 30_insomniac_museum),
   retail at 0x003c4848. Not matched in wave 14: 328 bytes against the retail's 344.
   The first of the three loops matches the retail instruction for instruction
   (the guard, the reload of the array element, the flag word, the loop's `slt`
   and both delay slots). What is left is in the second and third loops: this cc1
   puts the array pointer in $a1 and the counter in $a2 where the retail uses $a2
   and $t0, it keeps the sub-block pointer in $v0 where the retail uses $a0, it
   increments the counter early instead of in the branch's delay slot, and it
   folds the two quadword copy addresses into the `lq`/`sq` offsets where the
   retail materialises them (`lw $a1,0x18($a0) ; addiu $a1,$a1,0x10 ; lq $v0,0($a1)`).
   The float constants (0x3C888889 and 0x3D088889, one ulp above 1/60 and 1/30)
   and the `mode(TI)` copy pattern are the retail's. What would unblock it: the
   source expression tree of the second and third loop, so this cc1 picks the same
   registers and keeps the quadword addresses in registers. */

#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

void func_L02_003C4848(char *a0)
{
    char *a3 = *(char **)(a0 + 0x68);
    char *s1;
    char *s2;
    char *s3;
    char *r;
    int i1, i2, i3;

    *(int *)(a3 + 0x130) = 0x3C;
    for (i1 = 0; i1 < *(int *)(a3 + 0x118); i1++) {
        char **arr = (char **)(a3 + 0xC0);
        s1 = *(char **)(*(char **)(arr + i1) + 0x68);
        *(int *)(s1 + 0x14) = *(int *)(s1 + 0x18);
        *(int *)(s1 + 0x4) = 0;
        *(int *)(s1 + 0x8) = 0;
        r = *(char **)(s1 + 0x1C);
        if (r != 0)
            *(unsigned short *)(r + 0x34) |= 0x41;
        *(unsigned short *)(*(char **)(arr + i1) + 0x34) &= 0xFFBE;
    }
    for (i2 = 0; i2 < *(int *)(a3 + 0x110); i2++) {
        char **arr = (char **)(a3 + 0x20);
        s2 = *(char **)(*(char **)(arr + i2) + 0x68);
        *(int *)(s2 + 0x14) = 0;
        *(int *)(a3 + 0x11C) = 0;
        *(float *)(s2 + 0x10) = (float)*(int *)(a3 + 0x8) * 0.016666667f;
        *(float *)(s2 + 0xC) = -1.0f;
        *(TI128 *)(*(char **)(arr + i2) + 0x10) = *(TI128 *)(*(char **)(s2 + 0x18) + 0x10);
    }
    for (i3 = 0; i3 < *(int *)(a3 + 0x114); i3++) {
        char **arr = (char **)(a3 + 0x70);
        s3 = *(char **)(*(char **)(arr + i3) + 0x68);
        *(int *)(s3 + 0x8) = 0;
        *(float *)(s3 + 0x4) = 0.033333335f;
        *(float *)(s3 + 0xC) = -1.0f;
        *(TI128 *)(*(char **)(arr + i3) + 0x10) = *(TI128 *)(*(char **)(s3 + 0x10) + 0x10);
    }
}
