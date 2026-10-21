/* No attempt: the row starts with linker remnants. 128 bytes at 0x133340 begin
   with two dead-stripped functions' epilogue fragments, `addiu $sp,$sp,0x10` /
   nop and `addiu $sp,$sp,0x30` / nop (16 bytes).  A positive
   `addiu $sp,$sp,X` is an epilogue, never a prologue, so no body can start at
   0x133340.  The 112-byte body is at 0x133350 and ends at 0x1333C0, and the
   next row (func_001333C0) starts at 0x1333C0.  A tools/levels.py split that
   starts the row at 0x133350 is what unblocks it. */
