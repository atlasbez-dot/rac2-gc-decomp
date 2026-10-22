/* func_002E11C0 - 104 bytes, 28 places (the boot and every level), retail at
   0x002E11C0: lui $v0,0x1B ; lw $v0,0x22A8($v0) ; addiu $sp,$sp,-0x10 ;
   lui $v1,0x1A ; lw $v1,0x72D4($v1) ; daddu $a0,$zero,$zero ; lui $at,0x1B ;
   sw $v0,0x20B4($at) ; addiu $v0,$v0,0x10 ; sd $ra,0x0($sp) ; lui $at,0x1A ;
   sw $v1,0x72D0($at) ; jal func_11AEA0 ; sw $v0,0x32B8($gp) ; jal func_2E1228 ;
   nop ; lui $a0,0x21 ; addiu $a1,$zero,0x3200 ; addiu $a2,$zero,0x40 ;
   jal func_282BA8 ; addiu $a0,$a0,0x4120 ; jal func_2E0F98 ; nop ;
   ld $ra,0x0($sp) ; jr $ra ; addiu $sp,$sp,0x10.

   Measured near miss.  The function advances the resident table's pointer and
   hands the engine its start.  Its shape is reproduced: the two globals it
   reads, the two it writes, the third one it writes through $gp, the four
   calls and their arguments, the pointer's +0x10 and the frame.

   Two things are still open, and each of them is one step:

   1. The last call's argument setup.  The retail computes the table's
      address as `lui $a0,0x21` first and adds the low half in the call's
      delay slot (`addiu $a0,$a0,0x4120`); this attempt computes the whole
      address between the other two arguments.  The low half's form depends
      on the spelling: a *symbol* is an address and comes out as
      `lui`+`addiu` (the retail's form) but the whole address is then
      computed at once, while the plain literal 0x214120 is a *constant*
      and comes out as `lui`+`ori` - with the literal every instruction
      matches except that last one (`ori $a0,$a0,0x4120` against the
      retail's `addiu $a0,$a0,0x4120`), because the retail's value is an
      address and not a constant.

   2. The two loads and the frame.  The retail has `lui $v0,0x1B ;
      lw $v0,0x22A8($v0)`, then the frame setup, then `lui $v1,0x1A ;
      lw $v1,0x72D4($v1)`: each load shares the register of its own high
      half, and the frame sits between the two loads.  With the default
      (split) profile this cc1 hoists both high halves to the top, keeps the
      loaded values in other registers and puts the frame after both loads.
      With `-mno-split-addresses` the two loads come out as the retail has
      them (each sharing its high half's register) and 21 of the 26
      instructions match - the rest is point 1.

   What was tried: the two names for the address 0x1B22A8 (the absolute
   form for the load, the $gp form for the store, which is what the retail
   does), the pointer advanced through a variable and through the
   expression, both globals read before the stores and one at a time, the
   table's address as a symbol, as a local and as the plain literal, the
   third argument as a variable, and the flags `-mno-split-addresses`,
   `-fno-schedule-insns`, `-fno-schedule-insns2`, `-fno-gcse` and
   `-fno-strength-reduce`.

   The C below needs the `-G8` profile (the store to 0x1B22A8 goes through
   $gp) and, for the two loads, `-mno-split-addresses`: config/cflags.txt
   must give its unit "-O2 -G8 -ffunction-sections -mno-split-addresses",
   and the unit must hold no other body.  */

#include "include_asm.h"

/* The two names stand for the same address: the load reaches it in the
   absolute form, the store through $gp. */
extern void *D_001B22A8 __attribute__((nosda));

extern void *D_001B22A8_2 __attribute__((sda));

extern void *D_001B20B4 __attribute__((nosda));

extern int D_001A72D0 __attribute__((nosda));

extern int D_001A72D4 __attribute__((nosda));

extern char D_00214120[];

extern void func_0011AEA0(int);

extern void func_002E1228(void);

extern void func_00282BA8(void *first, int second, int third);

extern void func_002E0F98(void);

/* Advances the resident table's pointer and hands the engine its start. */
void func_002E11C0(void)
{
    char *pointer = (char *)D_001B22A8;
    int other = D_001A72D4;

    D_001B20B4 = pointer;
    pointer += 0x10;
    D_001A72D0 = other;
    D_001B22A8_2 = pointer;
    func_0011AEA0(0);
    func_002E1228();
    func_00282BA8(D_00214120, 0x3200, 0x40);
    func_002E0F98();
}
