/* Near miss from src/levels/20_yeedil/L20_00449178-g8.c: 388 bytes, retail 408.
   The attempt belongs in the -G8 unit: the body reaches D_L20_001B2444,
   D_L20_001B2448 and D_L20_001B244C through $gp.

   The two clamps are the retail's shape instruction for instruction: the
   pi/4 constant (0x3F490FDC) and its negation (0xBF490FDC), the
   `swc1` in the branch delay slots, the bc1f / b / bc1tl / bc1tl / bc1fl
   sequence and the two `mov.s $f0,$f20` (the function returns the float
   the second func_00282DF0 call gave - the caller compares it with 0.1f).
   The calls, their argument setup and the epilogue match too.

   Two differences:
     1. the 16-byte copies (the wall of this level, see
        func_L20_0044A838 and func_L20_00449FD0): the retail materialises
        both addresses (`lq $v0,0x0($s2) ; sq $v0,0x0($s3)` with $s2 =
        state+0x180 and $s3 = arg0+0x10 kept in callee-saved registers),
        this cc1 folds the offsets into the operands;
     2. the float comparisons: the retail emits the signalling forms
        `c.lt.s` and this cc1 the ordered forms `c.olt.s` for the same C
        (a > pi/4, a < -pi/4, v > pi/4, v < 0).  The operand order and
        the branch structure are the retail's, only the ordered flag
        differs - not measured further.

   Because the copies fold, this cc1 needs one callee-saved register less
   (the retail keeps the state+0x180 pointer in $s2), so the frame is 0x60
   where the retail's is 0x70. */

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef int TI128 __attribute__((mode(TI)));


extern float D_L20_001B2444 __attribute__((sda));

extern float D_L20_001B2448 __attribute__((sda));

extern float D_L20_001B244C __attribute__((sda));

extern float func_00282DF0(void *);

extern void func_002AAC80(void *, float, float, float, float);

extern void func_002AFDD8(void *, void *, void *, int);

extern void func_L07_00321D68(void *, void *);

float func_L20_0044A8F0(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);
    char *v = state + 0x180;
    char *src = arg0 + 0x10;
    float b0[4];
    float b1[4];
    float b2[4];
    float f;
    float a;

    func_00282CF0(b0, state + 0x190, state + 0x180);
    b2[0] = func_00282DF0(state + 0xF0);
    f = func_00282DF0(b0);
    func_002AAC80(b2, f, D_L20_001B2444 * 0.00027777778f,
                  D_L20_001B2444 * 0.00027777778f,
                  D_L20_001B2448 * 0.016666668f);
    func_00282F20(state + 0xF0, b0, b2[0]);
    *(TI128 *)src = *(TI128 *)v;
    func_L07_00321D68(arg0, state + 0xF0);
    *(TI128 *)v = *(TI128 *)src;
    func_002AFDD8(arg0, b1, state + 0xF0, 0);
    a = b1[1] * -D_L20_001B244C;
    *(float *)(state + 0x1A8) = a;
    *(float *)(state + 0x1AC) = b1[0] * D_L20_001B244C;
    if (a > 0.78539824f) {
        *(float *)(state + 0x1A8) = 0.78539824f;
    } else if (a < -0.78539824f) {
        *(float *)(state + 0x1A8) = -0.78539824f;
    }
    a = *(float *)(state + 0x1AC);
    if (a > 0.78539824f) {
        *(float *)(state + 0x1AC) = 0.78539824f;
    } else if (a < 0.0f) {
        *(float *)(state + 0x1AC) = 0.0f;
    }
    return f;
}

/* WAVE 3 (2026-10-20, worker 09, unit src/levels/20_yeedil/L20_00449178-g8.c).
   The attempt above is unchanged and is still the best one.  Measured
   size: 388 bytes against the retail's 408 - twenty bytes short.

   THE c.olt.s / c.lt.s RESIDUE IS NOT A DIFFERENCE.  The R5900's
   c.lt.s has a different bit pattern from the general MIPS one
   (opcodes/mips-opc.c: "The r5900 has a different bit pattern for the
   c.lt.s instruction"): c.lt.s assembles as 0x46000034 on this target,
   and 0x46000034 is the pattern the general MIPS calls c.olt.s.  The
   retail's word here is 0x46011834 (its listing prints "c.lt.s") and this
   cc1's is 0x460d6034 - both are & 0xffe007ff == 0x46000034, the same
   instruction.  rabbitizer prints "c.olt.s" for both sides of the
   tools/check.py diff, so the wave-2 note that read the retail's own
   listing against rabbitizer's output mistook a naming difference for a
   code difference.  There is no signalling compare to chase.

   What is left is the 16-byte copy: the retail materialises both
   addresses (addiu $s2, $s4, 0x180 for the source and $s3 for
   arg0+0x10) and keeps them in callee-saved registers across the calls,
   which is why its frame is 0x70 with five saved registers where this
   cc1's is 0x60 with four.  The mechanism (the CSE's find_best_addr cost
   tie) is written up in full in nonmatching/levels/func_L20_0044A838.c
   (wave 3). */

/* WAVE 4 (2026-10-21, worker 11, unit src/levels/20_yeedil/L20_00449178-g8.c).
   The attempt above is unchanged and is still the best one.  This wave
   measured what the wall really is and found the rule the retail follows.

   1. THE RULE (this replaces the common file's "used more than once"
      rule, which does not hold).  The retail materialises EVERY 128-bit
      address into a register and uses a ZERO displacement:
          addiu $a0, $s0, 0x10 ; lq $v0, 0x0($v1) ; sq $v0, 0x0($a0)
      Plain C reproduces that when the address is
        - a PLAIN POINTER (a parameter, a loaded pointer, a pointer
          variable that holds a pointer).  The matched witness is
          src/levels/shared/L00_002D3798.c: `*out = *in;` with TI-mode
          pointer parameters gives the retail's `lq $v0,0($s2)`;
        - a SYMBOL.  The matched witness is src/game/002C1EF0-rc2.c:
          `TI v = D_001BAFA0;` gives the retail's
          `lui $v0,%hi(S) ; addiu $v0,$v0,%lo(S) ; lq $v1,0($v0)`;
        - a STACK SLOT.  The matched witness is this level's
          func_L20_0043F510, whose `sq $v0,0x0($sp)` is the frame pointer
          (find_best_addr never touches a frame-pointer address).
      It does NOT reproduce it when the address is base+const with a
      runtime base.  MEASURED over the whole game (every catalogue row,
      every level): the retail's shape - an addiu whose destination is
      the base of a zero-displacement lq/sq - occurs 43,255 times, 2,210
      of them in level 20, and in NONE of the 3,855 functions that are
      already C in src/.  => The retail's copy is the original source's
      inline-asm copy macro ("lq $v0,0(%1); sq $v0,0(%0)" with "r"
      operands - which is also the order the retail's two addiu's are in:
      the destination's address first, then the source's), and src/ does
      not allow inline asm.  The level-2 record
      nonmatching/levels/func_L02_003F52B0.c reached the same conclusion
      from the other side.

   2. WHERE THE FOLD HAPPENS, exactly (measured with `cc1 -da`):
      - the front end builds the copy as
          (set (reg/v:SI 86) (plus:SI (reg/v:SI 84) (const_int 16)))
          (set (reg:TI 88) (mem:TI (reg/v:SI 87) 0))
          (set (mem:TI (reg/v:SI 86) 0) (reg:TI 88))
        so the MEM's address IS a pseudo; the .cse dump already shows
        (mem:TI (plus:SI (reg/v:SI 84) (const_int 16)) 0).
      - the CSE's find_best_addr() (gcc/cse.c:2690) substitutes the class
        member that ties on the address cost: ADDRESS_COST(REG) = 1
        (config/mips/mips.h:3826) and mips_address_cost(plus(reg, const))
        = 1 (config/mips/mips.c:2660; SMALL_INT is [-32768, 32767],
        mips.h:2099) - a TIE, and the tie-break
        ((p->cost + 1) >> 1 > best_rtx_cost) favours the plus, whose
        COST is rtx_cost(plus,SET)*2 against the pseudo's 1.
      - the reload then sees (mem:TI (plus (reg) const) 0), which IS a
        legitimate TImode address (GO_IF_LEGITIMATE_ADDRESS,
        config/mips/mips.h:3055: the offset in [-32768, 32752]), so
        find_reloads_address_1 (gcc/reload.c:4632) returns without
        reloading and the offset becomes the displacement.
      => The retail's shape is EXACTLY what the reload produces when the
         MEM's address is still the pseudo.  Only the CSE's cost tie
         takes it away.
      - find_best_addr() returns EARLY, without touching the address, for
        an address based on the frame pointer (gcc/cse.c:2716) and for a
        constant address (CONSTANT_ADDRESS_P) - that is the stack and the
        symbol escape above.

   3. SPELLINGS MEASURED THIS WAVE, ALL FOLD (the mem's address stays a
      plus and the reload folds it):
      - the pointer as a C variable, computed before the if-block or
        inside it, used once or twice;
      - `p = p + const` in place, with a known or an unknown base: the
        CSE's canon_reg rewrites plus(p,16) into plus(base,16) when it
        knows the base, and the invalidation does not take the plus out
        of the class;
      - the pointer carried by a loop: the address IS materialised, but
        at the pointer's definition site, before the loop (measured
        `beq $v0,$0,$L ; addu $4,$4,16 ; ... ; sq $v2,0($4)`);
      - the pointer computed in one basic block and used in another: the
        copy is hoisted into the branch's delay slot, back into the block
        that holds the address;
      - do { ... } while (0);
      - a struct with a TI-mode member (the copy of two plain pointers
        gives the retail's zero displacement; base+const still folds);
      - the volatile pointer object and the out-of-range offset, both
        measured before, both change the shape.

   4. THE FLAG.  -fno-schedule-insns was measured for this body and it
      makes it WORSE (404 bytes with the flag against 396 without), so
      the default flags stand and no cflags.txt row is needed.  The body
      is 396 bytes against the retail's 408 and the difference is the
      two copies and the register allocation they cost: the retail keeps
      the state+0x180 pointer in $s2 and the arg0+0x10 pointer in $s3
      (`lq $v1,0x0($s2) ; sq $v1,0x0($s3) ; lq $v0,0x0($s3) ;
      sq $v0,0x0($s2)`), this cc1 folds them (`lq $v0,0x180($s2) ;
      sq $v0,0x10($s0)`) and needs one saved register less; the frame is
      0x60 here and 0x70 in the retail.

/* WAVE 5 (2026-10-21, worker 11, unit src/levels/20_yeedil/L20_00449178-g8.c).
   The attempt above is unchanged and is still the best one.  This wave
   settled the mechanism, settled the disputed point of wave 4, and
   measured that the wall is a SOURCE-level macro, not a compiler rule.

   1. THE MECHANISM, SETTLED.  The two stories of the last wave are both
      right, about two different steps, and the order matters.

      (a) For the direct spelling `*(TI128 *)(base + off)' the CSE is NOT
          involved.  The front end builds the address as a PLUS EXPRESSION
          (measured with `cc1 -da', the .rtl dump):
              (set (mem:TI (plus:SI (reg/v:SI 84) (const_int 16)) 0)
                    (reg:TI 86))
          and the RELOAD folds the constant into the displacement:
          GO_IF_LEGITIMATE_ADDRESS (config/mips/mips.h) accepts
          plus(reg, const_int) as a TImode address while
              INTVAL(const) >= -32768 && INTVAL(const) + 16 - 1 <= 32767,
          so strict_memory_address_p() (gcc/reload.c) finds the address
          legal, does not reload it into a register, and the printer prints
          the constant as the displacement.  DECISIVE MEASUREMENT: the
          offset 32752 folds (`sq $2,32752($4)') and 32753, one past the
          TImode range, makes the reload materialise the address
          (`addu $4,$4,32753 ; sq $2,0($4)').

      (b) For the pointer-VARIABLE spelling (`char *p = base + off;'
          `*(TI128 *)p = v;') the front end builds the address as the
          PSEUDO p (the .rtl dump: `(set (mem:TI (reg/v:SI 84) 0) ...)'),
          and the CSE's find_best_addr() (gcc/cse.c) substitutes the class
          member plus(base, off), because mips_address_cost()
          (config/mips/mips.c) gives "register plus a small constant" the
          cost 1 and ADDRESS_COST(REG) is 1 too - a tie, and the tie-break
          (the rtx cost, gcc/cse.c) goes to the plus.  The reload then
          folds it as in (a).

      So the fold is in the RELOAD in both spellings; the CSE only decides
      whether the reload ever sees a plus.  No flag changes it (measured on
      the same body: -fno-gcse, -fno-expensive-optimizations,
      -fno-schedule-insns, -mno-split-addresses, -g and -fno-strength-reduce
      all give the same folded lq/sq).

   2. THE DISPUTED POINT, SETTLED: a pointer LOADED FROM MEMORY SURVIVES.
      `char *p = *(char **)q; *(TI128 *)p = v;' gives
          lw $3,0($5) ; lq $2,0($3) ; sq $2,0($3)
      - the address is a register and the displacement is zero.  But it
      does NOT survive an offset added afterwards: `*(TI128 *)(p + 0x10)'
      gives `sq $2,16($3)', folded.  The escape only applies when the
      offset is already inside the loaded value.

   3. THE WALL IS A SOURCE-LEVEL MACRO, NOT A COMPILER RULE.  Measured in
      level 20: of the adjacent lq/sq pairs (a 16-byte copy), 2,421
      materialise BOTH addresses (the addiu and a zero displacement) and
      28 do not.  The 28 that fold are the field-by-field copies of ONE
      struct - the two addresses have the same relative layout (the
      matched witness below copies 0xC0/0xC0, 0xD0/0xD0 and 0xE0/0xE0) -
      while the 2,421 that materialise are copies of a single value.
      THE PROJECT HAS EXACTLY THAT MATCHED: func_L00_00395240
      (src/levels/shared/L00_0038F178.c) - `*(TI128 *)(object + 0xC0) =
      *(TI128 *)(p + 0xC0);' and two more - matches in 27 of 27 places,
      and the retail's bytes are the FOLDED
          lq $v0,0xC0($a0) ; sq $v0,0xC0($s0)
      => Plain C folds, and the retail folds too where the source is plain
      C.  The materialised places are the game's own copy macro - the PS2
      idiom `lq $v0,0(%1); sq $v0,0(%0)' with "r" operands, which forces
      both addresses into registers and sets the DESTINATION's address up
      first (the order the retail shows).  src/ does not allow inline asm
      (AGENTS.md), so those bodies are not reachable from C.
      => The wave-4 "matched witnesses" (L00_002D3798, 002C1EF0-rc2,
      func_L20_0043F510) are NOT evidence for an escape: in all three the
      address is a plain register, a symbol or a stack slot, where plain C
      and the macro agree.  The witness for the FOLD is func_L00_00395240.

   3b. HOW MANY OF THE MATERIALISED COPIES ARE REACHABLE AT ALL.  Of the
       2,421 adjacent materialised copies in level 20, 1,640 have a
       base+const address (the macro form, not reachable from plain C) and
       781 have plain-register addresses - a parameter, a pointer loaded
       from memory, or a callee-saved register that already holds the
       pointer (the plain-C form, reachable, and the shape the wave-4
       witnesses have).  So the "43,255 places game-wide" of the last
       wave counts the base+const shape alone; the plain-register copies
       are a separate, matchable population, and the 28 struct copies are
       a third.

   4. THE ESCAPES, all re-measured, and what each one costs:
        - a plain pointer (a parameter): the zero displacement.  FREE,
          but only when the address has no offset.
        - a pointer loaded from memory: the zero displacement.  FREE, and
          only when the offset is inside the loaded value.
        - a call result: the zero displacement.  FREE, same condition.
        - a symbol: materialised as lui/addiu (a constant address is
          illegitimate for TImode on the R5900, GO_IF_LEGITIMATE_ADDRESS).
          The retail's own form for D_00189E20 + 0xD0 is
          `lui %hi(D) ; addiu %lo(D) ; addiu 0xD0 ; lq $v0,0($v1)', which
          the C spelling cannot give (the front end folds the constant
          into the symbol's address).
        - a stack slot at offset 0: `sq $v0,0($sp)'.  FREE, no offset.
        - a volatile pointer object: the right shape, at the price of a
          sw/lw round trip and a frame.
        - an offset outside [-32768, 32752]: the right shape, with the
          wrong immediate (`addu $4,$4,32753 ; sq $2,0($4)').
        - NEW: a 64-bit address keeps the copy in a register (`sq $3,0($2)')
          but costs dsll/dsrl/daddu/dsll/dsra where the retail has one
          addiu.
        - NEW: `plus(const_int, reg)' (the constant on the left) is NOT a
          legitimate TImode address in the reload and would be
          materialised - but the front end canonicalises the constant to
          the right, so it cannot be spelled in C (measured: `16 +
          (u32)arg0' gives the same folded `sq $2,16($4)').
      => NONE of them applies to base+const with a runtime base, which is
      what these bodies need.

   5. THIS BODY.  The retail's two copies are
          lq $v0, 0x0($s2) ; sq $v0, 0x0($s3)
          lq $v0, 0x0($s3) ; sq $v0, 0x0($s2)
      with $s2 = state+0x180 and $s3 = arg0+0x10, both kept in
      callee-saved registers across the calls - the macro's addresses,
      materialised once and live across the calls.  Everything else in the
      body is the retail instruction: the two clamps (pi/4 = 0x3F490FDC and
      its negation 0xBF490FDC), the swc1 in the branch delay slots, the
      bc1f / b / bc1tl / bc1tl / bc1fl sequence, the two `mov.s $f0,$f20'
      and the calls.  (The wave-3 note about the ordered c.olt.s against
      the signalling c.lt.s is not a difference: on the R5900 c.lt.s
      assembles to the word the general MIPS calls c.olt.s.)  The wave-4
      attempt stands; the body cannot be matched from C.
