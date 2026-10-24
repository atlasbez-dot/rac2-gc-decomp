/* Nonmatching reconstruction of func_L00_003F4210 (retail 2392 bytes).
 * Measured 2026-10-23: 2352 bytes, 0/27 placements in US and US2.
 * PAL has no catalogue entry. Profile: -O2 -G8 -ffunction-sections
 * -frac2-qcopy -frac2-qcopy-barrier. The 0x100 frame matches; allocation,
 * branch shape and scheduling remain. Reopen with original local lifetime
 * evidence. No candidate or linked-build credit is claimed.
 * 003252A8 forwards output/mode in a1/a2 to 002AFFD8. This three-argument
 * interface is reconciled with the lead repair of the former one-argument
 * definition, preserving all retail inputs. 00282F70 takes f12 at both calls: the second
 * value is minimum/60, built at US 00:003F46B0 before the branch.
 * 002BDCE8 returns the allocated pointer, with a 64-bit signed color word.
 * 002ABBB8 preserves seven FP, eight GPR and four stack inputs (0,8,16,24).
 * The scratch union overlays disjoint movement, color and explosion phases;
 * its motion arm and the damage request are each 48 bytes, the RGB is 12.
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

typedef struct { float r, g, b; } Color;
typedef struct {
    unsigned char pad[0x10];
    Vector velocity;
    int timer;
    char *owner;
    short particle_timer, bounces;
    float fade_scale;
} ProjectileState;
extern char *D_L00_001BF218;
extern Vector D_L00_001BF220, D_L00_001BF240;
extern int D_L00_001A8FF0;
extern Vector D_L00_001A8F20;
extern char *D_L00_001C3280[];
extern unsigned char D_00139587;
extern unsigned char D_L00_00262570[];
extern Color D_L00_001B0920;
extern float D_L00_001B0900 __attribute__((sda));
extern int D_L00_001B0904 __attribute__((sda));
extern float D_L00_001B0908 __attribute__((sda));
extern float D_L00_001B090C __attribute__((sda));
extern float D_L00_001B0918 __attribute__((sda));
extern float D_L00_001B091C __attribute__((sda));
extern int func_00277258(Vector *, int, char *, float);
extern int func_00282948(int *);
extern int func_00282978(short *);
extern void func_00282CC0(Vector *, const Vector *, const Vector *);
extern void func_00282CF0(Vector *, const Vector *, const Vector *);
extern void func_L00_003252A8(void *, void *, int);
extern void func_00282D30(Vector *, const Vector *, float);
extern float func_00282DB0(const Vector *, const Vector *);
extern void func_L00_0031D670(Vector *, const Vector *, const Vector *, float);
extern int func_002A77E0(int);
extern float func_00283CE0(int);
extern char *func_002BDCE8(Vector *, int, const Vector *, long, int, float, float, float, float);
extern int func_002761F8(Vector *, Vector *, int, char *, int);
extern void func_00282F20(Vector *, const Vector *, float);
extern void func_00283028(Vector *, const Vector *, const Vector *);
extern int func_002E5CF8(int, int, char *);
extern void func_00282F70(Vector *, const Vector *, float);
extern float func_00282E20(const Vector *);
extern void func_003001E0(Vector *, const Vector *, const Vector *);
extern int func_00283CF0(float);
extern void func_00300190(void *, void *);
extern int func_002E5DA0(int, int, char *, int);
extern void func_002ABBB8(void *, void *, void *, float, float, int, int, int,
                         float, float, float, float, int, float, int, int, int, int, int);
extern void func_002A8BD0(char *, int, int, float);
extern int func_00277F48(Vector *, int, char *, DamageRequest *, float);
extern int func_00334160(char *, int, int);
extern void func_0029F338(void *);
extern float func_00283B98(float, float);

void func_L00_003F4210(char *object)
{
    union {
        DamageRequest request;
        Color color;
        struct { Vector end, normal, scaled; } motion;
    } scratch;
    Vector point, temporary, vertical, tangent;
    ProjectileState *state = *(ProjectileState **)(object + 0x68);
    Vector *position = (Vector *)(object + 0x10);
    Vector *velocity = &state->velocity;
    char *particle;
    char **hit;
    int count, i, spin, crossed;
    unsigned int red, green, blue;
    float speed, fade, damage, dot, minimum;

    if (func_00277258(position, 0, object, 0.64999998f) != 0 &&
        D_L00_001BF218 != 0 && D_L00_001BF218 != state->owner)
        *(unsigned char *)(object + 0x20) = 3;
    if (func_00282948(&state->timer) != 0)
        *(unsigned char *)(object + 0x20) = 3;
    switch (*(unsigned char *)(object + 0x20)) {
    case 0:
    case 1:
        func_00282CC0(&scratch.motion.end, position, velocity);
        func_L00_003252A8(object, &scratch.motion.normal, 0);
        func_00282D30(&scratch.motion.scaled, &scratch.motion.normal, velocity->v[3]);
        func_00282CC0(velocity, velocity, &scratch.motion.scaled);
        if (D_L00_001A8FF0 == 0) {
            if (*(unsigned char *)(object + 0x20) == 1 && velocity->v[2] < 0.0f)
                *(unsigned char *)(object + 0x20) = 0;
        } else if (*(unsigned char *)(object + 0x20) == 1) {
            if (func_00282DB0(velocity, &scratch.motion.normal) > 0.0f)
                *(unsigned char *)(object + 0x20) = 0;
        }
        func_00282978(&state->particle_timer);
        if (state->particle_timer != 0) {
            for (i = 0; i < 3; ++i) {
                temporary.word = position->word;
                func_L00_0031D670(&point, &temporary, &scratch.motion.end, (float)i * 0.3333f);
                spin = func_002A77E0(6);
                if (func_002A77E0(2) != 0) spin = -spin;
                fade = func_00283CE0(D_L00_001B0904);
                particle = func_002BDCE8(&point, spin, &D_L00_001A8F20, (long)(int)0x80808080,
                                        1, 0.025f, 1.0f, 1.0f,
                                        ((float)state->particle_timer / fade) * 45000.0f + 5000.0f);
                if (particle != 0) {
                    *(short *)(particle + 0xa) = 120;
                    *(int *)(particle + 0x24) = 2;
                    *(unsigned char *)(particle + 0x2a) = 127;
                    *(unsigned char *)(particle + 0x2b) = *(unsigned char *)(particle + 0xa);
                }
            }
        }
        if (func_002761F8(position, &scratch.motion.end, 0, object, 0) != 0 &&
            (D_L00_001BF218 == 0 || D_L00_001BF218 != state->owner))
            position->word = D_L00_001BF220.word;
        else
            position->word = scratch.motion.end.word;
        if (D_L00_001A8FF0 == 0) {
            crossed = position->v[2] - D_L00_001BF220.v[2] < 0.0f;
        } else {
            func_00282CF0(&point, position, &D_L00_001BF220);
            crossed = func_00282DB0(&point, &scratch.motion.normal) > 0.0f;
        }
        if (func_00277258(position, 0, object, D_L00_001B0900) == 0) break;
        if (*(unsigned char *)(object + 0x20) != 0 && !crossed) break;
        if (D_L00_001BF218 != 0 && D_L00_001BF218 == state->owner) break;
        func_00282F20(&point, &D_L00_001BF240, D_L00_001B0900);
        func_00282CC0(position, &D_L00_001BF220, &point);
        func_00283028(velocity, velocity, &D_L00_001BF240);
        func_002E5CF8(1, 0, object);
        if (*(unsigned char *)(object + 0x20) == 0) {
            *(unsigned char *)(object + 0x20) = 3;
            ++state->bounces;
            if (state->bounces == 1) {
                func_00282F70(velocity, velocity, D_L00_001B091C * 0.016666668f);
                if (D_L00_001A8FF0 == 0) {
                    velocity->v[2] *= D_L00_001B0918;
                } else {
                    dot = func_00282DB0(velocity, &scratch.motion.normal);
                    func_00282D30(&temporary, &scratch.motion.normal, -dot);
                    func_00282CF0(&vertical, velocity, &temporary);
                    func_00282D30(&temporary, &temporary, D_L00_001B0918);
                    func_00282CC0(velocity, &vertical, &temporary);
                }
                func_003001E0(velocity, velocity, position);
            } else {
                func_00282D30(&temporary, velocity, D_L00_001B0918);
                speed = func_00282E20(&temporary);
                minimum = D_L00_001B0908 * 0.016666668f;
                if (speed < minimum) {
                    func_00282F70(velocity, velocity, minimum);
                    if (D_L00_001A8FF0 == 0) {
                        velocity->v[2] *= D_L00_001B0918;
                    } else {
                        dot = func_00282DB0(velocity, &scratch.motion.normal);
                        func_00282D30(&vertical, &scratch.motion.normal, -dot);
                        func_00282CF0(&tangent, velocity, &vertical);
                        func_00282D30(&vertical, &vertical, D_L00_001B0918);
                        func_00282CC0(velocity, &tangent, &vertical);
                    }
                    func_003001E0(velocity, velocity, position);
                } else {
                    velocity->word = temporary.word;
                }
            }
        }
        if (state->bounces >= 4) {
            *(unsigned char *)(object + 0x20) = 2;
            if (D_L00_001A8FF0 == 0) velocity->v[2] = 0.0f;
            else {
                dot = func_00282DB0(velocity, &scratch.motion.normal);
                func_00282D30(&temporary, &scratch.motion.normal, -dot);
                func_00282CF0(velocity, velocity, &temporary);
            }
            speed = func_00282E20(velocity);
            velocity->v[3] = speed * D_L00_001B0918;
            if (velocity->v[3] < D_L00_001B0908 * 0.016666668f)
                velocity->v[3] = D_L00_001B0908 * 0.016666668f;
            func_00282F20(velocity, velocity, velocity->v[3]);
            func_003001E0(velocity, velocity, position);
            state->fade_scale = 1.0f / func_00283CE0(state->timer);
        }
        break;
    case 2:
        scratch.color = D_L00_001B0920;
        fade = (float)state->timer * state->fade_scale;
        red = func_00283CF0((scratch.color.r - 255.0f) * fade + 255.0f);
        green = func_00283CF0(scratch.color.g * fade);
        blue = func_00283CF0(scratch.color.b * fade);
        *(unsigned int *)(object + 0x78) = (blue << 16) | 0xff000000 | (green << 8) | red;
        velocity->v[3] *= (D_L00_001B090C - 1.0f) + 1.0f;
        if (velocity->v[3] < D_L00_001B0908 * 0.016666668f)
            velocity->v[3] = D_L00_001B0908 * 0.016666668f;
        func_00282F20(velocity, velocity, velocity->v[3]);
        func_00282CC0(position, position, velocity);
        func_00300190(position, position);
        break;
    case 3:
        damage = *(float *)(D_L00_00262570 + D_00139587 * 0xe0 + 0x74);
        func_002E5DA0(5, 0, object, 0xb02);
        func_002ABBB8(object, velocity, position, 0.0f, 0.0f, 5, 2, 4,
                     6.0f, 2.0f, 9.0f, 1.0f, 0, 15.0f, 1, 1, -1, 0, 0x810001);
        func_002A8BD0((char *)&scratch.request, (int)object, 0x810000, damage);
        scratch.request.enabled = 2;
        scratch.request.kind = 1;
        scratch.request.object_class = *(unsigned short *)(object + 0xaa);
        count = func_00277F48(position, 0x10, object, &scratch.request, 6.0f);
        hit = D_L00_001C3280;
        while (count > 0) {
            func_00334160(*hit, 61, *(int *)(object + 0xb8));
            ++hit;
            --count;
        }
        func_0029F338(object);
        return;
    }
    if (*(unsigned char *)(object + 0x20) < 2) speed = func_00282E20(velocity);
    else if (*(unsigned char *)(object + 0x20) == 2) speed = velocity->v[3];
    else return;
    if (speed < 0.0033333336f) speed = 0.0033333336f;
    if (speed > 0.10000001f) speed = 0.10000001f;
    *(float *)(object + 0xf4) = func_00283B98((((speed - 0.0033333336f) / 0.09666668f) * 7.0f + 1.0f) * 0.017453294f,
                                            *(float *)(object + 0xf4));
}
