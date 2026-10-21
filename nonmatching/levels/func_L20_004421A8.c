/* func_L20_004421A8 (756 bytes, level 20): NOT ATTEMPTED in this wave; the body is
 * recovered below and the blockers are measured.
 *
 * THE BODY
 *
 *   void func_L20_004421A8(char *arg0)
 *
 *   The frame is 0x60; $s1 = arg0, $s3 = &D_189E20, $s5 = the `%hi` of D_189E20,
 *   $s2 = state (arg0->0x68), $s0 = state+0xF0, $s4 = arg0+0xC0, $f20 = 2.0f.
 *
 *   - the two vector differences against D_189E20 (state->0x80/0x84 minus
 *     arg0->0x10/0x14) go through func_00283248 and then func_00303358 with
 *     arg0->0xF8; the result is compared with pi/2 (0x3FC90FDB) and, if it is smaller,
 *     the two differences are computed AGAIN and func_00341AA8(arg0) is called -
 *     that is the `bc1fl` at the top;
 *   - func_00340898(arg0, -1.0f, 0x10) with the `lw $v0,0x2290($s3)` in the delay
 *     slot, and `sw $zero,0x98($v0)`;
 *   - func_003396D8(state->0x2290->0x24->0x10, 0, 0) with `sw $v0,0x98($t0)` in the
 *     delay slot;
 *   - func_00283098(state+0xF0, state+0xF0, arg0+0xC0) with `sw $zero,0xF4($s2)`;
 *   - the float at state->0x100 is doubled and divided by the float at state->0x78;
 *     the quotient is clamped to 0.5f with a `c.lt.s` + `bc1tl` + `mov.s` (the
 *     branch-likely form, so the clamp is `if (q < 0.5f) q = 0.5f;` written as a
 *     separate test);
 *   - the constant 0.000290888245f (0x3998825C) and the float at gp+0x3134
 *     (0x1B2124) multiply the clamped quotient, and func_00303270 is called with
 *     the float at state->0x1804; the result is stored back to state->0x1804;
 *   - func_00282CC0(sp, arg0+0xC0, arg0+0x10) copies the vector at arg0+0x10 into
 *     the stack slot, and the float at +8 of it is used to set up the last
 *     func_00330FC0 call (the float 0x8(sp) plus 5.0f);
 *   - the two calls func_00330FC0 take (arg0, sp, 0x10008, 0, 1, 0) and
 *     (arg0, sp, 0x10000, 0, 1, 0);
 *   - the behaviour table: `lw $a0,0xD4($s2)`, then the word at +0xAA against 0x1366
 *     and 0x1367 selects func_003A5FF0 or func_003A7C50, and the word at
 *     D_189E20+0x2294 against 0x8C decides whether the rest runs;
 *   - func_00282E80(arg0+0x80, arg0+0x10) and the `c.le.s` + `bc1f` pair, then
 *     func_002A89A8(arg0+0x80, 0, (state->0x88 + 5.0f) * 0.5f) and the two `sh 5`
 *     stores;
 *   - the last call func_003583C8(state->0x50, state->0x210, arg0+0x10).
 *
 * THE BLOCKERS
 *
 *   1. the unit has to be a -G8 unit: the float at gp+0x3134 (0x1B2124) is read
 *      through $gp;
 *   2. the register allocation: nine callee-saved registers, $f20, three float
 *      branch-likelys of two different polarities, a float division and a clamp;
 *   3. the `bc1tl` clamp and the `bc1fl`/`bc1f` pairs: the polarity of a COP1
 *      branch-likely is a spelling choice (a negated comparison with the operands
 *      swapped), so each of the three has to be found separately.
 */
