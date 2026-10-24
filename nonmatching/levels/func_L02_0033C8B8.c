/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Prior worker coverage: US 0/1; US2 0/1; PAL absent from catalogue.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/* Nonmatching: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier. us: func_L02_0033C8B8: 0 of 1 places match (src/levels/02_maktar_nebula/L02_0033C8B8.c); us2: func_L02_0033C8B8: 0 of 1 places match (src/levels/02_maktar_nebula/L02_0033C8B8.c); pal: absent. Two manual forms; final1304/1304 frame0xB0, firstdiff+8 saved registers. True64-byte linked particle, full64-bit packed neighborflag checks,16-byte vectors and64-byte camera matrix. Force-square calculation and damping coefficient lifetime align retail intent; remaining register allocation/branch scheduling. Reopen on original partial-record/address lifetime evidence. */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef union { Quad quad; float f[4]; } Vector;
typedef struct ChainParticle {
    u32 unknown00, color;
    s8 rotation;
    u8 unknown09[7];
    Vector position, velocity;
    struct ChainParticle *previous, *next;
    u32 unknown38;
    short collided;
    u16 flags;
} ChainParticle;
extern Vector D_L02_001C0970, D_L02_001C0980, D_L02_001BA500;
extern float D_L02_001BA480[4][4];
extern void func_00282C88(Quad *), func_00282CF0(void *, void *, void *), func_00282F20(void *, void *, float), func_00282CC0(void *, void *, void *);
extern void func_00282D30(void *, void *, float), func_00283028(void *, void *, void *), func_002830C0(void *, void *, void *), func_002B9180(void *);
extern float func_00282DF0(void *), func_00282C48(float), func_00283248(float, float);
extern int func_00277258(void *, int, void *, float), func_00283CF0(float);
/* Integrates a linked particle chain with collision response and projected facing. */
void func_L02_0033C8B8(ChainParticle *particle) {
    Vector point, delta, force;
    ChainParticle *node, *attachment;
    char *link;
    float distance, damping, step;
    int alpha;
    if ((short)particle->flags != 0xFF) {
        if (particle->flags & 1) point.quad = particle->position.quad;
        else {
            node = particle->next;
            link = node ? (char *)&node->velocity : 0;
            distance = 2; damping = 0.15f;
            func_00282C88(&force.quad);
            if (!particle->collided && node && !(*(u64 *)(link + 0x18) & 0x1FFFF00000000ULL)) {
                do {
                    step = distance * distance;
                    func_00282CF0(&point, &node->position, &particle->position);
                    distance += 1; damping *= 0.999f;
                    func_00282F20(&point, &point, 0.2f / step);
                    func_00282CC0(&force, &force, &point);
                    node = *(ChainParticle **)(link + 0x14);
                    if (node) link = (char *)&node->velocity;
                    else break;
                } while (!(*(u64 *)(link + 0x18) & 0x1FFFF00000000ULL));
            }
            damping = (0.15f - damping) + 1.07f;
            if (!link || !*(short *)(link + 0x1C)) func_00282CC0(&particle->velocity, &particle->velocity, &force);
            else func_00282D30(&particle->velocity, &particle->velocity, 0.5f);
            if (!particle->next) func_00282D30(&particle->velocity, &particle->velocity, 0.97f);
            else func_00282D30(&particle->velocity, &particle->velocity, damping);
            particle->velocity.f[2] -= 0.02f;
            func_00282CC0(&point, &particle->position, &particle->velocity);
        }
        if (particle->previous) {
            func_00282CF0(&force, &point, &particle->previous->position);
            if (func_00282C48(func_00282DF0(&force) - 0.15f) > 0.1f) {
                func_00282F20(&force, &force, 0.15f);
                func_00282CC0(&point, &force, &particle->previous->position);
            }
            if (!func_00277258(&point, 0, 0, 0.15f)) particle->collided = 0;
            else {
                if (!particle->collided) point.quad = D_L02_001C0970.quad;
                else point.quad = particle->position.quad;
                particle->collided = 1;
            }
            if (!particle->collided) {
                func_00282CF0(&delta, &point, &particle->position);
                func_00282CC0(&particle->velocity, &particle->velocity, &delta);
                func_00282D30(&particle->velocity, &particle->velocity, 0.5f);
            } else {
                func_00283028(&particle->velocity, &particle->velocity, &D_L02_001C0980);
                func_00282D30(&particle->velocity, &particle->velocity, 0.95f);
            }
            func_00282CF0(&delta, &point, &particle->position);
            func_00282CC0(&particle->velocity, &particle->velocity, &delta);
            func_00282D30(&particle->velocity, &particle->velocity, 0.5f);
        }
        particle->position.quad = point.quad;
        if (particle->flags & 2) {
            alpha = (particle->color >> 24) - 2;
            if (alpha > 0) particle->color = (particle->color & 0xFFFFFF) | (alpha << 24);
            else if (!particle->next) {
                if (particle->previous) particle->previous->next = 0;
                func_002B9180(particle); return;
            }
        }
    }
    attachment = particle->previous;
    if (attachment) {
        func_00282CF0(&point, &attachment->position, &D_L02_001BA500);
        func_002830C0(&point, &point, D_L02_001BA480);
        func_00282D30(&point, &point, 1.0f / point.f[3]);
        func_00282CF0(&delta, &particle->position, &D_L02_001BA500);
        func_002830C0(&delta, &delta, D_L02_001BA480);
        func_00282D30(&delta, &delta, 1.0f / delta.f[3]);
        func_00282CF0(&point, &point, &delta);
        particle->rotation = func_00283CF0(func_00283248(point.f[0], point.f[1]) * 40.743664f) - 32;
    }
}

/* Historical screening only; superseded by the measured reconstruction above. */
