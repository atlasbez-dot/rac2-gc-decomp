/* Signature/interface follow-up, 23 October 2026.
 * Profile: -O2 -G8 -ffunction-sections.
 * USA v1.01: 2220/2136 bytes, 0/3 carrying placements.
 * USA v2.00: 2220/2136 bytes, 0/3 carrying placements.
 * PAL: canonical name absent from the catalogue.
 * func_L00_00387518 follows its one-owner current C interface; the removed second object
 * expression has no side effects. Canonical callback and signed +0x4e index repairs are
 * preserved.
 * This follows the current linked C contract; it does not independently prove the original
 * source declaration.
 * The retained C remains nonmatching. Earlier sizes and residual offsets below are
 * historical and superseded by this measurement; their reopening hypotheses remain
 * unqualified. No linked build was run for this follow-up.
 */

/* Historical measurements, superseded where inconsistent with the follow-up above. */
/* GNU game -O2 -G8, 2224/2136 bytes, us/us2 each 0/3 places; absent from PAL.
 * Rechecked with canonical callback func_003058C8(void *) and the two-argument
 * func_00300300 interface. At every US/US2 placement, retail loads signed
 * state byte +0x4e into a1 before that call (including the no-effect-handle
 * branch); this supplies the index, with no inferred or guessed value.
 * Projectile state branches, collision query fields and attachment coordinates
 * are reconstructed. Default quad-copy lowering and allocation yield a 0x1a0
 * frame instead of 0x190. Reopen with a qualified copy profile and the collision
 * query layout independently checked.
 */
typedef int ProjectileQuad __attribute__((mode(TI)));
typedef union { ProjectileQuad quad; struct { float x, y, z, w; } v; } ProjectileVector;
typedef struct { float x, y, z; } ProjectileOffset;
typedef struct {
    ProjectileVector previous, position, velocity;
    unsigned char *hitObject;
    int *excluded;
    int mode;
    float radius, response, friction;
    int flags0, flags1, enabled, surface, active;
    float tolerance;
} ProjectileQuery;
extern int D_L03_001AEFCC __attribute__((sda));
extern float D_L03_001AEFB0 __attribute__((sda));
extern float D_L03_001AEFB8 __attribute__((sda));
extern int D_L03_001B31B0 __attribute__((sda));
extern int D_L03_001B31B8 __attribute__((nosda));
extern unsigned char *D_L03_001ADAAC __attribute__((nosda));
extern unsigned char D_L03_0023B300[] __attribute__((nosda));
extern unsigned char D_L03_0023B400[] __attribute__((nosda));
extern unsigned char *D_L03_0023B530[] __attribute__((nosda));
extern ProjectileOffset D_L03_0023B6C0[] __attribute__((nosda));
extern unsigned char D_L03_00189E20[] __attribute__((nosda));
extern void func_002FE8D8(void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282DD8(void *, void *, void *);
extern float func_00282DB0(void *, void *);
extern float func_00283198(float);
extern void func_00282D30(void *, void *, float);
extern float func_00283180(float);
extern void func_00283958(void *, void *);
extern void func_00283738(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_002FEE70(int, void *, int);
extern void func_002FE880(float, void *, void *);
extern void func_00300190(void *, void *);
extern int func_002FE9D0(ProjectileQuery *);
extern int func_00300540(int);
extern void func_002FD1B8(float, float, float, float, int, int, int);
extern unsigned char *func_00312D58(float, void *);
extern signed char func_00300280(void *, void *);
extern void func_L00_00387F98(void);
extern int func_002E5CF8(int, int, void *);
extern void func_002A75E0(void *, int, int, int, int);
extern void func_002FEE50(int);
extern void func_00282CF0(void *, void *, void *);
extern void func_00283698(void *, void *);
extern void func_002830C0(void *, void *, void *);
extern float func_0029F530(void *);
extern void func_00304D38(void *);
extern void func_00304F28(void *);
extern void func_00305058(void *);
extern signed char func_002FED90(float, float, float, void *, int);
extern int func_002FEC78(void *, int);
extern void func_L00_00387370(void *);
extern void func_L00_00387408(void *);
extern void func_002AC728(float, float, void *, void *, int);
extern void func_002FED28(int);
extern void func_00300300(void *, int);
extern void func_0029F338(void *);
extern void func_00283098(void *, void *, void *);
extern void func_L00_00387AC8(void *);
extern void func_002829D8(void *);
extern int func_00282948(void *);
extern void func_003054E8(void *);
extern void func_00304C18(void *);
extern void func_L00_00387518(void *);
typedef void (*ProjectileDrawCallback)(void *);
extern void func_L00_002E6EF8(ProjectileDrawCallback, void *);
extern void func_003058C8(void *);
#define PI(p,o) (*(int *)((p)+(o)))
#define PF(p,o) (*(float *)((p)+(o)))
#define PP(p,o) (*(unsigned char **)((p)+(o)))
#define PV(p,o) (*(ProjectileVector *)((p)+(o)))

void func_L03_0038BCC0(unsigned char *object) {
    unsigned char *state = PP(object, 0x68);
    unsigned char *attached, *created;
    ProjectileVector normal, forward, quaternion, cross, oldPosition, relative;
    float matrix[12], inverse[16];
    ProjectileQuery query;
    int excluded[2];
    float halfAngle;
    int collision, response, index;
    switch (object[0x20]) {
    case 0:
        object[0x20] = 1;
        PI(state, 0x6C) = D_L03_001AEFCC;
        D_L03_001AEFCC = (D_L03_001AEFCC + 1) % 100;
        PI(object, 0x98) = 0;
    case 1:
        func_002FE8D8(object + 0x10, &normal);
        func_00282F20(&forward, object + 0xE0, 1.0f);
        func_00282DD8(&cross, &forward, &normal);
        halfAngle = func_00282DB0(&forward, &normal) * 0.5f;
        func_00282D30(&quaternion, &cross, func_00283198(halfAngle));
        quaternion.v.w = func_00283180(halfAngle);
        func_00283958(&quaternion, matrix);
        func_00283738(object + 0xC0, matrix, object + 0xC0);
        oldPosition = PV(object, 0x10);
        func_00282CC0(object + 0x10, object + 0x10, state);
        func_002FEE70((signed char)state[0x4F], state, 0);
        func_002FE880(D_L03_001AEFB0 * 0.00027777778450399637f, object + 0x10, state);
        func_00300190(object + 0x10, object + 0x10);
        excluded[0] = 0;
        excluded[1] = 0xC5A;
        query.previous = oldPosition;
        query.position = PV(object, 0x10);
        query.velocity = PV(state, 0);
        query.hitObject = object;
        query.excluded = excluded;
        query.mode = 2;
        query.radius = 0.1f;
        query.response = D_L03_001AEFB8;
        query.friction = 0.5555555820465088f;
        query.flags0 = 0;
        query.flags1 = 0;
        query.enabled = 1;
        query.active = 1;
        query.tolerance = 0.07400000095367432f;
        collision = func_002FE9D0(&query);
        PV(object, 0x10) = query.position;
        PV(state, 0) = query.velocity;
        if (collision == 2) {
            if (query.hitObject && (*(short *)(query.hitObject + 0xAA) == 0xCB ||
                *(short *)(query.hitObject + 0xAA) == 0x1366 || *(short *)(query.hitObject + 0xAA) == 0x1367)) {
                func_00282D30(state, state, 1.1f);
                break;
            }
            PV(state, 0).quad = 0;
            PP(state, 0x70) = query.hitObject;
            if (query.hitObject) {
                PF(state, 0x74) = PF(query.hitObject, 0x10);
                PF(state, 0x78) = PF(query.hitObject, 0x14);
                PF(state, 0x7C) = PF(query.hitObject, 0x18);
            }
            response = func_00300540(query.surface);
            if (response == 2) {
                PF(state, 8) = -0.02500000223517418f;
                object[0x20] = 7;
                if (!query.surface) {
                    func_002FD1B8(PF(object, 0x10), PF(object, 0x14), 0.5f, -0.35f, D_L03_001B31B0, D_L03_001B31B8, 1);
                    created = func_00312D58(2.0f, object + 0x10);
                    if (created)
                        created[0x23] = 0x70;
                }
            } else if (response == 1) {
                object[0x20] = 8;
            } else {
                state[0x4E] = func_00300280(D_L03_0023B300, object);
                func_L00_00387F98();
                if (D_L03_0023B400[(signed char)state[0x4E]]) {
                    object[0x20] = 2;
                    func_002E5CF8(1, 0, object);
                    func_002A75E0(object, 1, 0, 0, 0);
                } else {
                    object[0x20] = 6;
                }
            }
            func_002FEE50((signed char)state[0x4F]);
            index = PI(state, 0x6C);
            D_L03_0023B530[index] = D_L03_001ADAAC;
            if (D_L03_001ADAAC) {
                func_00282CF0(&relative, object + 0x10, D_L03_001ADAAC + 0x10);
                func_00283698(inverse, D_L03_0023B530[PI(state, 0x6C)] + 0xC0);
                func_002830C0(&relative, &relative, inverse);
                D_L03_0023B6C0[PI(state, 0x6C)].x = relative.v.x;
                D_L03_0023B6C0[PI(state, 0x6C)].y = relative.v.y;
                D_L03_0023B6C0[PI(state, 0x6C)].z = relative.v.z;
            }
            PI(object, 0x98) = PI(PP(object, 0x24), 0x10);
        }
        break;
    case 2:
        if (func_0029F530(object) >= 6.0f) {
            func_002A75E0(object, 2, 0, 0, 0);
            object[0x20] = 3;
        }
        break;
    case 3:
        func_00304D38(object);
        goto checkAttached;
    case 4:
        func_00304F28(object);
        func_00305058(object);
checkAttached:
        attached = PP(state, 0x70);
        if (attached && (attached[0x20] == 0xFE || attached[0x20] == 0xFD)) {
            PI(object, 0x98) = 0;
            state[0x4F] = func_002FED90(1.0f, 1.0f, 1.0f, object, 0);
            object[0x20] = 1;
            PP(state, 0x70) = 0;
        }
        break;
    case 5:
        if (func_0029F530(object) <= 1.0f) {
            func_002A75E0(object, 0, 0, 0, 0);
            PF(object, 0x48) = 1.0f;
            object[0x20] = 6;
        }
        break;
    case 6:
        if (D_L03_0023B400[(signed char)state[0x4E]]) {
            object[0x20] = 2;
            func_002E5CF8(1, 0, object);
            func_002A75E0(object, 1, 0, 0, 0);
            PI(state, 0x48) = func_002FEC78(object, 0);
        }
        break;
    case 7:
        func_L00_00387370(object);
        func_L00_00387408(object);
        break;
    case 8:
        func_002E5CF8(3, 0, object);
        func_002AC728(0.5f, 13.0f, object, object + 0x10, -1);
        object[0x20] = 9;
        *(unsigned short *)(object + 0x34) |= 0x41;
        break;
    case 9:
        if (!PI(state, 0x64)) {
            if (PI(state, 0x48) != -1)
                func_002FED28(PI(state, 0x48));
            if ((signed char)state[0x4E] != -1)
                func_00300300(D_L03_0023B300, (signed char)state[0x4E]);
            func_0029F338(object);
            return;
        }
        break;
    }
    if (object[0x20] >= 2 && D_L03_0023B530[PI(state, 0x6C)]) {
        index = PI(state, 0x6C);
        normal.v.x = D_L03_0023B6C0[index].x;
        normal.v.y = D_L03_0023B6C0[index].y;
        normal.v.z = D_L03_0023B6C0[index].z;
        normal.v.w = 0;
        func_00283098(&normal, &normal, D_L03_0023B530[PI(state, 0x6C)] + 0xC0);
        func_00282CC0(object + 0x10, D_L03_0023B530[PI(state, 0x6C)] + 0x10, &normal);
    }
    if ((unsigned int)(object[0x20] - 3) < 2)
        func_L00_00387AC8(object);
    func_002829D8(state + 0x5C);
    if ((func_00282948(state + 0x40) || PI(D_L03_00189E20, 0x2294) == 0x6F) && object[0x20] != 9)
        object[0x20] = 8;
    func_003054E8(object);
    if ((unsigned int)(object[0x20] - 3) < 2) {
        func_00304C18(object);
        if (!D_L03_0023B400[(signed char)state[0x4E]]) {
            func_002A75E0(object, 1, 9, 0, 0);
            object[0x20] = 5;
            PF(object, 0x48) = -1.0f;
            func_002FED28(PI(state, 0x48));
            PI(state, 0x48) = -1;
            *(short *)(state + 0x4C) = 1;
            PI(state, 0x50) = 0;
            PI(state, 0x44) = 0;
            PI(state, 0x68) = 0;
            PV(state, 0x30) = PV(state, 0x10);
            PV(state, 0x20) = PV(state, 0x10);
        }
    }
    if (object[0x20] < 8 && PP(state, 0x70))
        func_L00_00387518(object);
    func_L00_002E6EF8(func_003058C8, object);
}
