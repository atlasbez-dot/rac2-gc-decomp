/* Nonmatching reconstruction, 23 October 2026.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Final check.py coverage: us 0/1, us2 0/1, pal 0/1; no linked build run.
 * Default 488/520; qcopy plus unsplit 536/520; qcopy 540/520.
 * Remaining: Mixed direct/GP table loads and global-base/vector address lifetimes differ.
 * Reopen with a measured source-level model for the mixed table loads and player aggregate.
 */
#include "common.h"
typedef int VectorBits __attribute__((mode(TI)));
extern char D_00189E20[];
extern char *D_L06_001B281C;
extern short D_L06_001B2970[] __attribute__((sda));
extern float func_00282E80(char *, char *);

/* Find the nearest active target and fill the target's position frames. */
int func_L06_00361728(char *moby, char *target, float distance)
{
    char *best = *(char **)(D_00189E20 + 0x2290);
    int kind = 0;
    int index;
    if (*(int *)(D_00189E20 + 0x229C) == 0x18 ||
        *(int *)(D_00189E20 + 0x2294) == 0x6F) {
        best = 0;
        kind = 2;
    }
    for (index = 1; index <= D_L06_001B2970[0]; index++) {
        char *candidate = D_L06_001B281C + (D_L06_001B2970[index] << 8);
        if (candidate &&
            (*(short *)(candidate + 0xAA) == 0xCB ||
             *(short *)(candidate + 0xAA) == 0x76C) &&
            *(unsigned char *)(candidate + 0x20) != 0xFE &&
            *(unsigned char *)(candidate + 0x20) != 0xFD &&
            *(unsigned char *)(candidate + 0x20) == 3) {
            float current = func_00282E80(moby + 0x10, candidate + 0x10);
            if (current < distance) {
                best = candidate;
                distance = current;
                kind = 1;
            }
        }
    }
    if (best) {
        *(char **)(target + 0x40) = best;
        *(VectorBits *)target = *(VectorBits *)(best + 0x10);
        *(VectorBits *)(target + 0x10) = *(VectorBits *)(best + 0xF0);
        if (best == *(char **)(D_00189E20 + 0x2290)) {
            *(VectorBits *)(target + 0x20) = *(VectorBits *)(D_00189E20 + 0xD0);
            *(VectorBits *)(target + 0x30) = *(VectorBits *)(D_00189E20 + 0xE0);
        } else {
            *(VectorBits *)(target + 0x30) = *(VectorBits *)target;
            *(float *)(target + 0x38) += 0.6f;
            *(VectorBits *)(target + 0x20) = *(VectorBits *)(target + 0x30);
        }
    } else {
        *(int *)(target + 0x40) = 0;
        *(VectorBits *)target = 0;
        *(VectorBits *)(target + 0x10) = 0;
        *(VectorBits *)(target + 0x30) = 0;
        *(VectorBits *)(target + 0x20) = 0;
    }
    *(int *)(target + 0x44) = kind;
    return kind;
}
