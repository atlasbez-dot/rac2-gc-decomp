/* func_L20_004451C0 (1392 bytes, level 20): NOT ATTEMPTED in this wave; the body is
 * recovered below and the blockers are measured.
 *
 * THE BODY
 *
 *   void func_L20_004451C0(char *arg0)
 *
 *   The prologue is
 *
 *       addiu $sp,$sp,0x10 ; nop
 *       addiu $sp,$sp,0x20 ; nop
 *       addiu $sp,$sp,-0xD0
 *
 *   - a DYNAMIC frame: the source has an `alloca` (or a variable-length array), and
 *     the two `addiu` with a `nop` in the delay slot are the two halves of it.  This
 *     is the only function in this level that does it, and it is the first thing to
 *     reproduce: a C `alloca` is not standard C89, so the source must have had a
 *     compiler extension or the retail's own stack allocation;
 *   - the frame is then 0xD0 with $s0..$s7, $ra, $f20 (0.0f) and $f21 saved; $s2 =
 *     arg0, $s1 = state (arg0->0x68);
 *   - the first calls: func_00331BB8(0x10000, 0) whose result is the second argument
 *     of func_00331C18(arg0, result); then the float at state->0x20 is compared with
 *     0.0f and decremented (a `c.lt.s` + `bc1f`), then compared with 0.0f again
 *     (`c.le.s` + `bc1f`), and func_002A7750(arg0, 3, -1) is the fallback;
 *   - the body then runs the level's behaviour code: the word at arg0+0x96 is a
 *     counter that is incremented (`sh` at +0x96) while it is below 0xFFFE
 *     (`ori $v0,$zero,0xFFFE ; sltu`), and the last block restores the eight saved
 *     registers, $f21 and $f20.
 *
 * THE BLOCKERS
 *
 *   1. the dynamic frame: the two `addiu $sp,$sp,+0x10` / `+0x20` with a `nop` in the
 *      delay slot have to be found; a plain C `alloca` is not C89 and this cc1 may
 *      not have it;
 *   2. 1392 bytes is 348 instructions with more than twenty calls: the function has
 *      to be taken in blocks, and each block has to be matched against --diff
 *      separately;
 *   3. the register allocation of eight callee-saved registers plus two FPRs.
 */
