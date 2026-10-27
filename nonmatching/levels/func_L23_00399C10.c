/* Retained complete C reconstruction; not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections.
 * Compiled 5828 bytes; retail 5868 bytes.
 * us: 0/1 placements match (exit 1).
 * us2: 0/1 placements match (exit 1).
 * pal: canonical name absent; no match credit.
 * Remaining: The true 32-bit cooldown, canonical metadata words and complete aligned
 * query/vector buffers are retained. Retail transient query addresses at SP+0x2C0 and SP+0x2D0,
 * and subsequent endpoint reuse at SP+0x2D0, justify the disjoint-lifetime workspace views. This
 * restores frame 0x440 instead of 0x470. The measured dual-target branches now retain 132 static
 * calls, as retail does. Register allocation, target-loop phase placement and packet schedules
 * remain different; matching frame and call count do not establish semantic or byte equality.
 * Reopen: Independent target-selection and per-arc lifetime evidence within the now-correct
 * workspace; preserve the 128-entry hidden-object list, full hit fields and four five-point
 * strips.
 */

#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef struct { int a,b,c,d; } __attribute__((aligned(16))) Quad16;
typedef struct {
    float direction[4] __attribute__((aligned(16))); void *owner; int flags;
    u8 type,active; u16 oclass; float damage; int enabled;
} __attribute__((aligned(16))) DamoselHit;

/* Retail gives the two transient query packets overlapping slots at +0x2C0
 * and +0x2D0, then reuses the latter address for the arc endpoint. Their
 * query lifetimes do not overlap; the simultaneous arc vectors are the
 * separate first and second rows of this workspace. */
typedef union {
    DamoselHit secondary;
    struct { u8 gap[16]; DamoselHit packet; } primary;
    struct { u8 gap[16]; float vector[4]; } temporary;
} DamoselWorkspace;

typedef struct { u8 pad[4]; u8 dual; u8 gap[0x6B]; float damage; u8 tail[0x6C]; } DamoselDamage;
#define F(p,o) (*(float *)((u8 *)(p)+(o)))
#define I(p,o) (*(int *)((u8 *)(p)+(o)))
#define S(p,o) (*(short *)((u8 *)(p)+(o)))
#define P(p,o) (*(u8 **)((u8 *)(p)+(o)))
extern DamoselDamage D_L23_00266A70[];
extern struct { u8 prefix[0x12]; u8 selected; } D_00139568;
extern u8 *D_0018C0B0,*D_L23_001FC560[],*D_L23_001C0A98;
extern float D_00189EA0[4],D_00189EB8,D_0018A0E0[4],D_0018A560[4],D_0018A570[4];
extern float D_L23_001BA640[],D_L23_001C0AA0[4],D_L23_001A8F20[4];
extern int D_L23_001A8FF0;
extern float D_L23_0023B1D0[][4],D_L23_0023B310[][4];
extern float D_L23_0023B450[],D_L23_0023B4A0[][4],D_L23_0023B5E0[];
extern float D_L23_0023B630[][5][4];
extern int D_L23_001B3040;
extern short D_L23_001B3048[],D_L23_001B3050[],D_L23_001B3058[],D_L23_001B3060[];
extern unsigned int D_L23_001AF028 __attribute__((sda));
extern float D_L23_001AEFC4 __attribute__((sda));
extern float D_L23_001AEFC8 __attribute__((sda));
extern float D_L23_001AEFCC __attribute__((sda));
extern float D_L23_001AEFD0 __attribute__((sda));
extern float D_L23_001AEFD4 __attribute__((sda));
extern float D_L23_001AEFD8 __attribute__((sda));
extern float D_L23_001AEFDC __attribute__((sda));
extern float D_L23_001AEFE0 __attribute__((sda));
extern float D_L23_001AEFE4 __attribute__((sda));
extern float D_L23_001AEFE8 __attribute__((sda));
extern float D_L23_001AEFEC __attribute__((sda));
extern float D_L23_001AEFF0 __attribute__((sda));
extern float D_L23_001AEFF4 __attribute__((sda));
extern float D_L23_001AEFF8 __attribute__((sda));
extern float D_L23_001AEFFC __attribute__((sda));
extern float D_L23_001AF000 __attribute__((sda));
extern float D_L23_001AF014 __attribute__((sda));
extern float D_L23_001AF018 __attribute__((sda));
extern float D_L23_001AF058 __attribute__((sda));
extern float D_L23_001AF05C __attribute__((sda));
extern float func_00283B98(float,float),func_00283BE0(float,float);
extern int func_002AB1F0(u8 *);
extern void func_00282CF0(void *,void *,void *),func_00282CC0(void *,void *,void *);
extern void func_00282D30(void *,void *,float),func_00282F20(void *,void *,float);
extern float func_00282DB0(void *,void *),func_00282DF0(void *),func_00282E20(void *);
extern float func_00282E48(void *,void *),func_00283248(float,float),func_00283C80(float,float),func_002831B0(float);
extern int func_00282948(int *),func_00282978(short *);
extern void func_00282C88(Quad *);
extern void func_002A8C00(char *,int,int,float,Quad16 *);
extern int func_00277F48(void *,int,void *,void *,float);
extern void func_00282DD8(void *,void *,void *),func_002ACEC0(void *,void *,void *,float);
extern float func_00283CE0(int),func_002ABB18(float),func_00283198(float),func_00283180(float);
extern float func_002A78D8(float,float),func_002A7878(float,float);
extern int func_002A7820(int,int),func_002A77E0(int),func_00283CF0(float);
extern void func_00300190(void *,void *);
extern void func_00282D08(void *,void *,void *,float);
extern int func_002761F8(void *,void *,int,void *,void *),func_002A8E20(void *,void *);
extern void *func_002C2210(void *,int,unsigned int,int,int,void *,int,float,float,float);

void func_L23_00399C10(u8 *object)
{
    float primaryPoint[4] __attribute__((aligned(16))),secondaryPoint[4],scratch[4],direction[4],axis[4],delta[4],blend[4],stepVector[4],toward[4],offset[4];
    float ripple[4][4] __attribute__((aligned(16)));
    DamoselHit hit;
    DamoselWorkspace work;
    u8 *hidden[128];
    u8 *state=P(object,0x68),*candidate,*properties,*best=0,*second=0;
    u8 **list;
    int hasSecondary,hitWall=0,hiddenCount=0,n,j,k,spin,remaining,difference;
    float bestScore=0.0f,secondScore=0.0f,score,distance,angle,pitch,a,b,c,length;
    float step=D_L23_001AEFC4*0.05f,segmentAngle,amplitude,wave,oldWave,blendWeight,sideAngle,phase1,phase2,sign;
    hasSecondary=D_L23_00266A70[D_00139568.selected].dual!=0;
    D_L23_001AEFDC=func_00283B98(D_L23_001AEFDC,D_L23_001AEFE0);
    D_L23_001AEFE4=func_00283BE0(D_L23_001AEFE4,D_L23_001AEFE8);
    D_L23_001AEFF8=func_00283B98(D_L23_001AEFF8,D_L23_001AEFFC);
    if (P(state,0x20)!=0 && (!hasSecondary || P(state,0x38)!=0)) goto targetsReady;
    if (P(state,0x38)!=0) {
        P(state,0x20)=P(state,0x38); S(state,0x40)=S(state,0x42);
        P(state,0x38)=0; S(state,0x42)=0;
        goto targetsReady;
    }
    for (list=D_L23_001FC560;(candidate=*list)!=0;list++) {
        if (candidate==P(state,0x20) || candidate==P(state,0x38) || P(candidate,0x24)==0 || S(P(candidate,0x24),0x46)!=5) continue;
        if (candidate[0x20]==254 || candidate[0x20]==253 || !func_002AB1F0(candidate)) continue;
        func_00282CF0(primaryPoint,candidate+0x10,state);
        if (!D_L23_001A8FF0) distance=func_00282E20(primaryPoint);
        else {
            a=func_00282DB0(primaryPoint,D_0018C0B0+0xE0);
            func_00282D30(secondaryPoint,D_0018C0B0+0xE0,a);
            func_00282CF0(scratch,primaryPoint,secondaryPoint);
            distance=func_00282DF0(scratch);
        }
        if (!(distance<=D_L23_001AEFC4)) continue;
        a=func_00283248(F(candidate,0x10)-D_L23_001BA640[0],F(candidate,0x14)-D_L23_001BA640[1]);
        angle=func_00283C80(D_L23_001BA640[6],a);
        if (!(angle<=D_L23_001AEFCC)) continue;
        pitch=0.0f;
        if (!D_L23_001A8FF0) {
            a=func_00283248(F(candidate,0x10)-D_00189EA0[0],F(candidate,0x14)-D_00189EA0[1]);
            pitch=func_00283C80(a,D_00189EB8);
        } else {
            func_00282CF0(secondaryPoint,candidate+0x10,D_00189EA0);
            a=func_00282DB0(secondaryPoint,D_0018C0B0+0xE0);
            func_00282D30(scratch,D_0018C0B0+0xE0,a);
            func_00282CF0(secondaryPoint,secondaryPoint,scratch);
            a=func_00282DB0(secondaryPoint,D_0018C0B0+0xC0);
            b=func_00282DF0(secondaryPoint);
            if (b==0.0f) continue;
            pitch=1.5707964f-func_002831B0(a/b);
        }
        if (!(pitch<=D_L23_001AEFC8)) continue;
        score=((D_L23_001AEFCC-angle)/D_L23_001AEFCC)*D_L23_001AF05C+(D_L23_001AEFC4-distance)/D_L23_001AEFC4;
        if (bestScore<score) { second=best; secondScore=bestScore; bestScore=score; best=candidate; }
        else if (secondScore<score) { second=candidate; secondScore=score; }
    }
targetsReady:
    if (best) {
        if (!P(state,0x20)) {
            S(state,0x40)=0; P(state,0x20)=best;
            if (func_00282948(&D_L23_001B3040)) D_L23_001B3040=10;
        } else second=best;
    }
    if (second && hasSecondary) {
        distance=func_00282E48(state,best+0x10);
        if (distance<D_L23_001AEFC4 && distance+func_00282E48(best+0x10,second+0x10)<D_L23_001AEFC4) {
            S(state,0x42)=0; P(state,0x38)=second;
        }
    }
    distance=0.0f;
    if (P(state,0x20)) {
        properties=(u8 *)func_002AB1F0(P(state,0x20));
        qcopy(primaryPoint,(P(state,0x20)+0x10));
        func_00282D30(secondaryPoint,P(state,0x20)+0xE0,F(properties,0x10));
        func_00282CC0(primaryPoint,primaryPoint,secondaryPoint);
        distance=func_00282E48(state,primaryPoint); step=distance*0.05f;
    }
    if (P(state,0x38)) {
        properties=(u8 *)func_002AB1F0(P(state,0x38));
        qcopy(secondaryPoint,(P(state,0x38)+0x10));
        func_00282D30(scratch,P(state,0x38)+0xE0,F(properties,0x10));
        func_00282CC0(secondaryPoint,secondaryPoint,scratch);
        step=(func_00282E48(primaryPoint,secondaryPoint)+distance)*0.05f;
    }
    D_L23_001AF028=hasSecondary?0x207F20:0x7F2020;
    func_00282C88((Quad *)scratch);
    func_002A8C00((char *)&hit,(int)object,0x210000,D_L23_00266A70[D_00139568.selected].damage,(Quad16 *)scratch);
    hit.oclass=*(u16 *)(object+0xAA); hit.active=1; hit.type=5; S(state,0x3E)=20;
    func_00277F48(state,16,D_0018C0B0,&hit,0.3f);
    func_00282CF0(direction,state+0x10,state);
    func_00282F20(direction,direction,1.0f);
    if (P(state,0x20) || P(state,0x38)) {
        func_00282DD8(axis,direction,D_0018A0E0);
        func_002ACEC0(direction,direction,axis,0.17453295f);
    }
    func_00282D30(stepVector,direction,step);
    qcopy(D_L23_0023B1D0[0],state);
    qcopy(D_L23_0023B310[0],state);
    for (n=1;n<=19;n++) {
        amplitude=D_L23_001AEFD4+(D_L23_001AEFD8-D_L23_001AEFD4)*func_00283CE0(n)*0.05f;
        segmentAngle=func_002ABB18(D_L23_001AEFDC+(float)n*D_L23_001AEFD0);
        a=func_00283198(segmentAngle);
        wave=amplitude*a+func_002A78D8(D_L23_001AF014,D_L23_001AF018);
        oldWave=D_L23_0023B450[n]; D_L23_0023B450[n]=wave;
        D_L23_0023B1D0[n][2]-=oldWave;
        func_00300190(D_L23_0023B1D0[n],D_L23_0023B1D0[n]);
        func_00282CF0(delta,D_L23_0023B1D0[n],D_L23_0023B1D0[n-1]);
        func_00282D08(blend,delta,stepVector,0.85f);
        length=func_00282DF0(blend);
        if (length==0.0f) qcopy(D_L23_0023B1D0[n],D_L23_0023B1D0[n-1]);
        else {
            func_00282D30(blend,blend,step/length);
            func_00282CC0(D_L23_0023B1D0[n],D_L23_0023B1D0[n-1],blend);
            qcopy(stepVector,blend);
        }
        D_L23_0023B1D0[n][2]+=wave;
        func_00282CF0(axis,D_L23_0023B1D0[n],D_L23_0023B1D0[n-1]);
        if (P(state,0x20)) {
            if (!hasSecondary || !P(state,0x38)) {
                func_00282CF0(toward,primaryPoint,D_L23_0023B1D0[n]);
                length=func_00282DF0(toward);
                if (length!=0.0f) {
                    if (n==19) { blendWeight=0.5f; step=length; }
                    else if (n<16) blendWeight=0.1f;
                    else { blendWeight=0.5f; step=length/func_00283CE0(19-n); }
                    func_00282D30(toward,toward,step/length);
                    func_00282D08(stepVector,stepVector,toward,blendWeight);
                }
            } else {
                if (n<10) func_00282CF0(toward,primaryPoint,D_L23_0023B1D0[n]);
                else func_00282CF0(toward,secondaryPoint,D_L23_0023B1D0[n]);
                length=func_00282DF0(toward);
                if (length!=0.0f) {
                    if (n==9 || n==19) { blendWeight=0.7f; step=length; }
                    else if ((unsigned int)(n-5)<5 || n>14) {
                        blendWeight=0.7f; step=length/func_00283CE0(n<10?9-n:19-n);
                    } else blendWeight=0.2f;
                    func_00282D30(toward,toward,step/length);
                    func_00282D08(stepVector,stepVector,toward,blendWeight);
                }
            }
        }
        if (n<10) {
            phase1=func_002ABB18(D_L23_001AEFE4+(float)n*D_L23_001AEFEC);
            phase2=func_002ABB18(D_L23_001AEFF8+(float)n*D_L23_001AF000);
            a=D_L23_001AEFF0*func_00283198(phase2);
            qcopy(D_L23_0023B310[n],D_L23_0023B1D0[n]);
            b=func_00283198(phase1); c=func_002A78D8(0.0f,0.1f);
            D_L23_0023B5E0[n]=a*b+c;
            D_L23_0023B310[n][2]+=D_L23_0023B5E0[n];
            sideAngle=func_00283B98(func_00283248(axis[0],axis[1]),1.5707965f);
            a=D_L23_001AEFF4*func_00283180(phase1);
            offset[0]=func_00283180(sideAngle)*a;
            offset[1]=func_00283198(sideAngle)*a;
            offset[2]=0.0f;
            qcopy(D_L23_0023B4A0[n],offset);
            func_00282CC0(D_L23_0023B310[n],D_L23_0023B310[n],offset);
        } else {
            qcopy(D_L23_0023B310[n],D_L23_0023B1D0[n]);
            D_L23_0023B310[n][2]+=D_L23_0023B5E0[21-n];
            func_00282CC0(D_L23_0023B310[n],D_L23_0023B310[n],D_L23_0023B4A0[21-n]);
            qcopy(offset,D_L23_0023B4A0[n]);
        }
        if (n>1 && (n==19 || !(n&1))) {
            func_00282CF0(scratch,D_L23_0023B1D0[n],D_L23_001BA640);
            if (!D_L23_001A8FF0) scratch[2]=0.0f;
            else {
                a=func_00282DB0(scratch,D_0018C0B0+0xE0);
                func_00282D30(toward,D_0018C0B0+0xE0,a);
                func_00282CF0(scratch,scratch,toward);
            }
            length=func_00282DF0(scratch);
            if (length==0.0f) scratch[2]=1.0f;
            else func_00282D30(scratch,scratch,1.0f/length);
            scratch[3]=5627.9248f;
            qcopy(hit.direction,scratch);
            hitWall=func_002761F8(D_L23_0023B1D0[n-2],D_L23_0023B1D0[n],16,object,0);
            candidate=D_L23_001C0A98;
            if (hitWall) {
                if (candidate) {
                    properties=(u8 *)func_002AB1F0(candidate);
                    if (!properties || !P(candidate,0x24) || S(P(candidate,0x24),0x46)!=5) func_002A8E20(candidate,&hit);
                    else { hitWall=0; hidden[hiddenCount++]=candidate; I(candidate,0x98)=0; }
                }
                if (hitWall) {
                    qcopy(D_L23_0023B1D0[n],D_L23_001C0AA0);
                    S(state,0x3E)=n;
                    qcopy((state+0x10),D_L23_001C0AA0);
                    if (!D_L23_001C0A98) { P(state,0x20)=0; S(state,0x40)=0; }
                    break;
                }
            }
        }
    }
    for (j=0;j<hiddenCount;j++) I(hidden[j],0x98)=I(P(hidden[j],0x24),0x10);
    if (!hitWall) qcopy((state+0x10),D_L23_0023B1D0[19]);
    if (P(state,0x20) && (*(u64 *)(state+0x40)&0xFFFF0000FFFFULL)==0) {
        func_00282CF0(toward,P(state,0x20)+0x10,D_L23_001BA640);
        if (!D_L23_001A8FF0) toward[2]=0.0f;
        else {
            a=func_00282DB0(toward,D_0018C0B0+0xE0);
            func_00282D30(work.temporary.vector,D_0018C0B0+0xE0,a); func_00282CF0(toward,toward,work.temporary.vector);
        }
        func_00282F20(toward,toward,1.0f); toward[3]=5627.9248f;
        func_002A8C00((char *)&work.primary.packet,(int)object,0x210000,D_L23_00266A70[D_00139568.selected].damage,(Quad16 *)toward);
        work.primary.packet.oclass=*(u16 *)(object+0xAA); work.primary.packet.active=3; work.primary.packet.type=5;
        func_002A8E20(P(state,0x20),&work.primary.packet);
        properties=(u8 *)func_002AB1F0(P(state,0x20));
        S(state,0x44)=properties && S(properties,4)==1?1:5;
    }
    if (P(state,0x38) && (*(u64 *)(state+0x40)&0xFFFF0000FFFF0000ULL)==0) {
        func_00282CF0(toward,P(state,0x38)+0x10,D_L23_001BA640);
        if (!D_L23_001A8FF0) toward[2]=0.0f;
        else {
            a=func_00282DB0(toward,D_0018C0B0+0xE0);
            func_00282D30(work.temporary.vector,D_0018C0B0+0xE0,a); func_00282CF0(toward,toward,work.temporary.vector);
        }
        func_00282F20(toward,toward,1.0f); toward[3]=5627.9248f;
        func_002A8C00((char *)&work.secondary,(int)object,0x210000,D_L23_00266A70[D_00139568.selected].damage,(Quad16 *)toward);
        work.secondary.oclass=*(u16 *)(object+0xAA); work.secondary.active=3; work.secondary.type=5;
        func_002A8E20(P(state,0x38),&work.secondary);
        properties=(u8 *)func_002AB1F0(P(state,0x38));
        S(state,0x46)=properties && S(properties,4)==1?1:5;
    }
    for (j=0;j<4;j++) {
        qcopy(work.temporary.vector,(j<2?state:state+0x10));
        if (!func_00282978(&D_L23_001B3048[j])) {
            for (k=0;k<4;k++) {
                func_00282CF0(ripple[k],D_L23_0023B630[j][k+1],D_L23_0023B630[j][k]);
                ripple[k][0]+=func_002A78D8(0.0f,0.1f);
                ripple[k][1]+=func_002A78D8(0.0f,0.1f);
                ripple[k][2]+=func_002A78D8(0.0f,0.1f);
            }
            qcopy(D_L23_0023B630[j][0],work.temporary.vector);
            for (k=0;k<4;k++) func_00282CC0(D_L23_0023B630[j][k+1],D_L23_0023B630[j][k],ripple[k]);
            difference=D_L23_001B3048[j]-D_L23_001B3060[j];
            if (difference<0) difference=-difference;
            D_L23_001B3050[j]=func_00283CF0((1.0f-func_00283CE0(difference)/func_00283CE0(15))*32.0f);
        } else {
            D_L23_001B3048[j]=D_L23_001B3058[j]; D_L23_001B3050[j]=0;
            a=func_002A78D8(0.52359885f,1.0471977f); b=func_002A7878(-1.0471977f,0.17453295f);
            func_00282D30(toward,direction,j<2?0.4f:0.5f);
            func_002ACEC0(toward,toward,D_0018A560,b); func_002ACEC0(toward,toward,D_0018A570,a);
            qcopy(D_L23_0023B630[j][0],work.temporary.vector);
            func_00282CC0(D_L23_0023B630[j][1],work.temporary.vector,toward);
            sign=1.0f;
            for (k=1;k<=3;k++) {
                func_00282CF0((float *)&work.secondary,D_L23_0023B630[j][k],D_L23_001BA640);
                a=func_002A7878(0.17453295f,0.9599312f)*sign; sign=-sign;
                func_002ACEC0(toward,toward,&work.secondary,a);
                func_00282CC0(D_L23_0023B630[j][k+1],D_L23_0023B630[j][k],toward);
            }
        }
    }
    a=func_002A78D8(0.52359885f,1.0471977f); b=func_002A7878(-0.52359885f,1.0471977f);
    func_00282D30(toward,direction,D_L23_001AF058);
    func_002ACEC0(toward,toward,D_0018A560,b); func_002ACEC0(toward,toward,D_0018A570,a);
    spin=func_002A7820(1,8); if (func_002A77E0(2)) spin=-spin;
    a=func_002A7878(0.2f,0.6f);
    func_002C2210(state,15,D_L23_001AF028|0x7F000000,0,spin,toward,1,a*0.3f,a,0.0f);
    func_002C2210(state,15,0x307F7F7F,0,-spin,toward,1,a*0.15f,a*0.5f,0.0f);
    spin=func_002A7820(1,8); if (func_002A77E0(2)) spin=-spin;
    a=func_002A7878(0.15f,3.0f);
    func_002C2210(state+0x10,12,D_L23_001AF028|0x7F000000,0,spin,D_L23_001A8F20,1,a*0.1f,a,0.0f);
}
