/* func_L00_0040B2C0, 112 bytes, 27 placements.  ABANDON - the func_L00_003ACC88 wall,
   same body instruction for instruction (only the $gp offset of the float constant and the
   branch targets differ).
   Builds {CONST, 0, 0, 1.0f} in a 16-byte local, copies that quadword into a second 16-byte
   slot and hands it to func_2EE5B0(slot, slot, a0 + 0xC0) and func_2EE108(a1, slot, a0 + 0x10).
   The retail materialises the 128-bit zero with pcpyld $v0,$zero,$zero and stores the register
   form (sq $v0,0x10($sp) at +0x14), then copies the built quadword with lq $v0,0x10($sp) at
   +0x2C / sq $v0,0x0($sp) at +0x48.  rac2_fold_zero_ti_store folds that zero store to
   sq $zero whenever the register is dead afterwards, which it is here, so the register form
   cannot be produced from C under the pinned chain.  The C below is the closest spelling
   (132 bytes); tools/check.py last line for the twin: 112 bytes, +0x1c differs.

   Wave 8 w8-03: measured again with the current compiler, the C below is 124 bytes with the
   default flags (-O2 -G0 -ffunction-sections) and stays 124 with -frac2-qcopy,
   -frac2-qcopy-barrier, -frac2-zero-ti-barrier, -frac2-no-annulled-wide-stores and their
   pairs; -frac2-zero-ti-por alone makes it 128.  The retail's two copies are the group
   pattern `lq $v0,0x10($sp)` / `sq $v0,0x0($sp)`, and its zero is an MMI `por`
   (0x700014A9), not a `pcpyld` (0x70001389).  The float constant is $gp-relative
   (lwc1 $f0,0x1FEC($gp)), so the row also needs a -G8 unit. */

#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

extern float D_L00_001B0FDC __attribute__((sda));

extern void func_2EE5B0(void *a0, void *a1, void *a2);

extern void func_2EE108(void *a0, void *a1, void *a2);

void func_L00_0040B2C0(char *a0, char *a1)
{
    float local[4];
    float other[4];
    TI128 zero = 0;

    *(TI128 *)local = zero;
    local[0] = D_L00_001B0FDC;
    local[3] = 1.0f;
    *(TI128 *)other = *(TI128 *)local;
    func_2EE5B0(other, other, a0 + 0xC0);
    func_2EE108(a1, other, a0 + 0x10);
}
