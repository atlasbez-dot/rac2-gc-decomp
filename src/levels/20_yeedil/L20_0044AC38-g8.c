#include "include_asm.h"

/* This unit is built with -G8: the body reaches a global through $gp. */

INCLUDE_ASM("asm/levels", func_L20_0044AC38);

/* func_L20_0044AC38 is a near miss: nonmatching/levels/func_L20_0044AC38.c
   (the attempt is exact in size and 86 of the retail's 135 instructions
   match; the three walls left are the 128-bit copy address, the
   branch-likely of the loop and the order of the saved registers). */
