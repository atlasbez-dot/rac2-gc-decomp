/* func_L00_003425F8 - 816 bytes, 27 places (every level), retail at 0x003425F8.
 *
 * Screened, not matched in wave 13 (worker s1): 26 call(s), no $gp-relative small-data
 * access, MMI words [lq $a1 / sq $a2] - a plain register as the base, so this body
 * is NOT blocked by the lq/sq offset folding that stops the rest of the family.  It is
 * the largest of the three survivors: 816 bytes, twenty-six calls, a loop over a table
 * and a 16-byte copy.  No C was written in this wave.
 */