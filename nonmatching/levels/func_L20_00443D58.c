/* near-miss: func_L20_00443D58 (20_yeedil, 152 bytes).
   Reaches retail's exact 0x60 frame and its `swc1 $f20,0x50($sp)` save once the helper
   output is re-read into a second float local (`g`) after the 0x443B60 call.
   0x2c: retail sets `$a3 = $sp+0x20` before `$a2 = $s2` for the 0x443B60 call, this cc1
   the other way round; every other word matches. */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern void func_L20_00443B60(char *, TI128 *, TI128 *, f32 *);
extern s32 func_002A7820(s32, s32);
extern void func_L20_00449FD0(char *, TI128 *, TI128 *, s32, f32, f32);

void func_L20_00443D58(char *arg0)
{
    char *state = *(char **)(arg0 + 0x68);
    TI128 v0;
    TI128 v1;
    f32 f;
    f32 g;
    s32 r;

    f = 1.0471977f;
    func_L20_00443B60(arg0, &v0, &v1, &f);
    g = f;
    r = func_002A7820(0x12C, 0x258);
    func_L20_00449FD0(arg0, &v0, &v1, r, g, (f32)*(u8 *)(state + 0x36));
}
