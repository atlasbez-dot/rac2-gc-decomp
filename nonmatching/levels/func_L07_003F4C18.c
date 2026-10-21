/* Matched byte for byte, but not landable: this body needs `qcopy`/`qzero` from
   include/common.h, which are inline assembly, and AGENTS.md's "Plain C" rule (no inline
   assembly in a function) forbids that as a matching route - docs/COMPILER-NOTES.md says it
   in as many words. Kept here as a starting point: the shape is right, and only the 128-bit
   copies would need a plain-C spelling that neither `mode(TI)` nor an aggregate gives yet.
   Removed from src/ on 2026-10-13. */

void func_L07_003F4C18(u8 *a0, u8 *a1, u8 *a2)
{
    u8 *s0 = *(u8 **)(a0 + 0x68);

    if (*(u8 **)(s0 + 0x20) != 0) {
        func_00283098(a1, s0, *(u8 **)(s0 + 0x20) + 0xC0);
        func_00282CC0(a1, a1, *(u8 **)(s0 + 0x20) + 0x10);
        func_00283098(a2, s0 + 0x10, *(u8 **)(s0 + 0x20) + 0xC0);
        func_00282CC0(a2, a2, *(u8 **)(s0 + 0x20) + 0x10);
        return;
    }
    qcopy(a1, s0);
    qcopy(a2, s0 + 0x10);
}

/* wave 24, worker 03 (src/levels/07_siberius/L07_003F4578.c): the same body in
   plain C with `mode(TI)` instead of the qcopy macro.  tools/check.py
   func_L07_003F4C18 prints "164 bytes, expected 168" - every instruction of
   the retail body is there except one address materialisation:

     retail   addiu $v1, $s0, 0x10 ; lq $v0, 0($v1) ; sq $v0, 0($s2)
     this cc1                          lq $v0, 0x10($s0) ; sq $v0, 0($a2)

   The first copy of the pair needs no materialisation (its source is $s0
   itself, at offset zero, and this cc1 keeps it there, as the retail does);
   the second one carries the +0x10 and this cc1 folds it into the `lq`.
   The `mode(TI)` spelling does reach `lq`/`sq` where a plain struct
   assignment gives `ldl`/`ldr`/`sdl`/`sdr`. */
