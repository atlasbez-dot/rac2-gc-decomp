/* near miss, 2 instr (reg a0 vs v0 and delay slot at the final call): func_L04_00400D48; needs a -g8.c unit */
#include "common.h"

/* The -G8 sibling of L04_003C8380.c: this body reads a small-data word through $gp. */

typedef int Q16_B0e5d8f83 __attribute__((mode(TI)));

extern s32 D_001A79F0;
extern s32 ref_L04_00400D48_01 __attribute__((sda));
extern char ref_L04_00400D48_00[];
extern u8 *D_001FE340[];
extern struct { s32 pad; s32 flags; u8 rest[56]; } D_002C63C0[];
extern s32 ref_L04_00400D48_02(u8 *a0, u8 *a1, s32 a2);
extern f32 func_30FF88(s32 value);
extern void func_366360(u8 *a0, u8 *a1, u8 *a2, u8 *a3, f32 f12, f32 f13);

void func_L04_00400D48(u8 *a0, u8 *a1, s32 a2)
{
    u8 *s1 = *(u8 **)(*(u8 **)(a1 + 0x164) + 0x68);
    s32 a3 = -1;
    f32 f;
    f32 t;
    f32 h;
    u8 *o;

    if ((s32)ref_L04_00400D48_00 == 0x28 || D_001A79F0 == 4) {
        if (*(s32 *)(s1 + 0x314) == -1) {
            *(u8 **)(a1 + 0x110) = D_001FE340[*(s32 *)(a1 + 0x54)];
        } else if (D_002C63C0[ref_L04_00400D48_01].flags & 4) {
            *(u8 **)(a1 + 0x110) = D_001FE340[*(s32 *)(a1 + 0x6C)];
            if (*(s32 *)(a1 + 0x120) == 1 && *(s32 *)(a1 + 0x124) >= 3) {
                a3 = 0x82;
            }
        }
    }
    if (a3 == -1) {
        a3 = ref_L04_00400D48_02(a0, *(u8 **)(a1 + 0x110), 1);
    }
    if (a2 != 0) {
        *(Q16_B0e5d8f83 *)(a0 + 0x10) = *(Q16_B0e5d8f83 *)(*(u8 **)(a1 + 0x110) + a3 * 16 + 0x10);
    }
    t = func_30FF88(a3);
    o = *(u8 **)(a1 + 0x110);
    t = t * *(f32 *)(o + 0x1C);
    if (*(s32 *)(a1 + 0x244) != 0) {
        f = t + 15.0f;
    } else {
        f = t + 5.0f;
    }
    *(f32 *)(a1 + 0xA8) = f;
    o = *(u8 **)(a1 + 0x110);
    h = *(f32 *)(o + 0x1C);
    func_366360(o, a1 + 0x114, a1 + 0x118, a1 + 0xF0, f, h);
    *(s32 *)(a1 + 0x1C0) = 0;
    *(f32 *)(s1 + 0x63C) = 1.0f;
    *(s32 *)(s1 + 0x4C4) = 0;
}
