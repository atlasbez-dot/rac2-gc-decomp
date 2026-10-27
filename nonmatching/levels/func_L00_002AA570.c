/* Retained complete C repair, 2026-10-25; not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections.
 * Private placement checks: us: 0/22, us2: 0/22, pal: absent.
 * Both vector arguments occupy 16 bytes and have 16-byte alignment. Only XYZ
 * are initialized by this caller; the original fourth words remain unqualified
 * and are not given invented zeroes. The emitter returns pointer/null, ignored
 * here. Legacy RNG names resolve to the exact catalogue callees. The incoming
 * word is preserved when passed to the integer RNG; native pointer/integer
 * interpretation remains unqualified.
 * Current code is 472/480 bytes, with frame 0x70 versus 0x80. The global
 * base/high-half lifetime still differs. Historical screening predates the
 * extent and return repairs.
 */

#include "common.h"

extern char D_00189E20_20[];
extern float func_002A7878(float, float);
extern int func_002A77E0(int);
extern float func_00283B98(float, float);
extern float func_00283BE0(float, float);
extern float func_00283180(float);
extern float func_00283198(float);
extern void *func_L00_00338AE0(float *, float *, float *, float, float);

void func_L00_002AA570(char *self, int arg1)
{
    float v[4] __attribute__((aligned(16)));
    float w[4] __attribute__((aligned(16)));
    float f;
    float r;
    int n;
    int i;
    char *p;

    p = D_00189E20_20;
    n = *(unsigned short *)(p + 0xA48) + 1;
    *(unsigned short *)(p + 0xA48) = n;
    if (arg1 < (short)n) {
        for (i = 0; i < 2; i++) {
            if (i == 0)
                f = func_00283B98(*(float *)(p + 0x98), 0.785398006f);
            else
                f = func_00283BE0(*(float *)(p + 0x98), 0.785398006f);
            v[0] = func_00283180(f) * 0.0100000007f;
            v[1] = func_00283198(f) * 0.0100000007f;
            w[0] = *(float *)(p + 0x80) + v[0] * 18.0f;
            w[1] = *(float *)(p + 0x84) + v[1] * 18.0f;
            w[2] = *(float *)(p + 0x330);
            v[2] = 0.0f;
            v[0] = v[0] - func_00283180(*(float *)(p + 0x98)) * 0.0250000022f;
            v[1] = v[1] - func_00283198(*(float *)(p + 0x98)) * 0.0250000022f;
            r = func_002A7878(0.4f, 0.5f);
            func_L00_00338AE0(w, v, (float *)(p + 0x330), r,
                              i == 0 ? 2.0f : -2.0f);
            if (self == 0)
                *(unsigned short *)(p + 0xA48) = 0;
            else
                *(unsigned short *)(p + 0xA48) = func_002A77E0((int)self);
        }
    }
}
