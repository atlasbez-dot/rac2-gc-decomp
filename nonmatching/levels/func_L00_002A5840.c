/* func_L00_002A5840 - 1136 bytes, 27 places, level 00_aranos_tutorial at 0x002A5840.
   Wave 13 s4: not attempted, screened.  The body is a long straight-line
   float computation with nine saved registers ($s0..$s7, $fp, $ra), a
   `div`/`break` guard, a `mtc1 $s3,$f12` (a general register into an FPR)
   and $gp-relative small data (`addiu $a0,$gp,-0x72F8`), which needs a
   -G8 unit for this file.  It also carries the retail quad-copy shape:
     sq $v0,0($s7) ; sq $v0,0($s5) ; lq $v0,0($v1) ; sq $v0,0($fp) ;
     lq $v0,0($s2) ; sq $v0,0($s0)
   (words 0x7AE20000, 0x7EA20000, 0x78620000, 0x7FC20000, 0x7A420000,
   0x7E020000) - the same wall as func_L00_002A6008, where this cc1 folds
   the constant offset into the lq/sq.  The 0x700014A9 word is the MMI0
   `pcpyld` that plain C cannot spell either.  Unblocker: the quad-copy wall
   of func_L00_002A6008 and the MMI0 zero have to fall first, and the file
   would need its own -G8 build. */
