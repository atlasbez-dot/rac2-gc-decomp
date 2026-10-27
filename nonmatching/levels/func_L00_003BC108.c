/* Bounded manual reconstruction, 2026-10-25; not linked.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * 288/288 bytes; us: 0/27 placements; us2: 0/27 placements; pal: 0/27 placements.
 * The two complete endpoint copies use qcopy, replacing the historical invented volatile
 * destination. All three cubic components, early exits and the final zero remain. Operation shape
 * and size agree, but FP register allocation differs from the initial zero.
 * Reopen with actual floating live-range or source-expression evidence. Do not restore source
 * volatile merely to control scheduling.
 * Original complete variants and allocator diagnostics are preserved privately.
 * No candidate or linked-build credit is claimed.
 */
#include "common.h"

#ifndef RAC2_T_TI128_3BC108
#define RAC2_T_TI128_3BC108
typedef int TI128_3BC108 __attribute__((mode(TI)));
#endif

/* Blends the two points along the cubic that runs through the four given ones: the
   first two are copied whole when the parameter is 0 or 1, otherwise the curve is
   evaluated at the parameter. */
void func_L00_003BC108(float t, void *out, void *p1, void *p2, void *p3, void *p4)
{
    float *o = (float *)out;
    float *a = (float *)p1;
    float *b = (float *)p2;
    float *c = (float *)p3;
    float *d = (float *)p4;
    float zero = 0.0f;
    float t2;

    if (t == zero) {
        qcopy(out, p1);
        return;
    }
    if (t == 1.0f) {
        qcopy(out, p2);
        return;
    }

    t2 = t * t;
    o[0] = (((d[0] - b[0]) - (c[0] - a[0])) * (t2 * t)
           + ((c[0] - a[0]) - ((d[0] - b[0]) - (c[0] - a[0]))) * t2
           + (b[0] - c[0]) * t) + a[0];
    o[1] = (((d[1] - b[1]) - (c[1] - a[1])) * (t2 * t)
           + ((c[1] - a[1]) - ((d[1] - b[1]) - (c[1] - a[1]))) * t2
           + (b[1] - c[1]) * t) + a[1];
    o[2] = (((d[2] - b[2]) - (c[2] - a[2])) * (t2 * t)
           + ((c[2] - a[2]) - ((d[2] - b[2]) - (c[2] - a[2]))) * t2
           + (b[2] - c[2]) * t) + a[2];
    o[3] = zero;
}
