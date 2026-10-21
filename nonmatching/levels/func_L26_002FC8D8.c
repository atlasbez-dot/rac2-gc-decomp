/* func_L26_002FC8D8 (384 bytes, 1 placement, level 26 jamming array): NOT ATTEMPTED.
   The body was read but no C was written for it: the wave's budget went to the four
   neighbouring functions, and this one is the largest of the five and needs a -G8 unit.
   What the retail bytes say, for whoever takes it next:

   The frame is 0xC0 and saves $s0..$s7 and $ra plus $f20; the prologue reads the mode
   word *(0x1A79F0) (the same word func_L26_004070F8 shifts by) and leaves the function
   at once unless the mode is 0x1A:

       lui $v1,0x1A ; lw $v1,0x79F0($v1) ; bne $v1,$v0,<end>   (with 0x1A materialised)

   The table at 0x1BC880 (0x1C0000-0x3780) is then walked. Its word at +0x30 is a kind:
   0 and 1 skip the walk, any other value takes the pointer at +0x194 (kept in $s2). The
   two tests are a `beqz` and a `bne` against 1, and a folded `beq $a1,$v0` with $a1 = 1
   and $v0 = -1 that never fires - a comparison of two constants the source could not
   fold, so the original had a variable in it.

   The walk itself uses the table entry at +0x18C (a pointer, read through the entry's
   index times four) and the entry's field at +0x50, which is set to 0x27E310; the
   second array is then at 0x27E330 and $s5 = the pointer at +0x10. A pointer read
   through $gp ($gp-0x5C10) is walked three times, so the unit must be built with -G8.

   The loop (three times, the counter in $s3) calls, in this order:
     - func_L02_002EF2B0 (the boot's func_002EF2B0) with the pointer at +0x58 of the
       walk's pointer, plus 0x10;
     - func_L02_002EF118 with the frame's own scratch (sp) and the same scratch;
     - a division of the float at +0x2C by the float at +0x24 of the pointer the word
       at +0x24 holds (div.s into $f20);
     - func_L02_002EE7D0 with the array at 0x27E330 and the $gp pointer;
     - func_L02_002EE398 with the array at 0x27E330 and the ratio in $f12;
     - func_L02_002EE328 with the array at 0x27E330 and the pointer at +0x10;
   the array advances by 0x10 and the $gp pointer by 0x10 each turn.

   After the walk the entry's +0x18C word is copied into the field at +0x68 of the table
   entry's +0x50 pointer, the table's word at +0x34 is compared with 0x597, and the
   entry's +0x50 field is cleared when it is (a branch-likely with the store in its
   delay slot).

   The declarations the body needs are the ones the other level-26 units use:
   D_L26_001A79F0 (the mode word), the table's own address (0x1BC880, a level address,
   so it needs a name), the words at 0x1BC8B0, 0x1BCA14, 0x1BC8B4 and the $gp pointer. */

#include "include_asm.h"
