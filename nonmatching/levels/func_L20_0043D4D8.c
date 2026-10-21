/* Not matched (worker 07, level-20 wave of 2026-10-21): the 128-bit copy wall.
 *
 * THE WALL.  This body has FOUR 128-bit accesses and every one of them is
 * MATERIALISED into a register with a ZERO displacement:
 *
 *      0043D4EC  addiu $v1, $s2, 0x10
 *      0043D504  lq    $v0, 0x0($v1)
 *      0043D508  sq    $v0, 0x0($sp)        ; a stack slot at offset 0
 *      0043D50C  addiu $a0, $sp, 0x10
 *      0043D510  addiu $v1, $s2, 0xF0
 *      0043D514  lq    $v0, 0x0($v1)
 *      0043D518  sq    $v0, 0x0($a0)       ; a stack slot at +0x10
 *      ...
 *      0043D7CC  addiu $s4, $s2, 0xF0
 *      0043D820  lq    $v0, 0x0($s4)
 *      0043D824  sq    $v0, 0x0($v1)
 *
 * Plain C folds every one of them (the front end builds the address as
 * plus(reg,const) and the RELOAD accepts that for TImode while the offset is
 * inside [-32768, 32751]), so the copies come out as
 * `lq $v0,0x10($s2) ; sq $v0,0x0($sp)`, `lq $v0,0xF0($s2) ; sq $v0,0x10($sp)`
 * and so on.  The escapes do not apply: the bases are runtime pointers (not
 * plain pointers, not symbols) and the stack slots are at offsets 0x10 and
 * above (the stack-slot escape only gives a zero displacement for a slot at
 * offset 0).  This is the compiler-side wall of wave 4, not a source shape.
 *
 * THE STRUCTURE (for whoever picks it up after the wall is solved).
 *   - the frame is 0x80 with $s1..$s5 and $ra saved; $s2 = the argument,
 *     $s1 = the object (arg0 + 0x68);
 *   - the two copies at the top load the argument's 16-byte blocks at +0x10
 *     and +0xF0 into two stack buffers (at sp+0 and sp+0x10);
 *   - the body calls func_0029EFD0, func_002B37E8, func_002B3868,
 *     func_002A0F48, func_00282948, func_00282CC0, func_00282CF0,
 *     func_00282D30, func_00283B98, func_0029F338, func_002A7750,
 *     func_L20_0043D470, func_002E59F8, func_002E5CF8, func_002AD6F0,
 *     func_L00_00324120, func_L01_003208D0, func_L00_002D70A0 and
 *     func_L00_002D7140;
 *   - the copy at 0x0043D820 is the third 128-bit access.
 *
 * This body belongs in the `-G8` unit?  No: it reaches no global through
 * `$gp`.
 */
