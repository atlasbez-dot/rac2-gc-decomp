/* Measured profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier. us: 18_damosel:
   instruction at +0x58 differs; us2: 18_damosel: instruction at +0x58 differs; pal: absent pal. Equal
   572-byte reconstruction first differs at +0x58 in initialization register/store ordering. Disabling
   instruction scheduling moved the first difference earlier (+0x38) and was rejected. Reopen with a
   matching initialization field-order witness. No linked build or functional execution run. */

/* Historical screening below; superseded by the measured C reconstruction. */
/* func_L18_003F5198 - 572 bytes, 3 place(s), level 18_damosel, retail at
   0x003f5198. Screened with tools/w10_screen.py: 8 call(s)
   [func_00283CF0@003F51B8, func_00283CF0@003F51C8, func_002B60B0@003F52D8,
   func_002A7750@003F5324, func_002A7750@003F534C,
   func_L18_003F7590@003F5364, func_002A7750@003F5384,
   func_L18_0032B768@003F53B4]; data addresses materialised [0x3efa0000,
   0x3ecc0000, 0x3fb30000, 0x3e4c0000, 0x3bb60000, 0x3fc90000, 0x3b910000,
   0x3e080000, 0x3b640000, 0x3e560000, 0x1b0000]; float constants
   [0x41700000, 0x40c00000, 0x41800000, 0x3f000000, 0x40000000, 0x40a00000];
   $gp-relative small data: no   saves: -; callee-saved registers saved [-];
   words plain C cannot emit [LQ/SQ 78620000@0x01fc, LQ/SQ 7C820000@0x0200,
   LQ/SQ 78620000@0x020c, LQ/SQ 7CA20000@0x0210]. Head: addiu $sp, $sp,
   -0x20 ; lui $at, 0x4170 ; mtc1 $at, $f12 ; sd $s1, 0x8($sp) ; sd $s2,
   0x10($sp) ; daddu $s1, $a0, $zero. Not matched in this wave: the 128-bit
   copy needs an `lq`/`sq` pair; plain C reaches it only through a
   `mode(TI)` local, and this cc1 folds the destination offset into the `sq`
   where retail materialises the pointer first. What would unblock it: the
   exact source expression tree, so this cc1 picks the same registers in the
   same order. */

#include "common.h"
typedef int VectorBits __attribute__((mode(TI)));
extern s32 func_00283CF0(float);
extern void *func_002B60B0(u8 *, float, float, float, float);
extern void func_002A7750(u8 *, u8, s32);
extern void func_L18_003F7590(u8 *);
extern s32 func_L18_0032B768(u8 *, s32, s32);
extern u8 *D_L18_001B281C MACRO_ADDR;
void func_L18_003F5198(u8 *object)
{
    u8 *state = *(u8 **)(object + 0x68);
    s16 mode;
    state[0x48] = func_00283CF0(15.0f);
    state[0x4A] = func_00283CF0(6.0f);
    state[0x60] = 17;
    *(float *)(state + 0x84) = 0.49000000953674316f;
    *(s32 *)(state + 0xCC) = *(s32 *)(state + 0x260);
    state[0x29] = 1;
    *(s32 *)(state + 0x98) = 3;
    *(float *)(state + 0x80) = 0.49000000953674316f;
    *(float *)(state + 0x8C) = 0.4f;
    if (*(s16 *)(state + 0x24) == 0) {
        *(s16 *)(state + 0x24) = 16;
        *(float *)(state + 0x20) = 16.0f;
    }
    state[0x28] = 3;
    *(float *)(state + 0x30) = 0.5f;
    state[0x2E] = 1;
    *(float *)(state + 0x134) = 1.4f;
    *(float *)(state + 0x104) = 0.2f;
    *(float *)(state + 0x100) = 0.4f;
    *(float *)(state + 0x12C) = 0.0055555556900799274f;
    *(float *)(state + 0x108) = 2.0f;
    *(float *)(state + 0x10C) = 5.0f;
    *(float *)(state + 0x110) = 1.5707964897155762f;
    func_002B60B0(object, 0.004444444552063942f, 0.13333334028720856f, 0.0034906589426100254f, 0.20943954586982727f);
    if (*(s32 *)(state + 0x260) != -1) *(s32 *)(state + 0x13C) = *(s32 *)(state + 0x260);
    *(float *)(state + 0x268) = *(float *)(object + 0x2C);
    if (*(s32 *)(state + 0x280) != -1) *(u8 **)(state + 0x258) = D_L18_001B281C + (*(s32 *)(state + 0x280) << 8);
    *(s32 *)(object + 0x98) = *(s32 *)(*(u8 **)(object + 0x24) + 0x10);
    func_002A7750(object, 6, 2);
    mode = *(s16 *)(state + 0x296);
    if (mode == 14) {
        if (*(s32 *)(state + 0x26C) != -1) func_002A7750(object, 14, 2);
    } else if (mode == 1) func_L18_003F7590(object);
    else if (mode == 2) func_002A7750(object, 2, 0);
    *(VectorBits *)(state + 0x210) = *(VectorBits *)(object + 0x10);
    *(VectorBits *)(state + 0x220) = *(VectorBits *)(object + 0xF0);
    func_L18_0032B768(object, 0, 3);
}
