/* Current nonmatching reconstruction; game compiler, -O2 -G8 -ffunction-sections -mno-split-addresses.
   us: 18_damosel: 284 bytes, expected 292; func_L18_003FD730: 0 of 3 places match (src/levels/shared/L18_003FD730-g8.c).
   us2: 18_damosel: 284 bytes, expected 292; func_L18_003FD730: 0 of 3 places match (src/levels/shared/L18_003FD730-g8.c).
   pal: 18_damosel: 284 bytes, expected 292; func_L18_003FD730: 0 of 3 places match (src/levels/shared/L18_003FD730-g8.c).
   284 bytes against 292. The truthful scalar declarations with -mno-split-addresses recover absolute loads, but retail has two additional nops before its division. The no-scheduling profile did not restore them. Reopen with a measured scheduling explanation; no artificial nops were added.
   Historical screening comments below predate this measured C reconstruction. */
/* func_L18_003FD730 - 292 bytes, 3 place(s), level 18_damosel, retail at
   0x003fd730. Screened with tools/w10_screen.py: 5 call(s)
   [func_002820A0@003FD744, func_002AA140@003FD7AC, func_00283CF0@003FD7EC,
   func_00283CF0@003FD810, func_002820D0@003FD834]; data addresses
   materialised [0x1b0000, 0x1b0000, 0x3dcc0000, 0x3da30000]; float
   constants [0x3f800000, 0x41200000, 0x3f800000]; $gp-relative small data:
   no   saves: -; callee-saved registers saved [-]; words plain C cannot
   emit [COP1 46806320@0x00ac, COP1 46800020@0x00d8]. Head: addiu $sp, $sp,
   -0x20 ; sd $s0, 0x0($sp) ; swc1 $f20, 0x10($sp) ; daddu $s0, $a0, $zero ;
   sd $ra, 0x8($sp) ; jal func_307860. Not matched in this wave: the float
   code has to come out of the same expression tree to keep the FPU
   registers. What would unblock it: the exact source expression tree, so
   this cc1 picks the same registers in the same order. */

typedef int s32;
typedef float f32;
extern f32 D_L18_001B06AC __attribute__((nosda));
extern f32 D_L18_001B0778 __attribute__((sda));
extern f32 D_L18_001B077C __attribute__((nosda));
extern s32 D_L18_001B0780 __attribute__((sda));
extern f32 D_L18_001B0784 __attribute__((sda));
extern void func_002820A0(void);
extern f32 func_002AA140(f32, f32, f32);
extern s32 func_00283CF0(f32);
extern void func_002820D0(void *, s32, s32, f32, f32, f32);

/* Draws the object's charge indicator with a size and opacity set by its progress. */
void func_L18_003FD730(char *self) {
    char *state;
    f32 ratio, size;
    s32 alpha;
    func_002820A0();
    state = *(char **)(self + 0x68);
    ratio = *(f32 *)(state + 0xC0) / D_L18_001B06AC;
    if (ratio > 1.0f) ratio = 1.0f;
    else if (ratio < 0.0f) ratio = 0.0f;
    size = func_002AA140(D_L18_001B0778, D_L18_001B077C, ratio);
    if (ratio < 0.1f) alpha = func_00283CF0((f32)D_L18_001B0780 * ratio * 10.0f);
    else alpha = func_00283CF0((f32)D_L18_001B0780 * (1.0f - ratio));
    func_002820D0(state + 0x90, alpha, 0, size, D_L18_001B0784, 0.07999999821186066f);
}
