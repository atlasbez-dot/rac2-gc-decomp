/* 0 of 1 places match - last line: 01_oozla: 196 bytes, expected 204
   The body is recovered: the 0x660-byte object comes from func_0029EFD0(0x660),
   the 0x30/0x31/0x32/0x20 bytes and the 0x2C float (the 0x24 word's 0x24 float
   times the first float argument) are written into it, the 16-byte position is
   copied from the second argument, the state words 0x50/0x54/0x58/0x5C are
   written and func_002A0F48 is called on the object.  Two words are missing:
   the retail materialises the 128-bit destination (`addiu $a1,$s0,0x10` then
   `sq $v0,0($a1)`) where this cc1 folds the offset into the store
   (`sq $v0,0x10($s0)`) - the CSE tie of docs/COMPILER-NOTES.md, and the guard
   is retail's branch-likely form (`beql $s1,$zero` with the 0x5C store copied
   into its annulled slot) where this cc1 emits a plain `beq` with the 16-byte
   copy in the slot.  Spellings measured: the guard written with an empty then
   arm, inverted, with a `goto`, the two stores in both orders, the copy before
   and after the guard, the copy through a pointer variable, a struct member and
   an integer address (all give the plain `beq` and the folded store); a
   `||` chain of two tests, which is what makes this cc1 emit a branch-likely
   form at all, has no counterpart in this body.  -ffast-math (the flag that
   gives the retail's min.s in the sibling unit) changes nothing here. */

#include "include_asm.h"
#include "common.h"

typedef unsigned int TI128 __attribute__((mode(TI)));

extern void *func_0029EFD0(int);

extern void func_002A0F48(void *);

void *func_L01_003A6280(u8 *arg0, void *arg1, u32 arg2, f32 f12, f32 f13) {
    u8 *s0 = (u8 *)func_0029EFD0(0x660);
    u8 *a2;

    if (s0 != 0) {
        s0[0x30] = arg0[0x30];
        a2 = *(u8 **)(s0 + 0x68);
        *(u16 *)(s0 + 0x32) = *(u16 *)(arg0 + 0x32);
        s0[0x31] = 1;
        s0[0x20] = 0;
        *(u32 *)(a2 + 0x50) = (u32)arg0;
        *(f32 *)(s0 + 0x2C) = *(f32 *)(*(u32 *)(s0 + 0x24) + 0x24) * f12;
        *(TI128 *)(s0 + 0x10) = *(TI128 *)arg1;
        if (arg0 != 0) {
            *(u32 *)(a2 + 0x54) = *(s16 *)(arg0 + 0xAA);
        }
        *(u32 *)(a2 + 0x5C) = arg2;
        *(f32 *)(a2 + 0x58) = f13;
        func_002A0F48(s0);
    }
    return s0;
}
