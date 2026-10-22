/* func_L11_00449AD8 (404 bytes, 1 place: 11:00449AD8) -- NEAR MISS, not integrated.
   This C compiles to 404 bytes against retail's 404 in a unit of its own with the
   `-frac2-qcopy` profile (the 16-byte copy of the direction vector is retail's grouped
   `lq $v0,0($s2) ; sq $v0,0($v1)` with both addresses in registers, which only that
   opt-in pattern emits; a plain unit gives `sq $v0,0x330($s0)` instead).  29 of the 101
   words still differ, all of them register-allocation or scheduling choices:

   What the function is: it takes the object and a 16-byte direction vector, reads the
   object's state (object+0x68) and the flag at state+0x36E, and, depending on the flag,
   computes a scale and a base angle and writes three floats into the state at +0x330,
   +0x334 and +0x338.  The two branches share the object/vector difference
   (object+0x10/0x14 minus vector+0x00/0x04) and the length helper func_300BD0
   (func_00283248), and the two 0x330/0x334 writes are sin and cos (func_300B08 =
   func_00283180, func_300B20 = func_00283198) of the base, scaled.  The constants are
   0.17453295f (0x3E32B8C4), 0.78539825f (0x3F490FDC), 15.0f, 8.0f, and 4.0f/2.0f; the
   helper func_32CB48 (func_002A7878) is called with a negative and a positive pair.
   The caller at 0x447788 passes (object, vector), so the parameter order is fixed.

   What differs (29 words):
   1. The two pointer parameters take the saved registers the other way round.  Retail
      copies the object into $s1 in the prologue (`daddu $s1,$a0,$zero` before the `sd
      $ra`) and the vector into $s2 in the delay slot of the `beqz`; this C does the
      opposite ($s2 for the object, $s1 for the vector) and puts the object's copy after
      the `$ra` save.  Both pointers are referenced six times each and both are live
      across calls, so the priority is a tie and the tie-break decides; the reference
      source must give the object the higher priority.  Tried: block-scoped locals,
      separate names per branch, `float *` for the vector, separate load locals,
      mentioning the vector before the object, inlining the state load, and the state
      loaded through an `s32`; none moves the allocation.
   2. The two float constants of a call are materialised in the other order.  Retail
      loads the first argument's constant into $f12 before the second's into $f13 (the
      `lui $at,0xBE32 ; ori ; mtc1 $at,$f12` pair before the `0x3E32` one for the
      0.17453295f pair, and the `0xC000` one before the `0x4000` one for the 4.0f/2.0f
      pair); this C always loads the second argument's constant first, except for the
      0.78539825f pair, which comes out right.  The values are right, only the order of
      the two three-instruction sequences differs.
   3. In the second branch the `add.s $f20,$f0,$f1` that adds 8.0f to the second
      func_32CB48 result is scheduled after the vector copy here (into the delay slot of
      the `jal func_300B08`), where retail has it before the `lq`/`sq` and puts the
      `mov.s $f12,$f21` in the delay slot.  The first branch's order is retail's.

   Tried (about twenty compiles, none moves item 1): the block-scoped locals of the two
   branches (which did fix the $f20/$f21 split of the second branch, where retail keeps
   the base in $f21 and the scale in $f20), `+=` on the state floats against an explicit
   temporary, the scale assigned back (`scale = scale * func_300B20(base)`) against a
   fresh temporary, the base as one expression, the 15.0f assigned before or after the
   base, the constants as locals, the vector as `float *`, and the vector copy written
   as a local.  What is needed next is a way to make the object parameter outrank the
   vector one in the allocator, and a spelling that makes the two call arguments'
   constants load in argument order.
*/

#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern float func_300BD0(float f12, float f13);
extern float func_32CB48(float f12, float f13);
extern float func_300B08(float f12);
extern float func_300B20(float f12);

void func_L11_00449AD8(char *object, char *vec)
{
    char *state = *(char **)(object + 0x68);

    if (*(s16 *)(state + 0x36E) != 0) {
        float dx = *(float *)(object + 0x10) - *(float *)(vec + 0x0);
        float dy = *(float *)(object + 0x14) - *(float *)(vec + 0x4);
        float base = func_300BD0(dx, dy) + func_32CB48(-0.17453295f, 0.17453295f);
        float scale = 15.0f;
        float t;

        *(TI128 *)(state + 0x330) = *(TI128 *)vec;
        *(float *)(state + 0x330) += func_300B08(base) * scale;
        *(float *)(state + 0x334) += func_300B20(base) * scale;
        t = func_32CB48(-4.0f, 4.0f);
        *(float *)(state + 0x338) = *(float *)(object + 0x18) + t;
    } else {
        float dx = *(float *)(object + 0x10) - *(float *)(vec + 0x0);
        float dy = *(float *)(object + 0x14) - *(float *)(vec + 0x4);
        float base = func_300BD0(dx, dy) + func_32CB48(-0.78539825f, 0.78539825f);
        float scale = func_32CB48(-2.0f, 2.0f) + 8.0f;

        *(TI128 *)(state + 0x330) = *(TI128 *)vec;
        *(float *)(state + 0x330) += scale * func_300B08(base);
        scale = scale * func_300B20(base);
        *(float *)(state + 0x334) += scale;
    }
}
