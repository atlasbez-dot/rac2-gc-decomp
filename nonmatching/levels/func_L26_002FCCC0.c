/*
 * Complete manual reconstruction retained as nonmatching; no coverage credit.
 * Fresh checks on the qualified current compiler, 2026-10-25.
 * Profile: -O2 -G32 -Wa,-G32 -ffunction-sections
 * Coverage: US: 0/1; US2: absent from catalogue; PAL: absent from catalogue.
 * Compiled text: 632 bytes; retail text: 672 bytes.
 * Remaining difference: Frame 0xD0 matches. The full 64-byte transform is explicitly aligned as
 * four vectors; the complete 32-byte input table is retained. qzero reproduces the observed SQ-
 * zero operation, but the body remains 632 bytes versus 672 with global addressing and loop
 * scheduling differences.
 * Reopen when: Independent source evidence for the global/loop model; preserve the observed delay-
 * slot object ID load and all transform rows.
 */

#include "common.h"

typedef int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } Vector;
extern char D_L26_001BC880[];
extern int D_001A79F0 __attribute__((sda));
extern float D_L26_001A9450[2][4] __attribute__((sda));
extern float D_L26_001A9420 __attribute__((sda));
extern float D_L26_001A9424;
extern unsigned int D_L26_001A9428 __attribute__((sda));
extern unsigned int D_L26_001A942C;
extern int D_L26_001A9430 __attribute__((sda));
extern int D_L26_001A9434, D_L26_001A9438, D_L26_001A943C;
extern int D_L26_001A9440, D_L26_001A9444;
extern void func_L00_002FC980(void);
extern void func_002E64A0(void *);
extern void func_L00_00326048(char *, float *, int, int, float);
extern void func_0029FC20(char *, int, char *);
extern void func_002830C0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern float func_002A7878(float, float);
extern unsigned int func_00283D38(unsigned int, unsigned int, float);
extern int func_002A7820(int, int);
extern char *func_002BAA28(void *, void *, void *, unsigned int, unsigned int, int, int, int, int);
extern int func_00283CF0(float);

void func_L26_002FCCC0(void) {
    Vector transform[4];
    Vector position;
    Vector velocity;
    Vector acceleration;
    char *hero = D_L26_001BC880;
    char **slot;
    char *object;
    char *effect;
    unsigned int color;
    int duration;
    int speed;
    int size;
    int i;
    short id;
    func_L00_002FC980();
    slot = (char **)(hero + 0x18C);
    for (i = 0; i < *(short *)(hero + 0x44); i++, slot++) {
        object = *slot;
        id = *(short *)(object + 0xAA);
        if (object && id == 0xE29) {
            *(unsigned short *)(object + 0x34) |= 0x800;
            id = *(short *)(object + 0xAA);
        }
        if (id == 0xD54) func_002E64A0(object);
        if (object && *(short *)(object + 0xAA) == 4000 && *(char **)(object + 0x68))
            func_L00_00326048(object, (float *)(*(char **)(object + 0x68) + 0xC),
                              (int)0x80AAAAD2, (int)0x80396464, 0.061086535f);
    }
    if (D_001A79F0 == 26 && *(int *)(hero + 0x30) == 0 && *(int *)(hero + 0x34) < 260) {
        object = *(char **)(hero + 0x198);
        func_0029FC20(object, 0, (char *)transform);
        qcopy((transform + 3), (object + 0x10));
        for (i = 0; i < 8; i++) {
            func_002830C0(&position, D_L26_001A9450[i & 1], transform);
            func_00282F20(&velocity, transform, 0.06666667f);
            velocity.f[3] = D_L26_001A9420;
            qzero(&acceleration);
            acceleration.f[3] = D_L26_001A9424;
            color = func_00283D38(D_L26_001A9428, D_L26_001A942C, func_002A7878(0.0f, 1.0f));
            duration = func_002A7820(D_L26_001A9430, D_L26_001A9434);
            speed = func_002A7820(D_L26_001A9438, D_L26_001A943C);
            size = func_002A7820(D_L26_001A9440, D_L26_001A9444);
            effect = func_002BAA28(&position, &velocity, &acceleration, color, color & 0xFFFFFF,
                                   duration, speed, size, -1);
            if (effect) effect[9] = func_00283CF0(2.0f) - 16;
        }
    }
}
