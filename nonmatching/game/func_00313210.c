/* M21 2026-10-26: 812 of 824 bytes with -O2 -G16 -Wa,-G16 -ffunction-sections (us), about
   60 lines off (was 109). Profile: the three 16-byte sda tables need -G16; D_001B5340 is then
   an incomplete array (retail lui/addiu). func_00283D38 returns int (no dsll32/dsra32).
   Block-local angle/timer pointers stop loop.c's strength reduction (written as data + 0x60
   + offset it reduces to one pointer; retail does not). Retail additionally shows gcse copies
   (daddu $s4/$s3 of data+0x60/0x58) that this spelling does not produce, which shifts the
   s-register allocation of the colour/table values. Index-based arrays were worse (90). */

#include "common.h"

extern void func_00282CF0(float *, float *, float *);
extern void func_00282CC0(float *, float *, float *);
extern void func_00282F20(float *, float *, float);
extern int func_00282978(short *);
extern float func_00283CE0(int);
extern float func_00282C48(float);
extern int func_00283CF0(float);
extern int func_00283D38(unsigned int, unsigned int, float);
extern unsigned char *func_002C2FD8(float *, int, int, int, int, int, int, float);
extern float D_001B5340[];
extern int D_001AF174 __attribute__((sda));
extern unsigned int D_001AF1C4 __attribute__((sda)), D_001AF1C8 __attribute__((sda));
extern unsigned int D_001AF1CC __attribute__((sda)), D_001AF1D0 __attribute__((sda));
extern int D_001AF1D4 __attribute__((sda)), D_001AF1D8 __attribute__((sda));
extern float D_001AF1E0[4] __attribute__((sda));
extern float D_001AF1F0[4] __attribute__((sda));
extern float D_001AF200[4] __attribute__((sda));
extern unsigned char *D_001F2540[] MACRO_ADDR;

#define ANGLE(o) (*(float *)((char *)angle + (o)))
#define TIMER(o) (*(short *)((char *)timers + (o)))
#define TABLE(t, o) (*(float *)((o) + (unsigned int)(t)))

int func_00313210(unsigned char *self)
{
    float position[4] __attribute__((aligned(16)));
    float step[4] __attribute__((aligned(16)));
    int count, active;
    unsigned char *data = *(unsigned char **)(self + 0x68);
    short *timer = (short *)(data + 0x58);
    int floatOffset = 0, timerOffset = 0;
    float baseZ, remaining, mix;
    int color, alpha;
    unsigned char *effect;

    active = 0;
    func_00282CF0(position, D_001B5340, (float *)(self + 0x10));
    func_00282F20(position, position, -0.3f);
    func_00282F20(step, position, 0.1f);
    count = 3;
    func_00282CC0(position, position, (float *)(self + 0x10));
    baseZ = position[2];
    do {
        if (func_00282978(timer) == 0) {
            float *angle = (float *)(data + 0x60);
            short *timers = (short *)(data + 0x58);
            ANGLE(floatOffset) += TABLE(D_001AF1E0, floatOffset);
            if (TIMER(timerOffset) >= 49)
                active = 1;
            if (ANGLE(floatOffset) >= 255.0f)
                ANGLE(floatOffset) -= 255.0f;
            else if (ANGLE(floatOffset) <= 0.0f)
                ANGLE(floatOffset) += 255.0f;
            mix = func_00282C48(0.5f - func_00283CE0(255 - TIMER(timerOffset)) * 0.00392156886f);
            if (data[0x57])
                color = func_00283D38(D_001AF1CC, D_001AF1D0, mix);
            else
                color = func_00283D38(D_001AF1C4, D_001AF1C8, mix);
            remaining = 1.0f - (float)TIMER(timerOffset) / func_00283CE0(D_001AF174);
            alpha = func_00283CF0(func_00283CE0(color >> 24) * (1.0f - remaining)) << 24;
            color = alpha | (color & 0xFFFFFF);
            position[2] = baseZ + TABLE(D_001AF200, floatOffset);
            effect = func_002C2FD8(position, color, func_00283CF0(ANGLE(floatOffset)) & 255, D_001AF1D8, 0, 2, 1,
                                   TABLE(D_001AF1F0, floatOffset) * remaining);
            if (effect)
                effect[2] = D_001F2540[62][0];
            effect = func_002C2FD8(position, alpha | 0xFFFFFF, func_00283CF0(ANGLE(floatOffset)) & 255, D_001AF1D8,
                                   D_001AF1D4, 2, 1, TABLE(D_001AF1F0, floatOffset) * 0.7f * remaining);
            if (effect)
                effect[2] = D_001F2540[62][0];
            func_00282CC0(position, position, step);
        }
        floatOffset += 4;
        timerOffset += 2;
        timer++;
    } while (--count >= 0);
    return active;
}
