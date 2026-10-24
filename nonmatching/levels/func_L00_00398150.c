/* Nonmatching: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier. us: func_L00_00398150: 0 of 27 places match (src/levels/shared/L00_00398150.c); us2: func_L00_00398150: 0 of 27 places match (src/levels/shared/L00_00398150.c); pal: absent. Two manual trials; final1724/1728 frame0x200 versus0x1B0. Collision query is96bytes with pointer/32-bit fields and3vectors; matrices48/64bytes are truthful. 002FE9D0 takes query pointer retained inA0, returns int; 002AD0E0 actually returns boolean despite legacy void declaration. Full002ABBB8 twelveGPR/sevenFP and four stacked arguments retained. Reopen on original lexical storage lifetimes. */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef union { Quad quad; float f[4]; } Vector;
typedef struct {
    Vector previous, position, velocity;
    char *owner;
    int *ignore;
    int ignoreCount;
    float radius, friction, bounce;
    int flags, mask, response, surface, gravity;
    float maxTurn;
} CollisionQuery;
extern int D_L00_001A8FF4;
extern Vector D_L00_001BF240;
extern u16 D_L00_001B1FF0[];
extern void func_002A7470(char *, int, int, int), func_002FE8D8(void *, float *);
extern void func_00282F20(void *, void *, float), func_00282DD8(void *, void *, void *);
extern float func_00282DB0(void *, void *), func_00283198(float), func_00283180(float);
extern void func_00282D30(void *, void *, float), func_00283958(void *, void *), func_00283738(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *), func_002FEE70(int, void *, void *), func_002FE880(void *, float *, float);
extern void func_00300190(void *, void *), func_00300248(int, int);
extern int func_002FE9D0(CollisionQuery *), func_00300540(int);
extern void func_002ACB48(float *, float);
extern void func_002ABBB8(void *, void *, void *, float, float, int, int, int,
                         float, float, float, float, int, float, int, int, int, int, int);
extern float func_002A7878(float, float);
extern void func_0030E8A8(char *), func_0030E700(char *), func_002FEE50(int), func_002ACAD0(int, u16 *), func_0029F338(void *);
extern void func_00283658(void *, void *), func_002AB6D8(float *, float *), func_002833F0(void *, void *);
/* Retail returns a boolean, despite a legacy caller declaring this helper void. */
extern int func_002AD0E0(int, int, void *, void *, void *, void *);
/* Steers a moving projectile, resolves its collision, then follows a struck actor. */
void func_L00_00398150(char *actor) {
    char *state = *(char **)(actor + 0x68);
    ++*(int *)(state + 0x3C);
    switch ((u8)actor[0x20]) {
    case 0:
        actor[0x20] = 1;
        if ((u8)actor[0x43]) func_002A7470(actor, 0, 0, 0);
        *(int *)(actor + 0x98) = 0;
        /* fall through */
    case 1: {
        Vector oldPosition, desired, forward, quaternion, axis, scatter;
        Vector rotation[3];
        CollisionQuery query;
        int ignore[2], collision;
        char *hit;
        float halfAngle;
        short type;
        func_002FE8D8(actor + 0x10, desired.f);
        func_00282F20(&forward, actor + 0xE0, 1.0f);
        func_00282DD8(&axis, &forward, &desired);
        halfAngle = func_00282DB0(&forward, &desired) * 0.5f;
        func_00282D30(&quaternion, &axis, func_00283198(halfAngle));
        quaternion.f[3] = func_00283180(halfAngle);
        func_00283958(&quaternion, rotation);
        func_00283738(actor + 0xC0, rotation, actor + 0xC0);
        oldPosition.quad = *(Quad *)(actor + 0x10);
        func_00282CC0(actor + 0x10, actor + 0x10, state + 0x10);
        func_002FEE70(*(int *)(state + 0x20), state + 0x10, 0);
        func_002FE880(actor + 0x10, (float *)(state + 0x10), 0.0030555557f);
        func_00300190(actor + 0x10, actor + 0x10);
        func_00300248((int)(state + 0x10), (int)(state + 0x10));
        ignore[0] = 0; ignore[1] = 0x232;
        query.previous.quad = oldPosition.quad;
        query.position.quad = *(Quad *)(actor + 0x10);
        query.velocity.quad = *(Quad *)(state + 0x10);
        query.owner = actor; query.ignore = ignore; query.ignoreCount = 2;
        query.radius = 0.2f; query.friction = 0.45f; query.bounce = 0.5555556f;
        query.flags = 0; query.mask = 0; query.gravity = 1; query.response = 1; query.maxTurn = 0.174f;
        collision = func_002FE9D0(&query);
        *(Quad *)(actor + 0x10) = query.position.quad;
        *(Quad *)(state + 0x10) = query.velocity.quad;
        if (D_L00_001A8FF4 && *(float *)(actor + 0x18) < 462.43f) {
            func_002ACB48(scatter.f, 0.5f);
            func_002ABBB8(actor, &scatter, 0, 0.0f, 0.0f, 0, 0, 0,
                         4.0f, 3.0f, 9.0f, 1.0f, 2, 12.0f, 1, 1, -1, 0, 0x810001);
            actor[0x20] = 6;
        }
        if (collision != 2) break;
        hit = query.owner;
        if (hit && ((type = *(short *)(hit + 0xAA)) == 0xCB || type == 0x1366 || type == 0x1367)) {
            func_00282D30(state + 0x10, state + 0x10, 1.1f);
        } else {
            if (hit) *(char **)(state + 0x38) = hit;
            func_00282D30(&desired, &D_L00_001BF240, 0.0009765625f);
            func_00282F20(&desired, &desired, 1);
            func_00282F20(&forward, actor + 0xE0, 1);
            func_00282DD8(&axis, &forward, &desired);
            halfAngle = func_00282DB0(&forward, &desired) * 0.5f;
            func_00282D30(&quaternion, &axis, func_00283198(halfAngle));
            quaternion.f[3] = func_00283180(halfAngle);
            func_00283958(&quaternion, rotation);
            func_00283738(actor + 0xC0, rotation, actor + 0xC0);
            actor[0x20] = collision;
            if ((u8)actor[0x43] != 1) func_002A7470(actor, 1, 0, 10);
            *(int *)(actor + 0x98) = *(int *)(*(char **)(actor + 0x24) + 0x10);
        }
        if (func_00300540(query.surface)) {
            func_002ACB48(scatter.f, 0.5f);
            func_002ABBB8(actor, &scatter, 0, 0.0f, 0.0f, 0, 0, 0,
                         4.0f, 3.0f, 9.0f, 1.0f, 2, 12.0f, 1, 1, -1, 0, 0x810001);
            actor[0x20] = 6;
        }
        break;
    }
    case 2: actor[0x20] = 3; break;
    case 3:
        if ((u8)actor[0x60] & 2) {
            if ((u8)actor[0x43] != 2) func_002A7470(actor, 2, 0, 10);
            *(float *)(actor + 0x48) = func_002A7878(0.7f, 1.05f);
        }
        func_0030E8A8(actor); func_0030E700(actor);
        break;
    case 4:
        *(float *)(actor + 0x2C) -= *(float *)(actor + 0x2C) * 0.02f;
        if (*(float *)(actor + 0x2C) < *(float *)(*(char **)(actor + 0x24) + 0x24) * 0.1f) actor[0x20] = 6;
        break;
    case 5: actor[0x20] = 4; break;
    case 6:
        func_002FEE50(*(int *)(state + 0x20));
        if (!*(int *)(state + 0x40)) func_002ACAD0((int)actor, D_L00_001B1FF0);
        func_0029F338(actor);
        return;
    }
    if ((u32)((u8)actor[0x20] - 2) < 3 && *(char **)(state + 0x38)) {
        Vector transform[4], angles, adjusted;
        func_00283658(transform, actor + 0xC0);
        func_002AB6D8((float *)transform, angles.f);
        if (func_002AD0E0((int)actor, *(int *)(state + 0x38), actor + 0x10, &angles, actor + 0x10, &adjusted))
            func_002833F0(actor + 0xC0, &adjusted);
    }
}

/* Historical screening only; superseded by the measured reconstruction above. */
/* func_L00_00398150 - 1728 bytes, 27 place(s), level 00_aranos_tutorial,
   retail at 0x00398150. Screened with tools/w10_screen.py: 44 call(s)
   [func_002A7470@003981E8, func_002FE8D8@00398200, func_00282F20@0039822C,
   func_00282DD8@0039824C, func_00282DB0@00398258, func_00283198@00398268,
   func_00282D30@00398278, func_00283180@00398280, func_00283958@00398294,
   func_00283738@003982A4, func_00282CC0@003982C8, func_002FEE70@003982DC,
   func_002FE880@003982F4, func_00300190@00398300, func_00300248@0039830C,
   func_002FE9D0@003983A8, func_002ACB48@00398404, func_002ABBB8@00398474,
   func_00282D30@003984D8, func_00282F20@003984E8, func_00282F20@003984F8,
   func_00282DD8@00398508, func_00282DB0@00398514, func_00283198@0039852C,
   func_00282D30@0039853C, func_00283180@00398544, func_00283958@00398554,
   func_00283738@00398564, func_002A7470@0039858C, func_00282D30@003985B4,
   func_00300540@003985BC, func_002ACB48@003985D4, func_002ABBB8@00398648,
   func_002A7470@00398688, func_002A7878@003986A8, func_0030E8A8@003986B4,
   func_0030E700@003986BC, func_002FEE50@00398728, func_002ACAD0@00398748,
   func_0029F338@00398750, func_00283658@00398788, func_002AB6D8@00398798,
   func_002AD0E0@003987BC, func_002833F0@003987CC]; data addresses
   materialised [0x2a0000, 0x3b480000, 0x3e4c0000, 0x3ee60000, 0x3f0e0000,
   0x3e320000, 0x1b0000, 0x43e70000, 0x810000, 0x1c0000, 0x3f8c0000,
   0x810000, 0x3f330000, 0x3f860000, 0x3ca30000, 0x3dcc0000, 0x1b0000];
   float constants [0x3f800000, 0x3f000000, 0x40800000, 0x40400000,
   0x41100000, 0x41400000, 0x3a800000, 0x3f800000, 0x3f000000, 0x3f000000,
   0x40800000, 0x40400000, 0x41100000, 0x3f800000, 0x41400000]; $gp-relative
   small data: no   saves: -; callee-saved registers saved [-]; words plain
   C cannot emit [LQ/SQ 7A220000@0x0160, LQ/SQ 7E420000@0x0164, LQ/SQ
   7A420000@0x01d4, LQ/SQ 7C820000@0x01d8, LQ/SQ 7A220000@0x01e0, LQ/SQ
   7E620000@0x01e4, LQ/SQ 7A020000@0x01ec, LQ/SQ 7E420000@0x01f0, LQ/SQ
   7A620000@0x0264, LQ/SQ 7E220000@0x0268, LQ/SQ 7A420000@0x026c, LQ/SQ
   7E020000@0x0270]. Head: addiu $sp, $sp, -0x1B0 ; sd $fp, 0x180($sp) ; sd
   $s0, 0x140($sp) ; daddu $fp, $a0, $zero ; sd $s1, 0x148($sp) ; sd $s2,
   0x150($sp). Not matched in this wave: the 128-bit copy needs an `lq`/`sq`
   pair; plain C reaches it only through a `mode(TI)` local, and this cc1
   folds the destination offset into the `sq` where retail materialises the
   pointer first. What would unblock it: the exact source expression tree,
   so this cc1 picks the same registers in the same order. */
