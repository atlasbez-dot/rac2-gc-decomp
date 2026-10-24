/* Nonmatching reconstruction checked 23 October 2026.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Final check.py coverage: us 0/27, us2 0/27; no candidate.
 * Manual beam-network reconstruction 2508/2532; repeated geometry blocks are explicit. Corrected the second phase step to retail 0x3ED37CC6 (0.4130613208f); rechecked both carrying releases.
 * Remaining: Owner/loop registers, transformed attachment/workspace lifetimes and repeated beam-call scheduling differ.
 * Reopen with a measured attachment/matrix layout and register-lifetime hypothesis.
 * Historical screening below is preserved, not treated as acceptance evidence.
 */

/* func_L00_003A1580 - 2532 bytes, 27 place(s), level 00_aranos_tutorial,
   retail at 0x003a1580. Screened with tools/w10_screen.py: 79 call(s)
   [func_002FC560@003A15CC, func_L00_003A2138@003A15E4,
   func_002A3F10@003A15FC, func_00283198@003A161C, func_00283180@003A1654,
   func_00283180@003A1670, func_00283B98@003A169C, func_00283B98@003A16B4,
   func_002830C0@003A1724, func_L00_003A2BB8@003A1744,
   func_L00_003A25D8@003A1768, func_L00_003A25D8@003A178C,
   func_L00_003A2BB8@003A17A0, func_002AA458@003A1814,
   func_L00_003A25D8@003A1868, func_L00_003A25D8@003A18A4,
   func_L00_003A2BB8@003A18B8, func_L00_003A25D8@003A18D4,
   func_L00_003A25D8@003A18F0, func_L00_003A2BB8@003A1904,
   func_L00_003A25D8@003A1920, func_L00_003A25D8@003A193C,
   func_L00_003A2BB8@003A1950, func_L00_003A25D8@003A196C,
   func_L00_003A25D8@003A1988, func_L00_003A2258@003A19A0,
   func_L00_003A2408@003A19CC, func_00282CF0@003A19E0,
   func_00282F20@003A19F0, func_00282DD8@003A1A00, func_00282F20@003A1A10,
   func_00282DD8@003A1A20, func_00282F20@003A1A44, func_00282CC0@003A1A58,
   func_L00_003A2258@003A1A6C, func_L00_003A25D8@003A1A88,
   func_L00_003A25D8@003A1AA4, 0x1163b0@003A1AAC,
   func_L00_003A2C60@003A1AF0, func_00282CF0@003A1B0C,
   func_00282F20@003A1B1C, func_00282DD8@003A1B2C, func_00282F20@003A1B3C,
   func_00282DD8@003A1B4C, func_00282F20@003A1B70, func_00282CC0@003A1B84,
   func_L00_003A2258@003A1B9C, func_L00_003A25D8@003A1BC0,
   func_L00_003A25D8@003A1BE4, 0x1163b0@003A1BEC,
   func_L00_003A2C60@003A1C34, func_00282CF0@003A1C50,
   func_00282F20@003A1C60, func_00282DD8@003A1C70, func_00282F20@003A1C80,
   func_00282DD8@003A1C90, func_00282F20@003A1CB4, func_00282CC0@003A1CC8,
   func_L00_003A2258@003A1CE0, func_L00_003A25D8@003A1D04,
   func_L00_003A25D8@003A1D28, 0x1163b0@003A1D30,
   func_L00_003A2C60@003A1D74, func_0029FCC0@003A1D98,
   func_L00_003A2258@003A1DB8, func_L00_003A25D8@003A1DD4,
   func_L00_003A25D8@003A1DF0, func_0029FCC0@003A1E00,
   func_L00_003A2258@003A1E14, func_L00_003A25D8@003A1E30,
   func_L00_003A25D8@003A1E4C, func_0029FCC0@003A1E5C,
   func_L00_003A2258@003A1E70, func_L00_003A25D8@003A1E8C,
   func_L00_003A25D8@003A1EA8, 0x1163b0@003A1EB0, 0x1163b0@003A1ED4,
   func_L00_003A2C60@003A1F10, func_002FC560@003A1F20]; data addresses
   materialised [0x50000, 0x240000, 0x3c750000, 0x290000, 0x3ecc0000,
   0x3c740000, 0x3c770000, 0x3ed60000, 0x3ed30000, 0x3de10000, 0x7f7f0000,
   0x3d4c0000, 0x7fff0000, 0x1b0000, 0x1b0000, 0x1b0000, 0x3e4c0000,
   0x7f000000, 0x3e3e0000, 0x1b0000, 0x240000, 0x3d610000, 0x3ccc0000,
   0x7f000000, 0x3dac0000, 0x1b0000, 0x7f7f0000, 0x7fff0000, 0x7f7f0000,
   0x7fff0000, 0x7f7f0000, 0x7fff0000, 0x1b0000, 0x3eb30000, 0x1b0000,
   0x1b0000, 0x3ee60000, 0x1b0000, 0x7f7f0000, 0x7fff0000, 0x1b0000,
   0x3ee60000, 0x1b0000, 0x240000, 0x3d610000, 0x7f7f0000, 0x3ccc0000,
   0x7fff0000, 0x1b0000, 0x3ee60000, 0x1b0000, 0x240000, 0x3d610000,
   0x7f7f0000, 0x3ccc0000, 0x7fff0000, 0x240000, 0x240000, 0x3d610000,
   0x3ccc0000, 0x7f7f0000, 0x7fff0000, 0x7f7f0000, 0x7fff0000, 0x7f7f0000,
   0x7fff0000, 0x3a830000, 0x50000]; float constants [0x3f800000,
   0xbf800000, 0x3e800000, 0x1b0000, 0x3f000000, 0x3f800000, 0x3f800000,
   0x3f800000]; $gp-relative small data: no   saves: -; callee-saved
   registers saved [-]; words plain C cannot emit [LQ/SQ 7AA20000@0x0254,
   LQ/SQ 7C620000@0x0258]. Head: addiu $sp, $sp, -0x1C0 ; lui $a1, 0x5 ; ori
   $a1, $a1, 0x3001 ; sd $s2, 0x160($sp) ; daddu $s2, $a0, $zero ; sd $s0,
   0x150($sp). Not matched in this wave: the 128-bit copy needs an `lq`/`sq`
   pair; plain C reaches it only through a `mode(TI)` local, and this cc1
   folds the destination offset into the `sq` where retail materialises the
   pointer first. What would unblock it: the exact source expression tree,
   so this cc1 picks the same registers in the same order. */

#include "common.h"
typedef int VectorBits __attribute__((mode(TI)));
extern float D_L00_0023B510[4][32];
extern float D_L00_002947B0[5][4];
extern float D_L00_001B2850[4];
extern float D_L00_001AF5F0 __attribute__((sda));
extern float D_L00_001AF5F4 __attribute__((sda));
extern float D_L00_001AF5D8 __attribute__((sda));
extern void func_002FC560(unsigned int, unsigned long long);
extern void func_L00_003A2138(int, float *, int);
extern void func_002A3F10(void *, int, int *, void *);
extern float func_00283198(float), func_00283180(float), func_00283B98(float, float);
extern void func_002830C0(void *, void *, void *);
extern void func_L00_003A2BB8(char *, int, char *, char *);
extern void func_L00_003A25D8(int, int, int, int, float);
extern float func_002AA458(void *, void *, void *, float, float, float);
extern void func_L00_003A2258(void *, void *, void *, void *);
extern void func_L00_003A2408(char *, void *, void *, float);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282DD8(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern int func_001163B0(void);
extern void func_L00_003A2C60(void *, int, float);
extern void func_0029FCC0(char *, int, char *);

/* Transform the weapon's animated attachment points and draw its beam network. */
void func_L00_003A1580(void *object)
{
    float center[4], samples[4][4], attachments[5][4], matrix[4][4];
    float normal[4], side[4], endpoint[4], muzzle[4];
    char *moby = object;
    char *state;
    int lookup = 0, i;
    func_002FC560(0x47, 0x53001ULL);
    state = *(char **)(moby + 0x68);
    func_L00_003A2138((int)moby, D_L00_0023B510[0], 4);
    func_002A3F10(moby, 1, &lookup, matrix);
    *(VectorBits *)matrix[3] = 0;
    matrix[3][3] = 1.0f;
    D_L00_002947B0[1][0] = func_00283198(D_L00_001AF5F0) * 0.015f + 0.4f;
    D_L00_002947B0[1][2] = func_00283180(D_L00_001AF5F0) * 0.0149f;
    D_L00_002947B0[1][1] = -func_00283180(D_L00_001AF5F4) * 0.0151f;
    D_L00_001AF5F0 = func_00283B98(D_L00_001AF5F0, 0.4188790917f);
    D_L00_001AF5F4 = func_00283B98(D_L00_001AF5F4, 0.4130613208f);
    for (i = 0; i < 5; i++)
        func_002830C0(attachments[i], D_L00_002947B0[i], matrix);
    func_L00_003A2BB8(moby, 0, (char *)center, (char *)attachments[0]);
    func_L00_003A25D8((int)moby, (int)center, 0x7F7F2020, 0x40, 0.11f);
    func_L00_003A25D8((int)moby, (int)center, 0x7FFF4040, 0x78, 0.05f);
    func_L00_003A2BB8(moby, 0, (char *)samples[0], (char *)attachments[1]);
    if (D_L00_001B2850[3] == -1.0f) {
        D_L00_001B2850[0] = samples[0][0];
        D_L00_001B2850[1] = samples[0][1];
        D_L00_001B2850[2] = samples[0][2];
        D_L00_001B2850[3] = 0.0f;
    } else {
        int changed = 0;
        func_002AA458(D_L00_001B2850, samples[0], &changed, 0.25f, 0.2000000179f, 0.5f);
    }
    func_L00_003A25D8((int)moby, (int)D_L00_001B2850, 0x7F00397F, 0x40, *(float *)(state + 0xC) * 0.1856249869f);
    func_L00_003A25D8((int)moby, (int)D_L00_001B2850, 0x7F0072FF, 0x78, *(float *)(state + 0xC) * 0.08437500149f);
    func_L00_003A2BB8(moby, 1, (char *)samples[1], (char *)attachments[2]);
    func_L00_003A25D8((int)moby, (int)samples[1], 0x7F7F2020, 0x40, 0.055f);
    func_L00_003A25D8((int)moby, (int)samples[1], 0x7FFF4040, 0x78, 0.025f);
    func_L00_003A2BB8(moby, 2, (char *)samples[2], (char *)attachments[3]);
    func_L00_003A25D8((int)moby, (int)samples[2], 0x7F7F2020, 0x40, 0.055f);
    func_L00_003A25D8((int)moby, (int)samples[2], 0x7FFF4040, 0x78, 0.025f);
    func_L00_003A2BB8(moby, 3, (char *)samples[3], (char *)attachments[4]);
    func_L00_003A25D8((int)moby, (int)samples[3], 0x7F7F2020, 0x40, 0.055f);
    func_L00_003A25D8((int)moby, (int)samples[3], 0x7FFF4040, 0x78, 0.025f);
    func_L00_003A2258(moby, center, D_L00_001B2850, D_L00_0023B510[0]);
    func_L00_003A2408(moby, D_L00_001B2850, normal, *(float *)(state + 0xC) * 0.35f);
    func_00282CF0(side, D_L00_001B2850, samples[1]);
    func_00282F20(side, side, 1.0f);
    func_00282DD8(side, side, normal);
    func_00282F20(side, side, 1.0f);
    func_00282DD8(side, side, normal);
    func_00282F20(side, side, *(float *)(state + 0xC) * 0.45f);
    func_00282CC0(endpoint, side, D_L00_001B2850);
    func_L00_003A2258(moby, samples[1], endpoint, D_L00_0023B510[1]);
    func_L00_003A25D8((int)moby, (int)endpoint, 0x7F7F2020, 0x40, 0.055f);
    func_L00_003A25D8((int)moby, (int)endpoint, 0x7FFF4040, 0x78, 0.025f);
    if (func_001163B0() % 11 == 0 && *(float *)(state + 0xC) > D_L00_001AF5D8)
        func_L00_003A2C60(endpoint, 1, 0.0f);
    func_00282CF0(side, D_L00_001B2850, samples[2]);
    func_00282F20(side, side, 1.0f);
    func_00282DD8(side, side, normal);
    func_00282F20(side, side, 1.0f);
    func_00282DD8(side, side, normal);
    func_00282F20(side, side, *(float *)(state + 0xC) * 0.45f);
    func_00282CC0(endpoint, side, D_L00_001B2850);
    func_L00_003A2258(moby, samples[2], endpoint, D_L00_0023B510[2]);
    func_L00_003A25D8((int)moby, (int)endpoint, 0x7F7F2020, 0x40, 0.055f);
    func_L00_003A25D8((int)moby, (int)endpoint, 0x7FFF4040, 0x78, 0.025f);
    if (func_001163B0() % 11 == 0 && *(float *)(state + 0xC) > D_L00_001AF5D8)
        func_L00_003A2C60(endpoint, 1, 0.0f);
    func_00282CF0(side, D_L00_001B2850, samples[3]);
    func_00282F20(side, side, 1.0f);
    func_00282DD8(side, side, normal);
    func_00282F20(side, side, 1.0f);
    func_00282DD8(side, side, normal);
    func_00282F20(side, side, *(float *)(state + 0xC) * 0.45f);
    func_00282CC0(endpoint, side, D_L00_001B2850);
    func_L00_003A2258(moby, samples[3], endpoint, D_L00_0023B510[3]);
    func_L00_003A25D8((int)moby, (int)endpoint, 0x7F7F2020, 0x40, 0.055f);
    func_L00_003A25D8((int)moby, (int)endpoint, 0x7FFF4040, 0x78, 0.025f);
    if (func_001163B0() % 11 == 0 && *(float *)(state + 0xC) > D_L00_001AF5D8)
        func_L00_003A2C60(endpoint, 1, 0.0f);
    func_0029FCC0(moby, 1, (char *)muzzle);
    func_L00_003A2258(moby, muzzle, samples[1], D_L00_0023B510[3]);
    func_L00_003A25D8((int)moby, (int)muzzle, 0x7F7F2020, 0x40, 0.055f);
    func_L00_003A25D8((int)moby, (int)muzzle, 0x7FFF4040, 0x78, 0.025f);
    func_0029FCC0(moby, 2, (char *)muzzle);
    func_L00_003A2258(moby, muzzle, samples[2], D_L00_0023B510[2]);
    func_L00_003A25D8((int)moby, (int)muzzle, 0x7F7F2020, 0x40, 0.055f);
    func_L00_003A25D8((int)moby, (int)muzzle, 0x7FFF4040, 0x78, 0.025f);
    func_0029FCC0(moby, 3, (char *)muzzle);
    func_L00_003A2258(moby, muzzle, samples[3], D_L00_0023B510[1]);
    func_L00_003A25D8((int)moby, (int)muzzle, 0x7F7F2020, 0x40, 0.055f);
    func_L00_003A25D8((int)moby, (int)muzzle, 0x7FFF4040, 0x78, 0.025f);
    if (func_001163B0() % 11 == 0) {
        int selected = func_001163B0() % 4;
        func_L00_003A2C60(samples[selected], 1, 0.001f);
    }
    func_002FC560(0x47, 0x5360BULL);
}
