/* func_L00_00340560 - 388 bytes, 27 places (every level), retail at 0x00340560.
 *
 * Screened, not matched in wave 13 (worker s1): 8 call(s), no $gp-relative small-data
 * access, MMI words [lq $s0 / sq $v1].  The 16-byte copy is retail's
 * materialised-pointer form (ddiu , , 0x10 in the delay slot of the beqz, then
 * sq , 0()) and the tested source forms folded a constant offset into the lq/sq pair.
 * Twenty spellings were measured and all of them fold it.  No C was written in this wave.
 */