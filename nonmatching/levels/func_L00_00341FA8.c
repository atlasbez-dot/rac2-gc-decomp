/* Readable C reconstruction, measured 2026-10-23.
 * Profile: -O2 -G0 -ffunction-sections.
 * us: 0/23, us2: 0/23, pal: 0/23.
 * 912 bytes, retail924; qcopy/barrier reached932. Local/vector address lifetimes and register allocation differ.
 * Tried: Full readable two-stage path sampling, using the corrected float-returning distance wrapper; default and copy profiles.
 * Reopen: A vector/local layout and lifetime shape reproducing the retail register choices.
 * Historical screening notes follow unchanged. No handwritten-assembly inference.
 */

/* func_L00_00341FA8 - 924 bytes, 23 places, retail at 0x00341FA8.
 *
 * Screened, not matched in wave 13 (worker s1): 12 call(s), no $gp-relative small-data
 * access, MMI words with mostly plain register bases but two of them take $v0 - a
 * scratch register holding a materialised address - so the body is blocked by the lq/sq
 * offset folding for part of the family.  No C was written in this wave.
 */

typedef int Quadword __attribute__((mode(TI)));
typedef union { Quadword q; float f[4]; } Vector;
typedef struct { int count; int reserved[3]; Vector points[0]; } Path;
extern void func_00282CF0(void *, const void *, const void *);
extern void func_00282F20(void *, const void *, float);
extern void func_00282CC0(void *, const void *, const void *);
extern float func_L00_00341A88(void *, void *, float);
extern int func_L00_00341820(const Path *, Vector *, int *, float *, int, float);
extern int func_L00_003417B8(const int *, int, int, int);
extern float func_L00_00341D08(Vector *, const Vector *, const Vector *, const Vector *, float);
extern void func_00282C88(Quadword *);

/* Find the nearby path segment and the projected position on that segment. */
int func_L00_00341FA8(const Path *path, const Vector *point, Vector *out,
                     int *index, float *offset, int wrap,
                     float range, float step, float height) {
    Vector current, a, b, candidate;
    int scanIndex = 0;
    float scanOffset = 0.0f;
    int left, right;
    int nearestIndex = 0;
    float nearestOffset = 0.0f;
    float nearestDistance, distance;
    int finished, previous, next;
    current.q = path->points[0].q;
    a.q = point->q;
    nearestDistance = func_L00_00341A88(&current, &a, height);
    if (path->count == 0) {
        func_00282C88(&out->q);
        return 0;
    }
    range = step + range;
    do {
        finished = func_L00_00341820(path, &current, &scanIndex, &scanOffset, wrap, step);
        a.q = point->q;
        distance = func_L00_00341A88(&current, &a, height);
        if (distance < nearestDistance) {
            nearestIndex = scanIndex;
            nearestDistance = distance;
            nearestOffset = scanOffset;
        }
    } while (!finished);
    if (range < nearestDistance) return 0;
    left = nearestIndex;
    scanOffset = nearestOffset;
    func_L00_00341820(path, &current, &left, &scanOffset, wrap, -step);
    right = nearestIndex;
    scanOffset = nearestOffset;
    func_L00_00341820(path, &current, &right, &scanOffset, wrap, step);
    right = func_L00_003417B8(&path->count, right, 1, wrap);
    scanIndex = left;
    nearestDistance = 1000000000.0f;
    for (;;) {
        a.q = path->points[scanIndex].q;
        b.q = point->q;
        distance = func_L00_00341A88(&a, &b, height);
        if (distance < nearestDistance) {
            nearestIndex = scanIndex;
            nearestDistance = distance;
        }
        if (scanIndex == right) break;
        scanIndex = (scanIndex + 1) % path->count;
    }
    nearestDistance = 1000000000.0f;
    if (nearestIndex > 0 || wrap) {
        previous = (nearestIndex + path->count - 1) % path->count;
        nearestDistance = func_L00_00341D08(out, point, &path->points[previous], &path->points[nearestIndex], height);
        *index = previous;
        a.q = path->points[previous].q;
        b.q = out->q;
        *offset = func_L00_00341A88(&a, &b, 0.0f);
    }
    if (nearestIndex < path->count - 1 || wrap) {
        next = (nearestIndex + 1) % path->count;
        distance = func_L00_00341D08(&a, point, &path->points[nearestIndex], &path->points[next], height);
        if (distance < nearestDistance) {
            out->q = a.q;
            *index = nearestIndex;
            b.q = path->points[nearestIndex].q;
            candidate.q = out->q;
            *offset = func_L00_00341A88(&b, &candidate, 0.0f);
        }
    }
    return 1;
}
