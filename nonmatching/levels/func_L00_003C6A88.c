/* func_L00_003C6A88: M3 2026-10-26: rewritten from retail under -O2 -G8 -g -frac2-qcopy -frac2-qcopy-barrier (sda floats, incomplete sda arrays for the absolute words, which the assembler turns to $gp in delay slots): the first 0x70 bytes are exact, 260/268. Missing: the two loop-preheader nops and the loop counter registers.
 */
#include "common.h"
typedef int Q128 __attribute__((mode(TI)));

extern int D_L00_001B2A00[] __attribute__((sda));
extern float D_L00_001AEFA4 __attribute__((sda));
extern float D_L00_001B2A10 __attribute__((sda));
extern float D_L00_001AFFF4 __attribute__((sda));
extern float D_L00_001AFFFC __attribute__((sda));
extern float D_L00_001B0000 __attribute__((sda));
extern int D_L00_001B2A14[] __attribute__((sda));
extern int D_L00_001B2ACC[] __attribute__((sda));
extern int D_L00_001B2AC0[];
extern Q128 D_L00_001B2A50[];
extern Q128 D_L00_002403C0[];
extern Q128 D_L00_002403B0[];
extern float func_00283CE0(int);
extern void func_00282D30(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);

void func_L00_003C6A88(char *owner)
{
    Q128 local;
    char *inner;
    float rate;
    Q128 *src;
    Q128 *dst;
    int i;

    inner = *(char **)(owner + 0x68);
    if (D_L00_001B2A00[0] == 0)
        return;
    D_L00_001B2A00[0] = 0;
    rate = D_L00_001AEFA4 / func_00283CE0(12);
    D_L00_001B2A10 = rate;
    func_00282D30(&local, owner + 0xC0, -rate);
    D_L00_002403C0[0] = *(Q128 *)inner;
    src = &D_L00_002403B0[1];
    dst = &D_L00_002403C0[1];
    for (i = 10; i >= 0; i--) {
        func_00282CC0(dst, src, &local);
        src++;
        dst++;
    }
    D_L00_001AFFF4 = 0.0f;
    D_L00_001AFFFC = 0.0f;
    D_L00_001B0000 = 0.0f;
    D_L00_001B2A14[0] = 0;
    D_L00_001B2ACC[0] = 0;
    for (i = 2; i >= 0; i--) {
        D_L00_001B2AC0[2 - i] = 0;
        qcopy(&D_L00_001B2A50[2 - i], &local);
    }
}
