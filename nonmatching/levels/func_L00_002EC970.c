/* func_L00_002EC970 - 1652 bytes, 27 places. C draft (M26), not a match: the SPECIAL2 word
   0x700034A9 is `por`, the TImode zero of nearSize/farSize, reachable under
   -frac2-zero-ti-por (the unit profile used: -O2 -G0 -frac2-qcopy -frac2-qcopy-barrier
   -frac2-zero-ti-por). Structure follows retail (two func_L00_0038ADD0 strips laid along a
   polyline, func_00281DE8 setup, 0.75 narrowing, u stepping by du with a wrap at 1);
   1660/1652 B. What is left is register allocation and the spill layout: retail keeps
   &origin in $s1, the count in $fp and spills points, colour, colour|0x7F000000, count-1,
   count*16 and the two strips' point[3] addresses to 0x190..0x1A8. */
#include "include_asm.h"
#include "common.h"

typedef int Quadword __attribute__((mode(TI)));
typedef union { Quadword bits; float f[4]; } Vector4;
typedef struct {
    Vector4 point[4];
    unsigned int color[4];
    float uv[8];
    unsigned long tag, tex, alpha, test;
} Beam;

extern void func_00281DE8(void *, int, int, int);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282D30(void *, void *, float);
extern void func_00282F20(void *, void *, float);
extern void func_00282DD8(void *, void *, void *);
extern void func_002830C0(void *, void *, void *);
extern float func_002A7878(float, float);
extern int func_001163B0(void);
extern float func_00283CE0(int);
extern void func_00280B90(void *, void *, int);
extern Vector4 D_001B8DC0;

/* A beam along a polyline: the func_L00_0038ADD0 twin strips (cleared through
   func_00281DE8) laid segment by segment over the points, narrowing by 0.75 per joint, the
   strip's v coordinate stepping by du and wrapping at 1. */
void func_L00_002EC970(Vector4 *start, Vector4 *points, unsigned int color, int count, float u0, float du)
{
    Vector4 origin;
    Beam first, second;
    Vector4 basis[4], nearSize, farSize;
    float width, u, v;
    int i;

    origin.bits = start->bits;
    func_00281DE8(&first, 23, 1, 0x80);
    func_00281DE8(&second, 23, 1, 0x80);
    nearSize.bits = 0;
    farSize.bits = 0;
    first.color[0] = first.color[1] = color | 0x7F000000;
    second.color[0] = second.color[1] = color | 0x3F000000;
    nearSize.f[3] = 1;
    farSize.f[3] = 1;
    width = func_002A7878(0.2f, 0.45f);
    nearSize.f[2] = width;
    farSize.f[2] = width * 1.5f;
    if (!(func_001163B0() & 1)) {
        first.uv[0] = u0; first.uv[1] = 0; first.uv[2] = u0; first.uv[3] = 1;
        first.uv[4] = du + u0; first.uv[5] = 0; first.uv[6] = du + u0; first.uv[7] = 1;
        second.uv[0] = u0; second.uv[1] = 0; second.uv[2] = u0; second.uv[3] = 1;
        second.uv[4] = du + u0; second.uv[5] = 0; second.uv[6] = du + u0; second.uv[7] = 1;
    } else {
        first.uv[0] = u0; first.uv[1] = 1; first.uv[2] = u0; first.uv[3] = 0;
        first.uv[4] = du + u0; first.uv[5] = 1; first.uv[6] = du + u0; first.uv[7] = 0;
        second.uv[0] = u0; second.uv[1] = 1; second.uv[2] = u0; second.uv[3] = 0;
        second.uv[4] = du + u0; second.uv[5] = 1; second.uv[6] = du + u0; second.uv[7] = 0;
    }
    func_00282CF0(&basis[0], points, &origin); func_00282F20(&basis[0], &basis[0], 1);
    func_00282CF0(&basis[1], &D_001B8DC0, &origin); func_00282DD8(&basis[2], &basis[1], &basis[0]);
    func_00282F20(&basis[2], &basis[2], 1); func_00282DD8(&basis[1], &basis[0], &basis[2]);
    basis[3].bits = origin.bits;
    first.point[0].bits = nearSize.bits; second.point[0].bits = farSize.bits;
    func_00282D30(&first.point[1], &first, -1); func_00282D30(&second.point[1], &second, -1);
    func_002830C0(&first, &first, basis); func_002830C0(&first.point[1], &first.point[1], basis);
    func_002830C0(&second, &second, basis); func_002830C0(&second.point[1], &second.point[1], basis);
    for (i = 0; i < count - 1; i++) {
        func_00282CF0(&basis[0], &points[i + 1], &points[i]); func_00282F20(&basis[0], &basis[0], 1);
        func_00282CF0(&basis[1], &D_001B8DC0, &points[i]); func_00282DD8(&basis[2], &basis[1], &basis[0]);
        func_00282F20(&basis[2], &basis[2], 1); func_00282DD8(&basis[1], &basis[0], &basis[2]);
        basis[3].bits = points[i].bits;
        nearSize.f[2] *= 0.75f; farSize.f[2] = nearSize.f[2] * 1.5f;
        first.point[2].bits = nearSize.bits; second.point[2].bits = farSize.bits;
        func_00282D30(&first.point[3], &first.point[2], -1); func_00282D30(&second.point[3], &second.point[2], -1);
        func_002830C0(&first.point[2], &first.point[2], basis); func_002830C0(&first.point[3], &first.point[3], basis);
        func_002830C0(&second.point[2], &second.point[2], basis); func_002830C0(&second.point[3], &second.point[3], basis);
        first.color[3] = first.color[2] = color | 0x7F000000;
        second.color[3] = second.color[2] = color | 0x3F000000;
        u = func_00283CE0(i + 1) * du;
        v = u + du;
        if (u >= 1.0f) { u -= 1.0f; v -= 1.0f; }
        u += u0; v += u0;
        second.uv[2] = u; second.uv[6] = v;
        first.uv[0] = u; first.uv[2] = u; first.uv[4] = v; first.uv[6] = v;
        second.uv[0] = u; second.uv[4] = v;
        func_00280B90(&first, 0, 0); func_00280B90(&second, 0, 0);
        first.point[0].bits = first.point[2].bits; first.point[1].bits = first.point[3].bits;
        second.point[0].bits = second.point[2].bits; second.point[1].bits = second.point[3].bits;
    }
    basis[3].bits = points[count - 1].bits;
    nearSize.f[2] *= 0.75f; farSize.f[2] = nearSize.f[2] * 1.5f;
    first.point[2].bits = nearSize.bits; second.point[2].bits = farSize.bits;
    func_00282D30(&first.point[3], &first.point[2], -1); func_00282D30(&second.point[3], &second.point[2], -1);
    func_002830C0(&first.point[2], &first.point[2], basis); func_002830C0(&first.point[3], &first.point[3], basis);
    func_002830C0(&second.point[2], &second.point[2], basis); func_002830C0(&second.point[3], &second.point[3], basis);
    second.color[2] = first.color[3] = first.color[2] = second.color[3] = color;
    u = func_00283CE0(i + 1) * du;
    v = u + du;
    if (u >= 1.0f) { v -= 1.0f; u -= 1.0f; }
    v += u0; u += u0;
    second.uv[6] = v; second.uv[2] = u;
    first.uv[0] = u; first.uv[2] = u; first.uv[4] = v; first.uv[6] = v;
    second.uv[0] = u; second.uv[4] = v;
    func_00280B90(&first, 0, 0); func_00280B90(&second, 0, 0);
}
