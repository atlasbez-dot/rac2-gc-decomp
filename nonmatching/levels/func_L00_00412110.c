/* func_L00_00412110, 288 bytes, 27 placements.  ABANDON - the FPR allocation of the three components.
 *
 * The body is recovered word for word and the size is exact (288 bytes) with
 * `-frac2-qcopy`; only the FPR allocation of the three components differs.  Retail keeps
 * t*t in $f5 and p0[i] in $f6 for the whole component, this candidate in $f4 and $f5;
 * retail reuses $f4 (p1[i]) for p1[i]-p2[i] and a fresh $f7 for the t3 coefficient, this
 * candidate a fresh $f7 for p1[i]-p2[i] and $f0 (dead) for the t3 coefficient.  Every
 * instruction is retail's, in retail's order, and the first difference is at +0x54.
 *
 * `-frac2-qcopy` is needed for the two early exits: without it this cc1 sinks the 16-byte
 * store into the `jr $ra` delay slot and the body is 280 bytes.  The two copies are the
 * group pattern `lq $v0,0($p1)` / `sq $v0,0($out)` (opcode 0x1E and 0x1F), not an lqd pair.
 *
 * Measured: eight statement orders of the five coefficients, four component orders, the
 * fully inlined expression, the coefficients in a nested scope, and the flags -O3,
 * -fno-gcse, -fno-strength-reduce, -mno-split-addresses, -fno-expensive-optimizations,
 * -fschedule-insns, -fschedule-insns2, -fno-schedule-insns, -O1.  None of them moves the
 * allocation; what would unblock it is the source expression tree the retail's allocator
 * saw, not the spelling of the arithmetic.
 *
 * func_L00_00412110 is the same body (same fingerprint 2ae8dc3c64a3dcc0) and takes the
 * same source; this record covers both rows.
 *
 * The row is the same body as func_L00_003CBD08 (same fingerprint), so the
 * candidate above is shared by the two rows.
 */
#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

/* Cubic Hermite between p0 and p1: the t3 coefficient is (p3-p1)-(p2-p0), the t2 one is
   (p2-p0) minus that, the t1 one is p1-p2, and the constant is p0.  The two early exits
   copy the whole 16-byte vector: p0 when t is zero, p1 when t is one. */
void func_L00_00412110(float *out, float *p0, float *p1, float *p2, float *p3, float t)
{
    float t2;
    float t3;
    float d0, d1, c1, c2, c3;

    if (t == 0.0f) {
        *(TI128 *)out = *(TI128 *)p0;
        return;
    }
    if (t == 1.0f) {
        *(TI128 *)out = *(TI128 *)p1;
        return;
    }
    t2 = t * t;
    t3 = t2 * t;

    d0 = p2[0] - p0[0];
    d1 = p3[0] - p1[0];
    c3 = d1 - d0;
    c2 = d0 - c3;
    c1 = p1[0] - p2[0];
    out[0] = c3 * t3 + c2 * t2 + c1 * t + p0[0];

    d0 = p2[1] - p0[1];
    d1 = p3[1] - p1[1];
    c3 = d1 - d0;
    c2 = d0 - c3;
    c1 = p1[1] - p2[1];
    out[1] = c3 * t3 + c2 * t2 + c1 * t + p0[1];

    d0 = p2[2] - p0[2];
    d1 = p3[2] - p1[2];
    c3 = d1 - d0;
    c2 = d0 - c3;
    c1 = p1[2] - p2[2];
    out[2] = c3 * t3 + c2 * t2 + c1 * t + p0[2];

    out[3] = 0.0f;
}

INCLUDE_ASM("asm/levels", func_L00_00412110);
