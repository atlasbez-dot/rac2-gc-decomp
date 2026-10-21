/* func_0027E920 - 260 bytes, 28 places (the boot and every level).
   Screened in wave 13 (worker g4): 0 call(s), 2 $gp-relative small-data access(es), 1 MMI lq/sq word(s), 0 64-bit daddu copy(ies), 0 float constant(s).
   the body carries the MMI sq word 0x7C620000, which a mode(TI) local reaches, but this cc1 folds the constant offset into the sq where retail materialises the pointer first; two of its words are $gp-relative small data, so the unit needs -G8.
   Not matched in wave 13 (worker g4): screening only; no C candidate was tested in this wave. */