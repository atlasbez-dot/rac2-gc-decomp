/*
 * Complete manual reconstruction retained as nonmatching; no exact-C, linked-build
 * or runtime credit. Fresh worker checks on 2026-10-25, base dcfcd1f90746f3fbba715825d25bf19e88bf875c.
 * Tested profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -g
 * Coverage: US: 0/1 placements; US2: 0/1 placements; PAL: absent from both catalogues.
 * US compiled size: 1296 bytes; retail: 1304 bytes.
 * Remaining difference: 1296 bytes versus 1304. The complete 64-byte chain record and dynamics tail are retained. Object, position and velocity pointers still have different saved-register assignments; division delay-slot padding and later scheduling differ.
 * Reopen only with: Actual allocator evidence identifying a semantic particle/dynamics lifetime or access form that accounts for the retail saved-register allocation and the three DIV.S padding sites.
 * Earlier complete variants and command logs are preserved privately.
 */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef union { Quad quad; float f[4]; } Vector;
typedef struct ChainParticle ChainParticle;
typedef struct {
    Vector velocity;
    ChainParticle *previous, *next;
    u32 unknown38;
    short collided;
    u16 flags;
} ChainParticleDynamics;
struct ChainParticle {
    u32 unknown00, color;
    s8 rotation;
    u8 unknown09[7];
    Vector position;
    ChainParticleDynamics dynamics;
};
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
    ChainParticleDynamics *dynamics=&particle->dynamics;
    Vector *velocity=&dynamics->velocity;
    Vector *position=&particle->position;
    if ((short)dynamics->flags != 0xFF) {
        if (dynamics->flags & 1) qcopy(&point,position);
        else {
            node = dynamics->next;
            link = node ? (char *)&node->dynamics.velocity : 0;
            distance = 2; damping = 0.15f;
            func_00282C88(&force.quad);
            if (!dynamics->collided && node && !(*(u64 *)(link + 0x18) & 0x1FFFF00000000ULL)) {
                do {
                    step = distance * distance;
                    func_00282CF0(&point, &node->position, position);
                    distance += 1; damping *= 0.999f;
                    func_00282F20(&point, &point, 0.2f / step);
                    func_00282CC0(&force, &force, &point);
                    node = *(ChainParticle **)(link + 0x14);
                    if (node) link = (char *)&node->dynamics.velocity;
                    else break;
                } while (!(*(u64 *)(link + 0x18) & 0x1FFFF00000000ULL));
            }
            damping = (0.15f - damping) + 1.07f;
            if (!link || !*(short *)(link + 0x1C)) func_00282CC0(velocity, velocity, &force);
            else func_00282D30(velocity, velocity, 0.5f);
            if (!dynamics->next) func_00282D30(velocity, velocity, 0.97f);
            else func_00282D30(velocity, velocity, damping);
            velocity->f[2] -= 0.02f;
            func_00282CC0(&point, position, velocity);
        }
        if (dynamics->previous) {
            func_00282CF0(&force, &point, &dynamics->previous->position);
            if (func_00282C48(func_00282DF0(&force) - 0.15f) > 0.1f) {
                func_00282F20(&force, &force, 0.15f);
                func_00282CC0(&point, &force, &dynamics->previous->position);
            }
            if (!func_00277258(&point, 0, 0, 0.15f)) dynamics->collided = 0;
            else {
                if (!dynamics->collided) qcopy(&point,&D_L02_001C0970);
                else qcopy(&point,position);
                dynamics->collided = 1;
            }
            if (!dynamics->collided) {
                func_00282CF0(&delta, &point, position);
                func_00282CC0(velocity, velocity, &delta);
                func_00282D30(velocity, velocity, 0.5f);
            } else {
                func_00283028(velocity, velocity, &D_L02_001C0980);
                func_00282D30(velocity, velocity, 0.95f);
            }
            func_00282CF0(&delta, &point, position);
            func_00282CC0(velocity, velocity, &delta);
            func_00282D30(velocity, velocity, 0.5f);
        }
        qcopy(position,&point);
        if (dynamics->flags & 2) {
            alpha = (particle->color >> 24) - 2;
            if (alpha > 0) particle->color = (particle->color & 0xFFFFFF) | (alpha << 24);
            else if (!dynamics->next) {
                if (dynamics->previous) dynamics->previous->dynamics.next = 0;
                func_002B9180(particle); return;
            }
        }
    }
    attachment = dynamics->previous;
    if (attachment) {
        func_00282CF0(&point, &attachment->position, &D_L02_001BA500);
        func_002830C0(&point, &point, D_L02_001BA480);
        func_00282D30(&point, &point, 1.0f / point.f[3]);
        func_00282CF0(&delta, position, &D_L02_001BA500);
        func_002830C0(&delta, &delta, D_L02_001BA480);
        func_00282D30(&delta, &delta, 1.0f / delta.f[3]);
        func_00282CF0(&point, &point, &delta);
        particle->rotation = func_00283CF0(func_00283248(point.f[0], point.f[1]) * 40.743664f) - 32;
    }
}
