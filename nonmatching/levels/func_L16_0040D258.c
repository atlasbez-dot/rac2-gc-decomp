/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-por.
 * Reported final C / retail: 668 / 656 bytes; size equality is not a match.
 * us: 0/1 placements; 668/656 bytes.
 * us2: 0/1 placements; 668/656 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: Loop register allocation and instruction scheduling; all eight spark GPR inputs retained.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Manual reconstruction, 2026-10-23: NOT MATCHED. US 668/656 bytes,
 * 0/1 placements; profile: -O2 -ffunction-sections G8 qcopy/qcopy-barrier/zero-ti-por.
 * Loop register allocation and instruction scheduling; all eight spark GPR inputs retained.
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

void func_L16_0040D258(u8 *moby)
{
    float position[4] __attribute__((aligned(16)));
    float velocity[4] __attribute__((aligned(16)));
    float clear[4] __attribute__((aligned(16)));
    int bone, lifetime, size;
    for (bone = 5; bone < 8; bone++) {
        *(BossQuadword *)clear = 0;
        clear[2] = -(func_002A7878(4.5f, 5.5f) * 0.016666668f);
        *(BossQuadword *)velocity = *(BossQuadword *)clear;
        func_0029FCC0((char *)moby, bone, (char *)position);
        if (D_L16_001B2648 & 1) {
            size = func_002A7820(18, 22);
            func_002BAE50(position, velocity, 0xcf0000ff, 0xcf, size, 180, -10, 1);
        } else {
            size = func_002A7820(20, 24);
            func_002BAE50(position, velocity, 0x6000ffff, 0x80, size, 350, -10, 1);
        }
        lifetime = func_002A7820(20, 90);
        size = func_002A7820(10, 15);
        func_002BAE50(position, velocity, 0xefff7f4f, 0xff0000, size, lifetime, -lifetime, 1);
    }
    for (bone = 3; bone < 5; bone++) {
        func_00282F20(velocity, moby + 0xc0, -(func_002A7878(4.5f, 5.5f) * 0.016666668f));
        func_0029FCC0((char *)moby, bone, (char *)position);
        if (D_L16_001B2648 & 1) {
            size = func_002A7820(18, 22);
            func_002BAE50(position, velocity, 0xcf0000ff, 0xcf, size, 50, -10, 1);
        } else {
            size = func_002A7820(20, 24);
            func_002BAE50(position, velocity, 0x6000ffff, 0x80, size, 100, -10, 1);
        }
        lifetime = func_002A7820(10, 25);
        size = func_002A7820(10, 15);
        func_002BAE50(position, velocity, 0xefff7f4f, 0xff0000, size, lifetime, -lifetime, 1);
    }
}
