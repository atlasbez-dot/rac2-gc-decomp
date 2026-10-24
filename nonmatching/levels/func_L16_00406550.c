/* 2026-10-23 C reconstruction. Measured with -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-
   barrier -frac2-zero-ti-por. us: 0/3 placements, 16_snivelak: 3152 bytes, expected 3164; us2: 0/3
   placements, 16_snivelak: 3152 bytes, expected 3164; pal: canonical name absent. All explosion groups
   and final particle setup reconstructed with real pointer returns, integer conversion calls, FP banks
   and the twelve-GPR collider tail. Frame0xE0 agrees; source emits por clears, superseding the
   historical impossibility claim. No-split gave3144, so the3152-byte grouped-copy profile is retained.
   Reopen when: A matching particle-loop/global-address expression witness and final all-placement
   checks. Historical screening follows unchanged.
 */

/* MMI (SPECIAL2) instruction: no C spelling. 3164 bytes, level 16_snivelak.
   Retail at 0x00406550 carries the SPECIAL2 word 0x700014A9 (+0x0960) -
   opcode 0x1C, which rabbitizer prints as `INVALID`; it is the MMI family
   (pcpyld and its relatives) the sixth wave recorded and that no C spelling
   reaches. This cc1 emits `lq`/`sq` for a `mode(TI)` local and
   `ldl`/`ldr`/`sdl`/`sdr` for a struct assignment, never the packed copy.
   ASM_FUNC candidate, as for the rest of the family. */

#include "common.h"
typedef int Quad __attribute__((mode(TI)));
#define F(p,o) (*(float *)((u8 *)(p)+(o)))
#define I(p,o) (*(int *)((u8 *)(p)+(o)))
extern float D_L16_001B1508 __attribute__((sda)),D_L16_001B150C __attribute__((sda));
extern int D_L16_001B1510 __attribute__((sda));
extern float D_L16_001A8F20[4],D_L16_001B9B00[4];
extern u8 *D_L16_001FF7F0 NOT_SDA,*D_L16_001FF754 NOT_SDA;
extern u8 *func_002C65A0(void *,void *,int,int,int,int,int,int,float,float,float);
extern float func_00283248(float,float);
extern float func_002A78D8(float,float);
extern int func_00283CF0(float);
extern int func_002A7820(int,int);
extern float func_002A7878(float,float);
extern float func_00283B98(float,float);
extern float func_00283180(float);
extern float func_00283198(float);
extern u8 *func_002C7970(void *,void *,int,int,int,int,int,int,float,float,float);
extern void func_00282D30(void *,void *,float);
extern void func_002AB668(void *,int,float);
extern void func_002ACDE8(void *,void *,void *);
extern u8 *func_002C6DD8(void *,void *,int,float);
extern void func_00308408(void *,void *,void *,int,int,int,int,int,float);
extern void func_002ABBB8(void *,void *,void *,int,int,int,int,int,int,int,int,int,float,float,float,float,float,float,float);
extern void func_002AF000(float *,float,float,float);
extern u8 *func_002BDCE8(void *,int,void *,int,int,float,float,float,float);
extern float func_00283CE0(int);
void func_L16_00406550(u8 *object)
{
    float position[4],velocity[4],rotation[4];
    u8 *state=*(u8 **)(object+0x68),*effect;
    float inner,outer,angle,size,speed,radius,roll,turn;
    int i,lifetime,phase,sign;
    inner=D_L16_001B1508*F(state,0x14)*210000.0f;
    outer=D_L16_001B150C*F(state,0x14)*210000.0f;
    effect=func_002C65A0(object+0x10,D_L16_001A8F20,D_L16_001B1510,0x388EF7,0,100,0,0,inner,outer,0.0f);
    if (effect) effect[2]=D_L16_001FF7F0[0];
    effect=func_002C65A0(object+0x10,D_L16_001A8F20,D_L16_001B1510,0x14F700,0,100,0,0,inner,outer,0.0f);
    if (effect) effect[2]=D_L16_001FF7F0[0];
    for (i=1;i>=0;i--) {
        effect=func_002C65A0(object+0x10,D_L16_001A8F20,D_L16_001B1510,0x38F738,0,127,0,0,inner,outer,0.0f);
        if (effect) effect[2]=D_L16_001FF7F0[5];
    }
    for (i=1;i>=0;i--) {
        effect=func_002C65A0(object+0x10,D_L16_001A8F20,D_L16_001B1510,0x38F738,0,127,0,0,inner,outer,0.0f);
        if (effect) effect[2]=D_L16_001FF7F0[6];
    }
    for (i=0;i<I(state,0x20);i++) {
        angle=func_00283248(D_L16_001B9B00[0]-F(object,0x10),D_L16_001B9B00[1]-F(object,0x14));
        phase=func_00283CF0(func_002A78D8(2.0f,5.0f));
        lifetime=func_002A7820(30,50);
        position[0]=F(object,0x10)+func_002A78D8(0.0f,0.1f)*F(state,0x14);
        position[1]=F(object,0x14)+func_002A78D8(0.0f,0.1f)*F(state,0x14);
        position[2]=F(object,0x18)+func_002A78D8(0.0f,0.1f)*F(state,0x14);
        size=func_002A7878(0.6f,1.0f)*F(state,0x14);
        speed=func_002A7878(9.0f,12.0f)*F(state,0x14);
        angle=func_00283B98(angle,func_002A78D8(0.0f,1.3962636f));
        velocity[0]=func_00283180(angle)*0.016666668f*speed;
        velocity[1]=func_00283198(angle)*0.016666668f*speed;
        velocity[2]=0.0f;
        velocity[2]=func_002A7878(0.0f,12.0f)*F(state,0x14)*0.016666668f;
        func_002C7970(position,velocity,lifetime,0xFF7F40,phase,127,127,1,size*210000.0f,F(state,0x14)*2100.0f,0.00405555591f);
        effect=func_002C7970(position,velocity,lifetime,0x20FF00,-phase*2,48,48,0,size*1260000.0f,F(state,0x14)*4200.0f,0.00405555591f);
        if (effect) effect[2]=D_L16_001FF754[0];
    }
    for (i=0;i<I(state,0x24);i++) {
        angle=func_00283248(D_L16_001B9B00[0]-F(object,0x10),D_L16_001B9B00[1]-F(object,0x14));
        phase=func_00283CF0(func_002A78D8(2.0f,5.0f));
        lifetime=func_002A7820(30,50);
        position[0]=F(object,0x10)+func_002A78D8(0.0f,0.1f)*F(state,0x14);
        position[1]=F(object,0x14)+func_002A78D8(0.0f,0.1f)*F(state,0x14);
        position[2]=F(object,0x18)+func_002A78D8(0.0f,0.1f)*F(state,0x14);
        size=func_002A7878(0.75f,1.5f)*F(state,0x14);
        speed=func_002A7878(9.0f,12.0f)*F(state,0x14);
        angle=func_00283B98(angle,func_002A78D8(0.0f,1.3962636f));
        velocity[0]=func_00283180(angle)*0.016666668f*speed;
        velocity[1]=func_00283198(angle)*0.016666668f*speed;
        velocity[2]=0.0f;
        velocity[2]=func_002A7878(0.0f,12.0f)*F(state,0x14)*0.016666668f;
        func_002C7970(position,velocity,lifetime,0x20FF00,phase,127,127,5,size*210000.0f,F(state,0x14)*2100.0f,0.00405555591f);
    }
    for (i=0;i<I(state,0x28);i++) {
        angle=func_00283248(D_L16_001B9B00[0]-F(object,0x10),D_L16_001B9B00[1]-F(object,0x14));
        phase=func_00283CF0(func_002A78D8(2.0f,5.0f));
        lifetime=func_002A7820(30,50);
        position[0]=F(object,0x10)+func_002A78D8(0.0f,0.1f)*F(state,0x14);
        position[1]=F(object,0x14)+func_002A78D8(0.0f,0.1f)*F(state,0x14);
        position[2]=F(object,0x18)+func_002A78D8(0.0f,0.1f)*F(state,0x14);
        size=func_002A7878(0.6f,1.0f)*F(state,0x14);
        speed=func_002A7878(9.0f,12.0f)*F(state,0x14);
        angle=func_00283B98(angle,func_002A78D8(0.0f,1.3962636f));
        velocity[0]=func_00283180(angle)*0.016666668f*speed;
        velocity[1]=func_00283198(angle)*0.016666668f*speed;
        velocity[2]=0.0f;
        velocity[2]=func_002A7878(0.0f,12.0f)*F(state,0x14)*0.016666668f;
        func_002C7970(position,velocity,lifetime,0x64FF30,phase,127,127,3,size*210000.0f,F(state,0x14)*2100.0f,0.00405555591f);
    }
    for (i=0;i<I(state,0x30);i++) {
        speed=func_002A7878(15.0f,20.0f)*F(state,0x14)*0.016666668f;
        func_00282D30(position,object+0xC0,speed);
        roll=func_002A78D8(0.26179942f,1.3962636f);
        turn=func_002A78D8(0.26179942f,1.3962636f);
        func_002AB668(rotation,(int)(object+0xD0),roll);
        func_002ACDE8(velocity,position,rotation);
        func_002AB668(rotation,(int)(object+0xC0),turn);
        func_002ACDE8(velocity,velocity,rotation);
        lifetime=func_002A7820(20,35);
        func_002C6DD8(object+0x10,velocity,lifetime,0.00405555591f);
    }
    if (I(state,0x34)) {
        *(Quad *)velocity=0;
        velocity[2]=F(state,0x14)*0.13333334f;
        *(Quad *)position=*(Quad *)velocity;
        func_00308408(object,object+0x10,position,16,0,0,255,40,F(state,0x14)*3.5f);
    }
    func_002ABBB8(object,D_L16_001A8F20,object+0x10,0,0,0,-1,0,0,-1,0,0x810001,0.0f,0.0f,0.0f,0.0f,9.0f,0.0f,F(state,0x14)*20.0f);
    sign=1;
    angle=func_00283248(D_L16_001B9B00[0]-F(object,0x10),D_L16_001B9B00[1]-F(object,0x14));
    for (i=0;i<I(state,0x2C);i++) {
        position[0]=F(object,0x10)+func_002A78D8(0.0f,1.0f)*F(state,0x14);
        sign=-sign;
        position[1]=F(object,0x14)+func_002A78D8(0.0f,1.0f)*F(state,0x14);
        position[2]=F(object,0x18)+func_002A78D8(0.0f,1.0f)*F(state,0x14);
        radius=func_002A7878(0.016666668f,0.033333335f)*F(state,0x14);
        roll=func_002A78D8(0.0f,1.3962636f);
        turn=func_00283B98(angle,func_002A78D8(0.0f,1.5707965f));
        func_002AF000(velocity,radius,turn,roll);
        effect=func_002BDCE8(position,sign,velocity,0x7F20FF60,0,0.0f,1.0f,1.01f,F(state,0x14)*315000.0f);
        if (effect) {
            *(u16 *)(effect+0xA)=func_002A7820(40,70);
            effect[9]=func_00283CF0(4.0f)+64;
            I(effect,0x24)=3;
            F(effect,0x3C)=func_00283CE0(func_002A7820(1,10));
            effect[0x2A]=64;
            effect[0x2B]=effect[0xA];
        }
    }
}
