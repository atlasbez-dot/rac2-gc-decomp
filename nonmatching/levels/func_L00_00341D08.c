/* func_L00_00341D08 - 672 bytes, 27 places (every level), retail at 0x00341D08.
 *
 * Screened, not matched in wave 13 (worker s1): 16 call(s), no $gp-relative small-data
 * access, MMI words with plain register bases only ($s0, $s2, $s3, $s4, $s5
 * and $sp), so this body is NOT blocked by the lq/sq offset folding that stops the
 * rest of the family. It calls func_L00_00341B18 (still unmatched) and
 * func_L00_00341A88 (matched),
 * has a float comparison loop and eight 16-byte copies.  No C was written in this wave.
 */
