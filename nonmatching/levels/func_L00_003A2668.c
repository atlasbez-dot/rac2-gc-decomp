/* Reconstruction checked 23 October 2026.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Final check.py coverage: us 0/27, us2 0/27, pal 0/27.
 * Manual144-byte beam-quad reconstruction1224/1204 with qcopy/barrier.
 * Remaining: Quad/register initialization scheduling, stack/workspace allocation and segment-loop registers differ.
 * Reopen with a verified complete render-quad declaration and matching loop witness.
 * The qualified R5900 view decodes the cited SPECIAL2 word as por, not an unknown instruction.
 * Historical screening below is preserved; its blanket C/ISA claims are not acceptance evidence.
 */

/* MMI (SPECIAL2) instruction: no C spelling. 1204 bytes, level
   00_aranos_tutorial. Retail at 0x003A2668 carries the SPECIAL2 word
   0x700014A9 (+0x00C4) - opcode 0x1C, which rabbitizer prints as `INVALID`;
   it is the MMI family (pcpyld and its relatives) the sixth wave recorded
   and that no C spelling reaches. This cc1 emits `lq`/`sq` for a `mode(TI)`
   local and `ldl`/`ldr`/`sdl`/`sdr` for a struct assignment, never the
   packed copy. ASM_FUNC candidate, as for the rest of the family. */

#include "common.h"
typedef int VectorBits __attribute__((mode(TI)));
typedef struct { float vertices[4][4]; unsigned int colors[4]; float uv[4][2]; u64 registers[4]; } BeamQuad;
extern u64 func_0027C878(int);
extern void func_L00_003A2570(void *, int);
extern void func_L00_003A2B28(char *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282DD8(void *, void *, void *);
extern void func_00282D30(void *, void *, float);
extern void func_002830C0(void *, void *, void *);
extern void func_00280B90(void *, int, int);
extern float func_00283CE0(int);
extern float D_L00_001B8DC0[4];

/* Draw a two-layer ribbon along a sequence of sampled beam points. */
void func_L00_003A2668(void *owner, unsigned int opacity, float points[][4], int count)
{
    BeamQuad outer, inner;
    float frame[4][4], outerWidth[4], innerWidth[4];
    float *current = points[1];
    int index;
    outer.registers[3] = ((u64)opacity << 32) | 0x68;
    outer.registers[1] = func_0027C878(43);
    outer.colors[0] = 0x7F7F7F7F;
    outer.colors[1] = 0x7F7F7F7F;
    outer.registers[2] = 0xFF9000000260ULL;
    outer.registers[0] = 0;
    inner.registers[1] = func_0027C878(14);
    inner.registers[2] = 0xFF9000000260ULL;
    inner.registers[0] = 0;
    *(VectorBits *)outerWidth = 0;
    *(VectorBits *)innerWidth = 0;
    outer.colors[1] = 0x7FFF0000;
    inner.colors[0] = 0x7FFF0000;
    outerWidth[2] = 0.0125f;
    outerWidth[3] = 1.0f;
    innerWidth[2] = 0.053125f;
    innerWidth[3] = 1.0f;
    inner.registers[3] = ((u64)(int)((int)opacity / 3) << 32) | 0x68;
    func_L00_003A2570(points, count);
    func_L00_003A2B28((char *)&outer);
    func_L00_003A2B28((char *)&inner);
    outer.uv[0][0] = 0.0f; outer.uv[0][1] = 0.0f;
    outer.uv[1][0] = 0.0f; outer.uv[1][1] = 1.0f;
    outer.uv[2][0] = 1.0f; outer.uv[2][1] = 0.0f;
    outer.uv[3][0] = 1.0f; outer.uv[3][1] = 1.0f;
    inner.uv[0][0] = 0.0f; inner.uv[0][1] = 0.0f;
    inner.uv[1][0] = 0.0f; inner.uv[1][1] = 1.0f;
    inner.uv[2][0] = 0.33f; inner.uv[2][1] = 0.0f;
    inner.uv[3][0] = 0.33f; inner.uv[3][1] = 1.0f;
    func_00282CF0(frame[0], current, points[0]);
    func_00282F20(frame[0], frame[0], 1.0f);
    func_00282CF0(frame[1], D_L00_001B8DC0, points[0]);
    func_00282DD8(frame[2], frame[1], frame[0]);
    func_00282F20(frame[2], frame[2], 1.0f);
    func_00282DD8(frame[1], frame[0], frame[2]);
    *(VectorBits *)frame[3] = *(VectorBits *)points[0];
    *(VectorBits *)outer.vertices[0] = *(VectorBits *)outerWidth;
    func_00282D30(outer.vertices[1], outer.vertices[0], -1.0f);
    func_002830C0(outer.vertices[0], outer.vertices[0], frame);
    func_002830C0(outer.vertices[1], outer.vertices[1], frame);
    *(VectorBits *)inner.vertices[0] = *(VectorBits *)innerWidth;
    func_00282D30(inner.vertices[1], inner.vertices[0], -1.0f);
    func_002830C0(inner.vertices[0], inner.vertices[0], frame);
    func_002830C0(inner.vertices[1], inner.vertices[1], frame);
    for (index = 1; index < count - 1; index++) {
        *(VectorBits *)outer.vertices[2] = *(VectorBits *)outerWidth;
        func_00282D30(outer.vertices[3], outer.vertices[2], -1.0f);
        *(VectorBits *)inner.vertices[2] = *(VectorBits *)innerWidth;
        func_00282D30(inner.vertices[3], inner.vertices[2], -1.0f);
        func_00282CF0(frame[0], points[index + 1], current);
        func_00282F20(frame[0], frame[0], 1.0f);
        func_00282CF0(frame[1], D_L00_001B8DC0, current);
        func_00282DD8(frame[2], frame[1], frame[0]);
        func_00282F20(frame[2], frame[2], 1.0f);
        func_00282DD8(frame[1], frame[0], frame[2]);
        *(VectorBits *)frame[3] = *(VectorBits *)current;
        func_002830C0(outer.vertices[2], outer.vertices[2], frame);
        func_002830C0(outer.vertices[3], outer.vertices[3], frame);
        func_002830C0(inner.vertices[2], inner.vertices[2], frame);
        func_002830C0(inner.vertices[3], inner.vertices[3], frame);
        outer.colors[2] = outer.colors[3] = 0x7F7F7F7F;
        inner.colors[2] = inner.colors[3] = 0x7FFF0000;
        func_00280B90(&outer, 0, 0);
        func_00280B90(&inner, 0, 0);
        inner.uv[0][0] = func_00283CE0(index) * 0.33f;
        inner.uv[2][0] = inner.uv[0][0] + 0.33f;
        if (inner.uv[0][0] >= 1.0f) {
            inner.uv[0][0] -= 1.0f;
            inner.uv[2][0] -= 1.0f;
        }
        *(VectorBits *)outer.vertices[0] = *(VectorBits *)outer.vertices[2];
        *(VectorBits *)outer.vertices[1] = *(VectorBits *)outer.vertices[3];
        *(VectorBits *)inner.vertices[0] = *(VectorBits *)inner.vertices[2];
        *(VectorBits *)inner.vertices[1] = *(VectorBits *)inner.vertices[3];
        current += 4;
        inner.uv[1][0] = inner.uv[0][0];
        inner.uv[3][0] = inner.uv[2][0];
    }
}
