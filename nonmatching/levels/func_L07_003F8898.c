/* Matched byte for byte, but not landable: this body needs `qcopy`/`qzero` from
   include/common.h, which are inline assembly, and AGENTS.md's "Plain C" rule (no inline
   assembly in a function) forbids that as a matching route - docs/COMPILER-NOTES.md says it
   in as many words. Kept here as a starting point: the shape is right, and only the 128-bit
   copies would need a plain-C spelling that neither `mode(TI)` nor an aggregate gives yet.
   Removed from src/ on 2026-10-13. */

void func_L07_003F8898(u8 *a0, u8 *a1)
{
    u8 *s0 = *(u8 **)(a0 + 0x68);

    if (*(u8 *)(a0 + 0x95) == 0) {
        func_00283098(a1, s0 + 0x400, *(u8 **)(s0 + 0x418) + 0xC0);
        func_00282CC0(a1, a1, *(u8 **)(s0 + 0x418) + 0x10);
        return;
    }
    qcopy(a1, s0 + 0x400);
}

/* wave 24, worker 03 (src/levels/07_siberius/L07_003F4578.c): the same wall as
   func_L07_003F8828, on the other side of the copy.  The retail materialises
   the SOURCE address there:

     retail   addiu $v1, $s0, 0x400 ; lq $v0, 0($v1) ; sq $v0, 0($s1)
     this cc1                          lq $v0, 0x400($s0) ; sq $v0, 0($a1)

   and the plain-C candidate is 108 bytes against retail's 112.  The same
   spellings were measured as for func_L07_003F8828 (the offset in the cast,
   through a pointer variable, in a `u32 *`, through a struct member, with and
   without `volatile`, the base loaded from memory): all fold the offset into
   the `lq`.  The destination `sq $v0, 0($s1)` (a1, a plain pointer) is the
   one that this cc1 already keeps at offset zero, which is the retail's shape
   for a plain pointer. */
