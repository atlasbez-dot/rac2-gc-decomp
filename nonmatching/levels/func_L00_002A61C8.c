/* func_L00_002A61C8 - 600 bytes, 27 places, level 00_aranos_tutorial at 0x002A61C8.
   Wave 13 s4: not attempted, screened.  The body has no 128-bit copy, so the
   quad wall of func_L00_002A6008 does not apply here; what it has instead is
   a `div $zero,$v1,$v0` with the `break 0,7` guard, an integer-to-float
   conversion (`mtc1 $v1,$f12` then `cvt.s.w`), eight calls
   (func_00283CF0, func_L00_0035F6D8, func_0029FCC0, func_00283180,
   func_00283198, func_002A89A8, func_00283B98, func_00282F20,
   func_00282CC0, func_L00_0033BA68) and a long chain of float expressions
   whose result registers ($f0/$f1/$f12/$f13/$f20) have to be reproduced one
   by one, plus the `sltiu $a1,$s2,0x1` boolean-to-int form and a float
   constant in each branch.  The frame is 0x60 with $s0..$s3 and $f20 saved.
   Unblocker: the float register plan has to be found first; the argument
   order of func_L00_0035F6D8 (four integers plus the mode) is a lever the
   brief already measured for the fifth argument. */
