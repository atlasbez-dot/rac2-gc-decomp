/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 952 / 952 bytes; size equality is not a match.
 * us: 0/27 placements.
 * us2: 0/27 placements.
 * pal: 0/27 placements.
 * Residual: Complete952/952-byte three-band renderer with the real0x90packet and0x130frame. Ten bounded forms advanced the first US difference from+0x88to+0x100. Two independent UV stores and later packet-store scheduling remain different; indexed UV walking fixed the pointer/counter register tie. Further unchanged cosmetic trials should not be repeated.
 * Reopening condition: New ABI/CFG/allocator evidence or a measured compiler-model improvement; do not repeat tied forms.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Retained complete manual reconstruction; not an exact match.
 * Source profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Complete952/952-byte three-band renderer with the real0x90packet and0x130frame. Ten bounded forms advanced the first US difference from+0x88to+0x100. Two independent UV stores and later packet-store scheduling remain different; indexed UV walking fixed the pointer/counter register tie. Further unchanged cosmetic trials should not be repeated.
 */
#include "common.h"
typedef int EffectVectorWord __attribute__((mode(TI)));
typedef union { float v[4]; EffectVectorWord word; } EffectVector;
typedef struct {
    u8 pad[0x70];
    long f70;
    long f78;
    long f80;
    long f88;
} QuadPacket;
typedef union {
    QuadPacket header;
    struct {
        EffectVector vertex[4];
        u32 color[4];
        float uv[8];
        long control[4];
    } fields;
} EffectPacket;
#define VERTEX(p, i) (&(p).fields.vertex[i])
#define COLORS(p) ((p).fields.color)
#define UV(p) ((p).fields.uv)
extern float func_00283CE0(int);
extern int func_00283CF0(float);
extern float func_00283198(float);
extern void func_00281DE8(QuadPacket *, int, int, int);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282D30(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282DD8(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_00280B90(void *, void *, int);
extern char D_L00_001B8DC0[];
extern float D_L00_001B0BB8 __attribute__((sda));
extern float D_L00_001B0BBC __attribute__((sda));
extern float D_L00_001B0BC0 __attribute__((sda));
extern float D_L00_001B0BC4 __attribute__((sda));
extern u32 D_L00_001B0BC8 __attribute__((sda));
extern u32 D_L00_001B0BCC __attribute__((sda));
extern u32 D_L00_001B0BD0 __attribute__((sda));
extern u32 D_L00_001B0BD4 __attribute__((sda));
extern u32 D_L00_001B0BD8 __attribute__((sda));

/* Draw three bands of the emitter's camera-facing ribbon. */

void func_L00_003FC468(char *object) {
    EffectPacket packet;
    EffectVector camera_delta;
    EffectVector segment;
    EffectVector midpoint;
    EffectVector normal;
    char *state = *(char **)(object + 0x68);
    char *position;
    float life;
    float alpha;
    int i;
    float *uv;
    u32 color;

    life = func_00283CE0(*(int *)(state + 0x38)) * *(float *)(state + 0x3C);
    func_00281DE8(&packet.header, 23, 0, 0x80);
    alpha = life * 64.0f;
    COLORS(packet)[0] = COLORS(packet)[1] = COLORS(packet)[2] = COLORS(packet)[3] =
        ((u32)func_00283CF0(alpha) << 24) | 0x00108080;
    COLORS(packet)[2] = COLORS(packet)[3] =
        ((u32)func_00283CF0(alpha) << 24) | 0x00101080;
    UV(packet)[0] = 0.0f; UV(packet)[1] = 0.0f; UV(packet)[2] = 0.0f;
    UV(packet)[7] = UV(packet)[6] = UV(packet)[4] = UV(packet)[3] = 1.0f;
    UV(packet)[5] = 0.0f;
    for (i = 0; i < 4; i++) {
        UV(packet)[i * 2] -= *(float *)(state + 0x30);
        if (UV(packet)[i * 2] <= 7.0f) UV(packet)[i * 2] += 7.0f;
    }
    *(float *)(state + 0x30) += 0.1f;
    if (*(float *)(state + 0x30) >= 4.0f) *(float *)(state + 0x30) -= 4.0f;
    position = object + 0x10;
    func_00282CF0(&camera_delta, position, D_L00_001B8DC0);
    func_00282CF0(&segment, state + 0x50, position);
    func_00282D30(&segment, &segment, 0.5f);
    func_00282CC0(&midpoint, position, &segment);
    func_00282DD8(&normal, &camera_delta, &segment);
    func_00282F20(&normal, &normal, 0.1f);
    func_00282CC0(VERTEX(packet,0), position, &normal);
    func_00282CF0(VERTEX(packet,1), position, &normal);
    func_00282CC0(VERTEX(packet,2), &midpoint, &normal);
    func_00282CF0(VERTEX(packet,3), &midpoint, &normal);
    func_00280B90(&packet, 0, 0);
    COLORS(packet)[0] = COLORS(packet)[2];
    COLORS(packet)[1] = COLORS(packet)[3];
    COLORS(packet)[2] = 0x00108080;
    COLORS(packet)[3] = 0x00108080;
    *(EffectVectorWord *)VERTEX(packet,0) = *(EffectVectorWord *)VERTEX(packet,2);
    *(EffectVectorWord *)VERTEX(packet,1) = *(EffectVectorWord *)VERTEX(packet,3);
    func_00282CC0(VERTEX(packet,2), VERTEX(packet,2), &segment);
    func_00282CC0(VERTEX(packet,3), VERTEX(packet,3), &segment);
    func_00280B90(&packet, 0, 0);
    func_00281DE8(&packet.header, 14, 1, 0x80);
    color = ((u32)func_00283CF0(life * 64.0f) << 24) | 0x000040FF;
    COLORS(packet)[0] = color;
    COLORS(packet)[2] = 0x000040FF;
    COLORS(packet)[3] = 0x000040FF;
    UV(packet)[7] = 1.0f; UV(packet)[0] = 0.0f;
    UV(packet)[1] = 0.0f; UV(packet)[2] = 0.0f;
    UV(packet)[3] = 1.0f; UV(packet)[4] = 1.0f;
    UV(packet)[5] = 0.0f; UV(packet)[6] = 1.0f;
    COLORS(packet)[1] = COLORS(packet)[0];
    func_00282F20(&normal, &normal, 0.6f);
    func_00282CC0(VERTEX(packet,0), position, &normal);
    func_00282CF0(VERTEX(packet,1), position, &normal);
    func_00282CC0(&midpoint, position, &segment);
    func_00282CC0(&midpoint, &midpoint, &segment);
    func_00282CC0(VERTEX(packet,2), &midpoint, &normal);
    func_00282CF0(VERTEX(packet,3), &midpoint, &normal);
    func_00280B90(&packet, 0, 0);
}
