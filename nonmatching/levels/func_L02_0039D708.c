/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Prior worker coverage: US 0/1; US2 0/1; PAL absent from catalogue.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/* Nonmatching: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier. us: func_L02_0039D708: 0 of 1 places match (src/levels/02_maktar_nebula/L02_0039D708.c); us2: func_L02_0039D708: 0 of 1 places match (src/levels/02_maktar_nebula/L02_0039D708.c); pal: absent. Two manual forms; final5776/5868 frame0x440. Full targetselection,19segments, passthroughhitrestoration, fourarcs and threeemitters reconstructed. True20-vector geometry arrays,20-float wavearrays,4x5arcpoints,128-pointer hitlist,64-byte playerbasis and48-byte aligneddamage records. ActualsevenGPR/threeFP pointer-return C2210qualified. Removed GhidraHI artifact via ordinary32-bit pointer/index math. Remaining92bytes and FP/register/local lifetime differences; reopen on original scalar/vector/source-layout evidence. */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef union { Quad quad; float f[4]; } Vector;
typedef struct { int a, b, c, d; } __attribute__((aligned(16))) Quad16;
typedef struct {
    Vector direction;
    char *owner;
    u32 flags;
    u8 kind, response;
    u16 objectClass;
    float power;
    int mode;
} DamageRecord;
typedef struct {
    Vector start, end;
    char *target;
    float length;
    short targetAge, secondaryAge;
    int timer, light, fade;
    char *secondary;
    short ammoTimer, cutoff, targetReady, secondaryReady, targetTimer, secondaryTimer;
    int sound;
} BeamState;
typedef struct {
    int unknown00[6]; char *hit; int mesh;
    Vector position, unknown30, normal, edgeStart, edgeEnd, tail;
} CollisionResult;
extern char D_00189E20[] NOT_SDA;
extern Vector D_0018A0E0, D_0018A550[4], D_L02_001BA500, D_L02_001A8F20;
extern float D_L02_001BA518;
extern int D_L02_001A8FF0;
extern u8 D_00139568[];
extern char D_L02_00264A70[][0xE0];
extern char *D_L02_001FC420[];
extern CollisionResult D_L02_001C0940;
extern Vector D_L02_0023B090[20], D_L02_0023B1D0[20], D_L02_0023B360[20], D_L02_0023B4F0[4][5];
extern float D_L02_0023B310[20], D_L02_0023B4A0[20];
extern int D_L02_001B3E40;
extern short D_L02_001B3E48[4], D_L02_001B3E50[4], D_L02_001B3E58[4], D_L02_001B3E60[4];
extern float D_L02_001AF204 __attribute__((sda)), D_L02_001AF208 __attribute__((sda)), D_L02_001AF20C __attribute__((sda));
extern float D_L02_001AF210 __attribute__((sda)), D_L02_001AF214 __attribute__((sda)), D_L02_001AF218 __attribute__((sda));
extern float D_L02_001AF21C __attribute__((sda)), D_L02_001AF220 __attribute__((sda)), D_L02_001AF224 __attribute__((sda));
extern float D_L02_001AF228 __attribute__((sda)), D_L02_001AF22C __attribute__((sda)), D_L02_001AF230 __attribute__((sda));
extern float D_L02_001AF234 __attribute__((sda)), D_L02_001AF238 __attribute__((sda)), D_L02_001AF23C __attribute__((sda)), D_L02_001AF240 __attribute__((sda));
extern float D_L02_001AF254 __attribute__((sda)), D_L02_001AF258 __attribute__((sda)), D_L02_001AF298 __attribute__((sda)), D_L02_001AF29C __attribute__((sda));
extern u32 D_L02_001AF268 __attribute__((sda));
extern float func_00283B98(float, float), func_00283BE0(float, float), func_00283C80(float, float), func_00283248(float, float), func_002831B0(float), func_00283180(float), func_00283198(float), func_002ABB18(float);
extern float func_00282E20(void *), func_00282DF0(void *), func_00282E48(void *, void *), func_00282DB0(void *, void *), func_00283CE0(int), func_002A78D8(float, float), func_002A7878(float, float);
extern int func_002AB1F0(u8 *), func_00282948(int *), func_00282978(short *), func_00283CF0(float), func_002A77E0(int), func_002A7820(int, int), func_002761F8(void *, void *, int, char *, void *), func_00277F48(void *, int, char *, void *, float);
extern void func_00282CF0(void *, void *, void *), func_00282CC0(void *, void *, void *), func_00282D30(void *, void *, float), func_00282F20(void *, void *, float), func_00282DD8(void *, void *, void *), func_002ACEC0(void *, void *, void *, float), func_00282D08(void *, void *, void *, float);
extern void func_00282C88(Quad *), func_00300190(void *, void *), func_002A8C00(char *, int, int, float, Quad16 *), func_002A8E20(char *, DamageRecord *);
extern void *func_002C2210(void *, int, u32, int, int, void *, int, float, float, float);
/* Selects chained beam targets, integrates the two ribbons, applies hits and animates four arcs. */
void func_L02_0039D708(char *actor) {
    BeamState *beam = *(BeamState **)(actor + 0x68);
    Vector firstPoint, secondPoint, delta, projection, flattened, direction, tangent, step, smooth, offset, screen;
    Vector arcDelta[4];
    DamageRecord damage, targetDamage;
    char *passed[128], **candidate, *object, *best = 0, *second = 0, *data;
    float bestScore = 0, secondScore = 0, range = D_L02_001AF204, firstLength = 0;
    float distance, cameraAngle, playerAngle, score, length, stepLength, blend, wave, amplitude, phase, phase2, side, radius, angle, sign;
    int upgraded = D_L02_00264A70[D_00139568[0x12]][4] != 0;
    int i, j, hitCount = 0, blocked = 0, spin, difference;
    D_L02_001AF21C = func_00283B98(D_L02_001AF21C, D_L02_001AF220);
    D_L02_001AF224 = func_00283BE0(D_L02_001AF224, D_L02_001AF228);
    D_L02_001AF238 = func_00283B98(D_L02_001AF238, D_L02_001AF23C);
    if (beam->target && (!upgraded || beam->secondary)) goto targets_selected;
    if (beam->secondary) {
        beam->target = beam->secondary; beam->targetReady = beam->secondaryReady; beam->secondary = 0; beam->secondaryReady = 0;
        goto targets_selected;
    }
    for (candidate = D_L02_001FC420; (object = *candidate) != 0; candidate++) {
        if (object == beam->target || object == beam->secondary || !*(char **)(object + 0x24) || *(short *)(*(char **)(object + 0x24) + 0x46) != 5 ||
            (u8)object[0x20] == 0xFE || (u8)object[0x20] == 0xFD || !func_002AB1F0((u8 *)object)) continue;
        func_00282CF0(&delta, object + 0x10, &beam->start);
        if (!D_L02_001A8FF0) distance = func_00282E20(&delta);
        else {
            func_00282D30(&projection, (*(char **)(D_00189E20 + 0x2290)) + 0xE0, func_00282DB0(&delta, (*(char **)(D_00189E20 + 0x2290)) + 0xE0));
            func_00282CF0(&flattened, &delta, &projection); distance = func_00282DF0(&flattened);
        }
        if (!(distance <= D_L02_001AF204)) continue;
        angle = func_00283248(*(float *)(object + 0x10) - D_L02_001BA500.f[0], *(float *)(object + 0x14) - D_L02_001BA500.f[1]);
        cameraAngle = func_00283C80(D_L02_001BA518, angle);
        if (!(cameraAngle <= D_L02_001AF20C)) continue;
        playerAngle = 0;
        if (!D_L02_001A8FF0) {
            angle = func_00283248(*(float *)(object + 0x10) - *(float *)(D_00189E20 + 0x80), *(float *)(object + 0x14) - *(float *)(D_00189E20 + 0x84));
            playerAngle = func_00283C80(angle, *(float *)(D_00189E20 + 0x98));
        } else {
            func_00282CF0(&projection, object + 0x10, D_00189E20 + 0x80);
            func_00282D30(&flattened, (*(char **)(D_00189E20 + 0x2290)) + 0xE0, func_00282DB0(&projection, (*(char **)(D_00189E20 + 0x2290)) + 0xE0));
            func_00282CF0(&projection, &projection, &flattened);
            side = func_00282DB0(&projection, (*(char **)(D_00189E20 + 0x2290)) + 0xC0); length = func_00282DF0(&projection);
            if (length == 0) continue;
            playerAngle = 1.5707964f - func_002831B0(side / length);
        }
        if (!(playerAngle <= D_L02_001AF208)) continue;
        score = ((D_L02_001AF20C - cameraAngle) / D_L02_001AF20C) * D_L02_001AF29C + (D_L02_001AF204 - distance) / D_L02_001AF204;
        if (bestScore < score) { second = best; secondScore = bestScore; bestScore = score; best = object; }
        else if (!(score <= secondScore)) { second = object; secondScore = score; }
    }
targets_selected:
    if (best) {
        if (!beam->target) { beam->targetReady = 0; beam->target = best; if (func_00282948(&D_L02_001B3E40)) D_L02_001B3E40 = 10; }
        else second = best;
    }
    if (second && upgraded) {
        distance = func_00282E48(&beam->start, best + 0x10);
        if (distance < D_L02_001AF204 && distance + func_00282E48(best + 0x10, second + 0x10) < D_L02_001AF204) {
            beam->secondaryReady = 0; beam->secondary = second;
        }
    }
    if (beam->target) {
        data = (char *)func_002AB1F0((u8 *)beam->target);
        firstPoint.quad = *(Quad *)(beam->target + 0x10);
        func_00282D30(&projection, beam->target + 0xE0, *(float *)(data + 0x10)); func_00282CC0(&firstPoint, &firstPoint, &projection);
        firstLength = func_00282E48(&beam->start, &firstPoint); range = firstLength;
    }
    if (beam->secondary) {
        data = (char *)func_002AB1F0((u8 *)beam->secondary);
        secondPoint.quad = *(Quad *)(beam->secondary + 0x10);
        func_00282D30(&projection, beam->secondary + 0xE0, *(float *)(data + 0x10)); func_00282CC0(&secondPoint, &secondPoint, &projection);
        range = func_00282E48(&firstPoint, &secondPoint) + firstLength;
    }
    stepLength = range * 0.05f;
    D_L02_001AF268 = upgraded ? 0x207F20 : 0x7F2020;
    func_00282C88(&flattened.quad);
    func_002A8C00((char *)&damage, (int)actor, 0x210000, *(float *)(D_L02_00264A70[D_00139568[0x12]] + 0x70), (Quad16 *)&flattened);
    damage.objectClass = *(u16 *)(actor + 0xAA); damage.response = 1; damage.kind = 5; beam->cutoff = 20;
    func_00277F48(&beam->start, 16, (*(char **)(D_00189E20 + 0x2290)), &damage, 0.3f);
    func_00282CF0(&direction, &beam->end, &beam->start); func_00282F20(&direction, &direction, 1);
    if (beam->target || beam->secondary) { func_00282DD8(&tangent, &direction, &D_0018A0E0); func_002ACEC0(&direction, &direction, &tangent, 0.17453294f); }
    func_00282D30(&step, &direction, stepLength);
    D_L02_0023B090[0].quad = beam->start.quad; D_L02_0023B1D0[0].quad = beam->start.quad;
    for (i = 1; i < 20; i++) {
        amplitude = D_L02_001AF214 + (D_L02_001AF218 - D_L02_001AF214) * func_00283CE0(i) * 0.05f;
        phase = func_002ABB18(D_L02_001AF21C + (float)i * D_L02_001AF210);
        wave = amplitude * func_00283198(phase) + func_002A78D8(D_L02_001AF254, D_L02_001AF258);
        amplitude = D_L02_0023B310[i]; D_L02_0023B310[i] = wave; D_L02_0023B090[i].f[2] -= amplitude;
        func_00300190(&D_L02_0023B090[i], &D_L02_0023B090[i]);
        func_00282CF0(&delta, &D_L02_0023B090[i], &D_L02_0023B090[i - 1]);
        func_00282D08(&smooth, &delta, &step, 0.85f); length = func_00282DF0(&smooth);
        if (length == 0) D_L02_0023B090[i].quad = D_L02_0023B090[i - 1].quad;
        else {
            func_00282D30(&smooth, &smooth, stepLength / length); func_00282CC0(&D_L02_0023B090[i], &D_L02_0023B090[i - 1], &smooth); step.quad = smooth.quad;
        }
        D_L02_0023B090[i].f[2] += wave;
        func_00282CF0(&delta, &D_L02_0023B090[i], &D_L02_0023B090[i - 1]);
        if (beam->target) {
            if (!upgraded || !beam->secondary) {
                func_00282CF0(&projection, &firstPoint, &D_L02_0023B090[i]); length = func_00282DF0(&projection);
                if (length != 0) {
                    if (i == 19) { stepLength = length; blend = 0.5f; }
                    else if (i < 16) blend = 0.1f;
                    else { stepLength = length / func_00283CE0(19 - i); blend = 0.5f; }
                    func_00282D30(&projection, &projection, stepLength / length); func_00282D08(&step, &step, &projection, blend);
                }
            } else {
                func_00282CF0(&projection, i < 10 ? (void *)&firstPoint : (void *)&secondPoint, &D_L02_0023B090[i]); length = func_00282DF0(&projection);
                if (length != 0) {
                    if (i == 9 || i == 19) { stepLength = length; blend = 0.7f; }
                    else if ((u32)(i - 5) < 5 || i > 14) { stepLength = length / func_00283CE0(i < 10 ? 9 - i : 19 - i); blend = 0.7f; }
                    else blend = 0.2f;
                    func_00282D30(&projection, &projection, stepLength / length); func_00282D08(&step, &step, &projection, blend);
                }
            }
        }
        if (i < 10) {
            phase = func_002ABB18(D_L02_001AF224 + (float)i * D_L02_001AF22C); phase2 = func_002ABB18(D_L02_001AF238 + (float)i * D_L02_001AF240);
            side = D_L02_001AF230 * func_00283198(phase2) * func_00283198(phase) + func_002A78D8(0, 0.1f);
            D_L02_0023B1D0[i].quad = D_L02_0023B090[i].quad; D_L02_0023B4A0[i] = side; D_L02_0023B1D0[i].f[2] += side;
            angle = func_00283B98(func_00283248(delta.f[0], delta.f[1]), 1.5707964897155762f);
            amplitude = D_L02_001AF234 * func_00283180(phase);
            offset.f[0] = func_00283180(angle) * amplitude; offset.f[1] = func_00283198(angle) * amplitude; offset.f[2] = 0;
            D_L02_0023B360[i].quad = offset.quad; func_00282CC0(&D_L02_0023B1D0[i], &D_L02_0023B1D0[i], &offset);
        } else {
            D_L02_0023B1D0[i].quad = D_L02_0023B090[i].quad; D_L02_0023B1D0[i].f[2] += D_L02_0023B4A0[21 - i];
            func_00282CC0(&D_L02_0023B1D0[i], &D_L02_0023B1D0[i], &D_L02_0023B360[21 - i]); offset.quad = D_L02_0023B360[i].quad;
        }
        if (i > 1 && (i == 19 || !(i & 1))) {
            func_00282CF0(&screen, &D_L02_0023B090[i], &D_L02_001BA500);
            if (!D_L02_001A8FF0) screen.f[2] = 0;
            else { func_00282D30(&projection, (*(char **)(D_00189E20 + 0x2290)) + 0xE0, func_00282DB0(&screen, (*(char **)(D_00189E20 + 0x2290)) + 0xE0)); func_00282CF0(&screen, &screen, &projection); }
            length = func_00282DF0(&screen); if (length == 0) screen.f[2] = 1; else func_00282D30(&screen, &screen, 1.0f / length);
            screen.f[3] = 5627.925f; damage.direction.quad = screen.quad;
            blocked = func_002761F8(&D_L02_0023B090[i - 2], &D_L02_0023B090[i], 16, actor, 0); object = D_L02_001C0940.hit;
            if (blocked) {
                if (object) {
                    if (!func_002AB1F0((u8 *)object) || !*(char **)(object + 0x24) || *(short *)(*(char **)(object + 0x24) + 0x46) != 5) func_002A8E20(object, &damage);
                    else { blocked = 0; passed[hitCount++] = object; *(int *)(object + 0x98) = 0; }
                }
                if (blocked) {
                    D_L02_0023B090[i].quad = D_L02_001C0940.position.quad; beam->cutoff = i; beam->end.quad = D_L02_001C0940.position.quad;
                    if (!D_L02_001C0940.hit) { beam->target = 0; beam->targetReady = 0; }
                    break;
                }
            }
        }
    }
    for (j = 0; j < hitCount; j++) *(int *)(passed[j] + 0x98) = *(int *)(*(char **)(passed[j] + 0x24) + 0x10);
    if (!blocked) beam->end.quad = D_L02_0023B090[19].quad;
    if (beam->target && !(*(u64 *)&beam->targetReady & 0xFFFF0000FFFFULL)) {
        func_00282CF0(&screen, beam->target + 0x10, &D_L02_001BA500);
        if (!D_L02_001A8FF0) screen.f[2] = 0;
        else { func_00282D30(&projection, (*(char **)(D_00189E20 + 0x2290)) + 0xE0, func_00282DB0(&screen, (*(char **)(D_00189E20 + 0x2290)) + 0xE0)); func_00282CF0(&screen, &screen, &projection); }
        func_00282F20(&screen, &screen, 1); screen.f[3] = 5627.925f;
        func_002A8C00((char *)&targetDamage, (int)actor, 0x210000, *(float *)(D_L02_00264A70[D_00139568[0x12]] + 0x70), (Quad16 *)&screen);
        targetDamage.objectClass = *(u16 *)(actor + 0xAA); targetDamage.response = 3; targetDamage.kind = 5; func_002A8E20(beam->target, &targetDamage);
        data = (char *)func_002AB1F0((u8 *)beam->target); beam->targetTimer = data && *(short *)(data + 4) == 1 ? 1 : 5;
    }
    if (beam->secondary && !(*(u64 *)&beam->targetReady & 0xFFFF0000FFFF0000ULL)) {
        func_00282CF0(&screen, beam->secondary + 0x10, &D_L02_001BA500);
        if (!D_L02_001A8FF0) screen.f[2] = 0;
        else { func_00282D30(&projection, (*(char **)(D_00189E20 + 0x2290)) + 0xE0, func_00282DB0(&screen, (*(char **)(D_00189E20 + 0x2290)) + 0xE0)); func_00282CF0(&screen, &screen, &projection); }
        func_00282F20(&screen, &screen, 1); screen.f[3] = 5627.925f;
        func_002A8C00((char *)&targetDamage, (int)actor, 0x210000, *(float *)(D_L02_00264A70[D_00139568[0x12]] + 0x70), (Quad16 *)&screen);
        targetDamage.objectClass = *(u16 *)(actor + 0xAA); targetDamage.response = 3; targetDamage.kind = 5; func_002A8E20(beam->secondary, &targetDamage);
        data = (char *)func_002AB1F0((u8 *)beam->secondary); beam->secondaryTimer = data && *(short *)(data + 4) == 1 ? 1 : 5;
    }
    for (i = 0; i < 4; i++) {
        if (!func_00282978(&D_L02_001B3E48[i])) {
            for (j = 0; j < 4; j++) {
                func_00282CF0(&arcDelta[j], &D_L02_0023B4F0[i][j + 1], &D_L02_0023B4F0[i][j]);
                arcDelta[j].f[0] += func_002A78D8(0, 0.1f); arcDelta[j].f[1] += func_002A78D8(0, 0.1f); arcDelta[j].f[2] += func_002A78D8(0, 0.1f);
            }
            D_L02_0023B4F0[i][0].quad = i < 2 ? beam->start.quad : beam->end.quad;
            for (j = 0; j < 4; j++) func_00282CC0(&D_L02_0023B4F0[i][j + 1], &D_L02_0023B4F0[i][j], &arcDelta[j]);
            difference = D_L02_001B3E48[i] - D_L02_001B3E60[i]; if (difference < 0) difference = -difference;
            D_L02_001B3E50[i] = func_00283CF0((1.0f - func_00283CE0(difference) / func_00283CE0(15)) * 32.0f);
        } else {
            D_L02_001B3E48[i] = D_L02_001B3E58[i]; D_L02_001B3E50[i] = 0;
            phase = func_002A78D8(0.52359885f, 1.0471977f); phase2 = func_002A7878(-1.0471977f, 0.17453294f);
            func_00282D30(&offset, &direction, i < 2 ? 0.4f : 0.5f); func_002ACEC0(&offset, &offset, &D_0018A550[1], phase2); func_002ACEC0(&offset, &offset, &D_0018A550[2], phase);
            D_L02_0023B4F0[i][0].quad = i < 2 ? beam->start.quad : beam->end.quad;
            func_00282CC0(&D_L02_0023B4F0[i][1], &D_L02_0023B4F0[i][0], &offset);
            sign = 1;
            for (j = 0; j < 3; j++) {
                func_00282CF0(&screen, &D_L02_0023B4F0[i][j + 1], &D_L02_001BA500);
                angle = func_002A7878(0.17453294f, 0.9599312f) * sign; sign = -sign;
                func_002ACEC0(&offset, &offset, &screen, angle); func_00282CC0(&D_L02_0023B4F0[i][j + 2], &D_L02_0023B4F0[i][j + 1], &offset);
            }
        }
    }
    phase = func_002A78D8(0.52359885f, 1.0471977f); phase2 = func_002A7878(-0.52359885f, 1.0471977f);
    func_00282D30(&offset, &direction, D_L02_001AF298); func_002ACEC0(&offset, &offset, &D_0018A550[1], phase2); func_002ACEC0(&offset, &offset, &D_0018A550[2], phase);
    spin = func_002A7820(1, 8); if (func_002A77E0(2)) spin = -spin; radius = func_002A7878(0.2f, 0.6f);
    func_002C2210(&beam->start, 15, D_L02_001AF268 | 0x7F000000, 0, spin, &offset, 1, radius * 0.3f, radius, 0);
    func_002C2210(&beam->start, 15, 0x307F7F7F, 0, -spin, &offset, 1, radius * 0.15f, radius * 0.5f, 0);
    spin = func_002A7820(1, 8); if (func_002A77E0(2)) spin = -spin; radius = func_002A7878(0.15f, 3.0f);
    func_002C2210(&beam->end, 12, D_L02_001AF268 | 0x7F000000, 0, spin, &D_L02_001A8F20, 1, radius * 0.1f, radius, 0);
}

/* Historical screening only; superseded by the measured reconstruction above. */
