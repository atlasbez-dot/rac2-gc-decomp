/* Not a C row (wave 13, worker g3): the catalogue splits a piece of its neighbour.

   The 148 bytes at 0x0037CAE8 (level 00) are a chain of frame adjustments

     addiu $sp, $sp, 0x100 ; nop ; addiu $sp, $sp, 0x60 ; nop ; ...
     sw $zero, 0x10($v0) ; nop ; ...

   with no `jr $ra` anywhere in the row, and the one store it does carry reads $v0,
   a register the row never sets. The neighbouring functions end with their own
   `jr $ra`, so the row is a piece of a function the catalogue cut in the wrong place.

   A follow-up audit covered all 23 placements (boot and 22 levels). Each has a
   preceding return, with no direct control-flow target or aligned literal pointer
   into the extent in that program. This supports a residual catalogue extent;
   computed indirect targets are not ruled out. Retain it for a separately
   validated generator correction, without C or ASM_FUNC credit. */
