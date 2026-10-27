/* Retained near miss, 26 October 2026 (fam5to9, F8 seed; shared by 27 levels). Not linked.
 * Profile: -O2 -G8 -ffunction-sections (the copy helpers come from common.h).
 * 1480/1488 bytes, 361/372 opcodes. Changes since the 25 October draft: packet colour stores
 * written in retail order (this cc1 keeps source order for these), the inverse length in its own
 * local, the first loop's bound as count - 1 with `segments` set before the second loop, the
 * second loop with its own next pointer (retail keeps current spilled and next in a saved
 * register), the first segment's points+1 in its own local.
 * Residual: parameter registers (retail points $s6/colour $s4, width $f22/extend $f23; these
 * flip between drafts), the first loop's current/next copies ($s0 = copy of points+1, $s1),
 * the loop-invariant spill set of the second loop, two instructions short in loop setup.
 * Reopen with a greg priority comparison (alloc.py) for the parameter pseudos.
 */
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
    core.color[3] = coreColor; core.color[2] = coreColor;
    core.color[1] = coreColor; core.color[0] = coreColor;
    halo.texture = func_0027C878(D_L00_001AF398);
    halo.flags = core.flags; halo.mode = core.mode; halo.primitive = core.primitive;
    haloColor = outerColor;
    halo.color[3] = haloColor; halo.color[2] = haloColor;
    halo.color[1] = haloColor; halo.color[0] = haloColor;
    halo.uv[0] = 0; halo.uv[1] = 0; halo.uv[2] = 0; halo.uv[3] = 1;
    halo.uv[4] = 1; halo.uv[5] = 0; halo.uv[6] = 1; halo.uv[7] = 1;
    core.uv[0] = D_L00_001AF33C; core.uv[1] = 0; core.uv[2] = D_L00_001AF33C; core.uv[3] = 1;
    core.uv[4] = D_L00_001AF33C + 1.0f; core.uv[5] = 0; core.uv[6] = D_L00_001AF33C + 1.0f; core.uv[7] = 1;
    { Vector *second = points + 1;
    func_00282CF0(&eye, points, D_L00_001B8DC0);
    func_00282CF0(&tangent, second, points);
    func_00282DD8(&normal, &tangent, &eye);
    { float l = func_00282DF0(&normal);
    if (l != 0) l = 1.0f / l;
    func_00282D30(&normal, &normal, D_L00_001AF358 * l); }
    func_00282CC0(&core.vertex[0], points, &normal);
    func_00282CF0(&core.vertex[1], points, &normal);
    current = second; }
    for (i = 1, next = points + 2; i < count - 1; i++, current++, next++) {
        func_00282CF0(&eye, current, D_L00_001B8DC0);
        func_00282CF0(&tangent, next, current);
        func_00282DD8(&normal, &tangent, &eye);
        length = func_00282DF0(&normal);
        if (length != 0) length = 1.0f / length;
        func_00282D30(&normal, &normal, D_L00_001AF358 * length);
        func_00282CC0(&core.vertex[2], current, &normal);
        func_00282CF0(&core.vertex[3], current, &normal);
        if (i == 1) { core.color[1] = D_L00_001AF344; core.color[0] = D_L00_001AF344; }
        else if (i == count - 2) { core.color[3] = D_L00_001AF344; core.color[2] = D_L00_001AF344; }
        else if (i == 2) { core.color[1] = coreColor; core.color[0] = coreColor; }
        func_00280B90(&core, 0, 0);
        qcopy(&core.vertex[0], &core.vertex[2]); qcopy(&core.vertex[1], &core.vertex[3]);
    }
    segments = count - 1;
    for (i = 0, current = points; i < segments; i++) {
        next = current + 1;
        func_00282CF0(&firstRay, current, D_L00_001B8DC0);
        func_00282CF0(&lastRay, next, D_L00_001B8DC0);
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
        if (i == 0) { halo.color[1] = D_L00_001AF348; halo.color[0] = D_L00_001AF348; }
        else if (i == count - 2) { halo.color[3] = D_L00_001AF348; halo.color[2] = D_L00_001AF348; }
        else if (i == 1) { halo.color[1] = haloColor; halo.color[0] = haloColor; }
        func_00280B90(&halo, 0, 0);
        current = next;
    }
    func_002FC560(0x47, 0x5360B);
}

