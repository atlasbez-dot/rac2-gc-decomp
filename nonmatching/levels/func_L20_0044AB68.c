/* Near miss from src/levels/20_yeedil/L20_00449178.c: 200 bytes, retail 204.
   This unit has no $gp access, so the body belongs here (-G0), not in the
   -G8 sibling.

   Everything matches but one instruction: the retail writes the 128-bit zero
   of the stack buffer with a materialised register
       por $v0, $zero, $zero ; sq $v0, 0x20($sp)
   while this cc1's rac2_fold_zero_ti_store pass folds that store to
       sq $zero, 0x20($sp)
   (4 bytes short).  The pass folds whenever the zero register is dead after
   the store, and it is dead here.

   Measured this wave (2026-10-20): the frame (0x50), the two saved
   registers, the 0.3f materialisation, the two float calls, the 14-argument
   func_0032C700 call with its four stack words, the branch-likely test and
   the epilogue are all the retail instructions.  The union spelling (float
   f[4] / TI128 q) is what puts the float at sp+0x28 and keeps the buffer
   address out of a callee-saved register, as the retail has it.

   Spellings tried for the zero, all of which fold to sq $zero: `v.q = 0`,
   `v = 0`, `v = {0}`, `*(volatile TI128 *)&v = 0`, the same store through a
   pointer, and a struct with a TI128 member.  The por survives only when the
   zero feeds two stores (measured: two stores of the same zero keep
   `por $2,$0,$0` and two `sq $2`), and the retail has one store.  The same
   wall is recorded for func_L00_002A75D8, func_L00_003ACC88,
   func_L13_0040A2C8 and func_L04_00422D40. */

#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

extern void func_00283098(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_002E59F8(int);
extern void func_0032C700(void *a0, int a1, int a2, int a3, int a4, int a5,
                           int a6, int a7, float f12, float f13, int s1, int s2,
                           int s3, int s4);

void func_L20_0044AB68(char *arg0) {
    union {
        TI128 q;
        float f[4];
    } v;
    char *state;

    v.q = 0;
    v.f[2] = 0.3f;
    func_00283098(&v, &v, arg0 + 0xC0);
    func_00282CC0(&v, &v, arg0 + 0x10);
    func_0032C700(&v, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 0, 0.666f, 20.0f, 1, 0,
                  0, 0);
    state = *(char **)(arg0 + 0x68);
    if (*(int *)(state + 0x1B8) != -1) {
        func_002E59F8(*(int *)(state + 0x1B8));
        *(int *)(state + 0x1B8) = -1;
    }
}
