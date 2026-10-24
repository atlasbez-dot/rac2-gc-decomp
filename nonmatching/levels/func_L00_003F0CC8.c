/* Nonmatching reconstruction of func_L00_003F0CC8 (retail 1592 bytes).
 * Measured 2026-10-23: 1580 bytes, 0/27 placements in US and US2.
 * PAL has no catalogue entry. Profile: -O2 -G8 -ffunction-sections
 * -frac2-qcopy -frac2-qcopy-barrier. Remaining register allocation and loop
 * scheduling differences need original local declarations to reopen.
 * Canonical 0032A978 takes no arguments, so its unused retail a0 setup is
 * omitted. The 0032AA30 call retains the object supplied by this caller,
 * although the callee overwrites a0 before reading it.
 * Callback 00:003F1C68 is canonical func_0032B190, a genuine entry.
 * The 137 angle pairs, eight 32-byte lights and 48-byte damage request are
 * complete extents. No matching or linked-build credit is claimed.
 */
#include "common.h"

typedef unsigned int QuadWord __attribute__((mode(TI)));
typedef union { QuadWord word; float v[4]; } Vector;
typedef struct { int a, b, c, d; } __attribute__((aligned(16))) Quad16;
typedef struct {
    Vector impulse;
    int owner, flags;
    unsigned char enabled, kind;
    unsigned short object_class;
    float damage;
    int active;
} DamageRequest;

typedef struct {
    int pending, timer;
    char *first, *second;
    int light;
    float radius;
} EffectState;
typedef struct {
    int reserved[2];
    float intensity;
    int flags;
    Vector position;
} Light;
extern char *D_0018C0B0;
extern Vector D_00189F00, D_0018A0C0;
extern Vector D_L00_001B8DC0, D_L00_001BF220;
extern float D_L00_00252F60[137][2];
extern char *D_L00_001C3280[];
extern Light D_L00_001C6F40[8];
extern int D_L00_001B08D0 __attribute__((sda));
extern float func_002A7940(void);
extern float func_00283CE0(int);
extern float func_002A7790(float);
extern void func_002AF000(float *, float, float, float);
extern void func_00282CC0(Vector *, const Vector *, const Vector *);
extern void func_00282CF0(Vector *, const Vector *, const Vector *);
extern void func_00282F20(Vector *, const Vector *, float);
extern int func_002761F8(Vector *, Vector *, int, char *, int);
extern void func_0032B598(char *, Vector *, int);
extern void func_0032ABC0(char *);
extern int func_00282948(int *);
extern int func_00277F48(Vector *, int, char *, DamageRequest *, float);
extern void func_002A8C00(char *, int, int, float, Quad16 *);
extern void func_002A8E20(char *, DamageRequest *);
extern void func_0032A978(void);
extern void func_0032AA30(void *);
extern void func_0029F338(void *);
extern void func_00291450(int);
extern float func_00283180(float);
extern int func_00283CF0(float);
extern float func_00283B98(float, float);
extern float func_00283BE0(float, float);
extern void func_002833F0(Vector *, const Vector *);
extern void func_0032ACF0(int);
extern void func_0032AF50(s8 *);
extern void func_0032B7D0(char *);
extern void func_L00_002E6EF8(void (*)(void *), void *);
extern void func_0032B190(void *);

void func_L00_003F0CC8(char *object)
{
    Vector point;
    DamageRequest request;
    EffectState *state = *(EffectState **)(object + 0x68);
    char **hit;
    char *satellite;
    Light *light;
    int count;
    float progress, first_angle, second_angle;
    float (*angles)[2];

    ((Vector *)(object + 0x10))->word = ((Vector *)(D_0018C0B0 + 0x10))->word;
    switch (*(unsigned char *)(object + 0x20)) {
    case 0:
        *(unsigned char *)(object + 0x20) = 1;
        state->timer = 60;
        state->radius = 0.0f;
        angles = D_L00_00252F60;
        count = 136;
        do {
            --count;
            (*angles)[0] = func_002A7940();
            (*angles)[1] = func_002A7940();
            ++angles;
        } while (count >= 0);
    case 1:
        *(unsigned char *)(object + 0x20) = 2;
    case 2:
        progress = func_00283CE0(state->timer);
        progress /= func_00283CE0(60);
        state->radius = func_002A7790(1.0f - progress) * 15.0f;
        if (state->timer % 3 == 0) {
            first_angle = func_002A7940();
            second_angle = func_002A7940();
            func_002AF000(point.v, state->radius, first_angle, second_angle);
            func_00282CC0(&point, &point, &D_00189F00);
            if (func_002761F8(&D_00189F00, &point, 0, D_0018C0B0, 0) != 0)
                point.word = D_L00_001BF220.word;
            func_0032B598(object, &point, 10);
        }
        if (state->timer < 10 && (state->timer & 7) == 0)
            func_0032ABC0(object);
        if (func_00282948(&state->timer) != 0) {
            state->timer = 120;
            *(unsigned char *)(object + 0x20) = 3;
            count = func_00277F48(&D_00189F00, 0, object, 0, 15.0f);
            hit = D_L00_001C3280;
            while (count > 0) {
                if ((*(unsigned long long *)(*hit + 0x30) & 0x500000000000ULL) != 0 &&
                    *hit != D_0018C0B0 && *(short *)(*hit + 0xaa) != 0xce7 &&
                    *(short *)(*hit + 0xaa) != 0xbb8) {
                    func_00282CF0(&point, (Vector *)(*hit + 0x10), &D_00189F00);
                    func_00282F20(&point, &point, 1.0f);
                    /* The incoming request impulse is not initialized in retail. */
                    func_00282F20(&request.impulse, &request.impulse, 1.0f);
                    func_002A8C00((char *)&request, (int)object, 0x830000, 30.0f, (Quad16 *)&point);
                    request.impulse.word = point.word;
                    request.impulse.v[3] = 5627.9248f;
                    request.enabled = 5;
                    request.kind = 3;
                    request.object_class = *(unsigned short *)(*hit + 0xaa);
                    request.active = 1;
                    func_002A8E20(*hit, &request);
                }
                --count;
                ++hit;
            }
            func_0032A978();
        }
        break;
    case 3:
        if ((state->timer & 7) == 0) func_0032ABC0(object);
        func_00282948(&state->timer);
        func_0032AA30(object);
        if (state->timer == 40) *(unsigned char *)(object + 0x20) = 4;
        break;
    case 4:
        if (func_00282948(&state->timer) != 0 && state->pending == 0) {
            if (state->first != 0) func_0029F338(state->first);
            if (state->second != 0) func_0029F338(state->second);
            if (state->light != -1) func_00291450(state->light);
            D_L00_001B08D0 = 0;
            func_0029F338(object);
            return;
        }
        break;
    }
    progress = func_00283CE0(state->timer);
    progress /= func_00283CE0(120);
    progress = (func_00283180((1.0f - progress) * 6.2831855f - 3.1415927f) + 1.0f) * 0.5f;
    if (state->first != 0) {
        **(int **)(state->first + 0x68) = func_00283CF0(progress * 32.0f);
        *(float *)(state->first + 0xf8) = func_00283B98(*(float *)(state->first + 0xf8), 0.052359887f);
        satellite = state->first;
        func_002833F0((Vector *)(satellite + 0xc0), (Vector *)(satellite + 0xf0));
        *(float *)(state->first + 0xc0) *= 0.5f;
        *(float *)(state->first + 0xd4) *= 0.5f;
        *(float *)(state->first + 0xe8) = progress * 1.5f;
        ((Vector *)(state->first + 0x10))->word = ((Vector *)(D_0018C0B0 + 0x10))->word;
    }
    if (state->second != 0) {
        **(int **)(state->second + 0x68) = func_00283CF0(progress * 32.0f);
        *(float *)(state->second + 0xf8) = func_00283BE0(*(float *)(state->second + 0xf8), 0.052359887f);
        satellite = state->second;
        func_002833F0((Vector *)(satellite + 0xc0), (Vector *)(satellite + 0xf0));
        *(float *)(state->second + 0xe8) = progress;
        ((Vector *)(state->second + 0x10))->word = ((Vector *)(D_0018C0B0 + 0x10))->word;
    }
    if (state->light != -1) {
        light = &D_L00_001C6F40[state->light];
        func_00282F20(&point, &D_0018A0C0, 0.5f);
        func_00282CC0(&light->position, (Vector *)(D_0018C0B0 + 0x10), &point);
        func_00282CF0(&point, &D_L00_001B8DC0, &light->position);
        func_00282F20(&point, &point, 0.15f);
        func_00282CC0(&light->position, &light->position, &point);
        light->intensity = progress;
        light->position.v[3] = 5.0f;
        light->flags = 0;
    }
    func_0032ACF0((int)object);
    func_0032AF50((s8 *)object);
    func_0032B7D0(object);
    func_L00_002E6EF8(func_0032B190, object);
}
