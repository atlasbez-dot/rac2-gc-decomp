#include "include_asm.h"

/* Near miss for func_002B8548 (boot 0x002B8548 only; it is in no level).
 *
 * Retail body (176 bytes): it calls func_1282A8 with the incoming argument, then
 * func_1288C0(0), then stores 2 into D_001B1D70 and 0 into D_001B1D74, then calls
 * func_128900 with (&D_001B1D70, &D_00138180) and keeps the result in D_00138180+0x194
 * (with +0x19C and +0x198 cleared), then stores 2 into D_001B1D70 and 1 into D_001B1D74
 * and calls func_128900 with (&D_001B1D70, &D_00138500), keeping the result in
 * D_00138500+0x194 and clearing +0x19C and +0x198.
 *
 * Measured with "-O2 -G0 -ffunction-sections -mno-split-addresses": 176 bytes, the
 * retail's size, but the three address materialisations are hoisted into the prologue
 * (la D_00138500, la D_00138180, la D_001B1D70) where the retail keeps two of them at
 * their use sites, and the four callee-saved registers are permuted.
 *
 * With the file's own profile ("-O2 -G0 -ffunction-sections", the split-addresses
 * mode) the candidate is 184 bytes: a 64-bit argument of a symbol address becomes a
 * (hi, lo) pair in two registers, where the retail keeps the address in one 32-bit
 * register ($s3) and widens it at the call (daddu $a0,$s3,$zero).
 *
 * Tried and measured: the addresses as a pointer, as an unsigned int and as an
 * unsigned long variable, inline; the parameter types long and unsigned long; the
 * casts (long), (unsigned long), (unsigned int) and none.  The split-addresses mode
 * is needed for the file's other functions (func_002B7E28, func_002B8048 and
 * func_002BA978 all stop matching under -mno-split-addresses), so a candidate for
 * this body would have to live in a file of its own with that flag.
 */
typedef struct {
    char reserved[0x18E];
    short active;
    int value;
    int f194;
    int f198;
    int f19C;
} State_2B8548;

extern State_2B8548 D_00138180;
extern State_2B8548 D_00138500;
extern int D_001B1D70;
extern int D_001B1D74;

extern void func_1282A8(void *);
extern void func_1288C0(long);
extern int func_128900(unsigned long, unsigned long);

void func_002B8548(void *a0)
{
    unsigned long p = (unsigned long)&D_001B1D70;
    int two = 2;

    func_1282A8(a0);
    func_1288C0(0);
    D_001B1D70 = two;
    D_001B1D74 = 0;
    D_00138180.f194 = func_128900(p, (unsigned long)&D_00138180);
    D_00138180.f19C = 0;
    D_001B1D70 = two;
    D_001B1D74 = 1;
    D_00138180.f198 = 0;
    D_00138500.f194 = func_128900(p, (unsigned long)&D_00138500);
    D_00138500.f19C = 0;
    D_00138500.f198 = 0;
}
