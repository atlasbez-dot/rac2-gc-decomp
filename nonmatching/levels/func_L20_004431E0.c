/* Near miss from src/levels/20_yeedil/L20_0043ECB0-g8.c: 324 bytes of retail,
   324 bytes of candidate (the same size, the instructions differ from +0xc).

   The body reaches a global through $gp (the limit at 0x1AEFF0 + 0x3FC8), so it
   belongs in the -G8 sibling.

   The shape is the retail's: the table lookup `D_L20_001FBB20[state->0x218]`,
   the `& 0xFF` guard, the `D_L20_001B2FB8` range guard, the null guard, the
   `*(s16 *)(rec - 1) >= 0` and `rec == D_L20_001FBB20[idx]` pair, the
   `base + ((id & 0x7FFF) << 8)` address, the call to func_003BA3F8 with the
   `movn` that keeps the entry, the 16-byte copy of the second argument into
   the entry, the three calls and the 0.5f adjustment of the float at +8 of the
   copy.

   What differs is the register allocation and the order of the first block:
   the retail computes the table base in `$v0` (`lui $v0` + `addiu $a0,$v0`), the
   state in `$a2` and the index in `$v1`, and copies the table base into `$a3`
   in the delay slot of the jump to the guard block; the candidate computes the
   table base in `$v1` (with the `addiu` in the same register) before the state
   is loaded, and keeps the index in `$v0`/`$a3`.

   Measured (2026-10-20): the guard block has to be a separate block reached
   by a jump, with the body block laid out before it - a `goto` into a block
   gives the retail's order where an `if` does not.  The index must be read
   twice, once in the first block and once in the guard block, and this cc1
   folds the two reads into one unless the guard's read is `volatile` (the
   retail reads `state->0x218` twice and the table entry twice as well).

typedef unsigned short u16;
typedef signed short s16;

extern char *D_L20_001FBB20[];

extern char *D_L20_001B2F9C;

extern int D_L20_001B2FB8 __attribute__((sda));

extern int func_003BA3F8(char *);

extern void func_003BA368(char *);

extern void func_002FFA70(char *, char *, char *, int, int);

extern void func_0039BDF0(char *, char *, int, int, float);

void func_L20_004431E0(char *arg0, TI128 *arg1) {
    char *state = *(char **)(arg0 + 0x68);
    u16 *rec = (u16 *)D_L20_001FBB20[*(int *)(state + 0x218)];
    char *found = 0;
    TI128 buf;
    int idx;

    goto check;
body:
    {
        char *e = (char *)D_L20_001B2F9C + ((*rec & 0x7FFF) << 8);

        if (e != 0) {
            if (func_003BA3F8(e) != 0) {
                found = e;
            }
        }
    }
    goto end;
check:
    idx = *(volatile int *)(state + 0x218);
    if ((idx & 0xFF) == 0xFF) {
        goto end;
    }
    if (D_L20_001B2FB8 < idx) {
        goto end;
    }
    if (rec == 0) {
        goto end;
    }
    if (*(s16 *)(rec - 1) >= 0 || rec == (u16 *)D_L20_001FBB20[idx]) {
        goto body;
    }
end:
    if (found != 0) {
        char *p = found + 0x10;
        char *s2;

        *(TI128 *)p = *arg1;
        func_003BA368(found);
        func_002FFA70(found, p, found + 0xF0, 0, 0);
        s2 = *(char **)(found + 0x68);
        *(int *)(s2 + 0xAC) |= 8;
        buf = *(TI128 *)p;
        *(float *)((char *)&buf + 8) -= 0.5f;
        func_0039BDF0(found, (char *)&buf, 0x168, 0, *(float *)((char *)&buf + 8));
    }
    return found;
}

/* ---- wave 3 (20_yeedil, 2026-10-20, worker 02): the first block, re-measured -------
 *
 * The candidate is still the retail's exact 324 bytes with the instructions differing
 * from +0xc, and the difference is the register allocation and the ORDER of the first
 * block only.  What was measured:
 *
 *  - The retail's first block is: `lui $v0,%hi(D_1FBB20)` (the %hi in $v0), the state
 *    in $a2, the index in $v1, `addiu $a0,$v0,%lo(D_1FBB20)` (the table's base in $a0),
 *    the record in $a1, then `b .L0044324C` with `daddu $a3,$v0,$zero` (the %hi
 *    copied) in the delay slot.  This compiler materialises the whole address in one
 *    register (`lui $v1,%hi; addiu $v1,$v1,%lo`) early in the prologue and copies the
 *    %hi into $t0 there, and it folds the `& 0xFF` test into the first block (the
 *    retail keeps it in the guard block the jump goes to).
 *  - The retail's split form (`%hi` in one register, the address in another, and the
 *    %hi copied for the second use) is the "split 64-bit la" wall of
 *    docs/COMPILER-NOTES.md; `-mno-split-addresses` gives the opposite shape (the
 *    address in one register), so no per-file flag reaches the retail's form here.
 *  - The index has to be read twice (once in the first block, once in the guard block);
 *    the guard's read must be `volatile` or this cc1 folds the two reads into one.
 *    That is in the candidate.
 *  - Measured and not enough: the table's element type (`u32 *` and `char *`), the
 *    index's type (`int`/`u32`), the volatile read as `volatile int` vs
 *    `volatile u32`, and the `-mno-split-addresses` profile (which changes the whole
 *    first block).
 */

/* Near miss from src/levels/20_yeedil/L20_0043ECB0-g8.c (wave 4, 20_yeedil, 2026-10-20,
   worker 02): the candidate is 320 bytes against retail's 324.

   What the wave-4 candidate settles:
   - func_0039BDF0 takes FOUR arguments, not five: retail's last call is
     `jal f_0039BDF0` with $a0 = found, $a1 = &buf, $a2 = 0x168, $a3 = 0 and the float
     that the call's delay slot stores (`swc1 $f0,0x8($sp)`) is the `buf`'s float field,
     not an argument.  With a fifth float argument this cc1 adds a `mov.s $f12,$f0` and
     the frame grows; with four arguments the float stays in $f0 and the candidate is one
     instruction shorter than the wave-3 note's.
   - The frame is 0x30 with $s0, $s1, $s2 and $ra saved, exactly as retail.
   - The index at state+0x218 is read twice, as retail does: once for the table lookup in
     the entry block and once in the guard block.  The guard's read has to be `volatile`,
     or this cc1 folds the two reads into one.
   - The body's shape is retail's: `e = D_L20_001B2F9C + ((*rec & 0x7FFF) << 8)`, the
     `beqz` on it, the call to func_003BA3F8 with the `daddu $a0,$s0,$zero` in the delay
     slot, the `daddu $s1,$zero,$zero` in the call's delay slot and the `movn $s1,$s0,$v0`
     that keeps the entry.
   - The 16-byte copy into found+0x10 and the float's `-0.5f` come out with the zero
     displacement (`lq $v0,0x0($s2)` ; `sq $v0,0x0($s0)`), because the destination
     pointer is loaded from memory (the `plus(reg,const)` the CSE substitutes is not
     there).

   What still differs:
   - The FIRST block.  Retail keeps the %hi of D_L20_001FBB20 in $v0 and adds the %lo at
     each use (`addiu $a0,$v0,%lo(D_1FBB20)` in the entry, `daddu $a3,$v0,$zero` in the
     jump's delay slot and `addiu $v0,$a3,%lo(D_1FBB20)` in the guard block); the candidate
     materialises the whole address in one register (`lui $v1,%hi` ; `addiu $v1,$v1,%lo`).
     The "second C name" escape does not reach retail's form here: it only removes the
     early copy of the %hi.
   - The guard block is CROSS-JUMPED into the first block: the candidate's first block
     holds the guard's `andi`/`beq` and the guard block only holds the rest, while retail
     jumps to the guard block and keeps the whole guard there.  This is gcc's
     `cross_jump` in jump.c, and it is what makes the candidate four bytes short.
   - The `lw $v0,0xAC($a0)` / `ori $v1,$v1,0x8` / `sw $v1,0xAC($a0)` of the tail: retail
     loads the object into $a0 and works on it there, the candidate loads it into $t0 and
     copies found into $a0.

   The candidate (a -G8 unit: the limit D_L20_001B2FB8 is read through $gp):

typedef int TI128 __attribute__((mode(TI)));

typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u32 *D_L20_001FBB20[];

extern u32 D_L20_001B2F9C;

extern int D_L20_001B2FB8 __attribute__((sda));

extern int func_003BA3F8(char *);

extern void func_003BA368(char *);

extern void func_002FFA70(char *, char *, char *, int, int);

extern void func_0039BDF0(char *, char *, int, int);

void func_L20_004431E0(char *arg0, TI128 *arg1) {
    char *state = *(char **)(arg0 + 0x68);
    u16 *rec = (u16 *)D_L20_001FBB20[*(int *)(state + 0x218)];
    char *found = 0;
    TI128 buf;
    int idx;

    goto check;
body:
    {
        char *e = (char *)D_L20_001B2F9C + ((*rec & 0x7FFF) << 8);

        if (e != 0) {
            if (func_003BA3F8(e) != 0) {
                found = e;
            }
        }
    }
    goto end;
check:
    idx = *(volatile int *)(state + 0x218);
    if ((idx & 0xFF) == 0xFF) {
        goto end;
    }
    if (D_L20_001B2FB8 < idx) {
        goto end;
    }
    if (rec == 0) {
        goto end;
    }
    if (*(s16 *)(rec - 1) >= 0) {
        goto body;
    }
    if (rec == (u16 *)D_L20_001FBB20[idx]) {
        goto body;
    }
    goto end;
end:
    if (found != 0) {
        char *p = found + 0x10;
        char *s2;

        *(TI128 *)p = *arg1;
        func_003BA368(found);
        func_002FFA70(found, p, found + 0xF0, 0, 0);
        s2 = *(char **)(found + 0x68);
        *(int *)(s2 + 0xAC) |= 8;
        buf = *(TI128 *)p;
        *(float *)((char *)&buf + 8) -= 0.5f;
        func_0039BDF0(found, (char *)&buf, 0x168, 0);
    }
    return found;
}

/* ---- wave 5 (20_yeedil, 2026-10-21, worker 01): the SPLIT ADDRESS is SOLVED --------
 *
 * The wave-4 note called the split address "the split 64-bit la wall of
 * docs/COMPILER-NOTES.md" and said that no per-file flag reaches the retail's form.  The
 * corrected rule in the wave-5 common file WORKS, and it is a SOURCE rule:
 *
 *   a second ASSIGNMENT of the same symbol, with a use after it, splits the address:
 *   the `%hi` is materialised ONCE in a register and the `%lo` is added at EVERY use.
 *
 * With one assignment of `D_L20_001FBB20` used twice, this cc1 materialises the whole
 * address once (`lui $v1,%hi ; addiu $v1,$v1,%lo`) and uses that register twice - the
 * wave-4 candidate.  With a SECOND assignment of the symbol (a re-assignment after the
 * nested body block, with a use after it) the compiler emits the retail's form:
 *
 *   retail:  lui $v0,%hi(D_1FBB20) ; ... ; addiu $a0,$v0,%lo(D_1FBB20)   (use 1)
 *            ... ; daddu $a3,$v0,$zero                                  (the %hi copied)
 *            ... ; addiu $v0,$a3,%lo(D_1FBB20)                          (use 2)
 *   here:    lui $v0,%hi(D_1FBB20) ; ... ; addiu $a3,$v0,%lo(D_1FBB20)   (use 1)
 *            ... ; daddu $t0,$v0,$zero                                  (the %hi copied)
 *            ... ; addiu $a3,$t0,%lo(D_1FBB20)                          (use 2)
 *
 * The mechanism is the `movsi` expand of gcc 1.1's mips.md: a symbol address moved into
 * a register becomes `tem = HIGH(symbol)` and `LO_SUM(tem, symbol)`, so the `%hi` is one
 * expression (the CSE merges the two HIGHs) while the two LO_SUMs stay separate.  A
 * single assignment makes the two uses share ONE LO_SUM, which is why the wave-4
 * candidate did not split.
 *
 * The candidate with the second assignment is 320 bytes against the retail's 324: the
 * four missing bytes are the `b .L0044324C` at the end of the retail's first block.  This
 * cc1 CROSS-JUMPS the guard block into the first block (gcc's `cross_jump` in jump.c
 * moves the code before the `check` label up to the jump), so the first block ends with
 * the guard's `andi`/`beq` instead of a jump, and the guard's tail ends up after the body
 * block.  The retail keeps the whole guard in its own block, with the body block laid
 * out between the first block and the guard.
 *
 * MEASURED AND REJECTED: the source order of the three blocks (the body before the
 * guard, the guard before the body, and a `for (;;)` with the table lookup at the top of
 * the body) all cross-jump the guard into the first block (308, 312 and 312 bytes).  The
 * `beql` of the last test needs the two `if (...) goto body;` statements to be separate
 * (with one `||` it comes out as a plain `bne`).
 *
 * The remaining difference after the split is the register allocation of the first
 * block: the retail keeps the `%hi` in $v0, the table base in $a0 and the record in $a1,
 * and copies the `%hi` into $a3 in the delay slot of the jump; this cc1 keeps the `%hi`
 * in $v0 but puts the table base in $a3, the copy of the `%hi` in $t0 (in the prologue,
 * not in the jump's delay slot) and the second use in $a3.
 *
 * The candidate (a -G8 unit: the limit D_L20_001B2FB8 is read through $gp):
 */

typedef int TI128 __attribute__((mode(TI)));
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u32 *D_L20_001FBB20[];
extern u32 D_L20_001B2F9C;
extern int D_L20_001B2FB8 __attribute__((sda));
extern int func_003BA3F8(char *);
extern void func_003BA368(char *);
extern void func_002FFA70(char *, char *, char *, int, int);
extern void func_0039BDF0(char *, char *, int, int);

void func_L20_004431E0(char *arg0, TI128 *arg1) {
    char *state = *(char **)(arg0 + 0x68);
    u32 *tbl = D_L20_001FBB20;
    u16 *rec = (u16 *)tbl[*(int *)(state + 0x218)];
    char *found = 0;
    TI128 buf;
    int idx;

    goto check;
body:
    {
        char *e = (char *)D_L20_001B2F9C + ((*rec & 0x7FFF) << 8);

        if (e != 0) {
            if (func_003BA3F8(e) != 0) {
                found = e;
            }
        }
    }
    goto end;
check:
    idx = *(volatile int *)(state + 0x218);
    if ((idx & 0xFF) == 0xFF) {
        goto end;
    }
    if (D_L20_001B2FB8 < idx) {
        goto end;
    }
    if (rec == 0) {
        goto end;
    }
    if (*(s16 *)(rec - 1) >= 0) {
        goto body;
    }
    tbl = D_L20_001FBB20;
    if (rec == (u16 *)tbl[idx]) {
        goto body;
    }
    goto end;
end:
    if (found != 0) {
        char *p = found + 0x10;
        char *s2;

        *(TI128 *)p = *arg1;
        func_003BA368(found);
        func_002FFA70(found, p, found + 0xF0, 0, 0);
        s2 = *(char **)(found + 0x68);
        *(int *)(s2 + 0xAC) |= 8;
        buf = *(TI128 *)p;
        *(float *)((char *)&buf + 8) -= 0.5f;
        func_0039BDF0(found, (char *)&buf, 0x168, 0);
    }
    return found;
}
