/* func_L01_002E2608 - 388 bytes, 4 place(s) (levels 01_oozla, 02_maktar_nebula,
   09_dobbo, 11_joba), retail at 0x002E2608 in level 01.  Screened and decoded, not
   matched in this wave.

   Calls: func_00281DE8@002E262C (the level's 0x002E1468), with the frame pointer as
   its first argument (`daddu $a0,$sp,$zero`), the second and third arguments of the
   function unchanged and 128 as its fourth.
   Float constants: 0x3F800000 (1.0).
   Data addresses: none.  $gp-relative small data: no.
   Saves: $s0, $s1, $s2, $ra.  Callee-saved registers saved [$s0, $s1, $s2].  Frame 0xD0.
   Words plain C cannot emit: none, but the copy of the eight floats is a pair of
   4-iteration loops over two float2 columns.

   The body, decoded:
     - the call above, then twelve words are written at sp+0x40: the fourth argument
       four times (as an int), then 0, 0, 0, then 1.0f, 1.0f, then 0 (as an int),
       then 1.0f, 1.0f - that is four rows of two floats, (0,0), (0,1), (1,0), (1,1);
     - the first loop copies those eight floats (as four float2's) from sp+0x50 to
       sp+0x90, four iterations, the counter running down from 3;
     - the second loop writes them back rotated: row k of sp+0x50 takes row (k + the
       fifth argument) % 4 of sp+0x90, the index computed with the retail's
       modulo-four pattern (`addiu $a1,$s1,0x3 ; slt $a0,$t1,$v1 ; movn $v0,$v1,$a0 ;
       sra $v0,$v0,2 ; sll $v0,$v0,2 ; subu $v1,$v1,$v0 ; sll $v1,$v1,3`), that is
       x % 4 for a possibly negative x;
     - the fifth argument is the one the caller pushes on the stack (`daddu $s1,$t0,
       $zero`).

   Not matched in this wave: the frame pointer is passed as the first argument of
   the call, which no plain C spells (the local it belongs to has to be at the frame's
   offset 0, and the source of the function's 0x40 bytes of unused frame is not
   known), and the two loops have to come out of the same expression to keep the
   induction variables and the modulo pattern.  What would unblock it: the source of
   the call's first argument and the type of the twelve-word block at sp+0x40 (four
   ints, then eight floats, in one array or in a struct).
 */
