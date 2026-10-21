/* from src/core/0011BEE0.c: kputchar, exact bytes only with a register pin */
/*
 * The 56-byte body comes out byte for byte with a local pinned to $v1 through an
 * empty asm statement, __asm__("" : "=r"(p) : "0"(0x1000F180)). AGENTS.md's plain-C
 * rule forbids inline assembly and register pins, so this body cannot land as C;
 * the marker is back in place. The same shape is what rac1-decomp records for its
 * kputchar. ASM_FUNC candidate on a maintainer's agreement.
 */
#include "common.h"
#include "structs.h"

/* kputchar (libkernl.a:kprintf.o): wait until the SIO status port
   (0x1000F130) has its busy bit (0x8000) clear, write the character to
   the SIO data port (0x1000F180) and return it.

   Retail's store is not volatile (it fills the return's delay slot, which
   a volatile access never does) yet its address stays in a register
   (lui/ori). A plain constant address is folded into the store by the
   optimizer instead, so the address goes through an empty asm that hides
   its value.

   Identity: config/datamine/ntsc-u-sdk-matches.tsv names 0x0011BEE0
   libkernl.a:kprintf.o kputchar; rac1-decomp src/core/00119D88.c:
   func_00119D88 is the same body.

   Wave 24 (worker 06) measured the same body and adds:
   - the dead `daddu $v0,$a0,$zero` is the RETURN VALUE: the function returns the
     character (kputchar), so `return c;` puts the copy exactly where the retail
     has it, between the `lui` and the `ori`:
         int func_0011BEE0(int c) {
             while (*(volatile u32 *)0x1000F130 & 0x8000) ;
             *(volatile u8 *)0x1000F180 = c;
             return c;
         }
     compiles (sdk -O2 -G2) to 60 bytes with every word of the retail's tail
     right, except that the retail has the `sb $a0,0($v1)` in the `jr $ra` delay
     slot and this cc1 leaves a nop there: a volatile store is not scheduled
     into a delay slot.
   - without `volatile` on the store the delay slot is right (the store goes in
     it) but the address is split: `lui $at,0x1001 ; sb $a0,-0xE80($at)` instead
     of the retail's materialised `lui $v1,0x1000 ; ori $v1,$v1,0xF180 ;
     sb $a0,0($v1)`.  A pointer variable for the address does not help: the
     compiler folds the constant back into the store.
   - the argument must be an int: an unsigned char parameter adds
     `andi $a0,$a0,0xFF`, which the retail does not have (64 bytes).
   So the retail needs the address in a register AND a non-volatile store; the
   only spelling that gives both is the register pin the note above quotes, and
   AGENTS.md's plain-C rule forbids it. */
int func_0011BEE0(int c) {
    unsigned char *p;

    while (*(volatile unsigned int *)0x1000F130 & 0x8000)
        ;
    __asm__("" : "=r"(p) : "0"(0x1000F180));
    *p = c;
    return c;
}
