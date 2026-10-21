/* Retained near miss: 180/180 bytes and 0/1 placements with -O2 -G8 -ffunction-sections -frac2-qcopy. The copy, floating registers and final block match; the global load and float-constant materialization remain in the opposite order at +0x3C. Five bounded source variants were checked. */

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef int TI128 __attribute__((mode(TI)));

extern float D_L20_001B2410 __attribute__((sda));
extern float D_L20_001B2414 __attribute__((sda));
extern float D_L20_001B241C __attribute__((sda));

extern float func_00283B98(float, float);
extern float func_00283198(float);
extern void func_002A9288(char *, float);
extern void func_L20_0044AA88(char *);

void func_L20_0044A838(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);
    u16 n = *(u16 *)(arg0 + 0x96);
    float r;

    *(u16 *)(arg0 + 0x96) = n + 1;
    if (*(u8 *)(arg0 + 0x31)) {
        *(TI128 *)(arg0 + 0x10) = *(TI128 *)(state + 0x180);
        r = D_L20_001B2414;
        r = func_00283B98(*(float *)(state + 0x1A0), r * 0.000290888245f);
        *(float *)(state + 0x1A0) = r;
        r = func_00283198(r);
        {
            float amount = D_L20_001B241C;
            *(float *)(arg0 + 0x18) = *(float *)(arg0 + 0x18) + D_L20_001B2410 * r;
            func_002A9288(arg0, amount);
        }
    }
    if (((*(u16 *)(arg0 + 0x34)) ^ 1) & 1) {
        func_L20_0044AA88(arg0);
    }
}
