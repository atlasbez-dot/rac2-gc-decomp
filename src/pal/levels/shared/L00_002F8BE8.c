#include "include_asm.h"

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_002F8BE8);

extern int r1_func_0011CC38();

/* rac1-decomp src/core/00119D88.c: func_0011CCB0 */
/* Returns its callee's value: retail keeps the frame and calls, and
   2.9-ee would tail-call it (a bare `j`) if it were void. */
int func_PAL_L00_002F8C60(void) {
    return r1_func_0011CC38();
}

