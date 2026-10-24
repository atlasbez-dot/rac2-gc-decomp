/* 224-byte near miss. The prologue, float argument saves, range check and
 * conditional func_00115E38 call match; the first difference is +0x54, where
 * the candidate computes t*t into $f2 instead of retail's $f1. The remaining
 * polynomial instructions consequently use a different FPR allocation.
 * Four equivalent formula spellings did not change that allocation. The best
 * candidate matched 0/28 placements in USA v1.01, PAL and USA v2.00. */
extern char D_001AE7A0[];
extern char D_001AE7B8[];
extern void func_00115E38(char *, int, char *);

float func_0034EE78(float t, float p0, float m0, float m1, float p1)
{
    float t2, t3, r0, r1, r2, r3;

    if (!(t >= 0.0f && t <= 1.0f))
        func_00115E38(D_001AE7A0, 0x24, D_001AE7B8);

    t2 = t * t;
    t3 = t * t2;
    r0 = p0 * ((t3 + t3) - (t2 * 3.0f)) + p0;
    r1 = m0 * ((t3 - (t2 + t2)) + t);
    r2 = m1 * (t3 - t2);
    r3 = p1 * ((t2 * 3.0f) - (t3 + t3));
    return ((r0 + r1) + r2) + r3;
}
