/* func_L11_00456378 -- draft w17 (wave 6, file src/levels/11_joba/L11_00453358.c)
 * BEST ATTEMPT (log2): 11_joba: 184 bytes, expected 192 -- register allocation
 * CONFORMING to the retail (p->$s1, q->$s0) and the whole body identical EXCEPT the branch
 * form (mine `beq $v0,$s2` + nop, retail `bnel $v0,$s2` with a useful delay slot) and the
 * "then" block placed on the wrong side. Variant 1 call = 160 bytes, variant 2 calls = 200 bytes (2 jal).
 * Retail = 192 bytes with A SINGLE jal shared by the two paths.
 */

/* Near miss: 188 against 192 bytes, four words short.  Level 11, 0x00456378.

   The shape is retail's: the prologue, the `bnel` with the 0xB8 load in its delay
   slot, the two duplicated argument setups and the single shared call to
   func_002B3BA8 all come out as the retail has them, and the two
   callee-saved registers land where the retail puts them ($s1 = the object,
   $s0 = the state).

   What still differs:

   1. the early exit.  Retail does `b .L0045641C` with the `sw $zero,0x240($s0)`
      in the delay slot and the `sh $zero,0x256($s0)` at the shared label, so
      one store serves both exits.  This candidate puts the `sh` in the early
      block instead and jumps past the shared label.

   2. the tail.  Retail keeps the call's result in $v0 and loads 0x220 into
      $v1 (`lw $v1,0x220($s0)` ; `sh $v0,0x254($s0)` ; `sw $v1,0x240($s0)`).
      This candidate copies the result ($v0) into $v1 first and loads 0x220
      into $v0, so it needs the extra `daddu $v1,$v0,$zero`.

   3. the order inside the second branch's setup (the `sh $s2,0x256($s0)`
      and the `lw $a1,0x24C($s0)` are swapped against retail).

   Measured while here (all with the file's own flags, -O2 -G0):

   - the callee-saved allocation follows the number of calls the object
     crosses at allocation time, not the declaration order.  With one call to
     func_002B3BA8 in the source the object gets $s1 (retail's) and the
     state $s0; with the call written in both arms it gets $s0 and the state
     $s1, whatever the order of the declarations.  The `if (v == 1) {...}
     else {...}` shape (the one that gives retail's `bnel`) needs the call in
     both arms, and the shape that gives retail's allocation needs one call:
     the two cannot be had at once from one source.

   - the `bnel` + delay-slot load comes from the inverted comparison
     (`if (v == 1) {...} else {...}`); the plain `if (v != 1) {...}` gives
     `beq` with a `nop` delay slot.

   - the float constant 100.0f must be written twice (once per arm) for the
     `lui $at,0x42C8 ; mtc1 $at,$f12` form; written once it comes out as
     `li.s $f12,1e2`.

   - `func_002B3BA8` is func_002B3BA8 in the catalogue (level 11, 0x0033C800)
     and `f_00441868` is func_L11_00441868. */


   One more shape measured, worth keeping: writing the result of
   func_002B3BA8 straight into 0x254 in both arms (no `r` variable) and
   leaving the tail to the shared block gives retail's prologue AND
   retail's first exit (`b` with the `sw $zero,0x240($s0)` in the delay
   slot, the `sh $zero,0x256($s0)` at the label the two exits share), but
   only 180 bytes: the argument setup is split across the join and the
   tail keeps the load of 0x220 in $v0, where the retail has it in $v1
   with the result left in $v0.  The `r` variable that gives the retail's
   tail order costs the allocation, and the shape that keeps the
   allocation costs the tail order.

#include "common.h"

extern int func_L11_00441868(char *p, int id);
extern int func_002B3BA8(void *a0, int a1, int a2, int a3, float f12, float f13);

void func_L11_00456378(char *p)
{
    char *s1 = p;
    char *s0 = *(char **)(s1 + 0x68);
    s32 w;
    s16 v;
    s32 r;

    if (*(u8 *)(s1 + 0x20) < 4) {
        *(s32 *)(s0 + 0x240) = 0;
        *(u16 *)(s0 + 0x256) = 0;
        return;
    }
    v = *(s16 *)(s0 + 0x256);
    if (v == 1) {
        r = func_002B3BA8(s1, *(s32 *)(s0 + 0x24C), 0, 0, 100.0f, 100.0f);
    } else {
        if (func_L11_00441868(*(char **)(s1 + 0xB8), *(s16 *)(s1 + 0xAA)) == 0)
            goto reset;
        *(u16 *)(s0 + 0x256) = 1;
        r = func_002B3BA8(s1, *(s32 *)(s0 + 0x24C), 0, 0, 100.0f, 100.0f);
    }
    w = *(s32 *)(s0 + 0x220);
    *(u16 *)(s0 + 0x254) = r;
    *(s32 *)(s0 + 0x240) = w;
    return;
reset:
    *(u16 *)(s0 + 0x256) = 0;
}
