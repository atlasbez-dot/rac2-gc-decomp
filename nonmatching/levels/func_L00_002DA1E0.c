/* Near miss (mid-15): 412/420 bytes, flags -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier. Structure equal; retail keeps the object base in $s1 across the calls and hoists a copy of it ($s5) plus the constants $s4/$s6/$s7 into the preheader, which this C does not reproduce. */
#include "include_asm.h"

/* The grouped quadword copy: the R5900 lq/sq pair with both addresses in registers. */
typedef int Rac2TI128 __attribute__((mode(TI)));

extern char D_001B8C80[];
extern char D_001BF230[];
extern char D_001B8DC0[];
extern char D_00189E20[];
extern int D_001B1850 __attribute__((sda));

extern void func_00282CF0(void *out, void *a, void *b);
extern void func_00282CC0(void *out, void *a, void *b);
extern float func_00282DF0(void *v);
extern void func_00282D90(void *out, void *a, float f);
extern int func_00283CF0(float f);
extern float func_00283CE0(int v);
extern int func_00277258(void *pos, int a, void *b, float step);

void func_L00_002DA1E0(char *pos, float step)
{
    float sp0[4];
    float sp10[4];
    char *g = D_001B8C80;
    char *obj;
    float *src;
    int n;
    int i;
    int j;

    obj = *(char **)(g + 0x190);
    src = (float *)(obj + 0x64);
    sp10[0] = src[0];
    sp10[1] = src[1];
    sp10[2] = src[2];
    sp10[3] = 0.0f;
    if (*(short *)(obj + 0x8A) != 0) {
        *(Rac2TI128 *)(g + 0x140) = *(Rac2TI128 *)pos;
        *(short *)(obj + 0x8A) = 0;
        return;
    }
    func_00282CF0(sp0, pos, sp10);
    n = func_00283CF0(func_00282DF0(sp0) / (step * 0.9f)) + 1;
    func_00282D90(sp0, sp0, func_00283CE0(n));
    *(Rac2TI128 *)pos = *(Rac2TI128 *)sp10;
    for (j = 0; j < n; j++) {
        func_00282CC0(pos, pos, sp0);
        i = 0;
        while (i < 6 && func_00277258(pos, D_001B1850, *(void **)(D_00189E20 + 0x2290), step) != 0) {
            *(Rac2TI128 *)pos = *(Rac2TI128 *)D_001BF230;
            obj = *(char **)(g + 0x190);
            if (*(unsigned char *)(obj + 0x89) == 0)
                *(unsigned char *)(obj + 0x89) = 1;
            i++;
        }
    }
    *(Rac2TI128 *)D_001B8DC0 = *(Rac2TI128 *)pos;
}
