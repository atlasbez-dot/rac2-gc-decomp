/* func_00313678 - 84 bytes, 28 places (the boot and every level).
   Retail at 0x00313678: the 16-byte vector at +0x10 of the argument is
   copied into the local at +0x00 of the frame (lq $v0,0($a0) ; sq $v0,0($sp)),
   the local is turned by half a turn and handed to func_002B00D8 together
   with the argument's own +0x10 pointer, and the helper's answer with the
   resident table decides the return value.
   The candidate below is that body, but the 16-byte copy differs: retail
   materialises the address of the source (addiu $a0,$a0,0x10 ; lq $v0,0($a0))
   where this cc1 folds the offset into the instruction (lq $v0,0x10($a0)).
   That is the known CSE tie of the 128-bit copy (docs/COMPILER-NOTES.md, "The
   128-bit copy wall"): the address of a TI access is used once here, so the
   plus(reg, const) is folded into the lq/sq instead of being materialised.
   Measured and not enough: a TI128* parameter for func_002B00D8, the pointer
   written as (x + 0x10) at both uses, and the volatile destination - all
   three leave the lq folded. The escape the repository knows is the opt-in
   -frac2-qcopy profile, which keeps both addresses in registers; the unit
   would need that flag in config/cflags.txt. */
typedef int TI128 __attribute__((mode(TI)));

extern void func_002B00D8(TI128 *p, float *a1, float *a2, float f);

extern int func_002761F8(void *a, void *b, int mode, void *self, int flag);

extern char D_00189F00[];

int func_00313678(char *x)
{
    TI128 local;
    TI128 *p = (TI128 *)(x + 0x10);

    local = *p;
    func_002B00D8(p, (float *)&local, (float *)&local, -0.5f);
    return func_002761F8(&local, D_00189F00, 0x12, 0, 0) == 0;
}
