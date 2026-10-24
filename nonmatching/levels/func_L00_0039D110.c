/* Nonmatching: -O2 -G0 -ffunction-sections. us: func_L00_0039D110: 0 of 27 places match (src/levels/shared/L00_0039D110.c); us2: func_L00_0039D110: 0 of 27 places match (src/levels/shared/L00_0039D110.c); pal: absent. Three measured source trials, final572/560 bytes and frame0x80 versus0x70; launch input/state machine reconstructed. Corrected typed hero field offsets checked against retail. Four float inputs and four pointer inputs to FDF40, seven GPR inputs plus float dt to FE5A0 verified in helper bodies; no-argument AF568 wrapper verified to overwrite incoming arguments before use. Remaining saved-register lifetime and branch layout; reopen with natural state/gate lifetime hypothesis. */
#include "common.h"
typedef struct {
    char prefix[0x1230]; unsigned int buttons; char pad1234[0xC]; int resource;
    char pad1244[0x1050]; int level; char pad2298[0x24]; unsigned char busy;
    char pad22BD[0x277]; int cooldown;
} LaunchHero;
extern LaunchHero D_00189E20;
extern unsigned int D_00138320;
extern void func_0029FCC0(char *, int, char *);
extern void func_002FDF40(void *, void *, void *, void *, float, float, float, float);
extern int func_002FE5A0(void *, void *, void *, void *, void *, int, int, float);
extern int func_00282948(int *), func_L00_002D3F30(int, int);
extern void func_L00_002AF568(void), func_L00_002AF7D0(void);
extern int func_002E5CF8(int, int, char *);
extern char *func_L00_00398810(char *, char *);
extern void func_L00_002E6EF8(void (*)(void *), void *);
extern void func_L00_0039D340(void *);
/* Aims and launches the actor's projectile in response to the shared input gate. */
void func_L00_0039D110(char *actor) {
    char *state = *(char **)(actor + 0x68);
    char position[16], direction[16];
    float range;
    int ready;
    unsigned char nextState;
    int timer;
    func_0029FCC0(actor, 0, position);
    range = 5.0f;
    if (D_00189E20.level == 29) range = 11.0f;
    func_002FDF40(direction, position, 0, 0, 1.5f, range, 0.16666667f, 0.003055555745959282f);
    ready = 1;
    *(int *)(state + 0x24) = func_002FE5A0(position, direction, state, state + 0x10, actor, 0, 0, 0.003055555745959282f);
    if (D_00189E20.level == 29) ready = func_00282948(&D_00189E20.cooldown) != 0;
    else D_00189E20.cooldown = 40;
    switch (*(unsigned char *)(actor + 0x20)) {
    case 0:
        *(unsigned char *)(actor + 0x20) = 1;
        *(int *)(state + 0x24) = 0;
    case 1:
        if ((D_00138320 & D_00189E20.buttons) == 0 || D_00189E20.busy || D_00189E20.resource < 9 || !ready) break;
        if (!func_L00_002D3F30(-1, 1)) { func_002E5CF8(2, 0, actor); break; }
        func_L00_002AF568();
        nextState = 2; timer = 20;
        goto transition;
    case 2:
        if (!func_00282948((int *)(state + 0x20))) break;
        *(char **)(func_L00_00398810(position, direction) + 0xB8) = actor;
        func_L00_002AF7D0();
        nextState = 3; timer = 10;
transition:
        *(unsigned char *)(actor + 0x20) = nextState;
        *(int *)(state + 0x20) = timer;
        break;
    case 3:
        if (func_00282948((int *)(state + 0x20))) *(unsigned char *)(actor + 0x20) = 1;
        break;
    }
    func_L00_002E6EF8(func_L00_0039D340, actor);
}

/* Historical screening only; superseded by the measured reconstruction above. */
/* func_L00_0039D110 - 560 bytes, 27 place(s), level 00_aranos_tutorial,
   retail at 0x0039d110. Screened with tools/w10_screen.py: 12 call(s)
   [func_0029FCC0@0039D148, func_002FDF40@0039D1A8, func_002FE5A0@0039D1D0,
   func_00282948@0039D1E8, func_L00_002D3F30@0039D288,
   func_L00_002AF568@0039D298, func_002E5CF8@0039D2B0,
   func_00282948@0039D2C0, func_L00_00398810@0039D2D0,
   func_L00_002AF7D0@0039D2D8, func_00282948@0039D2F4,
   func_L00_002E6EF8@0039D30C]; data addresses materialised [0x190000,
   0x3b480000, 0x3e2a0000, 0x3a0000, 0x3a0000, 0x140000, 0x3a0000, 0x3a0000,
   0x3a0000, 0x3a0000]; float constants [0x40a00000, 0x41300000,
   0x3fc00000]; $gp-relative small data: no   saves: -; callee-saved
   registers saved [-]; words plain C cannot emit [-]. Head: addiu $sp, $sp,
   -0x70 ; daddu $a1, $zero, $zero ; sd $s0, 0x20($sp) ; daddu $a2, $sp,
   $zero ; sd $s2, 0x30($sp) ; daddu $s0, $a0, $zero. Not matched in this
   wave: the body is straight-line code whose register allocation and the
   materialisation of its constant addresses have to be reproduced word for
   word. What would unblock it: the exact source expression tree, so this
   cc1 picks the same registers in the same order. */
