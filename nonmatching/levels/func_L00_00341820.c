/* Readable C reconstruction, measured 2026-10-23.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * us: 0/24, us2: 0/24, pal: 0/24.
 * 624 bytes, retail616. Loop condition/index register allocation, offset loads and endpoint interpolation remain different.
 * Tried: Path layout and explicit byte-offset references; loading the old offset separately in both direction branches.
 * Reopen: A source shape reproducing the retail loop allocation without synthetic barriers.
 * Historical screening notes follow unchanged. No handwritten-assembly inference.
 */

/* func_L00_00341820 - 616 bytes, 24 places, retail at 0x00341820.
 *
 * Screened, not matched in wave 13 (worker s1): 3 call(s), no $gp-relative small-data
 * access, MMI words [lq $v1 / sq $s1, lq $v1 / sq $s1].  Both 16-byte copies
 * take retail's materialised-pointer form (the source address is computed into $v1
 * and the MMI load uses it with an offset of zero) and this cc1 always folds a
 * constant offset into the lq/sq pair.  Twenty spellings were measured and all of
 * them fold it.  No C was written in this wave.
 */

typedef int Quadword __attribute__((mode(TI)));
typedef union { Quadword q; float f[4]; } Vector;
typedef struct { int count; int reserved[3]; Vector points[0]; } Path;
extern void func_00282CF0(void *, const void *, const void *);
extern void func_00282F20(void *, const void *, float);
extern void func_00282CC0(void *, const void *, const void *);

/* Advance a path distance, preserving the current segment and its offset. */
int func_L00_00341820(const Path *path, Vector *out, int *index, float *offset, int wrap, float step) {
    Vector delta;
    int direction = 1;
    int reached = 0;
    int next;
    int crosses;
    float oldOffset;
    if (step < 0.0f) {
        step = -step;
        direction = -1;
    }
    while (step != 0.0f && (*index != path->count - 1 || wrap)) {
        if (direction == 1) {
            oldOffset = *offset;
            crosses = *(const float *)((const char *)path + ((*index << 4) + 0x1C)) < oldOffset + step;
        } else {
            oldOffset = *offset;
            crosses = oldOffset < step;
        }
        next = *index + direction;
        if (crosses) {
            if (next >= path->count || next < 0)
                next = (next + path->count) % path->count;
            if (direction == 1) {
                step -= *(const float *)((const char *)path + ((*index << 4) + 0x1C)) - oldOffset;
                *offset = 0.0f;
                if (step < *offset) step = *offset;
            } else {
                step -= oldOffset;
                *offset = *(const float *)((const char *)path + ((next << 4) + 0x1C));
            }
            if ((direction == 1 && *index == path->count - 1) || (direction == -1 && *index == 0))
                reached = 1;
            *index = next;
        } else {
            if (direction == 1) *offset = oldOffset + step;
            else *offset = oldOffset - step;
            step = 0.0f;
        }
    }
    out->q = *(const Quadword *)((const char *)path + ((*index << 4) + 0x10));
    if (*index == path->count - 1 && !wrap) {
        if (direction == -1) {
            *index = 0;
            out->q = *(const Quadword *)((const char *)path + 0x10);
            *offset = 0.0f;
        }
        return 1;
    }
    next = *index + 1;
    if (next >= path->count) next %= path->count;
    func_00282CF0(&delta, (const char *)path + ((next << 4) + 0x10), (const char *)path + ((*index << 4) + 0x10));
    func_00282F20(&delta, &delta, *offset);
    func_00282CC0(out, out, &delta);
    return reached;
}
