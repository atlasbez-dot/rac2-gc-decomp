/* Best attempt for func_L20_00449850 (404 bytes, 1 place) - NOT MARKED.
   G8: this body reaches $gp-relative data (D_L20_001B23E0, D_L20_001B23E4,
   D_L20_001B2AC8) and needs the -G8 profile, so it belongs in the -G8
   sibling of its unit (src/levels/20_yeedil/L20_00449850-g8.c), not in
   L20_00449178.c.

   ------------------------------------------------------------------
   Fourth attempt (wave w23, worker 16): 4 instructions differ, the size is
   the retail's 404 bytes, and the two remaining differences are both
   SCHEDULER decisions, not shape.  What is measured below, for the next
   worker:

   - the CHECK block is an if/else, and it fixes the three D_0018A3E0 reads
     and the D_L20_001B2AC8 pair (wave 4's finding, confirmed here):

         if (D_0018A3E0 == (int)arg0) {
             *(volatile u32 *)(state + 0xAC) = 1;
             v = D_001B2AC8;        (the absolute form)
         } else {
             v = D_L20_001B2AC8;    (the $gp form)
         }
         if ((v & 0xF) == (((int)arg0 >> 8) & 0xF)) {

     the global on the LEFT of the comparison is what gives retail's
     `bnel $v1,$v0`; with the arg0 on the left the branch comes out
     `bnel $v0,$v1`.  (The same shape is in the matched
     src/levels/20_yeedil/L20_0039C448.c, func_L20_0039D7B0.)

   - the mode 0 block is (the wave-4 shape, reproduced and confirmed):

         t0 = D_L20_001B23E0;
         t4 = D_L20_001B23E4;
         *(u16 *)(state + 0x24) = 1;
         *(float *)(state + 0x20) = 1.0f;
         *(u32 *)(state + 0x70) |= 6;
         *(float *)(state + 0x84) = t0;
         *(float *)(state + 0x88) = t4;

     which gives retail's float registers ($f0 = D_L20_001B23E4,
     $f1 = 1.0f, $f2 = D_L20_001B23E0), retail's load order (D_L20_001B23E0
     first, then D_L20_001B23E4), retail's store order but for one pair, and
     retail's delay-slot store (the 0x84 store in the jal's delay slot).

   - WHAT STILL DIFFERS (4 instructions):

         004498E8  sh    $a1, 0x24($s1)  | swc1  $f1, 0x20($s1)
         004498EC  swc1  $f1, 0x20($s1)  | sh    $a1, 0x24($s1)
         00449950  andi  $v1, $v1, 0xF   | andi  $v0, $v0, 0xF
         00449954  andi  $v0, $v0, 0xF   | andi  $v1, $v1, 0xF

     (1) the mode 0 block stores 0x24 before 0x20; retail stores 0x20
         first.  Swapping the two statements in the source gives retail's
         store order BUT swaps retail's float registers (the constant then
         takes $f0 and D_L20_001B23E4 $f1) - the two goals are in tension
         and no statement order reaches both (see below).
     (2) the two mask andis are in the other order: retail masks the
         arg0 side first, this cc1 masks the global first.  The RTL is the
         same either way (the source's operand order), so this is the
         SCHEDULER's choice, and it is the same in every spelling tried.

   - WHY the float registers follow the source (measured, and it is a rule
     worth knowing for other bodies): gcc 2.x's local allocator sorts the
     quantities of a basic block by
         QTY_CMP_PRI(q) = floor_log2(n_refs) * n_refs * size
                         / (qty_death - qty_birth)
     (gcc/local-alloc.c) and gives the registers out in that order, so the
     SHORTEST live range gets $f0 and the longest $f2 (ties go to the
     lower quantity number, i.e. the order the pseudo appears in the
     block).  The three values of the mode 0 block therefore have to be
     live in the order  D_L20_001B23E4 (shortest) < 1.0f < D_L20_001B23E0
     (longest) to land in $f0, $f1, $f2.  The live ranges are set by where
     the STORES end up, and the stores' order is what the source decides
     - that is the tension of (1): with 0x20 before 0x24 the constant is
     materialised right before its store, its live range becomes the
     shortest, and it takes $f0.

   - the two mask andis: the scheduler (gcc/sched.c, the old scheduler
     with `rank_for_schedule`) always emits the global's andi before the
     arg0's andi here, whatever the source.  Tried and measured, all
     giving the same order: the global on the left of the comparison, the
     arg0 on the left, the mask in its own statement
     (`m = ((int)arg0 >> 8) & 0xF;`), the shift in its own statement, the
     mask on the global, both in their own statements, the global as
     unsigned/char/short/long, the mask constant as 0xF or 15, the shift
     signed or unsigned, and the whole comparison written with `!=` and a
     goto.  The RTL is identical in all of them, so this looks like a
     compiler-side difference (the retail's scheduler put the arg0's andi
     first).

   - the search that reached this state (all of it with the relocation
     check too, so a swapped pair of global loads is caught - a plain byte
     comparison hides them): every order of the three float reads and the
     five stores of the mode 0 block (8! = 40320), every mix of inline and
     temporary reads over every order of the resulting statements (57720),
     every order of the five effects with up to two temporaries in any of
     six slots (28200), and the same with the three temporaries in seven
     slots (12348) - about 150000 source shapes in all.  The best is 4
     instructions; nothing reached 3.

   - flags tried on the -G8 unit, none of them closer: -fno-schedule-insns
     (much worse), -fno-schedule-insns2, -fno-sched-interblock,
     -fno-gcse, -fno-expensive-optimizations, -O3, -mno-split-addresses
     (396 bytes), -O1 (412 bytes).

   ------------------------------------------------------------------
   The C below is the wave-5 attempt (the mode 0 block and the CHECK block
   of the fourth attempt above).  The attempts before it, in order:
   wave 1 (w20-11) had the size right and 14 instructions wrong, wave 2
   (w20-11) fixed the volatile store and the frame, wave 3 (w21-10) fixed
   the float registers and the delay-slot store but left the store order
   and the two andis, wave 4 (w23) fixed the CHECK block, and wave 5
   (w23-16, this file) measured the rule behind the float registers and
   searched about 150000 source shapes for the last two differences. */

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef int TI128 __attribute__((mode(TI)));

/* an external global in a -G8 file: no attribute at all, that is what gives
   retail's absolute form */
extern int D_L20_001A8F00;

extern int D_0018A3E0 __attribute__((nosda));

extern float D_L20_001B23E0 __attribute__((sda));

extern float D_L20_001B23E4 __attribute__((sda));

extern int D_L20_001B2AC8 __attribute__((sda));

extern int D_001B2AC8;

extern void func_L20_00449A78(char *);

extern void func_L20_00449AE8(char *);

extern void func_L20_00449BB0(char *);

/* the interleaved prototype reproduces retail's argument setup order */
extern void func_L01_0031AB20(float, char *, float, char *, float, int);

extern float func_002A89A8(char *, int, float);

extern float func_00282C48(float);

extern int func_00282948(char *);

void func_L20_00449850(char *arg0) {
    int g = D_L20_001A8F00;
    char *state = *(char **)(arg0 + 0x68);
    int mode;
    int v;
    float f;
    float t0, t4;

    if (g == 2) {
        if (*(u8 *)(arg0 + 0x20) != 1) {
            func_L20_00449A78(arg0);
        }
    }
    mode = *(u8 *)(arg0 + 0x20);
    if (mode == 1) {
        return;
    }
    if (mode >= 2) {
        goto B8;
    }
    if (mode == 0) {
        goto C8;
    }
    goto CHECK;
B8:
    if (mode == 2) {
        goto G;
    }
    goto CHECK;
C8:
    t0 = D_L20_001B23E0;
    t4 = D_L20_001B23E4;
    *(u16 *)(state + 0x24) = 1;
    *(float *)(state + 0x20) = 1.0f;
    *(u32 *)(state + 0x70) |= 6;
    *(float *)(state + 0x84) = t0;
    *(float *)(state + 0x88) = t4;
    func_L20_00449A78(arg0);
    return;
G:
    func_L01_0031AB20(0.0f, arg0, 0.5f, state + 0x50, 0.6f, *(int *)(state + 0xA0));
    goto CHECK;
CHECK:
    if (D_0018A3E0 == (int)arg0) {
        *(volatile u32 *)(state + 0xAC) = 1;
        v = D_001B2AC8;
    } else {
        v = D_L20_001B2AC8;
    }
    if ((v & 0xF) == (((int)arg0 >> 8) & 0xF)) {
        f = func_002A89A8(arg0 + 0x10, 0, 0.5f);
        f = *(float *)(arg0 + 0x18) - f;
        if (5.0f < func_00282C48(f)) {
            goto L499B8;
        }
    }
    if (*(u32 *)(state + 0xAC) == 0) {
        goto L499C8;
    }
    if (func_00282948(state + 0xA8) == 0) {
        goto L499C8;
    }
    goto L499B8;
L499B8:
    func_L20_00449AE8(arg0);
    goto END;
L499C8:
    func_L20_00449BB0(arg0);
END:
    return;
}
