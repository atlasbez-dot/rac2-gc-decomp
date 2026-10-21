/* Near miss: every instruction agrees but one, a single destination register.
   Retail at 0x00407F80, level 04 (164 bytes, 1 place) starts the object on its first update:

     void f(char *a0)
     {
         char *s0 = a0;
         char *sub = *(char **)(s0 + 0x68);          /* read unconditionally */

         if (*(unsigned char *)(s0 + 0x20) == 0) {
             func_002A0488(s0, D_L04_001B07B0, D_L04_001B07B4, D_L04_001B07B8);
             *(unsigned char *)(s0 + 0x30) = 0xC4;
             *(unsigned char *)(s0 + 0x20) = 1;
             *(unsigned short *)(s0 + 0x34) |= 1;
             *(unsigned short *)(s0 + 0x32) = 0;
         } else {
             if (*(int *)(sub + 8) != -1)
                 if (func_002ACBC8(D_L04_001B9680) == 0)
                     return;
             func_002A0488(s0, D_L04_001B07B0, D_L04_001B07B4, D_L04_001B07B8);
             func_L00_002E6EF8(func_L04_00407B80, s0);
         }
     }

   Its sibling func_L04_00407000 in src/levels/04_barlow/L04_003AB458-g8.c is the same shape and
   already matches, which is what fixed the three small-data words (D_L04_001B07B0/14/18, the
   second triple, not the D_L04_001B0710/14/18 func_L04_00407000 uses).

   probes "as measured": the field at +0x68 must be read unconditionally - that is what makes the
   branch a plain `bnez` with the load in its delay slot instead of the `bnel` an inline read
   produces; the constant at +0x30 must be `unsigned char` (a signed `char` folds 0xC4 to
   `addiu $v1,$zero,-0x3C`).

   Remaining gap, one register: the delayed load is `lw $a1,0x68($s0)` in retail and
   `lw $v1,0x68($s0)` for us. Tried and did not move it: hoisting the read as `int *` and as
   `char *`, and reading it inline. Register allocation, the wall already paid. */

/* Second attempt (wave 24, worker 15): re-measured with the catalogue names
   (func_002A0488, func_002ACBC8, func_L00_002E6EF8 - the retail's
   f_00333460, f_00342228 and f_003076D0 at level 04) in the -g8 sibling.
   check.py (04_barlow): "04_barlow: instruction at +0x18 differs".
   The first branch now agrees with retail (a plain `bnez` with the load of
   the +0x68 field in its delay slot) and the frame, both calls and the
   stores are right.  Two differences are left:
     00407F98  lw   $v1, 0x68($s0)   |  lw   $a1, 0x68($s0)
     00407FD8  beq  $v1, $v0, .+0x6  |  beql $a1, $v0, .L00407FF4
   i.e. the pointer lands in $v1 where retail keeps it in $a1, and the second
   test comes out as a plain branch where retail uses the branch-likely form.
   Tried and all identical: the pointer in a named local; the pointer read
   inline; the test as `== -1` with the body in the else; the test as two
   `if (...) goto`; the call result tested the other way round; -G0.
   */
