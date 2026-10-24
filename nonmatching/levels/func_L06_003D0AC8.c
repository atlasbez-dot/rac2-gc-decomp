/* Nonmatching reconstruction, 23 October 2026.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Final check.py coverage: us 0/1; no linked build run.
 * Default 1040/1044; qcopy/barrier exactly 1044 bytes but still 0/1.
 * Remaining: First instruction difference at +0x18; entry zero-store scheduling, indexed table address formation and collision-base registers differ.
 * Reopen with a qualified aggregate/global addressing witness; equal size is not a match.
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

extern void func_002FEE70(int, void *, int);
extern void func_00300190(void *, void *);
extern void func_00300248(void *, void *);
extern void func_002FE880(void *, void *, float);
extern void func_L00_0038F178(void *);
extern int func_00278E78(void);
extern void func_002FD1B8(int, int, int, float, float, float, float);
extern int D_L06_001B2FB0 __attribute__((sda));
extern int D_L06_001B2FB8 __attribute__((sda));
extern void func_00282C88(void *);
extern char *func_00312D58(void *, float);
extern float func_002A7940(void);
extern float func_002A7878(float, float);
extern float func_00283180(float);
extern float func_00283198(float);
extern int func_002A7820(int, int);
extern int func_002A77E0(int);
extern void func_002BFB38(void *, void *, int, int);

/* Advance a projectile and create splash effects when it enters water. */
void func_L06_003D0AC8(char *moby)
{
    float oldPosition[4], normal[4], direction[4];
    char query[0x30];
    float splash[4], velocity[4];
    char *state, *hit;
    *(VectorBits *)normal = 0;
    state = *(char **)(moby + 0x68);
    *(VectorBits *)direction = 0;
    normal[2] = 1.0f / 30.0f;
    direction[2] = 1.0f;
    *(VectorBits *)oldPosition = *(VectorBits *)(moby + 0x10);
    func_00282CC0(moby + 0x10, state, moby + 0x10);
    func_002FEE70(*(int *)(state + 0x1C), state, 0);
    func_00300190(moby + 0x10, moby + 0x10);
    func_00300248(state, state);
    func_002FE880(moby + 0x10, state, 0.003055555746f);
    func_L00_0038F178(moby);
    *(char **)(query + 0x10) = moby;
    *(int *)(query + 0x14) = 0x830000;
    if (*(int *)(state + 0x18) < 0x122)
        *(int *)(query + 0x14) = 0x830001;
    *(float *)(query + 0x1C) = *(float *)(D_L06_0026C7F0 + D_00139574 * 0xE0 + 0x70);
    *(int *)(query + 0x20) = 1;
    *(VectorBits *)query = *(VectorBits *)state;
    func_00282F70(query, query, 1.0f);
    *(float *)(query + 8) = 1.0f;
    *(float *)(query + 0xC) = 5627.9248f;
    *(unsigned char *)(query + 0x18) = 2;
    *(unsigned short *)(query + 0x1A) = *(unsigned short *)(moby + 0xAA);
    *(unsigned char *)(query + 0x19) = 1;
    if (func_002761F8(oldPosition, moby + 0x10, 0x10, moby, query)) {
        if (!func_00278E78() && *(float *)(state + 8) < 0.0f) {
            char *effect;
            int count;
            func_002FD1B8(D_L06_001B2FB0, D_L06_001B2FB8, 1,
                         *(float *)(moby + 0x10), *(float *)(moby + 0x14), 0.5f, -0.35f);
            *(int *)(state + 0x14) = 1;
            func_00282C88(state);
            *(float *)(state + 8) = -0.02500000224f;
            splash[0] = *(float *)(moby + 0x10);
            splash[1] = *(float *)(moby + 0x14);
            splash[2] = *(float *)(D_L06_001BFC80 + 0x28);
            effect = func_00312D58(splash, 2.0f);
            if (effect)
                *(unsigned char *)(effect + 0x23) = 0x70;
            for (count = 15; count >= 0; count--) {
                float angle = func_002A7940();
                float speed = func_002A7878(0.0f, 0.05000000447f);
                int lifetime, type;
                velocity[0] = func_00283180(angle) * speed;
                velocity[1] = func_00283198(angle) * speed;
                velocity[2] = func_002A7878(0.05000000447f, 0.1083333418f);
                lifetime = func_002A7820(90, 120);
                type = func_002A77E0(2);
                func_002BFB38(splash, velocity, type, lifetime);
            }
        } else {
            hit = *(char **)(D_L06_001BFC80 + 0x18);
            if (hit) {
                if ((hit == D_0018C0B0 || *(short *)(hit + 0xAA) == 0xC0) &&
                    *(int *)(state + 0x18) >= 0x122)
                    return;
                if (*(int *)(hit + 0x64) == D_L06_001AC790 && *(short *)(hit + 0xAA) != 0x336)
                    goto finish;
            } else if (*(int *)(D_L06_001BFC80 + 0x1C) <= 0) {
                goto finish;
            }
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
        func_L00_0038DE70(moby, normal, direction);
    }
}
