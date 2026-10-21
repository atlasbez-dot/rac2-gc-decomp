/* func_L00_002A5518 - 808 bytes, 27 places, level 00_aranos_tutorial at 0x002A5518.
   Wave 13 s4: not attempted, screened.  The body is a float comparison chain
   over two resident records (0x8A4 and 0x8A8 of the record at 0x2290) with
   four branch-likely `bc1tl` blocks, a call to func_L00_002A5480, a counter
   at 0x1180 and a loop over eight entries; it has no 128-bit copy, so the
   quad wall of func_L00_002A6008 does not apply, but the float result
   registers, the likely-branch placement and the eleven saved registers
   ($s0..$s7, $fp, $ra, $f20, $f21) have to be reproduced word by word.  The
   frame is 0x70 and the constants are 0x3E80, 0x3E17, 0x3E97, 0xBE32,
   0x3D0E, 0xBD0E, 0x3DFA and 0xBDFA.  Unblocker: the float register plan
   and the branch-likely slots. */
