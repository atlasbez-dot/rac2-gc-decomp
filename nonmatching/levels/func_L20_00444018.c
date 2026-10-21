/* Wave 4 (worker 04): the candidate below is the wave-4 one - the body is the
   retail's 108 bytes and 14 of the 27 instructions differ.  See the wave-4
   note at the end. */
/* near-miss: func_L20_00444018 (20_yeedil, 108 bytes).
   Retail hoists the 0.78539824f materialisation above `addiu $sp,$sp,-0x50` and gives
   `$s1` to the state pointer, `$s2` to `&v1`; this cc1 sinks the constant below the
   frame adjust and swaps the two callee-saved registers. 
   Second wave (20_yeedil, 2026-10-20) re-measured this one: eight further source
   shapes (the two locals as char[16], unsigned int[4], float[4]; one 32-byte array
   used as v and v+16; a TI128 pair; the declaration order of the locals; the float
   assigned as a separate statement; the float as the first local) all allocate $s1 to
   the local's address and $s2 to the state pointer, and all sink the 0.78539824f
   materialisation below the frame adjust. The constant is 0.78539824f (0x3F490FDC),
   one ulp above pi/4, and it is loaded with lui/ori/mtc1 exactly as retail has it.
   The body is right: the second call f_0044AC38 takes (object, index = state->[0x240],
   &v0, &v1), the index is a word and the two vectors are swapped against the first
   call. Wall: the callee-saved register order plus the entry-block constant.
   Third wave (20_yeedil, 2026-10-20, worker 03) re-measured this one in the plain
   L20_0043ECB0.c unit: the body is retail's (the second call takes
   (object, state->[0x240], &v0, &v1), the float is 0x78539824f stored to sp+0x20) and
   the frame is retail's 0x50, but the entry block still sinks the lui/ori/mtc1 of the
   constant BELOW `addiu $sp,$sp,-0x50` (retail has it above) and still gives $s1 to
   &v1 and $s2 to the state pointer (retail has it the other way round). Measured and
   rejected: the float as a `volatile float` (120 bytes: the store leaves the jal's
   delay slot), the two vectors as `char *` parameters instead of TI128 * (no change),
   the float declared first and the state pointer declared between the calls (the state
   reload moves after the first call, 100 bytes).
   Per-file flags measured on this one (in a file of its own, so the flag does not touch
   the rest of L20_0043ECB0.c): -fno-schedule-insns and -fno-schedule-insns2 keep the
   size at 108 bytes but leave the same two differences (the constant is still sunk below
   the frame adjust and $s1/$s2 are still the wrong way round); both together give 112
   bytes; -g and -mno-split-addresses change nothing. The flag does not help here, but
   it does fix the same kind of difference in func_L20_00444088 (see that function, now
   matched in L20_00444088-g8.c with -fno-schedule-insns).
*/
typedef int TI128 __attribute__((mode(TI)));
typedef int s32;
typedef float f32;

extern void func_L20_00443B60(char *, char *, char *, float *);
extern void func_L20_0044AC38(char *, s32, TI128 *, TI128 *);

void func_L20_00444018(char *arg0)
{
    char *state = *(char **)(arg0 + 0x68);
    TI128 v0;
    TI128 v1;
    f32 f;

    f = 0.78539824f;
    func_L20_00443B60(arg0, (char *)&v0, (char *)&v1, &f);
    func_L20_0044AC38(arg0, *(s32 *)(state + 0x240), &v0, &v1);
}



/* ---- wave 4 (20_yeedil, 2026-10-20, worker 04): the two residues, re-measured -----
 *
 * The body is the retail's (108 bytes, the retail's 108) and the two residues
 * are the ones recorded above.  Measured here:
 *
 *  - the callee-saved assignment IS reachable: reading the index into a local
 *    BEFORE the first call gives the retail's $s2 for the address of the second
 *    vector and $s1 for the state pointer, where the expression
 *    `*(s32 *)(state + 0x240)` in the second call's arguments gives $s1 for the
 *    address and $s2 for the state.  The retail's shape is between the two:
 *    $s2 = &v1, $s1 = the state, and the index is loaded into $a1 AFTER the
 *    first call (`lw $a1,0x240($s1)`), so the state's pointer is the value that
 *    survives the call.
 *  - the constant's position is NOT a flag: the retail materialises
 *    0.78539824f (`lui $at ; ori $at ; mtc1 $at,$f0`) BEFORE the frame adjust
 *    (`addiu $sp,$sp,-0x50`), this cc1 after it.  Measured: a float constant
 *    that is stored to the stack comes out before the frame adjust in a small
 *    function, so the position depends on the scheduler, not on the source
 *    order of the statements; -mastra-keep-frame-order, -fno-schedule-insns,
 *    -fno-schedule-insns2 and -fno-sched-interblock change nothing here.
 */

/* ---- wave 5 (20_yeedil, 2026-10-21, worker 01): the two residues, re-measured --------
 *
 * The candidate below is the retail's EXACT size (108 bytes = 27 instructions) and
 * differs from the retail in three places only, all of them scheduling or a register
 * choice:
 *
 *  1. the constant's position: the retail materialises 0.78539824f (`lui $at ; ori $at ;
 *     mtc1 $at,$f0`) BEFORE the frame adjust (`addiu $sp,$sp,-0x50`), this cc1 sinks it
 *     below it.  The matched witness func_L00_0031AD40 (src/levels/shared/L00_00316F60.c)
 *     has the same shape - the constant above the frame adjust - so the placement is
 *     reachable, but nothing in the source moved it here.
 *  2. the callee-saved order: the retail gives $s1 to the state pointer and $s2 to
 *     `&v1`; this cc1 gives $s1 to `&v1` and $s2 to the state pointer.  The brief's
 *     lead ("reading the index into a local BEFORE the first call gives the retail's
 *     $s2 = &v1") is only half right: reading the index into a local before the call
 *     DOES give $s2 = &v1, but then the index itself takes $s1 and the state is dead
 *     after the call (it stays in $v0, read in the delay slot of the first `jal`), so
 *     $s1 is not the state pointer.  With the index read AFTER the call (the only shape
 *     the retail's `lw $a1,0x240($s1)` allows) the state is live across the call and
 *     this cc1 still gives $s1 to `&v1`.
 *  3. the float's store: the retail stores it at `swc1 $f0,0x20($sp)` in the middle of
 *     the first block and puts the `daddu $a2,$s2,$zero` in the `jal`'s delay slot; this
 *     cc1 puts the store in the delay slot and the `daddu $a2,$s1,$zero` before the
 *     `jal`.
 *
 * MEASURED AND REJECTED (all give the same 15 differing instructions): the order of the
 * four declarations; the float declared first; the state read in a separate statement
 * before the calls or after them; the state read in the second call's argument list
 * without a named variable; the index read into a local in a nested block; the float
 * assigned in a separate statement before the call; the vectors as `TI128 v[2]`; the
 * vectors swapped; the `-G8` profile (the allocation is the same there).
 *
 * The C (it is the retail's body; the three residues above are what is left):
 */

typedef int TI128 __attribute__((mode(TI)));
typedef int s32;
typedef float f32;

extern void func_L20_00443B60(char *, char *, char *, float *);
extern void func_L20_0044AC38(char *, s32, TI128 *, TI128 *);

void func_L20_00444018(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);
    TI128 v0;
    TI128 v1;
    f32 f = 0.78539824f;

    func_L20_00443B60(arg0, (char *)&v0, (char *)&v1, &f);
    func_L20_0044AC38(arg0, *(s32 *)(state + 0x240), &v0, &v1);
}
