/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-por.
 * Reported final C / retail: 676 / 664 bytes; size equality is not a match.
 * us: 0/1 placements; 676/664 bytes.
 * us2: 0/1 placements; 676/664 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: An extra saved GPR and cached state pointer; two scoped forms tied.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Manual reconstruction, 2026-10-23: NOT MATCHED. US 676/664 bytes,
 * 0/1 placements; profile: -O2 -ffunction-sections G8 qcopy/qcopy-barrier/zero-ti-por.
 * An extra saved GPR and cached state pointer; two scoped forms tied.
 * Historical screening notes below are preserved; the current measured
 * residual replaces any earlier claim that lq/sq/por cannot be emitted. */
#include "common.h"
typedef int BossQuadword __attribute__((mode(TI)));
extern unsigned int D_L16_001B2648;
extern u8 *D_L16_001FE7C0[];
extern u8 *D_L16_001B2C0C;
extern float D_L16_001B9B00[4];
extern float D_L16_001B1750 __attribute__((sda));
extern float D_L16_001B18CC __attribute__((sda));
extern float D_L16_001B18D0 __attribute__((sda));
extern float D_L16_001B18D4 __attribute__((sda));
extern float func_002A7878(float, float);
extern int func_002A7820(int, int), func_002A77E0(int);
extern void func_0029FCC0(char *, int, char *);
extern void func_002BAE50(void *, void *, int, int, int, int, int, int);
extern void func_00282F20(void *, void *, float);
extern void func_00282D30(void *, void *, float);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern float func_00282DF0(void *);
extern void func_002AAC80(float *, float, float, float, float);
extern float func_00283248(float, float);
extern void func_002AAA00(float *, float *, int, float, float, float, float);
extern int func_002A8D70(float, float, float, void *, void *, int, int, int, int);
extern void func_L16_00410FA8(u8 *);
extern u8 *func_0029EFD0(int);
extern void func_002B37E8(u8 *, u8 *);
extern void func_002A7750(u8 *, u8, int);
extern void func_00282C90(void *);
extern int func_00283DB8(void *, float);
extern void func_002830C0(void *, void *, void *);
extern float func_00283B98(float, float), func_00283180(float), func_00283198(float);
extern int func_00283CF0(float);
extern void func_0029F338(void *), func_002A0F48(void *);
extern void func_L16_004133B0(u8 *);

void func_L16_004110D0(u8 *moby, float dt)
{
    float point[4] __attribute__((aligned(16)));
    float delta[4] __attribute__((aligned(16)));
    float step[4] __attribute__((aligned(16)));
    u8 *state = *(u8 **)(moby + 0x68);
    u8 *path = D_L16_001FE7C0[*(int *)(state + 0x170)];
    int finalPoint = 1;
    float distance;
    *(float *)(moby + 0x48) = *(float *)(state + 0x230) * 3.0f;
    *(float *)(*(u8 **)(state + 0x1f0) + 0x48) = *(float *)(moby + 0x48);
    if (*(int *)(state + 0x220) == *(int *)(state + 0x1f4) && *(int *)(state + 0x224) == *(int *)(state + 0x1f8)) {
        *(BossQuadword *)point = *(BossQuadword *)(state + 0x200);
    } else {
        int previous = *(int *)(state + 0x22c);
        if (previous == *(int *)(state + 0x220) || previous == *(int *)(state + 0x224) ||
            *(int *)(state + 0x228) != *(int *)(state + 0x220) || *(int *)(state + 0x228) != *(int *)(state + 0x224)) func_L16_00410FA8(moby);
        *(BossQuadword *)point = *(BossQuadword *)(path + *(int *)(state + 0x228) * 16 + 16);
        finalPoint = 0;
    }
    func_00282CF0(delta, point, moby + 0x10);
    delta[2] = 0.0f;
    distance = func_00282DF0(delta);
    func_002AAC80((float *)(state + 0x230), distance, D_L16_001B1750 * 0.00027777778f, D_L16_001B1750 * 0.00027777778f, dt);
    func_002AAA00((float *)(moby + 0xf8), (float *)(state + 0x234), 0, func_00283248(delta[0], delta[1]), 0.00174532947f, 0.00174532947f, 0.104719773f);
    func_00282F20(step, delta, *(float *)(state + 0x230));
    func_00282CC0(moby + 0x10, moby + 0x10, step);
    if (!*(int *)(state + 0x26c)) {
        func_002A8D70(6.0f, 50.0f, 1.0f, moby, 0, 0x90000, 0, 1, 0);
        func_002A8D70(6.0f, 50.0f, 1.0f, moby, (void *)1, 0x90000, 0, 1, 0);
    }
    if (!finalPoint && distance < 0.5f) {
        int current = *(int *)(state + 0x228);
        int previous = *(int *)(state + 0x22c);
        if (previous < current) { *(int *)(state + 0x224) = current; *(int *)(state + 0x220) = previous; }
        else { *(int *)(state + 0x224) = previous; *(int *)(state + 0x220) = current; }
    }
}
