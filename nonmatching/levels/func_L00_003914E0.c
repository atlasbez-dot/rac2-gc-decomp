/* RAC1-helper follow-up, 2026-10-25: NOT MATCHING; no exact-C credit.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * Fresh local measurement: 1000/1000 bytes, 0/27 US placements, first mismatch +0x60; frame 0xE0.
 * Change: The copied point has explicit 16-byte alignment and uses approved qcopy; the actual three particle API return banks and FP argument slots are preserved.
 * Residual: No-force-mem measured 1004. Smoke call argument scheduling and the spark-loop preheader still differ despite equal size.
 * Reopen: Reopen with measured smoke/counter argument-setup ordering, not false particle prototypes or invented dependencies.
 * Earlier measurements/screens below are historical; they do not prohibit
 * the currently approved shared transfer helpers or establish linked equality.
 */
/* Nonmatching: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier. us: func_L00_003914E0: 0 of 27 places match (src/levels/shared/L00_003914E0.c); us2: func_L00_003914E0: 0 of 27 places match (src/levels/shared/L00_003914E0.c); pal: absent. Four manual trials; best 1000/1000 bytes, frame0xE0, first mismatch+0x60. Natural preinitialized countdown matches saved flag/counter allocation, but smoke call scheduling and spark preheader differ. Reopen with original counter/expression scheduling evidence. Verified three particle APIs return allocated pointers, full five/two/one FP arguments retained. */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef struct { int color[6]; } EffectPalette;
extern EffectPalette D_L00_001AF0F8, D_L00_001AF110;
extern char D_L00_001B8DC0[];
extern float D_L00_001B19CC MACRO_ADDR;
extern void *func_002BC768(void *, int, int, float, float, float, float, float);
extern void func_00282CF0(void *, void *, void *), func_00282C88(Quad *);
extern float func_00282DF0(void *), func_002A7878(float, float);
extern int func_00283CF0(float), func_002A77E0(s32), func_002A7820(s32, s32);
extern void *func_002BBCB0(void *, void *, int, int, int, int, int, int, float, float);
extern char *func_00308408(void *, void *, void *, int, int, int, int, int, float);
/* Emits the tether's impact smoke, distance-weighted sparks and colored fragments. */
void func_L00_003914E0(char *actor, int fragments) {
    float point[4] __attribute__((aligned(16)));
    float delta[4], velocity[4];
    EffectPalette first, second;
    int i, count, startLife, endLife;
    int *firstColor, *lastColor;
    float distance, nearPenalty, speed;
    qcopy(point, actor + 0x10);
    point[2] += 0.3f;
    i = 4;
    func_002BC768(point, 1, 0x40808080, 0.3f, 1.01f, 1.075f, 0.05f, 50000.0f);
    do {
        --i;
        func_002BC768(point, 1, 0x40808080, 0.3f, 1.01f, 1.07f, 0.05f, 50000.0f);
    } while (i >= 0);
    if (!fragments) return;
    func_00282CF0(delta, D_L00_001B8DC0, actor + 0x10);
    func_00282C88((Quad *)velocity);
    distance = func_00282DF0(delta);
    if (distance < 8.0f) count = func_00283CF0(distance) + 2;
    else count = 10;
    nearPenalty = 0;
    if (distance < 7.0f) nearPenalty = 7.0f - distance;
    while (count > 0) {
        --count;
        speed = func_002A7878(8.0f, 10.0f) * 0.016666668f;
        speed -= nearPenalty * 0.016666668f;
        first = D_L00_001AF0F8;
        second = D_L00_001AF110;
        firstColor = first.color + func_002A77E0(6);
        lastColor = second.color + func_002A77E0(6);
        startLife = func_002A7820(15, 20);
        endLife = func_002A7820(25, 30);
        func_002BBCB0(actor + 0x10, velocity, *firstColor, *lastColor, startLife, endLife, 0, 0,
                      400000.0f, speed);
    }
    if (D_L00_001B19CC < 0.95f) {
        func_00308408(actor, actor + 0x10, velocity, 15, 0x7F, 0x7F, 0x7F, 0x20, 3.0f);
        func_00308408(actor, actor + 0x10, velocity, 24, 0x7F, 0x20, 0, 0x20, 2.0f);
    }
    func_00308408(actor, actor + 0x10, velocity, 20, 0x7F, 0x40, 0, 0x30, 3.0f);
    func_00308408(actor, actor + 0x10, velocity, 27, 0x60, 0x10, 0, 0x40, 2.0f);
    func_00308408(actor, actor + 0x10, velocity, 29, 0x20, 0, 0, 0x20, 1.0f);
}

/* Historical screening only; superseded by the measured reconstruction above. */
/* func_L00_003914E0 - 1000 bytes, 27 place(s), level 00_aranos_tutorial,
   retail at 0x003914e0. Screened with tools/w10_screen.py: 17 call(s)
   [func_002BC768@00391584, func_002BC768@003915D8, func_00282CF0@00391600,
   func_00282C88@0039160C, func_00282DF0@00391614, func_00283CF0@0039163C,
   func_002A7878@00391690, func_002A77E0@00391714, func_002A77E0@00391724,
   func_002A7820@00391738, func_002A7820@00391748, func_002BBCB0@0039177C,
   func_00308408@003917D4, func_00308408@00391800, func_00308408@0039182C,
   func_00308408@00391858, func_00308408@00391884]; data addresses
   materialised [0x40800000, 0x3e990000, 0x3f810000, 0x3f890000, 0x3d4c0000,
   0x47430000, 0x40800000, 0x3e990000, 0x3f810000, 0x3f880000, 0x3d4c0000,
   0x47430000, 0x40800000, 0x1c0000, 0x3c880000, 0x1b0000, 0x1b0000,
   0x48c30000, 0x1b0000, 0x3f730000]; float constants [0x41000000,
   0x40e00000, 0x41000000, 0x41200000, 0x40400000, 0x40000000, 0x40400000,
   0x40000000, 0x3f800000]; $gp-relative small data: no   saves: -; callee-
   saved registers saved [-]; words plain C cannot emit [LQ/SQ
   78620000@0x0044, LQ/SQ 7FA20000@0x0048]. Head: addiu $sp, $sp, -0xE0 ; sd
   $s5, 0x98($sp) ; sd $s1, 0x78($sp) ; daddu $s5, $a0, $zero ; sd $s0,
   0x70($sp) ; daddu $s1, $a1, $zero. Not matched in this wave: the 128-bit
   copy needs an `lq`/`sq` pair; plain C reaches it only through a
   `mode(TI)` local, and this cc1 folds the destination offset into the `sq`
   where retail materialises the pointer first. What would unblock it: the
   exact source expression tree, so this cc1 picks the same registers in the
   same order. */
