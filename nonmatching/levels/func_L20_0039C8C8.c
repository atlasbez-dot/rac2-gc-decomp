/* Not matched (worker 06, level-20 wave of 2026-10-20): not attempted
   in depth.

   The body has no 128-bit copy and no `$gp` access, so neither of the
   two walls of this level is in the way; it is 836 bytes with a frame
   of 0xD0, ten callee-saved registers and eight saved float registers
   (f21..f29), and it calls func_00282CF0, func_00282920, func_00282CC0
   and others.

   This body belongs in the `-G8` unit?  No: it reaches no global
   through `$gp`. */

/* ------------------------------------------------------------------
   level-20 wave of 2026-10-21, worker 07: the structure, and what it
   would take to match it.

   The body has NO 128-bit copy and reaches no global through $gp, so
   neither of the two walls of this level is in the way; it is 836 bytes
   with a frame of 0xD0, ten callee-saved registers ($s0..$s7 and $fp) and
   ten saved float registers (f20..f29).

   THE STRUCTURE.

     - $s2 = the argument; the first call is
       func_00282CF0(sp, D_L20_001B9FC0, arg0), i.e. it fills a 16-byte
       stack buffer at sp+0 from the global and the argument;
     - the two floats of that buffer go through func_00283248 and the
       result is kept in $f29; the constants are 0.2f ($f25), 1/60f
       ($f28), 1.0f ($f24), 210000.0f ($f27), 0.0f ($f22), 0x3FB2B8C4
       ($f26) and 0.1f ($f23);
     - the loop at .L0039C9A0 runs while $s6 >= 0, with $s6 starting at
       0x13 and the decrement in the delay slot of the call to
       func_002A7878 - a COUNT-DOWN loop (this is one of the bodies where
       the retail keeps the count-down form);
     - the body of the loop calls func_002A7878, func_00282D30,
       func_002A78D8, func_00283CF0, func_002A7878, func_002A78D8,
       func_002BDCE8 (f_00349DD8), func_00283CF0, func_00283CE0,
       func_002A7878, func_002A7878, func_002A78D8, func_00283B98,
       func_002AF000 (f_003385C8), func_002A78D8 and func_002C16C0
       (f_0034DA68);
     - three more stack buffers are used at sp+0x10 ($s4), sp+0x20 ($s5)
       and the float fields at +0x20, +0x24 and +0x28.

   WHY IT WAS NOT MATCHED HERE.  The float register allocation is the
   hard part: the retail keeps four constants in $f20..$f23 for the whole
   body and passes them as the second and third float arguments of
   func_002A78D8 and func_002B3BA8, and it re-uses $f0 for four
   different values in a row.  The frame is 0xD0 and every one of the
   eight calls has to set its arguments in the retail's order.

   This body belongs in the `-G8` unit?  No: it reaches no global through
   `$gp`.
   ------------------------------------------------------------------ */
