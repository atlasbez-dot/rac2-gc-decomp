/* func_L00_0042A520 (376 bytes, 27 places) - the body holds a COP2 word, so it is not a
 * C row.
 *
 * Retail at 0x0042a520 (level 00): at +0xEC the word 0x700014A9 sits between two calls
 * (its opcode field is 0x1C, the R5900's COP2 group) and the neighbouring words are the
 * usual `daddu` argument moves. A COP2 word belongs to the vector unit and this cc1
 * never emits one, so plain C cannot reproduce the body whatever the source says.
 *
 * The rest of the body reads as: the table entry selected by the owner's index halfword
 * at +0x84 (through the pointer stored at 0x001B1844), four floats written into it from
 * the small-data constants at 0x2650/0x264C ($gp), a quadword copy out of the entry's
 * own 0xE0 block, three matrix helpers (func_2EE3D0, func_2EE108, func_2EE220) and the
 * owner block at +0x30 / +0x10, then func_2EE138 on the owner and the final word from
 * 0x265C($gp).
 */
