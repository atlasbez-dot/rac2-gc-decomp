/* Mid worker 11 near miss (func_L05_004247C8).
   Profile: -O2 -G0 -ffunction-sections.
   Status: same 420 bytes; constants and calls match, only the scheduling of the colour shift/or around the jal delay slot and the order of two prologue constants differ. */
#include "common.h"

#define FLD(base, T, off) (((struct { u8 pad[off]; T v; } *)(base))->v)

extern void ref_L05_004247C8_00(char *, void *);
extern char ref_L05_004247C8_01[];
extern float ref_L05_004247C8_02(void);
extern float ref_L05_004247C8_03(float);
extern float ref_L05_004247C8_04(float);
extern void ref_L05_004247C8_05(float *, float *, char *);
extern void ref_L05_004247C8_06(float *, float *, char *);
extern int ref_L05_004247C8_07(float);
extern void ref_L05_004247C8_08(float *, int, int, int, float, float, float);
extern float ref_L05_004247C8_09(float, float);
extern float ref_L05_004247C8_10(float);

void func_L05_004247C8(char *obj) {
    float v[4];
    char *state;
    int color;
    int i;
    float full;

    full = 128.0f;
    state = FLD(obj, char *, 0x68);
    ref_L05_004247C8_00(obj + 0x10, ref_L05_004247C8_01);
    for (i = 29; i >= 0; i--) {
        float angle = ref_L05_004247C8_02();
        v[0] = 0.0f;
        v[1] = ref_L05_004247C8_03(angle);
        v[2] = -ref_L05_004247C8_04(angle);
        ref_L05_004247C8_05(v, v, obj + 0xC0);
        ref_L05_004247C8_06(v, v, obj + 0x10);
        color = ref_L05_004247C8_07(full) << 24;
        color |= 0x808080;
        ref_L05_004247C8_08(v, 0x13, color, 1, 0.25f, 0.1f, ref_L05_004247C8_02());
        {
            float half = 0.5f;
            color = FLD(state, int, 8);
            color &= 0xFFFFFF;
            color |= ref_L05_004247C8_07(full * half) << 24;
            ref_L05_004247C8_08(v, 0x13, color, 1, half, 0.1f, ref_L05_004247C8_02());
        }
    }
    FLD(state, float, 4) = 0.13380859792232513f;
    FLD(state, float, 0) = ref_L05_004247C8_09(FLD(state, float, 0), 0.13380859792232513f);
    ref_L05_004247C8_10(FLD(state, float, 0));
}
