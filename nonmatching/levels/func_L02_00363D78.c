/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G0 -ffunction-sections.
 * Prior worker coverage: US 0/1; US2 0/1; PAL 0/1.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/* Nonmatching: -O2 -G0 -ffunction-sections. us: func_L02_00363D78: 0 of 1 places match (src/levels/02_maktar_nebula/L02_00363D78.c); us2: func_L02_00363D78: 0 of 1 places match (src/levels/02_maktar_nebula/L02_00363D78.c); pal: func_L02_00363D78: 0 of 1 places match (src/levels/02_maktar_nebula/L02_00363D78.c). Four meaningful manual trials; best1056/1060, frame0x70. True32-byte particle union(color/phase),32-byte control record and64-byte matrix. RNG bit extraction, repeatedtrigcalls,64-bit renderstate verified. Remaining first-loop scheduling/registerroles and4-byte length difference. Reopen with original branch/local lifetime evidence. */
#include "common.h"
typedef struct {
    u8 kind, unknown01, textureMode, opacity;
    u32 color;
    float rotation;
    union { u32 color; u16 phase[2]; } initial;
    float position[3], scale;
} BackgroundParticle;
typedef struct {
    int unknown00;
    short emitted, unknown06, count;
    char unknown0A[0x12];
    BackgroundParticle *particle;
} BackgroundParticles;
extern BackgroundParticles *D_L02_001B3B20 __attribute__((sda));
extern float D_L02_001B3B50[4][4] __attribute__((sda));
extern void func_00283388(void *), func_002E3478(int), func_002E3940(int), func_L02_00364A18(void);
extern void func_002FC560(u32, u64);
extern int func_001163B0(void), func_002A77E0(int);
extern float func_002A7940(void), func_00283CE0(int), func_00283180(float), func_00283198(float), func_00282C48(float);
/* Initializes the background particle shell, animates its colors, and submits it. */
void func_L02_00363D78(void) {
    BackgroundParticle *p;
    u16 *phase;
    int i, shade, alpha;
    u32 random;
    float longitude, latitude;
    D_L02_001B3B20->emitted = 0;
    func_00283388(D_L02_001B3B50);
    func_002E3478(0); func_002E3940(0);
    func_002E3478(1); func_002E3940(1);
    if (!D_L02_001B3B20->count) {
        D_L02_001B3B20->count = 256;
        for (i = 0; i < D_L02_001B3B20->count; i++) {
            p = &D_L02_001B3B20->particle[i];
            if (i >= 246) {
                p->kind = 0;
                phase = p->initial.phase;
                phase[0] = func_001163B0() >> 16;
                phase[1] = func_001163B0() >> 16;
                p->scale = 0.16f; p->textureMode = 1; p->opacity = 72;
            } else {
                p->kind = 3; p->initial.phase[0] = func_002A77E0(256);
                p->textureMode = (func_001163B0() >> 16) & 1; p->opacity = 72;
                p->rotation = func_002A7940();
                p->scale = func_00283CE0(func_002A77E0(48) + 32) * 0.00390625f;
                longitude = func_002A7940(); latitude = func_002A7940();
                p->position[0] = func_00283180(longitude) * func_00283198(latitude) * 50.0f;
                p->position[1] = func_00283198(longitude) * func_00283198(latitude) * 50.0f;
                p->position[2] = func_00283180(latitude) * func_00283180(latitude) * 36.0f + 16.0f;
                shade = func_002A77E0(24); alpha = func_002A77E0(32) << 24;
                if ((func_001163B0() >> 16) & 1) p->initial.color = 0x30505050 + alpha + (shade << 16);
                else p->initial.color = (0x30505050 + alpha + (shade << 8)) | shade;
            }
        }
    }
    for (i = 0; i < D_L02_001B3B20->count; i++) {
        p = &D_L02_001B3B20->particle[i];
        if (!p->kind) {
            phase = p->initial.phase;
            ++phase[0]; ++phase[1];
            longitude = func_00283CE0((phase[0] & 0xFFF) - 0x800) * 0.0015339808f;
            latitude = func_00283CE0((phase[1] & 0xFFF) - 0x800) * 0.0015339808f;
            p->position[0] = func_00283180(longitude) * func_00283198(latitude) * 50.0f;
            p->position[1] = func_00283198(longitude) * func_00283198(latitude) * 50.0f;
            p->position[2] = func_00282C48(func_00283180(latitude)) * 50.0f;
            p->color = (phase[0] & 0x3F) < 8 ? 0x702020F0 : 0x202020F0;
        } else if (p->kind == 3) {
            random = (u32)func_001163B0() >> 16;
            p->color = p->initial.color + ((random & 0x1F00) << 10) - 0x202020 + ((random & 0x1F0) << 6) + ((random & 0x1F) << 2);
        }
    }
    func_L02_00364A18(); func_002FC560(0x42, 0x8000000044ULL);
    func_002E3478(2); func_002E3940(2);
    func_002E3478(3); func_002E3940(3);
}

/* Historical screening only; superseded by the measured reconstruction above. */
