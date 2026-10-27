/* Nonmatching C: Initialize the object and its child, update challenge progress and dispatch the requested target action.
 * Tested profile: -O2 -G8 -ffunction-sections.
 * Measured US size: 3768 bytes; retail: 3992 bytes.
 * Placement checks: US and US2: 0/2 each; PAL: absent from the catalogue.
 * Remaining: Dispatch block placement, shared transitions and register allocation remain different.
 * Reopen with independent state and child-pointer lifetime evidence; keep the complete vectors, canonical pointer returns and full effect-call argument banks.
 */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } StateVector;
typedef struct { s16 state, padding; u32 tick, flags; } ChallengeProgress;
extern ChallengeProgress D_0018CB2C, D_0018CF58, D_0018CDE4;
extern u32 D_001A7390;
extern int D_001A79F0, D_0018C304;
extern u16 D_L03_001B275C, D_L03_001B275E, D_L03_001B2760, D_L03_001B2762, D_L03_001B2764;
extern float D_L03_001AFEE0 __attribute__((sda));
extern float D_L03_001AFEE4 __attribute__((sda));
extern int D_L03_001AFEF8 __attribute__((sda));
extern int D_L03_001AFEFC __attribute__((sda));
extern u16 D_L03_001AFF00 __attribute__((sda));
extern int D_L03_001B2548;
extern int D_L03_001B2A38 __attribute__((sda));
extern u16 *D_L03_001FB5A0[];
extern u8 *D_L03_001B2A1C __attribute__((sda));
extern float D_00189EA0[], D_L03_001B9980[];
extern int func_002A77E0(int);
extern int func_002A7820(int, int);
extern float func_002A89A8(u8 *, int, float);
extern u8 *func_0029EFD0(int);
extern void func_002B37E8(void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_002A7750(u8 *, s32, s32);
extern void func_002A7470(u8 *, int, int, int);
extern void func_L03_00419A60(u32, u8 *, s32);
extern float func_00282E48(void *, void *);
extern float func_00282E80(void *, void *);
extern void func_002A93B0(void *);
extern void func_L03_0032AD10(int);
extern void *func_002A9640(void *, u32, int);
extern int func_00282C30(int);
extern u8 *func_0032C700(void *,int,int,int,int,int,int,int,float,float,int,int,int,void *);
extern void func_002B0A68(char *, int, float *, unsigned char, float, float, float, float);
extern float *func_L03_003C5668(u8 *, float *, float *);
extern void func_L02_002EF388(void *, void *, void *, int, int);
extern u8 *func_L03_003C5128(u8 *);
extern u8 *func_L03_003C52D0(u8 *);
extern u8 *func_L03_003C5488(u8 *);
extern u8 *func_L03_003C4D40(u8 *);
extern u8 *func_L03_003C4F58(u8 *);
extern int func_00288E18(int, int);
extern void func_L03_004197C8(void *, void *);
extern int func_L03_00419BD8(u32, void *, void *);
extern void func_L03_003CAAF0(void *, void *, void *);
extern void func_L03_003CA148(void *, void *, void *);
extern void func_L03_003CA230(void *, void *);
extern void func_L03_0038A9D0(void *, void *);
extern void func_L00_003294F0(void *, int);
extern int func_L03_003C5CE8(void *);
extern void func_L03_003C5EE8(void *);
#define ANIM_COUNT(p, offset) (*(u8 *)(*(u8 **)(*(u8 **)((p) + 0x24) + (offset)) + 0x10))


void func_L03_003C3220(u8 *object)
{
    StateVector point, first, second;
    u8 *state = *(u8 **)(object + 0x68);
    u8 *child, *target;
    int type, i, animation, frame;
    float distance;
    int permitted;
    if (object[0x20] == 0) {
        if (func_002A77E0(2)) *(u16 *)(object + 0x34) |= 0x8000;
        else *(u16 *)(object + 0x34) &= 0x7FFF;
        object[0x7E] |= 1;
        *(float *)(object + 0x18) = func_002A89A8(object + 0x10, 0, 0.5f);
        *(float *)(state + 0x3A4) = *(float *)(object + 0x18);
        type = *(s16 *)(object + 0xAA);
        child = func_0029EFD0(type == 0x964 ? 0x972 : 0xD75);
        *(u8 **)(state + 0x354) = child;
        if (child) {
            func_002B37E8(child, object);
            child = *(u8 **)(state + 0x354);
            if (type != 0x964) *(u16 *)(child + 0x7C) = D_L03_001AFF00;
            *(u16 *)(child + 0x32) = 0x30;
            if (type != 0x964 && *(s16 *)(object + 0xAA) == 0x93C)
                *(float *)(child + 0x2C) = *(float *)(*(u8 **)(child + 0x24) + 0x24) * 1.2f;
        }
        state[0x28] = 3;
        *(float *)(state + 0x20) = 1.0f;
        *(s16 *)(state + 0x24) = 1;
        *(float *)(state + 0x144) = D_L03_001AFEE0;
        *(float *)(state + 0x114) = 0.3f;
        type = *(s16 *)(object + 0xAA);
        if (type == 0x940) {
            *(float *)(state + 0x110) = 0.39f;
            *(float *)(object + 0x18) += 0.089f;
            func_00282F20(&point, object + 0xC0, -0.2f);
            func_00282CC0(object + 0x10, &point, object + 0x10);
        } else {
            *(float *)(state + 0x110) = (type == 0x93C || type == 0xA59) ? 0.42f : 0.15f;
            *(float *)(object + 0x18) += 0.089f;
        }
        *(u8 **)(state + 0x15C) = state + 0x2C0;
        *(float *)(state + 0x11C) = 0.5f;
        *(float *)(state + 0x120) = 1.5882498f;
        *(float *)(state + 0x140) = 0.523598849773407f;
        *(u8 **)(state + 0x158) = state + 0x240;
        *(float *)(state + 0x13C) = 0.0055555557f;
        *(float *)(state + 0x118) = 0.5f;
        func_002A7750(object, 1, 0);
        if (object[0x43])
            func_002A7470(object, 0, func_002A77E0(ANIM_COUNT(object, 0x48)), 0);
        type = *(s16 *)(object + 0xAA);
        if (type == 0x940) {
            for (i = 0; i < 8; i++) {
                int group = *(int *)(state + 0x200 + i * 4);
                u16 *ids;
                if (group == -1 || (group & 255) == 255 || group > D_L03_001B2A38)
                    continue;
                ids = D_L03_001FB5A0[group];
                if (!ids) continue;
                while ((s16)ids[-1] >= 0 || ids == D_L03_001FB5A0[*(int *)(state + 0x200 + i * 4)]) {
                    u8 *member = D_L03_001B2A1C + ((*ids & 0x7FFF) << 8);
                    if (!member) break;
                    if (*(s16 *)(member + 0xAA) == 0x97A)
                        func_L03_00419A60(*(int *)(state + 0x220), member + 0x10, 0);
                    group = *(int *)(state + 0x200 + i * 4);
                    if ((group & 255) == 255 || group > D_L03_001B2A38 || ids + 1 == 0)
                        break;
                    ids++;
                }
            }
        } else if (type == 0xA59 && object[0x43] != 6) {
            func_002A7470(object, 6, 0, 0);
        }
    }
    if (object[0x31] && func_00282E48(object + 0x10, D_L03_001B9980) < 24.0f) {
        func_002A93B0(object);
        object[0x6F] = 0x16;
    }
    if (object[0x20] > 1 && object[0x95] != 4) func_L03_0032AD10((int)object);
    if (func_002A9640(object, 1, 0) ||
        (*(float *)(object + 0x18) < *(float *)(state + 0x3A4) - 10.0f &&
         *(float *)(object + 0x18) - 10.0f < *(float *)(state + 0x1A0))) {
        if (func_00282C30(D_L03_001AFEF8 - D_L03_001B2548) > D_L03_001AFEFC) {
            point.q = 0;
            point.f[2] = 0.5f;
            D_L03_001AFEF8 = D_L03_001B2548;
            func_00282CC0(&point, &point, object + 0x10);
            func_0032C700(object+0x10,0,5,5,5,10,20,0,0.25f,20.0f,1,0,0,0);
            if (*(s16 *)(object + 0xAA) == 0x964)
                func_002B0A68((char *)object, 15, (float *)(state + 0x1B0), 255, 3.0f, 6.0f, 3.0f, 6.0f);
            func_002A7750(object, 4, 1);
            qzero(state + 0x1B0);
            *(int *)(state + 0x1E8) = -1;
            func_L03_003C5668(object, first.f, second.f);
            func_L02_002EF388(object, &first, &second, 0, 0);
        }
        object[0xA8] = 255;
    }
    if (object[0x95] == 4) D_L03_001B275E++;
    type = *(s16 *)(object + 0xAA);
    if (D_0018CB2C.state != -1 && type == 0x940 && object[0x20] != 1 && func_L03_003C5128(object)) {
        if (D_0018CB2C.state == 0) {
            D_0018CB2C.state = 1;
            if (D_0018CB2C.tick < D_001A7390) D_0018CB2C.tick = D_001A7390;
            D_0018CB2C.flags |= (1U << (D_001A79F0 & 31)) | 0x80000000U;
        } else if (D_001A7390 - D_0018CB2C.tick < 1081 && D_0018CB2C.tick != 0) {
            if (D_0018CB2C.tick < D_001A7390) D_0018CB2C.tick = D_001A7390;
        } else func_00288E18(0x9D0, 0x27);
    }
    if (D_0018CF58.state != -1 && type == 0x93C && object[0x20] != 1 && func_L03_003C52D0(object)) {
        if (D_0018CF58.state == 0) {
            D_0018CF58.state = 1;
            if (D_0018CF58.tick < D_001A7390) D_0018CF58.tick = D_001A7390;
            D_0018CF58.flags |= (1U << (D_001A79F0 & 31)) | 0x80000000U;
        } else if (D_001A7390 - D_0018CF58.tick < 1081 && D_0018CF58.tick != 0) {
            if (D_0018CF58.tick < D_001A7390) D_0018CF58.tick = D_001A7390;
        } else func_00288E18(0xA29, 0x80);
    }
    if (D_0018CDE4.state != -1 && type == 0xA59 && object[0x20] != 1 && func_L03_003C5488(object)) {
        if (D_0018CDE4.state == 0) {
            D_0018CDE4.state = 1;
            if (D_0018CDE4.tick < D_001A7390) D_0018CDE4.tick = D_001A7390;
            D_0018CDE4.flags |= (1U << (D_001A79F0 & 31)) | 0x80000000U;
        } else if (D_001A7390 - D_0018CDE4.tick < 1081 && D_0018CDE4.tick != 0) {
            if (D_0018CDE4.tick < D_001A7390) D_0018CDE4.tick = D_001A7390;
        } else func_00288E18(0xA0A, 0x61);
    }
    if (object[0x20] != 1 && func_00282E80(object + 0x10, D_00189EA0) < 16.0f) {
        D_L03_001B275C++;
        type = *(s16 *)(object + 0xAA);
        if (type == 0x940) D_L03_001B2760++;
        else if (type == 0x93C) D_L03_001B2762++;
        else if (type == 0xA59) D_L03_001B2764++;
    }
    permitted = D_0018C304 != 0 && object[0x20] != 1 && object[0x20] != 13 &&
                object[0x95] != 7 && *(int *)(state + 0x364) == 0;
    if (object[0x95] == 4 && D_0018C304 != 6) permitted = 0;
    if (object[0x95] == 5 && D_0018C304 != 5) permitted = 0;
    if (!permitted) return;
    switch (D_0018C304) {
    case 1:
        if (object[0x95] == 1) return;
        distance = func_00282E80(object + 0x10, D_00189EA0);
        if (distance > D_L03_001AFEE4) {
            func_002A7750(object, 3, 1);
            if (object[0x43] == 2) return;
            animation = 2; frame = func_002A77E0(ANIM_COUNT(object, 0x50));
        } else {
            func_002A7750(object, 4, 1);
            if (object[0x43] == 0) return;
            animation = 0; frame = func_002A77E0(ANIM_COUNT(object, 0x48));
        }
        func_002A7470(object, animation, frame, 10);
        break;
    case 2:
        if (object[0x95] != 0) {
            func_002A7750(object, 2, 0);
            if (object[0x43]) func_002A7470(object, 0, func_002A77E0(ANIM_COUNT(object, 0x48)), 10);
            *(int *)(state + 0x384) = func_002A7820(60, 120);
            *(int *)(state + 0x38C) = 0;
            *(int *)(state + 0x388) = 0;
        }
        break;
    case 3:
        if (object[0x95] == 2 || *(s16 *)(object + 0xAA) != 0x964) return;
        target = func_L03_003C4D40(object); *(u8 **)(state + 0x358) = target;
        if (!target) {
            func_002A7750(object, 11, 2);
            if (object[0x43] == 0) return;
            animation = 0; frame = func_002A77E0(ANIM_COUNT(object, 0x48));
        } else {
            func_002A7750(object, 9, 2);
            if (object[0x43] == 3) return;
            animation = 3; frame = func_002A77E0(ANIM_COUNT(object, 0x54));
        }
        func_002A7470(object, animation, frame, 10);
        break;
    case 4:
        if (*(s16 *)(object + 0xAA) != 0x964) return;
        *(int *)(state + 0x364) = 30;
        if (object[0x95] == 3) {
            if (object[0x20] == 13) return;
            func_002A7750(object, 4, 1);
            if (object[0x43] == 0) return;
            func_002A7470(object, 0, 0, 10);
        } else {
            target = func_L03_003C4F58(object); *(u8 **)(state + 0x358) = target;
            if (!target) return;
            func_L03_004197C8(target, &point);
            if (!func_L03_00419BD8(*(u32 *)(state + 0x220), object + 0x10, &point)) {
                *(u8 **)(state + 0x358) = 0; return;
            }
            qcopy(state + 0x340, &point);
            func_002A7750(object, 12, 3);
            if (object[0x43] != 2) func_002A7470(object, 2, 0, 10);
        }
        break;
    case 5:
        if (*(s16 *)(object + 0xAA) != 0x93C) return;
        if (object[0x95] != 5) {
            target = func_L03_003C52D0(object); *(u8 **)(state + 0x358) = target;
            if (!target) return;
            func_002A7750(object, 18, 5);
            if (object[0x43] != 2) func_002A7470(object, 2, 0, 10);
            *(int *)(state + 0x364) = 30;
            func_L03_003CA148(*(u8 **)(state + 0x358), object + 0x10, state + 0x340);
            return;
        }
        if (object[0x20] != 19) {
            func_L00_003294F0(*(u8 **)(state + 0x358), 0);
            *(u8 **)(state + 0x358) = 0; *(int *)(state + 0x364) = 30;
            func_002A7750(object, 4, 1);
            if (object[0x43]) func_002A7470(object, 0, 0, 20);
        }
        break;
    case 6:
        if (*(s16 *)(object + 0xAA) != 0x940) return;
        *(int *)(state + 0x364) = 30;
        if (object[0x95] != 4) {
            target = func_L03_003C5128(object); *(u8 **)(state + 0x358) = target;
            if (!target) return;
            func_002A7750(object, 14, 4);
            if (object[0x43] != 2) func_002A7470(object, 2, 0, 10);
            func_L03_003CAAF0(*(u8 **)(state + 0x358), &point, &first);
            if (func_L03_00419BD8(*(u32 *)(state + 0x220), object + 0x10, &point))
                qcopy(state + 0x340, &point);
            else qcopy(state + 0x340, &first);
        } else if (object[0x20] == 14) {
            func_002A7750(object, 4, 1);
            if (object[0x43]) func_002A7470(object, 0, 0, 20);
        } else if (object[0x20] == 16 && !func_L03_003C5CE8(object)) func_L03_003C5EE8(object);
        break;
    case 7:
        if (*(s16 *)(object + 0xAA) != 0xA59) return;
        if (object[0x95] != 6) {
            target = func_L03_003C5488(object); *(u8 **)(state + 0x358) = target;
            if (!target) return;
            func_002A7750(object, 20, 6);
            if (object[0x43] != 2) func_002A7470(object, 2, 0, 10);
            target = *(u8 **)(state + 0x358); *(int *)(state + 0x364) = 30;
            if (*(s16 *)(target + 0xAA) == 0xB10) func_L03_0038A9D0(target, state + 0x340);
            else if (*(s16 *)(target + 0xAA) == 0xF4D) func_L03_003CA230(target, state + 0x340);
        } else if (object[0x20] != 21) {
            func_L00_003294F0(*(u8 **)(state + 0x358), 0);
            *(u8 **)(state + 0x358) = 0; *(int *)(state + 0x364) = 30;
            func_002A7750(object, 4, 1);
            if (object[0x43]) func_002A7470(object, 0, 0, 20);
        }
        break;
    case 8:
        if (*(s16 *)(object + 0xAA) != 0x964) func_002A7750(object, 6, 1);
        else if (object[0x95] != 1) func_002A7750(object, 4, 1);
        break;
    }
}
