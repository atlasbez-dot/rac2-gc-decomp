/* Best attempt for func_L20_0044AC38 (540 bytes, 1 place) - NOT MARKED.
   The body belongs in a -G8 unit of its own (it reaches a global through
   $gp: `lw $a1, 0x3450($gp)` at 0x0044AD44, i.e. D_L20_001B2440), so the
   marker was moved to src/levels/20_yeedil/L20_0044AC38-g8.c (a file named
   *-g8.c gets -G8 from its name; no config/cflags.txt line is needed).

   What the attempt gets right (all measured with tools/check.py --diff):

   - the SIZE is exact: 540 bytes, the retail's size.
   - the dispatch, the loop and its two back edges, the branch-likely
     `beql $v0,$t2` with `daddu $s3,$a0,$zero` in the delay slot, the
     `bgezl`/`beql` pair at the loop's end with the `lhu` in the delay
     slots, the zero guard (`daddu $a3,$zero,$zero` + `bnez $a3`), the
     `beqz $v0` + `ori`/`andi` pair after func_0032F680 and the whole tail
     of the calls are the retail's instructions.
   - the zero guard: `s32 flag = arg0 & ~arg0;` assigned in the block
     AFTER the first branch and tested inside the loop keeps the zero
     materialised and the retail's `bnez` alive.  Two things matter and
     both were measured here:
       * the assignment must be in ANOTHER block than the test (the loop
         body): inside the same block the plain CSE folds `arg0 & ~arg0`
         and the branch dies.  With the assignment at the top of the
         function the zero is merged with the `found = 0` zero and the
         test dies with it; with the assignment after the first branch
         the two zeros stay apart and the test survives.
       * the types matter: the table and the base must be pointers
         (`extern char *D_L20_001FBB20[];`, `extern char *D_L20_001B2F9C;`)
         or the int-to-pointer conversion adds a 64-bit zero extension.

   What still differs (the two remaining walls):

   1. THE 128-BIT COPY WALL.  The retail materialises the destination
      address of each 16-byte copy:
          addiu $s2,$s3,0x10 ; lq $v0,0x0($s5) ; sq $v0,0x0($s2)
          addiu $v1,$s0,0x180 ; lq $v0,0x0($s5) ; sq $v0,0x0($v1)
          addiu $a0,$s0,0x170 ; lq $v0,0x0($s4) ; sq $v0,0x0($a0)
      and this cc1 folds the offset into the displacement
      (`sq $v0,0x180($s0)`).  Measured this wave: the address stays in a
      register only when it is a plain register at the store - a pointer
      that is a parameter, or one LOADED FROM MEMORY (the matched
      src/levels/shared/L08_003D3928.c: `*(volatile TI128 *)*(u32 *)(a0 +
      0x68) = *(TI128 *)a1;`).  Every plain spelling of a COMPUTED
      address folds here, even when the address is used twice (a pointer
      variable, a pointer live across a call, a volatile pointer object -
      the last one gives the zero displacement but with a stack store and
      a reload, four instructions for the retail's three).
   2. THE REGISTER ALLOCATION.  The retail uses $s0 for the value at
      found+0x68, $s1 for arg0, $s2 for found+0x10, $s3 for found, $s4 for
      arg3 and $s5 for arg2 - six saved registers.  The attempt uses
      seven: it keeps `s0 + 0x190` in a register of its own ($s1) instead
      of computing it in the delay slot of the func_0032F718 call (the
      retail: `addiu $s1,$s0,0x190` in that delay slot, reusing the
      register arg0 has just freed), so arg0 lands in $s6.  The order in
      which the values are first set in the source decides the order of
      the saved registers.

   The frame, the two global loads, the `slt`/`bnez` test, the flags
   0xFFBE/0x1000/0x7FFF/0x8000 and the four calls of the tail are the
   retail's instructions.  The last `lw` of the tail is a byte offset:
   `*(int *)((char *)t + 0x10)` and not `*(int *)(t + 0x10)` (an int
   pointer scales the offset by four).
*/


   ------------------------------------------------------------------
   WAVE 5 (worker 17).  The attempt below is the closest one so far:
   540 bytes, the retail's size, and 86 of the retail's 135
   instructions differ (the earlier attempt differed in 108).  The
   three walls below are what is left; the first one is a compiler
   wall, the other two are source shapes this wave could not find.

   1. THE 128-BIT COPY WALL - MEASURED AGAIN, AND IT IS A WALL.
      The retail materialises the destination of every 16-byte copy:
          addiu $s2,$s3,0x10 ; lq $v0,0x0($s5) ; sq $v0,0x0($s2)
          addiu $v1,$s0,0x180 ; lq $v0,0x0($s5) ; sq $v0,0x0($v1)
          addiu $a0,$s0,0x170 ; lq $v0,0x0($s4) ; sq $v0,0x0($a0)
      and this cc1 folds the offset into the displacement.  Measured
      this wave over the retail's own level-20 listing: 6,784 lq/sq,
      5,435 with a zero displacement and 1,349 with a non-zero one, so
      the retail does BOTH - and the rule is visible in the retail
      itself: a 128-bit access whose address is a plain pointer
      VARIABLE has a zero displacement (0x002B892C `lq $v0,0x0($a2)`
      with `addiu $a2,$s0,0x80` just before), while an access whose
      address is a `base+const` EXPRESSION has the offset folded into
      the displacement (0x002C28CC `sq $v1,0x730($s2)`).  So the
      original source computed the copy addresses into variables, and
      the retail's compiler kept them in registers.

      Why this cc1 cannot: the fold is the RELOAD's (plus(reg,const) is
      a legitimate TImode address for any offset in [-32768, 32752],
      GO_IF_LEGITIMATE_ADDRESS in config/mips/mips.h), and the CSE's
      find_best_addr (gcc/cse.c) rewrites the address of a plain
      pointer variable back into plus(base,const): the equivalence
      class of the variable holds both the pseudo (COST 1) and the
      plus expression (COST notreg_cost(plus) = rtx_cost*2 = 6), the
      class is kept in increasing-cost order, and the tie is broken
      towards the HIGHER rtx_cost - so the plus always wins and the
      offset is always folded.  Measured: 30 spellings of a 16-byte
      copy (a pointer variable, a plain pointer parameter, a symbol, a
      stack slot, a struct member, a union, a volatile pointer, a
      volatile store, __builtin_memcpy, an array index, a 64-bit
      base, an out-of-range offset, a variable offset, the address in
      a branch, the address in a nested block) - all fold, and the
      only one that materialises the address is a VOLATILE POINTER
      object, which costs a stack store and a reload (four
      instructions for the retail's two).  The plain-pointer case
      (the address is a parameter, so its class holds no plus) is
      the one that works, and it is why the C functions already in
      src/ have no materialised 128-bit address.

      => the three copies of this body are a compiler-side wall, not
      a source shape.  Six of the retail's instructions (three addiu
      and the three sq) cannot be produced from plain C.

   2. THE BRANCH-LIKELY.  The retail has
          beql $v0,$t2,.L0044AD10 ; daddu $s3,$a0,$zero
          bgezl $v0,.L0044ACC0   ; lhu $v0,0x0($a2)
          beql $a2,$v0,.L0044ACC0 ; lhu $v0,0x0($a2)
      and this cc1 emits a plain `bne` plus a `b` with the same
      instructions around them.  Measured this wave: the branch-likely
      appears when the "then" block of the branch ends in a STORE (to
      a global or through a pointer) - `if (c) { g = *p; goto L; }
      return 0;` gives `beql $a0,$a1` with the load in the delay slot
      - but NOT when it is a register assignment (`if (c) { y = *p;
      goto L; } return 0;` gives `bne`).  A register assignment is
      what the retail has here (`found = i`), and 20 spellings of it
      (the assignment inside the if, before the test, after the test,
      in a for/while/do loop, with break, with the constant in a
      register, ...) all give the plain branch.  The delay slot of
      the retail's branch holds the assignment, so the annul bit
      (INSN_ANNULLED_BRANCH_P, which is what makes mips.md print the
      `l` of `beql`, mips.md:8410) must be set by reorg's
      fill_eager_delay_slots, and this wave did not find the source
      shape that makes it set.

   3. THE REGISTER ORDER.  The retail has $s0=found+0x68, $s1=arg0,
      $s2=found+0x10, $s3=found, $s4=arg3, $s5=arg2 - six saved
      registers - and reuses $s1 for `s0+0x190` after arg0's last
      use.  The attempt has seven: it keeps `s0+0x190` in a register
      of its own, and the scheduler computes it BEFORE arg0's last
      use, so the two overlap and cannot share $s1.  The retail
      computes it in the delay slot of the func_0032F718 call, i.e.
      after `sw $s1,0xB8($s3)`.  This is the same "the value is born
      too early" problem as the 128-bit copies: the source order is
      the same, the scheduler's choice is not.

      The retail also has two shapes this cc1 does not produce:
      `daddu $a1,$t0,$zero` (a copy of the count into $a1, so that
      $t0 can be reused for the zero guard) and the constants 1 and
      0xFF materialised once into $t2 and $t1 before the loop - the
      attempt has the 1 in a register ($t1) but the 0xFF is
      rematerialised in the delay slots.

      A difference of the COMPILER, not of the source, worth
      reporting: the retail sets $a0 = found ONCE (0x0044ADA0) and
      uses it for both the func_0032F5B0 call and the func_0032F718
      call, although the first call clobbers $a0; this cc1
      re-materialises $a0 for the second call.  Measured on a
      two-call test function, this cc1 always re-sets it.

   4. WHAT THIS WAVE DID CHANGE in the attempt (it is now 86 of 135
      instructions off, the earlier attempt was 108 off):
      - the zero guard `flag = arg0 & ~arg0` is assigned AFTER the
        three dispatch branches (in the block that sets up the loop)
        and tested inside the loop: with the assignment at the top of
        the function the compiler folds `x & ~x` into `nor`+`and`
        (two instructions) and the guard's `bnez` dies; after the
        branches the value is a copy of zero (`daddu $t0,$zero,$zero`)
        and the guard survives.
      - the constants 1 and 0xFF are variables (`one`, `ff`), so
        they are materialised once before the loop instead of being
        rematerialised in the delay slots.
      - the tail's `*(int *)(found + 0xB8) = arg0;` and the
        func_0032F5B0 call come BEFORE the three 16-byte copies.
      - `int *t = *(int **)(found + 0x24);` (the earlier attempt had
        `*(int *)`, which is an int value assigned to a pointer: the
        compiler warned, "initialization makes pointer from integer
        without a cast").

   Checked: tools/check.py func_L20_0044AC38 --diff
   -> "func_L20_0044AC38: 0 of 1 places match"; 540 bytes (the
   retail's size), 86 of the 135 instructions differ.
*/

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
typedef int TI128 __attribute__((mode(TI)));

extern int D_L20_001B2FB8;

extern char *D_L20_001B2F9C;

extern char *D_L20_001FBB20[];

extern int D_L20_001B2440 __attribute__((sda));

extern void func_0032F2D0(void *, int, int, int);

extern void func_003381E0(void *, void *);

extern int func_0032F680(int);

extern void func_0032F5B0(void *, int, int);

extern float func_0032F718(void *, float, float);

extern void func_00302548(void *, void *, float);

extern void func_00302260(void *, void *, void *);

extern float func_00302920(float, float);

extern float func_0032F7E0(void);

char *func_L20_0044AC38(int arg0, int arg1, TI128 *arg2, TI128 *arg3) {
    char **entry = &D_L20_001FBB20[arg1];
    char *p = *entry;
    int count = arg1 & 0xFF;
    char *found = 0;
    char *base;
    u16 v;
    int one;
    int ff;
    unsigned int flag;
    char *i;

    if (count == 0xFF) {
        goto end;
    }
    if (D_L20_001B2FB8 < arg1) {
        goto end;
    }
    if (p == 0) {
        goto end;
    }

    one = 1;
    ff = 0xFF;
    base = D_L20_001B2F9C;
    flag = arg0 & ~arg0;

    v = *(u16 *)p;
loop:
    v = v & 0x7FFF;
    i = base + (v << 8);
    if (i == 0) {
        goto end;
    }
    if (*(u8 *)(i + 0x20) == one) {
        found = i;
        goto end;
    }
    if (count == ff) {
        goto end;
    }
    p = p + 2;
    if (flag) {
        goto end;
    }
    if (p == 0) {
        goto end;
    }
    if (*(s16 *)(p - 2) >= 0) {
        v = *(u16 *)p;
        goto loop;
    }
    if (p == *entry) {
        v = *(u16 *)p;
        goto loop;
    }
end:
    if (found == 0) {
        goto ret;
    }
    {
        u16 w = *(u16 *)(found + 0x34);
        int *t = *(int **)(found + 0x24);

        w = w & 0xFFBE;
        w = w | 0x1000;
        *(u16 *)(found + 0x34) = w;
        *(int *)(found + 0x98) = *(int *)((char *)t + 0x10);
        func_0032F2D0(found, 0, 0, 0xF);
        func_003381E0(found, (void *)D_L20_001B2440);
        if (func_0032F680(2) != 0) {
            w = *(u16 *)(found + 0x34) | 0x8000;
        } else {
            w = *(u16 *)(found + 0x34) & 0x7FFF;
        }
        *(u16 *)(found + 0x34) = w;
    }
    {
        char *s0 = *(char **)(found + 0x68);
        char *s2 = found + 0x10;
        float f;
        s16 sv;

        *(int *)(found + 0xB8) = arg0;
        func_0032F5B0(found, 2, -1);
        *(TI128 *)s2 = *(TI128 *)arg2;
        *(TI128 *)(s0 + 0x180) = *(TI128 *)arg2;
        *(TI128 *)(s0 + 0x170) = *(TI128 *)arg3;
        f = func_0032F718(found, 20.0f, 30.0f);
        func_00302548(s0 + 0x190, arg3, f);
        func_00302260(s0 + 0x190, s0 + 0x190, s2);
        sv = *(s16 *)(s0 + 0x24);
        f = *(float *)((char *)arg2 + 8);
        *(float *)(s0 + 0x198) = f;
        *(float *)(s0 + 0x20) = (float)sv;
        f = func_00302920(*(float *)arg3, *(float *)((char *)arg3 + 4));
        *(float *)(found + 0xF8) = f;
        *(float *)(s0 + 0x1A0) = func_0032F7E0();
        *(float *)(s0 + 0x20) = (float)*(s16 *)(s0 + 0x24);
    }
ret:
    return found;
}
