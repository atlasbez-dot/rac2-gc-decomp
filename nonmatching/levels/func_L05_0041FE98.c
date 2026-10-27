/* func_L05_0041FE98 - 352 bytes, 1 place. Opus near miss (M18): the L10_00423698 mission reset with L05 data plus the checkpoint-block copy (MACRO_ADDR struct, macro loads/stores). 352/352 B; only the four float copies differ: retail loads +8,+0x10,+4,+0xC into f0..f3, this cc1 +4,+8,+0xC,+0x10 whatever the source order (8 tail lines). Unit -g8 (default -G8 profile). */
#include "common.h"
#include "include_asm.h"
typedef struct GornConfig { int words[10]; } GornConfig;
extern char D_L05_00221D10[];
extern GornConfig D_L05_002A1800[];
extern int D_L05_001B1360 __attribute__((sda));
extern int D_L05_001B1364 __attribute__((sda));
extern void *D_L05_001B13B4 __attribute__((sda));
extern void *D_L05_001B13B8 __attribute__((sda));
extern int D_L05_001B13E8 __attribute__((sda));
extern int D_L05_001B13F0 __attribute__((sda));
extern void func_L05_0037B210(void);
extern void func_L05_00379F18(int);
extern int func_002ED8A0(int);
extern void func_L05_00379F28(int);
extern void func_L05_0037D6E8(void);
extern void func_L05_00379F68(void);
extern void func_L05_00445A98(void);
extern void func_0029F338(void *);

typedef struct { u8 b0, b1, b2; float f4, f8, fC, f10; int i14; } Checkpoint_41FE98;
extern Checkpoint_41FE98 D_L05_001B3558 MACRO_ADDR;
extern Checkpoint_41FE98 D_L05_001B2000 MACRO_ADDR;

/* L05 copy of func_L10_00423698, which also restores the checkpoint block. Resets the mission (the 004235A0 body without the carried-object test, with two more counters)'s shared counters and removes its two temporary objects. */
void func_L05_0041FE98(void) {
    char *state;
    int i;
    func_L05_0037B210();
    func_L05_00379F18(1);
    state = D_L05_00221D10;
    D_L05_001B1360 = -2;
    *(int *)(state + 0x10) = 0;
    *(int *)(state + 0xC) = 0;
    D_L05_001B13E8 = 1;
    *(int *)(state + 0x2C) = 1;
    *(int *)(state + 0x28) = 100;
    D_L05_001B1364 = 0;
    *(int *)(state + 0x14) = 0;
    i = func_002ED8A0(6);
    D_L05_001B13F0 = 0;
    D_L05_002A1800[i].words[5] = D_L05_002A1800[i].words[4];
    func_L05_0037D6E8();
    func_L05_00379F68();
    func_L05_00445A98();
    *(float *)(state + 0x30) = 8.0f;
    func_L05_00379F28(0);
    if (D_L05_001B13B4) { func_0029F338(D_L05_001B13B4); D_L05_001B13B4 = 0; }
    if (D_L05_001B13B8) { func_0029F338(D_L05_001B13B8); D_L05_001B13B8 = 0; }
    D_L05_001B2000.b0 = D_L05_001B3558.b0;
    D_L05_001B2000.b1 = D_L05_001B3558.b1;
    D_L05_001B2000.b2 = D_L05_001B3558.b2;
    D_L05_001B2000.f4 = D_L05_001B3558.f4;
    D_L05_001B2000.f8 = D_L05_001B3558.f8;
    D_L05_001B2000.fC = D_L05_001B3558.fC;
    D_L05_001B2000.f10 = D_L05_001B3558.f10;
    D_L05_001B2000.i14 = D_L05_001B3558.i14;
}
