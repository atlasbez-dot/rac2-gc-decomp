/* Nonmatching reconstruction, 23 October 2026.
 * Profile: -O2 -G8 -ffunction-sections.
 * Final check.py coverage: us 0/1, us2 0/1; no linked build run.
 * Manual path/group reconstruction, default G8: 680/700.
 * Remaining: Persistent path/list registers and float scheduling differ.
 * Reopen after a matching group-list/path initialization witness.
 */
#include "common.h"
extern unsigned short *D_L06_001FB3A0[];
extern char *D_L06_001B281C;
extern char *D_L06_001FE500[];
extern int D_L06_001AFC58 __attribute__((sda));
extern int D_L06_001AFC5C;
extern float D_L06_001AFC60 __attribute__((sda));
extern float D_L06_001AFC64;
extern float func_00282E48(void *, void *);
extern float func_002A7878(float, float);
extern float func_002A78D8(float, float);
extern float func_00283CE0(int);
extern void func_00282C88(void *);
extern int func_002A7820(int, int);
extern float func_002A7940(void);

/* Space the group's objects around a path and initialize their movement. */
void func_L06_003FDEB8(int group)
{
    unsigned short *entry = D_L06_001FB3A0[group];
    char *path, *state, *last;
    float reciprocal, pathLength;
    int count, reverse, closed;
    if (!entry)
        return;
    state = *(char **)(D_L06_001B281C + ((*entry & 0x7FFF) << 8) + 0x68);
    path = D_L06_001FE500[*(int *)state];
    reciprocal = 1.0f / func_00282E48(path + 0x10, path + 0x20);
    pathLength = (float)*(int *)path;
    closed = 1;
    if (func_00282E48(path + 0x10, path + (*(int *)path << 4)) >= 5.0f)
        closed = 0;
    count = 0;
    do {
        last = D_L06_001B281C + ((*entry & 0x7FFF) << 8);
        count++;
    } while ((short)*entry++ >= 0);
    entry = D_L06_001FB3A0[group];
    reverse = count - 1;
    do {
        char *moby = D_L06_001B281C + ((*entry & 0x7FFF) << 8);
        float position;
        state = *(char **)(moby + 0x68);
        *(float *)(state + 0x14) = (reciprocal * (1.0f / 60.0f)) *
                                  func_002A7878(*(float *)(state + 8), *(float *)(state + 0xC));
        *(float *)(state + 0x18) = (reciprocal * 0.0002777777845f) *
                                  (*(float *)(state + 0xC) - *(float *)(state + 8));
        position = func_00283CE0(reverse--);
        position /= func_00283CE0(count);
        position *= pathLength;
        *(char **)(state + 0x34) = last;
        *(float *)(state + 0x60) = reciprocal;
        *(char **)(state + 0x30) = path;
        last = moby;
        *(int *)(state + 0x40) = closed;
        *(float *)(state + 0x5C) = *(float *)(state + 0x14);
        *(float *)(state + 0x38) = *(float *)(state + 0x14);
        *(float *)(state + 0x1C) = reciprocal * 3.5f;
        *(float *)(state + 0x10) = position;
        func_00282C88(state + 0x20);
        *(float *)(state + 0x20) = func_002A78D8(0.0f, *(float *)(state + 4));
        *(float *)(state + 0x28) = func_002A78D8(0.0f, *(float *)(state + 4));
        *(int *)(state + 0x48) = func_002A7820(D_L06_001AFC58, D_L06_001AFC5C);
        *(float *)(state + 0x4C) = func_002A7940();
        *(float *)(state + 0x50) = func_002A78D8(D_L06_001AFC60, D_L06_001AFC64) * 0.0002908882452f;
        *(unsigned char *)(moby + 0x20) = 1;
        *(unsigned short *)(moby + 0x32) = 0xFF;
        *(int *)(state + 0x54) = -1;
    } while ((short)*entry++ >= 0);
}
