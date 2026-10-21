/* func_L02_003DB158, 164 bytes, 1 placement (level 2).  Near miss with the opt-in `-frac2-qcopy`
   profile (#262): in a unit of its own (src/levels/02_maktar_nebula/L02_003DB158-g8.c, flags
   `-O2 -G8 -ffunction-sections -frac2-qcopy`; -G8 for the three `$gp` reads below, which are
   `$gp + 0x1490/0x1488/0x1484`) the C below is retail's 164 bytes, with the 0xA0 frame, the
   four scratch blocks, the five calls, the delay slots and retail's copy
   `addiu $v1,$sp,0x10 ; lq $v0,0($sp) ; sq $v0,0($v1)`.  9 of its 41 words still differ
   (tools/check.py: 0 of 1 places match, first difference at +0xC):
     retail prologue   sd s0, daddu a2,sp, sd s2, daddu s0,a0, sd s1, daddu s2,a1, sd s3, sd ra
     this unit         sd s0, daddu a2,sp, sd s1, daddu s0,a0, sd s2, sd ra, daddu s2,a1, sd s3
     retail after the first call   addiu v1,sp,0x10 ; lq ; sq ; addiu s1,sp,0x20 ; daddu a0 ; daddu a1
     this unit                     addiu s1,sp,0x20 ; addiu v1,sp,0x10 ; lq ; sq ; daddu a0 ; daddu a1
   Cause (measured, `-fsched-verbose-5 -dR`): retail's copy was a volatile asm, which both
   scheduling passes treat as a barrier, and `rac2_qcopy` is an ordinary insn.  sched2 takes the five
   prologue `sd` in the order of their priority (all equal), then of how many insns depend on each
   store (more first), then of emission order.  Retail's barrier leaves `sd s0` and `sd s2` one
   dependent more (their first writes `move s0,a0` / `move s2,a1` come before the barrier) than the
   others, giving s0, s2, s1, s3, ra; without it `sd s1` (first write `addu s1,sp,32`) and `sd ra`
   (the epilogue `ld ra`) get one more as well, giving s0, s1, s2, ra, s3.  The same dependent
   counts make sched2 float `addu s1,sp,32` above the copy.
   Measured in a scratch copy (not allowed in src/): with the copy written as one volatile asm
   `__asm__ __volatile__("lq $2,0(%1)\n\tsq $2,0(%0)" : : "r"(&copy), "r"(&src) : "$2", "memory")`
   the same C is exact (1 of 1 places); so it is with the profile's own copy kept and only
   `__asm__ __volatile__("" : : : "memory");` written right after it, so the barrier after the
   copy is what matters.  No single extra flag changes it (-fno-schedule-insns,
   -fno-schedule-insns2, -fno-sched-interblock, -fno-gcse, -mno-split-addresses,
   -fno-strength-reduce, -g, -fno-expensive-optimizations, -fno-delayed-branch,
   -mastra-keep-frame-order: 8 to 12 words differ or the size moves).  C spellings tried
   (9 words each, 16 for the first): `&block` in a pointer local set before the copy, the same
   local set after it, a named destination/source pointer pair for the copy, the state load split
   in two statements.
   What would unblock it: a barrier form of the profile (the pattern given a volatile asm's
   dependences in sched_analyze_insn, as -frac2-zero-ti-barrier does for the clear); the C below
   would then go into that unit unchanged.
   Body measured in that unit: */

typedef int s32;
typedef float f32;
typedef int TQ __attribute__((mode(TI)));

extern f32 D_L02_001B0474 __attribute__((sda));
extern f32 D_L02_001B0478 __attribute__((sda));
extern s32 D_L02_001B0480 __attribute__((sda));

extern void *func_0029FCC0(char *, int, void *);
extern void func_0029FC20(char *, int, void *);
extern void func_002830C0(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_L00_00325AE8(void *, int, float, float);

typedef struct { f32 x, y, z, w; } V4;
typedef struct { f32 v[16]; } M4;

void func_L02_003DB158(char *a0, s32 a1) {
    char *s3 = *(char **)(*(char **)(a0 + 0xB8) + 0x68);
    V4 src, copy;
    M4 block;
    V4 out;

    func_0029FCC0(a0, a1, &src);
    *(TQ *)&copy = *(TQ *)&src;
    func_0029FC20(a0, a1, &block);
    func_002830C0(&out, &D_L02_001B0480, &block);
    func_00282CC0(&src, &src, &out);
    func_L00_00325AE8(&src, *(s32 *)(s3 + 0x250), D_L02_001B0478, D_L02_001B0474);
}
