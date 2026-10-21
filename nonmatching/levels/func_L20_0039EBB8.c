/* Not matched (worker 06, level-20 wave of 2026-10-20): the 128-bit
   copies are the wall.  The retail keeps the address of every 128-bit
   access in a register - `lq $v0,0x0($s2)` with `addiu $s2,$s1,0x10`
   (the object's +0x10), `lq $v0,0x0($s3)` with `addiu $s3,$s1,0xF0`
   (the object's +0xF0), `lq $v0,0x0($v1)` with `addiu $v1,$sp,0x10`
   (a local buffer) - while this compiler folds the offset into the
   instruction (`lq $v0,0x10($s1)`).

   The mechanism is measured in the note of func_L20_0039C448: the CSE
   substitutes the pointer's value (`plus(reg,const)`) into the address
   of the `lq`/`sq` and the reload pass then keeps the offset in the
   instruction; a pointer that is a parameter or a value loaded from
   memory keeps the register form, a computed `reg + const` never does.
   Every source spelling measured folds: a TI128 pointer variable, a
   struct member, an array index, a volatile load, a volatile pointer
   (a stack store and a reload, eight bytes over), a `static
   __inline__` copy helper, a truncation and a 64-bit address.

   This body belongs in the `-G8` unit?  No: it reaches no global
   through `$gp`. */

/* ---- level-20 wave 5, worker 05 (2026-10-21) ----
 *
 * The wall and every escape measured are now written down in the note on
 * func_L20_0039E770 in this directory: the CSE's find_best_addr() folds the
 * offset of a `plus` of a register into the lq/sq, and the address only
 * stays in a register when the pointer's value is not a plus of a register
 * (a symbol, a load, a call result, or a pointer carried by a loop).
 *
 * The retail's four copies of this body are:
 *
 *   addiu $s2, $s1, 0x10 ; lq $v0,0x0($s2)     ; the source: arg0 + 0x10
 *   sq $v0, 0x0($sp)                          ; the destination: a stack slot
 *   addiu $v1, $sp, 0x10 ; lq $v0,0x0($s3)     ; the destination: sp + 0x10
 *   sq $v0, 0x0($v1)
 *   addiu $v1, $s0, 0x60 ; lq $v0,0x0($s2)     ; the destination: state + 0x60
 *   sq $v0, 0x0($v1)
 *   addiu $v1, $s0, 0x60 ; lq $v0,0x0($v1)     ; the source: state + 0x60
 *   sq $v0, 0x0($s2)
 *
 * The first store (into the stack slot at +0) is the one this compiler can
 * reproduce; the other three materialise an address with a runtime base or a
 * stack offset, and it folds the offset into the instruction.
 *
 * This wave also measured that the retail's shape for a stack local is NOT
 * reachable by passing the local's address to a call: the compiler hoists
 * the address into the argument register (`addu $4,$sp,16`) and the 128-bit
 * store still folds (`sq $2,16($sp)`), also when the same pointer is passed
 * to two calls (then it is kept in $s0 and the store is still
 * `sq $2,560($sp)`).
 *
 * This body belongs in the -G8 unit?  No: it reaches no global through $gp. */
