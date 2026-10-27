/* Retained complete query wrapper; not linked or counted.
 * Profile: -O2 -G0 -ffunction-sections. Size: 84/84 bytes.
 * US, US2 and PAL: 0/2 each. The two sentinel stores remain earlier than retail, from +0x1c.
 * Aggregate, named-tolerance and call-site initialization forms tie; separate
 * scalar outputs differ at +0x10. These preserve the measured original
 * scheduling constraint, while repairing the three pointer inputs and actual
 * integer result forwarded from the seven-GPR/two-FP query.
 * Reopen with independent output-lifetime/scheduling evidence, not argument
 * permutations, false prototypes or artificial dependencies.
 */
#include "common.h"
extern s32 func_L02_0032E998(u8 *, u8 *, void *, u8 *, s32, s32 *, s32 *, float, float);

s32 func_L03_00419C00(u8 *object, u8 *first, u8 *second) {
    struct { float angle; s32 first; s32 second; } result;
    u8 *record = *(u8 **)(object + 0x68);
    result.first = -1;
    result.second = -1;
    return func_L02_0032E998(first, second, &result.angle, record + 0x80,
                            *(s32 *)(record + 0x480), &result.first, &result.second,
                            0.0f, 0.1f);
}
