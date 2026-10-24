/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-gcse-unsplit-edges.
 * Reported final C / retail: 1472 / 1488 bytes; size equality is not a match.
 * us: 0/1 placements; 1472/1488 bytes.
 * us2: 0/1 placements; 1472/1488 bytes.
 * pal: 0/1 placements; 1472/1488 bytes.
 * Residual: Complete two-packet ribbon reconstruction: 1464,1480,1472,1472,1472 bytes against1488. The0x250frame and0x90packet extents are correct; allocator, FP saves, loop spills and packet-copy scheduling differ. The renderer nullable-matrix input is qualified; its ignored third caller slot remains an original-formal uncertainty. Reopen with grounded allocator/profile evidence, not a fabricated object extent or barrier.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */



/* Manual retained reconstruction; not an exact match.
 * Profile: -O2 -G8 -ffunction-sections -frac2-gcse-unsplit-edges.
 * Complete two-packet ribbon reconstruction: 1464,1480,1472,1472,1472 bytes against1488. The0x250frame and0x90packet extents are correct; allocator, FP saves, loop spills and packet-copy scheduling differ. The renderer nullable-matrix input is qualified; its ignored third caller slot remains an original-formal uncertainty. Reopen with grounded allocator/profile evidence, not a fabricated object extent or barrier.
 * All carrying releases fail the final complete check; absent catalogue entries are not matches.
 */
#include "common.h"

typedef int RibbonQuadword __attribute__((mode(TI)));
typedef union {
    float component[4];
    RibbonQuadword quadword;
} RibbonVector;

/* Four vertices, four RGBA words, four UV pairs and four GS register words. */
typedef struct {
    RibbonVector vertex[4];
    u32 color[4];
    float uv[8];
    u64 register_word[4];
} RibbonPacket;

extern unsigned long func_0027C878(int);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282DD8(void *, void *, void *);
extern float func_00282DF0(void *);
extern void func_00282D30(void *, void *, float);
/* The matrix input is nullable. This caller also supplies zero in a2;
 * the renderer does not consume that slot, so the original formal tail
 * still needs source-contract qualification before this caller can land. */
extern void func_00280B90(void *, void *, int);
extern void func_002FC560(u32, u64);
extern float D_L02_001B0C68 __attribute__((sda));
extern u32 D_L02_001B0C70 __attribute__((sda));
extern u32 D_L02_001B0C74 __attribute__((sda));
extern float D_L02_001B0C80 __attribute__((sda));
extern int D_L02_001B0CBC __attribute__((sda));
extern int D_L02_001B0CC0 __attribute__((sda));
extern char D_L02_001BA500[];

/* Draw the core strip and camera-facing outer ribbon along the supplied polyline. */
void func_L02_003E9BB0(float unused_scale, float width, float inset,
                      RibbonVector *points, u32 core_color, u32 outer_color, int count) {
    RibbonPacket core;
    RibbonPacket outer;
    RibbonVector normal;
    RibbonVector scaled_normal;
    RibbonVector from_camera;
    RibbonVector segment;
    RibbonVector first;
    RibbonVector second;
    RibbonVector radial_first;
    RibbonVector radial_second;
    RibbonVector offset;
    RibbonVector edge;
    RibbonVector *current;
    RibbonVector *next;
    RibbonVector *segment_vector;
    RibbonVector *offset_vector;
    RibbonVector *edge_vector;
    RibbonVector *normal_vector;
    float length;
    float first_length;
    float second_length;
    int i;
    int last;

    current = points + 1;
    core.register_word[1] = func_0027C878(D_L02_001B0CBC);
    core.register_word[3] = 0x8000000048ULL;
    core.register_word[2] = 0xFF9000000260ULL;
    core.register_word[0] = 0;
    core.color[3] = core_color;
    core.color[2] = core_color;
    core.color[1] = core_color;
    core.color[0] = core_color;
    outer.register_word[1] = func_0027C878(D_L02_001B0CC0);
    outer.register_word[3] = core.register_word[3];
    outer.register_word[2] = core.register_word[2];
    outer.register_word[0] = core.register_word[0];
    outer.color[3] = outer_color;
    outer.color[2] = outer_color;
    outer.color[1] = outer_color;
    outer.color[0] = outer_color;
    outer.uv[0] = 0.0f;
    outer.uv[1] = 0.0f;
    outer.uv[2] = 0.0f;
    outer.uv[3] = 1.0f;
    outer.uv[4] = 1.0f;
    outer.uv[5] = 0.0f;
    outer.uv[6] = 1.0f;
    outer.uv[7] = 1.0f;
    core.uv[0] = D_L02_001B0C68;
    core.uv[1] = 0.0f;
    core.uv[2] = D_L02_001B0C68;
    core.uv[3] = 1.0f;
    core.uv[4] = D_L02_001B0C68 + 1.0f;
    core.uv[5] = 0.0f;
    core.uv[6] = D_L02_001B0C68 + 1.0f;
    core.uv[7] = 1.0f;
    func_00282CF0(&from_camera, points, D_L02_001BA500);
    func_00282CF0(&segment, current, points);
    func_00282DD8(&normal, &segment, &from_camera);
    length = func_00282DF0(&normal);
    if (length != 0.0f) length = 1.0f / length;
    func_00282D30(&normal, &normal, D_L02_001B0C80 * length);
    func_00282CC0(&core.vertex[0], points, &normal);
    func_00282CF0(&core.vertex[1], points, &normal);
    last = count - 1;
    next = points + 2;
    for (i = 1; i < last; i++) {
        func_00282CF0(&from_camera, current, D_L02_001BA500);
        func_00282CF0(&segment, next, current);
        func_00282DD8(&normal, &segment, &from_camera);
        length = func_00282DF0(&normal);
        if (length != 0.0f) length = 1.0f / length;
        func_00282D30(&normal, &normal, D_L02_001B0C80 * length);
        func_00282CC0(&core.vertex[2], current, &normal);
        func_00282CF0(&core.vertex[3], current, &normal);
        if (i == 1) {
            core.color[0] = D_L02_001B0C70;
            core.color[1] = D_L02_001B0C70;
        } else if (i == count - 2) {
            core.color[2] = D_L02_001B0C70;
            core.color[3] = D_L02_001B0C70;
        } else if (i == 2) {
            core.color[0] = core_color;
            core.color[1] = core_color;
        }
        func_00280B90(&core, 0, 0);
        core.vertex[0].quadword = core.vertex[2].quadword;
        core.vertex[1].quadword = core.vertex[3].quadword;
        next++;
        current++;
    }
    segment_vector = &segment;
    offset_vector = &offset;
    edge_vector = &edge;
    normal_vector = &normal;
    for (i = 0; i < last; i++) {
        current = points;
        points++;
        next = points;
        func_00282CF0(&radial_first, current, D_L02_001BA500);
        func_00282CF0(&radial_second, next, D_L02_001BA500);
        first_length = func_00282DF0(&radial_first);
        second_length = func_00282DF0(&radial_second);
        if (second_length < first_length) {
            if (second_length == 0.0f) radial_second.quadword = radial_first.quadword;
            else func_00282D30(&radial_second, &radial_second, first_length / second_length);
        } else if (first_length == 0.0f) radial_first.quadword = radial_second.quadword;
        else func_00282D30(&radial_first, &radial_first, second_length / first_length);
        func_00282CC0(&first, D_L02_001BA500, &radial_first);
        func_00282CC0(&second, D_L02_001BA500, &radial_second);
        func_00282CF0(segment_vector, &second, &first);
        func_00282D30(offset_vector, segment_vector, inset);
        func_00282CF0(&first, &first, offset_vector);
        func_00282CC0(&second, &second, offset_vector);
        func_00282CF0(edge_vector, D_L02_001BA500, &first);
        func_00282DD8(normal_vector, edge_vector, segment_vector);
        length = func_00282DF0(normal_vector);
        if (length != 0.0f) length = 1.0f / length;
        func_00282D30(&scaled_normal, normal_vector, width * length);
        func_00282CC0(&outer.vertex[0], &first, &scaled_normal);
        func_00282CF0(&outer.vertex[1], &first, &scaled_normal);
        func_00282CC0(&outer.vertex[2], &second, &scaled_normal);
        func_00282CF0(&outer.vertex[3], &second, &scaled_normal);
        if (i == 0) {
            outer.color[0] = D_L02_001B0C74;
            outer.color[1] = D_L02_001B0C74;
        } else if (i == count - 2) {
            outer.color[2] = D_L02_001B0C74;
            outer.color[3] = D_L02_001B0C74;
        } else if (i == 1) {
            outer.color[1] = outer_color;
            outer.color[0] = outer_color;
        }
        func_00280B90(&outer, 0, 0);
    }
    func_002FC560(0x47, 0x5360BULL);
}
