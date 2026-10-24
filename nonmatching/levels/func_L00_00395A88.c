/* Nonmatching: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier. us: func_L00_00395A88: 0 of 27 places match (src/levels/shared/L00_00395A88.c); us2: func_L00_00395A88: 0 of 27 places match (src/levels/shared/L00_00395A88.c); pal: func_L00_00395A88: 0 of 27 places match (src/levels/shared/L00_00395A88.c). Three manual trials; final1516/1516 but frame0x250 versus0x260, saved-register/loop scheduling differences. Real144-byte packets, aligned16-byte vectors, u64 texture return/state and all3float arguments retained. Reopen on original loop/local lifetime evidence. */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef union { Quad quad; float f[4]; } Vector;
typedef struct { Vector vertex[4]; u32 color[4]; float uv[8]; u64 primitive, texture, mode, flags; } RibbonPacket;
extern char D_L00_001B8DC0[];
extern u64 func_0027C878(int);
extern void func_00280B90(void *, void *, int), func_002FC560(int, u64);
extern void func_00282CC0(void *, void *, void *), func_00282CF0(void *, void *, void *);
extern void func_00282DD8(void *, void *, void *), func_00282D30(void *, void *, float);
extern float func_00282DF0(void *);
extern int D_L00_001AF280 __attribute__((sda)), D_L00_001AF284 __attribute__((sda));
extern u32 D_L00_001AF250 __attribute__((sda)), D_L00_001AF254 __attribute__((sda));
/* Draws the narrow ribbon and its camera-facing halo along the point chain. */
void func_L00_00395A88(Vector *points, u32 alpha, u32 outerAlpha, int count, float coreWidth, float width, float extend) {
    RibbonPacket core, halo;
    Vector normal, widthVector, eye, tangent, first, last, firstRay, lastRay, toEye, extension;
    Vector *current, *next;
    float length, firstLength, lastLength;
    int i, segments;
    u32 coreColor, haloColor;
    core.texture = func_0027C878(D_L00_001AF280);
    coreColor = D_L00_001AF250 | (alpha << 24);
    core.flags = 0x8000000048ULL;
    core.mode = 0xFF9000000260ULL;
    core.primitive = 0;
    core.color[0] = coreColor; core.color[1] = coreColor;
    core.color[2] = coreColor; core.color[3] = coreColor;
    halo.texture = func_0027C878(D_L00_001AF284);
    halo.flags = core.flags; halo.mode = core.mode; halo.primitive = core.primitive;
    haloColor = D_L00_001AF254 | (outerAlpha << 24);
    halo.color[0] = haloColor; halo.color[1] = haloColor;
    halo.color[2] = haloColor; halo.color[3] = haloColor;
    halo.uv[0] = 0; halo.uv[1] = 0; halo.uv[2] = 0; halo.uv[3] = 1;
    halo.uv[4] = 1; halo.uv[5] = 0; halo.uv[6] = 1; halo.uv[7] = 1;
    core.uv[0] = 0; core.uv[1] = 0; core.uv[2] = 0; core.uv[3] = 1;
    core.uv[4] = 1; core.uv[5] = 0; core.uv[6] = 1; core.uv[7] = 1;
    current = points + 1;
    func_00282CF0(&eye, points, D_L00_001B8DC0);
    func_00282CF0(&tangent, current, points);
    func_00282DD8(&normal, &tangent, &eye);
    length = func_00282DF0(&normal);
    if (length != 0) length = 1.0f / length;
    func_00282D30(&normal, &normal, coreWidth * length);
    func_00282CC0(&core.vertex[0], points, &normal);
    func_00282CF0(&core.vertex[1], points, &normal);
    segments = count - 1;
    for (i = 1, next = points + 2; i < segments; i++, current++, next++) {
        func_00282CF0(&eye, current, D_L00_001B8DC0);
        func_00282CF0(&tangent, next, current);
        func_00282DD8(&normal, &tangent, &eye);
        length = func_00282DF0(&normal);
        if (length != 0) length = 1.0f / length;
        func_00282D30(&normal, &normal, coreWidth * length);
        func_00282CC0(&core.vertex[2], current, &normal);
        func_00282CF0(&core.vertex[3], current, &normal);
        if (i == 1) { core.color[0] = D_L00_001AF250; core.color[1] = D_L00_001AF250; }
        else if (i == count - 2) { core.color[2] = D_L00_001AF250; core.color[3] = D_L00_001AF250; }
        else if (i == 2) { core.color[0] = coreColor; core.color[1] = coreColor; }
        func_00280B90(&core, 0, 0);
        core.vertex[0].quad = core.vertex[2].quad; core.vertex[1].quad = core.vertex[3].quad;
    }
    for (i = 0, current = points; i < segments; i++, current++) {
        points++;
        func_00282CF0(&firstRay, current, D_L00_001B8DC0);
        func_00282CF0(&lastRay, points, D_L00_001B8DC0);
        firstLength = func_00282DF0(&firstRay);
        lastLength = func_00282DF0(&lastRay);
        if (lastLength < firstLength) {
            if (lastLength == 0) { lastRay.f[2] = firstRay.f[2]; lastRay.f[3] = firstRay.f[3]; }
            else func_00282D30(&lastRay, &lastRay, firstLength / lastLength);
        } else if (firstLength == 0) { firstRay.f[2] = lastRay.f[2]; firstRay.f[3] = lastRay.f[3]; }
        else func_00282D30(&firstRay, &firstRay, lastLength / firstLength);
        func_00282CC0(&first, D_L00_001B8DC0, &firstRay);
        func_00282CC0(&last, D_L00_001B8DC0, &lastRay);
        func_00282CF0(&tangent, &last, &first);
        func_00282D30(&extension, &tangent, extend);
        func_00282CF0(&first, &first, &extension);
        func_00282CC0(&last, &last, &extension);
        func_00282CF0(&toEye, D_L00_001B8DC0, &first);
        func_00282DD8(&normal, &toEye, &tangent);
        length = func_00282DF0(&normal);
        if (length != 0) length = 1.0f / length;
        func_00282D30(&widthVector, &normal, width * length);
        func_00282CC0(&halo.vertex[0], &first, &widthVector);
        func_00282CF0(&halo.vertex[1], &first, &widthVector);
        func_00282CC0(&halo.vertex[2], &last, &widthVector);
        func_00282CF0(&halo.vertex[3], &last, &widthVector);
        if (i == 0) { halo.color[0] = D_L00_001AF254; halo.color[1] = D_L00_001AF254; }
        else if (i == count - 2) { halo.color[2] = D_L00_001AF254; halo.color[3] = D_L00_001AF254; }
        else if (i == 1) { halo.color[0] = haloColor; halo.color[1] = haloColor; }
        func_00280B90(&halo, 0, 0);
    }
    func_002FC560(0x47, 0x5360B);
}

/* Historical screening only; superseded by the measured reconstruction above. */
/* func_L00_00395A88 - 1516 bytes, 27 place(s), level 00_aranos_tutorial,
   retail at 0x00395a88. Screened with tools/w10_screen.py: 39 call(s)
   [func_0027C878@00395AEC, func_0027C878@00395B3C, func_00282CF0@00395BD8,
   func_00282CF0@00395BEC, func_00282DD8@00395C00, func_00282DF0@00395C0C,
   func_00282D30@00395C3C, func_00282CC0@00395C4C, func_00282CF0@00395C5C,
   func_00282CF0@00395C94, func_00282CF0@00395CA4, func_00282DD8@00395CB4,
   func_00282DF0@00395CBC, func_00282D30@00395CF0, func_00282CC0@00395D00,
   func_00282CF0@00395D10, func_00280B90@00395D70, func_00282CF0@00395DF8,
   func_00282CF0@00395E08, func_00282DF0@00395E10, func_00282DF0@00395E1C,
   func_00282D30@00395E60, func_00282D30@00395E9C, func_00282CC0@00395EB0,
   func_00282CC0@00395EC4, func_00282CF0@00395ED4, func_00282D30@00395EE4,
   func_00282CF0@00395EF4, func_00282CC0@00395F04, func_00282CF0@00395F14,
   func_00282DD8@00395F24, func_00282DF0@00395F2C, func_00282D30@00395F60,
   func_00282CC0@00395F70, func_00282CF0@00395F80, func_00282CC0@00395F90,
   func_00282CF0@00395FA0, func_00280B90@00395FF8, func_002FC560@00396028];
   data addresses materialised [0x1c0000, 0x1c0000, 0x1c0000, 0x50000];
   float constants [0x3f800000, 0x3f800000, 0x3f800000]; $gp-relative small
   data: no   saves: -; callee-saved registers saved [-]; words plain C
   cannot emit [LQ/SQ 7A420000@0x02f0, LQ/SQ 7FA20000@0x02f4, LQ/SQ
   7A620000@0x02fc, LQ/SQ 7C620000@0x0300, LQ/SQ 7A620000@0x03bc, LQ/SQ
   7E220000@0x03c0, LQ/SQ 7A220000@0x03f8, LQ/SQ 7E620000@0x03fc]. Head:
   addiu $sp, $sp, -0x260 ; sd $s6, 0x210($sp) ; daddu $s6, $a0, $zero ; sd
   $s0, 0x1E0($sp) ; sd $s1, 0x1E8($sp) ; daddu $s0, $a1, $zero. Not matched
   in this wave: the 128-bit copy needs an `lq`/`sq` pair; plain C reaches
   it only through a `mode(TI)` local, and this cc1 folds the destination
   offset into the `sq` where retail materialises the pointer first. What
   would unblock it: the exact source expression tree, so this cc1 picks the
   same registers in the same order. */
