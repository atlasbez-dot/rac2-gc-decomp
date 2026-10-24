/* Reconstruction checked 23 October 2026.
 * Profile: -O2 -G0 -ffunction-sections.
 * Final check.py coverage: us 0/27, us2 0/27.
 * Typed collision/weapon prefixes reconstructed496/508; -mno-split-addresses gave492/508 and was not retained.
 * Remaining: Global collision/weapon address formation and integer-register scheduling differ.
 * Reopen with a measured ordinary-C aggregate-address hypothesis.
 * Historical screening below is preserved; its blanket C/ISA claims are not acceptance evidence.
 */

/* func_L00_003A5DC0 - 508 bytes, 27 place(s), level 00_aranos_tutorial,
   retail at 0x003a5dc0. Screened with tools/w10_screen.py: 12 call(s)
   [func_00282CF0@003A5DF4, func_00282F20@003A5E08, func_002761F8@003A5E34,
   func_00282CF0@003A5E48, func_00282F20@003A5E5C, func_00282CF0@003A5E74,
   func_L00_003FC108@003A5E88, func_00282E48@003A5EC0,
   func_002A8E20@003A5F50, func_0032D758@003A5F60, func_00282CF0@003A5F7C,
   func_L00_003FC108@003A5F90]; data addresses materialised [0x45af0000,
   0x190000, 0x1c0000, 0x1c0000, 0x140000, 0x260000, 0x1c0000]; float
   constants [0x3fc00000, 0x3f800000, 0x41200000, 0x41600000, 0x3f400000,
   0x41a00000, 0x3e000000, 0x3f000000]; $gp-relative small data: no   saves:
   -; callee-saved registers saved [-]; words plain C cannot emit [-]. Head:
   addiu $sp, $sp, -0x50 ; sd $s0, 0x10($sp) ; sd $s1, 0x18($sp) ; daddu
   $s0, $a1, $zero ; sd $s2, 0x20($sp) ; daddu $s1, $a2, $zero. Not matched
   in this wave: the body is straight-line code whose register allocation
   and the materialisation of its constant addresses have to be reproduced
   word for word. What would unblock it: the exact source expression tree,
   so this cc1 picks the same registers in the same order. */

#include "common.h"
typedef struct { char pad[0x70]; float power; char tail[0x6C]; } WeaponEntry;
typedef struct { char pad[0x18]; void *object; int detail; float point[4]; } CollisionPrefix;
extern CollisionPrefix D_L00_001BF200;
extern WeaponEntry D_L00_00262570[];
extern unsigned char D_00139582;
extern void *D_0018C0B0;
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
    if (func_002761F8(start, end, 0x10, D_0018C0B0, 0)) {
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
            return D_L00_001BF200.object;
        }
    } else {
        func_00282CF0(direction, end, start);
        func_L00_003FC108(start, direction, end, 0);
    }
    return 0;
}
