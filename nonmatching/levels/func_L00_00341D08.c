/* Readable C reconstruction, measured 2026-10-23.
 * Profile: -O2 -G0 -ffunction-sections.
 * us: 0/27, us2: 0/27, pal: 0/27.
 * 640 bytes, retail672; the qcopy/barrier profile reached656. Copy grouping, float allocation, divide scheduling and endpoint checks differ.
 * Tried: Readable three-dimensional projection with moving-pointer bounds loop; default and qualified copy profiles.
 * Reopen: A consistent natural vector/copy shape for both fast and general projection branches.
 * Historical screening notes follow unchanged. No handwritten-assembly inference.
 */

/* func_L00_00341D08 - 672 bytes, 27 places (every level), retail at 0x00341D08.
 *
 * Screened, not matched in wave 13 (worker s1): 16 call(s), no $gp-relative small-data
 * access, MMI words with plain register bases only ($s0, $s2, $s3, $s4, $s5
 * and $sp), so this body is NOT blocked by the lq/sq offset folding that stops the
 * rest of the family. It calls func_L00_00341B18 (still unmatched) and
 * func_L00_00341A88 (matched),
 * has a float comparison loop and eight 16-byte copies.  No C was written in this wave.
 */

typedef int Quadword __attribute__((mode(TI)));
typedef union { Quadword q; float f[4]; } Vector;
extern float func_00282C48(float);
extern float func_L00_00341B18(float *, const float *, const float *, const float *);
extern float func_00282E80(const void *, const void *);
extern float func_00282E48(const void *, const void *);
extern void func_L00_0031D670(void *, const void *, const void *, float);
extern void func_00282CF0(void *, const void *, const void *);
extern void func_00282F20(void *, const void *, float);
extern float func_00282DB0(const void *, const void *);
extern void func_00282D30(void *, const void *, float);
extern void func_00282CC0(void *, const void *, const void *);
extern float func_L00_00341A88(void *, void *, float);

float func_L00_00341D08(Vector *out, const Vector *point, const Vector *start, const Vector *end, float height) {
    Vector direction, base, normal, pointCopy, outCopy;
    float distance, endpointDistance, negativeDot, baseDot, denominator;
    int axis;
    const float *a, *b;
    float *projection;
    if (0.0f < height && func_00282C48(point->f[2] - start->f[2]) < height &&
        func_00282C48(point->f[2] - end->f[2]) < height) {
        distance = func_L00_00341B18(out->f, point->f, start->f, end->f);
        endpointDistance = func_00282E80(start, out);
        height = endpointDistance / func_00282E80(start, end);
        direction.q = start->q;
        base.q = end->q;
        func_L00_0031D670(out, &direction, &base, height);
        return distance;
    }
    func_00282CF0(&direction, end, start);
    base.q = start->q;
    func_00282F20(&direction, &direction, 1.0f);
    normal.q = direction.q;
    negativeDot = -func_00282DB0(point, &direction);
    baseDot = func_00282DB0(&base, &normal);
    denominator = func_00282DB0(&direction, &normal);
    func_00282D30(out, &direction, -(negativeDot + baseDot) / denominator);
    func_00282CC0(out, out, &base);
    axis = 0;
    b = end->f;
    a = start->f;
    projection = out->f;
    do {
        if (*a < *projection && *b < *projection) break;
        if (*projection < *a && *projection < *b) break;
        ++axis;
        ++b;
        ++a;
        ++projection;
    } while (axis < 3);
    if (axis < 3) {
        endpointDistance = func_00282E48(out, start);
        if (endpointDistance < func_00282E48(out, end)) out->q = start->q;
        else out->q = end->q;
    }
    pointCopy.q = point->q;
    outCopy.q = out->q;
    return func_L00_00341A88(&pointCopy, &outCopy, 0.0f);
}
