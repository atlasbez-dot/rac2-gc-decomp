#include "include_asm.h"
#include "common.h"
extern s32 D_001B2748;

/* Scales the level's shared word by the object's own signed halfword, takes it modulo
   sixty and paints the object with 0x80FFFFFF when the remainder is under fifteen and
   with 0x80404040 otherwise; then it sets the sub-object's two flag words. */
void func_PAL_L17_003C0758(s32 a0)
{
    s32 v1 = D_001B2748;
    s32 d = 50;
    s32 v0 = *(short *)(a0 + 0xB2);
    s32 c1 = 0x80404040;
    s32 t0 = 0x80FFFFFF;
    s32 a1;
    s32 a3;

    v1 = v1 + v0;
    v0 = v1 % d;
    if (v0 >= 12)
        a1 = c1;
    else
        a1 = t0;
    *(s32 *)(a0 + 0x78) = a1;
    a3 = *(s32 *)(a0 + 0x68);
    *(u32 *)(a3 + 0x8C) |= 1;
    *(u16 *)(a3 + 0x3E) |= 8;
    *(u8 *)(a0 + 0x30) = 0;
}
