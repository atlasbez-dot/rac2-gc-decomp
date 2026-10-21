/* func_L03_003C5668 (644 bytes, 2 places: levels 3 and 14) -- NEAR MISS, not integrated.
   state: 640 bytes against 644 when built as a unit of its own with `-frac2-qcopy` (636
   without it). The control flow, the id-list walk, every call, every constant and every
   register of the loop match retail; what differs is instruction ORDER (and the one delay
   slot it changes), at both places alike:
   - retail's grouped 16-byte copy is a scheduling barrier and `-frac2-qcopy` is not (the known
     wall 2). The three copies here (the stack vector `vec`, then `*a2` and `*a1` at the end)
     let `daddu $a0,$sp,$zero` move above the `lq` into the `bc1f` slot (retail's slot holds
     `lw $a2,0x1C($sp)`, hence the 4 bytes), and let the second copy's `addiu`, the `lw $a3,
     0x10($sp)` and the `lui/mtc1 $f12` float above the first output copy; the two spill slots
     0x1C and 0x20 (ids base copy, `i + 1`) also come out swapped (their pseudos come from gcse,
     which sees the copies differently). With the three copies written as `asm volatile ("lq
     $2,0(%1); sq $2,0(%0)" ...)` in a SCRATCH copy, the spill slots, the whole loop and the
     vector block are retail's; only the next item and the epilogue's reload registers remain
     (the asm operands change those, so that scratch says nothing about them).
   - `sw $a1,0x10($sp)` is retail's SECOND instruction (right after `addiu $sp`), here the
     ninth, among the callee-saved saves; `sw $a2,0x14($sp)` is at retail's place. In sched2
     (-fsched-verbose-5) the spill and the first five saves (s0, s4, s6, s7, f21) have the
     same priority (14, through the two loads before the first call) and the same number of
     dependents (5), so stream order decides and the saves go first; retail ranks the spill
     ahead of all of them. No spelling tried moved it, and the copies are not the cause (it
     is in the first block, ahead of every copy).
   What is right and measured:
   - the first call's argument is a fresh load of the target (`lw $a1,0x354($s5)`,
     `addiu $a1,$a1,0x10`), the candidate is a second load after the call (`lw $s4,0x354`),
     and `best` a third one after func_L03_00419BD8: three reads of `o->target`, as written
     here (one local would share the first load and the `+ 0x10`).
   - `func_00277258`'s argument order (vec, 0, 0.5f, self) is the order the setup takes in
     retail; the epilogue copies `*a2` first, then `*a1`, and func_002A89A8's result goes to
     `a1[2]`, a1 is returned.
   - `s4` is the candidate (updated before func_L03_00419BD8 is called, as `daddu $s4,$s1`
     in its delay slot shows), `best` moves with `movn`, and `if (best) cand = best` is the
     `movn $s4,$s7,$s7` before the copies.
   Tried without getting closer: `float vec[4]` and a `TI128` local; `vec[2] += 1.0f`,
   `vec[2] = vec[2] + 1.0f` and `1.0f + vec[2]`; four prototype orders of func_00277258; the
   outer loop as `for`, `while`, `do/while`, with an `unsigned` counter, and with `ids` as a
   local pointer (604 bytes: the spills vanish, which retail has); `const` on the state load;
   `-fno-schedule-insns` (608), `-fno-schedule-insns2`, `-fno-gcse` (672),
   `-fno-sched-interblock`, `-frac2-gcse-unsplit-edges`, `-frac2-keep-block-order` (all
   worse or equal to the plain `-frac2-qcopy` profile). */

typedef int TI128 __attribute__((mode(TI)));

extern unsigned char *D_L03_001B2A1C __attribute__((sda));

extern int D_L03_001B2A38[] __attribute__((sda));

extern unsigned short *D_L03_001FB5A0[];

extern int func_L03_00419BD8(unsigned int, void *, void *);

extern float func_00282E80(void *, void *);

extern float func_00282E48(void *, void *);

extern int func_00277258(void *, int, float, void *);

extern float func_002A89A8(void *, int, float);

/* the part of the object's private state (at +0x68) that this walk reads: eight group ids at
   +0x200, the id of an entity at +0x220 and the current target at +0x354 */
typedef struct {
    unsigned char pad0[0x200];
    int ids[8];
    unsigned int ref220;
    unsigned char pad1[0x354 - 0x224];
    unsigned char *target;
} L03SeekState;

/* Looks, over the object's eight groups, for the entity of class 0x972 nearer than the current
   target (nearest so far) that has an unobstructed line (func_00277258 on its position raised
   by 1.0) and that func_L03_00419BD8 accepts; writes the chosen entity's vectors at +0xF0 and
   +0x10 to a2 and a1, puts the result of func_002A89A8 in a1[2], and returns a1. The current
   target stays the answer when nothing better is found. */
float *func_L03_003C5668(unsigned char *a0, float *a1, float *a2) {
    L03SeekState *o = *(L03SeekState **)(a0 + 0x68);
    unsigned short **tbl = D_L03_001FB5A0;
    unsigned char *cand;
    unsigned char *best = 0;
    unsigned char *e;
    unsigned short *q;
    float bestd;
    float d;
    float vec[4];
    int r;
    int i;

    bestd = func_00282E48(a0 + 0x10, o->target + 0x10);
    cand = o->target;
    if (func_L03_00419BD8(o->ref220, a0 + 0x10, cand + 0x10))
        best = o->target;
    for (i = 0; i < 8; i++) {
        for (q = tbl[o->ids[i]];
             (o->ids[i] & 0xFF) != 0xFF && o->ids[i] <= D_L03_001B2A38[0] && q != 0 &&
             ((short)q[-1] >= 0 || q == tbl[o->ids[i]]);
             q++) {
            e = D_L03_001B2A1C + ((*q & 0x7FFF) << 8);
            if (e == 0)
                break;
            if (*(short *)(e + 0xAA) == 0x972) {
                d = func_00282E80(a0 + 0x10, e + 0x10);
                if (d < bestd) {
                    *(TI128 *)vec = *(TI128 *)(e + 0x10);
                    vec[2] += 1.0f;
                    if (func_00277258(vec, 0, 0.5f, a0) == 0) {
                        cand = e;
                        r = func_L03_00419BD8(o->ref220, a0 + 0x10, e + 0x10);
                        bestd = d;
                        if (r)
                            best = cand;
                    }
                }
            }
        }
    }
    if (best)
        cand = best;
    *(TI128 *)a2 = *(TI128 *)(cand + 0xF0);
    *(TI128 *)a1 = *(TI128 *)(cand + 0x10);
    a1[2] = func_002A89A8(a1, 0, 0.5f);
    return a1;
}
