/* func_L08_00422850 (172 bytes, 1 place) - max.s/min.s wall, ASM_FUNC candidate.
 *
 * The readable part: `mov.s $f20,$f14`, then a 128-bit copy pair (`lq`/`sq`) into the
 * caller's stack, then func_2EA300(v1, sp, 2, 0, 0) with the result gated by a
 * `c.eq.s $f15` test, and two arms that answer either D_L08_001C....-ish `lwc1 -0x98($v0)`
 * or the doubled argument.
 * The wall is the two COP1 words: 0x4600A028 = `max.s $f0,$f20,$f0` and 0x460C7829 =
 * `min.s $f0,$f15,$f12` (fmt=S, funct 0x28/0x29).  The sixth wave measured that this cc1
 * has no max.s/min.s pattern and that the ternary and conditional-assignment spellings both
 * emit `c.olt.s` + `bc1f`/`bc1tl` + `mov.s` instead (func_L08_00425328 is behind the same
 * wall).  Nothing else is missing.
 */

/* Measured again (wave 24, worker 10): the wall is the machine description
   itself.  The game's mips.md (gcc-1.1, patched) has no max.s/min.s pattern at
   all - `grep -n "max_s\|min_s" config/mips/mips.md` finds nothing, and the
   only division/compare patterns are divsf3/divdf3 and the usual slt/sltu - so
   no C spelling can produce 0x4600A028 (`max.s`) or 0x460C7829 (`min.s`).
   A ternary, a conditional assignment and a comparison against a constant all
   come out as c.olt.s + bc1f/bc1tl + mov.s.  The rest of the body is
   instruction-exact apart from that word. */
