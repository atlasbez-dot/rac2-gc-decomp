/* func_0027C540 - 288 bytes, 28 places (the boot and every level).
   Screened in wave 13 (worker g4): 0 call(s), 2 $gp-relative small-data access(es), 0 MMI lq/sq word(s), 5 64-bit daddu copy(ies), 0 float constant(s).
   the body writes 64-bit zeros (sd) and reaches two $gp-relative small-data words, so the unit needs -G8 and a declared size; five pointers are copied with daddu $d,$s,$zero, where this cc1 sign-extends with dsll/dsra.
   Not matched in wave 13 (worker g4): screening only; no C candidate was tested in this wave. */