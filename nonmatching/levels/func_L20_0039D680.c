/* Near miss from src/levels/20_yeedil/L20_0039C448-g8.c (the -G8 unit).

   The body has the retail size (300 bytes) and the loop matches the retail
   instruction for instruction, from 0x39D6E8 to the end.  Only the prologue
   differs: the retail keeps the high half of the D_00189EA0 constant in a
   callee-saved register from the start and the compiler here puts it in $a1
   and copies it into a saved register before the call:

     retail:  addiu sp,-0x50 / sd s0 / sd s1 / lui s0,%hi(D_189EA0) / sd s2 /
              addiu a1,s0,%lo(D_189EA0) / sd s3 / daddu s2,a0 / swc1 f20 /
              addiu a0,s2,0x10 / sd s4 / daddu s3,zero / sd ra / sd s5 / jal /
              lw s5,0x68(s2) / lbu v0,0x21(s2) / lui a0,%hi(D_1FBB20) /
              addiu v1,a0,%lo(D_1FBB20) / mov.s f20,f0 / sll v0,v0,2 /
              addu v0,v0,v1 / lw s1,0(v0) / daddu s4,s0 / b / daddu s0,a0
     here:    addiu sp,-0x50 / lui a1,%hi(D_189EA0) / sd s0 / sd s1 / sd s2 /
              daddu s1,a0 / sd s4 / addiu a0,s1,0x10 / sd s5 / daddu s2,zero /
              swc1 f20 / daddu s5,a1 / sd ra / addiu a1,a1,%lo(D_189EA0) /
              sd s3 / jal / lw s3,0x68(s1) / lui v0,%hi(D_1FBB20) /
              lbu v1,0x21(s1) / daddu s4,v0 / mov.s f20,f0 / sll v1,v1,2 /
              addiu v0,v0,%lo(D_1FBB20) / addu v1,v1,v0 / b / lw s0,0(v1)

   So: the retail's $s0 holds %hi(D_189EA0) and is reused for %hi(D_1FBB20)
   after the copy into $s4, while here %hi(D_189EA0) is born in $a1 and the
   two table constants land in $s4/$s5 and the record in $s0.  The retail's
   `addiu v1,s0,-0x44E0` is %lo(D_1FBB20) applied to the saved %hi, and the
   attempt gets the same shape (the attempt's `addiu v1,s4,%lo(D_1FBB20)`).

   What did work (and is in the attempt):
   - the loop is written with goto labels (check/body/out) instead of a `while`
     or `for`.  A loop makes the compiler duplicate the exit test in front of
     the loop (jump.c: duplicate_loop_exit_test) and the retail has the test
     only once, at the end of the body, with the entry branching over the body
     to it.  The goto form reproduces that shape exactly.
   - the second table is the same table: `D_L20_001FBB20[idx]`, and %lo(D_1FBB20)
     is -0x44E0, so the retail's `addiu v1,s0,-0x44E0` is that %lo, not a
     separate symbol at D_L20_001F7640.
   - D_L20_001B2F9C carries `nosda` (the retail reaches it through $at/$lo)
     and D_L20_001B2FB8 carries `sda` (the retail reaches it through $gp at
     0x1AEFF0+0x3FC8).
   - the float compare is `result < limit`: the retail's `c.lt.s f0,f20` with
     the branch-likely `bc1tl` runs the delay slot (the increment) when the
     comparison is false, so the counter goes up when the result is >= limit.

   Tried: for(;;), do/while(1) and while(cond) spellings of the loop (all of
   them duplicate the exit test and give 356-376 bytes), the exit test as one
   && chain, the exit test split over several ifs, the second table as
   D_L20_001F7640 and as a shifted base pointer ((char **)D_L20_001FBB20 - 0x1138),
   the order of the exit tests, the constant in a local variable, and the
   declaration order of the locals.  Only the prologue's register allocation
   and the interleaving of the `lui` with the register saves are left.    With the attempt in src/ (the unit's default flags):
     20_yeedil: instruction at +0x8 differs
     func_L20_0039D680: 0 of 1 places match
   With the attempt in a unit of its own built with -fno-schedule-insns the
   first difference moves to +0x0c (the prologue's register allocation).
*/
#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern float func_00302440(void *, void *);

extern char D_00189EA0[];

extern u16 *D_L20_001FBB20[];

/* The retail body of func_L20_0039D680 reaches D_L20_001B2F9C through $at/$lo. */
extern char *D_L20_001B2F9C __attribute__((nosda));

/* 0x1AEFF0 + 0x3FC8 : the retail body reaches this one through $gp. */
extern int D_L20_001B2FB8 __attribute__((sda));

void func_L20_0039D680(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);
    float limit = func_00302440(arg0 + 0x10, D_00189EA0);
    u16 *rec = (u16 *)D_L20_001FBB20[*(u8 *)(arg0 + 0x21)];
    int count = 0;
    u8 idx;

    goto check;
body:
    {
        char *p = D_L20_001B2F9C + ((*rec & 0x7FFF) << 8);

        if (p == 0) {
            goto out;
        }
        if (p != arg0 && *(u8 *)(p + 0x20) != 6) {
            if (func_00302440(p + 0x10, D_00189EA0) < limit) {
                count++;
            }
        }
        rec++;
    }
check:
    idx = *(u8 *)(arg0 + 0x21);
    if (idx == 0xFF) {
        goto out;
    }
    if (D_L20_001B2FB8 < idx) {
        goto out;
    }
    if (rec == 0) {
        goto out;
    }
    if (*(s16 *)(rec - 1) >= 0) {
        goto body;
    }
    if (rec == (u16 *)D_L20_001FBB20[idx]) {
        goto body;
    }
    goto out;
out:
    *(int *)(state + 0x27C) = count < 2;
}

/* ------------------------------------------------------------------
   Second attempt (wave 20, worker 08).  What the first attempt got
   wrong and what this one measured.

   The first attempt's loop ended with

       if (*(s16 *)(rec - 1) < 0 && rec != (u16 *)D_L20_001FBB20[idx]) {
           goto out;
       }
       goto body;

   The retail's loop ends with two SEPARATE tests that both jump back
   into the body:

       lh   $v0, -0x2($s1)
       bgezl $v0, .L0039D6E8        <- branch LIKELY
         lhu  $v0, 0x0($s1)
       lw   $v0, 0x0($s3)
       beql $s1, $v0, .L0039D6E8    <- branch LIKELY
         lhu  $v0, 0x0($s1)

   Writing the two tests as two `if (...) goto body;` (instead of one
   `&&` chain) is what makes this cc1 emit the branch-LIKELY form:
   the loop's check block then ends in an unconditional jump to the
   body, GCC's thread_jumps inverts the last condition and fills the
   delay slot with the load.  With the `&&` spelling the same cc1
   emits plain `bgez`/`beq` and the body is then off by two
   instructions.  (Measured: the body matches instruction for
   instruction from 0x39D6E8 to the end once the two `if`s are used.)

   Two more measurements on this body:

   - With the default flags the compiler hoists the
     `lui $s0,%hi(D_00189EA0)` to the top of the prologue, right after
     the stack adjust; the retail has it between `sd $s1` and
     `sd $s2`, and it also keeps the high half in a callee-saved
     register (`addiu $a1,$s0,%lo(D_00189EA0)`, the "hi in a register,
     lo added at each use" form) instead of materialising the whole
     address in $a1.  `-fno-schedule-insns` reproduces both: with it
     the file's body is 75 instructions against the retail's 75 and
     only eight groups differ, all in the prologue.

   - The prologue's remaining difference is the register allocation:
     the retail gives $s4 to the %hi(D_00189EA0) copy and $s5 to the
     state pointer (`lw $s5,0x68($s2)` in the jal's delay slot), this
     attempt gives $s4 to the state and $s5 to the %hi copy, and the
     copy of the high half lands before the call instead of after it
     (the retail copies it at 0x39D6DC, after the call, because $s0
     is reused for %hi(D_001FBB20)).  No source spelling tried (the
     order of the four statements, the types of `count` and `idx`,
     the state loaded before or after the call, the state loaded at
     the use) changes that allocation.

   The attempt below is the closest one: the two `if`s and the
   default flags.  With `-fno-schedule-insns` it is eight groups of
   instructions away; with the default flags it is eleven (the whole
   prologue differs).  The `-fno-schedule-insns` profile would need a
   file of its own, which is why the attempt is left here.
*/

/* ------------------------------------------------------------------
   Wave 21, worker 08.  What this wave measured on the same body.

   The attempt below (the two `if (...) goto body;` and the default
   flags) is 300 bytes, the retail's size, and the loop matches the
   retail instruction for instruction from 0x39D6E8 to the end.  With
   `-fno-schedule-insns` only 32 instructions differ, all of them in the
   prologue; with the default flags 42 differ.

   The retail's prologue, measured:

     addiu sp,-0x50 / sd s0 / sd s1 / lui s0,%hi(D_00189EA0) / sd s2 /
     addiu a1,s0,%lo(D_00189EA0) / sd s3 / daddu s2,a0 / swc1 f20 /
     addiu a0,s2,0x10 / sd s4 / daddu s3,zero / sd ra / sd s5 / jal /
     lw s5,0x68(s2) / lbu v0,0x21(s2) / lui a0,%hi(D_L20_001FBB20) /
     addiu v1,a0,%lo(D_L20_001FBB20) / mov.s f20,f0 / sll v0,v0,2 /
     addu v0,v0,v1 / lw s1,0(v0) / daddu s4,s0,zero / b / daddu s0,a0

   so the retail keeps %hi(D_00189EA0) in $s0, copies it into $s4 only
   at 0x39D6DC (just before $s0 is reused for %hi(D_L20_001FBB20)), and
   gives $s5 to the state pointer (loaded in the jal's delay slot).
   The attempt gives $s4 to the state and $s5 to the %hi copy, and
   copies the %hi before the call.

   What was measured in this wave (about 40 compiles):

   - the register roles of the attempt and the retail are the same
     except for $s4/$s5: the attempt has state=$s4 and %hi-copy=$s5,
     the retail has %hi-copy=$s4 and state=$s5.  Everything else
     ($s0=%hi, $s1=rec, $s2=arg0, $s3=count) is already the same.
   - the copy of the %hi lands in the attempt before the call and in
     the retail after it (0x39D6DC).  The copy is the reload of the
     loop's `addiu $a1,$s4,%lo(D_00189EA0)`, and it must be placed
     before $s0 is reused for %hi(D_L20_001FBB20).  The attempt places
     it before the call because the reload happens there; the retail
     places it in the loop's preheader.
   - the source order of the three top-level statements (state, call,
     table) does not change the allocation: all six orders give 32 to
     72 differing instructions, and the best is state, call, table
     (the attempt's order).
   - the declaration order of the locals, the type of `count` (int,
     s32, u32), the type of `idx` (u8, s32), the type of `state`
     (char *, void *, u32), the type of `limit` (float, f32), the
     type of `p`, the way the second use of D_00189EA0 is written, and
     whether the mark pointer is a local all change nothing (32
     differing instructions in every case).
   - `sda`/`nosda` on D_00189EA0, D_L20_001FBB20 and D_L20_001B2F9C
     change nothing (32), except `sda` on D_00189EA0 and on
     D_L20_001FBB20, which make it worse (61 and 47).
   - no flag beats `-fno-schedule-insns` (32): `-fno-schedule-insns2`
     43, `-fno-thread-jumps` 42, `-fno-cse-follow-jumps` 42,
     `-fno-expensive-optimizations` 42, `-fno-defer-pop` 42, `-O3` 42,
     `-fno-crossjumping`/`-fno-tree-pre`/`-fno-if-conversion` are not
     options of this cc1, `-fno-delayed-branch` 80, `-O1` 73,
     `-mno-split-addresses` 57, `-G0`/`-G16` 32.
   - the attempt needs a unit of its own for `-fno-schedule-insns`
     (the flag changes the other bodies of a shared unit).  The row
     would be:
       src/levels/20_yeedil/L20_0039D680-g8.c  -O2 -G8 -ffunction-sections -fno-schedule-insns

   What this wave measured about the compiler, for the next worker:

   - this cc1's model of a branch-likely is the INVERSE of the MIPS
     manual: it believes the instruction in the delay slot of a
     branch-likely runs when the branch is TAKEN (the retail's code
     and the compiler agree, e.g. the `bgezl` in this body, whose delay
     slot loads *rec for the loop body, while the byte at 0x21 has to
     survive in another register for the fall-through path).
   - the register allocation of this body gives the LOWER callee-saved
     number to the pseudo that was created LATER: the %hi copy (created
     by the reload, after the state) got $s5 in the attempt and $s4 in
     the retail, and the state (created first) got $s4 and $s5.  The
     attempt's C creates the copy before the state, so it gets the
     higher number; the retail's C must create it after.  No spelling
     tried moves the copy's creation past the state load.

   The attempt below is the closest one; the C is the second attempt's
   with the `idx` variable kept (reading the byte twice from memory
   does not change anything).
*/

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern float func_00302440(void *, void *);
extern char D_00189EA0[];
extern u16 *D_L20_001FBB20[];
extern char *D_L20_001B2F9C __attribute__((nosda));
extern int D_L20_001B2FB8 __attribute__((sda));

void func_L20_0039D680(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);
    float limit = func_00302440(arg0 + 0x10, D_00189EA0);
    u16 *rec = (u16 *)D_L20_001FBB20[*(u8 *)(arg0 + 0x21)];
    int count = 0;
    u8 idx;

    goto check;
body:
    {
        char *p = D_L20_001B2F9C + ((*rec & 0x7FFF) << 8);

        if (p == 0) {
            goto out;
        }
        if (p != arg0 && *(u8 *)(p + 0x20) != 6) {
            if (func_00302440(p + 0x10, D_00189EA0) < limit) {
                count++;
            }
        }
        rec++;
    }
check:
    idx = *(u8 *)(arg0 + 0x21);
    if (idx == 0xFF) {
        goto out;
    }
    if (D_L20_001B2FB8 < idx) {
        goto out;
    }
    if (rec == 0) {
        goto out;
    }
    if (*(s16 *)(rec - 1) >= 0) {
        goto body;
    }
    if (rec == (u16 *)D_L20_001FBB20[idx]) {
        goto body;
    }
    goto out;
out:
    *(int *)(state + 0x27C) = count < 2;
}

/* ------------------------------------------------------------------
   Wave 22, worker 09.  The attempt below is the previous wave's C in
   a unit of its own, built with -fno-schedule-insns.  It is 300 bytes,
   the retail's size, and the loop matches the retail instruction for
   instruction from 0x39D6E8 to the end.  Only the PROLOGUE differs,
   and only in two things:

     - the copy of the high half of D_00189EA0
       (`daddu $s4,$s0,$zero` in the retail, at 0x39D6DC, AFTER the
       call) is emitted BEFORE the call in the attempt
       (`daddu $s5,$s0,$zero` at 0x39D6AC);
     - because of that, the two values take the other two callee-saved
       registers: the retail has the copy in $s4 and the state in $s5,
       the attempt has the state in $s4 and the copy in $s5.

   What this wave measured:

   - `-fno-schedule-insns` is the flag that puts the `lui $s0,%hi` back
     between the saves of $s1 and $s2 (the retail's shape).  With the
     default flags the `lui` is hoisted to the top of the prologue and
     the whole prologue differs.  The flag needs a unit of its own:
       src/levels/20_yeedil/L20_0039D680-g8.c  -O2 -G8 -ffunction-sections -fno-schedule-insns
     (with the default flags the attempt is 42 instructions different,
     with the flag it is 32 - all of them in the prologue).

   - The copy of the high half is a RELOAD of the pseudo that holds
     %hi(D_00189EA0) for the loop's use.  It is emitted before the call
     because the pseudo is live across the call; the retail emits it
     after the call, which is what a quantity that was SPLIT at the
     call would give (the first part in $s0 for the prologue's use, the
     second part in $s4 for the loop's use, with the copy joining them).
     The same thing happens in the retail for %hi(D_001FBB20): the
     table's high half is materialised into $a0 and copied into $s0
     (0x39D6E4) after the high half of D_00189EA0 has been copied out
     of it (0x39D6DC) - the register is reused.

   - Tried and measured, all of them 32 instructions different (with
     the flag) and all of them keeping the copy before the call:
     the state loaded after the call in the source (the load then
     leaves the jal's delay slot), the state loaded from a second
     expression, the two uses of D_00189EA0 through two different C
     names (that gives the MATERIALISED address, `lui`+`addiu`, not
     the split form), the loop's use through a local variable that
     holds the address (the high half then lands in a caller-saved
     register), the loop's use through a local variable declared inside
     the loop body (LICM does not hoist the copy out of the loop), the
     second use written as `(void *)D_00189EA0` or as
     `D_00189EA0 + 0`, the declaration order of the locals, the order
     of the three top-level statements, and the type of `count`,
     `idx`, `state` and `limit`.

   - The register allocation of the two values (the copy and the
     state) is the same wall as in func_L20_003BFEB8: the retail gives
     the LOWER callee-saved register to the value with the SHORTER
     live range, this compiler gives it to the other one.  gcc's
     quantity allocator hands the hard registers out in the order of
     the quantities' priority
     (floor_log2(n_refs) * n_refs * size / life), and the copy's
     live range is the shorter of the two, so the copy should get the
     lower register - it does not, and the reason is not understood.

   The attempt below is the previous wave's C, unchanged.  With the
   attempt in src/ (the unit's default flags):
     20_yeedil: instruction at +0x8 differs
     func_L20_0039D680: 0 of 1 places match
   With the attempt in a unit of its own built with -fno-schedule-insns:
     20_yeedil: instruction at +0x20 differs
     func_L20_0039D680: 0 of 1 places match
*/

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern float func_00302440(void *, void *);
extern char D_00189EA0[];
extern u16 *D_L20_001FBB20[];
extern char *D_L20_001B2F9C __attribute__((nosda));
extern int D_L20_001B2FB8 __attribute__((sda));

void func_L20_0039D680(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);
    float limit = func_00302440(arg0 + 0x10, D_00189EA0);
    u16 *rec = (u16 *)D_L20_001FBB20[*(u8 *)(arg0 + 0x21)];
    int count = 0;
    u8 idx;

    goto check;
body:
    {
        char *p = D_L20_001B2F9C + ((*rec & 0x7FFF) << 8);

        if (p == 0) {
            goto out;
        }
        if (p != arg0 && *(u8 *)(p + 0x20) != 6) {
            if (func_00302440(p + 0x10, D_00189EA0) < limit) {
                count++;
            }
        }
        rec++;
    }
check:
    idx = *(u8 *)(arg0 + 0x21);
    if (idx == 0xFF) {
        goto out;
    }
    if (D_L20_001B2FB8 < idx) {
        goto out;
    }
    if (rec == 0) {
        goto out;
    }
    if (*(s16 *)(rec - 1) >= 0) {
        goto body;
    }
    if (rec == (u16 *)D_L20_001FBB20[idx]) {
        goto body;
    }
    goto out;
out:
    *(int *)(state + 0x27C) = count < 2;
}

/* ------------------------------------------------------------------
   Wave 23, worker 09.  The attempt below is the closest one yet: in a
   unit of its own built with -fno-schedule-insns it is 300 bytes (the
   retail's size) and only EIGHTEEN instructions differ, all of them in
   the prologue and the entry block.  The wave-22 attempt was 32
   instructions different with the same flag; the three source changes
   below are what got it closer.

   WHAT THIS WAVE CHANGED IN THE SOURCE

   1. The loop's index in a variable:

          u32 idx2 = (*rec & 0x7FFF) << 8;
          char *p = D_L20_001B2F9C + idx2;

      instead of `char *p = D_L20_001B2F9C + ((*rec & 0x7FFF) << 8);`.
      This is what makes the loop's registers the retail's: the retail
      keeps the index in $v0 and the base in $v1 (`andi $v0,$v0,0x7FFF ;
      sll $v0,$v0,8 ; addu $a0,$v1,$v0`) and the attempt had them the
      other way round.  (32 -> 24 instructions different.)

   2. D_L20_001B2F9C WITHOUT the nosda attribute.  In a -G8 unit the
      plain declaration gives the retail's absolute form (`lui
      $v1,%hi(D_1B2F9C) ; lw $v1,%lo(D_1B2F9C)($v1)`) - the wave-4
      correction - and it is measured here: with nosda the body is 24
      instructions different, without it 22.  (The same symbol is
      declared plainly for func_L20_0039E890 in
      src/levels/20_yeedil/L20_0039C448-g8.c, and that function is
      matched.)

   3. The check block's table through a BYTE POINTER:

          if (rec == *(u16 *)((u8 *)D_L20_001FBB20 + (idx << 2))) {

      instead of `if (rec == (u16 *)D_L20_001FBB20[idx]) {`.  This is
      the wave-4 finding (the constant stays in the load's displacement
      only when the address is built through a byte pointer variable),
      and it holds here too.

   The flag: the attempt needs a unit of its own, built with
   -fno-schedule-insns (the default flags give 38 instructions
   different against the 18 with the flag).  The row would be:

        src/levels/20_yeedil/L20_0039D680-g8.c  -O2 -G8 -ffunction-sections -fno-schedule-insns

   and the function's marker has to be taken out of
   src/levels/20_yeedil/L20_0039C448-g8.c.

   WHAT IS STILL DIFFERENT (18 instructions, all in the prologue and the
   entry block; the loop from 0x39D6E8 to the end matches the retail
   instruction for instruction):

     - the copy of the high half of D_00189EA0.  The retail copies it
       into $s4 AFTER the call (`daddu $s4,$s0,$zero` at 0x39D6DC), the
       attempt copies it into $s5 BEFORE the call (`daddu $s5,$s0,$zero`
       at 0x39D6AC).  Because the copy lands early, the two values take
       the other two callee-saved registers (the attempt has the state in
       $s4 and the copy in $s5, the retail the other way round), the
       frame's saves come out in the order s0, s1, s2, s3, s5, s4
       instead of the retail's ascending s0, s1, s2, s3, s4, s5, and the
       copy of %hi(D_1FBB20) into $s0 lands before the `addu` instead of
       in the branch's delay slot.
     - the word at 0x60(state) and the two table registers: the retail
       has the word in $v1 and the base in $v0, the attempt the other
       way round.  Same cause: the copy's position.

   MEASURED AND NOT CHANGING THE PROLOGUE (all with the flag, all 18
   instructions different): the state's load before or after the call in
   the source, the rec load before or after the count, the count as
   int/s32/u32, the index as u8/s32, the order of the three top-level
   statements, the table's entry type (u16/u32/pointer), the comparison
   with the table's start as a word, the D_00189EA0 pointer in a local
   variable, the state as a local variable, the second assignment of
   D_00189EA0, and the nosda attribute on D_00189EA0 and on
   D_L20_001FBB20 (both make it worse).

   THE COMPILER'S TWO MOVES THAT MATTER HERE (measured on this body):
   the reload pass emits the copy of a value that is live across a call
   BEFORE the call (the value has to be in a callee-saved register by
   then), and the quantity allocator hands out the callee-saved
   registers by the priority floor_log2(n_refs) * n_refs * size / life,
   so the value with the SHORTEST live range gets the LOWEST register.
   The retail's copy is made late (after the call) and therefore has the
   shorter live range, and it gets $s4; the attempt's copy is made early
   and gets $s5.  One wall, both symptoms.

   The attempt below is the closest one; it is 18 instructions different
   with the flag and 38 with the default flags.  With the attempt in
   src/ in a unit of its own:
      20_yeedil: instruction at +0x20 differs
      func_L20_0039D680: 0 of 1 places match
*/

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern float func_00302440(void *, void *);
extern char D_00189EA0[];
extern char *D_L20_001FBB20[];
extern char *D_L20_001B2F9C;
extern int D_L20_001B2FB8 __attribute__((sda));

void func_L20_0039D680(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);
    float limit = func_00302440(arg0 + 0x10, D_00189EA0);
    u16 *rec = (u16 *)D_L20_001FBB20[*(u8 *)(arg0 + 0x21)];
    int count = 0;
    u8 idx;

    goto check;
body:
    {
        u32 idx2 = (*rec & 0x7FFF) << 8;
        char *p = D_L20_001B2F9C + idx2;

        if (p == 0) {
            goto out;
        }
        if (p != arg0 && *(u8 *)(p + 0x20) != 6) {
            if (func_00302440(p + 0x10, D_00189EA0) < limit) {
                count++;
            }
        }
        rec++;
    }
check:
    idx = *(u8 *)(arg0 + 0x21);
    if (idx == 0xFF) {
        goto out;
    }
    if (D_L20_001B2FB8 < idx) {
        goto out;
    }
    if (rec == 0) {
        goto out;
    }
    if (*(s16 *)(rec - 1) >= 0) {
        goto body;
    }
    if (rec == *(u16 *)((u8 *)D_L20_001FBB20 + (idx << 2))) {
        goto body;
    }
    goto out;
out:
    *(int *)(state + 0x27C) = count < 2;
}
