/* func_L09_00404C50: near miss, 540 B vs 520 (about five instructions). The field set, the qcopy position copy and every call match, including
   the real argument lists the older draft missed: func_002A7878 takes the position pointer, func_002A78D8 takes the integers 0xB, 2 and 3
   before its two floats, func_002A7940 takes 0xB4 and 0x78. Left: retail loads the integers 0xB, 2 and 3 once into $a0/$a1/$a2 before the stores and
   reuses them for the byte and word stores, where this build loads them again for the call. Own unit: -O2 -G8 -ffunction-sections -frac2-qcopy. */
#include "common.h"

extern float D_L09_001B13F4 __attribute__((sda));
extern float func_002A7878(char *, float, float);
extern int func_00283CF0(float);
extern float func_002A78D8(int, int, int, float, float);
extern float func_002A7940(int, int);
extern void func_002A7750(char *, int, int);
extern void func_002A7470(char *, int, int, int);

/* Initialises a burst emitter: copies the object position, rolls its size and lifetimes and loads the particle defaults. */
void func_L09_00404C50(char *obj)
{
    char *rec = *(char **)(obj + 0x68);
    float size, spin;
    int life, kind, count;

    qcopy(rec + 0x300, obj + 0x10);
    size = func_002A7878(obj + 0x10, 1.0f, 1.333f);
    *(float *)(rec + 0x344) = size;
    *(float *)(obj + 0x2C) = *(float *)(*(char **)(obj + 0x24) + 0x24) * size;
    *(u8 *)(rec + 0x48) = func_00283CF0(15.0f);
    *(u8 *)(rec + 0x4A) = func_00283CF0(4.0f);
    life = 0xB;
    kind = 2;
    count = 3;
    *(float *)(rec + 0x84) = 0.2f;
    *(u8 *)(rec + 0x28) = count;
    *(float *)(rec + 0x134) = 0.05f;
    *(float *)(rec + 0x104) = *(float *)(rec + 0x344) * 0.1f;
    *(float *)(rec + 0x110) = 0.17453295f;
    *(float *)(rec + 0x130) = 0.52359885f;
    *(s32 *)(rec + 0x98) = count;
    *(float *)(rec + 0x80) = 0.2f;
    *(u8 *)(rec + 0x60) = life;
    *(float *)(rec + 0x30) = 0.333f;
    *(u8 *)(rec + 0x2A) = kind;
    *(float *)(rec + 0x100) = *(float *)(rec + 0x344) * 0.3f;
    *(float *)(rec + 0x10C) = 0.1f;
    *(s32 *)(rec + 0x138) |= 0x80;
    *(float *)(rec + 0x108) = 0.1f;
    *(float *)(rec + 0x8C) = 0.4f;
    spin = func_002A78D8(life, kind, count, 18.0f, 22.0f);
    *(u8 *)(rec + 0x1E8) = 7;
    *(u8 *)(rec + 0x1E9) = 6;
    *(short *)(rec + 0x1E2) = 0x78;
    *(s32 *)(rec + 0x13C) = *(s32 *)(rec + 0x234);
    *(short *)(rec + 0x1E4) = 0xB4;
    *(float *)(rec + 0x1D4) = 1.75f;
    *(float *)(rec + 0x1D0) = D_L09_001B13F4 * 0.016666668f;
    *(float *)(rec + 0x1DC) = spin * 0.017453294f;
    *(float *)(rec + 0x348) = func_002A7940(0xB4, 0x78);
    func_002A7750(obj, 1, 0);
    if (*(u8 *)(obj + 0x43) != 0)
        func_002A7470(obj, 0, 0, 0);
    *(s32 *)(obj + 0x9C) = 0xC;
    *(unsigned short *)(obj + 0x34) |= 0x1000;
}
