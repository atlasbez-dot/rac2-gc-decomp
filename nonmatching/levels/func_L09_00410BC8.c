/* func_L09_00410BC8: near miss, same size but about 12 instructions of scheduling and constant-register order off. The 2nd and 3rd blocks write the FIRST sprite's fields (retail copy-paste: the stores in blocks two and three use $s2), the vector {0,0,-0.5,1} is a local, func_002BDCE8 takes (vec, side, dir, colour, four floats, 0), and one pointer variable serves as the obj+0x10 source and every glow pointer ($s0). Left: retail adds 0x10 to the object register after the first call and loads the 0.9f and 420000.0f constants in the opposite order ($f21/$f22). Own unit: -O2 -G0 -ffunction-sections -frac2-qcopy. */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern s32 func_002A77E0();
extern s32 func_00283CF0(float);
extern char *func_002BDCE8(void *, s32, void *, s32, float, float, float, float, s32);

/* Sprays three flame sprites from the object (two coloured, one white), each with a random lifetime and a glow child. */
void func_L09_00410BC8(char *obj)
{
    float dir[4] __attribute__((aligned(16)));
    float pos[4] __attribute__((aligned(16)));
    s32 side;
    char *a, *c;

    dir[0] = 0.0f;
    dir[1] = 0.0f;
    dir[2] = -0.5f;
    dir[3] = 1.0f;
    side = func_002A77E0(0x10);
    if (func_002A77E0(2) != 0)
        side = -side;
    obj = obj + 0x10;
    qcopy(pos, obj);
    pos[2] -= 0.25f;
    a = func_002BDCE8(pos, side, dir, 0xDF204080, 0.1f, 1.0f, 0.9f, 420000.0f, 0);
    if (a != 0) {
        *(short *)(a + 0xA) = 0xA;
        obj = a + 0x20;
        *(u8 *)(a + 9) = func_00283CF0(4.0f) + 0x70;
        *(s32 *)(obj + 4) = 2;
        *(u8 *)(obj + 0xA) = 0xDF;
        *(u8 *)(obj + 0xB) = *(u8 *)(a + 0xA);
    }
    obj = func_002BDCE8(pos, side, dir, 0xDF204080, 0.1f, 1.0f, 0.9f, 420000.0f, 0);
    if (obj != 0) {
        obj = obj + 0x20;
        *(short *)(a + 0xA) = 0xA;
        *(u8 *)(a + 9) = func_00283CF0(4.0f) + 0x70;
        *(s32 *)(obj + 4) = 2;
        *(u8 *)(obj + 0xA) = 0xDF;
        *(u8 *)(obj + 0xB) = *(u8 *)(a + 0xA);
    }
    c = func_002BDCE8(pos, 0x10, dir, 0xDFFFFFFF, 0.05f, 1.0f, 0.97f, 210000.0f, 0);
    if (c != 0) {
        obj = c + 0x20;
        *(u8 *)(c + 9) = func_00283CF0(4.0f) + 0x70;
        *(short *)(c + 0xA) = 5;
        *(u8 *)(c + 8) = func_002A77E0(0xFF);
        *(u8 *)(obj + 0xA) = 0xDF;
        *(s32 *)(obj + 4) = 2;
        *(u8 *)(obj + 0xB) = *(u8 *)(a + 0xA);
    }
}
