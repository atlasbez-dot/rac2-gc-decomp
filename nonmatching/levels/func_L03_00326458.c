/* Reconstructed 2026-10-23; -O2 -G0 -ffunction-sections.
 * us: 0/3, us2: 0/3, pal: absent.
 * Same 728-byte size and 0xD0 frame.
 * Template address hoisting changes saved-register allocation, call setup and loop stores.
 * Energy/radius source order corrected the first FP difference; no-split-addresses and no-GCSE did not solve the body.
 * Reopen with original template-address lifetime or loop allocation evidence.
 */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
extern float D_L03_001A8F20[4];
extern void func_00282CC0(void *, void *, void *);
extern int func_002A77E0(int);
extern void func_0029FC20(void *, int, void *);
extern float func_00282DF0(void *);
extern void func_00282F20(void *, void *, float);
extern unsigned char *func_002BDCE8(void *, int, void *, unsigned int, int, float, float, float, float);

void func_L03_00326458(unsigned char *object)
{
    float matrix[16], point[4], velocity[4];
    float weight, radius, energy;
    unsigned char *particle;
    int spin, i;
    short type = *(short *)(object + 0xAA);
    if ((type != 0x2EE && type != 0xCE0) || object == 0)
        return;
    func_0029FC20(object, 0, matrix);
    weight = func_00282DF0(matrix) * 0.9746588468551636f;
    if (weight > 1.0f)
        weight = 1.0f;
    energy = weight * 44000.0f + 6000.0f;
    radius = weight * 0.02f + 0.01f;
    func_00282F20(velocity, matrix + 8, weight * -0.025f + -0.025f);
    func_00282CC0(point, matrix + 12, velocity);
    for (i = 1; i >= 0; i--) {
        spin = func_002A77E0(16);
        if (func_002A77E0(2))
            spin = -spin;
        particle = func_002BDCE8(point, spin, D_L03_001A8F20, 0x503030FF, 0, radius, 1.0f, 0.75f, energy);
        if (particle != 0) {
            unsigned char *payload = particle + 0x20;
            *(short *)(particle + 0xA) = 6;
            *(int *)(payload + 4) = 2;
            payload[0xA] = 0x50;
            payload[0xB] = particle[0xA];
        }
    }
    energy = weight * 25000.0f + 5000.0f;
    radius = weight * 0.015000000596046448f + 0.01f;
    func_00282F20(velocity, matrix + 8, weight * -0.015000000596046448f + -0.01f);
    func_00282CC0(point, matrix + 12, velocity);
    for (i = 4; i >= 0; i--) {
        particle = func_002BDCE8(point, 16, D_L03_001A8F20, 0x7FFFFFFF, 0, radius, 1.0f, 1.0f, energy);
        if (particle != 0) {
            unsigned char *payload;
            *(short *)(particle + 0xA) = 2;
            particle[8] = func_002A77E0(255);
            payload = particle + 0x20;
            *(int *)(payload + 4) = 2;
            payload[0xA] = 0x7F;
            payload[0xB] = particle[0xA];
        }
    }
}
