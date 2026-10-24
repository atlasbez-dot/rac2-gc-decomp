/* Nonmatching: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier. us: func_L00_0039D598: 0 of 27 places match (src/levels/shared/L00_0039D598.c); us2: func_L00_0039D598: 0 of 27 places match (src/levels/shared/L00_0039D598.c); pal: absent. Manual reconstruction2976/3004 frame0x80. True128-byte light-state layout with three5-byte color settings and overlaid initial delay byte in origin.w; aligned u64 flag-pair reads preserved. Explicit symmetric RNG upper bounds, typed integer lifetime/light IDs and fivefloat lightallocator arguments verified. Remaining register/branch/local ordering differences; reopen with original source expressions. */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef union { Quad quad; float f[4]; } Vector;
typedef struct { u8 initial, maximum, minimum, rise, fall; } ColorCycle;
typedef struct {
    Vector offset, origin;
    char *parent;
    u8 intensity;
    ColorCycle color[3];
    float initialRadius, maximumRadius, minimumRadius, radiusRise, radiusFall;
    int lifetime;
    u32 flags;
    int light;
    float rgb[3], radius;
    int parentIndex;
    u8 hold[4];
    short interval[4], timer[4];
    u8 delay[4];
} LightState;
extern char *D_L00_001B1E9C;
extern Vector D_L00_001C6F40[8][2];
extern float func_00283CE0(int), func_002A7878(float, float);
extern int func_00283CF0(float), func_00282948(int *), func_00282978(short *), func_002829A8(u8 *), func_00283DB8(void *, float);
extern void func_00291450(int), func_0029F338(void *), func_00282D30(void *, void *, float), func_00283098(void *, void *, void *), func_00282CC0(void *, void *, void *);
extern int func_L00_002FCF18(void *, float, float, float, float, float);
/* The retail code checks flag pairs through the aligned lifetime/flags doubleword. */
#define UPDATE_COLOR(n, randomFlag, pairMask, pairValue, pauseFlag, downFlag, topFlag, bottomFlag) \
    if (s->interval[n] && func_00282978(&s->timer[n])) { \
        s->timer[n] = s->interval[n]; \
        s->rgb[n] = (float)s->color[n].minimum; \
        s->flags &= ~(downFlag); \
    } \
    if (s->flags & (randomFlag)) { \
        if (!s->interval[n]) { \
            low = (float)func_00283CF0((float)s->color[n].minimum) * 0.01f; \
            high = (float)func_00283CF0((float)s->color[n].maximum) * 0.01f; \
            s->rgb[n] = func_002A7878(low, high); \
        } \
    } else { \
        if ((*(u64 *)&s->lifetime & (pairMask)) == (pairValue)) s->flags ^= (pauseFlag); \
        if (s->flags & (pauseFlag)) { \
            if (s->hold[n] && func_002829A8(&s->delay[n])) s->flags ^= (pauseFlag); \
        } else if (s->flags & (downFlag)) { \
            low = func_00283CE0(s->color[n].minimum) * 0.01f; \
            s->rgb[n] -= func_00283CE0(s->color[n].fall) * 0.01f; \
            if (s->rgb[n] <= low) { \
                s->rgb[n] = low; \
                if ((s->flags & (bottomFlag)) && !s->interval[n]) s->flags ^= (downFlag); \
            } \
        } else { \
            high = func_00283CE0(s->color[n].maximum) * 0.01f; \
            s->rgb[n] += func_00283CE0(s->color[n].rise) * 0.01f; \
            if (high <= s->rgb[n]) { \
                s->rgb[n] = high; \
                if (!(s->flags & (topFlag))) s->flags ^= (downFlag); \
                else { s->flags = (s->flags | (pauseFlag)) ^ (downFlag); s->delay[n] = s->hold[n]; } \
            } \
        } \
    }
/* Updates a configured animated point light: radius, RGB cycles and attachment. */
void func_L00_0039D598(char *actor) {
    LightState *s;
    Vector sphere, origin, offset;
    u8 startup;
    u32 saved;
    int radiusReset = 0, index;
    float low, high, intensity;
    if (!actor) return;
    s = *(LightState **)(actor + 0x68);
    if (!s) return;
    if (!(u8)actor[0x20]) {
        actor[0x30] = 0xFF;
        startup = *((u8 *)&s->origin + 12); actor[0xBC] = startup;
        s->origin.quad = *(Quad *)(actor + 0x10);
        s->light = -1;
        s->timer[1] = s->interval[1]; *((u8 *)&s->origin + 12) = startup;
        *(u32 *)&s->offset.f[3] = s->flags;
        s->timer[0] = s->interval[0]; s->timer[2] = s->interval[2]; s->timer[3] = s->interval[3];
        s->rgb[0] = func_00283CE0(s->color[0].initial) * 0.01f;
        s->rgb[1] = func_00283CE0(s->color[1].initial) * 0.01f;
        s->rgb[2] = func_00283CE0(s->color[2].initial) * 0.01f;
        s->radius = s->initialRadius;
        if (s->parentIndex != -1) s->parent = D_L00_001B1E9C + s->parentIndex * 0x100;
        if (s->radiusRise < 0) s->radiusRise = -s->radiusRise;
        if (s->radiusFall < 0) s->radiusFall = -s->radiusFall;
        actor[0x20] = 1;
    }
    if ((u8)actor[0xBC]) { --((u8 *)actor)[0xBC]; return; }
    if (s->lifetime != -1 && func_00282948(&s->lifetime)) {
        if (s->light != -1) { func_00291450(s->light); s->light = -1; }
        func_0029F338(actor); return;
    }
    sphere.quad = *(Quad *)(actor + 0x10); sphere.f[3] = s->radius;
    if (func_00283DB8(&sphere, 255) == -1) {
        if (s->light != -1) { func_00291450(s->light); s->light = -1; }
        return;
    }
    if (s->parent) origin.quad = *(Quad *)(s->parent + 0x10);
    else origin.quad = s->origin.quad;
    if (!(s->flags & 0x800000)) {
        if (!(s->flags & 0x100000)) {
            saved = *(u32 *)&s->offset.f[3]; s->offset.f[3] = 0;
            offset.quad = s->offset.quad; *(u32 *)&s->offset.f[3] = saved;
        } else if (!(s->flags & 0x200000)) {
            saved = *(u32 *)&s->offset.f[3]; s->offset.f[3] = 0;
            func_00282D30(&offset, &s->offset, func_002A7878(s->offset.f[3], 1));
            *(u32 *)&s->offset.f[3] = saved;
        } else {
            offset.f[0] = func_002A7878(-s->offset.f[0], s->offset.f[0]);
            offset.f[1] = func_002A7878(-s->offset.f[1], s->offset.f[1]);
            offset.f[2] = func_002A7878(-s->offset.f[2], s->offset.f[2]);
        }
        if ((s->flags & 0x400000) && s->parent) func_00283098(&offset, &offset, s->parent + 0xC0);
        func_00282CC0(actor + 0x10, &origin, &offset);
    } else *(Quad *)(actor + 0x10) = origin.quad;
    if (s->interval[3] && func_00282978(&s->timer[3])) {
        s->timer[3] = s->interval[3];
        radiusReset = (s->flags & 4) != 0;
        if (radiusReset) { s->radius = s->minimumRadius; s->flags &= ~8; }
    }
    if (s->flags & 0x80000) {
        if (!s->interval[3] || radiusReset) s->radius = func_002A7878(s->minimumRadius, s->maximumRadius);
    } else {
        if ((*(u64 *)&s->lifetime & 0x300000000ULL) == 0x200000000ULL) s->flags ^= 2;
        if (s->flags & 2) {
            if (s->hold[3] && func_002829A8(&s->delay[3])) s->flags ^= 2;
        } else if (!(s->flags & 8)) {
            s->radius += s->radiusRise;
            if (s->maximumRadius <= s->radius) {
                s->radius = s->maximumRadius;
                if (!(s->flags & 1)) s->flags ^= 8;
                else { s->flags = (s->flags | 2) ^ 8; s->delay[3] = s->hold[3]; }
            }
        } else {
            s->radius -= s->radiusFall;
            if (s->radius <= s->minimumRadius) {
                s->radius = s->minimumRadius;
                if ((s->flags & 4) && !s->interval[3]) s->flags ^= 8;
            }
        }
    }
    UPDATE_COLOR(0, 0x10000, 0x3000000000ULL, 0x2000000000ULL, 0x20, 0x80, 0x10, 0x40);
    UPDATE_COLOR(1, 0x20000, 0x30000000000ULL, 0x20000000000ULL, 0x200, 0x800, 0x100, 0x400);
    UPDATE_COLOR(2, 0x40000, 0x300000000000ULL, 0x200000000000ULL, 0x2000, 0x8000, 0x1000, 0x4000);
    if (s->light == -1) {
        intensity = func_00283CE0(s->intensity) * 0.01f;
        s->light = func_L00_002FCF18(actor + 0x10, s->radius * 0.8f, intensity, s->rgb[0], s->rgb[1], s->rgb[2]);
    } else {
        index = s->light;
        D_L00_001C6F40[index][1].quad = *(Quad *)(actor + 0x10);
        D_L00_001C6F40[index][1].f[3] = s->radius * 0.8f;
        D_L00_001C6F40[index][0].f[0] = s->rgb[0]; D_L00_001C6F40[index][0].f[1] = s->rgb[1]; D_L00_001C6F40[index][0].f[2] = s->rgb[2];
        D_L00_001C6F40[index][0].f[3] = func_00283CE0(s->intensity) * 0.01f;
    }
}
#undef UPDATE_COLOR

/* Historical screening only; superseded by the measured reconstruction above. */
/* func_L00_0039D598 - 3004 bytes, 27 place(s), level 00_aranos_tutorial,
   retail at 0x0039d598. Screened with tools/w10_screen.py: 48 call(s)
   [func_00283CE0@0039D644, func_00283CE0@0039D654, func_00283CE0@0039D664,
   func_00282948@0039D700, func_00291450@0039D71C, func_0029F338@0039D728,
   func_00283DB8@0039D754, func_002A7878@0039D7D0, func_002A7878@0039D7E0,
   func_002A7878@0039D7F0, func_002A7878@0039D818, func_00282D30@0039D828,
   func_00283098@0039D878, func_00282CC0@0039D888, func_00282978@0039D8AC,
   func_002829A8@0039D9D4, func_002A7878@0039DA08, func_00282978@0039DA20,
   func_00283CE0@0039DAC4, func_00283CE0@0039DAD0, func_00283CE0@0039DB24,
   func_00283CE0@0039DB30, func_002829A8@0039DB90, func_00283CF0@0039DBDC,
   func_00283CF0@0039DC00, func_002A7878@0039DC18, func_00282978@0039DC30,
   func_00283CE0@0039DCD4, func_00283CE0@0039DCE0, func_00283CE0@0039DD34,
   func_00283CE0@0039DD40, func_002829A8@0039DDA0, func_00283CF0@0039DDEC,
   func_00283CF0@0039DE10, func_002A7878@0039DE28, func_00282978@0039DE40,
   func_00283CE0@0039DEE4, func_00283CE0@0039DEF0, func_00283CE0@0039DF44,
   func_00283CE0@0039DF50, func_002829A8@0039DFB0, func_00283CF0@0039DFFC,
   func_00283CF0@0039E020, func_002A7878@0039E038, func_00283CE0@0039E068,
   func_L00_002FCF18@0039E090, func_00283CE0@0039E0EC,
   func_00291450@0039E118]; data addresses materialised [0x3c230000,
   0x1b0000, 0x800000, 0x100000, 0x200000, 0x400000, 0xffff0000, 0x80000,
   0xffff0000, 0x10000, 0x3c230000, 0x3c230000, 0x3c230000, 0xffff0000,
   0x20000, 0x3c230000, 0x3c230000, 0x3c230000, 0xffff0000, 0x40000,
   0x3c230000, 0x3c230000, 0x3c230000, 0x1c0000, 0x3f4c0000, 0x3c230000,
   0x3f4c0000, 0x3c230000]; float constants [0x437f0000, 0x3f800000]; $gp-
   relative small data: no   saves: -; callee-saved registers saved [-];
   words plain C cannot emit [LQ/SQ 78620000@0x0064, LQ/SQ 7C820000@0x0068,
   LQ/SQ 78620000@0x01a0, LQ/SQ 7FA20000@0x01a4, LQ/SQ 78820000@0x01e4,
   LQ/SQ 7C620000@0x01e8, LQ/SQ 78620000@0x01fc, LQ/SQ 7C820000@0x0200,
   LQ/SQ 7A420000@0x02ac, LQ/SQ 7C620000@0x02b0, LQ/SQ 7A820000@0x0300,
   LQ/SQ 7EA20000@0x0304, COP1 46800020@0x04b0, COP1 46806320@0x0640, COP1
   4680A520@0x0658, COP1 46806320@0x0664, COP1 46806B60@0x0678, COP1
   46800020@0x06c0, COP1 46806320@0x0850, COP1 4680A520@0x0868, COP1
   46806320@0x0874, COP1 46806B60@0x0888, COP1 46800020@0x08d0, COP1
   46806320@0x0a60, COP1 4680A520@0x0a78, COP1 46806320@0x0a84, COP1
   46806B60@0x0a98, LQ/SQ 7AA20000@0x0b18, LQ/SQ 7C620000@0x0b1c]. Head:
   addiu $sp, $sp, -0x80 ; sd $s1, 0x38($sp) ; sd $s0, 0x30($sp) ; daddu
   $s1, $a0, $zero ; sd $s2, 0x40($sp) ; sd $s3, 0x48($sp). Not matched in
   this wave: the 128-bit copy needs an `lq`/`sq` pair; plain C reaches it
   only through a `mode(TI)` local, and this cc1 folds the destination
   offset into the `sq` where retail materialises the pointer first. What
   would unblock it: the exact source expression tree, so this cc1 picks the
   same registers in the same order. */
