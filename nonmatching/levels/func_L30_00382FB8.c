/* No C yet: the body is decoded below so the next attempt can start from the structure
   rather than from the disassembly.

   The 284-byte extent at 0x00382FB8 (level 30) starts clean - `lw $a0,-0x438($gp)` - so
   the row is a real function and the only obstacle is the matching itself.

   It reads two of the level's small-data indices (D_001AEBB8 and D_001AEBBC, $gp =
   0x1AEFF0) and rewrites the 24x24 float table at 0x00233A60: for every cell it sums
   eight neighbours of the source row, scales the sum by 0.25f, subtracts the third
   neighbour and then subtracts a sixteenth of that, and stores the result into the
   destination row (D_001AEBC0). The strides are 0x900 bytes per row of 24 cells and
   0x60 bytes per cell.

   The sum is taken in the retail order - the cell and its two neighbours in the source
   row, then the cell and its two neighbours in the neighbour row:

       f0 = p[0] + q[0] + r[-2] + r[0] + p[-1] + p[1] + q[-1] + q[1]
       f0 = f0 * 0.25f - s;
       f0 = f0 - f0 * 0.0625f;

   The inner loop counts the eight summands with a3 (1..0x17) and the outer loop with
   t0 (2..0x17); both the four row addresses and the two 0x900 strides are computed
   with `mult` inside the loop, so the row pointers are not hoisted. A spelling that
   keeps the eight loads in the retail order is the open question.

   It needs the -g8 sibling of the level unit: D_001AEBB8 and D_001AEBBC are small
   data below the boot's $gp, so the unit is built with -G8 and the globals carry the
   sda attribute. */
