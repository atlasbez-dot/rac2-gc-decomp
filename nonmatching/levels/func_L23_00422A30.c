/*
 * Updated manual-C near miss, 2026-10-25.
 * Measured standalone unit: src/levels/23_damosel_orbit/L23_00422A30-g8.c
 * Game profile: -O2 -G8 -ffunction-sections
 * Release coverage: US 0/1 (exit1); US2 0/1 (exit1); PAL catalogue absent (exit1).
 * Current residual: 980/980 bytes. Only the final source-address addiu and
 * global-destination lui are exchanged at +0x330/+0x334. A real source pointer ties;
 * mno-split-addresses gives 972 and disabling sched2 changes earlier code. The three
 * pose-row transfers intentionally remain ordinary folded TI assignments.
 * Reopen only for: A concrete address lifetime/assembler model for the last global vector
 * copy; retain both real relocation identities.
 * Older notes below are historical. ASM marker and trial-only profiles were restored.
 */

#include "common.h"

/* func_L23_00422A30 (level 23, 980 bytes) -- NEAR MISS, not integrated.
   state: 976 bytes against retail's 980 (`-O2 -G8 -ffunction-sections -frac2-qcopy`, a unit of its own: it
   reads $gp outside delay slots, hence -G8); 0 of 1 places match, about 78 words differ (instruction order
   around the 16-byte copies, see below).
   right (each measured): the frame (0xB0, locals at sp+0x00..0x3F as one TI16[4]), the allocation call and
   its early exit, the field setup, the target / hero / none three-way, the PRE register copies of the
   address expressions (`obj + 0x10` -> $a0 then $s7, `st + 0x30` -> $s1 then $s6, `&loc[2]` -> $s0 then
   $s7): written as the literal expression at every use, not as a pointer variable (a named pointer
   coalesces them and the `daddu` copies disappear); the two byte parameters declared `s32` (`u8` gives an
   `andi $s2,$a3,0xFF` that retail does not have); the global hero pointer read ONCE into a local before the
   target test (retail loads it into the delay slot of the `beqz $s0`, and every later use is that register);
   the inner test as `== 0xF7F` first (retail's `bne` skips the &D_L23_001B36E0 arm); `st->0x20 = 0` written
   once after the big block (retail reaches it through branch-delay copies); the dot product in a variable of
   its own (it lands in $f1, a short-lived register, and the two magnitudes keep $f21/$f20); func_002E5CF8
   declared as returning s32 (it ends with `daddu $v0,$a0,$zero`): that is what moves the last `lhu`/`ori`
   temporary from $v0 to $v1; the three plain copies of rows +0xC0/+0xD0/+0xE0 go through TI16 temporaries
   (`c0 = *src; *dst = c0`) so that -frac2-qcopy does not group them: retail keeps those three as ordinary
   `lq`/`sq` with the offsets folded (and $v0, $v1, $v0 as temporaries), while the other six copies (obj+0x10,
   the four vectors in the aim block, the +0xE0 copy into D_L23_001B1FB0 and its copy back) are grouped
   `lq $v0,0(src) ; sq $v0,0(dst)` pairs through address registers.
   what still differs (wall (2) of the brief): the grouped copies are scheduling barriers in retail and are not
   with -frac2-qcopy, so instructions move across them (the first copy's `lwc1`/`mul.s`/`lui` set-up, the
   argument moves before the aim block's calls, the `daddu $s6,$s1` copies) and about 78 words differ.
   In a SCRATCH copy (build/, never src/) with the six grouped copies written as
   `asm volatile ("lq $2,0(%1) ; sq $2,0(%0)" : : "r"(dst), "r"(src) : "$2")` (no memory clobber) the same C
   compiles to retail's 980 bytes and only TWO words differ: `addiu $v1,$s5,0xE0` and `lui $s0,0x1B` of the
   last copy come in the other order (a scheduling tie of the two address computations; not changed by the
   asm operand order).
   tried without effect: -frac2-zero-ti-barrier is not involved (no clear in this body); default flags without
   qcopy give 956 bytes (the six register-address copies come out folded). */






typedef int TI16 __attribute__((mode(TI)));

typedef struct View_00422A30 {
    u8 pad0[0x188C];
    u8 *f188C;
    u8 pad1[0x2290 - 0x1890];
    u8 *f2290;
    s32 f2294;
} View_00422A30;

extern View_00422A30 D_00189E20;

extern float D_L23_001B1910 __attribute__((sda));

extern float D_L23_001B1928 __attribute__((sda));

extern u8 *D_L23_001B1484 __attribute__((sda));

extern s32 D_L23_001B36E0;

extern TI16 D_L23_001B1FB0;

extern u8 *func_0029EFD0(s32);

extern void func_002B37E8(u8 *, u8 *);

extern void func_L23_00418650(void *, float);

extern void func_00282CF0(void *, void *, void *);

extern void func_00282F20(void *, void *, float);

extern float func_002B0360(void *);

extern float func_00282E48(void *, void *);

extern float func_00282C48(float);

extern float func_00282DB0(void *, void *);

extern void func_00282D30(void *, void *, float);

extern s32 func_L23_0041B948(void);

extern s32 func_002E5CF8(s32, s32, u8 *);

/* Creates the follower object for `src` (the effect that tracks `target`, or the hero, or nothing): copies
   the pose rows, fills the state, and when it has a live target works out the direction, the distance and
   the aim test, dropping the target when the aim, the range or the helper says so. */
u8 *func_L23_00422A30(u8 *src, TI16 *pos, u8 *target, s32 a3, s32 a4) {
    u8 *obj;
    u8 *st;
    TI16 loc[4];
    float f20;
    float f21;
    float f22;
    float dot;
    s32 flag;
    u8 *hero;
    TI16 c0;
    TI16 c1;
    TI16 c2;
    TI16 *reverse;

    obj = func_0029EFD0(0x118F);
    if (obj != 0) {
        st = *(u8 **)(obj + 0x68);
        func_002B37E8(obj, src);
        *(float *)(obj + 0x2C) = *(float *)(obj + 0x2C) * D_L23_001B1910;
        *(u16 *)(obj + 0x34) = *(u16 *)(obj + 0x34) | 0x100;
        *(float *)(st + 0x1C) = 0.33333334f;
        c0 = *(TI16 *)(src + 0xC0);
        *(TI16 *)(obj + 0xC0) = c0;
        c1 = *(TI16 *)(src + 0xD0);
        *(TI16 *)(obj + 0xD0) = c1;
        c2 = *(TI16 *)(src + 0xE0);
        *(TI16 *)(obj + 0xE0) = c2;
        *(u8 **)(st + 0x10) = src;
        qcopy(obj + 0x10, pos);
        *(s32 *)(st + 0x14) = 0x96;
        *(float *)(obj + 0x2C) = *(float *)(obj + 0x2C) + *(float *)(obj + 0x2C);
        st[0x28] = a3;
        st[0x29] = a4;
        hero = D_L23_001B1484;
        if (target != 0) {
            *(u8 **)(st + 0x18) = target;
            *(s32 *)(st + 0x24) = 0x890000;
        } else {
            if (hero != 0) {
                *(u8 **)(st + 0x18) = hero;
                if (*(s16 *)(hero + 0xAA) == 0xF7F) {
                    *(s32 **)(st + 0x2C) = &D_L23_001B36E0;
                } else {
                    *(u8 **)(st + 0x2C) = hero + 0x10;
                }
                *(s32 *)(st + 0x24) = 0x890000;
            } else {
                *(s32 *)(st + 0x18) = 0;
                *(s32 *)(st + 0x24) = 0x890000;
                st[0x29] = 0;
                st[0x28] = 0;
            }
        }
        if (src == D_00189E20.f2290) {
            st[0x29] = 1;
        }
        if (st[0x28] == 0 && *(s32 *)(st + 0x18) != 0) {
            qcopy(&loc[0], *(void **)(st + 0x2C));
            func_L23_00418650(&loc[0], 0.0f);
            func_00282CF0(st + 0x30, *(u8 **)(st + 0x2C), obj + 0x10);
            qcopy(&loc[1], obj + 0x10);
            func_L23_00418650(&loc[1], 0.0f);
            func_00282CF0(&loc[2], &loc[0], &loc[1]);
            flag = 0;
            func_00282F20(&loc[2], &loc[2], 1.0f);
            func_00282F20(st + 0x30, st + 0x30, 1.0f);
            f21 = func_002B0360(src + 0x10);
            f20 = func_002B0360(*(u8 **)(st + 0x2C));
            f22 = func_00282E48(&loc[0], &loc[1]);
            if (f22 < 5.0f) {
                if (func_00282C48(f21 - f20) > 10.0f) {
                    flag = 1;
                }
            }
            qcopy(&loc[3], obj + 0xC0);
            dot = func_00282DB0(&loc[2], &loc[3]);
            if ((src == D_00189E20.f2290 && *(*(u8 **)(st + 0x18) + 0x31) == 0) ||
                dot < D_L23_001B1928 || 50.0f < f22 || flag != 0 || func_L23_0041B948() != 0) {
                *(s32 *)(st + 0x18) = 0;
            }
            if (src == D_00189E20.f2290) {
                if (*(s32 *)(st + 0x18) != 0) {
                    D_00189E20.f188C = st + 0x30;
                } else if (D_00189E20.f2294 == 0x5B) {
                    reverse = (TI16 *)(src + 0xE0);
                    qcopy(&D_L23_001B1FB0, reverse);
                    func_00282D30(&D_L23_001B1FB0, &D_L23_001B1FB0, -1.0f);
                    D_00189E20.f188C = (u8 *)&D_L23_001B1FB0;
                    qcopy(st + 0x30, &D_L23_001B1FB0);
                    st[0x28] = 0;
                    *(s32 *)(st + 0x18) = 1;
                    st[0x29] = 0;
                }
            }
        }
        *(s32 *)(st + 0x20) = 0;
        func_002E5CF8(1, 0, obj);
        *(u16 *)(obj + 0x34) = *(u16 *)(obj + 0x34) | 0x41;
        obj[0xBC] = 0;
    }
    return obj;
}
