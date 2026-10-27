/* func_L06_0045A2D8: near miss: the code is right; retail keeps the anim parameter in $s4 and the self pointer in $s5 (this build swaps them) and moves "mov.s $f12,$f24" one instruction earlier before the last call. The 0x30-byte local at sp+0x10 is required for the frame size (0xD0). */
#include "common.h"

extern void func_00282D30(char *, char *, float);
extern void func_002A7470(char *, int, int, int);

typedef float V4_F45a2d8[4] __attribute__((aligned(16)));

extern int D_001BFC98[];
extern float func_0029F530(void);
extern void func_00282F20(void *, void *, float);
extern void func_002A8C00(void *, char *, int, void *, float);
extern void func_0029FCC0(char *, int, void *);
extern int func_00277F48(void *, int, char *, void *, float);

/* Runs the shared pickup test: when the object is in the given state and the draw is inside the window, aims at the target and, on a hit with the expected tag, hands over to the next state. */
void func_L06_0045A2D8(char *obj, char *self, int kind, int sub, int anim, int link, int next, int tag,
                       float lo, float hi, float scale, float reach, float range)
{
    V4_F45a2d8 dir;
    char aim[0x30] __attribute__((aligned(16)));
    V4_F45a2d8 probe;
    float roll = func_0029F530();
    char *vec;

    if (*(u8 *)(obj + 0x20) == kind && *(u8 *)(obj + 0x42) == sub && lo < roll && roll < hi) {
        vec = self + 0xC0;
        func_00282F20(dir, vec, scale);
        dir[2] = 1.0f;
        func_002A8C00(aim, obj, 1, dir, reach);
        func_0029FCC0(obj, 0, probe);
        if (func_00277F48(probe, 0x21, obj, aim, range) != 0 && D_001BFC98[0] == tag) {
            func_00282D30(vec, vec, -1.0f);
            *(float *)(self + 0xC8) = -0.05f;
            if (*(u8 *)(obj + 0x43) != anim)
                func_002A7470(obj, anim, link, 5);
            *(u8 *)(obj + 0x20) = next;
        }
    }
}
