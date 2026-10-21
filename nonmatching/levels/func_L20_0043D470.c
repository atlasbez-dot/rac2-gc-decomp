/* Not landable: this body reaches a 128-bit copy through `qcopy`/`qzero` or a local
   `__asm__` helper, and AGENTS.md's "Plain C" rule (no inline assembly in a function)
   forbids that as a matching route. Kept as a starting point. Removed from src/ 2026-10-13. */

/* ---- level-20 wave, worker 06 (2026-10-20): the plain-C candidate ------------------
 *
 * Near miss: 88 bytes against retail's 100, level 20 only.
 *
 * The body is seven stores into the object the argument's state points at, and a
 * 16-byte copy at the end:
 *
 *     retail:  lw    $a1,0x68($a0)      ; state
 *              lui   $at,0x4100 / mtc1 $at,$f1      ; 8.0f  -> $f1
 *              addiu $a0,$zero,1
 *              lw    $v1,0x84($a1)      ; the object pointer, reloaded every time
 *              addiu $a2,$a1,0x60      ; the copy source, MATERIALISED
 *              lui   $at,0x4020 / mtc1 $at,$f0      ; 2.5f  -> $f0
 *              swc1  $f1,0($v1) / swc1 $f0,4($v0)
 *              sb    $a0,0x18($v1) / sh $zero,0x1A($v0) / sb $a0,0x1E($v1) / sb $zero,0x1F($v0)
 *              lw    $v1,0x84($a1)
 *              addiu $v1,$v1,0x20      ; the copy destination, MATERIALISED
 *              lq    $v0,0($a2) / sq $v0,0($v1)
 *              jr $ra
 *
 * Two differences, both of them compiler behaviour and not source shapes:
 *
 * 1. THE 128-BIT COPY WALL.  Retail materialises both addresses (a 32-bit `addiu`
 *    each) and copies with a zero offset; this cc1 folds the constant offset into the
 *    `lq`/`sq` (`lq $v0,0x60($a1)` / `sq $v0,0x20($v1)`), which is two instructions
 *    shorter.  Measured this wave, all of these fold: a `TI128 *` variable, a `char *`
 *    variable, an array index, a struct member, a union, `volatile`, an integer cast,
 *    a pointer loaded from memory, the pointer used twice, two C names for one pointer,
 *    offsets applied one at a time, `__builtin_memcpy(...,16)`.  The only spelling that
 *    MATERIALISES the address is 64-bit pointer arithmetic
 *    (`s64 q = (s64)p + 0x10; *(TI128 *)q`), and that costs three extra instructions
 *    (`daddiu` + `dsll32` + `dsra32`) where the retail has one 32-bit `addiu`, so it
 *    does not match either.  A 32-bit pointer whose value came from a 32-bit load does
 *    not help: gcc still emits the sign-extension pair.
 *
 *    A SECOND MEASUREMENT (worker 06): using the address a second time does NOT break
 *    the fold either - it only materialises the address for the COMPARISON operand
 *    (`addiu $v0,$a0,0x10` for `if (p != 0)`), while the `lq`/`sq` keep the folded
 *    offset (`lq $v0,0x10($a0)`).  Measured with the pointer compared against 0, against
 *    the other pointer, and against itself (the last one folds the comparison away and
 *    the materialisation with it).
 *
 * 2. THE FLOAT REGISTER ORDER.  Retail puts 8.0f in $f1 and 2.5f in $f0 - the first
 *    constant in the instruction stream gets the HIGHER register.  This cc1 always
 *    allocates in the opposite order (the first constant gets $f0): measured with the
 *    two stores in either source order, with the constants in a local variable, and with
 *    the stores swapped, and with -fno-schedule-insns/-fno-schedule-insns2 (which only
 *    change the order, not the allocation).  The retail's order is the 2.9 local
 *    register allocator's; this tree uses the 2.95 one (patch 0047-pathb-reload1-
 *    localalloc-regclass-2952), which allocates the other way round.
 *
 * Per-file flags tried and measured, none of them changes either difference:
 * -g, -mno-split-addresses, -fno-schedule-insns, -fno-schedule-insns2,
 * -mastra-split-trunc-slot.  The function needs no -G8 unit (it reaches no global).
 *
 * The candidate below is 22 instructions against the retail's 25; every instruction but
 * the three of the copy wall and the two float registers matches.
 *
 * WHERE ELSE THE SAME WALL BLOCKS LEVEL 20 (measured, level-20 wave, worker 06):  the
 * wall bites exactly where the retail MATERIALISES a 128-bit address with a non-zero
 * offset, i.e. where it has `addiu $rX,$rY,0xNN` in front of an `lq`/`sq` with a zero
 * offset.  Reading the retail bodies of the level:
 *
 *   func_L20_0039E770 (284)  addiu $v1,$s1,0x10 ; lq $v0,0($v1)   -> blocked
 *   func_L20_0039EBB8 (444)  addiu $s2,$s1,0x10 ; lq $v0,0($s2)   -> blocked
 *   func_L20_0039F268 (756)  addiu $a0,$sp,0x10 ; lq $v0,0($a0)   -> blocked, and it
 *                            also has the 128-bit ZERO store (por $v0,$zero,$zero ;
 *                            sq $v0,0($sp)), which the chain's rac2_fold_zero_ti_store
 *                            folds to `sq $zero` because the zero dies after the store
 *   func_L20_0043D4D8 (960)  addiu $a0,$sp,0x10 ; sq $v0,0($a0)   -> blocked
 *   func_L20_003E6FA0 (1804) addiu $a0,$sp,0x240 ; lq $v0,0($a0)  -> blocked
 *
 * The other 128-bit copies of the level all have a ZERO offset and a plain-register
 * base, so they are NOT behind the wall and are worth a try:
 *
 *   func_L20_0039F560 (1028) lq $v0,0($s0) / sq $v0,0($a2), both bases are plain
 *                            registers ($s0 is a pointer the loop advances, $a2 is
 *                            `addiu $a2,$sp,0xC0`)
 *   func_L20_0039E1E8 (352)  and func_L20_0039C8C8 (836) have no 128-bit copy at all
 */

typedef int TI128 __attribute__((mode(TI)));

typedef unsigned char u8;

typedef unsigned short u16;

typedef float f32;

void func_L20_0043D470(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);

    *(f32 *)(*(char **)(state + 0x84) + 0x0) = 8.0f;
    *(f32 *)(*(char **)(state + 0x84) + 0x4) = 2.5f;
    *(u8 *)(*(char **)(state + 0x84) + 0x18) = 1;
    *(u16 *)(*(char **)(state + 0x84) + 0x1A) = 0;
    *(u8 *)(*(char **)(state + 0x84) + 0x1E) = 1;
    *(u8 *)(*(char **)(state + 0x84) + 0x1F) = 0;
    *(TI128 *)(*(char **)(state + 0x84) + 0x20) = *(TI128 *)(state + 0x60);
}

/* ---- level-20 wave 3, worker 05 (2026-10-20): two more measurements ---------------
 *
 * 1. The FLOAT REGISTER ORDER (point 2 above) is a compiler difference, not a source
 *    shape, and it is confirmed from this side too: the FPR of a float constant is the
 *    register the allocator gives its pseudo, and the pseudos are created in the order
 *    the source first uses the constants, so the FIRST constant introduced always takes
 *    $f0.  Measured here with the constants in two local variables (`f32 a = 2.5f;
 *    f32 b = 8.0f;` then the stores of b and a), with both store orders, and with
 *    `volatile` on the stores: the constants are folded back into the stores by the
 *    front end, so the variables make no difference, and the FPR order always follows
 *    the order the constants first appear in the source.  The retail's 8.0f in $f1 with
 *    2.5f in $f0 therefore means its source introduced the 2.5f first although its store
 *    comes second - which no source shape we tried produces, because the scheduler
 *    does not swap two stores (measured: with the stores in the order (2.5f at +4, 8.0f
 *    at +0) the FPRs come out right but the stores stay in that order).
 *
 * 2. The 128-BIT COPY WALL (point 1 above) also bites the rest of the level 20 set
 *    this wave, and I did not find a spelling that gets past it: every address form
 *    folds into the lq/sq, including the 32-bit casts of a 64-bit pointer that the
 *    common file's hint suggests (`(int)(long long)p + 0x10` and `(u32)(long long)p +
 *    0x10` both give `lq $2,16($4)`), a pointer variable used twice, a second access
 *    to the same address (a `sd` through it), and two accesses through one address.
 *    The level-20 functions whose retail body MATERIALISES a 128-bit address with a
 *    non-zero offset (and which are therefore behind this wall) are
 *    func_L20_0039CF58 (addiu $v1,$s1,0x10), func_L20_0039DCF8 (addiu $v1,$s0,0x10 and
 *    addiu $a0,$s0,0xF0), func_L20_0039DBC8 (addiu $a2,$a1,0x60), func_L20_0039F268
 *    (addiu $a0,$sp,0x10), func_L20_0043D4D8 (addiu $v1,$s2,0xF0), func_L20_003B0A88
 *    (addiu $v1,$a1,0x10) and func_L20_003E6FA0 (addiu $a0,$s1,0x10). */

/* ---- level-20 wave 4, worker 06 (2026-10-20): two more measurements ---------------
 *
 * 1. THE -G8 PROFILE DOES NOT BREAK THE 128-BIT WALL.  func_L20_0043D470 was compiled
 *    in a -G8 unit as well: the copy still folds into the lq/sq (`lq $v0,0x60($a1)` /
 *    `sq $v0,0x20($v1)`).  The profile changes the register allocation, not the CSE.
 *
 * 2. THE FLOAT REGISTER ORDER FOLLOWS THE INSTRUCTION STREAM, not the declaration.
 *    With one constant a local variable and the other written inline
 *    (`f32 two = 2.5f;` and `*(f32 *)(...) = 8.0f;`), this cc1 gives $f0 to the 8.0f -
 *    the constant that ends up first in the stream - and $f1 to the 2.5f, although the
 *    source introduces the 2.5f first.  With both constants as locals the order
 *    follows the stores instead.  So the retail's 8.0f in $f1 with 2.5f in $f0 needs
 *    the 2.5f to be first in the stream AND second in the FPR order, which no
 *    spelling measured here produces.
 *
 * 3. The reload pattern of the object pointer (the retail re-reads state->0x84 before
 *    every store) needs the pointer read again in each store expression; with a local
 *    variable this cc1 keeps it in a register and does not reload.  The candidate
 *    above does the re-reads and gives every byte store and every reload its retail
 *    address. */

/* ---- level-20 wave 5, worker 06 (2026-10-21): the two residues, measured from the
 * compiler's own source, and what the wave's other functions have in common.
 *
 * 1. THE 128-BIT COPY.  The retail materialises both addresses
 *      addiu $a2,$a1,0x60 ; lq $v0,0x0($a2) ; sq $v0,0x0($v1)
 *    (with $v1 = the object pointer + 0x20) while this cc1 folds the constant
 *    back into the lq/sq (`lq $v0,0x60($a1)' / `sq $v0,0x20($v1)'), which is
 *    three instructions against the retail's five.
 *
 *    The fold is NOT the CSE's: with -fno-cse and with -fno-gcse the folded
 *    form is still what comes out.  It is the RELOAD: in
 *    gcc/config/mips/mips.h's GO_IF_LEGITIMATE_ADDRESS, `plus (reg, const_int)'
 *    is a legitimate TImode address whenever the offset fits in
 *    [-32768, 32752], so the reload prints the offset as the displacement
 *    instead of materialising the address.  The address is materialised only
 *    when the expression is something the reload cannot fold: a plain
 *    register, a symbol, or a memory reference.
 *
 *    The escapes, all measured today with the project's compiler: a pointer
 *    whose value comes from a MEMORY LOAD (`char *p = *(char **)(arg0 + 0x60);
 *    *(TI128 *)arg1 = *(TI128 *)p;' gives `lw $3,0x60($4) ; lq $2,0($3)'), a
 *    SYMBOL, a STACK SLOT at offset 0, a LOOP-CARRIED POINTER (`char *p =
 *    arg0 + 0x10; while (n--) { *(TI128 *)arg1 = *(TI128 *)p; p += 2; }' gives
 *    `addu $4,$4,16 ; lq $2,0($4)'), and a VOLATILE POINTER OBJECT (the
 *    zero-displacement form on both sides, at the price of a stack round
 *    trip).  Here the two addresses are `state + 0x60' and `object + 0x20',
 *    i.e. a runtime base plus a constant, and the copy is not in a loop, so
 *    no plain-C spelling reaches the retail's shape.
 *
 * 2. THE FLOAT REGISTER ORDER.  The retail puts 8.0f in $f1 and 2.5f in $f0
 *    and materialises the 8.0f FIRST in the instruction stream; this cc1
 *    gives $f0 to the first constant of the stream, so it can only produce
 *    the retail's order if the 2.5f is first in the stream - but the 2.5f's
 *    store is the second one.  Measured today with every spelling that could
 *    break the tie: both constants as locals (the order then follows the
 *    stores), one as a local and the other inline (the order follows the
 *    stream, so the inline 8.0f wins again), the stores in the opposite order
 *    (the FPRs come out right but the stores stay in that order), and with
 *    -fno-schedule-insns / -fno-schedule-insns2 (which only move the
 *    instructions).  No spelling produces the retail's combination, so this
 *    residue is a compiler difference (the 2.9 local register allocator
 *    allocates the FPRs the other way round than the 2.95 one that patch
 *    0047 ports in), not a source shape.
 *
 * WHAT THE WAVE'S OTHER FUNCTIONS HAVE IN COMMON: every one of them is
 * behind the 128-bit wall of point 1 (or, for func_L20_0039F268, behind the
 * `por' of the 128-bit zero store).  Measured over every catalogue row of
 * level 20: 359 of the 3978 functions that live in level 20 have the
 * retail's shape - an addiu whose destination is the base of a
 * zero-displacement lq/sq - and only TWO of them are already C in src/
 * (func_002C1EF0 and func_00334710, both the SYMBOL escape).
 */
