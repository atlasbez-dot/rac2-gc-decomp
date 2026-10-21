/* Near miss (level 2, one place), 336 bytes.  With the opt-in `-frac2-qcopy` profile (#262) in a unit
 * of its own (src/levels/02_maktar_nebula/L02_003D47B0-g8.c, flags `-O2 -G8 -ffunction-sections
 * -frac2-qcopy`; -G8 for D_L02_001B01C0 at `$gp + 0x11D0`) the C below is retail's 336 bytes with
 * retail's copy (`addiu $a2,$s1,0x10` / `addiu $a1,$gp,0x11D0` / `lq $v0,0($a1)` / `sq $v0,0($a2)`),
 * and 21 of its 84 words differ (tools/check.py: 0 of 1 places match, first difference at +0x98).
 *
 * One C detail was wrong in the previous record and is corrected below: retail stores
 * `sh $zero,0x31A($s0)` in the delay slot of `jal func_L02_003D5570`, so that store is written
 * BEFORE the call (the old order had it after, and was 28 words off).  The tail from the call on is
 * now exact.
 *
 * What still differs is the stretch around the copy.  Retail: the destination pointer
 * (`addiu $a2,$s1,0x10`), the source pointer, the flag stores, the copy, then
 *     lui $v1,0x19 ; lwc1 $f1,0x10($s1) ; addiu $v1,$v1,-0x61E0 ; lwc1 $f0,0x14($s1) ;
 *     lwc1 $f13,0x84($v1) ; lwc1 $f12,0x80($v1) ; sub.s $f13,$f13,$f0 ; jal ; sub.s $f12,$f12,$f1
 * Here: the source pointer is built before the destination pointer, the hero block's
 * `lui`/`addiu` are scheduled above the copy (so they live in $a0, not $v1), and the hero's two
 * floats are loaded first (`lwc1 $f1,0x84($a0) ; lwc1 $f0,0x80($a0)`) with the object's into
 * $f12/$f13, so the subtractions write the other registers (`sub.s $f12,$f0,$f12` and
 * `sub.s $f13,$f1,$f13`); retail loads the object's two floats first into $f1/$f0, the hero's into
 * $f13/$f12, and subtracts in place.
 *
 * Cause (measured): retail's copy was a volatile asm, a barrier for both scheduling passes, so the
 * hero's address arithmetic (pseudo-register insns that cannot depend on the store; the four
 * loads do depend on it and stay behind it) stayed after it.  `rac2_qcopy` is an ordinary insn
 * (no unit, cost 1) and sched1 puts the hero's `lui` first: its chain to the call gives it
 * priority 15 against the copy's 14.  Measured in a scratch copy (not allowed in src/): with the
 * copy as one volatile asm, `__asm__ __volatile__("lq $2,0(%1)\n\tsq $2,0(%0)" : : "r"(arg0 + 0x10),
 * "r"(&D_L02_001B01C0) : "$2", "memory")`, the C below (with the corrected order) is exact, 1 of 1
 * places.  None of -fno-schedule-insns, -fno-schedule-insns2, -fno-sched-interblock, -fno-gcse,
 * -mno-split-addresses, -fno-strength-reduce, -g gets the profile build below 21 words.
 *
 * Spelling notes kept from the earlier record: the angle is func_002A7878(0.0f, 1.5707965f)
 * (retail's constant is 0x3FC90FDC), and the two halfword stores to +0x34 stay two only when the
 * load through the +0x24 record sits between them (written as one expression, or as two statements
 * with nothing between, cc1 folds them to a single `andi 0xFFFC` and one store).
 *
 * What would unblock it: a barrier form of the profile (the pattern given a volatile asm's
 * dependences in sched_analyze_insn, as -frac2-zero-ti-barrier does for the clear); the C below
 * would then go into that unit unchanged.
 */

typedef int TI128 __attribute__((mode(TI)));

extern float func_002A7878(float, float);

extern void func_002A7750(char *, int, int);

extern void func_002A0488(char *, int, int, int);

extern void func_L02_003D4AF0(char *, int);

extern void func_L02_003D5570(char *);

extern float func_00283248(float, float);

typedef struct {
    char pad0[0x80];
    float x;
    float y;
} L02_003D7900_Hero;

extern L02_003D7900_Hero D_00189E20;

extern int D_L02_001B01C0 __attribute__((sda));

void func_L02_003D47B0(char *arg0, int arg1) {
    char *state = *(char **)(arg0 + 0x68);
    float r;
    L02_003D7900_Hero *hero;

    *(float *)(state + 0x20) = (float)*(short *)(state + 0x24);
    r = func_002A7878(0.0f, 1.5707965f);
    *(float *)(state + 0x304) = 0.0f;
    *(short *)(state + 0x32C) = 0;
    *(int *)(state + 0x300) = 0;
    *(short *)(state + 0x32A) = 0;
    *(short *)(state + 0x98) = 0;
    *(float *)(state + 0x2F4) = r;
    func_002A7750(arg0, 2, 1);
    func_L02_003D4AF0(arg0, 1);
    *(unsigned char *)(state + 0x7A) = 0;
    *(unsigned char *)(state + 0x2E) = 1;
    *(unsigned char *)(arg0 + 0x31) = 1;
    *(unsigned short *)(arg0 + 0x34) = *(unsigned short *)(arg0 + 0x34) & 0xFFFE;
    *(int *)(arg0 + 0x98) = *(int *)(*(char **)(arg0 + 0x24) + 0x10);
    *(unsigned short *)(arg0 + 0x34) = (*(unsigned short *)(arg0 + 0x34) | 0x1000) & 0xFFFD;
    *(unsigned char *)(arg0 + 0x7F) = 0;
    *(TI128 *)(arg0 + 0x10) = *(TI128 *)&D_L02_001B01C0;
    hero = &D_00189E20;
    *(float *)(arg0 + 0xF8) = func_00283248(hero->x - *(float *)(arg0 + 0x10),
                                            hero->y - *(float *)(arg0 + 0x14));
    *(int *)(state + 0x310) = 0;
    *(short *)(state + 0x318) = 0;
    *(short *)(state + 0x31A) = 0;
    func_L02_003D5570(arg0);
    if (*(short *)(state + 0x60) != 0) {
        *(short *)(state + 0x60) = 0;
        func_002A0488(arg0, *(unsigned char *)(state + 0x64),
                      *(unsigned char *)(state + 0x65),
                      *(unsigned char *)(state + 0x66));
        *(short *)(state + 0x62) = 1;
    }
    *(short *)(state + 0x330) = arg1;
}
