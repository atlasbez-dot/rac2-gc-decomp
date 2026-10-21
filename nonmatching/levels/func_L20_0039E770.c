/* Not matched (worker 05, level-20 wave 5, 2026-10-21).

   The body is 284 bytes with a frame of 0x40 and four calls.  Everything in it
   is ordinary C; the one thing that stops it is its single 128-bit copy:

       addiu      $v1, $s1, 0x10      ; $s1 = $a0, so the address is arg0 + 0x10
       lq         $v0, 0x0($v1)       ; the source
       sq         $v0, 0x0($sp)       ; the destination: a stack slot at +0

   The destination is the retail's "stack slot" form and this compiler
   reproduces it (`sq $v0,0($sp)` comes out of a 16-byte local).  The SOURCE
   is the wall: the retail keeps `arg0 + 0x10` in a register, this compiler
   folds the offset into the load (`lq $v0,0x10($s1)`).

   The wall is measured, not guessed.  The mechanism is in the CSE's
   find_best_addr() (gcc/cse.c, in the tree under build/downloads/ with
   tools/compiler/patches/ applied):

     - the front end builds the address of a 128-bit access as the pointer's
       pseudo: `(set (mem:TI (reg/v:SI 86) 0) ...)` (cc1 -da, the .rtl dump);
     - the pseudo's value is `(plus:SI (reg/v:SI 84) (const_int 16))`, and the
       CSE puts the pseudo and the plus in ONE equivalence class;
     - find_best_addr() replaces the address with the class member that has
       the highest rtx cost among the members whose CSE_ADDRESS_COST equals
       the address's own.  The plus costs notreg_cost(plus) =
       rtx_cost(plus)*2 = 10, the pseudo costs 1 and a hard register 2
       (COST() in gcc/cse.c), so the plus always wins and the offset is
       folded into the instruction;
     - the reload then prints the offset as the displacement, because
       GO_IF_LEGITIMATE_ADDRESS (gcc/config/mips/mips.h) accepts
       plus(reg,const_int) for TImode while the offset is in [-32768, 32752].

   So the address stays in a register only when the plus is NOT in the class
   of the address pseudo, that is when the pointer's value is not a plus of a
   register.  Measured escapes, all confirmed this wave:

     * the value is a SYMBOL: `*(TI128 *)(SYM + 0x10)` gives
       `lui $2,%hi(SYM+16); addiu $2,$2,%lo(SYM+16); sq $3,0($2)` - the address
       is materialised, because mips_address_cost(plus(symbol,16)) is 3 and
       not 1, and because GO_IF_LEGITIMATE_ADDRESS rejects a constant address
       for TImode on the R5900 (`! (TARGET_MIPS5900 && mode == TImode)`);
     * the value is LOADED FROM MEMORY: `TI128 *d = *(TI128 **)(arg0 + 0x68);`
       gives `lw $3,0($a0); lq $2,0($a1); sq $2,0($3)`;
     * the value is a CALL RESULT: `TI128 *d = getp();` gives the same shape;
     * the pointer is CARRIED BY A LOOP: `for (i=0;i<2;i++) *d = v;` gives
       `addu $4,$4,16; lq $2,0($a1); sq $2,0($4)` - the address stays in a
       register, but the loop costs 32 bytes over the retail.

   None of them fits this body: the source address is `arg0 + 0x10` with a
   runtime base.  The retail's own source used an inline-assembly copy macro
   (its operand has to live in a register), and src/ forbids inline assembly.

   The rule is a proof, not a list of failures: the CSE puts the address
   pseudo and the `plus` in one class (the pseudo is DEFINED by the plus, so
   the two are equal and the class is shared), and the substitution picks the
   member with the highest rtx cost, which is the plus.  The only way out is
   a pointer whose value is not a plus of a register - a symbol, a load, a
   call result - or a pointer the loop carries.  The compiler-side way out
   would be to make find_best_addr() keep the pseudo for a TImode address; a
   change in tools/compiler/, not in the source, and not this worker's to make.

   The candidate is 280 bytes against the retail's 284: the one `addiu` is
   the whole difference.

   Everything else in the body is reachable from C: the `ori $v0,$zero,0xFDE7`
   / `sltu $v0,$v0,$v1` / `bnez` triple is the unsigned threshold test on the
   u16 counter at +0x96 (0xFDE7 = 65007; the counter is only raised while it
   is at most that), the 0x3CF5C28F and 0x3E99999A constants are 0.24f and
   0.3f, and the four calls are f_00302920 (a float helper), f_003032B8,
   f_00338210 and f_0039E9F8.

   This body belongs in the -G8 unit?  No: it reaches no global through $gp. */
