/* Retained plain-C near miss; measured 23 October 2026, USA v1.01.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * 288/288 bytes, 0/27 placements. Qcopy/barrier fixes both early-return copy slots
 * without fake volatile accesses. First difference +0x54 remains the cubic float
 * allocation/expression tree; retain the existing eleven-shape stopping evidence.
 */
typedef int TI128 __attribute__((mode(TI)));

void func_L00_003A2018(TI128 *out, TI128 *a1, TI128 *a2, TI128 *a3, TI128 *a4, float t)
{
    float *o = (float *)out;
    float *p = (float *)a1;
    float *q = (float *)a2;
    float *r = (float *)a3;
    float *s = (float *)a4;
    float tt, ttt, x, y, z, e, g;

    if (t == 0.0f) {
        TI128 tmp = *a1;
        *out = tmp;
        return;
    }
    if (t == 1.0f) {
        TI128 tmp = *a2;
        *out = tmp;
        return;
    }
    tt = t * t;
    ttt = tt * t;
    x = r[0] - p[0];
    y = s[0] - q[0];
    z = q[0] - r[0];
    e = y - x;
    g = x - e;
    o[0] = e * ttt + g * tt + z * t + p[0];
    x = r[1] - p[1];
    y = s[1] - q[1];
    z = q[1] - r[1];
    e = y - x;
    g = x - e;
    o[1] = e * ttt + g * tt + z * t + p[1];
    x = r[2] - p[2];
    y = s[2] - q[2];
    z = q[2] - r[2];
    e = y - x;
    g = x - e;
    o[2] = e * ttt + g * tt + z * t + p[2];
    o[3] = 0.0f;
}
