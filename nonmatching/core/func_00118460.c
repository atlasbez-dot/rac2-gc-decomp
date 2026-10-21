/* from src/core/001163B0.c: C that compiles to 188 bytes where retail has 112
 * - and the gap is the compiler, not the source.
 *
 * A decimal counter advanced in place, right to left: with a zero length
 * nothing happens and 1 is returned; the last digit is set to '0' when it is
 * '5' or above, the 9s below it are cleared, and the first digit that is not a
 * 9 is incremented (returning the new character) or 0 is returned when that
 * digit is a 9.
 *
 * Retail's control flow is a peeled loop: the length test at +0, the digit
 * test at +0x10, one `sb` of '0' at +0x20, then the 9s loop as a
 * `beql $v0,$a2` back edge at +0x3C, the digit at +0x4C and the two returns
 * at +0x58 and +0x60.
 *
 * The first instruction is `blez $a1, 0x001184D0` - a branch into the next
 * function, func_001184D0 (the SDK's strrev, libc.a/vfprintf.obj in
 * config/datamine/ntsc-u-sdk-matches.tsv), whose result is returned: a
 * sibling call. The rebuilt compiler cannot make one: gcc/calls.c's
 * expand_call keeps `|| 1` under TARGET_ABI_UNSPECIFIED, and
 * -mastra-sibcall (tools/compiler/patches/0022-sibcall-default-off.patch)
 * only replaces the `mips_astra_no_sibcall` term, so the call stays a `jal`
 * with a frame, a `sd $ra` and a `ld $ra` - 76 bytes more than retail. The
 * same C with the call left as a call is what the body below is; the shape
 * of the body (the digit test, the 9s loop, the increment) is measured.
 *
 * With the call written as a plain call the candidate is 188 bytes: the
 * `jal`+frame prologue, then the digit test `slti $v0,$v0,0x35` and the
 * 9s loop, but the loop is not peeled the way retail has it and the final
 * increment returns the character where retail returns it as an int.
 *
 * Wave 24 (worker 07): the sibling call above is a misreading of the
 * listing.  Retail's first instruction is `blez $a1, .L001184C8` and
 * 0x001184C8 is *inside* this function: it is its last block, the
 * `jr $ra ; addiu $v0,$zero,0x1` that returns 1 (the same block the digit
 * test branches to).  So the body is a plain "if (len <= 0) return 1;"
 * and no call is involved; the 76 bytes the note measures are this
 * worker's own call, not retail's.
 *
 * With the call dropped and the entry restructured so that the "return 1"
 * block comes last in the source (the block order is what makes cc1 emit
 * `blez $a1, <the return 1 block>` with the main path falling through),
 * the candidate is 112 bytes - retail's exact size - and the digit test
 * and the two returns agree.  What is left, measured with the SDK profile
 * and with the game compiler (both give the same body here):
 *   - the 9s loop is peeled the other way: this cc1 emits the store of
 *     '0' in the delay slot of the `blez` and an extra copy of the body
 *     before the loop, where retail keeps one loop whose back edge is
 *     `beql $v0,$a2` with the store in its delay slot;
 *   - retail has three `nop`s between the digit load and that `beql`,
 *     this cc1 one;
 *   - the digit test is `slti $v0,$v0,0x35 ; bnez` in retail (the branch
 *     to the return 1) and `slt ; beq` here (the branch to the main path);
 *   - with the loop written as a `goto` the candidate is again 112 bytes
 *     but the store lands in the `blez`'s delay slot and the back edge is
 *     a plain `beq`, not retail's `beql`.
 *
 * The closest body so far (wave 24) is 116 bytes - four over - and agrees
 * with the retail instruction for instruction up to the 9s loop:
 *   blez $a1, <the return 1 block> ; addiu $a1,$a1,-0x1 ;
 *   addu $v1,$a0,$a1 ; lb $v0,0($v1) ; slti $v0,$v0,0x35 ;
 *   bnez $v0, <the return 1 block> ; addiu $v0,$zero,0x30 ;
 *   addiu $a3,$zero,0x39 ; sb $v0,0($v1)
 * with the failure block last in the source (`goto fail`), so that the
 * digit test branches to it.  What is left is the 9s loop: this cc1
 * peels it, keeps the store of '0' in the delay slot of the `blez` and
 * emits a second '0' constant, where retail keeps one loop, one '0'
 * constant, three `nop`s and the store in the delay slot of the `beql`
 * back edge.
 */
extern char *func_001184D0(char *arg0);

int func_00118460(char *buf, int len) {
    if (len <= 0)
        return func_001184D0(buf);
    len--;
    if (buf[len] < '5')
        return 1;
    buf[len] = '0';
    for (;;) {
        len--;
        if (len <= 0)
            break;
        if (buf[len] != '9')
            break;
        buf[len] = '0';
    }
    buf += len;
    if (*buf == '9')
        return 0;
    *buf = *buf + 1;
    return *buf;
}
