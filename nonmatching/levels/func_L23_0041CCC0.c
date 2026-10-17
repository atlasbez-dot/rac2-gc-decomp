/* func_L23_0041CCC0 (152 bytes, 1 place, level 23, default profile -O2 -G0)
   -- measured 0 of 1: candidate is 156 bytes, ONE instruction over.

   Resets the level-23 "collected" bookkeeping: clears three 50-word blocks at
   D_L23_00259050 + i*0xF0 (stride 60 words, 50 cleared), zeroes D_L23_001B3738[3]
   and D_L23_001B3744, then latches two counters out of the object state (+0x2FA,
   +0x2FE) into D_L23_001B1FA0[1..3].

   The candidate below is structurally right: the 2-D form gives retail's exact
   address arithmetic (`addu $v1,$v0,$t1` then `addiu $v1,$v1,0xC4`, i.e. the +196
   stays OUTSIDE the symbol - a `(s32 *)((char *)sym + i * 0xF0) + 0x31` pointer
   folds the +196 into the symbol's reloc and is 144 bytes, too short), and the
   inner loop (`sw zero,0($v1)` / counter decrement / `bgez` / `addiu $v1,$v1,-4`
   in the delay slot) matches instruction for instruction after alignment.

   The residue is the outer loop's own counter. This cc1 gives `i` a second
   pseudo: the .loop RTL holds `(set (reg/v:SI 86) (reg:SI 125))` and the object
   shows `addiu $v0,$a1,0x1` ... `daddu $a1,$v0,$zero` ... `slti $v0,$a1,0x3`
   where retail has one in-place `addiu $a0,$a0,0x1`. Present before sched2 (kept
   under -fno-schedule-insns2) and before reload, so it is the loop/allocator
   path, not scheduling. Same 156 bytes for: for/while/do-while, `i <= 2`,
   `3 > i`, counters declared in every order, `register`, unsigned outer, a local
   row pointer, a flat `[i * 60 + j]` index, a struct row, and an advanced `*e++`
   over the small array (measured in five runs, ~35 forms).

   Remaining, unproven lead: the two loop counters are the only user variables
   (`/v` pseudos 86 and 87); retail's outer counter behaves like a compiler-made
   biv (in-place update, no copy), so a source shape in which the counter is not
   needed after the increment - e.g. one where the small array is indexed by the
   same expression the multiply uses - is the one place left to look.

   The tail store order also differs (retail: 0xC, then D_L23_001B1FA0[0] via the
   $1B base, then 0x8, then 0x4 in the $ra slot; the candidate emits
   [0]=0,0xC,0x4,0x8) - that is downstream of the loop's register state. */

typedef signed short s16;
typedef signed int s32;

extern s32 D_L23_001B3744;
extern s32 D_L23_001B3738[3];
extern s32 D_L23_001B1FA0[4];
extern s32 D_L23_00259050[3][60];

void func_L23_0041CCC0(char *arg0) {
    char *st = *(char **)(arg0 + 0x68);
    s32 i, j;

    D_L23_001B3744 = 0;
    for (i = 0; i < 3; i++) {
        D_L23_001B3738[i] = 0;
        for (j = 0x31; j >= 0; j--)
            D_L23_00259050[i][j] = 0;
    }
    D_L23_001B1FA0[3] = *(s16 *)(st + 0x2FE);
    D_L23_001B1FA0[0] = 0;
    D_L23_001B1FA0[2] = *(s16 *)(st + 0x2FA);
    D_L23_001B1FA0[1] = 0;
}
