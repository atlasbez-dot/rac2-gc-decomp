/* Retained manual C reconstruction; not linked and not credited as matching.
 * Checked source: src/game/00313210-g8.c
 * Profile: -O2 -G8 -ffunction-sections
 * Retail US extent: 824 bytes.
 * us: 0/28 (exit 1, 832 compiled bytes); us2: 0/28 (exit 1, 832 compiled bytes); pal: catalogue absent (exit 1).
 * Residual: 832/824 bytes. The frame is 0xA0. Counter/table index allocation and saves differ; byte offsets and the independently advanced timer are retained.
 * Reopen only with: A measured lifetime or induction model for the two table offsets and timer cursor, preserving all four timers and both emitted effects.
 * No complete linked build was run for this candidate.
 */
#include "include_asm.h"
typedef unsigned long u64;
extern void func_00282CF0(float *, float *, float *);
extern void func_00282CC0(float *, float *, float *);
extern void func_00282F20(float *, float *, float);
extern int func_00282978(short *);
extern float func_00283CE0(int);
extern float func_00282C48(float);
extern int func_00283CF0(float);
extern u64 func_00283D38(unsigned int, unsigned int, float);
extern unsigned char *func_002C2FD8(float *, int, int, int, int, int, int, float);
extern float D_001B5340[4];
extern int D_001AF174 __attribute__((sda));
extern unsigned int D_001AF1C4 __attribute__((sda)), D_001AF1C8 __attribute__((sda));
extern unsigned int D_001AF1CC __attribute__((sda)), D_001AF1D0 __attribute__((sda));
extern int D_001AF1D4 __attribute__((sda)), D_001AF1D8 __attribute__((sda));
extern float D_001AF1E0[4] __attribute__((sda));
extern float D_001AF1F0[4] __attribute__((sda));
extern float D_001AF200[4] __attribute__((sda));
extern unsigned char *D_001F2540[];
int func_00313210(unsigned char *self)
{
    float position[4] __attribute__((aligned(16)));
    float step[4] __attribute__((aligned(16)));
    int count, active = 0;
    unsigned char *data = *(unsigned char **)(self + 0x68);
    short *timer = (short *)(data + 0x58);
    float *angle = (float *)(data + 0x60);
    int floatOffset = 0, timerOffset = 0;
    float baseZ, remaining, mix;
    int color, alpha;
    unsigned char *effect;
    func_00282CF0(position, D_001B5340, (float *)(self + 0x10));
    func_00282F20(position, position, -0.3f);
    func_00282F20(step, position, 0.1f);
    count = 3;
    func_00282CC0(position, position, (float *)(self + 0x10));
    baseZ = position[2];
    do {
        if (func_00282978(timer) == 0) {
            (*(float *)((char *)angle + floatOffset)) += (*(float *)((char *)D_001AF1E0 + floatOffset));
            if ((*(short *)(data + 0x58 + timerOffset)) >= 49) active = 1;
            if ((*(float *)((char *)angle + floatOffset)) >= 255.0f) (*(float *)((char *)angle + floatOffset)) -= 255.0f;
            else if ((*(float *)((char *)angle + floatOffset)) <= 0.0f) (*(float *)((char *)angle + floatOffset)) += 255.0f;
            mix = func_00282C48(0.5f - func_00283CE0(255 - (*(short *)(data + 0x58 + timerOffset))) * 0.00392156886f);
            if (data[0x57]) color = (int)func_00283D38(D_001AF1CC, D_001AF1D0, mix);
            else color = (int)func_00283D38(D_001AF1C4, D_001AF1C8, mix);
            remaining = 1.0f - (float)(*(short *)(data + 0x58 + timerOffset)) / func_00283CE0(D_001AF174);
            alpha = func_00283CF0(func_00283CE0(color >> 24) * (1.0f - remaining)) << 24;
            color = alpha | (color & 0xffffff);
            position[2] = baseZ + (*(float *)((char *)D_001AF200 + floatOffset));
            effect = func_002C2FD8(position, color, func_00283CF0((*(float *)((char *)angle + floatOffset))) & 255, D_001AF1D8, 0, 2, 1,
                (*(float *)((char *)D_001AF1F0 + floatOffset)) * remaining);
            if (effect) effect[2] = D_001F2540[62][0];
            effect = func_002C2FD8(position, alpha | 0xffffff, func_00283CF0((*(float *)((char *)angle + floatOffset))) & 255, D_001AF1D8,
                D_001AF1D4, 2, 1, ((*(float *)((char *)D_001AF1F0 + floatOffset)) * 0.7f) * remaining);
            if (effect) effect[2] = D_001F2540[62][0];
            func_00282CC0(position, position, step);
        }
        floatOffset += 4; timerOffset += 2;
        timer++;
    } while (--count >= 0);
    return active;
}
