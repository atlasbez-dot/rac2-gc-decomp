/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G16 -ffunction-sections -Wa,-G16 -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-por -fno-gcse.
 * Reported final C / retail: 1164 / 1168 bytes; size equality is not a match.
 * us: 0/1 placements; 1164/1168 bytes.
 * us2: 0/1 placements; 1164/1168 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: Frame 0x80 matches; cached state+0x140 and saved GPR choices differ. First1172, no-gcse1164; reopen with state-pointer lifetime evidence.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Manual reconstruction, 2026-10-23: NOT MATCHED. US 1164/1168 bytes,
 * 0/1 placements; profile: -O2 -ffunction-sections G16 asG16 qcopy/qcopy-barrier/zero-ti-por -fno-gcse.
 * Frame 0x80 matches; cached state+0x140 and saved GPR choices differ. First1172, no-gcse1164; reopen with state-pointer lifetime evidence.
 * Historical screening notes below are preserved; the current measured
 * residual replaces any earlier claim that lq/sq/por cannot be emitted. */
/* Historical screen/map retained privately. The current manual reconstruction and measured residual above supersede that screen; its extracted instruction, opcode and address lists establish neither matching nor handwritten-assembly status. */

#include "common.h"
typedef int ProjectileQuadword __attribute__((mode(TI)));
typedef struct {
    u8 reserved00[0x18];
    u8 *object;
    int polygon;
    float correction[4], point[4], normal[4];
} CollisionView;
extern int D_L20_001A8F00;
extern CollisionView D_L20_001C0400;
extern u8 *D_0018C0B0;
extern u8 D_00189E20[];
extern u8 D_L20_001B9E80[];
extern unsigned int D_L20_001B2AC8;
extern float D_L20_001B23F8 __attribute__((sda));
extern float D_L20_001B23FC __attribute__((sda));
extern float D_L20_001B2400 __attribute__((sda));
extern float D_L20_001B2404;
extern float D_L20_001B2408 __attribute__((sda));
extern float D_L20_001B2420 __attribute__((sda));
extern float D_L20_001B2430[4] __attribute__((sda));
extern void func_0029F338(void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern float func_00282DF0(void *), func_00282E20(void *);
extern int func_002761F8(void *, void *, int, void *, int);
extern void func_00282F20(void *, void *, float);
extern void func_00282F70(void *, void *, float);
extern int func_00277258(void *, int, void *, float);
extern void func_L20_0044A108(char *, char *);
extern float func_002A7878(float, float), func_002A78D8(float, float);
extern float func_002AA2E8(float *, float, float);
extern void func_002833F0(void *, void *);
extern void func_00283098(void *, void *, void *);
extern void func_002A9288(char *, float);
extern void func_00282C98(void *);
extern void func_00282DD8(void *, void *, void *);
extern void func_002ACE78(float *, float *, float);
extern void func_00283958(void *, void *);
extern void func_00283738(void *, void *, void *);
extern int func_00282948(int *);
extern void func_L20_0044A658(char *);
extern int func_002B3868(u8 *);
extern int func_002E5CF8(int, int, char *);
extern float func_L20_0044A8F0(char *);
extern void func_002A7750(u8 *, u8, int);
extern void func_002A7470(u8 *, int, int, int);
extern u8 *func_L20_004448A8(u8 *, u8 *);
extern int func_002A77E0(int);
extern float func_00283B98(float, float), func_00283180(float), func_00283198(float);
extern float func_002A89A8(void *, int, float);
extern void func_L20_0039C540(u8 *, void *, void *, float);
extern void func_L20_0044A838(char *);

/* Alternates between target selection and directed projectile bursts. */
void func_L20_0044A1C8(u8 *moby)
{
    float target[4] __attribute__((aligned(16)));
    float origin[4] __attribute__((aligned(16)));
    float velocity[4] __attribute__((aligned(16)));
    u8 *state = *(u8 **)(moby + 0x68);
    u8 *selected;
    float angle, radius, savedHeight, x;
    func_L20_0044A658((char *)moby);
    if (D_L20_001A8F00 == 2) { func_0029F338(moby); return; }
    switch (moby[0x20]) {
    case 2:
        if (func_002B3868(moby)) *(int *)(state + 0x1b8) = func_002E5CF8(0, 4, (char *)moby);
        *(int *)(*(u8 **)(moby + 0xb8) + 0x98) = 0;
        if (func_L20_0044A8F0((char *)moby) < 0.1f) func_002A7750(moby, 3, -1);
        *(int *)(*(u8 **)(moby + 0xb8) + 0x98) = *(int *)(*(u8 **)(*(u8 **)(moby + 0xb8) + 0x24) + 0x10);
        break;
    case 3:
        if (*(unsigned short *)(moby + 0x96) > 60) func_002A7750(moby, 4, -1);
        break;
    case 4:
        if (func_002B3868(moby)) {
            if (moby[0x43]) func_002A7470(moby, 0, 0, 15);
            selected = func_L20_004448A8(*(u8 **)(moby + 0xb8), moby);
            *(u8 **)(state + 0x1b0) = selected;
            if (func_002A77E0(2)) *(u8 **)(state + 0x1b0) = 0;
            selected = *(u8 **)(state + 0x1b0);
            if (selected) {
                *(u8 **)(state + 0x150) = selected;
                *(ProjectileQuadword *)(state + 0x140) = *(ProjectileQuadword *)(selected + 0x10);
            }
            angle = func_00283B98(*(float *)(D_L20_001B9E80 + 0x158), func_002A78D8(20.0f, 70.0f) * 0.017453294f);
            radius = func_002A7878(5.0f, 15.0f);
            savedHeight = *(float *)(state + 0x198);
            *(float *)(state + 0x190) = func_00283180(angle) * radius;
            *(float *)(state + 0x194) = func_00283198(angle) * radius;
            *(float *)(state + 0x198) = 0.0f;
            func_00282CC0(state + 0x190, state + 0x190, state + 0x140);
            if (*(float *)(D_00189E20 + 0x2d8) == 0.0f) *(float *)(state + 0x198) = savedHeight;
            else {
                *(float *)(D_00189E20 + 0x2d8) += func_002A7878(1.5f, 2.5f);
                *(float *)(state + 0x198) = *(float *)(D_00189E20 + 0x2d8);
            }
        }
        if (!(func_L20_0044A8F0((char *)moby) >= 0.1f)) func_002A7750(moby, 5, -1);
        break;
    case 5:
        if (func_002B3868(moby)) {
            if (moby[0x43] != 1) func_002A7470(moby, 1, 0, 15);
            if (!*(int *)(state + 0x1b0)) *(float *)(state + 0x1b4) = -func_002A7878(4.0f, 6.0f);
            else *(float *)(state + 0x1b4) = 0.0f;
            func_002E5CF8(1, 0, (char *)moby);
        }
        if ((D_L20_001B2AC8 & 15) == (((unsigned int)moby >> 8) & 15)) {
            func_00282CF0(target, state + 0x140, moby + 0x10);
            target[2] = 0.0f;
            x = func_00282E20(target) + *(float *)(state + 0x1b4);
            if (x < 1.0f) x = 1.0f;
            func_00282F70(target, target, x);
            func_00282CC0(target, target, moby + 0x10);
            target[2] = func_002A89A8(target, 0, 0.5f);
            if (target[2] == 0.0f) target[2] = *(float *)(state + 0x148);
            func_00283098(origin, D_L20_001B2430, moby + 0xc0);
            func_00282CC0(origin, origin, moby + 0x10);
            func_00282CF0(velocity, target, origin);
            func_00282F20(velocity, velocity, D_L20_001B2420 * 0.016666668f);
            func_L20_0039C540(moby, origin, velocity, (float)state[0x34]);
            func_002AA2E8((float *)(state + 0x1b4), 4.0f, 1.0f);
        }
        if (*(float *)(state + 0x1b4) >= 4.0f) func_002A7750(moby, 4, -1);
        break;
    }
    func_L20_0044A838((char *)moby);
}
