/* 2026-10-23 bounded readable-C attempt.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * US: 536 versus 540; prologue/loop-counter scheduling and mixed GP/absolute data accesses differ.
 * All carrying placements checked in us, us2 and pal; no candidate.
 * Tried scalar/TI versus union vectors, pointer grouping, expression/control flow
 * spelling, and applicable qualified copy profiles. Reopen with a demonstrated
 * scheduling or symbol declaration remedy; do not infer handwritten assembly.
 */

#include "include_asm.h"
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
    float brightness;
    int r, g, b, first, second;
    int *rgb = &D_L02_001A8D68;
    if (colour) rgb = colour;
    if (count > 0) do {
        brightness = func_002A7878(0.7f, 1.3f);
        r = func_00283CF0((float)rgb[0] * brightness);
        g = func_00283CF0((float)rgb[1] * brightness);
        b = func_00283CF0((float)rgb[2] * brightness);
        func_00282D08(&direction, from, to, func_002A7878(0.0f, 1.0f));
        position.q = direction.q;
        position.f[3] = func_002A7878(D_L02_001A8D78, D_L02_001A8D7C);
        --count;
        func_00282C88(&velocity);
        velocity.f[2] = -gravity * (float)(r + g + b);
        func_00282CC0(&velocity, &velocity, &direction);
        velocity.f[3] = position.f[3];
        first = func_00283D38(D_L02_001A8D58, D_L02_001A8D5C, func_002A7878(0.0f, 1.0f));
        second = func_00283D38(D_L02_001A8D60, D_L02_001A8D64, func_002A7878(0.0f, 1.0f));
        func_002BAA28(owner, &position, &velocity, first, second, r, g, b, D_L02_001A8D50);
    } while (count != 0);
}
