/* func_L02_003D2390 (244 bytes, 1 place) - two MMI words, ASM_FUNC candidate unless they
 * turn out to be lq/sq.
 *
 * Classified by pattern, not decoded this wave: two `.word # INVALID` entries, no
 * max.s/min.s class word, seven calls - the busiest of the three L02 rows in this tour.
 * Same note as func_L02_003CD668: check whether the INVALID words are lq/sq (reachable
 * through mode(TI) in principle) or the real 0x7000_xxxx MMI family before working it.
 */
