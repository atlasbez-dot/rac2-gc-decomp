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
   and the interleaving of the `lui` with the register saves are left. */
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
    if (*(s16 *)(rec - 1) < 0 && rec != (u16 *)D_L20_001FBB20[idx]) {
        goto out;
    }
    goto body;
out:
    *(int *)(state + 0x27C) = count < 2;
}
