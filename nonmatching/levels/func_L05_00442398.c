/* func_L05_00442398 (288 bytes, 4 places) -- NEAR MISS, not integrated.
   No C was reached inside the budget of this attempt; what follows is the
   structure read off the retail bytes and the measured facts about it, so that
   the next attempt starts from facts and not from the disassembly.

   The body (level 05, address 0x442398):
     - frame 0x50, saves $s0/$ra.
     - it starts with a guard: the word in the small data area at 0x1B1B20 is
       compared with 6 and, when it is 6, the body jumps straight to the tail.
     - the halfword at +0x84 of the object is shifted left by five and added to
       D_001B1EC4; the entry at +0x1C of that is used, the word at +0x20 of it
       is shifted left by eight and added to D_001B251C, and the entry at +0x68
       of that is called with +0x10 (func_3D1E60).
     - the two words at 0x1B1F60 and 0x1B1F64 are zeroed.
     - the quadword at +0x30 of the object is copied to 0x1B3620.
     - the word D_001A79F0 selects the scale: 20 gives 2.0f, anything else 1.0f,
       and that float is the argument of func_L05_004424B8 (a level function, so
       it needs a ref_ name) together with the object.
     - the word in the small data area at 0x1B1ADC is copied to 0x1B1B34.
     - the three quadwords at +0x00, +0x10 and +0x20 of the object are copied
       to the stack at +0x00, +0x10 and +0x20, the fourth quadword (at +0x30 of
       the stack) is zeroed, and the float 1.0f is written at +0x3C of the
       stack while 0.0f goes to +0x0C, +0x1C and +0x2C; the stack is then handed
       to func_336A90 with 0x1B3610.

   Measured facts:
   - the small data area is used (0x1B1B20, 0x1B1F60, 0x1B1F64, 0x1B1ADC), so
     the unit has to be built with -G8 (a -g8.c sibling); at -G0 these are
     addressed with lui/addiu.
   - the four quadword copies are a grouped R5900 copy: both addresses are in
     registers (`lq $v0,0x0($s0); sq $v0,0x0($v1)`), which is the
     -frac2-qcopy pattern; without it this cc1 folds the offsets into the lq.
   - the level data addresses differ from level to level, and so do the small data
     offsets, so the names have to be D_L05_ for the canonical level and the
     other levels' values come from the retail bytes.
   - the small data offsets per level: the guard word is at $gp+0x2B30 in levels
     05 and 10, at $gp+0x2C00 in level 15 and at $gp+0x2680 in level 25; the word
     copied into it is at $gp+0x2AEC, $gp+0x2BBC and $gp+0x263C, and its
     destination at $gp+0x2B34, $gp+0x2C04 and $gp+0x2684.
   - the callees' catalogue names, read off config/levels/functions.tsv:
     func_3D1E60 is func_L05_003D1E60, func_4424B8 is func_L05_004424B8 and
     func_336A90 is func_002AB6D8.  The first two are level functions with one
     place per level, so their address differs from level to level; the third is
     a boot function.
   - the absolute addresses move as well: level 05 has 0x1B1EC4, 0x1B251C,
     0x1B1F60, 0x1B1F64, 0x1B3620 and 0x1B3610, level 10 has 0x1B1EC4,
     0x1B251C, 0x1B1F60, 0x1B1F64, 0x1B3600 and 0x1B35F0, level 15 has
     0x1B1FC4, 0x1B261C, 0x1B2060, 0x1B2064, 0x1B3720 and 0x1B3710.

   What is left: the source of the four stack words and their order, the guard
     on 0x1B1B20, and the two level functions the body calls. */
