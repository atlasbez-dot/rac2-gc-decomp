/* Nonmatching reconstruction checked 23 October 2026.
 * Profile: -O2 -G8 -ffunction-sections.
 * Final check.py coverage: us 0/27, us2 0/27; no candidate.
 * Four bounded source/profile variants: direct globals 1584/1616; resident-state prefix/separate clears 1556; two-state switch 1552; -fno-gcse 1556, discarded.
 * Remaining: Retained 1552/1616. Entry addressing improved, but dispatch/charge branches, oscillator-loop registers and global lifetimes differ.
 * Reopen with a measured charge-state CFG and resident/input aggregate-lifetime witness.
 * Historical screening below is preserved, not treated as acceptance evidence.
 */

/* func_L00_003A0F30 - 1616 bytes, 27 place(s), level 00_aranos_tutorial,
   retail at 0x003a0f30. Screened with tools/w10_screen.py: 36 call(s)
   [func_00282948@003A0F80, func_002A7470@003A1018, func_0029F978@003A103C,
   func_L00_00329E90@003A1060, func_L00_0032A088@003A107C,
   func_002A78D8@003A10AC, func_002A78D8@003A10C0, func_002A78D8@003A10D0,
   func_002A7878@003A10E0, func_002A7878@003A10F0, func_002A7878@003A1100,
   func_002A78D8@003A111C, func_002A78D8@003A112C, func_002A78D8@003A113C,
   func_002A7878@003A114C, func_002A7878@003A115C, func_002A7878@003A116C,
   func_00282C88@003A1180, func_00282C88@003A1188,
   func_L00_002C42E0@003A11D4, func_L00_002D4040@003A1208,
   func_00273318@003A1248, func_002829D8@003A1250,
   func_L00_003BB5F0@003A1290, func_L00_002D3F30@003A12B4,
   func_002E5CF8@003A12D4, func_002E5CF8@003A1390, func_0029FCC0@003A1434,
   func_00282F20@003A1460, func_00282F20@003A1470,
   func_L00_0032A1A8@003A1494, func_L00_003BB080@003A14A8,
   func_L00_002E6EF8@003A1504, func_00283B98@003A1528,
   func_00283198@003A1534, func_00283180@003A1544]; data addresses
   materialised [0x190000, 0x3ebb0000, 0x1b0000, 0x3d4c0000, 0x3e990000,
   0x240000, 0x1b0000, 0x600f0000, 0x60000000, 0x600f0000, 0x140000,
   0x1b0000, 0x140000, 0x140000, 0x260000, 0x260000, 0x1b0000, 0x1b0000,
   0x3eaa0000, 0x3eaa0000, 0x3a0000, 0x3ea00000]; float constants
   [0xbf800000, 0x3e800000, 0x3f400000, 0xbf800000, 0x3f800000, 0x42b40000,
   0x3f800000, 0x3f800000, 0x3f000000]; $gp-relative small data: yes
   saves: -; callee-saved registers saved [-]; words plain C cannot emit
   [-]. Head: addiu $sp, $sp, -0x80 ; lui $v0, 0x19 ; sd $s2, 0x40($sp) ; sd
   $s3, 0x48($sp) ; daddu $s2, $a0, $zero ; sd $s4, 0x50($sp). Not matched
   in this wave: the body is straight-line code whose register allocation
   and the materialisation of its constant addresses have to be reproduced
   word for word. What would unblock it: the exact source expression tree,
   so this cc1 picks the same registers in the same order. */

#include "common.h"
typedef int VectorBits __attribute__((mode(TI)));
/* Measured resident player-state prefix; fields beyond this prefix are unknown. */
typedef struct {
    char p0[0xBF8]; char *aimTarget;
    char p1[0x634]; unsigned int buttons;
    char p2[0xC]; int inputTicks;
    char p3[0x20C]; char *overrideTarget;
    char p4[0xE3C]; char *hero; int mode;
    char p5[0x24]; u8 blocked;
    char p6[0x22F]; short viewMode;
    char p7[0x46]; int inputTimer;
} PlayerStatePrefix;
extern PlayerStatePrefix D_00189E20;
extern u8 D_00139584 NOT_SDA;
extern unsigned int D_00138320 NOT_SDA,D_00138324 NOT_SDA;
extern float D_0018A580[4];
extern float D_L00_001B285C NOT_SDA;
extern int D_L00_001B2840 NOT_SDA;
extern int D_L00_001AF5CC __attribute__((sda));
extern float D_L00_001AF5D0 __attribute__((sda));
extern float D_L00_001AF5D4 __attribute__((sda));
extern float D_L00_001AF5D8 __attribute__((sda));
extern float D_L00_001AF5DC __attribute__((sda));
extern float D_L00_001AF5E0 __attribute__((sda));
extern int D_L00_001AF5E4 __attribute__((sda));
extern char *D_L00_001AF5E8 __attribute__((sda));
extern int D_L00_001AF5EC __attribute__((sda));
extern float D_L00_0023B510[4][32];
typedef struct { char prefix[0x54]; float rate; char tail[0x88]; } WeaponEntry;
extern WeaponEntry D_L00_00262570[];
extern int func_00282948(void *);
extern void func_002A7470(void *, int, int, int);
extern void func_0029F978(u8 *, u32, u8 *);
extern int func_L00_00329E90(void *, int, void *);
extern char *func_L00_0032A088(int, int);
extern float func_002A78D8(float, float), func_002A7878(float, float);
extern void func_00282C88(VectorBits *);
extern void func_L00_002C42E0(int, int);
extern int func_L00_002D4040(int);
extern void func_00273318(void *, unsigned int, int, int, int, int, float, float, float);
extern int func_002829D8(void *);
extern int func_L00_003BB5F0(void);
extern int func_L00_002D3F30(int, int);
extern int func_002E5CF8(int, int, char *);
extern void func_0029FCC0(char *, int, char *);
extern void func_00282F20(void *, void *, float);
extern void func_L00_0032A1A8(char *, char *, char *, float);
extern void *func_L00_003BB080(char *, char *, char *, char *);
extern void func_L00_003A1580(void *);
extern void func_L00_002E6EF8(void (*)(void *), void *);
extern float func_00283B98(float, float), func_00283198(float), func_00283180(float);

/* Initialize the beam oscillators and update the weapon's charge cycle. */
void func_L00_003A0F30(char *moby)
{
    float velocity[4], origin[4], query[4];
    char *state = *(char **)(moby + 0x68);
    int ready = 1;
    if (D_00189E20.mode == 29) {
        if (func_00282948(&D_00189E20.inputTimer) == 0)
            ready = 0;
    }
    else
        D_00189E20.inputTimer = 40;
    if (D_00189E20.overrideTarget)
        D_00189E20.aimTarget = (char *)D_00189E20.overrideTarget;
    switch (*(unsigned char *)(moby + 0x20)) {
    case 0: {
        int i, handle;
        *(float *)state = 0.3666666746f;
        *(unsigned char *)(moby + 0x20) = 1;
        D_L00_001B285C = -1.0f;
        D_L00_001AF5E4 = 0;
        D_L00_001AF5CC = 0;
        if (*(unsigned char *)(moby + 0x43) || (*(unsigned char *)(moby + 0x60) & 2))
            func_002A7470(moby, 1, 0, 0);
        *(int *)(state + 0xC) = 0;
        *(int *)(state + 0x10) = 0;
        func_0029F978((u8 *)moby, 0, (u8 *)state + 0x20);
        handle = func_L00_00329E90(moby, 0, query);
        *(int *)(state + 4) = handle;
        *(char **)(state + 8) = func_L00_0032A088(*(short *)(moby + 0xAA), handle);
        for (i = 0; i < 4; i++) {
            float *entry = D_L00_0023B510[i];
            entry[0] = 0.0f; entry[1] = 0.0f; entry[2] = 0.0f;
            entry[3] = func_002A78D8(0.05f, 0.3f);
            entry[4] = func_002A78D8(0.05f, 0.3f);
            entry[5] = func_002A78D8(0.05f, 0.3f);
            entry[6] = func_002A7878(0.25f, 0.75f);
            entry[7] = func_002A7878(0.25f, 0.75f);
            entry[8] = func_002A7878(0.25f, 0.75f);
            entry[9] = 0.0f; entry[10] = 0.0f; entry[11] = 0.0f;
            entry[12] = func_002A78D8(0.05f, 0.3f);
            entry[13] = func_002A78D8(0.05f, 0.3f);
            entry[14] = func_002A78D8(0.05f, 0.3f);
            entry[15] = func_002A7878(0.25f, 0.75f);
            entry[16] = func_002A7878(0.25f, 0.75f);
            entry[17] = func_002A7878(0.25f, 0.75f);
            func_00282C88((VectorBits *)(entry + 20));
            func_00282C88((VectorBits *)(entry + 24));
        }
        return;
    }
    case 1:
        break;
    default:
        return;
    }
    D_L00_001B285C = -1.0f;
    if (D_L00_001AF5CC == 0) {
        *(int *)(state + 0xC) = 0;
        D_L00_001AF5CC = 1;
    }
    if (D_00189E20.mode == 1)
        func_L00_002C42E0(29, 1);
    if (D_00189E20.mode == 29) {
        unsigned int color = 0x600FFF0F;
        if (*(float *)state != 0.0f && func_L00_002D4040(-1))
            color = 0x600000FF;
        func_00273318(moby, color, 0, 0x26, -1, 4, 1.0f, 0.0f, 90.0f);
    }
    if (func_002829D8(state) && ready && !D_00189E20.blocked && (D_00138320 & D_00189E20.buttons) &&
        !func_L00_003BB5F0() && D_00189E20.inputTicks > 22) {
        if (func_L00_002D3F30(-1, 1)) {
            D_L00_001B2840 = 1;
            func_002E5CF8(2, 0, moby);
            if (D_L00_001AF5E4 == 0)
                *(float *)(state + 0xC) = D_L00_001AF5D8;
            else if (D_L00_001AF5E4 != 2)
                goto charge;
            D_L00_001AF5E4 = 1;
            *(float *)state = 1.0f / D_L00_00262570[D_00139584].rate;
        } else if ((D_00138324 & D_00189E20.buttons) || D_L00_001B2840 == 1) {
            func_002E5CF8(6, 0, moby);
            D_L00_001B2840 = 0;
        }
    }
charge:
    if (D_L00_001AF5E4 == 1) {
        *(float *)(state + 0xC) += D_L00_001AF5D0;
        if (*(float *)(state + 0xC) > D_L00_001AF5E0) {
            func_0029FCC0(moby, 0, (char *)origin);
            if (D_00189E20.viewMode == 1)
                func_00282F20(velocity, moby + 0xD0, -0.3333333433f);
            else
                func_00282F20(velocity, D_0018A580, 0.3333333433f);
            if (D_00189E20.aimTarget)
                func_L00_0032A1A8(D_00189E20.aimTarget, (char *)origin, (char *)velocity, 0.3333333433f);
            D_L00_001AF5E8 = func_L00_003BB080(moby, (char *)*(int *)(state + 4), (char *)origin, (char *)velocity);
            if (D_L00_001AF5E8)
                *(char **)(D_L00_001AF5E8 + 0xB8) = moby;
            D_L00_001AF5EC = 50;
            D_L00_001AF5E4 = 2;
        }
    } else if (D_L00_001AF5E4 == 0) {
        if (*(float *)(state + 0xC) < D_L00_001AF5D8) {
            *(float *)(state + 0xC) += D_L00_001AF5DC;
            if (*(float *)(state + 0xC) > D_L00_001AF5D8)
                *(float *)(state + 0xC) = D_L00_001AF5D8;
        }
    } else if (D_L00_001AF5E4 == 2) {
        *(float *)(state + 0xC) -= D_L00_001AF5D4;
        if (*(float *)(state + 0xC) <= D_L00_001AF5D8) {
            *(float *)(state + 0xC) = D_L00_001AF5D8;
            D_L00_001AF5E4 = 0;
        }
    }
    if (*(unsigned char *)(moby + 0x31))
        func_L00_002E6EF8(func_L00_003A1580, moby);
    *(float *)(state + 0x10) = func_00283B98(*(float *)(state + 0x10), *(float *)(state + 0xC) * 0.3141593039f);
    *(float *)(state + 0x30) = func_00283198(*(float *)(state + 0x10) * 0.5f);
    *(float *)(state + 0x3C) = func_00283180(*(float *)(state + 0x10) * 0.5f);
}
