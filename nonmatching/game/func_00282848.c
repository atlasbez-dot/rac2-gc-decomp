/* func_00282848, 72 bytes, 28 placements (all the levels).
   Not a C row: catalogue defect.  The extent at 0x002EDC48 in level 00 (and
   at the matching address in the other levels) is six `addiu $sp,$sp,N` pairs
   with nops - 0x40, 0x40, 0x30, (two nops), 0x10, 0x50, 0x60 - followed by a
   complete sixteen-byte function:

     lwc1   $f0, -0x76E4($gp)
     nop
     jr     $ra
     mul.s  $f0, $f0, $f12

   The six stack adjustments have no prologue before them and no `jr $ra`
   after them; they are the tail of a neighbour's frame (the same shape as
   func_00281E88), and the neighbour func_002824B8 ends with its own
   `jr $ra` and a single `addiu $sp,$sp,0x80` in the delay slot, so the six
   adjustments belong to neither of them.  No C can be placed on them: one C
   function cannot be six `addiu $sp,$sp,N`.  A `tools/levels.py` split (the
   row starts 52 bytes late) is what unblocks the sixteen-byte function, which
   is the same shape as func_L00_002EDCB8, func_L00_002EDCF0 and
   func_L00_002EDD38 next to it. */

#include "include_asm.h"
