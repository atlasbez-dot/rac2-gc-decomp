/* Complete manual reconstruction; NOT MATCHING and never linked.
   Tested profile: -O2 -G16 -Wa,-G16 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
   Actual final-source coverage: us: 0/6 placements, 1468 compiled bytes; us2: 0/6 placements, 1468 compiled bytes; pal: 0/6 placements, 1468 compiled bytes.
   1468/1504 bytes, correct 0x90 frame. Complete area guards, all three containment calls, 3-vector initialization, 16-byte previous position, ordered float tests, UV wrapping, sinusoidal height and genuine callback registration are retained. Unknown speed-table extents remain incomplete; GP formation, repeated-baseline stores, allocation and branch scheduling differ.
   Reopen only with: Establish complete speed-table extents and original aggregate/alias model; a G16 profile is valid only for the measured full 16-byte position, never a shortened matrix/table.
*/

#include "include_asm.h"
typedef int AreaQuadword __attribute__((mode(TI)));
typedef union { AreaQuadword bits; float f[4]; } AreaVector;
typedef void (*DrawCallback_r002E6CF0)(void *);
typedef void (*DrawCallback_r002E6DB8)(void *);
extern void func_L00_002E6CF0(DrawCallback_r002E6CF0, void *);
extern void func_L00_002E6DB8(DrawCallback_r002E6DB8, void *);
extern void func_L06_00402570(void *);
extern int func_002ACBC8(void *, int);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282D30(void *, void *, float);
extern int func_00283CF0(float);
extern float func_00283CE0(int);
extern float func_00283198(float);
extern int D_L06_001C9DC0;
extern int D_001A79F0;
extern char D_00189E20[];
extern int D_L06_001A9010;
extern int D_L06_001A8A48;
extern float D_L06_001B3284, D_L06_001B3280;
extern AreaVector D_L06_001B9A70[];
extern AreaVector D_L06_001B3290[];
extern float D_L06_001B3270[][2];
extern AreaVector D_L06_001B3260 __attribute__((sda));
extern char D_L06_001B9840[];
extern float D_L06_001B0060[];
extern float D_L06_001B0070[][2];
extern float D_001A7928;
extern int D_L06_001B2348;

void func_L06_00403130(char *owner)
{
    AreaVector movement, scaled;
    char *state = *(char **)(owner + 0x68);
    float range, fraction;
    int i;
    if (D_L06_001C9DC0 != *(int *)(state + 0x38))
        return;
    if (D_001A79F0 == 13 && *(float *)(D_00189E20 + 0x88) < 88.0f &&
        *(int *)(D_00189E20 + 0x2294) != 116)
        return;
    if (D_001A79F0 == 11 && D_L06_001A9010 != 0)
        return;
    D_L06_001B3284 = *(float *)(state + 0x14);
    if (owner[0x20] == 0) {
        owner[0x20] = 1;
        owner[0x30] = 0xFF;
        D_L06_001B3290[0].bits = D_L06_001B9A70[0].bits;
        D_L06_001B3290[1].bits = D_L06_001B9A70[1].bits;
        D_L06_001B3290[2].bits = D_L06_001B9A70[2].bits;
        for (i = 1; i >= 0; i--) {
            D_L06_001B3270[1 - i][0] = 0.0f;
            D_L06_001B3270[1 - i][1] = 0.0f;
        }
        D_L06_001B3260.bits = *(AreaQuadword *)D_L06_001B9840;
        D_L06_001B3284 = *(float *)(state + 0x14);
        return;
    }
    if (func_002ACBC8(D_00189E20 + 0x80, *(int *)(state + 0x30))) {
        *(short *)(D_00189E20 + 0x1FE) = 0;
        return;
    }
    if (func_002ACBC8(D_00189E20 + 0x80, *(int *)(state + 0x34)) &&
        D_001A79F0 != 13 && *(int *)(state + 0x38) == 0) {
        float angle = *(float *)(D_L06_001B9840 + 0x18);
        if (angle > 0.031f || angle < -1.62f ||
            (unsigned int)(*(int *)(D_00189E20 + 0x229C) - 17) < 2) {
            *(short *)(D_00189E20 + 0x1FE) = 0;
            return;
        }
    }
    if (func_002ACBC8(D_00189E20 + 0x80, *(int *)(state + 0x34))) {
        *(short *)(D_00189E20 + 0x1FE) = 0;
        return;
    }
    range = *(float *)(state + 0x18);
    if (*(int *)(D_00189E20 + 0x2294) == 28 || D_L06_001A8A48 != 0) {
        if (range > 32.0f)
            range = 32.0f;
    }
    *(short *)(D_00189E20 + 0x1FE) = 2;
    func_00282CF0(&movement, D_L06_001B9840, &D_L06_001B3260);
    D_L06_001B3260.bits = *(AreaQuadword *)D_L06_001B9840;
    if (!(*(float *)(D_L06_001B9840 + 8) > *(float *)(state + 0x20)))
        return;
    for (i = 0; i < 2; i++) {
        func_00282D30(&scaled, &movement, (D_L06_001B0060[i] + D_L06_001B0060[i]) / (range * 5.0f));
        if (scaled.f[0] > 1.0f || scaled.f[0] < 1.0f)
            scaled.f[0] -= func_00283CE0(func_00283CF0(scaled.f[0]));
        if (scaled.f[1] > 1.0f || scaled.f[1] < 1.0f)
            scaled.f[1] -= func_00283CE0(func_00283CF0(scaled.f[1]));
        D_L06_001B3270[i][0] += scaled.f[0];
        D_L06_001B3270[i][1] += scaled.f[1];
        if (D_L06_001B3270[i][0] > 1.0f)
            D_L06_001B3270[i][0] -= 1.0f;
        if (D_L06_001B3270[i][0] < -1.0f)
            D_L06_001B3270[i][0] += 1.0f;
        if (D_L06_001B3270[i][1] > 1.0f)
            D_L06_001B3270[i][1] -= 1.0f;
        if (D_L06_001B3270[i][1] < -1.0f)
            D_L06_001B3270[i][1] += 1.0f;
    }
    fraction = func_00283CE0(D_L06_001B2348 % 360) * 0.017444444820284843f - 3.14f;
    D_L06_001B3280 = D_L06_001B3284 + func_00283198(fraction) * *(float *)(state + 0x3C);
    for (i = 0; i < 2; i++) {
        D_L06_001B3270[i][0] += D_L06_001B0070[i][0] * D_001A7928;
        if (D_L06_001B3270[i][0] > 1.0f)
            D_L06_001B3270[i][0] -= 1.0f;
        if (D_L06_001B3270[i][0] < -1.0f)
            D_L06_001B3270[i][0] += 1.0f;
        D_L06_001B3270[i][1] += D_L06_001B0070[i][1] * D_001A7928;
        if (D_L06_001B3270[i][1] > 1.0f)
            D_L06_001B3270[i][1] -= 1.0f;
        if (D_L06_001B3270[i][1] < -1.0f)
            D_L06_001B3270[i][1] += 1.0f;
    }
    if (*(int *)state < 0)
        func_L00_002E6DB8(func_L06_00402570, owner);
    else
        func_L00_002E6CF0(func_L06_00402570, owner);
}
