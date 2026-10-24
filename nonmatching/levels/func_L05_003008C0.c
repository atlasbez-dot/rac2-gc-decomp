/* 2026-10-23 reconstruction. Measured with -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-
   barrier -mno-split-addresses. us: 0/7 placements; 05_feltzin_system: 540 bytes, expected 564; us2:
   0/7 placements; 05_feltzin_system: 540 bytes, expected 564; pal: 0/7 placements; 05_feltzin_system:
   540 bytes, expected 564. Two profiles. Real 64-bit texture/color arguments and a full16-byte packet
   template are preserved. No-split restores the retail128-byte frame, but packet expression scheduling
   remains24bytes short. Reopen with a matching packed-coordinate expression tree. Historical screening
   is preserved below. */

/* func_L05_003008C0 - 564 bytes, 7 place(s), level 05_feltzin_system,
   retail at 0x003008c0. Screened with tools/w10_screen.py: 4 call(s)
   [func_00283CF0@00300930, func_00283CF0@0030094C, func_00283CF0@00300964,
   func_00283CF0@00300980]; data addresses materialised [0x1a0000, 0x1a0000,
   0x1a0000, 0x10000000, 0x1a0000, 0x50000000, 0x1b0000, 0x1b0000, 0x1b0000,
   0x1b0000, 0x1b0000, 0x1b0000, 0x1b0000, 0x1b0000, 0x1b0000]; float
   constants [0x41800000, 0x1b0000]; $gp-relative small data: no   saves: -;
   callee-saved registers saved [-]; words plain C cannot emit [LQ/SQ
   78820000@0x0144, LQ/SQ 7C620000@0x0148]. Head: addiu $sp, $sp, -0x80 ;
   swc1 $f22, 0x60($sp) ; swc1 $f20, 0x50($sp) ; lui $at, 0x4180 ; mtc1 $at,
   $f22 ; mov.s $f20, $f12. Not matched in this wave: the 128-bit copy needs
   an `lq`/`sq` pair; plain C reaches it only through a `mode(TI)` local,
   and this cc1 folds the destination offset into the `sq` where retail
   materialises the pointer first. What would unblock it: the exact source
   expression tree, so this cc1 picks the same registers in the same order. */

#include "common.h"
typedef int Quad __attribute__((mode(TI)));
extern int D_001A7350;
extern int D_001A7354;
extern u32 *D_L05_001B2C88;
extern Quad D_L05_001ACA80;
extern int func_00283CF0(float);
void func_L05_003008C0(float x,float y,float width,float height,int u,int v,int uw,int vh,u64 color,u64 texture)
{
    s64 left,right,top,bottom;
    u32 *header;
    u64 *packet;
    int u0,u1,v0,v1;
    left = func_00283CF0(x*16.0f)+D_001A7350-8;
    right = func_00283CF0((x+width)*16.0f)+D_001A7350-8;
    top = func_00283CF0(y*16.0f)+D_001A7354-8;
    bottom = func_00283CF0((y+height)*16.0f)+D_001A7354-8;
    D_L05_001B2C88[0] = 0x10000007;
    D_L05_001B2C88[1] = 0;
    D_L05_001B2C88[2] = 0;
    D_L05_001B2C88[3] = 0x50000007;
    header = D_L05_001B2C88;
    D_L05_001B2C88 = header+4;
    *(Quad *)(header+4) = D_L05_001ACA80;
    packet = (u64 *)(header+8);
    D_L05_001B2C88 = header+8;
    u0 = u<<4;
    u1 = (u+uw)<<4;
    v0 = v<<20;
    v1 = (v+vh)<<20;
    packet[0] = texture;
    packet[2] = color;
    packet[3] = v0+u0;
    packet[4] = (u64)left | ((u64)top<<16) | 0x00FFFFF000000000ULL;
    packet[5] = v0+u1;
    packet[6] = (u64)right | ((u64)top<<16) | 0x00FFFFF000000000ULL;
    packet[7] = v1+u0;
    packet[8] = (u64)left | ((u64)bottom<<16) | 0x00FFFFF000000000ULL;
    packet[9] = v1+u1;
    packet[1] = 0x154;
    packet[10] = (u64)right | ((u64)bottom<<16) | 0x00FFFFF000000000ULL;
    packet[11] = 0;
    D_L05_001B2C88 += 24;
}
