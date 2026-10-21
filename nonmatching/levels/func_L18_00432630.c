/* Near miss from src/levels/18_damosel/L18_003F80A0.c: the build refuses this body at its
   place — 92 bytes, expected 100. Kept as a starting point;
   not linked, not counted. */

/* Near miss: 96 against 100 bytes, one word short.  Level 18, 0x00432630.

   The float part is retail's: `func_00308FB0` and `func_003099E8` with the
   two `lwc1`s of the argument vector, the subtraction of pi/2
   (0x3FC90FDC = 1.5707964f, materialised as `lui $at,0x3FC9 ;
   ori $at,$at,0x0FDC ; mtc1 $at,$f1`) and the two stores at the end.

   What differs is the `lh $v0,0x7FC($v1)` after the two pointer loads: the
   retail reads the state's flag at 0x7FC and never uses the value - a dead
   load - and this cc1 removes it.  The neighbouring matched functions
   (func_L18_004325D8, func_L18_00432718) read the same field and DO use it,
   so the field is a flag and the retail's read is a leftover.

   A `volatile` read keeps the load but comes out as `lhu` (and, when the
   value is used, as `lhu` + `sll`/`sra`), never as the retail's `lh`: gcc
   1.x loads a volatile halfword unsigned.  A plain read is dropped, with or
   without a comparison, a cast, a temporary or a `void` use.  So the dead
   signed halfword load has no plain-C spelling measured here.

   The load order of the two argument floats is also one slot out: the
   retail loads a1[1] before a1[0], this candidate a1[0] before a1[1]. */


typedef unsigned char u8;
typedef short s16;
typedef float f32;

extern float func_00308FB0(float arg0, float arg1);
extern float func_003099E8(float arg0, float arg1);

f32 func_L18_00432630(u8 *a0, f32 *a1)
{
    u8 *v1 = *(u8 **)(a0 + 0x68);
    u8 *s0;
    f32 f;

    *(volatile s16 *)(v1 + 0x7FC);
    s0 = *(u8 **)(v1 + 0x7C0);
    f = func_00308FB0(a1[0] - *(f32 *)(s0 + 0x10), a1[1] - *(f32 *)(s0 + 0x14));
    f = func_003099E8(*(f32 *)(s0 + 0xF8), f);
    return f - 1.5707964f;
}
