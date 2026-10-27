/*
 * Retained complete manual reconstruction; not linked or counted.
 * Profile: -O2 -G16 -Wa,-G16 -ffunction-sections -frac2-zero-ti-por -g
 * Retail: 5504 bytes; compiled: 5416 bytes.
 * Final coverage: us: 0/1; us2: catalogue absent; pal: catalogue absent.
 * Residual: 5416/5504 bytes with the 0xB0 frame. The complete sentry state machine, full
 * target transfers and particle/child constructor stack inputs are retained.
 * Resident/effect globals are externally incomplete and accessed through measured
 * prefixes. State/resident register assignment, switch lower bound and branch/schedule
 * sharing differ. Full retail semantics is not yet qualified.
 * Reopen: A real dispatch/local-field lifetime witness. The explicit resident local
 * produced 5404 bytes and is preserved privately. The older source-only compiler-copy
 * profiles and neutral debug toggles are not new evidence; preserve the whole body and
 * actual integer mode width.
 */
#include "common.h"

typedef int Quadword __attribute__((mode(TI)));
typedef struct { u8 prefix[0x2C0]; float waypoint[4]; float previousPosition[4]; } WaypointView;
/* Partial current dispatch context; the payload's full extent is not inferred. */
typedef struct {
    u8 reserved_00[0x18]; u8 enabled, count, kind; u8 reserved_1b[0x65]; u8 payload[1];
} Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchContext;
typedef unsigned long Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchFlags;
typedef struct { u8 prefix[0x20]; float amount; int reserved24; int kind; int detail; } EffectTuning;
extern u8 D_L02_001BA500[];
#define EFFECT ((EffectTuning *)D_L02_001BA500)
extern float D_L02_001B3F58 __attribute__((sda));
extern float D_L02_001B01B0[4] __attribute__((sda));
extern float D_L02_001B01C0[4] __attribute__((sda));
extern float D_L02_001B01D0[4] __attribute__((sda));
extern int D_L02_001B01E0 __attribute__((sda));
extern int D_L02_001A903C;
typedef struct { u8 prefix[0x229C]; int motion; u8 reserved22A0[0x1FC]; char *damage; } ResidentView;
extern u8 D_00189E20[];
#define RESIDENT ((ResidentView *)D_00189E20)
#define D_0018C2BC RESIDENT->damage
extern u8 D_001A7A61;
extern float D_00189EA0[4];
extern void func_L02_003D4308(char *);
extern float func_00282E80(void *, void *);
extern float func_00282E48(void *, void *);
extern float func_00283248(float, float);
extern float func_0029F530(char *);
extern int func_002B3890(u8 *);
extern int func_002B3868(u8 *);
extern void *func_002B60B0(u8 *, float, float, float, float);
extern void func_L02_003D5B90(char *);
/* The retail callback site supplies a parent even though this leaf ignores it. */
extern int func_L00_0042AB40();
extern void func_002A7470(char *, int, int, int);
extern void func_002A7750(u8 *, s32, s32);
extern void func_L02_003D4ED0(char *);
extern void func_L02_003D4FD0(char *, Quadword *, float, float);
extern float func_002A7878(float, float);
extern int func_002A77E0(int);
extern void func_L02_003D4A48(char *);
extern void func_L02_003DB880(char *);
extern void func_L02_003FC020(char *, char *);
extern void func_002B5258(char *);
extern void func_L02_003D4AF0(char *, int);
extern float func_L02_002F21C0(void *, void *);
extern int func_L01_00321178(char *, char *);
extern float func_00283C80(float, float);
extern void func_L02_003D69F0(void);
extern void func_L02_003D5118(char *, int);
extern void func_L02_003D6690(char *, int);
extern int func_L02_003D4D00(char *);
extern int func_L02_003D4A60(char *);
extern Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchFlags func_002B1C20(void *, Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchContext *);
/* Extra caller slots are retained at this legacy entry; its leaf ignores them. */
extern void func_L02_003FC248(void *, int, int);
extern int func_002E5E58(int, int, void *);
extern void func_002B0A18(int, int);
extern void func_L01_003E9CF8(char *, int, void (*)(char *));
extern void func_L02_003D4900(char *);
extern void func_002B5278(u8 *, float);
extern void func_L02_003D4E00(char *);
extern int func_00282978(short *);
extern int func_L02_003D4D68(char *);
extern int func_L02_003D52A8(char *);
extern void func_00282C88(Quadword *);
extern void func_L02_003D5660(char *, int);
extern int func_L02_003D5748(char *, int);
extern void func_L02_003D46B8(char *);
#define B(o) (*(u8 *)(state+(o)))
#define H(o) (*(short *)(state+(o)))
#define I(o) (*(int *)(state+(o)))
#define W(o) (*(unsigned int *)(state+(o)))
#define F(o) (*(float *)(state+(o)))
#define P(o) (*(char **)(state+(o)))
#define SET_MODE(m,r) func_002A7750((u8 *)self,(m),(r))

extern char *D_L02_001B359C;
extern float D_L02_001B03F0[4] __attribute__((sda));
extern float D_L02_001B0400[4] __attribute__((sda));
extern float D_L02_001A8F20[4] __attribute__((nosda));
extern u8 D_001A7A73;
#define D_0018C0BC RESIDENT->motion
typedef struct { u8 prefix[4]; u8 active; u8 reserved05[0x13]; char *owner; u8 reserved1C[0x54]; } SoundSlot;
extern SoundSlot D_001886D0[];
extern void func_L02_003D91A0(char *);
extern float func_002A89A8(void *, int, float);
extern char *func_L02_003FC098(char *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern int func_L02_003329C8(char *, char *, float, float);
extern void func_L02_003DB9E0(char *);
extern int func_002E5CF8(int, int, char *);
extern void func_L02_003DB938(char *);
extern void func_L02_003D4990(char *);
extern float func_L02_00321C30(void *, void *, float);
extern void func_L02_003DB2F0(char *);
extern int func_00283CF0(float);
extern int func_L02_003DB950(char *);
extern int func_002E59B0(int, int);
extern void func_002E59F8(int);
extern void func_L02_003DB200(char *);
extern float func_00283CE0(int);
extern char *func_L02_0032B468(char *, int, void *, void *, int, int, void *, void *, void *, float);
extern void func_L02_003DBB70(char *, char *);
extern void func_0029F338(void *);
extern int func_002E5DA0(int, int, char *, int);
extern void *func_0032C700(void *, int, int, int, int, int, int, int, int, int, int, int, float, float);
extern void func_0029FCC0(char *, int, char *);
extern void func_002A7A00(float *, float, float);
extern void func_002B0A68(char *, int, float *, unsigned char, float, float, float, float);
extern void func_L02_003DB6D8(char *);
extern void func_L02_003D9608(char *);
#define PROXY (D_L02_001B359C + (*(int *)(*(char **)(self+0x68)+0x244) << 8))
#define ACTOR_FLAGS (*(unsigned short *)(self+0x34))

/* Drive the second Maktar sentry's emergence, movement, attacks and destruction. */
void func_L02_003D7C20(char *self)
{
    char *state;
    char *object;
    char *child;
    float target[4] __attribute__((aligned(16)));
    float direction[4] __attribute__((aligned(16)));
    float curve[4] __attribute__((aligned(16)));
    float distance, yaw, frame, facing, value;
    short damageKind;
    int sound, animation, phase;
    u8 *actor=(u8 *)self;

    func_L02_003D91A0(self);
    state=*(char **)(self+0x68);
    *(Quadword *)target=0;
    if (P(0x240)) qcopy(target, P(0x240)+0x10);
    distance=func_00282E80(self+0x10,target);
    yaw=func_00283248(target[0]-*(float *)(self+0x10),target[1]-*(float *)(self+0x14));
    frame=func_0029F530(self);
    damageKind=0;
    if (D_0018C2BC) damageKind=*(short *)(D_0018C2BC+0xAA);
    if (D_0018C0BC==7 || D_0018C2BC==self || damageKind==0xD08) H(0x290)=1;
    switch ((u8)actor[0x20]) {
    case 0:
    case 1:
        goto finish;
    case 2:
        H(0x290)=0;
        if (func_002B3868((u8 *)self)) {
            actor[0xBC]=0; *(short *)(self+0x96)=0; func_002A7470(self,0,0,3);
            object=PROXY;
            if (((u8 *)object)[0x43]) { animation=0; goto proxyAnimation; }
            break;
        }
        phase=actor[0xBC];
        if (phase==0 && *(unsigned short *)(self+0x96)>60) {
            actor[0xBC]=1;
            if (actor[0x43]!=3) func_002A7470(self,3,0,10);
            object=PROXY;
            if (((u8 *)object)[0x43]!=6) func_002A7470(object,6,0,10);
            *(float *)(self+0x18)=func_002A89A8(self+0x10,0,10.0f);
            func_00282CF0(direction,func_L02_003FC098(*(char **)(self+0xB8)),self+0x10);
            direction[2]=0.0f; func_00282F20(direction,direction,30.0f);
            func_00282CC0(direction,direction,self+0x10);
            direction[2]=*(float *)(func_L02_003FC098(*(char **)(self+0xB8))+8);
            func_L02_003329C8(self,(char *)direction,0.33333334f,F(0x7C));
            break;
        }
        if (phase==1 && (actor[0x60]&2)) {
            actor[0xBC]=2;
            if (actor[0x43]!=4) func_002A7470(self,4,0,7);
            object=PROXY;
            if (((u8 *)object)[0x43]!=7) { animation=7; goto proxyAnimation; }
            break;
        }
        if (actor[0xBC]==2 && *(float *)(self+0x18)<*(float *)(func_L02_003FC098(*(char **)(self+0xB8))+8)+0.05f) {
            func_00282C88((Quadword *)(state+0xF0)); actor[0xBC]=3; H(0x292)=0;
            if (actor[0x43]!=5) func_002A7470(self,5,3,2);
            object=PROXY; if (((u8 *)object)[0x43]!=8) func_002A7470(object,8,0,10);
            func_L02_003DB9E0(self);
            break;
        }
        if (actor[0xBC]==3) {
            value=func_0029F530(self);
            if (value>2.0f && !H(0x292)) { H(0x292)=1; func_002E5CF8(0,0,self); }
            if (actor[0x60]&2) {
                EFFECT->amount=0.35f; EFFECT->kind=25; EFFECT->detail=0;
                func_00282C88((Quadword *)(state+0xF0));
                if (actor[0x43]) func_002A7470(self,0,0,0);
                object=PROXY; if (((u8 *)object)[0x43]) func_002A7470(object,0,0,0);
                SET_MODE(5,1); H(0x288)=func_00283CF0(func_002A7878(600.0f,1200.0f));
            }
        }
        break;
    case 3:
        if (func_002B3868((u8 *)self)) {
            actor[0xBC]=0; qcopy(state+0x230, D_L02_001B0400);
            if (actor[0x43]!=1) func_002A7470(self,1,0,10);
            func_L02_003DB938(self); func_L02_003D4990(P(0x264));
            func_L02_003FC020(*(char **)(self+0xB8),P(0x264));
            func_00282C88((Quadword *)(state+0xF0)); *(short *)(self+0x96)=0; break;
        }
        if (actor[0xBC]==0) {
            value=func_00282E80(self+0x10,state+0x230);
            if (value<0.01f) {
                actor[0xBC]=1;
                if (actor[0x43]!=3) func_002A7470(self,3,0,10);
                object=PROXY; if (((u8 *)object)[0x43]!=6) func_002A7470(object,6,0,10);
                func_00282C88((Quadword *)(state+0xF0));
                func_L02_003329C8(self,(char *)D_L02_001B03F0,0.33333334f,F(0x7C));
                break;
            }
        }
        phase=actor[0xBC];
        if (phase==1 && (actor[0x60]&2)) {
            actor[0xBC]=2; *(short *)(self+0x96)=0;
            if (actor[0x43]!=4) func_002A7470(self,4,0,10);
            object=PROXY; if (((u8 *)object)[0x43]!=7) { animation=7; goto proxyAnimation; }
        } else if (phase==2) {
            value=func_00282E48(self+0x10,D_L02_001B03F0);
            if (value>=1.0f && *(unsigned short *)(self+0x96)<301) break;
            actor[0xBC]=3;
            if (actor[0x43]!=5) func_002A7470(self,5,0,10);
            object=PROXY; if (((u8 *)object)[0x43]!=8) { animation=8; goto proxyAnimation; }
        } else if (phase==3 && (actor[0x60]&2)) SET_MODE(4,-1);
        break;
    case 4:
        if (func_002B3868((u8 *)self)) {
            if (actor[0x43]) func_002A7470(self,0,0,10);
            object=PROXY; if (((u8 *)object)[0x43]) func_002A7470(object,0,0,10);
        }
        func_L02_00321C30(self+0x10,D_L02_001B03F0,0.16666667f);
        if (H(0x280)==1 && func_00282E80(self+0x10,D_L02_001B03F0)<0.001f) SET_MODE(2,1);
        break;
    case 5:
        if (func_002B3868((u8 *)self)) {
            if (actor[0x43]!=1) func_002A7470(self,1,0,15);
            object=PROXY; if (((u8 *)object)[0x43]!=1) func_002A7470(object,1,0,10);
            actor[0xBC]=1;
        }
        facing=func_00283C80(yaw,*(float *)(self+0xF8));
        if (actor[0xBC]==1 && facing>0.78539824f) {
            actor[0xBC]=2;
            if (actor[0x43]!=2) func_002A7470(self,2,0,15);
            object=PROXY; if (((u8 *)object)[0x43]!=3) func_002A7470(object,3,0,10);
        }
        if (actor[0xBC]==2 && facing<0.17453295f) {
            actor[0xBC]=1;
            if (actor[0x43]!=1) func_002A7470(self,1,0,15);
            object=PROXY; if (((u8 *)object)[0x43]!=1) func_002A7470(object,1,0,10);
        }
        if (actor[0xBC]==1 && distance<10.0f) {
            actor[0xBC]=0;
            if (actor[0x43]) func_002A7470(self,0,0,15);
        }
        if (actor[0xBC]==0 && distance>20.0f) {
            actor[0xBC]=1; if (actor[0x43]!=1) func_002A7470(self,1,0,10);
        }
        if (D_0018C2BC) func_L02_003DB2F0(self);
        if (func_00282978((short *)(state+0x288))) {
            H(0x288)=func_00283CF0(func_002A7878(600.0f,1200.0f)); SET_MODE(6,-1);
        }
        if (func_L02_003DB950(self)) SET_MODE(3,0);
        break;
    case 6:
        if (func_002B3868((u8 *)self)) {
            if (actor[0x42]==7) {
                actor[0xBC]=1;
                object=PROXY; if (((u8 *)object)[0x43]!=10) func_002A7470(object,10,0,10);
            } else {
                if (actor[0x42]!=6) {
                    if (actor[0x43]!=6) func_002A7470(self,6,0,0);
                    object=PROXY; if (((u8 *)object)[0x43]!=9) func_002A7470(object,9,0,10);
                }
                actor[0xBC]=0; ACTOR_FLAGS &= 0xEFFF;
            }
        } else if (actor[0xBC]==0 && frame>28.0f) {
            if (actor[0x43]!=7) func_002A7470(self,7,0,0);
            object=PROXY; if (((u8 *)object)[0x43]!=10) func_002A7470(object,10,0,10);
            actor[0xBC]=1; F(0x30)=1.5f; ACTOR_FLAGS |= 0x1000;
            if (!func_002E59B0((int)self,I(0x26C))) I(0x26C)=func_002E5CF8(6,4,self);
        } else if (actor[0xBC]==1) {
            *(int *)(self+0x9C)=1;
            if (func_00282978((short *)(state+0x288)) || func_L02_003DB950(self)) {
                if (actor[0x43]!=8) func_002A7470(self,8,0,0);
                object=PROXY; if (((u8 *)object)[0x43]!=11) func_002A7470(object,11,0,10);
                actor[0xBC]=2; ACTOR_FLAGS &= 0xEFFF;
            }
        }
        if (actor[0xBC]==1 && D_0018C2BC) { func_L02_003DB2F0(self); break; }
        if (actor[0xBC]==2 && frame>45.0f) {
            F(0x30)=11.0f; *(int *)(self+0x9C)=0; ACTOR_FLAGS |= 0x1000;
            H(0x288)=func_00283CF0(func_002A7878(600.0f,1200.0f)); SET_MODE(5,-1);
            sound=I(0x26C);
            if (sound!=-1 && D_001886D0[sound].owner==self && D_001886D0[sound].active) func_002E59F8(sound);
            I(0x26C)=-1;
        }
        break;
    case 7:
        if (func_002B3868((u8 *)self)) {
            object=PROXY; if (((u8 *)object)[0x43]!=7) func_002A7470(object,7,0,15);
            F(0x24C)+=0.1939255f; *(short *)(self+0x96)=0;
        } else if (*(unsigned short *)(self+0x96)>=181) SET_MODE(6,-1);
        break;
    case 8:
        if (func_002B3868((u8 *)self)) {
            if (actor[0x43]!=8) func_002A7470(self,8,0,20);
            object=PROXY; if (((u8 *)object)[0x43]!=9) func_002A7470(object,9,0,15);
            F(0x24C)+=0.1939255f;
        } else if (!(frame<=45.0f)) SET_MODE(*(unsigned short *)(state+0x28A),-1);
        break;
    case 9:
        if (func_002B3868((u8 *)self)) {
            object=PROXY; if (((u8 *)object)[0x43]!=12) func_002A7470(object,12,0,15);
        }
        func_L02_003DB200(self);
        if (!(PROXY[0x60]&2)) break;
        actor[0x20]=(u8)H(0x28A); actor[0xBC]=B(0x28E);
        object=PROXY; animation=*(unsigned short *)(state+0x28C);
        if ((u8)((u8 *)object)[0x43]!=animation) func_002A7470(object,animation,0,15);
        break;
    case 10:
        if (func_002B3868((u8 *)self)) {
            sound=I(0x26C);
            if (sound!=-1 && D_001886D0[sound].owner==self && D_001886D0[sound].active) func_002E59F8(sound);
            I(0x26C)=-1;
            if (actor[0x42]==7) actor[0xBC]=1;
            else {
                actor[0xBC]=0;
                if (actor[0x42]!=6 && actor[0x43]!=9) func_002A7470(self,9,0,15);
            }
            object=PROXY; if (((u8 *)object)[0x43]!=13) func_002A7470(object,13,0,15);
            break;
        }
        if (actor[0xBC]==0 && (actor[0x60]&2)) {
            actor[0xBC]=1; object=PROXY;
            if (((u8 *)object)[0x43]!=13) func_002A7470(object,13,0,15);
            if (actor[0x43]!=7) { object=self; animation=7; goto proxyAnimation; }
        } else if (actor[0xBC]==1 && (PROXY[0x60]&2)) SET_MODE(11,-1);
        break;
    case 11:
        if (func_002B3868((u8 *)self)) {
            if (!H(0x290) && !D_001A7A73) {
                D_001A7A73=1; func_002E5E58(1,0,0); func_002B0A18(0x1233,-1); D_L02_001A903C=1;
            }
            *(int *)(self+0x48)=0; *(int *)(PROXY+0x48)=0; *(short *)(self+0x96)=0;
            func_00282CF0(direction,D_L02_001BA500,PROXY+0x10);
            func_00282F20(direction,direction,func_002A7878(0.083333336f,0.116666675f));
            direction[2]+=0.06666667f;
            child=*(char **)(*(char **)(self+0x68)+0x260);
            if (child) {
                func_L02_0032B468(child,0xA4C,child+0x10,child+0xF0,300,0,direction,
                        D_L02_001A8F20,D_L02_001A8F20,0.0013888889f);
                func_L02_003DBB70(self,(char *)D_L02_001A8F20);
                func_0029F338(*(char **)(*(char **)(self+0x68)+0x260));
                *(char **)(*(char **)(self+0x68)+0x260)=0;
                func_002E5DA0(5,0,self,0xA44);
            }
            func_L02_003FC248(self,0,-1); B(0x1F2)=1;
            F(0x210)=2.0f; F(0x218)=2.0f; F(0x214)=2.0f; ACTOR_FLAGS &= 0xEFFF;
        }
        value=func_00283CE0(*(unsigned short *)(self+0x96))*-0.0111110555f+2.0f;
        if (value<0.0f) value=0.0f;
        F(0x210)=value; F(0x218)=value; F(0x214)=value;
        if (*(unsigned short *)(self+0x96)>180) {
            *(float *)(self+0x48)=1.0f; *(float *)(PROXY+0x48)=1.0f;
            func_0032C700(self+0x10,1,25,20,30,40,45,1,0,1,0,0,2.0f,20.0f);
            func_0029FCC0(self,2,(char *)direction);
            func_0032C700(self+0x10,0,10,5,10,5,20,1,0,0,0,0,0.7f,20.0f);
            func_0029FCC0(self,6,(char *)direction);
            func_0032C700(self+0x10,0,0,10,20,15,45,1,0,0,0,0,0.7f,20.0f);
            func_0029FCC0(self,4,(char *)direction);
            func_0032C700(self+0x10,0,20,0,15,10,30,1,0,0,0,0,0.7f,20.0f);
            func_0029FCC0(self,8,(char *)direction);
            func_0032C700(self+0x10,0,5,15,5,25,25,1,0,0,0,0,0.7f,20.0f);
            func_002A7A00(curve,0.10000001f,0.20000002f);
            func_002B0A68(self,0xFFF,curve,255,3.0f,6.0f,3.0f,6.0f);
            func_002A7A00(curve,0.13333334f,0.26666668f);
            func_002B0A68(PROXY,0x1F,curve,255,3.0f,6.0f,3.0f,6.0f);
            func_002E5DA0(5,0,self,0xA44); func_L02_003DB6D8(self);
            F(0x210)=1.0f; F(0x218)=1.0f; F(0x214)=1.0f; B(0x1F2)=0;
            child=P(0x264);
            if (child && (u8)child[0x20]!=254 && (u8)child[0x20]!=253 && (u8)child[0x20]>2) {
                func_L02_003D4990(child); func_L02_003FC020(*(char **)(self+0xB8),P(0x264));
            }
        }
        break;
    }
    goto finish;
proxyAnimation:
    func_002A7470(object,animation,0,10);
finish:
    func_L02_003D9608(self);
}
