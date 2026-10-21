/* No attempt: the row starts with linker remnants. 84 bytes at 0x132AA0 begin
   with five dead-stripped functions' epilogue fragments, each a pair of
   `addiu $sp,$sp,X` / nop with X = 0x40, 0x40, 0x20, 0x30, 0x20 (40 bytes).
   A positive `addiu $sp,$sp,X` is an epilogue, never a prologue: a C body
   always allocates its frame with a negative one, so no body can start at
   0x132AA0.  The 44-byte body is at 0x132AC8 and ends at 0x132AF4, and the
   next row (func_00132AF8) starts at 0x132AF8.  A tools/levels.py split that
   starts the row at 0x132AC8 is what unblocks it. */
