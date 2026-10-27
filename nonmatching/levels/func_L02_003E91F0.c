/*
 * Updated manual-C near miss, 2026-10-25.
 * Measured unit: src/levels/02_maktar_nebula/L02_003E91F0-g8.c
 * Profile: -O2 -G8 -ffunction-sections
 * Actual release coverage: US 0/1 (exit1); US2 0/1 (exit1); PAL absent (exit1).
 * Current residual: 1728/1720 bytes. Canonical AB1F0 integer return is explicitly converted
 * to the actual pointer view, and the old four-byte table declaration is incomplete. Full
 * vector copies and both 20-point strands remain. FP/copy allocation and scheduling differ.
 * Reopen only for: A measured lifetime/container hypothesis after the real table extent is
 * qualified; preserve the corrected call input and return width.
 * M34 2026-10-26: now 1724/1720. `length = D * 0.05f` in both arms (retail keeps 0.05 in $f20
 * and multiplies early), the hero vectors through the D_00189E20 view, and the strand span its
 * own local (retail tests it in $f0). Left: one more saved float here ($f25), the state pointer
 * in $s6 (retail $s4) and one more stack slot; the rest follows from that allocation.
 * Older notes below are historical. Marker and trial-only profiles were restored.
 */

/* Nonmatching: USA v1.01: 0/1 carrying places; USA v2.00: 0/1 carrying places; PAL: absent. Final C 1736/1720 retail bytes. Game -O2 -G8 -frac2-qcopy -frac2-qcopy-barrier. Rope relaxation, two-strand animation and spark emission reconstructed. Three trials: expression staging identical, then corrected live object argument to func_002AB1F0. Original 0x110 frame; remaining register roles/copy/float scheduling. Reopen with lifetime/container hypothesis; no linked builds.  */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
extern float D_L02_001B0BA8 __attribute__((sda));
extern float D_L02_001B0C1C __attribute__((sda)), D_L02_001B0C20 __attribute__((sda)), D_L02_001B0C24 __attribute__((sda));
extern float D_L02_001B0C28 __attribute__((sda)), D_L02_001B0C2C __attribute__((sda));
extern float D_L02_001B0C30 __attribute__((sda)), D_L02_001B0C34 __attribute__((sda));
extern float D_L02_001B0C38 __attribute__((sda)), D_L02_001B0C3C __attribute__((sda)), D_L02_001B0C40 __attribute__((sda));
extern float D_L02_001B0C44 __attribute__((sda)), D_L02_001B0C48 __attribute__((sda)), D_L02_001B0C4C __attribute__((sda));
extern float D_L02_001B0C60 __attribute__((sda)), D_L02_001B0C64 __attribute__((sda));
extern float D_L02_001B0CAC __attribute__((sda));
extern int D_L02_001B0C7C __attribute__((sda));
extern float D_L02_00249090[2][20][4];
extern float D_L02_00249310[20], D_L02_00249360[20][4], D_L02_002494A0[20];
typedef union { char b[0x2600]; float f[0x980]; Quad q[0x260]; } Hero;
extern char D_00189E20[];
extern char D_L02_001A8F20[] __attribute__((sda));
extern float func_00283B98(float, float), func_00283BE0(float, float);
extern int func_002AB1F0(void *);
extern float func_00282E48(void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282DD8(void *, void *, void *);
extern void func_002ACEC0(void *, void *, void *, float);
extern void func_00282D30(void *, void *, float);
extern float func_00283CE0(int), func_002ABB18(float), func_00283198(float), func_00283180(float), func_002A78D8(float, float);
extern void func_00282D08(void *, void *, void *, float);
extern float func_00282DF0(void *);
extern void func_00282CC0(void *, void *, void *);
extern float func_00283248(float, float), func_002A7878(float, float);
extern int func_002A7820(int, int), func_002A77E0(int);
extern void func_002C2210(void *, int, int, int, int, void *, int, float, float, float);
/* Relaxes and animates a pair of twenty-point tether strands, then emits sparks. */
void func_L02_003E91F0(char *actor) {
    char *state = *(char **)(actor + 0x68);
    float endpoint[4], direction[4], delta[4], blended[4], tangent[4], sideways[4], toward[4];
    float length = D_L02_001B0BA8 * 0.05f;
    float phase, height, span, distance, weight, oscillation, lateral, heading, width, radius;
    int i, spin;
    D_L02_001B0C28 = func_00283B98(D_L02_001B0C28, D_L02_001B0C2C);
    D_L02_001B0C30 = func_00283BE0(D_L02_001B0C30, D_L02_001B0C34);
    D_L02_001B0C44 = func_00283B98(D_L02_001B0C44, D_L02_001B0C48);
    if (*(char **)(state + 0x4C)) {
        char *settings = (char *)func_002AB1F0(*(char **)(state + 0x4C));
        qcopy(endpoint, *(char **)(state + 0x4C) + 0x10);
        endpoint[2] += *(float *)(settings + 0x10);
        length = func_00282E48(state + 0x20, endpoint) * 0.05f;
    }
    *(int *)(state + 0x50) = 20;
    func_00282CF0(direction, state + 0x30, state + 0x20);
    func_00282F20(direction, direction, 1.0f);
    if (*(char **)(state + 0x4C)) {
        func_00282DD8(delta, direction, &((Hero *)D_00189E20)->q[0x2C0 / 16]);
        func_002ACEC0(direction, direction, delta, 0.17453295f);
    }
    func_00282D30(tangent, direction, length);
    qcopy(D_L02_00249090[0][0], state + 0x20);
    qcopy(D_L02_00249090[1][0], state + 0x20);
    for (i = 1; i < 20; i++) {
        float *point = D_L02_00249090[0][i];
        float *previous = D_L02_00249090[0][i - 1];
        height = func_00283CE0(i);
        height = D_L02_001B0C20 + (D_L02_001B0C24 - D_L02_001B0C20) * height * 0.05f;
        height *= func_00283198(func_002ABB18(D_L02_001B0C28 + (float)i * D_L02_001B0C1C));
        height += func_002A78D8(D_L02_001B0C60, D_L02_001B0C64);
        point[2] -= D_L02_00249310[i];
        D_L02_00249310[i] = height;
        func_00282CF0(delta, point, previous);
        func_00282D08(blended, delta, tangent, 0.85f);
        span = func_00282DF0(blended);
        if (span == 0.0f) qcopy(point, previous);
        else {
            func_00282D30(blended, blended, length / span);
            func_00282CC0(point, previous, blended);
            qcopy(tangent, blended);
        }
        point[2] += height;
        func_00282CF0(delta, point, previous);
        if (*(char **)(state + 0x4C)) {
            func_00282CF0(toward, endpoint, point);
            distance = func_00282DF0(toward);
            if (distance != 0.0f) {
                if (i == 19) { length = distance; weight = 0.5f; }
                else if (i < 16) weight = 0.1f;
                else { length = distance / func_00283CE0(19 - i); weight = 0.5f; }
                func_00282D30(toward, toward, length / distance);
                func_00282D08(tangent, tangent, toward, weight);
            }
        }
        phase = func_002ABB18(D_L02_001B0C30 + (float)i * D_L02_001B0C38);
        oscillation = func_002ABB18(D_L02_001B0C44 + (float)i * D_L02_001B0C4C);
        lateral = func_00283198(oscillation);
        lateral = D_L02_001B0C3C * lateral;
        qcopy(D_L02_00249090[1][i], point);
        lateral *= func_00283198(phase);
        D_L02_002494A0[i] = lateral;
        D_L02_00249090[1][i][2] += lateral;
        heading = func_00283B98(func_00283248(delta[0], delta[1]), 1.5707965f);
        width = func_00283180(phase);
        width = D_L02_001B0C40 * width;
        sideways[0] = func_00283180(heading) * width;
        sideways[1] = func_00283198(heading) * width;
        sideways[2] = 0;
        qcopy(D_L02_00249360[i], sideways);
        func_00282CC0(D_L02_00249090[1][i], D_L02_00249090[1][i], sideways);
    }
    qcopy(state + 0x30, D_L02_00249090[0][19]);
    oscillation = func_002A78D8(0.52359885f, 1.0471977f);
    phase = func_002A7878(-0.52359885f, 1.0471977f);
    func_00282D30(toward, direction, D_L02_001B0CAC);
    func_002ACEC0(toward, toward, &((Hero *)D_00189E20)->q[0x740 / 16], phase);
    func_002ACEC0(toward, toward, &((Hero *)D_00189E20)->q[0x750 / 16], oscillation);
    spin = func_002A7820(1, 8);
    if (func_002A77E0(2)) spin = -spin;
    radius = func_002A7878(0.2f, 0.6f);
    func_002C2210(state + 0x20, 15, D_L02_001B0C7C | 0x7F000000, 0, spin, toward, 0, radius * 0.3f, radius, 0.0f);
    func_002C2210(state + 0x20, 15, 0x307F7F7F, 0, -spin, toward, 0, radius * 0.15f, radius * 0.5f, 0.0f);
    spin = func_002A7820(1, 8);
    if (func_002A77E0(2)) spin = -spin;
    radius = func_002A7878(0.15f, 3.0f);
    func_002C2210(state + 0x30, 12, D_L02_001B0C7C | 0x7F000000, 0, spin, D_L02_001A8F20, 0, radius * 0.1f, radius, 0.0f);
}
