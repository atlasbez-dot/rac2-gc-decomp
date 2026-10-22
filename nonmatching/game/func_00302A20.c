/* func_00302A20 - 100 bytes, 28 places (the boot and every level), retail at
   0x00302A20: addiu $sp,$sp,-0x20 ; sd $s1,0x8($sp) ; daddu $s1,$a0,$zero ; sd $s0,0($sp) ;
   sd $ra,0x10($sp) ; jal func_0029EFD0 ; addiu $a0,$zero,0x3EF ; daddu $s0,$v0,$zero ;
   beqz $s0,+0xA ; addiu $v0,$zero,0xFF ; lhu $v1,0x34($s0) ; sb $v0,0x30($s0) ;
   addiu $a0,$s0,0x10 ; ori $v1,$v1,0x41 ; sh $v1,0x34($s0) ; lq $v0,0($s1) ;
   sq $v0,0($a0) ; jal func_002A0F48 ; daddu $a0,$s0,$zero ; daddu $v0,$s0,$zero ;
   ld $s1,0x8($sp) ; ld $s0,0($sp) ; ld $ra,0x10($sp) ; jr $ra ; addiu $sp,$sp,0x20.

   Measured near miss: with the grouped quadword pattern (-frac2-qcopy, the profile
   docs/COMPILER-NOTES.md qualifies for aligned TImode copies) the body is byte-exact
   except for the register that holds the copy's destination address: this attempt
   gives `addiu $a1,$s0,0x10 ; sq $v0,0($a1)` where the retail has
   `addiu $a0,$s0,0x10 ; sq $v0,0($a0)`.  Everything else, including the instruction
   order (lhu, sb, addiu, ori, sh, lq, sq), the call arguments and the frame, matches.

   Without -frac2-qcopy the copy folds into the instruction (`sq $v0,0x10($s0)`),
   because the CSE's address cost ties between a register and a register plus a small
   constant and the tie goes to the plus; the grouped pattern keeps both addresses in
   registers, which is the retail's shape.

   What was tried (all give the same $a1): the destination as a local TI128 pointer,
   the base as char-pointer/unsigned-int/int, the source through a char* cast, the fields
   through a struct type, the two field writes in either order, the copy before or
   after the call, the return as int and as void*, and the source of the copy through
   a local TI128.  The difference is one reload decision on the copy's destination
   pseudo, so what is still open is a source shape whose reload order gives the
   destination $a0 (the reload gives the source address $a0 first when both
   addresses need a register, as in the qualified witness func_L20_0039E158).

   The draft below needs a source unit of its own: config/cflags.txt must give that
   unit -frac2-qcopy, and the unit must hold no other body, since the flag changes
   every TImode copy in it.  */

#include "common.h"

/* The 128-bit integer mode is what reaches retail's lq/sq copies. */
typedef int TI128 __attribute__((mode(TI)));

extern void *func_0029EFD0(int id);

extern void func_002A0F48(char *object);

/* Finds the object with the fixed id, marks it and gives it the caller's position. */
int func_00302A20(void *object)
{
    void *found = func_0029EFD0(0x3EF);

    if (found != 0) {
        *(unsigned short *)((char *)found + 0x34) |= 0x41;
        *(unsigned char *)((char *)found + 0x30) = 0xFF;
        *(TI128 *)((char *)found + 0x10) = *(TI128 *)object;
        func_002A0F48(found);
    }
    return (int)found;
}
