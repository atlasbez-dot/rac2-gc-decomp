/* func_L20_00445738 (344 bytes, level 20): near miss - ONE register swap away.
 *
 * The candidate below is the retail's structure instruction for instruction: the dispatch,
 * the jump table, the five case bodies, the shared tail and the two exit blocks are all in
 * the retail's order with the retail's calls, and every instruction of the body matches
 * (the diff stops at the prologue).  The only difference is the two callee-saved registers:
 * the retail keeps the argument copy in $s0 and the state pointer in $s1, this cc1 keeps
 * the state pointer in $s0 and the argument copy in $s1.  The offsets of the two saves are
 * the same (0x0 and 0x8); only the registers - and so the order of the two `sd`s - differ.
 *
 * The candidate:
 *
 *     extern void *jtbl_002B5960[5];
 *     ...
 *     void func_L20_00445738(char *arg0) {
 *         static void * volatile tab[] = { &&c0, &&c1, &&c2, &&c3, &&c4 };
 *         char *s0 = arg0;
 *         char *s1;
 *         unsigned char sel;
 *         int n;
 *
 *         sel = *(unsigned char *)(s0 + 0x20);
 *         s1 = *(char **)(s0 + 0x68);
 *         if (sel >= 5) {
 *             goto end;
 *         }
 *         goto *jtbl_002B5960[sel];
 *     c0:
 *         *(float *)(s1 + 0x10) = *(float *)(s0 + 0x10);
 *         func_002A7750(s0, 1, -1);
 *         goto out;
 *     c1:
 *         if ((D_0019B2E8[*(unsigned char *)(s0 + 0xB0) + *(int *)0x001A79F0 * 16] & 0x80) == 0) {
 *             goto end;
 *         }
 *         n = 2;
 *         goto shared;
 *     c2:
 *         if (func_002B3868(s0) != 0) {
 *             *(int *)(s1 + 0x14) = 0;
 *             func_002E5CF8(0, 0, s0);
 *         }
 *         func_002AA548(s0 + 0x10, s1 + 0x14,
 *                       *(float *)(s1 + 0x10) - *(float *)(s1 + 0x0),
 *                       *(float *)(s1 + 0x8), *(float *)(s1 + 0x8),
 *                       *(float *)(s1 + 0xC));
 *         goto out;
 *     c3:
 *         if (func_002B38B8(s0) == 0) {
 *             goto end;
 *         }
 *         n = 4;
 *     shared:
 *         func_002A7750(s0, n, -1);
 *         goto out;
 *     c4:
 *         if (func_002B3868(s0) != 0) {
 *             func_002E5CF8(0, 0, s0);
 *             *(int *)(s1 + 0x14) = 0;
 *         }
 *         func_002AA548(s0 + 0x10, s1 + 0x14, *(float *)(s1 + 0x10),
 *                       *(float *)(s1 + 0x8), *(float *)(s1 + 0x8),
 *                       *(float *)(s1 + 0xC));
 *         goto out;
 *     end:
 *     out:
 *         return;
 *     }
 *
 * The function is the twin of the matched func_L20_00446E70 (same table shape, same five
 * behaviours, the same D_0019B2E8 test); it adds the func_002E5CF8 call in the last two
 * cases and shares the func_002A7750 call between the first and the fourth case through
 * the variable `n` (2 and 4).
 *
 * WHAT WAS MEASURED
 * - The two `$s0`/`$s1` are decided by gcc's global allocator, and the decision moves
 *   with the register pressure, not with the order of the source: the same body compiled
 *   with the state's floats read into locals at the top of the function (so that four
 *   float locals are live across the calls) puts the ARGUMENT in $s0 and the state in $s1
 *   - the retail's allocation - at the price of a 0x40 frame and four spilled FPRs.  With
 *   the floats read inside the two case blocks (the retail's code) the state pointer wins
 *   $s0.
 * - Spelling the state's addresses through a local (`char *p = s1 + 0x14;` and the floats
 *   into locals) reproduces the retail's body instruction for instruction - the diff then
 *   stops at the prologue alone - but does not move the allocation.
 * - Measured and NOT enough (all give the same $s0/$s1 swap, with the body unchanged):
 *   the argument used directly instead of a copy, the two declarations exchanged, the
 *   state loaded before the `sel` load, the state read through the parameter instead of
 *   the copy, the state loaded in the declaration, the argument declared `const char *`,
 *   `n` as a short, the state's floats read into locals, the state's floats read through a
 *   `float *`, the state as an `unsigned char *`.
 */
/* The level's own jump table (the label of the data blob at 0x002B5960). */
extern void *jtbl_002B5960[5];

extern void func_002A7750(int, int, int);

extern int func_002B3868(char *);

extern int func_002B38B8(char *);

extern void func_002AA548(char *, char *, float, float, float, float);

extern void func_002E5CF8(int, int, char *);

extern unsigned char D_0019B2E8[];

/* The five behaviours the object's state byte selects; the table in the level's data
   holds the address of each. */
void func_L20_00445738(char *arg0) {
    static void * volatile tab[] = { &&c0, &&c1, &&c2, &&c3, &&c4 };
    char *s1;
    char *s0 = arg0;
    unsigned char sel;
    int n;

    sel = *(unsigned char *)(s0 + 0x20);
    s1 = *(char **)(s0 + 0x68);
    if (sel >= 5) {
        goto end;
    }
    goto *jtbl_002B5960[sel];
c0:
    *(float *)(s1 + 0x10) = *(float *)(s0 + 0x10);
    func_002A7750(s0, 1, -1);
    goto out;
c1:
    if ((D_0019B2E8[*(unsigned char *)(s0 + 0xB0) + *(int *)0x001A79F0 * 16] & 0x80) == 0) {
        goto end;
    }
    n = 2;
    goto shared;
c2:
    if (func_002B3868(s0) != 0) {
        *(int *)(s1 + 0x14) = 0;
        func_002E5CF8(0, 0, s0);
    }
    func_002AA548(s0 + 0x10, s1 + 0x14,
                  *(float *)(s1 + 0x10) - *(float *)(s1 + 0x0),
                  *(float *)(s1 + 0x8), *(float *)(s1 + 0x8),
                  *(float *)(s1 + 0xC));
    goto out;
c3:
    if (func_002B38B8(s0) == 0) {
        goto end;
    }
    n = 4;
shared:
    func_002A7750(s0, n, -1);
    goto out;
c4:
    if (func_002B3868(s0) != 0) {
        func_002E5CF8(0, 0, s0);
        *(int *)(s1 + 0x14) = 0;
    }
    func_002AA548(s0 + 0x10, s1 + 0x14, *(float *)(s1 + 0x10),
                  *(float *)(s1 + 0x8), *(float *)(s1 + 0x8),
                  *(float *)(s1 + 0xC));
    goto out;
end:
out:
    return;
}


/* ---- wave 5 (20_yeedil, 2026-10-21, worker 03): the allocation, measured -------
 *
 * The candidate above is the wave-4 one and the diff is 44 words: 42 of them
 * are the `$s0`/`$s1` swap and the two delay slots that follow from it.
 *
 * The allocation is decided by gcc's global allocator, and its priority is
 * (gcc/global.c, allocno_compare):
 *
 *     pri = floor_log2(n_refs) * n_refs / live_length * 10000 * size
 *
 * `cc1 -da` prints the numbers in x.i.lreg ("Register N used R times across L
 * insns").  For the candidate:
 *
 *     Register 84 (the argument copy): used 14 times across 51 insns
 *     Register 85 (the state pointer): used 13 times across 43 insns
 *
 * so pri(arg) = 3*14/51 = 0.824 and pri(state) = 3*13/43 = 0.907: the state
 * wins and takes $s0, which is what this cc1 produces.  The retail has the
 * argument in $s0, so its source must have had either
 *
 *   - 16 or more references to the argument (floor_log2(16) = 4, so
 *     4*16/51 = 1.25 > 0.907 whatever the live length is), or
 *   - a live length of at most 46 for the argument (3*14/46 = 0.913), or
 *   - a live length of at least 48 for the state.
 *
 * The argument's live range starts in the prologue (the parameter copy) and
 * the state's starts at the `lw` a few instructions later, so the difference
 * is the handful of instructions between them - the argument can not have a
 * shorter live range.  The references are 14 in the retail as well (the two
 * `func_002E5CF8` calls add two, the twin func_L20_00446E70's two fewer).
 * What is left is the live length, and the retail's compiler counted the
 * blocks differently.
 *
 * Measured and NOT enough (all give the same 44 words, the allocation
 * unchanged): the argument used directly instead of a copy, the declarations
 * exchanged, the state loaded before the `sel` load, the state read through
 * the parameter, the state loaded in the declaration, the state as an
 * `unsigned char *`, `n` as an `unsigned char` or a `short`, `sel` as an
 * `int`, the state's floats read into locals (that one DOES flip the
 * allocation - the argument wins $s0 - but the frame grows from 0x20 to 0x40
 * and four FPRs are spilled), the state's floats read through a `float *`,
 * the argument used directly in the last case only, the source written with
 * the argument instead of a copy (the twin's style).
 *
 * The second difference, once the allocation is right, is the order of the
 * set-up of the shared call `func_002A7750(s0, n, -1)`: the retail sets its
 * first argument up before its second one (the `daddu $a0,$s0,$zero` in the
 * `bc1f`/`beqz` delay slot and the `addiu $a1,$zero,0x2` in the branch's),
 * this cc1 the other way round, because the `n = 2` and `n = 4` assignments
 * sit in the case blocks and are materialised before the call's first
 * argument.
 */
