/* func_L00_002A5CB0 - 852 bytes, 19 places, level 00_aranos_tutorial at 0x002A5CB0.
   Wave 13 s4: not attempted, screened.  This is the twin of func_L00_002A6008:
   it builds the object the resident block points at (the pointer is at
   0x1864 here), stores the two resident records into it and sets its flags.
   The 128-bit copies are retail's materialised shape again -
     addiu $a2,$s0,0x80 ; lq $v0,0($a2) ; sq $v0,0($v1)
     addiu $a1,$a0,0xF0 ; addiu $v1,$s0,0x90 ; lq $v0,0($v1) ; sq $v0,0($a1)
     addiu $v1,$s1,0x2010 ; lq $v0,0($sp) ; sq $v0,0($v1)
     addiu $a1,$sp,0x40 ; addiu $v1,$a0,0x10 ; lq $v0,0($a1) ; sq $v0,0($v1)
   (words 0x78C20000, 0x7C620000, 0x78620000, 0x7CA20000, 0x7BA20000,
   0x78A20000) - the same wall as func_L00_002A6008: this cc1 folds the
   constant offset into the lq/sq instead of keeping the address in a
   register.  The body also carries the float constant 0x3FD9999A and a
   `lw`/`sw` pair of the 0x801432D7 / 0x301432D7 tags.  Unblocker: the
   quad-copy wall of func_L00_002A6008 has to fall first. */
