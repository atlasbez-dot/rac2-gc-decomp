/* Nonmatching: -O2 -G0 -ffunction-sections. us: func_L00_0038F8B8: 0 of 27 places match (src/levels/shared/L00_0038F8B8.c); us2: absent; pal: absent. Two source forms844 then900/908 bytes, original0x50 frame. Preserving separate pitched/flat vector construction recovers56 bytes. Actual two-pointer/two-float spawn ABI, all three spherical-vector floats and four animation integer inputs verified; no live inputs dropped. Remaining register allocation and gate/counter scheduling. Reopen with a concrete resident-view/lifetime hypothesis; no linked builds. */
#include "common.h"
/* Partial resident view: only fields observed by the launch gate are named. */
typedef struct {
    char pad00[0x33C]; char *support; int grounded; char pad344[0x434]; float heading;
    char pad77C[0xAB4]; u32 buttons; char pad1234[0xC]; int resource;
    char pad1244[0x2BC]; int special; char pad1504[0xD90]; int level;
    char pad2298[4]; int state; char pad22A0[0x1C]; u8 busy; char pad22BD[0x22F];
    s16 platform; char pad24EE[0x46]; int cooldown; char pad2538[0xB0];
    u16 launches; char pad25EA[2]; u32 bestTime; u32 mask;
} TetherLaunchHero;
extern TetherLaunchHero D_00189E20;
extern int D_L00_001A8F00, D_L00_001A8F08;
extern u32 D_00138324;
extern u32 D_001A7390 MACRO_ADDR;
extern u32 D_001A79F0;
extern char *D_L00_001B8E10;
extern int func_00282948(int *), func_L00_002D3F30(int, int);
extern float func_00282E20(void *), func_00283248(float, float);
extern void func_002AF000(float *, float, float, float), func_00282CC0(void *, void *, void *);
extern void func_002A7470(void *, int, int, int), func_L00_002F46C8(void);
extern char *func_L00_00390FF8(char *, char *, float, float);
extern int func_002E5CF8(int, int, char *);
/* Starts the tether when the shared input and movement gates permit it. */
void func_L00_0038F8B8(char *actor) {
    int *state;
    int ready = 1;
    float point[4];
    float heading, pitch;
    u32 now;
    if (!actor) return;
    state = *(int **)(actor + 0x68);
    func_00282948(state);
    if (D_00189E20.level == 29) ready = func_00282948(&D_00189E20.cooldown) != 0;
    else D_00189E20.cooldown = 40;
    if (D_L00_001A8F00 || D_L00_001A8F08 != -2 || !(D_00138324 & D_00189E20.buttons) || state[0] || state[1] || D_00189E20.busy) goto finish;
    if (D_00189E20.state == 7 || D_00189E20.state == 2 || D_00189E20.state == 3 || D_00189E20.state == 4 || D_00189E20.state == 5 || D_00189E20.state == 6 || D_00189E20.state == 16 || D_00189E20.state == 14 || D_00189E20.state == 9 || D_00189E20.state == 10 || D_00189E20.state == 11 || D_00189E20.state >= 13 || D_00189E20.level == 111 || D_00189E20.level == 98) goto finish;
    if ((D_L00_001B8E10 && *(short *)(D_L00_001B8E10 + 0x86) == 5) || !D_00189E20.grounded || D_00189E20.resource < 23) goto finish;
    if (D_00189E20.support && (*(short *)(D_00189E20.support + 0xAA) == 0x13E || *(short *)(D_00189E20.support + 0xAA) == 0x46F) && ready) goto finish;
    if (!func_L00_002D3F30(-1, 1)) {
        if (D_00138324 & D_00189E20.buttons) func_002E5CF8(0, 0, actor);
        goto finish;
    }
    pitch = 0.0f;
    heading = D_00189E20.heading;
    if (D_00189E20.platform == 1 || D_00189E20.special) {
        pitch = func_00283248(func_00282E20(actor + 0xD0), *(float *)(actor + 0xD8));
        func_002AF000(point, 0.6f, heading, -pitch);
        func_00282CC0(point, point, actor + 0x10);
    } else {
        func_002AF000(point, 0.6f, heading, -0.0f);
        func_00282CC0(point, point, actor + 0x10);
    }
    if (*(u8 *)(actor + 0x43) != 3) func_002A7470(actor, 3, 0, 0);
    func_L00_002F46C8();
    *(char **)(state + 1) = func_L00_00390FF8(actor, (char *)point, heading, pitch);
    if (D_00189E20.launches != 0xFFFF) D_00189E20.launches++;
    now = D_001A7390;
    if (D_00189E20.bestTime < now) D_00189E20.bestTime = now;
    D_00189E20.mask |= (1U << (D_001A79F0 & 31)) | 0x80000000;
    state[0] = 60;
finish:
    if ((*(u8 *)(actor + 0x60) & 2) && *(u8 *)(actor + 0x43) != 1) func_002A7470(actor, 1, 0, 0);
    *(u16 *)(actor + 0x34) |= 4;
}

/* Historical screening only; superseded by the measured reconstruction above. */
/* func_L00_0038F8B8 - 908 bytes, 27 place(s), level 00_aranos_tutorial,
   retail at 0x0038f8b8. Screened with tools/w10_screen.py: 14 call(s)
   [func_00282948@0038F8EC, func_00282948@0038F910,
   func_L00_002D3F30@0038FA70, func_00282E20@0038FAA0,
   func_00283248@0038FAAC, func_002AF000@0038FACC, func_00282CC0@0038FADC,
   func_002AF000@0038FAFC, func_00282CC0@0038FB0C, func_002A7470@0038FB2C,
   func_L00_002F46C8@0038FB34, func_L00_00390FF8@0038FB48,
   func_002E5CF8@0038FBDC, func_002A7470@0038FC08]; data addresses
   materialised [0x190000, 0x1b0000, 0x1b0000, 0x140000, 0x1c0000,
   0x3f190000, 0x3f190000, 0x190000, 0x1a0000]; float constants [0x1a0000,
   0x80000000]; $gp-relative small data: no   saves: -; callee-saved
   registers saved [-]; words plain C cannot emit [-]. Head: addiu $sp, $sp,
   -0x50 ; sd $s0, 0x10($sp) ; sd $s1, 0x18($sp) ; daddu $s0, $a0, $zero ;
   sd $s2, 0x20($sp) ; sd $s3, 0x28($sp). Not matched in this wave: the body
   is straight-line code whose register allocation and the materialisation
   of its constant addresses have to be reproduced word for word. What would
   unblock it: the exact source expression tree, so this cc1 picks the same
   registers in the same order. */
