/* Nonmatching reconstruction checked 23 October 2026.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Final check.py coverage: us 0/27, us2 0/27, pal 0/27; no candidate.
 * Three source forms: manual typed draw packet, scoped ring alpha, and named subobject views. Final 1788/1784. Ring-alpha scope fixed early FPR allocation; subobject views did not resolve the remaining mismatch and were removed.
 * Remaining: Quad/workspace pointer spills, UV store ordering, scalar lifetimes and scheduling differ. Similar size does not establish a match.
 * Reopen with an equivalent packet/workspace lifetime model and a measured drawing-loop witness.
 * Historical screening below is preserved, not treated as acceptance evidence.
 */

/* func_L00_003A6538 - 1784 bytes, 27 place(s), level 00_aranos_tutorial,
   retail at 0x003a6538. Screened with tools/w10_screen.py: 75 call(s)
   [func_002AFFD8@003A6590, func_00282CF0@003A65AC, func_00282F20@003A65BC,
   func_00283CE0@003A6614, func_00281DE8@003A6630, func_00283CF0@003A6644,
   func_00282D30@003A669C, func_00282CC0@003A66AC, func_002AB668@003A66BC,
   func_002ACDE8@003A66CC, func_00282DD8@003A66DC, func_00282F20@003A66EC,
   func_00282CC0@003A66FC, func_00282CF0@003A670C, func_00282D30@003A6724,
   func_00282CC0@003A6734, func_00282CC0@003A6744, func_00282CF0@003A6754,
   func_00280B90@003A6764, func_002AB668@003A6784, func_002ACDE8@003A6794,
   func_00283CE0@003A67C0, func_00283B98@003A67E0, func_00283B98@003A67F4,
   func_00281DE8@003A680C, func_00283CF0@003A681C, func_00282D30@003A6880,
   func_00282CC0@003A6890, func_00282CF0@003A68A0, func_00282F20@003A68B0,
   func_002AB668@003A68C0, func_00282DD8@003A68D0, func_00282DD8@003A68E0,
   func_002ACDE8@003A68F0, func_00282F20@003A6914, func_00282DD8@003A6924,
   func_00282F20@003A6934, func_00282CC0@003A6944, func_00282CC0@003A6954,
   func_00282CF0@003A6964, func_00282CF0@003A6974, func_00282CC0@003A6984,
   func_00282CF0@003A6994, func_00280B90@003A69A4, func_002AB668@003A69B4,
   func_002ACDE8@003A69C4, func_00282D30@003A69D4, func_00282DD8@003A69E4,
   func_00282F20@003A69F4, func_00282CC0@003A6A04, func_00282CC0@003A6A14,
   func_00282CF0@003A6A24, func_00282CF0@003A6A34, func_00282CC0@003A6A44,
   func_00282CF0@003A6A54, func_00280B90@003A6A64, func_00283CE0@003A6A78,
   func_00281DE8@003A6A94, func_00283CF0@003A6AA8, func_00282D30@003A6ADC,
   func_00282CC0@003A6AEC, func_00282DD8@003A6AFC, func_00282F20@003A6B0C,
   func_00282DD8@003A6B1C, func_00282F20@003A6B2C, func_00282CC0@003A6B3C,
   func_00282CC0@003A6B4C, func_00282CF0@003A6B5C, func_00282CF0@003A6B6C,
   func_00282CC0@003A6B7C, func_00282CF0@003A6B8C, func_00280B90@003A6B9C,
   func_00283CF0@003A6BA8, func_002FC560@003A6BCC, func_0027DE50@003A6BEC];
   data addresses materialised [0x1c0000, 0x200000, 0x3f490000, 0x1c0000,
   0x3c8e0000, 0x800000, 0x800000, 0xbdcc0000, 0x1a0000]; float constants
   [0x3f800000, 0x437f0000, 0x3f000000, 0x3f800000, 0x41a00000, 0xc1800000,
   0x41800000, 0x437f0000]; $gp-relative small data: no   saves: -; callee-
   saved registers saved [-]; words plain C cannot emit [LQ/SQ
   78620000@0x0044, LQ/SQ 7E420000@0x0048]. Head: addiu $sp, $sp, -0x1F0 ;
   sd $s2, 0x190($sp) ; sd $s0, 0x180($sp) ; addiu $s2, $sp, 0x90 ; sd $s1,
   0x188($sp) ; sd $s3, 0x198($sp). Not matched in this wave: the 128-bit
   copy needs an `lq`/`sq` pair; plain C reaches it only through a
   `mode(TI)` local, and this cc1 folds the destination offset into the `sq`
   where retail materialises the pointer first. What would unblock it: the
   exact source expression tree, so this cc1 picks the same registers in the
   same order. */

#include "common.h"
typedef int VectorBits __attribute__((mode(TI)));
typedef struct { u8 pad[0x70]; long f70, f78, f80, f88; } QuadPacket;
typedef struct { float vertex[4][4]; unsigned int color[4]; float uv[4][2]; long registers[4]; } EffectQuad;
extern float D_L00_001B8DC0[4];
extern short D_001A65D0 NOT_SDA, D_001A65D2 NOT_SDA;
extern float D_L00_001AF694 __attribute__((sda));
extern float D_L00_001AF698 __attribute__((sda));
extern float D_L00_001AF69C __attribute__((sda));
extern float D_L00_001AF6A0 __attribute__((sda));
extern float D_L00_001AF6A4 __attribute__((sda));
extern float D_L00_001AF6A8 __attribute__((sda));
extern float D_L00_001AF6AC __attribute__((sda));
extern float D_L00_001AF6B0 __attribute__((sda));
extern float D_L00_001AF6B8 __attribute__((sda));
extern void func_002AFFD8(char *, char *, int);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern float func_00283CE0(int);
extern void func_00281DE8(QuadPacket *, int, int, int);
extern int func_00283CF0(float);
extern void func_00282D30(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_002AB668(void *, int, float);
extern void func_002ACDE8(void *, void *, void *);
extern void func_00282DD8(void *, void *, void *);
extern void func_00280B90(void *, int, int);
extern float func_00283B98(float, float);
extern void func_002FC560(unsigned int, unsigned long long);
extern void func_0027DE50(int, int, int, int, long);

/* Draw the beam's ring, crossing core planes and terminal flash. */
void func_L00_003A6538(void *object)
{
    char *moby = object;
    EffectQuad quad;
    float position[4], normal[4], view[4], radius[4], center[4], rotation[4];
    float spoke[4], side[4], up[4], horizontal[4], vertical[4], corner[4], temporary[4];
    char *state = *(char **)(moby + 0x68);
    float alpha, scale;
    unsigned int color;
    int i;
    *(VectorBits *)position = *(VectorBits *)(state + 0x10);
    func_002AFFD8((char *)position, (char *)normal, 1);
    func_00282CF0(view, D_L00_001B8DC0, position);
    func_00282F20(view, view, 1.0f);
    if (*(short *)(state + 8)) {
        float ringAlpha = func_00283CE0(*(short *)(state + 8)) * *(float *)(state + 0x20);
        func_00281DE8((QuadPacket *)&quad, 11, 1, 0x80);
        color = (func_00283CF0(ringAlpha * 255.0f) << 24) | 0x2040FF;
        quad.color[0] = quad.color[1] = quad.color[2] = quad.color[3] = color;
        quad.uv[0][0] = quad.uv[1][0] = 0.5f;
        quad.uv[0][1] = 0.0f; quad.uv[1][1] = 1.0f;
        quad.uv[2][0] = 1.0f; quad.uv[2][1] = 0.0f;
        quad.uv[3][0] = 1.0f; quad.uv[3][1] = 1.0f;
        func_00282D30(radius, normal, D_L00_001AF694);
        func_00282CC0(center, position, radius);
        func_002AB668(rotation, (int)view, *(float *)(state + 0xC));
        func_002ACDE8(radius, radius, rotation);
        for (i = 0; i < 8; i++) {
            func_00282DD8(spoke, view, radius);
            func_00282F20(spoke, spoke, D_L00_001AF698);
            func_00282CC0(quad.vertex[0], position, spoke);
            func_00282CF0(quad.vertex[1], position, spoke);
            func_00282D30(spoke, spoke, D_L00_001AF69C / D_L00_001AF698);
            func_00282CC0(side, position, radius);
            func_00282CC0(quad.vertex[2], side, spoke);
            func_00282CF0(quad.vertex[3], side, spoke);
            func_00280B90(&quad, 0, 0);
            if (i < 7) {
                func_002AB668(rotation, (int)view, 0.7853981853f);
                func_002ACDE8(radius, radius, rotation);
            }
        }
    }
    alpha = func_00283CE0(*(short *)(state + 10)) * *(float *)(state + 0x24);
    *(float *)(state + 0x28) = func_00283B98(*(float *)(state + 0x28), D_L00_001AF6A8 * 0.017453294f);
    *(float *)(state + 0x2C) = func_00283B98(*(float *)(state + 0x2C), D_L00_001AF6AC * 0.017453294f);
    func_00281DE8((QuadPacket *)&quad, 0x38, 1, 0x80);
    color = (func_00283CF0(alpha * 20.0f) << 24) | 0x8080FF;
    quad.color[0] = quad.color[1] = quad.color[2] = quad.color[3] = color;
    quad.uv[0][0] = quad.uv[0][1] = quad.uv[1][0] = 0.0f;
    quad.uv[1][1] = quad.uv[2][0] = quad.uv[3][0] = quad.uv[3][1] = 1.0f;
    quad.uv[2][1] = 0.0f;
    func_00282D30(radius, state + 0x30, alpha * -16.0f + 16.0f);
    func_00282CC0(center, position, radius);
    func_00282CF0(rotation, D_L00_001B8DC0, center);
    func_00282F20(rotation, rotation, 1.0f);
    func_002AB668(spoke, (int)rotation, *(float *)(state + 0x28));
    func_00282DD8(side, rotation, normal);
    func_00282DD8(up, side, rotation);
    func_002ACDE8(horizontal, up, spoke);
    scale = D_L00_001AF6A4 + (D_L00_001AF6A0 - D_L00_001AF6A4) * alpha;
    func_00282F20(horizontal, horizontal, scale);
    func_00282DD8(vertical, rotation, horizontal);
    func_00282F20(vertical, vertical, scale);
    func_00282CC0(corner, center, horizontal);
    func_00282CC0(quad.vertex[0], corner, vertical);
    func_00282CF0(quad.vertex[1], corner, vertical);
    func_00282CF0(corner, center, horizontal);
    func_00282CC0(quad.vertex[2], corner, vertical);
    func_00282CF0(quad.vertex[3], corner, vertical);
    func_00280B90(&quad, 0, 0);
    func_002AB668(spoke, (int)rotation, *(float *)(state + 0x2C));
    func_002ACDE8(horizontal, up, spoke);
    func_00282D30(horizontal, horizontal, scale);
    func_00282DD8(vertical, rotation, horizontal);
    func_00282F20(vertical, vertical, scale);
    func_00282CC0(corner, center, horizontal);
    func_00282CC0(quad.vertex[0], corner, vertical);
    func_00282CF0(quad.vertex[1], corner, vertical);
    func_00282CF0(corner, center, horizontal);
    func_00282CC0(quad.vertex[2], corner, vertical);
    func_00282CF0(quad.vertex[3], corner, vertical);
    func_00280B90(&quad, 0, 0);
    if (*(int *)(state + 0x40)) {
        alpha = func_00283CE0(*(int *)(state + 0x40)) * *(float *)(state + 0x44);
        func_00281DE8((QuadPacket *)&quad, 11, 4, 0x80);
        color = (func_00283CF0(alpha * 255.0f) << 24) | 0x808080;
        quad.color[0] = quad.color[1] = quad.color[2] = quad.color[3] = color;
        func_00282D30(temporary, view, -0.1f);
        func_00282CC0(center, D_L00_001B8DC0, temporary);
        func_00282DD8(vertical, view, normal);
        func_00282F20(vertical, vertical, D_L00_001AF6B0);
        func_00282DD8(horizontal, vertical, view);
        func_00282F20(horizontal, horizontal, D_L00_001AF6B0);
    func_00282CC0(corner, center, horizontal);
    func_00282CC0(quad.vertex[0], corner, vertical);
    func_00282CF0(quad.vertex[1], corner, vertical);
    func_00282CF0(corner, center, horizontal);
    func_00282CC0(quad.vertex[2], corner, vertical);
    func_00282CF0(quad.vertex[3], corner, vertical);
    func_00280B90(&quad, 0, 0);
        color = (func_00283CF0(D_L00_001AF6B8 * alpha) << 24) | 0x808080;
        quad.color[0] = quad.color[1] = quad.color[2] = quad.color[3] = color;
        func_002FC560(0x42, 0x48ULL);
        func_0027DE50(0, D_001A65D2, 0, D_001A65D0, (long)(int)quad.color[0]);
    }
}
