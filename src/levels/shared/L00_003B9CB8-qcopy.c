#include "include_asm.h"

/* The grouped quadword copy: the R5900 lq/sq pair with both addresses in registers. */
typedef int Rac2TI128 __attribute__((mode(TI)));

extern float func_00283CE0(int a);

extern void func_00282CC0(void *out, void *in1, void *in2);

extern void ref_L00_003BCE28_00(void *out, void *a, void *b, void *c, void *d, float f);

extern unsigned int func_002A7820(int a, int b);

extern void func_L00_003BCF88(void *a0, unsigned int a1, void *a2, int a3);

/* Walks eight steps of a state block. Each step adds the block's two constant vectors
   to its two moving ones, then the shared helper builds the step's own vector from the
   four of them, scaled by the step's share of the whole. The block's two counts choose
   the range the block is finally emitted with. */
void func_L00_003BCE28(char *a0, char *a1)
{
    Rac2TI128 pts[8];
    Rac2TI128 tmp[3];
    Rac2TI128 *t1 = &tmp[1];
    Rac2TI128 *t2 = &tmp[2];
    Rac2TI128 *p1 = (Rac2TI128 *)(a1 + 0x10);
    char *c0 = a1 + 0x20;
    char *c1 = a1 + 0x30;
    int i;
    float f;
    int v0;
    int v1;

    i = 0;
    do {
        f = func_00283CE0(i) / func_00283CE0(7);
        *t1 = *(Rac2TI128 *)a1;
        *t2 = *p1;
        func_00282CC0(t1, t1, c0);
        func_00282CC0(t2, t2, c1);
        ref_L00_003BCE28_00(&pts[i], c0, c1, t1, t2, f);
        i++;
    } while (i < 8);

    v0 = *(int *)(a1 + 0x9C) >> 1;
    v1 = *(int *)(a1 + 0x98);
    if (v1 >= v0)
        func_L00_003BCF88(a0, func_002A7820(0x40, 0x80), pts, 9);
    else
        func_L00_003BCF88(a0, func_002A7820(0, 0x40), pts, 9);
}
