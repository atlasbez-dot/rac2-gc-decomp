/* Near miss from src/levels/20_yeedil/L20_00449178-g8.c: 592 bytes, retail 624.
   The attempt belongs in the -G8 unit: the body reaches D_001A79F0 through
   $gp and D_0019B2E8 / D_00189EA0 absolutely (nosda).

   The state machine is the retail's shape: the switch on arg0[0x20] with
   its two branch-likely tests, the two table lookups
   (D_0019B2E8 + arg0[0xB0] + D_001A79F0 * 16, the `sll` by 4 and the
   0x80 mask), the func_0033E7F8 / func_0033E808 calls, the pi/4 clamp of
   the case 2, the state stores and the epilogue all match.

   The difference is the four 16-byte copies (the wall of this level, see
   func_L20_0044A838 and func_L20_00449FD0): the retail materialises both
   addresses of every copy into registers (`lq $v0,0x0($a0) ;
   sq $v0,0x0($sp)` with $a0 = arg0+0x10 computed by an addiu) and this
   cc1 folds the constant offsets into the operands.  That is 32 bytes
   short, and it also shifts the register allocation (the retail keeps the
   state, the state+0x180 pointer and arg0+0x10 in callee-saved
   registers, so its frame is 0x60 where this cc1's is 0x50). */

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef int TI128 __attribute__((mode(TI)));


extern s32 D_001A79F0 __attribute__((sda));

extern u8 D_0019B2E8[] __attribute__((nosda));

extern u32 D_00189EA0[] __attribute__((nosda));

extern void *func_0033E808(u32 *);

extern int func_0033E7F8(char *);

extern void func_00336648(char *, char *, char *, char *);

void func_L20_00449338(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);
    TI128 v0, v1, v2;
    u32 a1;
    float f0, f1, f2, f3;

    v0 = *(TI128 *)(arg0 + 0x10);
    v1 = *(TI128 *)(arg0 + 0xF0);
    switch (*(u8 *)(arg0 + 0x20)) {
    case 0:
        *(TI128 *)(state + 0x60) = v0;
        *(TI128 *)(state + 0x70) = v1;
        a1 = *(u32 *)(state + 0x88);
        if (*(u8 *)(arg0 + 0xB0) != 0xFF) {
            if (*(u32 *)(state + 0x8C) != 0) {
                if (*(u8 *)((char *)D_0019B2E8 + *(u8 *)(arg0 + 0xB0) +
                            D_001A79F0 * 16) & 0x80) {
                    goto l2c;
                }
            } else {
                a1 = *(u32 *)(state + 0x88);
            }
        }
        if (a1 == (u32)-1) {
            func_002A7750(arg0, 1, -1);
            break;
        }
        if (func_0033E808(D_00189EA0) == 0) {
            func_002A7750(arg0, 1, -1);
            break;
        }
    l2c:
        f0 = *(float *)(state + 0x68);
        f1 = *(float *)(state + 0x80);
        *(u16 *)(arg0 + 0x34) |= 2;
        *(float *)(arg0 + 0x18) = f0 + f1;
        func_002A7750(arg0, 3, -1);
        break;
    case 1:
        if (*(u8 *)(arg0 + 0xBC) != 0) {
            func_002A7750(arg0, 2, -1);
            break;
        }
        if (func_0033E7F8(arg0) != 0) {
            func_002A7750(arg0, 2, -1);
            break;
        }
        a1 = *(u32 *)(state + 0x88);
        if (*(u8 *)(arg0 + 0xB0) != 0xFF) {
            if (*(u32 *)(state + 0x8C) != 0) {
                if (*(u8 *)((char *)D_0019B2E8 + *(u8 *)(arg0 + 0xB0) +
                            D_001A79F0 * 16) & 0x80) {
                    func_002A7750(arg0, 2, -1);
                    break;
                }
            } else {
                a1 = *(u32 *)(state + 0x88);
            }
        }
        if (a1 == (u32)-1) {
            break;
        }
        if (func_0033E808(D_00189EA0) != 0) {
            func_002A7750(arg0, 2, -1);
        }
        break;
    case 2:
        f0 = *(float *)(state + 0x84);
        f3 = 1.0f;
        f1 = *(float *)(state + 0x90);
        f0 = f3 / f0;
        f1 = f1 + f0;
        *(float *)(state + 0x90) = f1;
        if (f1 <= f3) {
            *(float *)(state + 0x90) = f3;
        }
        f1 = *(float *)(state + 0x90);
        f2 = *(float *)(state + 0x80);
        f0 = *(float *)(state + 0x68);
        f1 = f1 * f2;
        f0 = f0 + f1;
        *(float *)(arg0 + 0x18) = f0;
        if (*(float *)(state + 0x90) <= f3) {
            func_002A7750(arg0, 3, -1);
        }
        break;
    }
    if (*(u8 *)(arg0 + 0x20) < 3) {
        func_00282CF0(&v2, arg0 + 0x10, &v0);
        func_00336648(state + 0x20, &v2, &v1, arg0 + 0xF0);
    }
}

/* WAVE 3 (2026-10-20, worker 09, unit src/levels/20_yeedil/L20_00449178-g8.c).
   The attempt above is unchanged and is still the best one.  Measured
   size: 592 bytes against the retail's 624 - thirty-two bytes short,
   which is exactly the retail's four copies, two instructions each:
       addiu $a0, $s1, 0x10 ; ... ; lq $v0, 0x0($a0) ; sq $v0, 0x0($sp)
   where this cc1 folds the offsets into the operands.  The mechanism (the
   CSE's find_best_addr cost tie) is written up in full in
   nonmatching/levels/func_L20_0044A838.c (wave 3).

   The frame difference (0x50 here, 0x60 in the retail) and the extra
   callee-saved registers follow from the copies: the retail keeps the
   state pointer, the state+0x180 pointer and arg0+0x10 in registers. */

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

   4. THE FLAG.  This body wants -fno-schedule-insns, and it needs a unit
      of its own (the flag breaks the two bodies already matched in the
      shared unit).  Measured with a unit of its own
        src/levels/20_yeedil/L20_00449338-g8.c
          -O2 -G8 -ffunction-sections -fno-schedule-insns
      the body is 584 bytes against the retail's 624 (592 without the
      flag) and the difference is the four copies and the register
      allocation they cost: the retail materialises every address
      (`addiu $a0,$s1,0x10 ; lq $v0,0x0($a0) ; sq $v0,0x0($sp) ;
      addiu $a1,$s1,0xF0 ; addiu $v1,$sp,0x10 ; lq $v0,0x0($a1) ;
      sq $v0,0x0($v1)`), this cc1 folds them; the frame is 0x50 here and
      0x60 in the retail and the saved registers come out in the other
      order.

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

   5. THIS BODY.  All FOUR of the retail's copies are materialised:
          addiu $a0, $s1, 0x10 ; lq $v0, 0x0($a0) ; sq $v0, 0x0($sp)
          addiu $a1, $s1, 0xF0 ; addiu $v1, $sp, 0x10 ;
          lq $v0, 0x0($a1) ; sq $v0, 0x0($v1)
          addiu $v1, $s2, 0x60 ; lq $v0, 0x0($a0) ; sq $v0, 0x0($v1)
          addiu $a0, $s2, 0x70 ; lq $v0, 0x0($a1) ; sq $v0, 0x0($a0)
      - the stack slots are materialised too (the retail's `addiu $v1,$sp,
      0x10' and `sq $v0, 0x0($sp)'), which the frame-pointer path of the
      reload does not give.  The state machine is the retail's shape: the
      switch on arg0[0x20] with its two branch-likely tests, the two table
      lookups (D_0019B2E8 + arg0[0xB0] + D_001A79F0 * 16), the
      func_0033E7F8 / func_0033E808 calls, the pi/4 clamp of the case 2, the
      state stores and the epilogue all match.  The wave-4 attempt stands;
      the body cannot be matched from C.
