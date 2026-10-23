#include "include_asm.h"

#include "common.h"

/* Near miss: the body is decoded, the frame and the register allocation are not.
   Needs a -G8 unit (the two level floats are read through $gp) and a grouped
   quadword copy for the 16-byte vectors.

   What is recovered from the retail bytes:
     - the frame is 0xC0, with $s0-$s4 and $ra saved from 0x80 and the two
       $f20/$f21 from 0xB0;
     - the six 16-byte locals sit at 0x00, 0x10, 0x20, 0x30, 0x40 and 0x50, and
       the third float of the vector at 0x40 is written from 0x64 of the state;
     - the calls, in order: func_2E4340, func_314038, func_2E45F0, func_2E4B70,
       func_2E47D0, func_2E4340, func_316638 and twice func_2E4310;
     - the two scaled level floats: *(f32 *)0x1B0FE0 times 1/3600 (the retail
       word 0x3991A2B4) and *(f32 *)0x1B0FE4 times 1/60 (0x3C888889);
     - the vector at 0x40 is cleared with `por $v0,$zero,$zero` and `sq $v0,0x40($sp)`
       and then copied to 0x30 with a grouped `lq`/`sq`.

   What is not recovered: the exact local layout and the register allocation, the
   first call's second argument (the retail leaves $a1 unset, so the source
   passes a value it never sets), and the argument order of the later calls.

   Measured (tools/check.py func_L07_003F6DC0 --diff): not matched; the frame and
   the saved-register set differ from the first instruction.
*/

typedef int TI128 __attribute__((mode(TI)));

extern f32 D_L07_001B0FE0 __attribute__((sda));

extern f32 D_L07_001B0FE4 __attribute__((sda));

extern void func_2E4340(void *a, void *b, void *c);

extern void func_314038(void *a, f32 b, f32 c, f32 d);

extern f32 func_2E45F0(void *a, void *b);

extern void func_2E4B70(void *a, void *b);

extern void func_2E47D0(void *a, void *b);

extern void func_316638(void *a, f32 b);

extern void func_2E4310(void *a, void *b);

void func_L07_003F6DC0(u8 *a0)
{
    u8 *s0;
    u8 *s1;
    u8 *s2;
    u8 *s3;
    u8 *s4;
    f32 v0[4];
    f32 v1[4];
    f32 v2[4];
    TI128 w;
    TI128 v;
    f32 v3[2];
    f32 v4[4];
    f32 f20;
    f32 f21;

    s0 = a0;
    s4 = s0 + 0x10;
    func_2E4340(v0, 0, s4);
    s2 = *(u8 **)(s0 + 0x68);
    s3 = s2 + 0x50;
    f21 = D_L07_001B0FE0 * (1.0f / 3600.0f);
    f20 = D_L07_001B0FE4 * (1.0f / 60.0f);
    func_314038(s0 + 0x18, *(f32 *)(s2 + 0x60), f21, f21);
    func_2E45F0(v1, v0);
    *(TI128 *)&v = 0;
    *(f32 *)((u8 *)&v + 8) = *(f32 *)(s2 + 0x64);
    *(TI128 *)&w = *(TI128 *)&v;
    func_2E4B70(v4, &w);
    func_2E47D0(v1, v1);
    func_2E4340(v2, v1, s3);
    func_316638(v2, f21);
    func_2E4310(s3, s3);
    func_2E4310(s4, s3);
}
