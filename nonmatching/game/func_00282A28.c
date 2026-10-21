/* func_00282A28 - 16 bytes, 28 places (the boot and every level), retail at
   0x00282A28: teq $zero,$zero,0 ; nop ; jr $ra ; nop.
   the body starts with a trap (teq $zero,$zero,0), which no C emits.  Not matched in wave 12 (worker g1): no C source reproduces the body.
   What would unblock it: a source with a deliberate trap, which the compiler spells `break`. */
