/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 2052 / 2108 bytes; size equality is not a match.
 * us: 0/1 placements; 2052/2108 bytes.
 * us2: not run / not reported.
 * pal: not run / not reported.
 * Residual: Retained complete readable C. Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier. Two complete-source trials: 2060/2108 then 2052/2108 bytes, US 0/1. Moving tracking/rate initialisation to the aiming stage recovered the retail 0x80 frame. Addressing, state-merge layout and scheduling remain different. The current shared wrapper L01_003246D0 omits its live forwarded a0 input; this caller preserves the observed object argument. Reopen after that API is qualified and an original state/aim layout is identified.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Retained complete readable C. Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Two complete-source trials: 2060/2108 then 2052/2108 bytes, US 0/1.
 * Moving tracking/rate initialisation to the aiming stage recovered the retail 0x80 frame.
 * Addressing, state-merge layout and scheduling remain different.
 * The current shared wrapper L01_003246D0 omits its live forwarded a0 input; this caller preserves the observed object argument.
 * Reopen after that API is qualified and an original state/aim layout is identified.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int Quadword __attribute__((mode(TI)));
typedef struct BarlowUtilityQueueView BarlowUtilityQueueView;
extern u8 D_001A7B00, D_001A7A40;
extern u32 D_001397D0, D_00138324;
extern u8 D_00139568[];
extern int D_001A79F8;
extern u8 D_00189EA0[];
extern u8 D_L11_001C0AC0[];
extern u8 *D_L11_001B368C;
extern u8 D_L11_00279BA0[];
extern int D_L11_001B32E8;
extern int D_L11_001A8F00;
extern void func_L04_00434AD0(void);
extern void func_002A7750(u8 *, u8, int);
extern void func_L01_003128C0(char *);
extern int func_002ACBC8(char *, int);
extern int func_00288AA0(u8 *, int);
extern int func_00288BE8(BarlowUtilityQueueView *);
extern int func_002F5D10(void);
extern void func_L00_002B9D60(float *, float *, int, int);
extern int func_L01_003245E0(u8 *, int, float);
extern void func_L00_0030C710(int);
extern void func_L01_00324550(int, int, int);
extern void func_L01_003246D0(u8 *);
extern void func_002A8598(int, int);
extern void func_00288308(int);
extern void func_002B0A18(int, int);
extern int func_0029B3E0(int, int);
extern void func_0029F338(void *);
extern int func_00282978(void *);
extern float func_002A7878(float, float);
extern int func_00283CF0(float);
extern void func_002A7470(u8 *, int, int, int);
extern float func_00282E80(void *, void *);
extern float func_00283248(float, float);
extern float func_00283C80(float, float);
extern float func_00282DF0(void *);
extern int func_00282948(void *);
extern float func_00283B98(float, float);
extern void func_002AF000(float *, float, float, float);
extern void func_00282CC0(float *, float *, float *);
extern void func_00282CF0(float *, float *, float *);
extern float func_00283BE0(float, float);
extern float func_00282E20(void *);
extern void func_002AEC48(u8 *, void *, int, float, float);

void func_L11_004618C0(u8 *object) {
    float destination[4], origin[4], difference[4];
    u8 *vars = *(u8 **)(object + 0x68);
    u8 *record;
    int next, index, tracking;
    int animation;
    float rate;
    float yaw, pitch, distance, a, b;
    func_L04_00434AD0();
    switch (object[0x20]) {
    case 0:
        if (D_001A7B00) goto destroy;
        if (!(D_001397D0 & 0x800)) func_002A7750(object, 1, -1);
        else func_002A7750(object, 2, -1);
        func_L01_003128C0((char *)object);
        break;
    case 1:
        if (func_002ACBC8((char *)D_00189EA0, *(int *)(vars + 0x120)) && func_00288AA0(D_L11_001C0AC0, 0x6B)) {
            func_L01_003246D0(object);
            func_00288BE8((BarlowUtilityQueueView *)D_L11_001C0AC0);
            next = 2;
            goto change_state;
        }
        break;
    case 2:
        D_L11_001B32E8 = 1;
        if (D_L11_001A8F00 == 2) {
            object[0x31] = 0;
            *(u16 *)(object + 0x34) |= 1;
        }
        if (!func_002F5D10()) {
            D_L11_001B32E8 = 0;
            record = D_L11_001B368C + *(int *)(vars + 0x120) * 0x80;
            func_L00_002B9D60((float *)(record + 0x30), (float *)(record + 0x70), 0, 1);
            object[0x31] = 1;
            *(u16 *)(object + 0x34) &= 0xFFFE;
            if (D_001A79F8 < *(int *)(D_L11_00279BA0 + D_00139568[8] * 0xE0 + 0x80)) next = 3;
            else next = 4;
            goto change_state;
        }
        break;
    case 3:
        if (*(int *)(D_L11_00279BA0 + D_00139568[8] * 0xE0 + 0x80) < D_001A79F8) {
            next = 4;
            goto change_state;
        }
        if (func_L01_003245E0(object, 10, 2.5f)) {
            func_L00_0030C710(180);
            func_L01_00324550(0x27BC, *(int *)(D_L11_00279BA0 + D_00139568[8] * 0xE0 + 0x80), -1);
            func_L01_003246D0(object);
        }
        break;
    case 4:
        if (D_001A79F8 < *(int *)(D_L11_00279BA0 + D_00139568[8] * 0xE0 + 0x80)) {
            func_L00_0030C710(180);
            next = 3;
            goto change_state;
        }
        if (func_L01_003245E0(object, 10, 2.5f)) {
            func_L00_0030C710(180);
            func_L01_00324550(0x27BB, *(int *)(D_L11_00279BA0 + D_00139568[8] * 0xE0 + 0x80), -1);
            func_L01_003246D0(object);
            if ((D_00138324 & 0x10) && func_00288AA0(D_L11_001C0AC0, 0x6C)) {
                func_00288BE8((BarlowUtilityQueueView *)D_L11_001C0AC0);
                next = 5;
                goto change_state;
            }
        }
        break;
    case 5:
        D_L11_001B32E8 = 1;
        if (D_L11_001A8F00 == 2) {
            object[0x31] = 0;
            *(u16 *)(object + 0x34) |= 1;
        }
        if (!func_002F5D10()) {
            D_L11_001B32E8 = 0;
            object[0x31] = 1;
            *(u16 *)(object + 0x34) &= 0xFFFE;
            if ((signed char)object[0x21] != -1) func_002A8598((signed char)object[0x21], 1);
            if (!D_001A7B00) {
                D_001A79F8 = D_001A79F8 - *(int *)(D_L11_00279BA0 + D_00139568[8] * 0xE0 + 0x80);
                func_L00_0030C710(180);
                func_00288308(8);
            }
            index = *(int *)(vars + 0x124);
            if (index != -1) {
                record = D_L11_001B368C + index * 0x80;
                func_L00_002B9D60((float *)(record + 0x30), (float *)(record + 0x70), 0, 1);
            }
            func_002B0A18(0x1230, -1);
            func_0029B3E0(0, -1);
            goto destroy;
        }
        break;
    change_state:
        func_002A7750(object, next, -1);
        break;
    }
    animation = object[0x43];
    if (object[0x20] != 0) {
        if (animation == 0 && func_00282978(vars + 0x11E)) {
            *(short *)(vars + 0x11E) = func_00283CF0(func_002A7878(1200.0f, 2400.0f));
            if (object[0x43] != 1) func_002A7470(object, 1, 0, 10);
            animation = object[0x43];
            goto aim;
        }
        if ((object[0x60] & 2) && object[0x43] != 0) func_002A7470(object, 0, 0, 10);
        animation = object[0x43];
    }
aim:
    tracking = 0;
    rate = 0.02f;
    if (animation == 0) {
        tracking = 1;
        distance = func_00282E80(object + 0x10, D_00189EA0);
        if (distance < 8.0f && func_00283C80(*(float *)(object + 0xF8), func_00283248(*(float *)(D_00189EA0 + 0x60) - *(float *)(object + 0x10), *(float *)(D_00189EA0 + 0x64) - *(float *)(object + 0x14))) < 1.5707965f) {
            if (func_00282DF0(D_00189EA0 + 0x90) > 0.01f) *(int *)(vars + 0x114) = 120;
            else func_00282948(vars + 0x114);
        } else if (*(int *)(vars + 0x114)) {
            *(int *)(vars + 0x114) = 0;
            *(Quadword *)(vars + 0x100) = *(Quadword *)(D_00189EA0 + 0x60);
        }
        if (func_00282948(vars + 0x118)) {
            *(int *)(vars + 0x118) = func_00283CF0(func_002A7878(180.0f, 300.0f));
            a = func_002A7878(-90.0f, 90.0f);
            yaw = func_00283B98(*(float *)(object + 0xF8), a * 0.017453294f);
            b = func_002A7878(0, 30.0f);
            func_002AF000((float *)(vars + 0x100), 6.0f, yaw, b * 0.017453294f);
            func_00282CC0((float *)(vars + 0x100), (float *)(vars + 0x100), (float *)(object + 0x10));
        }
        if (*(int *)(vars + 0x114)) {
            *(Quadword *)destination = *(Quadword *)(D_00189EA0 + 0x60);
            rate = 0.04f;
        } else *(Quadword *)destination = *(Quadword *)(vars + 0x100);
    }
    if (tracking) {
        *(Quadword *)origin = *(Quadword *)(object + 0x10);
        origin[2] += 2.0f;
        func_00282CF0(difference, destination, origin);
        yaw = func_00283BE0(func_00283248(difference[0], difference[1]), *(float *)(object + 0xF8));
        pitch = -func_00283248(func_00282E20(difference), difference[2]);
        if (yaw > 1.5707965f) yaw = 1.5707965f;
        else if (yaw < -1.5707965f) yaw = -1.5707965f;
        if (pitch > 0.52359885f) pitch = 0.52359885f;
        else if (pitch < -0.52359885f) pitch = -0.52359885f;
        *(float *)(vars + 0x64) = pitch;
        *(float *)(vars + 0x68) = yaw * 0.6f;
        *(float *)(vars + 0xE8) = yaw * 0.4f;
    }
    if (D_001A7A40) *(float *)(vars + 0x70) = 2.75f;
    func_002AEC48(object, vars, 0, rate, 0.3f);
    func_002AEC48(object, vars + 0x80, 1, rate, 0.3f);
    return;
destroy:
    func_0029F338(object);
}
