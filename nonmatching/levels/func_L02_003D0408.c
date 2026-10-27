/*
 * Complete manual reconstruction retained as nonmatching; no exact-C, linked-build
 * or runtime credit. Fresh worker checks on 2026-10-25, base dcfcd1f90746f3fbba715825d25bf19e88bf875c.
 * Tested profile: -O2 -G8 -ffunction-sections -mno-split-addresses
 * Coverage: US: 0/1 placements; US2: 0/1 placements; PAL: absent from both catalogues.
 * US compiled size: 3296 bytes; retail: 3304 bytes.
 * Remaining difference: 3296 bytes versus 3304. The target-selection branch shape, float-component staging and later scheduling differ. Native TI copies are deliberately retained because the three observed retail transfers fold LQ/SQ into ordinary scheduling. FC248 is called with all three actual GPR slots.
 * Reopen only with: A source-backed target-selection/control-flow lifetime that reproduces branch-likely and float staging, with the actual native TI copies and full integer/FP call interfaces unchanged.
 * Earlier complete variants and command logs are preserved privately.
 */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef union { Quad quad; float f[4]; } Vector;
extern char D_00189E20[] NOT_SDA;
extern int D_L02_001B0148 __attribute__((sda));
extern void func_L02_003D10F0(char *), func_L02_003D14F8(char *), func_L02_003D1588(char *), func_L02_003D1610(char *), func_L02_003D1430(char *), func_L02_003D1C38(char *);
extern void func_L02_003D25C8(char *, float *), func_L02_003D1ED0(char *, Quad *), func_L02_003D2390(char *), func_L02_003FC248(void *, int, int);
extern int func_L02_003D26B0(char *), func_L02_003D1698(char *), func_002B3868(u8 *), func_002B3890(u8 *), func_002A77E0(int), func_L02_003FC0B8(char *), func_L00_003206B8(void *, int), func_L00_0042AB40(void);
extern char *func_L02_003FC098(char *);
extern float func_00283248(float, float), func_00282E80(void *, void *), func_00283C80(float, float), func_0029F530(char *);
/* Retail forwards the final dot product in F0. */
extern float func_L02_003D1820(char *, char *);
extern void func_002A7750(u8 *, int, int), func_002A7470(char *, int, int, int);
extern int func_L01_00321178(char *, char *);
extern int func_002B50E0(char *, int, float), func_002B4FF0(char *, float *, float);
extern void func_002B5258(char *), func_002B5278(u8 *, float), func_0029F978(u8 *, u32, u8 *), func_00282A60(char *, int, int), func_002A7A00(float *, float, float);
extern unsigned long func_002B1C20(void *, void *);
extern void func_002B0A68(char *, int, int, u8, float, float, float, float), func_L01_003E9CF8(char *, int, void (*)(char *));
extern void *func_002B60B0(u8 *, float, float, float, float);
/* Runs the armed enemy's target selection and combat animation state machines. */
void func_L02_003D0408(char *self) {
    Vector target, scratch;
    char *state, *owner, *point;
    char *targetObject;
    float heading, distance, turn, time, saved, targetX, targetY;
    unsigned long flags;
    int stateByte = (u8)self[0x20], choice;
    if (stateByte == 1 || !self || stateByte == 0xFE || stateByte == 0xFD) return;
    state = *(char **)(self + 0x68);
    func_L02_003D10F0(self);
    flags = 0;
    stateByte = (u8)self[0x20];
    if (stateByte == 1 || stateByte == 0xFE || stateByte == 0xFD) return;
    if (!*(short *)(state + 0x2F6)) {
        *(char **)(state + 0x2E0) = 0;
        if ((u8)self[0x95] != 2 && (u8)self[0x95] != 7 && (u8)self[0x95] != 1) func_L02_003D14F8(self);
    }
    targetObject = *(char **)(state + 0x2E0);
    if (targetObject) {
        target.quad = *(Quad *)(targetObject + 0x10);
        targetX = *(float *)(*(char **)(state + 0x2E0) + 0x10);
        targetY = *(float *)(*(char **)(state + 0x2E0) + 0x14) - *(float *)(self + 0x14);
    } else {
        target.quad = *(Quad *)(D_00189E20 + 0x80);
        targetX = *(float *)(D_00189E20 + 0x80);
        targetY = *(float *)(D_00189E20 + 0x84) - *(float *)(self + 0x14);
    }
    heading = func_00283248(targetX - *(float *)(self + 0x10), targetY);
    distance = func_00282E80(self + 0x10, &target);
    switch ((u8)self[0x95]) {
    case 2:
        if (func_002B3890((u8 *)self)) {
            owner = *(char **)(self + 0xB8); point = func_L02_003FC098(owner);
            if ((u8)self[0x43] != 3) func_002A7470(self, 3, 0, 10);
            self[0xBC] = 0; func_L02_003D25C8(self, (float *)point); *(u16 *)(self + 0x96) = 10000;
        }
        if ((u8)self[0xBC] == 1 && *(u16 *)(self + 0x96) > 300) {
            choice = func_002A77E0(2);
            if (!choice) { if ((u8)self[0x43] != 1) func_002A7470(self, 1, 0, 10); }
            else if (choice == 1 && (u8)self[0x43]) func_002A7470(self, 0, 0, 10);
            *(u16 *)(self + 0x96) = func_002A77E0(100);
        }
        if (*(short *)(state + 0x2F6)) func_L02_003D1588(self);
        if (!(u8)self[0xBC] && func_00282E80(self + 0x10, state + 0x2D0) < 0.5f) { self[0xBC] = 1; break; }
        func_002B50E0(self, (int)(state + 0x2D0), heading);
        break;
    case 3:
        if (!func_L02_003D26B0(self)) {
            if ((u8)self[0x42] == 2) func_L01_00321178(self, (char *)&target);
            else if ((u8)self[0x42] == 3) func_002B4FF0(self, target.f, *(float *)(state + 0x2E8));
        }
        break;
    case 4:
        if (distance > 14) func_L02_003D1588(self);
        else if (!func_L02_003D1698(self)) {
            if (distance < 4) {
                turn = func_00283C80(*(float *)(self + 0xF8), heading);
                if (!(turn >= 0.26179942f)) { func_002A7750((u8 *)self, 11, -1); break; }
            }
            if ((u8)self[0x20] == 11 && distance > 5) func_002A7750((u8 *)self, 10, -1);
        }
        break;
    case 5:
        if ((u8)self[0x60] & 2) func_L02_003D1610(self);
        break;
    case 6: func_002B5278((u8 *)self, heading); break;
    case 7:
        flags = func_002B1C20(self, state + 0x50);
        if (*(float *)(state + 0x20) <= 1 && *(char **)(state + 0x2E4)) {
            scratch.quad = *(Quad *)(*(char **)(state + 0x2E4) + 0x10); func_L02_003D1ED0(self, &scratch.quad);
        }
        if (*(float *)(state + 0x20) <= 0 && !(u8)state[0x291]) {
            func_00282A60(state + 0x290, 0, 64); func_0029F978((u8 *)self, 3, (u8 *)(state + 0x290));
            *(float *)(state + 0x2B0) = 0.0001f; *(float *)(state + 0x2B8) = 0.0001f; *(float *)(state + 0x2B4) = 0.0001f; state[0x292] = 1;
            func_002A7A00(scratch.f, 0.016666668f, 0.050000004f);
            func_002B0A68(self, 0x20, (int)&scratch, 0xFF, 3.0f, 6.0f, 3.0f, 6.0f);
        }
        if ((flags & 1) || (*(float *)(state + 0x20) <= 0 && *(u16 *)(self + 0x96) > 60)) {
            *(int *)(self + 0x98) = 0; func_L02_003FC248(self, 0, -1); func_L01_003E9CF8(self, 0, func_L02_003D2390);
        }
        break;
    }
    switch ((u8)self[0x20]) {
    case 3:
        if (func_002B3868((u8 *)self)) {
            self[0xBC] = 0; if ((u8)self[0x43]) func_002A7470(self, 0, 0, 0); *(int *)(state + 0x13C) = -1;
        }
        if (!(u8)self[0xBC] && (int)*(short *)(state + 0x2FC) < (int)*(u16 *)(self + 0x96)) {
            if ((u8)self[0x43] != 3) func_002A7470(self, 3, 0, 10); self[0xBC] = 1;
        } else if ((u8)self[0xBC] == 1) {
            owner = *(char **)(self + 0xB8);
            if (func_L00_003206B8(self + 0x10, func_L02_003FC0B8(owner))) {
                func_002A7750((u8 *)self, 4, 2); *(int *)(state + 0x13C) = func_L00_0042AB40();
            }
            point = func_L02_003FC098(*(char **)(self + 0xB8)); func_L01_00321178(self, point);
        }
        break;
    case 6:
        if (distance <= 14) { if (distance < 4 || *(int *)(state + 0x180) > 30) func_L02_003D1610(self); }
        else {
            func_002B60B0((u8 *)self, 0.0055555556900799274f, 0.10333333909511566f, 0.0034906589426100254f, 0.41887909173965454f);
            func_002A7750((u8 *)self, 7, 3); if ((u8)self[0x43] != 3) func_002A7470(self, 3, 0, 10);
        }
        break;
    case 7:
        if (distance < 4 || *(u16 *)(self + 0x96) > 450 || *(int *)(state + 0x180) > 30) func_L02_003D1588(self);
        break;
    case 8: case 9:
        turn = func_L02_003D1820(self, (char *)&target);
        if (((u8)self[0x20] == 8 && turn > -0.01f) || ((u8)self[0x20] == 9 && turn < 0.01f)) {
            func_002A7750((u8 *)self, 10, -1); if ((u8)self[0x43] != 6) func_002A7470(self, 6, 0, 10); func_002B5258(self);
        } else if (func_0029F530(self) > 5) {
            saved = *(float *)(state + 0x130); *(float *)(state + 0x130) = 0.01745329424738884f;
            func_002B5278((u8 *)self, heading); *(float *)(state + 0x130) = saved;
        }
        break;
    case 10:
        time = func_0029F530(self); turn = func_L02_003D1820(self, (char *)&target);
        if (turn > 0.01f) { func_002A7750((u8 *)self, 9, -1); if ((u8)self[0x43] != 5) func_002A7470(self, 5, 0, 10); }
        else if (turn < -0.01f) { func_002A7750((u8 *)self, 8, -1); if ((u8)self[0x43] != 4) func_002A7470(self, 4, 0, 10); }
        else if (distance < 4) func_002A7750((u8 *)self, 11, -1);
        else {
            if (time < 2) func_002B60B0((u8 *)self, 0.0055555556900799274f, 0.033333335f, 0.0034906589426100254f, 0.41887909173965454f);
            else if ((time > 10 && func_0029F530(self) < 17) || time >= 20) goto face_target;
            func_L01_00321178(self, (char *)&target); break;
        }
face_target:
        func_002B5278((u8 *)self, heading); break;
    case 11:
        if (func_002B3868((u8 *)self) && (u8)self[0x43] != 1) func_002A7470(self, 1, 0, 10);
        func_002B5278((u8 *)self, heading);
        /* fall through */
    case 19: case 20:
        if (flags & 2) func_L02_003D14F8(self);
        break;
    case 13:
        if ((u8)self[0x60] & 2) { *(float *)(self + 0x48) = 0.5f; func_002A7750((u8 *)self, 14, -1); if ((u8)self[0x43] != 9) func_002A7470(self, 9, 0, 10); }
        break;
    case 14:
        if (distance < 4) {
            D_L02_001B0148 = 0; *(float *)(self + 0x48) = 1; func_002A7750((u8 *)self, 15, -1);
            if ((u8)self[0x43] != 10) func_002A7470(self, 10, 10, 10);
        } else {
            if (distance <= 4) {
                if (!((u8)self[0x60] & 2)) break;
                choice = D_L02_001B0148++; if (choice < 3) break; D_L02_001B0148 = 0;
            }
            *(float *)(self + 0x48) = 1; func_L02_003D14F8(self);
        }
        break;
    case 15: case 18:
        if ((u8)self[0x60] & 2) {
            *(short *)(state + 0x2F8) = 0;
            if (*(char **)(D_00189E20 + 0x249C) == self) {
                func_002A7750((u8 *)self, 12, 5); if ((u8)self[0x43] != 7) func_002A7470(self, 7, 0, 10);
            } else func_L02_003D14F8(self);
        }
        func_L02_003D1C38(self); break;
    case 16:
        if ((u8)self[0x60] & 2) { *(float *)(self + 0x48) = 0.5f; func_002A7750((u8 *)self, 17, -1); if ((u8)self[0x43] != 12) func_002A7470(self, 12, 0, 10); }
        break;
    case 17:
        if (distance < 4) {
            D_L02_001B0148 = 0; *(float *)(self + 0x48) = 1; func_002A7750((u8 *)self, 18, -1);
            if ((u8)self[0x43] != 13) func_002A7470(self, 13, 10, 10);
        } else if (distance <= 4) {
            if ((u8)self[0x60] & 2) { choice = D_L02_001B0148++; if (choice > 2) { D_L02_001B0148 = 0; *(float *)(self + 0x48) = 1; func_L02_003D14F8(self); } }
        } else { *(float *)(self + 0x48) = 1; func_L02_003D14F8(self); }
        break;
    }
    func_L02_003D1430(self);
}
