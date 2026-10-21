#include "common.h"

/*
 * Follow the chain of entries of the same kind as `index`: the byte table at
 * +0x29C marks each entry 2 (another link), 1 (a final one) or something else
 * (not a chain). Walk it while the kind is 2, then, for a kind-1 entry, add the
 * entry's own value to the object's first word.
 */
extern s32 func_00115E28(void);

s32 func_00120A30(s32 index, u8 *object) {
    s8 *kind = (s8 *) (object + 0x29C);
    u64 *chain = (u64 *) (object + 0x18);

    for (;;) {
        if (kind[index] != 2) {
            break;
        }
        index = (s32) chain[index];
    }
    if (kind[index] == 1) {
        return *(s32 *) object + *(s32 *) (object + 0x18 + index * 8);
    }
    return func_00115E28();
}
/* Near miss: the body is exact, the allocator is not.
   Loop and both index computations come out right; the candidate is 132 bytes
   where retail is 136 because this cc1 keeps the `index` parameter in $a0 and
   loads the value byte into $v0, while retail copies `index` to $a2 at entry
   (daddu $a2,$a0,$zero) and uses $a0 as the scratch. Rewording the loop as
   do/while, while and for gives the same 132 bytes three times; the game
   compiler does copy the parameter to $a2 but reaches 136 with another order.
   Unblocking it needs a source shape that makes the parameter's pseudo
   conflict with $a0, which no wording tried here did. */

/* Wave 24 (worker 09) -- NEAR MISS: not reached inside the bound.
   The body is 34 instructions and reads no callee-saved register, so it is
   writable in plain C; the difficulty is the shape, not the ABI.  The retail
   disassembly (tools/check.py --diff, right column) is:

       addiu  $sp, $sp, -0x10
       daddu  $a2, $a0, $zero       $a2 = the first argument
       sd     $ra, 0x0($sp)
       addiu  $t0, $a1, 0x29C       $t0 = arg1 + 0x29C
       addu   $v1, $t0, $a2         $v1 = $t0 + arg0
       addiu  $v0, $zero, 2
       lb     $a0, 0x0($v1)         a byte at $v1
       bne    $a0, $v0, +0xC
       addu   $v0, $t0, $a2
       addiu  $a3, $a1, 0x18
       sll    $v0, $a2, 3
       addiu  $a0, $zero, 2
       addu   $v0, $a3, $v0
       ld     $v1, 0x0($v0)         a 64-bit load
       dsll32 $a2, $v1, 0           the 64->32 truncation, as a pair
       dsra32 $a2, $a2, 0
       addu   $v0, $t0, $a2
       lb     $v1, 0x0($v0)
       beql   $v1, $a0, -7          the loop: exit when the byte is 2
       sll    $v0, $a2, 3
       addiu  $a0, $zero, 1
       lb     $v1, 0x0($v0)
       bne    $v1, $a0, +6
       sll    $v1, $a2, 3
       lw     $a0, 0x0($a1)
       addu   $v1, $a1, $v1
       lw     $v0, 0x18($v1)
       b      +3                   an unconditional branch over the next two
       addu   $v0, $a0, $v0         (dead: the branch skips it)
       jal    func_115E28          (dead too)
       nop
       ld     $ra, 0x0($sp)
       jr     $ra
       addiu  $sp, $sp, 0x10

   The dsll32/dsra32 pair is the 64->32 truncation: it needs a named s64 local
   (as src/core/00120B38.c says: writing (int)*(s64 *)p folds the load into a
   32-bit lw, the local keeps retail's ld plus the pair).  The loop is the
   branch-likely shape: the byte test at the top, the increment of the index in
   the delay slot and the second test in the delay slot of the bne.  The last
   three instructions before the epilogue are dead in retail (the b skips the
   addu and the jal), so the source must have had a condition the compiler
   proved true and the branch became unconditional.

   Checked with: python3 tools/check.py func_00120A30 --diff
   Last line: func_00120A30: 0 of 1 places match (src/core/00120390.c) */
