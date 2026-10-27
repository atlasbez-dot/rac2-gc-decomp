/* func_L01_003CB540 (292 B, 1 place), M31 26 Oct 2026: size matches with
   src/levels/shared/L01_003CB540.c -O2 -G16 -ffunction-sections -mno-split-addresses -Wa,-G16.
   19 lines differ, all in the first 0x60 bytes: retail loads the packet pointer first, keeps
   the camera view base (la s0) late and unfolded, and loads the four floats 31D4..31E0 in
   ascending order before the pointer store. Rest of the body (packet words re-read through
   non-array stores, giftag, rgb, delay-slot $gp store) matches. */
#include "include_asm.h"
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

typedef struct {
    u8 pad000[0x218];
    f32 f218;
    f32 f21C;
    u8 pad220[0x228 - 0x220];
    f32 f228;
    f32 f22C;
    s32 r;
    s32 g;
    s32 b;
} L01View3CB540;

extern u8 *D_L01_001B2CC8;
extern TI128 D_L01_001B02A0 __attribute__((sda));
extern f32 D_L01_001B31D4;
extern f32 D_L01_001B31D8;
extern f32 D_L01_001B31DC;
extern f32 D_L01_001B31E0;
extern L01View3CB540 D_L01_001BD9C0;

extern void func_0027AB40(void);
extern void func_00279D18(void);
extern void func_L00_0037B7B0(void);

void func_L01_003CB540(void) {
    u64 *q;
    u8 *pkt;
    f32 f0, f1, f2, f3;
    L01View3CB540 *v = &D_L01_001BD9C0;

    f0 = D_L01_001B31D4; f1 = D_L01_001B31D8; f2 = D_L01_001B31DC; f3 = D_L01_001B31E0;
    pkt = D_L01_001B2CC8;
    *(TI128 *)pkt = D_L01_001B02A0;
    D_L01_001B2CC8 = pkt + 0x10;
    v->f218 = f0; v->f21C = f1; v->f228 = f2; v->f22C = f3;
    func_0027AB40();
    func_00279D18();
    *(u32 *)(D_L01_001B2CC8 + 0) = 0x10000002;
    *(u32 *)(D_L01_001B2CC8 + 4) = 0;
    *(u32 *)(D_L01_001B2CC8 + 8) = 0x11000000;
    *(u32 *)(D_L01_001B2CC8 + 12) = 0x50000002;
    D_L01_001B2CC8 += 0x10;
    q = (u64 *)D_L01_001B2CC8;
    q[0] = 0x1000000000008001ULL;
    q[1] = 0xE;
    q[2] = (u64)v->r | ((u64)v->g << 8) | ((u64)v->b << 16);
    q[3] = 0x3D;
    D_L01_001B2CC8 = (u8 *)(q + 4);
    func_L00_0037B7B0();
}
