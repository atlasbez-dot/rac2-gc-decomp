/* Retained 23 October 2026 reconstruction of the complete 21-state update.
   Game -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
   -frac2-zero-ti-barrier: 5172/5228 bytes, 0/1 USA v1.01 placements;
   absent from the USA v2.00 and PAL catalogues. Canonical direct-call identity counts
   agree (161 sites in each body), but this is not byte-match or runtime proof.
   Remaining differences span address formation, GPR/FPR allocation, stores,
   scheduling and state-branch sharing; equal stack size (0x1a0) is insufficient.

   Ten bounded trials covered actual pointer/value lifetimes, the partial resident
   view below, shared versus per-state cleanup stores, countdown pointer loops,
   -g, -fno-gcse and the qualified block-order/unsplit-edge profiles. Sizes ranged
   from 5120 to 5348 bytes. The 5244-byte form duplicated six static call sites
   (167 versus 161), so the more faithful shared-cleanup form is retained.

   The jump table was read from retail and cross-checked against a freshly recovered
   reference switch. Matrix outputs are full 64-byte objects, with explicit column
   views. The particle helper has all eight GPR, two FP and four stack arguments;
   its final stack slot and pointer return are preserved. The wrapper
   func_L02_00332630 forwards func_L02_00332668's int result, which this caller
   consumes, despite its historical void C definition. Action helpers whose result
   is discarded retain provisional result declarations where retail supplies no
   deliberate return-bank evidence; these contracts are not claimed recovered.

   Reopen with independent original state/control/layout or return-contract evidence,
   or a qualified compiler explanation for the measured differences. Do not repeat
   the same lifetime/cleanup/flag trials or classify the ordinary MMI copies as
   handwritten. No linked builds or integrated match are claimed. */
#include "include_asm.h"

typedef int Quad __attribute__((mode(TI)));
typedef unsigned char u8;
typedef struct {
    char prefix[0x18]; u8 enabled, count, kind;
    char reserved[0x65]; u8 payload[1];
} DispatchContext;
typedef struct LvlSlotNode { char prefix[0x1c]; struct LvlSlotNode *next; } LvlSlotNode;
typedef struct LvlSlotCtx { char prefix[0x50]; LvlSlotNode *head; } LvlSlotCtx;
extern unsigned char D_00189E20[];
/* A partial resident view; the external byte array keeps its unknown full extent. */
typedef struct {
    u8 prefix[0x80];
    float position[4];
    u8 middle[0x2200];
    char *player;
} ResidentHeroView;
extern void *D_L23_002AB4C0[];
extern u8 *D_L23_00259560[];
extern float D_L23_001B36A0 __attribute__((nosda));
extern float D_L23_001B36A4 __attribute__((nosda));
extern int D_L23_001B36AC __attribute__((nosda));
extern int D_L23_001B3710 __attribute__((nosda));
extern int D_L23_001B3714 __attribute__((nosda));
extern int D_L23_001B3718 __attribute__((nosda));
extern float D_L23_001B36C0[4] __attribute__((nosda));
extern float D_L23_001B36D0[4] __attribute__((nosda));
extern float D_L23_001B3760[4] __attribute__((nosda));
extern float D_L23_001B3770[4] __attribute__((nosda));
extern float D_L23_001B3860[4] __attribute__((nosda));
extern float D_L23_001B3880[4] __attribute__((nosda));
extern float D_L23_001BA640[4] __attribute__((nosda));
extern Quad D_L23_001BA870[] __attribute__((nosda));
extern Quad D_L23_001C87C0 __attribute__((nosda));
extern Quad D_L23_001C87D0 __attribute__((nosda));
extern float D_L23_001B13D8 __attribute__((sda));
extern float D_L23_001B13DC __attribute__((sda));
extern float D_L23_001B13E0 __attribute__((sda));
extern int D_L23_001B13E4 __attribute__((sda));
extern int D_L23_001B13EC __attribute__((sda));
extern int D_L23_001B140C __attribute__((sda));
extern float D_L23_001B1410 __attribute__((sda));
extern float D_L23_001B1420 __attribute__((sda));
extern int D_L23_001B1424 __attribute__((sda));
extern int D_L23_001B1428 __attribute__((sda));
extern int D_L23_001B142C __attribute__((sda));
extern int D_L23_001B1430 __attribute__((sda));
extern u8 *D_L23_001B1484 __attribute__((sda));
extern float D_L23_001B1488 __attribute__((sda));
extern float D_L23_001B148C __attribute__((sda));
extern float D_L23_001B1494 __attribute__((sda));
extern float D_L23_001B1498 __attribute__((sda));
extern float D_L23_001B14C4 __attribute__((sda));
extern float D_L23_001B14C8 __attribute__((sda));
extern float D_L23_001B14CC __attribute__((sda));
extern float D_L23_001B14D0 __attribute__((sda));
extern float D_L23_001B14D4 __attribute__((sda));
extern int D_L23_001B14D8 __attribute__((sda));
extern float D_L23_001B14E0 __attribute__((sda));
extern float D_L23_001B14E4 __attribute__((sda));
extern int D_L23_001B14EC __attribute__((sda));
extern int D_L23_001B14F8 __attribute__((sda));
extern float D_L23_001B1500 __attribute__((sda));
extern int D_L23_001B15BC __attribute__((sda));
extern float D_L23_001B1600 __attribute__((sda));
extern float D_L23_001B1604 __attribute__((sda));
extern float D_L23_001B1634 __attribute__((sda));
extern int D_L23_001B1638 __attribute__((sda));
extern int D_L23_001B1648 __attribute__((sda));
extern int D_L23_001B164C __attribute__((sda));
extern float D_L23_001B168C __attribute__((sda));
extern int D_L23_001B1694 __attribute__((sda));
extern float D_L23_001B36FC __attribute__((sda));
extern int D_L23_001B3758 __attribute__((sda));
extern int D_L23_001B3780 __attribute__((sda));

extern int func_00282948(char *);
extern void func_00282D30(char *, char *, float);
extern void func_00282CC0(char *, char *, char *);
extern void func_00282CF0(char *, char *, char *);
extern float func_00282DF0(char *);
extern float func_00282E48(char *, char *);
extern void func_00282F20(char *, char *, float);
extern int func_002761F8(void *, void *, int, void *, void *);
extern float func_002B0360(char *);
extern void func_0029FCC0(char *, int, char *);
extern void func_0029FC20(char *, int, char *);
extern void func_0029F978(u8 *, unsigned int, u8 *);
extern void func_002A7750(u8 *, u8, int);
extern float func_002A7878(float, float);
extern int func_002B3868(u8 *);
extern void func_002AB6D8(float *, float *);
extern int func_002E5CF8(int, int, char *);
extern void func_002E59F8(int);
extern unsigned long func_002B1C20(void *, DispatchContext *);
extern void func_L00_002AF7D0(void);
extern void func_L00_00310C88(LvlSlotCtx *, LvlSlotNode **);
extern void func_L08_004356A0(u8 *, void *);
extern int func_L22_003B9428(unsigned int);
extern int func_L23_00423698(int);
extern void func_L23_00423588(int, int);
extern int func_L00_002D6900(unsigned int);
extern int func_L02_00332630(char *, void *);
extern void func_L23_0041B6D8(char *);
extern void func_L23_00418650(char *, float);
extern void func_L23_004183F0(char *);
extern void func_L23_004180F0(char *);
extern void func_L23_0041B540(char *, float *);
extern void func_L23_0041B668(char *, float *);
extern void func_L23_0041B8F8(char *);
extern void func_L23_0041B960(float);
extern void func_L23_0041BFF0(char *);
extern void func_L23_0041D930(void);
extern void func_L23_0041B5C8(char *);
extern void func_L23_0041B5B0(char *);
extern void func_L23_0041B498(char *);
extern void func_L23_0041A648(char *);
/* Action-helper inputs were checked against retail. Their discarded result
   declarations remain hypotheses where no deliberate result bank is observable. */
extern void func_L23_004177F8(u8 *);
extern void func_L23_00418160(char *);
extern void func_L23_004186D0(char *, float);
extern void func_L23_00419D60(char *);
extern int func_L23_0041A038(char *, char *);
extern int func_L23_0041A3B8(char *, char *);
extern void func_L23_0041A7A0(char *);
extern void func_L23_0041B188(char *);
extern void func_L23_0041C0E8(char *);
extern void func_L23_0041CD58(char *);
extern void func_L23_0041D398(char *);
extern void func_00335370(char *);
extern void func_003353C8(char *);
extern void func_00335438(char *, char *, int, int, void *);
extern char *func_0032C700(char *, int, int, int, int, int, int, int, float, float, int, int, int, void *);
extern void func_0027D330(int);
extern void func_002AF1D0(u8 *, char *, int, int);
extern void func_L00_002B9D60(char *, char *, int, int);
extern int func_L22_002C9898(int, int);
extern char *func_L22_003F85A0(char *, char *);
extern void func_00283898(char *, int, float);

/* Measured accesses to the boss's private state, not a claim about its complete type. */
#define S32(o) (*(int *)(state + (o)))
#define SF(o) (*(float *)(state + (o)))
#define SB(o) (*(u8 *)(state + (o)))
#define SP(o) (*(char **)(state + (o)))
#define SQ(o) (*(Quad *)(state + (o)))
#define FLAGS(p) (*(unsigned short *)((p) + 0x34))
#define AGE (*(unsigned short *)(object + 0x96))
#define HERO ((ResidentHeroView *)D_00189E20)
#define PLAYER (HERO->player)
#define PLAYER_POS ((char *)HERO->position)

void func_L23_00416388(u8 *object)
{
    static void *cases[21] = {&&state_default, &&state1, &&state2, &&state3, &&state4,
        &&state5, &&state6, &&state7, &&state8, &&state9, &&state10, &&state11,
        &&state12, &&state13, &&state14, &&state15, &&state16, &&state_default,
        &&state_default, &&state19, &&state20};
    char direction[16];
    float jointMatrix[16];
    char jointOffset[16];
    char blendedPosition[16];
    char localPosition[16];
    char transform[64];
    char angles[16];
    char secondPosition[16];
    char thirdPosition[16];
    char extraPosition[16];
    char *state = *(char **)(object + 0x68);
    char *position;
    char *jointPosition;
    char *enemy;
    int i;
    float height, distance;
    unsigned int mode;
    int wasActive;

    func_L23_004177F8(object);
    if (D_L23_001B1424 > 200)
        return;
    D_L23_001B1410 = 0.0f;
    func_00282948((char *)&D_L23_001B3714);
    wasActive = S32(0x604);
    D_L23_001B13EC = wasActive != 0;
    if (!wasActive && S32(0x60c) != -1)
        D_L23_001B1430 = 1;
    else
        D_L23_001B1430 = 0;
    if (!D_L23_001B1484)
        return;
    func_L23_0041B6D8((char *)object);
    S32(0x604) = 0;
    func_00282D30((char *)D_L23_001B36C0, PLAYER + 0xe0, D_L23_001B1488);
    func_00282CC0((char *)D_L23_001B36C0, (char *)D_L23_001B36C0, PLAYER_POS);
    func_00282D30((char *)D_L23_001B36D0, PLAYER + 0xe0, D_L23_001B148C);
    func_00282CC0((char *)D_L23_001B36D0, (char *)D_L23_001B36D0, PLAYER_POS);
    SQ(0x3f0) = *(Quad *)PLAYER_POS;
    position = (char *)object + 0x10;
    func_L23_00418650(state + 0x3f0, 0.0f);
    SQ(0x3e0) = *(Quad *)position;
    func_L23_00418650(state + 0x3e0, 0.0f);
    {
        float playerHeight = func_002B0360(PLAYER_POS) - D_L23_001B36A4;
        SF(0x5c0) = playerHeight;
        D_L23_001B3710 = SF(0x588) < playerHeight;
    }
    func_00282CF0(direction, state + 0x3f0, state + 0x3e0);
    SF(0x5b8) = func_00282DF0(direction);
    func_L23_004183F0((char *)object);
    SF(0x5bc) = func_00282E48(position, PLAYER_POS);
    func_0029FCC0((char *)object, 0x2a, jointOffset);
    func_0029FC20((char *)object, 0x27, (char *)jointMatrix);
    func_00282D30((char *)D_L23_001B3860, (char *)jointMatrix, D_L23_001B1600);
    func_00282CC0((char *)D_L23_001B3860, (char *)D_L23_001B3860, jointOffset);
    jointPosition = (char *)jointMatrix + 0x30;
    func_00282CF0(blendedPosition, (char *)D_L23_001B36C0, jointPosition);
    func_00282F20(blendedPosition, blendedPosition, D_L23_001B1604);
    func_00282CC0((char *)D_L23_001B3880, jointPosition, blendedPosition);
    SB(0x404) = 0;
    if (SF(0x5bc) < D_L23_001B1634)
        SB(0x404) = !func_002761F8(D_L23_001B3880, D_L23_001B36C0, 0x10, PLAYER, 0);
    if (D_L23_001B1648 / 2 < D_L23_001B36AC) {
        SB(0x405) = 0;
    } else {
        func_00282948((char *)&D_L23_001B142C);
        if (object[0x20] == 7 &&
            (!SB(0x404) || !object[0x31] || D_L23_001B14E0 + 40.0f < SF(0x5bc)) &&
            !D_L23_001B142C && !S32(0x590)) {
            D_L23_001B142C = D_L23_001B1428;
            func_002A7750(D_L23_00259560[D_L23_001B164C], 6, 0);
            D_L23_001B164C = (D_L23_001B164C + 1) % 25;
        }
        SB(0x405) = 0;
    }
    mode = object[0x20];
    if (mode != 4 && (SF(0x5bc) < D_L23_001B1634 || mode == 16) &&
        (D_L23_001B168C <= SF(0x5b8) || SF(0x5c0) <= SF(0x588)))
        SB(0x405) = func_L02_00332630((char *)object, PLAYER_POS);
    mode = object[0x20];
    if (mode < 21)
        goto *D_L23_002AB4C0[mode];
    goto state_default;
state4:
    func_L23_0041BFF0((char *)object);
    *(short *)(D_00189E20 + 0x1e0) = 10;
    if (func_002B3868(object)) {
        func_L23_0041D930();
        func_0027D330(D_L23_001B13E4);
    } else if (D_L23_001B13E4 / 2 < AGE) {
        func_L23_0041D398((char *)object);
    } else if (AGE == D_L23_001B13E4 / 2 - 4) {
        func_0027D330(1);
        *(Quad *)(transform + 0x00) = D_L23_001BA870[0];
        *(Quad *)(transform + 0x10) = D_L23_001BA870[1];
        *(Quad *)(transform + 0x20) = D_L23_001BA870[2];
        *(Quad *)(transform + 0x30) = 0;
        func_002AB6D8((float *)transform, (float *)localPosition);
        func_00335438((char *)D_L23_001BA640, localPosition, 1, 0, 0);
    } else if (D_L23_001B13E4 / 2 - 4 < AGE) {
        func_0027D330(1);
        *(Quad *)(transform + 0x00) = *(Quad *)(object + 0xc0);
        *(Quad *)(transform + 0x10) = *(Quad *)(object + 0xd0);
        *(Quad *)(transform + 0x20) = *(Quad *)(object + 0xe0);
        *(Quad *)(transform + 0x30) = 0;
        func_002AB6D8((float *)transform, (float *)localPosition);
        func_00282D30(secondPosition, (char *)object + 0xc0, -D_L23_001B13E0);
        func_00282CC0(secondPosition, secondPosition, position);
        func_L23_00418650(secondPosition, 0.0f);
        func_L00_002B9D60(secondPosition, localPosition, 0x6f, 0);
        func_003353C8(localPosition);
        func_00282D30(thirdPosition, (char *)object + 0xc0, -D_L23_001B13D8);
        func_00282CC0(thirdPosition, thirdPosition, position);
        func_L23_00418650(thirdPosition, D_L23_001B13DC);
        func_00335370(thirdPosition);
        D_L23_001C87D0 = 0;
        D_L23_001C87C0 = 0;
    } else {
        func_0027D330(1);
    }
    ++AGE;
    return;
state2:
    if (func_002B3868(object)) {
        func_L23_0041B540((char *)object, &D_L23_001B1498);
        func_L23_0041B668((char *)object, &D_L23_001B14D0);
        if (!SB(0x4b1))
            func_0029F978(object, 0x27, (u8 *)state + 0x4b0);
        SF(0x578) = 1.4726215600967407f;
        func_00283898(state + 0x4c0, 1, 1.4726215600967407f);
    }
    goto state_default;
state3:
    SQ(0x3d0) = *(Quad *)D_L23_001B3760;
    SP(0x400) = state + 0x3d0;
    func_L23_004186D0((char *)object, SF(0x588));
    func_L23_0041A648((char *)object);
    func_002A7750(object, 7, 1);
    goto state_default;
state1:
    func_L23_0041B8F8((char *)object);
    if (func_002B3868(object)) {
        SP(0x400) = (char *)D_L23_001B3760;
        func_L23_0041B540((char *)object, &D_L23_001B1498);
        func_L23_0041B668((char *)object, &D_L23_001B14C4);
    }
    if (func_00282E48(state + 0x3e0, (char *)D_L23_001B3760) < 10.0f)
        func_002A7750(object, 3, 0);
    else
        func_L23_004186D0((char *)object, SF(0x588));
    goto state_default;
state7:
    func_L23_0041B8F8((char *)object);
    func_00282948(state + 0x608);
    if (func_002B3868(object)) {
        func_L23_0041B540((char *)object, &D_L23_001B1494);
        func_L23_0041B668((char *)object, &D_L23_001B14C4);
        func_L23_0041B960(D_L23_001B14E0 + func_002A7878(5.0f, 45.0f));
    }
    if (S32(0x60c) == -1) {
        func_002A7750(object, 6, 1);
        goto state_default;
    }
    if (!(D_L23_001B1648 / 2 < D_L23_001B36AC) && !S32(0x608)) {
        if (D_L23_001B3758 % 3 == 2)
            func_L23_0041B960(D_L23_001B14E0);
        else
            func_L23_0041B960(D_L23_001B14E0 + func_002A7878(25.0f, 55.0f));
        func_002A7750(object, 8, 1);
        ++D_L23_001B3758;
    } else {
        func_L23_0041B188((char *)object);
        if (AGE % 480 == 0) {
            if (D_L23_001B36AC < 4)
                func_L23_0041B960(D_L23_001B14E0 + 60.0f);
            else
                func_L23_0041B960(D_L23_001B14E0 + func_002A7878(-4.0f, 80.0f));
        }
    }
    goto state_default;
state8:
    func_L23_0041B8F8((char *)object);
    func_002B3868(object);
    if (D_L23_001B14E4 - 6.0f <= SF(0x5b8) && SF(0x5b8) <= D_L23_001B14E4 + 6.0f)
        func_002A7750(object, 9, 1);
    else
        func_L23_0041B188((char *)object);
    goto state_default;
state9:
    if (func_002B3868(object)) {
        func_L23_0041B188((char *)object);
        func_L23_0041B668((char *)object, &D_L23_001B14C8);
        S32(0x598) = D_L23_001B14EC;
        func_002E5CF8(6, 0, (char *)object);
    } else if (S32(0x5d8)) {
        if (S32(0x598) <= 0) {
            func_002A7750(object, 10, 1);
        } else {
            if (S32(0x598) == D_L23_001B14EC) {
                int next = D_L23_001B164C;
                func_002E5CF8(0, 0, (char *)object);
                for (i = 0; i < 4; ++i) {
                    enemy = (char *)D_L23_00259560[next];
                    func_002A7750((u8 *)enemy, 2, 0);
                    next = (next + 1) % 25;
                    func_0029FCC0((char *)object, i + 30, transform);
                    func_0029FC20((char *)object, i + 30, (char *)jointMatrix);
                    func_00282D30(localPosition, (char *)jointMatrix + 0x20, -16.0f);
                    *(Quad *)extraPosition = *(Quad *)transform;
                    func_L23_00418650(extraPosition, 0.0f);
                    func_00282CF0(thirdPosition, extraPosition, position);
                    func_00282D30(thirdPosition, thirdPosition, D_L23_001B1420);
                    func_00282CC0(localPosition, localPosition, thirdPosition);
                    func_00282CC0(transform, position, localPosition);
                    func_L23_00418650(transform, 0.0f);
                    *(Quad *)(enemy + 0xc0) = *(Quad *)(object + 0xc0);
                    *(Quad *)(enemy + 0xd0) = *(Quad *)(object + 0xd0);
                    *(Quad *)(enemy + 0xe0) = *(Quad *)(object + 0xe0);
                    *(Quad *)(enemy + 0x10) = *(Quad *)transform;
                }
            }
            func_00282948(state + 0x598);
        }
    }
    goto state_default;
state10:
    if (S32(0x60c) == -1)
        func_L23_0041B8F8((char *)object);
    if (func_002B3868(object))
        func_L23_0041B668((char *)object, &D_L23_001B14C4);
    if (D_L23_001B14CC < SF(0x588)) {
        int enable;
        S32(0x598) = 0;
        S32(0x590) = 4;
        func_002A7750(object, 11, 1);
        enable = D_L23_001B14D8;
        for (i = 0; i < 5; ++i) {
            char *child = SP(0x36c + i * 4);
            if (child) {
                char *source = SP(0x358 + i * 4);
                *(Quad *)(child + 0xc0) = *(Quad *)(source + 0xc0);
                *(Quad *)(child + 0xd0) = *(Quad *)(source + 0xd0);
                *(Quad *)(child + 0xe0) = *(Quad *)(source + 0xe0);
                *(Quad *)(child + 0x10) = *(Quad *)(source + 0x10);
                FLAGS(child) &= 0xbff9;
                *(int *)(child + 0x98) = *(int *)(*(char **)(child + 0x24) + 0x10);
                if (enable)
                    FLAGS(child) &= 0xffbe;
            }
        }
    }
    goto state_default;
state11:
    if (func_002B3868(object))
        func_L23_0041B960(D_L23_001B14E0);
    if (S32(0x60c) == -1)
        func_L23_0041B8F8((char *)object);
    if (S32(0x5d8) && !S32(0x598) && !S32(0x590)) {
        for (i = 0; i < 5; ++i) {
            char *child = SP(0x36c + i * 4);
            if (child) {
                *(int *)(child + 0x98) = 0;
                FLAGS(child) |= 0x41;
            }
        }
        S32(0x608) = D_L23_001B1638;
        if (object[0x31] && SB(0x404)) {
            func_002A7750(object, 13, 2);
            D_L23_001B15BC = func_002E5CF8(8, 4, (char *)object);
            D_L23_001B140C = 0;
        } else {
            func_002A7750(object, 7, 1);
        }
    } else if (S32(0x590) && !S32(0x598)) {
        func_L23_00418160((char *)object);
    }
    func_L23_0041B188((char *)object);
    goto state_default;
state13:
    func_L23_0041B8F8((char *)object);
    if (AGE)
        func_002A7750(object, 14, 2);
    func_L23_0041B188((char *)object);
    goto state_default;
state14:
    func_L23_0041B8F8((char *)object);
    if (AGE >= 40)
        func_002A7750(object, 15, 2);
    func_L23_0041B188((char *)object);
    goto state_default;
state15:
    func_L23_0041B8F8((char *)object);
    func_002B3868(object);
    if (AGE >= 40) {
        if (D_L23_001B15BC != -1) {
            func_002E59F8(D_L23_001B15BC);
            D_L23_001B15BC = -1;
        }
        func_002A7750(object, 7, 1);
    }
    goto state_default;
state12:
    if (!S32(0x598) && !S32(0x590)) {
        func_002A7750(object, 16, 2);
        S32(0x608) = D_L23_001B1638;
    } else if (S32(0x590) && !S32(0x598)) {
        func_L23_00418160((char *)object);
    }
    goto state_default;
state19:
    if (func_002B3868(object)) {
        func_L23_0041B668((char *)object, &D_L23_001B14D4);
    } else if (D_L23_001B14F8 < AGE) {
        func_002A7750(object, 7, 0);
    }
    if (D_L23_001B36A0 < SF(0x588))
        func_L23_0041B188((char *)object);
    goto state_default;
state5:
    if (func_002B3868(object)) {
        SP(0x400) = (char *)D_L23_001B3770;
        func_L23_0041B540((char *)object, &D_L23_001B1494);
    } else if (func_00282E48(state + 0x3e0, (char *)D_L23_001B3770) > 1.0f) {
        func_L23_004186D0((char *)object, SF(0x588));
    } else {
        func_002A7750(object, 17, 2);
    }
    goto state_default;
state6:
    func_L23_0041B8F8((char *)object);
    if (func_002B3868(object)) {
        SP(0x400) = (char *)D_L23_001B3760;
        func_L23_0041B540((char *)object, &D_L23_001B1494);
        func_L23_0041B668((char *)object, &D_L23_001B14C4);
    } else if (func_00282E48(state + 0x3e0, (char *)D_L23_001B3760) > 1.0f) {
        func_L23_004186D0((char *)object, SF(0x588));
    } else {
        func_002A7750(object, 16, 2);
    }
    goto state_default;
state16:
    if (func_002B3868(object))
        func_L23_0041B668((char *)object, &D_L23_001B14D0);
    if (D_L23_001B1500 + D_L23_001B1500 * 0.6200000047683716f < SF(0x5b8)) {
        func_L23_0041A648((char *)object);
        if (!S32(0x5b0))
            goto state16_timer;
    } else if (!D_L23_001B3780) {
        if (*(float *)(*(char **)(SP(0x610) + 0x68) + 0x20) < D_L23_001B36FC ||
            SF(0x5b8) < D_L23_001B1500 * 0.5f) {
            func_L23_0041A7A0((char *)object);
            D_L23_001B3780 = 1;
        } else {
state16_timer:
            func_00282948(state + 0x608);
            if (!(D_L23_001B1648 / 2 < D_L23_001B36AC) && !S32(0x608)) {
                func_002A7750(object, 12, 2);
                S32(0x598) = 0;
                S32(0x590) = 4;
            }
        }
    } else {
        func_L23_0041A7A0((char *)object);
    }
    goto state_default;
state20:
    func_L23_0041A648((char *)object);
    if (func_002B1C20(object, (DispatchContext *)(state + 0x140)) & 1) {
        func_002A7750(object, 4, 0);
        *(int *)(D_00189E20 + 0x2294) = 0;
        func_L00_002AF7D0();
        func_L00_00310C88((LvlSlotCtx *)PLAYER, (LvlSlotNode **)(D_00189E20 + 0x1870));
        *(int *)(D_00189E20 + 0x187c) = 0;
        func_L22_002C9898(0, 1);
        D_L23_001B1694 = 0;
        return;
    }
state_default:
    S32(0x5a8) = 0;
    for (i = 0; i < 5; ++i) {
        char *child = SP(0x36c + i * 4);
        if (child && !*(unsigned short *)(child + 0x7c))
            *(unsigned short *)(child + 0x7c) = 0x3ff;
    }
    func_L23_0041CD58((char *)object);
    func_L23_004180F0((char *)object);
    for (i = 0; i < 5; ++i) {
        if (SP(0x358 + i * 4)) {
            func_002AF1D0(object, SP(0x358 + i * 4), i + 1, 0);
            FLAGS(SP(0x358 + i * 4)) &= 0xfff9;
            FLAGS(SP(0x358 + i * 4)) |= 0x4000;
        }
    }
    if (!SP(0x610)) {
        FLAGS(object) |= 0x4000;
    } else {
        func_002AF1D0(object, SP(0x610), 0x22, 0);
        FLAGS(SP(0x610)) &= 0xfff9;
        FLAGS(SP(0x610)) |= 0x800;
        if (S32(0x60c) == -1 && (object[0x20] == 16 || object[0x20] == 12))
            FLAGS(SP(0x610)) |= 0x4000;
        else
            FLAGS(SP(0x610)) &= 0xbfff;
    }
    if (SP(0x614)) {
        func_002AF1D0(object, SP(0x614), 0x22, 0);
        FLAGS(SP(0x614)) &= 0xfff9;
        FLAGS(SP(0x614)) &= 0xbfff;
        FLAGS(SP(0x614)) |= 0x100;
    }
    func_L23_00419D60((char *)object);
    *(Quad *)localPosition = *(Quad *)D_L23_001B36C0;
    func_L23_0041A038((char *)object, localPosition);
    func_L23_0041A3B8((char *)object, localPosition);
    func_L23_0041C0E8((char *)object);
    if (!SP(0x40c))
        SP(0x40c) = func_L22_003F85A0((char *)object, position);
    else
        func_L08_004356A0((u8 *)SP(0x40c), position);
    func_L23_0041B5C8((char *)object);
    if (D_L23_001B1410 == 0.0f)
        func_L23_0041B5B0((char *)object);
    else
        func_L23_0041B498((char *)object);
    if (func_L22_003B9428((unsigned int)PLAYER) && D_L23_001B3780 &&
        (object[0x20] == 16 || object[0x20] == 12) && D_L23_001B1500 < SF(0x5bc)) {
        char *attachment = (char *)func_L23_00423698((int)PLAYER) + 0x10;
        height = func_002B0360(attachment) - D_L23_001B36A4;
        distance = func_00282E48(attachment, (char *)D_L23_001B3760);
        if (distance < D_L23_001B1500 * 0.6f && height < D_L23_001B14D0 - 2.0f) {
            func_0032C700(attachment, 0, 15, 10, 15, 15, 15, 1, 2.0f, 20.0f, 0, 0, 0, 0);
            func_L23_00423588((int)PLAYER, 1);
        }
    }
    func_00282948((char *)&D_L23_001B3718);
    if (D_L23_001B3718)
        func_L00_002D6900(0x2b);
}
