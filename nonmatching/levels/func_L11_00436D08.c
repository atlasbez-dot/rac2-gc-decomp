/* Retained complete C reconstruction; not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections -frac2-zero-ti-por.
 * Compiled 636 bytes; retail 632 bytes.
 * us: 0/1 placements match (exit 1).
 * us2: 0/1 placements match (exit 1).
 * pal: canonical name absent; no match credit.
 * Remaining: The real qcopy capture and qualified zero-ti-por profile restore the 0x80 frame and
 * materialized zero. The entity-table base is a truthful scalar pointer with NOT_SDA, replacing
 * the historical three-word array extent. The final position predicate retains its actual
 * integer return. Pointer allocation and the PRE/CSE boundary remain different, starting at
 * +0x8; no artificial barrier was used.
 * Reopen: Independent CSE block-boundary evidence or a real source operation/lifetime that
 * preserves the retail reaching-pointer copy.
 */

#include "common.h"
typedef int TI128 __attribute__((mode(TI)));

/* the id-list table, and the two words the walk reads (the count through $gp; the entity base as a
   bare symbol: a three-word `sda` array keeps the `lui`/`lw` pair, a scalar would use $gp) */
extern u16 *D_L11_001FC420[];
extern u8 *D_L11_001B359C NOT_SDA;
extern s32 D_L11_001B35B8 __attribute__((sda));

/* the three float tuning words of this variant (angle limits in degrees, range) */
extern float D_L11_001B1230 __attribute__((sda));
extern float D_L11_001B1234 __attribute__((sda));
extern float D_L11_001B1238 __attribute__((sda));

extern int func_00283DB8(void *v, float r);
extern float func_00282E80(void *, void *);
extern float func_00283248(float, float);
extern float func_00283C80(float, float);
extern float func_00283BE0(float, float);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_002ACEC0(void *, void *, void *, float);
extern int func_L01_00321178(char *, char *);
extern s32 func_L02_003D7300(u8 *);

#define GROUP(off) (*(s32 *)(state + (off)))

s32 func_L11_00436D08(u8 *obj) {
    u8 *state = *(u8 **)(obj + 0x68);
    float copy[4] __attribute__((aligned(16)));
    float vec[4] __attribute__((aligned(16)));
    u16 *p;
    u8 *e;
    float saved;
    float a;
    float b;

    *(TI128 *)vec = 0;
    vec[0] = *(float *)(obj + 0x10);
    vec[1] = *(float *)(obj + 0x14);
    vec[2] = *(float *)(obj + 0x18);
    vec[3] = 2.0f;
    qcopy(copy ,vec);
    if (func_00283DB8(copy, 128.0f) > 0) {
        if (GROUP(0x278) != -1) {
            for (p = D_L11_001FC420[GROUP(0x278)];
                 (GROUP(0x278) & 0xFF) != 0xFF && GROUP(0x278) <= D_L11_001B35B8 && p != 0 &&
                 ((p != 0 && (s16)p[-1] >= 0) || p == D_L11_001FC420[GROUP(0x278)]);
                 p++) {
                e = D_L11_001B359C + ((*p & 0x7FFF) << 8);
                if (e == 0)
                    break;
                if (func_L02_003D7300(e)) {
                    if (func_00282E80(obj + 0x10, e + 0x10) < D_L11_001B1230) {
                        a = func_00283248(*(float *)(e + 0x10) - *(float *)(obj + 0x10),
                                          *(float *)(e + 0x14) - *(float *)(obj + 0x14));
                        if (func_00283C80(*(float *)(obj + 0xF8), a) < D_L11_001B1234 * 0.017453294f) {
                            func_00282CF0(vec, obj + 0x10, e + 0x10);
                            b = D_L11_001B1238 * 0.017453294f;
                            a = func_00283248(*(float *)(e + 0x10) - *(float *)(obj + 0x10),
                                              *(float *)(e + 0x14) - *(float *)(obj + 0x14));
                            func_002ACEC0(vec, vec, obj + 0xE0,
                                          func_00283BE0(*(float *)(obj + 0xF8), a) >= 0.0f ? -b : b);
                            func_00282CC0(vec, vec, e + 0x10);
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
