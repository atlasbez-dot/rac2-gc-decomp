/*
 * Retained manual C reconstruction; not linked or counted.
 * Profile: -O2 -G0 -ffunction-sections -frac2-zero-ti-por
 * Retail: 236 bytes; compiled: 248 bytes.
 * Final coverage: us: 0/1; us2: 0/1; pal: 0/1.
 * Residual: 248/236 bytes with a 0x30 rather than 0x20 frame and three saved GPRs rather
 * than one. The por-based full-vector clear is recovered by the existing por profile,
 * but array/count address lifetimes and clear/save scheduling still differ.
 * Reopen: A real source lifetime witness for the two fixed record arrays and the
 * repeatedly loaded count pointer. Separate copy phases tied; disabling strength
 * reduction or pre-reload scheduling retained 248 bytes. Do not add fake storage or
 * barriers.
 */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));
typedef union { TI128 q; float f[4]; } Vector;

typedef struct { int x, y; float z; } Record;
extern Record *D_L14_001B23D0;
extern char *D_L14_001B2B20;
extern char D_L14_001B2B50[];
extern float D_L14_001B9730[];
extern Record D_L14_00284690[];
extern Record D_L14_00284708[];
extern float func_00282DB0(void *, void *);
extern void func_00283388(void *);
extern void func_002E3478(int);
extern void func_002E3940(int);

void func_L14_00304190(void) {
    Vector axis;
    Record *dst = D_L14_00284708;
    float scale;
    int i;
    axis.q = 0;
    axis.f[0] = 1.0f;
    D_L14_001B23D0 = dst;
    scale = func_00282DB0(D_L14_001B9730, &axis);
    {
        Record *src = D_L14_00284690;
        int copyIndex;
        for (copyIndex = 0; copyIndex < 10; copyIndex++)
            dst[copyIndex].z = src[copyIndex].z * -scale;
    }
    for (i = 0; i < *(short *)(D_L14_001B2B20 + 6); i++) {
        if (i < 10) {
            func_002E3478(i);
            func_002E3940(i);
        } else {
            func_00283388(D_L14_001B2B50);
        }
    }
}
