/* Retained manual C reconstruction; not linked or counted.
 * Retail: 1428 bytes. Checked trial: src/levels/12_todano/L12_00420B78-g8.c
 * Profile: -O2 -G8 -ffunction-sections -fno-strength-reduce -frac2-qcopy -frac2-qcopy-barrier
 * us: 0/1 placements (exit 1), 1396 compiled bytes
 * us2: 0/1 placements (exit 1), 1396 compiled bytes
 * pal: explicit catalogue absence (exit 1); no credit
 * Residual: The 0x80-byte mixed GPR/FPR frame agrees. Save scheduling, eight coefficient live ranges and the repeated 21-vector strip loops still differ.
 * Reopen: Reopen with a concrete source layout for the coefficient live ranges or a measured loop-scheduling control; retain all eight calls and the 294-vector initialization.
 * The ASM marker and trial-only file profile were restored after checks.
 */

#include "common.h"
typedef int WaveQuad __attribute__((mode(TI)));
extern float D_L12_002A11B0[][4];
extern u8 D_00189E20[];
extern int D_L12_001B363C;
extern WaveQuad D_L12_001B3640;
extern int D_L12_001B29C8;
extern float D_L12_001B1F44, D_L12_001B1F48;
extern int func_L00_00329520(void *point, int index);
extern void func_L12_00420950(void *object);
extern void func_L00_002E6CF0(void (*callback)(void *), void *object);
extern void func_L00_002E6EF8(void (*callback)(void *), void *object);
extern float func_00283198(float angle);
extern float func_002A7878(float low, float high);
extern float func_00282E80(void *a, void *b);

#define MOVE_STRIP(N, W) do { \
    float (*vertex)[4] = D_L12_002A11B0 + (N) * 21; \
    int n; \
    for (n = 20; n >= 0; n--, vertex++) \
        (*vertex)[2] += (W); \
} while (0)

void func_L12_00420B78(u8 *object)
{
    u8 *data = *(u8 **)(object + 0x68);
    float (*vertex)[4];
    int i;
    float angle;
    float a,b,c,d,e,f,g,h;
    switch (object[0x20]) {
    case 0:
        *(float *)(data + 0xc) = 0.75f;
        *(float *)(data + 4) = 0.25f;
        *(float *)(data + 0x2c) = 1.75f;
        *(float *)(data + 8) = 0.5f;
        *(float *)(data + 0x20) = 1.0f;
        *(float *)(data + 0x24) = 1.25f;
        *(float *)(data + 0x28) = 1.5f;
        *(float *)data = 0;
        object[0x30] = 255;
        object[0x20] = 1;
        if (D_L12_002A11B0[0][0] > 1000.0f) {
            vertex = D_L12_002A11B0;
            for (i = 293; i >= 0; i--, vertex++) {
                (*vertex)[0] *= 0.01f;
                (*vertex)[1] *= 0.01f;
                (*vertex)[2] *= 0.01f;
            }
        }
        break;
    case 1:
        if (func_L00_00329520(D_00189E20 + 0x80, *(int *)(data + 0x18)))
            return;
        func_L00_002E6CF0(func_L12_00420950, object);
        D_L12_001B363C = 1;
        D_L12_001B3640 = *(WaveQuad *)(D_00189E20 + 0x80);
        *(float *)((u8 *)&D_L12_001B3640 + 12) = 48.0f;
        *(short *)(D_00189E20 + 0x1fe) = 5;
        angle = (float)(D_L12_001B29C8 % 360) * 0.017444444820284843f - 3.140000104904175f;
        *(float *)((u8 *)&D_L12_001B3640 + 8) = func_00283198(angle) * 0.25f + 59.5f;
        *(float *)(data + 0x10) += *(float *)(data + 0x14);
        if (*(float *)(data + 0x10) >= 8.0f)
            *(float *)(data + 0x10) -= 8.0f;
        a = func_00283198(*(float *)(data + 0) * 3.141590118408203f) * 0.001f;
        b = func_00283198(*(float *)(data + 4) * 3.141590118408203f) * 0.001f;
        c = func_00283198(*(float *)(data + 8) * 3.141590118408203f) * 0.001f;
        d = func_00283198(*(float *)(data + 12) * 3.141590118408203f) * 0.001f;
        e = func_00283198(*(float *)(data + 0) * 3.141590118408203f) * 0.001f;
        f = func_00283198(*(float *)(data + 4) * 3.141590118408203f) * 0.001f;
        g = func_00283198(*(float *)(data + 8) * 3.141590118408203f) * 0.001f;
        h = func_00283198(*(float *)(data + 12) * 3.141590118408203f) * 0.001f;
        MOVE_STRIP(0, a);
        MOVE_STRIP(1, b);
        MOVE_STRIP(2, c);
        MOVE_STRIP(3, d);
        MOVE_STRIP(4, e);
        MOVE_STRIP(5, f);
        MOVE_STRIP(6, g);
        MOVE_STRIP(7, h);
        *(float *)(data + 0) += 0.01f;
        *(float *)(data + 4) += 0.01f;
        *(float *)(data + 8) += 0.01f;
        *(float *)(data + 12) += 0.01f;
        *(float *)(data + 0x20) += 0.01f;
        *(float *)(data + 0x24) += 0.01f;
        *(float *)(data + 0x28) += 0.01f;
        *(float *)(data + 0x2c) += 0.01f;
        if (*(float *)(data + 0) > 2.0f) *(float *)(data + 0) = 0;
        if (*(float *)(data + 4) > 2.0f) *(float *)(data + 4) = 0;
        if (*(float *)(data + 8) > 2.0f) *(float *)(data + 8) = 0;
        if (*(float *)(data + 12) > 2.0f) *(float *)(data + 12) = 0;
        *(float *)(data + 0x14) = func_002A7878(D_L12_001B1F44, D_L12_001B1F48);
        break;
    case 2:
        if (func_00282E80(object + 0x10, D_00189E20 + 0x80) < 64.0f)
            func_L00_002E6EF8(func_L12_00420950, object);
        break;
    }
}
