/* func_00303DA8 - 116 bytes, 28 places (the boot and every level), retail at
   0x00303DA8: addiu $sp,$sp,-0x20 ; sd $s0,0x10($sp) ; sd $ra,0x18($sp) ;
   daddu $s0,$a0,$zero ; lq $v0,0x0($s0) ; sq $v0,0x0($sp) ; lwc1 $f0,0x8($sp) ;
   daddu $a0,$s0,$zero ; daddu $a1,$sp,$zero ; addiu $a2,$zero,0x12 ;
   add.s $f0,$f0,$f12 ; daddu $a3,$zero,$zero ; daddu $t0,$zero,$zero ;
   jal func_2761F8 ; swc1 $f0,0x8($sp) ; bnez $v0,+0x18 ; lui $a1,0x1C ;
   lui $at,0x461C ; ori $at,$at,0x3C00 ; mtc1 $at,$f0 ; b +0x18 ;
   ld $s0,0x10($sp) ; daddu $a0,$s0,$zero ; jal func_282E80 ;
   addiu $a1,$a1,-0x5060 ; ld $s0,0x10($sp) ; ld $ra,0x18($sp) ; jr $ra ;
   addiu $sp,$sp,0x20.

   Measured near miss: 112 of 116 bytes with the default profile
   ("-O2 -G0 -ffunction-sections"), i.e. the whole body, the call arguments, the
   frame, the tail and the two constants match; what is missing is one
   instruction and the order of the argument setup.

   1. The retail keeps `daddu $a0,$s0,$zero` before the first call although
      `$a0` already holds that value (the copy `daddu $s0,$a0,$zero` is at the
      top).  This cc1 deletes it: the reload pass knows the pseudo for the
      object pointer lives in `$s0` and that `$a0` still holds the incoming
      argument, so the move is redundant.  The final RTL still carries the move
      ("(insn 31 ... (set (reg:SI 4 a0) (reg/v:SI 84))"), it disappears between
      the final RTL and the assembly.  A source that keeps the object pointer
      in a local (`void *p = obj;`, the pointer used for the copy and for both
      calls) does not change that: the copy is propagated into the incoming
      argument again and the move is deleted again.  What would be needed is a
      source whose object pointer is a pseudo the allocator puts in `$s0` and
      whose value at the call is not provably the incoming `$a0`.

   2. The argument setup of the first call is in the retail's order
      (a0, a1, a2, a3, t0, with the add.s between a2 and a3); this cc1
      hoists the constants (`addiu $a2,$zero,0x12`, `daddu $a3,$zero,$zero`,
      `daddu $t0,$zero,$zero`) into the body and leaves `daddu $a1,$sp,$zero`
      early as well.  With "-fno-schedule-insns2" the order is still scattered,
      so this is the reload pass, not the scheduler.

   The measured values: the second constant is 0x461C3C00, which is 9999.0f
   (not 10000.0f), and the data address the last call takes is
   0x001BAFA0 (0x1C0000 - 0x5060), which is in the memory a level replaces,
   so it is named `ref_00303DA8_00` and its value is read from the retail
   bytes at each place.

   The VU0 helper `func_2761F8` takes five integer arguments (the fifth in
   `$t0`): the same shape appears in `func_00307298` and `func_00304AD0`,
   where the call is `daddu $a3,$s2,$zero ; jal func_2761F8 ;
   daddu $t0,$zero,$zero`.  `func_282E80` is a VU0 routine that returns its
   result in `$f0` (it ends in `mtc1 $a0,$f0`), so the function returns a
   float. */

#include "common.h"

/* The 128-bit integer mode is what reaches retail's lq/sq copies. */
typedef int TI128 __attribute__((mode(TI)));

extern int func_2761F8(void *a, void *b, int c, int d, int e);
extern float func_282E80(void *a, void *b);

/* The address the last call takes; its value differs from program to program. */
extern char ref_00303DA8_00[];

/* Asks the vector unit whether the shifted position is inside the field, and
   gives the distance to a fixed point when it is. */
float func_00303DA8(void *obj, float delta)
{
    TI128 local = *(TI128 *)obj;
    float *f = (float *)((char *)&local + 8);

    *f = *f + delta;
    if (func_2761F8(obj, &local, 0x12, 0, 0) != 0)
        return func_282E80(obj, ref_00303DA8_00);
    return 9999.0f;
}
