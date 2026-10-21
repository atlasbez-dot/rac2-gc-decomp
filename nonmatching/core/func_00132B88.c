/* No attempt: the row starts with linker remnants. 128 bytes at 0x132B88 begin
   with seven dead-stripped functions' epilogue fragments, each a pair of
   `addiu $sp,$sp,X` / nop with X = 0x20 six times and 0x30 once (56 bytes).
   A positive `addiu $sp,$sp,X` is an epilogue, never a prologue, so no body can
   start at 0x132B88.  The 72-byte body is at 0x132BC0 and ends at 0x132C08,
   and the next row (func_00132C48) starts at 0x132C48.  A tools/levels.py
   split that starts the row at 0x132BC0 is what unblocks it. */
