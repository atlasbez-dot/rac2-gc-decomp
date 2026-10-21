#include "common.h"

/* The bodies that reach a global through $gp live in this -G8 sibling of
   L06_0033BDC0.c; the declarations carry the sda attribute so that cc1 emits
   the one-instruction $gp form the retail code has. */

extern void func_002A7750(void *, int, int);
extern int func_002A9640(void *, int, int);
extern void func_L00_0032A258(void *, void *, void *, void *, int, int, int, int,
                               int, int, int);
extern void func_L01_0031A278(char *, float *, float, float, float);
extern void func_L06_00402230(char *);
extern void func_0029F338(void *);
extern void func_002A7398();
extern float func_00283C80(float, float);
extern float func_00283B98(float, float);
extern float func_00283198(float);
extern int func_002E5CF8(int, int, char *);

extern float D_L06_001B0020 __attribute__((sda));
extern float D_L06_001B0028 __attribute__((sda));
extern float D_L06_001B0030 __attribute__((sda));
extern int D_L06_001B0050 __attribute__((sda));
extern float D_L06_001AFE40 __attribute__((sda));
extern char *D_L06_001B281C[] __attribute__((sda));

/* a moby's three states: idle, hit, and gone */
void func_L06_00402440(char *a0)
{
    char *s0 = a0;
    char *s1;
    float buf[4];

    s1 = *(char **)(s0 + 0x68);

    switch (*(unsigned char *)(s0 + 0x20)) {
    case 0:
        if (*(int *)(s1 + 4) != 0)
            *(unsigned short *)(s0 + 0x34) |= 0x8000;
        func_002A7750(s0, 1, -1);
        break;
    case 1:
        if (func_002A9640(s0, 0x4010000, 0) != 0) {
            if (*(int *)s1 == 0)
                func_002A7750(s0, 2, -1);
        }
        *(unsigned char *)(s0 + 0xA8) = 0xFF;
        break;
    case 2:
        func_L00_0032A258(s0, &D_L06_001B0030, &D_L06_001B0028, &D_L06_001B0020,
                          0xFFFF, 0, D_L06_001B0050, 6, 0xFFFF, 0xFF, 0);
        func_L01_0031A278(s0, buf, 1.0f, 1.0f, 3.0f);
        func_L06_00402230(s0);
        func_0029F338(s0);
        break;
    }
}

/* a moby that has just come alive: it takes its state, its position and the
   level's step, and it is retired when its angle has turned too far */
extern void func_L06_00400498(char *a0);

extern char *D_0018C0B0[];
extern u8 D_00188660[];
extern int func_002E59B0(void *, int);
extern void func_002E59F8(int);

/* a moby that wakes up: it takes the level's step, and it gives its handle
   back when the moby it is attached to is gone */
void func_L06_00403F60(char *a0)
{
    char *s1 = a0;
    char *s0;
    char *s3;
    char *q;
    char *e;
    int idx;
    int a1;
    long long v;

    s0 = *(char **)(s1 + 0x68);
    if (s0 == 0)
        return;

    switch (*(unsigned char *)(s1 + 0x20)) {
    case 0:
        *(float *)(s0 + 8) = *(float *)(s1 + 0x18);
        v = *(long long *)(*(char **)D_0018C0B0 + 0x38);
        *(unsigned char *)(s1 + 0x20) = 1;
        *(long long *)(s1 + 0x38) = v;
        *(int *)(s0 + 0x10) = 0;
        break;
    case 1:
        idx = *(int *)s0;
        if (idx == -1)
            break;
        q = D_L06_001B281C[0] + (idx << 8);
        if (q == 0)
            break;
        s3 = *(char **)(q + 0x68);
        *(float *)(s1 + 0x18) = *(float *)(s3 + 0) * *(float *)(s0 + 4)
                               + *(float *)(s0 + 8);
        if (*(float *)(s3 + 0) != *(float *)(s0 + 0x10)) {
            if (*(float *)(s3 + 0) == 1.0f || *(float *)(s3 + 0) == 0.0f) {
                if (func_002E59B0(s1, *(int *)(s0 + 0xC)) != 0) {
                    a1 = *(int *)(s0 + 0xC);
                    if (a1 != -1) {
                        e = D_00188660 + a1 * 0x70;
                        if (*(int *)(e + 0x88) == (int)s1) {
                            if (*(unsigned char *)(e + 0x74) != 0)
                                func_002E59F8(a1);
                        }
                    }
                    *(int *)(s0 + 0xC) = -1;
                }
                func_002E5CF8(1, 0, s1);
            } else {
                if (func_002E59B0(s1, *(int *)(s0 + 0xC)) == 0)
                    *(int *)(s0 + 0xC) = func_002E5CF8(0, 4, s1);
            }
        } else {
            if (func_002E59B0(s1, *(int *)(s0 + 0xC)) != 0) {
                a1 = *(int *)(s0 + 0xC);
                if (a1 != -1) {
                    e = D_00188660 + a1 * 0x70;
                    if (*(int *)(e + 0x88) == (int)s1) {
                        if (*(unsigned char *)(e + 0x74) != 0)
                            func_002E59F8(a1);
                    }
                }
                *(int *)(s0 + 0xC) = -1;
            }
        }
        *(float *)(s0 + 0x10) = *(float *)(s3 + 0);
        break;
    }
}
