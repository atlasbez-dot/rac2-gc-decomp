/* Not landable: this body reaches a 128-bit copy through `qcopy`/`qzero` or a local
   `__asm__` helper, and AGENTS.md's "Plain C" rule (no inline assembly in a function)
   forbids that as a matching route. Kept as a starting point. Removed from src/ 2026-10-13.

   Wave 24 (worker 13): this body compiles to 144 bytes against retail's 152 with the
   plain C of a `mode(TI)` local (the `qcopy` helper of the earlier note is not
   needed), but the copy still folds: `lq $v0,0x10($s0)` against retail's
   `addiu $v1,$s1,0x10 ; lq $v0,0($v1)`.  The call to func_L01_00321178 takes the
   object and the state pointer, and its result is returned.
*/

func_L01_003DCDD8(u8 *a0, void *a1) {
    u8 *o = (u8 *)*(s32 **)(a0 + 0x68);
    s32 list[0x10];
    u8 vec[0x10];
    s32 count;
    s32 r;

    if (*(u8 *)(o + 0x3E4) != 0) {
        func_L01_003DC8B8(a0, list, &count);
    }
    qcopy(vec, a0 + 0x10);
    r = func_L01_00321178(a0, a1);
    func_L01_003DC9E0(a0, vec);
    if (*(u8 *)(o + 0x3E4) != 0) {
        func_L01_003DC9A8((void **)list, &count);
    }
    return r;
}
