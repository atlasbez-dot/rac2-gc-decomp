#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

extern void func_00282CC0(char *, char *, char *);

extern void func_002A8C00(char *, int, int, void *, float);

extern int func_002761F8(void *, void *, int, int, void *);

extern int func_00282948(void *);

extern void func_002E5DA0(int, int, void *, int);

extern void func_L00_002E6EF8(void *, int);

extern void func_L20_0039C5D0(char *);

extern void func_L20_0039C8C8(char *, int, int);

extern void func_L20_0039CC10(void);

extern void func_0029F338(int);

extern char D_L20_001C0420[];

/* Near miss from src/levels/20_yeedil/L20_0039C448.c: 248 bytes; 248-byte candidate; 0/1.
    (Replaces an earlier draft from commit adcbd51, which used the inline-assembly `qcopy`
    helper that AGENTS.md's "Plain C" rule forbids; that draft is in that commit.)
    The whole body matches - the frame (0x60), the call sequence, the branch, the local buffer
    and the register allocation - except for two instructions:
      - the 128-bit load: retail keeps the source pointer in $s0 and loads from it
        (`addiu $s0,$s2,0x10; lq $v0,0($s0)`) while this cc1 folds the constant offset back
        into the load (`lq $v0,0x10($s2)`).  The store side is fine (a plain register address
        needs no offset).  Measured again in this wave with about twenty spellings: a TI128
        pointer variable, a struct member, an array index, a volatile load, two C names for the
        same pointer, a pointer used twice and a pointer kept across a call - all fold the
        offset.  A `short` truncation keeps the address in a register but costs `sll`/`sra`.
      - the order of the two saves: retail emits `sd $s0,0x30($sp); sd $s2,0x40($sp);
        sd $s1,0x38($sp)`, this cc1 `sd $s0,0x30($sp); sd $s1,0x38($sp); sd $s2,0x40($sp)`
        (the "the order of the two save registers sometimes rotates" wall).
    Every callee name in the draft was checked against the level-20 catalogue and is right. */
void func_L20_0039C448(char *arg0) {
    char *s0 = arg0 + 0x10;
    char *s3 = *(char **)(arg0 + 0x68);
    char *s1;
    char buf[0x30];

    *(TI128 *)s3 = *(TI128 *)s0;
    s1 = s3 + 0x10;
    func_00282CC0(s0, s0, s1);
    func_002A8C00(buf, (int)arg0, 0x10001, s1, *(float *)(s3 + 0x2C));
    if (func_002761F8(s3, s0, 0, *(int *)(arg0 + 0xB8), buf) != 0
        || func_00282948(s3 + 0x20) != 0) {
        func_L20_0039C8C8(D_L20_001C0420, 0x14, 1);
        func_002E5DA0(2, 0, arg0, 0x12EF);
        func_0029F338((int)arg0);
    } else {
        func_L20_0039C5D0(arg0);
        func_L00_002E6EF8(func_L20_0039CC10, (int)arg0);
    }
}

/* ------------------------------------------------------------------
   Second attempt (worker 07, level-20 wave of 2026-10-20).
   The attempt above still differs from the retail in two places; this
   note records what the second attempt changed and what was measured.

   The second attempt keeps the 32-bit pointer arithmetic of the retail
   (`char *s0 = (char *)((s32)arg0 + 0x10);` gives the retail's `addiu
   $s0,$s2,0x10` instead of a 64-bit `daddu`) and reorders nothing else.
   It does not change the result: the 128-bit load is still folded
   (`lq $v0,0x10($s2)` where the retail has `addiu $s0,$s2,0x10 ; lq
   $v0,0x0($s0)`), and the prologue still saves the registers in the
   ascending order this cc1 uses (`sd $s0; sd $s1; sd $s2; sd $ra`) where
   the retail saves them `sd $s0; sd $s2; sd $s1; sd $ra`.

   The two walls, measured on this body:

   1. The 128-bit load.  gcc/config/mips/mips.h defines
      `ADDRESS_COST(ADDR) (REG_P (ADDR) ? 1 : mips_address_cost (ADDR))`
      and `mips_address_cost` gives a register+small-constant the cost 1
      as well, so in gcc/cse.c's `find_best_addr` the two addresses tie and
      the tie is broken on the expression cost - the `plus` wins, and the
      constant offset is folded back into the `lq`.  The substitution needs
      the pointer's value to be in the same equivalence class, i.e. the
      pointer must be `reg + const`; a pointer whose value is a MEMORY LOAD
      has the cost 4 and survives (the measured escape), and so does a
      64-bit address expression (cost 4) - but that one costs a
      `dsll`/`dsra` sign-extension pair and a `daddu` where the retail has
      `addiu`.  Measured and all folding: a TI128 pointer variable, the
      destination pointer as a variable, a `volatile` store or load, a
      `volatile` pointer variable (this one keeps the address in a
      register but spills the pointer to the stack), the destination
      computed before the `if`, a TI128 temporary, `__builtin_memcpy`,
      and a 32-bit `(s32)` cast of the pointer.

   2. The prologue save order.  The retail's order here (`s0, s2, s1,
      ra, s3`) is neither ascending nor descending; this cc1 emits the
      saves in ascending register order and the scheduler moves them
      around.  `-mastra-keep-frame-order` switches the scheduler back to
      the emission order, which is the ascending one - so it does not
      help either.  The order is reproducible for some bodies (the matched
      `func_L20_004404B8` saves `s1, s2, ra, s0`), so it is a scheduler
      artefact, not a source shape.

   This body belongs in the `-G8` unit?  No: it reaches no global through
   `$gp`.
   ------------------------------------------------------------------ */

/* ------------------------------------------------------------------
   Third attempt (worker 06, level-20 wave of 2026-10-20): the wall is
   now measured exactly, and it is NOT a source shape.

   The retail keeps the 128-bit source address in a register
   (`addiu $s0,$s2,0x10` / `lq $v0,0x0($s0)`) where this cc1 folds the
   offset back into the load (`lq $v0,0x10($s2)`).  The mechanism, read
   out of the compiler's own sources (the ee-gcc 2.9-ee tree in
   build/, gcc/cse.c and gcc/config/mips/mips.c):

     - the front end builds the load's address as the pointer's PSEUDO
       register (the `-dr` dump shows `(mem:TI (reg/v:SI 85) 0)` before
       the CSE);
     - the CSE's `find_best_addr` (gcc/cse.c) looks the address up in
       the CSE table, finds the class of the pseudo and substitutes the
       class member `plus(reg,const)` for it.  `ADDRESS_COST` is
       `(REG_P (ADDR) ? 1 : mips_address_cost (ADDR))` and
       `mips_address_cost` gives `plus(reg,CONST_INT)` the cost 1 for
       any 16-bit constant (gcc/config/mips/mips.h: `SMALL_INT` is
       +-32767), so the plus TIES with the plain register and the
       tie is broken on the rtx cost, which favours the plus
       (`notreg_cost` = `rtx_cost*2` = 10 for the plus against 1 for
       the register);
     - the reload pass then finds the address `plus(reg,const)`
       legitimate for TImode (`GO_IF_LEGITIMATE_ADDRESS`,
       gcc/config/mips/mips.h, accepts `plus(reg,CONST_INT)` while the
       offset is inside [-32768, 32752]) and keeps the offset in the
       instruction.

   So the materialised form needs the address to be a plain register at
   reload time, and the only way to get that is for the pointer's
   value to be UNKNOWN to the CSE - a parameter, or a value loaded
   from memory.  Measured, with a two-line body:

       *(TI128 *)arg1 = *(TI128 *)arg0;      -> lq $2,0($4)   (the
                                               retail's form)
       char *p = *(char **)(arg0+0x60);
       *(TI128 *)arg1 = *(TI128 *)p;        -> lq $2,0($3)   (the
                                               retail's form)
       char *p = arg0 + 0x10;
       *(TI128 *)arg1 = *(TI128 *)p;        -> lq $2,16($4)  (folded)

   and the same for the store side.  A pointer that is a computed
   `reg + const` is ALWAYS folded by this compiler, whatever the
   source: a TI128 pointer variable, a struct member, an array index, a
   volatile load, a volatile pointer (that one reaches the retail's
   zero-displacement form at the price of a stack store and a reload -
   eight bytes over), a `static __inline__` copy helper, a 32-bit
   truncation (that one keeps the address in a register but costs
   `sll`/`sra`), a 64-bit address (`dsll`/`dsra` and a `daddu` where
   the retail has an `addiu`) and an integer cast all fold.

   The retail's own bodies show the same rule: where the pointer is a
   plain copy of a parameter or of a heap pointer, the offset is folded
   into the instruction (`lq $v1,0xC0($s1)` in func_L00_00395240, which
   is matched); where the pointer is itself `reg + const`, the address
   goes through a register (`sq $v0,0x0($v1)` with `addiu $v1,$a2,0x10`
   in func_L20_0039C540).  This compiler folds both.

   So the wall needs a compiler change, not a source shape: the CSE
   must not substitute a `plus(reg,const)` into a TImode address (or
   `mips_address_cost` must give it more than the cost of a register).
   The retail's compiler is the same source with the same patches
   (tools/compiler/patches/0048-pathb-cse-2952.patch only ports the
   2.95 CSE into the 2.9 tree; `find_best_addr` is unchanged), so the
   difference is in the compiler's own build.


   One more escape was found and it works, but it needs a loop around
   the copy, which this body does not have:

       char *p = arg0 + 0x10;
       while (n--) { *(TI128 *)arg1 = *(TI128 *)p; p += 2; }
       ->  lq $2,0($4)      (the retail's form: the address in a register)

   The reason is the CSE's loop handling: the pointer's value is
   changed inside the loop, so at the copy the CSE no longer knows that
   the pointer is `arg0 + 0x10` and it does not substitute the plus
   into the address.  The same happens when the pointer is given
   different values in two branches (the value is unknown at the join),
   which of course changes the meaning.

   The second escape that works: a pointer that is a PARAMETER, or a
   value loaded from memory (`lq $2,0($3)` for
   `char *p = *(char **)(arg0+0x60);`), keeps the register form.

   This body belongs in the `-G8` unit?  No: it reaches no global
   through `$gp`.
   ------------------------------------------------------------------ */

/* ------------------------------------------------------------------
   Fourth attempt (worker 07, level-20 wave of 2026-10-20): the wall is
   read out of the compiler's own source, and the escapes are measured
   again.  The compiler's sources are IN THE REPO'S DOWNLOADS: build/
   downloads/gnu-ee-binutils-gcc-1.1.tar.gz holds the whole ee-gcc tree
   (gcc/cse.c, gcc/config/mips/mips.h, gcc/reload.c); unpacking it and
   applying tools/compiler/patches/ gives the exact source the compiler
   was built from.  That is how the mechanism below was read.

   WHAT THE COMPILER DOES, exactly:

   - The front end builds the store/load address as the pointer's PSEUDO
     (`(set (mem:TI (reg/v:SI 88) 0) ...)`) when the source uses a
     pointer variable, and as `plus(reg, const)` directly when the source
     writes the expression inline (`*(TI128 *)(o + 0x10)` gives
     `(mem:TI (plus:SI (reg/v:SI 86) (const_int 16)) 0)`).
   - The CSE (gcc/cse.c, `find_best_addr`) replaces the address of a MEM
     by the cheapest equivalent expression it finds in the class of that
     address.  For a class member `plus(reg, const_int)` the cost is
     `mips_address_cost` (gcc/config/mips/mips.c):

         case PLUS: ... case CONST_INT: return SMALL_INT (plus1) ? 1 : 2;

     so `plus(reg, 16)` costs 1 - the same as a plain register
     (`ADDRESS_COST (ADDR) (REG_P (ADDR) ? 1 : ...)`) - and the tie is
     broken on the rtx cost, which favours the plus.  THAT is the fold:
     the reload then finds `plus(reg, const)` legitimate for TImode
     (gcc/config/mips/mips.h, `GO_IF_LEGITIMATE_ADDRESS`: the offset may
     be -32768..32752) and prints it as the displacement.
   - The address is MATERIALISED (`addiu $reg, $base, 0x10` +
     `lq $v0, 0x0($reg)`) exactly when the address is still a PSEUDO at
     reload time: the reload gives the pseudo a register and computes
     its value there (gcc/reload.c, `find_reloads_address`).

   SO THE ESCAPE IS: make the class of the address pseudo hold a value
   whose address cost is MORE than 1, or hold no value at all.  Measured
   today, in this level:

     WORKS
     - a pointer whose value is LOADED FROM MEMORY: the class member is
       a MEM, `mips_address_cost (MEM)` is 4, so the CSE does not
       substitute and the address stays a register (`lq $2,0($3)`);
     - a pointer with DIFFERENT VALUES IN TWO BRANCHES: the class is
       ambiguous, so nothing is substituted - but the compiler then
       computes both values and joins them with a `movn`
       (`addu $3,$4,16 ; addu $4,$4,32 ; movn $4,$3,$6 ; sq $2,0($4)`),
       four instructions instead of two;
     - a `volatile` POINTER OBJECT: the address is materialised, but the
       pointer is spilled and reloaded (`sw $4,0($sp) ; lq $3,0($5) ;
       lw $2,0($sp) ; sq $3,0($2)`), eight bytes over.

     DOES NOT WORK (measured today, all of them fold)
     - the pointer as a TI128 pointer variable, the pointer used twice,
       the pointer used with two different offsets, the offset in a
       variable (`int off = 0x10`), a 64-bit address, a struct member,
       an array index, a union, a `volatile` store or pointee, an
       `__inline__` copy helper (2 parameters), `__builtin_memcpy`, an
       integer cast, the pointer loaded from memory AND offset by 0x10
       (the offset folds), the pointer assigned twice in one block (the
       class is rebuilt at every assignment, so each use sees one
       value), the pointer in a `volatile` variable, the address
       computed inline more than once.

   The only spelling that reaches the retail's zero displacement with a
   plain C source is a SYMBOL base: `plus(symbol, const)` costs 3 (the
   symbol's cost plus one), so the CSE leaves it alone and the reload
   materialises it.  The matched `func_L00_002D40A0` is that case:
   `char *addr = (char *)&D_00189E20_11 + 0x18A0; *(V4 *)addr = *v;`
   gives `addiu $v1, $v1, %lo(D_18B6C0) ; sq $v0, 0x0($v1)`.

   So for a base that is a REGISTER the wall stands: the retail's
   compiler did not make the same substitution this one does.

   The second difference (the order of the two saves) is a scheduler
   artefact of the first: with the load's address in the retail's form
   the body differs and the scheduler has other choices.  Nothing to fix
   on its own.

   This body belongs in the `-G8` unit?  No: it reaches no global through
   `$gp`.
   ------------------------------------------------------------------ */

/* ------------------------------------------------------------------
   Wave 5, worker 06 (2026-10-21): the 128-bit wall, measured from the
   compiler's own source, and the two residues of this body.

   THE 128-BIT LOAD.  The retail keeps the source address in $s0
   (`addiu $s0,$s2,0x10 ; lq $v0,0x0($s0)') where this cc1 folds the
   constant back into the load (`lq $v0,0x10($s2)').  The fold is NOT
   the CSE's: with -fno-cse and with -fno-gcse the folded form is still
   what comes out.  It is the RELOAD: gcc/config/mips/mips.h's
   GO_IF_LEGITIMATE_ADDRESS accepts `plus (reg, const_int)' as a TImode
   address (the offset has to fit in [-32768, 32752]), so the reload
   prints the offset as the displacement instead of materialising the
   address.  The address is materialised only when the expression is
   something the reload cannot fold: a plain register, a symbol or a
   memory reference.

   The escapes, all measured today with the project's compiler: a
   pointer whose value comes from a MEMORY LOAD (`char *p = *(char **)
   (arg0 + 0x60); *(TI128 *)arg1 = *(TI128 *)p;' gives `lw $3,0x60($4)
   ; lq $2,0($3)'), a SYMBOL, a STACK SLOT at offset 0, a LOOP-CARRIED
   POINTER (`char *p = arg0 + 0x10; while (n--) { *(TI128 *)arg1 = *
   (TI128 *)p; p += 2; }' gives `addu $4,$4,16 ; lq $2,0($4)'), and a
   VOLATILE POINTER OBJECT (the zero-displacement form on both sides,
   at the price of a stack round trip).  None of them is a plain-C
   spelling of `base + const' with a runtime base, and this body's
   copy is not in a loop.

   THE PROLOGUE SAVE ORDER.  The retail emits `sd $s0,0x30($sp) ; sd
   $s2,0x40($sp) ; sd $s1,0x38($sp)', this cc1 `sd $s0 ; sd $s1 ; sd
   $s2'.  The register assignment is the same in both (the retail's
   $s0 holds arg0+0x10, its $s2 holds arg0, its $s1 holds state+0x10
   and its $s3 holds state), so only the order of the three stores
   differs.  Measured today: the order does NOT follow the order in
   which the values are first set in the source - three source orders
   (the pointer arg0+0x10 first, the copy of arg0 first, and state+0x10
   computed at its first use) all give the same ascending prologue.
   -mastra-keep-frame-order keeps the emission order and gives the same
   ascending order, so the retail's order is a scheduler artefact of a
   body that differs in the 128-bit load: the two are not separable
   here.
   ------------------------------------------------------------------ */
