/* Near miss from src/levels/14_aranos_prison/L14_00304190.c — 2 words (8 bytes) differ.
 *
 * Kept as a starting point; not linked, not counted.
 *
 * Retail is 80 bytes; the body below compiles to 80 bytes and matches instruction
 * for instruction except two words, both about how GCC picks a branch sense:
 *
 *   003DE330  bgez $v0, +0x1C      |  bltz  $v0, +0x1C      (delay slot differs too)
 *   003DE340  c.ole.s $f0, $f1    |  c.olt.s $f1, $f0      or c.ole.s, depending on wording
 *
 * Everything structural is settled and worth keeping:
 *   - the loop runs four times: `n` starts at 3, is decremented once per
 *     iteration, and `p++` plus the `n >= 0` test sit *after* the body. So it is a
 *     do/while, and the `addiu $a1,$a1,-1` in the `beqz` delay slot runs even on
 *     the null-slot exit.
 *   - retail's `bgez` skips straight to the loop test at 0x3DE350, so both inner
 *     tests jump to the same block rather than branching into the body.
 *   - the float test is `f <= 0.0f` and `bc1tl` (branch-likely, on true) skips the
 *     clear, so the slot is cleared when the value is greater than zero. Getting
 *     `> 0.0f` in the C is what produces `bc1tl`; getting `<= 0.0f` is what
 *     produces `c.ole.s $f0, $f1`. No single wording tried produces both.
 *
 * Nine wordings were tried: nested `if` with `< 0`, with `>= 0` and empty else
 * branches, a single `&&` chain, and the block moved in and out of the `e != 0`
 * guard. The `<= 0.0f`-with-empty-else form gives `c.ole.s` but `bc1fl`; the
 * `&&` chain gives `bc1tl` but `c.olt.s`.
 *
 * What is left is GCC's branch-sense and static-likelihood choice, which tracks
 * the exact block layout rather than the C. Not yet tried: making the s8 test the
 * loop's own `continue` condition, or spelling the float test as `!(x > 0.0f)`.
 *
 * Wave 9 (p1) re-measured it: 80 bytes, 19 of 20 words identical, and the two words
 * left are the branch-likely form of BOTH inner tests (the retail has plain `bltz`
 * and `bc1f`; this cc1 emits `bltzl` and `bc1tl` and so copies the clear store into
 * each annulled delay slot, where the retail has one store).  Tried here: the `||`
 * form, the if/else-if form, the inverted test (>= 0), and a goto to a shared clear
 * block - all four reach the same two words.  One thing this wave measured: the
 * record pointer has to be a `char *`, not a `u32 *`, or the flag load comes out
 * `lb $v0,0x80($v1)` instead of `lb $v0,0x20($v1)`.
 *
 * Wave 24 (worker 06) re-measured it and adds the spelling that gives the
 * retail's instruction SEQUENCE exactly (every word, in retail's order), which
 * is one step closer than the body above:
 *
 *     void func_L14_003DE310(char *a0) {
 *         int *p = (int *)(*(int *)(a0 + 0x68) + 0xE0);
 *         int n = 3;
 *         float f1 = 0.0f;
 *         do {
 *             int *v = (int *)*p;
 *             n--;
 *             if (v != 0) {
 *                 if (*(s8 *)((char *)v + 0x20) < 0) {
 *                     *p = 0;
 *                 } else {
 *                     v = *(int *)((char *)v + 0x68);
 *                     if (*(f32 *)((char *)v + 0x40) <= f1) {
 *                         *p = 0;
 *                     }
 *                 }
 *             }
 *             p++;
 *         } while (n >= 0);
 *     }
 *
 * - the pointer at v+0x68 has to be LOADED into the same variable v
 *   (`v = *(int *)((char *)v + 0x68)`): that gives the retail's
 *   `lw $v1,0x68($v1)` and keeps the +0x40 out of the float load
 *   (`lwc1 $f0,0x40($v1)`).  Computing the address instead folds the two into
 *   `lwc1 $f0,0xA8($v1)` (76 bytes), and a separate variable for it gives
 *   `lw $v0,0x68($v1)`, which is the register the retail uses for the flag.
 * - the float test is `f0 <= f1` with f1 = 0.0f materialised before the loop
 *   (`mtc1 $zero,$f1`), and the clear happens when the test is true; that is
 *   the retail's `c.le.s $f0,$f1` and its polarity.  The retail's `bc1f` skips
 *   the clear when the test is false, and the clear block is shared with the
 *   bltz above it.
 * - what is left is only the branch-likely form of the two inner branches: this
 *   cc1 emits `bltzl` and `bc1tl` and copies the clear store into each
 *   annulled delay slot, where the retail has plain `bltz` and `bc1f` and one
 *   shared store block.  The delay-slot filler takes the single instruction of
 *   the branch target (the store) instead of the fall-through's first
 *   instruction (the lw), because the branch is predicted taken; the retail
 *   takes the fall-through, and the trapping load then sits in a plain delay
 *   slot.  Tried here with the spelling above: the if/else-if form, the
 *   `||`-chain of the two conditions, an explicit goto to a shared clear block
 *   and the inverted test - all four give the same two words. */
void func_L14_003DE310(char *a0) {
    u32 *p = (u32 *)(*(u32 *)(a0 + 0x68) + 0xE0);
    s32 n = 3;
    do {
        u32 e = *p;
        n--;
        if (e != 0 && *(s8 *)(e + 0x20) < 0) {
            if (*(float *)(*(u32 *)(e + 0x68) + 0x40) > 0.0f)
                *p = 0;
        }
        p++;
    } while (n >= 0);
}