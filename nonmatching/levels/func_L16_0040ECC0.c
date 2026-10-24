/* Retained boss update reconstruction, 2026-10-23.
 * -O2 -G8 -ffunction-sections -g -frac2-qcopy -frac2-qcopy-barrier
 * -frac2-zero-ti-por: 6444/6484 bytes, 0/1 US and 0/1 us2 placements.
 * This canonical function is absent from PAL. Retail and C both use a 0x90
 * frame and 169 named direct calls, but saved-register allocation differs at
 * +0x4 and control-flow, scalar allocation and mixed absolute/GP loads remain.
 * Four bounded trials covered ordinary C (6408 bytes), qualified copy/zero
 * scheduling (6420), separate turning-animation branches (6444), and a tied
 * keep-block-order profile (6444). No retained flag entry is needed in src/.
 * The partial private-state layout, 64-byte matrix/vector union and 16-byte
 * velocity vector reflect observed storage. Retail-qualified live inputs are
 * preserved, including initial a0, sound-owner a2, the f12 particle parameter,
 * and the ballistic helper's two FP inputs, optional output and f0 result.
 * The transition wrapper's third formal is a verified signed frame duration;
 * the matching helper's declaration is repaired separately in its existing TU.
 * Discarded return types of assembly-only effect helpers are not fully known.
 * Reopen with evidence for original state-variable/control-flow lifetimes and
 * shared-global addressing. Do not use register pins, fake aliases or padding.
 */

#include "common.h"

typedef int BossQuadword __attribute__((mode(TI)));

/* Measured partial view of the boss's private record, through offset 0x36f. */
typedef struct {
    u8 reserved00[0x20];
    float health;
    short maximumHealth;
    u8 reserved26[15];
    u8 power;
    u8 reserved36[0x142];
    int entryArea;
    u8 reserved17c[0x18];
    int exitArea;
    u8 reserved198[0x24];
    int introStarted;
    u8 reserved1c0[0x30];
    u8 *body;
    u8 reserved1f4[12];
    float destination[4];
    float lastPlayer[4];
    u8 reserved220[0x14];
    float turnVelocity;
    u8 *arms[2];
    int activeArm;
    int fired;
    int reserved248;
    u8 *target;
    float aimTime;
    float aimBlend;
    int reserved258;
    int aimTimeout;
    int reserved260;
    float floorHeight;
    float verticalSpeed;
    int bodyMode;
    int resumeState;
    int resumeArgument;
    u8 reserved278[0xa8];
    u8 taunted;
    u8 reserved321[0x2f];
    int suppressSpeech;
    int reserved354[2];
    int fireTimer;
    u8 *projectile;
    short leftUsed;
    short rightUsed;
    int attackSound;
    int bodySound;
} SnivelakBossState;

/* The same work area holds a bone matrix or two temporary vectors in disjoint states. */
typedef union {
    float bone[16];
    struct { float position[4], offset[4]; } vectors;
} BossWork;

typedef struct {
    u8 prefix[0x30];
    int field30, field34, field38, field3c, field40, field44;
} BarlowUtilityQueueView;

extern float D_00189EA0[4], D_00189EF0[4];
extern u8 D_0013963B;
extern int D_0018C0B4, D_00189FD8;
extern u8 *D_0018C2BC;
extern u8 D_00188660[];
extern BarlowUtilityQueueView D_L16_001BFD00;
extern int D_L16_001A8F00 __attribute__((sda));
extern u8 *D_L16_001B16C0 __attribute__((sda));
extern float D_L16_001B16E4 __attribute__((sda));
extern float D_L16_001B16E8 __attribute__((sda));
extern float D_L16_001B16EC __attribute__((sda));
extern float D_L16_001B16F0 __attribute__((sda));
extern float D_L16_001B16F4 __attribute__((sda));
extern float D_L16_001B16F8 __attribute__((sda));
extern unsigned int D_L16_001B2648 __attribute__((sda));
extern float D_L16_001B2564 __attribute__((sda));
extern float D_L16_001B9B00[4];

/* Current C interfaces and retail-observed register banks for assembly callees. */
extern void func_L16_00410618(u8 *);
extern int func_002ACBC8(void *, int);
extern int func_00288AA0(u8 *, int);
extern int func_00288BE8(BarlowUtilityQueueView *);
extern void func_002F5CB8(int, int);
extern int func_002F5D10(void);
extern void func_L16_00412D48(u8 *);
extern void func_L16_00412E70(u8 *);
extern void func_002A7750(u8 *, u8, int);
extern int func_002B3868(u8 *);
extern void func_L16_004116C8(u8 *, int, int, float);
extern int func_002A77E0(int);
extern int func_002A7820(int, int);
extern float func_L02_002F21C0(void *, void *);
extern void func_L16_00412C58(u8 *, int, int);
extern void func_L16_00410CC0(u8 *, void *);
extern void func_L16_004110D0(u8 *, float);
extern float func_00282E80(void *, void *);
extern float func_0029F530(char *);
extern float func_00282C48(float);
extern int func_002E5CF8(int, int, char *);
extern int func_002E5DA0(int, int, char *, int);
extern void func_002E59F8(int);
extern void func_L16_00412BA8(u8 *, int);
extern void func_L16_00411B40(u8 *);
extern float func_00283248(float, float);
extern float func_00283C80(float, float);
extern float func_00283BE0(float, float);
extern void func_002AAA00(float *, float *, int, float, float, float, float);
extern int func_00282948(int *);
extern void func_L16_00411ED0(u8 *);
extern int func_L00_0035F5A0(int, int, int);
extern void func_L16_00411900(u8 *);
extern void func_L16_00410E40(u8 *, float, float);
extern void func_L16_00410B88(u8 *);
extern void func_002A7470(u8 *, int, int, int);
extern float func_002AA2E8(float *, float, float);
extern void func_L00_002E6CF0(void (*)(void *), void *);
extern void func_L16_00412560(void *);
extern void func_002A8C28(u8 *, void *, int, int, int, int, float, float, float);
extern u8 *func_L16_004130B0(u8 *, int);
extern void func_L16_00411D00(u8 *);
extern void func_0029FC20(char *, int, char *);
extern int func_L16_00413638(u8 *);
extern void func_L16_00413690(u8 *, u8 *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern float func_L00_0031CDD0(void *, void *, float *, float, float);
extern void func_L16_00413700(u8 *, void *, float);
extern float func_002A78D8(float, float), func_002A7878(float, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_0032DA58(u8 *, void *, void *, float);
extern void func_L16_002D2D10(int, float, float);
extern void func_L16_00411F80(u8 *, int);
extern void func_L16_00411480(u8 *);
extern void func_L16_00411600(u8 *);

/* Advances the boss's arena, animation, aiming and projectile phases. */
void func_L16_0040ECC0(u8 *moby)
{
    SnivelakBossState *state = *(SnivelakBossState **)(moby + 0x68);
    BossWork work;
    float velocity[4] __attribute__((aligned(16)));
    float angle, distance, frame;
    int next, sound;
    func_L16_00410618(moby);
    if (!moby || moby[0x20] == 254 || moby[0x20] == 253) return;

    switch (moby[0x95]) {
    case 0:
        if (func_002ACBC8(D_00189EA0, state->entryArea) ||
            (func_002ACBC8(D_00189EA0, state->exitArea) && D_0013963B == 1)) {
            if (!D_0013963B) {
                if (func_00288AA0((u8 *)&D_L16_001BFD00, 132)) {
                    func_00288BE8(&D_L16_001BFD00);
                    func_002F5CB8((int)func_L16_00412D48, (int)moby);
                    D_0013963B = 1;
                    state->introStarted = 1;
                }
            } else if (!func_002F5D10()) {
                func_L16_00412D48(moby);
            }
        } else if ((*(unsigned short *)(moby + 0x34) & 1) && D_00189EA0[0] >= 610.0f) {
            *(unsigned short *)(moby + 0x34) = (*(unsigned short *)(moby + 0x34) & 0xffbe) | 0x1000;
            *(int *)(moby + 0x98) = *(int *)(*(u8 **)(moby + 0x24) + 0x10);
            if (state->body) {
                *(unsigned short *)(state->body + 0x34) &= 0xffbe;
                *(unsigned short *)(state->body + 0x34) |= 0x1000;
                *(int *)(state->body + 0x98) = *(int *)(*(u8 **)(state->body + 0x24) + 0x10);
            }
            if (state->arms[0]) {
                *(unsigned short *)(state->arms[0] + 0x34) &= 0xffbe;
                *(unsigned short *)(state->arms[0] + 0x34) |= 0x1000;
                *(int *)(state->arms[0] + 0x98) = *(int *)(*(u8 **)(state->arms[0] + 0x24) + 0x10);
            }
            if (state->arms[1]) {
                *(unsigned short *)(state->arms[1] + 0x34) &= 0xffbe;
                *(unsigned short *)(state->arms[1] + 0x34) |= 0x1000;
                *(int *)(state->arms[1] + 0x98) = *(int *)(*(u8 **)(state->arms[1] + 0x24) + 0x10);
            }
        }
        break;
    case 1:
        if (D_L16_001B16C0) {
            state->target = D_L16_001B16C0;
            func_002A7750(moby, 7, 2);
        }
        break;
    case 2:
        if (!D_L16_001B16C0) func_002A7750(moby, 2, 1);
        break;
    }
    if (D_L16_001A8F00 == 2) return;

    switch (moby[0x20]) {
    case 2:
        if (func_002B3868(moby)) {
            func_L16_004116C8(moby, 10, 15, 3.0f);
            if (!func_002A77E0(1)) {
                if (func_L02_002F21C0(moby + 0x10, D_00189EA0) <= 1600.0f)
                    func_L16_00412C58(moby, 7, 11);
                else func_L16_00412C58(moby, 3, 6);
            }
        }
        func_L16_00410CC0(moby, D_00189EA0);
        func_L16_004110D0(moby, D_L16_001B16E4 * 0.016666668f);
        if (func_00282E80(moby + 0x10, state->destination) < 32.0f) {
            frame = func_0029F530((char *)moby);
            if (func_00282C48(frame - 5.0f) < 1.0f || func_00282C48(frame - 21.0f) < 1.0f) {
                func_002E5CF8(8, 0, (char *)moby);
                func_002A7750(moby, 3, -1);
            }
        }
        func_L16_00410B88(moby);
        break;
    case 3:
        if (func_002B3868(moby)) {
            func_002E5CF8(9, 0, (char *)moby);
            func_L16_004116C8(moby, 3, 15, 6.0f);
            if (!func_002A77E0(1)) func_L16_00412C58(moby, 12, 15);
        }
        if (!state->taunted && !state->suppressSpeech && !func_002A77E0(2) &&
            D_0018C0B4 == 22 && D_00189FD8 == 1 && D_0018C2BC &&
            *(short *)(D_0018C2BC + 0xaa) == 0xea7) {
            state->taunted = 1;
            func_L16_00412BA8(moby, 16);
        }
        if ((D_L16_001B2648 & 15) == (((unsigned int)moby >> 8) & 15)) func_L16_00411B40(moby);
        func_L16_00410CC0(moby, D_00189EA0);
        if (D_0018C0B4 == 129) next = 6;
        else if (func_00282E80(moby + 0x10, state->destination) > 48.0f) next = 2;
        else if (!(func_00282E80(moby + 0x10, D_00189EA0) >= 12.0f ||
                   func_00282C48(D_00189EA0[2] - state->floorHeight) >= 10.0f)) next = 5;
        else {
            angle = func_00283248(D_00189EA0[0] - *(float *)(moby + 0x10), D_00189EA0[1] - *(float *)(moby + 0x14));
            if (func_00283C80(*(float *)(moby + 0xf8), angle) <= 0.26179942f) {
                if (*(unsigned short *)(moby + 0x96) > 900) {
                    func_002A7750(moby, 11, -1);
                    state->target = 0;
                    *(BossQuadword *)state->lastPlayer = *(BossQuadword *)D_00189EF0;
                }
                func_L16_00410B88(moby);
                break;
            }
            next = 4;
        }
        func_002A7750(moby, next, -1);
        func_L16_00410B88(moby);
        break;
    case 4:
        if (func_002B3868(moby)) {
            angle = func_00283248(D_00189EA0[0] - *(float *)(moby + 0x10), D_00189EA0[1] - *(float *)(moby + 0x14));
            if (func_00283BE0(*(float *)(moby + 0xf8), angle) <= 0.0f)
                func_L16_004116C8(moby, 10, 30, 10.0f);
            else
                func_L16_004116C8(moby, 10, 30, 1.0f);
        }
        angle = func_00283248(D_00189EA0[0] - *(float *)(moby + 0x10), D_00189EA0[1] - *(float *)(moby + 0x14));
        func_002AAA00((float *)(moby + 0xf8), &state->turnVelocity, 0, angle, 0.00174532947f, 0.00174532947f, 0.104719773f);
        angle = func_00283248(D_00189EA0[0] - *(float *)(moby + 0x10), D_00189EA0[1] - *(float *)(moby + 0x14));
        if (!(func_00283C80(*(float *)(moby + 0xf8), angle) >= 0.087266475f) && moby[0x42] == moby[0x43]) func_002A7750(moby, 3, -1);
        break;
    case 5:
        if (func_002B3868(moby)) {
            state->verticalSpeed = 0.0f;
            state->bodyMode = 1;
            state->fireTimer = 30;
            func_L16_004116C8(moby, 0, 30, state->verticalSpeed);
        }
        angle = func_00283248(D_00189EA0[0] - *(float *)(moby + 0x10), D_00189EA0[1] - *(float *)(moby + 0x14));
        func_002AAA00((float *)(moby + 0xf8), &state->turnVelocity, 0, angle, 0.000872664736f, 0.000872664736f, 0.104719773f);
        if (func_00282948(&state->fireTimer)) {
            func_L16_00411ED0(moby);
            func_L00_0035F5A0(17, 0, (int)moby);
            state->fireTimer = func_002A7820(45, 75);
        }
        if (!(func_00282E80(moby + 0x10, D_00189EA0) <= 16.0f && func_00282C48(D_00189EA0[2] - state->floorHeight) <= 10.0f)) func_002A7750(moby, 2, -1);
        break;
    case 6:
        if (func_002B3868(moby)) {
            func_L16_004116C8(moby, 16, 30, 0.0f);
            *(float *)(moby + 0x48) = 0.666f;
        }
        if (state->body[0x60] & 2) func_002A7750(moby, 2, -1);
        break;
    case 7:
        if (func_002B3868(moby)) {
            func_L16_004116C8(moby, 10, 30, 6.0f);
            func_L16_00410E40(moby, D_L16_001B16EC, D_L16_001B16F0);
        }
        func_L16_004110D0(moby, D_L16_001B16E8 * 0.016666668f);
        if (func_00282E80(moby + 0x10, state->destination) < 1.0f) func_002A7750(moby, 8, -1);
        func_L16_00410B88(moby);
        break;
    case 8:
        if (func_002B3868(moby)) {
            func_L16_004116C8(moby, state->activeArm + 11, 20, 0.0f);
            if (!state->suppressSpeech) func_L16_00412C58(moby, 17, 23);
            state->fired = 0;
            *(float *)(moby + 0x48) = 1.0f;
        }
        angle = func_00283248(D_00189EA0[0] - *(float *)(moby + 0x10), D_00189EA0[1] - *(float *)(moby + 0x14));
        func_002AAA00((float *)(moby + 0xf8), &state->turnVelocity, 0, angle, 0.00349065894f, 0.00349065894f, 0.209439546f);
        if (!state->fired && state->body[0x42] == state->body[0x43] && !(func_0029F530((char *)state->body) < 13.0f)) {
            if (state->body[0x42] == 11) func_002E5CF8(7, 0, (char *)moby);
            func_L16_00411900(moby);
            state->fired = 1;
        } else if (func_0029F530((char *)state->body) > 20.0f) {
            func_L16_004116C8(moby, state->activeArm + 11, 20, 0.0f);
            state->fired = 0;
        }
        if (*(unsigned short *)(moby + 0x96) > 300) func_002A7750(moby, 7, -1);
        break;
    case 9:
        if (func_002B3868(moby)) func_L16_004116C8(moby, 16, 30, 6.0f);
        angle = func_00283248(D_00189EA0[0] - *(float *)(moby + 0x10), D_00189EA0[1] - *(float *)(moby + 0x14));
        func_002AAA00((float *)(moby + 0xf8), &state->turnVelocity, 0, angle, 0.00349065894f, 0.00349065894f, 0.209439546f);
        if (state->body[0x60] & 2) {
            if ((float)state->maximumHealth * 0.55f <= state->health) next = 10;
            else if (!func_002A77E0(2) && state->leftUsed && state->rightUsed) next = 10;
            else next = 13;
            func_002A7750(moby, next, -1);
        }
        break;
    case 10:
        if (func_002B3868(moby)) {
            func_L16_004116C8(moby, 10, 30, 6.0f);
            func_L16_00410CC0(moby, state->target + 0x10);
        }
        func_L16_004110D0(moby, D_L16_001B16E8 * 0.016666668f);
        if (!(func_00282E80(moby + 0x10, state->destination) >= 1.0f)) {
            next = func_00282C48(*(float *)(state->target + 0x18) - 120.0f) < 1.0f ? 12 : 11;
            func_002A7750(moby, next, -1);
        }
        break;
    case 11:
        if (func_002B3868(moby)) {
            if (moby[0x43] != 22) func_002A7470(moby, 22, 0, 20);
            func_002A7470(state->body, 3, 0, 30);
            state->aimTimeout = 120;
            state->aimTime = D_L16_001B16F4;
            state->aimBlend = 0.0f;
            state->verticalSpeed = 0.0f;
        }
        if (state->target) {
            angle = func_00283248(*(float *)(state->target + 0x10) - *(float *)(moby + 0x10), *(float *)(state->target + 0x14) - *(float *)(moby + 0x14));
        } else {
            angle = func_00283248(state->lastPlayer[0] - *(float *)(moby + 0x10), state->lastPlayer[1] - *(float *)(moby + 0x14));
        }
        func_002AAA00((float *)(moby + 0xf8), &state->turnVelocity, 0, angle, 0.00349065894f, 0.00349065894f, 0.209439546f);
        if (func_00283C80(angle, *(float *)(moby + 0xf8)) < 0.087266475f) {
            func_002AA2E8(&state->aimTime, 0.0f, D_L16_001B16F8 * 0.016666668f);
            func_002AA2E8(&state->aimBlend, 1.0f, 0.06666667f);
            sound = state->attackSound;
            if (*(u8 **)(D_00188660 + (sound * 112 + 0x88)) != state->body || !D_00188660[sound * 112 + 0x74])
                state->attackSound = func_002E5CF8(2, 4, (char *)state->body);
            func_L00_002E6CF0(func_L16_00412560, moby);
        }
        if ((state->target && (*(unsigned short *)(state->target + 0x34) & 1) && func_00282948(&state->aimTimeout)) || (!state->target && state->aimTime <= 0.0f)) {
            func_002A7750(moby, 3, 1);
            sound = state->attackSound;
            if (sound != -1 && *(u8 **)(D_00188660 + (sound * 112 + 0x88)) == state->body && D_00188660[sound * 112 + 0x74]) func_002E59F8(sound);
            state->attackSound = -1;
        }
        break;
    case 12:
        if (func_002B3868(moby)) {
            func_L16_004116C8(moby, 1, 30, 0.0f);
            *(float *)(moby + 0x48) = 0.5f;
        }
        angle = func_00283248(*(float *)(state->target + 0x10) - *(float *)(moby + 0x10), *(float *)(state->target + 0x14) - *(float *)(moby + 0x14));
        func_002AAA00((float *)(moby + 0xf8), &state->turnVelocity, 0, angle, 0.00349065894f, 0.00349065894f, 0.209439546f);
        frame = func_0029F530((char *)moby);
        if (frame > 30.0f) func_002AA2E8((float *)(moby + 0x48), 1.0f, 0.13333334f);
        if (frame > 40.0f && frame < 42.0f) func_002A8C28(moby, state->target + 0x10, 0x10001, 0, 1, 0, 4.0f, (float)state->power, 1.0f);
        if (moby[0x60] & 2) func_002A7750(moby, 2, 1);
        else if (D_0018C0B4 == 22 && D_00189FD8 == 1 && D_0018C2BC == moby) func_L16_00412C58(moby, 24, 27);
        break;
    case 13:
        if (func_002B3868(moby)) {
            state->verticalSpeed = 0.0f;
            state->bodyMode = 1;
            func_L16_004116C8(moby, 0, 30, state->verticalSpeed);
            if (state->leftUsed == state->rightUsed) {
                if (!func_002A77E0(2)) state->projectile = 0;
                else state->projectile = func_L16_004130B0(moby, 1);
            } else if (!state->leftUsed) state->projectile = func_L16_004130B0(moby, 1);
            else state->projectile = 0;
        }
        angle = func_00283248(D_00189EA0[0] - *(float *)(moby + 0x10), D_00189EA0[1] - *(float *)(moby + 0x14));
        func_002AAA00((float *)(moby + 0xf8), &state->turnVelocity, 0, angle, 0.00349065894f, 0.00349065894f, 0.209439546f);
        if (*(float *)(moby + 0x18) > state->floorHeight + 20.0f) {
            if (state->projectile) { func_002A7750(moby, 14, -1);
            state->leftUsed = 1; }
            else { func_002A7750(moby, 15, -1);
            state->rightUsed = 1; }
        }
        break;
    case 14:
        if (func_002B3868(moby)) func_L16_004116C8(moby, 6, 30, 0.0f);
        func_0029FC20((char *)state->body, 3, (char *)work.bone);
        switch (state->body[0x43]) {
        case 6:
            if (func_L16_00413638(state->projectile)) {
                func_L16_00413690(state->projectile, (u8 *)work.bone);
                func_L16_004116C8(moby, 7, 5, 0.0f);
            }
            break;
        case 7:
            func_L16_00413690(state->projectile, (u8 *)work.bone);
            if (state->body[0x60] & 2) func_L16_004116C8(moby, 9, 5, 0.0f);
            break;
        case 9:
            if (state->projectile) {
                func_L16_00413690(state->projectile, (u8 *)work.bone);
                if (state->body[0x42] == 9 && func_0029F530((char *)state->body) > 16.0f) {
                    distance = func_00282E80(state->projectile + 0x10, state->target + 0x10) * 0.008333334f;
                    func_00282CF0(velocity, state->target + 0x10, state->projectile + 0x10);
                    velocity[2] = 0.0f;
                    func_00282F20(velocity, velocity, distance);
                    velocity[2] = func_L00_0031CDD0(state->projectile + 0x10, state->target + 0x10, 0, distance, -0.0013888889f);
                    func_L16_00413700(state->projectile, velocity, 0.0013888889f);
                    state->projectile = 0;
                }
            }
            if (state->body[0x60] & 2) func_002A7750(moby, 2, 1);
            break;
        }
        break;
    case 15:
        if (func_002B3868(moby)) func_L16_004116C8(moby, 14, 30, 0.0f);
        angle = func_00283248(D_00189EA0[0] - *(float *)(moby + 0x10), D_00189EA0[1] - *(float *)(moby + 0x14));
        func_002AAA00((float *)(moby + 0xf8), &state->turnVelocity, 0, angle, 0.00349065894f, 0.00349065894f, 0.209439546f);
        if (state->body[0x42] == state->body[0x43] && (D_L16_001B2648 & 15) == (((unsigned int)moby >> 8) & 15)) func_L16_00411D00(moby);
        if (*(unsigned short *)(moby + 0x96) > 180) func_002A7750(moby, 2, 1);
        break;
    case 16:
        if (func_002B3868(moby)) state->verticalSpeed = 0.0f;
        state->verticalSpeed -= 0.008333334f;
        *(float *)(moby + 0x18) += state->verticalSpeed;
        if (*(float *)(moby + 0x18) <= state->floorHeight) {
            *(float *)(moby + 0x18) = state->floorHeight;
            func_002E5CF8(9, 0, (char *)moby);
            func_002A7750(moby, state->resumeState, state->resumeArgument);
        }
        break;
    case 17:
        if (func_002B3868(moby)) {
            func_L16_004116C8(moby, 16, 30, 0.0f);
            *(float *)(moby + 0x48) = 0.5f;
            state->bodyMode = 1;
            if (state->verticalSpeed < 0.0f) state->verticalSpeed = 0.0f;
            sound = state->attackSound;
            if (sound != -1 && *(u8 **)(D_00188660 + (sound * 112 + 0x88)) == state->body && D_00188660[sound * 112 + 0x74]) func_002E59F8(sound);
            state->attackSound = -1;
            sound = state->bodySound;
            if (sound != -1 && *(u8 **)(D_00188660 + (sound * 112 + 0x88)) == moby && D_00188660[sound * 112 + 0x74]) func_002E59F8(sound);
            state->bodySound = -1;
        }
        angle = func_00283248(D_00189EA0[0] - *(float *)(moby + 0x10), D_00189EA0[1] - *(float *)(moby + 0x14));
        func_002AAA00((float *)(moby + 0xf8), &state->turnVelocity, 0, angle, 0.00174532947f, 0.00174532947f, 0.104719773f);
        if ((D_L16_001B2648 & 15) == (((unsigned int)moby >> 8) & 15)) {
            *(BossQuadword *)work.vectors.offset = 0;
            work.vectors.offset[0] = func_002A78D8(0.0f, 6.0f);
            work.vectors.offset[1] = func_002A78D8(0.0f, 6.0f);
            work.vectors.position[2] = func_002A7878(5.0f, 20.0f);
            work.vectors.position[0] = work.vectors.offset[0];
            work.vectors.position[1] = work.vectors.offset[1];
            work.vectors.position[3] = work.vectors.offset[3];
            work.vectors.offset[2] = work.vectors.position[2];
            func_00282CC0(work.vectors.position, work.vectors.position, moby + 0x10);
            func_00282CF0(work.vectors.offset, D_L16_001B9B00, work.vectors.position);
            func_00282F20(work.vectors.offset, work.vectors.offset, 1.0f);
            func_0032DA58(moby, work.vectors.position, work.vectors.offset, 0.0f);
            func_002E5DA0(6, 0, (char *)moby, 0xf78);
        }
        if (state->body[0x42] == state->body[0x43] && state->body[0x41] > 29) func_L16_002D2D10(5, 5.0f, 15.0f);
        if (D_L16_001B2564 >= 1.0f) {
            func_002A7750(moby, 18, -1);
            moby[0x31] = 0;
            *(unsigned short *)(moby + 0x34) |= 1;
            state->bodyMode = 0;
        }
        break;
    case 18:
        *(float *)(moby + 0x48) = 0.1f;
        *(float *)(state->body + 0x48) = 0.1f;
        state->bodyMode = 0;
        state->verticalSpeed -= 0.0055555557f;
        *(float *)(moby + 0x18) += state->verticalSpeed;
        if (*(unsigned short *)(moby + 0x96) > 90 && D_0013963B != 2 && func_00288AA0((u8 *)&D_L16_001BFD00, 133)) {
            func_002A7750(moby, 19, -1);
            func_00288AA0((u8 *)&D_L16_001BFD00, 17);
            func_00288AA0((u8 *)&D_L16_001BFD00, 134);
            func_00288BE8(&D_L16_001BFD00);
            func_002F5CB8((int)func_L16_00412E70, (int)moby);
        }
        break;
    case 19:
        if (func_002B3868(moby)) {
            *(int *)(moby + 0x98) = 0;
            *(unsigned short *)(moby + 0x34) = (*(unsigned short *)(moby + 0x34) & 0xefff) | 0x41;
            *(unsigned short *)(state->body + 0x34) |= 0x41;
            *(unsigned short *)(state->body + 0x34) &= 0xefff;
            *(int *)(state->body + 0x98) = 0;
            *(unsigned short *)(state->arms[0] + 0x34) |= 0x41;
            *(unsigned short *)(state->arms[0] + 0x34) &= 0xefff;
            *(int *)(state->arms[0] + 0x98) = 0;
            *(unsigned short *)(state->arms[1] + 0x34) |= 0x41;
            *(unsigned short *)(state->arms[1] + 0x34) &= 0xefff;
            *(int *)(state->arms[1] + 0x98) = 0;
        }
        if (D_L16_001A8F00 == 2) func_L16_00411F80(moby, 0);
        break;
    }
    func_L16_00411480(moby);
    func_L16_00411600(moby);
    sound = state->bodySound;
    if (!state->bodyMode) {
        if (sound != -1 && *(u8 **)(D_00188660 + (sound * 112 + 0x88)) == moby && D_00188660[sound * 112 + 0x74]) func_002E59F8(sound);
        state->bodySound = -1;
    } else if (*(u8 **)(D_00188660 + (sound * 112 + 0x88)) != moby || !D_00188660[sound * 112 + 0x74]) {
        state->bodySound = func_002E5CF8(10, 4, (char *)moby);
    }
}
