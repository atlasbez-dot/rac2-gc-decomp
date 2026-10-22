/* func_00304AD0 - 148 bytes, 1 place (the boot), retail at 0x00304AD0:
   addiu $sp,$sp,-0x30 ; sd $s0,0x10($sp) ; sd $s2,0x20($sp) ; sd $ra,0x28($sp) ;
   daddu $s2,$a0,$zero ; sd $s1,0x18($sp) ; addiu $s0,$s2,0x10 ;
   lw $s1,0x68($s2) ; lq $v0,0x0($s0) ; sq $v0,0x0($sp) ; daddu $a2,$s1,$zero ;
   daddu $a0,$s0,$zero ; jal func_282CC0 ; daddu $a1,$s0,$zero ;
   lwc1 $f0,-0x400($gp) ; daddu $a1,$s1,$zero ; lui $at,0x37E9 ;
   ori $at,$at,0x453 ; mtc1 $at,$f12 ; daddu $a0,$s0,$zero ; jal func_2FE880 ;
   mul.s $f12,$f0,$f12 ; daddu $a1,$s0,$zero ; daddu $a0,$sp,$zero ;
   addiu $a2,$zero,0x10 ; daddu $a3,$s2,$zero ; jal func_2761F8 ;
   daddu $t0,$zero,$zero ; beqz $v0,+8 ; addiu $v0,$zero,0x8 ; sb $v0,0x20($s2) ;
   ld $s0,0x10($sp) ; ld $s1,0x18($sp) ; ld $s2,0x20($sp) ; ld $ra,0x28($sp) ;
   jr $ra ; addiu $sp,$sp,0x30.

   The twin of func_00307298: the bodies are the same instruction for
   instruction, the only difference is the `$gp` constant, -0x400 here against
   -0x3A0 there, so the small-data word is at 0x001AEBF0.

   Measured near miss: 124 of 148 bytes with the profile
   "-O2 -G8 -ffunction-sections -frac2-qcopy" in a unit of its own
   (src/game/00300618-g8.c).  What is left is the argument setup of the first
   call, six instructions in the wrong places; see func_00307298.c for the
   measurement and for what was tried.

   Measured further (coordinator): the retail sets up the first call's
   arguments after the copy, in the order third, first, second (the second in
   the call's delay slot), while this cc1 sets the first argument up before
   the copy and the third in the delay slot.  The flags `-fno-schedule-insns`,
   `-fno-schedule-insns2` and both together do not change it.  The two
   arguments that carry the same pointer are the retail's first and second;
   only their order in the setup differs, so the copy's placement and the
   arguments' evaluation order are what is open. */

#include "common.h"

/* The 128-bit integer mode is what reaches retail's lq/sq copies. */
typedef int TI128 __attribute__((mode(TI)));

extern float D_001AEBF0 __attribute__((sda));
extern void func_282CC0(void *a, void *b, void *c);
extern void func_2FE880(void *a, void *b, float c);
extern int func_2761F8(void *a, void *b, int c, int d, int e);

/* Copies the owner's position, asks the vector unit whether it is inside the
   field, and marks the object when it is. */
void func_00304AD0(void *obj)
{
    void *s2 = obj;
    void *s0 = (char *)s2 + 0x10;
    void *s1 = *(void **)((char *)s2 + 0x68);
    TI128 local;

    *(TI128 *)&local = *(TI128 *)s0;
    func_282CC0(s0, s0, s1);
    func_2FE880(s0, s1, D_001AEBF0 * 2.7777778e-05f);
    if (func_2761F8(&local, s0, 0x10, s2, 0) != 0)
        *(unsigned char *)((char *)s2 + 0x20) = 8;
}
