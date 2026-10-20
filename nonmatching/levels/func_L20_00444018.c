/* near-miss: func_L20_00444018 (20_yeedil, 108 bytes).
   Retail hoists the 0.78539824f materialisation above `addiu $sp,$sp,-0x50` and gives
   `$s1` to the state pointer, `$s2` to `&v1`; this cc1 sinks the constant below the
   frame adjust and swaps the two callee-saved registers. 
   Second wave (20_yeedil, 2026-10-20) re-measured this one: eight further source
   shapes (the two locals as char[16], unsigned int[4], float[4]; one 32-byte array
   used as v and v+16; a TI128 pair; the declaration order of the locals; the float
   assigned as a separate statement; the float as the first local) all allocate $s1 to
   the local's address and $s2 to the state pointer, and all sink the 0.78539824f
   materialisation below the frame adjust. The constant is 0.78539824f (0x3F490FDC),
   one ulp above pi/4, and it is loaded with lui/ori/mtc1 exactly as retail has it.
   The body is right: the second call f_0044AC38 takes (object, index = state->[0x240],
   &v0, &v1), the index is a word and the two vectors are swapped against the first
   call. Wall: the callee-saved register order plus the entry-block constant.*/
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern void func_L20_00443B60(char *, TI128 *, TI128 *, f32 *);
extern void func_L20_0044AC38(char *, s32, TI128 *, TI128 *);

void func_L20_00444018(char *arg0)
{
    char *state = *(char **)(arg0 + 0x68);
    TI128 v0;
    TI128 v1;
    f32 f;

    f = 0.78539824f;
    func_L20_00443B60(arg0, &v0, &v1, &f);
    func_L20_0044AC38(arg0, *(s32 *)(state + 0x240), &v0, &v1);
}
