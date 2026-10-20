/* func_L18_003F75E8 - 264 bytes, 3 place(s), level 18_damosel, retail at
   0x003f75e8. Screened with tools/w10_screen.py: 0 call(s) [-]; data
   addresses materialised [0x200000, 0x1b0000, 0x1b0000, 0x1b0000]; float
   constants [-]; $gp-relative small data: no   saves: -; callee-saved
   registers saved [-]; words plain C cannot emit [-]. Head: addiu $v0,
   $zero, -0x1 ; bne $a0, $v0, . + 4 + (0x3 << 2) ; sw $zero, 0x0($a1) ; jr
   $ra ; daddu $v0, $zero, $zero ; lui $v0, 0x20. Not matched in this wave:
   the body is straight-line code whose register allocation and the
   materialisation of its constant addresses have to be reproduced word for
   word. What would unblock it: the exact source expression tree, so this
   cc1 picks the same registers in the same order. */
