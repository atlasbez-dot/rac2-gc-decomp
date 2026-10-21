/* func_L10_004189D8, 252 bytes, 1 placement, level 10_hrugis_cloud, retail at
   0x004189D8.  NEAR MISS: the candidate is 244 bytes (8 words short) and the body, the
   frame (0x40) and the level data are recovered; five residues remain.

   Read in full: `s2 = *(u8 **)(a0 + 0x68)`, `s3 = a0 + 0x10`; a0[0x34] |= 0x100,
   a0[0x20] = 1, then `*(s32 *)(func_37BA88(a0) + 0x148) = 0xA` and func_37CCB0(a0, 1).
   Then the four state stores s2[0x180] = 10.0f, s2[0x26C] = -1, s2[0x268] = 0 and
   a0[0x2C] = 0.04f, with the table base and the index read first:
   `t = *(u8 **)D_L10_001B2614 + *(s32 *)D_L10_00221CD0 * 0x80`.  Then
   func_00335258(0.0f, *(f32 *)t), func_0033D090(s3, a, a, b) with a and b the two results
   of func_00335320() (retail passes the FIRST result as both f12 and f13 and the second
   as f14), and finally func_00308B30(s3, t + 0x30, s3).

   The two level data addresses are new: D_L10_001B2614 holds the table base pointer
   (loaded with `lui $s1,0x1B ; lw $s1,0x2614($s1)`) and D_L10_00221CD0 holds the index
   (`lui $v1,0x22 ; lw $v0,0x1CD0($v1)`, then `sll $v0,$v0,7`).

   The residues:
   1. retail keeps a SECOND copy of the first func_00335320() result in $f21
      (`mov.s $f21,$f0` in that call's delay slot) and passes it as f12, while the
      candidate keeps one copy in $f20 (`mov.s $f12,$f20`, `mov.s $f13,$f12`).  Retail's
      f13 is read from the second copy (`mov.s $f13,$f20`), so retail's frame holds two
      callee-saved FPRs and the candidate only one - that is the two missing words.
   2. retail's two float constants land in $f1 (10.0f) and $f0 (0.04f); the candidate
      puts 10.0f in $f0 and 0.04f in $f1 whatever the order of the two stores in the
      source.
   3. retail sets up the second call as `daddu $a0,$s0,$zero ; sw $v1,0x148($v0) ; jal ;
      addiu $a1,$zero,0x1`; the candidate hoists `addiu $a1,$zero,0x1` before the store
      and sinks `daddu $a0,$s0,$zero` into the delay slot.  The same wall is recorded for
      func_L10_004190F0.
   4. retail stores in the order 0x180, 0x26C, 0x268, 0x2C; the candidate reorders the
      -1 store before the 10.0f store.
   5. retail loads the table base with the destination register as the address holder
      (`lui $s1,0x1B ; lw $s1,0x2614($s1)`); the candidate keeps the high half in a
      scratch register (`lui $a0,0x1B ; lw $s1,0x2614($a0)`).

   Measured, all with tools/check.py: the table base is the VALUE at D_L10_001B2614 (the
   candidate reaches the right code with `extern u8 *D_L10_001B2614;`), the index is
   scaled by 0x80, the float argument order is (a, a, b) - (a, b, b) gives a different
   body - and the two constants are 10.0f and 0.04f (0x41200000 and 0x3D23D70A).  Moving
   the table read before the four stores, the two stores against each other and the
   func_0037BA88 result into the store's expression were all measured. */

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef float f32;

extern u8 *func_0037BA88(u8 *arg0);
extern void func_0037CCB0(u8 *arg0, s32 a1);
extern void func_00335258(f32 f12, f32 f13);
extern f32 func_00335320(void);
extern void func_0033D090(u8 *a0, f32 f12, f32 f13, f32 f14);
extern void func_00308B30(u8 *a0, u8 *a1, u8 *a2);

extern u8 *D_L10_001B2614;
extern u8 D_L10_00221CD0[];

void func_L10_004189D8(u8 *arg0)
{
    u8 *s3 = arg0 + 0x10;
    u8 *s2 = *(u8 **)(arg0 + 0x68);
    u8 *s1;
    f32 a, b;

    *(u16 *)(arg0 + 0x34) |= 0x100;
    arg0[0x20] = 1;
    *(s32 *)(func_0037BA88(arg0) + 0x148) = 0xA;
    func_0037CCB0(arg0, 1);
    s1 = D_L10_001B2614 + *(s32 *)D_L10_00221CD0 * 0x80;
    *(f32 *)(s2 + 0x180) = 10.0f;
    *(s32 *)(s2 + 0x26C) = -1;
    *(s32 *)(s2 + 0x268) = 0;
    *(f32 *)(arg0 + 0x2C) = 0.04f;
    func_00335258(0.0f, *(f32 *)s1);
    a = func_00335320();
    b = func_00335320();
    func_0033D090(s3, a, a, b);
    func_00308B30(s3, s1 + 0x30, s3);
}
