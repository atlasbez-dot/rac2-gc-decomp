/* func_0031E7D8 (288 bytes, boot; unit src/game/003173B0-qcopy.c, -frac2-qcopy
   -frac2-qcopy-barrier). 26 October 2026 (M32): 288/288, the three components unrolled
   with the w clear after the last; only FPR choices and the order of the three
   differences inside each component are left (about 35 lines). In the permuter. */
typedef int CurveWord128 __attribute__((mode(TI)));

/* Cubic curve point at t between p0 (t = 0) and p1 (t = 1), shaped by the two
   control points a and b; w is cleared. */
void func_0031E7D8(void *out, void *p0, void *p1, void *a, void *b, float t)
{
    float *o = out;
    float *s = p0;
    float *e = p1;
    float *c = a;
    float *d = b;
    float t2;
    float t3;
    float k;
    float m;
    float l;

    if (t == 0.0f) {
        *(CurveWord128 *)out = *(CurveWord128 *)p0;
        return;
    }
    if (t == 1.0f) {
        *(CurveWord128 *)out = *(CurveWord128 *)p1;
        return;
    }
    t2 = t * t;
    t3 = t2 * t;
    l = e[0] - c[0];
    k = c[0] - s[0];
    m = (d[0] - e[0]) - k;
    o[0] = m * t3 + (k - m) * t2 + l * t + s[0];
    l = e[1] - c[1];
    k = c[1] - s[1];
    m = (d[1] - e[1]) - k;
    o[1] = m * t3 + (k - m) * t2 + l * t + s[1];
    l = e[2] - c[2];
    k = c[2] - s[2];
    m = (d[2] - e[2]) - k;
    o[2] = m * t3 + (k - m) * t2 + l * t + s[2];
    o[3] = 0.0f;
}
