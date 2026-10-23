/* func_L05_00441D40 (352 bytes, 4 places) -- NEAR MISS, not integrated.
   No C was reached inside the budget of this attempt; what follows is the
   structure read off the retail bytes and the measured facts about it, so that
   the next attempt starts from facts and not from the disassembly.

   The body (level 05, address 0x441D40):
     - frame 0x20, saves $s0/$s1/$ra and $f20.
     - fifteen floats are read from the small data area through $gp and written
       into two structures: 0x1B1A10 (0.03), 0x1B1A14 (0.2), 0x1B1A18 (0) into
       +0x00/+0x04/+0x08 of the object at +0x70, then 0x1B1A4C (0.0125),
       0x1B1A50 (0.3), 0x1B1A54 (0), 0x1B1A58 (0.005), 0x1B1A5C (0.3),
       0x1B1A60 (0.2), 0x1B1A64 (0), 0x1B1A68 (0.3), 0x1B1A6C (1.5),
       0x1B1A70 (2.5), 0x1B1A74 (1.5), 0x1B1A7C (1.15) into the block at
       +0x50 of the same object, with the bytes at +0x6C/+0x6E/+0x6F and the
       words at +0x68/+0x70/+0x74 zeroed.  The store order is not the source
       order of the offsets: 0x50, 0x54, 0x58, 0x74, 0x60, 0x64, 0x78, 0x5C,
       0x6F, 0x70, 0x6C, 0x68, 0x74 (blocker 14: calibrate the order per
       block, do not rotate it by rule).
     - three calls to func_3065F8 (the same one three times), one to
       func_L05_00441EA0, one to func_2FDC80 with the literal 0x45800000 in f12,
       one to func_L05_00442720, one to func_3D1E20 and one to func_3D1E60
       (func_L05_00441EA0 and func_L05_00442720 are level functions and need
       ref_ names; func_3065F8, func_2FDC80 and func_3D1E20 are the boot's).
     - the pointer at +0x70 is loaded twice, once before and once after the
       first call.
     - the packed word at +0x84 is shifted left by five and added to
       D_001B1EC4; the word at +0x20 of that entry is shifted left by eight and
       added to D_001B251C; the float 0x3C888889 (pi/180) multiplies the float
       at 0x1B1AC0, and the product is written at +0x38 of the entry at +0x68 of
       D_001B251C, with -1 written at +0x214.
     - three words in the small data area are zeroed: 0x1B1B20, 0x1B1B64 and
       0x1B1B78.

   Measured facts:
   - the fifteen constants are small data, so the unit has to be built with -G8
     (a -g8.c sibling); at -G0 they are addressed with lui/addiu instead.
   - the literals 0x45800000 and 0x3C888889 come out of this cc1 as
     `lui $at,...; ori $at,...; mtc1 $at,$fN` (and `lui` alone when the low
     half is zero), in -G0 and in -G8 alike.
   - the level data addresses differ from level to level, and so do the small data
     offsets: the first constant is at $gp+0x2A20 (0x1B1A10) in level 05 and at
     $gp+0x2570 (0x1B1560) in level 25, and the absolute ones move as well
     (0x1B1EC4 in level 05, 0x1B1A44 in level 25).  The names therefore have to
     be D_L05_ for the canonical level and the linker takes the other levels'
     values from the retail bytes.
   - the small data offsets per level, in the order the body reads them: level 05
     and level 10 share them (0x2A20, 0x2A24, 0x2A28, 0x2A5C, 0x2A60, 0x2A64,
     0x2A80, 0x2A6C, 0x2A74, 0x2A7C, 0x2A68, 0x2AD0, then the three zeroed words
     at 0x2B30, 0x2B84, 0x2B88); level 15 has 0x2AF0, 0x2AF4, 0x2AF8, 0x2B2C,
     0x2B30, 0x2B34, 0x2B50, 0x2B3C, 0x2B44, 0x2B4C, 0x2B38, 0x2BA0, 0x2C00,
     0x2C54, 0x2C58; level 25 has 0x2570, 0x2574, 0x2578, 0x25AC, 0x25B0, 0x25B4,
     0x25D0, 0x25BC, 0x25C4, 0x25CC, 0x25B8, 0x2620, 0x2680, 0x26D4, 0x26D8.
   - the callees' catalogue names, read off config/levels/functions.tsv:
     func_3065F8 is func_00282C88, func_2FDC80 is func_L00_002E54E0, func_3D1E20
     is func_L05_003D1E20 and func_3D1E60 is func_L05_003D1E60; only
     func_00282C88 is a boot function, the other three are level functions whose
     address differs from level to level.

   What is left: the source of the two structure initialisations (the store
   order and the mixed float/byte/word sizes), the three calls with the same
   callee, and the packed-word arithmetic. */
