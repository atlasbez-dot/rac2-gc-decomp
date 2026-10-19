#include "include_asm.h"

extern int D_L14_001B17D8 __attribute__((sda));
extern int D_L14_001B17DC;
extern int D_001A72E0;

extern int func_2F6E20(int a, int b, float c);
extern void func_385CB8(unsigned int reg, unsigned long value);
extern void func_3030C0(int, int, int, int, int, int);

/* Plays one sound effect derived from the owner's state block and then queues the level jingle. */
void func_L14_00427250(char *a0)
{
    char *v0;
    int s0;

    v0 = *(char **)(a0 + 0x68);
    s0 = func_2F6E20(D_L14_001B17D8, D_L14_001B17DC, *(float *)v0);
    func_385CB8(0x42, 0x8000000044UL);
    func_3030C0(0, 0, 600, 500, s0, 0);
    func_385CB8(0x4E, 0x1000000UL | (D_001A72E0 >> 13));
}

extern float D_L14_001B17B8 __attribute__((sda));
extern float D_L14_001B17BC __attribute__((sda));

extern char D_00189EA0[];

extern int func_00282948(void *table);

extern void *func_L00_002D70A0(int size);

extern void func_L00_002D7140(void *block);

/* Rewinds the step timer, then respawns the effect the first live slot names, or frees it. */
INCLUDE_ASM("asm/levels", func_L14_00426E60);

extern float D_L14_001B1678 __attribute__((sda));
extern float D_L14_001B167C __attribute__((sda));
extern int D_L14_001B1660 __attribute__((sda));
extern int D_L14_001B1668 __attribute__((sda));
extern int D_L14_001B1690 __attribute__((sda));
extern int D_L14_001B1694 __attribute__((sda));
extern float D_L14_001B1698 __attribute__((sda));
extern float D_L14_001B169C __attribute__((sda));
extern float D_L14_001B16A0 __attribute__((sda));
extern float D_L14_001B16A4 __attribute__((sda));
extern char D_L14_002594F0[][0x280];
extern void func_L14_004229A0(char *, char *, int, int, int, float, float, float);

void func_L14_004228C0(char *object) {
    char *state = *(char **)(object + 0x68);

    D_L14_001B1678 -= D_L14_001B167C;
    if (D_L14_001B1678 <= -8.0f)
        D_L14_001B1678 += 8.0f;
    func_L14_004229A0(object, D_L14_002594F0[*(int *)(state + 0x38)],
        D_L14_001B1660, D_L14_001B1668, *(int *)(state + 0x2C) - 2,
        *(float *)(state + 0x40), *(float *)(state + 0x44), D_L14_001B16A0);
    func_L14_004229A0(object, D_L14_002594F0[*(int *)(state + 0x38)] + 0x140,
        D_L14_001B1690, D_L14_001B1694, *(int *)(state + 0x2C),
        D_L14_001B1698, D_L14_001B169C, D_L14_001B16A4);
}
