/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G16 -ffunction-sections -Wa,-G16 -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-por.
 * Reported final C / retail: 1460 / 1524 bytes; size equality is not a match.
 * us: 0/1 placements; 1460/1524 bytes.
 * us2: 0/1 placements; 1460/1524 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: Frame 0xB0 versus retail 0xC0; loop pointer lifetimes and stores differ. Four dust stack words retained.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Manual reconstruction, 2026-10-23: NOT MATCHED. US 1460/1524 bytes,
 * 0/1 placements; profile: -O2 -ffunction-sections G16 asG16 qcopy/qcopy-barrier/zero-ti-por.
 * Frame 0xB0 versus retail 0xC0; loop pointer lifetimes and stores differ. Four dust stack words retained.
 * Historical screening notes below are preserved; the current measured
 * residual replaces any earlier claim that lq/sq/por cannot be emitted. */
#include "common.h"
typedef int MissileQuadword __attribute__((mode(TI)));
extern u8 D_00188660[];
extern float D_00189EA0[4], D_L16_001B9B00[4];
extern int D_L16_001A8F00;
extern u8 *D_L16_001BFF58;
extern float D_L16_001B1648[3] __attribute__((sda));
extern float D_L16_001B1658[3] __attribute__((sda));
extern float D_L16_001B1664 __attribute__((sda));
extern int func_002E5CF8(int, int, void *);
extern void func_002E59F8(int), func_002A7470(void *, int, int, int);
extern void func_002AA548(float *, float *, float, float, float, float);
extern void func_00282CF0(void *, void *, void *), func_00282CC0(void *, void *, void *);
extern void func_00282D30(void *, void *, float), func_00282F20(void *, void *, float);
extern float func_00283248(float, float), func_002A78D8(float, float), func_002A7878(float, float);
extern void func_002AA800(float *, int, float, float), func_L16_0040DC70(u8 *);
extern void *func_002A9640(void *, int, int);
extern u8 *func_00273730(void *, int, int, int, void *, void *, void *, int, float, float);
extern void func_0032C700(void *, int, int, int, int, int, int, int, float, float, int, int, int, int);
extern void func_0029F338(void *), func_002A7750(void *, u8, int);
extern int func_002761F8(void *, void *, int, void *, void *);
extern int func_00277258(void *, int, void *, float);
extern void func_0032DA58(void *, void *, void *, float);
extern int func_002A8C28(void *, void *, int, int, float, float, float, int, int);

/* The sound handle indexes 0x70-byte resident records. The sound owner and
 * active byte are checked before stopping a handle that may have been reused. */
void func_L16_0040D4E8(u8 *moby)
{
    u8 *state = *(u8 **)(moby + 0x68);
    float oldPosition[4] __attribute__((aligned(16)));
    float delta[4] __attribute__((aligned(16)));
    float velocity[4] __attribute__((aligned(16)));
    int handle, i;
    if (moby[0x20] == 0) {
        handle = *(int *)(state + 0x68);
        if (*(u8 **)(D_00188660 + handle * 0x70 + 0x88) != moby ||
            !D_00188660[handle * 0x70 + 0x74])
            *(int *)(state + 0x68) = func_002E5CF8(0, 4, moby);
        *(MissileQuadword *)oldPosition = *(MissileQuadword *)(moby + 0x10);
        *(MissileQuadword *)(moby + 0x10) = *(MissileQuadword *)state;
        for (i = 0; i < 3; i++) {
            if (i == 0 || D_L16_001B1664 < *(float *)(state + 0x3c + i * 4)) {
                func_002AA548((float *)(state + 0x40 + i * 4),
                    (float *)(state + 0x50 + i * 4), 1.0f,
                    D_L16_001B1648[i] * 0.00027777778f,
                    D_L16_001B1648[i] * 0.00027777778f,
                    D_L16_001B1658[i] * 0.016666668f);
                if (i == 2 && *(float *)(state + 0x44) > 0.95f && moby[0x43])
                    func_002A7470(moby, 0, 0, 20);
            }
            func_00282CF0(delta, state + (i + 1) * 16, state + i * 16);
            func_00282D30(delta, delta, *(float *)(state + 0x40 + i * 4));
            func_00282CC0(moby + 0x10, moby + 0x10, delta);
        }
        func_002AA800((float *)(moby + 0xf8), 0,
            func_00283248(D_00189EA0[0] - *(float *)(moby + 0x10),
                D_00189EA0[1] - *(float *)(moby + 0x14)), 0.20943955f);
        func_L16_0040DC70(moby);
        if (func_002A9640(moby, 0x10000, 0) || D_L16_001A8F00 == 2) {
            func_002E5CF8(2, 0, moby);
            handle = *(int *)(state + 0x68);
            if (handle != -1 && *(u8 **)(D_00188660 + handle * 0x70 + 0x88) == moby &&
                D_00188660[handle * 0x70 + 0x74]) func_002E59F8(handle);
            *(int *)(state + 0x68) = -1;
            for (i = 0; i < 3; i++) {
                float lifetime, size;
                if (i == 0) func_00282D30(velocity, moby + 0xd0, 0.15f);
                else if (i == 1) func_00282D30(velocity, moby + 0xd0, -0.15f);
                else if (i == 2) func_00282D30(velocity, moby + 0xe0, 0.10000001f);
                lifetime = func_002A78D8(90.0f, 180.0f);
                size = func_002A7878(5.0f, 15.0f);
                func_00273730(moby, 1, *(short *)(moby + 0xaa), i,
                    moby + 0x10, moby + 0xf0, velocity, 255, lifetime, size);
            }
            func_0032C700(moby + 0x10, 0, 0, 0, 0, 20, 45, 1,
                1.0f, 20.0f, 1, 0, 0, 0);
            func_0029F338(moby);
        } else {
            if (*(float *)(state + 0x48) >= 1.0f) func_002A7750(moby, 1, -1);
            if (func_002761F8(oldPosition, moby + 0x10, 0, moby, 0)) {
                if (D_L16_001BFF58 &&
                    (*(short *)(D_L16_001BFF58 + 0xaa) == 0xf78 ||
                     *(short *)(D_L16_001BFF58 + 0xaa) == 0x7e8)) return;
            } else {
                if (*(float *)(state + 0x44) < 0.9f) return;
                if (!func_00277258(moby + 0x10, 0, moby, 1.5f)) return;
            }
            func_002A7750(moby, 1, -1);
        }
    } else if (moby[0x20] == 1) {
        handle = *(int *)(state + 0x68);
        if (handle != -1 && *(u8 **)(D_00188660 + handle * 0x70 + 0x88) == moby &&
            D_00188660[handle * 0x70 + 0x74]) func_002E59F8(handle);
        *(int *)(state + 0x68) = -1;
        func_002E5CF8(1, 0, moby);
        func_00282CF0(oldPosition, D_L16_001B9B00, moby + 0x10);
        func_00282F20(oldPosition, oldPosition, 1.0f);
        func_0032DA58(moby, moby + 0x10, oldPosition, 0.0f);
        func_002A8C28(moby, moby + 0x10, 0x10001, 0, 2.0f, 5.0f, 1.0f, 1, 0);
        func_0029F338(moby);
    }
}
