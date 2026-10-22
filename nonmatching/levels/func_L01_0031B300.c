/* Near miss: 268 of the retail's 272 bytes.
 *
 * func_L01_0031B300 (272 bytes, level 01 at 0x0031B300; also 02:0032A458,
 * 07:0031C008, 12:00328E68, 20:0033A650).
 *
 * tools/check.py func_L01_0031B300 --diff (with -frac2-qcopy on the unit):
 *   01_oozla: 268 bytes, expected 272
 *
 * The retail's 16-byte copy (lq/sq at 0x0031B37C) needs the grouped R5900
 * quadword copy, so the unit has to be compiled with -frac2-qcopy.
 *
 * What is left: the retail branches on equality where this draft branches on
 * inequality (beq against 0x881 and beqz against zero, both out of line), the
 * retail's "p == 0" test is a branch-likely, and the retail keeps the object
 * pointer in $s2 and the global in $s3 where this draft swaps them.
 */

#include "include_asm.h"

/* The game's 16-byte copy type: a whole vector or matrix moved in one quadword. */
typedef int TI128 __attribute__((mode(TI)));

extern char D_L01_001B5900[];

extern int func_002D3C80(char *a0, char *a1, int a2, char *a3, char *a4);

extern void func_002E3738(float *a0, float *a1, float f12);

extern void func_002E34A0(void *a0, void *a1, void *a2);

extern float func_002E3560(float *a0, float *a1);

extern float func_002E33E0(float f12);

extern void func_002E3470(void *a0, void *a1, void *a2);

int func_L01_0031B300(char *a0, int a1, char *a2, char *a3) {
    float v[4];
    float w[4];
    float f20;
    float f2;
    char *g;
    char *h;
    int *p;
    int v1;

    if (func_002D3C80(a2, a3, 0x10, a0, 0) == 0)
        goto fail;
    g = D_L01_001B5900;
    p = *(int *)(g + 0x18);
    if (p == 0)
        goto skip;
    v1 = *(short *)((char *)p + 0xAA);
    if (v1 == 0x881)
        goto fail;
    if (v1 == 0)
        goto fail881;
    f20 = *(float *)(a0 + 0x18);
skip:
    h = g + 0x40;
    *(TI128 *)w = *(TI128 *)h;
    func_002E3738(w, w, 1.0f);
    func_002E34A0(v, a3, g + 0x20);
    f2 = func_002E33E0(func_002E3560(v, w));
    func_002E3738(w, (float *)h, f2);
    func_002E3470(a0 + 0x10, a0 + 0x10, w);
    *(float *)(a0 + 0x18) = f20;
    return 1;
fail:
    return 0;
fail881:
    return 0x881;
}
