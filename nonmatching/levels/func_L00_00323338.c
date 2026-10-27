/*
 * Retained manual C reconstruction; not linked or counted.
 * Profile: -O2 -G0 -ffunction-sections
 * Retail: 272 bytes; compiled: 272 bytes.
 * Final coverage: us: 0/15; us2: 0/15; pal: 0/15.
 * Residual: 272/272 bytes. Two full vector snapshots remain ordinary TI and the final
 * transfer uses qcopy; the inverse matrix scratch is a full 64-byte object. Index/count
 * allocation and final cursor setup differ. Current retail has no initial copy of the
 * unused first input, superseding the old draft comment.
 * Reopen: A measured best-index/count lifetime witness with the true 96-byte workspace.
 * Matrix/first-vector views improve some allocation roles; delayed best initialization
 * ties. Do not retain an artificial use of the unused first input.
 */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));
typedef union { TI128 q; float f[4]; } Vector;

extern float func_00282E48(void *, void *);

extern void func_00283698(void *, void *);

extern void func_00283678(void *, void *);

#ifndef RAC2_T_V4TI_F36D8A248
#define RAC2_T_V4TI_F36D8A248
typedef int V4TI_F36d8a248 __attribute__((mode(TI)));
#endif

int func_L00_00323338(void *a0, void *records, int count, void *src0, void *src1,
                      void *dst, void *ctx)
{
    struct {
        V4TI_F36d8a248 v0;
        V4TI_F36d8a248 v1;
        V4TI_F36d8a248 matrix[4];
    } local;
    void *lp = &local.v0;
    void *matrix = (char *)lp + 0x20;
    char *p;
    int i = 0;
    int best;
    float bestf = 9999.0f;

    local.v0 = *(V4TI_F36d8a248 *)src0;
    local.v1 = *(V4TI_F36d8a248 *)src1;
    best = 0;
    if (count > 0) {
        p = (char *)records + 0x30;
        do {
            float f = func_00282E48(lp, p);
            if (f < bestf) {
                bestf = f;
                best = i;
            }
            i++;
            p += 0x40;
        } while (i < count);
    }
    p = (char *)records + (best << 6);
    func_00283698(matrix, p);
    func_00283678(ctx, matrix);
    p += 0x30;
    qcopy(dst, p);
    return best;
}
