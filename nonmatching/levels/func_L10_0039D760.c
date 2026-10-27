/* Retained C reconstruction; not linked or counted.
 * Profile: -O2 -G0 -ffunction-sections.
 * 604/604 bytes. us: 0/2 places; us2: 0/2 places; pal: 0/2 places.
 * Remaining: Real qcopy transfers and a position pointer formed at its use retain the
 * 604-byte extent and 0xA0 frame. Saved-register priority, early object spill
 * and strip-loop address/induction scheduling still differ from +0x4. All
 * four components are copied; the interior-coordinate jitters remain scalar.
 * Reopen with: Independent strip-loop/object lifetime evidence; the field-at-use form
 * removes the 612-byte helper trial overhead but does not match.
 */

#include "common.h"

typedef int Quad __attribute__((mode(TI)));
extern short D_L10_001B2DB8[4];
extern short D_L10_001B2DC0[4];
extern f32 D_L10_00234600[4][8][4];
extern int func_00282978(short *);
extern f32 func_002A7878(f32, f32);
extern f32 func_002A78D8(f32, f32);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, f32);
extern void func_00282CC0(void *, void *, void *);
extern void func_L00_0031AA28(void *, void *, void *, void *, void *, f32);

/* Rebuilds each expired lightning strip and jitters its interior control points. */
void func_L10_0039D760(void *object) {
    f32 point[4];
    f32 direction[4];
    f32 result[4];
    char *self = object;
    char *state = *(char **)(self + 0x68);
    f32 t;
    f32 *objectPosition;
    int strip, i;
    for (strip = 0; strip < 4; strip++) {
        if (func_00282978(&D_L10_001B2DB8[strip])) {
            D_L10_001B2DB8[strip] = 2;
            D_L10_001B2DC0[strip] = 0;
            qcopy(point, state);
            point[0] += func_002A7878(0.0f, 0.0f);
            point[1] += func_002A7878(0.0f, 0.0f);
            point[2] += func_002A7878(0.0f, 0.0f);
            objectPosition=(f32 *)(self+0x10);
            func_00282CF0(direction, point, objectPosition);
            func_00282F20(direction, direction, 0.5f);
            func_00282CC0(direction, point, direction);
            for (i = 0; i < 8; i++) {
                t = (f32)i * 0.1f;
                if (i == 7) t = 1.0f;
                func_L00_0031AA28(result, objectPosition, point, direction, direction, t);
                qcopy(D_L10_00234600[strip][i], result);
            }
            for (i = 1; i < 7; i++) {
                qcopy(result, D_L10_00234600[0][i]);
                result[0] += func_002A78D8(0.0f, *(f32 *)(state + 0x34));
                result[1] += func_002A78D8(0.0f, *(f32 *)(state + 0x34));
                result[2] += func_002A78D8(0.0f, *(f32 *)(state + 0x34));
                qcopy(D_L10_00234600[0][i], result);
            }
        }
    }
}
