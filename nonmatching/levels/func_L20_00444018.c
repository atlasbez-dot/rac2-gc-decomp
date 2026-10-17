/* near-miss: func_L20_00444018 (20_yeedil, 108 bytes).
   Retail hoists the 0.78539824f materialisation above `addiu $sp,$sp,-0x50` and gives
   `$s1` to the state pointer, `$s2` to `&v1`; this cc1 sinks the constant below the
   frame adjust and swaps the two callee-saved registers. */
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
