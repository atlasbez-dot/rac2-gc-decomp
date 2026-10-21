/* func_0027DE50 - 448 bytes, 28 places (the boot and every level).
   Screened in wave 13 (worker g4): 0 call(s), 1 $gp-relative small-data access(es), 2 MMI lq/sq word(s), 0 64-bit daddu copy(ies), 0 float constant(s).
   the body carries the MMI sq words (0x7C), which a mode(TI) local reaches, but this cc1 folds the constant offset into the sq where retail materialises the pointer first; one of its words is $gp-relative small data.
   Not matched in wave 13 (worker g4): screening only; no C candidate was tested in this wave. */