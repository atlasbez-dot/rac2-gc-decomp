/* Not matched (worker 05, level-20 wave 5, 2026-10-21).

   The body is 756 bytes with a frame of 0x90 and eight calls.  The one thing
   that stops it is its single 128-bit copy:

       addiu      $v1, $sp, 0x10      ; the address of a local buffer
       lq         $v0, 0x0($s2)       ; $s2 = *(arg0 + 0x68), a plain register
       sq         $v0, 0x0($v1)       ; the destination: the local buffer

   The source is a plain register and this compiler reproduces it; the
   DESTINATION is the wall: the retail keeps the address of the stack local in
   a register, this compiler folds the offset into the store
   (`sq $v0,0x10($sp)`).

   The mechanism and every escape measured are in the note on
   func_L20_0039E770 in this directory: the CSE's find_best_addr() replaces
   the address pseudo of a 128-bit access by the `plus` of a register and a
   constant (the class member with the highest rtx cost wins, and the plus
   costs 8 against the pseudo's 1), and the reload then prints the constant as
   the displacement.  The address stays in a register only when the pointer's
   value is not a plus of a register: a symbol, a load, a call result, or a
   pointer carried by a loop.  A stack local is a plus of $sp, so it folds
   like any other base.

   What the rest of the body needs (for the next worker):

     * the calls are f_0032F680, f_00353190 (three times), f_00302290,
       f_003022D0, f_0032F718, f_0032F778 (three times) and f_00302260;
     * the globals are the boot's D_001A8F20 (its address is taken with
       lui/addiu, so it is `extern char D_001A8F20[]` without sda), D_1FFC14
       and D_1B2AC8 (both read with lui + lw, so they need __attribute__((nosda)));
     * the float constants are 0x48CD1400 (210000.0f), 0x3DCCCCCD (0.1f),
       0x3D4CCCCD (0.05f), 0x484D1400, 0x47241000 and 0x3E99999A (0.3f);
     * the `div $zero,$v1,$v0` is guarded by `beql $v0,$zero` plus `break 0,7`
       (the divide-by-zero trap the compiler emits for an integer division),
       and the same guard appears on the `mfhi` of D_1B2AC8 / 10.

   This body belongs in the -G8 unit?  No: it reaches no global through $gp. */
