/* func_00270EA8 - 56 bytes, 28 places (the boot and every level), retail at
   0x00270EA8: lui $v0,0x1B ; addiu $a2,$v0,0x5490 ; lbu $v1,0x2($a2) ;
   beqz $v1,+0x20 ; addiu $a0,$a2,0x50 ; addiu $v1,$a2,0xC0 ; lq $v0,0($v1) ;
   sq $v0,0($a0) ; addiu $a1,$a2,0xD0 ; addiu $v1,$a2,0x60 ; lq $v0,0($a1) ;
   sq $v0,0($v1) ; jr $ra ; nop.

   Measured near miss: every instruction is the retail's, in the retail's
   order, with the retail's two quadword copies (both addresses in registers,
   zero displacement) - only the registers differ.  The retail keeps the
   object's address in $a2 and the four copy addresses in $a0, $a1 and $v1;
   this attempt keeps the address in $v0 and the four addresses in $a0, $a1,
   $a2 and $v1, and it computes the four addresses before the first copy
   instead of one pair per copy.

   The grouped pattern materialises the destination address before the source
   address (its expansion forces the destination first), while the retail's
   second copy has the source in the lower register ($a1) and the destination
   in $v1; that order is the pattern's, not the source's.

   What was tried: the destination and the source through `char *` and through
   `TI128 *`, a `const` pointer, the object as a structure with named fields,
   the second copy's source in a local variable, the two copies in the
   opposite order (they are independent, so the source may swap them), and
   the flags `-frac2-qcopy`, `-fno-schedule-insns`, `-fno-schedule-insns2`,
   `-fno-sched-interblock` and `-mastra-keep-frame-order`.

   What is still open: the allocation of the copy addresses.  The C below
   needs the `-frac2-qcopy` profile: config/cflags.txt must give its unit
   "-O2 -G0 -ffunction-sections -frac2-qcopy", and the unit must hold no other
   body, since the flag changes every TImode copy in it.  */

#include "include_asm.h"

/* The 128-bit integer mode is what reaches retail's lq/sq copies. */
typedef int TI128 __attribute__((mode(TI)));

/* The resident object's address; the function works on it directly. */
extern char D_001B5490[];

/* Copies the object's saved vectors back into its working ones. */
void func_00270EA8(void)
{
    unsigned char *object = D_001B5490;

    if (object[2] != 0) {
        *(TI128 *)(object + 0x50) = *(TI128 *)(object + 0xC0);
        *(TI128 *)(object + 0x60) = *(TI128 *)(object + 0xD0);
    }
}
