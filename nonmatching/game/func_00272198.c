/* func_00272198 - 48 bytes, 28 places (the boot and every level), retail at
   0x00272198: lui $at,0x3F80 ; mtc1 $at,$f0 ; lui $v0,0x1B ;
   addiu $v0,$v0,0x5200 ; nop ; nop ; div.s $f12,$f0,$f12 ; lui $at,0x1B ;
   swc1 $f0,0x15A0($at) ; sw $zero,0x26C($v0) ; jr $ra ; swc1 $f12,0x268($v0).

   Measured near miss: 46 of 48 bytes with the profile
   "-O2 -G0 -ffunction-sections -g -mno-split-addresses" in a unit of its
   own.  Every instruction is the retail's, in the retail's order, with the
   retail's two nops in front of the division, the retail's two base
   registers and the retail's three stores - only the position of the zero
   store differs: this cc1 hoists it above the division, the retail keeps it
   after it (between the 1.0 store and the result store).  A volatile store
   does not change that: this cc1 only orders volatile accesses against each
   other.

   The two flags are the finding:

   - **-g gives the division its two nops.**  The SDK 3.01 assembler pads a
     division that is fewer than two instructions after the most recent code
     label; this cc1 emits no label in front of the division, and a debug
     build does.  That is the whole division floor of docs/COMPILER-NOTES.md
     (the same class is recorded for func_L00_003EEE20, func_L00_003E4B80,
     func_L00_00329FF0, func_L04_00365300, func_L02_002DCEA0 and
     func_L00_00368F58), and it is a flag, not a compiler patch.
   - **-mno-split-addresses gives the retail's address form.**  With the
     default (split) profile the two globals' high halves are computed into
     two registers; the retail computes one high half and adds the low half
     to the same register.

   What was tried: the division first in the function, the division after the
   address computation, the division inside an `if` with a zero test (that
   adds a branch the retail does not have), the constant as a literal, the
   result stored through a `float *` and through a `float[]`, a volatile
   zero store, and the flags `-g`, `-mno-split-addresses`,
   `-fno-schedule-insns`, `-fno-schedule-insns2` and their pairs.  */

#include "include_asm.h"

extern char D_001B5200[];

extern float D_001B15A0[];

/* Stores one divided by the argument into the resident object's state. */
void func_00272198(float value)
{
    char *state = D_001B5200;
    float one = 1.0f;
    float result = one / value;

    D_001B15A0[0] = one;
    *(int *)(state + 0x26C) = 0;
    *(float *)(state + 0x268) = result;
}
