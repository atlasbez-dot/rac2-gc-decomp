/* func_L11_00425AF8 (228 bytes, 1 place) -- NEAR MISS, not integrated.
   state: 228 bytes, the size is retail's; 42 of 57 words are identical and every
   branch target is retail's. Two differences remain, both in the same places.

   check.py (11_joba), with the source below:
     00425AF8  lbu    $v1, 0x21($a0)    |  lbu    $v0, 0x21($a0)
     00425AFC  addiu  $v0, $zero, 0xFF  |  addiu  $v1, $zero, 0xFF
     00425B00  beq    $v1, $v0, ...     |  beq    $v0, $v1, ...
   The kind byte and the 0xFF constant are swapped between $v0 and $v1; the table
   base then follows the constant's register, so `lui $v0 / sll $v1 / addu $v1` comes
   out against retail's `lui $v1 / sll $v0 / addu $v0`. Everything from 00425B2C on
   matches word for word until the branch forms:

     00425B54  bltz   $v1, ...          |  bltzl  $v1, ...
     00425B58  nop                      |  lh     $v0, 0x0($a2)
     00425BA0  bltz   $v0, ...          |  bltzl  $v0, ...
     00425BA4  nop                      |  lh     $v0, 0x0($a2)
     00425BAC  bne    $v0, $t1, ...      |  bnel   $v0, $t1, ...
     00425BB0  nop                      |  lh     $v0, 0x0($a2)

   What is measured and right:
   - the level data is read with %hi/%lo, not through $gp: `D_L11_001FC420` (the
     0x1FC420 table) needs `lui $v1,0x20 ; addiu $v1,$v1,-0x3BE0 ; sll ; addu ; lw`,
     and `D_L11_001B359C` needs `lui $t0,0x1B ; lw $t0,0x359C($t0)`. Both are reached
     with plain (non-sda) declarations; the table holds 32-bit addresses, so it must
     be `int[]` and not `char *[]`. The unit's own declarations
     (`extern char *D_L11_001FC420[] __attribute__((sda));` and
     `extern int D_L11_001B359C __attribute__((sda));`) have to be repaired to the
     forms below before this C can be integrated there.
   - the table entry is sign-extended once (`daddu $a2,$v0,$zero`), and the record
     address is 32-bit arithmetic (`addu $a1,$t0,$v0`), so `base` is an `int` and the
     record pointer is `base + (id << 8)`.
   - the loop shape is the source's: the id load (`lhu`) is at the head, the signed
     test load (`lh`) at the bottom, and the `!= 0xCF6` case leaves the loop after
     `p++` while the `0xCF6` case falls through to the same `p++` and the `bgez`.

   What is left:
   - the two `bltz`/`bne` would have to be the annulling (`l`) forms, which this
     cc1 only emits when the delay-slot candidate conflicts with the opposite
     thread (reorg.c sets INSN_ANNULLED_BRANCH_P only on that path). Retail's delay
     slots hold a copy of the loop's `lh $v0,0x0($a2)` in $v0, the register the
     loop head's `andi $v0` needs, which is exactly the conflict that would annul
     the slot and force the second copy at the loop's bottom. Getting the kind byte
     into $v0 (and not $v1) is what would let the copy land in $v0 as well.
   - the register swap is the allocator's choice, not the source's: this cc1's local
     allocator hands registers out in order of decreasing live range, and the 0xFF
     constant wins $v0 here. Loading the kind byte twice (once for the test, once for
     the index) puts it in $v0, but then the index is computed in 64 bits and a
     `daddu $v1,$v0,$zero` appears; a single load into a variable keeps the index in
     32 bits and loses $v0.
*/

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern int D_L11_001FC420[];
extern int D_L11_001B359C;

void func_L11_00425AF8(void *a0)
{
    u8 kind = *(u8 *)(a0 + 0x21);
    int entry;
    int base;
    s16 *p;
    u8 *rec;
    u16 id;
    void *obj;
    s16 v;

    if (0xFF == kind) {
        return;
    }
    entry = D_L11_001FC420[kind];
    if (entry == 0) {
        return;
    }
    a0 = *(void **)(a0 + 0x68);
    base = D_L11_001B359C;
    p = (s16 *)entry;
    for (;;) {
        id = *(u16 *)p;
        id &= 0x7FFF;
        rec = (u8 *)(base + (id << 8));
        if (*(s8 *)(rec + 0x20) < 0) {
            return;
        }
        if (*(s16 *)(rec + 0xAA) == 0xCF5) {
            obj = *(void **)(rec + 0x68);
            *(u16 *)(obj + 0x266) = 1;
            *(unsigned int *)(obj + 0x560) += 1;
            if (*(float *)(a0 + 0x20) <= 0.0f) {
                *(unsigned int *)(obj + 0x584) += 1;
            }
        }
        if (*(s8 *)(rec + 0x20) < 0) {
            return;
        }
        if (*(s16 *)(rec + 0xAA) != 0xCF6) {
            p++;
            return;
        }
        obj = *(void **)(rec + 0x68);
        *(u16 *)(obj + 0x266) = 1;
        *(unsigned int *)(obj + 0x560) += 1;
        v = *(s16 *)p;
        p++;
        if (v >= 0) {
            continue;
        }
        return;
    }
}
