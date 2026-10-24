/* Nonmatching reconstruction, 23 October 2026.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Final check.py coverage: us 0/1, us2 0/1, pal 0/1; no linked build run.
 * Default 1408/1424; qcopy/barrier 1416/1424.
 * Remaining: Vector/member addresses, state-transition branches and sound-handle registers differ.
 * Reopen with a validated moving-platform vector/address lifetime witness.
 */
#include "common.h"
typedef int VectorBits __attribute__((mode(TI)));
extern char D_00188660[];
extern char D_00189EA0[];
extern float D_00189EA8;
extern int func_L00_00324120(void *);
extern void func_002A7750(void *, int, int);
extern int func_002E59B0(void *, int);
extern int func_002E5CF8(int, int, void *);
extern void func_002E59F8(int);
extern int func_002ACBC8(void *, int);
extern float func_00282E48(void *, void *);
extern float func_00283180(float);
extern float func_00283198(float);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_002AD6F0(void *, void *, void *, void *);

/* Move a platform between its two paths according to the player's height. */
void func_L06_00401820(char *moby)
{
    float oldPosition[4], oldRotation[4], movement[4];
    char *state = *(char **)(moby + 0x68);
    char *sound;
    int handle;
    *(VectorBits *)oldPosition = *(VectorBits *)(moby + 0x10);
    *(VectorBits *)oldRotation = *(VectorBits *)(moby + 0xF0);
    switch (*(unsigned char *)(moby + 0x20)) {
    case 0:
        *(int *)(state + 0x5C) |= 1;
        *(VectorBits *)(state + 0x60) = *(VectorBits *)(moby + 0x10);
        *(unsigned char *)(moby + 0x20) = 1;
        *(int *)(state + 0x88) = -1;
        *(int *)(state + 0x80) = 0;
        *(int *)(state + 0x84) = 0;
        break;
    case 1:
        if (func_L00_00324120(moby)) {
            if (*(int *)(state + 0x80) == 0) {
                func_002A7750(moby, 3, -1);
                if (!func_002E59B0(moby, *(int *)(state + 0x88)))
                    *(int *)(state + 0x88) = func_002E5CF8(0, 4, moby);
            } else {
                func_002A7750(moby, 2, -1);
                if (!func_002E59B0(moby, *(int *)(state + 0x88)))
                    *(int *)(state + 0x88) = func_002E5CF8(1, 4, moby);
            }
        }
        if (D_00189EA8 < 55.0f && *(int *)(state + 0x80) == 0) {
            if (!func_002E59B0(moby, *(int *)(state + 0x88)))
                *(int *)(state + 0x88) = func_002E5CF8(0, 4, moby);
            func_002A7750(moby, 3, -1);
        } else if (D_00189EA8 > 57.0f && *(int *)(state + 0x80) == 1 &&
                   func_002ACBC8(D_00189EA0, *(int *)(state + 0x8C))) {
            if (!func_002E59B0(moby, *(int *)(state + 0x88)))
                *(int *)(state + 0x88) = func_002E5CF8(1, 4, moby);
            func_002A7750(moby, 2, -1);
        }
        break;
    case 2:
        if (func_00282E48(moby + 0x10, state + 0x60) <= 0.04f) {
            if (!func_L00_00324120(moby)) {
                *(int *)(state + 0x80) = 0;
                handle = *(int *)(state + 0x88);
                if (handle != -1) {
                    sound = D_00188660 + handle * 0x70;
                    if (*(char **)(sound + 0x88) == moby && *(unsigned char *)(sound + 0x74))
                        func_002E59F8(handle);
                }
                *(int *)(state + 0x88) = -1;
                func_002A7750(moby, 1, -1);
                *(VectorBits *)(moby + 0x10) = *(VectorBits *)(state + 0x60);
                *(int *)(state + 0x84) = 0;
            } else {
                goto stop;
            }
        } else {
            movement[0] = func_00283180(*(float *)(moby + 0xF8) + 1.57079649f) * 0.05f;
            movement[1] = func_00283198(*(float *)(moby + 0xF8) + 1.57079649f) * 0.05f;
            movement[2] = 0.0f;
            func_00282CC0(moby + 0x10, moby + 0x10, movement);
            if (*(int *)(state + 0x84) < 104)
                *(float *)(moby + 0x18) += 0.07f;
            (*(int *)(state + 0x84))++;
        }
        break;
    case 3:
        if (*(float *)(moby + 0x18) < 50.75f) {
            if (!func_L00_00324120(moby) && *(float *)(moby + 0x18) < 50.75f) {
                *(int *)(state + 0x80) = 1;
                handle = *(int *)(state + 0x88);
                if (handle != -1) {
                    sound = D_00188660 + handle * 0x70;
                    if (*(char **)(sound + 0x88) == moby && *(unsigned char *)(sound + 0x74))
                        func_002E59F8(handle);
                }
                *(int *)(state + 0x88) = -1;
                func_002A7750(moby, 1, -1);
                *(int *)(state + 0x84) = 0;
            } else {
                goto stop;
            }
            break;
        }
        if (*(float *)(moby + 0x18) < 53.0f &&
            func_002ACBC8(D_00189EA0, *(int *)(state + 0x8C)) &&
            D_00189EA8 < *(float *)(moby + 0x18))
            break;
        movement[0] = func_00283180(*(float *)(moby + 0xF8) - 1.57079649f) * 0.05f;
        movement[1] = func_00283198(*(float *)(moby + 0xF8) - 1.57079649f) * 0.05f;
        movement[2] = 0.0f;
        func_00282CC0(moby + 0x10, moby + 0x10, movement);
        if (*(int *)(state + 0x84) >= 61)
            *(float *)(moby + 0x18) -= 0.07f;
        (*(int *)(state + 0x84))++;
        break;
    }
    goto done;
stop:
    handle = *(int *)(state + 0x88);
    if (handle != -1) {
        sound = D_00188660 + handle * 0x70;
        if (*(char **)(sound + 0x88) == moby && *(unsigned char *)(sound + 0x74))
            func_002E59F8(handle);
    }
    *(int *)(state + 0x88) = -1;
done:
    func_00282CF0(movement, moby + 0x10, oldPosition);
    func_002AD6F0(state + 0x20, movement, oldRotation, moby + 0xF0);
}
