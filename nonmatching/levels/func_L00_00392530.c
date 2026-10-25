/* RAC1-helper follow-up, 2026-10-25: NOT MATCHING; no exact-C credit.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * Fresh local measurement: 2568/2644 bytes, 0/27 US placements, frame 0x80.
 * Change: Approved qcopy expresses the start/end transfers and qzero the measured local clear. Both target paths, ammunition/statistics, light and sound behavior remain present.
 * Residual: No-split-addresses hit GNU as assertion tc-mips.c:11867 and was removed. Branch/global base/register scheduling remains different.
 * Reopen: Reopen with measured dual-target field/source lifetime evidence or an independently controlled assembler fix.
 * Earlier measurements/screens below are historical; they do not prohibit
 * the currently approved shared transfer helpers or establish linked equality.
 */
/* Nonmatching: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier. us: func_L00_00392530: 0 of 27 places match (src/levels/shared/L00_00392530.c); us2: func_L00_00392530: 0 of 27 places match (src/levels/shared/L00_00392530.c); pal: absent. Manual reconstruction2564/2644 frame0x80. Full two-target acquisition/ammo/statistics/light/sound behavior retained. Verified AFFD8threeGPR and AB1F0oneactor/GPR32 value interpreted as record pointer. Scalar short timers and pointer targets truthful. Remaining globalbase sharing, branch order/register scheduling; reopen with original struct/expression layout. */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef union { Quad quad; float f[4]; } Vector;
typedef struct {
    Vector start, end;
    char *target;
    float length;
    short targetAge, secondaryAge;
    int timer, light, fade;
    char *secondary;
    short ammoTimer, cooldown, targetReady, secondaryReady, targetTimer, secondaryTimer;
    int sound;
} DualBeamState;
extern char D_00189E20[] NOT_SDA, D_00138180[] NOT_SDA, D_00188660[] NOT_SDA;
extern float D_0025C64C NOT_SDA, D_0018A550[4][4] NOT_SDA;
extern u8 D_0013957A;
extern char D_L00_00262570[][0xE0];
extern float D_L00_001C6F40[8][8];
extern int D_L00_001AF130 __attribute__((sda)), D_L00_001B2748 __attribute__((sda));
extern u32 D_001A7390 __attribute__((sda)), D_001A79F0;
extern int func_L00_002D4040(int), func_L00_002D3F30(int, int), func_00282948(int *), func_00282978(short *);
extern void func_00273318(void *, u32, void *, int, int, int, float, float, float);
extern int func_00291308(void *, int, float, float), func_002E5CF8(int, int, char *), func_002E59B0(int, int);
extern float func_00283248(float, float), func_00283C80(float, float), func_00282E48(void *, void *), func_00283CE0(int);
extern void func_002AFFD8(char *, char *, int), func_00282D30(void *, void *, float), func_00282CC0(void *, void *, void *);
extern int func_002AB1F0(u8 *);
extern void func_0029FCC0(char *, int, char *), func_00283098(void *, void *, void *), func_00282F20(void *, void *, float);
extern void func_0030A188(char *), func_L00_00393148(char *), func_0030BA38(void *);
extern void func_L00_002E6EF8(void (*)(void *), void *), func_002E59F8(int);
extern void func_L00_002AF568(void), func_L00_002AF7D0(void), func_00291450(int);
/* Maintains two beam targets, their acquisition delays, ammunition and the light/sound state. */
void func_L00_00392530(char *actor) {
    Vector direction, offset, local;
    DualBeamState *beam = *(DualBeamState **)(actor + 0x68);
    char *player = D_00189E20, *input = D_00138180, *entry, *sound;
    int stopping = *(int *)(player + 0x1244) == 3;
    int active = 0, permitted = 1, ammo, limit;
    u32 stamp;
    float angle, desiredLength, fade;
    if ((*(u32 *)(input + 0x1A4) & *(u32 *)(player + 0x1230)) && !((u8 *)player)[0x22BC]) beam->length = 0.8f;
    D_0025C64C = 0.9f;
    ammo = func_L00_002D4040(-1);
    if (*(int *)(player + 0x2294) == 1) {
        if (!func_00282948((int *)(player + 0x2534))) permitted = 0;
        else func_00273318(actor, func_L00_002D4040(-1) ? 0x600FFF0F : 0x600000FF, 0, 31, -1, 4, 1, 0, 90);
    } else *(int *)(player + 0x2534) = 40;
    if (!(*(u32 *)(input + 0x1A0) & *(u32 *)(player + 0x1230)) || (u8)actor[0x20] == 4 || !(u8)actor[0x20] ||
        ((u8 *)player)[0x22BC] || *(int *)(player + 0x2294) == 0x6F || *(int *)(player + 0x1240) < 23 || !permitted) {
        beam->target = 0; goto clear_targets;
    }
    if (!beam->timer) {
        if (ammo < 1) {
            beam->target = 0; beam->secondary = 0;
            beam->targetReady = 0; beam->secondaryReady = 0; beam->targetTimer = 0; beam->secondaryTimer = 0;
        } else {
            if (func_00282978(&beam->ammoTimer)) {
                func_00282978(&beam->targetTimer); func_00282978(&beam->secondaryTimer);
                func_L00_002D3F30(-1, 1); beam->ammoTimer = 10;
            }
            if (beam->light == -1) beam->light = func_00291308(actor + 0x10, 0, 7.5f, 0);
            else if (beam->fade < 10) ++beam->fade;
            active = 1;
            if (beam->target) {
                angle = func_00283248(*(float *)(beam->target + 0x10) - *(float *)(player + 0x80), *(float *)(beam->target + 0x14) - *(float *)(player + 0x84));
                angle = func_00283C80(*(float *)(player + 0x98), angle);
                if (angle > 2.0943f || !((u8 *)beam->target)[0x31] || func_00282E48(beam->target + 0x10, player + 0x80) > 20) {
                    beam->target = 0; beam->targetReady = 0;
                }
            }
            if (beam->secondary) {
                angle = func_00283248(*(float *)(beam->secondary + 0x10) - *(float *)(player + 0x80), *(float *)(beam->secondary + 0x14) - *(float *)(player + 0x84));
                angle = func_00283C80(*(float *)(player + 0x98), angle);
                if (angle > 2.0943f || !((u8 *)beam->secondary)[0x31] || func_00282E48(beam->secondary + 0x10, player + 0x80) > 20) {
                    beam->secondary = 0; beam->secondaryReady = 0;
                }
            }
            func_002AFFD8((char *)beam, (char *)&direction, 1);
            qcopy(&beam->start, actor + 0x10);
            func_00282D30(&offset, &direction, 0.7f);
            func_00282CC0(&beam->start, &beam->start, &offset);
            qcopy(&beam->end, &beam->start);
            if (!beam->target || !beam->targetReady) beam->targetAge = 0;
            else {
                ++beam->targetAge;
                entry = (char *)func_002AB1F0((u8 *)beam->target); limit = 50;
                if (entry && *(short *)(entry + 4) == 1) limit = 5;
                if (beam->targetAge >= limit) { beam->target = 0; beam->targetReady = 0; }
            }
            if (!beam->secondary || !beam->secondaryReady) beam->secondaryAge = 0;
            else {
                ++beam->secondaryAge;
                entry = (char *)func_002AB1F0((u8 *)beam->secondary); limit = 50;
                if (entry && *(short *)(entry + 4) == 1) limit = 5;
                if (beam->secondaryAge >= limit) { beam->secondary = 0; beam->secondaryReady = 0; }
            }
            desiredLength = 12;
            if (D_L00_00262570[D_0013957A][4]) desiredLength = 18;
            beam->length += (desiredLength - beam->length) * 0.07f;
            if (*(short *)(player + 0x24EC) == 1) {
                func_0029FCC0(actor, 0, (char *)&beam->start);
                local.f[0] = 0; local.f[2] = 0; local.f[1] = -beam->length;
                func_00283098(&local, &local, actor + 0xC0);
                func_00282CC0(&beam->end, &beam->start, &local);
            } else {
                func_0029FCC0(actor, 0, (char *)&beam->start);
                func_00282F20(&beam->end, D_0018A550, beam->length);
                func_00282CC0(&beam->end, &beam->start, &beam->end);
            }
            func_0030A188(actor); func_L00_00393148(actor);
            func_L00_002E6EF8(func_0030BA38, actor);
        }
    }
    goto update_sound;
clear_targets:
    beam->secondary = 0; beam->targetReady = 0; beam->secondaryReady = 0;
update_sound:
    if (active) {
        if (!func_002E59B0((int)actor, beam->sound)) beam->sound = func_002E5CF8(4, 4, actor);
    } else {
        D_L00_001AF130 = 1;
        if (beam->fade > 0) --beam->fade;
        sound = D_00188660 + beam->sound * 0x70;
        if (beam->sound != -1 && *(char **)(sound + 0x88) == actor && (u8)sound[0x74]) func_002E59F8(beam->sound);
        beam->sound = -1;
    }
    if (!beam->target || (u8)beam->target[0x20] == 0xFE || (u8)beam->target[0x20] == 0xFD || !(*(u16 *)(beam->target + 0x34) & 0x1000)) beam->targetReady = 1;
    if (!beam->secondary || (u8)beam->secondary[0x20] == 0xFE || (u8)beam->secondary[0x20] == 0xFD || !(*(u16 *)(beam->secondary + 0x34) & 0x1000)) beam->secondaryReady = 1;
    switch ((u8)actor[0x20]) {
    case 0:
        beam->timer = 16; beam->light = func_00291308(&beam->start, 0, 0, 0);
        D_L00_001AF130 = 1; actor[0x20] = 1; beam->cooldown = 20; beam->sound = -1;
        beam->secondary = 0; beam->target = 0; beam->targetReady = 0; beam->secondaryReady = 0;
        beam->secondaryTimer = 0; beam->targetTimer = 0; D_L00_001B2748 = 10;
        break;
    case 1:
        func_00282948(&beam->timer);
        if (active) { func_L00_002AF568(); actor[0x20] = 3; }
        if ((*(u32 *)(input + 0x1A4) & *(u32 *)(player + 0x1230)) && !((u8 *)player)[0x22BC]) {
            if (!active) {
                beam->target = 0; beam->secondary = 0; beam->targetReady = 0; beam->secondaryReady = 0;
                actor[0x20] = 1; func_002E5CF8(0, 0, actor); func_L00_002AF7D0();
            } else {
                stamp = D_001A7390;
                if (*(u16 *)(player + 0x2618) != 0xFFFF) { ++*(u16 *)(player + 0x2618); stamp = D_001A7390; }
                if (*(u32 *)(player + 0x261C) < stamp) *(u32 *)(player + 0x261C) = stamp;
                *(u32 *)(player + 0x2620) |= (1u << (D_001A79F0 & 31)) | 0x80000000;
                func_L00_002AF568(); actor[0x20] = 3;
            }
        }
        break;
    case 3:
        if (!(*(u32 *)(input + 0x1A8) & *(u32 *)(player + 0x1230)) && active && !((u8 *)player)[0x22BC]) break;
        if (*(int *)(player + 0x1D8) > 70 && *(u16 *)(player + 0x2A68) != 0xFFFF) ++*(u16 *)(player + 0x2A68);
        if (*(u32 *)(player + 0x2A6C) < D_001A7390) *(u32 *)(player + 0x2A6C) = D_001A7390;
        *(u32 *)(player + 0x2A70) |= (1u << (D_001A79F0 & 31)) | 0x80000000;
        if (*(int *)(player + 0x1D8) < 30) ++((u8 *)player)[0x22C5]; else player[0x22C5] = 0;
        beam->target = 0; beam->secondary = 0; beam->targetReady = 0; beam->secondaryReady = 0; beam->length = 0;
        func_L00_002AF7D0(); actor[0x20] = 1;
        break;
    case 2: case 4: case 5: default: break;
    }
    if (beam->light != -1) {
        qzero(&direction); direction.f[0] = 2; direction.f[2] = 2;
        func_00283098(&direction, &direction, D_0018A550);
        D_L00_001C6F40[beam->light][4] = *(float *)(player + 0x80) + direction.f[0];
        D_L00_001C6F40[beam->light][5] = *(float *)(player + 0x84) + direction.f[1];
        D_L00_001C6F40[beam->light][6] = *(float *)(player + 0x88) + direction.f[2];
        D_L00_001C6F40[beam->light][7] = 7.5f;
        fade = func_00283CE0(beam->fade) * 0.1f;
        D_L00_001C6F40[beam->light][2] = fade;
        D_L00_001C6F40[beam->light][1] = fade * 0.7f;
        D_L00_001C6F40[beam->light][0] = D_L00_001C6F40[beam->light][1];
        if (!stopping) return;
        if (beam->light != -1) { func_00291450(beam->light); beam->light = -1; }
    }
    if (stopping && beam->light == -1) actor[0x20] = 4;
}

/* Historical screening only; superseded by the measured reconstruction above. */
/* func_L00_00392530 - 2644 bytes, 27 place(s), level 00_aranos_tutorial,
   retail at 0x00392530. Screened with tools/w10_screen.py: 42 call(s)
   [func_L00_002D4040@003925D0, func_00282948@003925EC,
   func_L00_002D4040@00392604, func_00273318@00392644,
   func_00282978@003926D0, func_00282978@003926E0, func_00282978@003926E8,
   func_L00_002D3F30@003926F4, func_00291308@0039272C,
   func_00283248@00392774, func_00283C80@00392780, func_00282E48@003927B8,
   func_00283248@00392804, func_00283C80@00392810, func_00282E48@0039284C,
   func_002AFFD8@00392880, func_00282D30@003928A4, func_00282CC0@003928B4,
   func_002AB1F0@003928E8, func_002AB1F0@00392944, func_0029FCC0@003929F0,
   func_00283098@00392A18, func_00282CC0@00392A28, func_0029FCC0@00392A3C,
   func_00282F20@00392A4C, func_00282CC0@00392A5C, func_0030A188@00392A64,
   func_L00_00393148@00392A6C, func_L00_002E6EF8@00392A7C,
   func_002E59F8@00392B0C, func_002E59B0@00392B1C, func_002E5CF8@00392B34,
   func_00291308@00392BEC, func_00282948@00392C38,
   func_L00_002AF568@00392C48, func_L00_002AF568@00392CE0,
   func_002E5CF8@00392D10, func_L00_002AF7D0@00392D18,
   func_L00_002AF7D0@00392DFC, func_00283098@00392E40,
   func_00283CE0@00392EC0, func_00291450@00392F30]; data addresses
   materialised [0x190000, 0x140000, 0x3f4c0000, 0x3f660000, 0x260000,
   0x600f0000, 0x60000000, 0x40060000, 0x40060000, 0x3f330000, 0x140000,
   0x140000, 0x260000, 0x3d8f0000, 0x390000, 0x190000, 0x2a0000, 0x190000,
   0x1a0000, 0x1a0000, 0x80000000, 0x1a0000, 0x1a0000, 0x80000000, 0x190000,
   0x1c0000, 0x3dcc0000, 0x3f330000]; float constants [0x3f800000,
   0x42b40000, 0x40f00000, 0x41a00000, 0x41a00000, 0x41400000, 0x41900000,
   0x190000, 0x40000000, 0x40f00000]; $gp-relative small data: yes   saves:
   -; callee-saved registers saved [-]; words plain C cannot emit [LQ/SQ
   7A220000@0x0358, LQ/SQ 7E420000@0x035c, LQ/SQ 7A420000@0x0390, LQ/SQ
   7C620000@0x0394, LQ/SQ 7FA00000@0x08ec]. Head: addiu $sp, $sp, -0x80 ;
   lui $v1, 0x19 ; sd $s3, 0x48($sp) ; lui $v0, 0x14 ; sd $s4, 0x50($sp) ;
   addiu $a3, $v1, -0x61E0. Not matched in this wave: the 128-bit copy needs
   an `lq`/`sq` pair; plain C reaches it only through a `mode(TI)` local,
   and this cc1 folds the destination offset into the `sq` where retail
   materialises the pointer first. What would unblock it: the exact source
   expression tree, so this cc1 picks the same registers in the same order. */
