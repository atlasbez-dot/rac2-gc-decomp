/* Not a C row (wave 13, worker g3): the catalogue splits a piece of its neighbour.

   The three instructions at 0x002FED78 are

     002FED78  addiu $v0, $zero, -1
     002FED7C  nop
     002FED80  addiu $sp, $sp, 0x40

   and they are followed by the padding up to 0x002FED90, where func_002FED90 starts.
   The previous function returns at 0x002FED68, with `addiu $sp,$sp,0x10`
   in the delay slot at 0x002FED6C; two nops follow.

   A boot-wide scan found no direct control-flow target or aligned literal pointer
   into this extent. Together with the preceding completed return and unmatched
   frame restore, this supports a residual catalogue extent. Absence of jr $ra
   alone is insufficient, and computed indirect targets are not ruled out. Retain
   this for a separately validated generator correction; no C or ASM_FUNC credit. */
