/* Current nonmatching reconstruction; game compiler, -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
   us: 18_damosel: instruction at +0xc differs; func_L18_0035D5F8: 0 of 3 places match (src/levels/shared/L18_0035D5F8-copy.c).
   us2: 18_damosel: instruction at +0xc differs; func_L18_0035D5F8: 0 of 3 places match (src/levels/shared/L18_0035D5F8-copy.c).
   pal: 18_damosel: instruction at +0xc differs; func_L18_0035D5F8: 0 of 3 places match (src/levels/shared/L18_0035D5F8-copy.c).
   Same 344-byte extent; differing saved-register allocation starts at +0xC. Moving pointer induction inside the guard and computing segment pointers from the loop index did not recover the retail allocation. Reopen with a source/layout explanation for the loop counter and segment pointer lifetimes.
   Historical screening comments below predate this measured C reconstruction. */
/* func_L18_0035D5F8 - 344 bytes, 3 place(s), level 18_damosel, retail at
   0x0035d5f8. Screened with tools/w10_screen.py: 4 call(s)
   [func_L18_0035D238@0035D68C, func_00282C48@0035D6A8,
   func_00282E48@0035D6C0, func_00282E48@0035D6D0]; data addresses
   materialised [0x51ba0000, 0x3dcc0000]; float constants [-]; $gp-relative
   small data: no   saves: -; callee-saved registers saved [-]; words plain
   C cannot emit [LQ/SQ 7BA20000@0x00f4, LQ/SQ 7E820000@0x00f8]. Head: addiu
   $sp, $sp, -0x80 ; sd $s2, 0x20($sp) ; sd $s3, 0x28($sp) ; daddu $s2,
   $zero, $zero ; sd $s4, 0x30($sp) ; daddu $s3, $a1, $zero. Not matched in
   this wave: the 128-bit copy needs an `lq`/`sq` pair; plain C reaches it
   only through a `mode(TI)` local, and this cc1 folds the destination
   offset into the `sq` where retail materialises the pointer first. What
   would unblock it: the exact source expression tree, so this cc1 picks the
   same registers in the same order. */

typedef int s32;
typedef float f32;
typedef int Quad __attribute__((mode(TI)));
extern f32 func_L18_0035D238(void *, void *, void *, void *, void *, f32);
extern f32 func_00282C48(f32);
extern f32 func_00282E48(void *, void *);

/* Finds the best projected point on the path, breaking near ties by distance. */
f32 func_L18_0035D5F8(void *out, void *origin, void *direction, char *path, f32 scale) {
    f32 candidate[4];
    f32 best = 100000000000.0f;
    f32 score, distance;
    s32 i = 0;
    if (*(s32 *)path - 1 > 0) {
    for (; i < *(s32 *)path - 1; i++) {
        score = func_L18_0035D238(candidate, origin, direction, path + 16 + (i << 4), path + 32 + (i << 4), scale);
        if (score < best) {
            best = score;
            *(Quad *)out = *(Quad *)candidate;
        } else if (func_00282C48(score - best) < 0.1f) {
            distance = func_00282E48(candidate, origin);
            if (distance < func_00282E48(out, origin)) {
                best = score;
                *(Quad *)out = *(Quad *)candidate;
            }
        }
    }
    }
    return best;
}
