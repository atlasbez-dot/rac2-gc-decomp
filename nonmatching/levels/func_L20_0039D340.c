/* Not matched (worker 07, level-20 wave of 2026-10-21): the 128-bit copy wall,
 * and this body needs the -G8 profile.
 *
 * TWO FINDINGS.
 *
 * 1. THIS BODY REACHES FOUR FLOATS THROUGH $gp:
 *
 *      0039D3C8  lwc1 $f1, -0x300($gp)
 *      0039D3CC  lwc1 $f2, -0x2F4($gp)
 *      0039D3D0  lwc1 $f3, -0x2F8($gp)
 *      0039D3D4  lwc1 $f12, -0x2FC($gp)
 *
 *    so it belongs in a -G8 unit of its own (a sibling file named
 *    L20_0039D340-g8.c, which gets -G8 from its name).  It is the only
 *    function of this wave that needs it.  In a -G0 unit the four floats
 *    come out as absolute loads and the body cannot match.
 *
 * 2. THE 128-BIT COPY WALL.  The retail's only copy is
 *
 *      0039D610  addiu $a0, $v1, 0x10      ; the source, object + 0x10
 *      0039D618  addiu $v1, $s1, 0x1F0     ; the destination, state + 0x1F0
 *      0039D61C  lq    $v0, 0x0($a0)
 *      0039D620  sq    $v0, 0x0($v1)
 *
 *    - the address is MATERIALISED into a register and the lq/sq use a ZERO
 *    displacement (the shape the corrected rule of wave 5 describes).  Both
 *    addresses are `base + constant` with a runtime base, so plain C folds
 *    them into the displacement (`lq $v0,0x10($v1) ; sq $v0,0x1F0($s1)`) and
 *    the escape does not apply: the base is not a plain pointer, not a
 *    symbol and not a stack slot at offset 0, and the offsets are inside the
 *    TImode displacement range [-32768, 32751] and inside the addiu immediate
 *    range.
 *
 * THE STRUCTURE (for whoever picks it up after the wall is solved).
 *   - the frame is 0x30 with $s0..$s3 and $ra saved;
 *   - $s2 = the argument, $s1 = the object (arg0 + 0x68);
 *   - the first block reads the byte at object+0x20 and, if it is zero, writes
 *     a block of constants into the state (offsets 0x150..0x1B6), multiplies
 *     four $gp floats by four constants and stores thirteen floats into the
 *     state, then calls func_002B60B0 (f_00341B10) with four arguments;
 *   - then it calls func_L20_00330A68, func_002A7750, func_002A7470,
 *     func_002A9640, func_002B0ED8, func_0029F338 and func_002B3BA8;
 *   - the two-element loop at 0x0039D5C8 frees the two objects at state+0x258
 *     and state+0x25C and then frees state+0x254;
 *   - the copy at 0x0039D61C is the only 128-bit access.
 *
 * This body belongs in the `-G8` unit?  YES - see above.
 */
