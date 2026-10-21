#include "include_asm.h"

/* The retail body scales a float by a power of ten and divides by it again: the
   exponent is counted in a loop (`mult $v0,$v0,$v1`, the R5900's three-operand
   multiply), the scale is converted with `mtc1`/`cvt.s.w`, and the argument of
   func_00283CF0 is (x + 1 / (2 * scale)) * scale.

   The loop, the frame, the conversion and the call all match; what differs is the
   floating point register allocation of the three temporaries: the retail keeps the
   incoming argument in $f12, puts the constant 1.0 in $f0 and the sum scale+scale
   in $f1, while this cc1 copies the argument into $f1 and puts the constant in
   $f12.  The source shapes tried here (the division inline or through a temporary,
   the operands of the sum swapped, 2.0f * scale instead of scale + scale) do not
   change it. */
extern int func_00283CF0_5(float x);

float func_002AEAE0(int a0, float x)
{
    int r = 1;
    float scale;
    int n;

    if (a0 > 0) {
        do {
            r *= 10;
        } while (--a0 != 0);
    }
    scale = (float)r;
    n = func_00283CF0_5((x + 1.0f / (scale + scale)) * scale);
    return (float)n / scale;
}
