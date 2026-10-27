/* func_L00_003A5DC0: retained near miss (M9, 2026-10-26). Profile -O2 -G0 -ffunction-sections.
 * 508/508 bytes, 0/27, 11 instructions off, all one v0/v1 swap: retail keeps the return
 * address's high part (the joined "return D_L00_001BF200.object" of both hit paths) in v0 and
 * the object test in v1; this gives the reverse, which also swaps the weapon-table index/base
 * pair. The object is returned on both hit paths (it is null on one). Reading D_0018C0B0
 * through a char array keeps its load in the jal delay slot after the hit[3] store, as retail.
 * Tried: a result local, dropping the else, != 0, separate damage/distance statements.
 */
#include "common.h"
typedef struct { char pad[0x70]; float power; char tail[0x6C]; } WeaponEntry;
typedef struct { char pad[0x18]; void *object; int detail; float point[4]; } CollisionPrefix;
extern CollisionPrefix D_L00_001BF200;
extern WeaponEntry D_L00_00262570[];
extern unsigned char D_00139582;
extern char D_0018C0B0[];
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern int func_002761F8(void *, void *, int, void *, void *);
extern void func_L00_003FC108(void *, void *, void *, int);
extern float func_00282E48(void *, void *);
extern void func_002A8E20(void *, void *);
extern void func_0032D758(void *, int, void *);

/* Trace a beam and apply distance-scaled damage at its contact point. */
void *func_L00_003A5DC0(void *owner, void *start, void *end, float *hit)
{
    float direction[4];
    func_00282CF0(hit, end, start);
    func_00282F20(hit, hit, 1.5f);
    hit[3] = 5627.9248046875f;
    if (func_002761F8(start, end, 0x10, *(void **)D_0018C0B0, 0)) {
        func_00282CF0(direction, end, start);
        func_00282F20(direction, direction, 1.0f);
        func_00282CF0(direction, D_L00_001BF200.point, start);
        func_L00_003FC108(start, direction, D_L00_001BF200.point, 1);
        if (D_L00_001BF200.object) {
            float damage = D_L00_00262570[D_00139582].power;
            float distance = func_00282E48(D_L00_001BF200.point, start);
            if (distance < 10.0f)
                hit[7] = damage;
            else if (distance < 14.0f)
                hit[7] = damage * 0.75f;
            else if (distance < 20.0f)
                hit[7] = damage * 0.5f;
            else
                hit[7] = damage * 0.125f;
            func_002A8E20(D_L00_001BF200.object, hit);
            func_0032D758(D_L00_001BF200.object, 26, owner);
        }
        return D_L00_001BF200.object;
    } else {
        func_00282CF0(direction, end, start);
        func_L00_003FC108(start, direction, end, 0);
    }
    return 0;
}
