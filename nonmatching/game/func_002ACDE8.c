#include "include_asm.h"

/* The retail body normalises the object's quaternion (a scale by -1, the fourth
   component copied from the second argument), takes the 128-bit quaternion of the
   second argument, clears its fourth word and multiplies the two.

   The frame, the register allocation of the arguments and the calls match; what
   differs is the 128-bit copy of the quaternion: the retail materialises the
   destination pointer (`addiu $a2,$sp,0x10`) and stores through it
   (`lq $v0,0($s2)`; `sq $v0,0($a2)`), while this cc1 folds the offset into the
   `sq` (`sq $v0,0x10($sp)`) and keeps the pointer in $s1.  The opt-in grouped copy
   (-frac2-qcopy) does not fire here: the destination is a local, so the two
   operands of the assignment are not two memory references at the expansion. */
typedef __attribute__((mode(TI))) int QI_002ACDE8;

extern void func_00282D30(char *dst, char *src, float scale);
extern void func_002837D0(char *dst, char *a, char *b);

void func_002ACDE8(void *a0, void *a1, void *a2, float x)
{
    QI_002ACDE8 m0, m1, m2;

    func_00282D30((char *)&m0, (char *)a2, -1.0f);
    *(float *)((char *)&m0 + 0xC) = *(float *)((char *)a2 + 0xC);
    m1 = *(QI_002ACDE8 *)a1;
    *(int *)((char *)&m1 + 0xC) = 0;
    func_002837D0((char *)&m2, (char *)a2, (char *)&m1);
    func_002837D0((char *)a0, (char *)&m2, (char *)&m1);
}
