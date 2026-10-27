/* M25 2026-10-26: 1648/1648 bytes (was 1640). The forward segment search is a
 * do/while whose top test exits without the subtraction (goto found), which gives
 * retail's loop shape and size. Left (119 lines): count/path in $a2/$a0 where retail
 * has $a0/$v1 (beq path,*currentPath operand order), progress in $f1 where retail
 * computes it straight into $f12, and the forward loop is strength-reduced (pointer
 * IVs) where retail indexes with sll/addu each pass.
 */
/* Signature/interface follow-up, 23 October 2026.
 * Profile: -O2 -G0 -ffunction-sections.
 * USA v1.01: 1640/1648 bytes, 0/1 carrying placements.
 * USA v2.00: 1640/1648 bytes, 0/1 carrying placements.
 * PAL: 1640/1648 bytes, 0/1 carrying placements.
 * func_0026FEB8 follows the canonical const-char-pointer variadic logger interface.
 * This follows the current linked C contract; it does not independently prove the original
 * source declaration.
 * The retained C remains nonmatching. Earlier sizes and residual offsets below are
 * historical and superseded by this measurement; their reopening hypotheses remain
 * unqualified. No linked build was run for this follow-up.
 */

/* Historical measurements, superseded where inconsistent with the follow-up above. */
/* USA v1.01/v2.00/PAL 0/1 each; 1640/1648 bytes.
 * Profile: default -O2 -G0 -ffunction-sections.
 * Range dispatch and float/register allocation remain; small-data declaration eligibility resolved address forms. Tried scoped ratios and float-first vector scale ABI. Reopen with local lifetime evidence.
 */
typedef unsigned char u8;
typedef float f32;
struct BarlowAnimation { int frames; u8 unused[24]; f32 duration; };
extern struct BarlowAnimation *D_L04_001FE340[];
extern u8 D_L04_001B1280[];
extern void func_0026FEB8(const char *, ...);
extern void func_00282D30(f32, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern int D_L04_001B12B0[][2] __attribute__((sda));
extern f32 D_L04_0026D370[][4];
extern f32 D_L04_001B3300[] __attribute__((sda));
extern f32 D_L04_001B33B8[] __attribute__((sda));
extern f32 D_L04_001B3470 __attribute__((sda));
extern int D_L04_001B12E8[][2] __attribute__((sda));
extern f32 D_L04_001B3280[][4] __attribute__((sda));
extern f32 D_L04_001B3320[] __attribute__((sda));
extern f32 D_L04_001B33D8[] __attribute__((sda));
extern f32 D_L04_001B3474 __attribute__((sda));
extern int D_L04_002CA3E0[][2];
extern f32 D_L04_0026D3E0[][4];
extern f32 D_L04_001B3330[] __attribute__((sda));
extern f32 D_L04_001B33E8[] __attribute__((sda));
extern f32 D_L04_001B3478 __attribute__((sda));
extern int D_L04_001B1300[][2] __attribute__((sda));
extern f32 D_L04_0026D490[][4];
extern f32 D_L04_001B3360[] __attribute__((sda));
extern f32 D_L04_001B3418[] __attribute__((sda));
extern f32 D_L04_001B347C __attribute__((sda));
extern int D_L04_002CA438[][2];
extern f32 D_L04_0026D4F0[][4];
extern f32 D_L04_001B3378[] __attribute__((sda));
extern f32 D_L04_001B3430[] __attribute__((sda));
extern f32 D_L04_001B3480 __attribute__((sda));
extern int D_L04_001B1330[][2] __attribute__((sda));
extern f32 D_L04_001B32B0[][4] __attribute__((sda));
extern f32 D_L04_001B33A0[] __attribute__((sda));
extern f32 D_L04_001B3458[] __attribute__((sda));
extern f32 D_L04_001B3484 __attribute__((sda));
extern int D_L04_001B1348[][2] __attribute__((sda));
extern f32 D_L04_001B32E0[][4] __attribute__((sda));
extern f32 D_L04_001B33B0[] __attribute__((sda));
extern f32 D_L04_001B3468[] __attribute__((sda));
extern f32 D_L04_001B3488 __attribute__((sda));

void func_L04_0043AD48(int *outX, int *outY, int animation, int frame, int *currentPath, int *currentSegment, u8 *data) {
    f32 point[4], movement[4];
    int (*points)[2];
    f32 (*vectors)[4], *lengths, *starts;
    int count, path, segment;
    f32 progress, start;
    struct BarlowAnimation *timing;
    if (animation == -1 && frame >= 0 && frame <= 151) {
        f32 ratio;
        timing = D_L04_001FE340[*(int *)(data + 0x1A8)];
        ratio = (timing->duration * (f32)(frame - 0)) / (timing->duration * 151.0f);
        if (ratio > 1.0f)
            ratio = 1.0f;
        progress = ratio * D_L04_001B3470;
        points = D_L04_001B12B0;
        vectors = D_L04_0026D370;
        lengths = D_L04_001B3300;
        starts = D_L04_001B33B8;
        count = 7;
        path = 1;
    } else if (animation == -1 && frame >= 151 && frame <= 174) {
        f32 ratio;
        timing = D_L04_001FE340[*(int *)(data + 0x1A8)];
        ratio = (timing->duration * (f32)(frame - 151)) / (timing->duration * 23.0f);
        if (ratio > 1.0f)
            ratio = 1.0f;
        progress = ratio * D_L04_001B3474;
        points = D_L04_001B12E8;
        vectors = D_L04_001B3280;
        lengths = D_L04_001B3320;
        starts = D_L04_001B33D8;
        count = 3;
        path = 2;
    } else if (animation == -1 && frame >= 174 && frame <= 312) {
        f32 ratio;
        timing = D_L04_001FE340[*(int *)(data + 0x1A8)];
        ratio = (timing->duration * (f32)(frame - 174)) / (timing->duration * 138.0f);
        if (ratio > 1.0f)
            ratio = 1.0f;
        progress = ratio * D_L04_001B3478;
        points = D_L04_002CA3E0;
        vectors = D_L04_0026D3E0;
        lengths = D_L04_001B3330;
        starts = D_L04_001B33E8;
        count = 11;
        path = 3;
    } else if (animation == -1 && frame >= 312 && frame <= 500) {
        f32 ratio;
        timing = D_L04_001FE340[*(int *)(data + 0x1A8)];
        ratio = (timing->duration * (f32)(frame - 312)) / (timing->duration * 186.0f);
        if (ratio > 1.0f)
            ratio = 1.0f;
        progress = ratio * D_L04_001B347C;
        points = D_L04_001B1300;
        vectors = D_L04_0026D490;
        lengths = D_L04_001B3360;
        starts = D_L04_001B3418;
        count = 6;
        path = 4;
    } else if (animation == 0) {
        f32 ratio;
        timing = D_L04_001FE340[*(int *)(data + 0x1AC)];
        ratio = (timing->duration * (f32)frame) / (timing->duration * (f32)timing->frames);
        if (ratio > 1.0f)
            ratio = 1.0f;
        progress = ratio * D_L04_001B3480;
        points = D_L04_002CA438;
        vectors = D_L04_0026D4F0;
        lengths = D_L04_001B3378;
        starts = D_L04_001B3430;
        count = 9;
        path = 5;
    } else if (animation == 2) {
        f32 ratio;
        timing = D_L04_001FE340[*(int *)(data + 0x1B4)];
        ratio = (timing->duration * (f32)frame) / (timing->duration * (f32)timing->frames);
        if (ratio > 1.0f)
            ratio = 1.0f;
        progress = ratio * D_L04_001B3484;
        points = D_L04_001B1330;
        vectors = D_L04_001B32B0;
        lengths = D_L04_001B33A0;
        starts = D_L04_001B3458;
        count = 3;
        path = 6;
    } else if (animation == 1) {
        f32 ratio;
        timing = D_L04_001FE340[*(int *)(data + 0x1B0)];
        ratio = (timing->duration * (f32)frame) / (timing->duration * (f32)timing->frames);
        if (ratio > 1.0f)
            ratio = 1.0f;
        progress = ratio * D_L04_001B3488;
        points = D_L04_001B1348;
        vectors = D_L04_001B32E0;
        lengths = D_L04_001B33B0;
        starts = D_L04_001B3468;
        count = 2;
        path = 7;
    } else {
        func_0026FEB8(D_L04_001B1280);
        *currentPath = -1;
        *currentSegment = 0;
        *outX = 0;
        *outY = 0;
        return;
    }
    segment = 0;
    if (*currentPath != path) {
        start = 0.0f;
        if (progress >= 0.0f) {
            start = lengths[0];
            if (progress < start) {
                start = 0.0f;
            } else {
                do {
                    segment++;
                    if (!(start <= progress))
                        goto found;
                    start += lengths[segment];
                } while (!(progress < start));
                start -= lengths[segment];
            found:;
            }
        }
        *currentSegment = segment;
        *currentPath = path;
    } else {
        segment = *currentSegment;
        start = starts[segment];
        if (progress < start) {
            while (progress < start) {
                segment--;
                if (segment < 0)
                    segment = count;
                start -= lengths[segment];
            }
        } else {
            while (start < progress) {
                start += lengths[segment];
                if (start < progress) {
                    segment++;
                    if (segment >= count)
                        segment = 0;
                }
            }
        }
        start = starts[segment];
        *currentSegment = segment;
    }
    point[0] = (f32)points[segment][0];
    point[1] = (f32)points[segment][1];
    point[2] = 0.0f;
    func_00282D30(progress - start, movement, vectors[segment]);
    func_00282CC0(point, point, movement);
    *outX = (int)point[0];
    *outY = (int)point[1];
}
