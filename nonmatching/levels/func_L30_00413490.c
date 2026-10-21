/* 0 of 1 places match (not attempted): the row holds two MMI words,
   `.word 0x78620000` at +0x2C and `.word 0x7C820000` at +0x30 (lq/sq family,
   rabbitizer reports INVALID), so this cc1 cannot emit it. The rest is ordinary C:
   spawn func_316A50(0x118A), copy the owner into the new object's 0xB8, clear its
   0x30 byte, then clear three parallel 16-entry tables (0x260E30, 0x260EB0 word
   stores and 0x1B3D30 byte stores) in one loop and return the object. Not C. */

/* Wave 24 (worker 09) -- the source below reaches 140 bytes against 152 and
   confirms the wall from the other side: retail reads and writes the 16-byte
   pair through registers (addiu $v1, $s0, 0x10 ; lq $v0, 0x0($v1) ;
   sq $v0, 0x0($a0)) where this cc1 folds both constant offsets into the
   instructions (lq $v0, 0x10($s0) ; sq $v0, 0x10($a2)).  The clearing loop
   also differs: retail walks three pointers (the two word tables and the byte
   table) and counts in a register of its own, this C indexes the arrays.

   Checked with: python3 tools/check.py func_L30_00413490 --diff
   Last line: func_L30_00413490: 0 of 1 places match (src/levels/30_insomniac_museum/L30_0040E660.c) */
