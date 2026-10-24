/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections -g -fno-gcse.
 * Reported final C / retail: 1864 / 1928 bytes; size equality is not a match.
 * us: 0/1 placements; 1864/1928 bytes.
 * us2: 0/1 placements; 1864/1928 bytes.
 * pal: 0/1 placements; 1864/1928 bytes.
 * Residual: Exact frame 0x690. Initial twelve TI loads need ordinary lowering; later copy address formation/save ordering/spills remain.
 * Reopening condition: New concrete supported compiler/API/identity hypothesis only; see retained source comment. No repeated flag or permutation sweep.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Complete retained rendering path. -O2 -G0 -ffunction-sections -g -fno-gcse
   gives 1864/1928 bytes and the exact 0x690-byte frame. Five meaningful trials:
   aggregate matrices/qcopy 2044, explicit quad copies 1932, packet cursor/no-GCSE
   1864, default GCSE 1908, debug/no-GCSE 1864 tie. US/US2/PAL 0/1.
   Matrix-load/store grouping, save placement, pointer spills and folded TI
   address forms remain. Ordinary lowering is needed for the twelve initial
   quad loads; applying grouped qcopy globally destroys that simultaneous-load
   pattern. Reopen with a supported distinction for later copy scheduling.
   Packet extent0x90, UV extent32 and helper inputs independently retail-reviewed. */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));
typedef union { TI128 quad; float f[4]; } EffectVector;
typedef struct { EffectVector vertex[4]; } EffectQuad;
typedef struct { float uv[8]; } EffectUV;
typedef struct { u32 word[5]; } EffectPalette;
/* The builder and renderer walk 0x90-byte packets, including the last header word. */
typedef struct {
    EffectVector vertex[4];
    u8 header[0x10];
    float uv[4][2];
    u8 tail[0x20];
} EffectPacket;
extern EffectUV D_L02_001B1AE0;
extern EffectUV D_L02_001B1B00;
extern EffectPalette D_L02_001B1B20;
extern EffectQuad D_L02_001B1B40;
extern EffectQuad D_L02_001B1B80;
extern EffectQuad D_L02_001B1BC0;
extern u32 D_L02_001B1C00;
extern u32 D_L02_001B1C04;
extern EffectVector D_L02_001BA500;
extern void func_00283658(void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282CF0(void *, void *, void *);
extern void func_002AFDD8(char *, char *, char *, char *);
extern void func_00282D30(void *, void *, float);
extern float func_00283198(float);
extern u32 func_00283D38(u32, u32, float);
extern void func_L02_002EF968(EffectPacket *, u32, u32, float *, EffectVector *, s32);
extern void *func_00115484(void *, s32, u32);
extern void func_002833F0(void *, void *);
extern void func_L01_002E1510(EffectPacket *, s32, void *, s32, void *);
extern void func_00282CC0(void *, void *, void *);

/* Render seven related quads with scrolling UVs and two expanding wave pairs. */
void func_L02_00411D18(u8 *object)
{
    EffectUV primary_uv = D_L02_001B1AE0;
    EffectUV secondary_uv = D_L02_001B1B00;
    EffectPalette palette = D_L02_001B1B20;
    EffectQuad primary;
    EffectQuad left;
    EffectQuad right;
    EffectVector context[4];
    EffectVector direction;
    EffectPacket packets[7];
    u32 wave_color[2];
    EffectVector transform_parameters[2];
    EffectVector expansion[2];
    EffectVector zero_expansion[2];
    EffectVector matrix[3];
    u8 *state = *(u8 **)(object + 0x68);
    u32 primary_color;
    u32 secondary_color;
    float phase;
    float fade;
    s32 i;

    primary.vertex[0].quad = D_L02_001B1B40.vertex[0].quad;
    primary.vertex[1].quad = D_L02_001B1B40.vertex[1].quad;
    primary.vertex[2].quad = D_L02_001B1B40.vertex[2].quad;
    primary.vertex[3].quad = D_L02_001B1B40.vertex[3].quad;
    left.vertex[0].quad = D_L02_001B1B80.vertex[0].quad;
    left.vertex[1].quad = D_L02_001B1B80.vertex[1].quad;
    left.vertex[2].quad = D_L02_001B1B80.vertex[2].quad;
    left.vertex[3].quad = D_L02_001B1B80.vertex[3].quad;
    right.vertex[0].quad = D_L02_001B1BC0.vertex[0].quad;
    right.vertex[1].quad = D_L02_001B1BC0.vertex[1].quad;
    right.vertex[2].quad = D_L02_001B1BC0.vertex[2].quad;
    right.vertex[3].quad = D_L02_001B1BC0.vertex[3].quad;
    func_00283658(context, object + 0xC0);
    context[3].quad = *(TI128 *)(object + 0x10);
    context[3].f[3] = 1.0f;
    func_00282F20(context, context, 4.0f);
    func_00282F20(context + 1, context + 1, 10.0f);
    func_00282CF0(&direction, &D_L02_001BA500, object + 0x10);
    func_002AFDD8((char *)object, (char *)&direction, (char *)&direction, 0);
    if (direction.f[0] < 0.0f)
        func_00282D30(context, context, -1.0f);
    phase = func_00283198(*(float *)(state + 0x2C)) * 0.5f + 0.5f;
    primary_color = func_00283D38(palette.word[0], palette.word[1], phase);
    secondary_color = func_00283D38(palette.word[2], palette.word[3], phase);
    fade = *(float *)(state + 0x20);
    if (!(fade >= 0.2f))
        fade = 1.0f - fade * 5.0f;
    wave_color[0] = func_00283D38(palette.word[3], palette.word[3] & 0xFFFFFF, fade);
    fade = *(float *)(state + 0x24);
    if (!(fade >= 0.2f))
        fade = 1.0f - fade * 5.0f;
    wave_color[1] = func_00283D38(palette.word[3], palette.word[3] & 0xFFFFFF, fade);
    if (*(float *)(state + 0x1C) < 1.0f) {
        primary_color = func_00283D38(primary_color & 0xFFFFFF, primary_color, *(float *)(state + 0x1C));
        secondary_color = func_00283D38(secondary_color & 0xFFFFFF, secondary_color, *(float *)(state + 0x1C));
        wave_color[0] = func_00283D38(wave_color[0] & 0xFFFFFF, wave_color[0], *(float *)(state + 0x1C));
        wave_color[1] = func_00283D38(wave_color[1] & 0xFFFFFF, wave_color[1], *(float *)(state + 0x1C));
    }
    func_L02_002EF968(packets, D_L02_001B1C00, primary_color, primary_uv.uv, primary.vertex, 1);
    func_L02_002EF968(packets + 1, D_L02_001B1C04, secondary_color, secondary_uv.uv, left.vertex, 1);
    func_L02_002EF968(packets + 2, D_L02_001B1C04, secondary_color, secondary_uv.uv, right.vertex, 1);
    func_L02_002EF968(packets + 3, D_L02_001B1C04, wave_color[0], secondary_uv.uv, left.vertex, 1);
    func_L02_002EF968(packets + 4, D_L02_001B1C04, wave_color[0], secondary_uv.uv, right.vertex, 1);
    func_L02_002EF968(packets + 5, D_L02_001B1C04, wave_color[1], secondary_uv.uv, left.vertex, 1);
    func_L02_002EF968(packets + 6, D_L02_001B1C04, wave_color[1], secondary_uv.uv, right.vertex, 1);
    i = 3;
    {
        float *uv1 = packets[1].uv[0];
        float *uv2 = packets[2].uv[0];
        float *uv3 = packets[3].uv[0];
        float *uv4 = packets[4].uv[0];
        float *uv5 = packets[5].uv[0];
        float *uv6 = packets[6].uv[0];
        u8 *vertex = (u8 *)packets;
        do {
            *uv1 += *(float *)(state + 0x28); uv1 += 2;
            *uv2 += *(float *)(state + 0x28); uv2 += 2;
            *uv3 += *(float *)(state + 0x28); uv3 += 2;
            *uv4 += *(float *)(state + 0x28); uv4 += 2;
            *uv5 += *(float *)(state + 0x28); uv5 += 2;
            *uv6 += *(float *)(state + 0x28); uv6 += 2;
            *(float *)(vertex + 0x1B8) -= *(float *)(state + 0x20) + *(float *)(state + 0x20);
            *(float *)(vertex + 0x248) += *(float *)(state + 0x20) + *(float *)(state + 0x20);
            *(float *)(vertex + 0x2D8) -= *(float *)(state + 0x24) + *(float *)(state + 0x24);
            *(float *)(vertex + 0x368) += *(float *)(state + 0x24) + *(float *)(state + 0x24);
            vertex += 0x10;
        } while (--i >= 0);
    }
    transform_parameters[0].quad = 0;
    transform_parameters[1].quad = 0;
    transform_parameters[0].f[2] = -0.19634955f;
    transform_parameters[1].f[2] = 6.0f;
    func_00115484(zero_expansion, 0, sizeof(zero_expansion));
    zero_expansion[0].f[2] = *(float *)(state + 0x20) + *(float *)(state + 0x20);
    zero_expansion[1].f[2] = *(float *)(state + 0x24) + *(float *)(state + 0x24);
    expansion[0].quad = zero_expansion[0].quad;
    expansion[1].quad = zero_expansion[1].quad;
    func_002833F0(matrix, transform_parameters);
    func_L01_002E1510(packets, 7, matrix, 16, context);
    i = 3;
    {
        EffectVector *v0 = packets[0].vertex;
        EffectVector *v1 = packets[1].vertex;
        EffectVector *v2 = packets[2].vertex;
        EffectVector *v3 = packets[3].vertex;
        EffectVector *v4 = packets[4].vertex;
        EffectVector *v5 = packets[5].vertex;
        EffectVector *v6 = packets[6].vertex;
        EffectVector *p0 = primary.vertex;
        EffectVector *p1 = left.vertex;
        EffectVector *p2 = right.vertex;
        do {
            func_00282CC0(v0++, p0++, transform_parameters + 1);
            func_00282CC0(v1++, p1, transform_parameters + 1);
            func_00282CC0(v2++, p2, transform_parameters + 1);
            func_00282CC0(v3, p1, transform_parameters + 1);
            func_00282CC0(v4, p2, transform_parameters + 1);
            func_00282CC0(v5, p1++, transform_parameters + 1);
            func_00282CC0(v6, p2++, transform_parameters + 1);
            func_00282CF0(v3, v3, expansion); v3++;
            func_00282CC0(v4, v4, expansion); v4++;
            func_00282CF0(v5, v5, expansion + 1); v5++;
            func_00282CC0(v6, v6, expansion + 1); v6++;
        } while (--i >= 0);
    }
    func_002833F0(matrix, transform_parameters);
    func_L01_002E1510(packets, 7, matrix, 16, context);
}
