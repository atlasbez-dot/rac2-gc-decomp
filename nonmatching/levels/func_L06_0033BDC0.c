/* Nonmatching reconstruction, 23 October 2026.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Final check.py coverage: us 0/1; no linked build run.
 * Default 1264/1300; qcopy/barrier 1268/1300.
 * Remaining: Player/scene aggregate address formation, mixed direct/GP load and exhaust-particle register lifetimes differ.
 * Reopen with a typed scene aggregate and matching particle-call lifetime witness.
 */
#include "common.h"
typedef int VectorBits __attribute__((mode(TI)));
extern void func_L00_002FC980(void);
extern void func_002E64A0(char *);
extern void func_L00_00326048(void *, void *, int, int, float);
extern char D_L06_001BD540[];
extern int D_001A79F0 __attribute__((sda));
extern void func_0029FCC0(void *, int, void *);
extern int func_002A77E0(int);
extern void func_00282F20(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern char *func_002BDCE8(void *, int, void *, int, int, float, float, float, float);
extern int func_00283CF0(float);

/* Update special scene objects, then emit the ship's paired exhaust effects. */
void func_L06_0033BDC0(void)
{
    float left[4], right[4], velocity[4], position[4], shift[4];
    char *moby, *first, *second, *spark;
    int i, rotation;
    func_L00_002FC980();
    for (i = 0; i < *(short *)(D_L06_001BD540 + 0x44); i++) {
        moby = ((char **)(D_L06_001BD540 + 0x18C))[i];
        if (moby) {
            if (*(short *)(moby + 0xAA) == 0xE29)
                *(unsigned short *)(moby + 0x34) |= 0x800;
            if (*(short *)(moby + 0xAA) == 0xD54)
                func_002E64A0(moby);
        }
        if (moby && *(short *)(moby + 0xAA) == 0xFA0) {
            char *state = *(char **)(moby + 0x68);
            if (state)
                func_L00_00326048(moby, state + 0xC, 0x80AAAAD2, 0x80396464, 0.06108653545f);
        }
    }
    if (D_001A79F0 != 6 || *(int *)(D_L06_001BD540 + 0x30))
        return;
    moby = *(char **)(D_L06_001BD540 + 0x194);
    if (*(short *)(moby + 0xAA) != 0xE29)
        return;
    func_0029FCC0(moby, 0, left);
    func_0029FCC0(moby, 1, right);
    rotation = func_002A77E0(16);
    func_00282F20(velocity, moby + 0xC0, 0.7333333492f);
    if (func_002A77E0(2))
        rotation = -rotation;
    *(VectorBits *)position = *(VectorBits *)left;
    first = func_002BDCE8(position, rotation, velocity, 0xDF204080, 0,
                            0.1f, 1.0f, 0.9f, 315000.0f);
    if (first) {
        *(short *)(first + 0xA) = 7;
        *(unsigned char *)(first + 9) = func_00283CF0(4.0f) + 0x70;
        *(int *)(first + 0x24) = 2;
        *(unsigned char *)(first + 0x2A) = 0xDF;
        *(unsigned char *)(first + 0x2B) = *(unsigned char *)(first + 0xA);
    }
    second = func_002BDCE8(position, rotation, velocity, 0xDF204080, 0,
                             0.1f, 1.0f, 0.9f, 315000.0f);
    if (second) {
        *(short *)(first + 0xA) = 7;
        *(unsigned char *)(first + 9) = func_00283CF0(4.0f) + 0x70;
        *(int *)(second + 0x24) = 2;
        *(unsigned char *)(second + 0x2A) = 0xDF;
        *(unsigned char *)(second + 0x2B) = *(unsigned char *)(first + 0xA);
    }
    spark = func_002BDCE8(position, 16, velocity, 0xDFFFFFFF, 0,
                            0.05f, 1.0f, 0.97f, 210000.0f);
    if (spark) {
        *(unsigned char *)(spark + 9) = func_00283CF0(4.0f) + 0x70;
        *(short *)(spark + 0xA) = 7;
        *(unsigned char *)(spark + 8) = func_002A77E0(255);
        *(unsigned char *)(spark + 0x2A) = 0xDF;
        *(int *)(spark + 0x24) = 2;
        *(unsigned char *)(spark + 0x2B) = *(unsigned char *)(first + 0xA);
    }
    *(VectorBits *)shift = *(VectorBits *)(moby + 0xD0);
    func_00282F20(shift, shift, 0.3f);
    func_00282CC0(position, position, shift);
    first = func_002BDCE8(position, 16, velocity, 0xDF204080, 0,
                            0.1f, 1.0f, 0.9f, 315000.0f);
    if (first) {
        *(short *)(first + 0xA) = 7;
        *(unsigned char *)(first + 9) = func_00283CF0(4.0f) + 0x70;
        *(int *)(first + 0x24) = 2;
        *(unsigned char *)(first + 0x2A) = 0xDF;
        *(unsigned char *)(first + 0x2B) = *(unsigned char *)(first + 0xA);
    }
    second = func_002BDCE8(position, 16, velocity, 0xDF204080, 0,
                             0.1f, 1.0f, 0.9f, 315000.0f);
    if (second) {
        *(short *)(first + 0xA) = 7;
        *(unsigned char *)(first + 9) = func_00283CF0(4.0f) + 0x70;
        *(int *)(second + 0x24) = 2;
        *(unsigned char *)(second + 0x2A) = 0xDF;
        *(unsigned char *)(second + 0x2B) = *(unsigned char *)(first + 0xA);
    }
    spark = func_002BDCE8(position, 16, velocity, 0xDFFFFFFF, 0,
                            0.05f, 1.0f, 0.97f, 210000.0f);
    if (spark) {
        *(unsigned char *)(spark + 9) = func_00283CF0(4.0f) + 0x70;
        *(short *)(spark + 0xA) = 7;
        *(unsigned char *)(spark + 8) = func_002A77E0(255);
        *(unsigned char *)(spark + 0x2A) = 0xDF;
        *(int *)(spark + 0x24) = 2;
        *(unsigned char *)(spark + 0x2B) = *(unsigned char *)(first + 0xA);
    }
}
