/* func_L23_00418650 (124 bytes, 1 place, L23_00416388.c, -O2 -G0) -- NEAR MISS, not integrated.
   Measured on 21 October 2026 in a unit of its own (src/levels/23_damosel_orbit/L23_00418650.c) built with
   `-O2 -G0 -ffunction-sections -frac2-qcopy`: 124 bytes, retail's size; check.py "instruction at +0x14
   differs", 0 of 1 places. One pair of words is left (+0x14/+0x18); the earlier second pair (the tail
   `lq; sq; ld $s0` against `lq; ld $s0; sq`) is fixed by the qcopy pattern, which is one insn, so the frame
   restore cannot slip between the lq and the sq.

   Retail builds a sixteen-byte vector in a stack local through three shared helpers and copies it back
   over the argument with lq/sq. The float global is read through `lui $at` because it is declared sda in
   this -G0 unit (cc1 emits the bare symbol, the assembler expands it through $at). Plain, it splits into
   `lui $v0` + `lwc1`. (D_L23_001B36A4 is level data, not D_001B36A4.)

   Left: retail has `lui $s0 ; swc1 $f20 ; addiu $s0,$s0,%lo(D_00189ED0) ; daddu $s1,$a0,$zero ; sd $ra`,
   this cc1 swaps the `addiu` and the `daddu` (the parameter copy comes first).
   Cause (measured with -dR -fsched-verbose-5): sched1 emits `high, $84=$4, lo_sum, $85=$f12` (the copy
   takes the second slot of cycle 1 against the float copy: priorities 12 and 11), and in sched2 the two
   tie at cycle 4: priority 17 each, five dependents each (the return, the restore, the argument setup, the
   call), so the LUID, i.e. sched1's order, puts the copy first. With the volatile asm macro of the original
   (`__asm__ __volatile__("lq $2,0(%1)\n\tsq $2,0(%0)" :: "r"(arg0), "r"(local) : "$2")`, scratch only)
   this file is exact (0 words differ): the asm clears the register-use and register-set lists, so the two
   restore loads are no longer dependents of the `addiu` and of the copy, and the `addiu` ends with five
   dependents against four and goes first. The qcopy insn leaves those lists alone: five against five.
   Tried without effect (all 124 bytes, the same pair): a TI local instead of char[16]; the float parameter
   declared first (the copies are then emitted float first); a `char *base = D_00189ED0` local; the sum in
   a float local; adding -frac2-zero-ti-barrier (no change); and, on the qcopy unit, 50 single extra cc1 flags (-fno-schedule-insns,
   -fno-schedule-insns2, -fno-gcse, -fno-strength-reduce, -fno-rerun-cse-after-loop, -mno-split-addresses,
   -g, ...): none moves the pair (-fno-schedule-insns2 loses the prologue interleave, -mno-split-addresses
   makes D_00189ED0 one `la`). sched1 would need the float copy to outrank the parameter copy (priority 12
   or more against 12, with more dependents) or the high/lo_sum pair to precede the copy in the stream;
   neither follows from a source shape. */


typedef int V4_L23_418650 __attribute__((mode(TI)));

extern char D_00189ED0[];
extern float D_L23_001B36A4 __attribute__((sda));
extern void func_00282CF0(char *dst, char *src, char *arg);
extern void func_00282F20(char *dst, char *src, float arg);
extern void func_00282CC0(char *dst, char *src, char *arg);

void func_L23_00418650(char *arg0, float arg1) {
    char local[16];

    func_00282CF0(local, arg0, D_00189ED0);
    func_00282F20(local, local, arg1 + D_L23_001B36A4);
    func_00282CC0(local, local, D_00189ED0);
    *(V4_L23_418650 *)arg0 = *(V4_L23_418650 *)local;
}
