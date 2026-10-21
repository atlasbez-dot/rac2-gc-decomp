/* Not a C row (wave 13, worker g3): the catalogue splits a piece of its neighbour.

   The nine instructions at 0x002FF0B0 are

     002FF0B0  addiu $sp, $sp, 0x20
     002FF0B4  nop
     002FF0B8  addiu $sp, $sp, 0x10
     002FF0BC  nop
     002FF0C0  sw    $v0, -0x3FBC($gp)
     002FF0C4  nop
     002FF0C8  addiu $sp, $sp, 0x10
     002FF0CC  nop
     002FF0D0  addiu $sp, $sp, 0x10

   The previous function ends at 0x002FF0AC (`jr $ra` at 0x002FF0A4, the
   `addiu $sp,$sp,0xB0` in its delay slot) and func_002FF0D8 starts at 0x002FF0D8.

   A boot-wide scan found no direct control-flow target or aligned literal pointer
   into this extent. Its preceding completed return and unmatched frame restores
   support a residual catalogue extent. The scan does not rule out computed
   indirect targets. Retain this for a separately validated generator correction;
   no C or ASM_FUNC credit is claimed. */
