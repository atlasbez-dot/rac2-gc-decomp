/* Wave 4 (worker 04): the candidate below is the wave-4 one - the zero guard works
   now and the body is the retail's 196 bytes; 21 of the 49 instructions differ,
   all of them the register allocation.  See the wave-4 note at the end. */
/* Near miss from src/levels/20_yeedil/L20_0043ECB0.c: 196 bytes of retail, 180
   bytes of candidate (four instructions short).

   This unit has no $gp access, so the body belongs here (-G0), not in the -G8
   sibling.

   What matches: the whole walk.  The table lookup
   (`D_L20_001FBB20[index]`, the `& 0xFF` guard, the `D_L20_001B2FB8` range
   guard, the null guard), the shared exit that returns the counter, the
   `base + ((id & 0x7FFF) << 8)` address, the `!= 6` and `>= 0` tests with
   the `movz` counter update, the `rec == 0` guard, the `bgezl`/`beql` pair
   that ends the walk, and the `daddu $v0,$a3,$zero` return are the retail's
   instructions, in the retail's registers.

   What is missing (four instructions):
   1. the retail tests a second flag inside the loop that this candidate
      cannot produce:
          daddu $t0, $zero, $zero    (before the loop)
          bnez   $t0, .L00440454     (at the bottom of the loop)
          nop
      The tested value is always zero, so the source spelling has to be one
      this cc1 cannot fold away.  Measured folded (the branch disappears):
      `int`/`u32`/`u16`/`u8`/`long long`/`u64` locals set to 0, a pointer set
      to 0, `flag != 0`, `index - index`, `m - m`, `rec - rec`, `count -
      count`, `index & 0`, `index ^ index`, `(u32)index * 0`, a `static`
      local, and the same flag declared `volatile`.  The retail's own
      `daddu $t0,$zero,$zero` + `bnez $t0` pattern occurs nowhere else in
      the game, so it is a rare source construct, not a common one.
   2. because that flag needs `$t0`, the retail copies the masked index out
      of it: `daddu $a2, $t0, $zero` (the retail compares `$a2` with 0xFF
      inside the loop, this candidate compares `$t0` in place).
   3. the retail loads the object bank base with an absolute
      `lui $t1,%hi(D_1B2F9C) ; lw $t1,%lo(D_1B2F9C)($t1)`; this candidate
      emits the same `lw` in a delay slot, where the assembler has to keep
      it `$gp`-relative (one instruction), so the base ends up in `$a2`
      instead of `$t1`.

   Spellings tried for the loop: `do { } while (cond)`, `for (;;)` with
   `goto`, the counter initialised before and after the guards (the retail
   initialises it after the masked index and before the first branch, so
   `int count = 0;` sits between them), a single `if (a && b && c)` around
   the loop, and the counter as a `u32`.  The `count` initialisation must
   stay before the first guard branch (the retail's `daddu $a3,$zero,$zero`
   is at +0x20) and the guards must share the single exit, which needs the
   counter to be unknown to this cc1 on the guard paths.

   The `||` in the walk condition is the retail's: `*(s16 *)(rec - 1) >= 0`
   or `rec == (u16 *)D_L20_001FBB20[index]`. */

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef signed short s16;
typedef int s32;

extern char *D_L20_001FBB20[];
extern unsigned int D_L20_001B2F9C;
extern int D_L20_001B2FB8;

int func_L20_00440398(int index) {
    int idx = index;
    u16 *rec = (u16 *)D_L20_001FBB20[idx];
    int m = idx & 0xFF;
    int count = 0;
    char *base;
    s32 flag;

    if (m == 0xFF) goto end;
    if (D_L20_001B2FB8 < idx) goto end;
    if (rec == 0) goto end;
    base = (char *)D_L20_001B2F9C;
    flag = index & ~index;
    do {
        u16 word = *rec;
        char *e = base + ((word & 0x7FFF) << 8);
        u8 c;

        if (e == 0) goto end;
        if (*(u8 *)(e + 0x20) == 6) goto skip;
        if (*(s8 *)(e + 0x20) >= 0) count++;
skip:;
        if (m == 0xFF) goto end;
        rec++;
        if (flag) goto end;
        if (rec == 0) goto end;
    } while (*(s16 *)(rec - 1) >= 0 || rec == (u16 *)D_L20_001FBB20[idx]);
end:
    return count;
}

/* ---- wave 3 (20_yeedil, 2026-10-20, worker 02): the always-zero guard, measured -----
 *
 * The walk is still the wave-2 candidate (180 bytes against the retail's 196: the
 * guard's three instructions and the copy of the masked index out of $t0 are missing).
 * What is new is what does NOT produce the guard:
 *
 *  - The assignment INSIDE the loop (`flag = 0;` at the top of the body, with
 *    `if (flag) goto end;` at the bottom) is hoisted out of the loop by the loop
 *    optimiser - and the branch is folded with it: both the assignment and the test
 *    disappear.  The hoisted copy would have been the retail's `daddu $t0,$zero,$zero`,
 *    but the test never survives the folding.
 *  - Twenty spellings of the flag were scanned in the loop's own context (int/u32/
 *    u16/s8/s16/s64/short/char/float/void-pointer/volatile/static locals, `flag`/`flag != 0`/
 *    `flag >= 0`/`flag > 0`/`!(flag == 0)`/`!!flag`/`flag ? 1 : 0` as the test, the
 *    flag assigned inside the loop, the flag assigned to itself, the flag as a
 *    `static`): every one of them is folded, and none leaves a `daddu $t0,$zero,$zero`
 *    behind.  The scan's output has no `bnez $t0` either.
 *  - What DOES keep a test alive, and is the way out for a similar guard: a 64-bit
 *    copy of an unknown 32-bit value (`s64 flag = x;` with `x` unknown) keeps the
 *    comparison (`bne $4,$0`) because the front end cannot fold a 64-bit comparison
 *    it cannot see through - but then the value is not zero and the retail's
 *    `daddu $t0,$zero,$zero` has no source.
 *  - The `x - x`/`x ^ x` family (with the two operands in two variables, in a struct,
 *    in an array, or one a copy of the other) is folded by the front end as well.
 *
 *  Conclusion so far: the retail's `daddu $t0,$zero,$zero` + `bnez $t0` is a branch on
 *  a value the compiler has just materialised as zero, and no plain-C spelling of a
 *  zero-valued local survives it in this cc1.  The same pattern appears in
 *  func_L20_0039E0A0 and func_L20_0039DBC8 (other units) - it is a game-wide idiom,
 *  so a construct that produces it is worth a search of its own.
 */

/* ---- wave 4 (20_yeedil, 2026-10-20, worker 04): the zero guard WORKS -----
 *
 * The zero guard is SOLVED: `s32 flag = index & ~index;` keeps the retail's
 * `daddu $t0,$zero,$zero` + `bnez $t0` (the front end does not fold `x & ~x`, and
 * `combine`, which does, runs after `gcse`).  With it the body compiles to the
 * retail's 196 bytes and every branch of the retail is there.  What is left is
 * the register allocation only (21 instructions of 49 differ).  Measured here:
 *
 *  - The guard needs a LOOP: the test must be in another block than the
 *    assignment.  Both placements keep the branch (the assignment before the
 *    loop, or the assignment at the top of the loop body, where the loop
 *    rotation splits the body): the second one puts the materialisation after
 *    the hoisted loop constants, which is the retail's order, but it does not
 *    change the allocation.
 *  - The `x & ~x` must be `s32` (a signed 32-bit local).  `int` works too.
 *  - The retail's `daddu $a2,$a0,$zero` at the top (the copy of the parameter
 *    into $a2) comes from an explicit `int idx = index;` in the source: with
 *    it the first five instructions, the `lw $a1,0($v1)` in the delay slot of
 *    the first `beq` and the `lui`/`addiu`/`sll`/`addu` order are the retail's.
 *    Without it the parameter stays in $a0 and four instructions differ.
 *  - The sign test of the class byte is `(s8)c >= 0` written as a SEPARATE
 *    `if` after a `goto skip` on `*(u8 *)(e + 0x20) == 6`: then the retail's
 *    `sll $v0,$v0,24` + `slti $v0,$v0,0x0` comes out.  The combined spelling
 *    `if (c != 6 && (s8)c >= 0)` gives `dsrl $v1,$v1,7` instead.
 *  - The `||` condition and the word read at the TOP of the body are what give
 *    the retail's branch-likely pair (`bgezl`/`beql`) and its loop rotation.
 *    The `do { word = *rec; ... } while (...)` spelling gives plain `bgez`/`beq`
 *    and a loop that is rotated one instruction further (the `andi` ends up in
 *    the second delay slot).
 *  - The two globals must be declared WITHOUT `sda` in this -G0 unit: with
 *    `sda` cc1 takes them through $gp (`lw $t1,0($gp)`), the retail loads them
 *    absolutely (`lui`+`lw`, base == dest).
 *
 * The residues (all register allocation, the sizes and the branches are right):
 *   retail: `lui $v0,%hi(D) ; addiu $v0,$v0,%lo(D) ; sll $v1,$a2,2 ; addu $v1,$v1,$v0`
 *   here:   `lui $v0,%hi(D) ; sll $v1,$a0,2 ; addiu $v0,$v0,%lo(D) ; addu $t0,$v1,$v0`
 *   - the table entry address is in $v1 in the retail and in $t0 here, and the
 *     scaled index is written into the same register in the retail and into a
 *     second one here;
 *   - the masked index is in $t0 in the retail and in $t1 here; the retail
 *     copies it out of $t0 into $a2 (`daddu $a2,$t0,$zero`, in the delay slot of
 *     the `beqz $a1`) because the flag takes $t0, here the flag takes $a0 and no
 *     copy is needed;
 *   - the retail's `daddu $a0,$v1,$zero` (the loop-invariant copy of the table
 *     entry address) is in $a2 here;
 *   - the two loop constants are in $t3/$t2 in the retail and $t3/$t0 here.
 */

/* ---- wave 5 (20_yeedil, 2026-10-21, worker 01): the guard is SOLVED, the body is the
 *    retail's 196 bytes, and only the register allocation is left -----------------------
 *
 * The candidate below compiles to the retail's EXACT size (196 bytes = 49 instructions)
 * and has every one of the retail's branches, in the retail's order: the table lookup
 * `D_L20_001FBB20[idx]`, the `& 0xFF` guard, the `D_L20_001B2FB8` range guard, the null
 * guard, the `base + ((id & 0x7FFF) << 8)` address, the `!= 6` and `>= 0` tests with the
 * `movz` counter update, the `rec == 0` guard, the `bgezl`/`beql` pair that ends the walk
 * and the `daddu $v0,$a3,$zero` return.  21 of the 49 instructions differ and EVERY one
 * of them is a register choice.  The zero guard works: `flag = index & ~index;` in
 * `s32` gives the retail's `daddu $t0,$zero,$zero` + `bnez $t0` (the front end does not
 * fold `x & ~x`, and `combine`, which does, runs after `gcse`), and the test has to be in
 * another block than the assignment, so the flag is tested at the bottom of the loop.
 *
 * WHAT THE RETAIL DOES THAT THIS C DOES NOT (the whole residue):
 *
 *   value                    | retail        | this cc1
 *   -------------------------+---------------+--------------
 *   the table entry address  | $v1 (coalesced| $t0 (a fresh
 *                             | with the      | register)
 *                             | `sll`)
 *   the masked index         | $t0, then     | $t1, never
 *                             | copied to $a2 | copied
 *   the copy of the masked   | $a2           | (none)
 *   index
 *   the base D_1B2F9C        | $t1           | $t2
 *   the second 0xFF          | $t2           | $t0 (the table
 *                             |               | address' old
 *                             |               | register)
 *   the zero guard's flag    | $t0 (the      | $a0 (a fresh
 *                             | masked index' | register)
 *                             | old register)
 *   the copy of the table    | $a0           | $a2
 *   entry address
 *
 * The retail COALESCES the table address with the shift that computes the index
 * (`sll $v1,$a2,2 ; addu $v1,$v1,$v0`), this cc1 does not (`sll $v1,$a2,2 ; addu $t0,$v1,$v0`),
 * and that one difference shifts every other choice in the function by one register.
 * The RTL is the same expression in both cases (`plus:SI (reg v1) (reg v0)`), so this is
 * the allocator's order, not a source shape.
 *
 * MEASURED AND REJECTED (all give the same 21 differences, the size stays 196):
 *   - the declaration order of the six locals (every order that keeps `idx` before `rec`);
 *   - `m` as a variable / `(idx & 0xFF)` inline in both tests, `m` from `index` instead
 *     of `idx`;
 *   - the flag before the loop / at the top of the loop body (the wave-3 note says the
 *     body placement changes where the materialisation lands but not the allocation);
 *   - `base` as a variable / the base inlined; `word` as a variable / inlined;
 *     `e` as `char *` / `unsigned char *` / `void *`; `word` as `unsigned short` / `short`
 *     / `int`; `count` and `flag` as `int` / `unsigned int` / `long` / `long long`;
 *   - the table's element type (`char *[]`, `u32 *[]` - the latter does not compile);
 *   - `rec` as `(unsigned short *)&D_L20_001FBB20[idx]` (48 differences - a different
 *     address form).
 * Per-file flags measured on a copy of the unit: `-fno-schedule-insns`,
 * `-fno-schedule-insns2`, `-fno-sched-interblock`, `-mno-split-addresses`, `-fno-gcse`,
 * `-mastra-keep-frame-order`, `-fno-expensive-optimizations`, `-O1` and `-G8` all change
 * the size (188, 188, 196, 188, 196, 196, 200, 208 and 188 bytes) and none of them
 * reaches the retail's 196 with the retail's registers.  The `-G8` unit also turns the
 * `D_L20_001B2FB8` load into a `$gp` load, which the retail does not have.
 *
 * THE C (it is the retail's body; only the register allocation is wrong):
 */

extern char *D_L20_001FBB20[];
extern unsigned int D_L20_001B2F9C;
extern int D_L20_001B2FB8;

int func_L20_00440398(int index) {
    int idx = index;
    unsigned short *rec = (unsigned short *)D_L20_001FBB20[idx];
    int m = idx & 0xFF;
    int count = 0;
    char *base;
    int flag;

    if (m == 0xFF) goto end;
    if (D_L20_001B2FB8 < idx) goto end;
    if (rec == 0) goto end;
    base = (char *)D_L20_001B2F9C;
    flag = index & ~index;
    do {
        unsigned short word = *rec;
        char *e = base + ((word & 0x7FFF) << 8);

        if (e == 0) goto end;
        if (*(unsigned char *)(e + 0x20) == 6) goto skip;
        if (*(signed char *)(e + 0x20) >= 0) count++;
skip:;
        if (m == 0xFF) goto end;
        rec++;
        if (flag) goto end;
        if (rec == 0) goto end;
    } while (*(signed short *)(rec - 1) >= 0 || rec == (unsigned short *)D_L20_001FBB20[idx]);
end:
    return count;
}
