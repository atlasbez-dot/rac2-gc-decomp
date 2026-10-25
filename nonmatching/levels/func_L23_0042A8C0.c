/*
 * Updated manual-C near miss, 2026-10-25.
 * Measured unit: src/levels/23_damosel_orbit/L23_0042A8C0-g8.c
 * Game profile: -O2 -G8 -ffunction-sections
 * Release coverage after copy-dependency correction: US 0/1 (exit1); US2 0/1 (exit1); PAL
 * absent (exit1).
 * Current residual: 952/940 bytes. Only the first three independent stack matrix rows use
 * qcopy_nc. The fourth row uses clobbering qcopy because C overwrites its w field next;
 * both qzero clears retain their memory clobbers. Matrix/state pointer allocation and
 * ring-count modulo setup remain different. Count-table extent is incomplete.
 * Reopen only for: A measured source representation for matrix/state lifetimes and ring
 * modulo values, retaining real alias effects.
 * Older notes below are historical. Marker and trial-only flags are restored.
 */

#include "common.h"

/* func_L23_0042A8C0 (level 23, 940 bytes) -- NEAR MISS, not integrated.
   state: 936 bytes against retail's 940 (this body, `-O2 -G8 -ffunction-sections -frac2-qcopy`, a unit of
   its own: it reads $gp outside delay slots, hence -G8, and copies 16 bytes five times and clears it
   twice); tools/check.py: 0 of 1 places match, 77 to 86 words differ (77 with `-frac2-zero-ti-barrier`
   added).
   right (each measured with a compile):
   - the frame (0x140) and the locals at sp+0x20 the matrix, 0x60 the sound position, 0x70 the axis
     vector, 0x80 the 3-row matrix, 0xB0 and 0xC0 the two edge vectors: declared in that order as float
     arrays;
   - the sound call with its three jittered floats (each sum is `result + constant`; the constants
     0.0f / 1.3f / 1.6f live in $f21 / $f20 / $f24), the arm order of `if (f() == 0)` (the 0.5 arm first,
     retail's `bnez` over it), the 16-argument call to func_L23_004256F0 (eight integer registers, four
     float registers, four stack words);
   - `vars` is loaded after the if/else, just before the copies (at the top it takes a callee-saved
     register for the whole body);
   - the table entry index is held in a local (`e = D_L23_0025E9D0[...]`): retail scales it once into $s0
     and indexes the edge table twice with it;
   - the counts array is reached through a pointer local (`cnt = D_L23_001B3980`): its address comes out as
     one `lui`/`addiu` pair instead of a shared `lui` and an `addiu` per use;
   - the range test is two nested ifs (`x < 0`, then `x >= -0x45`): in one `&&` fold makes it a single
     unsigned compare;
   - D_L23_001B1B98 is updated through TWO NAMES for the one word. Retail keeps both stores (`sw v0,0x2BA8
     ($gp)` after the `div`, then `sw a0,0x2BA8($gp)`), but flow deletes the first when both go through
     the same symbol (dead-store removal of identical MEMs with no read between). The second store, and
     every later read, go through D_L23_001B1B98_2 (the same address, resolved from the retail bytes).
   what still differs is the copy wall (wall (2) of the brief), five copies and two clears:
   - retail materialises each address with its own `addiu` and then runs `lq $v0,0(src) ; sq $v0,0(dst)`
     strictly in source order; the clears are `addiu $a0,$sp,0x50 ; sq $zero,0($a0)`. This cc1 folds the
     frame offset (`por $v0,$zero,$zero ; sq $v0,0x50($sp)`) and shares address registers between the
     copies and the calls (`&matrix` in a callee-saved register across calls; retail rematerialises it);
   - in a SCRATCH copy (build/, never src/) with the five copies and the two clears written as
     `asm volatile ("lq $2,0(%1) ; sq $2,0(%0)" : : "r"(dst), "r"(src) : "$2")` and
     `asm volatile ("sq $0,0(%0)" : : "r"(dst))` (no memory clobber: with one, cc1 reloads the state
     pointer after each), this C without the `cnt` pointer compiles to retail's 940 bytes and differs in
     57 words: a run of register numbers (`vars` in $s1 where retail has $s2 and keeps `&matrix` in $s1
     across the call that builds the rotation) and the counts-array / remainder pair in $a0/$a1 where
     retail has $a1/$a0 (retail computes the whole `lui $a1 ; addiu $a1` address above the `div`). With the
     `cnt` pointer it is 936 bytes. No source shape moved those registers.
   tried without effect: -frac2-gcse-unsplit-edges, a pointer variable for `&matrix` (hoisted into the
   prologue, or assigned just before the call that builds the rotation), assigning `cnt` before or after
   the modulo, -fno-schedule-insns (928 bytes), -fno-schedule-insns2 (920 bytes). */






typedef int TI128 __attribute__((mode(TI)));

typedef struct Edge_0042A8C0 {
    s16 a;
    s16 b;
    s16 c;
    s16 d;
} Edge_0042A8C0;

extern u8 *D_L23_001B1484;

extern float D_L23_001B1470;

extern float D_L23_001B39D0;

extern s32 D_L23_001B1694;

extern s32 D_L23_001B3934;

extern s32 D_L23_001B3980[];

extern s32 D_L23_0025E9D0[];

extern Edge_0042A8C0 D_L23_002A7A70[];

extern float D_L23_002A6390[][4];

extern float D_L23_0025EC40[][4];

extern float D_L23_001B1C60 __attribute__((sda));

extern s16 D_L23_001B1B96 __attribute__((sda));

extern s32 D_L23_001B1B98 __attribute__((sda));

extern s32 D_L23_001B1B98_2 __attribute__((sda));

extern float D_L23_001B1C4C __attribute__((sda));

extern float D_L23_001B1C50 __attribute__((sda));

extern float D_L23_001B1C54 __attribute__((sda));

extern float D_L23_001B1C0C __attribute__((sda));

extern float D_L23_001B1C34 __attribute__((sda));

extern s32 D_L23_001B1C44 __attribute__((sda));

extern s32 D_L23_001B1C48 __attribute__((sda));

extern s32 D_L23_001B1C40 __attribute__((sda));

extern u8 D_L23_001B1C58 __attribute__((sda));

extern u8 D_L23_001B1C5C __attribute__((sda));

extern s16 D_L23_001B1C38 __attribute__((sda));

extern s16 D_L23_001B1C3C __attribute__((sda));

extern void func_00291450(s32);

extern void func_00282D30(void *, void *, float);

extern void func_00282CC0(void *, void *, void *);

extern float func_002A7878(float, float);

extern s32 func_L00_002FCF18(void *, float, float, float, float, float);

extern s32 func_L23_0041C0B0(void);

extern void func_L03_002EFB60(void *, void *, float);

extern void func_002833F0(void *, void *);

extern void func_00283738(void *, void *, void *);

extern void func_002830C0(void *, void *, void *);

extern void *func_L23_004256F0(void *, u8 *, void *, u8, u8, s16, s16, s32, float, float, float, float, s32, s32,
                               s32, s32);

/* Smoke/spark emitter of the second state: refreshes the sound handle, builds a rotation from the
   state's matrix rows and the roll angle, picks the next slot of the 15-entry ring, rewrites the slot's
   two edge vectors from the edge table and starts the effect object with them. */
void func_L23_0042A8C0(u8 *moby) {
    u8 *vars;
    float m[16] __attribute__((aligned(16)));
    float v60[4] __attribute__((aligned(16)));
    float v70[4] __attribute__((aligned(16)));
    float m80[12] __attribute__((aligned(16)));
    float vB0[4] __attribute__((aligned(16)));
    float vC0[4] __attribute__((aligned(16)));
    float f20;
    float f21;
    float f22;
    float r1;
    float r2;
    float r3;
    s32 flag;
    s32 *cnt;
    s32 e;
    u8 *hero;

    if (D_L23_001B1484 != 0) {
        D_L23_001B39D0 = D_L23_001B1470 * D_L23_001B1C60;
        if (D_L23_001B1B96 != -1) {
            func_00291450(D_L23_001B1B96);
        }
        func_00282D30(v60, D_L23_001B1484 + 0xE0, 5.0f);
        func_00282CC0(v60, v60, D_L23_001B1484 + 0x10);
        r1 = func_002A7878(0.0f, 1.3f) + 1.3f;
        r2 = func_002A7878(0.0f, 1.3f) + 1.3f;
        r3 = func_002A7878(0.0f, 1.35f) + 1.6f;
        D_L23_001B1B96 = func_L00_002FCF18(v60, 10.0f, 0.0f, r1, r2, r3);
        if (func_L23_0041C0B0() == 0) {
            flag = 0;
            f21 = D_L23_001B1C4C - D_L23_001B1C4C * 0.5f;
            f20 = D_L23_001B1C50 - D_L23_001B1C50 * 0.5f;
            f22 = D_L23_001B1C54 * 0.5f;
        } else {
            flag = 1;
            f21 = D_L23_001B1C4C;
            f22 = D_L23_001B1C54 * 1.6f;
            f20 = D_L23_001B1C50;
        }
        vars = *(u8 **)(moby + 0x68);
        /* The following transfers only write private stack matrix rows. */
        hero = D_L23_001B1484;
        qcopy_nc(m, hero + 0xC0);
        qcopy_nc(m + 4, hero + 0xD0);
        qcopy_nc(m + 8, hero + 0xE0);
        qzero(m + 12);
        func_L03_002EFB60(m, m, D_L23_001B1C0C);
        qcopy(m + 12, D_L23_001B1484 + 0x10);
        m[15] = 1.0f;
        qzero(v70);
        v70[2] = *(float *)vars;
        func_002833F0(m80, v70);
        func_00283738(m, m, m80);
        cnt = D_L23_001B3980;
        D_L23_001B1B98 = D_L23_001B1B98 + 1;
        D_L23_001B1B98_2 = D_L23_001B1B98 % 15;
        if (D_L23_001B1694 < 0) {
            if (D_L23_001B1694 >= -0x45) {
                cnt[D_L23_001B1B98_2] = cnt[D_L23_001B1B98_2] + 1;
            }
        }
        cnt[D_L23_001B1B98_2] = cnt[D_L23_001B1B98_2] % D_L23_001B3934;
        e = D_L23_0025E9D0[cnt[D_L23_001B1B98_2]];
        func_002830C0(vB0, D_L23_002A6390[D_L23_002A7A70[e].a], m);
        func_002830C0(vC0, D_L23_002A6390[D_L23_002A7A70[e].b], m);
        qcopy(D_L23_0025EC40[D_L23_001B1B98_2 * 2], vB0);
        qcopy(D_L23_0025EC40[D_L23_001B1B98_2 * 2 + 1], vC0);
        func_L23_004256F0(D_L23_0025EC40[D_L23_001B1B98_2 * 2], moby, D_L23_0025EC40[D_L23_001B1B98_2 * 2 + 1],
                          D_L23_001B1C58, D_L23_001B1C5C, D_L23_001B1C38, D_L23_001B1C3C, D_L23_001B1C40, f21,
                          f20, f22, D_L23_001B1C34, D_L23_001B1C44, flag, D_L23_001B1C48, 0);
    }
}
