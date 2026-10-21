/* NEAR MISS, level 7 (siberius), func_L07_00378898: retail's 580 bytes, 122 of 145 words in
   place (137 aligned), 0 of 1 places; tools/check.py: "instruction at +0x90 differs".
   Measured on 21 October 2026 with the compiler of #258 (flow fix, opt-in clear profile).

   The C below, built as a function of a -G8 unit (it takes `addiu $v0,$gp,-0x3F8` for the speed
   table) with -frac2-zero-ti-barrier, gives everything but two spots:
     - the skip of an empty group: retail `beq $v0,$fp,NEXT` with `addiu $s7,$s2,1` in its slot,
       where NEXT (`daddu $s2,$s7,$zero`) is shared with the walk exits; here
       `bne $v0,$fp,ANGLE ; b TEST ; addiu $s2,$s2,1`;
     - after the angle call retail recomputes the group address (`addu $a0,$s6,$s4`, between
       the two `swc1 $f0`) where this C keeps the first one in $s1 across the call.
   Without -frac2-zero-ti-barrier (plain -G8: 130 words in place, 134 aligned) `sq $zero,0($sp)`
   comes out just before the call instead of first in the block (retail: first, the barrier
   shape). `__attribute__((nosda))` on
   D_L07_001C9780 is what gives retail's `lui $v0 ; lw $v1,%lo($v0)` (plain: `lw $v0`).

   Diagnosis (from the -da dumps; gcc/cse.c, gcse.c, jump.c of the shipped source):
     - gcse's PRE moves the walk's next index `i + 1` (reg 174, retail $s7) out of NEXT and
       inserts it at the end of the group-test block AND at the end of the angle block (the walk
       pre-header, before `b TEST`). Retail keeps both copies: they are the two delay slots.
     - With the natural `for (...) { if (g[i] == -1) continue; ... }` (572 bytes, the earlier
       record), cse2 sees the test block and the angle block as one extended block (the angle
       block is the fall-through, no label), turns the second copy into `reg174 = reg174` and
       deletes it; `i` then dies before the call (in $a0, not $s2) and everything shifts.
       cse1 likewise reuses the first group address after the call.
     - cse_end_of_basic_block ends an extended block only at a CODE_LABEL (and, in cse1 only,
       at NOTE_INSN_LOOP_END), and follows a conditional jump into its target when the label
       has one use and a BARRIER before it. So retail needs, in BOTH cse passes, the angle
       block to start a new extended block (a label that is not followed), while the test
       block's skip edge still goes to the shared NEXT; no jump into the angle block exists in
       the final code, so the label's last use must disappear after cse2.
     - Probes (not plain C, measurement only): a label kept alive at the start of the angle
       block (a static array of `&&label`) puts `i` in $s2 and keeps the second copy; the C
       below with -fno-cse-follow-jumps -fno-cse-skip-blocks reproduces the whole angle block
       word for word (the skip path then is the only difference). The increment duplicated
       into the skip path (below) is what gives the angle block its label: the walk side then
       matches exactly, but cse still follows the branch into it (one use, barrier before it).
     - No matched function in src/ carries this pattern (scan of all level programs for an
       `addiu $sX,$sY,1` in a conditional branch's delay slot and again in a `b`'s slot after
       a jal): only this function. func_L07_0040FC88 keeps such copies because each sits in a
       jump-table case block (cse never follows a tablejump).

   Tried without reaching the shared skip path and the recomputed address together: every
   spelling of the outer loop with one increment (for/continue, for/if, while/if, do/if,
   do/continue, `i <= 2`, `i != 3`, while(1)/break, `for (;;)` with the break at the end, a
   goto skip), all identical (572 bytes); the increment duplicated into the skip path (for,
   while, do: 580 bytes, the C below); an explicit next-index variable set on both paths (580
   bytes, `s7 = i + 1` lands in the `b` slot, the address is still reused) or at the top (572);
   the walk with `if (e == 0) break;`, with `(e = ...) != 0` in its condition, and with the
   macro's double `p != 0`; goto layouts that put the angle block out of line (merged back
   early, or the test stays at the bottom); every allowed per-file flag (-g,
   -mno-split-addresses, -fno-schedule-insns(2), -fno-gcse, -fno-strength-reduce,
   -fno-rerun-cse-after-loop, -frac2-zero-ti-barrier); five spellings of the flag test.
   What would unblock it: a plain-C shape that leaves a label (not followable by cse) at the
   start of the angle block through cse2 and disappears afterwards, with the skip branch still
   going straight to NEXT. */

#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

extern void func_002A7750(unsigned char *, int, int);
extern float func_00283B98(float, float);
extern float func_00282DF0(void *);
extern void func_002833F0(void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_L00_0036AE00(int, int);

extern int D_L07_001C9780 __attribute__((nosda));
extern unsigned short **D_L07_001A9014;
extern unsigned char *D_L07_001B295C;
extern float D_L07_001AEBF8[2] __attribute__((sda));

typedef struct {
    int groups[3];
    float angles[3];
} RotState;

void func_L07_00378898(unsigned char *a0)
{
    RotState *s6 = *(RotState **)(a0 + 0x68);
    int i;
    unsigned short *p;
    unsigned char *e;
    float v[4];
    float loc[3];
    float *q;
    int k;
    int m;
    float t;
    float ang;

    switch (a0[0x20]) {
    case 0:
        a0[0x30] = 0xFF;
        func_002A7750(a0, 1, -1);
        break;
    case 1:
        if (D_L07_001C9780 != 0)
            return;
        for (i = 0; i < 3;) {
            if (s6->groups[i] == -1) {
                i++;
                continue;
            }
            *(TI128 *)v = 0;
            ang = func_00283B98(s6->angles[i], D_L07_001AEBF8[i] * 0.00029088824f);
            s6->angles[i] = ang;
            v[2] = ang;
            for (p = D_L07_001A9014[s6->groups[i]];
                 p != 0 && ((short)p[-1] >= 0 || p == D_L07_001A9014[s6->groups[i]]);
                 p++) {
                e = D_L07_001B295C + ((*p & 0x7FFF) << 6);
                if (e == 0)
                    break;
                q = loc;
                for (k = 0; k < 3; k++)
                    q[k] = *(float *)(e + 0xC + k * 16);
                t = func_00282DF0(e);
                func_002833F0(e, v);
                func_00282F20(e, e, t);
                func_00282F20(e + 0x10, e + 0x10, t);
                for (m = 0; m < 3; m++)
                    *(float *)(e + 0xC + m * 16) = q[m];
                func_L00_0036AE00(*p & 0x7FFF, 1);
            }
            i++;
        }
        break;
    }
}
