/* func_002D35B8 - 228 bytes, 28 places (the boot and every level), retail at
   0x002D35B8: the resident table's base is read from D_001ACFFC; the object
   gets the two values the table's entries hold.

   Measured near miss: 224 of 228 bytes with
   "-O2 -G0 -ffunction-sections -mno-split-addresses" in a unit of its own.
   The body, the three calls, the two reads of the table's base (the first
   before any call, the later ones reloaded after each call), the three
   operand multiplications and the two stores all match.

   What is left:

   1. The table's address.  The retail keeps 0x139568 in a register of its own
      (`lui $s0,0x14 ; addiu $s0,$s0,-0x6A98`) and adds the base to it
      (`addu $v0,$v0,$s0 ; lbu $v1,0x0($v0)`); this cc1 folds the constant
      into the base (`lui $v0,0x14 ; addu $v0,$v0,$v1 ; lbu $v0,-0x6A98($v0)`)
      - the common-subexpression pass prefers the plus because the address
      cost of a register plus a small constant is the same as a plain
      register (docs/COMPILER-NOTES.md, "The constant-offset wall is a cost
      tie in cse").  Writing the table as a symbol does not help: two
      pointers cannot be added in C, and the integer spelling of the sum
      changes the constant's form.

   2. The register allocation of the frame: the retail keeps the object in
      $s3 and the table's base in $v0, this cc1 keeps the object in $s2 and
      the base in $v0 as well, with one register fewer saved.

   What was tried: the base read once into a local and read at every use,
   the table's address as a literal, as a symbol and as an integer sum, the
   profile with and without `-mno-split-addresses`, `-fno-schedule-insns2` and
   the default.

   The C below needs the `-mno-split-addresses` profile: config/cflags.txt
   must give its unit "-O2 -G0 -ffunction-sections -mno-split-addresses", and
   the unit must hold no other body.  */

#include "include_asm.h"

/* The resident table's base; the function works on it directly. */
extern char *D_001ACFFC;

extern void func_002341550(char *first, int second);

extern void func_002343560(char *first);

extern void *func_0023435A8(void);

/* Reads the object's two values out of the resident table and stores them. */
void func_002D35B8(void *object)
{
    void *target;
    short value;
    unsigned char index;

    if (D_001ACFFC == 0)
        return;
    func_002341550(D_001ACFFC + 0x3BE08, 1);
    func_002343560(D_001ACFFC + 0x3C108);
    index = *(unsigned char *)(D_001ACFFC + 0x139568);
    value = *(short *)(index * 0xE0 + 0x239BA0 + 0x42);
    target = func_0023435A8();
    *(short *)((char *)object + 0x34) = value;
    func_002343560(D_001ACFFC + 0x3C108);
    index = *(unsigned char *)(D_001ACFFC + 0x139568);
    value = *(short *)(index * 0xE0 + 0x239BA0 + 0x6);
    *(short *)((char *)target + 0x58) = value;
}
