/*
 * Retained manual C reconstruction; not linked or counted.
 * Profile: -O2 -G0 -ffunction-sections
 * Retail: 152 bytes; compiled: 152 bytes.
 * Final coverage: us: 0/27; us2: 0/27; pal: 0/27.
 * Residual: 152/152 bytes. The original useful complete TI-snapshot form remains the
 * final control; destination/right-local saved-register roles and first-store scheduling
 * differ at+0x28. The new first-snapshot helper gave 140 bytes; a streamed destination
 * gave 152 with the wrong 0x40 frame, so neither replaces this control.
 * Reopen: A real destination/right-snapshot lifetime witness. The prior dozens of
 * equivalent pointer/union/declaration forms remain stopping evidence; helper grouping
 * cannot by itself recover the separated initial loads.
 */
#include "common.h"

typedef unsigned int u128 __attribute__((mode(TI)));

extern float func_002AA140(float, float, float);

void func_L00_0031D670(f32 *out, const f32 *a, const f32 *b, f32 factor) {
    u128 left = *(const u128 *)a;
    u128 right = *(const u128 *)b;
    f32 *lf = (f32 *)&left;
    f32 *rf = (f32 *)&right;

    out[0] = func_002AA140(lf[0], rf[0], factor);
    out[1] = func_002AA140(lf[1], rf[1], factor);
    out[2] = func_002AA140(lf[2], rf[2], factor);
    out[3] = func_002AA140(lf[3], rf[3], factor);
}
