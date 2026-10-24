/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-por.
 * Reported final C / retail: 2816 / 4444 bytes; size equality is not a match.
 * us: 0/1 placements; 2816/4444 bytes.
 * us2: absent from catalogue (not a match).
 * pal: absent from catalogue (not a match).
 * Residual: Full five-case update semantics with common aiming and bone loops; retail expands the firing paths. Reopen with separate case lifetimes; no helper was invented.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Manual reconstruction, 2026-10-23: NOT MATCHED. US 2816/4444 bytes,
 * 0/1 placements; profile: -O2 -ffunction-sections G8 qcopy/qcopy-barrier/zero-ti-por.
 * Full five-case update semantics with common aiming and bone loops; retail expands the firing paths. Reopen with separate case lifetimes; no helper was invented.
 * Historical screening notes below are preserved; the current measured
 * residual replaces any earlier claim that lq/sq/por cannot be emitted. */
#include "common.h"
/* Observed assembly interfaces; ignored results remain unqualified. The path
 * call supplies a second GPR and two FP values although its callee overwrites
 * those registers before use. They are retained at this call boundary. */
extern int func_L16_00404A60(void *), func_002B3890(void *);
extern int func_002A7820(int, int), func_00282978(short *);
extern void func_002A7470(void *, int, int, int), func_002A7750(void *, u8, int);
extern void func_002A6C58(void *, int, int), func_002A7A00(void *, float, float);
extern float func_00282C48(float), func_002A78D8(float, float), func_002A7878(float, float);
extern void func_00282CC0(void *, void *, void *), func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern u8 *func_00273730(void *, int, int, int, void *, void *, void *, int, float, float);
extern void func_00310C88(void *), func_002AB650(void *), func_0029F338(void *);
extern int func_002E5CF8(int, int, void *);
extern void func_L16_00406080(void *, int, int, int, int, int, int, int, float, int, int);
extern int func_L01_00322288(int, float), func_L09_00329028(char *, int);
extern int func_L16_00404E40(void *, void *, float, float);
extern float func_00283248(float, float), func_00282E80(void *, void *), func_00283C80(float, float);
extern void func_002AAA00(float *, float *, int, float, float, float, float);
extern int func_002AEB60(void *, float);
extern void func_0029FCC0(char *, int, char *);
extern void func_L16_00405488(void *, void *, void *, int, float);
extern int func_002761F8(void *, void *, int, void *, void *);
extern void func_002AA548(float *, float *, float, float, float, float);
extern void func_L16_00404F50(void *);
extern float D_00189EA0[4], D_00189F00[4], D_L16_001A8F20[4];
extern u8 *D_0018C0B0, *D_L16_001BFF58;
extern int D_L16_001B9B48, D_L16_001B9B28, D_L16_001B9B2C;
extern float D_L16_001B9B40, D_L16_001B9B20;

void func_L16_00403900(u8 *moby)
{
    u8 *state = *(u8 **)(moby + 0x68);
    float position[4] __attribute__((aligned(16)));
    float aim[4] __attribute__((aligned(16)));
    u8 *child;
    int i, attack, collide;
    float angle, pitch;
    if (func_L16_00404A60(moby)) goto destroy;
    switch (moby[0x95]) {
    case 0:
        if (func_002B3890(moby)) *(short *)(state + 0x25e) = func_002A7820(0, 30);
        if (*(int *)(state + 0x260) == 1) {
            if (moby[0x43] != 3) func_002A7470(moby, 3, 0, 10);
            func_002A7750(moby, 5, 2);
            if (*(int *)(state + 0x288) || *(int *)(state + 0x2ac)) {
                if (moby[0x43]) func_002A7470(moby, 0, 0, 10);
                func_002A7750(moby, 4, 2);
            }
            if (*(int *)(state + 0x294) != -1) {
                func_002A7750(moby, 3, 2);
                if (!*(int *)(state + 0x2a8) || *(int *)(state + 0x2ac))
                    if (moby[0x43]) func_002A7470(moby, 0, 0, 10);
            }
        } else if (*(int *)(state + 0x264) && func_00282978((short *)(state + 0x25e))) {
            func_002A7750(moby, 2, 1);
            *(int *)(state + 0x264) = 0;
            if (*(int *)(state + 0x258) < 300)
                *(int *)(state + 0x258) = func_002A7820(480, 600);
        }
        break;
    case 1:
        if (*(int *)(state + 0x260) == 1 || *(int *)(state + 0x2b4) == 1)
            func_002A7750(moby, 5, 2);
        break;
    case 2:
        if (*(int *)(state + 0x260) == 1) break;
        if (*(int *)(state + 0x2b4) != 1 && moby[0x20] != 4 && moby[0x20] != 3) {
            func_002A7750(moby, 1, 0);
            if (moby[0x43]) func_002A7470(moby, 0, 0, 10);
            *(int *)(state + 0x258) = func_002A7820(580, 600);
        }
        break;
    case 3:
        if (*(float *)(state + 0x20) <= 0.0f) {
            func_002A6C58(moby, 0, 3);
            for (i = 0; i < 5; i++) {
                func_002A7A00(position, 0.13333334f, 0.20000002f);
                position[2] = func_00282C48(position[2]);
                position[2] *= 2.5f;
                func_00282CC0(position, position, D_L16_001A8F20);
                child = func_00273730(moby, 1, *(short *)(moby + 0xaa), i,
                    moby + 0x10, moby + 0xf0, position, 255, 30.0f, 15.0f);
                *(void (**)(void *))(child + 0x64) = func_00310C88;
            }
            func_002E5CF8(0, 0, moby);
            func_L16_00406080(moby + 0x10, 0, 15, 10, 10, 10, 15, 1, 2.0f, 1, 1);
            func_L16_00406080(moby + 0x10, 0, 15, 10, 10, 10, 15, 1, 1.0f, 1, 1);
            D_L16_001B9B40 = 0.1f;
            D_L16_001B9B48 = 90;
            D_L16_001B9B20 = 0.2f;
            D_L16_001B9B28 = 60;
            D_L16_001B9B2C = 0;
            func_0029F338(*(void **)(state + 0x274));
            position[0] = func_002A78D8(0.5f, 4.0f) * 0.016666668f;
            position[1] = func_002A78D8(0.0f, 4.0f) * 0.016666668f;
            position[2] = func_002A7878(7.0f, 9.0f) * 0.016666668f;
            position[2] = func_00282C48(position[2]);
            position[2] += position[2];
            func_00282CC0(position, position, D_L16_001A8F20);
            child = func_00273730(moby, 3, 0xecb, 0, moby + 0x10,
                moby + 0xf0, position, 255, 180.0f, 25.0f);
            func_002AB650(child);
            goto destroy;
        }
        if (!(moby[0x60] & 2)) break;
        *(int *)(state + 0x2b8) = 0;
        *(short *)(state + 0x25c) = 0;
        if (*(int *)(state + 0x260) == 1) {
            if (moby[0x43] != 3) func_002A7470(moby, 3, 0, 10);
            func_002A7750(moby, 5, 2);
            if (*(int *)(state + 0x298) != -1) func_002A7750(moby, 6, -1);
        } else {
            func_002A7750(moby, 2, 1);
            if (moby[0x43]) func_002A7470(moby, 0, 0, 10);
            *(int *)(state + 0x258) = func_002A7820(580, 600);
        }
        if (*(int *)(state + 0x2ac)) {
            func_002A7750(moby, 4, 2);
            if (moby[0x43]) func_002A7470(moby, 0, 0, 10);
        }
        break;
    }
    attack = moby[0x20];
    switch (attack) {
    case 3:
        if (!*(int *)(state + 0x2ac))
            func_L01_00322288((int)moby, func_00283248(D_00189EA0[0] - *(float *)(moby + 0x10),
                D_00189EA0[1] - *(float *)(moby + 0x14)));
        if (func_L16_00404E40(moby, moby + 0x10, 0.0f, 0.0f)) {
            if (*(int *)(state + 0x298) == -1) func_002A7750(moby, 5, -1);
            else func_002A7750(moby, 6, -1);
            if (moby[0x43] != 3) func_002A7470(moby, 3, 0, 10);
            if (*(int *)(state + 0x288) || *(int *)(state + 0x2ac)) {
                if (moby[0x43]) func_002A7470(moby, 0, 0, 10);
                func_002A7750(moby, 4, 2);
                *(float *)(state + 0x28c) = *(float *)(moby + 0x18) + 260.0f;
            }
        }
        if (!*(int *)(state + 0x2ac)) {
            pitch = func_00283248(func_00282E80(moby + 0x10, D_0018C0B0 + 0x10),
                *(float *)(D_0018C0B0 + 0x18) - *(float *)(moby + 0x18));
            func_002AAA00((float *)(moby + 0xf4), (float *)(state + 0x270), 0,
                -pitch, 0.00349065894f, 0.00349065894f, 0.20943955f);
        }
        collide = 0;
        goto shoot;
    case 4:
        func_002AA548((float *)(moby + 0x18), (float *)(state + 0x290),
            *(float *)(state + 0x28c), 0.0125f, 0.0027777778f, 0.06666667f);
        if (*(float *)(state + 0x28c) - *(float *)(moby + 0x18) >= 0.3f ||
            *(int *)(state + 0x2ac)) break;
        if (moby[0x43] != 3) func_002A7470(moby, 3, 0, 10);
        func_002A7750(moby, 5, -1);
        if (*(int *)(state + 0x298) != -1) func_002A7750(moby, 6, -1);
        break;
    case 5:
    case 6:
    case 7:
        func_L01_00322288((int)moby, func_00283248(D_00189EA0[0] - *(float *)(moby + 0x10),
            D_00189EA0[1] - *(float *)(moby + 0x14)));
        if (attack == 6) {
            if (func_L09_00329028((char *)moby, *(int *)(state + 0x298)) &&
                *(int *)(state + 0x29c) != -1) func_002A7750(moby, 7, -1);
        } else if (attack == 7) {
            if (func_L09_00329028((char *)moby, *(int *)(state + 0x29c)) &&
                *(int *)(state + 0x298) != -1) func_002A7750(moby, 6, -1);
        }
        pitch = func_00283248(func_00282E80(moby + 0x10, D_0018C0B0 + 0x10),
            *(float *)(D_0018C0B0 + 0x18) - *(float *)(moby + 0x18));
        func_002AAA00((float *)(moby + 0xf4), (float *)(state + 0x270), 0,
            -pitch, 0.00349065894f, 0.00349065894f, 0.20943955f);
        collide = 1;
shoot:
        if (!func_002AEB60(moby, 1.5f)) break;
        angle = func_00283248(D_00189EA0[0] - *(float *)(moby + 0x10),
            D_00189EA0[1] - *(float *)(moby + 0x14));
        if (!(func_00283C80(*(float *)(moby + 0xf8), angle) < 1.5707965f)) break;
        for (i = 2; i < 4; i++) {
            func_0029FCC0((char *)moby, i, (char *)position);
            func_00282CF0(aim, D_00189F00, position);
            func_00282F20(aim, aim, 0.833333373f);
            if (collide && func_002761F8(position, D_00189F00, 0, moby, 0) &&
                (!D_L16_001BFF58 || (D_L16_001BFF58 != D_0018C0B0 &&
                    *(short *)(D_L16_001BFF58 + 0xaa) == 0xebb))) continue;
            func_L16_00405488(moby, aim, position, 0, (float)state[0x34]);
        }
        break;
    }
    if ((unsigned int)moby[0x20] - 6 < 2) {
        if (moby[0x42] == 3) {
            if (++*(int *)(state + 0x2b8) > 240) {
                if (moby[0x43]) func_002A7470(moby, 0, 0, 10);
                *(int *)(state + 0x2b8) = 0;
            }
        } else if (!moby[0x42] && ++*(short *)(state + 0x25c) > 60) {
            if (moby[0x43] != 3) func_002A7470(moby, 3, 0, 10);
            *(short *)(state + 0x25c) = 0;
        }
    }
    func_L16_00404F50(moby);
    return;
destroy:
    func_0029F338(moby);
}
