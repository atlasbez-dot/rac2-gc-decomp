/* Near miss (shared by levels 2 and 26): 476 bytes, retail's size at both places.  Every word
 * of the function is retail's except two delay-slot choices in the second loop (the state 1 case).
 * Everything else was verified word for word with the relocations resolved (check.py first
 * differs at +0xF8): the 0x80 frame saving $s0-$s3/$ra/$f20, the switch on the byte at +0x20
 * (case 0, then case 1, both leaving through the shared epilogue), the `sb 0xFF` store, the
 * first loop (the `daddu $a2,$v1,$zero` copy of the table pointer and the `lw $a3` pool base
 * hoisted ahead of the loop, `b` to the test chain, `bnel` back with the `lwc1` in its slot),
 * the second loop's chain, the $gp float, the 1/60 step and the wrap at 1.0.
 *
 * The two differences, both inside loop 2 (the 64-byte records):
 *   1. Loop-back branch.  Retail keeps `sq $zero,0($sp)` as the first instruction of the loop and
 *      ends the chain with a plain `bnez $s1,loop` whose slot is `lwc1 $f0,gp` (taken from the
 *      fall-through).  This cc1 copies the loop's first instruction into an annulled slot instead:
 *      `bnel $s1,$zero,loop+4` + `sq $zero,0($sp)`, and the `sq` is gone from the loop top (the
 *      branch targets the next word, everything below it shifts by one).
 *   2. First call (func_002833F0).  Retail leaves `swc1 $f20,8($sp)` before the `jal` and fills the
 *      slot with the following `addiu $s0,$s0,2` (p++); this cc1 moves the `swc1` into the slot
 *      and leaves p++ after the call.  (Corrected 21 October 2026: this one is sched2's, not
 *      reorg's; see "Second retry" below.)
 *
 * (1) is a measurable compiler difference, not a spelling.  In the 27 retail programs 14,308 stores
 * sit in the delay slot of a branch-likely (beql/bnel/bgezl...): all of them sw, swc1, sh or sb.
 * Not one is a doubleword or quadword store (sd, sq, sdr, sdc2), although the same programs have
 * 6,231 sd, 899 sq, 162 sdr and 1,296 sdc2 in ordinary branch slots.  This cc1 puts them there:
 * a loop with `*(TI128 *)buf = 0; callee(m, buf);` at its top gives `bnel $2,$0,top ; sq $0,0($17)`
 * (and `sd $0,0($17)` for a long long), exactly the shape above.  Without the annulled copy the
 * delay slot pass falls back to the fall-through thread and takes the `lwc1`, which is retail's
 * word.  Rejecting 64- and 128-bit stores in annulled slots (eligible_for_annul_*) is the
 * candidate compiler change.  I could not find a C spelling that avoids it: while/for/do
 * shapes, the increment before, between or after the calls, the call return types, extra
 * statements before the zero store all give the same two slots.
 *
 * What does match, for the next worker (all measured here):
 *   - The pool bases and the group table are plain `extern` pointer scalars with no attribute:
 *     in this -G8 unit that gives the bare `lw $r,sym` macro (absolute, `lui`/`lw`) and a scalar
 *     MEM, so loop.c/gcse hoist both loads out of loop 1 despite its float store through the
 *     record pointer (retail's `daddu $a2,$v1,$zero`, `lw $a3`).  `sda` arrays (the `X[0]`
 *     habit) are struct-like MEMs and do not hoist; `nosda` gives the split lui/lw form and
 *     pulls the `lui` into callee-saved registers.  Only the $gp float carries `sda`.
 *   - The record pointer of loop 1 must be a struct pointer (Rec32) for the `e->w` access.
 *   - `u8 none = 0xFF; a0[0x30] = none;`: with a plain `a0[0x30] = 0xFF` the allocator shares
 *     $v0 with the -1 of the test above and reload deletes the `li 255` (retail keeps
 *     `addiu $v0,$zero,0xFF` in the delay slot of the `beq`).
 *   - `float m[12]` (48 bytes) and `float v[4]` give the 0x40-byte local area; `m` is the matrix
 *     func_002833F0 fills, `v` the quadword zeroed with `*(TI128 *)v = 0` and given its z by
 *     `v[2] = 0.00785398297f` (0x3C00ADFE).
 *   - The 1/60 step is the decimal 0.016666668f (0x3C888889).
 * Tried without effect on the two slots: -fno-schedule-insns, -fno-schedule-insns2,
 * -fno-sched-interblock, -fno-gcse, -fno-strength-reduce (none changes them; -mno-split-addresses
 * matches the preheader but breaks the `lh -2($a1)` offset).
 *
 * Names: the placed copy would live in L02_00410450-g8.c (it reads a float through $gp), in
 * address order after func_L02_00422538, with this comment in place of the marker in
 * L02_00410450.c.  The pool symbols are D_L02_xxxxxxxx names of level 2; at level 26 they are
 * where its bytes read (0x1B2294, 0x1B229C, 0x1AD3D0, gp+0x1D50), and check.py accepts them.
 * The two callees are boot functions with a copy in every level (the catalogue places
 * func_002833F0 at 02:002F27F0 and 26:002EEB70), so their boot names are right.
 *
 * Second retry (21 October 2026, Opus), with the -dR -fsched-verbose-5 and -dd dumps and the
 * pass sources read: both differences are pass decisions that no spelling reaches.
 *   (2) is sched2's.  reorg's backward scan from a direct `jal` takes the nearest insn before
 *       it whatever it is: the call's own needed set is empty (mark_referenced_resources with
 *       include_delayed_effects 0 skips the address MEM and the argument USEs) and its set is
 *       only $ra, so `swc1`, `daddu $a0`, `daddu $a1` are all eligible.  Retail's slot therefore
 *       means retail's sched2 issued p++ just before the jal.  Here the body block ends with the
 *       second call plus the `(use (const_int 0))` that flow (count_basic_blocks) puts after a
 *       call ending a block; haifa makes every insn without dependents precede that tail group,
 *       so p++ has priority 3 (its only dependent is the second call) against 5 for the first
 *       call (jal1 -> `a0 = e` -> `a1 = a0` -> jal2 -> use; every link costs at least 1 in this
 *       haifa).  p++ has no predecessors, but it only wins the cycle-3 tie if its priority beats
 *       the call's, which needs a dependent of priority 5 in the block: nothing in the body reads
 *       p after it (the test is a block of its own, the `b` entry target).
 *   (1) is reorg's.  mostly_true_jump gives the `bnez $s1` loop-back 1 (an NE test; the
 *       LOOP_BEG note is not next to the label, the entry `b` and its barrier sit between), so
 *       fill_eager_delay_slots tries the target thread first and the `sq` passes
 *       eligible_for_annul_false.  Retail's `lwc1` is the fall-through thread's first insn,
 *       which this reorg only reaches when the target yields nothing (the exit label is gone by
 *       then: both test branches were redirected past the copied `lwc1`).  `__builtin_expect`
 *       (the CYGNUS condjump_expect_p path in mostly_true_jump) cannot steer it either:
 *       mips.md has no `expect` pattern, so no EXPECT rtx is ever made.
 *   Measured, each 476 bytes with the same two slots (30 words, the shift included): p++ as
 *   the `for` increment, first in the body, after the zero store, after the z store, between
 *   the calls, last in the body; a `while` loop with p++ in the body; the vector written
 *   through a TI/float union.  Per-file flags on the same C: -fno-schedule-insns 480 bytes,
 *   -fno-schedule-insns2 476 bytes but 47-49 words (loop 1 and the prologue move), both 80+.
 *   What would unblock it: a reorg.c change that refuses 64/128-bit stores in annulled slots
 *   and stops the thread search (measured neutral: the 766 functions then matched still
 *   match) for (1), plus a sched2 change that issues p++ before the first call for (2).
 *   Neither is a source shape.
 */

typedef unsigned char u8;

typedef int TI128 __attribute__((mode(TI)));

typedef struct {
    float x, y, z, w;
    float pad[4];
} Rec32;

extern unsigned short **D_L02_001A9014;

extern Rec32 *D_L02_001B3C14;

extern u8 *D_L02_001B3C1C;

extern u8 *D_L02_001AD410;

extern float D_L02_001B2434 __attribute__((sda));

extern void func_002833F0(void *, void *);
extern void func_00283738(void *, void *, void *);

void func_L02_0042EDD0(u8 *a0) {
    int *s = *(int **)(a0 + 0x68);

    switch (a0[0x20]) {
    case 0: {
        unsigned short *p;
        Rec32 *e;
        u8 none = 0xFF;

        if (s[0] == -1)
            break;
        a0[0x30] = none;
        for (p = D_L02_001A9014[s[0]];
             p != 0 && ((p != 0 && (short)p[-1] >= 0) || p == D_L02_001A9014[s[0]]) &&
             (e = D_L02_001B3C14 + (*p & 0x7FFF)) != 0;
             p++)
            e->w = e->w + e->w;
        a0[0x20] = 1;
        break;
    }
    case 1: {
        unsigned short *p;
        u8 *e;
        float v[4];
        float m[12];
        float x;
        u8 *g;

        for (p = D_L02_001A9014[s[0]];
             p != 0 && ((p != 0 && (short)p[-1] >= 0) || p == D_L02_001A9014[s[0]]) &&
             (e = D_L02_001B3C1C + ((*p & 0x7FFF) << 6)) != 0;
             p++) {
            *(TI128 *)v = 0;
            v[2] = 0.00785398297f;
            func_002833F0(m, v);
            func_00283738(e, e, m);
        }
        g = D_L02_001AD410;
        x = *(float *)(g + 0x74) + D_L02_001B2434 * 0.016666668f;
        *(float *)(g + 0x74) = x;
        if (x > 1.0f)
            *(float *)(g + 0x74) = x - 1.0f;
        break;
    }
    }
}
