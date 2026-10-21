/* Not matchable yet: the extent begins on the linker's fill word.
   Bytes 0x125D94..0x125D97 are 0xCDCDCDCD (the fill between two objects); the
   function itself is the 188 bytes from 0x125D98 to 0x125E54. check.py
   requires the compiled section to be exactly the catalogue's 192 bytes and to
   equal those bytes, and no C starts with that word. This needs the same
   correction docs/LEVELS.md describes for three Aranos entries -- move the
   extent start to +4 -- in tools/levels.py; then the body (call func_00125D96,
   test the halfword at +6, and store eight 64-bit GS registers under either
   the 0x12000000..0x120000C0 or the 0x12000000/20/90/A0/E0 set) is ordinary C.
   The same correction applies to func_001290BC. */

Wave 24 (worker 01) confirms the catalogue defect.  The retail bytes at 0x00125D94
are CD CD CD CD (the linker's fill word) and the real body starts at 0x00125D98 with
`addiu $sp,$sp,-0x20` / `sd $s0,0($sp)` / `sd $ra,0x10($sp)` and ends with
`jr $ra` at 0x00125E4C (delay slot `addiu $sp,$sp,0x20` at 0x00125E50), so the
function is the 188 bytes from 0x00125D98 to 0x00125E54.  The catalogue row
`func_00125D94 boot 192 00125D94` therefore has both the start and the size wrong by
four bytes; tools/levels.py has to move the extent to +4.  No C can start with
0xCDCDCDCD, so this row cannot be matched until the catalogue is fixed.
