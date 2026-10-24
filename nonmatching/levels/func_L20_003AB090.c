/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-por.
 * Reported final C / retail: 1044 / 1044 bytes; size equality is not a match.
 * us: 0/1 placements.
 * us2: not run after us mismatch; no exact candidate.
 * pal: not run after us mismatch; no exact candidate.
 * Residual: Four source trials including one corrected declaration error; final 1044 bytes and the correct 0xE0 frame. Initial quadword-zero scheduling, the settings-table base and shared collision-record base differ. The complete collision/death/effect paths are retained; no helper prototype was chosen to force a register.
 * Reopening condition: Recover natural zero-initializer scheduling and the actual grouped settings/collision record declarations.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Not matched, 2026-10-23.
 * Four source trials including one corrected declaration error; final 1044 bytes and the correct 0xE0 frame. Initial quadword-zero scheduling, the settings-table base and shared collision-record base differ. The complete collision/death/effect paths are retained; no helper prototype was chosen to force a register.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-por
 * Final us check: func_L20_003AB090: 0 of 1 places match (src/levels/20_yeedil/L20_003AB090-g8.c); exit 1.
 * This source has not passed a linked build or a runtime test.
 */
#include "common.h"
typedef int Quadword __attribute__((mode(TI)));
typedef union { Quadword q; float f[4]; } Vector;
typedef struct { Vector direction; u8 *owner; u32 flags; u8 type,enabled; u16 objectClass; float restitution; int active; } CollisionQuery;
extern u8 D_00139574;
typedef struct { u8 prefix[0x70]; float restitution; u8 tail[0x6c]; } PhysicsSettings;
extern PhysicsSettings D_L20_0026D970[];
extern int D_L20_001B3730 __attribute__((sda));
extern int D_L20_001B3738 __attribute__((sda));
extern u8 D_L20_001C0400[];
extern u8 *D_0018C0B0;
extern int D_L20_001AC810;
extern void func_00282CC0(void *,void *,void *);
extern void func_00282CF0(void *,void *,void *);
extern void func_002FEE70(int,void *,int);
extern void func_00300190(void *,void *);
extern void func_00300248(int,int);
extern void func_002FE880(void *,float *,float);
extern void func_L00_0038F178(char *);
extern void func_00282F70(void *,void *,float);
extern int func_002761F8(void *,void *,int,void *,void *);
extern int func_00278E78(void);
extern void func_002FD1B8(int,int,int,float,float,float,float);
extern void func_00282C88(Quadword *);
extern u8 *func_00312D58(void *,float);
extern float func_002A7940(void);
extern float func_002A7878(float,float);
extern float func_00283180(float);
extern float func_00283198(float);
extern int func_002A7820(int,int);
extern int func_002A77E0(int);
extern u8 *func_002BFB38(void *,void *,int,int);
extern void func_00283028(void *,void *,void *);
extern void func_00282F20(void *,void *,float);
extern int func_00282948(void *);
extern void func_002FEE50(int);
extern void func_L00_0038DE70(void *,void *,void *);
void func_L20_003AB090(u8 *object)
{
    Vector oldPosition, acceleration, normal;
    CollisionQuery query;
    Vector effectPosition, effectVelocity;
    u8 *state;
    u8 *effect;
    int i,life;
    float angle,speed;
    acceleration.q=0;
    state=*(u8 **)(object+0x68);
    normal.q=0;
    acceleration.f[2]=0.033333335f;
    normal.f[2]=1.0f;
    oldPosition.q=*(Quadword *)(object+0x10);
    func_00282CC0(object+0x10,state,object+0x10);
    func_002FEE70(*(int *)(state+0x1c),state,0);
    func_00300190(object+0x10,object+0x10);
    func_00300248((int)state,(int)state);
    func_002FE880(object+0x10,(float *)state,0.0030555557f);
    func_L00_0038F178((char *)object);
    query.owner=object;
    query.flags=0x830000;
    if (*(int *)(state+0x18)<290) query.flags=0x830001;
    query.active=1;
    query.restitution=D_L20_0026D970[D_00139574].restitution;
    query.direction.q=*(Quadword *)state;
    func_00282F70(&query.direction,&query.direction,1.0f);
    query.objectClass=*(u16 *)(object+0xaa);
    query.direction.f[2]=1.0f;
    query.direction.f[3]=5627.9248046875f;
    query.type=2;
    query.enabled=1;
    if (func_002761F8(&oldPosition,object+0x10,16,object,&query)) {
        if (!func_00278E78() && *(float *)(state+8)<0.0f) {
            func_002FD1B8(D_L20_001B3730,D_L20_001B3738,1,*(float *)(object+0x10),*(float *)(object+0x14),0.5f,-0.35f);
            *(int *)(state+0x14)=1;
            func_00282C88((Quadword *)state);
            *(float *)(state+8)=-0.025000002f;
            effectPosition.f[0]=*(float *)(object+0x10);
            effectPosition.f[1]=*(float *)(object+0x14);
            effectPosition.f[2]=(*(float *)(D_L20_001C0400+0x28));
            effect=func_00312D58(&effectPosition,2.0f);
            if (effect) effect[0x23]=0x70;
            i=15;
            do {
                i--;
                angle=func_002A7940();
                speed=func_002A7878(0.0f,0.050000004f);
                effectVelocity.f[0]=func_00283180(angle)*speed;
                effectVelocity.f[1]=func_00283198(angle)*speed;
                effectVelocity.f[2]=func_002A7878(0.050000004f,0.10833334f);
                life=func_002A7820(90,120);
                func_002BFB38(&effectPosition,&effectVelocity,func_002A77E0(2),life);
            } while (i>=0);
        } else {
            if ((*(u8 **)(D_L20_001C0400+0x18))) {
                if (((*(u8 **)(D_L20_001C0400+0x18))==D_0018C0B0 || *(short *)((*(u8 **)(D_L20_001C0400+0x18))+0xaa)==0xc0) && *(int *)(state+0x18)>289) goto finish;
                if (*(int *)((*(u8 **)(D_L20_001C0400+0x18))+0x64)==D_L20_001AC810 && *(short *)((*(u8 **)(D_L20_001C0400+0x18))+0xaa)!=0x336) goto finish;
            } else if ((*(int *)(D_L20_001C0400+0x1c))<1) goto finish;
            object[0xbc]=1;
            *(Quadword *)(object+0x10)=(*(Quadword *)(D_L20_001C0400+0x20));
            func_00283028(&acceleration,state,D_L20_001C0400+0x40);
            func_00282F20(&acceleration,&acceleration,0.033333335f);
            func_00282F20(&normal,D_L20_001C0400+0x40,1.0f);
        }
    } else if (func_00282948(state+0x18)) {
        object[0xbc]=1;
        func_00282CC0(&acceleration,&acceleration,state);
    }
finish:
    if (object[0xbc]) {
        func_002FEE50(*(int *)(state+0x1c));
        func_L00_0038DE70(object,&acceleration,&normal);
    }
}
