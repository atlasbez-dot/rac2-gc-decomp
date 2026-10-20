/* func_L18_004273F0 - 660 bytes, 3 place(s), level 18_damosel, retail at
   0x004273f0. Screened with tools/w10_screen.py: 6 call(s)
   [func_0026FEB8@00427460, func_L18_0035D5A8@00427480,
   func_00282E80@004274F0, func_002A7750@004275EC,
   func_L18_00427208@00427634, func_002A7750@0042764C]; data addresses
   materialised [0x47c30000, 0x190000, 0x2c0000, 0x1b0000, 0x200000,
   0x200000, 0x1b0000]; float constants [-]; $gp-relative small data: no
   saves: -; callee-saved registers saved [-]; words plain C cannot emit
   [LQ/SQ 78620000@0x00b8, LQ/SQ 7FA20000@0x00bc]. Head: addiu $sp, $sp,
   -0x70 ; addiu $v0, $zero, -0x1 ; sd $s3, 0x28($sp) ; sd $s5, 0x38($sp) ;
   daddu $s3, $a0, $zero ; sd $s7, 0x48($sp). Not matched in this wave: the
   128-bit copy needs an `lq`/`sq` pair; plain C reaches it only through a
   `mode(TI)` local, and this cc1 folds the destination offset into the `sq`
   where retail materialises the pointer first. What would unblock it: the
   exact source expression tree, so this cc1 picks the same registers in the
   same order. */
