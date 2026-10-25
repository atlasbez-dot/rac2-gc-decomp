/* RAC1-helper follow-up, 2026-10-25: NOT MATCHING; no exact-C credit.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * Fresh local measurement: 1480/1488 bytes, 0/27 US placements, frame 0x250.
 * Change: The two zero-length ray branches now copy all 16 bytes, matching retail LQ/SQ; the previous draft copied only components 2/3. Core vertex transfers also use approved qcopy.
 * Residual: Real split loop indices and no-force-mem tied; pointer-at-use measured 1476. Saved input/loop register allocation and scheduling still differ.
 * Reopen: Obtain measured loop live-range evidence that reproduces the saved points/index allocation; preserve the complete ray copies and F13/F14 inputs.
 * Earlier measurements/screens below are historical; they do not prohibit
 * the currently approved shared transfer helpers or establish linked equality.
 */
/* Nonmatching: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier. us: func_L00_003973E8: 0 of 27 places match (src/levels/shared/L00_003973E8.c); us2: func_L00_003973E8: 0 of 27 places match (src/levels/shared/L00_003973E8.c); pal: func_L00_003973E8: 0 of 27 places match (src/levels/shared/L00_003973E8.c). Three manual trials; best1488/1488 frame0x250, first mismatch+4 saved registers. Real144-byte packets, aligned16-byte vectors andu64 texture return/state preserved. Retail usesF13 width/F14 extension, F12 unused. Reopen on loop lifetime/register allocation evidence. */
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
extern float D_L00_001AF33C __attribute__((sda)), D_L00_001AF358 __attribute__((sda));
extern int D_L00_001AF394 __attribute__((sda)), D_L00_001AF398 __attribute__((sda));
extern u32 D_L00_001AF344 __attribute__((sda)), D_L00_001AF348 __attribute__((sda));
/* Draws the narrow ribbon and its camera-facing halo along the point chain. */
void func_L00_003973E8(Vector *points, u32 color, u32 outerColor, int count, float unused, float width, float extend) {
    RibbonPacket core, halo;
    Vector normal, widthVector, eye, tangent, first, last, firstRay, lastRay, toEye, extension;
    Vector *current, *next;
    float length, firstLength, lastLength;
    int i, segments;
    u32 coreColor, haloColor;
    core.texture = func_0027C878(D_L00_001AF394);
    coreColor = color;
    core.flags = 0x8000000048ULL;
    core.mode = 0xFF9000000260ULL;
    core.primitive = 0;
    core.color[0] = coreColor; core.color[1] = coreColor;
    core.color[2] = coreColor; core.color[3] = coreColor;
    halo.texture = func_0027C878(D_L00_001AF398);
    halo.flags = core.flags; halo.mode = core.mode; halo.primitive = core.primitive;
    haloColor = outerColor;
    halo.color[0] = haloColor; halo.color[1] = haloColor;
    halo.color[2] = haloColor; halo.color[3] = haloColor;
    halo.uv[0] = 0; halo.uv[1] = 0; halo.uv[2] = 0; halo.uv[3] = 1;
    halo.uv[4] = 1; halo.uv[5] = 0; halo.uv[6] = 1; halo.uv[7] = 1;
    core.uv[0] = D_L00_001AF33C; core.uv[1] = 0; core.uv[2] = D_L00_001AF33C; core.uv[3] = 1;
    core.uv[4] = D_L00_001AF33C + 1.0f; core.uv[5] = 0; core.uv[6] = D_L00_001AF33C + 1.0f; core.uv[7] = 1;
    current = points + 1;
    func_00282CF0(&eye, points, D_L00_001B8DC0);
    func_00282CF0(&tangent, current, points);
    func_00282DD8(&normal, &tangent, &eye);
    length = func_00282DF0(&normal);
    if (length != 0) length = 1.0f / length;
    func_00282D30(&normal, &normal, D_L00_001AF358 * length);
    func_00282CC0(&core.vertex[0], points, &normal);
    func_00282CF0(&core.vertex[1], points, &normal);
    segments = count - 1;
    for (i = 1, next = points + 2; i < segments; i++, current++, next++) {
        func_00282CF0(&eye, current, D_L00_001B8DC0);
        func_00282CF0(&tangent, next, current);
        func_00282DD8(&normal, &tangent, &eye);
        length = func_00282DF0(&normal);
        if (length != 0) length = 1.0f / length;
        func_00282D30(&normal, &normal, D_L00_001AF358 * length);
        func_00282CC0(&core.vertex[2], current, &normal);
        func_00282CF0(&core.vertex[3], current, &normal);
        if (i == 1) { core.color[0] = D_L00_001AF344; core.color[1] = D_L00_001AF344; }
        else if (i == count - 2) { core.color[2] = D_L00_001AF344; core.color[3] = D_L00_001AF344; }
        else if (i == 2) { core.color[0] = coreColor; core.color[1] = coreColor; }
        func_00280B90(&core, 0, 0);
        qcopy(&core.vertex[0], &core.vertex[2]); qcopy(&core.vertex[1], &core.vertex[3]);
    }
    for (i = 0, current = points; i < segments; i++, current++) {
        func_00282CF0(&firstRay, current, D_L00_001B8DC0);
        func_00282CF0(&lastRay, current + 1, D_L00_001B8DC0);
        firstLength = func_00282DF0(&firstRay);
        lastLength = func_00282DF0(&lastRay);
        if (lastLength < firstLength) {
            if (lastLength == 0) { qcopy(&lastRay, &firstRay); }
            else func_00282D30(&lastRay, &lastRay, firstLength / lastLength);
        } else if (firstLength == 0) { qcopy(&firstRay, &lastRay); }
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
        if (i == 0) { halo.color[0] = D_L00_001AF348; halo.color[1] = D_L00_001AF348; }
        else if (i == count - 2) { halo.color[2] = D_L00_001AF348; halo.color[3] = D_L00_001AF348; }
        else if (i == 1) { halo.color[0] = haloColor; halo.color[1] = haloColor; }
        func_00280B90(&halo, 0, 0);
    }
    func_002FC560(0x47, 0x5360B);
}

/* Historical screening only; superseded by the measured reconstruction above. */
/* func_L00_003973E8 - 1488 bytes, 27 place(s), level 00_aranos_tutorial,
   retail at 0x003973e8. Screened with tools/w10_screen.py: 39 call(s)
   [func_0027C878@00397444, func_0027C878@0039748C, func_00282CF0@00397518,
   func_00282CF0@0039752C, func_00282DD8@00397540, func_00282DF0@0039754C,
   func_00282D30@00397584, func_00282CC0@00397594, func_00282CF0@003975A4,
   func_00282CF0@003975DC, func_00282CF0@003975EC, func_00282DD8@003975FC,
   func_00282DF0@00397604, func_00282D30@0039763C, func_00282CC0@0039764C,
   func_00282CF0@0039765C, func_00280B90@003976BC, func_00282CF0@00397740,
   func_00282CF0@00397750, func_00282DF0@00397758, func_00282DF0@00397764,
   func_00282D30@003977A8, func_00282D30@003977E4, func_00282CC0@003977F8,
   func_00282CC0@0039780C, func_00282CF0@0039781C, func_00282D30@0039782C,
   func_00282CF0@0039783C, func_00282CC0@0039784C, func_00282CF0@0039785C,
   func_00282DD8@0039786C, func_00282DF0@00397874, func_00282D30@003978A8,
   func_00282CC0@003978B8, func_00282CF0@003978C8, func_00282CC0@003978D8,
   func_00282CF0@003978E8, func_00280B90@00397940, func_002FC560@00397970];
   data addresses materialised [0x1c0000, 0x1c0000, 0x1c0000, 0x50000];
   float constants [0x3f800000, 0x3f800000, 0x3f800000]; $gp-relative small
   data: no   saves: -; callee-saved registers saved [-]; words plain C
   cannot emit [LQ/SQ 7A420000@0x02dc, LQ/SQ 7FA20000@0x02e0, LQ/SQ
   7A620000@0x02e8, LQ/SQ 7C620000@0x02ec, LQ/SQ 7A620000@0x03a4, LQ/SQ
   7E420000@0x03a8, LQ/SQ 7A420000@0x03e0, LQ/SQ 7E620000@0x03e4]. Head:
   addiu $sp, $sp, -0x250 ; sd $s6, 0x210($sp) ; daddu $s6, $a0, $zero ; sd
   $s4, 0x200($sp) ; swc1 $f23, 0x248($sp) ; daddu $s4, $a1, $zero. Not
   matched in this wave: the 128-bit copy needs an `lq`/`sq` pair; plain C
   reaches it only through a `mode(TI)` local, and this cc1 folds the
   destination offset into the `sq` where retail materialises the pointer
   first. What would unblock it: the exact source expression tree, so this
   cc1 picks the same registers in the same order. */
