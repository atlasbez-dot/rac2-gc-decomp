/*
 * Complete manual reconstruction retained as nonmatching; no coverage credit.
 * Fresh qualified-compiler checks, 2026-10-25.
 * Profile: -O2 -G8 -ffunction-sections
 * Coverage: US: 0/1; US2: absent from catalogue; PAL: absent from catalogue.
 * Compiled text: 1280 bytes; retail: 1300 bytes.
 * Remaining difference: The measured scene-header view restores frame 0xE0 from 0xD0 and gives
 * 1280/1300 bytes. The five complete aligned vectors and all six particle allocations remain
 * intact. Index/object register ownership, repeated null checks, and the mixed GP/direct level-
 * word accesses still differ.
 * Reopen when: Independent source evidence for the loop and canonical level/scene global model,
 * rather than a false second alias for the level word.
 */

#include "common.h"
typedef int VectorBits __attribute__((mode(TI)));
typedef float Vector[4] __attribute__((aligned(16)));
extern void func_L00_002FC980(void);
extern void func_002E64A0(char *);
extern void func_L00_00326048(void *, void *, int, int, float);
typedef struct {
    unsigned char before_active[0x30]; int active;
    unsigned char before_count[0x10]; short count;
    unsigned char before_objects[0x146];
} ScenePrefix;
extern ScenePrefix D_L06_001BD540;
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
    Vector left, right, velocity, position, shift;
    char *moby, *first, *second, *spark;
    int i, rotation;
    func_L00_002FC980();
    for (i = 0; i < D_L06_001BD540.count; i++) {
        moby = ((char **)((char *)&D_L06_001BD540 + 0x18C))[i];
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
    if (D_001A79F0 != 6 || D_L06_001BD540.active)
        return;
    moby = ((char **)((char *)&D_L06_001BD540 + 0x18C))[2];
    if (*(short *)(moby + 0xAA) != 0xE29)
        return;
    func_0029FCC0(moby, 0, left);
    func_0029FCC0(moby, 1, right);
    rotation = func_002A77E0(16);
    func_00282F20(velocity, moby + 0xC0, 0.7333333492f);
    if (func_002A77E0(2))
        rotation = -rotation;
    qcopy(position, left);
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
    qcopy(shift, (moby + 0xD0));
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
