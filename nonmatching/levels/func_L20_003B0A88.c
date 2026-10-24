/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 5756 / 5868 bytes; size equality is not a match.
 * us: 0/1 placements; 5756/5868 bytes.
 * us2: not run after us mismatch; no exact candidate.
 * pal: not run after us mismatch; no exact candidate.
 * Residual: Four source/profile trials; final 5756 versus 5868 bytes, frame0x470 versus 0x440. The complete beam targeting and twenty-point update, both damage-query paths, collider restoration, four five-point spark chains and three particle emissions are reconstructed. The decompiler HI-register artifacts were resolved from real 32-bit indices, not copied. Remaining differences include query scopes, float lifetimes and allocation.
 * Reopening condition: Recover shared query/local lifetimes and seven-FPR allocation before considering smaller scheduling differences; preserve real20-element arrays and128-pointer obstacle workspace.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Not matched, 2026-10-23.
 * Four source/profile trials; final 5756 versus 5868 bytes, frame0x470 versus 0x440. The complete beam targeting and twenty-point update, both damage-query paths, collider restoration, four five-point spark chains and three particle emissions are reconstructed. The decompiler HI-register artifacts were resolved from real 32-bit indices, not copied. Remaining differences include query scopes, float lifetimes and allocation.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * Final us check: func_L20_003B0A88: 0 of 1 places match (src/levels/20_yeedil/L20_003B0A88-g8.c); exit 1.
 * This source has not passed a linked build or a runtime test.
 */
#include "common.h"
typedef int Quadword __attribute__((mode(TI)));
typedef union { Quadword q; float f[4]; } Vector;
typedef struct { Vector direction; u8 *owner; u32 flags; u8 type,kind; u16 objectClass; float radius; int active; float field24; } CollisionQuery;
typedef struct { u8 prefix[4]; u8 dual; u8 gap[0x6b]; float radius; u8 tail[0x6c]; } BeamSettings;
extern BeamSettings D_L20_0026D970[];
extern u8 D_00139568[];
extern u8 D_00189E20[];
extern u8 *D_L20_001FBEE0[];
extern int D_L20_001A8FF0;
extern Vector D_0018A0E0,D_0018A560,D_0018A570,D_L20_001A8F20;
extern u8 D_L20_001B9FC0[];
extern u8 *D_L20_001C0418;
extern Vector D_L20_001C0420;
extern Vector D_L20_0023CAB0[20],D_L20_0023CBF0[20];
extern float D_L20_0023CD30[20],D_L20_0023CEC0[20];
extern Vector D_L20_0023CD80[20],D_L20_0023CF10[4][5];
extern int D_L20_001B3910 __attribute__((nosda));
extern s16 D_L20_001B3918[4],D_L20_001B3920[4],D_L20_001B3928[4],D_L20_001B3930[4];
extern float D_L20_001AF204 __attribute__((sda)),D_L20_001AF208 __attribute__((sda)),D_L20_001AF20C __attribute__((sda));
extern float D_L20_001AF210 __attribute__((sda)),D_L20_001AF214 __attribute__((sda)),D_L20_001AF218 __attribute__((sda));
extern float D_L20_001AF21C __attribute__((sda)),D_L20_001AF220 __attribute__((sda)),D_L20_001AF224 __attribute__((sda));
extern float D_L20_001AF228 __attribute__((sda)),D_L20_001AF22C __attribute__((sda)),D_L20_001AF230 __attribute__((sda)),D_L20_001AF234 __attribute__((sda));
extern float D_L20_001AF23C __attribute__((sda));
extern float D_L20_001AF238 __attribute__((sda)),D_L20_001AF240 __attribute__((sda)),D_L20_001AF244 __attribute__((sda));
extern float D_L20_001AF254 __attribute__((sda)),D_L20_001AF258 __attribute__((sda)),D_L20_001AF260 __attribute__((sda));
extern float D_L20_001AF298 __attribute__((sda)),D_L20_001AF29C __attribute__((sda));
extern u32 D_L20_001AF268 __attribute__((sda));
extern int func_002AB1F0(u8 *);
extern float func_00283B98(float,float),func_00283BE0(float,float),func_00283C80(float,float);
extern float func_00282DB0(void *,void *),func_00282DF0(void *),func_00282E20(void *),func_00282E48(void *,void *);
extern float func_00283248(float,float),func_00283180(float),func_00283198(float),func_002831B0(float),func_00283CE0(int),func_002ABB18(float);
extern float func_002A7878(float,float),func_002A78D8(float,float);
extern int func_002A7820(int,int),func_002A77E0(int),func_00283CF0(float),func_00282948(void *),func_00282978(void *);
extern void func_00282CF0(void *,void *,void *),func_00282CC0(void *,void *,void *),func_00282DD8(void *,void *,void *);
extern void func_00282D30(void *,void *,float),func_00282F20(void *,void *,float),func_00282D08(void *,void *,void *,float);
extern void func_00282C88(Quadword *),func_00300190(void *,void *);
extern void func_002ACEC0(void *,void *,void *,float);
typedef struct { int a,b,c,d; } __attribute__((aligned(16))) Quad16;
extern void func_002A8C00(char *,int,int,float,Quad16 *);
extern int func_00277F48(void *,int,void *,void *,float),func_002761F8(void *,void *,int,void *,void *);
extern void func_002A8E20(void *,void *);
extern void *func_002C2210(void *,int,u32,int,int,void *,int,float,float,float);

void func_L20_003B0A88(u8 *object)
{
    Vector delta,scaled,work;
    CollisionQuery query;
    Vector direction,cross,stepDelta,previousDelta,noise;
    u8 *disabled[128];
    Vector aim,projection;
    Vector chainDelta[4];
    u8 *state=*(u8 **)(object+0x68);
    u8 *first=0,*second=0,*candidate,*details,*target;
    Vector *point,*side;
    float best=0,runnerUp=0,distance,heading,cameraAngle,playerAngle,score,dot,length;
    float spacing=D_L20_001AF204*0.05f,phase,amplitude,offset,oldOffset,blend,sidePhase,otherPhase,sideAmplitude,rotation,radius,sign;
    int dual=D_L20_0026D970[D_00139568[0x12]].dual!=0;
    int i,j,hit=0,disabledCount=0,timerDifference,speed;
    u16 impactKind;
    D_L20_001AF21C=func_00283B98(D_L20_001AF21C,D_L20_001AF220);
    D_L20_001AF224=func_00283BE0(D_L20_001AF224,D_L20_001AF228);
    D_L20_001AF238=func_00283B98(D_L20_001AF238,D_L20_001AF23C);
    if (*(u8 **)(state+0x20) && (!dual || *(u8 **)(state+0x38))) goto targets_ready;
    if (*(u8 **)(state+0x38)) {
        *(u8 **)(state+0x20)=*(u8 **)(state+0x38);
        *(u16 *)(state+0x40)=*(u16 *)(state+0x42);
        *(int *)(state+0x38)=0;*(u16 *)(state+0x42)=0;
    } else {
        for(i=0;(candidate=D_L20_001FBEE0[i])!=0;i++) {
            if (candidate==*(u8 **)(state+0x20) || candidate==*(u8 **)(state+0x38) || !*(int *)(candidate+0x24) || *(s16 *)(*(u8 **)(candidate+0x24)+0x46)!=5 || candidate[0x20]==254 || candidate[0x20]==253) continue;
            if (!func_002AB1F0(candidate)) continue;
            func_00282CF0(&delta,candidate+0x10,state);
            if (!D_L20_001A8FF0) distance=func_00282E20(&delta);
            else {
                dot=func_00282DB0(&delta,(*(u8 **)(D_00189E20+0x2290))+0xe0);
                func_00282D30(&scaled,(*(u8 **)(D_00189E20+0x2290))+0xe0,dot);
                func_00282CF0(&work,&delta,&scaled);distance=func_00282DF0(&work);
            }
            if (distance>D_L20_001AF204) continue;
            heading=func_00283248(*(float *)(candidate+0x10)-*(float *)(D_L20_001B9FC0),*(float *)(candidate+0x14)-*(float *)(D_L20_001B9FC0+4));
            cameraAngle=func_00283C80(*(float *)(D_L20_001B9FC0+0x18),heading);
            if (cameraAngle>D_L20_001AF20C) continue;
            playerAngle=0;
            if (!D_L20_001A8FF0) {
                heading=func_00283248(*(float *)(candidate+0x10)-*(float *)(D_00189E20+0x80),*(float *)(candidate+0x14)-*(float *)(D_00189E20+0x84));
                playerAngle=func_00283C80(heading,*(float *)(D_00189E20+0x98));
            } else {
                func_00282CF0(&scaled,candidate+0x10,D_00189E20+0x80);
                dot=func_00282DB0(&scaled,(*(u8 **)(D_00189E20+0x2290))+0xe0);
                func_00282D30(&work,(*(u8 **)(D_00189E20+0x2290))+0xe0,dot);
                func_00282CF0(&scaled,&scaled,&work);
                dot=func_00282DB0(&scaled,(*(u8 **)(D_00189E20+0x2290))+0xc0);
                length=func_00282DF0(&scaled);if (!length) continue;
                playerAngle=1.5707964f-func_002831B0(dot/length);
            }
            if (playerAngle>D_L20_001AF208) continue;
            score=((D_L20_001AF20C-cameraAngle)/D_L20_001AF20C)*D_L20_001AF29C+(D_L20_001AF204-distance)/D_L20_001AF204;
            if (best<score) {second=first;runnerUp=best;first=candidate;best=score;}
            else if (runnerUp<score) {second=candidate;runnerUp=score;}
        }
    }
targets_ready:
    if (first) {
        if (!*(u8 **)(state+0x20)) {
            *(u16 *)(state+0x40)=0;*(u8 **)(state+0x20)=first;
            if (func_00282948(&D_L20_001B3910)) D_L20_001B3910=10;
        } else second=first;
    }
    if (second && dual) {
        distance=func_00282E48(state,first+0x10);
        if (distance<D_L20_001AF204 && distance+func_00282E48(first+0x10,second+0x10)<D_L20_001AF204) {
            *(u16 *)(state+0x42)=0;*(u8 **)(state+0x38)=second;
        }
    }
    distance=0;
    target=*(u8 **)(state+0x20);
    if (target) {
        details=(u8 *)func_002AB1F0(target);
        delta.q=*(Quadword *)(target+0x10);
        func_00282D30(&scaled,target+0xe0,*(float *)(details+0x10));
        func_00282CC0(&delta,&delta,&scaled);
        distance=func_00282E48(state,&delta);spacing=distance*0.05f;
    }
    target=*(u8 **)(state+0x38);
    if (target) {
        details=(u8 *)func_002AB1F0(target);
        scaled.q=*(Quadword *)(target+0x10);
        func_00282D30(&work,target+0xe0,*(float *)(details+0x10));
        func_00282CC0(&scaled,&scaled,&work);
        spacing=(func_00282E48(&delta,&scaled)+distance)*0.05f;
    }
    D_L20_001AF268=dual?0x207f20:0x7f2020;
    func_00282C88(&work.q);
    func_002A8C00((char *)&query,(int)object,0x210000,D_L20_0026D970[D_00139568[0x12]].radius,(Quad16 *)&work);
    query.objectClass=*(u16 *)(object+0xaa);query.kind=1;query.type=5;
    *(u16 *)(state+0x3e)=20;
    func_00277F48(state,16,(*(u8 **)(D_00189E20+0x2290)),&query,0.3f);
    func_00282CF0(&direction,state+0x10,state);func_00282F20(&direction,&direction,1.0f);
    if (*(int *)(state+0x20) || *(int *)(state+0x38)) {
        func_00282DD8(&cross,&direction,&D_0018A0E0);func_002ACEC0(&direction,&direction,&cross,0.17453295f);
    }
    func_00282D30(&previousDelta,&direction,spacing);
    D_L20_0023CAB0[0].q=*(Quadword *)state;D_L20_0023CBF0[0].q=*(Quadword *)state;
    for(i=1;i<20;i++) {
        point=&D_L20_0023CAB0[i];side=&D_L20_0023CBF0[i];
        amplitude=D_L20_001AF214+(D_L20_001AF218-D_L20_001AF214)*func_00283CE0(i)*0.05f;
        phase=func_002ABB18(D_L20_001AF21C+(float)i*D_L20_001AF210);
        offset=amplitude*func_00283198(phase)+func_002A78D8(D_L20_001AF254,D_L20_001AF258);
        oldOffset=D_L20_0023CD30[i];D_L20_0023CD30[i]=offset;point->f[2]-=oldOffset;
        func_00300190(point,point);
        func_00282CF0(&cross,point,&D_L20_0023CAB0[i-1]);
        func_00282D08(&stepDelta,&cross,&previousDelta,0.85f);
        length=func_00282DF0(&stepDelta);
        if (!length) point->q=D_L20_0023CAB0[i-1].q;
        else {
            func_00282D30(&stepDelta,&stepDelta,spacing/length);
            func_00282CC0(point,&D_L20_0023CAB0[i-1],&stepDelta);previousDelta.q=stepDelta.q;
        }
        point->f[2]+=offset;
        func_00282CF0(&cross,point,&D_L20_0023CAB0[i-1]);
        if (*(int *)(state+0x20)) {
            if (!dual || !*(int *)(state+0x38)) {
                func_00282CF0(&aim,&delta,point);length=func_00282DF0(&aim);
                if (length) {
                    if (i==19) {blend=0.5f;spacing=length;}
                    else if (i<16) blend=0.1f;
                    else {blend=0.5f;spacing=length/func_00283CE0(19-i);}
                    func_00282D30(&aim,&aim,spacing/length);func_00282D08(&previousDelta,&previousDelta,&aim,blend);
                }
            } else {
                func_00282CF0(&aim,i<10?(void *)&delta:(void *)&scaled,point);length=func_00282DF0(&aim);
                if (length) {
                    if (i==9 || i==19) {blend=0.7f;spacing=length;}
                    else if ((u32)(i-5)<5 || i>14) {blend=0.7f;spacing=length/func_00283CE0(i<10?9-i:19-i);}
                    else blend=0.2f;
                    func_00282D30(&aim,&aim,spacing/length);func_00282D08(&previousDelta,&previousDelta,&aim,blend);
                }
            }
        }
        if (i<10) {
            sidePhase=func_002ABB18(D_L20_001AF224+(float)i*D_L20_001AF22C);
            otherPhase=func_002ABB18(D_L20_001AF238+(float)i*D_L20_001AF240);
            amplitude=D_L20_001AF230*func_00283198(otherPhase);
            side->q=point->q;
            sideAmplitude=amplitude*func_00283198(sidePhase)+func_002A78D8(0.0f,0.1f);
            D_L20_0023CEC0[i]=sideAmplitude;side->f[2]+=sideAmplitude;
            rotation=func_00283B98(func_00283248(cross.f[0],cross.f[1]),1.5707965f);
            amplitude=D_L20_001AF234*func_00283180(sidePhase);
            noise.f[0]=func_00283180(rotation)*amplitude;noise.f[1]=func_00283198(rotation)*amplitude;
            D_L20_0023CD80[i].q=noise.q;noise.f[2]=0;
            func_00282CC0(side,side,&noise);
        } else {
            side->q=point->q;side->f[2]+=D_L20_0023CEC0[21-i];
            func_00282CC0(side,side,&D_L20_0023CD80[21-i]);noise.q=D_L20_0023CD80[i].q;
        }
        if (i>1 && (i==19 || !(i&1))) {
            func_00282CF0(&work,point,D_L20_001B9FC0);
            if (!D_L20_001A8FF0) work.f[2]=0;
            else {
                dot=func_00282DB0(&work,(*(u8 **)(D_00189E20+0x2290))+0xe0);
                func_00282D30(&aim,(*(u8 **)(D_00189E20+0x2290))+0xe0,dot);func_00282CF0(&work,&work,&aim);
            }
            length=func_00282DF0(&work);
            if (!length) work.f[2]=1;else func_00282D30(&work,&work,1.0f/length);
            work.f[3]=5627.9248046875f;query.direction.q=work.q;
            hit=func_002761F8(&D_L20_0023CAB0[i-2],point,16,object,0);
            if (hit) {
                target=D_L20_001C0418;
                if (target) {
                    details=(u8 *)func_002AB1F0(target);
                    if (!details || !*(int *)(target+0x24) || *(s16 *)(*(u8 **)(target+0x24)+0x46)!=5) func_002A8E20(target,&query);
                    else {hit=0;disabled[disabledCount++]=target;*(int *)(target+0x98)=0;}
                }
                if (hit) {
                    point->q=D_L20_001C0420.q;*(u16 *)(state+0x3e)=i;*(Quadword *)(state+0x10)=D_L20_001C0420.q;
                    if (!D_L20_001C0418) {*(int *)(state+0x20)=0;*(u16 *)(state+0x40)=0;}
                    break;
                }
            }
        }
    }
    for(i=0;i<disabledCount;i++) *(int *)(disabled[i]+0x98)=*(int *)(*(u8 **)(disabled[i]+0x24)+0x10);
    if (!hit) *(Quadword *)(state+0x10)=D_L20_0023CAB0[19].q;
    target=*(u8 **)(state+0x20);
    if (target && !(*(u64 *)(state+0x40)&0xffff0000ffffULL)) {
        CollisionQuery primaryQuery;
        func_00282CF0(&aim,target+0x10,D_L20_001B9FC0);
        if (!D_L20_001A8FF0) aim.f[2]=0;
        else {dot=func_00282DB0(&aim,(*(u8 **)(D_00189E20+0x2290))+0xe0);func_00282D30(&projection,(*(u8 **)(D_00189E20+0x2290))+0xe0,dot);func_00282CF0(&aim,&aim,&projection);}
        func_00282F20(&aim,&aim,1.0f);aim.f[3]=5627.9248046875f;
        func_002A8C00((char *)&primaryQuery,(int)object,0x210000,D_L20_0026D970[D_00139568[0x12]].radius,(Quad16 *)&aim);
        primaryQuery.objectClass=*(u16 *)(object+0xaa);primaryQuery.kind=3;primaryQuery.type=5;
        func_002A8E20(target,&primaryQuery);details=(u8 *)func_002AB1F0(target);
        impactKind=5;if (details && *(s16 *)(details+4)==1) impactKind=1;*(u16 *)(state+0x44)=impactKind;
    }
    target=*(u8 **)(state+0x38);
    if (target && !(*(u64 *)(state+0x40)&0xffff0000ffff0000ULL)) {
        CollisionQuery secondaryQuery;
        func_00282CF0(&aim,target+0x10,D_L20_001B9FC0);
        if (!D_L20_001A8FF0) aim.f[2]=0;
        else {dot=func_00282DB0(&aim,(*(u8 **)(D_00189E20+0x2290))+0xe0);func_00282D30(&projection,(*(u8 **)(D_00189E20+0x2290))+0xe0,dot);func_00282CF0(&aim,&aim,&projection);}
        func_00282F20(&aim,&aim,1.0f);aim.f[3]=5627.9248046875f;
        func_002A8C00((char *)&secondaryQuery,(int)object,0x210000,D_L20_0026D970[D_00139568[0x12]].radius,(Quad16 *)&aim);
        secondaryQuery.objectClass=*(u16 *)(object+0xaa);secondaryQuery.kind=3;secondaryQuery.type=5;
        func_002A8E20(target,&secondaryQuery);details=(u8 *)func_002AB1F0(target);
        impactKind=5;if (details && *(s16 *)(details+4)==1) impactKind=1;*(u16 *)(state+0x46)=impactKind;
    }
    for(i=0;i<4;i++) {
        projection.q=*(Quadword *)(state+(i<2?0:0x10));radius=i<2?0.4f:0.5f;
        if (!func_00282978(&D_L20_001B3918[i])) {
            for(j=0;j<4;j++) {
                func_00282CF0(&chainDelta[j],&D_L20_0023CF10[i][j+1],&D_L20_0023CF10[i][j]);
                chainDelta[j].f[0]+=func_002A78D8(0.0f,0.1f);chainDelta[j].f[1]+=func_002A78D8(0.0f,0.1f);chainDelta[j].f[2]+=func_002A78D8(0.0f,0.1f);
            }
            D_L20_0023CF10[i][0].q=projection.q;
            for(j=0;j<4;j++) func_00282CC0(&D_L20_0023CF10[i][j+1],&D_L20_0023CF10[i][j],&chainDelta[j]);
            timerDifference=D_L20_001B3918[i]-D_L20_001B3930[i];if (timerDifference<0) timerDifference=-timerDifference;
            D_L20_001B3920[i]=func_00283CF0((1.0f-func_00283CE0(timerDifference)/func_00283CE0(15))*32.0f);
        } else {
            D_L20_001B3918[i]=D_L20_001B3928[i];D_L20_001B3920[i]=0;
            phase=func_002A78D8(0.52359885f,1.0471977f);rotation=func_002A7878(-1.0471977f,0.17453295f);
            func_00282D30(&aim,&direction,radius);func_002ACEC0(&aim,&aim,&D_0018A560,rotation);func_002ACEC0(&aim,&aim,&D_0018A570,phase);
            D_L20_0023CF10[i][0].q=projection.q;func_00282CC0(&D_L20_0023CF10[i][1],&projection,&aim);
            sign=1;
            for(j=0;j<3;j++) {
                Vector flareAxis;
                func_00282CF0(&flareAxis,&D_L20_0023CF10[i][j+1],D_L20_001B9FC0);
                rotation=func_002A7878(0.17453295f,0.96f)*sign;sign=-sign;
                func_002ACEC0(&aim,&aim,&flareAxis,rotation);func_00282CC0(&D_L20_0023CF10[i][j+2],&D_L20_0023CF10[i][j+1],&aim);
            }
        }
    }
    phase=func_002A78D8(0.52359885f,1.0471977f);rotation=func_002A7878(-0.52359885f,1.0471977f);
    func_00282D30(&aim,&direction,D_L20_001AF298);func_002ACEC0(&aim,&aim,&D_0018A560,rotation);func_002ACEC0(&aim,&aim,&D_0018A570,phase);
    speed=func_002A7820(1,8);if (func_002A77E0(2)) speed=-speed;
    radius=func_002A7878(0.2f,0.6f);
    func_002C2210(state,15,D_L20_001AF268|0x7f000000,0,speed,&aim,1,radius*0.3f,radius,0.0f);
    func_002C2210(state,15,0x307f7f7f,0,-speed,&aim,1,radius*0.15f,radius*0.5f,0.0f);
    speed=func_002A7820(1,8);if (func_002A77E0(2)) speed=-speed;
    radius=func_002A7878(0.15f,3.0f);
    func_002C2210(state+0x10,12,D_L20_001AF268|0x7f000000,0,speed,&D_L20_001A8F20,1,radius*0.1f,radius,0.0f);
}
