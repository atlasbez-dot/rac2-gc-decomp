/* func_L00_0042AC18 (380 bytes, 4 places) - the body holds an R5900 three-operand MULT
 * word, and the rest is a long float/table walk.
 *
 * Retail at 0x0042ac18 (level 00): at +0x58 the word 0x00A42818 is the R5900's
 * three-operand `mult rd,rs,rt` (SPECIAL, funct 0x18, with a non-zero rd field:
 * rd=$a1, rs=$a1, rt=$a0). This cc1 only emits the two-register `mult` (rd = 0)
 * followed by mfhi/mflo, so the word cannot be produced by plain C.
 *
 * The body reads as: the sub-object at +0x8 of the argument, its first word tested
 * against zero, a call to func_2EE2B0 on the block at +0x40, the compare of the float at
 * +0xC with the result, then a table walk (the entry index multiplied by 0x20 into the
 * table at 0x001B19EC, the byte at +0x18 of the entry, the flag at +0x74 of the owner
 * record and the pointer at +0x8C), the call to func_2EDD48, then func_35F640 with a
 * 0x400 flag, the difference of the two words of the sub-object scaled by 60.0f and
 * written back as a float, and finally the same table walk again to reach func_35F0A8.
 */
