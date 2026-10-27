/* M21 2026-10-26: 536 of 540 bytes with -O2 -G8 -ffunction-sections -mno-split-addresses
   (us level 02); same result with -frac2-qcopy -frac2-qcopy-barrier. Two spots off: the
   loop's down-counter decrement lands in the first jal's slot (retail: a nop there, and the
   decrement in the slot of the func_002A7878(D_L02_001A8D78, D_L02_001A8D7C) call, after
   the copy), which also moves the $gp load of D_L02_001A8D78. What closed the rest: the
   counting-up for loop (loop.c's down-counter is copied from $a3 after the blez, as in
   retail), -mno-split-addresses for retail's macro loads (`lui $at; lwc1`), the qcopy helper,
   and func_002A7878 results held in a local before the func_00283D38 calls. Tried: do/while
   with --count anywhere, `while (--count)`, a separate counter. Permuter queued. */

#include "common.h"
typedef int TI128 __attribute__((mode(TI)));
typedef union { TI128 q; float f[4]; } Vec4;
extern int D_L02_001A8D68 __attribute__((sda));
extern float D_L02_001A8D78 __attribute__((sda));
extern int D_L02_001A8D58 __attribute__((sda));
extern int D_L02_001A8D50 __attribute__((sda));
extern float D_L02_001A8D7C __attribute__((nosda));
extern int D_L02_001A8D5C __attribute__((nosda));
extern int D_L02_001A8D60 __attribute__((nosda));
extern int D_L02_001A8D64 __attribute__((nosda));
extern float func_002A7878(float, float);
extern int func_00283CF0(float);
extern void func_00282D08(void *, void *, void *, float);
extern void func_00282C88(void *);
extern void func_00282CC0(void *, void *, void *);
extern int func_00283D38(int, int, float);
extern void func_002BAA28(void *, void *, void *, int, int, int, int, int, int);

void func_L02_002EFB60(void *owner, void *from, void *to, int count, int *colour, float speed) {
    Vec4 direction;
    Vec4 position;
    Vec4 velocity;
    float gravity = speed * 0.00027777778f;
    float brightness, t;
    int r, g, b, first, second, i;
    int *rgb = &D_L02_001A8D68;
    if (colour) rgb = colour;
    for (i = 0; i < count; i++) {
        brightness = func_002A7878(0.7f, 1.3f);
        r = func_00283CF0((float)rgb[0] * brightness);
        g = func_00283CF0((float)rgb[1] * brightness);
        b = func_00283CF0((float)rgb[2] * brightness);
        func_00282D08(&direction, from, to, func_002A7878(0.0f, 1.0f));
        qcopy(&position, &direction);
        position.f[3] = func_002A7878(D_L02_001A8D78, D_L02_001A8D7C);
        func_00282C88(&velocity);
        velocity.f[2] = -gravity * (float)(r + g + b);
        func_00282CC0(&velocity, &velocity, &direction);
        velocity.f[3] = position.f[3];
        t = func_002A7878(0.0f, 1.0f);
        first = func_00283D38(D_L02_001A8D58, D_L02_001A8D5C, t);
        t = func_002A7878(0.0f, 1.0f);
        second = func_00283D38(D_L02_001A8D60, D_L02_001A8D64, t);
        func_002BAA28(owner, &position, &velocity, first, second, r, g, b, D_L02_001A8D50);
    }
}
