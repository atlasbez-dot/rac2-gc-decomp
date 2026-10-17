/* 0 of 1 places match - last line: 20_yeedil: instruction at +0x2c differs
   The whole body is retail's, byte for byte, at retail's 164 bytes: two `addiu $s0/$s1`
   saves, the 0.78539824f store into the jal's delay slot, the 0.0166666675f scaling call,
   the `lbu`/`cvt.s.w` float argument and all three callees. The single difference is the
   order of two register set-ups before the first jal: retail sets `$a3 = $sp+0x20` before
   `$a2 = $s0`, this cc1 emits `$a2` first. The same swap is recorded next door
   (func_L20_00443D58, "0x2c") and in func_L20_00444018's callee-saved pair. Measured
   alternatives that are worse: a named `float *pf = &f` for the fourth argument costs a
   frame slot and an $s3 (176 bytes), and `__builtin_memcpy`/struct-assignment spellings of
   the TI128 pair change nothing here. */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern float D_L20_001B2090 __attribute__((sda));

extern int D_L20_001B2094 __attribute__((sda));

extern void func_L20_00443B60(char *, char *, char *, float *);

extern void func_L20_0044B100(char *, char *, char *, char *, int, float, int);

extern void func_00282F20(char *, char *, float);

/* Builds a 0.78539824f float next to two 16-byte buffers, lets func_L20_00443B60 fill all
   three, rescales the second buffer by D_L20_001B2090 * 0.0166666675f in place, then hands
   the three buffers plus the state's 0x1F0 block, the shared word D_L20_001B2094, the
   state's 0x35 byte as a float and its 0x210 word to func_L20_0044B100. */
void func_L20_00444088(char *arg0)
{
    char *state = *(char **)(arg0 + 0x68);
    TI128 a;
    TI128 b;
    f32 f;

    f = 0.78539824f;
    func_L20_00443B60(arg0, (char *)&a, (char *)&b, (float *)&f);
    func_00282F20((char *)&b, (char *)&b, D_L20_001B2090 * 0.0166666675f);
    func_L20_0044B100(arg0, (char *)&a, (char *)&b, state + 0x1F0, D_L20_001B2094,
                      (f32)*(u8 *)(state + 0x35), *(s32 *)(state + 0x210));
}
