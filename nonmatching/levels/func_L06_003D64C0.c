/*
 * Complete manual reconstruction retained as nonmatching; no coverage credit.
 * Fresh qualified-compiler checks, 2026-10-25.
 * Profile: -O2 -G8 -ffunction-sections
 * Coverage: US: 0/1; US2: absent from catalogue; PAL: absent from catalogue.
 * Compiled text: 5692 bytes; retail: 5868 bytes.
 * The shared cooldown is a 32-bit word: 00282948 uses LW/SW and this caller stores 10
 * with SW at +0x4E8. The four duration arrays keep their measured +8 start and 16-bit API.
 * 00277F48 returns a signed 32-bit count in v0; this caller ignores that result.
 * Remaining difference: Moving the zero initialization of target_distance to the measured post-
 * selection phase (+0x558) restores frame 0x440 from 0x450. Complete 128-pointer collision
 * storage, 21 contiguous main entries, four five-vector forks and Impact buffers remain intact.
 * Explicit vector helpers and separate target-side CF0 calls yield 5692/5868; one extra saved FP
 * register and phase/scheduling differences remain.
 * Reopen when: Recover the remaining phase/float lifetimes from exact retail dataflow and
 * allocator diagnostics. Do not manufacture stack overlays or reduce buffer extents.
 */

#include "common.h"

typedef unsigned int Quadword __attribute__((mode(TI)));
typedef union { Quadword whole; float f[4]; } Vector;
typedef struct {
    Vector origin, tip;
    char *primary;
    unsigned char unused24[0x14];
    char *secondary;
    unsigned short unused3c, segments, primary_timer, secondary_timer, primary_kind, secondary_kind;
} BeamState;
typedef struct {
    Vector direction;
    int source, flags;
    unsigned char type, mode;
    unsigned short kind;
    float damage;
    int active;
} Impact;
typedef struct { unsigned char prefix[0x18]; char *object; int polygon; Vector point, offset, normal; } CollisionView;
typedef struct { unsigned char before_mode[4]; unsigned char dual; unsigned char before_damage[0x6b]; float damage; unsigned char tail[0x6c]; } WeaponSettings;
extern WeaponSettings D_L06_0026C7F0[];
extern struct { unsigned char prefix[0x12]; unsigned char selected; } D_00139568;
extern char *D_L06_001FB760[];
extern int D_L06_001A8FF0;
extern char *D_0018C0B0;
extern Vector D_00189EA0;
extern float D_00189EB8;
extern Vector D_L06_001B9840;
extern float D_L06_001B9858;
extern Vector D_0018A0E0;
extern Vector D_0018A560, D_0018A570, D_L06_001A8F20;
extern CollisionView D_L06_001BFC80;
extern Vector D_L06_0023A3C0[21];
extern Vector D_L06_0023A510[20];
extern float D_L06_0023A650[20];
extern Vector D_L06_0023A6A0[20];
extern float D_L06_0023A7E0[20];
extern Vector D_L06_0023A830[4][5];
/* The cooldown and four fork arrays occupy one contiguous prefix. */
extern struct {
    int cooldown;
    /* Unmodeled bytes +4..+7; the first short array is measured at +8. */
    unsigned char unused04[4];
    short duration[4], alpha[4], reset[4], center[4];
} D_L06_001B30C0;
extern float D_L06_001AF014 __attribute__((sda));
extern float D_L06_001AF018 __attribute__((sda));
extern float D_L06_001AF01C __attribute__((sda));
extern float D_L06_001AF020 __attribute__((sda));
extern float D_L06_001AF024 __attribute__((sda));
extern float D_L06_001AF028 __attribute__((sda));
extern float D_L06_001AF02C __attribute__((sda));
extern float D_L06_001AF030 __attribute__((sda));
extern float D_L06_001AF034 __attribute__((sda));
extern float D_L06_001AF038 __attribute__((sda));
extern float D_L06_001AF03C __attribute__((sda));
extern float D_L06_001AF040 __attribute__((sda));
extern float D_L06_001AF044 __attribute__((sda));
extern float D_L06_001AF048 __attribute__((sda));
extern float D_L06_001AF04C __attribute__((sda));
extern float D_L06_001AF050 __attribute__((sda));
extern float D_L06_001AF064 __attribute__((sda));
extern float D_L06_001AF068 __attribute__((sda));
extern unsigned int D_L06_001AF078 __attribute__((sda));
extern float D_L06_001AF0A8 __attribute__((sda));
extern float D_L06_001AF0AC __attribute__((sda));
extern float func_00283B98(float, float), func_00283BE0(float, float), func_00283C80(float, float);
extern float func_00283248(float, float), func_00283180(float), func_00283198(float), func_002831B0(float);
extern float func_00283CE0(int);
extern int func_00283CF0(float);
extern int func_002AB1F0(char *);
extern void func_00282C88(void *);
extern void func_00282CF0(void *, void *, void *), func_00282CC0(void *, void *, void *);
extern void func_00282D30(void *, void *, float), func_00282F20(void *, void *, float);
extern void func_00282DD8(void *, void *, void *);
extern void func_00282D08(void *, void *, void *, float);
extern void func_002ACEC0(void *, void *, void *, float);
extern float func_00282DB0(void *, void *), func_00282DF0(void *), func_00282E20(void *), func_00282E48(void *, void *);
extern int func_00282948(int *);
extern int func_00282978(short *);
extern float func_002A7878(float, float), func_002A78D8(float, float), func_002ABB18(float);
extern void func_002A8C00(Impact *, int, int, float, Vector *);
extern void func_002A8E20(char *, Impact *);
extern int func_00277F48(void *, int, void *, Impact *, float);
extern int func_002761F8(void *, void *, int, void *, int);
extern void func_00300190(void *, void *);
extern int func_002A7820(int, int), func_002A77E0(int);
extern void *func_002C2210(void *, int, unsigned int, int, int, void *, int, float, float, float);

/* Update the two-target beam, its twenty points, and four short decorative forks. */
void func_L06_003D64C0(char *object)
{
    BeamState *beam = *(BeamState **)(object + 0x68);
    Vector primary_position, secondary_position, delta, projection, direction, normal;
    Vector velocity, scratch, pull, endpoint, fork_direction, relative;
    Vector offsets[4];
    Impact hit, target_hit;
    char *disabled[128];
    char *candidate, *primary = 0, *secondary = 0, *data;
    char **entry;
    int dual = D_L06_0026C7F0[D_00139568.selected].dual != 0;
    int count, collided, i, j, side, spin;
    float best = 0, next = 0, distance, angle, view_angle, score;
    float spacing = D_L06_001AF014 * 0.05f;
    float target_distance, amplitude, wobble, old_height, f, f2, phase, sign;
    D_L06_001AF02C = func_00283B98(D_L06_001AF02C, D_L06_001AF030);
    D_L06_001AF034 = func_00283BE0(D_L06_001AF034, D_L06_001AF038);
    D_L06_001AF048 = func_00283B98(D_L06_001AF048, D_L06_001AF04C);
    if (beam->primary == 0 || (dual && beam->secondary == 0)) {
        if (beam->secondary == 0) {
            for (entry = D_L06_001FB760; *entry; entry++) {
                candidate = *entry;
                if (candidate == beam->primary || candidate == beam->secondary || candidate == 0 ||
                    *(char **)(candidate + 0x24) == 0 || *(short *)(*(char **)(candidate + 0x24) + 0x46) != 5 ||
                    *(unsigned char *)(candidate + 0x20) == 0xfe || *(unsigned char *)(candidate + 0x20) == 0xfd ||
                    func_002AB1F0(candidate) == 0)
                    continue;
                func_00282CF0(&delta, candidate + 0x10, beam);
                if (!D_L06_001A8FF0) {
                    distance = func_00282E20(&delta);
                } else {
                    f = func_00282DB0(&delta, D_0018C0B0 + 0xe0);
                    func_00282D30(&projection, D_0018C0B0 + 0xe0, f);
                    func_00282CF0(&scratch, &delta, &projection);
                    distance = func_00282DF0(&scratch);
                }
                if (!(distance <= D_L06_001AF014)) continue;
                f = func_00283248(*(float *)(candidate + 0x10) - D_L06_001B9840.f[0], *(float *)(candidate + 0x14) - D_L06_001B9840.f[1]);
                angle = func_00283C80(D_L06_001B9858, f);
                if (!(angle <= D_L06_001AF01C)) continue;
                view_angle = 0;
                if (!D_L06_001A8FF0) {
                    f = func_00283248(*(float *)(candidate + 0x10) - D_00189EA0.f[0], *(float *)(candidate + 0x14) - D_00189EA0.f[1]);
                    view_angle = func_00283C80(f, D_00189EB8);
                } else {
                    func_00282CF0(&projection, candidate + 0x10, &D_00189EA0);
                    f = func_00282DB0(&projection, D_0018C0B0 + 0xe0);
                    func_00282D30(&scratch, D_0018C0B0 + 0xe0, f);
                    func_00282CF0(&projection, &projection, &scratch);
                    f = func_00282DB0(&projection, D_0018C0B0 + 0xc0);
                    f2 = func_00282DF0(&projection);
                    if (f2 == 0) continue;
                    view_angle = 1.5707963705062866211f - func_002831B0(f / f2);
                }
                if (view_angle <= D_L06_001AF018) {
                    score = ((D_L06_001AF01C - angle) / D_L06_001AF01C) * D_L06_001AF0AC +
                        (D_L06_001AF014 - distance) / D_L06_001AF014;
                    if (score > best) {
                        secondary = primary;
                        next = best;
                        primary = candidate;
                        best = score;
                    } else if (!(score <= next)) {
                        secondary = candidate;
                        next = score;
                    }
                }
            }
        } else {
            beam->primary = beam->secondary;
            beam->primary_timer = beam->secondary_timer;
            beam->secondary = 0;
            beam->secondary_timer = 0;
        }
    }
    if (primary) {
        if (beam->primary == 0) {
            beam->primary_timer = 0;
            beam->primary = primary;
            if (func_00282948(&D_L06_001B30C0.cooldown)) D_L06_001B30C0.cooldown = 10;
        } else secondary = primary;
    }
    if (secondary && dual) {
        distance = func_00282E48(beam, primary + 0x10);
        if (distance < D_L06_001AF014 && distance + func_00282E48(primary + 0x10, secondary + 0x10) < D_L06_001AF014) {
            beam->secondary_timer = 0;
            beam->secondary = secondary;
        }
    }
    target_distance = 0;
    if (beam->primary) {
        data = (char *)func_002AB1F0(beam->primary);
        qcopy(&primary_position, beam->primary + 0x10);
        func_00282D30(&projection, beam->primary + 0xe0, *(float *)(data + 0x10));
        func_00282CC0(&primary_position, &primary_position, &projection);
        target_distance = func_00282E48(beam, &primary_position);
        spacing = target_distance * 0.05f;
    }
    if (beam->secondary) {
        data = (char *)func_002AB1F0(beam->secondary);
        qcopy(&secondary_position, beam->secondary + 0x10);
        func_00282D30(&scratch, beam->secondary + 0xe0, *(float *)(data + 0x10));
        func_00282CC0(&secondary_position, &secondary_position, &scratch);
        spacing = (target_distance + func_00282E48(&primary_position, &secondary_position)) * 0.05f;
    }
    D_L06_001AF078 = dual ? 0x207f20 : 0x7f2020;
    func_00282C88(&scratch);
    func_002A8C00(&hit, (int)object, 0x210000, D_L06_0026C7F0[D_00139568.selected].damage, &scratch);
    hit.kind = *(unsigned short *)(object + 0xaa); hit.mode = 1; hit.type = 5;
    beam->segments = 20;
    func_00277F48(beam, 0x10, D_0018C0B0, &hit, 0.3f);
    func_00282CF0(&direction, &beam->tip, beam);
    func_00282F20(&direction, &direction, 1.0f);
    if (beam->primary || beam->secondary) {
        func_00282DD8(&normal, &direction, &D_0018A0E0);
        func_002ACEC0(&direction, &direction, &normal, 0.17453294992446899414f);
    }
    func_00282D30(&velocity, &direction, spacing);
    qcopy(&D_L06_0023A3C0[1], &beam->origin);
    qcopy(&D_L06_0023A510[0], &beam->origin);
    count = 0;
    collided = 0;
    for (i = 1; i < 20; i++) {
        Vector *point = &D_L06_0023A3C0[i + 1];
        Vector *render = &D_L06_0023A510[i];
        amplitude = D_L06_001AF024 + (D_L06_001AF028 - D_L06_001AF024) * func_00283CE0(i) * 0.05f;
        phase = func_002ABB18(D_L06_001AF02C + (float)i * D_L06_001AF020);
        wobble = amplitude * func_00283198(phase) + func_002A78D8(D_L06_001AF064, D_L06_001AF068);
        old_height = D_L06_0023A650[i]; D_L06_0023A650[i] = wobble; point->f[2] -= old_height;
        func_00300190(point, point);
        func_00282CF0(&normal, point, &D_L06_0023A3C0[i]);
        func_00282D08(&scratch, &normal, &velocity, 0.85f);
        distance = func_00282DF0(&scratch);
        if (distance == 0) {
            qcopy(point, &D_L06_0023A3C0[i]);
        } else {
            func_00282D30(&scratch, &scratch, spacing / distance);
            func_00282CC0(point, &D_L06_0023A3C0[i], &scratch);
            qcopy(&velocity, &scratch);
        }
        point->f[2] += wobble;
        func_00282CF0(&normal, point, &D_L06_0023A3C0[i]);
        if (beam->primary) {
            if (!dual || beam->secondary == 0) {
                func_00282CF0(&pull, &primary_position, point);
                distance = func_00282DF0(&pull);
                if (distance != 0) {
                    f = 0.5f;
                    if (i == 19) spacing = distance;
                    else if (i < 16) f = 0.1f;
                    else spacing = distance / func_00283CE0(19 - i);
                    func_00282D30(&pull, &pull, spacing / distance);
                    func_00282D08(&velocity, &velocity, &pull, f);
                }
            } else {
                if (i < 10) func_00282CF0(&pull, &primary_position, point);
                else func_00282CF0(&pull, &secondary_position, point);
                distance = func_00282DF0(&pull);
                if (distance != 0) {
                    if (i == 9 || i == 19) { f = 0.7f; spacing = distance; }
                    else if ((unsigned int)(i - 5) < 5 || i > 14) { f = 0.7f; spacing = distance / func_00283CE0(i < 10 ? 9 - i : 19 - i); }
                    else f = 0.2f;
                    func_00282D30(&pull, &pull, spacing / distance);
                    func_00282D08(&velocity, &velocity, &pull, f);
                }
            }
        }
        if (i < 10) {
            phase = func_002ABB18(D_L06_001AF034 + (float)i * D_L06_001AF03C);
            f = func_002ABB18(D_L06_001AF048 + (float)i * D_L06_001AF050);
            amplitude = D_L06_001AF040 * func_00283198(f);
            qcopy(render, point);
            wobble = amplitude * func_00283198(phase) + func_002A78D8(0, 0.1f);
            D_L06_0023A7E0[i] = wobble; render->f[2] += wobble;
            f = func_00283B98(func_00283248(normal.f[0], normal.f[1]), 1.5707964897155761719f);
            amplitude = D_L06_001AF044 * func_00283180(phase);
            endpoint.f[0] = func_00283180(f) * amplitude;
            endpoint.f[1] = func_00283198(f) * amplitude;
            qcopy(&D_L06_0023A6A0[i], &endpoint);
            endpoint.f[2] = 0;
            func_00282CC0(render, render, &endpoint);
        } else {
            qcopy(render, point);
            render->f[2] += D_L06_0023A7E0[21 - i];
            func_00282CC0(render, render, &D_L06_0023A6A0[21 - i]);
            qcopy(&endpoint, &D_L06_0023A6A0[i]);
        }
        if (i > 1 && (i == 19 || !(i & 1))) {
            func_00282CF0(&scratch, point, &D_L06_001B9840);
            if (!D_L06_001A8FF0) scratch.f[2] = 0;
            else {
                f = func_00282DB0(&scratch, D_0018C0B0 + 0xe0);
                func_00282D30(&pull, D_0018C0B0 + 0xe0, f);
                func_00282CF0(&scratch, &scratch, &pull);
            }
            distance = func_00282DF0(&scratch);
            if (distance == 0) scratch.f[2] = 1.0f;
            else func_00282D30(&scratch, &scratch, 1.0f / distance);
            scratch.f[3] = 5627.9248046875f;
            qcopy(&hit.direction, &scratch);
            collided = func_002761F8(&D_L06_0023A3C0[i - 1], point, 0x10, object, 0);
            if (collided) {
                candidate = D_L06_001BFC80.object;
                if (candidate) {
                    if (!func_002AB1F0(candidate) || !*(char **)(candidate + 0x24) || *(short *)(*(char **)(candidate + 0x24) + 0x46) != 5) {
                        func_002A8E20(candidate, &hit);
                    } else {
                        collided = 0; disabled[count++] = candidate; *(int *)(candidate + 0x98) = 0;
                    }
                }
                if (collided) {
                    qcopy(point, &D_L06_001BFC80.point);
                    beam->segments = i; qcopy(&beam->tip, &D_L06_001BFC80.point);
                    if (!D_L06_001BFC80.object) { beam->primary = 0; beam->primary_timer = 0; }
                    break;
                }
            }
        }
    }
    for (i = 0; i < count; i++) *(int *)(disabled[i] + 0x98) = *(int *)(*(char **)(disabled[i] + 0x24) + 0x10);
    if (!collided) qcopy(&beam->tip, &D_L06_0023A3C0[20]);
    if (beam->primary && !beam->primary_timer && !beam->primary_kind) {
        func_00282CF0(&pull, beam->primary + 0x10, &D_L06_001B9840);
        if (!D_L06_001A8FF0) pull.f[2] = 0;
        else { f = func_00282DB0(&pull, D_0018C0B0 + 0xe0); func_00282D30(&fork_direction, D_0018C0B0 + 0xe0, f); func_00282CF0(&pull, &pull, &fork_direction); }
        func_00282F20(&pull, &pull, 1.0f); pull.f[3] = 5627.9248046875f;
        func_002A8C00(&target_hit, (int)object, 0x210000, D_L06_0026C7F0[D_00139568.selected].damage, &pull);
        target_hit.kind = *(unsigned short *)(object + 0xaa); target_hit.mode = 3; target_hit.type = 5;
        func_002A8E20(beam->primary, &target_hit);
        data = (char *)func_002AB1F0(beam->primary);
        beam->primary_kind = data && *(short *)(data + 4) == 1 ? 1 : 5;
    }
    if (beam->secondary && !beam->secondary_timer && !beam->secondary_kind) {
        func_00282CF0(&pull, beam->secondary + 0x10, &D_L06_001B9840);
        if (!D_L06_001A8FF0) pull.f[2] = 0;
        else { f = func_00282DB0(&pull, D_0018C0B0 + 0xe0); func_00282D30(&fork_direction, D_0018C0B0 + 0xe0, f); func_00282CF0(&pull, &pull, &fork_direction); }
        func_00282F20(&pull, &pull, 1.0f); pull.f[3] = 5627.9248046875f;
        func_002A8C00(&target_hit, (int)object, 0x210000, D_L06_0026C7F0[D_00139568.selected].damage, &pull);
        target_hit.kind = *(unsigned short *)(object + 0xaa); target_hit.mode = 3; target_hit.type = 5;
        func_002A8E20(beam->secondary, &target_hit);
        data = (char *)func_002AB1F0(beam->secondary);
        beam->secondary_kind = data && *(short *)(data + 4) == 1 ? 1 : 5;
    }
    for (side = 0; side < 4; side++) {
        qcopy(&endpoint, side < 2 ? &beam->origin : &beam->tip);
        if (!func_00282978(&D_L06_001B30C0.duration[side])) {
            for (j = 0; j < 4; j++) {
                func_00282CF0(&offsets[j], &D_L06_0023A830[side][j + 1], &D_L06_0023A830[side][j]);
                offsets[j].f[0] += func_002A78D8(0, 0.1f);
                offsets[j].f[1] += func_002A78D8(0, 0.1f);
                offsets[j].f[2] += func_002A78D8(0, 0.1f);
            }
            qcopy(&D_L06_0023A830[side][0], &endpoint);
            for (j = 0; j < 4; j++) func_00282CC0(&D_L06_0023A830[side][j + 1], &D_L06_0023A830[side][j], &offsets[j]);
            i = D_L06_001B30C0.duration[side] - D_L06_001B30C0.center[side];
            if (i < 0) i = -i;
            D_L06_001B30C0.alpha[side] = func_00283CF0((1.0f - func_00283CE0(i) / func_00283CE0(15)) * 32.0f);
        } else {
            D_L06_001B30C0.duration[side] = D_L06_001B30C0.reset[side]; D_L06_001B30C0.alpha[side] = 0;
            f = func_002A78D8(0.52359884977340698242f, 1.0471976995468139648f);
            f2 = func_002A7878(-1.0471976995468139648f, 0.17453294992446899414f);
            func_00282D30(&pull, &direction, side < 2 ? 0.4f : 0.5f);
            func_002ACEC0(&pull, &pull, &D_0018A560, f2);
            func_002ACEC0(&pull, &pull, &D_0018A570, f);
            qcopy(&D_L06_0023A830[side][0], &endpoint);
            func_00282CC0(&D_L06_0023A830[side][1], &endpoint, &pull);
            sign = 1.0f;
            for (j = 0; j < 3; j++) {
                func_00282CF0(&relative, &D_L06_0023A830[side][j + 1], &D_L06_001B9840);
                f = func_002A7878(0.17453294992446899414f, 0.95993119478225708008f) * sign; sign = -sign;
                func_002ACEC0(&pull, &pull, &relative, f);
                func_00282CC0(&D_L06_0023A830[side][j + 2], &D_L06_0023A830[side][j + 1], &pull);
            }
        }
    }
    f = func_002A78D8(0.52359884977340698242f, 1.0471976995468139648f);
    f2 = func_002A7878(-0.52359884977340698242f, 1.0471976995468139648f);
    func_00282D30(&pull, &direction, D_L06_001AF0A8);
    func_002ACEC0(&pull, &pull, &D_0018A560, f2); func_002ACEC0(&pull, &pull, &D_0018A570, f);
    spin = func_002A7820(1, 8); if (func_002A77E0(2)) spin = -spin;
    f = func_002A7878(0.2f, 0.6f);
    func_002C2210(beam, 15, D_L06_001AF078 | 0x7f000000, 0, spin, &pull, 1, f * 0.3f, f, 0);
    func_002C2210(beam, 15, 0x307f7f7f, 0, -spin, &pull, 1, f * 0.15f, f * 0.5f, 0);
    spin = func_002A7820(1, 8); if (func_002A77E0(2)) spin = -spin;
    f = func_002A7878(0.15f, 3.0f);
    func_002C2210(&beam->tip, 12, D_L06_001AF078 | 0x7f000000, 0, spin, &D_L06_001A8F20, 1, f * 0.1f, f, 0);
}
