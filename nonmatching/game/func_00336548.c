/* func_00336548 (392 B, 28 places), M31 26 Oct 2026: size matches with
   -O2 -G0 -ffunction-sections -ffast-math (min.s needs fast-math). About 50 lines differ:
   register choice (bar in $s1, bottom in $s0), min.s operand order, cvt.w.s order of x/y,
   and where size[1] is added; the $gp frame counter is -0x1608 in boot (0x1AD9E8). */
#include "common.h"

typedef struct {
    f32 *pos;
    f32 *size;
    u8 pad08[4];
    u32 *colors;
    f32 *value;
    u8 pad14[0x3C - 0x14];
    u32 max;
    u8 pad40[4];
    u32 back;
} Bar336548;

extern s32 D_001AD9E8 __attribute__((sda));

extern void func_0027EAE8(int, int, int, int, int, void *);

void func_00336548(Bar336548 *bar) {
    u32 c[2];
    f32 *size;
    f32 x;
    f32 y;
    f32 w;
    f32 m;
    s32 z;
    s32 bottom;

    if (*bar->value == 0.0f) {
        return;
    }
    x = bar->pos[0];
    y = bar->pos[1];
    z = D_001AD9E8;
    size = bar->size;
    m = bar->max;
    size[0] = size[0] < m ? size[0] : m;
    w = bar->size[0];
    c[0] = bar->back;
    c[1] = bar->back;
    bottom = y + bar->size[1];
    func_0027EAE8(x, y, x + (f32)bar->max, bottom, z, c);
    c[0] = bar->colors[0];
    c[1] = bar->colors[1];
    func_0027EAE8(x, y, x + w, bottom, z, c);
}
