/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-por.
 * Reported final C / retail: 764 / 776 bytes; size equality is not a match.
 * us: 0/1 placements; 764/776 bytes.
 * us2: 0/1 placements; 764/776 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: Zero-store scheduling, packet registers, collision-base rematerialization.
 * Reopening condition: Independent matching clear/address-lifetime witness.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Retained plain C reconstruction, 23 October 2026; not matched or linked.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-por
 * USA final: 764/776 bytes; zero placements match.
 * Zero-store scheduling, packet store/register order and collision-base lifetime.
 * Reopen on independently supported source/address-lifetime evidence.
 */
typedef unsigned char u8;
typedef int Quadword __attribute__((mode(TI)));
typedef union { Quadword q; float f[4]; } Vector;
typedef struct {
    Vector velocity;
    u8 *actor;
    int flags;
    u8 kind;
    u8 enabled;
    short id;
    float power;
    int mode;
} CollisionRequest;

extern u8 D_00139574;
extern u8 *D_0018C0B0;
extern void *D_L19_001AC790;
typedef struct { u8 prefix[0x70]; float power; u8 tail[0x6c]; } WeaponRecord;
extern WeaponRecord D_L19_00265870[];
typedef struct { u8 prefix[0x18]; u8 *hit; int count; Vector point; u8 gap[0x10]; Vector normal; } Collision;
extern Collision D_L19_001BFE80;
extern void func_00282CC0(void *, void *, void *);
extern void func_00282D30(void *, void *, float);
extern void func_00282F20(void *, void *, float);
extern void func_00282F70(void *, void *, float);
extern void func_00283028(void *, void *, void *);
extern int func_00282948(int *);
extern int func_002761F8(void *, void *, int, void *, CollisionRequest *);
extern void func_002AFFD8(char *, char *, int);
extern void func_L00_0038F3D8(char *);
extern void func_002FEE50(int);
extern void func_L00_0038DE70(void *, void *, void *);
extern void func_L00_0038E880(void *, void *, void *);

void func_L19_0038B998(u8 *actor)
{
    Vector impulse = {0};
    Vector normal;
    Vector previous;
    Vector direction;
    CollisionRequest request;
    u8 *state;
    Vector *position;
    u8 *hit;
    state = *(u8 **)(actor + 0x68);
    position = (Vector *)(actor + 0x10);
    normal.q = 0;
    impulse.f[2] = 1.0f / 30.0f;
    normal.f[2] = 1.0f;
    previous.q = position->q;
    func_00282CC0(position, position, state);
    func_002AFFD8((char *)position, (char *)&direction, 0);
    func_00282D30(&direction, &direction, 0.0003055556f);
    func_L00_0038F3D8((char *)actor);
    request.actor = actor;
    request.flags = 0x830000;
    if (*(int *)(state + 0x18) < 0x122)
        request.flags = 0x830001;
    request.mode = 1;
    request.power = D_L19_00265870[D_00139574].power;
    request.velocity.q = *(Quadword *)state;
    func_00282F70(&request.velocity, &request.velocity, 1.0f);
    request.kind = 2;
    request.velocity.f[3] = 5627.925f;
    request.id = *(short *)(actor + 0xaa);
    request.velocity.f[2] = 1.0f;
    request.enabled = 1;
    *(int *)(state + 0x14) += 1;
    if (func_002761F8(&previous, position, 0x10, actor, &request)) {
        hit = D_L19_001BFE80.hit;
        if (hit) {
            if ((hit == D_0018C0B0 || *(short *)(hit + 0xaa) == 0xc0) &&
                    *(int *)(state + 0x18) >= 0x122)
                goto finish;
            if (*(void **)(hit + 0x64) == D_L19_001AC790 && *(short *)(hit + 0xaa) != 0x336)
                goto finish;
            actor[0xbc] = 1;
            *(Quadword *)(actor + 0x10) = D_L19_001BFE80.point.q;
            func_00283028(&impulse, state, &D_L19_001BFE80.normal);
            func_00282F20(&impulse, &impulse, 1.0f / 30.0f);
        } else {
            if (D_L19_001BFE80.count <= 0)
                goto finish;
            actor[0xbc] = 1;
            position->q = D_L19_001BFE80.point.q;
            func_00283028(&impulse, state, &D_L19_001BFE80.normal);
            func_00282F20(&impulse, &impulse, 1.0f / 30.0f);
        }
        func_00282F20(&normal, &D_L19_001BFE80.normal, 1.0f);
    } else if (func_00282948((int *)(state + 0x18))) {
        actor[0xbc] = 1;
        func_00282CC0(&impulse, &impulse, state);
    }
finish:
    if (actor[0xbc]) {
        func_002FEE50(*(int *)(state + 0x1c));
        if (*(int *)(state + 0x14) < 0x14)
            func_L00_0038DE70(actor, &impulse, &normal);
        else
            func_L00_0038E880(actor, &impulse, &normal);
    }
}
