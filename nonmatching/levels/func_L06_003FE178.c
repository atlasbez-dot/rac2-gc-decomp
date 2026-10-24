/* Nonmatching reconstruction, 23 October 2026.
 * Profile: -O2 -G8 -ffunction-sections -fno-gcse -g.
 * Final check.py coverage: us 0/1, us2 0/1; no linked build run.
 * Ten bounded source/profile trials: int path count, direct speed updates, early exits, -g, -fno-gcse, separate division. Sizes 556/560/564/572 versus 568.
 * Remaining: The retained -g -fno-gcse body is 564/568. Gap/next-speed FPR allocation differs and one pre-division nop is absent; own-line division made two nops and 572 bytes.
 * Reopen with a qualified division/scheduling witness and FPR source-lifetime model.
 */
#include "common.h"
extern void func_002C9828(void *, void *, void *, void *, int, float);
extern float func_00283B98(float, float);
extern float func_00283198(float);
extern float func_002A7878(float, float);
extern float D_L06_001AFCA0 __attribute__((sda));

/* Advance a moving object's path and keep its spacing from the next object. */
void func_L06_003FE178(char *moby)
{
    char *state = *(char **)(moby + 0x68);
    char *next;
    float phase, speed, pathPosition;
    int length;
    func_002C9828(*(void **)(state + 0x30), *(void **)(state + 0x40),
                 moby + 0x10, moby + 0xF0, 0, *(float *)(state + 0x10));
    phase = func_00283B98(*(float *)(state + 0x4C), *(float *)(state + 0x50));
    *(float *)(state + 0x4C) = phase;
    *(float *)(moby + 0x18) += D_L06_001AFCA0 * func_00283198(phase);
    length = **(int **)(state + 0x30);
    pathPosition = *(float *)(state + 0x10) + *(float *)(state + 0x14);
    *(float *)(state + 0x10) = pathPosition;
    if ((float)length <= pathPosition)
        *(float *)(state + 0x10) = pathPosition - (float)length;
    if (*(float *)(state + 0x14) > *(float *)(state + 0x38))
        *(float *)(state + 0x14) -= *(float *)(state + 0x18);
    else
        *(float *)(state + 0x14) += *(float *)(state + 0x18);
    next = *(char **)(state + 0x34);
    if (next && next != moby) {
        char *other = *(char **)(next + 0x68);
        float nextSpeed = *(float *)(other + 0x38);
        float gap = *(float *)(other + 0x10) - *(float *)(state + 0x10);
        float ownSpeed;
        if (gap < 0.0f)
            gap += (float)**(int **)(state + 0x30);
        ownSpeed = *(float *)(state + 0x38);
        if (nextSpeed < ownSpeed) {
            float difference = ownSpeed - nextSpeed;
            if (gap < difference * difference / (*(float *)(state + 0x18) + *(float *)(state + 0x18))
                       + *(float *)(other + 0x1C) + *(float *)(state + 0x1C)) {
                *(float *)(other + 0x38) = ownSpeed;
                *(float *)(state + 0x38) = nextSpeed;
            }
        }
        if (*(unsigned char *)(*(char **)(state + 0x34) + 0x20) == 2 &&
            gap < *(float *)(state + 0x1C) * 3.0f) {
            *(float *)(state + 0x5C) = *(float *)(state + 0x38);
            *(int *)(state + 0x38) = 0;
        }
        if (*(unsigned char *)(*(char **)(state + 0x34) + 0x20) == 3) {
            *(float *)(state + 0x38) = *(float *)(state + 0x5C);
            *(char **)(state + 0x34) = *(char **)(other + 0x34);
        }
        if (*(float *)(state + 0x38) != 0.0f)
            return;
        if (*(float *)(other + 0x38) == 0.0f)
            return;
        *(float *)(state + 0x38) = *(float *)(other + 0x38);
    } else {
        float random = func_002A7878(*(float *)(state + 8), *(float *)(state + 0xC));
        *(float *)(state + 0x38) = (*(float *)(state + 0x60) * (1.0f / 60.0f)) * random;
    }
}
