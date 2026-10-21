/* func_002E5F00 - near miss.
 *
 * The retail body (56 bytes):
 *   addiu $v0,$zero,0x70 ; lui $a2,0x19 ; mult $a0,$a0,$v0
 *   addiu $a2,$a2,-0x79A0          ; a2 = D_00188660
 *   addiu $v0,$a2,0xA0             ; v0 = D_00188660 + 0xA0
 *   addu  $a2,$a0,$a2              ; a2 = D_00188660 + index * 0x70
 *   lbu   $v1,0x75($a2) ; ori $v1,$v1,0x40 ; sb $v1,0x75($a2)
 *   addu  $a0,$a0,$v0              ; a0 = D_00188660 + 0xA0 + index * 0x70
 *   lq    $v0,0($a1) ; sq $v0,0($a0)
 *   jr    $ra ; addiu $v0,$zero,1
 *
 * What matches: the flag byte (load, or with 0x40, store), the three-operand
 * `mult` for index * 0x70, and the return value 1 in the delay slot.
 *
 * What differs: the address of the 16-byte copy.  Retail keeps the whole
 * destination address in a register (base + 0xA0 computed at run time, then
 * index * 0x70 added) and stores with `sq $v0,0($a0)`.  This cc1 folds the
 * constant 0xA0 into the store's displacement instead (`sq $v0,0xA0($reg)`),
 * which is the cost tie the compiler notes record in cse's find_best_addr.
 *
 * Tried: about thirty source shapes for the copy - a TI-mode (`mode(__TI__)`)
 * scalar, a struct of four ints, of chars, of shorts, of floats, a struct
 * holding a TI member, a union, a pointer variable for the destination, the
 * destination as a byte pointer, the destination computed from the record
 * pointer, the constant before and after the index, unsigned index, and a
 * volatile copy.  The struct shapes produce the retail's *address* form
 * (`addu $reg,base,0xA0` then `addu $reg,index,$reg`) but copy with ld/sd or
 * ldl/ldr; the TI shapes copy with lq/sq but fold the displacement.
 *
 * What would unblock it: a source that makes this cc1 compute the copy
 * address in a register and copy a quadword; the two behaviours are exclusive
 * in every shape measured.
 */
#include "include_asm.h"

typedef int s32;

typedef unsigned char u8;

typedef int s32ti __attribute__((mode(__TI__)));

extern u8 D_00188660[];

int func_002E5F00(int index, void *src)
{
    u8 *p = D_00188660 + index * 0x70;

    p[0x75] |= 0x40;
    *(s32ti *)(p + 0xA0) = *(s32ti *)src;
    return 1;
}
