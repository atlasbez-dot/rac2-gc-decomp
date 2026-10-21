/* Near miss: the body is two instructions away from retail.
 *
 * func_L06_0041FC58 (level 06, 264 bytes).  The candidate needs retail's grouped
 * quadword copy, so it was written for a unit compiled with
 *
 *     src/levels/06_notak/L06_0041FC58.c	-O2 -G0 -ffunction-sections -frac2-qcopy
 *
 * (the cflags.txt line was taken back out when the draft moved here).  With that profile
 * the copy is
 *
 *     addiu $v1,$s0,0x5B0 ; addiu $a0,$s0,0x460 ; lq $v0,0($a0) ; sq $v0,0($v1)
 *
 * and the default profile folds the offsets into the lq/sq instead
 * (`lq $v1,0x460($s1) ; sq $v1,0x5B0($s1)`), which is the wall this project already
 * records for TI copies.
 *
 * With the qcopy profile every instruction matches except the two that load the 1.0f
 * constant in the first branch: retail materialises it after the copy,
 *
 *     addiu $v1,$s0,0x5B0 ; addiu $a0,$s0,0x460 ; lq $v0,0($a0) ; sq $v0,0($v1)
 *     lui $at,0x3F80 ; mtc1 $at,$f0 ; addiu $v0,$zero,0x1 ; b ... ; swc1 $f0,0x5BC($s0)
 *
 * while this candidate emits the constant load first, because cc1 materialises the
 * float constant of the store in the tree phase and the grouped copy only in the later
 * phase.  The second branch (the same constant after a conditional branch) matches.
 */

#include "include_asm.h"

/* A quadword, copied as retail's lq/sq pair. */
typedef int TI128 __attribute__((mode(TI)));

/* The level's own table of polygons, at 0x1FE500. */
extern char *D_L06_001FE500[];

extern int func_002A8AF0(float *, float *, int);
extern void func_L02_0031E9E8(void *, float);
extern void func_00282CC0(void *, void *, void *);

/* Moves the actor's position to the target's, when the target is inside the actor's
   polygon; the level's own table holds the polygons. */
int func_L06_0041FC58(char *a0, char *a1)
{
    char *src = a0 + 0x10;
    char *st = a1;
    int ret = 0;

    if (func_002A8AF0((float *)src,
                      (float *)((char *)D_L06_001FE500[*(int *)(st + 0x230)] + 0x10),
                      *(int *)D_L06_001FE500[*(int *)(st + 0x230)]) == 0) {
        *(TI128 *)(st + 0x5B0) = *(TI128 *)(st + 0x460);
        *(float *)(st + 0x5BC) = 1.0f;
        return 1;
    }
    {
        char *v = st + 0x5B0;

        func_L02_0031E9E8(v, 7.0f);
        func_00282CC0(v, v, src);
        *(int *)(st + 0x5BC) = 0;
        if (func_002A8AF0((float *)v,
                          (float *)((char *)D_L06_001FE500[*(int *)(st + 0x230)] + 0x10),
                          *(int *)D_L06_001FE500[*(int *)(st + 0x230)]) != 0) {
            *(float *)(st + 0x5BC) = 1.0f;
            ret = 1;
        } else {
            *(TI128 *)v = *(TI128 *)src;
        }
    }
    return ret;
}
