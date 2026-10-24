/* Measured profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier. us: 18_damosel:
   instruction at +0x130 differs; us2: 18_damosel: instruction at +0x130 differs; pal: absent pal.
   Three meaningful source forms reached 488 bytes. The remaining +0x130 difference is entity-address
   destination allocation, followed by flag scratch and reload ordering. Mixed GP/absolute references
   use one truthful pointer identity. Reopen with an entity lookup lifetime idiom. No linked build or
   functional execution run. */

/* Historical screening below; superseded by the measured C reconstruction. */
/* func_L18_00427208 - 488 bytes, 3 place(s), level 18_damosel, retail at
   0x00427208. Screened with tools/w10_screen.py: 6 call(s)
   [func_L18_00426F28@004272B4, func_L18_00427130@004272DC,
   func_002829A8@00427308, func_002A7750@00427394,
   func_L02_002EF388@004273B4, func_002A7750@004273C4]; data addresses
   materialised [0x3dcc0000, 0x3f330000, 0x1b0000]; float constants
   [0x3f800000, 0x1b0000]; $gp-relative small data: no   saves: -; callee-
   saved registers saved [-]; words plain C cannot emit [LQ/SQ
   78620000@0x0048, LQ/SQ 7CA20000@0x004c, LQ/SQ 78820000@0x0058, LQ/SQ
   7C620000@0x005c, COP1 46800020@0x0084]. Head: addiu $sp, $sp, -0x40 ; sd
   $s0, 0x0($sp) ; sd $s4, 0x20($sp) ; daddu $s0, $a0, $zero ; sd $s2,
   0x10($sp) ; addiu $s4, $zero, -0x1. Not matched in this wave: the 128-bit
   copy needs an `lq`/`sq` pair; plain C reaches it only through a
   `mode(TI)` local, and this cc1 folds the destination offset into the `sq`
   where retail materialises the pointer first. What would unblock it: the
   exact source expression tree, so this cc1 picks the same registers in the
   same order. */

#include "common.h"
typedef int VectorBits __attribute__((mode(TI)));
extern u8 *D_L18_001B281C MACRO_ADDR;
extern void func_L18_00426F28(u8 *, s32, s32, float);
extern s32 func_L18_00427130(u8 *, s32, s32);
extern s32 func_002829A8(void *);
extern s32 func_L02_002EF388(u8 *, void *, void *, s32, s32);
extern void func_002A7750(u8 *, u8, s32);
void func_L18_00427208(u8 *object)
{
    u8 *state = *(u8 **)(object + 0x68);
    u8 *source;
    if (*(s32 *)(state + 0x3B4) == -1) return;
    source = D_L18_001B281C + (*(s32 *)(state + 0x3B4) << 8);
    *(VectorBits *)(object + 0x10) = *(VectorBits *)(source + 0x10);
    *(VectorBits *)(object + 0xF0) = *(VectorBits *)(source += 0xF0);
    state[0x2E] = 1;
    state[0x6A] = 0;
    *(s16 *)(state + 0x88) = 0;
    *(float *)(state + 0x20) = (float)*(s16 *)(state + 0x24);
    *(s32 *)(state + 0x94) = 0;
    object[0xA8] = 255;
    func_L18_00426F28(object, 7, 0, 1.0f);
    *(float *)(object + 0x48) = 0.1f;
    *(s32 *)(state + 0x13C) = *(s32 *)(state + 0x380);
    func_L18_00427130(object, *(s32 *)(state + 0x36C), -1);
    *(s32 *)(object + 0x98) = 0;
    object[0x7F] = 0;
    *(u16 *)(object + 0x34) &= ~0x1000;
    if (!(state[0x3B1] & 0x80)) func_002829A8(state + 0x3B1);
    *(float *)(state + 0x100) = 0.7f;
    if (*(s32 *)(state + 0x3B4) != -1 && (source = (u8 *)((*(s32 *)(state + 0x3B4) << 8) + (u32)D_L18_001B281C), *(s16 *)(source + 0xAA)) == 0x114D && source[0x20] != 0xFE && source[0x20] != 0xFD) {
        object[0x31] = 0;
        *(u16 *)(object + 0x34) |= 1;
        **(u8 ***)((u8 *)((*(s32 *)(state + 0x3B4) << 8) + (u32)D_L18_001B281C) + 0x68) = object;
        *(float *)(object + 0x48) = 1.0f;
        func_002A7750(object, 0, 11);
    } else {
        func_L02_002EF388(object, object + 0x10, object + 0xF0, 0, 0);
        func_002A7750(object, 0, 14);
    }
}
