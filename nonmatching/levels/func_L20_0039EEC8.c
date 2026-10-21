/* Not matched (worker 05, level-20 wave 5, 2026-10-21).

   The body is 836 bytes with a frame of 0x60 and four 128-bit copies:

       addiu $v1, $s6, 0x10 ; lq $v0,0x0($s0) ; sq $v0,0x0($v1)   ; dest materialised
       lq $v0,0x0($s5)      ; sq $v0,0x0($s3)                    ; BOTH plain registers
       addiu $v1, $s3, 0x10 ; lq $v0,0x0($fp) ; sq $v0,0x0($v1)   ; dest materialised
       addiu $v1, $s3, 0x20 ; lq $v0,0x0($s7) ; sq $v0,0x0($v1)   ; dest materialised

   The second copy is the plain-pointer form and this compiler reproduces it;
   the other three materialise the destination, which this compiler folds
   (`sq $v0,0x10($s6)` and so on).  The mechanism and every escape measured
   are in the note on func_L20_0039E770 in this directory.

   What the rest of the body needs (for the next worker):

     * the frame is 0x60 and the saved registers are $s0, $s1, $s2, $s3, $s4,
       $s5, $s6, $s7, $fp and $ra, with $f20 in the frame - eleven saved
       registers, so the body is long;
     * the calls are f_00325040, f_00302A38, f_00302548 (many times),
       f_00302260 (twice), f_00302378 (four times) and f_00302290 (twice);
     * the globals are D_234880, D_235500, D_235540, D_235550 and D_235560
       (level data, taken with lui/addiu), D_1B388C, D_1B38AC and D_1B38C2
       (the same) and D_001AEDA0 (read with lui + lw, so it needs
       __attribute__((nosda)));
     * the float constants are 0x3F800000 (1.0f) and the pi/180 constant
       0x3C8EFA36, which needs the literal 0.017453294f in this compiler;
     * the two loops (the `sw $zero,0x0($v0)` loop over D_1B38AC with a count
       of 7 and the `sh $zero,0x0($v0)` loop over D_1B38C2 with a count of 9)
       are counted loops, and this compiler's loop optimiser turns a counted
       loop into a count-down (`addiu $v1,$v1,-1` ; `bgez`) where the retail
       keeps the count-up - that is a separate obstacle from the copy.

   This body belongs in the -G8 unit?  YES: it reads a float through $gp
   (`lwc1 $f12,-0x2B0($gp)`, eight times), which only comes out of a file
   built with -G8, so it cannot live in the -G0 unit
   (src/levels/20_yeedil/L20_0039C448.c).  The gp offset is -0x2B0, that is
   the level-20 address 0x001AED40, the float 6.0f (0x40C00000); the C name
   is D_L20_001AED40 and it needs __attribute__((sda)). */
