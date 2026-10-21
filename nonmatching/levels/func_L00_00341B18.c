/* func_L00_00341B18 - 492 bytes, 27 places (every level), retail at 0x00341B18.
 *
 * Screened, not matched in wave 13 (worker s1): 6 call(s), no $gp-relative small-data
 * access, MMI words [lq $s3 / sq $s1, lq $s3 / sq $s2, lq $s4 / sq $s2] - all
 * of them take a plain register as their base, so this body is NOT blocked by the
 * lq/sq offset folding that stops the rest of the family.  It is the smallest of the
 * three survivors and the next tier's first candidate: 492 bytes, six calls
 * (func_00282CF0, func_00282F70, func_00282DB0 and three func_00282E80), a float
 * comparison loop over two elements and three 16-byte copies.  No C was written in
 * this wave.
 */