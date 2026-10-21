/* Not matched (worker 05, level-20 wave 5, 2026-10-21).

   The body is 1804 bytes with a frame of 0x310 and five 128-bit copies:

       lq $v1,0x0($a1)      ; sq $v1,0x0($sp)     ; BOTH plain (a stack slot at +0)
       lq $v0,0x0($v1)      ; sq $v0,0x0($s3)     ; BOTH plain (D_1C0420 and $s3)
       addiu $a0,$s1,0x10   ; lq $v0,0x0($a0) ; sq $v0,0x0($v1)   ; both materialised
       lq $v0,0x0($s3)      ; sq $v0,0x0($v1)     ; the destination is sp+0x250
       addiu $v1,$a1,0x20   ; lq $v0,0x0($v1) ; sq $v0,0x0($s2)   ; the source materialised

   The first two copies are the plain-pointer form and this compiler
   reproduces them; the other three materialise an address with a runtime
   base or a stack offset, which this compiler folds into the instruction.
   The mechanism and every escape measured are in the note on
   func_L20_0039E770 in this directory.

   What the rest of the body needs (for the next worker):

     * the frame is 0x310 and the saved float registers are $f20 to $f26;
     * the globals are D_1C0400, D_1C0420 (the boot's), the level data read
       with `lw $a1,0x2290($s2)` and the pi/180 constant 0x3C8EFA36, which
       needs the literal 0.017453294f in this compiler;
     * the pi/180 multiplication is `mul.s $f0,$f0,$f1` with the constant in
       $f1, compared with `c.lt.s $f21,$f0` and `bc1f`;
     * the copy at 0x003E7574 is inside a loop over a table at
       D_1C0400 + 0x18 with a bound of 0x80, so the destination there is a
       pointer that the loop walks - that one may come out of a plain C
       pointer.

   This body belongs in the -G8 unit?  YES: it reads a float through $gp
   (`lwc1 $f26,0x1324($gp)`, eight times), which only comes out of a file
   built with -G8, so it cannot live in the -G0 unit
   (src/levels/20_yeedil/L20_0039C448.c).  The gp offset is -0x5FFC, that is
   the level-20 address 0x001A8FF4, a float 0.0f (0x00000000); the C name is
   D_L20_001A8FF4 and it needs __attribute__((sda)). */
