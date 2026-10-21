/* func_L20_004429F0 (544 bytes, level 20): NOT ATTEMPTED in this wave; the body is
 * recovered below and the blockers are measured.
 *
 * THE BODY
 *
 *   void func_L20_004429F0(char *arg0)
 *
 *   The frame is 0x70; $s6 = arg0, $s2 = state (arg0->0x68), $s5 = &D_189E20, $f20 =
 *   60.0f, and the saved registers are $s0..$s7 and $fp ($fp is used as a general
 *   register: it holds the value 4 or 6).
 *
 *   The guards, in the retail's order:
 *     - `lw $v0,0x182C($s2)` and `bgtzl $v0` : if state->0x182C > 0, skip the two
 *       checks that follow; the delay slot loads `arg0[0x95]`;
 *     - `lw $v0,0x30FC($gp)` (a global) and `beqz` : if that global is zero, skip
 *       everything;
 *     - `if (arg0[0x95] == 5) skip` (the byte at arg0+0x95);
 *     - `func_0039E0A0(state->0x23C)` and `bnez` : skip if it returns non-zero;
 *     - `func_00301ED0(state + 0x1848)` and `bnez` : if it returns non-zero, run the
 *       main part; otherwise the global at gp+0x30FC decides again.
 *
 *   The main part:
 *     - func_00444B48(5, 0x14, 0.0f, 60.0f) and then the loop;
 *     - the loop runs 30 times (`slti $v0,$s7,0x1E`) and inside it:
 *         n = func_0032F680(6);
 *         the two indices n/6 and n%6 (a `div` with the `break` trap check) scaled by
 *         16 and offset by 0x10;
 *         func_002A7878(...) and func_002822A8(sp, base+i1, base+i0);
 *         func_002A89A8(sp, 0, 0.5f) and the result is added to 1.0f;
 *         func_002F3518(sp, 0, 0) and the 0x8(sp) result is decremented by 1.0f;
 *         func_0039DBC8(state->0x23C) and, if it returns zero, the loop ends;
 *     - the loop also ends when the counter of successes reaches $fp (4 or 6, from
 *       `xori $a1,$a1,0x2` and `movz $fp,$v0,$a1`).
 *
 * THE BLOCKERS
 *
 *   1. the unit has to be a -G8 unit: the global at gp+0x30FC is read through $gp
 *      (0x1AEFF0 + 0x30FC = 0x1B2FEC);
 *   2. the register allocation: eight callee-saved registers, $fp used as a general
 *      register, a `div` with the trap check, and the loop's counter;
 *   3. the source of the `movz $fp,$v0,$a1`: the retail computes 4 or 6 from
 *      `state->0x182C ^ 2`, so the source is something like
 *      `fp = (a1 == 0) ? 6 : 4;` - that spelling has to be found.
 */
