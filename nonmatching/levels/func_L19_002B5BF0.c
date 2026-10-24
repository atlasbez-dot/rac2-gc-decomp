/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 1160 / 1144 bytes; size equality is not a match.
 * us: 0/1 placements; 1160/1144 bytes.
 * us2: not run / not reported.
 * pal: not run / not reported.
 * Residual: Retained complete readable C. Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier. Three complete-source trials: 1156/1144 and 1160/1144 bytes, US 0/1. The frame remains 0x50 instead of 0x40, with address rematerialisation and allocation differences. Shared retail ABI audit confirms float E5F0/E668 results and the A6708/A4EF8 input contracts. Reopen with a meaningful source-layout/control-flow hypothesis.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Retained complete readable C. Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Three complete-source trials: 1156/1144 and 1160/1144 bytes, US 0/1.
 * The frame remains 0x50 instead of 0x40, with address rematerialisation and allocation differences.
 * Shared retail ABI audit confirms float E5F0/E668 results and the A6708/A4EF8 input contracts.
 * Reopen with a meaningful source-layout/control-flow hypothesis.
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef int Quadword __attribute__((mode(TI)));
extern u8 D_00189E20[];
extern u8 D_L19_001C4100[];
extern int D_L19_001A8F00;
extern int D_L19_001B0040;
extern u8 D_001A7A32;
extern u8 D_001A7A33;
extern float func_L00_0037E668(void);
extern float func_L00_0037E5F0(float);
extern void func_L00_002A6708(void);
extern void func_00282CF0(float *, float *, float *);
extern void func_L00_002D36E0(float *, int, float, float, float);
extern void func_L19_002C44F8(int, int);
extern void *func_002A9640(void *, u32, int);
extern int func_00283CF0(float);
extern void func_L00_002A4EF8(int);
extern int func_L00_002B9B88(int, int);
extern void func_L00_002B2C58(int, int, float, float);
extern void func_L00_002D3C68(char *, char *, float);
extern void func_00282CC0(float *, float *, float *);

int func_L19_002B5BF0(int apply) {
    float movement[4];
    u8 *slot;
    u8 *moby;
    u8 *vars;
    u8 *target;
    int special;
    int state;
    float speed;
    u8 *initial = D_00189E20;
    if (*(int *)(initial + 0x229C) == 20 || *(int *)(initial + 0x229C) == 7 || *(int *)(initial + 0x2294) == 0x31) goto reject;
    if (*(short *)(initial + 0x1DC)) goto reject;
    if (D_L19_001A8F00) goto reject;
    *(int *)(initial + 0x249C) = 0;
    moby = *(u8 **)(initial + 0x2290);
    if (moby[0xA8] == 255) goto reject;
    slot = D_L19_001C4100 + moby[0xA8] * 0x40;
    if (*(u8 **)(slot + 0x38) != moby) goto reject;
    if (initial[0x22B4] == 4) {
        if (D_L19_001B0040 || *(int *)(initial + 0x2294) == 0x6F) goto reject;
    } else if ((*(u32 *)(slot + 0x24) & 9) == 0) goto reject;
    if (*(float *)(slot + 0x2C) != 0) {
        D_001A7A33 = 0;
        D_001A7A32 = 1;
    }
    if (func_L00_0037E668() != 0 && D_00189E20[0x22B4] == 0) {
        speed = func_L00_0037E5F0(*(float *)(slot + 0x2C));
        *(float *)(slot + 0x2C) = speed;
        if (speed == 0) goto reject;
    }
    *(int *)(D_00189E20 + 0x249C) = *(int *)(slot + 0x20);
    if (D_00189E20[0x22B4] == 4 && D_L19_001B0040 == 0 && *(int *)(D_00189E20 + 0x2294) != 0x6F) {
        vars = *(u8 **)(*(u8 **)(D_00189E20 + 0x2290) + 0x68);
        *(unsigned short *)(vars + 0x3BC) -= 180;
        if (*(short *)(vars + 0x3BC) < 0) *(short *)(vars + 0x3BC) = 0;
    }
    if (!apply) return 1;
    special = 0;
    func_L00_002A6708();
    if (*(u32 *)(slot + 0x30) & 1) {
        *(Quadword *)movement = *(Quadword *)(slot + 0x10);
        if (*(float *)(slot + 0x1C) == 5627.9248f) special = 1;
    } else if (*(u8 **)(slot + 0x20) != 0) {
        func_00282CF0(movement, (float *)(D_00189E20 + 0x80), (float *)(*(u8 **)(slot + 0x20) + 0x10));
    } else {
        func_L00_002D36E0(movement, 0, -1.0f, 0, 0);
    }
    if (D_00189E20[0x22B4] != 0) {
        if (D_00189E20[0x22B4] == 4) {
            func_L19_002C44F8(0x90, 1);
            func_L00_002B2C58((int)movement, special, 0.083333336f, 0.050000004f);
        }
    } else {
        target = *(u8 **)(D_00189E20 + 0x249C);
        if (target && (*(short *)(target + 0xAA) == 0x4EB || *(short *)(target + 0xAA) == 0x558)) {
            func_L19_002C44F8(0x7D, 1);
            return 1;
        }
        state = *(int *)(D_00189E20 + 0x2294);
        if ((state == 1 || state == 0x1D || *(int *)(D_00189E20 + 0x1500)) && !(*(u32 *)(slot + 0x24) & 8)) {
            u8 *player = D_00189E20;
            target = func_002A9640(*(u8 **)(player + 0x2290), 1, 0);
            if (target) func_L00_002A4EF8(func_00283CF0(*(float *)(target + 0x2C)));
            if (*(int *)(player + 0x24CC) == 0) func_L19_002C44F8(0x16, 1);
            *(short *)(player + 0x1DC) = 77;
            if (*(short *)(player + 0x21C) == 0) *(short *)(player + 0x21C) = 18;
            func_L00_002B9B88(20, 0);
            goto reject;
        }
        state = *(int *)(D_00189E20 + 0x229C);
        if (state == 18) func_L19_002C44F8(0x72, 1);
        else if (state == 17) func_L19_002C44F8(0x73, 1);
        else if (*(u32 *)(slot + 0x24) & 8) func_L19_002C44F8(0x8C, 1);
        else func_L19_002C44F8(0x16, 1);
        if (*(int *)(D_00189E20 + 0x2294) == 0x8C) {
            *(Quadword *)movement = 0;
        } else {
            float acceleration = 0.055f;
            if (D_00189E20[0x1497]) acceleration = 0;
            func_L00_002B2C58((int)movement, special, acceleration, 0.028333336f);
            if (special && slot[0x28] == 4) func_L00_002D3C68((char *)movement, (char *)movement, 2.0f);
        }
    }
    {
    u8 *player = D_00189E20 + 0xF0;
    func_00282CC0((float *)player, (float *)player, movement);
    player += 0x20;
    func_00282CC0((float *)player, (float *)player, movement);
    return 1;
    }
reject:
    return 0;
}
