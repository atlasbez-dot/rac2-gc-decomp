/* func_L14_004272D8 (380 B, levels 14, 16, 26), M31 26 Oct 2026: size matches as
   L14_004272D8-g32.c with -O2 -G32 -Wa,-G32 -ffunction-sections (the 16- and 32-byte sda
   tables). Register numbering only: retail keeps kind in $s6 and forms kind<<2 late; cc1
   gives kind $s2 and shifts it early. Queued for the permuter. */
#include "include_asm.h"
#include "common.h"

extern f32 D_L14_001B1820[2] __attribute__((sda));
extern s32 D_L14_001B1828[2] __attribute__((sda));
extern s32 D_L14_001B1830[4] __attribute__((sda));
extern f32 D_L14_001B1840 __attribute__((sda));
extern f32 D_L14_001B1850[2][4] __attribute__((sda));

extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282D30(void *, void *, float);
extern void func_00283098(void *, void *, void *);
extern float func_00283CE0(int);
extern int func_002A77E0(int);
extern int func_002A7820(int, int);
extern float func_002A7878(float, float);
extern void *func_002C3150(void *, void *, int, int, int, int, float);

void func_L14_004272D8(u8 *self) {
    f32 pos[4] __attribute__((aligned(16)));
    f32 step[4] __attribute__((aligned(16)));
    s32 side;
    s32 kind;
    s32 n;

    side = func_002A77E0(2);
    kind = 1;
    if (!(func_002A7878(0.0f, 1.0f) < D_L14_001B1840)) {
        kind = 0;
    }
    n = func_002A7820(D_L14_001B1830[kind * 2], D_L14_001B1830[kind * 2 + 1]);
    func_00283098(pos, D_L14_001B1850[side], self + 0xC0);
    func_00282CC0(pos, pos, self + 0x10);
    func_00282CF0(step, D_L14_001B1850[(side + 1) & 1], D_L14_001B1850[side]);
    func_00283098(step, step, self + 0xC0);
    func_00282D30(step, step, 1.0f / func_00283CE0(n));
    func_002C3150(pos, step, D_L14_001B1828[kind], n & 0xFF, func_002A77E0(0xFF) & 0xFF, 0, D_L14_001B1820[kind]);
}
