/* func_L20_004424A0 (176 bytes, level 20): near miss, 44 of 44 words, 31 words differ.
 *
 * What matches: the frame (0x30 - one word too big, see below), the two float products
 * (D_L20_001B212C * 4.84813745e-06f and D_L20_001B2130 * 0.000290888245f) materialised
 * through $f14/$f15, the call to func_00341B10 with the two zeros in $f12/$f13, the
 * func_00330C60 call, the two float stores, the 16-byte zero store and the func_00302198
 * call with the doubling `add.s $f12,$f12,$f12` (this cc1 turns x * 2.0f into x + x on its
 * own).
 *
 * What differs: (1) this cc1 hoists the lwc1 of D_L20_001B2130 above the frame setup, the
 * retail keeps both loads after it; (2) the value D_L20_001B2138 * 0.000277777785f is live
 * across the func_00330C60 call here, so this cc1 puts it in $f20 and saves $f20 (frame
 * 0x30, `swc1 $f20,0x20($sp)`), while the retail keeps it in the caller-saved $f0 and
 * never saves an FPR (frame 0x20); (3) the register names of the two products follow from
 * (2).  The function has to live in the -g8 sibling: it reads four constants through $gp
 * (0x3138..0x3148 -> 0x1B2128..0x1B2138).
 *
 * Fourth wave (20_yeedil, 2026-10-20, worker w20-01) measured the second residue more
 * closely, and it is a compiler-model difference, not a source shape: the retail keeps the
 * product `D_L20_001B2138 * 0.000277777785f` in the CALLER-SAVED $f0 across the
 * `jal f_00330C60` and stores it to state[0xE0] after that call, while this cc1 keeps the
 * value in the callee-saved $f20 (and saves it, so the frame is 0x30 instead of 0x20).
 * The callee really does clobber $f0 (f_00330C60 = func_002A89A8 writes $f0 twice), so the
 * retail's second store keeps whatever the callee left in $f0 - the retail body is what it
 * is, and this cc1 will not reproduce it from C: any source that has the value live across
 * the call puts it in $f20 here, and a source that re-reads the value from state[0x7C]
 * after the call (so that it is not live across it) emits a reload the retail does not
 * have.  The first residue (this cc1 hoists the `lwc1` of D_L20_001B2130 above the frame
 * setup) was not re-measured; the note above stands.
 */
typedef int TI128 __attribute__((mode(TI)));

extern float D_L20_001B212C __attribute__((sda));
extern float D_L20_001B2130 __attribute__((sda));
extern float D_L20_001B2138 __attribute__((sda));
extern float D_L20_001B2128 __attribute__((sda));

extern void func_00341B10(float, float, float, float);
extern void func_00330C60(char *, int, float);
extern void func_00302198(float);

void func_L20_004424A0(char *arg0) {
    char *s1 = arg0;
    char *s0 = *(char **)(arg0 + 0x68);
    float f0;
    TI128 *p;

    func_00341B10(0.0f, 0.0f, D_L20_001B212C * 4.84813745e-06f,
                  D_L20_001B2130 * 0.000290888245f);
    f0 = D_L20_001B2138 * 0.000277777785f;
    func_00330C60(s1 + 0x10, 0, 0.5f);
    *(float *)(s0 + 0x7C) = f0;
    *(float *)(s0 + 0xE0) = f0;
    p = (TI128 *)(s0 + 0xF0);
    *p = 0;
    func_00302198(*(float *)(s0 + 0x7C) * 2.0f * D_L20_001B2128);
    *(float *)(s0 + 0xF8) = f0;
}

/* Near miss from src/levels/20_yeedil/L20_0043ECB0.c (wave 4, 20_yeedil, 2026-10-20,
   worker 02): the candidate is 172 bytes against retail's 176 - one instruction short.

   What the wave-4 candidate settles (this is the wave-3 note's open hypothesis, now
   confirmed):
   - The store to state+0xE0 is the RESULT of the call, not a second store of the value
     from before it: retail's `swc1 $f0,0xE0($s0)` sits right after `jal f_00330C60` and
     $f0 is what the callee returned.  So the source is
     `*(float *)(s0 + 0xE0) = func_002A89A8(s1 + 0x10, 0, 0.5f);` and func_002A89A8 returns
     a float.  With that, the value `D_L20_001B2138 * 0.000277777785f` is NOT live across
     the call any more and the frame stays 0x20 (the wave-3 note's $f20 difference is gone).
   - The store to state+0xF8 is the RESULT of the LAST call as well: retail's
     `swc1 $f0,0xF8($s0)` sits after `jal f_00302198` and $f0 is the return value, so the
     source is `*(float *)(s0 + 0xF8) = func_00282C10(*(float *)(s0 + 0x7C) * 2.0f *
     D_L20_001B2128);`.  func_00282C10 returns a float (the boot function at 20:00302198).
     With that, D_L20_001B2128 is loaded ONCE, as in retail, and nothing is live across the
     call.
   - The two products of the first call are materialised through $f14 and $f15, the two
     zeros in $f12 and $f13, the frame is 0x20 with $s0 and $s1 saved, and the 0.30f
     constant of the first call is 0.000277777785f = 0x3991A2B4.
   - The four constants are read through $gp (0x3138..0x3148), so the unit has to be built
     with -G8 and every declaration needs `__attribute__((sda))`.

   What still differs:
   - The 16-byte zero store.  Retail: `addiu $v0,$s0,0xF0` ; `sq $zero,0x0($v0)`.  The
     candidate: `sq $zero,0xF0($s0)` - the address is folded into the store (the 128-bit
     copy wall, the same one as func_L20_004499E8).  That is the one instruction the
     candidate is short.
   - The order of four instructions in the block after the first call.  Retail:
     `lwc1 $f0,0x3148($gp)` (D_L20_001B2138), `daddu $a1,$zero,$zero` (the call's second
     argument), the 0.000277777785f constant, `addiu $a0,$s1,0x10` (the call's first
     argument), the 0.5f constant, `mul.s $f0,$f0,$f1`.  The candidate keeps the product's
     operands together and the call's arguments together.  Measured and rejected: the
     0x7C store before the first call, the 0xE0 store before the 0x7C store, the two loads
     of D_L20_001B2128 written out twice (they are not CSE'd across the call, because the
     store to state+0xF8 may alias the global - `const` on the declaration makes the CSE
     work but then the value is live across the call and lands in $f20, frame 0x30).

   The candidate (a -G8 unit: the constants are read through $gp):

typedef int TI128 __attribute__((mode(TI)));

extern float D_L20_001B212C __attribute__((sda));

extern float D_L20_001B2130 __attribute__((sda));

extern float D_L20_001B2138 __attribute__((sda));

extern float D_L20_001B2128 __attribute__((sda));

extern void func_002B60B0(char *, float, float, float, float);

extern float func_002A89A8(void *, int, float);

extern float func_00282C10(float);

void func_L20_004424A0(char *arg0) {
    char *s1 = arg0;
    char *s0 = *(char **)(arg0 + 0x68);
    TI128 *p;

    func_002B60B0(s1, 0.0f, 0.0f, D_L20_001B212C * 4.84813745e-06f,
                  D_L20_001B2130 * 0.000290888245f);
    *(float *)(s0 + 0x7C) = D_L20_001B2138 * 0.000277777785f;
    *(float *)(s0 + 0xE0) = func_002A89A8(s1 + 0x10, 0, 0.5f);
    p = (TI128 *)(s0 + 0xF0);
    *p = 0;
    *(float *)(s0 + 0xF8) = func_00282C10(*(float *)(s0 + 0x7C) * 2.0f * D_L20_001B2128);
}

/* ---- wave 5 (20_yeedil, 2026-10-21, worker 01): the 16-byte zero store, measured ---
 *
 * The wave-4 candidate is 172 bytes against the retail's 176, and the four missing bytes
 * are the ONE instruction that materialises the address of the 16-byte zero store:
 *
 *   retail:  addiu $v0,$s0,0xF0 ; sq $zero,0x0($v0)
 *   here:    sq $zero,0xF0($s0)
 *
 * The address is a RUNTIME base plus a constant, and the wave-4 corrected rule says
 * that plain C never reproduces the materialised form for such an address (the CSE's
 * `find_best_addr` substitutes the `plus(reg, const)` and the reload folds the constant
 * into the displacement).  MEASURED in this wave, on a copy of the unit:
 *
 *   - `TI128 *p = (TI128 *)(s0 + 0xF0); *p = 0;`      -> `sq $zero,0xF0($s0)`   (folded)
 *   - `*(TI128 *)(s0 + 0xF0) = 0;`                    -> `sq $zero,0xF0($s0)`   (folded)
 *   - `*(volatile TI128 *)(s0 + 0xF0) = 0;`           -> `sq $zero,0xF0($s0)`   (folded)
 *   - the address through a struct member, through an array index and through two
 *     added constants (`s0 + 0x80 + 0x70`)            -> all folded
 *   - a VARIABLE offset (`s0 + o`)                     -> `addu $4,$4,$5 ;
 *                                                            sq $zero,0($4)`  (the
 *                                                            materialised form, but
 *                                                            with a register offset
 *                                                            instead of the retail's
 *                                                            immediate 0xF0)
 *   - a `volatile` POINTER OBJECT
 *       `TI128 *volatile d = (TI128 *)(s0 + 0xF0); *d = 0;`
 *     -> `addu $4,$4,240 ; sw $4,0($sp) ; lw $2,0($sp) ; sq $zero,0($2)`
 *        - the retail's zero-displacement `sq`, but four instructions instead of two
 *          (eight bytes over) and the frame grows by 0x10;
 *   - a pointer given DIFFERENT values in two branches
 *     -> `addu $2,$4,240 ; addu $4,$4,256 ; movn $4,$2,$5 ; sq $zero,0($4)` - four
 *        instructions again.
 *
 * So the zero store of this function is the plain case of the 128-bit wall and the
 * candidate cannot reach the retail's 176 bytes from C.  Everything else of the
 * wave-4 candidate is the retail's (the frame is 0x20, the four constants are read
 * through $gp, the two stores of the CALL RESULTS are right).
 */
