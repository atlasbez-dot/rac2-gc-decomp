/* Catalogue residue candidate: func_002A77C0, 28 bytes, boot only.
 * The extent contains floating-point arithmetic interleaved with nops. The
 * preceding function returns at 0x002A77AC, followed by its delay slot and
 * padding; the next function starts at 0x002A77E0. No direct control-flow
 * target or aligned literal pointer into the extent was found in the boot's
 * loaded sections. FPU nops or absence of jr $ra alone would not prove this.
 * Treat it as a residual-extent investigation, not handwritten-function credit.
 * The scan does not rule out computed indirect targets; a separate catalogue
 * correction must preserve the original bytes. No C candidate was attempted.
 */
