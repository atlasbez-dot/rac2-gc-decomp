/* Near miss from src/levels/20_yeedil/L20_00449178-g8.c: 452 bytes, retail 480.
   The attempt belongs in the -G8 unit: the body reaches D_L20_001B2418 through
   $gp and D_00189E20 absolutely (nosda).

   Everything but the two 16-byte copies is the retail instruction: the
   prologue, the two branches on arg0[0x20], the func_002A7750 /
   func_002A9640 / func_002A96A0 / func_002AA2E8 / func_002B3BA8 calls with
   their argument setup, the bc1fl on the state's float, the 0x12F2/0x12EF
   test, the state stores and the epilogue all match.

   The copies are the wall (the same one as func_L20_0044A838 and
   func_L20_00449FD0 in this level): the retail materialises both addresses
       addiu $a1, $s1, 0x180 ; addiu $a0, $s0, 0x10 ;
       lq $v0, 0x0($a0) ; sq $v0, 0x0($a1)
   while this cc1 folds the constant offsets into the operands
       lq $v0, 0x10($s0) ; sq $v0, 0x180($s1)
   (8 bytes short for that copy).  The second copy, out of D_00189E20, is
   the same: the retail keeps the symbol in a register and adds 0x2290 and
   0xD0 to it, this cc1 folds 0xD0 into the lq.  Spelling tried for the
   symbol: `u32 *base = (u32 *)D_00189E20;` with `base[0x8A4]` and
   `*(TI128 *)((char *)base + 0xD0)` - that puts the symbol in a register
   and makes the load match the retail exactly, but the copy's offset
   still folds.

   With the copies unfolded the register allocation follows the retail's:
   the retail spends $a0/$a1 on the copy's addresses, so it keeps the
   flags in $v1 (`lhu $v1,0x34($s0)`) and the -1 in $v0, while this cc1
   (with $a0/$a1 free) keeps the flags in $v0 and the -1 in $a0.

   Measured this wave (2026-10-20): the fold is in the address printer -
   the TI access keeps the plus (GO_IF_LEGITIMATE_ADDRESS accepts
   plus(reg, const_int) for TImode when offset + 16 - 1 <= 32767) and the
   offset is then folded into the lq/sq.  Spellings tried and measured: a
   TI128 pointer variable, a char * variable, a u32/u64 address variable, a
   struct with a TI128 member, a union with a float array, the pointer used
   twice, the pointer live across a call, the pointer taken from a struct
   field, the offsets applied one at a time, a 32-bit (int) address, a
   64-bit address (keeps the copy in a register but adds a dsll/dsra pair
   and uses daddu, not addiu), __builtin_memcpy(...,16), and the per-file
   flags -g, -mno-split-addresses, -fno-schedule-insns, -fno-schedule-insns2
   (none of them changes the fold).  A pointer that is a plain parameter or
   a plain load keeps the retail's shape, so the wall is exactly the
   source-level constant offset. */

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef int TI128 __attribute__((mode(TI)));


/* func_L20_0044A658 reaches D_L20_001B2418 through $gp and D_00189E20 absolutely,
   so it lives in this -G8 unit. */

extern float D_L20_001B2418 __attribute__((sda));

extern u32 D_00189E20[] __attribute__((nosda));

extern void func_002A7750(char *, int, int);

extern void *func_002A9640(char *, int, int);

extern float func_002A96A0(char *, char *);


extern void func_002B3BA8(char *, u32, int, int, float, float);

extern void func_L20_0044AB68(char *);

void func_L20_0044A658(char *arg0) {
    char *state;
    char *p;
    u32 *q;
    short t;
    float f;

    state = *(char **)(arg0 + 0x68);
    if (*(u8 *)(arg0 + 0x20) == 0) {
        func_002A7750(arg0, 1, -1);
        *(u16 *)(arg0 + 0x34) = (*(u16 *)(arg0 + 0x34) | 0x41) & 0xEFFF;
        *(int *)(arg0 + 0x98) = 0;
        *(TI128 *)(state + 0x180) = *(TI128 *)(arg0 + 0x10);
        *(float *)(arg0 + 0x2C) =
            *(float *)(*(u32 *)(arg0 + 0x24) + 0x24) * D_L20_001B2418;
        *(int *)(state + 0x1B8) = -1;
    }
    if (*(u8 *)(arg0 + 0x20) == 1) {
        return;
    }
    p = func_002A9640(arg0, 0x10000, 0);
    if (p != 0) {
        q = *(u32 **)(p + 0x20);
        if (q != 0) {
            t = *(short *)((char *)q + 0xAA);
            if (t == 0x12F2 || t == 0x12EF) {
                p = 0;
            }
        }
    }
    f = func_002A96A0(arg0, p);
    func_002AA2E8((float *)(state + 0x20), 0.0f, f);
    *(u8 *)(arg0 + 0xA8) = 0xFF;
    if (*(float *)(state + 0x20) == 0.0f) {
        func_L20_0044AB68(arg0);
        *(u8 *)(arg0 + 0xA8) = 0xFF;
        func_002A7750(arg0, 1, -1);
        *(int *)(arg0 + 0x98) = 0;
        *(u16 *)(arg0 + 0x34) = (*(u16 *)(arg0 + 0x34) | 0x41) & 0xEFFF;
    }
    if (*(u8 *)(arg0 + 0x20) == 5) {
        return;
    }
    p = *(char **)(state + 0x1B0);
    if (p != 0) {
        *(u32 *)(state + 0x150) = (u32)p;
        *(TI128 *)(state + 0x140) = *(TI128 *)(p + 0x10);
        *(float *)(state + 0x148) = *(float *)(state + 0x148) + 0.5f;
        return;
    }
    func_002B3BA8(arg0, *(u32 *)(state + 0x160), 0, 0, 1024.0f, 37.0f);
    if (*(u32 *)(state + 0x150) != 0) {
        return;
    }
    {
        u32 *base = (u32 *)D_00189E20;
        *(u32 *)(state + 0x150) = base[0x8A4];
        *(TI128 *)(state + 0x140) = *(TI128 *)((char *)base + 0xD0);
    }
}

/* WAVE 3 (2026-10-20, worker 09, unit src/levels/20_yeedil/L20_00449178-g8.c).
   The attempt above is unchanged and is still the best one.  Measured
   size: 452 bytes against the retail's 480 - twenty-eight bytes short.
   The retail materialises BOTH addresses of the copy
       addiu $a1, $s1, 0x180 ; addiu $a0, $s0, 0x10 ;
       lq $v0, 0x0($a0) ; sq $v0, 0x0($a1)
   where this cc1 folds them into the operands
       lq $v0, 0x10($s0) ; sq $v0, 0x180($s1)
   and the same for the second copy out of D_00189E20.  The mechanism (the
   CSE's find_best_addr cost tie) is written up in full in
   nonmatching/levels/func_L20_0044A838.c (wave 3); only a SYMBOL base
   keeps the address in a register, and the symbol here is reached through
   a variable, so the offset folds.

   With the copies unfolded the register allocation follows the retail's
   (the retail spends $a0/$a1 on the copy's addresses, so it keeps the
   flags in $v1 and the -1 in $v0), which is why the flags move here. */

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
        src/levels/20_yeedil/L20_0044A658-g8.c
          -O2 -G8 -ffunction-sections -fno-schedule-insns
      the body is 456 bytes against the retail's 480 (464 without the
      flag) and the difference is the three copies and the register
      allocation they cost: the retail materialises every address
      (`addiu $a1,$s1,0x180 ; lq $v0,0x0($a0) ; sq $v0,0x0($a1)`
      and, for the copy out of D_00189E20, `lui $v1,%hi(D) ;
      addiu $v1,$v1,%lo(D) ; addiu $v1,$v1,0xD0 ; lq $v0,0x0($v1)`),
      this cc1 folds them all; the frame is 0x20 here and 0x30 in the
      retail.

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

   5. THIS BODY.  All THREE of the retail's copies are materialised:
          addiu $a1, $s1, 0x180 ; addiu $a0, $s0, 0x10 ;
          lq $v0, 0x0($a0) ; sq $v0, 0x0($a1)
          addiu $a0, $v0, 0x10 ; lq $v0, 0x0($a0) ; sq $v0, 0x0($v1)
          addiu $v1, $v1, 0xD0 ; lq $v0, 0x0($v1) ; sq $v0, 0x0($a1)
      The third one is the SYMBOL case: D_00189E20 + 0xD0.  The C spelling
      `*(TI128 *)((char *)base + 0xD0)' with `base = (u32 *)D_00189E20'
      gives the materialised
          lui %hi(D) ; addiu %lo(D) ; lq $v0, 0xD0($v1)
      - the symbol's address in a register, but the constant folded into
      the lq, where the retail adds 0xD0 to the register.  So even the
      symbol case needs the macro.  The second copy's source is a pointer
      LOADED FROM MEMORY plus 0x10 - the escape of point 2 does not reach
      through an offset.  The wave-4 attempt stands; the body cannot be
      matched from C.
