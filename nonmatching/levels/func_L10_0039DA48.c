/* Retained C reconstruction; not linked or counted.
 * Profile: -O2 -G0 -ffunction-sections.
 * 1484/1492 bytes. us: 0/2 places; us2: 0/2 places; pal: 0/2 places.
 * Remaining: The complete 144-byte core/glow packets preserve 64-bit texture/recorder
 * values and now state their real 16-byte packet alignment. Reviewed qcopy
 * handles the carried vertices and degenerate view rays. The frame remains
 * 0x260 versus retail 0x270; spills, local lifetimes and scheduling differ.
 * Explicit alignment does not change the 1484-byte helper result.
 * Reopen with: Independent renderer scratch/spill lifetime evidence. Do not manufacture
 * an extra vector or packet padding to reach the retail frame.
 */

#include "common.h"

typedef int Quad __attribute__((mode(TI)));
typedef struct StripQuad {
    f32 vertex[4][4];
    u32 color[4];
    f32 uv[2][4];
    u64 blend;
    u64 texture;
    u64 primitive;
    u64 tag;
} __attribute__((aligned(16))) StripQuad;
extern f32 D_L10_001B9680[4];
extern u64 func_0027C878(int);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282DD8(void *, void *, void *);
extern f32 func_00282DF0(void *);
extern void func_00282D30(void *, void *, f32);
extern void func_00280B90(void *, void *, int);
extern void func_002FC560(u32, u64);

/* Draws the core and camera-facing glow surfaces of a segmented energy strip. */
void func_L10_0039DA48(void *path, int coreAlpha, int glowAlpha, int count,
                      f32 coreWidth, f32 glowWidth, f32 bias, u32 coreColor, u32 glowColor) {
    StripQuad core;
    StripQuad glow;
    f32 normal[4], width[4], camera[4], tangent[4];
    f32 lineStart[4], lineEnd[4], sightStart[4], sightEnd[4], radial[4], shift[4];
    f32 (*points)[4] = path;
    f32 length, startLength, endLength;
    u32 coreTint, glowTint;
    int i, last = count - 1;
    core.texture = func_0027C878(14);
    coreTint = coreColor | ((u32)coreAlpha << 24);
    core.tag = 0x8000000048ULL;
    core.primitive = 0xFF9000000260ULL;
    core.blend = 0;
    core.color[0] = core.color[1] = core.color[2] = core.color[3] = coreTint;
    glow.texture = func_0027C878(16);
    glowTint = glowColor | ((u32)glowAlpha << 24);
    glow.tag = core.tag;
    glow.primitive = core.primitive;
    glow.blend = core.blend;
    glow.color[0] = glow.color[1] = glow.color[2] = glow.color[3] = glowTint;
    glow.uv[0][0] = 0.0f; glow.uv[0][1] = 0.0f; glow.uv[0][2] = 0.0f; glow.uv[0][3] = 1.0f;
    glow.uv[1][0] = 1.0f; glow.uv[1][1] = 0.0f; glow.uv[1][2] = 1.0f; glow.uv[1][3] = 1.0f;
    core.uv[0][0] = 0.0f; core.uv[0][1] = 0.0f; core.uv[0][2] = 0.0f; core.uv[0][3] = 1.0f;
    core.uv[1][0] = 1.0f; core.uv[1][1] = 0.0f; core.uv[1][2] = 1.0f; core.uv[1][3] = 1.0f;
    func_00282CF0(camera, points[0], D_L10_001B9680);
    func_00282CF0(tangent, points[1], points[0]);
    func_00282DD8(normal, tangent, camera);
    length = func_00282DF0(normal);
    if (length != 0.0f) length = 1.0f / length;
    func_00282D30(normal, normal, coreWidth * length);
    func_00282CC0(core.vertex[0], points[0], normal);
    func_00282CF0(core.vertex[1], points[0], normal);
    for (i = 1; i < last; i++) {
        func_00282CF0(camera, points[i], D_L10_001B9680);
        func_00282CF0(tangent, points[i + 1], points[i]);
        func_00282DD8(normal, tangent, camera);
        length = func_00282DF0(normal);
        if (length != 0.0f) length = 1.0f / length;
        func_00282D30(normal, normal, coreWidth * length);
        func_00282CC0(core.vertex[2], points[i], normal);
        func_00282CF0(core.vertex[3], points[i], normal);
        if (i == 1) core.color[0] = core.color[1] = coreColor;
        else if (i == last) core.color[2] = core.color[3] = coreColor;
        else if (i == 2) core.color[0] = core.color[1] = coreTint;
        func_00280B90(&core, 0, 0);
        qcopy(core.vertex[0], core.vertex[2]);
        qcopy(core.vertex[1], core.vertex[3]);
    }
    for (i = 0; i < last; i++) {
        func_00282CF0(sightStart, points[i], D_L10_001B9680);
        func_00282CF0(sightEnd, points[i + 1], D_L10_001B9680);
        startLength = func_00282DF0(sightStart);
        endLength = func_00282DF0(sightEnd);
        if (endLength < startLength) {
            if (endLength == 0.0f) qcopy(sightEnd, sightStart);
            else func_00282D30(sightEnd, sightEnd, startLength / endLength);
        } else {
            if (startLength == 0.0f) qcopy(sightStart, sightEnd);
            else func_00282D30(sightStart, sightStart, endLength / startLength);
        }
        func_00282CC0(lineStart, D_L10_001B9680, sightStart);
        func_00282CC0(lineEnd, D_L10_001B9680, sightEnd);
        func_00282CF0(tangent, lineEnd, lineStart);
        func_00282D30(shift, tangent, bias);
        func_00282CF0(lineStart, lineStart, shift);
        func_00282CC0(lineEnd, lineEnd, shift);
        func_00282CF0(radial, D_L10_001B9680, lineStart);
        func_00282DD8(normal, radial, tangent);
        length = func_00282DF0(normal);
        if (length != 0.0f) length = 1.0f / length;
        func_00282D30(width, normal, glowWidth * length);
        func_00282CC0(glow.vertex[0], lineStart, width);
        func_00282CF0(glow.vertex[1], lineStart, width);
        func_00282CC0(glow.vertex[2], lineEnd, width);
        func_00282CF0(glow.vertex[3], lineEnd, width);
        if (i == 0) glow.color[0] = glow.color[1] = glowColor;
        else if (i == count - 2) glow.color[2] = glow.color[3] = glowColor;
        else if (i == 1) glow.color[0] = glow.color[1] = glowTint;
        func_00280B90(&glow, 0, 0);
    }
    func_002FC560(0x47, 0x5360BULL);
}
