/*
 * Updated manual-C near miss, 2026-10-25.
 * Measured unit: src/levels/02_maktar_nebula/L02_003F52B0.c
 * Profile: -O2 -G0 -ffunction-sections
 * Actual release coverage: US 0/1 (exit1); US2 0/1 (exit1); PAL 0/1 (exit1).
 * Current residual: 220/220 bytes. Case zero still differs in four address/store setup
 * words beginning at +0x5c. Approved qcopy and a genuine prefix view of the four-float
 * effect-position field preserve the remaining body; three forms tie.
 * Reopen only for: A concrete field/address lifetime hypothesis for the setup, not another
 * store permutation sweep.
 * Older notes below are historical. Marker and trial-only profiles were restored.
 */

#include "common.h"

/* Near miss (small-function wave, level 2): 220 bytes, level 2 only.  With the opt-in `-frac2-qcopy`
 * profile (#262) in a unit of its own (src/levels/02_maktar_nebula/L02_003F52B0.c, flags `-O2 -G0
 * -ffunction-sections -frac2-qcopy`) the C below is retail's 220 bytes (the earlier record, without
 * the profile, was 216: the copy folded its constant) with the copy through register addresses
 * (`addiu $a1,$v1,0xB0` ... `lq $v0,0($a1)` / `sq $v0,0($a0)`), and 14 of its 55 words differ
 * (tools/check.py: 0 of 1 places match, first difference at +0x54).  The switch, the frame, case 1,
 * the calls and the tail of case 0 are exact, including `lui $a0,0x1B ; lw $a0,-0x2BF0($a0)` for
 * D_L02_001AD410: that is the bare-symbol load the assembler expands in place, which the `sda`
 * attribute on a -G0 unit gives (without it: `lui $v0 ; lw $a0,0($v0)`, 17 words off).
 *
 * What differs is case 0 around the copy.  Retail:
 *     lui $v1,0x19 ... addiu $v1,$v1,-0x61E0 ; addiu $a1,$v1,0xB0 ; swc1 $f0,0xB4($v1) ;
 *     lui $a0,0x1B ; addiu $a0,$a0,0x3210 ; swc1 $f1,0xB8($v1) ; swc1 $f1,0xB0($v1) ;
 *     swc1 $f20,0xBC($v1) ; lq $v0,0($a1) ; sq $v0,0($a0) ;
 *     addiu $v1,$zero,0xFF ; daddu $a0,$s0,$zero ; jal func_L02_003F5390 ; sb $v1,0x30($s0)
 * Here the base `g` is in $v0, the stores are B0 B4 B8 BC with the source pointer after the first
 * of them, the destination pointer is in $v1, and the 0xFF constant (`$a1`) and `daddu $a0,$s0`
 * are scheduled above the copy.
 *
 * Cause: retail's copy was a volatile asm, a barrier for both scheduling passes, so the 0xFF byte
 * and the call's argument stayed behind it; `rac2_qcopy` is an ordinary insn, sched1 lifts them,
 * and the 0xFF constant, now live across the copy's `$v0`/`$v1` clobber, takes $a1 and pushes
 * the other registers around.  Measured in a scratch copy (not allowed in src/): with the copy as
 * one volatile asm, `__asm__ __volatile__("lq $2,0(%1)\n\tsq $2,0(%0)" : : "r"(D_L02_001B3210),
 * "r"(g + 0xB0) : "$2", "memory")`, everything after the stores is exact, g is in $v1 and the
 * allocation is retail's, but 4 of the 55 words still differ: the order of the four stores and of
 * the destination/source pointer set-up before the asm.  432 source variants in that scratch form
 * (the 24 orders of the four stores, the source pointer inline or in a local set before or after
 * the stores, the destination pointer likewise, either operand order) all stay at 4 words (the C
 * below gives `lui $a0 ; swc1 B4 ; addiu $a0 ; swc1 B0 ; addiu $a1,$v1,0xB0 ; swc1 B8 ; swc1 BC`
 * where retail has `addiu $a1,$v1,0xB0 ; swc1 B4 ; lui $a0 ; addiu $a0 ; swc1 B8 ; swc1 B0 ;
 * swc1 BC`).  So this one needs a barrier AND another spelling of the setup that was not found.
 * None of -fno-schedule-insns, -fno-schedule-insns2,
 * -fno-sched-interblock, -fno-gcse, -mno-split-addresses, -fno-strength-reduce, -g gets the
 * profile build below 14 words.
 *
 * Also tried, without the profile (216 bytes, all folded): the base as a pointer variable `g` with
 * `*(TI128 *)(g + 0xB0)`; the source as its own `TI128 *src` variable set before or after the
 * stores; `char *s = g + 0xB0`; the source as the constant `D_00189E20 + 0xB0`.
 *
 * What would unblock it: a barrier form of the profile (the pattern given a volatile asm's
 * dependences in sched_analyze_insn, as -frac2-zero-ti-barrier does for the clear), plus the store
 * order above.
 */


typedef int TI128 __attribute__((mode(TI)));

/* Prefix view of the effect-position field; not a complete global layout. */
typedef struct { char pad[0xB0]; float effect_position[4]; } EffectPositionView;
extern EffectPositionView D_00189E20;
extern char D_L02_001B3210[];
extern char *D_L02_001AD410 __attribute__((sda));
extern void func_L02_003F5390(char *);
extern void func_L02_003F54D8(char *);
extern void func_L02_003F56C0(char *);
extern void func_L02_003F5710(char *);
extern void func_002833B8(char *, float);
extern void func_002A7750(u8 *, s32, s32);

void func_L02_003F52B0(char *arg0) {
    switch (*(u8 *)(arg0 + 0x20)) {
    case 0: {
        EffectPositionView *g = &D_00189E20;

        g->effect_position[1] = 200.0f;
        g->effect_position[2] = 500.0f;
        g->effect_position[0] = 500.0f;
        g->effect_position[3] = 1.0f;
        qcopy(D_L02_001B3210, g->effect_position);
        *(u8 *)(arg0 + 0x30) = 0xFF;
        func_L02_003F5390(arg0);
        func_002833B8(D_L02_001AD410 + 0x40, 1.0f);
        func_002A7750(arg0, 1, -1);
        break;
    }
    case 1:
        func_L02_003F54D8(arg0);
        func_L02_003F56C0(arg0);
        func_L02_003F5710(arg0);
        break;
    }
}
