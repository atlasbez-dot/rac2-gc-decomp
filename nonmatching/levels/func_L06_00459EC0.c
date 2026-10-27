/* 0 of 1 places match - last line: 06_notak: instruction at +0x34 differs
   Same size (524 bytes) and the whole body matches word for word except the entry block.
   Retail tests the pending-sweep flag with a branch into the body and a second branch to
   the shared reserved-distance store, whose first load fills that branch's delay slot:
       bnez $v0, body ; b store+4 ; lwc1 $f1,0x14($s1)
   This cc1 instead branches to the store from the flag test (beqz) and spends the extra
   pair on the loop's exit edge (b store+4 ; lwc1 $f1). The two edges are swapped, the total
   is the same.
   Tried: `if (flag != 0) { body } store;`, `if (flag == 0) { store } else { body }`,
   `if (flag == 0) { store; return; } body; store;`, and the body/store duplicated in both
   arms of an if/else (the compiler cross-jumps the two stores; the flag test still branches
   to the store). Each shape keeps the same 2-word difference.
   Not tried: a profile or source form that makes cc1 lay the shared store out as the join
   of both arms rather than the fall-through of the flag test.
   Calibrated literals: the turn limit is one ulp above 2*pi (0x40C90FDC, source 6.283186f,
   not 6.2831855f); the sine scale is 5.2f (0x40A66666); the direction scale constant is
   1.5f. func_002761F8 takes a fifth integer argument 0 and func_00277258 takes a trailing
   float argument 1.5f; both are passed in the delay slots. The two identical stores at
   the end are what the arms share; the loop's `continue` shape (add inside the if) is what
   reproduces retail's bnel/beql pair. */

#include "include_asm.h"

typedef unsigned char u8;

extern float func_00283180(float);
extern float func_00283198(float);
extern void func_00282CC0(char *, char *, char *);
extern int func_002A8AF0(void *, void *, int);
extern int func_002761F8(void *, void *, int, void *, int);
extern int func_00277258(void *, int, void *, float);
extern float func_00282C48(float);
extern float func_00283B98(float, float);
extern float func_00283248(float, float);

void func_L06_00459EC0(char *a0, char *a1)
{
    char *obj = a0;
    char *st = a1;
    float dir[3];
    char *p;
    float ang;
    float step;
    float total;

    if (*(int *)(st + 0x124) != 0) {
        dir[0] = func_00283180(*(float *)(obj + 0xF8)) * 5.2f;
        dir[1] = func_00283198(*(float *)(obj + 0xF8)) * 5.2f;
        dir[2] = 0.0f;
        func_00282CC0((char *)dir, (char *)dir, obj + 0x10);
        p = *(char **)(st + 0x118);
        if (func_002A8AF0(dir, p + 0x10, *(int *)p) != 0 &&
            func_002761F8(obj + 0x10, dir, 0x24, obj, 0) == 0 &&
            func_00277258(dir, 0x24, obj, 1.5f) == 0)
            return;
        step = func_00282C48(*(float *)(st + 0x130));
        ang = *(float *)(obj + 0xF8);
        total = 0.0f;
        do {
            ang = func_00283B98(ang, *(float *)(st + 0x130));
            dir[0] = func_00283180(ang) * 5.2f;
            dir[1] = func_00283198(ang) * 5.2f;
            dir[2] = 0.0f;
            func_00282CC0((char *)dir, (char *)dir, obj + 0x10);
            p = *(char **)(st + 0x118);
            if (func_002A8AF0(dir, p + 0x10, *(int *)p) == 0 ||
                func_002761F8(obj + 0x10, dir, 0x24, obj, 0) != 0 ||
                func_00277258(dir, 0x24, obj, 1.5f) != 0) {
                total += step;
                continue;
            }
            *(float *)(st + 0x12C) = ang;
            return;
        } while (total < 6.283186f);
        *(float *)(st + 0x12C) = func_00283248(*(float *)(st + 0xE0) - *(float *)(obj + 0x10),
                                             *(float *)(st + 0xE4) - *(float *)(obj + 0x14));
    } else {
        *(float *)(st + 0x12C) = func_00283248(*(float *)(st + 0xE0) - *(float *)(obj + 0x10),
                                             *(float *)(st + 0xE4) - *(float *)(obj + 0x14));
    }
}
