/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 2376 / 2488 bytes; size equality is not a match.
 * us: 0/1 placements; 2376/2488 bytes.
 * us2: not run / not reported.
 * pal: not run / not reported.
 * Residual: Retained complete readable C. Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier. Three complete-source trials: 2436, 2388 and 2376 bytes against 2488, US 0/1. Correctly treating the first height-control global as float and rereading the path point after calls recovered the retail 0x60 frame. State-arm merging, addressing, arithmetic and scheduling still differ. The particle creator ABI requires a final hidden-input audit before promotion. Reopen with independent state-layout or compiler evidence.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Retained complete readable C. Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Three complete-source trials: 2436, 2388 and 2376 bytes against 2488, US 0/1.
 * Correctly treating the first height-control global as float and rereading the path point after calls recovered the retail 0x60 frame.
 * State-arm merging, addressing, arithmetic and scheduling still differ.
 * The particle creator ABI requires a final hidden-input audit before promotion.
 * Reopen with independent state-layout or compiler evidence.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int Quadword __attribute__((mode(TI)));
struct family_27f9_object;
extern int D_L11_001CAE40;
extern int D_0018B068;
extern unsigned int D_00138324;
extern u8 D_00189EA0[];
extern int *D_L11_001FF580[];
extern float D_L11_001B2978 __attribute__((sda));
extern float D_L11_001B297C __attribute__((sda));
extern int D_L11_001AED08;
extern void *func_002B60B0(u8 *, float, float, float, float);
extern void func_L02_0031E9E8(float *, float);
extern void func_00282CC0(float *, float *, float *);
extern void func_002A7750(u8 *, u8, int);
extern int func_002A77E0(int);
extern void func_002A7470(u8 *, int, int, int);
extern float func_00282E48(void *, void *);
extern float func_00282E80(void *, void *);
extern int func_002A7820(int, int);
extern float func_00283B98(float, float);
extern void func_002AF000(float *, float, float, float);
extern int func_L07_00321D68(char *, void *);
extern float func_002A7CA0(struct family_27f9_object *, float *, float, float, float, float);
extern void func_0029F338(void *);
extern float func_00283248(float, float);
extern void func_002AEE70(float *, float *, float *, float, float, float);
extern void func_L01_00321178(char *, char *);
extern void func_002A7A00(float *, float, float);
extern u8 *func_L11_00396DC8(u8 *, float *, float *);
extern void *func_002A9640(void *, unsigned int, int);
extern void func_002B0990(void *, float *, float, int, int);
#define VF(offset) (*(float *)(vars + (offset)))
#define VI(offset) (*(int *)(vars + (offset)))

void func_L11_004702F0(u8 *object) {
    float motion[4], previous[4];
    u8 *vars;
    u8 *particle;
    int *path;
    float angle, distance, speed;
    int first, second, next, i;
    short timer;
    if (D_L11_001CAE40) return;
    vars = *(u8 **)(object + 0x68);
    switch (object[0x20]) {
    case 0:
        *(u8 **)(vars + 0x18) = vars + 0x20;
        *(float *)(object + 0x2C) *= 1.5f;
        *(Quadword *)(vars + 0x110) = *(Quadword *)(object + 0x10);
        VF(0x24) = 0.4f;
        VF(0x54) = 0.25f;
        VF(0x2C) = 0.6f;
        VF(0x50) = 1.48353004f;
        VF(0x4C) = 0.00138888892f;
        VF(0x20) = 0.4f;
        VF(0x28) = 0.6f;
        VF(0x30) = 1.48353004f;
        func_002B60B0(object, 0.000555555569f, 0.0166666675f, 0.00116355298f, 0.104719773f);
        func_L02_0031E9E8((float *)(vars + 0x120), 4.0f);
        func_00282CC0((float *)(vars + 0x120), (float *)(vars + 0x120), (float *)(vars + 0x110));
        func_002A7750(object, VI(0x130), -1);
        object[0x30] = 255;
        first = func_002A77E0(8);
        second = func_002A77E0(18);
        func_002A7470(object, 0, first, second);
        VI(0x144) = 0;
        if (VI(0x140) != -1 && VI(0x130) != 8) {
            *(float *)(object + 0x2C) *= 1.5f;
            if (object[0x43] != 4) {
                first = func_002A77E0(3);
                second = func_002A77E0(8);
                func_002A7470(object, 4, first, second + 10);
            }
            next = 7;
            goto change_state;
        }
        break;
    case 2:
        if (func_00282E48(object + 0x10, D_00189EA0) < 9.0f) {
            if (object[0x43] != 3) func_002A7470(object, 3, 0, 10);
            next = 4;
            goto change_state;
        }
        if (D_0018B068 != 10 && D_0018B068 != 13 && (D_00138324 & 0x20)) {
            if (func_00282E80(object + 0x10, D_00189EA0) >= 64.0f || VI(0x150)) break;
            VF(0x134) = (float)func_002A7820(170, 190);
            if (object[0x43] != 4) func_002A7470(object, 4, 0, 10);
            VF(0x138) = 0.083333336f;
            next = 6;
            goto change_state;
        }
        break;
    case 4:
        if (object[0x60] & 2) {
            VF(0x134) = (float)func_002A7820(170, 190);
            if (object[0x43] != 4) func_002A7470(object, 4, 0, 10);
            VF(0x138) = 0.033333335f;
            next = 5;
            goto change_state;
        }
        break;
    case 5:
        speed = VF(0x138) + 0.008333334f;
        VF(0x138) = speed;
        if (speed > 0.116666675f) VF(0x138) = 0.116666675f;
        *(Quadword *)previous = *(Quadword *)(object + 0x10);
        angle = func_00283B98(*(float *)(object + 0xF8), VF(0x134) * 0.017453294f);
        func_002AF000(motion, VF(0x138), angle, 2.96706009f);
        func_L07_00321D68((char *)object, motion);
        if (func_00282E80(object + 0x10, previous) < VF(0x138)) {
            angle = func_00283B98(*(float *)(object + 0xF8), 3.141593f);
            func_002A7CA0((struct family_27f9_object *)object, (float *)(vars + 0x13C), angle, 0.000199999995f, 0.00200000009f, 0.04f);
        }
        if (func_00282E80(object + 0x10, D_00189EA0) > 64.0f) goto destroy;
        goto adjust_height;
    case 6:
        speed = VF(0x138) + 0.008333334f;
        VF(0x138) = speed;
        if (speed > 0.416666687f) VF(0x138) = 0.416666687f;
        angle = func_00283B98(*(float *)(object + 0xF8), VF(0x134) * 0.017453294f);
        func_002AF000(motion, VF(0x138), angle, 2.96706009f);
        func_00282CC0((float *)(object + 0x10), (float *)(object + 0x10), motion);
        if (func_00282E80(object + 0x10, D_00189EA0) > 64.0f) goto destroy;
        break;
    case 7:
        path = D_L11_001FF580[VI(0x140)];
        distance = func_00282E80(object + 0x10, path + 4 + VI(0x144) * 4);
        angle = func_00283248(distance, ((float *)path)[6 + VI(0x144) * 4] - *(float *)(object + 0x18));
        func_002AF000(motion, 0.116666675f, *(float *)(object + 0xF8), angle);
        angle = func_00283248(((float *)path)[4 + VI(0x144) * 4] - *(float *)(object + 0x10), ((float *)path)[5 + VI(0x144) * 4] - *(float *)(object + 0x14));
        func_002A7CA0((struct family_27f9_object *)object, (float *)(vars + 0x13C), angle, 9.99999975e-05f, 0.00100000005f, 0.02f);
        func_00282CC0((float *)(object + 0x10), (float *)(object + 0x10), motion);
        if (object[0x43] != 4) func_002A7470(object, 4, 0, 10);
        if (func_00282E80(object + 0x10, path + 4 + VI(0x144) * 4) < 0.5f) {
            ++VI(0x144);
            if (VI(0x144) >= *path - 1) VI(0x144) = *path - 1;
        }
        goto adjust_height;
    case 8:
        if (object[0x43] != 2) func_002A7470(object, 2, 0, 10);
        if (func_00282E80(object + 0x10, vars + 0x120) >= 0.5f) {
            if (VI(0xA0)) {
                *(u16 *)(object + 0x96) = 0;
                goto reset_target;
            }
            if (*(u16 *)(object + 0x96) > 239) {
                *(u16 *)(object + 0x96) = 0;
                goto reset_target;
            }
            func_L01_00321178((char *)object, (char *)vars + 0x120);
        } else {
            *(u16 *)(object + 0x96) = 0;
        reset_target:
            VI(0xA0) = 0;
            func_L02_0031E9E8((float *)(vars + 0x120), 4.0f);
            func_00282CC0((float *)(vars + 0x120), (float *)(vars + 0x120), (float *)(vars + 0x110));
            if (func_002A77E0(4) == 1) {
                if (object[0x43] != 1) func_002A7470(object, 1, 0, 10);
                func_002A7750(object, 9, -1);
            }
        }
        if (func_00282E48(object + 0x10, D_00189EA0) < 10.0f) {
            if (object[0x43] != 2) func_002A7470(object, 2, 0, 10);
            next = 4;
            goto change_state;
        }
        break;
    case 9:
        if (object[0x60] & 2) {
            func_002A7750(object, 8, -1);
            if (object[0x43] != 2) func_002A7470(object, 2, 0, 10);
        }
        if (func_00282E48(object + 0x10, D_00189EA0) < 10.0f) {
            if (object[0x43] != 2) func_002A7470(object, 2, 0, 10);
            next = 4;
            goto change_state;
        }
        break;
    change_state:
        func_002A7750(object, next, -1);
        break;
    adjust_height:
        func_002AEE70((float *)object, (float *)(vars + 0x148), (float *)(vars + 0x14C), D_L11_001B2978, D_L11_001B297C * 0.00029088825f, -1.0f);
        break;
    }
    timer = *(short *)(object + 0x96);
    if (timer != -1) *(short *)(object + 0x96) = timer + 1;
    if (object[0x42] == 4) *(float *)(object + 0x48) = 2.5f;
    else if (object[0x42]) *(float *)(object + 0x48) = 1.0f;
    if (!func_002A9640(object, 0x10000, 0)) {
        func_002B0990(object, (float *)(vars + 0x160), 2.5f, 0, 1);
    } else {
        i = 13;
        do {
            --i;
            func_002A7A00(motion, 0.06666667f, 0.100000009f);
            particle = func_L11_00396DC8(object, (float *)(object + 0x10), motion);
            particle[0x30] = 255;
            *(u16 *)(particle + 0x32) = 255;
        } while (i >= 0);
        ++D_L11_001AED08;
        goto destroy;
    }
    return;
destroy:
    func_0029F338(object);
}
