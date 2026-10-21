/* func_L10_00417F30, 340 bytes, 1 placement, level 10_hrugis_cloud, retail at
   0x00417F30.  NEAR MISS: the candidate is 264 bytes; the branch shape and the body are
   recovered, but the eight 128-bit copies come out with their offsets folded into the
   lq/sq operands where retail materialises both pointers.

   Read in full: `s2 = *(u8 **)(a0 + 0x68)` and `st = s2[0x14]`.  When st is 0 the body
   computes a point on the cloud: `f = func_00309138(0.2f)`, `func_00308BB8(v, p + 0xC0, f)`
   with `p = *(u8 **)s2[0x10]`, `v[3] = func_00309120(0.2f)`, `func_003098F8(v, w)` and
   `func_003096D8(a0 + 0xC0, w, p + 0xC0)`, then copies p[0x10] to a0[0x10].  When st is 1
   it copies the four 16-byte fields at p + 0xC0, p + 0xD0, p + 0xE0 and p + 0x10 into
   a0 + 0xC0, a0 + 0xD0, a0 + 0xE0 and a0 + 0x10.  Finally, when `q = *(u8 **)s2[0x18]`
   is not null, the same four fields are copied from a0 into q.

   The copies are the wall.  Retail materialises the pointer and copies at offset zero:
     addiu $v1,$a0,0xC0 ; lq $v0,0($v1) ; sq $v0,0($a1)
   while this cc1 folds the offset into the operands:
     lq $v0,0xC0($v1) ; sq $v0,0xC0($a1)
   The instruction class itself is reachable: a `mode(TI)` local does give the lq/sq pair
   (a plain struct assignment gives ldl/ldr/sdl/sdr), so this is the "constant-offset
   wall is a cost tie in cse" of docs/COMPILER-NOTES.md, the same wall as
   func_L10_0039D5E0 and func_L10_0039D760.

   Two further residues: retail tests st with `beqz $v1` and then `bnel $v1,$v0` and
   carries `lw $a2,0x18($s2)` in the annulled slot, where the candidate branches with
   `bnez` and loads the two state pointers eagerly; and the candidate's block-0 frame
   (0x60) is not retail's (0x70).

   What would unblock it: a source shape that keeps the lq/sq operands at zero offset -
   the pointer has to be materialised by the source, not folded by the address
   optimiser - plus the branch shape of the state test. */

#include "include_asm.h"

typedef unsigned char u8;
typedef int s32;
typedef float f32;

typedef int TI128 __attribute__((mode(TI)));

extern f32 func_00309138(f32 f12);
extern f32 func_00309120(f32 f12);
extern void func_00308BB8(f32 *a0, u8 *a1, f32 f12);
extern void func_003098F8(f32 *a0, f32 *a1);
extern void func_003096D8(u8 *a0, f32 *a1, u8 *a2);

void func_L10_00417F30(u8 *arg0)
{
    u8 *s1 = arg0;
    u8 *s2 = *(u8 **)(arg0 + 0x68);
    u8 *p = *(u8 **)(s2 + 0x10);
    u8 *q;
    s32 st = *(s32 *)(s2 + 0x14);
    f32 v[4];
    f32 w[4];
    TI128 t;

    if (st == 0) {
        f32 f = func_00309138(0.2f);

        func_00308BB8(v, p + 0xC0, f);
        v[3] = func_00309120(0.2f);
        func_003098F8(v, w);
        func_003096D8(arg0 + 0xC0, w, p + 0xC0);
        t = *(TI128 *)(p + 0x10);
        *(TI128 *)(arg0 + 0x10) = t;
    } else if (st == 1) {
        t = *(TI128 *)(p + 0xC0);
        *(TI128 *)(arg0 + 0xC0) = t;
        t = *(TI128 *)(p + 0xD0);
        *(TI128 *)(arg0 + 0xD0) = t;
        t = *(TI128 *)(p + 0xE0);
        *(TI128 *)(arg0 + 0xE0) = t;
        t = *(TI128 *)(p + 0x10);
        *(TI128 *)(arg0 + 0x10) = t;
    }
    q = *(u8 **)(s2 + 0x18);
    if (q != 0) {
        t = *(TI128 *)(arg0 + 0xC0);
        *(TI128 *)(q + 0xC0) = t;
        t = *(TI128 *)(arg0 + 0xD0);
        *(TI128 *)(q + 0xD0) = t;
        t = *(TI128 *)(arg0 + 0xE0);
        *(TI128 *)(q + 0xE0) = t;
        t = *(TI128 *)(arg0 + 0x10);
        *(TI128 *)(q + 0x10) = t;
    }
}
