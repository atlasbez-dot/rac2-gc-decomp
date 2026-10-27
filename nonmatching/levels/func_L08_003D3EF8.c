/* Near miss (mid-15): -O2 -G8 -ffunction-sections (default for -g8), 652/664 bytes. First half is the func_L01_00397EB0 body; the second half (four tinted draws) keeps its three float constants in callee-saved registers and the w1 pointer in $s2/$s4 in retail, which this C does not reproduce (about 12 words). */
#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

extern float D_L08_001B0338 __attribute__((sda));
extern float D_L08_001B033C __attribute__((sda));
extern float D_L08_001B0340 __attribute__((sda));
extern float D_L08_001B0344 __attribute__((sda));
extern unsigned char D_L08_001B0348 __attribute__((sda));
extern int D_L08_001B034C __attribute__((sda));
extern int D_L08_001B0350 __attribute__((sda));
extern float D_L08_001B0354 __attribute__((sda));
extern float D_L08_001B0358 __attribute__((sda));
extern int D_L08_001B035C __attribute__((sda));
extern int D_L08_001B0360 __attribute__((sda));
extern int D_L08_001B0368 __attribute__((sda));
extern int D_L08_001B036C __attribute__((sda));
extern unsigned char D_L08_001B2508_[] __attribute__((sda));
extern char D_L08_001B9B00[];

extern void func_0029FCC0(void *, int, void *);
extern int func_002A77E0(int);
extern void func_002A7A00(void *, float, float);
extern void func_002C3150(void *, void *, int, unsigned char, unsigned char, int, float);
extern void func_002C2FD8(void *, int, int, int, int, int, int, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern float func_00283CE0(int);
extern float func_00282C48(float);
extern int func_00283D38(int, int, float);

void func_L08_003D3EF8(char *obj)
{
    TI128 m, v1, v2, w1, w2;
    float step;
    int i;
    int k;
    int b;
    int c;
    float f;
    int col;
    char *p;
    char *q;

    func_0029FCC0(obj, 0, &m);
    if (func_002A77E0(4) == 0) {
        i = 2;
        func_002A7A00(&v1, D_L08_001B0338 * 0.016666668f, D_L08_001B033C * 0.016666668f);
        b = D_L08_001B0348;
        func_002C3150(&m, &v1, D_L08_001B034C, b, func_002A77E0(255), 0, D_L08_001B0354);
        do {
            i--;
            func_002A7A00(&v2, D_L08_001B0340 * 0.016666668f, D_L08_001B0344 * 0.016666668f);
            func_00282CC0(&v1, &v1, &v2);
            b = D_L08_001B0348;
            func_002C3150(&m, &v1, D_L08_001B0350, b, func_002A77E0(255), 0, D_L08_001B0358);
        } while (i >= 0);
    }
    p = (char *)&w1;
    q = (char *)&w2;
    func_00282CF0(p, D_L08_001B9B00, &m);
    func_00282F20(p, p, -0.3f);
    func_00282F20(q, p, 0.1f);
    func_00282CC0(p, p, &m);
    k = 0;
    for (i = 0; k < 4; k++, i += 0x14) {
        f = func_00283CE0(0xFF - ((D_L08_001B2508_[0] + i) & 0xFF));
        col = func_00283D38(D_L08_001B035C, D_L08_001B0360, func_00282C48(0.5f - f * 0.003921569f));
        b = D_L08_001B2508_[0];
        if (k & 2)
            b = b * 2;
        if (k & 1)
            b = 0xFF - b;
        b &= 0xFF;
        f = func_00283CE0(k) + 3.0f;
        func_002C2FD8(p, col, b, D_L08_001B036C, D_L08_001B0368, 2, 0, f * (*(float *)(obj + 0x2C) / *(float *)(*(char **)(obj + 0x24) + 0x24)));
        func_00282CC0(p, p, q);
    }
}
