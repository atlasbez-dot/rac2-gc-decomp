/* Near miss: 360 bytes against the retail's 396, level 20 only.
 *
 * Two differences, and the first one is the 128-bit wall that blocks most of
 * level 20 (measured again this wave, see the note at the end):
 *
 * 1. THE 128-BIT COPY.  The retail materialises both destination addresses
 *
 *        addiu $v1,$s0,0x10 ; lq $v0,0x0($s5) ; sq $v0,0x0($v1)
 *        addiu $a0,$s0,0xF0 ; lq $v0,0x0($s4) ; sq $v0,0x0($a0)
 *
 *    while this cc1 folds the constant back into the store
 *
 *        lq $v0,0x0($s5) ; sq $v0,0x10($s0)
 *        lq $v0,0x0($s4) ; sq $v0,0xF0($s0)
 *
 *    i.e. four instructions instead of six.  The load side is fine: the two
 *    sources are the parameters ($s5, $s4), a plain register.  The fold is not
 *    the CSE's: with -fno-cse and with -fno-gcse the folded form is still
 *    what comes out.  It is the reload: gcc/config/mips/mips.h's
 *    GO_IF_LEGITIMATE_ADDRESS accepts `plus (reg, const_int)' as a TImode
 *    address (the offset has to fit in [-32768, 32752]), so the reload prints
 *    the offset as the displacement instead of materialising the address.
 *    The escapes that reach the retail's shape are measured at the end of
 *    this note; none of them is a plain-C spelling of `base + const' with a
 *    runtime base.
 *
 * 2. THE STRUCT PASSED BY VALUE.  The retail builds a 12-byte structure in a
 *    local at sp+0x10 and copies it to the outgoing argument area at sp+0x00
 *    with an eight-byte piece and a four-byte piece
 *
 *        ldl $v0,0x17($sp) ; ldr $v0,0x10($sp) ; lw $v1,0x18($sp)
 *        sdl $v0,0x7($sp)  ; sdr $v0,0x0($sp)  ; sw $v1,0x8($sp)
 *
 *    (so the structure's alignment is 8 and the frame is 0x60 with the
 *    argument area at 0x00 and the local at 0x10).  This cc1 forwards the
 *    three word stores straight into the argument area
 *
 *        sw $v0,0x10($sp) ; sw $v0,0x14($sp) ; sw $v1,0x18($sp)
 *
 *    because it splits the structure into three four-byte pieces - the
 *    pieces come from the type, so a structure of three `s32' has three
 *    four-byte pieces, and a copy that gcc can forward never happens.  A
 *    structure with an eight-byte first member would give the eight-byte
 *    piece but its size is 16, not 12.
 *
 * Everything else matches: the frame's shape, the prologue, the flag update,
 * the first two calls, the twelve-iteration loop (the `do ... while' spelling
 * keeps the retail's count-up form), the two calls of the failure path, the
 * `mtc1' + `cvt.s.w' conversion and the branch.
 *
 * The candidate:
 */
typedef struct {
    s32 a;
    s32 b;
    s32 c;
} L20_0039DCF8_S;

extern void func_002A7750(char *, int, int);

extern void func_002A7398(char *, int, int);

extern int func_002A7820(int, int);

extern void func_002A0F48(void *);

extern void func_L02_002EF388(void *, void *, void *, L20_0039DCF8_S, int);

void func_L20_0039DCF8(char *arg0, char *arg1, char *arg2) {
    char *s0 = arg0;
    char *s5 = arg1;
    char *s4 = arg2;
    char *s2 = *(char **)(arg0 + 0x68);
    char *s3 = s2 + 0x270;
    s32 i;
    s16 h;
    L20_0039DCF8_S st;

    *(u16 *)(arg0 + 0x34) = (*(u16 *)(arg0 + 0x34) & 0xFFBE) | 0x1000;
    *(s32 *)(arg0 + 0x98) = *(s32 *)(*(s32 *)(arg0 + 0x24) + 0x10);
    func_002A7750(arg0, 2, 0);
    func_002A7398(arg0, 2, 0);
    *(u8 *)(arg0 + 0x7F) = 0;
    *(f32 *)(arg0 + 0x48) = 1.0f;
    i = 0;
    do {
        *(u8 *)(s3 + i) = func_002A7820(0x40, 0xFE);
        i++;
    } while (i < 12);
    *(s32 *)(s2 + 0x27C) = 0;
    *(TI128 *)(arg0 + 0x10) = *(TI128 *)arg1;
    *(TI128 *)(arg0 + 0xF0) = *(TI128 *)arg2;
    *(u16 *)(arg0 + 0x7C) = 0xF;
    func_002A0F48(arg0);
    h = *(s16 *)(s2 + 0x24);
    if (func_L20_0039DF18(arg0, 1) != 0) {
        *(f32 *)(s2 + 0x20) = (f32)h;
        *(u16 *)(s2 + 0x178) = 0;
        func_002A7398(*(char **)(s2 + 0x254), 2, 0);
        st.a = *(s32 *)(s2 + 0x254);
        st.b = *(s32 *)(s2 + 0x258);
        st.c = *(s32 *)(s2 + 0x25C);
        func_L02_002EF388(arg0, arg1, arg2, st, 3);
    } else {
        func_L20_0039DE88(arg0);
    }
}

/* ------------------------------------------------------------------
   Wave 5, worker 06 (2026-10-21): the 128-bit wall, measured from the
   compiler's own source this time, and the escapes that reach the
   retail's shape.

   The compiler's source is in the repository's downloads
   (build/downloads/gnu-ee-binutils-gcc-1.1.tar.gz, sha256
   1f518043e252d6eda726386971d52eda26541ab936ea73a9783d73712b595f92,
   fetched from the archive.org copy the build recipe names).  The tree
   is the ee-gcc 2.9 one; the RAC2 patches are applied on top of it.

   WHERE THE FOLD HAPPENS.  It is not the CSE.  With -fno-cse and with
   -fno-gcse the folded form is still what comes out, so the offset is
   never substituted into the address by cse.c; the address is built as
   `plus (reg, const_int)' by the front end (or by the reload's own
   pseudo) and the RELOAD prints it as base+displacement:

     gcc/config/mips/mips.h, GO_IF_LEGITIMATE_ADDRESS:
       if (code0 == REG && REG_MODE_OK_FOR_BASE_P (xplus0, MODE))
         {
           if (code1 == CONST_INT
               && INTVAL (xplus1) >= -32768
               && INTVAL (xplus1) + GET_MODE_SIZE (MODE) - 1 <= 32767)
             goto ADDR;
           ...
         }

   For TImode (16 bytes) that accepts every offset in [-32768, 32752],
   so `base + 0x10' with a runtime base is ALWAYS a legitimate address and
   the reload folds it into the lq/sq.  The address is materialised only
   when the address expression is something the reload cannot fold: a
   plain register, a symbol, or a memory reference.

   cse.c's find_best_addr is a SECOND gate, and its early return is what
   the earlier notes called the "frame-pointer and constant addresses"
   escape:

     if ((GET_CODE (addr) == PLUS && ... && regno == FRAME_POINTER_REGNUM
          || ... HARD_FRAME_POINTER_REGNUM || ... ARG_POINTER_REGNUM)
         || (GET_CODE (addr) == REG && ... the same three ...)
         || GET_CODE (addr) == ADDRESSOF || CONSTANT_ADDRESS_P (addr))
       return;

   On MIPS those three registers are 17 ($1, the virtual frame pointer),
   30 ($fp) and 16 ($s0, ARG_POINTER_REGNUM).  But the local addresses are
   `plus (pseudo, const)' with a PSEUDO base at that stage, so the early
   return does not fire for them either: a local at sp+0x20 still folds
   into `lq $2,0x20($sp)'.

   THE ESCAPES, MEASURED TODAY (each one a complete C file compiled with
   the project's compiler, -O2 -G0):

     WORKS
     - a pointer whose value comes from a MEMORY LOAD.  The address's
       class member is a MEM, mips_address_cost (MEM) is 4, so the CSE
       keeps the pseudo and the reload materialises the load:
           char *p = *(char **)(arg0 + 0x60);
           *(TI128 *)arg1 = *(TI128 *)p;      ->  lw $3,0x60($4)
                                                   lq $2,0($3)
     - a SYMBOL: `lui $v1,%hi(S) ; addiu $v1,$v1,%lo(S) ; lq $v0,0($v1)'.
       The witness is the matched src/game/00334710-rc2.c.
     - a STACK SLOT at offset 0: the local sits at sp+0, so the folded
       form `sq $v0,0($sp)' IS the retail's form.  The witness is the
       matched func_L20_0043F510.
     - a LOOP-CARRIED POINTER: the pointer is incremented at the end of
       the body, so the CSE loses the equivalence and the address stays
       in a register:
           char *p = arg0 + 0x10;
           while (n--) { *(TI128 *)arg1 = *(TI128 *)p; p += 2; }
                                                 ->  addu $4,$4,16
                                                     lq $2,0($4)
       This is the escape that makes the copies of func_L20_0039F268
       (inside its loop) reachable; the copies of this body are not in a
       loop.
     - a VOLATILE POINTER OBJECT reaches the zero-displacement form on
       both sides, at the price of a stack round trip:
           TI128 *volatile d = (TI128 *)(arg0 + 0x10);
           *d = *(TI128 *)arg1;   ->  addu $4,$4,16 ; sw $4,0($sp) ;
                                     lq $3,0($5) ; lw $2,0($sp) ;
                                     sq $3,0($2)

     DOES NOT WORK (measured today, all of them fold)
     - the offset inline (`*(TI128 *)(arg0 + 0x10)'), in a pointer
       variable, in a struct member, in an array index, with a `volatile'
       pointee, with a 32-bit or 64-bit cast of the pointer (the 64-bit
       one costs a dsll/dsra pair and a daddu where the retail has an
       addiu), with -fno-cse, with -fno-gcse, with -g,
       -mno-split-addresses, -fno-schedule-insns and
       -fno-schedule-insns2.

   LEVEL 20, MEASURED OVER EVERY CATALOGUE ROW: 359 of the 3978
   functions that live in level 20 have the retail's shape - an addiu
   whose destination is the base of a zero-displacement lq/sq - and only
   TWO of them are already C in src/: func_002C1EF0 and func_00334710,
   both of them the SYMBOL escape.  All the other 357 are behind the
   wall, and every function of this wave's list is one of them.
   ------------------------------------------------------------------ */

/* ------------------------------------------------------------------
   Wave 5, worker 06 (2026-10-21): the float register order of
   func_L20_0043D470, measured again, and the prologue save order of
   func_L20_0039C448.

   THE FLOAT REGISTER ORDER (func_L20_0043D470).  The retail puts 8.0f
   in $f1 and 2.5f in $f0, and its instruction stream materialises the
   8.0f FIRST (`lui $at,0x4100 ; mtc1 $at,$f1' before `lui $at,0x4020 ;
   mtc1 $at,$f0').  This cc1 gives $f0 to the first constant of the
   instruction stream, so it can only produce the retail's order if the
   2.5f is first in the stream - but the 2.5f's store is the second one.
   Measured today with every spelling that could break the tie: both
   constants as locals (the order then follows the stores), one as a
   local and the other inline (the order follows the stream, so the
   inline 8.0f wins again), the stores in the opposite order (the FPRs
   come out right but the stores stay in that order), and with
   -fno-schedule-insns / -fno-schedule-insns2 (which only move the
   instructions).  No spelling produces the retail's combination, so
   this residue is a compiler difference (the 2.9 local register
   allocator allocates the FPRs the other way round than the 2.95 one
   that patch 0047 ports in), not a source shape.

   THE PROLOGUE SAVE ORDER (func_L20_0039C448).  The retail emits
   `sd $s0,0x30($sp) ; sd $s2,0x40($sp) ; sd $s1,0x38($sp)', this cc1
   `sd $s0 ; sd $s1 ; sd $s2'.  The register ASSIGNMENT is the same in
   both (the retail's $s0 holds arg0+0x10, its $s2 holds arg0, its $s1
   holds state+0x10 and its $s3 holds state - the same four values in
   the same four registers as this candidate's), so only the ORDER of
   the three stores differs.  Measured today: the order does NOT
   follow the order in which the values are first set in the source -
   three different source orders (the pointer arg0+0x10 first, the copy
   of arg0 first, and state+0x10 computed at its first use) all give
   the same `sd $s0 ; sd $s1 ; sd $s2' prologue and the same body.  The
   prologue's stores come out in ascending register order here, and
   -mastra-keep-frame-order (which keeps the emission order) gives the
   same ascending order, so the retail's order is a scheduler artefact
   of a body that differs in the 128-bit load - the two are not
   separable here.
   ------------------------------------------------------------------ */
