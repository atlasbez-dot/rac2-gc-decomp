/* Near miss from src/levels/20_yeedil/L20_00449178-g8.c: 172 bytes, retail 180.
   The attempt belongs in the -G8 unit (the body reaches three $gp-relative
   floats: D_L20_001B2410, D_L20_001B2414, D_L20_001B241C).

   Everything but the 128-bit copy is the retail instruction for instruction:
   the prologue, the three $gp loads, the two calls, the flag test, the
   branch offsets and the epilogue all match.

   The copy is the wall: retail materialises the two addresses into registers
       addiu $a0, $s0, 0x10 ; addiu $v1, $s1, 0x180 ;
       lq $v0, 0x0($v1) ; sq $v0, 0x0($a0)
   while this cc1 folds the constant offsets into the lq/sq operands
       lq $v0, 0x180($s1) ; sq $v0, 0x10($s0)
   which is 8 bytes short.

   Measured this wave (2026-10-20), with the RTL dump (-dg) as the evidence:
   the address of a TI access is built as (mem:TI (plus:SI (reg:SI base)
   (const_int off)) 0) and memory_address() (explow.c) keeps the plus because
   GO_IF_LEGITIMATE_ADDRESS (config/mips/mips.h) accepts plus(reg, const_int)
   for TImode when the offset + 16 - 1 <= 32767.  The offset is then folded
   into the lq/sq by the address printer.  Spellings tried and measured here:
   a TI128 pointer variable, a char * variable, a u32/u64 address variable, a
   struct with a TI128 member, a union with a float array, a static __inline__
   copy helper, the pointer used twice, the pointer live across a call, the
   pointer taken from a struct field, the offsets applied one at a time, and
   the 64-bit address form (which keeps the copy in a register but adds a
   dsll/dsra sign-extension pair per address, and uses daddu, not addiu).
   A pointer that is a plain parameter or a plain load keeps retail's shape
   (the address stays a register with offset 0), so the wall is exactly the
   source-level constant offset.

   History: an earlier attempt in this file was 184 bytes (the copy alone was
   two instructions instead of four); the body below is the 172-byte one, which
   matches the retail instruction for instruction everywhere but the copy. */

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef int TI128 __attribute__((mode(TI)));

extern float D_L20_001B2410 __attribute__((sda));
extern float D_L20_001B2414 __attribute__((sda));
extern float D_L20_001B241C __attribute__((sda));

extern float func_00283B98(float, float);
extern float func_00283198(float);
extern void func_002A9288(char *, float);
extern void func_L20_0044AA88(char *);

void func_L20_0044A838(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);
    u16 n = *(u16 *)(arg0 + 0x96);
    float r;

    *(u16 *)(arg0 + 0x96) = n + 1;
    if (*(u8 *)(arg0 + 0x31)) {
        *(TI128 *)(arg0 + 0x10) = *(TI128 *)(state + 0x180);
        r = func_00283B98(*(float *)(state + 0x1A0),
                          D_L20_001B2414 * 0.000290888245f);
        *(float *)(state + 0x1A0) = r;
        r = func_00283198(r);
        *(float *)(arg0 + 0x18) = *(float *)(arg0 + 0x18) + D_L20_001B2410 * r;
        func_002A9288(arg0, D_L20_001B241C);
    }
    if (((*(u16 *)(arg0 + 0x34)) ^ 1) & 1) {
        func_L20_0044AA88(arg0);
    }
}
