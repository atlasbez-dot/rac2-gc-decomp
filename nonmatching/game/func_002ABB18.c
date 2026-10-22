#include "include_asm.h"

/* The retail body is a wrap of an angle into [-pi, pi): it takes the fraction of
   (x + pi) / (2 pi), scales it back and subtracts pi.  The constant 1 / (2 pi) is
   0x3E22F983, pi is 0x40490FDB and 2 pi is 0x40C90FDB; the first multiply sits in
   the delay slot of the call.

   Everything matches except the register of the second multiply's result: the retail
   keeps it in $f12 (`mul.s $f12,$f0,$f1` then `sub.s $f0,$f12,$f20`) and this cc1
   reuses the call's result register (`mul.s $f0,$f0,$f1` then `sub.s $f0,$f0,$f20`).
   The difference is the reload allocator's choice for the output of the multiply,
   which the source shapes tried here (a named temporary, a comma expression, the
   operands swapped, the product used twice) do not change.  What is needed is a
   source whose multiply result is not the dying input of the multiply. */
extern float func_00283CC8(float x, float *out);

float func_002ABB18(float x)
{
    float whole;
    float frac = func_00283CC8((x + 3.1415927f) * 0.15915494f, &whole);
    return frac * 6.2831855f - 3.1415927f;
}
