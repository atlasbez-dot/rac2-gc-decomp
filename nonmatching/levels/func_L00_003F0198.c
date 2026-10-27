/* Bounded manual reconstruction, 2026-10-25; not linked.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -g.
 * 1248/1252 bytes; us: 0/27 placements; us2: 0/27 placements; pal: absent from catalogue.
 * Truthful 128-byte pool records retain all three initialization variants, bounds and rollback
 * stores. Scalar zero stores lose the retail floating zero lifetime; frame0x70 differs from retail
 * 0x80.
 * Reopen with concrete scalar zero-store and allocator lifetime evidence. Do not manufacture a
 * floating dependency, volatile store or extra vector.
 * Prior complete variants and diagnostic dumps are preserved privately.
 * No candidate or linked-build credit is claimed.
 */
#include "common.h"

typedef int PoolWord128 __attribute__((mode(TI)));
typedef union { PoolWord128 word; float values[4]; } PoolVector;
typedef struct {
    PoolVector position, velocity;
    float gravity, strength, randomA, randomB, angularSpeed, phase;
    float x, y, z, width, height, scale;
    int color, a, b, lifetime, maximumLife, colorA, colorB, shade;
    int mode, reserved, kind;
    char *owner;
} PoolRecord;
extern PoolRecord *D_L00_001B2BB8 __attribute__((sda));
extern int func_002A7820(int, int);
extern int func_001163B0(void);
extern void func_002ACEC0(void *, void *, void *, float);
extern float func_002A7878(float, float);
extern float func_002A7940(void);
extern float func_002A78D8(float, float);
extern void func_00282F20(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);

PoolRecord *func_L00_003F0198(char *owner, int kind, PoolVector *position, float angle) {
    PoolVector direction, offset;
    PoolRecord *slot;
    int i, oldCount, random;
    float scale;
    float zero = 0.0f;
    for (i = 0; i < 320; i++) {
        if (D_L00_001B2BB8[i].owner)
            continue;
        if (kind == 0) {
            oldCount = *(int *)(owner + 0x40);
            *(int *)(owner + 0x40) = oldCount + 1;
            if (oldCount + 1 == 150) {
                *(int *)(owner + 0x40) = oldCount;
                return 0;
            }
        } else if (kind == 1) {
            oldCount = *(int *)(owner + 0x44);
            *(int *)(owner + 0x44) = oldCount + 1;
            if (oldCount + 1 == 150) {
                *(int *)(owner + 0x44) = oldCount;
                return 0;
            }
        }
        slot = &D_L00_001B2BB8[i];
        slot->owner = owner;
        (*(int *)(owner + 0x38))++;
        random = func_002A7820(95, 127);
        slot->lifetime = random;
        slot->maximumLife = random;
        slot->mode = func_001163B0() % 2 + 1;
        slot->kind = kind;
        if (kind == 0) {
            func_002ACEC0(&slot->velocity, owner + 0x10, owner, angle);
            slot->z = zero;
            slot->x = zero;
            slot->y = zero;
            random = func_002A7820(0, 3);
            slot->shade = (random << 16) + (random << 8) + random;
            scale = func_002A7878(0.15f, 1.25f);
            slot->height = scale * 0.125f;
            slot->width = scale * 0.125f;
            scale = func_002A7878(0.5f, 1.8f);
            slot->b = 90;
            slot->a = 90;
            slot->scale = scale * 0.7f;
            slot->strength = 0.075f;
            func_00282F20(&direction, slot->owner, 0.1f);
            func_00282CC0(&slot->position, slot->owner + 0x20, &direction);
            func_00282F20(&offset, &slot->velocity, 0.75f);
            func_00282CC0(&slot->position, &offset, &slot->position);
            slot->angularSpeed = func_002A78D8(0.05235988646745682f, 0.10471977293491364f);
            slot->kind = 2;
            slot->mode = 2;
        } else if (kind == 1) {
            func_002ACEC0(&slot->velocity, owner + 0x10, owner, func_002A7940());
            slot->x = zero;
            slot->y = zero;
            slot->z = zero;
            random = func_002A7820(0, 13);
            slot->shade = (random << 16) + (random << 8) + random;
            scale = func_002A7878(0.25f, 0.5f);
            slot->height = scale;
            slot->width = scale;
            slot->scale = func_002A7878(1.0f, 1.5f);
            slot->strength = func_002A7878(0.06666667f, 0.083333336f);
            random = func_002A7820(100, 120);
            slot->b = random;
            slot->a = random;
            qcopy(&slot->position, position);
            slot->mode = 2;
            slot->angularSpeed = zero;
        } else if (kind == 2) {
            func_002ACEC0(&slot->velocity, owner + 0x10, owner, angle);
            slot->z = zero;
            slot->x = zero;
            slot->y = zero;
            random = func_002A7820(0, 3);
            slot->shade = (random << 16) + (random << 8) + random;
            scale = func_002A7878(0.15f, 1.25f);
            slot->height = scale * 0.125f;
            slot->width = scale * 0.125f;
            scale = func_002A7878(0.5f, 1.8f);
            slot->b = 90;
            slot->a = 90;
            slot->scale = scale * 0.7f;
            slot->strength = 0.20833334f;
            func_00282F20(&direction, slot->owner, 0.1f);
            func_00282CC0(&slot->position, slot->owner + 0x20, &direction);
            func_00282F20(&offset, &slot->velocity, 0.75f);
            func_00282CC0(&slot->position, &offset, &slot->position);
            slot->angularSpeed = func_002A78D8(0.05235988646745682f, 0.10471977293491364f);
            slot->mode = 2;
        }
        slot->colorB = 0x103080;
        slot->colorA = 0x103080;
        slot->gravity = 0.00055555557f;
        scale = func_002A78D8(0.3141593f, 0.35633811354637146f);
        slot->randomB = scale;
        slot->randomA = scale;
        slot->phase = func_002A7940();
        slot->reserved = 0;
        return slot;
    }
    return 0;
}
