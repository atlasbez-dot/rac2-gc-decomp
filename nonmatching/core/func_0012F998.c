/* Not a function: two linker remnants.
   0x0012F998  addiu $sp,$sp,0x10   a stripped function's return delay slot
   0x0012F99C  nop
   0x0012F9A0  sw    $a2,0x98($v0)   another stripped function's last word
   0x0012F9A4  nop
   The row has no `jr $ra` - it falls through into func_0012F9A8 - and it
   reads $v0, which it never sets. Nothing reaches it either: no branch or
   jump lands on one of the four words and no word of code or data holds one
   of their addresses. Going back over the leftovers there is func_0012F948's
   `jr $ra` and its delay slot, so both runs are what retail's linker left
   of the functions it stripped. rac1-decomp keeps the same bytes (0x0012BB78,
   this image's +0x3E20 core shift) as a linker remnant and has no C for them
   either. Nothing to compile: the catalogue splits the remnants out, and a
   tools/levels.py fix is what unblocks the row. */
