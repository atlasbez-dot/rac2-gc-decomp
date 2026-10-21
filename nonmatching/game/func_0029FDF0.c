/* func_0029FDF0 - 240 bytes, 28 places (the boot and every level).
   Screened in wave 13 (worker g4): 2 call(s), 1 $gp-relative small-data access(es), 0 MMI lq/sq word(s), 1 64-bit daddu copy(ies), 0 float constant(s).
   one of its words is a $gp-relative small-data load, so the unit needs -G8 and a declared size; a pointer is copied with daddu $d,$s,$zero, where this cc1 sign-extends with dsll/dsra.
   Not matched in wave 13 (worker g4): screening only; no C candidate was tested in this wave. */