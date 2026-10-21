/* func_L00_003B60E8 (108 bytes, 27 places) -- NEAR MISS, not integrated.

   The prologue, the two field loads and the register use are retail's exactly.  What
   is left is the loop shape.  Retail keeps the record increment in the *annulled*
   delay slot of a branch-likely branch and the loop tail at the bottom:

       loop: lw    $v0, 0($s1)
             beql  $v0, $zero, +0x10      ; skip the call
             addiu $s0, $s0, 0x150        ; annulled: only on the taken path
             jal   func_322EC8
             daddu $a0, $s0, $zero
             addiu $s0, $s0, 0x150        ; the fall-through path
             addiu $s2, $s2, -0x1
             bgez  $s2, loop
             addiu $s1, $s1, 0x4

   this cc1 rotates every loop spelling into a form with the increments at the *top*
   of the body and a plain `beqz` where retail has `beql`, so the increment is
   duplicated by the scheduler instead of by the source.  Eleven spellings measured
   (for / while / do-while, the increment in the body or in the for-clause, the
   `continue` form, the increment written in both arms of the if): none produces the
   branch-likely form or keeps the increments in the loop tail.

   Wave 12 (worker s4). */
typedef struct OBJ4 {
    char pad0[8];
    int f8;
    int fC;
} OBJ4;

extern void func_322EC8(void *p);

void func_L00_003B60E8(OBJ4 *a0)
{
    char *base = (char *)a0 + 0x20;
    char *s = base + a0->f8;
    int *w = (int *)(base + a0->fC);
    int i;

    for (i = 24; i >= 0; i--, w++) {
        if (*w != 0)
            func_322EC8(s);
        s += 0x150;
    }
}
