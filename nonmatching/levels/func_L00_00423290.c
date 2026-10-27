/* 26 October 2026 (M24): -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -mno-split-addresses, 356/360 bytes: retail keeps a copy of the object pointer (daddu $s2, $s1) and reuses its register for +0x60; the +0xB0/+0xF0 pointers are formed after the first calls. */
/* func_L00_00423290 - NOT MATCHED, best attempt - 360 bytes expected, 27 places.
 * last check.py line: "func_L00_00423290: 0 of 27 places match (src/levels/shared/L00_004224D0.c)"
 * with "00_aranos_tutorial: 356 bytes, expected 360" - the body is 356 bytes of the
 * retail's 360, in a unit built with the opt-in quadword-copy profile
 * (-frac2-qcopy -frac2-qcopy-barrier, config/cflags.txt).
 *
 * What the profile fixed: the five 16-byte copies.  Without it this cc1 folds the
 * constant offset into the `sq` and the body is 340 bytes; with it the grouped copy
 * through register addresses gives retail's
 *
 *   addiu $v1, $s2, 0xC0 ; lq $v0, 0($s1) ; sq $v0, 0($v1)
 *
 * exactly, and the barrier keeps the instructions around the copy on their own side
 * of it.  All five copies and the twelve calls now sit where the retail has them.
 *
 * What is left is one register swap and the four bytes that follow from it: the
 * retail keeps the object in $s2 and its +0x60 in $s1, and copies the object with
 * `daddu $s2, $s1, $zero` before it reuses $s1 for the +0x60; this cc1 keeps the
 * object in $s1 and puts the +0x60 in $s2, with no copy.  The retail's copy is
 * also what makes the frame 0x60 and the saved registers seven; ours has the same
 * seven.  Measured: the copy of the object in the source (an explicit `base = obj`)
 * is folded back by the front end, the order of the five derived pointers
 * (obj+0x60, obj+0xB0, obj+0xF0, obj+0x160) does not change the allocation, and
 * neither does the order of the two copies.  What would unblock it: the source
 * expression tree that keeps the object in two registers at once.
 *
 * The first copy's destination is the object's +0x60 (the retail's `sq $v0, 0($s1)`
 * with $s1 = obj+0x60), not the +0x160; the deposit below says so. */
typedef int HeroQ __attribute__((mode(TI)));
typedef union { unsigned char b[0x2600]; signed char c[0x2600]; short h[0x1300]; unsigned short uh[0x1300]; int i[0x980]; unsigned int u[0x980]; float f[0x980]; char *ptr[0x980]; HeroQ q[0x260]; } Hero;
extern unsigned char D_00189E20[];
#define H ((Hero *)D_00189E20)


#include "include_asm.h"

#ifndef RAC2_T_V4_F0FBA48D3
#define RAC2_T_V4_F0FBA48D3
typedef int V4_F0fba48d3 __attribute__((mode(TI)));
#endif

extern void func_00282CF0_2(void *b, void *c, void *d);

extern void func_00282CC0(void *c, void *c2, void *s);

extern void func_00282D30(void *dst, void *src, float k);

extern float func_00282DB0_1(char *local, char *p);

extern void func_00282C88(void *a);





void func_L00_00423290(char *a0)
{
    char *obj;
    char *v60;
    char *vB0;
    char *vF0;
    char *v160;
    char *hero;
    char *pos;
    V4_F0fba48d3 *dst;
    char buf0[16];
    char buf1[16];

    if (*(short *)(a0 + 0x86) != 0)
        return;

    hero = (&H->c[704]);
    obj = *(char **)(a0 + 0x70);
    v160 = obj + 0x160;
    v60 = obj + 0x60;

    func_00282D30(buf0, hero, -1.0f);
    /* The hero's position, 0x240 below the facing direction the call above uses. */
    hero = hero - 0x240;
    *(V4_F0fba48d3 *)v60 = *(V4_F0fba48d3 *)hero;
    dst = (V4_F0fba48d3 *)(obj + 0xC0);
    *dst = *(V4_F0fba48d3 *)v60;
    vB0 = obj + 0xB0;
    vF0 = obj + 0xF0;
    func_00282D30(obj + 0x70, buf0, func_00282DB0_1(v60, buf0));
    func_00282C88(obj + 0xD0);
    func_00282C88(obj + 0xE0);
    func_00282C88(obj + 0x100);
    func_00282D30(buf1, buf0, *(float *)(v160 + 0x30));
    func_00282CC0(vB0, buf1, v60);
    func_00282D30(buf1, buf0, *(float *)(v60 + 0xB0));
    func_00282CC0(vF0, buf1, v60);
    dst = (V4_F0fba48d3 *)(obj + 0xA0);
    *dst = *(V4_F0fba48d3 *)vF0;
    func_00282CF0_2(v160, a0 + 0x30, vB0);
    dst = (V4_F0fba48d3 *)(obj + 0x170);
    *dst = *(V4_F0fba48d3 *)v160;
    *(V4_F0fba48d3 *)obj = *(V4_F0fba48d3 *)(a0 + 0x30);
    func_00282CC0(obj + 0x210, vB0, v160);
    *(int *)(obj + 0x240) = 0;
}
