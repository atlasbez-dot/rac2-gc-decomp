/* func_L05_004431A0 (316 bytes, 4 places) -- NEAR MISS, not integrated.
   state: 316 bytes against retail's 316, and 41 of the 79 words identical; one
   register-allocation difference is left.
   check.py (05_feltzin_system), with the source below:
     004431A4  lui  $v0,0x0      | lui  $v0,0x1A
     004431A8  sd   $s0,0x10($sp) | lw   $v0,0x79F0($v0)      <- the mode load
     ...
     004431C4  lw   $v1,0x0($v0) | daddu $s2,$a2,$zero
     004431C8  addiu $s3,$zero,0x14 | sd $ra,0x30($sp)
   Everything else matches: the frame (0x50), the five saved registers, the mode
   compare, the two `jal`s of each block, the three quadword copies and the epilogue.

   What is measured and right:
   - the unit needs -O2 -G0 -ffunction-sections -frac2-qcopy.  The three quadword
     copies are the grouped R5900 pair with both addresses in registers; without
     -frac2-qcopy this cc1 folds the offsets into the lq and the body is 308 bytes.
     The copy source is `D = *(TI128 *)src;` (a TImode memory assignment), not a
     memcpy (that expands to ldl/ldr/sdl/sdr) and not a pointer walk (that folds
     the offsets away).
   - the first constant is 1e-5f: retail's `lui $at,0x3727; ori $at,$at,0xC5AC;
     mtc1 $at,$f20` is this cc1's inline float literal, in -G0 and in -G8 alike.
   - the mode global D_001A79F0 is read twice, once before the calls and once
     after, so the source tests it twice; the second read needs a second symbol
     (D_001A79F0_alt here) because one symbol makes this cc1 keep the address in
     $s4 across the calls instead of rematerialising it (308 bytes, $s4 saved).
   - the branches are `if (mode == 20) goto done;` twice, the second test being
     `mode == 20 || mode == 15`; nested ifs give the same control flow but the
     first branch then skips the second test instead of the end.
   - the 16-byte scratch is a local at sp+0 and the float is $f20 (callee saved).

   Tried and not enough: -mastra-keep-frame-order (no change), the two mode reads
   swapped, one mode symbol with a volatile read (the address then lands in $s2
   and the body grows to 328 bytes), the copy source through the parameter a0
   (this file) or through s0 (an extra `daddu $s4,$s0,$zero` and 328 bytes).
   What is left: this cc1 sinks the mode load below the prologue and keeps the
   high part in $v0 while the value goes to $v1; retail keeps both in $v0.  The
   load has to stay adjacent to its `lui` so that the reload pass coalesces the
   two into one register.

   Measured afterwards (same cc1):
   - the unit's flags give exactly retail's size: `-O2 -G0 -ffunction-sections
     -frac2-qcopy` compiles the body to 316 bytes (20 of the 79 words differ
     from retail), without the flag it is 308 bytes.
   - the copy source has to be the `a0` parameter (`D = *(TI128 *)a0;`): with
     `s0` or with `*(TI128 *)&D_L05_001B35D0` the body is 328 bytes.
   - the mode read through a local variable (`int mode = D_001A79F0;`) changes
     nothing; the two names for the one global are still needed.
   - retail keeps the first mode load at the top of the body, before the frame's
     register saves, and lets the `lui` register become the loaded value; the
     second read uses $v1 the same way. */
#include "include_asm.h"
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern int D_001A79F0;

extern int D_001A79F0_alt;

extern TI128 D_L05_001B35D0;

extern TI128 D_L05_001B35E0;

extern TI128 D_L05_001B35F0;

extern float ref_L05_004431A0_00(float);

extern void ref_L05_004431A0_01(void *, void *, float);

extern void ref_L05_004431A0_02(void *, void *, void *);

void func_L05_004431A0(void *a0, float *a1, float *a2)
{
    void *s0 = a0;
    float *s1 = a1;
    float *s2 = a2;
    TI128 scratch;
    float f20;

    if (D_001A79F0 == 20)
        goto done;
    f20 = 1e-5f;
    if (f20 < ref_L05_004431A0_00(*s1)) {
        ref_L05_004431A0_01(&scratch, (char *)s0 + 0x20, *s1);
        ref_L05_004431A0_02(s0, s0, &scratch);
        ref_L05_004431A0_02((char *)s0 + 0x10, (char *)s0 + 0x10, &scratch);
    }
    if (D_001A79F0_alt == 20 || D_001A79F0_alt == 15)
        goto done;
    if (f20 < ref_L05_004431A0_00(*s2)) {
        ref_L05_004431A0_01(&scratch, (char *)s0 + 0x10, *s2);
        ref_L05_004431A0_02(s0, s0, &scratch);
        ref_L05_004431A0_02((char *)s0 + 0x20, (char *)s0 + 0x20, &scratch);
    }
done:
    D_L05_001B35D0 = *(TI128 *)a0;
    D_L05_001B35E0 = *(TI128 *)((char *)s0 + 0x10);
    D_L05_001B35F0 = *(TI128 *)((char *)s0 + 0x20);
}
