/* func_L23_003C01F8 (204 bytes, 1 place: 23:003C01F8) -- NEAR MISS, not integrated.
   Not an MMI row: the five `.word`s of the earlier record are R5900 `lq`/`sq` at offset 0
   (`lq $v0,0($s1)`, `sq $v0,0($sp)`, `sq $v0,0($s0)`, `lq $v0,0($v1)`, `sq $v0,0($s1)`).
   The two guards do not return: both branch to the `beqz $s1`, so they only skip the call.

   Measured on 21 October 2026 in a unit of its own (src/levels/23_damosel_orbit/L23_003C01F8.c) built with
   `-O2 -G0 -ffunction-sections -frac2-qcopy`: 204 bytes, retail's size; check.py "instruction at +0x54
   differs", 5 words (the earlier record had 12). The three register-address copies are retail's now
   (`addiu $s0,$sp,0x10 ; lq $v0,0($s1) ; sq $v0,0($s0)`, the first call's delay slot, and the final
   `lui $v1 ; addiu $v1 ; lq $v0,0($v1) ; sq $v0,0($s1)` with the data in $v0). What is left is the order
   inside the block after `beqz $s1`:
       retail:  lq,sq (a) ; addiu $s0,$sp,0x10 ; lq,sq (b) ; lui $at,0xC000 ; mtc1 $at,$f12 ; jal ; daddu $a0,$s0
       here:    lui $at,0xC000 ; mtc1 $at,$f12 ; addiu $s0,$sp,0x10 ; lq,sq (a) ; lq,sq (b) ; jal ; daddu $a0,$s0
   (the `li.s -2.0f` and the address `$s0` are hoisted above both copies: 5 words.)
   Cause (measured, -dR -fsched-verbose-5): the block's first cycle has only two ready insns, the address
   `$s1 = $s0+0x10` and the `li.s $f12,-2.0` (a load-class insn of priority 9, as the copies), so the constant
   takes the second slot and the copies, which wait for the address, come after it; sched2 then hoists
   `addiu $s0,$sp,0x10` the same way. Retail keeps both copies before them because its copies are the
   original's volatile inline-asm macro
       __asm__ __volatile__("lq $2,0(%1)\n\tsq $2,0(%0)" :: "r"(dst), "r"(src) : "$2")
   With COPY128(&a, arg0 + 0x10), COPY128(&b, arg0 + 0x10) and COPY128(arg0 + 0x10, &D_L23_001C0AA0) in this
   body, a scratch copy of the unit is exact (0 words differ, derive OK). The qcopy insn is not a barrier.
   Inline asm is not allowed in src/, so this stays a near miss.

   Plain-C levers found on the way (each measured here):
   - `arg0 = (char *)&b;` after `pos = arg0 + 0x10` kills cse's equivalence pos == arg0+0x10, so
     the loads stay `lq $v0,0($s1)` (no fold) and arg0's register $s0 is reused for &b as in
     retail. With pos a separate pseudo its base is unknown to alias.c (find_base_value has no
     ADDRESS case for the argument copy), so the store to `a` between the copies keeps the second
     `lq` (cse2 merged them while the address was folded to arg0+0x10).
   - `p = &a;` before `arg0 = (char *)&b;` gives a sp+0 and b sp+0x10: purge_addressof allocates
     the slots in the order the addresses are first taken as values.
   Tried without effect: `b = *pos; a = *pos;` (4 words, but b's copy first), a separate pointer for &b instead of
   reusing arg0 (8 words), `b = a`, the copies through `*p` and `*(TI16 *)arg0`, 32 permutations of the copy
   spellings (earlier record), 54 orders of `p = &a`, `arg0 = &b` and the two copies (written as `a = *pos` or
   `*p = *pos`, `b = *pos` or `*(TI16 *)arg0 = *pos`): 4 words at best, never exact; adding
   -frac2-zero-ti-barrier changes nothing; and 50 single extra cc1 flags (-fno-schedule-insns2 7 words,
   -mno-split-addresses 208 bytes; none exact). Needs a barrier model for qcopy. */


typedef int TI16 __attribute__((mode(TI)));

extern float D_L23_001AFA10 __attribute__((sda));

extern TI16 D_L23_001C0AA0;

extern void func_L23_003BFFC0(char *arg0, int arg1, int arg2, int arg3, int arg4, float arg5);

extern void func_L23_00418650(TI16 *, float);

extern int func_002761F8(TI16 *, TI16 *, int, int, int);

void func_L23_003C01F8(char *arg0, int arg1) {
    TI16 a;
    TI16 b;
    TI16 *p;

    if ((unsigned char)(*(unsigned char *)(arg0 + 0x43) - 5) >= 2 && *(unsigned char *)(arg0 + 0x20) != 2)
        func_L23_003BFFC0(arg0, 5, 0, 6, 1, D_L23_001AFA10);
    if (arg1 != 0) {
        TI16 *pos = (TI16 *)(arg0 + 0x10);

        p = &a;
        arg0 = (char *)&b;
        a = *pos;
        b = *pos;
        func_L23_00418650((TI16 *)arg0, -2.0f);
        func_L23_00418650(p, 0.1f);
        if (func_002761F8((TI16 *)arg0, p, 0x12, 0, 0) != 0)
            *pos = D_L23_001C0AA0;
    }
}
