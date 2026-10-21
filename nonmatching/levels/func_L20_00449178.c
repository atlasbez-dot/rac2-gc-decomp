/* Best attempt for func_L20_00449178 (444 bytes, 1 place) - NOT MARKED.
   G8: this body reaches the level's data through $gp (D_L20_001B23A0,
   D_L20_001B23A8, D_L20_001B23B0, addressed as $gp+0x33B0/$gp+0x33B8/
   $gp+0x33C0), so it belongs in the -G8 sibling of its unit
   (src/levels/20_yeedil/L20_00449178-g8.c), not in L20_00449178.c.

   last check.py line: "20_yeedil: 464 bytes, expected 404"
   (20 bytes over: the frame is retail's 0x50, but the body is longer.)

   What the retail body does, and what the attempt got wrong:

   - the dispatch tests "mode == 1", then "mode >= 2" (slti + a
     branch-likely beql), then "mode == 0"; the mode 2 block is the big
     one, the mode 0 block builds a 128-bit vector on the stack.
   - the attempt reproduces the dispatch and the block order, but cc1
     gives "mode >= 2" a plain `bnez` where retail has the branch-likely
     `beql`, and it allocates $s1 to the object and $s0 to the state
     where retail has $s0 for the object and $s1 for the state.
   - the 128-bit vector: retail writes it as `por $v0,$zero,$zero` +
     `sq $v0,0x20($sp)` (one 16-byte store of zero, the por in the
     delay slot of the branch into the block) and then `swc1 $f0,0x28($sp)`
     for the 2.0f in its upper half.  cc1 folds the zero store to
     `sd $zero` (or to two of them) and never emits the por; the docs
     say the por survives only when the zero feeds two or more stores,
     so the source must write the zero twice in a way that cc1 merges
     into one 16-byte store.
   - the argument setup: retail materialises the arguments of
     f_00353920 (func_L00_0033E220) as f12, a0, f13, a1, a2, a3, t0..t3,
     so the prototype is the interleaved `(void *, void *, int, int, int,
     int, int, int, float, float)` - the same order the already matched
     func_0032C700 call uses.  The constants are 420000.0f (0x48CD1400),
     1.0f, and the two INT constants 0x40204080 and 0x4010000 (they are
     bit patterns of floats, but they travel in integer registers).
   - the call to f_0033F540 (func_L00_0032A258) takes the addresses of
     the three level globals as pointers, so they must be declared with a
     type bigger than the -G8 threshold (a TI128) for cc1 to compute
     $gp+offset instead of loading them out of .sdata.
   ------------------------------------------------------------------
   The `por` wall, measured again this wave (2026-10-21, worker 10 of the
   level 20 wave 5), with the answer to "is there a source shape that puts
   a call or a label between the materialisation and the store?".

   THE ANSWER IS NO, and the reason is in the reload, not in the source.
   `rac2_fold_zero_ti_store` (tools/compiler/transformers/fold_zero_ti_store.py)
   folds the materialisation into the store when (a) the store's source is
   a register, (b) that register is not READ before it is rewritten, and
   (c) the materialisation is at most TWELVE instructions above the store
   in the SAME block (a call, a jump or a label between them stops the
   backward scan).  But the materialisation is not something the source
   can place: the RELOAD emits it, as its own insn, IMMEDIATELY before the
   store that consumes it.  The RTL dump after the reload shows the two
   insns side by side:

       (insn 36 17 30 (set (reg:TI 2 v0) (const_int 0)) 239 {movti_internal}
       (insn 30 36 19 (set (mem:TI (reg:SI 29 sp) 0) (reg:TI 2 v0)) 239 {movti_internal}

   (cc1 -da, file x.i.greg; x.i.dbr and x.i.sched2 show the same pair).
   So the materialisation and the store are always adjacent and always in
   the same block: no source shape can separate them.  The only way to get
   a materialisation that is NOT adjacent to the store is a SECOND use of
   the same zero constant - and then there are two stores (the second use
   costs one), which is one `sq` more than the retail has.

   What the fold needs to be defeated, and why it cannot be:
   * the forward scan (`rac2_reg_live_after_store_p`) walks the insns
     after the store; it stops at the first insn that WRITES the register
     number (`single_set` + `REGNO`), and it returns "live" only for an
     insn that READS it (`reg_referenced_p` on the pattern).  In these
     bodies the register is written before it is read (the retail reuses
     $v0/$v1 for other values: in func_L20_0044AB68 the constant 1 is
     materialised into $v0 at 0x0044ABB4 and only read at 0x0044ABD4), so
     the scan returns "dead" and the store is folded;
   * a later READ of the register would keep the `por`, but the register
     is a 128-bit one and the only thing that reads it is another 128-bit
     store, which is the two-store case again.

   Re-measured this wave, all of them `sq $zero` (one store, folded):
   a local TI128, a union, a struct member, an array element, a volatile
   pointer, a volatile store, a global, a static local, a store through a
   pointer, a store of a variable the compiler knows is zero, and the
   store of a zero whose address is `plus(reg, const)`.  The compiler
   flags make no difference either: -O1, -O2, -O3, -G0, -G8,
   -fno-schedule-insns and -fno-schedule-insns2 all fold the same way
   (measured on `*(TI128 *)p = 0;`).

   The ONE spelling that keeps a materialised zero with a SINGLE store is
   the wave-4 note's: the zero is the FUNCTION VALUE, so the fold's guard
   sees the function-value use and refuses to fold -
   `int f(TI128 *p) { *p = 0; return 0; }` gives `por $2,$0,$0 ; j $31 ;
   sq $2,0($4)`.  It needs the store to be the LAST thing before the
   return: with a call in between (`*p = 0; g(); return 0;`) the compiler
   re-materialises the zero for the return (`move $2,$0`) and the store
   goes back to `sq $zero`.  These three bodies are void and their store is
   at the top, so the trick cannot reach them.

   THE FIX, in the project's own pass: the fold must not fire when the
   store's displacement is not zero.  The wave-4 note measured that rule
   over the compiled code of the matched corpus: there the zero register
   is the source of a 128-bit store only when the displacement is zero
   (2554 of 2554), and of the 1768 single stores with a non-zero
   displacement 1330 keep their materialisation.  The retail itself has
   both forms (in level 20: 147 `sq $zero,0x0($x)` against 85
   `sq $zero,off($x)` with a non-zero displacement), so the rule is not
   absolute - but the fold as it stands fires on a non-zero displacement
   here, and the retail's shape for these three bodies is
   `por $v0,$zero,$zero ; sq $v0,0x20($sp)`, the materialised form.
   A pass that folds only on a zero displacement keeps the `por` of these
   three bodies and they then match.
   The register allocation follows: with the `por` present the constant 1
   of func_L20_0044AB68 lands in $v0 (as in the retail) instead of $v1 -
   measured by giving the body a second zero store, which keeps the
   `por` and puts the constant in $v0.

   For the record, the whole of func_L20_0044AB68 is the retail's body
   except that one instruction (and the register the constant 1 lands
   in): with the near-miss C of this file, `tools/check.py
   func_L20_0044AB68 --diff` prints "20_yeedil: 200 bytes, expected 204"
   and the diff is the `por` alone.
*/

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef int TI128 __attribute__((mode(TI)));

extern TI128 D_L20_001B23A0;

extern TI128 D_L20_001B23A8;

extern TI128 D_L20_001B23B0;

extern void func_L00_0033E220(void *, void *, int, int, int, int, int, int, float, float);

extern void func_002A7750(char *, int, int);

extern int func_002A9640(char *, int, int);

extern void func_L00_0032A258(char *, void *, void *, void *, int, int, int, int, int, int, int);

extern void func_L01_0031A278(void *, void *, float, float, float);

extern void func_0032C700(void *, int, int, int, int, int, int, int, float, float, int, int, int, int);

extern void func_L00_00326620(char *, int, int);

extern void func_0029F338(char *, char *);

void func_L20_00449178(char *arg0) {
    char *self = arg0;
    char *state = *(char **)(self + 0x68);
    int mode = *(u8 *)(self + 0x20);
    TI128 v;

    if (mode == 1) {
        goto L49230;
    }
    if (mode >= 2) {
        goto L492BC;
    }
    if (mode == 0) {
        goto L491CC;
    }
    return;
L491CC:
    *(u64 *)&v = 0;
    *(u64 *)((char *)&v + 8) = 0;
    *(float *)((char *)&v + 8) = 2.0f;
    func_L00_0033E220(&v, self, 0x40204080, -1, 1, -1, 0, -1, 420000.0f, 1.0f);
    func_002A7750(self, 1, -1);
    return;
L492BC:
    if (mode == 2) {
        goto L49270;
    }
    return;
L49230:
    if (func_002A9640(self, 0x4010000, 0) != 0) {
        if (*(u32 *)state == 0) {
            func_002A7750(self, 2, -1);
        }
    }
    *(u8 *)(self + 0xA8) = 0xFF;
    return;
L49270:
    func_L00_0032A258(self, &D_L20_001B23B0, &D_L20_001B23A8, &D_L20_001B23A0,
                      0xFFFF, 0, -1, 0, 0xFFFF, mode, 0);
    func_L01_0031A278(self, &v, 0.0f, 0.0f, 2.0f);
    func_0032C700(&v, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 1, 0.5f, 20.0f, 1, 1, 0, 0);
    func_L00_00326620(self, 0x126A, 0);
    func_0029F338(self, self);
    return;
}

   ------------------------------------------------------------------
   The `por` wall, measured again this wave (2026-10-20, worker 10 of
   the level 20 wave 4).  The retail's `por $v0,$zero,$zero` is a 128-bit
   zero materialised in the MMI register 2: cc1 prints that instruction
   `por $2,$0,$0` (the retail's listing prints the MMI register with the
   GPR names, so its `$v0` is the field 2, i.e. $f2).  Three measured
   facts:

   * THIS cc1 puts a TImode constant zero in a REGISTER only when the
     constant has TWO OR MORE uses.  With one use the reload assigns the
     value to register 0 - the RTL after reload is
     `(set (mem:TI ...) (reg:TI 0 $0))` (cc1 -dall, file x.i.sched2) -
     and emits no `por` at all: the store prints `sq $0`.  With two uses
     the reload picks register 2 and the body prints `por $2,$0,$0` plus
     one `sq $2` per use.  Measured: `*p = 0;` -> `sq $0,0($4)`;
     `*p = 0; *q = 0;` -> `por $2,$0,$0` + two `sq $2`.

   * The chain's `rac2_fold_zero_ti_store` deletes that materialisation
     again when the register is dead after the store.  Its guard scans
     FORWARD from the store and refuses to fold when a later instruction
     references the register - and the comparison is on the whole rtx, so
     the MODE matters: a later 32-bit use of the same register number
     does NOT keep the `por`, a later TImode use does.  Its backward
     scan looks for the materialisation in the same block, at most twelve
     instructions above the store; a call, a jump or a label between them
     stops the scan, so a store in another block than the materialisation
     keeps its `por` (that is the retail's shape in func_L20_00449178:
     the `por` sits in the delay slot of the `beqz` and the `sq` is in
     the block that branch goes to).

   * The ONE spelling that gets a materialised zero with a SINGLE store
     is the shared materialisation with the function value: with
     `int f(TI128 *p) { *p = 0; return 0; }` cc1 prints
     `por $2,$0,$0 ; j $31 ; sq $2,0($4)` - the `por` IS the return value
     (regno 2 is $v0), the store uses the same register, and the fold's
     guard sees the function-value use and refuses to fold.  It needs NO
     call between the store and the return: with one in between
     (`*p = 0; g(); return 0;`) the compiler re-materialises the zero for
     the return (`move $2,$0`) and the store goes back to `sq $0`.

   So the three bodies of this file keep their `por` only if the retail's
   source had a second use of the zero constant that costs no
   instruction of its own, or if the store sits in another block than the
   materialisation and the constant had two uses.  No spelling of that
   second use was found; the wall stands.
