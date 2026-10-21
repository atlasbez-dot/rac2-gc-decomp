/* func_L04_0044AAC8 (820 bytes, 1 place: level 04_barlow) - best attempt, NOT MATCHED.
 *
 * Rechecked on 21 October 2026 with the compiler of #258 (the zero fold leaves a displaced
 * quadword store alone): this body is now 820 bytes, retail's size, and its `por $v0,$zero,$zero`
 * / `sq $v0,0x20($sp)` and the loop's alignment `nop` are retail's; tools/check.py: "instruction
 * at +0x19c differs", the call argument order described below. The notes below were written
 * with the earlier compiler.
 *
 * Built as a function of src/levels/04_barlow/L04_00422A00-g8.c (it takes $gp addresses of
 * small data), this body is 812 bytes against retail's 820.  tools/check.py: "812 bytes,
 * expected 820".  Everything else is recovered: the prologue and the switch on the byte at +0x20
 * (cases 0, 1 and 2 in retail's binary-tree order), cases 0 and 1 word for word, the walk of the
 * id list at the end of case 2 (unrotated, with the second `p != 0` guard, 32-byte records at
 * D_L04_001B2B54, the list table through the pointer D_L04_001A9014 which is a $gp load in the
 * branch delay slot and a bare lui/lw in the test) and the epilogue.
 *
 * What differs:
 *
 *  1. The wall, 4 bytes plus the 4 that follow from it.  Case 2 clears a 16-byte local before
 *     setting one float in it: retail has
 *         por $v0,$zero,$zero ; addiu $s1,$sp,0x30 ; sq $v0,0x20($sp) ; ... swc1 $f0,0x28($sp)
 *     and this cc1 has `sq $zero,0x20($sp)`.  rac2_fold_zero_ti_store folds a zero register that
 *     feeds ONE store; a second store keeps the `por` (measured here with a dummy
 *     `*(TI128 *)B = 0`, which gives the exact `por`/`sq $v0` and 820 bytes), a single one never
 *     does.  The `{0, 0, c, 0}` initializer is worse (a memset call), and two identical stores
 *     collapse to one before reload.  Missing the `por` also moves the id-list loop top to a
 *     multiple of 8, so retail's alignment `nop` (0x44AD5C) disappears: that is the other 4 bytes.
 *
 *  2. Instruction order in the argument set-up of the four calls (func_34D4E8 before the vector,
 *     func_3472B0 and the three func_340F08), same words, other order, and different words in
 *     three delay slots: retail leaves the last integer move (`addiu $t3`) in the delay slot of
 *     func_340F08 where this cc1 leaves a float move, and `mov.s $f13,$f20` in the slot of
 *     func_3472B0 where this cc1 has `addiu $s2,$zero,-1`.  The prototype of func_340F08 below
 *     (19 parameters: floats interleaved among the integers) was hill-climbed on the aligned-word
 *     count: 153 -> 170 of retail's 205 words align, nothing more; the natural order (pointers,
 *     integers, then the seven floats) is the 153 one.  Spelling the first call's loads
 *     (temporary for the $gp value, other types for the sda objects) changes nothing.
 *
 * Callees (level 04 addresses): func_33B9B0, func_33E6B0 (returns a pointer), func_34D4E8,
 * func_348788, func_3472B0, func_340F08, func_3317E8; the constants hoisted into $f20/$f21/$f22
 * are 0.0, 2.25 and 9.0, and the vector's float is 0.16666667f (0x3E2AAAAB).
 */

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

typedef int TI128 __attribute__((mode(TI)));

extern u16 **D_L04_001A9014;
extern u8 *D_L04_001B2B54;
extern u8 D_L04_001B17E0[8] __attribute__((sda));
extern u8 D_L04_001B17D8[8] __attribute__((sda));
extern u8 D_L04_001B17D0[8] __attribute__((sda));
extern s32 D_L04_001B1800 __attribute__((sda));

extern void func_33B9B0(void *a0, s32 a1, s32 a2);
extern void *func_33E6B0(void *a0, s32 a1, s32 a2);
extern void func_34D4E8(void *a0, void *a1, void *a2, void *a3, s32 a4, s32 a5, s32 a6, s32 a7,
                        s32 a8, s32 a9, s32 a10);
extern void func_348788(void *a0, s32 a1, f32 f12);
extern void func_3472B0(void *a0, void *a1, f32 f12, f32 f13, f32 f14);
extern void func_340F08(void *o, f32 f0, void *A, f32 f1, void *B, s32 i0, s32 i1, s32 i2, f32 f2,
                        f32 f3, f32 f4, f32 f5, s32 i3, f32 f6, s32 i4, s32 i5, s32 i6, s32 i7,
                        s32 i8);
extern void func_3317E8(void *a0);

void func_L04_0044AAC8(u8 *a0)
{
    u8 *state = *(u8 **)(a0 + 0x68);
    f32 A[4] __attribute__((aligned(16)));
    f32 B[4] __attribute__((aligned(16)));
    u16 *p;
    u8 *e;

    switch (a0[0x20]) {
    case 0:
        a0[0x31] = 0;
        *(u16 *)(a0 + 0x34) |= 1;
        func_33B9B0(a0, 1, -1);
        break;
    case 1:
        if (func_33E6B0(a0, 0x4010000, 0) != 0) {
            if (*(s32 *)state == 0)
                func_33B9B0(a0, 2, -1);
        }
        a0[0xA8] = 0xFF;
        break;
    case 2:
        func_34D4E8(a0, D_L04_001B17E0, D_L04_001B17D8, D_L04_001B17D0, 0x7F, 0, D_L04_001B1800, 1,
                    0xFFFF, 0xFF, 0);
        func_348788(a0, 5, 0.0f);
        *(TI128 *)A = 0;
        A[2] = 0.16666667f;
        func_3472B0(a0, B, 0.0f, 0.0f, 4.0f);
        func_340F08(a0, 0.0f, A, 0.0f, B, 50, 10, 10, 3.0f, 1.0f, 9.0f, 2.25f, -1, 15.0f, 1, 7, -1,
                    0, 0x810001);
        func_340F08(a0, 0.0f, A, 0.0f, B, 5, 1, 1, 0.0f, 0.0f, 9.0f, 2.25f, -1, 0.0f, 0, 0, -1, 1,
                    0x810001);
        func_340F08(a0, 0.0f, A, 0.0f, B, 5, 1, 1, 0.0f, 0.0f, 9.0f, 2.25f, -1, 0.0f, 0, 0, -1, 2,
                    0x810001);
        if (*(s32 *)(state + 4) != 0) {
            for (p = (u16 *)D_L04_001A9014[*(s32 *)(state + 4)];
                 p != 0 &&
                 ((p != 0 && (s16)p[-1] >= 0) || p == (u16 *)D_L04_001A9014[*(s32 *)(state + 4)]);
                 p++) {
                e = D_L04_001B2B54 + ((*p & 0x7FFF) << 5);
                if (e == 0)
                    break;
                e[0x1E] |= 4;
            }
        }
        func_3317E8(a0);
        break;
    }
}
