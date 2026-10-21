/* func_00270E30 - 116 bytes, 28 places (the boot and every level), retail at
   0x00270E30: addiu $sp,$sp,-0x10 ; lui $v0,0x1B ; sd $s0,0($sp) ; sd $ra,0x8($sp) ;
   addiu $s0,$v0,0x5490 ; lbu $v1,0x2($s0) ; bnel $v1,$zero,+0x4C ; ld $s0,0($sp) ;
   addiu $a1,$s0,0xC0 ; addiu $v1,$s0,0x50 ; lq $v0,0($v1) ; sq $v0,0($a1) ;
   lbu $a0,0x3($s0) ; addiu $v0,$zero,0x2 ; bne $a0,$v0,+0x1C ; addiu $a0,$s0,0x60 ;
   daddu $a0,$a1,$zero ; lui $a1,0x19 ; daddu $a2,$a0,$zero ; jal func_282CC0 ;
   addiu $a1,$a1,-0x6090 ; addiu $a0,$s0,0x60 ; addiu $v1,$s0,0xD0 ; lq $v0,0($a0) ;
   sq $v0,0($v1) ; ld $s0,0($sp) ; ld $ra,0x8($sp) ; jr $ra ; addiu $sp,$sp,0x10.

   Measured near miss: 112 of 116 bytes with `-frac2-qcopy` and
   `-fno-schedule-insns` (the copy, the byte load, the comparison and the call
   are all in the retail's order); the difference is the register allocation of
   the two copies' addresses.

   The retail keeps the first copy's destination (object + 0xC0) in $a1, the
   second copy's source (object + 0x60) in $a0 - the $bne delay slot - and its
   destination (object + 0xD0) in $v1; it then copies $a1 into $a0 and $a0 into
   $a2 for the call's two arguments that are the same address.  This attempt
   keeps the first copy's destination in $a2 (so the call needs only one copy,
   $a0 = $a2) and puts the second copy's *destination* in the $bne delay slot
   ($a0 = object + 0xD0) with its source in $v1.

   Two further observations:

   - With the default profile (both schedulers on) the load of object[3] is
     hoisted above the copy and the allocation follows from that; with
     `-fno-schedule-insns` the copy keeps the retail's place.  The retail's
     copy was the game's inline-asm macro, so both schedulers treat it as a
     barrier; `-frac2-qcopy` reproduces its bytes but not the barrier.
   - The grouped pattern materialises the destination address before the
     source address (the expansion forces the destination first), while the
     retail's second copy has the source in the lower register.  That order is
     the pattern's, not the source's, so no C spelling changes it.

   What was tried: the destination and the source of the copies through `char *`
   and through `TI128 *`, the call's arguments through a `char *` variable and
   through the address expression, `volatile` on the byte reads (the TImode
   path drops the flag, so it changes nothing), and the flags `-frac2-qcopy`,
   `-fno-schedule-insns`, `-fno-schedule-insns2`, both schedulers off,
   `-fno-sched-interblock`, `-mastra-keep-frame-order` and their pairs.

   What is still open: the allocation of the two copies' addresses.  The
   grouped pattern's force order (destination first) is the likely cause; a
   pattern that materialises the source first, or one that leaves the copy a
   scheduling barrier, would be needed to close this family.

   The C below needs the `-frac2-qcopy` profile: config/cflags.txt must give
   its unit "-O2 -G0 -ffunction-sections -frac2-qcopy -fno-schedule-insns",
   and the unit must hold no other body, since the flag changes every TImode
   copy in it.  */

#include "include_asm.h"

/* The 128-bit integer mode is what reaches retail's lq/sq copies. */
typedef int TI128 __attribute__((mode(TI)));

/* The resident object's address; the function works on it directly. */
extern char D_001B5490[];

extern char D_00189F70[];

extern void func_00282CC0(char *first, char *second, char *third);

/* Copies the object's two vectors and asks the engine to rebuild its matrix
   when the object's type says so. */
void func_00270E30(void)
{
    unsigned char *object = D_001B5490;

    if (object[2] == 0) {
        *(TI128 *)(object + 0xC0) = *(TI128 *)(object + 0x50);
        if (object[3] == 2) {
            func_00282CC0((char *)(object + 0xC0), D_00189F70, (char *)(object + 0xC0));
        }
        *(TI128 *)(object + 0xD0) = *(TI128 *)(object + 0x60);
    }
}
