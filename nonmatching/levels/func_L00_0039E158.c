/* Retained C reconstruction; not linked or counted.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * 948/940 bytes. us: 0/2 places; us2: 0/2 places; pal: absent.
 * Remaining: The indexed rail-length reconstruction remains at 948 bytes with its
 * existing TI-copy profile. Real qcopy also gives 948; a truthful 16-byte
 * XYZ/length rail-point view gives 956. The 0xB0 frame agrees, but pointer
 * allocation and loop scheduling remain different.
 * Reopen with: Independent path-count or saved-point lifetime evidence; do not repeat
 * the typed rail-point or advancing-pointer forms without changed input.
 */

#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef struct { float heading, pitch; int unused; float speed; } RailAngles;
extern char *D_L00_001FDA80[];
extern int D_0018C0BC;
extern float D_00189EA0[4], D_00189F20[4];
extern int D_00189FD8;
extern short D_0018A020;
extern RailAngles D_0018A960;
extern float func_00282E48(void *, void *);
extern int func_L00_00341FA8(void *, void *, void *, int *, float *, int, float, float, float);
extern int func_L00_00341820(void *, void *, int *, float *, int, float);
extern void func_00282CF0(void *, void *, void *);
extern float func_00282E20(void *), func_00283248(float, float), func_002AA2E8(float *, float, float), func_00282DF0(void *);
extern void func_00282F20(void *, void *, float), func_00282D30(void *, void *, float);
/* Precomputes path segment lengths and steers the hero along the nearest active path. */
void func_L00_0039E158(char *actor) {
    char *state = *(char **)(actor + 0x68);
    float previous[4], point[4], delta[4], step[4];
    int segment, bestSegment;
    float t, bestT;
    char *curve, *bestCurve;
    int i, j;
    float distance, bestDistance, advance, length;
    if (!state || *(int *)state == -1 || *(int *)(state + 0x70) == 0) return;
    if (*(int *)(state + 0x68) == 0) {
        *(int *)(state + 0x68) = 1;
        for (i = 0; i < *(int *)(state + 0x70); i++) {
            curve = D_L00_001FDA80[((int *)state)[i]];
            for (j = 0; j < *(int *)curve - 1; j++)
                *(float *)(curve + j * 16 + 0x1C) = func_00282E48(curve + j * 16 + 0x10, curve + j * 16 + 0x20);
            *(float *)(curve + j * 16 + 0x1C) = func_00282E48(curve + j * 16 + 0x10, curve + 0x10);
        }
        *(u8 *)(actor + 0x30) = 0xFF;
    }
    if (D_0018C0BC != 16) return;
    bestCurve = 0;
    bestDistance = 9999.0f;
    for (i = 0; i < *(int *)(state + 0x70); i++) {
        curve = D_L00_001FDA80[((int *)state)[i]];
        func_L00_00341FA8(curve, D_00189EA0, point, &segment, &t, 0, 999.0f, 5.0f, 0.0f);
        distance = func_00282E48(D_00189EA0, point);
        if (distance < bestDistance) {
            *(Quad *)previous = *(Quad *)point;
            bestSegment = segment;
            bestT = t;
            bestCurve = curve;
            bestDistance = distance;
        }
    }
    if (!bestCurve) return;
    advance = 3.7f - (float)D_00189FD8 * 0.02f;
    if (advance < 0.7f) advance = 0.7f;
    i = func_L00_00341820(bestCurve, point, &bestSegment, &bestT, 0, advance);
    if (*(float *)(state + 0x64) < bestDistance) return;
    if (!i) {
        func_00282CF0(step, point, previous);
        func_00282CF0(delta, point, D_00189EA0);
        D_0018A960.pitch = func_00283248(func_00282E20(step), step[2]);
        D_0018A960.heading = func_00283248(delta[0], delta[1]);
        delta[2] = 0;
        func_002AA2E8(&D_0018A960.speed, *(float *)(state + 0x60), 0.0036111111f);
        length = func_00282DF0(delta);
        if (length > 0.001f) func_00282F20(D_00189F20, delta, D_0018A960.speed);
        D_00189F20[3] = 0;
        *(Quad *)(state + 0x50) = *(Quad *)D_00189F20;
        if (D_0018A020 < 30) D_0018A020 = 30;
    } else {
        func_00282D30(state + 0x50, state + 0x50, 0.99f);
        *(Quad *)D_00189F20 = *(Quad *)(state + 0x50);
        D_00189F20[3] = 0;
    }
}
