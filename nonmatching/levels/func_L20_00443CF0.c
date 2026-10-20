/* near-miss: func_L20_00443CF0 (20_yeedil, 100 bytes).
   0x24: retail emits `daddu $a1,$sp,$zero` before the prologue's `sd $s0,0x30($sp)`,
   this cc1 the other way round. Every other word matches. Same wall as the recorded
   func_001334B8 row (a single scheduling word in the prologue). 
   Second wave (20_yeedil, 2026-10-20) re-measured this one and could not move it:
   ten further source shapes for the two locals (char[16], unsigned int[4], float[4],
   a TI128 pair, one 32-byte array used as v and v+16, a 48-byte struct holding all
   three objects, the &v[0] spellings, a `char *p0 = v0` temporary, the declaration
   order of the locals, and the float assigned as a separate statement) all give the
   same 100 bytes with only these two words swapped. The float constant is 1.0471977f
   (0x3F860A93) and is materialised in the entry block, before the frame setup, exactly
   as retail has it. Wall: the prologue interleaving - a lever that pins the local's
   address computation before the `sd $s0,0x30($sp)` prologue save is what is missing.*/
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern void func_L20_00443B60(char *, TI128 *, TI128 *, f32 *);
extern void func_L20_00440198(s32, TI128 *, TI128 *, f32);

void func_L20_00443CF0(char *arg0)
{
    char *state = *(char **)(arg0 + 0x68);
    TI128 v0;
    TI128 v1;
    f32 f;

    f = 1.0471977f;
    func_L20_00443B60(arg0, &v0, &v1, &f);
    func_L20_00440198(*(s32 *)(state + 0x21C), &v0, &v1, f);
}
