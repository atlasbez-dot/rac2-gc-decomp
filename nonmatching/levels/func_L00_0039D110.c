/* Near miss (M5): 560/560 B, 24 lines off at the 27 places, two register swaps only:
   - state and the hero-block base trade $s1/$s2 (reading state after the first call gives
     retail's registers but moves the load out of the jal slot);
   - nextState/timer trade $v0/$v1 (assigning timer first gives the registers but swaps
     the two addiu).
   Solved: range as a conditional inside func_002FDF40's argument list (retail computes
   &direction into $s3 before the level test), the cooldown gate as `if (!f()) ready = 0`
   (movz), and the success arm of func_L00_002D3F30 first. Profile `-O2 -G0 -ffunction-sections`. */
#include "include_asm.h"
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
extern void func_L00_002AF7D0(void), func_L00_002AF568(void);
extern int func_002E5CF8(int, int, char *);
extern char *func_L00_00398810(char *, char *);
extern void func_L00_002E6EF8(void *, void *);
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
    func_002FDF40(direction, position, 0, 0, 1.5f, D_00189E20.level == 29 ? 11.0f : 5.0f, 0.16666667f, 0.003055555745959282f);
    ready = 1;
    *(int *)(state + 0x24) = func_002FE5A0(position, direction, state, state + 0x10, actor, 0, 0, 0.003055555745959282f);
    if (D_00189E20.level == 29) {
        if (!func_00282948(&D_00189E20.cooldown)) ready = 0;
    }
    else D_00189E20.cooldown = 40;
    switch (*(unsigned char *)(actor + 0x20)) {
    case 0:
        *(unsigned char *)(actor + 0x20) = 1;
        *(int *)(state + 0x24) = 0;
    case 1:
        if ((D_00138320 & D_00189E20.buttons) == 0 || D_00189E20.busy || D_00189E20.resource < 9 || !ready) break;
        if (func_L00_002D3F30(-1, 1)) {
            func_L00_002AF568();
            nextState = 2; timer = 20;
            goto transition;
        }
        func_002E5CF8(2, 0, actor);
        break;
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

