/* Retained manual C reconstruction, 25 October 2026; not matching.
 * Measured profile: -O2 -G8 -ffunction-sections -frac2-zero-ti-por. USA v1.01 and USA v2.00 each
 * match 0/1; the canonical name is absent from PAL.
 * 628/632 bytes. The qualified zero-ti-por profile reproduces the real por/sq clear. One entity-
 * position pseudo still replaces retail's two saved values, so the frame is 0x70 instead of 0x80
 * and register/save and branch scheduling differ. The encoded id-list walk and full 16-byte
 * vectors are retained. The true scalar entity-pool pointer uses nosda for its observed absolute
 * access; the old invented three-word _abs declaration and mismatched void declaration of the
 * integer-returning dispatcher were removed. Limited CSE traversal reached 632 bytes without
 * fixing the frame. The unsplit-GCSE probe and typed entity-prefix form tied the default
 * 628-byte text exactly.
 * Independent source/control-flow lifetime evidence preserving the second entity-position value.
 * Do not add a fake array extent, redundant use, register pin or barrier to force it.
 * No linked build or runtime validation. This results header was added after candidate checks;
 * the copied standalone file has not been recompiled after retention.
 */

#include "common.h"
typedef int TI128 __attribute__((mode(TI)));
/* Observed prefix only; entity indexing retains the measured 0x100-byte stride. */
typedef struct {
    u8 reserved00[0x10];
    float position[4];
} EntityPositionPrefix;

/* Encoded id lists and the observed absolute entity-pool pointer. */
extern u16 *D_L11_001FC420[];
extern u8 *D_L11_001B359C __attribute__((nosda));
extern s32 D_L11_001B35B8 __attribute__((sda));

/* the three float tuning words of this variant (angle limits in degrees, range) */
extern float D_L11_001B1D28 __attribute__((sda));
extern float D_L11_001B1D2C __attribute__((sda));
extern float D_L11_001B1D30 __attribute__((sda));

extern int func_00283DB8(void *v, float r);
extern float func_00282E80(void *, void *);
extern float func_00283248(float, float);
extern float func_00283C80(float, float);
extern float func_00283BE0(float, float);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_002ACEC0(void *, void *, void *, float);
extern int func_L01_00321178(char *, char *);
extern int func_L02_003D7300(char *);

#define GROUP(off) (*(s32 *)(state + (off)))

s32 func_L11_004530E0(u8 *obj) {
    u8 *state = *(u8 **)(obj + 0x68);
    float copy[4];
    float vec[4];
    u16 *p;
    EntityPositionPrefix *e;
    float saved;
    float a;
    float b;

    *(TI128 *)vec = 0;
    vec[0] = *(float *)(obj + 0x10);
    vec[1] = *(float *)(obj + 0x14);
    vec[2] = *(float *)(obj + 0x18);
    vec[3] = 2.0f;
    *(TI128 *)copy = *(TI128 *)vec;
    if (func_00283DB8(copy, 128.0f) > 0) {
        if (GROUP(0x2C0) != -1) {
            for (p = D_L11_001FC420[GROUP(0x2C0)];
                 (GROUP(0x2C0) & 0xFF) != 0xFF && GROUP(0x2C0) <= D_L11_001B35B8 && p != 0 &&
                 ((p != 0 && (s16)p[-1] >= 0) || p == D_L11_001FC420[GROUP(0x2C0)]);
                 p++) {
                e = (EntityPositionPrefix *)(D_L11_001B359C + ((*p & 0x7FFF) << 8));
                if (e == 0)
                    break;
                if (func_L02_003D7300((char *)e)) {
                    if (func_00282E80(obj + 0x10, e->position) < D_L11_001B1D28) {
                        a = func_00283248(e->position[0] - *(float *)(obj + 0x10),
                                          e->position[1] - *(float *)(obj + 0x14));
                        if (func_00283C80(*(float *)(obj + 0xF8), a) < D_L11_001B1D2C * 0.017453294f) {
                            func_00282CF0(vec, obj + 0x10, e->position);
                            b = D_L11_001B1D30 * 0.017453294f;
                            a = func_00283248(e->position[0] - *(float *)(obj + 0x10),
                                              e->position[1] - *(float *)(obj + 0x14));
                            func_002ACEC0(vec, vec, obj + 0xE0,
                                          func_00283BE0(*(float *)(obj + 0xF8), a) >= 0.0f ? -b : b);
                            func_00282CC0(vec, vec, e->position);
                            saved = *(float *)(state + 0x134);
                            *(float *)(state + 0x134) = 0.0001f;
                            func_L01_00321178((char *)obj, (char *)vec);
                            *(float *)(state + 0x134) = saved;
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
