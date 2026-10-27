/* Nonmatching C: Initialize the effect pools, apply area damage and advance its timed fade states.
 * Tested profile: -O2 -G8 -ffunction-sections.
 * Measured US size: 1344 bytes; retail: 1360 bytes.
 * Placement checks: US and US2: 0/27 each; PAL: absent from the catalogue.
 * Remaining: Pool clearing direction, pointer lifetimes and scalar-global allocation differ.
 * Reopen with independent pool-clear and alias-reload evidence; preserve the complete 48-byte damage request and avoid inferring a whole pool extent.
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
    unsigned char pad[0x10];
    float angle;
    int timer;
    float angular_velocity;
    int alpha;
    short pad20;
    short slot;
    int damage, handle;
} EffectState;

extern char *D_L00_001B2BB4 __attribute__((sda));
extern char *D_L00_001B2BB8;
extern int *D_L00_001B2BBC;
extern char *D_L00_001C3280[];
extern char *D_0018C0B0;
extern unsigned char D_00139592;
extern unsigned char D_L00_00262570[];
extern float D_L00_001B8DE0;
extern int D_L00_001B8DE8, D_L00_001B8DEC;
extern float D_L00_001B0830 __attribute__((sda)), D_L00_001B0834 __attribute__((sda));

extern int func_002B4038(int, int);
extern void func_00300190(void *, void *);
extern int func_L00_00329E90(char *, int, int *);
extern char *func_L00_0032A088(int, int);
extern int func_L00_003EEE20(int);
extern void func_L00_003EFF58(char *, int, Vector *, EffectState *, float);
extern void func_L00_003EF560(char *, Vector *);
extern int func_00283DB8(Vector *, float);
extern float func_00283CE0(int);
extern int func_00283CF0(float);
extern int func_00277F48(Vector *, int, char *, DamageRequest *, float);
extern int func_002AB1F0(unsigned char *);
extern void func_00282CF0(Vector *, const Vector *, const Vector *);
extern void func_00282F20(Vector *, const Vector *, float);
extern void func_002A8C00(char *, int, int, float, Quad16 *);
extern void func_002A8E20(char *, DamageRequest *);
extern int func_0032D758(char *, int, int);
extern int func_00282948(int *);
extern void func_L00_003EF550(void);
extern void func_0029F338(void *);
extern void func_L00_003F00A0(char *);
extern void func_L00_002E6EF8(void (*)(char *), char *);
extern void func_L00_003EFA00(char *);

void func_L00_003EEE90(char *object)
{
    Vector initial_position, light_position, normal;
    DamageRequest request;
    int created;
    EffectState *state = *(EffectState **)(object + 0x68);
    Vector *position = (Vector *)(object + 0x10);
    char *record;
    char **hit;
    int count, i;
    float progress, fade;

    if (*(unsigned char *)(object + 0x20) != 0 &&
        func_002B4038(*(short *)(object + 0xaa), state->handle) == 0)
        goto destroy;
    func_00300190(position, position);
    switch (*(unsigned char *)(object + 0x20)) {
    case 0:
        *(unsigned char *)(object + 0x20) = 1;
        state->angle = 0.0f;
        state->angular_velocity = 0.66666669f;
        state->alpha = 127;
        state->damage = 111;
        state->timer = 20;
        state->handle = func_L00_00329E90(object, 0, &created);
        D_L00_001B2BB4 = func_L00_0032A088(*(short *)(object + 0xaa), state->handle);
        D_L00_001B2BB8 = (char *)func_L00_003EEE20((int)(D_L00_001B2BB4 + 0x50));
        D_L00_001B2BBC = (int *)func_L00_003EEE20((int)(D_L00_001B2BB8 + 0xa000));
        for (i = 0; i < 144; ++i)
            D_L00_001B2BBC[i] = 0;
        record = D_L00_001B2BB8 + 0x9ffc;
        i = 319;
        do {
            *(int *)record = 0;
            --i;
            record -= 0x80;
        } while (i >= 0);
        *(int *)(D_L00_001B2BB4 + 0x30) = 0;
        qcopy(&initial_position, position);
        initial_position.v[2] += 1.0f;
        func_L00_003EFF58(object, 20, position, state, 0.16666667f);
        func_L00_003EF560(object, position);
        qcopy(&light_position, &initial_position);
        light_position.v[3] = 2.0f;
        if (func_00283DB8(&light_position, 100.0f) != -1) {
            D_L00_001B8DE0 = 0.44999999f;
            D_L00_001B8DE8 = 40;
            D_L00_001B8DEC = 0;
        }
    case 1:
        state->damage -= 5;
        if (state->damage < 0) state->damage = 0;
        state->angle += state->angular_velocity;
        progress = func_00283CE0(state->timer);
        progress /= func_00283CE0(20);
        count = func_00277F48(position, 0, object, 0, (1.0f - progress) * 6.0f + 0.001f);
        hit = D_L00_001C3280;
        while (count > 0) {
            if ((func_002AB1F0((unsigned char *)*hit) != 0 ||
                 (*(unsigned short *)(*hit + 0x34) & 0x4000) != 0) &&
                *hit != D_0018C0B0 && *(short *)(*hit + 0xaa) != 0xa5a) {
                func_00282CF0(&normal, (Vector *)(*hit + 0x10), position);
                func_00282F20(&normal, &normal, 1.0f);

                /* Retail normalizes this impulse before initialization. Preserve the sequence;
                 * native C execution is undefined and unverified. */
                func_00282F20(&request.impulse, &request.impulse, 1.0f);
                func_002A8C00((char *)&request, (int)object, 0x830000,
                             *(float *)(D_L00_00262570 + D_00139592 * 0xe0 + 0x74),
                             (Quad16 *)&normal);
                qcopy(&request.impulse, &normal);
                request.impulse.v[3] = 5627.9248f;
                request.enabled = 5;
                request.kind = 3;
                request.object_class = *(unsigned short *)(*hit + 0xaa);
                request.active = 1;
                func_002A8E20(*hit, &request);
                func_0032D758(*hit, 42, *(int *)(object + 0xb8));
            }
            --count;
            ++hit;
        }
        if (func_00282948(&state->timer) != 0) {
            *(unsigned char *)(object + 0x20) = 2;
            state->timer = 40;
        }
        break;
    case 2:
        state->angle += state->angular_velocity;
        fade = func_00283CE0(state->timer) * 0.025f;
        if (func_00282948(&state->timer) != 0) {
            if (state->alpha != 0) --state->alpha;
            else {
                state->alpha = 0;
                *(unsigned char *)(object + 0x20) = 6;
            }
        } else {
            state->alpha = func_00283CF0(func_00283CE0(127) * fade);
        }
        break;
    case 6:
        state->angle += state->angular_velocity;
        if (*(int *)(D_L00_001B2BB4 + 0x38) == 0) {
        destroy:
            func_L00_003EF550();
            func_0029F338(object);
            return;
        }
        break;
    }
    D_L00_001B0834 -= 0.04f;
    if (D_L00_001B0830 < -8.0f) D_L00_001B0830 += 8.0f;
    if (D_L00_001B0834 < -8.0f) D_L00_001B0834 += 8.0f;
    func_L00_003F00A0(object);
    func_L00_002E6EF8(func_L00_003EFA00, object);
}
