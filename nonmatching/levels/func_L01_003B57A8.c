/* 0 of 1 places match - last line: 01_oozla: instruction at +0x18 differs
   G8: the body reads the 0xB264C word through $gp, so it needs the
   src/levels/01_oozla/L01_003835D8-g8.c unit (-G8).
   The body is recovered: the three words at the state's 0x310 are the indices
   of the three positions, the word D_L01_001B264C is the table base, the
   position is the 16-byte record at base + index * 0x80 + 0x30, func_00282E80
   measures it against D_00189EA0, the closest one is copied to the output and
   its distance stored at 0xC, and func_002A89A8 scales the result into 0x8.
   Four differences are left: retail keeps the table base in $v0 and the index
   in $v1 while this cc1 uses $a2 and $v1, retail's table address is the
   separate `addiu $v1,$v1,0x30` (the 0x30 is materialised) where this cc1
   folds it into the load (`lq $v0,0x30($v1)`), retail's float guard is the
   branch-likely `bc1fl` with the counter's decrement copied into its annulled
   slot where this cc1 emits a plain `bc1f` with the record's load in the slot,
   and the counter is 3 in retail against 2 here (the loop runs four times in
   retail, so the source's counter is 4 with the test at the bottom).  The
   counter spelling, the address through a pointer variable, a struct member
   and an integer address were all measured; the loop's three iterations and
   the table's stride of 0x80 are right. */

#include "include_asm.h"
#include "common.h"

typedef unsigned int TI128 __attribute__((mode(TI)));

extern u8 *D_L01_001B264C __attribute__((sda));

extern char D_00189EA0[];

extern float func_00282E80(void *, void *);

extern float func_002A89A8(void *, int, float);

void func_L01_003B57A8(u8 *arg0, u8 *out) {
    u32 *p = (u32 *)(*(u32 *)(arg0 + 0x68) + 0x310);
    TI128 v;
    int count = 4;
    f32 f;

    *(f32 *)(out + 0xC) = 0.0f;
    while (--count >= 0) {
        u32 index = *p;

        if (index != 0xFFFFFFFF) {
            u8 *base = D_L01_001B264C;

            v = *(TI128 *)(base + index * 128 + 0x30);
            f = func_00282E80(&v, D_00189EA0);
            if (*(f32 *)(out + 0xC) < f) {
                *(TI128 *)out = v;
                *(f32 *)(out + 0xC) = f;
            }
        }
        p++;
    }
    *(f32 *)(out + 0x8) = func_002A89A8(out, 0, 10.0f);
}
