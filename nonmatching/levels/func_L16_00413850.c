/* 2026-10-23 C reconstruction. Measured with -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-
   barrier. us: 0/2 placements, 16_snivelak: 1184 bytes, expected 1212; us2: 0/2 placements,
   16_snivelak: 1184 bytes, expected 1212; pal: canonical name absent. Projectile lifetime, quaternion
   steering, collision and impact paths reconstructed with the measured six-GPR plus three-FP effect-
   factory call and twelve-GPR explosion tail. The retained1184-byte profile preserves the0x190 frame;
   no-GCSE gave1168 with a smaller frame. Register and scalar scheduling remain. The callback genuinely
   differs by placement and uses a scoped reference. Reopen when: A matching quaternion/hit-record
   expression tree and final callback binding checks. Historical screening follows unchanged.
 */

/* func_L16_00413850 - 1212 bytes, 2 place(s), level 16_snivelak, retail at
   0x00413850. Screened with tools/w10_screen.py: 34 call(s)
   [func_002A8C28@004138D4, func_002A7750@004138E4, func_00282D30@00413930,
   func_00282DF0@00413944, func_00282F20@00413964, func_00282F20@0041397C,
   func_00282CC0@0041398C, func_00282CC0@0041399C, func_002761F8@004139B4,
   func_00282F20@004139D8, func_00282F20@004139F4, func_00282D30@00413A18,
   func_00282F20@00413A28, func_00282DD8@00413A38, func_00282DB0@00413A44,
   func_00283198@00413A64, func_00282D30@00413A74, func_00283180@00413A7C,
   func_002837D0@00413ABC, func_002837D0@00413ACC, func_00282F20@00413ADC,
   func_00282D30@00413AF0, func_00282CC0@00413B08, func_002A8C00@00413B24,
   func_002761F8@00413B44, func_00277258@00413B68, func_00282D30@00413BBC,
   func_002A8C00@00413BF0, func_00277F48@00413C24, func_002A7750@00413C34,
   func_00282D30@00413C5C, func_0032C700@00413CA4, func_0029F338@00413CAC,
   func_L00_002E6EF8@00413CC0]; data addresses materialised [0x3f190000,
   0x10000, 0x410000, 0x3dcc0000, 0x1c0000, 0x1c0000, 0x3e990000, 0x1c0000,
   0x45af0000, 0x10000, 0x3f190000, 0x410000]; float constants [0xbf800000,
   0xc0400000, 0x3f800000, 0xbf800000, 0x3f800000, 0x3f000000, 0x3fc00000,
   0x40400000, 0xbf000000, 0x3e800000, 0x41a00000]; $gp-relative small data:
   no   saves: -; callee-saved registers saved [-]; words plain C cannot
   emit [LQ/SQ 7A420000@0x00c0, LQ/SQ 7C820000@0x00c4, LQ/SQ
   7A420000@0x02a8, LQ/SQ 7EE20000@0x02ac, LQ/SQ 7A820000@0x0340, LQ/SQ
   7E020000@0x0344, LQ/SQ 7A820000@0x0358, LQ/SQ 7E020000@0x035c, LQ/SQ
   78620000@0x03f8, LQ/SQ 7EC20000@0x03fc]. Head: addiu $sp, $sp, -0x190 ;
   sd $s5, 0x138($sp) ; sd $s0, 0x110($sp) ; daddu $s5, $a0, $zero ; sd $s1,
   0x118($sp) ; sd $s2, 0x120($sp). Not matched in this wave: the 128-bit
   copy needs an `lq`/`sq` pair; plain C reaches it only through a
   `mode(TI)` local, and this cc1 folds the destination offset into the `sq`
   where retail materialises the pointer first. What would unblock it: the
   exact source expression tree, so this cc1 picks the same registers in the
   same order. */

#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef struct { int a,b,c,d; } __attribute__((aligned(16))) Quad16;
typedef struct {
    Quad16 direction;
    int owner,flags;
    u8 kind,active;
    u16 oclass;
    float damage;
    int enabled;
} L16Hit;
extern float D_L16_001BFF80[4];
extern u8 *D_L16_001BFF58;
extern void func_002A8C28(u8 *,void *,int,int,int,int,float,float,float);
extern void func_002A7750(u8 *,u8,s32);
extern void func_00282D30(void *,void *,float);
extern float func_00282DF0(void *);
extern void func_00282F20(void *,void *,float);
extern void func_00282CC0(void *,void *,void *);
extern int func_002761F8(void *,void *,int,void *,void *);
extern void func_00282DD8(void *,void *,void *);
extern float func_00282DB0(void *,void *);
extern float func_00283198(float);
extern float func_00283180(float);
extern void func_002837D0(void *,void *,void *);
extern void func_002A8C00(char *,int,int,float,Quad16 *);
extern int func_00277258(void *,int,void *,float);
extern int func_00277F48(void *,int,void *,void *,float);
extern void func_0032C700(void *,int,int,int,int,int,int,int,int,int,int,int,float,float);
extern void func_0029F338(void *);
extern void ref_L16_00413850_00(void *);
extern void func_L00_002E6EF8(void (*)(void *),void *);
void func_L16_00413850(u8 *object)
{
    float destination[4],backward[4],normal[4],quaternion[4],inverse[4],rotated[4],start[4],finish[4];
    L16Hit hit;
    float impact[4];
    L16Hit blast;
    u8 *state=*(u8 **)(object+0x68);
    float savedW,speed,angle,magnitude;
    int i;
    *(int *)(state+0x24) += 1;
    if (*(int *)(state+0x24)>240) {
        func_002A8C28(object,object+0x10,0x10001,0,1,0,0.6f,*(float *)(state+0x14),0.0f);
        func_002A7750(object,1,-1);
    }
    if (object[0x20]==0) {
        *(Quad *)backward=*(Quad *)(object+0xE0);
        func_00282D30(backward,backward,-1.0f);
        savedW=*(float *)(state+0xC);
        *(float *)(state+0xC)=0.0f;
        speed=func_00282DF0(state);
        func_00282F20(start,object+0xE0,0.1f);
        func_00282F20(finish,object+0xE0,-3.0f);
        func_00282CC0(start,start,object+0x10);
        func_00282CC0(finish,finish,object+0x10);
        if (!func_002761F8(start,finish,2,object,0)) func_00282F20(normal,object+0xE0,-1.0f);
        else func_00282F20(normal,D_L16_001BFF80,1.0f);
        func_00282D30(normal,normal,-1.0f);
        func_00282F20(state,state,1.0f);
        func_00282DD8(normal,backward,normal);
        angle=-func_00282DB0(backward,normal)*0.5f;
        func_00282D30(quaternion,normal,func_00283198(angle));
        quaternion[3]=func_00283180(angle);
        inverse[0]=-quaternion[0];
        inverse[1]=-quaternion[1];
        inverse[2]=-quaternion[2];
        inverse[3]=quaternion[3];
        func_002837D0(rotated,quaternion,state);
        func_002837D0(state,rotated,inverse);
        func_00282F20(state,state,speed);
        *(float *)(state+0xC)=savedW;
        func_00282D30(normal,normal,-1.0f);
        *(Quad *)(object+0xE0)=*(Quad *)normal;
        func_00282CC0(destination,object+0x10,state);
        func_002A8C00((char *)&hit,(int)object,1,*(float *)(state+0x14),(Quad16 *)state);
        hit.oclass=*(u16 *)(object+0xAA);
        if (func_002761F8(object+0x10,destination,0,object,&hit) || func_00277258(object+0x10,0,object,0.3f)) {
            if (!D_L16_001BFF58 || D_L16_001BFF58 != *(u8 **)(state+0x10)) {
                magnitude=D_L16_001BFF58 ? 1.5f : 3.0f;
                *(Quad *)impact=*(Quad *)state;
                func_00282D30(impact,impact,magnitude);
                impact[2]=1.0f;
                impact[3]=5627.9248046875f;
                func_002A8C00((char *)&blast,(int)object,0x10001,*(float *)(state+0x14),(Quad16 *)impact);
                blast.oclass=*(u16 *)(object+0xAA);
                blast.active=1;
                blast.kind=0;
                func_00277F48(object+0x10,0,object,&blast,0.6f);
                func_002A7750(object,1,-1);
                return;
            }
        }
        *(Quad *)(object+0x10)=*(Quad *)destination;
        func_00282D30(impact,state,-0.5f);
    } else if (object[0x20]==1) {
        func_0032C700(object+0x10,0,25,20,20,20,45,0,0,0,0,0,0.25f,20.0f);
        func_0029F338(object);
        return;
    }
    func_L00_002E6EF8(ref_L16_00413850_00,object);
}
