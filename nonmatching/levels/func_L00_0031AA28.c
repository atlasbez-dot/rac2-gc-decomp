/*
 * Retained manual C reconstruction; not linked or counted.
 * Profile: -O2 -G0 -ffunction-sections
 * Retail: 288 bytes; compiled: 288 bytes.
 * Final coverage: us: 0/27; us2: 0/27; pal: 0/27.
 * Residual: 288/288 bytes; the copies and control flow are retained using approved qcopy
 * instead of the old invented volatile stores. Five floating temporaries retain a
 * different allocation, beginning at+0x40. All four source vectors have explicit field
 * views.
 * Reopen: A specific allocator/lifetime witness for the control-point components and t
 * squared/cubed. Full-vector source views tie. Existing recorded arithmetic/prototype
 * permutations are not a reason for another blind trial.
 */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));
typedef union { TI128 q; float f[4]; } Vector;

typedef int V4TI __attribute__((mode(TI)));

typedef struct {
    float x, y, z, w;
} V4;

/* cubic curve through four control vectors: at a phase of zero the first is copied and
   at one the second, in between the three first components follow the cubic built from
   the four vectors and the fourth component is cleared */
void func_L00_0031AA28(V4 *out, V4 *p0, V4 *p1, V4 *p2, V4 *p3, float t)
{
    float t2;
    float t3;
    float c;

    if (t == 0.0f) {
        qcopy(out, p0);
        return;
    }
    if (t == 1.0f) {
        qcopy(out, p1);
        return;
    }
    t2 = t * t;
    t3 = t2 * t;
    c = (p3->x - p1->x) - (p2->x - p0->x);
    out->x = c * t3 + ((p2->x - p0->x) - c) * t2 + (p1->x - p2->x) * t + p0->x;
    c = (p3->y - p1->y) - (p2->y - p0->y);
    out->y = c * t3 + ((p2->y - p0->y) - c) * t2 + (p1->y - p2->y) * t + p0->y;
    c = (p3->z - p1->z) - (p2->z - p0->z);
    out->z = c * t3 + ((p2->z - p0->z) - c) * t2 + (p1->z - p2->z) * t + p0->z;
    out->w = 0.0f;
}
