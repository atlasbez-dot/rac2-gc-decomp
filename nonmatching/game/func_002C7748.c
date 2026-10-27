/* SPDX-License-Identifier: MIT
 *
 * Near miss: func_002C7748 (SpawnSplashDropletParticle), 320 bytes in the retail boot and in
 * every level, 28 places.
 *
 * Draft marked G8: it needs a -g8.c source unit (the three small-data floats) when it is
 * checked again; the profile is -O2 -G8 -ffunction-sections.
 *
 * Result: 320/320 bytes, 0/28 places in USA v1.01. The body, the call order, the packet
 * fields, the two quadword copies and the small-data reads are retail's; only the entry
 * block's register allocation differs: retail keeps the particle in $s1 and the velocity
 * slot in $s0, this source keeps the particle in $s0 and the velocity slot in $s1, which
 * also swaps the two saved-register slots and every use of the two pointers.
 *
 * The declaration order, the assignment order, the two copy forms (the qcopy helper and a
 * TImode assignment with -frac2-qcopy -frac2-qcopy-barrier) and a goto form for the null
 * test all leave the allocation unchanged. Reopen with a source shape that changes the
 * allocator's priority for the two pointers.
 */

#include "common.h"

extern float D_001AA3CC __attribute__((sda));
extern float D_001AA3D0 __attribute__((sda));
extern float D_001AA3D4 __attribute__((sda));
extern char *D_001F26C0;

extern void *func_002B9030(int size);
extern float func_002A7878(float, float);
extern int func_002A77E0(int);
extern int func_002A7820(int, int);
extern int func_00283CF0(float);

/* Spawns a splash droplet: a new particle with a position, a velocity and a life. */
void *func_002C7748(char *pos, char *vel, int life)
{
    char *p;
    char *q;

    p = func_002B9030(0x60);
    q = p + 0x20;
    if (p != 0) {
        p[9] = func_00283CF0(2.0f) + 0x40;
        p[3] = 0x44;
        p[1] = 0;
        p[2] = *(unsigned char *)D_001F26C0;
        *(float *)(p + 0xC) = func_002A7878(D_001AA3CC, D_001AA3D0) * 105000.0f;
        p[8] = func_002A77E0(0xFF);
        *(short *)(p + 0xA) = (short)life;
        *(int *)(p + 4) = 0x40808080;

        qcopy(p + 0x10, pos);
        qcopy(q, vel);
        *(int *)(q + 0xC) = 0;
        *(float *)(q + 0x18) = *(float *)(p + 0xC) * 2.0f;
        *(int *)(q + 0x14) = func_002A7820(0, 3);
        *(int *)(q + 0x10) = life / 2;
        *(float *)(q + 0x1C) = func_002A7878(D_001AA3D4, D_001AA3D4 + 2.0f) * 0.00027777778f;
    }
    return p;
}
