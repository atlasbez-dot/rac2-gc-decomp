/* 0 of 6 places match - last line: 01_oozla: 500 bytes, expected 504.
   124 of 126 instructions, and the whole control flow, the two float constants
   (0x3F490FDC, 0x40278D37) and the qcopy 16-byte stack copy agree. The only
   difference is how the hero-position global is addressed in the last block:
   retail materialises `D_00189E20 + 0x80` into a saved register ($s0) from a
   temporary `lui $v0,0x19` and then re-derives the block base as
   `addiu $v0,$s0,-0x80` for the two loads (`lwc1 0x80($v0)`, `0x84($v0)`);
   here the compiler keeps the block base in $s0 across the call and folds the
   loads as `0x80($s0)` / `0x4($s3)`, which is one instruction shorter.
   Tried: the argument spelled `D_00189EA0`, `D_00189E20 + 0x80` (identical
   bytes), a named pointer local, hoisting that pointer above the branch,
   `-mno-split-addresses` (collapses the loads to 0/4 off the pointer) and the
   SDK profile (same 500 bytes). Needs a source shape that makes the compiler
   give up the block base and derive it from the argument pointer instead.
   Profile: -O2 -G0 -ffunction-sections -frac2-qcopy (needs a file of its own;
   `-frac2-qcopy-barrier` changed nothing here). */

#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

extern char D_00189E20[];

extern float func_3105E0(char *a0, float f12, float f13);
extern int func_310528(int a0, int a1);
extern float func_313EB0(char *a0, float f12, float f13, int a1);
extern int func_2E3110(void *a0);
extern float func_2E3A48(float f12);
extern float func_2E3A60(float f12);
extern int func_321178(char *a0, float *a1);
extern float func_311A00(char *a0, float f12, int a1);
extern float func_2E3650(char *a0, char *a1);
extern float func_2E3B10(float f12, float f13);
extern float func_313800(float f12, float f13, float f14);

/* Advances a steer-toward state: the init branch seeds the turn rate and a random
   delay, the live branch re-reads the smoothed yaw and drops the state once the
   probe reports, then the body copies the anchor position, offsets it by two
   probe lookups, and either snaps the yaw at the target (ray hit or the far
   cone) or interpolates it toward the hero scaled by the distance ratio. */
void func_L01_00318638(char *a0, char *a1, char *a2) {
    char *s3;
    char *hp;
    float v[4];
    float f20;
    float t;
    float w;
    float keep;
    float lim;
    int r;

    if (*(short *)(a1 + 0x28) == 0) {
        t = func_3105E0(a0, 0.78539824f, 2.617994f);
        *(float *)(a1 + 0x24) = *(float *)(a1 + 0x24) + t;
        *(short *)(a1 + 0x2A) = func_310528(*(short *)(a1 + 0x2C), *(short *)(a1 + 0x2E));
        *(short *)(a1 + 0x28) = 1;
    } else {
        func_313EB0(a0 + 0xF8, *(float *)(a1 + 0x24), *(float *)(a1 + 0x18), 0);
        if (func_2E3110(a1 + 0x2A) != 0)
            *(short *)(a1 + 0x28) = 0;
    }
    s3 = a0 + 0x10;
    *(TI128 *)v = *(TI128 *)s3;
    keep = *(float *)(a2 + 0x28);
    *(float *)(a2 + 0x28) = *(float *)(a1 + 0x14);
    t = func_2E3A48(*(float *)(a0 + 0xF8));
    v[0] = v[0] + (t + t);
    w = func_2E3A60(*(float *)(a0 + 0xF8));
    *(float *)(a2 + 0x28) = keep;
    v[1] = v[1] + (w + w);
    r = func_321178(a0, v);
    *(float *)(a0 + 0x18) = func_311A00(s3, 0.5f, 0);
    f20 = func_2E3650(s3, a1);
    if (r != 0 || *(float *)(a1 + 0x1C) < f20) {
        *(float *)(a1 + 0x24) =
            func_2E3B10(*(float *)(a1 + 0x0) - *(float *)(a0 + 0x10),
                        *(float *)(a1 + 0x4) - *(float *)(a0 + 0x14));
        *(short *)(a1 + 0x2A) = func_310528(0x1E, 0x5A);
        *(short *)(a1 + 0x28) = 1;
    } else {
        hp = D_00189E20 + 0x80;
        f20 = func_2E3650(s3, hp);
        lim = *(float *)(a1 + 0x20);
        if (f20 < lim) {
            f20 = f20 / lim;
            *(float *)(a1 + 0x24) =
                func_313800(*(float *)(a1 + 0x24),
                            func_2E3B10(*(float *)(a0 + 0x10) - *(float *)(D_00189E20 + 0x80),
                                        *(float *)(a0 + 0x14) - *(float *)(D_00189E20 + 0x84)),
                            f20);
        }
    }
}
