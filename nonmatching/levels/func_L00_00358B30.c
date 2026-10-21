/* func_L00_00358B30 - 544 bytes, 27 places (every level), retail at 0x00358B30.
 *
 * Screened, not matched in wave 13 (worker s1): 9 call(s), 1 `$gp`-relative small-data
 * access (`swc1 $f3, 0x29A0($gp)`), MMI words [lq `$v1` / sq `$a0`, lq `$v1` / sq `$a1`].
 * Two obstacles: the 16-byte copies are retail's materialised-pointer form (this cc1
 * always folds a constant offset into the lq/sq pair) and the `$gp` access needs a
 * `-G8` unit, so the body belongs in a `L00_00358B30-g8.c` file.  No C was written in
 * this wave.
 */
