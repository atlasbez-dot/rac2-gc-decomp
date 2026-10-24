/* Nonmatching: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-barrier. us: func_L00_003918C8: 0 of 27 places match (src/levels/shared/L00_003918C8.c); us2: absent; pal: absent. Manual reconstruction3100/3172 frame0x130 versus0x140. Full48-byte aligned damage record,128-byte collision result,16-byte vectors and complete constructorstacktail retained. 002761F8fiveGPR->bool,00277F48fourGPR+float->count,002A89A8point/int/float->F0 verified. Historical MMI claim superseded: ordinaryC compiles the body. Remaining stack/register/branch scheduling and identity binding differences; reopen with original source/local lifetime evidence. */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef union { Quad quad; float f[4]; } Vector;
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
    int unknown00[6];
    char *hit;
    int mesh;
    Vector position, unknown30, normal, edgeStart, edgeEnd, tail;
} CollisionResult;
extern char D_00189E20[] NOT_SDA, D_00138180[] NOT_SDA, D_00188660[] NOT_SDA;
extern int D_L00_001B1A4C, D_L00_001B1BE8, D_L00_001ADB2C;
extern int D_L00_001B1994 __attribute__((sda)), D_L00_001A8FF0 __attribute__((sda)), D_001A7428 __attribute__((sda));
extern float D_L00_001AF0E0 __attribute__((sda)), D_L00_001AF0E4 __attribute__((sda)), D_L00_001AF0E8 __attribute__((sda));
extern float D_L00_001AF0EC __attribute__((sda)), D_L00_001AF0F0 __attribute__((sda));
extern CollisionResult D_L00_001BF200;
extern float D_L00_001B8FF0[4][4];
extern u8 D_00139576;
extern char D_L00_00262570[][0xE0];
extern int D_L00_001C3280[];
extern void func_L00_002F46C8(void), func_002B0CE0(int, void *, int);
extern void func_L00_00391310(char *, char *), func_L00_00390F28(char *, int), func_L00_00391398(char *, char *);
extern void func_L00_00428000(char *, char *);
extern int func_00283CF0(float), func_002E5F40(int, int);
extern float func_00282C48(float), func_00283BE0(float, float), func_002A89A8(void *, int, float), func_002AA2E8(float *, float, float), func_00283248(float, float);
extern void func_002AB668(void *, int, float), func_002ACDE8(void *, void *, void *), func_002FEE70(int, void *, void *), func_002A9288(char *, float);
extern void func_00282D30(void *, void *, float), func_002AF000(float *, float, float, float), func_00282CC0(void *, void *, void *), func_00300190(void *, void *);
extern void func_00283898(void *, int, float), func_00282F70(void *, void *, float);
extern int func_L00_00380058(char *), func_002761F8(void *, void *, int, char *, DamageRecord *);
extern void func_00282CF0(void *, void *, void *), func_00282F20(void *, void *, float), func_00283028(void *, void *, void *), func_002E59F8(int);
extern void func_002ABBB8(void *, void *, void *, float, float, int, int, int,
                         float, float, float, float, int, float, int, int, int, int, int);
extern int func_00277F48(void *, int, char *, int, float);
extern void func_002A9850(void *, Vector *, int *, int, int, int, int, int, float, float, float);
extern void func_002ACB48(float *, float), func_L00_003914E0(char *, int), func_002AFFD8(char *, char *, int), func_00282DD8(void *, void *, void *);
/* Updates the flying tether's steering, sweep collision, impact burst and attached pieces. */
void func_L00_003918C8(char *actor) {
    Vector previous, blast, blastNormal, velocity, contactEdge, scratch;
    DamageRecord damage;
    char *state = *(char **)(actor + 0x68), *player = D_00189E20;
    char *mount, *ignore, *sound;
    Vector *plane;
    float desiredSpeed, inputX, angle, height, bank;
    int mode, timer, playerHit = 0, i, hits;
    blast.quad = 0; blastNormal.quad = 0;
    blast.f[2] = 0.13333334f; blastNormal.f[2] = 1;
    D_L00_001B1A4C = 1; D_L00_001B1994 = 1;
    func_L00_002F46C8(); D_L00_001B1BE8 = 1; func_002B0CE0(6, 0, 1);
    timer = --*(int *)(state + 0x10);
    mount = *(char **)(player + 0x33C);
    if (timer < -99 || *(int *)(player + 0x2294) == 0x16 || *(int *)(player + 0x2294) == 0x39 || *(int *)(player + 0x2294) == 0x6F ||
        *(int *)(player + 0x229C) == 2 || *(int *)(player + 0x229C) == 4 || *(int *)(player + 0x229C) == 3 || *(int *)(player + 0x229C) > 12 ||
        *(int *)(player + 0x229C) == 7 || *(int *)(player + 0x229C) == 10 || *(int *)(player + 0x229C) == 16 || *(int *)(player + 0x229C) == 5 ||
        *(int *)(player + 0x2294) == 0x62 || !*(int *)(player + 0x340) ||
        (mount && (*(short *)(mount + 0xAA) == 0x13E || *(short *)(mount + 0xAA) == 0x46F)) || D_001A7428) goto release;
    if (timer < 0) {
        if (D_L00_001ADB2C) { func_L00_00391310(actor, state); *(short *)(player + 0x1E0) = 12; return; }
        if (*(char **)(state + 0x14)) func_L00_00428000(*(char **)(state + 0x14), actor);
        func_L00_00390F28(actor, 0); func_L00_00391398(actor, state); return;
    }
    desiredSpeed = D_L00_001AF0E4;
    if (*(u32 *)(D_00138180 + 0x1A0) & 0x40) desiredSpeed = D_L00_001AF0E8;
    *(float *)(state + 0x48) += (desiredSpeed * 0.016666668f - *(float *)(state + 0x48)) * D_L00_001AF0EC;
    *(float *)(state + 4) += (*(float *)(state + 0x48) - *(float *)(state + 4)) * D_L00_001AF0F0;
    if (*(float *)(state + 4) > D_L00_001AF0E8 * 0.016666668f) *(float *)(state + 4) = D_L00_001AF0E8 * 0.016666668f;
    i = func_00283CF0((*(float *)(state + 0x48) - (D_L00_001AF0E4 * 0.016666668f) /
                      (D_L00_001AF0E8 * 0.016666668f - D_L00_001AF0E4 * 0.016666668f)) * D_L00_001AF0E0);
    func_002E5F40(*(int *)(state + 0x2C), i);
    mode = D_L00_001A8FF0;
    if ((u32)(*(int *)(state + 0x10) - 1) < 0xBB2) {
        *(float *)(state + 0x18) += (*(float *)(player + 0x1FB0) - *(float *)(state + 0x18)) * 0.1f;
        *(float *)(state + 0x1C) += (*(float *)(player + 0x1FB4) - *(float *)(state + 0x1C)) * 0.1f;
        if (!mode) {
            *(float *)(actor + 0xF0) += (*(float *)(state + 0x18) - *(float *)(actor + 0xF0)) * 0.06f;
            angle = func_00283BE0(*(float *)(actor + 0xF4), *(float *)(state + 0x1C) * 0.012271847f);
            *(float *)(actor + 0xF4) = angle;
            if (angle >= 1.5707964f) *(float *)(actor + 0xF4) = 1.5697963f;
            else if (angle <= -1.5707964f) *(float *)(actor + 0xF4) = -1.5697963f;
            *(float *)(actor + 0xF8) = func_00283BE0(*(float *)(actor + 0xF8), *(float *)(state + 0x18) * 0.012271847f);
            func_002A9288(actor, 0.2f);
            mode = D_L00_001A8FF0;
        } else {
            *(float *)(actor + 0xF0) = (*(float *)(state + 0x18) - *(float *)(actor + 0xF0)) * 0.06f;
            *(float *)(actor + 0xF4) = *(float *)(state + 0x1C) * 0.012271847f;
            *(float *)(actor + 0xF8) = *(float *)(state + 0x18) * 0.012271847f;
            if (func_00282C48(*(float *)(actor + 0xF8)) > 0.00001f) {
                func_002AB668(&scratch, (int)(actor + 0xE0), -*(float *)(actor + 0xF8));
                func_002ACDE8(actor + 0xC0, actor + 0xC0, &scratch); func_002ACDE8(actor + 0xD0, actor + 0xD0, &scratch);
            }
            if (func_00282C48(*(float *)(actor + 0xF4)) > 0.00001f) {
                func_002AB668(&scratch, (int)(actor + 0xD0), -*(float *)(actor + 0xF4));
                func_002ACDE8(actor + 0xC0, actor + 0xC0, &scratch); func_002ACDE8(actor + 0xE0, actor + 0xE0, &scratch);
            }
            if (func_00282C48(*(float *)(actor + 0xF0)) > 0.00001f) {
                func_002AB668(&scratch, (int)(actor + 0xC0), *(float *)(actor + 0xF0));
                func_002ACDE8(actor + 0xD0, actor + 0xD0, &scratch); func_002ACDE8(actor + 0xE0, actor + 0xE0, &scratch);
            }
            func_002FEE70(*(int *)(state + 0x4C), actor + 0xC0, 0); mode = D_L00_001A8FF0;
        }
    }
    if (!mode) func_002AF000(velocity.f, *(float *)(state + 4), *(float *)(actor + 0xF8), -*(float *)(actor + 0xF4));
    else func_00282D30(&velocity, actor + 0xC0, *(float *)(state + 4));
    previous.quad = *(Quad *)(actor + 0x10);
    func_00282CC0(actor + 0x10, actor + 0x10, &velocity); func_00300190(actor + 0x10, actor + 0x10);
    if (*(int *)(state + 0x10) >= 0xB7D) {
        height = func_002A89A8(actor + 0x10, 0, 0.5f) + *(float *)(state + 0x44);
        if (*(float *)(actor + 0x18) < height && (!D_L00_001BF200.hit ||
            (*(char **)(D_L00_001BF200.hit + 0x24) && *(short *)(*(char **)(D_L00_001BF200.hit + 0x24) + 0x46) == 5))) {
            angle = func_00283248(*(float *)(state + 4), func_002AA2E8((float *)(actor + 0x18), height, 0.10000001f));
            if (angle > 0.026179943f) angle = 0.026179943f;
            *(float *)(actor + 0xF4) -= angle;
        }
    }
    if (*(float *)(actor + 0x10) < 4.5f || *(float *)(actor + 0x10) > 1018.5f || *(float *)(actor + 0x14) < 4.5f ||
        *(float *)(actor + 0x14) > 1018.5f || *(float *)(actor + 0x18) < 4.5f || *(float *)(actor + 0x18) > 1018.5f) goto release;
    func_L00_00391398(actor, state);
    inputX = func_00282C48(*(float *)(state + 0x18) * 0.33333334f);
    bank = -(*(float *)(state + 0x1C) * 0.5f + inputX + (*(float *)(state + 0x18) - *(float *)(actor + 0xF0)) * 1.1f) * 0.7f;
    func_00283898(*(char **)(state + 0x24) + 0x10, 1, bank);
    inputX = func_00282C48(*(float *)(state + 0x18) * 0.33333334f);
    bank = ((*(float *)(state + 0x18) - *(float *)(actor + 0xF0)) * 1.1f - (*(float *)(state + 0x1C) * 0.5f + inputX)) * 0.7f;
    func_00283898(*(char **)(state + 0x28) + 0x10, 1, bank);
    damage.direction.quad = velocity.quad; damage.owner = actor; damage.flags = 0x830000;
    damage.mode = 1; damage.power = *(float *)(D_L00_00262570[D_00139576] + 0x70);
    func_00282F70(&damage.direction, &damage.direction, 1);
    damage.objectClass = *(u16 *)(actor + 0xAA); damage.kind = 3; damage.response = 2;
    damage.direction.f[3] = 5627.925f; damage.direction.f[2] = 1;
    ignore = actor;
    if (*(int *)(state + 0x10) > 0xB90) ignore = *(char **)(player + 0x2290);
    if (func_L00_00380058(actor + 0x10)) {
        actor[0xBC] = 2;
        contactEdge.quad = *(Quad *)D_L00_001B8FF0;
        scratch.quad = 0; scratch.f[2] = 1; scratch.f[3] = 1; plane = &scratch;
        goto rebound;
    }
    if (func_002761F8(&previous, actor + 0x10, 0, ignore, &damage)) {
        if (D_L00_001BF200.hit) {
            actor[0xBC] = 2; playerHit = D_L00_001BF200.hit == *(char **)(player + 0x2290);
            *(Quad *)(actor + 0x10) = D_L00_001BF200.position.quad;
        } else if (D_L00_001BF200.mesh > 0) {
            actor[0xBC] = 1; *(Quad *)(actor + 0x10) = D_L00_001BF200.position.quad;
        } else goto after_rebound;
        func_00282CF0(&contactEdge, &D_L00_001BF200.edgeStart, &D_L00_001BF200.edgeEnd);
        func_00282F20(&contactEdge, &contactEdge, 1); plane = &D_L00_001BF200.normal;
rebound:
        func_00283028(&blast, &velocity, plane); func_00282F20(&blast, &blast, 0.033333335f);
        func_00282F20(&blastNormal, plane, 1);
        sound = D_00188660 + *(int *)(state + 0x2C) * 0x70;
        if (*(int *)(state + 0x2C) != -1 && *(char **)(sound + 0x88) == actor && (u8)sound[0x74]) func_002E59F8(*(int *)(state + 0x2C));
        *(int *)(state + 0x2C) = -1;
    } else if (!*(int *)(state + 0x10)) goto release;
after_rebound:
    if (*(int *)(state + 0x10) < 0xB7C && (*(u32 *)(D_00138180 + 0x1A4) & 0x20)) {
        actor[0xBC] = 1; sound = D_00188660 + *(int *)(state + 0x2C) * 0x70;
        if (*(int *)(state + 0x2C) != -1 && *(char **)(sound + 0x88) == actor && (u8)sound[0x74]) func_002E59F8(*(int *)(state + 0x2C));
        *(int *)(state + 0x2C) = -1;
    }
    if ((u8)actor[0xBC]) {
        if (!playerHit) {
            func_002ABBB8(actor, &blast, 0, 0, 0, 10, 3, 16, 4, 2, 0, 1, 1, 20, 1, 1, -1, 0, 0x810001);
            hits = func_00277F48(actor + 0x10, 16, actor, 0, 4);
            scratch.quad = *(Quad *)(actor + 0x10);
            func_002A9850(actor, &scratch, D_L00_001C3280, hits, 0, 0x830000, 3, 2,
                          *(float *)(D_L00_00262570[D_00139576] + 0x70), 1, 1);
        }
        *(u16 *)(actor + 0x34) |= 1; *(float *)(state + 4) = 0.02f;
        *(float *)(state + 0x18) *= 0.01f;
        *(int *)(state + 0x10) = *(int *)(state + 0x10) < 0xB9B ? -1 : -100;
        scratch.quad = *(Quad *)(actor + 0x10);
        for (i = 4; i >= 0; --i) {
            *(Quad *)(actor + 0x10) = scratch.quad; func_002ACB48((float *)(actor + 0x10), 1.5f); func_L00_003914E0(actor, 1);
            *(Quad *)(actor + 0x10) = scratch.quad;
        }
        velocity.f[0] = 0; actor[0xBC] = 0;
    }
    if (*(char **)(state + 0x14)) func_L00_00428000(*(char **)(state + 0x14), actor);
    if (!D_L00_001A8FF0) return;
    func_002AFFD8(actor + 0x10, actor + 0xE0, 1);
    func_00282DD8(&scratch, actor + 0xC0, actor + 0xE0); func_00282F20(actor + 0xD0, &scratch, 1);
    func_00282DD8(actor + 0xE0, actor + 0xD0, actor + 0xC0);
    *(float *)(actor + 0xCC) = 0; *(float *)(actor + 0xEC) = 0; *(float *)(actor + 0xDC) = 0;
    return;
release:
    func_L00_00391310(actor, state);
}

/* Historical screening only; superseded by the measured reconstruction above. */
/* MMI (SPECIAL2) instruction: no C spelling. 3172 bytes, level
   00_aranos_tutorial. Retail at 0x003918C8 carries the SPECIAL2 words
   0x700014A9, 0x700024A9 (+0x0004, +0x0810) - opcode 0x1C, which rabbitizer
   prints as `INVALID`; it is the MMI family (pcpyld and its relatives) the
   sixth wave recorded and that no C spelling reaches. This cc1 emits
   `lq`/`sq` for a `mode(TI)` local and `ldl`/`ldr`/`sdl`/`sdr` for a struct
   assignment, never the packed copy. ASM_FUNC candidate, as for the rest of
   the family. */
