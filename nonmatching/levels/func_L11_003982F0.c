/* 0 of 1 places match - last line: 11_joba: 248 bytes, expected 252
   G8: the body reads its constants through $gp, so it needs the
   src/levels/11_joba/L11_002DE9E0-g8.c unit (-G8).
   The body is recovered: the object carries a 16-byte matrix at +0x10 that is
   copied twice, the second copy is scaled by D_L11_001AECF0 times the value at
   the state's +0x2C, two random vectors are built with func_002A7A00, a random
   index comes from func_002A7820, two random floats from func_002A7878, and
   the level's own list (a VLA of D_L11_001AECD0 16-byte elements) is handed to
   func_L11_00397C08 and func_L11_00397E68 with the level's constants.  The
   frame (0xF0), the 64-bit size multiply (sll 7 / srl 3) and the lq/sq copies
   match.  Four differences are left: retail saves $fp, $s0 and $ra in that
   order while this cc1 saves $ra, $s0 and $fp, retail materialises arg0 + 0x10
   in $a1 before the frame is set up while this cc1 keeps arg0 in $a1 and folds
   the +0x10 into the lq, retail adjusts the stack before the two lq/sq copies
   while this cc1 emits the copies first, and retail's mul.s has the constant
   in $f12 and the loaded value in $f0 (mul.s $f12,$f12,$f0) where this cc1
   loads the value into $f12 and the constant into $f0 (mul.s $f12,$f0,$f12).
   The ten-element local array and the variable-length array are what the
   0xF0 frame needs; a plain __builtin_alloca gives the frame without the
   array's 64-bit multiply. */

#include "common.h"

/* The 128-bit integer mode is what reaches retail's lq/sq copies. */
typedef int V4 __attribute__((mode(TI)));

extern void func_002ACB48(f32 *vector, f32 scale);

extern void func_002A7A00(f32 *out, f32 a1, f32 a2);

extern s32 func_002A7820(s32 a0, s32 a1);

extern f32 func_002A7878(f32 a0, f32 a1);

extern void func_L11_00397C08(void *a0, s32 a1, void *a2, f32 f12);

extern void func_L11_00397E68(void *a0, s32 a1, void *a2, s32 a3, s32 a4, f32 f12,
                              f32 f13);

extern s32 D_L11_001AECD0 __attribute__((sda));

extern s32 D_L11_001ACEF4 __attribute__((sda));

extern s32 D_L11_001ACEF8 __attribute__((sda));

extern f32 D_L11_001AECF0 __attribute__((sda));

extern f32 D_L11_001AECD4 __attribute__((sda));

extern f32 D_L11_001AECD8 __attribute__((sda));

extern f32 D_L11_001AECDC __attribute__((sda));

extern f32 D_L11_001AECE0 __attribute__((sda));

extern f32 D_L11_001AECE4 __attribute__((sda));

extern f32 D_L11_001AECE8 __attribute__((sda));

extern f32 D_L11_001AECEC __attribute__((sda));

void func_L11_003982F0(u8 *arg0) {
    u8 *a1 = arg0 + 0x10;
    u8 *a2 = *(u8 **)(arg0 + 0x68);
    V4 buf[D_L11_001AECD0];
    V4 m[10];
    s32 s0;
    f32 f21;
    f32 f20;

    m[0] = *(V4 *)a1;
    m[1] = *(V4 *)a1;
    func_002ACB48((f32 *)&m[1], D_L11_001AECF0 * *(f32 *)(a2 + 0x2C));
    func_002A7A00((f32 *)&m[2], D_L11_001AECD8, D_L11_001AECDC);
    func_002A7A00((f32 *)&m[3], D_L11_001AECD8, D_L11_001AECDC);
    s0 = func_002A7820(0x10, 0x40);
    f21 = func_002A7878(D_L11_001AECE0, D_L11_001AECE4);
    f20 = func_002A7878(D_L11_001AECE8, D_L11_001AECEC);
    func_L11_00397C08(buf, D_L11_001AECD0, (void *)&m[0], D_L11_001AECD4);
    func_L11_00397E68(buf, D_L11_001AECD0, (void *)s0, D_L11_001ACEF4,
                      D_L11_001ACEF8, f21, f20);
}
