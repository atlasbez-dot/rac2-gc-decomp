/* func_L18_003F9FB0 - 460 bytes, 3 place(s), level 18_damosel, retail at
   0x003f9fb0. Screened with tools/w10_screen.py: 2 call(s)
   [func_L18_003FC9B8@003FA0C4, func_L18_003F7988@003FA0DC]; data addresses
   materialised [0x200000, 0x1b0000, 0x200000, 0x1b0000, 0x1b0000]; float
   constants [-]; $gp-relative small data: no   saves: -; callee-saved
   registers saved [-]; words plain C cannot emit [-]. Head: addiu $sp, $sp,
   -0x60 ; daddu $v1, $zero, $zero ; sd $s2, 0x20($sp) ; sd $s0, 0x10($sp) ;
   sd $s1, 0x18($sp) ; sd $s3, 0x28($sp). Not matched in this wave: the body
   is straight-line code whose register allocation and the materialisation
   of its constant addresses have to be reproduced word for word. What would
   unblock it: the exact source expression tree, so this cc1 picks the same
   registers in the same order. */
