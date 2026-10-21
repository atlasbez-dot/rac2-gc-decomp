/* MMI (SPECIAL2) instruction: no C spelling. 104 bytes, level 04 (1 place).
   Retail at 0x00422D40 carries the SPECIAL2 word 0x700024A9 at +0x14 - opcode 0x1C, which
   rabbitizer prints as `INVALID`; it is the same family the near miss of func_L00_003A8E28
   documents (words 0x700014A9 / 0x700024A9, opcode 0x1C with the MMI funct field), one of the
   packed helpers the lot rows func_L00_00428000, func_L05_003D0538 and func_L00_0040B2C0 share.
   The body builds four float constants (0x479C4000, 0xC788B800, 0x4808B800, 0x3F800000), spills
   them into a 16-byte stack slot with swc1 and then feeds the packed word and the slot to the
   MMI op. ASM_FUNC candidate, as for the rest of the family. */

/* Later worker (wave 24): the same wall, confirmed with tools/check.py.  The candidate below
   reproduces the four float constants, the pointer at +0x68, the `addiu $v1,$v1,0x30`, the store
   of 0 to the global 0x1B9984 and the four swc1s, but the 128-bit move comes out as the
   ldl/ldr/sdl/sdr pairs instead of retail's lq/sq (a 16-byte struct of four floats is copied
   that way; only a TI16 cast reaches lq/sq, and its float fields are then written through the
   two 64-bit words instead of with swc1).  The word at +0x14 is the SPECIAL2 one the note above
   names: 0x700024A9, which rabbitizer prints as INVALID.  The zero store is a second wall: this
   project's own pass rac2_fold_zero_ti_store folds retail's `por $a0,$zero,$zero` +
   `sq $a0,0($sp)` back to `sq $zero` whenever the materialised register is dead after the
   store.  check.py func_L04_00422D40: "04_barlow: 148 bytes, expected 104". */
