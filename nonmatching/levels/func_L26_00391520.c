/*
 * Complete manual reconstruction retained as nonmatching; no coverage credit.
 * Fresh checks on the qualified current compiler, 2026-10-25.
 * Profile: -O2 -G8 -ffunction-sections
 * Coverage: US: 0/1; US2: 0/1; PAL: absent from catalogue.
 * Compiled text: 5680 bytes; retail text: 5868 bytes.
 * Remaining difference: The complete 5868-byte target remains a 5680-byte reconstruction with
 * frame 0x460 versus 0x440. All 128 disabled pointers, 20-point chains, collision contexts and
 * four spark vectors are retained. Lexically scoped hit contexts do not fix the frame. Retail late
 * context bases 0x2D0 and 0x2C0 overlap, but this alone does not prove a source union.
 * Reopen when: Trace all actual local addresses and context lifetimes, including 40-byte helper
 * copies and the later spark-axis use, before introducing any storage overlay.
 */

#include "common.h"

typedef int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } Vector;
/* A collision record is copied through byte 39 by the engine helpers. */
typedef struct {
    Vector direction;
    char *owner;
    int flags;
    unsigned char mode, enabled;
    unsigned short id;
    float material;
    int active;
    float falloff;
} CollisionContext;
extern float D_L26_001AF044 __attribute__((sda));
extern float D_L26_001AF048 __attribute__((sda));
extern float D_L26_001AF04C __attribute__((sda));
extern float D_L26_001AF050 __attribute__((sda));
extern float D_L26_001AF054 __attribute__((sda));
extern float D_L26_001AF058 __attribute__((sda));
extern float D_L26_001AF05C __attribute__((sda));
extern float D_L26_001AF060 __attribute__((sda));
extern float D_L26_001AF064 __attribute__((sda));
extern float D_L26_001AF068 __attribute__((sda));
extern float D_L26_001AF06C __attribute__((sda));
extern float D_L26_001AF070 __attribute__((sda));
extern float D_L26_001AF074 __attribute__((sda));
extern float D_L26_001AF078 __attribute__((sda));
extern float D_L26_001AF07C __attribute__((sda));
extern float D_L26_001AF080 __attribute__((sda));
extern float D_L26_001AF094 __attribute__((sda));
extern float D_L26_001AF098 __attribute__((sda));
extern unsigned int D_L26_001AF0A8 __attribute__((sda));
extern float D_L26_001AF0D8 __attribute__((sda));
extern float D_L26_001AF0DC __attribute__((sda));
extern unsigned char D_0013957A;
extern char D_L26_002622F0[];
extern char *D_L26_001FAAA0[];
extern int D_L26_001A8FF0;
extern char *D_0018C0B0;
extern Vector D_L26_001B8B80;
extern float D_L26_001B8B98;
extern Vector D_00189EA0;
extern float D_00189EB8;
extern Vector D_0018A0E0;
extern Vector D_0018A560, D_0018A570;
extern Vector D_L26_001A8F20;
extern int D_L26_001B24C0;
extern short D_L26_001B24C8[4];
extern short D_L26_001B24D0[4];
extern short D_L26_001B24D8[4];
extern short D_L26_001B24E0[4];
extern Vector D_L26_00239710[20];
extern Vector D_L26_00239850[20];
extern float D_L26_00239990[20];
extern Vector D_L26_002399E0[20];
extern float D_L26_00239B20[20];
extern Vector D_L26_00239B70[4][5];
extern char *D_L26_001BEFD8;
extern Vector D_L26_001BEFE0;
extern float func_00283B98(float, float);
extern float func_00283BE0(float, float);
extern s32 func_002AB1F0(u8 *);
extern void func_00282CF0(void *, void *, void *);
extern float func_00282DB0(void *, void *);
extern void func_00282D30(void *, void *, float);
extern float func_00282DF0(void *);
extern float func_00282E20(void *);
extern float func_00283248(float, float);
extern float func_00283C80(float, float);
extern float func_002831B0(float);
extern int func_00282948(int *);
extern float func_00282E48(void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282C88(Quad *);
extern void func_002A8C00(char *, int, int, float, Vector *);
extern int func_00277F48(void *, int, void *, void *, float);
extern void func_00282F20(void *, void *, float);
extern void func_00282DD8(void *, void *, void *);
extern void func_002ACEC0(void *, void *, void *, float);
extern float func_00283CE0(int);
extern float func_002ABB18(float);
extern float func_00283198(float);
extern float func_002A78D8(float, float);
extern void func_00300190(void *, void *);
extern void func_00282D08(void *, void *, void *, float);
extern float func_00283180(float);
extern int func_002761F8(void *, void *, int, void *, void *);
extern void func_002A8E20(void *, void *);
extern int func_00282978(short *);
extern int func_00283CF0(float);
extern float func_002A7878(float, float);
extern int func_002A7820(int, int);
extern int func_002A77E0(int);
extern char *func_002C2210(void *, int, unsigned int, int, int, void *, int, float, float, float);

void func_L26_00391520(char *object) {
    Vector primary_point, secondary_point, scratch;
    CollisionContext context;
    Vector direction, delta, proposed, heading, lateral;
    char *disabled[128];
    Vector hit_direction, auxiliary;
    CollisionContext primary_context, secondary_context;
    Vector spark_delta[4];
    char *private = *(char **)(object + 0x68);
    char *candidate = 0;
    char *alternate = 0;
    char *target;
    char *descriptor;
    char *hit;
    char *primary;
    char *secondary;
    float range = D_L26_001AF044;
    float best_score = 0.0f;
    float second_score = 0.0f;
    float distance, angle, player_angle, projection, length, score;
    float step_length, primary_length = 0.0f;
    float amplitude, wave, jitter, frequency, angle2, factor;
    float phase, magnitude, sign;
    int dual = D_L26_002622F0[(unsigned int)D_0013957A * 0xE0 + 4] != 0;
    int i, j, index, disabled_count = 0;
    int collided = 0;
    int counter, difference;
    short kind;
    D_L26_001AF05C = func_00283B98(D_L26_001AF05C, D_L26_001AF060);
    D_L26_001AF064 = func_00283BE0(D_L26_001AF064, D_L26_001AF068);
    D_L26_001AF078 = func_00283B98(D_L26_001AF078, D_L26_001AF07C);
    if (*(char **)(private + 0x20) && (!dual || *(char **)(private + 0x38))) goto targets_ready;
    if (!*(char **)(private + 0x38)) {
        for (index = 0; (target = D_L26_001FAAA0[index]) != 0; index++) {
            if (target == *(char **)(private + 0x20) || target == *(char **)(private + 0x38) ||
                !*(char **)(target + 0x24) || *(short *)(*(char **)(target + 0x24) + 0x46) != 5 ||
                (signed char)target[0x20] == -2 || (signed char)target[0x20] == -3)
                continue;
            if (!func_002AB1F0((u8 *)target)) continue;
            func_00282CF0(&primary_point, target + 0x10, private);
            if (!D_L26_001A8FF0) distance = func_00282E20(&primary_point);
            else {
                projection = func_00282DB0(&primary_point, D_0018C0B0 + 0xE0);
                func_00282D30(&secondary_point, D_0018C0B0 + 0xE0, projection);
                func_00282CF0(&scratch, &primary_point, &secondary_point);
                distance = func_00282DF0(&scratch);
            }
            if (!(distance <= D_L26_001AF044)) continue;
            angle = func_00283C80(D_L26_001B8B98,
                func_00283248(*(float *)(target + 0x10) - D_L26_001B8B80.f[0],
                               *(float *)(target + 0x14) - D_L26_001B8B80.f[1]));
            if (!(angle <= D_L26_001AF04C)) continue;
            player_angle = 0.0f;
            if (!D_L26_001A8FF0)
                player_angle = func_00283C80(func_00283248(*(float *)(target + 0x10) - D_00189EA0.f[0],
                                                          *(float *)(target + 0x14) - D_00189EA0.f[1]), D_00189EB8);
            else {
                func_00282CF0(&secondary_point, target + 0x10, &D_00189EA0);
                projection = func_00282DB0(&secondary_point, D_0018C0B0 + 0xE0);
                func_00282D30(&scratch, D_0018C0B0 + 0xE0, projection);
                func_00282CF0(&secondary_point, &secondary_point, &scratch);
                projection = func_00282DB0(&secondary_point, D_0018C0B0 + 0xC0);
                length = func_00282DF0(&secondary_point);
                if (length == 0.0f) continue;
                player_angle = 1.5707964f - func_002831B0(projection / length);
            }
            if (!(player_angle <= D_L26_001AF048)) continue;
            score = ((D_L26_001AF04C - angle) / D_L26_001AF04C) * D_L26_001AF0DC +
                    (D_L26_001AF044 - distance) / D_L26_001AF044;
            if (score > best_score) {
                alternate = candidate;
                second_score = best_score;
                best_score = score;
                candidate = target;
            } else if (!(score <= second_score)) {
                alternate = target;
                second_score = score;
            }
        }
    } else {
        *(char **)(private + 0x20) = *(char **)(private + 0x38);
        *(short *)(private + 0x40) = *(short *)(private + 0x42);
        *(char **)(private + 0x38) = 0;
        *(short *)(private + 0x42) = 0;
    }
targets_ready:
    if (candidate) {
        if (!*(char **)(private + 0x20)) {
            *(short *)(private + 0x40) = 0;
            *(char **)(private + 0x20) = candidate;
            if (func_00282948(&D_L26_001B24C0)) D_L26_001B24C0 = 10;
        } else alternate = candidate;
    }
    if (alternate && dual) {
        distance = func_00282E48(private, candidate + 0x10);
        if (distance < D_L26_001AF044 && distance + func_00282E48(candidate + 0x10, alternate + 0x10) < D_L26_001AF044) {
            *(short *)(private + 0x42) = 0;
            *(char **)(private + 0x38) = alternate;
        }
    }
    primary = *(char **)(private + 0x20);
    if (primary) {
        descriptor = (char *)func_002AB1F0((u8 *)primary);
        qcopy(&primary_point, (primary + 0x10));
        func_00282D30(&secondary_point, primary + 0xE0, *(float *)(descriptor + 0x10));
        func_00282CC0(&primary_point, &primary_point, &secondary_point);
        primary_length = func_00282E48(private, &primary_point);
        range = primary_length;
    }
    secondary = *(char **)(private + 0x38);
    if (secondary) {
        descriptor = (char *)func_002AB1F0((u8 *)secondary);
        qcopy(&secondary_point, (secondary + 0x10));
        func_00282D30(&scratch, secondary + 0xE0, *(float *)(descriptor + 0x10));
        func_00282CC0(&secondary_point, &secondary_point, &scratch);
        range = func_00282E48(&primary_point, &secondary_point) + primary_length;
    }
    step_length = range * 0.05f;
    D_L26_001AF0A8 = dual ? 0x207F20 : 0x7F2020;
    func_00282C88(&scratch.q);
    func_002A8C00((char *)&context, (int)object, 0x210000,
        *(float *)(D_L26_002622F0 + (unsigned int)D_0013957A * 0xE0 + 0x70), &scratch);
    context.id = *(unsigned short *)(object + 0xAA);
    context.enabled = 1;
    context.mode = 5;
    *(short *)(private + 0x3E) = 20;
    func_00277F48(private, 16, D_0018C0B0, &context, 0.3f);
    func_00282CF0(&direction, private + 0x10, private);
    func_00282F20(&direction, &direction, 1.0f);
    if (*(char **)(private + 0x20) || *(char **)(private + 0x38)) {
        func_00282DD8(&delta, &direction, &D_0018A0E0);
        func_002ACEC0(&direction, &direction, &delta, 0.17453295f);
    }
    func_00282D30(&heading, &direction, step_length);
    qcopy(&D_L26_00239710[0], private);
    qcopy(&D_L26_00239850[0], private);

    for (i = 1; i < 20; i++) {
        amplitude = D_L26_001AF054 + (D_L26_001AF058 - D_L26_001AF054) * func_00283CE0(i) * 0.05f;
        angle = func_002ABB18(D_L26_001AF05C + (float)i * D_L26_001AF050);
        jitter = amplitude * func_00283198(angle) + func_002A78D8(D_L26_001AF094, D_L26_001AF098);
        D_L26_00239710[i].f[2] -= D_L26_00239990[i];
        D_L26_00239990[i] = jitter;
        func_00300190(D_L26_00239710 + i, D_L26_00239710 + i);
        func_00282CF0(&delta, D_L26_00239710 + i, D_L26_00239710 + i - 1);
        func_00282D08(&proposed, &delta, &heading, 0.85f);
        length = func_00282DF0(&proposed);
        if (length == 0.0f) qcopy(&D_L26_00239710[i], &D_L26_00239710[i - 1]);
        else {
            func_00282D30(&proposed, &proposed, step_length / length);
            func_00282CC0(D_L26_00239710 + i, D_L26_00239710 + i - 1, &proposed);
            qcopy(&heading, &proposed);
        }
        D_L26_00239710[i].f[2] += jitter;
        func_00282CF0(&delta, D_L26_00239710 + i, D_L26_00239710 + i - 1);
        if (*(char **)(private + 0x20)) {
            if (!dual || !*(char **)(private + 0x38)) {
                func_00282CF0(&hit_direction, &primary_point, D_L26_00239710 + i);
                length = func_00282DF0(&hit_direction);
                if (length != 0.0f) {
                    if (i == 19) { factor = 0.5f; step_length = length; }
                    else if (i < 16) factor = 0.1f;
                    else { factor = 0.5f; step_length = length / func_00283CE0(19 - i); }
                    func_00282D30(&hit_direction, &hit_direction, step_length / length);
                    func_00282D08(&heading, &heading, &hit_direction, factor);
                }
            } else {
                func_00282CF0(&hit_direction, i < 10 ? &primary_point : &secondary_point, D_L26_00239710 + i);
                length = func_00282DF0(&hit_direction);
                if (length != 0.0f) {
                    if (i == 9 || i == 19) { factor = 0.7f; step_length = length; }
                    else if ((unsigned int)(i - 5) < 5 || i > 14) {
                        factor = 0.7f;
                        step_length = length / func_00283CE0(i < 10 ? 9 - i : 19 - i);
                    } else factor = 0.2f;
                    func_00282D30(&hit_direction, &hit_direction, step_length / length);
                    func_00282D08(&heading, &heading, &hit_direction, factor);
                }
            }
        }
        if (i < 10) {
            phase = func_002ABB18(D_L26_001AF064 + (float)i * D_L26_001AF06C);
            angle2 = func_002ABB18(D_L26_001AF078 + (float)i * D_L26_001AF080);
            frequency = D_L26_001AF070 * func_00283198(angle2);
            qcopy(&D_L26_00239850[i], &D_L26_00239710[i]);
            wave = frequency * func_00283198(phase) + func_002A78D8(0.0f, 0.1f);
            D_L26_00239B20[i] = wave;
            D_L26_00239850[i].f[2] += wave;
            angle2 = func_00283B98(func_00283248(delta.f[0], delta.f[1]), 1.5707965f);
            magnitude = D_L26_001AF074 * func_00283180(phase);
            lateral.f[0] = func_00283180(angle2) * magnitude;
            lateral.f[1] = func_00283198(angle2) * magnitude;
            qcopy(&D_L26_002399E0[i], &lateral);
            lateral.f[2] = 0.0f;
            func_00282CC0(D_L26_00239850 + i, D_L26_00239850 + i, &lateral);
        } else {
            qcopy(&D_L26_00239850[i], &D_L26_00239710[i]);
            D_L26_00239850[i].f[2] += D_L26_00239B20[21 - i];
            func_00282CC0(D_L26_00239850 + i, D_L26_00239850 + i, D_L26_002399E0 + 21 - i);
            qcopy(&lateral, &D_L26_002399E0[i]);
        }
        if (i > 1 && (i == 19 || !(i & 1))) {
            func_00282CF0(&scratch, D_L26_00239710 + i, &D_L26_001B8B80);
            if (!D_L26_001A8FF0) scratch.f[2] = 0.0f;
            else {
                projection = func_00282DB0(&scratch, D_0018C0B0 + 0xE0);
                func_00282D30(&hit_direction, D_0018C0B0 + 0xE0, projection);
                func_00282CF0(&scratch, &scratch, &hit_direction);
            }
            length = func_00282DF0(&scratch);
            if (length == 0.0f) scratch.f[2] = 1.0f;
            else func_00282D30(&scratch, &scratch, 1.0f / length);
            scratch.f[3] = 5627.925f;
            qcopy(&context.direction, &scratch);
            collided = func_002761F8(D_L26_00239710 + i - 2, D_L26_00239710 + i, 16, object, 0);
            if (collided) {
                hit = D_L26_001BEFD8;
                if (hit) {
                    descriptor = (char *)func_002AB1F0((u8 *)hit);
                    if (!descriptor || !*(char **)(hit + 0x24) || *(short *)(*(char **)(hit + 0x24) + 0x46) != 5)
                        func_002A8E20(hit, &context);
                    else {
                        collided = 0;
                        disabled[disabled_count++] = hit;
                        *(int *)(hit + 0x98) = 0;
                    }
                }
                if (collided) {
                    qcopy(&D_L26_00239710[i], &D_L26_001BEFE0);
                    *(short *)(private + 0x3E) = i;
                    qcopy((private + 0x10), &D_L26_001BEFE0);
                    if (!D_L26_001BEFD8) {
                        *(char **)(private + 0x20) = 0;
                        *(short *)(private + 0x40) = 0;
                    }
                    break;
                }
            }
        }
    }
    for (i = 0; i < disabled_count; i++)
        *(int *)(disabled[i] + 0x98) = *(int *)(*(char **)(disabled[i] + 0x24) + 0x10);
    if (!collided) qcopy((private + 0x10), &D_L26_00239710[19]);
    primary = *(char **)(private + 0x20);
    if (primary && !(*(unsigned long long *)(private + 0x40) & 0xFFFF0000FFFFULL)) {
        func_00282CF0(&hit_direction, primary + 0x10, &D_L26_001B8B80);
        if (!D_L26_001A8FF0) hit_direction.f[2] = 0.0f;
        else {
            projection = func_00282DB0(&hit_direction, D_0018C0B0 + 0xE0);
            func_00282D30(&auxiliary, D_0018C0B0 + 0xE0, projection);
            func_00282CF0(&hit_direction, &hit_direction, &auxiliary);
        }
        func_00282F20(&hit_direction, &hit_direction, 1.0f);
        hit_direction.f[3] = 5627.925f;
        func_002A8C00((char *)&primary_context, (int)object, 0x210000,
            *(float *)(D_L26_002622F0 + (unsigned int)D_0013957A * 0xE0 + 0x70), &hit_direction);
        primary_context.id = *(unsigned short *)(object + 0xAA);
        primary_context.enabled = 3;
        primary_context.mode = 5;
        func_002A8E20(primary, &primary_context);
        descriptor = (char *)func_002AB1F0((u8 *)primary);
        kind = descriptor && *(short *)(descriptor + 4) == 1 ? 1 : 5;
        *(short *)(private + 0x44) = kind;
    }
    secondary = *(char **)(private + 0x38);
    if (secondary && !(*(unsigned long long *)(private + 0x40) & 0xFFFF0000FFFF0000ULL)) {
        func_00282CF0(&hit_direction, secondary + 0x10, &D_L26_001B8B80);
        if (!D_L26_001A8FF0) hit_direction.f[2] = 0.0f;
        else {
            projection = func_00282DB0(&hit_direction, D_0018C0B0 + 0xE0);
            func_00282D30(&auxiliary, D_0018C0B0 + 0xE0, projection);
            func_00282CF0(&hit_direction, &hit_direction, &auxiliary);
        }
        func_00282F20(&hit_direction, &hit_direction, 1.0f);
        hit_direction.f[3] = 5627.925f;
        func_002A8C00((char *)&secondary_context, (int)object, 0x210000,
            *(float *)(D_L26_002622F0 + (unsigned int)D_0013957A * 0xE0 + 0x70), &hit_direction);
        secondary_context.id = *(unsigned short *)(object + 0xAA);
        secondary_context.enabled = 3;
        secondary_context.mode = 5;
        func_002A8E20(secondary, &secondary_context);
        descriptor = (char *)func_002AB1F0((u8 *)secondary);
        kind = descriptor && *(short *)(descriptor + 4) == 1 ? 1 : 5;
        *(short *)(private + 0x46) = kind;
    }
    for (i = 0; i < 4; i++) {
        qcopy(&auxiliary, (i < 2 ? private : private + 0x10));
        magnitude = i < 2 ? 0.4f : 0.5f;
        if (!func_00282978(D_L26_001B24C8 + i)) {
            for (j = 0; j < 4; j++) {
                func_00282CF0(spark_delta + j, D_L26_00239B70[i] + j + 1, D_L26_00239B70[i] + j);
                spark_delta[j].f[0] += func_002A78D8(0.0f, 0.1f);
                spark_delta[j].f[1] += func_002A78D8(0.0f, 0.1f);
                spark_delta[j].f[2] += func_002A78D8(0.0f, 0.1f);
            }
            qcopy(&D_L26_00239B70[i][0], &auxiliary);
            for (j = 0; j < 4; j++)
                func_00282CC0(D_L26_00239B70[i] + j + 1, D_L26_00239B70[i] + j, spark_delta + j);
            difference = D_L26_001B24C8[i] - D_L26_001B24E0[i];
            if (difference < 0) difference = -difference;
            D_L26_001B24D0[i] = func_00283CF0((1.0f - func_00283CE0(difference) / func_00283CE0(15)) * 32.0f);
        } else {
            D_L26_001B24C8[i] = D_L26_001B24D8[i];
            D_L26_001B24D0[i] = 0;
            angle = func_002A78D8(0.52359885f, 1.0471977f);
            angle2 = func_002A7878(-1.0471977f, 0.17453295f);
            func_00282D30(&hit_direction, &direction, magnitude);
            func_002ACEC0(&hit_direction, &hit_direction, &D_0018A560, angle2);
            func_002ACEC0(&hit_direction, &hit_direction, &D_0018A570, angle);
            qcopy(&D_L26_00239B70[i][0], &auxiliary);
            func_00282CC0(D_L26_00239B70[i] + 1, &auxiliary, &hit_direction);
            sign = 1.0f;
            for (j = 0; j < 3; j++) {
                func_00282CF0(&primary_context.direction, D_L26_00239B70[i] + j + 1, &D_L26_001B8B80);
                angle = func_002A7878(0.17453295f, 0.96f) * sign;
                sign = -sign;
                func_002ACEC0(&hit_direction, &hit_direction, &primary_context.direction, angle);
                func_00282CC0(D_L26_00239B70[i] + j + 2, D_L26_00239B70[i] + j + 1, &hit_direction);
            }
        }
    }
    angle = func_002A78D8(0.52359885f, 1.0471977f);
    angle2 = func_002A7878(-0.52359885f, 1.0471977f);
    func_00282D30(&hit_direction, &direction, D_L26_001AF0D8);
    func_002ACEC0(&hit_direction, &hit_direction, &D_0018A560, angle2);
    func_002ACEC0(&hit_direction, &hit_direction, &D_0018A570, angle);
    counter = func_002A7820(1, 8);
    if (func_002A77E0(2)) counter = -counter;
    magnitude = func_002A7878(0.2f, 0.6f);
    func_002C2210(private, 15, D_L26_001AF0A8 | 0x7F000000, 0, counter, &hit_direction, 1,
                   magnitude * 0.3f, magnitude, 0.0f);
    func_002C2210(private, 15, 0x307F7F7F, 0, -counter, &hit_direction, 1,
                   magnitude * 0.15f, magnitude * 0.5f, 0.0f);
    counter = func_002A7820(1, 8);
    if (func_002A77E0(2)) counter = -counter;
    magnitude = func_002A7878(0.15f, 3.0f);
    func_002C2210(private + 0x10, 12, D_L26_001AF0A8 | 0x7F000000, 0, counter, &D_L26_001A8F20, 1,
                   magnitude * 0.1f, magnitude, 0.0f);
}
