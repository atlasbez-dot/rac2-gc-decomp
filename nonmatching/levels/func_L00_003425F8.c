/* M20, 26 October 2026: 800/816 B, aligned score 18 (was 39).
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Found: a position pointer local (retail keeps &position in $fp), the point test read through
 * path->points[i] before start is taken, and the side test as !(side > radius).
 * Left: retail does not fold the loop-entry test (it compares the spilled hit word, which is
 * still 0, against count - 1 with slt where this C gives blez), copies &position out of a2, and
 * swaps the unit/planePart address registers (s0/s1).
 */
#include "common.h"
/* Readable C reconstruction, measured 2026-10-23.
 * Profile: -O2 -G0 -ffunction-sections.
 * us: 0/27, us2: 0/27, pal: 0/27.
 * 784 bytes, retail816. Stack flag lifetime, loop allocation and float scheduling differ.
 * Tried: Direct vector reconstruction; default and qualified qcopy/barrier profiles.
 * Reopen: A source-level explanation of the retail flag spill and vector scheduling.
 * Historical screening notes follow unchanged. No handwritten-assembly inference.
 */

/* func_L00_003425F8 - 816 bytes, 27 places (every level), retail at 0x003425F8.
 *
 * Screened, not matched in wave 13 (worker s1): 26 call(s), no $gp-relative small-data
 * access, MMI words [lq $a1 / sq $a2] - a plain register as the base, so this body
 * is NOT blocked by the lq/sq offset folding that stops the rest of the family.  It is
 * the largest of the three survivors: 816 bytes, twenty-six calls, a loop over a table
 * and a 16-byte copy.  No C was written in this wave.
 */

typedef int Quadword __attribute__((mode(TI)));
typedef union { Quadword q; float f[4]; } Vector;
typedef struct { int count; int reserved[3]; Vector points[0]; } Path;
extern void func_00282CF0(void *, const void *, const void *);
extern void func_00282F20(void *, const void *, float);
extern void func_00282CC0(void *, const void *, const void *);
extern const Vector D_0018A0E0;
extern const Path *D_L00_001FDA80[];
extern float func_00282DB0(const void *, const void *);
extern void func_00282DD8(void *, const void *, const void *);
extern float func_00282C48(float);
extern float func_00282DF0(const void *);

/* Push the point away from the active edges while retaining its plane height. */
int func_L00_003425F8(int pathIndex, const Vector *point, Vector *out, float radius) {
    Vector relative, displacement, position, segment, unit, cross, planePart;
    int hit = 0;
    const Path *path;
    int i;
    float height, side, length, along;
    const Vector *start;
    Vector *pos = &position;
    pos->q = point->q;
    path = D_L00_001FDA80[pathIndex];
    height = func_00282DB0(pos, &D_0018A0E0);
    for (i = 0; i < path->count - 1; ++i) {
        if (path->points[i].f[3] == 0.0f && path->points[i + 1].f[3] == 0.0f)
            continue;
        start = &path->points[i];
        func_00282CF0(&relative, pos, start);
        func_00282CF0(&segment, &path->points[i + 1], start);
        func_00282F20(&planePart, &D_0018A0E0, func_00282DB0(&relative, &D_0018A0E0));
        func_00282CF0(&relative, &relative, &planePart);
        func_00282F20(&planePart, &D_0018A0E0, func_00282DB0(&segment, &D_0018A0E0));
        func_00282CF0(&segment, &segment, &planePart);
        func_00282F20(&unit, &segment, 1.0f);
        func_00282DD8(&cross, &relative, &unit);
        side = func_00282C48(func_00282DB0(&cross, &D_0018A0E0));
        if (!(side > radius)) {
            length = func_00282DF0(&segment);
            along = func_00282DB0(&relative, &unit);
            if (length < along || along < 0.0f) {
                if (func_00282DF0(&relative) < radius) {
                    hit = 1;
                    func_00282F20(&displacement, &relative, radius);
                    func_00282CC0(pos, &displacement, start);
                }
            } else {
                hit = 1;
                func_00282F20(&planePart, &unit, along);
                func_00282CF0(&displacement, &relative, &planePart);
                func_00282F20(&displacement, &displacement, radius);
                func_00282CC0(&displacement, &displacement, &planePart);
                func_00282CC0(pos, &displacement, start);
            }
        }
    }
    if (hit) {
        height -= func_00282DB0(pos, &D_0018A0E0);
        func_00282F20(&segment, &D_0018A0E0, height);
        func_00282CC0(out, pos, &segment);
    }
    return hit;
}
