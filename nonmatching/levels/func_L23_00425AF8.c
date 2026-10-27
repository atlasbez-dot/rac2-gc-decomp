/* Retained C reconstruction; not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections -g.
 * Compiled 1488 bytes; retail 1516 bytes.
 * us: 0/1 placements match (exit 1).
 * us2: 0/1 placements match (exit 1).
 * pal: 0/1 placements match (exit 1).
 * Remaining: Shared qcopy transfers reach 1488 bytes, up from 1464. Both 144-byte packets and
 * ten complete vector temporaries are retained, with the debug profile that reproduces division
 * padding. Loop-1 pointer spills/rematerialization and loop-2 adjacent-point lifetimes still
 * differ.
 * Reopen: Independent adjacent-point and vector-copy lifetime evidence that reproduces the two
 * loop allocation graphs.
 */

#include "common.h"
typedef int TI16 __attribute__((mode(TI)));

typedef struct {
    TI16 v[4];
    s32 col[4];
    float uv[8];
    u64 f70;
    u64 tex;
    u64 f80;
    u64 f88;
} Quad_00425AF8;

extern s32 D_L23_001B19DC __attribute__((sda));
extern float D_L23_001BA640[];

extern u64 func_0027C878(s32);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282DD8(void *, void *, void *);
extern float func_00282DF0(void *);
extern void func_00282D30(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_00280B90(void *, s32, s32);
extern void func_002FC560(s32, u64);

void func_L23_00425AF8(TI16 *pts, s32 a, s32 b, s32 c, float x, float y, float z, s32 d, s32 e) {
    Quad_00425AF8 A;
    Quad_00425AF8 B;
    float n[4];
    float v130[4];
    float v140[4];
    float v150[4];
    float v160[4];
    float v170[4];
    float v180[4];
    float v190[4];
    float v1A0[4];
    float v1B0[4];
    s32 i;
    s32 colA;
    s32 colB;
    float l0;
    float l1;
    float la;
    float lb;
    float l3;

    A.tex = func_0027C878(D_L23_001B19DC);
    colA = d | (a << 24);
    A.f88 = 0x8000000048LL;
    A.f80 = 0xFF9000000260LL;
    A.f70 = 0;
    A.col[3] = colA;
    A.col[2] = colA;
    A.col[1] = colA;
    A.col[0] = colA;
    B.tex = func_0027C878(16);
    colB = e | (b << 24);
    B.f88 = A.f88;
    B.f80 = A.f80;
    B.f70 = A.f70;
    B.col[3] = colB;
    B.col[2] = colB;
    B.col[1] = colB;
    B.col[0] = colB;
    B.uv[0] = 0.0f;
    B.uv[1] = 0.0f;
    B.uv[2] = 0.0f;
    B.uv[3] = 1.0f;
    B.uv[4] = 1.0f;
    B.uv[5] = 0.0f;
    B.uv[6] = 1.0f;
    B.uv[7] = 1.0f;
    A.uv[0] = 0.0f;
    A.uv[1] = 0.0f;
    A.uv[2] = 0.0f;
    A.uv[3] = 1.0f;
    A.uv[4] = 1.0f;
    A.uv[5] = 0.0f;
    A.uv[6] = 1.0f;
    A.uv[7] = 1.0f;
    func_00282CF0(v140, &pts[0], D_L23_001BA640);
    func_00282CF0(v150, &pts[1], &pts[0]);
    func_00282DD8(n, v150, v140);
    l0 = func_00282DF0(n);
    if (l0 != 0.0f) {
        l0 = 1.0f / l0;
    }
    func_00282D30(n, n, x * l0);
    func_00282CC0(&A.v[0], &pts[0], n);
    func_00282CF0(&A.v[1], &pts[0], n);
    for (i = 1; i < c - 1; i++) {
        func_00282CF0(v140, &pts[i], D_L23_001BA640);
        func_00282CF0(v150, &pts[i + 1], &pts[i]);
        func_00282DD8(n, v150, v140);
        l1 = func_00282DF0(n);
        if (l1 != 0.0f) {
            l1 = 1.0f / l1;
        }
        func_00282D30(n, n, x * l1);
        func_00282CC0(&A.v[2], &pts[i], n);
        func_00282CF0(&A.v[3], &pts[i], n);
        if (i == 1) {
            A.col[1] = d;
            A.col[0] = d;
        } else if (i == c - 2) {
            A.col[3] = d;
            A.col[2] = d;
        } else if (i == 2) {
            A.col[1] = colA;
            A.col[0] = colA;
        }
        func_00280B90(&A, 0, 0);
        qcopy(&A.v[0],&A.v[2]);
        qcopy(&A.v[1],&A.v[3]);
    }
    for (i = 0; i < c - 1; i++) {
        func_00282CF0(v180, &pts[i], D_L23_001BA640);
        func_00282CF0(v190, &pts[i + 1], D_L23_001BA640);
        la = func_00282DF0(v180);
        lb = func_00282DF0(v190);
        if (lb < la) {
            if (lb == 0.0f) {
                qcopy(v190 ,v180);
            } else {
                func_00282D30(v190, v190, la / lb);
            }
        } else {
            if (la == 0.0f) {
                qcopy(v180 ,v190);
            } else {
                func_00282D30(v180, v180, lb / la);
            }
        }
        func_00282CC0(v160, D_L23_001BA640, v180);
        func_00282CC0(v170, D_L23_001BA640, v190);
        func_00282CF0(v150, v170, v160);
        func_00282D30(v1B0, v150, z);
        func_00282CF0(v160, v160, v1B0);
        func_00282CC0(v170, v170, v1B0);
        func_00282CF0(v1A0, D_L23_001BA640, v160);
        func_00282DD8(n, v1A0, v150);
        l3 = func_00282DF0(n);
        if (l3 != 0.0f) {
            l3 = 1.0f / l3;
        }
        func_00282D30(v130, n, y * l3);
        func_00282CC0(&B.v[0], v160, v130);
        func_00282CF0(&B.v[1], v160, v130);
        func_00282CC0(&B.v[2], v170, v130);
        func_00282CF0(&B.v[3], v170, v130);
        if (i == 0) {
            B.col[1] = e;
            B.col[0] = e;
        } else if (i == c - 2) {
            B.col[3] = e;
            B.col[2] = e;
        } else if (i == 1) {
            B.col[1] = colB;
            B.col[0] = colB;
        }
        func_00280B90(&B, 0, 0);
    }
    func_002FC560(0x47, 0x5360B);
}
