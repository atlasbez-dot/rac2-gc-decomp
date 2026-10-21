/* Catalogue residue candidate: func_00289018, 4 bytes, boot only.
 * The extent is a store through $v0 at 0x00289018. The preceding function
 * returns at 0x0028900C, followed by its delay slot and a nop. The next
 * function starts at 0x00289020. No direct control-flow target or aligned
 * literal pointer into this extent was found in the boot's loaded sections.
 * This supports a residual fragment, not an independent C function. The scan
 * does not rule out computed indirect targets. Keep the catalogue unchanged
 * until a separate generator correction verifies the boundary and original bytes.
 * No C candidate or ASM_FUNC credit is claimed.
 */
