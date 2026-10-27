/* Retained near miss (M4, 26 October 2026); not linked.
 * Unit: src/levels/shared/L00_003B3C40-g8-dbg.c, profile -O2 -G8 -ffunction-sections -frac2-zero-ti-por -g.
 * 568/568 bytes, 0/27 places. Closed here: the division as its own statement (retail's -g nops
 * before div.s), func_002BDCE8's real prototype (pointer, four floats, int, pointer, int, int) and
 * a block-scoped pointer for the first particle's state. Left (order only, about 5 words): the
 * $a1/$a2 moves for func_00282CC0(&position, object + 0x10, &direction) in the second block, and
 * the %hi of D_L00_001A8F20 scheduled early before the second particle call. Queued for the permuter.
 */
