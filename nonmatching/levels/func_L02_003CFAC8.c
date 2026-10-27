/*
 * Complete manual reconstruction retained as nonmatching; no exact-C, linked-build
 * or runtime credit. Fresh worker checks on 2026-10-25, base dcfcd1f90746f3fbba715825d25bf19e88bf875c.
 * Tested profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * Coverage: US: 0/1 placements; US2: 0/1 placements; PAL: absent from both catalogues.
 * US compiled size: 1820 bytes; retail: 1832 bytes.
 * Remaining difference: 1820 bytes versus 1832. The function-scope (self + 0x10) view and actor pointer have different saved-register assignments from retail; prologue/global-test scheduling and later branches differ. The complete constructor and emitter argument banks are retained.
 * Reopen only with: A qualified actor/(self + 0x10) access shape and state lifetime that explains the retail register interference while retaining the six-GPR/three-FP emitter and twelve-GPR/two-FP constructor.
 * Earlier complete variants and command logs are preserved privately.
 */
/* M34 2026-10-26: 1832/1832, profile -O2 -G0 -ffunction-sections -frac2-hazard-labels.
 * Closed: self+0x10 at each use (retail's PRE copy into $s5), the radius store as if/else,
 * the two state stores swapped, the detonate and respawn calls written in place (cross-jumped
 * by the compiler), NOT_SDA on the absolute globals, the shake slots as a struct, the else-arm
 * first for the radius ramp, the 0xD8 state word through a union view.
 * Left (two instructions, order only): before func_L01_0031BC68 retail issues the 0xD8 store,
 * both word loads, then mov.s $f12 in the slot; here the loads come first and the store fills
 * the slot. Register/order-only: permuter queued.
 */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef union { Quad quad; float f[4]; } Vector;
extern int D_L02_001CAA80 NOT_SDA;
extern char *D_L02_001C0958 NOT_SDA;
extern char D_00189E20[] NOT_SDA;
typedef struct { float amount; int unk4; int time; int phase; char pad[0x10]; } ShakeSlot;
typedef struct { char pad[0x160]; ShakeSlot slot[2]; } Shake;
typedef union { char b[0x100]; int i[0x40]; float f[0x40]; } PlatformState;
extern Shake D_L02_001BA3C0;
extern u16 D_0018CA60 NOT_SDA;
extern Vector D_L02_001BA500;
extern int D_L02_001B0130 __attribute__((sda)), D_L02_001B0138 __attribute__((sda));
extern float D_L02_001B0134 __attribute__((sda));
extern int D_L02_001B013C, D_L02_001B0140;
extern float func_002A89A8(void *, int, float), func_00282E48(void *, void *), func_00283B98(float, float), func_002AA340(int *, int, int);
extern void func_L01_0031AB20(char *, void *, int, float, float, float), func_002A7750(u8 *, int, int), func_L02_003D0238(char *), func_L02_003D02F0(char *);
extern int func_00283CF0(float), func_002B3868(u8 *), func_002B38B8(u8 *), func_00282948(int *), func_002E5CF8(int, int, char *), func_002E5DA0(int, int, char *, int);
extern int func_L01_0031BC68(int, int, float), func_00277258(void *, int, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern int func_002A8C28(void *, float, float *, int, float, float, int, int, int);
/* Full constructor: (self + 0x10), seven register words, four stack words, and two FP inputs. */
extern void *func_0032C700(void *, int, int, int, int, int, int, int, int, int, int, int, float, float);
/* Drives the timed platform through activation, falling, detonation and respawn. */
void func_L02_003CFAC8(char *self) {
    Vector point;
    char *state;
    float shake, radius;
    int timer, hits, i, old;
    if (D_L02_001CAA80) return;
    state = *(char **)(self + 0x68);
    switch (((u8 *)self)[0x20]) {
    case 0:
        ((u8 *)self)[0x30] = 0xFF; *(u16 *)(self + 0x34) |= 0x1000;
        *(float *)(state + 0x84) = 2.75f; *(float *)(state + 0xE0) = 0.333f;
        *(u32 *)(state + 0x70) |= 6; ((u8 *)self)[0x20] = 1;
        *(float *)(self + 0x18) = func_002A89A8((self + 0x10), 0, 0.5f) + 0.7f;
        if (D_L02_001C0958) *(float *)(state + 0x88) = 14.5f;
        else *(float *)(state + 0x88) = 10.0f;
        qcopy(state + 0xA0,(self + 0x10));
        break;
    case 1:
        func_L01_0031AB20(self, state + 0x50, -1, 0.5f, 0.5f, 0.1f);
        if (D_L02_001B0130) { D_L02_001B0130 = 0; func_002A7750((u8 *)self, 5, -1); break; }
        if (*(char **)(D_00189E20 + 0x5C0) != self) break;
        D_0018CA60 = 0xFFFF; func_002A7750((u8 *)self, 2, -1);
        *(int *)(state + 0xD4) = func_00283CF0(*(float *)(state + 0xC0) * 60.0f);
        break;
    case 2:
        if (func_002B3868((u8 *)self)) *(int *)(state + 0xDC) = 0;
        func_L01_0031AB20(self, state + 0x50, -1, 0.5f, 0.5f, 0.1f);
        if (*(int *)(state + 0xC4) != -1 && *(char **)(D_00189E20 + 0x5C0) == self) func_L02_003D02F0(self);
        timer = *(int *)(state + 0xD4);
        if (timer % 60 == 10 || (timer < 120 && timer % 30 == 10)) func_002E5DA0(1, 0, self, 0x1F9);
        if (func_00282948((int *)(state + 0xD4))) { func_002A7750((u8 *)self, 5, -1); break; }
        if (func_002B38B8((u8 *)self)) func_002A7750((u8 *)self, 3, -1);
        break;
    case 4:
        func_00282CC0((self + 0x10), (self + 0x10), state + 0xB0);
        *(float *)(state + 0xB8) -= 0.004166667f;
        hits = 0; i = 0;
        do {
            qcopy(&point,(self + 0x10));
            point.f[2] += (float)i; ++i;
            if (func_00277258(&point, 0, self, *(float *)(state + 0xE0))) hits = 1;
        } while (i < 1);
        if (hits || *(float *)(self + 0x18) < *(float *)(state + 0xA8) - 1.0f) func_002A7750((u8 *)self, 5, -1);
        if (*(float *)((self + 0x10)) < 2 || *(float *)((self + 0x10)) > 1021 || *(float *)(self + 0x14) < 2 ||
            *(float *)(self + 0x14) > 1021 || *(float *)(self + 0x18) < 2 || *(float *)(self + 0x18) > 1021)
            func_002A7750((u8 *)self, 6, -1);
        break;
    case 5:
        if (func_002B3868((u8 *)self)) {
            func_0032C700((self + 0x10), 1, 25, 20, 20, 20, 45, 0, 1, 1, 0, 0, D_L02_001B0134, 20.0f);
            ((u8 *)self)[0x31] = 0; *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 1) & 0xEFFF;
            func_002E5CF8(1, 0, self);
            shake = (24.0f - func_00282E48(&D_L02_001BA500, (self + 0x10))) * 0.0062500006f;
            if (shake > 0.15f) shake = 0.15f; else if (shake < 0) shake = 0;
            if (shake != 0) {
                D_L02_001BA3C0.slot[1].time = 90;
                D_L02_001BA3C0.slot[0].phase = 0;
                D_L02_001BA3C0.slot[1].amount = shake;
            }
        }
        func_002A8C28(self, (float)*(u16 *)(self + 0x96) * 0.5f, (float *)((self + 0x10)), 0x830000, 5.0f, 1.0f, 0, 1, 0);
        if (D_L02_001C0958 && *(short *)(D_L02_001C0958 + 0xAA) == 0xC82) func_002AA340((int *)(state + 0xE4), 0, 4);
        if (*(u16 *)(self + 0x96) < 11) break;
        old = *(int *)(state + 0xE4); *(int *)(state + 0xE4) = old + 1;
        if (old + 1 >= 8) {
            radius = (float)(old - 6) * 0.09514286f + 0.333f;
            *(float *)(state + 0xE0) = radius;
            if (radius > 1) *(float *)(state + 0xE0) = 1;
        } else *(float *)(state + 0xE0) = 0.333f;
        func_002A8C28(self, 6.0f, (float *)((self + 0x10)), 0x830000, 10.0f, 1.0f, 0, 1, 0);
        func_002A7750((u8 *)self, 6, -1); break;
    case 6:
        qcopy(&point,state + 0xA0); point.f[2] += 0.7f;
        if (!func_00277258(&point, 5, self, 0.75f)) func_L02_003D0238(self);
        break;
    case 3: default: break;
    }
    if (((u8 *)self)[0x31]) {
        *(float *)(self + 0xF4) = func_00283B98(*(float *)(self + 0xF4), 0.026179943f);
        *(float *)(self + 0xF8) = func_00283B98(*(float *)(self + 0xF4), 0.015126189216971397f);
        if (((u8 *)self)[0x20] == 1) *(int *)(self + 0x78) = D_L02_001B0138;
        else {
            ((PlatformState *)state)->f[0xD8 / 4] = func_00283B98(((PlatformState *)state)->f[0xD8 / 4], 0.20943955f);
            *(int *)(self + 0x78) = func_L01_0031BC68(D_L02_001B013C, D_L02_001B0140, ((PlatformState *)state)->f[0xD8 / 4]);
        }
    }
    ++*(u16 *)(self + 0x96);
}
