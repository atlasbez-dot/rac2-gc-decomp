/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Prior worker coverage: US 0/1; US2 absent from catalogue; PAL absent from catalogue.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/* Retained readable reconstruction, 23 October 2026; not linked.
 * Latest measured profile: -O2 -G0 -ffunction-sections -frac2-qcopy
 * -frac2-qcopy-barrier (an explicit override on the tested -g8.c sibling).
 * US: 14408/14864 bytes, 0/1 placements, check.py exit 1.
 * US2/PAL: the name is absent from both catalogues, not a match.
 * Seven bounded trials: initial13732/frame0x60; scoped captures13728;
 * qualified float fields14032; independent temporaries14016/frame0x50;
 * grouped copies underG8 14260; G0 14332; separate source cases14408.
 * The 88-case controller and recursive transitions are reconstructed. Separate
 * logical temporaries recover the retail frame and saved-register count, but
 * register roles, global reload/address lifetimes, copies and block layout
 * still differ substantially. Close size is not instruction matching evidence.
 * The full 64-bit canonical A4EF0 result and FD1B8's 3GPR/4FP inputs are kept.
 * Unresolved ignored return declarations and CAF20 arity are explicit below.
 * Reopen with independent player-view/alias or branch-layout evidence; do not
 * use duplicated data identities, register pins, barriers or repeat old flags.
 * No linked qualification or game-behavior validation was run.
 */

/* Player action transitions. Resident storage is viewed at measured byte
 * offsets, without claiming a complete player-object layout. The union extends
 * through the last accessed statistic at +0x2A94 and keeps vector accesses full
 * width. Word views preserve fields whose original interpretation is unknown. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } Vector;
typedef union {
    u8 bytes[0x2AA0];
    short signedHalves[0x2AA0 / 2];
    u16 halves[0x2AA0 / 2];
    int integers[0x2AA0 / 4];
    u32 words[0x2AA0 / 4];
    float floats[0x2AA0 / 4];
    char *pointers[0x2AA0 / 4];
    Vector vectors[0x2AA0 / 16];
} PlayerActionView;

extern PlayerActionView D_00189E20;
#define P_B(o) D_00189E20.bytes[(o)]
#define P_H(o) D_00189E20.halves[(o) / 2]
#define P_S(o) D_00189E20.signedHalves[(o) / 2]
#define P_I(o) D_00189E20.integers[(o) / 4]
#define P_W(o) D_00189E20.words[(o) / 4]
#define P_F(o) D_00189E20.floats[(o) / 4]
#define P_PTR(o) D_00189E20.pointers[(o) / 4]
#define P_V(o) D_00189E20.vectors[(o) / 16]
#define P_ADDR(o) (D_00189E20.bytes + (o))
#define OBJECT P_PTR(0x2290)
#define ACTION P_I(0x2294)
#define VARIANT P_I(0x2298)
#define STATE P_I(0x229C)
#define PREVIOUS_ACTION P_I(0x22A0)
#define PREVIOUS_STATE P_I(0x22A4)
#define PREVIOUS_FRAME P_I(0x22A8)
#define OLDER_ACTION P_I(0x22AC)
#define OLDER_STATE P_I(0x22B0)
#define MODE P_B(0x22B4)

/* The table is indexed with an observed 44-byte record stride. */
typedef struct {
    int variant, limit;
    u8 remaining[0x2C - 8];
} AttackEntry;
extern AttackEntry D_L08_00268114[];
extern u32 D_L08_002682A0[][25];
extern u8 D_L08_00268430[];
extern int D_L08_001A8F00, D_L08_001A8FF4;
extern float D_L08_001A7CD8 __attribute__((sda));
extern float D_L08_001A7CDC __attribute__((sda));
extern int D_L08_001A7DD8[];
extern u8 D_L08_001A7DE0[], D_L08_001A7E00[];
extern void *D_L08_001B3170;
extern int D_L08_001B3178;
extern float D_L08_001B9B08;
extern int D_L08_001B9DC0;
extern u32 D_001A7390, D_001A79F0;
extern int D_001A7B90;
extern u8 D_001A7A45;

extern void func_L00_00322EC8(void *);
extern void func_L00_002D6940(void);
extern void func_L00_002AF7D0(void);
extern int func_002A7820(int, int);
extern void func_L00_002AB3E0(void);
extern void func_L01_002C1988(unsigned long);
extern void func_00282C88(Quad *);
extern float func_00282C48(float), func_00282E20(void *);
extern float func_00282E48(void *, void *);
extern float func_00283180(float), func_00283198(float);
extern float func_00283248(float, float);
extern float func_00283B98(float, float), func_00283C80(float, float);
extern int func_00283CF0(float);
extern void func_00282CF0(void *, const void *, const void *);
extern void func_00282D30(void *, const void *, float);
extern void func_002AC9F8(float *, float);
extern void *func_002A9640(void *, u32, int);
extern float func_002A78D8(float, float);
extern int func_L04_002CC748(int);
extern int func_L00_002B9B88(int, int);
extern unsigned long func_L00_002A4EF0(unsigned long);
extern void func_L00_002B6118(float);
extern float func_L00_002D3A58(char *);
extern void func_L00_002D2470(int, int);
extern int func_L00_0035F5A0(int, int, int);
extern float func_L00_002AE070(int);
extern int func_L00_002C3A78(void);
extern int func_L00_002D6900(unsigned int);
extern u32 func_L00_002ADE68(int);
extern int func_L00_002B3248(u8 *);
extern float func_L00_002B9B38(void *, int);
extern void func_L00_00322A98(void *, char *);
extern void func_L00_00322AC0(void *, int, int, float);
extern void func_L00_002D3B58(void *, void *, float);
extern int func_L00_002ADF80(void);
/* The callee normalizes v0 to 0/1. The observed caller supplies an a0 context,
 * which this callee does not consume; its original formal arity is uncertain. */
extern int func_L00_002CAF20(int);

/* Qualified inputs for side-effect calls. Their ignored result banks do not
 * establish original return declarations: void is an interface assumption.
 */
extern void func_L00_002AF3D8(int, int);
extern void func_L00_002D2168(int, int, float);
extern void func_002A7470(char *, int, int, int);
extern void func_L00_002AABE0(int, int, int);
extern void func_002FD1B8(void *, int, int, float, float, float, float);
extern void func_L00_002A4EF8(int);
extern void func_L00_002B39F0(int, float);
extern void func_L00_002A61C8(int, int, int, int);
extern void func_L00_002BA508(void);
extern void func_L00_002B75A0(float, float, float);
extern void func_L00_0041E958(float, float, float);
extern void func_L00_002A6708(void);

int func_L08_002D2ED8(int action, int animate)
{
    char *originalObject;
    char *actor, *data;
    int savedVariant;
    u8 oldModeFlag;
    u8 equipment;
    int animation, redirectAction, frames, phase;
    int sourceAnimation, currentAnimation, softLanding, animationSide;
    int attackStep, followUp, frameIndex;
    unsigned long variantType;
    u32 flags, limit;
    float blend, angle, variation;

    if (STATE == 20) {
        if (action != 0x61 || animate != 2)
            return 0;
    }
    if ((D_L08_001A8F00 == 2 || D_L08_001A8F00 == 6) && animate != 2)
        return 0;
    if (P_I(0x24CC) == 0 && (STATE == 2 || STATE == 7)) {
        if (action != 6 && action != 0x39 && action != 0x43 && action != 0x91 &&
            action != 0x5F && action != 0x74 && action != 0x78 && action != 0x79 &&
            action != 0x7C && action != 0x67 && action != 0x7D && action != 0x7F)
            return 0;
    }
    savedVariant = VARIANT;
    originalObject = OBJECT;
    oldModeFlag = P_B(0x22B7);
    OLDER_ACTION = PREVIOUS_ACTION;
    OLDER_STATE = PREVIOUS_STATE;
    PREVIOUS_FRAME = P_I(0x1B8);
    PREVIOUS_ACTION = ACTION;
    PREVIOUS_STATE = STATE;
    ACTION = action;
    VARIANT = 0;
    if (P_B(0x22B5) == 1)
        P_B(0x22B5) = 0;
    P_B(0x22BC) = 0;
    if (MODE == 0) {
        *(int *)(OBJECT + 0x9C) = 0;
        P_B(0x22BD) = 0;
        P_B(0x22B7) = 0;
        P_B(0x22C2) = 0;
        P_B(0x22BF) = 0;
        P_H(0x2504) = 0;
        func_L00_00322EC8(P_ADDR(0x18E0));
    }
    if (P_S(0x1FA) == 0)
        func_L00_002D6940();
    func_L00_002AF3D8(PREVIOUS_ACTION, ACTION);
    P_W(0x1188) = 0;

    switch (action) {
    case 0:
        STATE = 0;
        P_W(0x24A0) = 0;
        if (P_I(0x1248) == 0x1A)
            func_L00_002AF7D0();
        P_B(0x24EF) = 0;
        P_W(0x11A0) = func_002A7820(50, 100);
        func_L00_002AB3E0();
        if (MODE) {
            func_L01_002C1988(0);
            return 1;
        }
        P_V(0x160).q = P_V(0x120).q;
        if (P_B(0x1492) && func_00282E20(P_ADDR(0x160)) > 0.008333334f) {
            redirectAction = 0x2E;
            goto redirect;
        }
        if (P_B(0x149A) && P_S(0x34C) == 0) {
            redirectAction = 0x76;
            goto redirect;
        }
        P_W(0x1188) = 0x68;
        if (!animate) goto finish;
        animation = func_L04_002CC748(0);
        blend = animation == 0x51 ? 18.0f : -1.0f;
        animation = func_L04_002CC748(0);
        break;
    case 1:
        P_W(0x24A0) = 4;
        STATE = 0;
        if (P_B(0x22BA)) goto finish;
        animation = func_L04_002CC748(1);
        if ((u8)OBJECT[0x43] == animation || !animate) goto finish;
        blend = 18.0f;
        break;
    case 2: case 0x2E: case 0x70:
        STATE = 1;
        P_W(0x24A0) = 0;
        if (PREVIOUS_STATE != 4 && OLDER_STATE != 4)
            P_F(0x1B4) = func_L00_002D3A58(P_ADDR(0x120));
        P_V(0x3F0).q = P_V(0).q;
        P_W(0x410) = 0;
        P_F(0x408) = P_F(0x98);
        if (P_F(0x1B4) > 0.116666675f)
            P_F(0x1B4) = 0.116666675f;
        P_B(0x40F) = 0;
        func_L00_002B39F0(0, 1.0f);
        angle = func_00283C80(P_F(0x98), P_F(0x1A0));
        if (angle > 1.5707965f &&
            (PREVIOUS_STATE == 4 || PREVIOUS_ACTION == 3 || OLDER_ACTION == 3))
            P_F(0x1B4) = 0.0f;
        P_W(0x1188) = 0x68;
        if (P_B(0x149A)) {
            if (P_S(0x34C) == 0 || P_F(0x31C) < 0.3f) {
                redirectAction = 0x76;
                goto redirect;
            }
        }
        if (!P_B(0x1492) && ACTION != 0x2E) {
            if (!P_B(0x22B9) && ACTION != 0x70) {
                VARIANT = 0;
                P_B(0x40C) = 0;
                P_B(0x40E) = 0;
                if (!animate) goto finish;
                frames = 8;
                if (P_I(0x24CC) == 1) frames = 12;
                if (OLDER_ACTION == 0x22 || PREVIOUS_ACTION == 0x22) frames = 15;
                if (OLDER_ACTION == 0x83 || PREVIOUS_ACTION == 0x83) frames = 15;
                if (PREVIOUS_ACTION == 0x13) frames = 13;
                if (OLDER_ACTION == 6 || OLDER_ACTION == 0x2C) frames = 18;
                if (OLDER_STATE == 4 && P_B(0x49C) > 5) frames = 13;
                func_L00_002D2168(VARIANT + 3, D_L08_001A7DD8[VARIANT], (float)frames);
                goto finish;
            }
            blend = 8.0f;
            ACTION = 0x70;
            animation = 0x59;
        } else {
            if (P_F(0x1B4) > 0.12833333f) P_F(0x1B4) = 0.12833333f;
            P_F(0xF8) = 0.0f;
            func_002AC9F8(P_V(0xF0).f, 0.12833333f);
            blend = 8.0f;
            ACTION = 0x2E;
            animation = 0x37;
            P_W(0x404) = 0;
        }
        break;
    case 3:
        STATE = 1;
        P_W(0x24A0) = 0;
        P_V(0x160).q = P_V(0x120).q;
        if (P_B(0x1492)) { redirectAction = 0x2E; goto redirect; }
        if (P_B(0x149A)) {
            if (P_S(0x34C) == 0) { redirectAction = 0x76; goto redirect; }
        }
        if (func_L00_002CAF20(0x2E)) return 0;
        if (func_L04_002CC748(0) == 0x51) {
            if (animate) {
                if (!func_L08_002D2ED8(0, 0)) return 0;
                func_L00_002D2168(func_L04_002CC748(0), 0, 18.0f);
                return 0;
            }
            goto finish;
        }
        if (!animate) goto finish;
        sourceAnimation = (u8)originalObject[0x42];
        goto chooseLocomotion;
    case 4:
        STATE = 12;
        P_W(0x24A0) = 0;
        P_F(0x1B4) = func_00282E20(P_ADDR(0x120));
        if (P_F(0x1B4) > 0.116666675f) P_F(0x1B4) = 0.116666675f;
        if (P_B(0x149A) && P_S(0x34C) == 0) { redirectAction = 0x76; goto redirect; }
        P_W(0x1188) = 0x68;
        P_V(0x160).q = P_V(0x120).q;
        func_002AC9F8(P_V(0x160).f, 0.116666675f);
        if (P_F(0x178) > 0.058333337f) func_L00_002B9B88(9, 0);
        if (animate) {
            currentAnimation = (u8)OBJECT[0x42];
            if (currentAnimation == func_L04_002CC748(0))
                func_L00_002D2168(13, 2, 9.0f);
            else
                func_L00_002D2168(13, 2, 14.0f);
            func_L00_002D2470(3, 18);
        }
        goto finish;
    case 6: case 0x74:
        STATE = 2;
        P_W(0x24A0) = 0;
        if (ACTION == 0x74) {
            STATE = 20;
            if (MODE == 1) {
                if (D_001A79F0 == 3) func_L00_0035F5A0(17, 0, (int)OBJECT);
                else if (D_001A79F0 == 14) func_L00_0035F5A0(21, 0, (int)OBJECT);
            }
        }
        P_F(0xA80) = 0.0061111115f;
        P_F(0xA84) = 0.001944444492f;
        if (ACTION == 0x74) {
            if (MODE == 0) P_H(0x24D6) = func_L00_002B9B88(14, 0x20);
            P_F(0xA90) = func_002A78D8(0.052359886f, 0.072722062469f);
            P_F(0xA94) = func_002A78D8(0.052359886f, 0.072722062469f);
        }
        P_W(0x1188) = 0x68;
        VARIANT = 0;
        P_V(0xF0).q = P_V(0x120).q;
        if (!animate) goto finish;
        if (P_F(0x31C) > 1.75f) {
            func_L00_002D2168(11, 0, 12.0f);
            VARIANT = 1;
            goto finish;
        }
        blend = 10.0f;
        animation = 10;
        break;
    case 7: case 9: case 10: case 11: case 12: case 13: case 14:
    case 15: case 16: case 17: case 18: case 0x1B: case 0x28: case 0x29:
    case 0x38: case 0x45: case 0x48: case 0x5B: case 0x66: case 0x6E:
    case 0x81: case 0x89: case 0x92:
        /* Enter an aerial action, retaining the fields not initialized here. */
        actor = P_PTR(0x33C);
        if (ACTION != 0x81 && actor &&
            (*(short *)(actor + 0xAA) == 0x9B9 || *(short *)(actor + 0xAA) == 0xF05)) {
            redirectAction = 0x81;
            goto redirect;
        }
        if (ACTION != 0x6E && P_S(0x348) == 1 && action != 14 && action != 0x38 &&
            D_L08_001A8FF4 == 0) {
            redirectAction = 0x6E;
            goto redirect;
        }
        if (PREVIOUS_ACTION == 17 && P_B(0x24DA) == 0)
            P_B(0x24DB)++;
        else
            P_B(0x24DB) = 0;
        if (P_S(0x1F2) != 0) { redirectAction = 0x82; goto redirect; }
        if (P_S(0x212) != 0) {
            P_I(0x1B8) = PREVIOUS_FRAME;
            P_W(0x1188) = 0;
            ACTION = PREVIOUS_ACTION;
            VARIANT = savedVariant;
            return 0;
        }
        STATE = 4;
        P_W(0x24A0) = (u32)(action - 0x28) < 2 ? 3 : 0x50;
        if (ACTION == 7 || ACTION == 15 || ACTION == 13 ||
            (ACTION == 11 && PREVIOUS_STATE != 4)) {
            equipment = P_B(0x149D);
            func_L00_002A61C8(equipment, 0, 0, 30);
            func_L00_002A61C8(equipment, 1, 0, 30);
        }
        P_V(0xF0).q = P_V(0x120).q;
        if (ACTION != 18 && P_B(0x1494) && P_F(0x88) < P_F(0x330) + 0.5f)
            func_L00_002AABE0(3, 16, 0);
        if (ACTION == 0x66) func_L00_002B9B88(8, 0);
        P_F(0x520) = 0.00825f;
        P_W(0x448) = 0xFFFFFFFF;
        P_F(0x500) = 0.00555555569f;
        P_F(0x510) = 2.5f;
        P_H(0x528) = P_B(0x1492);
        P_H(0x51A) = 0x50;
        P_F(0x494) = 0.2501639128f;
        P_F(0x4A0) = 0.8333333731f;
        P_F(0x490) = P_F(0x88);
        P_B(0x49E) = 0;
        P_B(0x49C) = 0;
        P_W(0x4B0) = 0;
        P_W(0x4B4) = 0;
        P_B(0x49D) = 0;
        P_F(0x504) = 0.003055555746f;
        P_H(0x524) = 0;
        P_B(0x52C) = 0;
        P_B(0x52E) = 0;
        P_B(0x52F) = 0;
        P_H(0x52A) = 0x46;
        P_H(0x526) = 0;
        P_F(0x514) = 0.5f;
        P_F(0x4A4) = 0.09916666895f;
        P_F(0x458) = 0.0f;
        P_B(0x49F) = 0;
        P_W(0x594) = 0;
        P_H(0x24D8) = 0;

        if (ACTION == 7) {
            P_F(0x458) = 0.009652500041f;
            P_F(0x4CC) = 30.0f;
            P_F(0x4D0) = 12.0f;
            P_F(0x50C) = 2.3f;
            P_F(0x508) = 1.28f;
            P_F(0x4A8) = 1.28f;
            goto standardJumpLimits;
        } else if (ACTION == 0x81) {
            P_F(0x50C) = D_L08_001A7CD8 + 0.5f;
            P_F(0x520) = D_L08_001A7CDC * 0.00027777778f;
            P_S(0x4AC) = 5;
            P_F(0x4B8) = 0.6000000238f;
            P_F(0x4C8) = 18.0f;
            P_F(0x4CC) = 30.0f;
            P_F(0x4D0) = 12.0f;
            P_F(0x508) = D_L08_001A7CD8;
            P_H(0x518) = 15;
            P_H(0x51A) = 400;
            P_F(0x510) = 300.0f;
            P_H(0x52A) = 1200;
            P_F(0x4A4) = 0.1166666746f;
            P_F(0x4A8) = D_L08_001A7CD8;
            P_H(0x526) = 1200;
            if (D_001A79F0 == 16) P_F(0x4A4) = 0.0f;
            func_L00_00322A98(OBJECT, P_ADDR(0x18E0));
            func_L00_00322AC0(P_ADDR(0x18E0), 70, 2, 0.0f);
            func_L00_00322AC0(P_ADDR(0x18E0), 35, 4, 0.0f);
            func_L00_00322AC0(P_ADDR(0x18E0), 17, 6, 0.0f);
        } else if (ACTION == 18) {
            softLanding = P_F(0x24C4) < 1.25f;
            P_S(0x4AC) = 2;
            P_F(0x4B8) = 0.6000000238f;
            P_F(0x4CC) = 28.0f;
            P_F(0x4D0) = 14.0f;
            P_F(0x50C) = 0.2f;
            P_F(0x508) = 0.1f;
            P_H(0x518) = 10;
            P_F(0x4A8) = 0.1f;
            P_F(0x4C8) = 18.0f;
            if (softLanding) {
                P_F(0x4A8) = 1.95f;
                P_S(0x4AC) = 15;
                P_F(0x50C) = 1.98f;
                P_F(0x508) = 1.95f;
            } else {
                func_L00_002D3B58(P_ADDR(0xF0), P_ADDR(0xF0), P_F(0x4B0));
                P_PTR(0x444) = (char *)D_L08_00268430;
                P_I(0x430) = 2;
                P_I(0x434) = 0x25;
                P_F(0x438) = 0.0f;
                P_W(0x440) = 40;
                P_F(0x43C) = 18.0f;
            }
            P_B(0x49D) = !softLanding;
            P_B(0x22B7) = 1;
            P_B(0x49F) = 1;
        } else if (ACTION == 0x66) {
            STATE = 25;
            if (P_F(0x88) < P_F(0x334))
                P_F(0x50C) = P_F(0x334) - P_F(0x88);
            else
                P_F(0x50C) = 0.0f;
            P_F(0x4A8) = P_F(0x50C) + 1.7f;
            P_F(0x50C) += 1.75f;
            P_B(0x49F) = 1;
            P_S(0x4AC) = 5;
            P_F(0x4B8) = 0.6000000238f;
            P_F(0x4C8) = 18.0f;
            P_F(0x4CC) = 30.0f;
            P_F(0x4D0) = 12.0f;
            P_H(0x518) = 19;
            P_F(0x508) = P_F(0x4A8);
        } else if (ACTION == 9) {
            P_F(0x4CC) = 29.0f;
            P_F(0x4D0) = 11.0f;
            P_F(0x50C) = 2.7f;
            P_F(0x508) = 1.0f;
            P_F(0x4A8) = 1.0f;
standardJumpLimits:
            P_B(0x52F) = 1;
            P_H(0x518) = 15;
            P_F(0x4C8) = 18.0f;
            P_F(0x4B8) = 0.6000000238f;
            P_S(0x4AC) = 5;
            P_F(0x4A4) = 0.09916666895f;
            P_B(0x52C) = 1;
            P_B(0x52E) = 1;
        } else if (ACTION == 0x6E) {
            P_F(0x4B8) = 0.6000000238f;
            P_F(0x4A4) = 0.1160250008f;
            P_F(0x4C8) = 18.0f;
            P_F(0x4CC) = 30.0f;
            P_F(0x4D0) = 12.0f;
            P_F(0x50C) = 2.75f;
            P_F(0x508) = 2.7f;
            P_H(0x518) = 5;
            P_B(0x49F) = 1;
            P_F(0x4A8) = 2.7f;
            P_S(0x4AC) = 5;
            P_B(0x52C) = 1;
            P_B(0x52E) = 0;
            P_B(0x52F) = 0;
        } else if (ACTION == 10) {
            P_H(0x526) = 70;
            P_S(0x4AC) = 5;
            P_F(0x4B8) = 0.6000000238f;
            P_F(0x4C8) = 18.0f;
            P_F(0x4CC) = 29.0f;
            P_F(0x4D0) = 10.0f;
            P_F(0x50C) = 1.95f;
            P_F(0x508) = 1.9f;
            P_H(0x518) = 14;
            P_F(0x520) = 0.0030555557f;
            P_B(0x52E) = 1;
            P_H(0x51A) = 120;
            P_H(0x52A) = 90;
            P_F(0x4A8) = 1.9f;
        } else if (ACTION == 16) {
            P_F(0x4C8) = 18.0f;
            P_F(0x4CC) = 30.0f;
            P_F(0x4D0) = 11.0f;
            P_F(0x50C) = 1.55f;
            P_S(0x4AC) = 5;
            P_F(0x4B8) = 0.8000000119f;
            P_F(0x508) = 1.5f;
            P_F(0x4A8) = 1.5f;
            P_H(0x518) = 1;
            func_L00_002D6900(20);
            P_F(0x508) = 0.4f;
            P_F(0x50C) = 0.9f;
            P_F(0x4A8) = 0.4f;
            if (P_F(0x184) < 0.33333334f) {
                func_L00_00322A98(OBJECT, P_ADDR(0x18E0));
                func_L00_00322AC0(P_ADDR(0x18E0), 40, 2, 0.0f);
                func_L00_00322AC0(P_ADDR(0x18E0), 20, 4, 0.0f);
                func_L00_00322AC0(P_ADDR(0x18E0), 10, 6, 0.0f);
            }
            P_B(0x52E) = 1;
            P_F(0x454) = 0.1916666776f;
            if (P_F(0x31C) > 1.4f) P_F(0x454) = 0.09499999881f;
            P_F(0x520) = 0.002361111f;
            P_F(0x504) = 0.01388888899f;
            P_F(0x500) = 0.01222222298f;
        } else if (ACTION == 0x1B) {
            P_B(0x52E) = 1;
            P_S(0x4AC) = 10;
            P_F(0x4B8) = 0.8500000238f;
            P_F(0x4C8) = 20.0f;
            P_F(0x4CC) = 29.0f;
            P_F(0x4D0) = 19.0f;
            P_F(0x50C) = 2.05f;
            P_F(0x508) = 2.0f;
            P_F(0x514) = 1.0f;
            P_F(0x520) = 0.0069444445f;
            P_F(0x4A8) = 2.0f;
            P_H(0x518) = 1;
            P_W(0x4BC) = 0;
            P_B(0x49F) = 1;
            P_B(0x22BF) = 1;
            P_B(0x22BC) = 1;
        } else if (ACTION == 17) {
            P_S(0x4AC) = 9;
            P_F(0x4B8) = 0.6000000238f;
            P_F(0x4C8) = 12.0f;
            P_F(0x4CC) = 20.0f;
            P_F(0x4D0) = 10.0f;
            P_H(0x518) = 12;
            if (!P_B(0x24DA)) {
                P_F(0x50C) = 1.85f;
                P_F(0x4A8) = 1.8f;
                P_F(0x498) = 0.02833333611f;
            } else {
                P_F(0x50C) = 3.35f;
                P_F(0x4A8) = 3.3f;
                P_F(0x498) = 0.08166667074f;
            }
            P_B(0x49F) = 1;
            P_F(0x508) = P_F(0x4A8);
            func_L00_002D6900(27);
            P_H(0x52A) = 80;
            P_F(0x520) = 0.008055556f;
            P_V(0x4F0).q = P_V(0x4E0).q;
            P_B(0x52C) = 1;
            P_H(0x24D8) = 1;
            P_B(0x22B7) = 1;
        } else if (ACTION == 13) {
            P_F(0x4C8) = 26.0f;
            P_F(0x4CC) = 38.0f;
            P_F(0x4D0) = 18.0f;
            P_F(0x50C) = 4.07f;
            P_S(0x4AC) = 9;
            P_F(0x4B8) = 0.6000000238f;
            P_F(0x508) = 4.0f;
            P_H(0x518) = 14;
            P_F(0x4A8) = 4.0f;
            func_L00_002D6900(20);
            P_F(0x510) = 4.5f;
            P_H(0x51A) = 120;
            P_F(0x4A4) = 0.03166666627f;
            P_H(0x526) = 37;
            if (P_F(0x184) < 0.33333334f) {
                func_L00_00322A98(OBJECT, P_ADDR(0x18E0));
                func_L00_00322AC0(P_ADDR(0x18E0), 40, 3, 0.0f);
                func_L00_00322AC0(P_ADDR(0x18E0), 20, 5, 0.0f);
            }
            P_B(0x52E) = 1;
        } else if (ACTION == 15) {
            P_S(0x4AC) = 9;
            P_F(0x4B8) = 0.6000000238f;
            P_F(0x4C8) = 50.0f;
            P_F(0x4CC) = 64.0f;
            P_F(0x4D0) = 28.0f;
            P_F(0x50C) = 1.7f;
            P_F(0x508) = 1.65f;
            P_H(0x518) = 5;
            P_F(0x510) = 4.5f;
            P_H(0x51A) = 130;
            P_F(0x4A4) = 0.05500000343f;
            P_H(0x526) = 85;
            P_H(0x1D0) = 70;
            P_B(0x49D) = 1;
            P_F(0x4A8) = 1.65f;
            P_I(0x430) = D_001A7B90 == 0 ? 35 : 34;
            P_PTR(0x444) = (char *)D_L08_001A7E00;
            P_I(0x434) = P_I(0x430) + 36;
            P_B(0x52E) = 1;
            P_F(0x438) = 29.0f;
            P_F(0x43C) = 50.0f;
            P_W(0x440) = 86;
        } else if (ACTION == 14) {
            P_F(0x4A8) = 0.7f;
            if (P_F(0x31C) < 2.0f) P_F(0x4A8) = (2.5f - P_F(0x31C)) * 0.5f + 0.7f;
            P_F(0x50C) = P_F(0x4A8) + 0.05f;
            P_H(0x526) = 30;
            P_S(0x4AC) = -1;
            P_F(0x4B8) = 0.6000000238f;
            P_F(0x4C8) = 32.0f;
            P_F(0x4CC) = 43.0f;
            P_F(0x4D0) = 19.0f;
            P_H(0x518) = 14;
            P_F(0x514) = 1.0f;
            P_F(0x4A4) = 0.07916667312f;
            P_F(0x508) = P_F(0x4A8);
        } else if (ACTION == 11) {
            P_H(0x52A) = 50;
            P_S(0x4AC) = 5;
            P_F(0x4B8) = 0.6000000238f;
            P_F(0x4C8) = 18.0f;
            P_F(0x4CC) = 31.0f;
            P_F(0x4D0) = 24.0f;
            P_F(0x50C) = 3.25f;
            P_F(0x508) = 3.2f;
            P_H(0x518) = 14;
            P_F(0x510) = 4.5f;
            P_F(0x514) = 1.0f;
            P_B(0x49F) = 1;
            P_F(0x4A8) = 3.2f;
            P_F(0x4C4) = func_L00_002AE070(10);
            P_V(0x480).q = P_V(0).q;
            P_I(0x4D4) = func_L00_002C3A78();
            P_F(0x4C0) = P_F(0x1A0);
            P_V(0x470).q = P_V(0x190).q;
            P_F(0x4D8) = P_F(0x174) > 0.025000002f ? P_F(0x174) : 0.0f;
            P_F(0x4DC) = 0.0f;
            P_B(0x52C) = 1;
            if (P_S(0x1454) == 0 || P_F(0x24B8) <= 0.3f) {
                P_B(0x52D) = 0;
            } else {
                P_F(0x4C0) = P_F(0x1458);
                P_V(0x470).q = P_V(0x1440).q;
                P_B(0x52D) = 1;
                P_F(0x4DC) = 0.08333333582f;
            }
            P_B(0x52E) = 1;
        }
        if (P_F(0x510) == 0.0f) P_F(0x510) = P_F(0x4A8) * 1.5f;
        if (!animate) goto finish;
        if (ACTION == 7 || ACTION == 0x6E || ACTION == 0x81 || ACTION == 0x66) {
            blend = 5.0f;
            animation = 7;
        } else if (ACTION == 18) {
            func_L00_002D2168(0x6B, 1, -1.0f);
            goto finish;
        } else if (ACTION == 9) {
            animation = 8;
            animationSide = func_00283CF0(P_F(0xC38));
            if (func_L00_002A4EF0((u8)originalObject[0x42]) == 4)
                animation = D_L08_001A7DE0[animationSide];
            blend = 5.0f;
        } else if (ACTION == 10) {
            blend = 5.0f;
            animation = 18;
        } else if (ACTION == 16) {
            if (PREVIOUS_STATE == 4 || (PREVIOUS_ACTION == 4 && P_I(0x1B8) < 7)) {
                func_L00_002D2168(0x26, 0, 8.0f);
                P_S(0x4AC) += 3;
                goto finish;
            }
            blend = 5.0f;
            animation = 0x26;
        } else if (ACTION == 0x1B) {
            blend = 4.0f;
            animation = 0x22;
        } else if (ACTION == 0x89) {
            func_L00_002D2168(0x7D, 11, 9.0f);
            goto finish;
        } else if (ACTION == 17) {
            func_L00_002D2168(0x23, 2, 7.0f);
            goto finish;
        } else if (ACTION == 13) {
            blend = 5.0f;
            animation = 17;
        } else if (ACTION == 14) {
            func_L00_002D2168(0x16, 3, 7.0f);
            P_F(0xC20) = 0.8000000119f;
            goto finish;
        } else if (ACTION == 15) {
            blend = 5.0f;
            animation = 21;
        } else if (ACTION == 11) {
            animation = P_I(0x4D4) + 0x1C;
            if (D_001A7A45) {
                if (animation == 0x1C) animation = 0x1D;
                else if (animation == 0x1D) animation = 0x1C;
            }
            if (PREVIOUS_STATE == 4) {
                func_L00_002D2168(animation, 1, 4.0f);
                P_S(0x4AC) = 1;
                goto finish;
            }
            blend = 5.0f;
        } else {
            goto finish;
        }
        break;
    case 8:
        STATE = 5;
        P_W(0x1188) = 0x68;
        P_W(0x24A0) = 0;
        if (P_F(0x170) > 0.075f) func_L00_002B6118(0.075f / P_F(0x170));
        P_W(0x24C8) = 0;
        P_V(0xF0).q = P_V(0x110).q;
        if (!animate) goto finish;
        blend = -2.0f;
        animation = 0x13;
        break;
    case 0x13: case 0x14: case 0x15: case 0x1F:
    case 0x22: case 0x4D: case 0x83: case 0x93:
        /* Attack bookkeeping uses saturating 16-bit counters and unsigned maxima. */
        STATE = 6;
        if (P_I(0x1500) && (u32)(ACTION - 0x13) < 3) {
            limit = D_001A7390;
            if (P_H(0x293C) != 0xFFFF) { P_H(0x293C)++; limit = D_001A7390; }
            if (P_W(0x2940) < limit) P_W(0x2940) = limit;
            P_W(0x2944) |= (1u << (D_001A79F0 & 31)) | 0x80000000u;
            if (P_H(0x27E0) != 0xFFFF) P_H(0x27E0)++;
            if (P_W(0x27E4) < D_001A7390) P_W(0x27E4) = D_001A7390;
            P_W(0x27E8) |= (1u << (D_001A79F0 & 31)) | 0x80000000u;
            func_L00_002BA508();
            ACTION = PREVIOUS_ACTION;
            STATE = PREVIOUS_STATE;
            goto finish;
        }
        if (action != 0x83) P_W(0x24A0) = 0;
        P_F(0xBF4) = 1.0f;
        P_I(0xBE8) = 0;
        P_W(0xBE4) = 0;
        P_H(0xBFE) = 0;
        if (ACTION == 0x15) {
            limit = D_001A7390;
            if (P_H(0x293C) != 0xFFFF) { P_H(0x293C)++; limit = D_001A7390; }
            if (P_W(0x2940) < limit) P_W(0x2940) = limit;
            P_W(0x2944) |= (1u << (D_001A79F0 & 31)) | 0x80000000u;
            if (P_H(0x27E0) != 0xFFFF) P_H(0x27E0)++;
            if (P_W(0x27E4) < D_001A7390) P_W(0x27E4) = D_001A7390;
            P_W(0x27E8) |= (1u << (D_001A79F0 & 31)) | 0x80000000u;
            P_S(0xBFC) = 3;
            P_W(0x2300) = 0;
            func_L00_002B75A0(14.0f, 0.52359885f, -1.0f);
            P_W(0xC0C) = P_W(0xC0C) == 0;
            if (animate) {
                frames = (u8)OBJECT[0x43] == 0x1A ? 3 : 10;
                if (PREVIOUS_ACTION == 1) frames = 17;
                func_L00_002D2168(0x1A, 0, (float)frames);
                func_L00_002D2470(6, 0x15);
            }
            goto finish;
        }
        if (ACTION > 0x15) {
            if (ACTION == 0x22) {
                if (animate) func_L00_002D2168(0x2C, 7, 9.0f);
                actor = P_PTR(0xBE0);
                if (P_I(0x1248) == 12 && actor) {
                    P_I(0xBE8) = 1;
                    P_F(0xBEC) = func_00283248(*(float *)(actor + 0x10) - P_F(0x80),
                                               *(float *)(actor + 0x14) - P_F(0x84));
                    func_00282CF0(P_ADDR(0xBC0), actor + 0x10, P_ADDR(0x80));
                }
            } else if (ACTION < 0x23) {
                if (ACTION == 0x1F && P_PTR(0x1220)) {
                    func_L00_002D6900(0x13);
                    if (animate) {
                        func_L00_002D2168(0x60, 4, -1.0f);
                        func_002A7470(P_PTR(0x1220), 3, 4, -1);
                    }
                    func_L00_002B75A0(11.0f, 0.87266469f, -1.0f);
                }
            } else if (ACTION == 0x83) {
                P_S(0xBFC) = 3;
                func_L00_0041E958(64.0f, 0.17453295f, 0.3490659f);
                if (animate) {
                    frames = (u8)OBJECT[0x43] == 0x1A ? 3 : 10;
                    if (PREVIOUS_ACTION == 1) frames = 17;
                    func_L00_002D2168(0x1A, 0, (float)frames);
                }
            }
            goto finish;
        }
        if (ACTION != 0x13) {
            if (ACTION == 0x14) {
                if (P_H(0x2930) != 0xFFFF) P_H(0x2930)++;
                if (P_W(0x2934) < D_001A7390) P_W(0x2934) = D_001A7390;
                P_W(0x2938) |= (1u << (D_001A79F0 & 31)) | 0x80000000u;
                P_W(0x24A0) = 0x50;
                P_S(0xBFC) = 4;
                P_W(0x2300) = 0;
                func_L00_002B75A0(8.0f, 1.0471977f, -1.0f);
                P_W(0xC00) = 0;
                if (animate) {
                    frames = PREVIOUS_ACTION == 11 && PREVIOUS_FRAME < 42 ? 17 : 11;
                    func_L00_002D2168(0x2B, 4, (float)frames);
                    actor = (char *)func_L00_002ADE68(0);
                    if (func_L00_002B3248((u8 *)actor))
                        func_002A7470(actor, 10, 4, frames + 2);
                }
            }
            goto finish;
        }
        limit = D_001A7390;
        if (P_H(0x25B8) != 0xFFFF) { P_H(0x25B8)++; limit = D_001A7390; }
        if (P_W(0x25BC) < limit) P_W(0x25BC) = limit;
        P_W(0x25C0) |= (1u << (D_001A79F0 & 31)) | 0x80000000u;
        phase = P_S(0xBFC);
        attackStep = 0;
        P_W(0x2300) = 0;
        if (PREVIOUS_ACTION != 0x13 || (float)D_L08_00268114[phase].limit <= P_F(0xC38)) {
            if (OLDER_ACTION == 0x13 && P_I(0x1B8) + PREVIOUS_FRAME < 27)
                attackStep = (D_L08_00268114[phase].variant + 1) % 3;
        } else {
            attackStep = (D_L08_00268114[phase].variant + 1) % 3;
        }
        P_S(0xBFC) = attackStep;
        func_L00_002B75A0(5.0f, 0.78539824f, 0.78539824f);
        if (animate) {
            flags = 0;
            if (attackStep == 0) {
                frames = 5;
            } else {
                flags = attackStep == 1 ? 2 : 4;
                frames = 7;
            }
            if (P_I(0xBE8) && attackStep < 2) {
                if (P_B(0x22C3) == 0)
                    angle = func_00283C80(P_F(0xBEC), P_F(0x98));
                else
                    angle = func_L00_002B9B38(P_ADDR(0xBC0), 0);
                frames += func_00283CF0(angle * 1.5f);
            }
            func_L00_002D2168(attackStep + 0x17, flags / 2, (float)frames);
            actor = (char *)func_L00_002ADE68(0);
            if (func_L00_002B3248((u8 *)actor))
                func_002A7470(actor, attackStep + 3, flags / 2, frames);
        }
        goto finish;
    case 0x16:
        STATE = 7;
        P_W(0x24A0) = 0;
        func_L00_002B6118(0.5f);
        func_L00_002D6900(18);
        P_H(0x20E) = 45;
        P_V(0xF0).q = P_V(0x120).q;
        func_002AC9F8(P_V(0xF0).f, 0.116666675f);
        actor = func_002A9640(OBJECT, 1, 0);
        func_L00_002A4EF8(actor ? func_00283CF0(*(float *)(actor + 0x2C)) : 1);
        P_H(0x1DC) = 77;
        if (!animate) goto finish;
        animation = 16;
        flags = 3;
        goto playResponse;
    case 0x17:
        STATE = 3;
        P_W(0x24A0) = 13;
        P_F(0x57C) = 0.0061111115f;
        P_F(0x580) = P_F(0x88);
        if (PREVIOUS_STATE == 4) {
            P_F(0x57C) = P_F(0x520);
            P_F(0x580) = P_F(0x490);
        }
        P_B(0x22BC) = 1;
        P_B(0x22BF) = 1;
        if (!animate) goto finish;
        animation = 0x20;
        if (P_F(0x174) <= 0.058333337f) {
            func_L00_002D2168(animation, 1, 11.0f);
            goto finish;
        }
        blend = 9.0f;
        break;
    case 0x18:
        STATE = 3;
        P_W(0x1188) = 0x68;
        P_W(0x24A0) = 13;
        P_B(0x22BC) = 1;
        P_B(0x22BF) = 1;
        if (!animate) goto finish;
        animation = 0x21;
        blend = 6.0f;
        break;
    case 0x19:
        P_B(0x22BC) = 1;
        STATE = 3;
        P_W(0x24A0) = 13;
        P_B(0x22BF) = 1;
        if (!animate) goto finish;
        animation = 0x24;
        blend = 6.0f;
        break;
    case 0x1A:
        P_B(0x22BC) = 1;
        STATE = 3;
        P_W(0x24A0) = 13;
        P_B(0x22BF) = 1;
        if (!animate) goto finish;
        animation = 0x25;
        blend = 6.0f;
        break;
    case 0x1C:
        P_B(0x22BC) = 1;
        STATE = 9;
        P_W(0x24A0) = 0;
        animation = func_L04_002CC748(0);
        blend = 10.0f;
        break;
    case 0x1E:
        STATE = 9;
        P_W(0x24A0) = 0;
        animation = func_L04_002CC748(0);
        blend = 10.0f;
        break;
    case 0x1D:
        P_W(0x24A0) = 0x51;
        STATE = 0;
        variantType = func_L00_002A4EF0((u8)OBJECT[0x42]);
        if (variantType == func_L04_002CC748(0)) goto finish;
        animation = func_L04_002CC748(0);
        blend = 5.0f;
        break;
    case 0x23:
        STATE = 13;
        P_W(0x24A0) = 7;
        if (P_H(0x25DC) != 0xFFFF) P_H(0x25DC)++;
        if (P_W(0x25E0) < D_001A7390) P_W(0x25E0) = D_001A7390;
        P_W(0x25E4) |= (1u << (D_001A79F0 & 31)) | 0x80000000u;
        actor = P_PTR(0xAA4);
        P_F(0x1A0) = func_00283248(*(float *)(actor + 0x10) - P_F(0x80),
                                   *(float *)(actor + 0x14) - P_F(0x84));
        if (PREVIOUS_ACTION == 0x28) P_V(0x160).q = P_V(0xF0).q;
        goto playTargetAction;
    case 0x24:
        P_B(0x22BC) = 1;
        STATE = 13;
        P_W(0x24A0) = 7;
        P_W(0xAA0) = 0;
        P_W(0xAB4) = 0;
        if (animate) func_L00_002D2168(0x30, 1, 10.0f);
        goto finish;
    case 0x25:
        P_B(0x22BC) = 1;
        STATE = 13;
        P_W(0x24A0) = 7;
        P_W(0xAA0) = 0;
        P_W(0xAB4) = 0;
        P_F(0xABC) = func_00282E48(P_ADDR(0x80), P_PTR(0xAA4) + 0x10);
        if (animate) func_L00_002D2168(0x30, 1, 5.0f);
        goto finish;
    case 0x26:
        STATE = 8;
        P_W(0x24A0) = 0;
        animation = func_L04_002CC748(0);
        blend = 10.0f;
        break;
    case 0x2B:
        STATE = 14;
        P_W(0x24A0) = 7;
        if (P_H(0x25DC) != 0xFFFF) P_H(0x25DC)++;
        if (P_W(0x25E0) < D_001A7390) P_W(0x25E0) = D_001A7390;
        P_H(0xAFE) = 1;
        P_W(0x25E4) |= (1u << (D_001A79F0 & 31)) | 0x80000000u;
        P_W(0xAE8) = 0;
        P_B(0x22BC) = 1;
        P_PTR(0xAD4) = P_PTR(0xAD0);
        P_H(0xADC) = 0;
        P_H(0xAFC) = 0;
        P_W(0xAF4) = 0;
        P_W(0xAF8) = 0;
        data = *(char **)(P_PTR(0xAD0) + 0x68);
        P_W(0xAE0) = *(u32 *)(data + 4);
        angle = *(float *)(data + 0x10);
        if (angle == 0.0f) angle = *(float *)(data + 12);
        *(float *)(data + 0x14) = angle;
        P_F(0xB08) = 0.33f;
        P_F(0xB0C) = 0.18333334f;
        P_F(0xB04) = 0.025f;
        func_00282C88(&P_V(0xA0).q);
        P_H(0x206) = 40;
        if (*(float *)(data + 0x24) != 0.0f) P_F(0xB04) = *(float *)(data + 0x24);
        if (*(float *)(data + 0x28) != 0.0f) P_F(0xB08) = *(float *)(data + 0x28);
        if (*(float *)(data + 0x2C) != 0.0f) P_F(0xB0C) = *(float *)(data + 0x2C);
        actor = P_PTR(0xAD4);
        P_F(0xAEC) = func_00283248(*(float *)(actor + 0x10) - P_F(0x80),
                                   *(float *)(actor + 0x14) - P_F(0x84));
        P_F(0xAE4) = func_00282E48(P_ADDR(0x80), actor + 0x10);
        P_F(0xAF0) = 0.0075000003f;
        if (PREVIOUS_STATE == 4) P_F(0xAF0) = P_F(0x520);
        else if (PREVIOUS_STATE == 2) P_F(0xAF0) = P_F(0xA80);
        if (animate) {
            func_L00_002D2168(0x34, 0, 11.0f);
            P_F(0xC20) = 0.6999999881f;
        }
        goto finish;
    case 0x2C:
        P_W(0x24A0) = 7;
        STATE = 2;
        func_00282C88(&P_V(0xA0).q);
        P_V(0xF0).q = P_V(0x120).q;
        if (!animate) goto finish;
        animation = 11;
        blend = 15.0f;
        break;
    case 0x2F:
        STATE = 8;
        P_W(0x24A0) = 0;
        P_V(0x160).q = P_V(0x110).q;
        func_L00_002D2168(func_L04_002CC748(0), 0, 5.0f);
        P_H(0x1EC) = 7;
        goto finish;
    case 0x31:
        STATE = 9;
        P_B(0x22BC) = 1;
        P_W(0x24A0) = 0;
        P_B(0x22B7) = 1;
        P_B(0x22BD) = 1;
        func_L00_00322EC8(P_ADDR(0x1A30));
        if (!animate) goto finish;
        animation = func_L04_002CC748(0);
        blend = -1.0f;
        break;
    case 0x32:
        STATE = 17;
        P_W(0x24A0) = 11;
        P_B(0x22B7) = 1;
        P_W(0xA3C) = 0;
        if (PREVIOUS_STATE == 18) { func_L00_002B9B88(3, 0); VARIANT = 1; }
        else P_W(0xA34) = 45;
        P_W(0x1188) = 0x68;
        P_W(0xA20) = 0;
        if (!animate) goto finish;
        blend = 12.0f;
        animation = 0x3B;
        break;
    case 0x33:
        STATE = 17;
        P_W(0x24A0) = 11;
        P_B(0x22B7) = 1;
        P_V(0x160).q = P_V(0x120).q;
        P_W(0x1188) = 0x68;
        frames = PREVIOUS_ACTION == 0x34 ? -2 : 35;
        if (!animate) goto finish;
        blend = (float)frames;
        animation = 0x3C;
        break;
    case 0x34:
        STATE = 17;
        P_B(0x22B7) = 1;
        P_W(0xA34) = 60;
        P_W(0x24A0) = 11;
        if (PREVIOUS_STATE == 18) { func_L00_002B9B88(3, 0); VARIANT = 1; }
        frames = PREVIOUS_ACTION != 0x32 ? 11 : 15;
        P_W(0x1188) = 0x68;
        P_W(0xA20) = 0;
        if (animate) func_L00_002D2168(0x3D, 0, (float)frames);
        goto finish;
    case 0x35:
        STATE = 18;
        P_W(0x1188) = 0x68;
        P_B(0x22B7) = 1;
        P_W(0x798) = 45;
        P_W(0x24A0) = 0;
        P_W(0xA3C) = 0;
        if (!animate) goto finish;
        blend = 17.0f;
        animation = 0x5E;
        break;
    case 0x36:
        STATE = 18;
        P_B(0x22B7) = 1;
        P_W(0x24A0) = 0;
        P_H(0xA4A) = 0;
        if (PREVIOUS_STATE == 17) {
            func_L00_002AABE0(3, 10, 0);
            if (D_L08_001B3170)
                func_002FD1B8(D_L08_001B3170, D_L08_001B3178, 0,
                             P_F(0x80), P_F(0x84), 0.4f, 0.3f);
        } else if (P_F(0x118) < -0.008333334f) {
            frames = func_00283CF0(func_00282C48(P_F(0x118)) * 300.0f);
            if (frames >= 41) frames = 40;
            func_L00_002AABE0(3, frames, 1);
            if (D_L08_001B3170)
                func_002FD1B8(D_L08_001B3170, D_L08_001B3178, 0,
                             P_F(0x80), P_F(0x84), 0.5f, -0.4f);
            P_H(0xA4A) = 75;
        }
        P_F(0x794) = P_F(0x118) * 0.37f;
        P_W(0x798) = 0;
        if (P_F(0x794) < -0.116666675f) P_F(0x794) = -0.116666675f;
        P_F(0x79C) = P_F(0x330);
        P_W(0x7A0) = 0;
        P_F(0x790) = (P_F(0x88) - P_F(0x330)) - -0.12f;
        P_V(0x160).q = P_V(0x120).q;
        P_F(0x168) = 0.0f;
        func_002AC9F8(P_V(0x160).f, 0.09166667f);
        P_W(0x1188) = 0x68;
        if (!animate) goto finish;
        blend = 22.0f;
        animation = 0x3A;
        break;
    case 0x39:
        STATE = 20;
        P_W(0x24A0) = 0;
        P_V(0x160).q = P_V(0x120).q;
        if (!animate) goto finish;
        animation = 0x45;
        blend = 12.0f;
        break;
    case 0x3D:
        func_L00_002D2168(func_L04_002CC748(0), 0, 9.0f);
        if (P_PTR(0x1854)) func_002A7470(P_PTR(0x1854), 0, 0, 9);
        goto finish;
    case 0x3E:
        STATE = 15;
        P_W(0x24A0) = 0;
        if (P_I(0x640) == 0) {
            actor = P_PTR(0x6C4);
            if (actor == 0) {
                func_L00_002A4EF8(1);
            } else {
                func_L00_002A4EF8(func_00283CF0(*(float *)(actor + 0x2C)));
                P_PTR(0x6C4) = 0;
            }
        }
        func_L00_002B9B88(20, 0);
        if (P_I(0x24CC) < 1) {
            angle = func_00283248(P_F(0xF0), P_F(0xF4));
            angle = func_00283B98(angle, 3.141593f);
            variation = func_002A78D8(0.52359885f, 0.6108653f);
            angle = func_00283B98(angle, variation);
            P_F(0x120) = func_00283180(angle) * P_F(0x644) * 0.7f;
            P_F(0x124) = func_00283198(angle) * P_F(0x644) * 0.7f;
            P_F(0x128) = 0.075f;
            if (P_I(0x640) > 15 && P_I(0x24CC) < 2) P_I(0x24CC) = 2;
            OBJECT[0xA8] = 0xFF;
            func_L08_002D2ED8(0x16, 1);
            P_H(0x1D0) = 70;
            P_H(0x1F4) = 150;
            return 0;
        }
        P_H(0x1DC) = 77;
        P_F(0x69C) = 0.04166666791f;
        if (P_F(0x680) > 0.041666668f) P_F(0x680) = 0.041666668f;
        P_W(0x674) = 0;
        func_00282C88(&P_V(0xF0).q);
        func_00282C88(&P_V(0x110).q);
        P_F(0xF8) = 0.18333334f;
        if (animate) func_L00_002D2168(16, 2, -3.0f);
        goto finish;
    case 0x60: case 0x61:
        STATE = 24;
        P_B(0x22BC) = 1;
        func_L00_00322EC8(P_ADDR(0x1A30));
        func_L00_002AF7D0();
        if (animate) func_L00_002D2168(func_L04_002CC748(0), 0, -1.0f);
        goto finish;
    case 0x62:
        STATE = 1;
        P_W(0x24A0) = 0;
        P_F(0x1B4) = func_00282E20(P_ADDR(0x120));
        P_B(0x22BC) = 1;
        if (MODE == 0) func_L00_002AF7D0();
        if (!animate) goto finish;
        animation = 2;
        if (MODE != 1) {
            if (MODE != 0) goto finish;
            func_L00_002D2168(VARIANT + 3, D_L08_001A7DD8[VARIANT], 8.0f);
            goto finish;
        }
        blend = 8.0f;
        break;
    case 0x63:
        STATE = 1;
        P_W(0x24A0) = 0;
        P_F(0x1B4) = func_L00_002D3A58(P_ADDR(0x120));
        P_V(0x160).q = P_V(0x120).q;
        if (!animate) goto finish;
        sourceAnimation = (u8)originalObject[0x42];
        goto chooseLocomotion;
    case 0x64:
        STATE = 0;
        P_W(0x24A0) = 0;
        func_00282C88(&P_V(0x160).q);
        P_W(0x1188) = 0x68;
        if (!animate) goto finish;
        animation = func_L04_002CC748(0);
        blend = animation == 0x51 ? 18.0f : -1.0f;
        animation = func_L04_002CC748(0);
        break;
    case 0x65:
        STATE = 25;
        P_I(0x18C0)++;
        P_W(0x24A0) = 0;
        func_L00_002B9B88(7, 0);
        P_W(0x3A0) = 0;
        P_W(0x1188) = 0x68;
        P_W(0x1B0) = 0;
        P_F(0x1B4) = 0.0f;
        if (!animate) goto finish;
        blend = 8.0f;
        animation = 0x6A;
        break;
    case 0x67:
        STATE = 20;
        P_B(0x22B7) = 1;
        P_W(0x24A0) = 0;
        if (P_S(0xA4E) > 50 && P_H(0x29C0) != 0xFFFF) P_H(0x29C0)++;
        if (P_W(0x29C4) < D_001A7390) P_W(0x29C4) = D_001A7390;
        P_W(0x29C8) |= (1u << (D_001A79F0 & 31)) | 0x80000000u;
        if (P_I(0xA50) > 2 && P_H(0x2A8C) != 0xFFFF) P_H(0x2A8C)++;
        if (P_W(0x2A90) < D_001A7390) P_W(0x2A90) = D_001A7390;
        P_W(0x2A94) |= (1u << (D_001A79F0 & 31)) | 0x80000000u;
        P_V(0x160).q = P_V(0x120).q;
        if (!animate) goto finish;
        animation = 0x58;
        blend = 10.0f;
        break;
    case 0x6D:
        STATE = 6;
        P_H(0xBFE) = 0;
        if (PREVIOUS_ACTION == 0x6D) {
            phase = P_S(0xBFC);
            P_S(0xBFC) = 5;
            if (D_L08_00268114[phase].variant == 0) P_S(0xBFC) = 6;
        } else {
            P_S(0xBFC) = 5;
        }
        followUp = D_L08_00268114[P_S(0xBFC)].variant;
        if (animate) {
            func_L00_002D2168(followUp + 0x17, followUp == 0, 5.0f);
            actor = (char *)func_L00_002ADE68(0);
            if (func_L00_002B3248((u8 *)actor))
                func_002A7470(actor, followUp + 12, followUp == 0, 5);
        }
        goto finish;
    case 0x6F:
        STATE = 9;
        P_B(0x22BC) = 1;
        P_W(0x24A0) = 0;
        func_L00_002AF7D0();
        if (!animate) goto finish;
        animation = func_L04_002CC748(0);
        blend = 10.0f;
        break;
    case 0x72: case 0x73:
        STATE = 7;
        P_W(0x24A0) = 0;
        func_L00_002B6118(0.5f);
        P_B(0x22B7) = 1;
        P_V(0xF0).q = P_V(0x110).q;
        actor = func_002A9640(OBJECT, 1, 0);
        func_L00_002A4EF8(actor ? func_00283CF0(*(float *)(actor + 0x2C)) : 1);
        P_H(0x1DC) = 77;
        if (animate) {
            func_L00_002D2168(ACTION == 0x72 ? 0x69 : 0x68, 3, -3.0f);
            goto updateResponseFrame;
        }
        goto finish;
    case 0x75:
        P_B(0x22BC) = 1;
        STATE = 9;
        P_W(0x24A0) = 0;
        P_B(0x22B7) = 1;
        func_00282C88(&P_V(0xF0).q);
        if (!animate) goto finish;
        animation = 11;
        blend = -1.0f;
        break;
    case 0x76:
        STATE = 2;
        P_W(0x24A0) = 0;
        P_V(0xF0).q = P_V(0x120).q;
        if (!animate) goto finish;
        animation = 11;
        blend = 12.0f;
        break;
    case 0x77:
        STATE = 10;
        P_W(0x24A0) = 0;
        P_F(0xBF0) = func_00283B98(P_F(0x98), 3.141593f);
        func_00282D30(P_ADDR(0xBD0), P_ADDR(0), -1.0f);
        P_F(0x1B4) = 0.15f;
        if (animate) func_L00_002D2168(0x29, 5, 8.0f);
        goto finish;
    case 0x78:
        P_H(0x1F0) = 10000;
        STATE = 25;
        P_W(0x24A0) = 0;
        func_L00_002B9B88(7, 0);
        P_W(0x1188) = 0x68;
        if (!animate) goto finish;
        animation = 0x6A;
        blend = 8.0f;
        break;
    case 0x7B:
        P_W(0x1188) = 0x68;
        STATE = 28;
        P_W(0x24A0) = 0;
        P_V(0xF0).q = P_V(0x110).q;
        if (P_I(0x1298) != 0x36) {
            P_W(0x22CC) = 0x36;
            P_I(0x2304) = P_I(0x1298);
        }
        if (!animate) goto finish;
        animation = 0x8B;
        blend = -2.0f;
        break;
    case 0x7C:
        P_F(0x794) = P_F(0x118) * 0.2f;
        P_F(0x79C) = P_F(0x330) - 0.37f;
        STATE = 20;
        P_H(0x1F0) = 10000;
        P_W(0x24A0) = 0;
        P_I(0x24CC) = 0;
        if (P_F(0x794) < -0.116666675f) P_F(0x794) = -0.116666675f;
        P_B(0x22B7) = 1;
        P_F(0x790) = P_F(0x88) - P_F(0x79C);
        P_W(0x7A0) = 0;
        if (!animate) goto finish;
        animation = 0x6D;
        blend = 11.0f;
        break;
    case 0x7F:
        STATE = 20;
        P_B(0x22B7) = 1;
        P_W(0x24A0) = 0;
        P_V(0x160).q = P_V(0x120).q;
        if (!animate) goto finish;
        animation = 0x79;
        blend = 10.0f;
        break;
    case 0x82:
        STATE = 30;
        P_W(0x24A0) = 0;
        if (PREVIOUS_ACTION != 0x16) {
            P_F(0x5B0) = 50.0f;
            if (P_F(0x5B8) != 0.0f) {
                blend = P_F(0x5B8);
                P_F(0x5B8) = 0.0f;
                P_F(0x5B0) = blend;
            }
        }
        P_B(0x24EF) = 1;
        P_W(0x1188) = 0x68;
        P_W(0x7A8) = 0;
        P_H(0x5BE) = 0;
        P_W(0x5A8) = 0;
        P_W(0x5A4) = 0;
        P_V(0xF0).q = P_V(0x110).q;
        P_H(0x5BC) = 7;
        if (!animate) goto finish;
        animation = 0x13;
        blend = -2.0f;
        break;
    case 0x85:
        STATE = 32;
        P_W(0x24A0) = 8;
        P_B(0x22C2) = 1;
        P_B(0x22B7) = 1;
        if (animate) func_L00_002D2168(0x4F, 0, 5.0f);
        actor = P_PTR(0x1830);
        P_F(0x98) = *(float *)(actor + 0xF8);
        P_V(0x80).q = *(Quad *)(actor + 0x10);
        func_00282C88(&P_V(0xF0).q);
        goto finish;
    case 0x8A:
        STATE = 33;
        P_W(0x24A0) = 0;
        if (P_H(0x25DC) != 0xFFFF) P_H(0x25DC)++;
        if (P_W(0x25E0) < D_001A7390) P_W(0x25E0) = D_001A7390;
        P_W(0x25E4) |= (1u << (D_001A79F0 & 31)) | 0x80000000u;
        actor = P_PTR(0xB10);
        P_F(0x1A0) = func_00283248(*(float *)(actor + 0x10) - P_F(0x80),
                                   *(float *)(actor + 0x14) - P_F(0x84));
        P_W(0xB1C) = 0;
playTargetAction:
        if (animate) {
            func_L00_002D2168(0x2F, 2, 5.0f);
            func_L00_002D2470(10, 14);
        }
        goto finish;
    case 0x8B:
        STATE = 33;
        P_B(0x22BC) = 1;
        P_W(0x24A0) = 0;
        goto finish;
    case 0x8C:
        STATE = 7;
        P_W(0x24A0) = 0;
        func_L00_002B6118(0.5f);
        P_B(0x22BC) = 1;
        func_L00_002D6900(18);
        actor = func_002A9640(OBJECT, 8, 0);
        func_L00_002A4EF8(actor ? func_00283CF0(*(float *)(actor + 0x2C)) : 1);
        P_H(0x1DC) = 77;
        if (!animate) goto finish;
        animation = 0x96;
        flags = 1;
playResponse:
        P_H(0x1DC) = 77;
        func_L00_002D2168(animation, flags, -3.0f);
updateResponseFrame:
        frameIndex = P_I(0xC34);
        P_I(0xC34)++;
        *(u32 *)(OBJECT + 0x44) = D_L08_002682A0[P_I(0xC30)][frameIndex];
        goto finish;
    default:
        goto finish;
    }
    func_L00_002D2168(animation, 0, blend);
    goto finish;

chooseLocomotion:
    blend = P_F(0xC38);
    animation = 6;
    if (func_L00_002A4EF0((u8)sourceAnimation) == 4 && blend > 3.0f && blend < 16.0f)
        animation = 5;
    func_L00_002D2168(animation, 4, 9.0f);
    goto finish;

redirect:
    func_L08_002D2ED8(redirectAction, 1);
    return 0;

finish:
    if (oldModeFlag && P_B(0x22B7) == 0) P_W(0x231C) = 1;
    if (P_S(0x348) == 0 && P_I(0x1298) == 0x13 && P_I(0x2304) != 0)
        P_W(0x2320) = 1;
    if ((u32)(STATE - 13) > 2 && (ACTION != 6 || PREVIOUS_ACTION != 0x24) &&
        P_I(0x1298) == 20 && P_I(0x2304) != 0)
        P_W(0x2320) = 1;
    if (STATE == 20) {
        func_L00_002AF7D0();
        P_B(0x22BC) = 1;
    }
    if ((!func_L00_002ADF80() || STATE == 18) &&
        (P_F(0x330) < D_L08_001B9B08 || STATE == 0))
        D_L08_001B9DC0 = 0;
    if (STATE != PREVIOUS_STATE) func_L00_002A6708();
    if (STATE != PREVIOUS_STATE) P_W(0x1BC) = 0;
    P_W(0x1C4) = 0;
    P_W(0x1C0) = 0;
    P_I(0x1B8) = 0;
    return 1;
}
