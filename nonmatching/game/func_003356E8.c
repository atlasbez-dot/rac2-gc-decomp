/* No attempt: the retail bytes are not code.  The 172-byte extent of
   func_003356E8 is a run of `addiu $sp,$sp,N` with a `nop` after each one (0x90, 0x20, 0x20, 0xA0, 0x20, 0x10, 0x40, 0x80, 0x10) and two stores (`sw $zero,0xC($v1)`, `sw $zero,0x0($v0)`, `sb $zero,0x39($v0)`)
   - no prologue, no body and no `jr $ra`.  It is the filler between two
   functions, not a function: no C can be placed there.  The same shape as
   func_L00_00341798 and func_L00_002E6440. */
