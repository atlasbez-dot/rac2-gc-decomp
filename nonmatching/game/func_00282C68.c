/* func_00282C68 - 16 bytes, 28 places (the boot and every level), retail at
   0x00282C68: 0x460D6028 ; nop ; jr $ra ; 0x460E0029.
   the two words are COP1 words of the single-precision group with funct 0x28 and 0x29: rabbitizer cannot name them and this cc1 never emits them.  Not matched in wave 12 (worker g1): no C source reproduces the body.
   What would unblock it: a source that makes cc1 emit those two COP1 words. */
