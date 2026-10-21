/* No attempt: the row starts with linker remnants. 64 bytes at 0x1333C0 begin
   with two dead-stripped functions' epilogue fragments, `addiu $sp,$sp,0xE0` /
   nop twice (16 bytes).  A positive `addiu $sp,$sp,X` is an epilogue, never a
   prologue, so no body can start at 0x1333C0.  The 48-byte body is at 0x1333D0
   and ends at 0x133400, and the next row (func_00133400) starts at 0x133400.
   A tools/levels.py split that starts the row at 0x1333D0 is what unblocks it. */
