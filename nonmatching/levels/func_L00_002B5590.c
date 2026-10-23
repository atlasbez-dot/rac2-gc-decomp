/* func_L00_002B5590 (92 bytes, 27 places) -- NEAR MISS, not integrated.
   Wave 8 w8-10: 80 bytes (20 instructions) against the retail's 92 (23). The copy, the
   two calls, their argument registers and the 1.0f constant all match. What differs:

   - The retail's frame is 0x40 with $s0 AND $s1 saved: $s1 holds `sp` itself
     (`daddu $s1,$sp,$zero`) and the second call passes it (`daddu $a0,$s1,$zero`), while
     $s0 holds `sp + 0x10`. This cc1 rematerialises `sp + 0` for the second call
     (`daddu $a0,$sp,$zero`) and keeps only $s0, so the frame is 0x30.
   - The retail clears the second quadword with `sq $zero,0($v1)`, the address being
     materialised in $v1 (`addiu $v1,$sp,0x10`) because the fold to an architectural
     zero only applies to a register-only address. This cc1 emits `por $zero,$zero,$zero`
     plus `sq $v0,0x10($sp)`: the address is folded into the store, so the zero is not
     folded. -frac2-qcopy and -frac2-zero-ti-barrier were measured on this unit and
     change neither.
   - The local layout must be an array of two quadwords: the copy lands at sp+0 and the
     cleared one at sp+0x10, as in the retail. Two separate locals put the cleared one
     at sp+0 and the copy at sp+0x10 (64 bytes, everything else rematerialised).

   What was measured: the parameter is a quadword pointer (`lq $v0,0($a0)`), the first
   helper takes (&second, &second, 1.0f) and the second (&first, &second); the callee
   names are right - func_L00_002D3798 and func_00282DB0 are the retail's targets in
   every level (their addresses move with the level, the boot copy included:
   0x2EE1F8 in level 00, 0x2EE418 in level 26). */

typedef int TI128 __attribute__((mode(TI)));

extern void func_L00_002D3798(TI128 *, TI128 *, float);
extern void func_00282DB0(TI128 *, TI128 *);

void func_L00_002B5590(TI128 *p)
{
    TI128 buf[2];

    buf[0] = *p;
    buf[1] = 0;
    func_L00_002D3798(&buf[1], &buf[1], 1.0f);
    func_00282DB0(&buf[0], &buf[1]);
}
