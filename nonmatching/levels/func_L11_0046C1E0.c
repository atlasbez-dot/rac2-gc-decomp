/* Retained readable reconstruction; NOT MATCHING and no exact-C credit.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -g
 * Fresh local measure: 1508/1520 bytes; 0/2 USA v1.01 placements; frame 0x250 versus 0x260.
 * Evidence: Approved full 16-byte ray and packet transfers are retained. Color globals are read after their texture getters, matching retail sequencing; masks use unsigned 32-bit shifts. All three FP slots remain declared, with incoming F12 unused. Packet/local and saved-register allocation differ.
 * Reopen: Reopen with measured packet/loop lifetime evidence while retaining the two complete 144-byte packets and 64-bit texture/state values.
 * Older notes below are historical. Equal size and allocator diagnostics do
 * not establish relocation/binding qualification or linked equality.
 */
#include "common.h"

/* 1508/1520; us/us2/pal 0/2 each.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -g.
 * Both ribbon passes, depth equalization and edge fades are reconstructed. Retail uses full lq/sq copies in the zero-distance paths; the decompiler lost their upper words. Caller confirms three FP inputs; incoming f12 is unused while the primary width is reloaded globally. Packet/template allocation differs. Reopen with original source lifetimes.
 */
typedef int TI128 __attribute__((mode(TI)));
typedef union { TI128 q; float f[4]; } TrailVector;
struct TrailQuad { TrailVector position[4]; u32 color[4]; float uv[4][2]; u64 clear, texture, giftag, flags; };
extern float D_L11_001BA8C0[4];
extern float D_L11_001B2600 __attribute__((sda));
extern u32 D_L11_001B2608 __attribute__((sda));
extern u32 D_L11_001B260C __attribute__((sda));
extern float D_L11_001B2610 __attribute__((sda));
extern int D_L11_001B2630 __attribute__((sda));
extern int D_L11_001B2634 __attribute__((sda));
extern long long func_0027C878(int);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282DD8(void *, void *, void *);
extern float func_00282DF0(void *);
extern void func_00282D30(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_00280B90(void *, void *, int);
extern void func_002FC560(u32, unsigned long long);

void func_L11_0046C1E0(TrailVector *points, int alpha0, int alpha1, int count, float unusedWidth, float width, float stretch) {
    struct TrailQuad narrow, wide;
    TrailVector view, direction, side, scaled, viewA, viewB, adjustedA, adjustedB, extension, toCamera;
    float length, inverse, lengthA, lengthB;
    u32 color0;
    u32 color1;
    int i;
    narrow.texture = func_0027C878(D_L11_001B2630);
    color0 = D_L11_001B2608 | ((u32)alpha0 << 24);
    narrow.flags = 0x8000000048ULL;
    narrow.giftag = 0xFF9000000260ULL;
    narrow.clear = 0;
    narrow.color[0] = color0; narrow.color[1] = color0;
    narrow.color[2] = color0; narrow.color[3] = color0;
    wide.texture = func_0027C878(D_L11_001B2634);
    color1 = D_L11_001B260C | ((u32)alpha1 << 24);
    wide.flags = narrow.flags;
    wide.giftag = narrow.giftag;
    wide.clear = narrow.clear;
    narrow.uv[0][0] = D_L11_001B2600; narrow.uv[0][1] = 0.0f;
    narrow.uv[1][0] = D_L11_001B2600; narrow.uv[1][1] = 1.0f;
    narrow.uv[2][0] = D_L11_001B2600 + 1.0f; narrow.uv[2][1] = 0.0f;
    narrow.uv[3][0] = D_L11_001B2600 + 1.0f; narrow.uv[3][1] = 1.0f;
    wide.color[0] = color1; wide.color[1] = color1;
    wide.color[2] = color1; wide.color[3] = color1;
    wide.uv[0][0] = 0.0f; wide.uv[0][1] = 0.0f;
    wide.uv[1][0] = 0.0f; wide.uv[1][1] = 1.0f;
    wide.uv[2][0] = 1.0f; wide.uv[2][1] = 0.0f;
    wide.uv[3][0] = 1.0f; wide.uv[3][1] = 1.0f;
    func_00282CF0(&view, &points[0], D_L11_001BA8C0);
    func_00282CF0(&direction, &points[1], &points[0]);
    func_00282DD8(&side, &direction, &view);
    length = func_00282DF0(&side);
    inverse = length;
    if (length != 0.0f)
        inverse = 1.0f / length;
    /* Retail reloads this global instead of consuming incoming f12. */
    func_00282D30(&side, &side, D_L11_001B2610 * inverse);
    func_00282CC0(&narrow.position[0], &points[0], &side);
    func_00282CF0(&narrow.position[1], &points[0], &side);
    for (i = 1; i < count - 1; i++) {
        func_00282CF0(&view, &points[i], D_L11_001BA8C0);
        func_00282CF0(&direction, &points[i + 1], &points[i]);
        func_00282DD8(&side, &direction, &view);
        length = func_00282DF0(&side);
        inverse = length;
        if (length != 0.0f)
            inverse = 1.0f / length;
        func_00282D30(&side, &side, D_L11_001B2610 * inverse);
        func_00282CC0(&narrow.position[2], &points[i], &side);
        func_00282CF0(&narrow.position[3], &points[i], &side);
        if (i == 1) {
            narrow.color[0] = D_L11_001B2608;
            narrow.color[1] = D_L11_001B2608;
        } else if (i == count - 2) {
            narrow.color[2] = D_L11_001B2608;
            narrow.color[3] = D_L11_001B2608;
        } else if (i == 2) {
            narrow.color[0] = color0;
            narrow.color[1] = color0;
        }
        func_00280B90(&narrow, 0, 0);
        qcopy(&narrow.position[0], &narrow.position[2]);
        qcopy(&narrow.position[1], &narrow.position[3]);
    }
    for (i = 0; i < count - 2; i++) {
        func_00282CF0(&viewA, &points[i], D_L11_001BA8C0);
        func_00282CF0(&viewB, &points[i + 1], D_L11_001BA8C0);
        lengthA = func_00282DF0(&viewA);
        lengthB = func_00282DF0(&viewB);
        if (lengthB < lengthA) {
            if (lengthB == 0.0f)
                qcopy(&viewB, &viewA);
            else
                func_00282D30(&viewB, &viewB, lengthA / lengthB);
        } else if (lengthA == 0.0f) {
            qcopy(&viewA, &viewB);
        } else {
            func_00282D30(&viewA, &viewA, lengthB / lengthA);
        }
        func_00282CC0(&adjustedA, D_L11_001BA8C0, &viewA);
        func_00282CC0(&adjustedB, D_L11_001BA8C0, &viewB);
        func_00282CF0(&direction, &adjustedB, &adjustedA);
        func_00282D30(&extension, &direction, stretch);
        func_00282CF0(&adjustedA, &adjustedA, &extension);
        func_00282CC0(&adjustedB, &adjustedB, &extension);
        func_00282CF0(&toCamera, D_L11_001BA8C0, &adjustedA);
        func_00282DD8(&side, &toCamera, &direction);
        length = func_00282DF0(&side);
        inverse = length;
        if (length != 0.0f)
            inverse = 1.0f / length;
        func_00282D30(&scaled, &side, width * inverse);
        func_00282CC0(&wide.position[0], &adjustedA, &scaled);
        func_00282CF0(&wide.position[1], &adjustedA, &scaled);
        func_00282CC0(&wide.position[2], &adjustedB, &scaled);
        func_00282CF0(&wide.position[3], &adjustedB, &scaled);
        if (i == 0) {
            wide.color[0] = D_L11_001B260C;
            wide.color[1] = D_L11_001B260C;
        } else if (i == count - 3) {
            wide.color[2] = D_L11_001B260C;
            wide.color[3] = D_L11_001B260C;
        } else if (i == 1) {
            wide.color[0] = color1;
            wide.color[1] = color1;
        }
        func_00280B90(&wide, 0, 0);
    }
    func_002FC560(0x47, 0x5360BULL);
}
