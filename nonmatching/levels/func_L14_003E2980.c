/* func_L14_003E2980: near miss, same instruction sequence apart from callee-saved register numbers (retail: obj $s2, mark $s3, rec $s4, colour channels $s1/$s0; this build: obj $s1, rec $s3, mark $s2, red $s4). Own unit with -O2 -G8 -ffunction-sections -frac2-qcopy. */
#include "common.h"

typedef float V4_F3e2980[4] __attribute__((aligned(16)));

extern float D_L14_001B04BC __attribute__((sda));
extern s32 D_L14_001B04D4 __attribute__((sda));
extern float D_L14_001B04D8 __attribute__((sda));
extern float D_L14_001B04DC __attribute__((sda));
extern s32 D_L14_001B04E0 __attribute__((sda));
extern s32 D_L14_001B04E4 __attribute__((sda));
extern s32 D_L14_001B04E8 __attribute__((sda));
extern s32 D_L14_001B04EC __attribute__((sda));
extern s32 D_L14_001B04F0 __attribute__((sda));
extern float D_L14_001B04F4 __attribute__((sda));
extern V4_F3e2980 D_L14_001A8F20;

extern float func_L14_003E22A8(char *);
extern float func_002A7878(float, float);
extern s32 func_002A7820(s32, s32);
extern s32 func_00283D38(s32, s32, float);
extern void func_002C7BB8(void *, void *, s32, s32, float, float, float, s32, s32, s32, s32);

/* Spawns the object's flash: offsets its position along the facing, packs the colour channels and hands both to the effect call. */
void func_L14_003E2980(char *obj)
{
    V4_F3e2980 pos;
    V4_F3e2980 mark;
    char *rec = *(char **)(obj + 0x68);
    s32 color, amount, half;
    s32 red, green, blue;

    qcopy(pos, obj + 0x10);
    pos[0] += func_002A7878(D_L14_001B04BC * -func_L14_003E22A8(obj), D_L14_001B04BC * func_L14_003E22A8(obj));
    pos[1] += func_002A7878(D_L14_001B04BC * -func_L14_003E22A8(obj), D_L14_001B04BC * func_L14_003E22A8(obj));
    pos[2] += func_002A7878(D_L14_001B04BC * -func_L14_003E22A8(obj), 0.0f);
    qcopy(mark, D_L14_001A8F20);
    red = func_002A7820(0, D_L14_001B04EC);
    green = func_002A7820(0, D_L14_001B04E8);
    blue = func_002A7820(0, D_L14_001B04E4);
    green = (green << 8) | 0xFF000000;
    red = (red << 16) | green;
    color = red | blue;
    amount = func_00283D38(color, *(s32 *)(rec + 0x84), func_L14_003E22A8(obj));
    half = func_002A7820(D_L14_001B04D4 / 2, D_L14_001B04D4);
    func_002C7BB8(pos, mark, half, amount, D_L14_001B04D8, D_L14_001B04DC, D_L14_001B04F4, func_002A7820(0, D_L14_001B04E0), 0x80, 0, D_L14_001B04F0);
}
