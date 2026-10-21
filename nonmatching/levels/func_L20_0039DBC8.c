#include "common.h"

/* Near miss from src/levels/20_yeedil/L20_0039C448.c (worker 07, level-20 wave of
   2026-10-20): 300 bytes in the retail, 268 bytes here.  The frame (0x30), the
   three saved registers (s0, s1, ra), the table lookup, the object search, the
   16-byte zero store (`sq $zero,0($sp)`), the two float calls and the branch
   structure are all there.  What is left:

     1. The register allocation.  The retail puts the found object in $s0 and the
        copy of the second argument in $s1; this cc1 puts the copy in $s0 and the
        found object in $s1 (and the same swap for $a3/$v1).  The instruction
        sequence of the prologue is otherwise the retail's, word for word.

     2. The test of a variable that is provably zero.  The retail keeps
        `daddu $t1,$zero,$zero` and `bnez $t1`; this cc1 folds the whole thing
        away.  Making the variable uninitialised and assigning it zero inside the
        search block does not help: the assignment dominates the test, so the
        constant is propagated and the branch goes away.  The same problem is
        reported for func_L20_0039E0A0.

     3. The conditional assignment after the last call.  The retail has
        `movz $s0,$zero,$v0` (if the call returned zero, clear the found object)
        and then returns it; this cc1 proves that the value returned is the
        call's result and drops the conditional move.  A source shape that keeps
        the move was not found (the ternary and the `if` form both fold).

     4. The branch-likely delay slots in the list walk.  The retail has
        `bgezl $v0,loop / lhu $v0,0($a2)` and `beql $a2,$v0,loop / lhu $v0,0($a2)`;
        this cc1 emits the plain `bgez` with a nop and keeps the loads apart.

     5. The global accesses.  The retail loads D_L20_001B2FB8 and
        D_L20_001B2F9C as `lui $v0,%hi(S) ; lw $v0,%lo(S)($v0)` - one register
        for both halves.  With `__attribute__((sda))` this cc1 emits the $gp
        relative form for one of the two and the lui/lw form for the other; which
        of the two comes out in which form depends on the declaration, so the
        pair needs the double-name pattern to be pinned down.

   This body belongs in the `-G8` unit?  No: it reaches no global through $gp.
*/

typedef int TI128_w07 __attribute__((mode(TI)));

extern int D_L20_001BB20[];

extern int D_L20_001B2FB8_b __asm__("D_L20_001B2FB8") __attribute__((sda));

extern float D_L20_0012E20[];

extern int func_L20_0039DCF8(char *, char *, void *);

extern float func_00283248(float, float);

void func_L20_0039DBC8(s32 a0, s32 a1, char *arg2) {
    char *s0 = 0;
    char *s1 = arg2;
    u32 a3 = a1 & 0xFF;
    char *p = (char *)D_L20_001BB20[a1];
    int t1;
    u16 w;
    char *q;
    char *base;
    s32 v0;

    if (a3 != 0xFF) {
        if (D_L20_001B2FB8_b < a1) {
            goto after;
        }
        if (p == 0) {
            goto after;
        }
        base = D_L20_001B2F9C;
        t1 = 0;
        w = *(u16 *)p;
        q = base + ((w & 0x7FFF) << 8);
        if (q == 0) {
            goto after;
        }
        if (*(u8 *)(q + 0x20) != 6) {
            goto check;
        }
        s0 = q;
        *(s32 *)(s0 + 0xB8) = a0;
    }
check:
    if (a3 == 0xFF) {
        goto after;
    }
    p += 2;
    if (t1 != 0) {
        goto after;
    }
    while (p != 0) {
        if (*(s16 *)(p - 2) >= 0) {
            continue;
        }
        v0 = *(u16 *)p;
        if (p == (char *)D_L20_001BB20[a1]) {
            continue;
        }
        v0 = *(u16 *)p;
        break;
    }
after:
    if (s0 != 0) {
        TI128_w07 buf = 0;
        f32 f1 = *(f32 *)s1;
        f32 f0 = *(f32 *)(s1 + 4);
        *(f32 *)((char *)&buf + 8) = func_00283248(
            *(f32 *)((char *)D_L20_0012E20 + 0x80) - f1,
            *(f32 *)((char *)D_L20_0012E20 + 0x84) - f0);
        if (func_L20_0039DCF8(s0, s1, &buf) == 0) {
            s0 = 0;
        }
    }
    return s0;
}

/* ---- level-20 wave 3, worker 05 (2026-10-20): point 2 (the zero guard) is SOLVED ----
 *
 * The construct that keeps a test on a value the compiler proves is zero is
 *
 *     s32 flag = arg1 & ~arg1;
 *
 * The front end does not fold `x & ~x` (gcc/fold-const.c's fold() has no case for
 * BIT_AND with a non-constant second operand) and neither does the CSE; only
 * `combine` folds it, and combine runs AFTER gcse (toplev.c: cse -> gcse -> loop ->
 * cse2 -> flow -> combine_instructions).  gcse's cprop is the pass that would
 * otherwise propagate the constant 0 into the search loop and delete the branch, so
 * with `x & ~x` the zero is materialised in the register (`daddu $t1,$zero,$zero`)
 * and the retail's `bnez $t1` survives.  Measured on func_L20_0039E0A0: with
 * `flag = 0` the guard and its zeroing disappear (176 bytes against retail's 184);
 * with `flag = arg0 & ~arg0` both are there and every branch matches.
 *
 * The other three functions of the family need the same spelling
 * (func_L20_0039E0A0, func_L20_00440398, func_L20_0044AC38).
 *
 * What is still open here is the rest of the note above (the register allocation, the
 * conditional move after the last call, the branch-likely delay slots and the two
 * global accesses) plus the 128-bit copy wall: the retail materialises the copy
 * source with `addiu $a2,$a1,0x60` and copies with a zero offset, and every
 * spelling we tried folds the offset back into the lq (see
 * nonmatching/levels/func_L20_0043D470.c for the measurements). */

/* ---- level-20 wave 4, worker 05 (2026-10-20): 308 bytes against the retail's 300 ----
 *
 * The zero guard (point 2 above) is confirmed and used: `s32 flag = arg0 & ~arg0;`
 * assigned inside the search block, just before the walk, gives the retail's
 * `daddu $t1,$zero,$zero` and its `bnez $t1` - and the assignment must sit there, after
 * the three early exits, or the compiler hoists the zero into the first branch's delay
 * slot instead of the retail's `addiu $t2,$zero,0xFF / daddu $t1,$zero,$zero` pair.
 *
 * What this wave measured and what still differs (the attempt above is unchanged and
 * is still the closest one):
 *
 *  1. THE 128-BIT COPY IS NOT THE WALL HERE.  This body has no 16-byte copy of a
 *     constant offset: the only `sq` is the zero store `sq $zero,0($sp)`, which the
 *     chain's rac2_fold_zero_ti_store folds for us, and the copy that the retail does
 *     (func_L20_0039DCF8 copies the 16-byte buffer) is a call, not a TI access.  So the
 *     128-bit copy wall does not block this function; what blocks it is the register
 *     allocation, the branch-likely delay slots and one float.
 *
 *  2. THE FLOAT.  The retail loads `arg2[1]` once into $f0, uses it for the call's
 *     fourth argument (`sub.s $f13,$f13,$f0`) and stores it at +8 of the buffer AFTER
 *     the call - without spilling it, although a call clobbers $f0.  This cc1 always
 *     moves a float that is live across a call into $f20 (a callee-saved register) and
 *     spills it (measured: `swc1 $f20,0x30($sp)` in the prologue, `lwc1 $f20,0x30($sp)`
 *     in the epilogue).  Three source shapes were measured: the store before the call
 *     (the compiler keeps the store before the call, 316 bytes), the store after the
 *     call with the value in a variable (308 bytes, the float spilled) and the store
 *     after the call with a fresh load of `arg2[1]` (320 bytes, two `lwc1`).
 *
 *  3. THE LOOP IS ROTATED.  The retail's walk has ONE copy of the header (`andi
 *     $v0,$v0,0x7FFF / sll $v0,$v0,8 / addu $a1,$t0,$v0` at the label the two
 *     back-edges jump to) and the back edges are `bgezl`/`beql` with `lhu $v0,0($a2)`
 *     in their delay slots.  This cc1 rotates the loop: the entry point is the `lhu`,
 *     the back edge lands on a SECOND copy of the header, and the branches are the plain
 *     `bgez`/`beq` with the `lhu` in the delay slot of the first one only.  The
 *     `for(;;)`, `do {...} while (1)` and `goto` spellings of the walk were measured: the
 *     `do` form puts the branch-likely on the `== 6` test instead of on the two
 *     back-edges, the `for` form on the same test as well, and the `goto` form on
 *     neither.
 *
 *  4. THE REGISTER ALLOCATION.  The retail keeps the found object in $s0, the copy of
 *     the second argument in $s1, the table index in $a3, the flag in $t1, the 0xFF in
 *     $t2, the 6 in $t3 and the object base in $t0.  This cc1 gives the same values
 *     different registers ($s1/$s0 swapped, the index in $t0, the flag in $t0), and it
 *     needs a third callee-saved register ($s2) for the found object, which is why the
 *     frame is 0x40 against the retail's 0x30.
 *
 *  This body belongs in the `-G8` unit?  No: it reaches no global through $gp. */

/* ------------------------------------------------------------------
   level-20 wave of 2026-10-21, worker 07: 296 bytes against the retail's
   300, and the zero guard confirmed.

   1. THE GLOBAL IS WRONG IN THE ATTEMPT ABOVE.  The retail reads
      `lui $v0,%hi(D_189E20) ; addiu $v0,$v0,%lo(D_189E20)` - that is the
      BOOT's resident data, `D_00189E20`, not a level symbol.  The
      attempt above uses `D_L20_0012E20`, whose address is a different
      one, so the `lui`/`addiu` pair does not match.  With `D_00189E20` the
      float part comes out as the retail's:

        lui $v0,%hi(D) ; lwc1 $f1,0x0($s1) ; addiu $v0,$v0,%lo(D) ;
        lwc1 $f0,0x4($s1) ; lwc1 $f13,0x84($v0) ; lwc1 $f12,0x80($v0)

      and the two `lwc1`s come out of the global's address with the
      offsets as displacements - so the source needs a POINTER to the
      global (`f32 *g = (f32 *)D_00189E20;` and `g[32]`, `g[33]`), not
      two `(char *)D_00189E20 + 0x80` expressions: the CSE merges the two
      addresses and folds them into one base plus one displacement.

   2. THE TABLE ENTRY IS LOADED TWICE in the retail (once in the delay
      slot of the first branch, once inside the loop), so the source has
      a pointer to the ENTRY and not to the table:

        char **pe = D_L20_001FBB20 + a1;   /* lui %hi ; addiu %lo ;
                                              sll $v1,$a1,2 ; addu $v1,$v1,$v0 */
        char *p = *pe;                    /* lw $a2,0x0($v1) */

      and the comparison in the loop is `p == *pe`.  With the table used
      directly (`D_L20_001FBB20[a1]` twice) the compiler materialises the
      global's address TWICE (two `lui`s) and the body grows.

   3. THE WALK.  The zero guard is confirmed: `s32 flag = a1 & ~a1;`
      assigned inside the search block, just before the walk, gives the
      retail's `daddu $t1,$zero,$zero` and its `bnez $t1`.  The FIRST
      back edge comes out as the retail's `bgezl` with the `lhu` in its
      delay slot.  The SECOND back edge does NOT: this cc1 emits
      `bne $a2,$v0,skip` + `nop` + `b exit` + `lhu` where the retail has
      `beql $a2,$v0,loop` + `lhu`.  Measured and all folding: `if (p == *pe)
      { w = *(u16 *)p; continue; }`, `if (*pe == p) {...}`, `if (p != *pe)
      { goto after; } else { w = ...; continue; }`, `if (!(p != *pe))
      {...}` and a labelled `goto` - the polarity does not change.

   4. THE REGISTER ALLOCATION is what is left, and it is the wall:
      the retail keeps the found object in $s0, the copy of the second
      argument in $s1, the masked index in $a3, the object base in $t0,
      the guard's flag in $t1, the 0xFF in $t2 and the 6 in $t3; this cc1
      gives the argument $s0 and the found object $s1 (the two swapped),
      the index $t0, the base $t2 and the flag $a3.  Measured and all
      folding: swapping the order of the two declarations, assigning the
      zero to the found object later, assigning the argument's copy
      inside the `if`, moving the store before the assignment, and using
      two different C names for the object pointer in the two branches.
      The save ORDER in the prologue is the retail's in every variant
      (s0, s1, s4, s3, ra, s2), so only the ROLES of the registers
      differ.

   5. THE 128-BIT COPY IS NOT THE WALL HERE (confirmed again): the only
      `sq` is the zero store `sq $zero,0($sp)`, a stack slot at offset 0,
      which the chain's rac2_fold_zero_ti_store gives for free.

   This body belongs in the `-G8` unit?  No: it reaches no global through
   `$gp`.
   ------------------------------------------------------------------ */

/* The candidate below is the near miss of this wave: 296 bytes against the
   retail's 300 (the wave-3 attempt above is 308 bytes but uses the wrong
   global). */

typedef int TI128_w07 __attribute__((mode(TI)));

extern char *D_L20_001FBB20[];
extern int D_L20_001B2FB8;
extern char *D_L20_001B2F9C;
extern char D_00189E20[];
extern int func_L20_0039DCF8(char *, char *, void *);
extern float func_00283248(float, float);

void func_L20_0039DBC8_w07(s32 a0, s32 a1, char *arg2) {
    char *s0 = 0;
    char *s1 = arg2;
    u32 a3 = a1 & 0xFF;
    char **pe = D_L20_001FBB20 + a1;
    char *p = *pe;
    char *base = D_L20_001B2F9C;
    s32 flag;
    u16 w;
    char *q;

    if (a3 != 0xFF) {
        if (D_L20_001B2FB8 < a1) {
            goto after;
        }
        if (p == 0) {
            goto after;
        }
        flag = a1 & ~a1;
        w = *(u16 *)p;
        for (;;) {
            q = base + ((w & 0x7FFF) << 8);
            if (q == 0) {
                goto after;
            }
            if (*(u8 *)(q + 0x20) == 6) {
                s0 = q;
                *(s32 *)(s0 + 0xB8) = a0;
                goto after;
            }
            p += 2;
            if (a3 == 0xFF) {
                goto after;
            }
            if (flag != 0) {
                goto after;
            }
            if (p == 0) {
                goto after;
            }
            if (*(s16 *)(p - 2) >= 0) {
                w = *(u16 *)p;
                continue;
            }
            if (p == *pe) {
                w = *(u16 *)p;
                continue;
            }
            goto after;
        }
    }
after:
    if (s0 != 0) {
        TI128_w07 buf = 0;
        f32 *g = (f32 *)D_00189E20;
        f32 f1 = *(f32 *)s1;
        f32 f0 = *(f32 *)(s1 + 4);
        *(f32 *)((char *)&buf + 8) = func_00283248(g[32] - f1, g[33] - f0);
        if (func_L20_0039DCF8(s0, s1, &buf) == 0) {
            s0 = 0;
        }
    }
    return;
}
