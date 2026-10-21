#include "include_asm.h"

/* ---- shared declarations ---- */

extern int func_002ED688(unsigned char *owner);
extern void func_L05_0037AEC0(char *object, int flag);
extern void func_L05_00379C68(int arg0, int value);
extern void func_L00_002E6DB8(void *, void *);
extern void func_L00_002E6CF0(void *a0, void *a1);
extern void func_L00_002E6EF8(void *, int);
extern void func_L15_00438238(void);
extern void func_L15_00438260(void);
extern void func_L15_00438518(void);

extern void func_002FC560(int, int);
extern void func_0027DE50(int, int, int, int, long);
extern int func_00282948(void *);
extern void func_L15_00432A60(void *, int, int, float, float, float, int, int, int);
extern short D_001A6480[];
extern char D_L15_00269FE0[];

/* Sets the level's four effect blocks up: the screen context first, then, when
   the level's own record says the object is idle, the four blocks of the
   effect data, each with its own size and colour. */
void func_L15_004328E8(void *a0) {
    char *s0 = *(char **)(a0 + 0x68);

    func_002FC560(0x42, 0x48);
    func_0027DE50(0, D_001A6480[0xA9], 0, D_001A6480[0xA8], 0x40404040);
    if (func_00282948(s0 + 0x50) == 0) {
        char *q = D_L15_00269FE0;

        func_L15_00432A60(q, 0x46, 0x46, 3.2f, 6.35f, 0.2f, 0x0A, 0x007F7F7F, 0x00FF1010);
        func_L15_00432A60(q + 0xA0, 0x20, 0x20, 3.1f, 6.19f, 0.2f, 0x0A, 0x007F7F7F, 0x00FF1040);
        func_L15_00432A60(q + 0x140, 0x20, 0x20, 3.1f, 6.19f, 0.2f, 0x0A, 0x007F7F7F, 0x00FF1040);
        func_L15_00432A60(q + 0x1E0, 0x20, 0x20, 3.1f, 6.19f, 0.2f, 0x0A, 0x007F7F7F, 0x00FF1040);
    }
}

INCLUDE_ASM("asm/levels", func_L15_00432A60);

INCLUDE_ASM("asm/levels", func_L15_00434100);

INCLUDE_ASM("asm/levels", func_L15_00434610);

INCLUDE_ASM("asm/levels", func_L15_00434D28);

INCLUDE_ASM("asm/levels", func_L15_00434F90);

typedef struct GornEffectCamera {
    char pad00[0x140];
    float position[4];
} GornEffectCamera;
extern GornEffectCamera D_L15_001B9680;
extern unsigned char *D_L15_001FF4AC;
extern void func_0029FCC0(void *, int, void *);
extern float func_00283248(float, float);
extern float func_002A78D8(float, float);
extern float func_002A7878(float, float);
extern float func_00283B98(float, float);
extern void func_002AF000(void *, float, float, float);
extern unsigned char *func_002BDCE8(float, float, float, float,
                                   void *, int, void *, int, int);
extern int func_002A7820(int, int);
extern int func_00283CF0(float);
extern float func_00283CE0(int);



void func_L15_004351E0(char *object, int joint, float radius) {
    float initial[4], point[4], velocity[4];
    float heading, speed, tilt, yaw;
    unsigned char *particle;
    unsigned char *data;

    func_0029FCC0(object, joint, initial);
    heading = func_00283248(D_L15_001B9680.position[0] - *(float *)(object + 0x10),
                            D_L15_001B9680.position[1] - *(float *)(object + 0x14));
    point[0] = initial[0] + func_002A78D8(0, radius);
    point[1] = initial[1] + func_002A78D8(0, radius);
    point[2] = initial[2] + func_002A78D8(0, radius);
    speed = func_002A7878(radius * 0.008333333767950535f,
                          radius * 0.01666666753590107f);
    tilt = func_002A78D8(0, 1.396263599395752f);
    yaw = func_00283B98(heading, func_002A78D8(0, 1.5707964897155762f));
    func_002AF000(velocity, speed, yaw, tilt);
    particle = func_002BDCE8(0, 1.0f, 1.01f, radius * 210000.0f,
                            point, -1, velocity, 0x307F7F7F, 0);
    if (particle != 0) {
        particle[3] = 0x48;
        *(short *)(particle + 0xA) = func_002A7820(40, 70);
        particle[9] = func_00283CF0(4.0f) + 0x60;
        data = particle + 0x20;
        *(float *)(data + 0x1C) = func_00283CE0(func_002A7820(1, 10));
        *(int *)(data + 4) = 3;
        data[0xA] = 0x7F;
        data[0xB] = particle[0xA];
        particle[2] = *D_L15_001FF4AC;
    }
}

INCLUDE_ASM("asm/levels", func_L15_004353E8);

INCLUDE_ASM("asm/levels", func_L15_00435838);

INCLUDE_ASM("asm/levels", func_L15_00435E80);

void func_L15_00436090(char *a0) {
    char *v1 = *(char **)(a0 + 0x68);

    *(int *)(v1 + 0x270) = 1;
    *(int *)(v1 + 0x274) = 0x1E0;
    *(char *)(a0 + 0x23) = 0x20;
    *(char *)(a0 + 0x20) = 2;
    *(unsigned short *)(a0 + 0x34) |= 8;
    *(float *)(v1 + 0x180) = 450.0f;
    *(int *)(a0 + 0x98) = 0;
}

INCLUDE_ASM("asm/levels", func_L15_004360D8);

extern int func_002E5CF8(int, int, void *);
extern void func_L05_00379FA0(void *, int, int, float, int, float, float, float,
                              int, int, int);

/* The mover's own state decides whether the shot happens: the level's record
   must exist and be ready, and the mover's own counter must be idle.  The two
   shots take the slots after the counter, and the counter wraps at three. */
void func_L15_00436298(char *a0) {
    char *s1 = a0;
    char *s0;
    char *v0;
    int v1;

    s0 = *(char **)(s1 + 0x68);
    v0 = (char *)func_002ED688(a0);
    if (v0 == 0) {
        return;
    }
    if (*(int *)(v0 + 0x120) == 0) {
        return;
    }
    if (*(int *)(s0 + 0x450) != 0) {
        return;
    }
    func_002E5CF8(2, 0, s1);
    func_L05_00379FA0(s1, 0x600000CF, 1, 1.0f, 0, 2.0f, 1.5f, 1.5f, 0x1E,
                     *(int *)(s0 + 0x454) * 2 + 4, 0);
    func_L05_00379FA0(s1, 0x600000CF, 1, 1.0f, 0, 2.0f, 1.5f, 1.5f, 0x1E,
                     *(int *)(s0 + 0x454) * 2 + 5, 0);
    *(int *)(s0 + 0x450) = func_002A7820(0x14, 0x3C);
    v1 = *(int *)(s0 + 0x454) + 1;
    *(int *)(s0 + 0x454) = v1;
    if (v1 >= 3) {
        *(int *)(s0 + 0x454) = 0;
    }
}

INCLUDE_ASM("asm/levels", func_L15_004363C8);

INCLUDE_ASM("asm/levels", func_L15_00436990);

void func_L15_00436BA8(char *a0) {
    char *s0 = a0;
    char *s1 = *(char **)(s0 + 0x68);
    char *s2 = (char *)func_002ED688((unsigned char *)a0);

    *(int *)(s2 + 0x148) = 100;
    func_L05_0037AEC0(s0, 1);
    *(float *)(s1 + 0x180) = 100.0f;
    *(unsigned char *)(s0 + 0x20) = 1;
    *(unsigned char *)(s0 + 0x30) = 0xFF;
    *(unsigned short *)(s0 + 0x32) = 0x1FF;
    *(unsigned short *)(s0 + 0x34) |= 0x100;
    *(float *)(s0 + 0x2C) = 0.20000000298023224f;
    *(float *)(s1 + 0x278) = 10.0f;
    *(int *)(s1 + 0x26C) = 0;
    *(int *)(s1 + 0x270) = 0;
    *(int *)(s1 + 0x274) = 0;
    *(int *)(s2 + 0x154) = (int)(s1 + 0x278);
    func_L05_00379C68((int)s0, 0xFFFF);
}

INCLUDE_ASM("asm/levels", func_L15_00436C68);

void func_L15_00437B18(void *a0) {
    func_L00_002E6DB8((void *)func_L15_00438238, a0);
    func_L00_002E6CF0((void *)func_L15_00438260, a0);
    func_L00_002E6EF8((void *)func_L15_00438518, a0);
}

INCLUDE_ASM("asm/levels", func_L15_00437B68);

INCLUDE_ASM("asm/levels", func_L15_00438260);

INCLUDE_ASM("asm/levels", func_L15_00438518);

INCLUDE_ASM("asm/levels", func_L15_00438B00);

/* The level's id lists: the number of groups, the table of the groups' lists (a pointer, read
   through $gp in a branch delay slot and as a bare lui/lw elsewhere: `sda` arrays of unknown size
   give that), the base of the 64-byte records of the first walk, the base of the 32-byte records
   of the second, and the table that maps a record's byte at +0x1D to a class. */
extern int D_L15_001A9018[] __attribute__((sda));
extern unsigned short **D_L15_001A9014[] __attribute__((sda));
extern unsigned char *D_L15_001B2C9C[] __attribute__((sda));
extern unsigned char *D_L15_001B2C94[] __attribute__((sda));
extern short D_L15_00227500[];

extern float func_00282E80(void *, void *);
extern float func_002A7940(void);
extern float func_00283198(float);
extern void func_002AEE70(void *, void *, void *, float, float, float);
extern void func_L00_00323448(void *, void *, int, int, int, int, int, int);
extern void func_L00_00323E48(void *, int, int, void *);
extern void func_L00_00323958(void *, void *);
extern void func_0029F338(void *);
extern void func_002833F0(void *, void *);

/* State 0 looks for the group of the level's id lists that holds the 64-byte record closest to
   the object (first walk, distances below 9999.0; the group index goes to the state's first word
   and the function ends when there is none), sets the object's aim from two random values
   (func_002A7878, func_002A7940) and the record list at state + 0x40, removes the object when the
   state's byte at +0x8A is zero, and otherwise walks the chosen group's 32-byte records
   (second walk): records of class 0xD34 and 0xD33 get their id written into the record list with
   the payload at state + 0x680 and state + 0x6A0 (func_L00_00323E48).  It then picks two random
   angular speeds (the second gets the sign opposite to the first) and goes to state 1, which
   keeps aiming and turns the two angles at +0x688 and +0x6A8.  Both walks keep the second
   `p != 0` guard before the `p[-1]` read and the second walk has a pointer variable of its own
   (one shared variable swaps two callee-saved registers).  Measured: a0 + 0xC0 and a0 + 0xF0
   formed in locals ahead of the second walk make loop.c hoist the two class constants out of it
   (two more saved registers); written at their use after the walk, as below, they stay in the
   loop.  The sign test is a store followed by a conditional store, which gives retail's
   `bc1f` with the first store in its slot and lets the constant 1 be shared by both stores. */
void func_L15_004390A0(unsigned char *a0)
{
    unsigned char *state = *(unsigned char **)(a0 + 0x68);
    unsigned short *p;
    unsigned short *q;
    unsigned char *e;
    int i;
    int best;
    short cls;
    float bestd;
    float d;
    float f2;

    switch (a0[0x20]) {
    case 0:
        best = -1;
        bestd = 9999.0f;
        for (i = 0; i < D_L15_001A9018[0]; i++) {
            for (p = D_L15_001A9014[0][i];
                 p != 0 && ((p != 0 && (short)p[-1] >= 0) || p == D_L15_001A9014[0][i]);
                 p++) {
                e = D_L15_001B2C9C[0] + ((*p & 0x7FFF) << 6);
                if (e == 0)
                    break;
                d = func_00282E80(e + 0x30, a0 + 0x10);
                if (d < bestd) {
                    bestd = d;
                    best = i;
                }
            }
        }
        *(int *)state = best;
        if (best == -1)
            return;
        *(float *)(state + 0x28) = 12.0f;
        *(float *)(state + 0x2C) = func_002A7878(30.0f, 37.0f);
        *(float *)(state + 0x1C) = func_002A7940();
        *(float *)(state + 0xC) = func_00283198(*(float *)(state + 0x1C)) * *(float *)(state + 0x28);
        func_002AEE70(a0, state + 0x1C, state + 0xC, *(float *)(state + 0x28),
                      *(float *)(state + 0x2C) * 0.000290888245f, -1.0f);
        a0[0x30] = 0xFF;
        func_L00_00323448(a0, state + 0x40, 20, *(int *)(state + 4), *(int *)state,
                          *(int *)(state + 8), 7, 0);
        if (state[0x8A] == 0) {
            func_0029F338(a0);
            return;
        }
        for (q = D_L15_001A9014[0][*(int *)state];
             q != 0 && ((q != 0 && (short)q[-1] >= 0) || q == D_L15_001A9014[0][*(int *)state]);
             q++) {
            e = D_L15_001B2C94[0] + ((*q & 0x7FFF) << 5);
            if (e == 0)
                break;
            cls = D_L15_00227500[e[0x1D]];
            if (cls == 0xD34)
                func_L00_00323E48(state + 0x40, 1, (short)*q, state + 0x680);
            if (cls == 0xD33)
                func_L00_00323E48(state + 0x40, 1, (short)*q, state + 0x6A0);
        }
        state[0x8D] = 1;
        *(unsigned short *)(a0 + 0x34) |= 0x104;
        func_002833F0(a0 + 0xC0, a0 + 0xF0);
        *(float *)(state + 0x38) = func_002A78D8(27.0f, 52.0f) * 0.000290888245f;
        f2 = func_002A78D8(25.0f, 37.0f) * 0.000290888245f;
        *(float *)(state + 0x3C) = f2;
        if (0.0f <= *(float *)(state + 0x38) * f2)
            *(float *)(state + 0x3C) = -f2;
        a0[0x20] = 1;
        break;
    case 1:
        func_002AEE70(a0, state + 0x1C, state + 0xC, *(float *)(state + 0x28),
                      *(float *)(state + 0x2C) * 0.000290888245f, -1.0f);
        *(float *)(state + 0x688) = func_00283B98(*(float *)(state + 0x688), *(float *)(state + 0x38));
        *(float *)(state + 0x6A8) = func_00283B98(*(float *)(state + 0x6A8), *(float *)(state + 0x3C));
        func_L00_00323958(a0, state + 0x40);
        break;
    }
}
