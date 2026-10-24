/* Complete manual reconstruction; NOT MATCHING and never linked.
   Tested profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
   Actual final-source coverage: us: 0/27 placements, 904 compiled bytes; us2: 0/27 placements, 904 compiled bytes; pal: 0/27 placements, 904 compiled bytes.
   904/916 bytes, correct 0x1F0 frame. Full 20-point history, quaternion update, length clamps, both effect allocations and the draw call with 11 GPR/stack slots plus 3 floats are retained. Entry copy scheduling, history allocation and division/branch scheduling differ.
   Reopen only with: Independent source object/alias lifetime or scheduling evidence; retain one saved endpoint pointer for both effect allocations and all stack-tail draw slots.
*/

#include "include_asm.h"
typedef int UiQuadword __attribute__((mode(TI)));
typedef union { UiQuadword bits; float f[4]; } UiHistoryPoint;
extern int D_L00_001B2940[];
extern UiHistoryPoint D_L00_0023FB80[][20];
extern UiHistoryPoint D_L00_001B2900[];
extern float D_L00_001AFF4C __attribute__((sda));
extern int D_L00_001AFF50 __attribute__((sda));
extern int D_L00_001AFF54 __attribute__((sda));
extern int D_L00_001AFF58 __attribute__((sda));
extern float D_L00_001AFF5C __attribute__((sda));
extern float D_L00_001AFF60 __attribute__((sda));
extern char D_L00_001FE940[];
extern void func_00282CC0(void *, void *, void *);
extern void func_002AB668(void *, int, float);
extern void func_002ACDE8(void *, void *, void *);
extern void func_002ACB48(float *, float);
extern float func_00282DF0(void *);
extern void func_00282D30(void *, void *, float);
extern char *func_002C36D0(void *, int, int, int);
extern void func_L00_003C5310(void *, int, int, int, int, int, int, int,
                              int, int, int, float, float, float);

void func_L00_003C4F78(char *owner)
{
    UiHistoryPoint vertices[20], origin, change;
    char *state = *(char **)(owner + 0x68);
    int i;
    origin.bits = *(UiQuadword *)(state + 0x30);
    for (i = 0; i < 4; i++) {
        int last, j;
        UiHistoryPoint *head, *tip;
        float length, limit;
        char *effect;
        D_L00_001B2940[i]++;
        if (D_L00_001B2940[i] >= 20)
            D_L00_001B2940[i] = 20;
        last = D_L00_001B2940[i] - 1;
        for (j = last; j > 0; j--) {
            int index = last - j;
            D_L00_0023FB80[i][j].bits = D_L00_0023FB80[i][j - 1].bits;
            func_00282CC0(&vertices[index], &origin, &D_L00_0023FB80[i][j]);
            vertices[index].f[3] = 0.05f;
        }
        head = &D_L00_0023FB80[i][0];
        func_002AB668(&change, (int)&D_L00_001B2900[i], 0.10471976548433304f);
        func_002ACDE8(head, head, &change);
        func_002ACB48(head->f, 0.025f);
        length = func_00282DF0(head);
        limit = D_L00_001AFF4C * 1.1f;
        if (length > limit)
            func_00282D30(head, head, limit / length);
        else {
            limit = D_L00_001AFF4C * 0.9f;
            if (length < limit)
                func_00282D30(head, head, limit / length);
        }
        func_00282CC0(&vertices[last], &origin, head);
        vertices[last].f[3] = 0.05f;
        tip = &vertices[D_L00_001B2940[i] - 1];
        effect = func_002C36D0(tip, 2, 0, 1);
        if (effect != 0) {
            *(int *)(effect + 4) = D_L00_001AFF50 | *(int *)(state + 8);
            *(float *)(effect + 12) = D_L00_001AFF5C * 210000.0f;
            effect[2] = (*(char **)(D_L00_001FE940 + 0xF8))[1];
        }
        effect = func_002C36D0(tip, 2, 0, 1);
        if (effect != 0) {
            *(int *)(effect + 4) = 0x407F7F7F;
            *(float *)(effect + 12) = D_L00_001AFF5C * 31500.001953125f;
        }
        func_L00_003C5310(vertices, 20, 14, 14,
                          D_L00_001AFF54, D_L00_001AFF54 & 0xFFFFFF,
                          D_L00_001AFF58 | *(int *)(state + 8), D_L00_001AFF58,
                          0, D_L00_001B2940[i] - 1, D_L00_001B2940[i],
                          0.02f, 0.07f, D_L00_001AFF60);
    }
}
