/* Not matched (worker 07, level-20 wave of 2026-10-21): the 128-bit copy wall.
 *
 * THE WALL.  The frame is 0x2A0 and the body holds six 128-bit buffers on the
 * stack.  Every one of the copies is MATERIALISED into a register with a
 * ZERO displacement, for instance
 *
 *      003E69AC  lq    $v0, 0x0($s6)       ; $s6 = sp + 0x20
 *      003E69B0  sq    $v0, 0x0($sp)       ; a stack slot at offset 0
 *      003E69B4  addiu $v1, $sp, 0x10
 *      003E69B8  lq    $v0, 0x0($s3)
 *      003E69BC  sq    $v0, 0x0($v1)       ; a stack slot at +0x10
 *      ...
 *      003E6ABC  lq    $v0, 0x0($s3)
 *      003E6AC0  sq    $v0, 0x0($v1)
 *      ...
 *      003E6B50  lq    $v0, 0x0($s7)
 *      003E6B54  sq    $v0, 0x0($v1)
 *      ...
 *      003E6C58  lq    $v0, 0x0($s3)
 *      003E6C5C  sq    $v0, 0x0($s7)
 *
 * Plain C folds them all into the displacement (`sq $v0,0x10($sp)` and so
 * on); the stack-slot escape only gives the zero displacement for a slot at
 * offset 0, and every slot here is at 0x10 or above.  The bases are stack
 * pointers with a constant offset - `base + const` with a runtime base - so
 * the corrected rule of wave 5 applies and plain C cannot produce the
 * retail's shape.
 *
 * THE STRUCTURE (for whoever picks it up after the wall is solved).
 *   - the frame is 0x2A0; the six 16-byte buffers are at sp+0x00, sp+0x10,
 *     sp+0x20, sp+0x30, sp+0x120, sp+0x140, sp+0x150, sp+0x180, sp+0x190,
 *     sp+0x1A0, sp+0x1B0, sp+0x1C0 and sp+0x1D0;
 *   - the body calls func_00280B90, func_00281DE8, func_00282CC0,
 *     func_00282CF0, func_00282D30, func_00282DD8, func_00282DF0,
 *     func_00282F20, func_00283CE0, func_00283D38 and func_002FC560;
 *   - the six `lq`/`sq` pairs above are the only 128-bit accesses.
 *
 * This body belongs in the `-G8` unit?  No: it reaches no global through
 * `$gp`.
 */
