/*
 * Retained complete manual reconstruction; not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections
 * Retail: 1092 bytes; compiled: 1080 bytes.
 * Final coverage: us: 0/1; us2: 0/1; pal: catalogue absent.
 * Residual: 1080/1092 bytes. A full 64-byte joint matrix and 48-byte rotation output are
 * retained;83678 writes three rows and AB028 touches only their 3x3 components. Full
 * vector transfers use qcopy. The trajectory table has an unknown full extent, replacing
 * scalar-based out-of-object indexing. Float allocation, interpolation and copy
 * schedules remain different.
 * Reopen: Independent trajectory-table extent/layout and interpolation lifetime
 * evidence. Keep the canonical particle constructor with 12 GPR/two FP inputs and real
 * caller stack words at 0,8,0x10,0x18. Do not restore a scalar masquerading as the
 * table.
 */
#include "common.h"

typedef int Vector __attribute__((mode(TI)));
/* The trajectory table has at least the five observed entries; full extent unknown. */
extern float D_L02_001B0190[] __attribute__((sda));
extern float D_L02_001B01E4 __attribute__((sda));
extern float D_L02_001B01E8 __attribute__((sda));
extern float D_L02_001B01B8;
extern void func_0029FCC0(char *, int, char *);
extern void func_0029FC20(char *, int, char *);
extern void func_00283678(void *, void *);
extern void func_002AB028(void *);
extern float func_00283180(float);
extern void func_00282D30(void *, void *, float);
extern void func_00282F20(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_002AF1D0(char *, char *, int, int);
extern void func_002A10E8(char *);
extern void func_L02_003D5DF8(char *);
extern char *func_L02_003D5CF0(void *, void *, float);
extern int func_00283CF0(float);
extern void *func_0032C700(void *, int, int, int, int, int, int, int, int, int, int, int, float, float);
extern void func_002A8C28(char *, void *, int, int, float, float, float, int, int);

int func_L02_003D5748(char *self, int joint) {
    float origin[4] __attribute__((aligned(16)));
    float end[4] __attribute__((aligned(16)));
    float direction[4] __attribute__((aligned(16)));
    float impact[4] __attribute__((aligned(16)));
    float rotation[12] __attribute__((aligned(16)));
    float matrix[16] __attribute__((aligned(16)));
    float delta[4] __attribute__((aligned(16)));
    float offset[4] __attribute__((aligned(16)));
    char *state = *(char **)(self + 0x68);
    char **slots;
    float travel;
    float outbound;
    float inbound;
    float phase;
    float time;
    int i;
    int rounded;
    int timer;
    func_0029FCC0(self, joint, (char *)origin);
    func_0029FC20(self, joint, (char *)matrix);
    func_00283678(rotation, matrix);
    func_002AB028(rotation);
    qcopy(direction, rotation);
    travel = (origin[2] - D_L02_001B01B8) / func_00283180(1.15f);
    func_00282D30(impact, direction, travel);
    func_00282CC0(impact, impact, origin);
    travel -= 5.3f;
    outbound = travel * 0.8571428f;
    inbound = travel * 0.6666666f;
    slots = (char **)(state + 0x2A0);
    for (i = 0; i < 5; i++, slots++) {
        if (*slots) {
            func_002AF1D0(self, *slots, joint, joint == 1 ? 6 : 0);
            time = (float)*(short *)(state + 0x31E);
            if (time < outbound)
                phase = (time - outbound * (4.0f - (float)i) * 0.25f) * 1.1666667f;
            else if (time < outbound + 5.0f)
                phase = outbound * ((float)i * 0.2916667f);
            else
                phase = outbound * ((float)i * 0.2916667f) - (time - (outbound + 5.0f)) * 1.5000001f;
            if (phase < 0.0f) phase = 0.0f;
            func_00282F20(delta, direction, phase + D_L02_001B0190[i]);
            func_00282CC0(*slots + 0x10, origin, delta);
            func_002A10E8(*slots);
            if (*(char **)(state + 0x300)) func_L02_003D5DF8(*(char **)(state + 0x300));
            func_00282F20(offset, rotation + 8, D_L02_001B01E8);
            func_00282CC0(origin, *(char **)(state + 0x2A0) + 0x10, offset);
            qcopy(end, *(char **)(state + 0x2B0) + 0x10);
            func_00282F20(offset, rotation + 4, D_L02_001B01E4);
            func_00282CC0(origin, origin, offset);
            *(char **)(state + 0x300) = func_L02_003D5CF0(origin, end, 0.2f);
        }
    }
    timer = (short)(*(unsigned short *)(state + 0x31E) + 1);
    *(short *)(state + 0x31E) = timer;
    rounded = func_00283CF0(outbound);
    if (timer > func_00283CF0(inbound) + rounded + 7) return 2;
    timer = *(short *)(state + 0x31E);
    if (timer > func_00283CF0(outbound) + 6) return 1;
    timer = *(short *)(state + 0x31E);
    if (timer > func_00283CF0(outbound) + 1 && *(short *)(state + 0x320) == 0) {
        func_0032C700(impact, 0, 25, 20, 20, 20, 45, 0, 1, 0, 0, 0, 0.5f, 20.0f);
        func_002A8C28(self, impact, 0x10001, 0, 0.5f, (float)*(unsigned char *)(state + 0x35), 1.0f, 1, 0);
        *(short *)(state + 0x320) = 1;
    }
    return 0;
}
