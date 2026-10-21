/* Not matched (worker 05, level-20 wave 5, 2026-10-21).

   The body is 996 bytes.  Its single 128-bit copy is

       addiu      $a0, $sp, 0x20      ; the address of a local buffer
       addiu      $v1, $s1, 0x10      ; $s1 = $a0, so arg0 + 0x10
       lq         $v0, 0x0($v1)
       sq         $v0, 0x0($a0)

   BOTH addresses are materialised in the retail and both are folded by this
   compiler (`lq $v0,0x10($s1)` and `sq $v0,0x20($sp)`).  The mechanism and
   every escape measured are in the note on func_L20_0039E770 in this
   directory: the CSE's find_best_addr() replaces the address pseudo of a
   128-bit access by the `plus` of a register and a constant, and the reload
   then prints the constant as the displacement.  The address stays in a
   register only when the pointer's value is not a plus of a register (a
   symbol, a load, a call result, a pointer carried by a loop), and neither
   address here is one of those.

   Note that $a0 (the local's address) is also the first argument of the call
   f_0041A018 further down, and that the retail keeps the materialised
   address in $a0 for both - the compiler hoists the address of a local that
   is passed to a function into a register.  Passing the same pointer to a
   call does NOT keep the address in a register in the 128-bit access: the
   measurement is in the note on func_L20_0039E770 (a local buffer passed to a
   call and used as the destination of a 128-bit store still gives
   `sq $2,560($sp)`).

   This body belongs in the -G8 unit?  No: it reaches no global through $gp. */
