/* 0 of 1 place match - 356 bytes against retail's 372; last line of tools/check.py:
   02_maktar_nebula: 356 bytes, expected 372
   Same wall as func_L23_0041C0E8: this cc1's GCSE is alias-aware, retail's reloads.

   Steps an actor along the path its state names (state +0x00 picks the table entry, +0x30 is the
   current point, +0x34 a running value clamped to 0..14): it measures the distance from
   D_00189EA0 to the current point (cur), then to the next point; when the next one is nearer it
   adds the current point's fourth float to +0x34, clamps it to 14.0, bumps the point index and
   returns the new distance; failing that it tries the previous point the same way (subtracts,
   clamps at 0.0, drops the index); else it returns cur. The caller (func_L02_003EE938) stores the
   float into +0x44 of the state. The entry is the one func_L02_003EEAD8 fills: a count and
   16-byte points from +0x10 whose fourth float is the distance to the next point.

   Everything matches retail word for word except the two tails after the clamps. Retail reloads
   the index after the clamp's join:
       swc1 f1,0x34(s0) ; swc1 f3,0x34(s0) ; lw v0,0x30(s0) ; mov.s f0,f2 ; addiu v0,v0,1 ;
       b epilogue ; sw v0,0x30(s0)
   (and the same with -1): two five-instruction tails, 372 bytes. This cc1 keeps the value of the
   first load of +0x30 (the one that scales the point address, just after the second call) in a
   register across the clamp and writes `addiu v0,v1,1`; the two tails then end in the same
   `mov.s f0,f2 ; b ; sw v0,0x30(s0)` and cross-jumping merges them: 356 bytes.

   Cause, measured with -dG: the GCSE pass (PRE) finds the index load after the clamp's join
   partially redundant (the store to +0x34 in the then-block ends the first load's availability
   inside the block, but a store to a disjoint offset of the same base does not kill it on the
   other path) and inserts a copy of the load before the clamp's `bc1f` ("PRE/HOIST: end of bb 2
   ... copying expression 9"); cse2 then forwards it. The same GCSE hoists `lui $a0,%hi(D_00189EA0)`
   into $s3 for the third call, exactly as retail does (`daddu $s3,$a0,$zero`, `addiu
   $a0,$s3,-0x6160`), so retail ran GCSE; only its PRE of the index load did not happen. A store
   that may alias +0x30 (a global, an entry-based address, the same offset) blocks the PRE here;
   retail has none, so its GCSE must treat the disjoint store as killing the load.
   Diagnostic, not a candidate (src/ allows no volatile): making only the read of the index in
   the two updates volatile, `state->idx = *(volatile int *)&state->idx + 1;`, gives 372 bytes
   and 0 words different (checked with the struct-typed body below). The struct-typed spelling is
   also what gives retail's `addu v0,s1,v0` operand order in the clamps; casts give `addu v0,v0,s1`.
   With -fno-gcse the clamps and tails come out as retail's (364 bytes) but the third call
   rematerialises the address and $s3 is gone.

   Tried, all 356 bytes (or worse): casts against struct members, `entry->pts[i].w` and locals for
   the index; the clamp as `t = ...; if (t > 14) t = 14; state->t = t` (bc1tl layout, wrong); the
   clamp as if/else (bc1fl, wrong); a second name for the state pointer (cprop folds it back);
   struct, cast and array-subscript mixes for the index (no effect on the PRE); no per-file flag
   or pair of flags from the usual list gets nearer (-g, -fno-gcse, -fno-rerun-cse-after-loop,
   -fedge-lcm, -fno-expensive-optimizations, -fno-schedule-insns{,2}, -fno-sched-interblock,
   -fno-cse-follow-jumps, -fno-cse-skip-blocks, -fno-regmove, ...).
   What would unblock it: a compiler-side switch for the older "any store kills every load" GCSE
   (it would also serve func_L23_0041C0E8), or a plain-C spelling of a may-alias write that leaves
   no instruction behind (none found). */

#include "include_asm.h"

typedef struct {
    float x, y, z, w;
} V4;

typedef struct {
    int count;
    int pad[3];
    V4 pts[1];
} Entry;

typedef struct {
    int id;
    char pad04[0x2C];
    int idx;
    float t;
} State;

extern char *D_L02_001FF1C0[];
extern char D_00189EA0[];
extern float func_00282E80(char *, char *);

float func_L02_003EEC58(char *arg0) {
    State *state = *(State **)(arg0 + 0x68);
    Entry *entry = (Entry *)D_L02_001FF1C0[state->id];
    float cur = func_00282E80(D_00189EA0, (char *)&entry->pts[state->idx]);
    float d;

    if (state->idx < entry->count - 1) {
        d = func_00282E80(D_00189EA0, (char *)&entry->pts[state->idx + 1]);
        if (d < cur) {
            state->t += entry->pts[state->idx].w;
            if (state->t > 14.0f)
                state->t = 14.0f;
            state->idx += 1;
            return d;
        }
    }
    if (state->idx > 0) {
        d = func_00282E80(D_00189EA0, (char *)&entry->pts[state->idx - 1]);
        if (d < cur) {
            state->t -= entry->pts[state->idx].w;
            if (state->t < 0.0f)
                state->t = 0.0f;
            state->idx -= 1;
            return d;
        }
    }
    return cur;
}
