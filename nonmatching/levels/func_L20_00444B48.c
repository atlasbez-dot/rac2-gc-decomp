/* 0 of 1 places match - last line: 20_yeedil: 204 bytes, expected 208
   The whole ramp is recovered and every instruction is retail's. Two integer parameters
   feed the guards through inline `cvt.s.w` (`D_L20_001B20A0 <= (f32)a0` returns f12,
   `(f32)a1 <= D_L20_001B20A0` returns f13); the interpolated return calls the int-to-float
   helper func_00283CE0 three times - twice on a0, once on a1, in the order the inline
   denominator gives - and divides (D_L20_001B20A0 - h(a0)) by (h(a1) - h(a0)). Two
   residues: the `nop` retail keeps between the third `sub.s` and the `div.s` is absent, and
   one set-up is swapped at +0x8C (retail saves `$s1 = $a1` in the bc1f delay slot with
   `mov.s $f23,$f13` four words earlier; this cc1 the other way round). Named numerator and
   denominator locals give 200 bytes and a different schedule; spelling the three helpers as
   `(f32)` casts lets this cc1 fold them into the guards (104 bytes). */
#include "common.h"

extern f32 D_L20_001B20A0 __attribute__((sda));

extern f32 func_00283CE0(s32);

/* The zero-crossing ramp between two integer positions: f12 at or below D_L20_001B20A0,
   f13 at or above it, and the linear blend of the two in between. */
f32 func_L20_00444B48(s32 a0, s32 a1, f32 f12, f32 f13)
{
    if (D_L20_001B20A0 <= (f32)a0)
        return f12;
    if ((f32)a1 <= D_L20_001B20A0)
        return f13;
    return f12 + (f13 - f12) *
                      ((D_L20_001B20A0 - func_00283CE0(a0)) /
                       (func_00283CE0(a1) - func_00283CE0(a0)));
}
