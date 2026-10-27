/* Retained C reconstruction; not linked or counted.
 * Profile: -O2 -G0 -ffunction-sections.
 * 324/324 bytes. us: 0/2 places; us2: 0/2 places; pal: absent.
 * Remaining: The real direction/position qcopy transfers agree. Three once-used input
 * values still receive different saved registers from +0x1C, and the final
 * timer-array address setup differs. Physical argument order, pointer/null
 * allocator return and the four FP inputs are preserved.
 * Reopen with: Natural input-value or state-field lifetime evidence; changing argument
 * order or declaring false callee contracts is not a remedy.
 */

#include "common.h"

typedef int Quad __attribute__((mode(TI)));
extern void *func_0029EFD0(s32);
extern short D_L10_001B2DB8[4];

/* Creates a strip-effect object with its supplied vectors and rendering parameters. */
void *func_L10_0039D5E0(void *position, void *direction, s32 duration, s32 kind,
                       s32 first, s32 second, s32 third, s32 texture,
                       float jitter, float width, float height, float fade) {
    u8 *object = func_0029EFD0(0x133E);
    char *state;
    int i;
    if (object) {
        state = *(char **)(object + 0x68);
        object[0x30] = 255;
        *(u16 *)(object + 0x32) = 255;
        object[0x31] = 1;
        object[0x20] = 0;
        *(s32 *)(state + 0x2C) = kind;
        *(s32 *)(state + 0x10) = duration;
        *(s32 *)(state + 0x14) = first;
        *(s32 *)(state + 0x18) = second;
        *(s32 *)(state + 0x1C) = third;
        *(float *)(state + 0x20) = width;
        *(float *)(state + 0x24) = height;
        *(float *)(state + 0x28) = fade;
        *(s32 *)(state + 0x30) = texture;
        *(float *)(state + 0x34) = jitter;
        qcopy(state, direction);
        qcopy((object + 0x10), position);
        for (i = 2; i >= 0; i--) D_L10_001B2DB8[i] = -1;
    }
    return object;
}
