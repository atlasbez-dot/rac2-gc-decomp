/* Retained near miss, 24 October 2026.
 * Dedicated unit `-O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier`.
 * USA v1.01, PAL and USA v2.00: 116/116 bytes, 0/28 places each.
 * Four checker invocations, no scratch compiles.
 *
 * The two grouped 16-byte copies, the 0.01f field, the +amount update, the
 * func_002761F8 call and the D_001BAFA8/0.0f return are retail's. The only
 * difference is the entry block: retail saves $ra and then copies $a0 into
 * $v1 for the two copies; this source saves $ra before the copy to $v1, and
 * the query pointer is materialised in a different register. qcopy alone
 * schedules the first copy after the constant; the barrier pins it but leaves
 * the entry order. A union of TImode and float[4] is identical.
 * -mastra-keep-frame-order does not change it.
 *
 * Reopen with independent evidence for the entry-block lifetime/order, not a
 * register pin or another copy spelling.
 */
#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));
typedef union { TI128 q; float f[4]; } Vector;

extern float D_001BAFA8;
extern int func_002761F8(void *, void *, int, void *, int);

float func_002A89A8(char *object, int mode, float amount)
{
    Vector local;
    Vector query;

    local.q = *(TI128 *)object;
    local.f[2] = 0.01f;
    query.q = *(TI128 *)object;
    query.f[2] += amount;
    if (func_002761F8(query.f, local.f, mode | 2, 0, 0))
        return D_001BAFA8;
    return 0.0f;
}
