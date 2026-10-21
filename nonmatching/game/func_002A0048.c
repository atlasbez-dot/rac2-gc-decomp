/* func_002A0048 - 308 bytes, 28 places (the boot and every level).
   Screened in wave 13 (worker g4): 2 call(s), 0 $gp-relative small-data access(es), 0 MMI lq/sq word(s), 1 64-bit daddu copy(ies), 0 float constant(s).
   a pointer is copied with daddu $d,$s,$zero, where this cc1 sign-extends with dsll/dsra; the packet writes have to reload the pointer for every word, as retail does.
   Not matched in wave 13 (worker g4): screening only; no C candidate was tested in this wave. */