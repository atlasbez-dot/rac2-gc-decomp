/* M33 2026-10-26: 748 -> 776/776 B, 104 -> 11 lines. Same collision tail as func_L19_0038B580: D_L19_001AC790 NOT_SDA, contact->hit re-read with the contact pointer set again before the second test, the normal scale written in each arm, and the weapon record read as (&D_L19_00265870[0] + D_00139574)->power (that spelling fixes the record-read registers here). Left: in the contact tests retail has hit in $a1 and the kept %hi copy in $a0 (here swapped), and loads D_L19_001AC790 before re-reading hit. Profile -O2 -G0 -ffunction-sections -frac2-zero-ti-por. In the permuter. */
/* Retained C reconstruction; not linked or counted.
 * Profile: -O2 -G0 -ffunction-sections -frac2-zero-ti-por.
 * 748/776 bytes. us: 0/1 places; us2: 0/1 places; pal: absent.
 * Remaining: Complete old-position, 48-byte request and collision-position transfers use
 * qcopy; the two real TI vector clears retain their measured zero profile.
 * Hit and contact views are branch-local, the request class follows the retail
 * unsigned halfword load and the timer takes an int32 pointer. The 0xC0 frame
 * agrees; request-store allocation and collision-base/branch scheduling differ.
 * Reopen with: Independent clear/request/collision lifetime evidence, preserving full
 * vectors and request contents. Do not substitute nc copies across dependent
 * writes or change the physical request to fit an SDA threshold.
 */

#include "common.h"

typedef int Quadword __attribute__((mode(TI)));
typedef union { Quadword q; float f[4]; } Vector;
typedef struct {
    Vector velocity;
    u8 *actor;
    int flags;
    u8 kind;
    u8 enabled;
    u16 id;
    float power;
    int mode;
} CollisionRequest;

extern u8 D_00139574;
extern u8 *D_0018C0B0 NOT_SDA;
extern void *D_L19_001AC790 NOT_SDA;
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
    state = *(u8 **)(actor + 0x68);
    position = (Vector *)(actor + 0x10);
    normal.q = 0;
    impulse.f[2] = 1.0f / 30.0f;
    normal.f[2] = 1.0f;
    qcopy(&previous, position);
    func_00282CC0(position, position, state);
    func_002AFFD8((char *)position, (char *)&direction, 0);
    func_00282D30(&direction, &direction, 0.0003055556f);
    func_L00_0038F3D8((char *)actor);
    request.actor = actor;
    request.flags = 0x830000;
    if (*(int *)(state + 0x18) < 0x122)
        request.flags = 0x830001;
    request.mode = 1;
    request.power = (&D_L19_00265870[0] + D_00139574)->power;
    qcopy(&request.velocity, state);
    func_00282F70(&request.velocity, &request.velocity, 1.0f);
    request.kind = 2;
    request.velocity.f[3] = 5627.925f;
    request.id = *(u16 *)(actor + 0xaa);
    request.velocity.f[2] = 1.0f;
    request.enabled = 1;
    *(int *)(state + 0x14) += 1;
    if (func_002761F8(&previous, position, 0x10, actor, &request)) {
        Collision *contact = &D_L19_001BFE80;
        if (contact->hit) {
            if ((contact->hit == D_0018C0B0 || *(short *)(contact->hit + 0xaa) == 0xc0) &&
                    *(int *)(state + 0x18) >= 0x122)
                goto finish;
            contact = &D_L19_001BFE80;
            if (*(void **)(contact->hit + 0x64) == D_L19_001AC790 && *(short *)(contact->hit + 0xaa) != 0x336)
                goto finish;
            actor[0xbc] = 1;
            qcopy((actor + 0x10), &contact->point);
            func_00283028(&impulse, state, &contact->normal);
            func_00282F20(&impulse, &impulse, 1.0f / 30.0f);
            func_00282F20(&normal, &contact->normal, 1.0f);
        } else {
            if (contact->count <= 0)
                goto finish;
            actor[0xbc] = 1;
            qcopy(position, &contact->point);
            func_00283028(&impulse, state, &contact->normal);
            func_00282F20(&impulse, &impulse, 1.0f / 30.0f);
            func_00282F20(&normal, &contact->normal, 1.0f);
        }
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
