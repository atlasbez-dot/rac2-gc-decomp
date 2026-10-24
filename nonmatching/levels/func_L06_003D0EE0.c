/* Nonmatching reconstruction, 23 October 2026.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Final check.py coverage: us 0/1; no linked build run.
 * Default 748/776; qcopy/barrier 768/776.
 * Remaining: Vector temporaries, global collision base, entry scheduling and branch layout differ.
 * Reopen with a shared projectile/collision aggregate type and validated source profile.
 */
#include "common.h"
typedef int VectorBits __attribute__((mode(TI)));
extern void func_00282CC0(void *, void *, void *);
extern void func_002AFFD8(void *, void *, int);
extern void func_00282D30(void *, void *, float);
extern void func_L00_0038F3D8(void *);
extern void func_00282F70(void *, void *, float);
extern int func_002761F8(void *, void *, int, void *, void *);
extern void func_00283028(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern int func_00282948(void *);
extern void func_002FEE50(int);
extern void func_L00_0038DE70(void *, void *, void *);
extern void func_L00_0038E880(void *, void *, void *);
extern unsigned char D_00139574;
extern char D_L06_0026C7F0[];
extern char D_L06_001BFC80[];
extern char *D_0018C0B0;
extern int D_L06_001AC790;

/* Trace a projectile's next step and dispatch its contact response. */
void func_L06_003D0EE0(char *moby)
{
    float normal[4], direction[4], oldPosition[4], acceleration[4];
    char query[0x30];
    char *state, *hit;
    *(VectorBits *)normal = 0;
    state = *(char **)(moby + 0x68);
    *(VectorBits *)direction = 0;
    normal[2] = 1.0f / 30.0f;
    direction[2] = 1.0f;
    *(VectorBits *)oldPosition = *(VectorBits *)(moby + 0x10);
    func_00282CC0(moby + 0x10, moby + 0x10, state);
    func_002AFFD8(moby + 0x10, acceleration, 0);
    func_00282D30(acceleration, acceleration, 0.000305555586f);
    func_L00_0038F3D8(moby);
    *(char **)(query + 0x10) = moby;
    *(int *)(query + 0x14) = 0x830000;
    if (*(int *)(state + 0x18) < 0x122)
        *(int *)(query + 0x14) = 0x830001;
    *(float *)(query + 0x1C) = *(float *)(D_L06_0026C7F0 + D_00139574 * 0xE0 + 0x70);
    *(int *)(query + 0x20) = 1;
    *(VectorBits *)query = *(VectorBits *)state;
    func_00282F70(query, query, 1.0f);
    *(float *)(query + 0xC) = 5627.9248f;
    *(unsigned char *)(query + 0x18) = 2;
    *(unsigned short *)(query + 0x1A) = *(unsigned short *)(moby + 0xAA);
    *(float *)(query + 8) = 1.0f;
    *(unsigned char *)(query + 0x19) = 1;
    (*(int *)(state + 0x14))++;
    if (func_002761F8(oldPosition, moby + 0x10, 0x10, moby, query)) {
        hit = *(char **)(D_L06_001BFC80 + 0x18);
        if (hit) {
            if ((hit == D_0018C0B0 || *(short *)(hit + 0xAA) == 0xC0) &&
                *(int *)(state + 0x18) >= 0x122)
                return;
            if (*(int *)(hit + 0x64) == D_L06_001AC790 && *(short *)(hit + 0xAA) != 0x336)
                goto finish;
            *(unsigned char *)(moby + 0xBC) = 1;
            *(VectorBits *)(moby + 0x10) = *(VectorBits *)(D_L06_001BFC80 + 0x20);
            func_00283028(normal, state, D_L06_001BFC80 + 0x40);
            func_00282F20(normal, normal, 1.0f / 30.0f);
            func_00282F20(direction, D_L06_001BFC80 + 0x40, 1.0f);
        } else if (*(int *)(D_L06_001BFC80 + 0x1C) > 0) {
            *(unsigned char *)(moby + 0xBC) = 1;
            *(VectorBits *)(moby + 0x10) = *(VectorBits *)(D_L06_001BFC80 + 0x20);
            func_00283028(normal, state, D_L06_001BFC80 + 0x40);
            func_00282F20(normal, normal, 1.0f / 30.0f);
            func_00282F20(direction, D_L06_001BFC80 + 0x40, 1.0f);
        }
    } else if (func_00282948(state + 0x18)) {
        *(unsigned char *)(moby + 0xBC) = 1;
        func_00282CC0(normal, normal, state);
    }
finish:
    if (*(unsigned char *)(moby + 0xBC)) {
        func_002FEE50(*(int *)(state + 0x1C));
        if (*(int *)(state + 0x14) < 20)
            func_L00_0038DE70(moby, normal, direction);
        else
            func_L00_0038E880(moby, normal, direction);
    }
}
