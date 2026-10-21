/* func_0029EFD0 - 248 bytes, 28 places (the boot and every level).
   Screened in wave 13 (worker g4): 3 call(s), 0 $gp-relative small-data access(es), 0 MMI lq/sq word(s), 8 64-bit daddu copy(ies), 0 float constant(s).
   the arguments are 64-bit pointers: retail copies them with daddu $d,$s,$zero and this cc1 sign-extends with dsll/dsra, and the two branch-likely tests have to be produced with their delay slots filled as retail fills them.
   Not matched in wave 13 (worker g4): screening only; no C candidate was tested in this wave. */