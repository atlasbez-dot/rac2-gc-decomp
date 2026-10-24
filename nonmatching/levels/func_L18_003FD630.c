/* Current nonmatching reconstruction; game compiler, -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
   us: 18_damosel: instruction at +0x0 differs; func_L18_003FD630: 0 of 3 places match (src/levels/shared/L18_003FD630-copy.c).
   us2: 18_damosel: instruction at +0x0 differs; func_L18_003FD630: 0 of 3 places match (src/levels/shared/L18_003FD630-copy.c).
   pal: 18_damosel: instruction at +0x0 differs; func_L18_003FD630: 0 of 3 places match (src/levels/shared/L18_003FD630-copy.c).
   Same 252-byte extent but the fixed stack frame is 0x90 against retail 0xF0. Only four control vectors are proven read by func_L11_00397C08; no padding was added to imitate the unexplained extra 0x60 bytes. Reopen with a verified complete control-structure layout.
   Historical screening comments below predate this measured C reconstruction. */
/* func_L18_003FD630 - 252 bytes, 3 place(s), level 18_damosel, retail at
   0x003fd630. Screened with tools/w10_screen.py: 8 call(s)
   [func_002ACB48@003FD680, func_002A7A00@003FD690, func_002A7A00@003FD6A0,
   func_002A7820@003FD6AC, func_002A7878@003FD6BC, func_002A7878@003FD6CC,
   func_L11_00397C08@003FD6E4, func_L11_00397E68@003FD704]; data addresses
   materialised [-]; float constants [-]; $gp-relative small data: no
   saves: -; callee-saved registers saved [-]; words plain C cannot emit
   [LQ/SQ 78A20000@0x0034, LQ/SQ 7FC20000@0x0038, LQ/SQ 78A20000@0x0040,
   LQ/SQ 7C820000@0x0044]. Head: addiu $sp, $sp, -0xF0 ; sd $fp, 0xC8($sp) ;
   sd $s0, 0xC0($sp) ; daddu $fp, $sp, $zero ; sd $ra, 0xD0($sp) ; swc1
   $f21, 0xE8($sp). Not matched in this wave: the 128-bit copy needs an
   `lq`/`sq` pair; plain C reaches it only through a `mode(TI)` local, and
   this cc1 folds the destination offset into the `sq` where retail
   materialises the pointer first. What would unblock it: the exact source
   expression tree, so this cc1 picks the same registers in the same order. */

typedef int s32;
typedef float f32;
typedef int Quad __attribute__((mode(TI)));
extern s32 D_L18_001B0748 __attribute__((sda));
extern f32 D_L18_001B074C __attribute__((sda));
extern f32 D_L18_001B0750 __attribute__((sda));
extern f32 D_L18_001B0754 __attribute__((sda));
extern f32 D_L18_001B0758 __attribute__((sda));
extern f32 D_L18_001B075C __attribute__((sda));
extern f32 D_L18_001B0760 __attribute__((sda));
extern f32 D_L18_001B0764 __attribute__((sda));
extern f32 D_L18_001B0768 __attribute__((sda));
extern s32 D_L18_001B076C __attribute__((sda));
extern s32 D_L18_001B0770 __attribute__((sda));
extern void func_002ACB48(f32 *, f32);
extern void func_002A7A00(float *, float, float);
extern s32 func_002A7820(s32, s32);
extern f32 func_002A7878(f32, f32);
extern void func_L11_00397C08(void *, s32, void *, f32);
extern void func_L11_00397E68(void *, s32, s32, s32, s32, f32, f32);

/* Builds a randomized strip from two control points and two random tangents. */
void func_L18_003FD630(char *self) {
    f32 control[4][4];
    s32 count = D_L18_001B0748;
    Quad points[count];
    char *state = *(char **)(self + 0x68);
    s32 texture;
    f32 width, height;
    *(Quad *)control[0] = *(Quad *)(state + 0x90);
    *(Quad *)control[1] = *(Quad *)(state + 0x90);
    func_002ACB48(control[1], D_L18_001B0768 * *(f32 *)(state + 0xC0));
    func_002A7A00(control[2], D_L18_001B0750, D_L18_001B0754);
    func_002A7A00(control[3], D_L18_001B0750, D_L18_001B0754);
    texture = func_002A7820(16, 64);
    width = func_002A7878(D_L18_001B0758, D_L18_001B075C);
    height = func_002A7878(D_L18_001B0760, D_L18_001B0764);
    func_L11_00397C08(points, D_L18_001B0748, control, D_L18_001B074C);
    func_L11_00397E68(points, D_L18_001B0748, texture, D_L18_001B076C, D_L18_001B0770, width, height);
}
