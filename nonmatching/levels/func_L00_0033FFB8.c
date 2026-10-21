/* func_L00_0033FFB8 - 336 bytes, 27 places (every level), retail at 0x0033FFB8.
 *
 * Screened, not matched in wave 13 (worker s1): 7 call(s), no $gp-relative small-data
 * access, MMI words [lq $s3 / sq $v1, lq $s4 / sq $s0].  The first 16-byte copy
 * is retail's materialised-pointer form: the destination address is computed with
 * ddiu , , 0x10 and the MMI store uses that register with an offset of zero,
 * while the tested source forms folded a constant offset into the lq/sq pair.  Twenty spellings
 * were measured (see nonmatching/levels/func_L00_003411A0.c) and all of them fold the
 * offset.  No C was written in this wave.
 */