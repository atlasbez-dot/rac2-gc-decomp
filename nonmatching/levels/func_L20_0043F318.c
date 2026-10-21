/* near-miss: func_L20_0043F318 (20_yeedil, 328 bytes).
   The attempt is in src/levels/20_yeedil/L20_0043F318-g8.c (a unit of its own: the
   body reaches D_L20_001B1F98 through $gp).  It is 324 bytes against retail's 328 and
   the shape is retail's: the lookup of the object of type 0x119D, the null guard, the
   five arguments copied into $s2-$s6, the float argument in $f21, the 16-byte copy
   into the object, the call to func_00282CF0 with the object's and the argument's
   vector, the two floats read back from the stack, the two calls to func_002A7878
   with the 1.0f constant, the store of the argument's float into the state, the three
   16-byte copies into the state and the return of the object.
   What differs:
     1. The 1.0f constant.  The retail keeps it in the callee-saved $f20 (it is live
        across the call to func_002A7878) and copies it into $f12 and $f13; this cc1
        rematerialises it into the argument register at each use, so the constant gets
        no register of its own, the argument float gets $f20 instead of $f21, and the
        epilogue saves one FPR less.  Four instructions.
        FOUND: writing the constant as a literal at both call sites instead of a
        variable gives the retail's shape - the compiler then keeps the constant in
        the callee-saved $f20 and copies it into $f12 and $f13, the argument float
        lands in $f21 and the epilogue saves both FPRs.  The attempt with that
        spelling is 328 bytes, retail's size.
     2. The three 16-byte copies into the state are a loop in the retail
        (`lq $v0,0x0($s3) ; sq $v0,0x0($v1)` with the destination pointer incremented
        in the branch's delay slot and a separate counter tested with `slti`/`bnez`).
        This cc1 turns the loop into a count-down (`addiu $a0,$a0,-1` ; `bgez $a0`),
        one instruction longer.  Measured here and all giving the count-down: a `for`
        with the index, a `for` with a pointer variable, a `while`, a `do`/`while`, an
        `i != 3` test, and the per-file flags -fno-strength-reduce, -fno-gcse,
        -fno-loop-optimize, -fno-peephole2 and -fno-expensive-optimizations.
     3. The order of a few instructions: retail sets `$a0 = 0x119D` before the
        prologue's `sd $ra`, and its `beqz` has the next call's argument set-up in the
        delay slot where this cc1 has the tail copy of the return value.
   The three calls' arguments and the two calls to func_002A7878 (whose third argument
   is NOT a float: the retail's call has only two float arguments, the third value is
   the result of the previous call) were measured and are as the attempt has them.
*/
#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

extern void *func_0029EFD0(int);
extern void func_002B37E8(void *, void *);
extern void func_00282CF0(float *, void *, void *);
extern float func_00282E20(float *);
extern float func_00283248(float, float);
extern float func_002A7878(float, float);
extern float D_L20_001B1F98 __attribute__((sda));

/* The unit needs -G8 (the global is read through $gp) and -fno-strength-reduce
   (the loop keeps the retail's count-up form).  See the wave-5 note below. */
char *func_L20_0043F318(char *arg0, char *arg1, int arg2, int arg3, int arg4, float f) {
    char *obj = (char *)func_0029EFD0(0x119D);
    char *state;
    float v[2];
    float r;
    int i;
    char *d;

    if (obj == 0) {
        goto out;
    }
    func_002B37E8(obj, arg0);
    *(TI128 *)(obj + 0x10) = *(TI128 *)arg1;
    func_00282CF0(v, (void *)(obj + 0x10), arg0 + 0x10);
    state = *(char **)(obj + 0x68);
    *(float *)(state + 0x40) = func_00282E20(v);
    *(float *)(state + 0x44) = func_00283248(v[0], v[1]);
    *(float *)(state + 0x5C) = *(float *)(arg0 + 0x18);
    r = func_002A7878(1.0f, 4.0f);
    *(float *)(state + 0x4C) = *(float *)(state + 0x5C) + r;
    r = func_002A7878(0.0f, 1.0f);
    *(int *)(state + 0x64) = arg2;
    *(int *)(state + 0x68) = arg3;
    *(int *)(state + 0x6C) = arg4;
    *(float *)(state + 0x70) = f;
    *(float *)(state + 0x48) = D_L20_001B1F98 + r;
    d = state + 0x10;
    for (i = 0; i < 3; i++) {
        *(TI128 *)d = *(TI128 *)arg1;
        d += 0x10;
    }
out:
    return obj;
}

/* ---- wave 5 (20_yeedil, 2026-10-21, worker 04): THE COUNT-UP LOOP IS REACHABLE -----
 *
 * The wave-4 note said the loop's count-down was unavoidable.  It is not: the
 * flag -fno-strength-reduce gives the retail's loop verbatim.
 *
 *   retail:  lq $v0,0($s3) ; sq $v0,0($v1) ; addiu $a0,$a0,1 ; slti $v0,$a0,3 ;
 *            nop ; bnez $v0,loop ; addiu $v1,$v1,0x10
 *   -fno-strength-reduce, with the pointer written in the source:
 *            lq $v0,0($s3) ; sq $v0,0($v1) ; addiu $a0,$a0,1 ; slti $v0,$a0,3 ;
 *            nop ; bnez $v0,loop ; addiu $v1,$v1,0x10
 *
 * WHY: gcc 1.1's loop optimiser REVERSES a counted loop (loop.c, check_dbra_loop:
 * "Can reverse loop" / "Reversed loop and added reg_nonneg").  The reversal is
 * what turns the retail's count-up into the count-down.  It fires because the
 * counter's induction-variable class has no derived variable (no_use_except_counting
 * is true) while the store's address is not invariant (reversible_mem_store is
 * false), so the second condition of the reversal is false and only the first one
 * applies.  -fno-strength-reduce keeps the whole strength_reduce pass - and with
 * it check_dbra_loop - from running, so the loop keeps its natural count-up form.
 * The flags -fno-loop-optimize, -fno-unroll-loops, -fno-gcse, -fno-peephole2 and
 * -fno-expensive-optimizations do NOT help (they all still count down).
 *
 * The unit has to be the -G8 sibling: the global D_L20_001B1F98 is read through
 * $gp.  Measured: an INT global with __attribute__((sda)) in a -G8 unit gives the
 * retail's `lw $v0,0x30DC($gp)` (the assembler expands the plain `lw $v0,SYM`
 * gp-relatively when the .extern with the size comes first); a plain declaration
 * gives the absolute `lui`+`lw`, and `nosda` gives the absolute form too.
 *
 * What is left (the candidate is 332 bytes against retail's 328):
 *   1. one extra instruction: this cc1 puts a COPY of the return value
 *      (`daddu $v0,$s1,$zero`) in the delay slot of the `beqz` that tests the object
 *      pointer, where retail has the next call's argument set-up
 *      (`daddu $a1,$s2,$zero`).  Measured: this copy is only pulled into the delay
 *      slot when the loop is present (the same body without the loop puts the
 *      argument set-up in the delay slot, retail's shape), so it is a consequence
 *      of the loop's register allocation, not a separate problem.
 *   2. the loop's two registers: retail has the counter in $a0 and the pointer in
 *      $v1, this cc1 the counter in $a1 and the pointer in $a0.  The declaration
 *      order of the two locals does not change it.
 *   3. the order inside the loop: retail stores before the counter's increment,
 *      this cc1 after it.
 */
