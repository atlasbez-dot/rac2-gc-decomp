/* func_L10_004176C0, 292 bytes, 1 placement, level 10_hrugis_cloud, retail at
   0x004176C0.  NEAR MISS: the candidate is exactly 292 bytes and every word but the
   argument set-up of the FIRST func_0037BD88 call is retail's (8 of 73 words differ,
   the first at +0x9c).

   Read in full: `s = *(u8 **)(a0 + 0x68)`, `p = func_37BA88(a0)`; the body runs only when
   p is not null, p[0x120] is not null and s[0x2E4] is zero.  It then calls
   func_3737B8(0, 0, a0, 0xF86), then func_37BD88 twice - flags 0x6000FF00, then 1, 0, 0x1E,
   2, s[0x2C0] resp. s[0x2C4], and the four floats 0.5f, 2.0f, 0.9f, 1.3f - and finally
   stores func_00335200(0x32, 0x78) into s[0x2E4].

   The residue is the order of the eight argument moves of the first call.  Retail:
     addiu $a2,$zero,0x1 ; mov.s $f12,$f22 ; daddu $a3,$zero,$zero ; mov.s $f13,$f23 ;
     mov.s $f14,$f21 ; mov.s $f15,$f20 ; addiu $t0,$zero,0x1E ; jal ; addiu $t1,$zero,0x2
   this cc1: the four integer arguments first (a2, a3, t0, t1), then the four float copies
   (f12, f13, f14, f15), the last of them in the call's delay slot.  The SECOND call's
   set-up is retail's in both (the floats first, then a2, a3, t0, and t1 in the delay
   slot), and so is the whole prologue, the constant materialisation (0.5f -> $f22,
   2.0f -> $f23, 0.9f -> $f21, 1.3f -> $f20), the func_003737B8 call and the tail.

   Measured, all with tools/check.py:
   - the return type must be `void`: an `s32` return makes cc1 materialise
     `daddu $v0,$zero,$zero` in the branch delay slots and the body grows to 296 bytes;
   - the order inside the call does not matter: cc1 normalises the set-up by hard
     register, so neither the argument order in the call nor the prototype's parameter
     order changes the emitted order (measured with two prototypes and two orders);
   - the same order comes out with the four floats in named locals, with the seventh
     argument in a local, with unsigned literal spellings, and with the file's flags
     changed (-fno-schedule-insns, -fno-schedule-insns2, -fno-gcse, -fno-strength-reduce).

   What would unblock it: the source expression tree that makes cc1 schedule the first
   call's argument moves in retail's order.  The set-up of the second call, with the same
   arguments, is exact, so the difference is in what precedes the first call. */

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

extern u8 *func_0037BA88(u8 *arg0);
extern s32 func_003737B8(s32 a, s32 b, u8 *c, s32 d);
extern void func_0037BD88(u8 *arg0, u32 flags, s32 a, s32 b, s32 c, s32 d, s32 e,
                          f32 f0, f32 f1, f32 f2, f32 f3);
extern s32 func_00335200(s32 a0, s32 a1);

void func_L10_004176C0(u8 *arg0)
{
    u8 *s1 = *(u8 **)(arg0 + 0x68);
    u8 *p = (u8 *)func_0037BA88(arg0);

    if (p == 0)
        return;
    if (*(s32 *)(p + 0x120) == 0)
        return;
    if (*(s32 *)(s1 + 0x2E4) != 0)
        return;
    func_003737B8(0, 0, arg0, 0xF86);
    func_0037BD88(arg0, 0x6000FF00, 1, 0, 0x1E, 2, *(s32 *)(s1 + 0x2C0),
                  0.5f, 2.0f, 0.9f, 1.3f);
    func_0037BD88(arg0, 0x6000FF00, 1, 0, 0x1E, 2, *(s32 *)(s1 + 0x2C4),
                  0.5f, 2.0f, 0.9f, 1.3f);
    *(s32 *)(s1 + 0x2E4) = func_00335200(0x32, 0x78);
}
