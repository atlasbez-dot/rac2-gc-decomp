/* Nonmatching: game -O2 -G8 -frac2-zero-ti-barrier; USA v1.01 and v2.00: 0/1 carrying places, 1272/1292 bytes; PAL absent. Original frame 0x60. Two initial trials plus ABI repair: func_L00_00424F58 takes (char *, float, float); retail passes actor + 0x10 in a0, 0.78539824f (0x3F490FDC) in f12 and +0.0f in f13. Corrected from the invalid three-register declaration; size unchanged. Remaining saved-register roles/block scheduling and field typing require a separate source hypothesis. In particular, the current D_0018B274 int store differs from retail's halfword store; this ABI-only repair leaves it for follow-up. No linked builds. */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
extern char *D_L02_001B359C;
extern char *D_0018A3E0;
extern char D_00189EA0[], D_00188660[];
extern int D_0018B274;
extern unsigned short D_0018CA6C;
extern float D_L02_001B0B80 __attribute__((sda));
extern float D_L02_001B0B84 __attribute__((sda));
extern float D_L02_001B0B88 __attribute__((sda));
extern float D_L02_001B0B8C __attribute__((sda));
extern float D_L02_001B0B90 __attribute__((sda));
extern float D_L02_001B0B94 __attribute__((sda));
extern float D_L02_001B0BA0 __attribute__((sda));
extern float D_L02_001B0BFC;
extern char D_L02_001B0BF0 __attribute__((sda));
extern void func_002A7750(void *, int, int);
extern char *func_0029EFD0(int);
extern void func_002B37E8(void *, void *);
extern float func_00282E80(void *, void *);
extern float func_00282E48(void *, void *);
extern void func_L00_003294F0(void *, int);
extern void func_00282C88(void *);
extern float func_00283248(float, float);
extern float func_00283B98(float, float);
extern float func_00283C80(float, float);
extern void func_002AAA00(void *, void *, int, float, float, float, float);
extern void func_L02_003E8CE8(void *);
extern int func_002E5CF8(int, int, void *);
extern void func_L00_00424F58(char *, float, float);
extern void func_L00_00424C28(void);
extern void func_L00_00424B70(float, float);
extern int func_002B3868(void *);
extern int func_L02_003E8E90(void *);
extern void func_L02_003CADA8(void *, void *);
extern void func_L02_003D01F0(void *, void *);
extern float func_00282C48(float);
extern void func_002E59F8(int);
extern void func_00283098(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern int func_002B38B8(void *);
extern void func_L00_002E6CF0(void (*)(char *), void *);
extern void func_L02_003E98A8(char *);
/* Updates a tether actor's capture, release, turning and attached effect. */
void func_L02_003E87D8(char *actor) {
    char *state = *(char **)(actor + 0x68);
    char *target = D_L02_001B359C + *(int *)state * 0x100;
    float local[4];
    int nextState;
    switch (*(unsigned char *)(actor + 0x20)) {
    case 0:
        *(float *)(state + 0x48) = *(float *)(actor + 0xF8);
        if (*(int *)state == -1) { nextState = 4; goto transition; }
        func_002A7750(actor, 1, -1);
        if (*(short *)(D_L02_001B359C + *(int *)state * 0x100 + 0xAA) == 0x9BC) {
            char *effect = func_0029EFD0(0xA61);
            *(char **)(state + 0x54) = effect;
            if (effect) {
                func_002B37E8(effect, actor);
                *(unsigned short *)(*(char **)(state + 0x54) + 0x34) |= 2;
            }
        }
        break;
    case 1:
        if ((*(unsigned short *)(target + 0x34) & 0x1000) && D_0018A3E0 == target &&
            func_00282E80(target + 0x10, actor + 0x10) < D_L02_001B0B80) {
            func_L00_003294F0(target, 1);
            func_00282C88(state + 0x10);
            nextState = 2;
            goto transition;
        }
        break;
    case 2:
        {
            float separation;
            float angle = func_00283B98(func_00283248(*(float *)(target + 0x10) - *(float *)(actor + 0x10), *(float *)(target + 0x14) - *(float *)(actor + 0x14)), 3.1415927f);
            if (func_00283C80(angle, *(float *)(actor + 0xF8)) > 1.5707964f) angle = func_00283B98(angle, 3.1415927f);
            func_002AAA00(actor + 0xF8, state + 0x40, 0, angle, D_L02_001B0B88 * 0.0000048481375f, D_L02_001B0B88 * 0.0000048481375f * 3.0f, D_L02_001B0B8C * 0.00029088825f);
            func_L02_003E8CE8(actor);
            separation = func_00282E80(actor + 0x10, D_00189EA0);
            if (D_0018A3E0 != target || separation > D_L02_001B0BA0) {
                float distance;
                D_0018A3E0 = 0;
                distance = func_00282E48(actor + 0x10, D_00189EA0) - D_L02_001B0B84;
                if (distance < 0.0f) distance = 0.0f;
                *(unsigned short *)(target + 0x34) &= 0xEFFF;
                *(float *)(state + 0x44) = D_L02_001B0B90 * 0.016666668f + D_L02_001B0B94 * (distance * 0.016666668f);
                func_002E5CF8(0, 0, actor);
                nextState = 3;
            } else {
                D_0018B274 = 2;
                func_L00_00424F58(actor + 0x10, 0.78539824f, 0.0f);
                func_L00_00424C28();
                func_L00_00424B70(0.03f, 0.2f);
                if (*(unsigned short *)(target + 0x34) & 0x1000) break;
                nextState = 1;
            }
        }
transition:
        func_002A7750(actor, nextState, -1);
        break;
    case 3:
        if (func_002B3868(actor)) {
            *(Quad *)(state + 0x10) = 0;
            func_002E5CF8(0, 0, actor);
        }
        if (func_L02_003E8E90(actor)) {
            func_L00_003294F0(target, 0);
            if (*(short *)(target + 0xAA) == 0x9BC) {
                func_L02_003CADA8(target, state + 0x10);
                D_0018CA6C = 0xFFFF;
            } else func_L02_003D01F0(target, state + 0x10);
            func_002A7750(actor, 1, -1);
        }
        break;
    }
    if (func_00282C48(*(float *)(state + 0x40)) > 0.004363324f) {
        char *slot = D_00188660 + *(int *)(state + 0x58) * 0x70;
        if (*(char **)(slot + 0x88) != actor || *(unsigned char *)(slot + 0x74) == 0)
            *(int *)(state + 0x58) = func_002E5CF8(1, 4, actor);
        if (*(unsigned char *)(actor + 0x20) != 2) *(float *)(state + 0x40) = 0;
    } else {
        int index = *(int *)(state + 0x58);
        char *slot = D_00188660 + index * 0x70;
        if (index != -1 && *(char **)(slot + 0x88) == actor && *(unsigned char *)(slot + 0x74)) func_002E59F8(index);
        *(int *)(state + 0x58) = -1;
    }
    if (*(char **)(state + 0x54)) {
        func_00283098(local, &D_L02_001B0BF0, actor + 0xC0);
        func_00282CC0(*(char **)(state + 0x54) + 0x10, local, actor + 0x10);
        *(float *)(*(char **)(state + 0x54) + 0xF8) = *(float *)(actor + 0xF8);
        *(float *)(*(char **)(state + 0x54) + 0x2C) = *(float *)(*(char **)(*(char **)(state + 0x54) + 0x24) + 0x24) * D_L02_001B0BFC;
    }
    if (func_002B38B8(target)) func_L00_002E6CF0(func_L02_003E98A8, actor);
}
