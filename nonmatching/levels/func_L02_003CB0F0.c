/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Prior worker coverage: US 0/1; US2 absent from catalogue; PAL absent from catalogue.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/* Nonmatching: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier. us: func_L02_003CB0F0: 0 of 1 places match (src/levels/02_maktar_nebula/L02_003CB0F0.c); us2: absent; pal: absent. Two complete manual controlflow forms; final5572/5824 frame0xB0. Bothfull switches covered. Correctly recognized FC20outputs as64-byte transforms and FCC0outputs as16-byte vectors, avoiding Ghidra apparentuninitialized stacklocals. SixGPR/threeFP pointer-return emitter00401530 qualified. L01_00321178actuallyforwardsintflags (canonicalrepairrequestedlead); dispatchunsignedlong64 retained. Remaining252bytes/reg/branch and literal-load differences; reopen with original lifetime/expression evidence. Unused declarations removed; no behavioral change. */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef union { Quad quad; float f[4]; } Vector;
struct L02NearObject;
struct L02GroupObject;
extern char D_00189E20[] NOT_SDA;
extern char *D_L02_001C0958, *D_L02_001FF1C0[];
extern int D_L02_001B30C8;
extern int func_L02_003CC7B0(char *), func_L02_003CCFE8(char *, void *);
extern void func_L02_003CCCC8(char *), func_L02_003CCEA0(char *), func_L02_003CD1E8(char *, void *), func_L02_003CD758(char *);
extern void func_L02_003CD298(struct L02NearObject *), func_L02_003CD4A8(struct L02GroupObject *), func_L02_003CED70(char *, void *, void *);
extern u8 *func_L02_003CEBB8(int);
extern void func_0029F338(void *), func_002A7750(u8 *, u8, int), func_002A7470(char *, int, int, int), func_002A6C58(char *, void *, int);
extern int func_002B3868(u8 *), func_002B3890(u8 *), func_002A77E0(int), func_002A7820(int, int), func_00282978(short *);
extern void *func_002B60B0(u8 *, float, float, float, float);
extern unsigned long func_002B1C20(void *, void *);
extern void func_L01_003E9CF8(char *, int, void (*)(char *));
/* The retail wrapper forwards B50E0's GPR flags. */
extern int func_L01_00321178(char *, char *), func_L01_00322288(int, float), func_L02_00331440(void *, void *, int, float, float, float), func_L02_00332630(char *, void *);
extern float func_00283248(float, float), func_00283C80(float, float), func_00282E48(void *, void *), func_00282E80(void *, void *), func_00282C48(float), func_00282DB0(void *, void *), func_0029F530(char *);
extern int func_002761F8(void *, void *, int, char *, void *), func_002ABB78(char *), func_002AEB60(char *, float), func_002ACBC8(void *, int), func_002B6120(char *, char *), func_002B6318(u8 *);
extern int func_002A8D70(float, float, float, void *, void *, int, int, int, int);
extern void func_0029FC20(char *, int, char *), func_0029FCC0(char *, int, char *), func_00282CF0(void *, void *, void *), func_00282F20(void *, void *, float), func_00282D30(void *, void *, float);
extern void *func_L02_00401530(void *, void *, void *, int, int, int, float, float, float);
/* Runs a ranged enemy's patrol, attack, group coordination and projectile states. */
void func_L02_003CB0F0(char *self) {
    Vector muzzle, velocity, acceleration, transform[4];
    char *state = *(char **)(self + 0x68), *path, *other, *hit;
    unsigned long flags;
    float angle, time;
    int choice, animation, newState, collision;
    if (func_L02_003CC7B0(self)) { func_0029F338(self); return; }
    switch ((u8)self[0x95]) {
    case 0:
        if (func_002B3890((u8 *)self)) func_002B60B0((u8 *)self, 0.0011111111380159855f, 0.050000004f, 0.0034906589426100254f, 0.41887909173965454f);
        if (*(int *)(state + 0x204) == 1) {
            if (*(int *)(state + 0x33C)) { *(int *)(state + 0x33C) = 0; func_002A7750((u8 *)self, 8, 2); }
            else func_002A7750((u8 *)self, 10, 2);
        } else if (*(short *)(state + 0x382)) {
            func_002A7750((u8 *)self, 3, 1); *(short *)(state + 0x382) = 0; *(short *)(state + 0x374) = func_002A7820(480, 600);
        }
        break;
    case 1:
        if (func_002B3890((u8 *)self)) func_002B60B0((u8 *)self, 0.002222222276031971f, 0.10000001f, 0.0034906589426100254f, 0.41887909173965454f);
        if (*(int *)(state + 0x204) == 1) func_002A7750((u8 *)self, 10, 2);
        else if (!*(short *)(state + 0x374)) {
            if (func_00282E80(self + 0x10, D_00189E20 + 0x80) <= 26) *(short *)(state + 0x374) = 120;
            else func_002A7750((u8 *)self, 1, 0);
        }
        break;
    case 2:
        if (func_002B3890((u8 *)self)) {
            func_L02_003CD298((struct L02NearObject *)self);
            func_002B60B0((u8 *)self, 0.002222222276031971f, 0.10000001f, 0.0034906589426100254f, 0.41887909173965454f);
        }
        if (*(int *)(state + 0x204) != 1 && ((u8)self[0x60] & 2) && (u8)self[0x20] != 11) {
            if (func_00282E48(self + 0x10, state + 0x340) > 4) func_002A7750((u8 *)self, 6, -1);
            else {
                choice = func_002A77E0(4);
                if (!choice) func_002A7750((u8 *)self, 3, 1);
                else if (choice == 1) func_002A7750((u8 *)self, 4, 1);
                else if (choice == 2) func_002A7750((u8 *)self, 5, 1);
                else if (choice == 3) func_002A7750((u8 *)self, 7, 1);
            }
            *(short *)(state + 0x374) = func_002A7820(580, 600);
        }
        break;
    case 3:
        flags = func_002B1C20(self, state + 0x50);
        if (flags & 1) {
            other = *(char **)(state + 0x370); *(u16 *)(other + 0x34) |= 0x41; *(u16 *)(other + 0x34) &= 0xEFFF; *(int *)(other + 0x98) = 0;
            func_002A6C58(self, 0, 3); func_L01_003E9CF8(self, 0, func_L02_003CD758); return;
        }
        if (flags & 2) {
            *(int *)(state + 0x33C) = 0;
            if (*(int *)(state + 0x320) == -1) {
                if (*(int *)(state + 0x204) == 1) func_002A7750((u8 *)self, 10, 2);
                else { func_002A7750((u8 *)self, 3, 1); *(short *)(state + 0x374) = func_002A7820(580, 600); }
            } else func_002A7750((u8 *)self, 18, 4);
        }
        break;
    case 4:
        if (func_002B3890((u8 *)self)) {
            func_002B60B0((u8 *)self, 0.0033333334140479565f, 0.10000001f, 0.0034906589426100254f, 0.41887909173965454f); *(float *)(state + 0x134) = 0.25f;
        }
        break;
    }
    switch ((u8)self[0x20]) {
    case 1:
        if (func_002B3868((u8 *)self) && (u8)self[0x43]) func_002A7470(self, 0, 0, 20);
        if (!((u8)self[0x60] & 2)) break;
        if (!func_002A77E0(4)) { newState = 5; goto change; }
        else if (!*(int *)(state + 0x33C)) { newState = 2; goto change; }
        break;
    case 2:
        if (func_002B3868((u8 *)self)) {
            if ((u8)self[0x43] != 5) func_002A7470(self, 5, 0, 20); func_L02_003CD1E8(self, state + 0x350);
        }
        if ((func_L01_00321178(self, state + 0x350) & 0x80) || *(u16 *)(self + 0x96) >= 181 || *(int *)(state + 0x180) >= 21) { newState = 5; goto change; }
        break;
    case 3:
        if (func_002B3868((u8 *)self) && (u8)self[0x43] != 9) func_002A7470(self, 9, 0, 20);
        angle = func_00283248(*(float *)(state + 0x1F0) - *(float *)(self + 0x10), *(float *)(state + 0x1F4) - *(float *)(self + 0x14));
        if (func_00283C80(*(float *)(self + 0xF8), angle) > 0.26179942f) { newState = 9; goto change; }
        else if (((u8)self[0x60] & 2) && func_002A77E0(2)) {
            choice = func_002A77E0(3); if (!choice) { newState = 4; goto change; } else if (choice == 1) { newState = 5; goto change; } else if (choice == 2) { newState = 7; goto change; }
        }
        break;
    case 4:
        if (func_002B3868((u8 *)self)) {
            animation = func_L02_003CCFE8(self, state + 0x350) ? 18 : 17;
            if (*(u16 *)(self + 0x34) & 0x8000) animation = animation == 17 ? 18 : 17;
            if ((u8)self[0x43] != animation) func_002A7470(self, animation, 0, 10);
        }
        angle = func_00283248(*(float *)(state + 0x350) - *(float *)(self + 0x10), *(float *)(state + 0x354) - *(float *)(self + 0x14));
        if ((func_L02_00331440(self, state + 0x350, 16, angle, -1, -1) & 0x80) || *(u16 *)(self + 0x96) >= 121) { newState = 3; goto change; }
        break;
    case 5:
        if (func_002B3868((u8 *)self)) {
            if (!(u8)self[0x95]) { if ((u8)self[0x43] != 1) func_002A7470(self, 1, 0, 20); }
            else if ((u8)self[0x95] == 1 && (u8)self[0x43] != func_002A77E0(2) + 3) func_002A7470(self, func_002A77E0(2) + 3, 0, 20);
        }
        if ((u8)self[0x60] & 2) { if (!(u8)self[0x95]) { newState = 1; goto change; } else if ((u8)self[0x95] == 1) { newState = 3; goto change; } }
        break;
    case 6:
        if (func_002B3868((u8 *)self) && (u8)self[0x43] != 6) func_002A7470(self, 6, 0, 15);
        if ((func_L01_00321178(self, state + 0x340) & 0x80) || *(u16 *)(self + 0x96) >= 241) { newState = 3; goto change; }
        break;
    case 7:
        if (func_002B3868((u8 *)self)) { animation = func_002A77E0(2) ? 20 : 21; if ((u8)self[0x43] != animation) func_002A7470(self, animation, 0, 15); }
        if ((u8)self[0x60] & 2) { newState = 3; goto change; }
        break;
    case 8:
        if (func_002B3868((u8 *)self) && (u8)self[0x43] != 2) func_002A7470(self, 2, 0, 10);
        angle = func_00283248(*(float *)(state + 0x1F0) - *(float *)(self + 0x10), *(float *)(state + 0x1F4) - *(float *)(self + 0x14));
        func_L01_00322288((int)self, angle); func_L02_003CCEA0(self); if ((u8)self[0x60] & 2) { newState = 10; goto change; }
        break;
    case 9:
        if (func_002B3868((u8 *)self) && (u8)self[0x43] != 5) func_002A7470(self, 5, 0, 10);
        angle = func_00283248(*(float *)(state + 0x1F0) - *(float *)(self + 0x10), *(float *)(state + 0x1F4) - *(float *)(self + 0x14));
        func_L01_00322288((int)self, angle); func_L02_003CCEA0(self);
        angle = func_00283248(*(float *)(state + 0x1F0) - *(float *)(self + 0x10), *(float *)(state + 0x1F4) - *(float *)(self + 0x14));
        if (!(func_00283C80(*(float *)(self + 0xF8), angle) >= 0.087266475f)) {
            if ((u8)self[0x95] == 1) { newState = 3; goto change; } else if ((u8)self[0x95] == 2) { newState = 10; goto change; }
        }
        break;
    case 10:
        if (func_002B3868((u8 *)self) && (u8)self[0x43] != 9) func_002A7470(self, 9, 0, 20);
        func_L02_003CCEA0(self);
        angle = func_00283248(*(float *)(state + 0x1F0) - *(float *)(self + 0x10), *(float *)(state + 0x1F4) - *(float *)(self + 0x14));
        if (func_00283C80(*(float *)(self + 0xF8), angle) > 0.52359885f) { { newState = 9; goto change; } break; }
        if (!*(short *)(state + 0x378) && *(u16 *)(self + 0x96) > 15) {
            func_0029FCC0(*(char **)(state + 0x370), 0, (char *)&muzzle);
            collision = func_002761F8(&muzzle, D_00189E20 + 0xD0, 16, self, 0); hit = D_L02_001C0958;
            if (collision && hit && *(short *)(hit + 0xAA) == 0xC1B) { { newState = 13; goto change; } break; }
            if (collision && hit != *(char **)(D_00189E20 + 0x2290) && !*(short *)(state + 0x386)) {
                if (!hit || (!func_002ABB78(hit) && (!*(char **)(hit + 0x24) || *(short *)(*(char **)(hit + 0x24) + 0x46) != 22))) break;
            }
            { newState = 11; goto change; }
        } else {
            if (func_00282E80(self + 0x10, D_00189E20 + 0x80) < 3 && func_00282C48(*(float *)(self + 0x18) - *(float *)(D_00189E20 + 0x88)) < 0.5f) { { newState = 14; goto change; } break; }
            if (((u8)self[0x60] & 2) && !func_002A77E0(2)) { newState = 13; goto change; }
        }
        break;
    case 11:
        if (func_002B3868((u8 *)self)) {
            if ((u8)self[0x43] != 10) func_002A7470(self, 10, 0, 10);
            *(short *)(state + 0x380) = func_002A7820(3, 5); func_L02_003CD4A8((struct L02GroupObject *)self);
            *(Quad *)(state + 0x360) = *(Quad *)(state + 0x1F0); *(float *)(state + 0x368) += 0.5f;
        }
        func_L02_003CCEA0(self);
        if ((D_L02_001B30C8 & 15) == (((u32)self >> 8) & 15)) func_L02_003CD4A8((struct L02GroupObject *)self);
        if (func_002AEB60(self, 5)) {
            func_0029FCC0(*(char **)(state + 0x370), 0, (char *)&muzzle);
            func_00282CF0(&velocity, state + 0x360, &muzzle); func_00282F20(&velocity, &velocity, 0.23333334922790527f);
            func_00282D30(&acceleration, &velocity, 0.25f);
            choice = *(short *)(state + 0x380) < 2;
            func_L02_00401530(&muzzle, &acceleration, &velocity, choice ? 30 : 10, choice ? 80 : 30, 1,
                              (float)(u8)state[0x34], (float)(u8)state[0x34], 0.0055555556900799274f);
            break;
        }
        if (!((u8)self[0x60] & 2)) break;
        func_0029FCC0(*(char **)(state + 0x370), 0, (char *)&muzzle);
        collision = func_002761F8(&muzzle, D_00189E20 + 0xD0, 0, self, 0);
        if (func_00282978((short *)(state + 0x380)) || (collision && D_L02_001C0958 != *(char **)(D_00189E20 + 0x2290))) {
            *(short *)(state + 0x378) += 15; { newState = func_002A77E0(3) ? 13 : 12; goto change; }
        } else {
            angle = func_00283248(*(float *)(state + 0x1F0) - *(float *)(self + 0x10), *(float *)(state + 0x1F4) - *(float *)(self + 0x14));
            if (func_00283C80(*(float *)(self + 0xF8), angle) > 0.52359885f) { newState = 9; goto change; }
            else if (*(int *)(D_00189E20 + 0x229C) == 7 && *(char **)(D_00189E20 + 0x249C) && *(short *)(*(char **)(D_00189E20 + 0x249C) + 0xAA) == 0xB5A) { newState = 12; goto change; }
        }
        break;
    case 12:
        if (func_002B3868((u8 *)self)) { animation = *(int *)(D_00189E20 + 0x229C) == 7 ? 12 : 11; if ((u8)self[0x43] != animation) func_002A7470(self, animation, 0, 20); }
        func_L02_003CCEA0(self); if ((u8)self[0x60] & 2) { newState = 10; goto change; }
        break;
    case 13:
        if (func_002B3868((u8 *)self)) {
            animation = func_L02_003CCFE8(self, state + 0x350) ? 18 : 17;
            if (*(u16 *)(self + 0x34) & 0x8000) animation = animation == 17 ? 18 : 17;
            if ((u8)self[0x43] != animation) func_002A7470(self, animation, 0, 10);
        }
        angle = func_00283248(*(float *)(state + 0x350) - *(float *)(self + 0x10), *(float *)(state + 0x354) - *(float *)(self + 0x14));
        if ((func_L02_00331440(self, state + 0x350, 16, angle, -1, -1) & 0x80) || *(u16 *)(self + 0x96) > 120 || *(int *)(state + 0x180) >= 21) { newState = 10; goto change; }
        break;
    case 14:
        if (func_002B3868((u8 *)self) && (u8)self[0x43] != 13) func_002A7470(self, 13, 0, 10);
        angle = func_00283248(*(float *)(state + 0x1F0) - *(float *)(self + 0x10), *(float *)(state + 0x1F4) - *(float *)(self + 0x14));
        func_L01_00322288((int)self, angle); time = func_0029F530(self);
        if (time >= 11 && time < 12.5f) func_002A8D70(0.6f, (float)(u8)state[0x35], 3.0f, self, (void *)3, 1, 0, 1, 0);
        if ((u8)self[0x60] & 2) { newState = 15; goto change; }
        break;
    case 15:
        if (func_002B3868((u8 *)self) && (u8)self[0x43] != 11) func_002A7470(self, 11, 10, 10);
        func_L02_003CCEA0(self); if (!((u8)self[0x60] & 2)) break;
        angle = func_00283248(*(float *)(state + 0x1F0) - *(float *)(self + 0x10), *(float *)(state + 0x1F4) - *(float *)(self + 0x14));
        { newState = func_00283C80(*(float *)(self + 0xF8), angle) <= 0.52359885f ? 11 : 9; goto change; }
        break;
    case 16:
        if (*(float *)(state + 0x20) <= 0) {
            if (func_002B3868((u8 *)self)) { *(short *)(state + 0x378) = func_002A7820(10, 15); *(short *)(state + 0x384) = func_002A77E0(3) == 0; }
            if (*(short *)(state + 0x384) && func_00282978((short *)(state + 0x378))) {
                func_0029FC20(*(char **)(state + 0x370), 0, (char *)transform);
                func_00282F20(&muzzle, transform, 0.23333334922790527f);
                func_00282CF0(&velocity, D_00189E20 + 0xE0, &transform[3]); func_00282F20(&velocity, &velocity, 1);
                if (func_00282DB0(&velocity, transform) < 0.2f) {
                    func_L02_00401530(&transform[3], &muzzle, &muzzle, 30, 80, 1, 1.0f, 0.0f, 1.0f);
                    *(short *)(state + 0x378) = func_002A7820(15, 30);
                }
            }
        }
        break;
    case 17:
        if (func_002B3868((u8 *)self) && (u8)self[0x43]) func_002A7470(self, 0, 0, 20);
        if (func_002ACBC8(D_00189E20 + 0x80, *(int *)(state + 0x324)) || *(int *)(state + 0x204) == 1) { newState = 18; goto change; }
        break;
    case 18:
        path = D_L02_001FF1C0[*(int *)(state + 0x320)];
        if (func_002B3868((u8 *)self)) { if ((u8)self[0x43] != 6) func_002A7470(self, 6, 0, 20); func_002B6318((u8 *)self); }
        if (*(float *)(state + 0x134) <= func_00282E80(self + 0x10, path + *(int *)path * 16) && !func_002B6120(self, path)) break;
        if ((u8)self[0x43] != 2) {
            angle = func_00283248(*(float *)(state + 0x1F0) - *(float *)(self + 0x10), *(float *)(state + 0x1F4) - *(float *)(self + 0x14));
            if (func_00283C80(*(float *)(self + 0xF8), angle > 0.3490659f ? 1.0f : 0.0f) != 0 && (u8)self[0x43] != 2) func_002A7470(self, 2, 5, 10);
        }
        func_L02_00332630(self, state + 0x1F0);
        angle = func_00283248(*(float *)(state + 0x1F0) - *(float *)(self + 0x10), *(float *)(state + 0x1F4) - *(float *)(self + 0x14));
        if (func_00283C80(*(float *)(self + 0xF8), angle) < 0.087266475f && ((u8)self[0x43] != 2 || ((u8)self[0x60] & 2))) {
            *(int *)(state + 0x320) = -1; *(Quad *)(state + 0x340) = *(Quad *)(self + 0x10);
            if (*(int *)(state + 0x328) == -1) func_002A7750((u8 *)self, 1, 0); else func_002A7750((u8 *)self, 19, 4);
        }
        break;
    case 19:
        if (func_002B3868((u8 *)self) && (u8)self[0x43]) func_002A7470(self, 0, 0, 20);
        if (*(int *)(state + 0x32C) == -1 || func_002ACBC8(D_00189E20 + 0x80, *(int *)(state + 0x32C)) || *(int *)(state + 0x204) == 1) { newState = 20; goto change; }
        break;
    case 20:
        if (func_002B3868((u8 *)self)) {
            if ((u8)self[0x43] != 9) func_002A7470(self, 9, 0, 20);
            if (*(float *)(state + 0x37C) == 0) *(float *)(state + 0x37C) = func_002A77E0(2) ? 0.3490659f : -0.3490659f;
            else *(float *)(state + 0x37C) = -*(float *)(state + 0x37C);
        }
        *(float *)(state + 0x278) = *(float *)(state + 0x37C);
        if (*(u16 *)(self + 0x96) < 11) break;
        if (!func_L02_003CEBB8(*(int *)(state + 0x328))) func_002A7750((u8 *)self, 3, 1); else { newState = 21; goto change; }
        break;
    case 21:
        if (func_002B3868((u8 *)self) && (u8)self[0x43] != 10) func_002A7470(self, 10, 0, 10);
        *(float *)(state + 0x278) = *(float *)(state + 0x37C);
        if (!func_002AEB60(self, 5)) { if ((u8)self[0x60] & 2) func_002A7750((u8 *)self, 20, -1); }
        else if ((other = (char *)func_L02_003CEBB8(*(int *)(state + 0x328))) != 0) {
            func_0029FC20(*(char **)(state + 0x370), 0, (char *)transform);
            func_00282F20(&velocity, transform, 0.23333334922790527f); muzzle.quad = transform[3].quad; func_L02_003CED70(other, &muzzle, &velocity);
        }
        break;
    case 22:
        if (func_002B3868((u8 *)self)) { if ((u8)self[0x43] != 6) func_002A7470(self, 6, 0, 20); func_002B6318((u8 *)self); }
        if (func_L01_00321178(self, state + 0x340) & 0x80) { func_002A7750((u8 *)self, 1, 0); *(Quad *)(state + 0x340) = *(Quad *)(self + 0x10); }
        break;
    }
    goto finish;
change:
    func_002A7750((u8 *)self, newState, -1);
finish:
    func_L02_003CCCC8(self);
}

/* Historical screening only; superseded by the measured reconstruction above. */
