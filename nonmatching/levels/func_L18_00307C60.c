/* Measured profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier. us: 18_damosel: 936
   bytes, expected 932; us2: 18_damosel: 936 bytes, expected 932; pal: 18_damosel: 936 bytes, expected
   932. Three meaningful pointer/count and color-expression forms produced 936 bytes versus 932.
   Remaining color stores, projection-UV branch ordering and clamp/join layout differ. Full 144-byte
   packet and 64-byte basis retained. Reopen with a matching quad packet/color and UV lifetime witness.
   No linked build or functional execution run. */

/* Historical screening below; superseded by the measured C reconstruction. */
/* func_L18_00307C60 - 932 bytes, 2 place(s), level 18_damosel, retail at
   0x00307c60. Screened with tools/w10_screen.py: 13 call(s)
   [func_00282DD8@00307CD8, func_00282F20@00307CF0, func_00282DD8@00307D00,
   func_00282D30@00307D14, func_00282CC0@00307D28, func_00282D30@00307D50,
   func_002830C0@00307D68, func_00281DE8@00307D84, func_00280B90@00307DDC,
   func_00281DE8@00307DF0, func_00282D30@00307E0C, func_0027C768@00307EE8,
   func_00280B90@00307FC0]; data addresses materialised [0x190000, 0x1b0000,
   0x800000, 0x3c230000]; float constants [0x3f800000, 0x3f800000,
   0x3f800000, 0x3f800000, 0x3f800000]; $gp-relative small data: no   saves:
   -; callee-saved registers saved [-]; words plain C cannot emit [LQ/SQ
   78820000@0x0050, LQ/SQ 7E420000@0x0054, LQ/SQ 78A20000@0x005c, LQ/SQ
   7E220000@0x0060]. Head: addiu $sp, $sp, -0x150 ; sd $s2, 0xF0($sp) ; sd
   $s6, 0x110($sp) ; addiu $s2, $sp, 0xC0 ; sd $s7, 0x118($sp) ; daddu $s6,
   $a2, $zero. Not matched in this wave: the 128-bit copy needs an `lq`/`sq`
   pair; plain C reaches it only through a `mode(TI)` local, and this cc1
   folds the destination offset into the `sq` where retail materialises the
   pointer first. What would unblock it: the exact source expression tree,
   so this cc1 picks the same registers in the same order. */

#include "common.h"
typedef int VectorBits __attribute__((mode(TI)));
typedef union { VectorBits bits; float f[4]; } LensVector;
typedef struct { LensVector vertex[4]; u32 colors[4]; float uv[4][2]; s64 primitive, texture, mode, flags; } QuadPacket;
extern float D_0018A0E0[4];
extern float D_L18_001AA250[4][4];
extern void func_00282DD8(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282D30(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_002830C0(void *, void *, void *);
extern void func_00281DE8(QuadPacket *, s32, s32, s32);
extern void func_00280B90(void *, void *, s32);
extern void func_0027C768(s32, float *, float *);
void func_L18_00307C60(float size, float spread, float distance, LensVector *position, LensVector *direction, s32 opacity, float **customUV)
{
    QuadPacket packet;
    LensVector basis[4], offset;
    float *source;
    s32 i;
    LensVector *vertex;
    basis[3].bits = position->bits;
    basis[0].bits = direction->bits;
    func_00282DD8(&basis[1], &basis[0], D_0018A0E0);
    func_00282F20(&basis[1], &basis[1], 1.0f);
    func_00282DD8(&basis[2], &basis[1], &basis[0]);
    func_00282D30(&offset, &basis[0], distance);
    func_00282CC0(&basis[3], &basis[3], &offset);
    source = D_L18_001AA250[0];
    vertex = packet.vertex;
    for (i = 3; i >= 0; i--) {
        func_00282D30(vertex, source, size);
        source += 4;
        func_002830C0(vertex, vertex, basis);
        vertex++;
    }
    func_00281DE8(&packet, 60, 5, 128);
    packet.colors[0] = packet.colors[1] = packet.colors[2] = packet.colors[3] = ((u32)opacity << 24) | 0x808080;
    packet.uv[0][0] = 0.0f; packet.uv[0][1] = 0.0f;
    packet.uv[1][0] = 0.0f; packet.uv[1][1] = 1.0f;
    packet.uv[2][0] = 1.0f; packet.uv[2][1] = 0.0f;
    packet.uv[3][0] = 1.0f; packet.uv[3][1] = 1.0f;
    func_00280B90(&packet, 0, 0);
    func_00281DE8(&packet, -1, 6, 128);
    func_00282D30(&offset, &basis[0], distance + 0.01f);
    if (customUV) {
        float *u = &packet.uv[0][0];
        float *v = &packet.uv[0][1];
        for (i = 3; i >= 0; i--) {
            *u = (*customUV)[0];
            *v = (*customUV)[1];
            if (*u > 1.0f) *u = 1.0f;
            else if (*u < 0.0f) *u = 0.0f;
            if (*v > 1.0f) *v = 1.0f;
            else if (*v < 0.0f) *v = 0.0f;
            u += 2;
            v += 2;
            customUV++;
        }
    } else {
        for (i = 0; i < 4; i++) {
            func_0027C768((s32)&packet.vertex[i], &packet.uv[i][0], &packet.uv[i][1]);
            if (i >> 1) packet.uv[i][0] -= spread;
            else packet.uv[i][0] += spread;
            if ((i & 1) == 0) packet.uv[i][1] -= spread;
            else packet.uv[i][1] += spread;
            if (packet.uv[i][0] > 1.0f) packet.uv[i][0] = 1.0f;
            else if (packet.uv[i][0] < 0.0f) packet.uv[i][0] = 0.0f;
            if (packet.uv[i][1] > 1.0f) packet.uv[i][1] = 1.0f;
            else if (packet.uv[i][1] < 0.0f) packet.uv[i][1] = 0.0f;
        }
    }
    func_00280B90(&packet, 0, 0);
}
