/* Retained manual C reconstruction; not linked or counted.
 * Retail: 964 bytes. Checked trial: src/levels/shared/L00_004291A0.c
 * Profile: -O2 -G0 -ffunction-sections -fno-strength-reduce -frac2-qcopy -frac2-qcopy-barrier
 * us: 0/11 placements (exit 1), 952 compiled bytes
 * us2: 0/11 placements (exit 1), 952 compiled bytes
 * pal: explicit catalogue absence (exit 1); no credit
 * Residual: The 0x90-byte frame agrees after disabling strength reduction and qualifying TI copies, but path-index live ranges, modulo/call scheduling and four transform copies differ.
 * Reopen: Recover the original separate path-walk/weight-walk locals or a measured aggregate address-lifetime shape.
 * The ASM marker and trial-only file profile were restored after checks.
 */

#include "common.h"
typedef int InitQuad __attribute__((mode(TI)));
extern u8 *D_L00_001B1844;
extern u8 D_L00_001BD2C0[];
extern u8 *D_L00_001FDA80[];
extern u8 D_L00_001B8C80[];
extern float func_00283248(float x, float y);
extern float func_00282E48(float *a, float *b);
extern float func_00283CE0(int x);
extern void func_00282C88(InitQuad *v);
extern int func_L00_002C42E0(int event, int value);

void func_L00_004291A0(u8 *object)
{
    u8 *data = *(u8 **)(D_L00_001B1844 + *(short *)(object + 0x84) * 32 + 0x1c);
    u8 *motion = *(u8 **)(object + 0x70) + 0x40;
    u8 *pathState;
    u8 *path;
    float *weight = (float *)(data + 0x60);
    int *indices = (int *)(data + 0x80);
    int accepted = 0;
    int i;
    float distance;
    float *entry;
    InitQuad *transform;
    data[0x38] = 1;
    *(int *)(motion + 0) = 0;
    *(int *)(motion + 4) = 0;
    *(int *)(motion + 8) = 0;
    *(int *)(motion + 0xc) = 0;
    *(int *)(motion + 0x10) = 0;
    *(short *)(motion + 0x14) = 0;
    *(short *)(motion + 0x16) = *(short *)(data + 0x3a);
    pathState = *(u8 **)(object + 0x70) + 0x58;
    for (i = 7; i >= 0; i--) {
        *(int *)(data + 0x60 + (7 - i) * 4) = 0;
        indices[7 - i] = -1;
    }
    *(float *)(pathState + 0x30) = func_00283248(1.0f, *(float *)(D_L00_001BD2C0 + 0xb0)) * 2.0f;
    if (*(int *)(data + 0x50) == 0 && *(int *)(data + 0x20) >= 0) {
        path = D_L00_001FDA80[*(int *)(data + 0x20)];
        for (i = 0; i < *(int *)path; i++) {
            entry = (float *)(path + 0x10 + i * 16);
            if (entry[3] > 0.0f) {
                *weight = entry[3];
                if (entry[3] > 180.0f)
                    *weight = *(float *)(pathState + 0x30) * 57.2957763671875f;
                weight++;
                indices[accepted++] = i;
            }
            distance = func_00282E48(entry, (float *)(path + 0x10 + ((i + 1) % *(int *)path) * 16));
            entry[3] = distance;
            if (i < *(int *)path - 1)
                *(float *)(motion + 8) += distance;
        }
    }
    if (*(short *)(data + 0x3a) > 0)
        *(float *)(data + 0x3c) = (*(float *)(motion + 8) / func_00283CE0(*(short *)(data + 0x3a))) * 60.0f;
    if (*(int *)(data + 0x24) >= 0) {
        path = D_L00_001FDA80[*(int *)(data + 0x24)];
        for (i = 0; i < *(int *)path; i++) {
            entry = (float *)(path + 0x10 + i * 16);
            distance = func_00282E48(entry, (float *)(path + 0x10 + ((i + 1) % *(int *)path) * 16));
            entry[3] = distance;
            if (i < *(int *)path - 1)
                *(float *)(motion + 0xc) += distance;
        }
    }
    path = *(u8 **)(object + 0x70);
    *(float *)path = 0.03f;
    *(float *)(path + 4) = 0.2f;
    func_00282C88((InitQuad *)(path + 0x10));
    path = *(u8 **)(object + 0x70);
    *(float *)(path + 0x20) = 0.03f;
    *(float *)(path + 0x24) = 0.2f;
    func_00282C88((InitQuad *)(path + 0x30));
    transform = *(InitQuad **)(D_L00_001B8C80 + 0x194);
    *(InitQuad *)(object + 0x30) = transform[3];
    *(InitQuad *)object = transform[0];
    *(InitQuad *)(object + 0x10) = transform[1];
    *(InitQuad *)(object + 0x20) = transform[2];
    if (*(int *)(data + 0x4c) == 0)
        func_L00_002C42E0(0x6f, 1);
    *(int *)(data + 0x50) = 1;
}
