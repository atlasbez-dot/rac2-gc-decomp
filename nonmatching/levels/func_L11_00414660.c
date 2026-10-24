/* 2026-10-23 readable reconstruction. Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -g.
 * 288/288 bytes, 0/4 placements in each of us, us2 and pal. First remaining mismatch +0x40: scalar FP allocation. Seven source/profile trials; plain TI endpoint copies work, qcopy/barrier fixes their return scheduling. Reopen with evidence for scalar temporary allocation.
 * Earlier screening-only commentary is preserved below as historical context.
 */
/* from src/levels/shared/L11_002C5E80.c: not written this wave. Retail 288 bytes, 4 place(s), first word at L11:00414660.
 * Rule: MMI/LQ/SQ (op 0x1e).
 * No C attempt was made (wave-5 tour-2 discard rule).
 * Retail opens with:
 *   0x00414660  mtc1        $zero, $f8
 *   0x00414664  nop
 *   0x00414668  c.eq.s      $f12, $f8
 *   0x0041466c  nop
 *   0x00414670  bc1f        . + 4 + (0x5 << 2)
 *   0x00414674  nop
 * Kept as data for the maintainers. */

typedef int Vec128_00414660 __attribute__((mode(TI)));

void func_L11_00414660(float *out, float *start, float *end, float *before, float *after, float t)
{
    float t2, t3, a, b, result;
    if (t == 0.0f) {
        *(Vec128_00414660 *)out = *(Vec128_00414660 *)start;
        return;
    }
    if (t == 1.0f) {
        *(Vec128_00414660 *)out = *(Vec128_00414660 *)end;
        return;
    }
    t2 = t * t;
    t3 = t2 * t;
    a = before[0] - start[0];
    b = (after[0] - end[0]) - a;
    result = b * t3 + (a - b) * t2 + (end[0] - before[0]) * t + start[0];
    out[0] = result;
    a = before[1] - start[1];
    b = (after[1] - end[1]) - a;
    result = b * t3 + (a - b) * t2 + (end[1] - before[1]) * t + start[1];
    out[1] = result;
    a = before[2] - start[2];
    b = (after[2] - end[2]) - a;
    result = b * t3 + (a - b) * t2 + (end[2] - before[2]) * t + start[2];
    out[3] = 0.0f;
    out[2] = result;

}
