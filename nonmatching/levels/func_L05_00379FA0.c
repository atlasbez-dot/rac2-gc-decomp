/* 2026-10-23 reconstruction. Measured with -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-
   barrier. us: 0/4 placements; 05_feltzin_system: 532 bytes, expected 628; us2: 0/4 placements;
   05_feltzin_system: 532 bytes, expected 628; pal: 0/4 placements; 05_feltzin_system: 532 bytes,
   expected 628. One reconstruction plus release checks. A truthful128-byte projectile record replaces
   historical screening only. Vector copies are reachable with the grouped-copy profile; pointer
   induction and register/stack allocation remain96bytes short. Reopen with a matching multi-pointer
   record traversal. Historical screening is preserved below. */

/* func_L05_00379FA0 - 628 bytes, 4 place(s), level 05_feltzin_system,
   retail at 0x00379fa0. Screened with tools/w10_screen.py: 10 call(s)
   [func_002ED688@0037A058, func_0029FCC0@0037A090, func_00282F20@0037A0C4,
   func_00282CC0@0037A0D8, func_00282CF0@0037A0F4, func_00282F20@0037A108,
   func_00282CC0@0037A118, func_00282F20@0037A164, func_00282CC0@0037A174,
   func_L05_0037DA58@0037A188]; data addresses materialised [0x220000,
   0x3f4c0000]; float constants [0x40000000]; $gp-relative small data: no
   saves: -; callee-saved registers saved [-]; words plain C cannot emit
   [LQ/SQ 78620000@0x0100, LQ/SQ 7EA20000@0x0104, LQ/SQ 78620000@0x0114,
   LQ/SQ 7FA20000@0x0118, LQ/SQ 7A220000@0x0144, LQ/SQ 7C820000@0x0148].
   Head: addiu $sp, $sp, -0xB0 ; lui $v0, 0x22 ; sd $s1, 0x48($sp) ; addiu
   $v0, $v0, 0x1DD0 ; daddu $s1, $a0, $zero ; sd $s0, 0x40($sp). Not matched
   in this wave: the 128-bit copy needs an `lq`/`sq` pair; plain C reaches
   it only through a `mode(TI)` local, and this cc1 folds the destination
   offset into the `sq` where retail materialises the pointer first. What
   would unblock it: the exact source expression tree, so this cc1 picks the
   same registers in the same order. */

#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef struct {
    float position[4], previous[4], origin[4], target[4], velocity[4];
    u8 *object;
    float distance;
    int flags,color,effect,mode;
    float rate,spin,life;
    u8 pad74[12];
} L05Projectile;
extern L05Projectile D_L05_00221DD0[];
extern s32 func_002ED688(u8 *);
extern void func_0029FCC0(char *,int,char *);
extern void func_00282F20(void *,void *,float);
extern void func_00282CC0(void *,void *,void *);
extern void func_00282CF0(void *,void *,void *);
extern void func_L05_0037DA58(void *,int,int,int);
void func_L05_00379FA0(u8 *object,int color,int mode,int effect,int emit,int joint,u8 *other,float rate,float speed,float spin,float life)
{
    L05Projectile *record = D_L05_00221DD0;
    u8 *state,*target;
    float direction[4],point[4];
    int index;
    for (index=0;index<128;index++,record++) {
        if (record->object) continue;
        record->object = object;
        state = (u8 *)func_002ED688(object);
        if (joint == -1) *(Quad *)record->target = *(Quad *)(object+0x10);
        else func_0029FCC0((char *)(other ? other : object),joint,(char *)record->target);
        target = *(u8 **)(state+0x120);
        *(Quad *)direction = *(Quad *)(target+0xC0);
        func_00282F20(direction,direction,speed);
        func_00282CC0(record->origin,target+0x10,direction);
        *(Quad *)record->previous = *(Quad *)record->target;
        func_00282CF0(record->velocity,record->origin,record->target);
        func_00282F20(record->velocity,record->velocity,2.0f);
        func_00282CC0(record->position,record->velocity,record->previous);
        record->color = color;
        record->rate = rate;
        record->mode = mode;
        record->spin = spin;
        record->effect = effect;
        record->life = life;
        record->flags = 0;
        record->distance = 0.0f;
        if (emit) {
            func_00282F20(point,record->velocity,0.8f);
            func_00282CC0(point,point,record->target);
            func_L05_0037DA58(point,emit,record->color,20);
        }
        return;
    }
}
