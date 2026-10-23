#include "include_asm.h"

#include "common.h"

/* Near miss: 320 bytes against the retail's 308, and the shape is the retail's.
   Needs a -frac2-qcopy unit for the grouped lq/sq pair.

   What is recovered: the call chain (func_312FA8, func_313008, func_313DD8,
   func_30FED0, func_355488, func_3109C8, func_3E2710, func_310610), the
   comparison that gates the whole tail of the body, the flag word update
   (0x41 / 0xEFFF), the 0xFF byte at 0xA8, the 0x98 word, the 16-byte copy of
   s1+0x10 and the +0.5 on its third float.

   What differs:
     - the retail's 16-byte vector is the outgoing argument slot itself
       (`lq $v0,0($a0)` ; `sq $v0,0($a1)` with $a1 = $sp+0x20, and the +0.5 on
       0x28($sp)), so the retail has one copy; this candidate keeps a separate
       local and copies it into the outgoing slot as well, which makes the
       frame 0x70 instead of 0x60 and the body 12 bytes longer;
     - the retail loads the compared float into $f1 and compares $f1 with $f20,
       this candidate reuses $f0;
     - the two calls inside the block set their arguments in the other order.

   Measured (tools/check.py func_L07_003F67B8 --diff, -O2 -G0 -frac2-qcopy):
     07_siberius: 320 bytes, expected 308.

   The retail's stack arguments of func_3E2710 are eight bytes apart
   (sp+0, sp+8, sp+0x10, sp+0x18), so that function is variadic; the float
   arguments are 1.0f and 20.0f in $f12/$f13.
*/

typedef int TI128 __attribute__((mode(TI)));

extern s32 func_312FA8(u8 *a, s32 b, s32 c);

extern f32 func_313008(u8 *a, s32 b);

extern void func_313DD8(void *a, f32 b, f32 c);

extern void func_30FED0(u8 *a, s32 b, s32 c);

extern void func_355488(s32 a, s32 b, u8 *c);

extern void func_3109C8(u8 *a, s32 b, s32 c);

extern void func_3E2710(u8 *a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, f32 i, f32 j, ...);

extern void func_310610(u8 *a, s32 b, s32 c);

void func_L07_003F67B8(u8 *a0)
{
    u8 *s0;
    u8 *s1;
    f32 v[4];
    f32 f0;
    f32 f20;
    u16 v1;

    s1 = a0;
    s0 = *(u8 **)(s1 + 0x68);
    f20 = 0.0f;
    f0 = func_313008(s1, func_312FA8(s1, 0x10000, 0));
    func_313DD8(s0 + 0x20, f20, f0);
    if (*(f32 *)(s0 + 0x20) <= f20) {
        func_30FED0(s1, 0, 3);
        func_355488(1, 0, s1);
        func_3109C8(s1, 1, -1);
        v1 = *(u16 *)(s1 + 0x34);
        *(u8 *)(s1 + 0xA8) = 0xFF;
        v1 |= 0x41;
        *(u32 *)(s1 + 0x98) = 0;
        v1 &= 0xEFFF;
        *(u16 *)(s1 + 0x34) = v1;
        *(TI128 *)v = *(TI128 *)(s1 + 0x10);
        v[2] = v[2] + 0.5f;
        func_3E2710(s1 + 0x10, 0, 0, 0, 0, 10, 20, 0, 1.0f, 20.0f, 1, 0, 0, 0, *(TI128 *)v);
        func_310610(s1, 2, 0);
    }
}
