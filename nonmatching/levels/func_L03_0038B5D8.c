/* Reconstructed 2026-10-23; -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * us: 0/2, us2: 0/2, pal: 0/2.
 * 1664/1768 bytes, expected 0x100 frame.
 * Strand-pool copies, inner-loop address accumulation and FP allocation differ.
 * Single-pool and independently referenced input/output pool views gave 1668 and 1664 bytes.
 * Exact phase2 constant corrected to 0xBFC25C21.
 * Reopen with measured pool/strand lifetime structure.
 */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef union { Quad quad; float f[4]; } RopeVector;
extern RopeVector D_L03_00238040[][16];
extern RopeVector D_L03_00238440[][16];
extern RopeVector *D_L03_001FE700[];
extern RopeVector D_L03_00237F40[];
extern float D_00189EA0[4];
extern float func_00283B98(float, float);
extern void func_00282CF0(void *, void *, void *);
extern float func_00282DF0(void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282D30(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern float func_002ABB18(float);
extern float func_00283198(float);
extern float func_00283180(float);
extern float func_00283248(float, float);

/* Builds four vertex strands and applies shared displacement and phase offsets. */
void func_L03_0038B5D8(u8 *object)
{
    RopeVector toward, relative, blended, tangent, radial, jitter;
    u8 *state = *(u8 **)(object + 0x68);
    int row, column;
    int flags;
    float segmentLength, vertical, phase, angle, magnitude;
    *(float *)(state + 0x94) = func_00283B98(*(float *)(state + 0x94), *(float *)(state + 0x98));
    *(float *)(state + 0xA8) = func_00283B98(*(float *)(state + 0xA8), *(float *)(state + 0x98));
    *(float *)(state + 0x84) += *(float *)(state + 0x88);
    if (*(float *)(state + 0x84) > 1.0f)
        *(float *)(state + 0x84) -= 1.0f;
    for (row = 0; row < 4; row++) {
        int group = *(int *)(state + 0x28 + row * 4);
        flags = *(int *)(state + 0x3C);
        if ((flags & 1) && group >= 0) {
            RopeVector *source = D_L03_001FE700[group] + 1;
            RopeVector *destination = D_L03_00238040[*(int *)(state + 0xDC) + row];
            for (column = 0; column < *(int *)(state + 0x38); column++)
                destination[column].quad = source[column].quad;
            if (flags & 8) {
                float distance, strength;
                func_00282CF0(&toward, D_00189EA0, state + 0xE0);
                distance = func_00282DF0(&toward);
                func_00282F20(&toward, &toward, 1.1f);
                if (distance <= *(float *)(state + 0xD4) + 1.1f) {
                    strength = 1.0f - (distance - 1.1f) / *(float *)(state + 0xD4);
                    for (column = 0; column < *(int *)(state + 0x38); column++) {
                        RopeVector *vertex = &D_L03_00238040[*(int *)(state + 0xDC) + row][column];
                        float length, amount;
                        relative.quad = vertex->quad;
                        func_00282CF0(&relative, &relative, state + 0xE0);
                        length = func_00282DF0(&relative);
                        if (length > 1.1f)
                            length = 1.1f;
                        amount = strength * (1.0f - length * 0.9090909f);
                        func_00282D30(&blended, &toward, amount);
                        func_00282D30(&relative, &relative, 1.0f - amount);
                        func_00282CC0(&blended, &blended, &relative);
                        func_00282CC0(vertex, &blended, state + 0xE0);
                    }
                }
            }
        } else {
            tangent.f[0] = 0.0f;
            tangent.f[1] = 0.0f;
            tangent.f[3] = 1.0f;
            switch (row) {
            case 0:
                tangent.f[2] = 1.1f;
                break;
            case 1:
                tangent.f[0] = -0.6395348906517029f;
                tangent.f[1] = -0.6395348906517029f;
                tangent.f[2] = -0.6395348906517029f;
                break;
            case 2:
                tangent.f[0] = 0.6395348906517029f;
                tangent.f[1] = -0.6395348906517029f;
                tangent.f[2] = -0.6395348906517029f;
                break;
            default:
                tangent.f[1] = 0.785714328289032f;
                tangent.f[2] = -0.6395348906517029f;
                break;
            }
            for (column = 0; column < *(int *)(state + 0x38); column++) {
                RopeVector *vertex;
                func_00282F20(&radial, &tangent, (float)column / ((float)*(int *)(state + 0x38) - 0.5f));
                vertex = &D_L03_00238040[*(int *)(state + 0xDC) + row][column];
                vertex->quad = radial.quad;
                func_00282CC0(vertex, vertex, state + 0xE0);
            }
        }
    }
    func_00282CF0(&tangent, &D_L03_00238040[*(int *)(state + 0xDC)][1],
                             &D_L03_00238040[*(int *)(state + 0xDC)][0]);
    segmentLength = func_00282DF0(&tangent);
    for (column = 0; column < *(int *)(state + 0x38); column++) {
        vertical = 0.0f;
        phase = 0.0f;
        if (!(*(int *)(state + 0x3C) & 0x40))
            func_00282D30(&jitter, &D_L03_00237F40[column], *(float *)(state + 0x90) * segmentLength);
        if (!(*(int *)(state + 0x3C) & 0x80)) {
            float firstPhase = func_002ABB18(*(float *)(state + 0x94) + (float)column * -1.780236005783081f);
            float first = func_00283198(firstPhase);
            phase = func_002ABB18(*(float *)(state + 0xA8) + (float)column * -1.5184365510940552f);
            vertical = segmentLength * (*(float *)(state + 0xA0) * first * func_00283198(phase));
        }
        if (!(*(int *)(state + 0x3C) & 0x100)) {
            angle = func_00283B98(func_00283248(tangent.f[0], tangent.f[1]), 1.5707964897155762f);
            magnitude = segmentLength * *(float *)(state + 0xA4) * func_00283180(phase);
            radial.f[0] = func_00283180(angle) * magnitude;
            radial.f[1] = func_00283198(angle) * magnitude;
            radial.f[2] = 0.0f;
        }
        for (row = 0; row < 4; row++) {
            int base = *(int *)(state + 0xDC) + row;
            RopeVector *original = &D_L03_00238040[base][column];
            RopeVector *output = &D_L03_00238440[base][column];
            output->quad = original->quad;
            if (column != 0 && column != *(int *)(state + 0x38) - 1) {
                if (!(*(int *)(state + 0x3C) & 0x40)) {
                    func_00282CC0(output, output, &jitter);
                    func_00282CC0(original, original, &jitter);
                }
                if (!(*(int *)(state + 0x3C) & 0x80))
                    D_L03_00238440[*(int *)(state + 0xDC) + row][column].f[2] += vertical;
                if (!(*(int *)(state + 0x3C) & 0x100))
                    func_00282CC0(&D_L03_00238440[*(int *)(state + 0xDC) + row][column],
                                 &D_L03_00238440[*(int *)(state + 0xDC) + row][column], &radial);
            }
        }
    }
}
