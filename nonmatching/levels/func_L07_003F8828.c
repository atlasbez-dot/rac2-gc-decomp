/* Matched byte for byte, but not landable: this body needs `qcopy`/`qzero` from
   include/common.h, which are inline assembly, and AGENTS.md's "Plain C" rule (no inline
   assembly in a function) forbids that as a matching route - docs/COMPILER-NOTES.md says it
   in as many words. Kept here as a starting point: the shape is right, and only the 128-bit
   copies would need a plain-C spelling that neither `mode(TI)` nor an aggregate gives yet.
   Removed from src/ on 2026-10-13. */

void func_L07_003F8828(u8 *a0, u8 *a1)
{
    u8 *s1 = *(u8 **)(a0 + 0x68);

    if (*(u8 *)(a0 + 0x95) == 0) {
        u8 *s0 = s1 + 0x400;

        func_00282CF0(s0, a1, *(u8 **)(s1 + 0x418) + 0x10);
        func_002AFDD8(*(u8 **)(s1 + 0x418), s0, s0, 0);
        return;
    }
    qcopy(s1 + 0x400, a1);
}

/* wave 24, worker 03 (src/levels/07_siberius/L07_003F4578.c): the plain-C route
   with `mode(TI)` reaches every instruction of the retail body except the one
   address materialisation.  tools/check.py func_L07_003F8828 --diff prints
   "104 bytes, expected 108"; the only difference is the last block:

     retail   addiu $v1, $s1, 0x400 ; lq $v0, 0($a1) ; sq $v0, 0($v1)
     this cc1                          lq $v0, 0($a1) ; sq $v0, 0x400($s1)

   the destination `s1 + 0x400` is a constant offset from a pointer, and this
   cc1 folds the offset into the `sq` (the reload accepts plus(reg, const_int)
   as a TImode address while the offset is inside [-32768, 32752]).  Measured
   here, all of them folding the same way: the offset written in the cast
   (`*(volatile TI128 *)(s1 + 0x400)`), the offset through a pointer variable
   (`u8 *dst = s1 + 0x400; *(volatile TI128 *)dst = ...`), the offset in a
   `u32 *` (the same address, word scaled), a struct with a TI member at
   0x400, the store with and without `volatile`, and the pointer loaded from
   memory instead of held in a register.  This is the wall of
   func_L11_003973F8 and func_L04_0033D0C0 (the same shape, four
   materialisations); the retail's own copy macro is the "r"-constrained
   `lq $v0,0(%1); sq $v0,0(%0)` idiom, which src/ may not use. */
