/* func_L05_00444DF8: near miss (about 8 instructions of argument-move scheduling off, same size). Calls, branch (the two calls to func_0027C878 per arm cross-jump into one), constants and the sda float all match; retail orders the f14/f15/a2 moves differently in calls two to four and fills the last call's delay slot with 'ori $a3'. Own unit: -O2 -G8 -ffunction-sections -mno-split-addresses. */
#include "common.h"

extern s32 D_001A79F0[];
extern float D_L05_001B1B1C __attribute__((sda));

extern s32 func_0027C878(s32);
extern float func_00283B98(float, float);
extern void func_L05_00444FD0(s32, s32, s32, s32, float, float, float, float, float, s32, s32, s32, s32);

/* Draws the four quarter-turn copies of a sprite ring around the point, the same size each time. */
void func_L05_00444DF8(u8 a, u8 b, u8 c, u8 d, float x, float y, float scale, float angle)
{
    s32 sprite;
    float size;

    if (D_001A79F0[0] == 0x14)
        sprite = func_0027C878(0x41);
    else
        sprite = func_0027C878(0x3F);
    size = D_L05_001B1B1C * scale;
    func_L05_00444FD0(0x3F, 0x3F, sprite, 0xFFFFF3, x, y, size, size, angle, a, b, c, d);
    angle = func_00283B98(angle, 1.5707964f);
    func_L05_00444FD0(0x3F, 0x3F, sprite, 0xFFFFF3, x, y, size, size, angle, a, b, c, d);
    angle = func_00283B98(angle, 1.5707964f);
    func_L05_00444FD0(0x3F, 0x3F, sprite, 0xFFFFF3, x, y, size, size, angle, a, b, c, d);
    func_L05_00444FD0(0x3F, 0x3F, sprite, 0xFFFFF3, x, y, size, size, func_00283B98(angle, 1.5707964f), a, b, c, d);
}
