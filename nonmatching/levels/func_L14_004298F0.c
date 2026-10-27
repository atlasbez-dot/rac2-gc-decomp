#include "include_asm.h"

/* func_L14_004298F0 copies a 16-byte vector, which needs the grouped quadword
   copy: it is in this sibling file, and config/cflags.txt gives it the
   -frac2-qcopy flag. */

/* The 16-byte vector the object and the entity keep. */
typedef int TI128 __attribute__((mode(TI)));

extern void func_00282948(char *);
extern void func_00325DA0(char *, char *);
extern void func_00282CF0(void *, char *, char *);
extern float func_00283B98(float, float);
extern void func_00325C50(char *, char *, int, void *, float);
extern void func_002B0990(char *, char *, int, int, float);

/* Per-frame update of the entity the object at arg points to. */
void func_L14_004298F0(char *arg)
{
    char *o;
    char *src;
    char *dst;
    TI128 v;
    unsigned short c;
    unsigned char m;
    float f;

    o = *(char **)(arg + 0x68);
    func_00282948(o + 0x30C);
    func_00282948(o + 0x310);
    c = *(unsigned short *)(arg + 0x96);
    if (c <= 0xFFFE)
        *(unsigned short *)(arg + 0x96) = c + 1;
    func_00325DA0(arg, o + 0x308);
    src = arg + 0x10;
    dst = o + 0x2D0;
    func_00282CF0(&v, src, dst);
    *(TI128 *)dst = *(TI128 *)src;
    m = *(unsigned char *)(arg + 0x95);
    if (m != 1) {
        f = func_00283B98(*(float *)(o + 0x2FC), 0.011635531f);
        *(float *)(o + 0x2FC) = f;
        func_00325C50(arg, o + 0x300, 0, &v, f);
    } else {
        f = func_00283B98(*(float *)(o + 0x2FC), 0.20943954586982727f);
        *(float *)(o + 0x2FC) = f;
        func_00325C50(arg, o + 0x300, 1, &v, f);
    }
    func_002B0990(arg, o + 0x230, 7, 1, 2.0f);
}
