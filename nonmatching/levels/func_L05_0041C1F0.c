/* func_L05_0041C1F0: M3 2026-10-26: the sound pick was inverted: D_001A79FC == 0 tests D_0018D030 and D_001A79F0 == 0x19, else plays 0x1282. 540/544 at -G8 -mno-split-addresses; one instruction left: retail reads D_0018D030 split (lui in the bnez slot, lhu into $v1) while D_001A79F0/79FC stay tied macro reads.
 */
/* PERMUTE-FLAGS: -O2 -G8 -mno-split-addresses -ffunction-sections */
#include "include_asm.h"

extern int D_L05_001B1300 __attribute__((sda));
extern int D_001A79F0 __attribute__((nosda));
extern int D_001A79FC __attribute__((nosda));
extern unsigned short D_0018D030 __attribute__((nosda));
extern float func_00282E48(void *, void *);
extern float func_002AA458(void *, void *, void *, float, float, float);
extern float func_00283B98(float, float);
extern int func_002E5DA0(int, int, char *, int);
extern void func_0029F338(void *);
extern void func_L05_0041C4E8(char *);
extern int func_00288E18(int, int);
extern int func_00288FB8(int);
extern void func_L00_0030DD70(int, int);

void func_L05_0041C1F0(char *object)
{
    char *state = *(char **)(object + 0x68);
    float scale;

    if (D_L05_001B1300 != 0) {
        scale = func_00282E48((void *)(D_L05_001B1300 + 0x10), object + 0x10);

        if (D_001A79F0 == 0x14) {
            func_002AA458(object + 0x10, (void *)(D_L05_001B1300 + 0x10), state + 0x40,
                         0.008888889104127884f, 0.0033333334140479565f, 1.0666667222976685f);
            goto check_scale;
        }
        if (scale < 60.0f) {
            float *p = *(float **)(object + 0x24);
            float v = p[9] * 0.02222222276031971f * scale;

            *(float *)(object + 0x2C) = v;
            {
                float cap = p[9] * 0.30000001192092896f;

                if (v < cap)
                    *(float *)(object + 0x2C) = cap;
            }
            func_002AA458(object + 0x10, (void *)(D_L05_001B1300 + 0x10), state + 0x40,
                         0.0055555556900799274f, 0.0016666667070239782f, 0.5f);
        }
check_scale:
        if (scale < 0.5f) {
            if (D_001A79FC == 0) {
                if (D_0018D030 == 0 && D_001A79F0 == 0x19)
                    func_00288E18(0xA3B, 0x92);
            } else {
                func_L00_0030DD70(func_00288FB8(0x1282), -1);
            }
            func_002E5DA0(0xC, 0, object, 0xFBF);
            D_001A79FC = D_001A79FC + 1;
            func_0029F338(object);
            return;
        }
    }
    func_L05_0041C4E8(object);
    *(float *)(object + 0xF8) = func_00283B98(*(float *)(object + 0xF8), 0.03f);
    *(float *)(object + 0xF0) = func_00283B98(*(float *)(object + 0xF0), 0.01f);
}
