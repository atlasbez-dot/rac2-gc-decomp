/* func_L00_00341820 - 616 bytes, 24 places, retail at 0x00341820.
 *
 * Screened, not matched in wave 13 (worker s1): 3 call(s), no $gp-relative small-data
 * access, MMI words [lq $v1 / sq $s1, lq $v1 / sq $s1].  Both 16-byte copies
 * take retail's materialised-pointer form (the source address is computed into $v1
 * and the MMI load uses it with an offset of zero) and this cc1 always folds a
 * constant offset into the lq/sq pair.  Twenty spellings were measured and all of
 * them fold it.  No C was written in this wave.
 */