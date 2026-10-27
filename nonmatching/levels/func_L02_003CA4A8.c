/*
 * Complete manual reconstruction retained as nonmatching; no exact-C, linked-build
 * or runtime credit. Fresh worker checks on 2026-10-25, base dcfcd1f90746f3fbba715825d25bf19e88bf875c.
 * Tested profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-barrier
 * Coverage: US: 0/1 placements; US2: 0/1 placements; PAL: absent from both catalogues.
 * US compiled size: 2276 bytes; retail: 2304 bytes.
 * Remaining difference: 2276 bytes versus 2304. A resident-prefix pointer remains live in a saved register, changing the prologue and body scheduling. State transitions remain complete; both observed CAE68 calls retain their real second pointer argument.
 * Reopen only with: A qualified resident-object access/lifetime shape that removes the extra long-lived pointer and explains remaining scheduling while preserving both actual CAE68 argument slots.
 * Earlier complete variants and command logs are preserved privately.
 */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef union { Quad quad; float f[4]; } Vector;
extern char D_00189E20[] NOT_SDA;
extern Vector D_L02_001BA500, D_L02_001C0970, D_L02_001C0980;
extern char *D_L02_001FF1C0[];
extern float D_L02_001B0080 __attribute__((sda)), D_L02_001B0084 __attribute__((sda)), D_L02_001B0088 __attribute__((sda));
extern float D_L02_001B008C __attribute__((sda)), D_L02_001B0090 __attribute__((sda));
extern int D_L02_001B0098 __attribute__((sda)), D_L02_001B009C NOT_SDA, D_L02_001B30C8 NOT_SDA;
extern float func_00282E48(void *, void *), func_00282E80(void *, void *), func_00282DB0(void *, void *), func_00282E20(void *), func_00283248(float, float), func_00283B98(float, float);
extern void func_002A93B0(char *), func_002A7750(u8 *, int, int), func_002A7470(char *, int, int, int);
extern int func_002B3868(u8 *), func_002B38B8(u8 *), func_002A77E0(int), func_L01_00322288(int, float);
extern int func_L02_0032E508(void *, int, void *, int), func_L02_0032EDD8(void *, void *, int, int *), func_L02_003CADF0(char *, int), func_002ACBC8(void *, int), func_00277258(void *, int, void *, float);
extern void *func_002B60B0(u8 *, float, float, float, float);
extern void func_L02_003CAE68(char *, void *), func_L02_003CB090(char *);
extern void func_L01_0031AB20(char *, void *, int, float, float, float);
extern void func_00282CC0(void *, void *, void *), func_00282C88(Quad *), func_00282F70(void *, void *, float), func_00282F20(void *, void *, float), func_00283028(void *, void *, void *), func_00282D30(void *, void *, float);
extern int func_L01_0031BC68(int, int, float);
/* Updates a path-following enemy through idle, patrol, pursuit and falling states. */
/* Measured field-at-use prefix; no whole resident allocation size is inferred. */
typedef struct { u8 prefix[0x80]; Vector position_80; u8 gap_90[0x530]; char *pointer_5c0; } L02_ResidentGrabPrefix;
void func_L02_003CA4A8(char *self) {
    L02_ResidentGrabPrefix *hero=(L02_ResidentGrabPrefix *)D_00189E20;
    char *state = *(char **)(self + 0x68), *path;
    Vector point;
    int step, nextState;
    float slope, length;
    if (((u8 *)self)[0x31] && func_00282E48(self + 0x10, &D_L02_001BA500) < 24.0f) {
        func_002A93B0(self); ((u8 *)self)[0x6F] = 22;
    }
    if (!((u8 *)self)[0x95]) {
        if (self == hero->pointer_5c0) {
            func_002A7750((u8 *)self, 5, 1); qcopy(state + 0x150,self + 0x10);
        } else if (func_00282E80(self + 0x10, &hero->position_80) < *(float *)(state + 0x178)) *(u16 *)(self + 0x34) |= 0x1000;
        else *(u16 *)(self + 0x34) &= 0xEFFF;
    }
    switch (((u8 *)self)[0x20]) {
    case 0:
        *(float *)(self + 0x2C) = *(float *)(*(char **)(self + 0x24) + 0x24) * D_L02_001B0080;
        *(short *)(state + 0x24) = 1; *(int *)(state + 0x8C) = *(int *)(state + 0x394);
        *(float *)(state + 0x20) = 1; *(float *)(state + 0x30) = 1.5f; *(float *)(state + 0x84) = 0.05f;
        *(float *)(state + 0x54) = 0.2f; *(float *)(state + 0x50) = 0.825f; *(float *)(state + 0x5C) = 0.4f;
        *(float *)(state + 0x60) = 1.5707964897155762f; *(float *)(state + 0x80) = 0.523598849773407f;
        *(u32 *)(state + 0x88) |= 1; *(char **)(state + 0x9C) = state + 0x190;
        *(float *)(state + 0x174) = 4; *(float *)(state + 0x178) = 12; *(float *)(state + 0x58) = 0.4f;
        *(short *)(state + 0x3B6) = func_L02_0032E508(self, *(int *)(state + 0x390), state + 0x290, 8);
        ((u8 *)self)[0x20] = 1; ((u8 *)self)[0x30] = 0x80; *(u16 *)(self + 0x34) |= 0x1000;
        break;
    case 1:
        if (func_002B3868((u8 *)self) && ((u8 *)self)[0x43] != func_002A77E0(2)) func_002A7470(self, func_002A77E0(2), 0, 10);
        if (*(int *)(state + 0x3C0) < (int)*(u16 *)(self + 0x96)) { nextState = 2; goto change; }
        break;
    case 2:
        if (func_002B3868((u8 *)self)) {
            if (((u8 *)self)[0x43] != 4) func_002A7470(self, 4, 0, 20);
            func_002B60B0((u8 *)self, 0.0011111111380159855f, D_L02_001B0088 * 0.016666668f, 0.0008726647356525064f, 0.10471977293491364f);
            func_L02_003CAE68(self, state + 0x3A0);
        }
        func_L02_003CADF0(self, (int)(state + 0x3A0));
        if ((*(u32 *)(state + 0xE4) & 0x80) || *(u16 *)(self + 0x96) >= 300) { nextState = 1; goto change; }
        break;
    case 3:
        if (func_002B3868((u8 *)self)) {
            if (((u8 *)self)[0x43] != 5) func_002A7470(self, 5, 0, 20);
            func_002B60B0((u8 *)self, 0.003888888983055949f, D_L02_001B008C * 0.016666668f, 0.0034906589426100254f, 0.41887909173965454f);
            func_L02_003CAE68(self, state + 0x3A0);
        }
        func_L02_003CADF0(self, (int)(state + 0x3A0));
        if (*(u16 *)(self + 0x96) >= 420) { nextState = 1; goto change; }
        break;
    case 4:
        if (func_002B3868((u8 *)self)) {
            if (((u8 *)self)[0x43] != 5) func_002A7470(self, 5, 0, 20);
            func_002B60B0((u8 *)self, 0.002222222276031971f, D_L02_001B008C * 0.016666668f, 0.0034906589426100254f, 0.20943954586982727f);
        }
        func_L02_003CADF0(self, (int)(&hero->position_80));
        if (*(float *)(state + 0x11C) < 6) { nextState = 1; goto change; }
        break;
    case 5:
        if (func_002B3868((u8 *)self)) {
            if (((u8 *)self)[0x43] != 7) func_002A7470(self, 7, 0, 10);
            *(short *)(state + 0x3B4) = 0;
        }
        slope = func_00282DB0(self + 0xC0, state + 0x140);
        if (slope < -0.033333335f) { if (((u8 *)self)[0x43] != 10) func_002A7470(self, 10, 0, 10); }
        else if (slope > 0.033333335f) { if (((u8 *)self)[0x43] != 9) func_002A7470(self, 9, 0, 10); }
        else if (((u8 *)self)[0x43] != 7) func_002A7470(self, 7, 0, 10);
        func_L01_00322288((int)self, func_00283248(hero->position_80.f[0] - *(float *)(self + 0x10), hero->position_80.f[1] - *(float *)(self + 0x14)));
        func_L01_0031AB20(self, state + 0x140, *(int *)(state + 0x394), 0.7f, 0.5f, 0.1f);
        func_L02_003CB090(self);
        if (func_002B38B8((u8 *)self)) { nextState = 6; goto change; }
        if (self != hero->pointer_5c0) func_002A7750((u8 *)self, 3, 0);
        break;
    case 6:
        if (func_002B3868((u8 *)self) && ((u8 *)self)[0x43] != 13) func_002A7470(self, 13, 0, 10);
        func_L01_00322288((int)self, func_00283248(hero->position_80.f[0] - *(float *)(self + 0x10), hero->position_80.f[1] - *(float *)(self + 0x14)));
        func_L02_003CB090(self);
        break;
    case 7:
        func_00282CC0(self + 0x10, self + 0x10, state + 0xF0);
        *(float *)(state + 0xF8) -= D_L02_001B0084 * 0.00027777778f;
        func_L02_003CB090(self);
        if (func_002ACBC8(self + 0x10, *(int *)(state + 0x398))) {
            length = func_00282E20(state + 0xF0); if (length > 0.016666668f) length = 0.016666668f;
            func_00282F70(state + 0xF0, state + 0xF0, length);
        }
        qcopy(&point,self + 0x10); point.f[2] += 0.5f;
        if (func_00277258(&point, 0, self, 0.5f)) {
            qcopy(self + 0x10,&D_L02_001C0970); *(float *)(self + 0x18) -= 0.5f;
            func_00282F20(&D_L02_001C0980, &D_L02_001C0980, 1);
            if (func_00282DB0(&D_L02_001C0980, state + 0xF0) < 0) {
                func_00283028(state + 0xF0, state + 0xF0, &D_L02_001C0980);
                func_00282D30(state + 0xF0, state + 0xF0, 0.5f);
            }
            if (D_L02_001C0980.f[2] >= 0.95f) {
                *(u16 *)(self + 0x34) |= 0x1000; func_002A7750((u8 *)self, 1, 0);
                qzero(state + 0xF0); qcopy(state + 0x150,self + 0x10);
                func_00282C88((Quad *)(state + 0x140));
            }
        }
        break;
    }
    goto finish;
change:
    func_002A7750((u8 *)self, nextState, -1);
finish:
    if (((u8 *)self)[0x31]) {
        *(float *)(state + 0x3B0) = func_00283B98(*(float *)(state + 0x3B0), D_L02_001B0090 * 0.0002908882452175021f);
        *(int *)(self + 0x78) = func_L01_0031BC68(D_L02_001B0098, D_L02_001B009C, *(float *)(state + 0x3B0));
    }
    if ((D_L02_001B30C8 & 31) == (((u32)self >> 8) & 31)) {
        step = *(int *)(state + 0x3C4);
        func_L02_0032EDD8(&hero->position_80, state + 0x290, *(short *)(state + 0x3B6), &step);
        if (*(int *)(state + 0x3C4) < step) {
            path = D_L02_001FF1C0[*(int *)(state + step * 0x20 + 0x290)];
            if (func_00282E48(path + 0x10, path + (*(int *)path >> 1) * 16 + 0x10) > 8) *(int *)(state + 0x3C4) = step;
        }
    }
    ++*(u16 *)(self + 0x96);
}
