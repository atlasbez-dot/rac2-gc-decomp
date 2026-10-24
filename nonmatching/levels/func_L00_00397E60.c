/* Nonmatching: -O2 -G0 -ffunction-sections. us: func_L00_00397E60: 0 of 27 places match (src/levels/shared/L00_00397E60.c); us2: func_L00_00397E60: 0 of 27 places match (src/levels/shared/L00_00397E60.c); pal: absent. One measured reconstruction712/696 bytes, frame0xA0 versus0x90. Readable target query and launch gate; QuerySettings copied with truthful12-byte extent, hero aimAxis16-byte field at+0x760. AF580 callee verified8GPR inputs+5float inputs including f16=zero, returned object pointer. Same extra saved-register lifetime/control-flow family as39D110; reopen with a concrete gate/base lifetime hypothesis. */
#include "common.h"
typedef struct {
    char prefix[0x760]; float aimAxis[4]; char pad770[0xAC0]; unsigned int buttons; char pad1234[0xC]; int resource;
    char pad1244[0x1050]; int level; char pad2298[0x24]; unsigned char busy;
    char pad22BD[0x277]; int cooldown;
} LaunchHero;
extern LaunchHero D_00189E20;
extern unsigned int D_00138320, D_00138324;
typedef struct { float value[3]; } QuerySettings;
extern QuerySettings D_L00_001AF410;
extern char *func_002AF580(void *, void *, int *, void *, int, int, int, void *, float, float, float, float, float);
extern void func_0029FCC0(char *, int, char *);
extern void func_002FDF40(void *, void *, void *, void *, float, float, float, float);
extern int func_002FE5A0(void *, void *, void *, void *, void *, int, int, float);
extern int func_00282948(int *), func_L00_002D3F30(int, int);
extern void func_L00_002AF568(void), func_L00_002AF7D0(void);
extern int func_002E5CF8(int, int, char *);
extern char *func_L00_0038D530(char *, char *);
extern void func_L00_002E6EF8(void (*)(void *), void *);
extern void func_L00_00398118(void *);
/* Selects an aim target and launches the actor's projectile through the shared input gate. */
void func_L00_00397E60(char *actor) {
    char *state = *(char **)(actor + 0x68);
    char position[16], direction[16];
    QuerySettings settings;
    int foundCount;
    char *target;
    float range;
    int ready;
    unsigned char nextState;
    int timer;
    func_0029FCC0(actor, 0, position);
    settings = D_L00_001AF410;
    target = func_002AF580(actor + 0x10, D_00189E20.aimAxis, &foundCount, 0, 0, 0, 0, &settings,
                          0.3926991f, 0.7853982f, 11.1f, 0.0f, 0.0f);
    range = 10.0f;
    if (D_00189E20.level == 29) range = 11.0f;
    func_002FDF40(direction, position, target, 0, 1.5f, range, 0.16666667f, 0.003055555745959282f);
    ready = 1;
    *(int *)(state + 0x24) = func_002FE5A0(position, direction, state, state + 0x10, actor, 0, 0, 0.003055555745959282f);
    if (D_00189E20.level == 29) ready = func_00282948(&D_00189E20.cooldown) != 0;
    else D_00189E20.cooldown = 40;
    switch (*(unsigned char *)(actor + 0x20)) {
    case 0:
        *(unsigned char *)(actor + 0x20) = 1;
        *(int *)(state + 0x24) = 0;
    case 1:
        if ((D_00138320 & D_00189E20.buttons) == 0 || D_00189E20.busy || D_00189E20.resource < 23 || !ready) break;
        if (!func_L00_002D3F30(-1, 1)) {
            if (D_00138324 & D_00189E20.buttons) func_002E5CF8(2, 0, actor);
            break;
        }
        func_L00_002AF568();
        nextState = 2; timer = 20;
        goto transition;
    case 2:
        if (!func_00282948((int *)(state + 0x20))) break;
        *(char **)(func_L00_0038D530(position, direction) + 0xB8) = actor;
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
    func_L00_002E6EF8(func_L00_00398118, actor);
}

/* Historical screening only; superseded by the measured reconstruction above. */
/* func_L00_00397E60 - 696 bytes, 27 place(s), level 00_aranos_tutorial,
   retail at 0x00397e60. Screened with tools/w10_screen.py: 13 call(s)
   [func_0029FCC0@00397E98, func_002AF580@00397F14, func_002FDF40@00397F6C,
   func_002FE5A0@00397F90, func_00282948@00397FA8,
   func_L00_002D3F30@00398050, func_L00_002AF568@00398060,
   func_002E5CF8@00398088, func_00282948@00398098,
   func_L00_0038D530@003980A8, func_L00_002AF7D0@003980B0,
   func_00282948@003980CC, func_L00_002E6EF8@003980E4]; data addresses
   materialised [0x1b0000, 0x3f490000, 0x3ec90000, 0x41310000, 0x3b480000,
   0x3e2a0000, 0x3a0000, 0x3a0000, 0x140000, 0x190000, 0x3a0000, 0x3a0000,
   0x3a0000]; float constants [0x190000, 0x41200000, 0x41300000,
   0x3fc00000]; $gp-relative small data: no   saves: -; callee-saved
   registers saved [-]; words plain C cannot emit [-]. Head: addiu $sp, $sp,
   -0x90 ; daddu $a1, $zero, $zero ; sd $s0, 0x40($sp) ; daddu $a2, $sp,
   $zero ; sd $s1, 0x48($sp) ; daddu $s0, $a0, $zero. Not matched in this
   wave: the body is straight-line code whose register allocation and the
   materialisation of its constant addresses have to be reproduced word for
   word. What would unblock it: the exact source expression tree, so this
   cc1 picks the same registers in the same order. */
