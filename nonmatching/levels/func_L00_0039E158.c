/* Nonmatching: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier. us: func_L00_0039E158: 0 of 2 places match (src/levels/shared/L00_0039E158.c); us2: func_L00_0039E158: 0 of 2 places match (src/levels/shared/L00_0039E158.c); pal: absent. Three source trials948/940 bytes, original0xB0 frame; separate advancing source/length pointers956 bytes. Retained indexed form with current curve count reloaded after opaque distance helper. Closest-point API has6GPR and3float inputs and int success return; advance API5GPR plusfloat step, int wrap result. State distance limit is binary32 (retail lwc1 without conversion); resident level count is int converted by cvt.s.w. Remaining pointer/register and loop scheduling; reopen with path-record source layout. */
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

/* Historical screening only; superseded by the measured reconstruction above. */
/* func_L00_0039E158 - 940 bytes, 2 place(s), level 00_aranos_tutorial,
   retail at 0x0039e158. Screened with tools/w10_screen.py: 14 call(s)
   [func_00282E48@0039E214, func_00282E48@0039E24C,
   func_L00_00341FA8@0039E2FC, func_00282E48@0039E308,
   func_L00_00341820@0039E3B8, func_00282CF0@0039E3E8,
   func_00282CF0@0039E400, func_00282E20@0039E408, func_00283248@0039E414,
   func_00283248@0039E424, func_002AA2E8@0039E444, func_00282DF0@0039E44C,
   func_00282F20@0039E478, func_00282D30@0039E4B8]; data addresses
   materialised [0x190000, 0x200000, 0x190000, 0x461c0000, 0x44790000,
   0x190000, 0x3ca30000, 0x406c0000, 0x3f330000, 0x3b6c0000, 0x3a830000,
   0x3f7d0000]; float constants [0x200000, 0x40a00000]; $gp-relative small
   data: no   saves: -; callee-saved registers saved [-]; words plain C
   cannot emit [LQ/SQ 7A420000@0x01cc, LQ/SQ 7FA20000@0x01d0, COP1
   46800860@0x0224, LQ/SQ 7A820000@0x0330, LQ/SQ 7C820000@0x0334, LQ/SQ
   7A020000@0x036c, LQ/SQ 7C620000@0x0370]. Head: addiu $sp, $sp, -0xB0 ; sd
   $s7, 0x88($sp) ; sd $s0, 0x50($sp) ; daddu $s7, $a0, $zero ; sd $s1,
   0x58($sp) ; sd $s2, 0x60($sp). Not matched in this wave: the 128-bit copy
   needs an `lq`/`sq` pair; plain C reaches it only through a `mode(TI)`
   local, and this cc1 folds the destination offset into the `sq` where
   retail materialises the pointer first. What would unblock it: the exact
   source expression tree, so this cc1 picks the same registers in the same
   order. */
