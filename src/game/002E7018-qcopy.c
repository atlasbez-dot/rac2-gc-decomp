#include "include_asm.h"

/* The ring's quads are copied with the grouped `lq`/`sq` profile, so this
 * function needs its own unit. */

typedef int TI128 __attribute__((mode(TI)));

extern int D_00152C00[];
extern float func_00283CE0(int);
extern float func_002A7940(void);
extern void func_002ACB48(float *, float);
extern void func_00281EB8(void *, unsigned int, unsigned int, int, float, float, float);
extern void func_00282CC0(void *, void *, void *);

/* Draws `count` copies of one quad along the segment from `from` to `to`,
 * each jittered by `radius` and turned by the engine's matrix. The mode flag
 * is the short at D_00152C20, 0x20 into the table at D_00152C00. */
void func_002E7570(void *src, void *matrix, int count, unsigned int colour,
                   float from, float to, float radius)
{
    TI128 quad[2];
    float step;
    int i;

    quad[0] = *(TI128 *)src;
    step = 1.0f / func_00283CE0(count);
    for (i = 0; i < count; i++) {
        short *table = (short *)D_00152C00;
        float f = func_00283CE0(i) * step;
        float t = from + (to - from) * f;
        float angle = func_002A7940();

        quad[1] = quad[0];
        func_002ACB48((float *)&quad[1], radius);
        func_00281EB8((char *)&quad[1], table[0x10] == 2 ? 5 : 0x2E, colour, 1,
                      t, 0.0f, angle);
        func_00282CC0((char *)&quad[0], (char *)&quad[0], matrix);
    }
}
