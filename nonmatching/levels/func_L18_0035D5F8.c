/* Retained manual C reconstruction, 25 October 2026; not matching.
 * Profile: -O2 -G0 -ffunction-sections.
 * 344/344 bytes, first mismatch +0xC. The true variable-count path layout and consistent
 * projection-helper FP/GPR interface do not resolve allocation: retail keeps the loop counter in
 * s2, while the candidate assigns s2 to the origin and the counter to s5. Actual allocator dumps
 * establish the competing live ranges. Reopen with an independently supported loop lifetime
 * model.
 * Checks: us: func_L18_0035D5F8: 0 of 3 places match; us2: func_L18_0035D5F8: 0 of 3 places
 * match; pal: func_L18_0035D5F8: 0 of 3 places match.
 * No linked build or runtime validation. This header was added after candidate checks; the
 * copied standalone file was not recompiled after retention.
 */

#include "common.h"
extern f32 func_L18_0035D238(f32, void *, void *, void *, void *, void *);
extern f32 func_00282C48(f32);
extern f32 func_00282E48(void *, void *);

/* GCC 2.9's zero-length trailing array describes the variable point payload. */
typedef struct { s32 count; u8 reserved04[12]; f32 point[0][4]; } PathPoints;

/* Finds the best projected point on the path, breaking near ties by distance. */
f32 func_L18_0035D5F8(void *out, void *origin, void *direction, char *path, f32 scale) {
    f32 candidate[4];
    f32 best = 100000000000.0f;
    f32 score, distance;
    s32 i = 0;
    PathPoints *points = (PathPoints *)path;
    if (points->count - 1 > 0) {
    for (; i < points->count - 1; i++) {
        score = func_L18_0035D238(scale, candidate, origin, direction, points->point[i], points->point[i + 1]);
        if (score < best) {
            best = score;
            qcopy(out, candidate);
        } else if (func_00282C48(score - best) < 0.1f) {
            distance = func_00282E48(candidate, origin);
            if (distance < func_00282E48(out, origin)) {
                best = score;
                qcopy(out, candidate);
            }
        }
    }
    }
    return best;
}
