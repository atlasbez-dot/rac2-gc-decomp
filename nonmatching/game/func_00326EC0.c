/* func_00326EC0 (376 B, boot only), M31 26 Oct 2026: 380 of 376 bytes as src/game/00326EC0-g8.c
   (default -G8, sda floats, sda incomplete D_001B27B0 so its la stays in the loop). Left:
   register numbering (retail out=s0, i=s1, self=s3) and the loop head: retail computes
   i<4 before the label and again in the bnel slot, and bumps i after the conditional call. */
#include "include_asm.h"
#include "common.h"

typedef int TI __attribute__((mode(TI)));

extern f32 D_001B0108 __attribute__((sda));
extern f32 D_001B010C __attribute__((sda));
extern f32 D_001B27B0[] __attribute__((sda));
extern f32 D_0022AFA0[][4];

extern void func_00282CC0(void *, void *, void *);
extern void func_00282D30(void *, void *, float);
extern void func_00282F20(void *, void *, float);

void func_00326EC0(u8 *self) {
    f32 axis[4][4] __attribute__((aligned(16)));
    f32 tmp[4] __attribute__((aligned(16)));
    f32 end[4] __attribute__((aligned(16)));
    f32 (*out)[4] = D_0022AFA0;
    f32 *pos;
    s32 i;

    qcopy(axis[0], self + 0xC0);
    qcopy(axis[3], self + 0xD0);
    func_00282D30(axis[1], axis[0], -1.0f);
    func_00282D30(axis[2], axis[3], -1.0f);
    qcopy(D_0022AFA0[4], axis[0]);
    qcopy(D_0022AFA0[5], axis[1]);
    qcopy(D_0022AFA0[6], axis[2]);
    qcopy(D_0022AFA0[7], axis[3]);
    pos = (f32 *)(self + 0x10);
    for (i = 0; i < 8; i++) {
        if (i < 4) {
            func_00282CC0(*out, axis[i >> 1], axis[2 + (i & 1)]);
        }
        func_00282F20(*out, *out, D_001B010C);
        func_00282CC0(*out, *out, pos);
        func_00282F20(tmp, D_001B27B0, -D_001B0108);
        func_00282CC0(*out, *out, tmp);
        out++;
        func_00282CC0(end, tmp, pos);
    }
}
