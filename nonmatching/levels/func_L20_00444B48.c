/* Wave 4 (worker 04): the candidate below is the wave-4 one - the constant is
   D_L20_001B20B0 and the body is 204 bytes against the retail's 208.  See the
   wave-4 note at the end. */
/* 0 of 1 places match - last line: 20_yeedil: 204 bytes, expected 208
   The whole ramp is recovered and every instruction is retail's. Two integer parameters
   feed the guards through inline `cvt.s.w` (`D_L20_001B20A0 <= (f32)a0` returns f12,
   `(f32)a1 <= D_L20_001B20A0` returns f13); the interpolated return calls the int-to-float
   helper func_00283CE0 three times - twice on a0, once on a1, in the order the inline
   denominator gives - and divides (D_L20_001B20A0 - h(a0)) by (h(a1) - h(a0)). Two
   residues: the `nop` retail keeps between the third `sub.s` and the `div.s` is absent, and
   one set-up is swapped at +0x8C (retail saves `$s1 = $a1` in the bc1f delay slot with
   `mov.s $f23,$f13` four words earlier; this cc1 the other way round). Named numerator and
   denominator locals give 200 bytes and a different schedule; spelling the three helpers as
   `(f32)` casts lets this cc1 fold them into the guards (104 bytes). 
   Second wave (20_yeedil, 2026-10-20) re-measured this one and adds three facts.
   (1) The symbol is D_L20_001B20B0, not D_L20_001B20A0: retail loads it with
   `lwc1 $f1,0x30B0($gp)` and gp is 0x1AEFF0, so the constant lives at 0x1B20B0 (the
   unit's -g8.c sibling already declares D_L20_001B20B0 and uses it). (2) That symbol is
   a FLOAT: declared as `int` the compiler adds a `cvt.s.w` right after the load, and
   changing the declaration in src/levels/20_yeedil/L20_0043ECB0-g8.c from int to float
   is what makes the load and the `c.ole.s` compare come out right - it does not disturb
   func_L20_00444C18, which only takes its address (still 1 of 1 places match).
    Third wave (20_yeedil, 2026-10-20, worker 04) re-measured this one in the -G8 sibling
    (the unit L20_0043ECB0-g8.c, built with -mno-split-addresses) and the picture is the
    same, 204 bytes against 208. Two facts worth keeping: the two `nop`s the retail keeps
    after the `mtc1` and after the `c.le.s` ARE emitted - they come from the assembler's
    mtc1 hazard rule, not from cc1 - so the only missing word is the `nop` before the
    `div.s` (the division floor of docs/COMPILER-NOTES.md: the assembler pads a division
    only when a code label precedes it, and no source shape puts one within two slots of
    the `div.s`; the division here is 15 slots after the block label). The other residue is
    the swap: retail keeps `$s1 = $a1` in the delay slot of the `bc1f` and `mov.s $f23,$f13`
    four words earlier, this cc1 has `mov.s $f23,$f13` in the delay slot and the copy in
    the prologue. Tried and not enough: the two guards with named locals for f12 and f13,
    an explicit copy of a1, both together, and the blend with the quotient in a named local
    (which gives 200 bytes and a different schedule).
   (3) The file has to be built with -G8 (the -g8.c sibling): at -G0 the load comes out
   `lui $at ; lwc1 $f1,0x0($at)`. The two residues are the same as recorded above: the
   `nop` retail keeps before the `div.s` (the load-delay nop that belongs to the
   `lwc1 $f1,0x30B0($gp)`), and the copy of the second argument into $s1 sits in the
   delay slot of the `bc1f` in retail while this cc1 puts it in the prologue block (and
   the `mov.s $f23,$f13` takes its place). Tried and not enough: the source spelled with
   if/else-if, with a result variable, with the three helper calls in named locals, with
   the numerator in a named local, and with the second comparison written as `>=` or as
   `!(a > b)` (those change the compare opcode and are wrong).*/
typedef int s32;
typedef float f32;

extern f32 D_L20_001B20B0 __attribute__((sda));

extern f32 func_00283CE0(s32);

f32 func_L20_00444B48(s32 a0, s32 a1, f32 f12, f32 f13)
{
    if (D_L20_001B20B0 <= (f32)a0)
        return f12;
    if ((f32)a1 <= D_L20_001B20B0)
        return f13;
    return f12 + (f13 - f12) *
                      ((D_L20_001B20B0 - func_00283CE0(a0)) /
                       (func_00283CE0(a1) - func_00283CE0(a0)));
}



/* ---- wave 4 (20_yeedil, 2026-10-20, worker 04): the two residues are confirmed,
 *      and the constant is D_L20_001B20B0 -----
 *
 * Re-measured in a -G8 unit of its own: 204 bytes against the retail's 208, and
 * the two residues are the ones recorded above.
 *
 *  - the missing word is the `nop` between the `sub.s $f1,$f1,$f21` and the
 *    `div.s $f1,$f1,$f20`.  It is NOT the assembler's division floor: the
 *    retail's division is thirteen slots after the last branch group and eight
 *    slots after the last code label, so neither the label rule nor the branch
 *    rule of the SDK 3.01 subset in tools/compiler/transformers/ fires.  It is
 *    the compiler's delay slot: this cc1 leaves the `sub.s`'s slot empty and
 *    the assembler fills it with the `div.s`, while the retail's compiler
 *    emitted the `nop` itself (the `div.s` is not a delay-slot candidate).
 *    No source shape tried changes that.
 *  - the swap: the retail has `mov.s $f23,$f13` in the prologue (with the
 *    other callee-saved copies) and `daddu $s1,$a1,$zero` in the delay slot of
 *    the `bc1f`; this candidate has the copy of $a1 in the prologue and the
 *    `mov.s $f23,$f13` in that delay slot.  The copy of the second argument
 *    has to be the LAST thing the compiler schedules before the call, which
 *    means it must not be needed before the branch.
 *  - the constant is D_L20_001B20B0 (gp+0x30B0), declared `__attribute__((sda))`
 *    in a -G8 unit; at -G0 the load comes out `lui $at ; lwc1`.
 */

/* ---- wave 5 (20_yeedil, 2026-10-21, worker 03): the two residues, re-measured -----
 *
 * The candidate above is the wave-4 one.  It is 204 bytes against the
 * retail's 208 and 21 of the 26 words match; the residue is exactly the two
 * the wave-4 note names, and this wave confirms both and measures the flags.
 *
 *  - The `nop` before the `div.s`.  This cc1 puts the division in the delay
 *    slot of the `sub.s $f1,$f1,$f21` that produces its numerator:
 *        sub.s $f1,$f1,$f21
 *        div.s $f1,$f1,$f20      <- the delay slot: the OLD $f1
 *        mul.s $f0,$f0,$f1
 *    while the retail has
 *        sub.s $f1,$f1,$f21
 *        nop
 *        div.s $f1,$f1,$f20      <- the NEW $f1
 *        mul.s $f0,$f0,$f1
 *    so the two objects do not even compute the same value: the retail's
 *    division uses the result of the subtraction, this cc1's uses the value
 *    the subtraction replaced.  The source shapes measured (the quotient in a
 *    named local, the numerator and the denominator in named locals, the
 *    division as its own statement) all give the same 204 bytes and the same
 *    wrong division, so the residue is in the delay-slot filling and not in
 *    the source.  gcc/config/mips/mips.md gives the fdiv a function unit of
 *    six cycles on the r5900 but no delay slot of its own, so nothing keeps
 *    the division out of the slot of the instruction that defines its
 *    numerator.
 *  - The `$s1 = $a1` copy.  The retail has it in the delay slot of the
 *    `bc1f` (the last thing in the block, after the `mov.s $f23,$f13` and
 *    the `mov.s $f22,$f12`), this cc1 has it in the prologue and the
 *    `mov.s $f23,$f13` in the delay slot.  The source shapes measured (the
 *    second guard with a named float, the two guards with braces) change
 *    nothing: the copy is emitted in the prologue because the parameter is
 *    live across the three calls.
 *  - The per-file flags, one at a time in a file of their own:
 *      - `-fno-schedule-insns2` gives the retail's 208 bytes but the body
 *        completely unscheduled (39 words differ);
 *      - `-fno-schedule-insns` and `-fno-sched-interblock` leave the same two
 *        residues (22 and 23 words).
 *  - The rest of the body is the retail's: the frame is 0x40 with $s0/$s1
 *    at 0x00/0x08, $ra at 0x10 and $f20/$f21/$f22/$f23 at 0x20/0x28/0x30/
 *    0x38; the constant is D_L20_001B20B0 at gp+0x30B0; the guards are
 *    `D_L20_001B20B0 <= (f32)a0` (returns f12) and `(f32)a1 <=
 *    D_L20_001B20B0` (returns f13); the three helper calls are
 *    func_00283CE0(a0), func_00283CE0(a1) and func_00283CE0(a0) in that
 *    order, and the blend is f12 + (f13 - f12) * ((D - h(a0)) / (h(a1) -
 *    h(a0))).
 */
