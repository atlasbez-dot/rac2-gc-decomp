/* func_0029FB20 - 256 bytes, 28 places (the boot and every level).
   Screened in wave 13 (worker g4): 1 call(s), 0 $gp-relative small-data access(es), 0 MMI lq/sq word(s), 0 64-bit daddu copy(ies), 0 float constant(s).
   a loop of sixteen entries whose body is a nest of branch-likely tests (beql/bnel) whose delay slots carry the consumer of the loaded word; the float constant (1.0f in $f20) and the loop counters have to land in the same registers as retail.
   Not matched in wave 13 (worker g4): screening only; no C candidate was tested in this wave. */