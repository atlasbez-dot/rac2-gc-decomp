/* func_L08_00422900 (200 bytes, 1 place) - max.s wall plus a quad copy, ASM_FUNC candidate.
 *
 * Same family as func_L08_00422850: `lq`/`sq` (`0x78620000`, `0x7FA20000`) move a 128-bit
 * object to the stack, the arms pick a radius from either `*(f32*)(a1+0x18)` or
 * `*(f32*)(s0+0x158)`, func_L08_00422850 is called with f12 built as `f13 + radius` and
 * f13 as `f13 - 0x41200000` (10.0f), the result is stored to +0x1B0, then
 * `c.olt.s $f0,$f1` + `bc1tl` + `swc1 $f1,0x1B0` clamp it against +0x1D4.
 * The wall is 0x46010028 at 0x004229B4 = `max.s $f0,$f0,$f1` (fmt=S, funct 0x28): the sixth
 * wave measured that this cc1 cannot emit max.s from any spelling, and it is the one word
 * that differs - the row needs the same compiler-side lever as func_L08_00425328.
 */

/* Measured again (wave 24, worker 10): the wall is the machine description
   itself.  The game's mips.md (gcc-1.1, patched) has no max.s pattern at all
   (`grep -n "max_s\|min_s" config/mips/mips.md` finds nothing), so no C
   spelling can produce the 0x46010028 at 0x004229B4; a ternary and a
   conditional assignment both come out as c.olt.s + bc1tl + mov.s.  Everything
   else in the body - the quad copy, both arms, the clamp against +0x1D4 - is
   instruction-exact. */
