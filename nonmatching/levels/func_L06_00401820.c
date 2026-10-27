/*
 * Complete manual reconstruction retained as nonmatching; no coverage credit.
 * Fresh qualified-compiler checks, 2026-10-25.
 * Profile: -O2 -G0 -ffunction-sections
 * Coverage: US: 0/1; US2: 0/1; PAL: 0/1.
 * Compiled text: 1416 bytes; retail: 1424 bytes.
 * Remaining difference: The complete aligned vectors and canonical 32-bit sound-owner argument are
 * retained. Frame 0x70 matches, but the body remains 1416/1424. A canonical player vector and a
 * measured sound-entry view did not resolve sound-handle allocation or state-transition
 * scheduling.
 * Reopen when: A verified platform/sound address-lifetime model; avoid arbitrary instruction
 * padding or prototype permutations.
 */

#include "common.h"
typedef int VectorBits __attribute__((mode(TI)));
typedef float Vector[4] __attribute__((aligned(16)));
extern char D_00188660[];
extern Vector D_00189EA0;
extern int func_L00_00324120(void *);
extern void func_002A7750(void *, int, int);
extern int func_002E59B0(int, int);
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
    Vector oldPosition, oldRotation, movement;
    char *state = *(char **)(moby + 0x68);
    char *sound;
    int handle;
    qcopy(oldPosition, (moby + 0x10));
    qcopy(oldRotation, (moby + 0xF0));
    switch (*(unsigned char *)(moby + 0x20)) {
    case 0:
        *(int *)(state + 0x5C) |= 1;
        qcopy((state + 0x60), (moby + 0x10));
        *(unsigned char *)(moby + 0x20) = 1;
        *(int *)(state + 0x88) = -1;
        *(int *)(state + 0x80) = 0;
        *(int *)(state + 0x84) = 0;
        break;
    case 1:
        if (func_L00_00324120(moby)) {
            if (*(int *)(state + 0x80) == 0) {
                func_002A7750(moby, 3, -1);
                if (!func_002E59B0((int)moby, *(int *)(state + 0x88)))
                    *(int *)(state + 0x88) = func_002E5CF8(0, 4, moby);
            } else {
                func_002A7750(moby, 2, -1);
                if (!func_002E59B0((int)moby, *(int *)(state + 0x88)))
                    *(int *)(state + 0x88) = func_002E5CF8(1, 4, moby);
            }
        }
        if (D_00189EA0[2] < 55.0f && *(int *)(state + 0x80) == 0) {
            if (!func_002E59B0((int)moby, *(int *)(state + 0x88)))
                *(int *)(state + 0x88) = func_002E5CF8(0, 4, moby);
            func_002A7750(moby, 3, -1);
        } else if (D_00189EA0[2] > 57.0f && *(int *)(state + 0x80) == 1 &&
                   func_002ACBC8(D_00189EA0, *(int *)(state + 0x8C))) {
            if (!func_002E59B0((int)moby, *(int *)(state + 0x88)))
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
                qcopy((moby + 0x10), (state + 0x60));
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
            D_00189EA0[2] < *(float *)(moby + 0x18))
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
