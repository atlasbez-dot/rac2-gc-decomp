/*
 * Retained manual C reconstruction; not linked or counted.
 * Profile: -O2 -G0 -ffunction-sections
 * Retail: 272 bytes; compiled: 272 bytes.
 * Final coverage: us: 0/5; us2: 0/5; pal: 0/5.
 * Residual: 272/272 bytes after actual hit/null/type guards. Both rejected IDs return 0,
 * and the object height is initialized on the null-hit path. Owner/global saved-register
 * roles and vector-pointer setup still differ. The old global address spelling was
 * corrected from retail instructions.
 * Reopen: A real hit-record/owner lifetime witness preserving the corrected guards,
 * initialized height and full16-byte vectors. No false return881 or uninitialized height
 * path.
 */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));
typedef union { TI128 q; float f[4]; } Vector;

extern char D_L01_001BF900[];

extern int func_002761F8(char *a0, char *a1, int a2, char *a3, char *a4);

extern void func_00282F20(float *a0, float *a1, float f12);

extern void func_00282CF0(void *a0, void *a1, void *a2);

extern float func_00282DB0(float *a0, float *a1);

extern float func_00282C48(float f12);

extern void func_00282CC0(void *a0, void *a1, void *a2);

int func_L01_0031B300(char *a0, int a1, char *a2, char *a3) {
    Vector v, w;
    float f20;
    float f2;
    char *g;
    char *h;
    char *p;
    int v1;

    if (func_002761F8(a2, a3, 0x10, a0, 0) == 0)
        goto fail;
    g = D_L01_001BF900;
    p = *(char **)(g + 0x18);
    if (p != 0) {
        v1 = *(short *)(p + 0xAA);
        if (v1 == 0x881 || v1 == 0)
            return 0;
    }
    f20 = *(float *)(a0 + 0x18);
    h = g + 0x40;
    qcopy(&w, h);
    func_00282F20(w.f, w.f, 1.0f);
    func_00282CF0(&v, a3, g + 0x20);
    f2 = func_00282C48(func_00282DB0(v.f, w.f));
    func_00282F20(w.f, (float *)h, f2);
    func_00282CC0(a0 + 0x10, a0 + 0x10, &w);
    *(float *)(a0 + 0x18) = f20;
    return 1;
fail:
    return 0;

}
