/*
 * Complete manual reconstruction retained as nonmatching; no coverage credit.
 * Fresh qualified-compiler checks, 2026-10-25.
 * Profile: -O2 -G8 -ffunction-sections
 * Coverage: US: 0/1; US2: absent from catalogue; PAL: absent from catalogue.
 * Compiled text: 2672 bytes; retail: 2848 bytes.
 * Remaining difference: The canonical allocator takes an int class identifier and returns
 * pointer/null. All three key-wrapper calls now forward the retail object value in a0. The COST
 * access is corrected to the measured +0x80 field within0xE0-strided records, supported by six
 * retail loads; the old draft read the record start. Separate state2/state5 paths and a measured
 * resident-player prefix give2672/2848 with frame0x80. Remaining control and scalar/vector
 * lifetimes differ.
 * Reopen when: Recover additional state and typed field dataflow after these semantic repairs; do
 * not narrow allocator parameters, discard owner keys or restore the old incorrect cost offset.
 */

#include "common.h"

typedef int Quad __attribute__((mode(TI)));
#define COST D_L04_0027B4F0[D_0013958F].cost
#define INT(p,o) (*(int *)((char *)(p)+(o)))
#define FLOAT(p,o) (*(float *)((char *)(p)+(o)))
#define HALF(p,o) (*(short *)((char *)(p)+(o)))
#define UHALF(p,o) (*(u16 *)((char *)(p)+(o)))
extern u8 D_001A7B1F, D_001395C9, D_0013958F, D_001A7A40;
extern unsigned D_001397A0, D_00138324;
extern int D_001A79F0 __attribute__((sda)), D_001A79F8 __attribute__((sda));
typedef struct {
    u8 prefix[0x80]; float position[4]; u8 gap90[0x50];
    float target[4]; u8 gapF0[0x20]; float velocity[4];
} ResidentPlayerPrefix;
extern char D_0019B4A8[];
extern ResidentPlayerPrefix D_00189E20;
/* The +0x80 cost field and 0xE0 record stride are independently measured. */
typedef struct { u8 prefix[0x80]; int cost; u8 tail[0x5C]; } WeaponSettings;
extern WeaponSettings D_L04_0027B4F0[];
extern char *D_L04_001B24DC __attribute__((sda));
extern int D_L04_001B2008, D_L04_001A8F00, D_L04_001B2228;
extern char D_L04_001BF880[], D_L04_0021DE64[], D_L04_0021EAD4[];
extern void func_L04_00434AD0(char *);
extern void func_0029F338(char *);
extern void func_002A7470(void *,int,int,int);
extern void func_002A7750(void *,int,int);
extern void func_L01_003128C0(char *);
extern void *func_0029EFD0(int);
extern void func_002A0F48(void *);
extern void func_002AB650(u8 *);
extern int func_L01_003245E0(u8 *,int,float);
extern void func_L01_003246D0(int);
extern int func_00288AA0(u8 *,int);
extern int func_00288BE8(void *);
extern int func_002F5D10(void);
extern float func_00283B98(float,float);
extern void func_L00_002B9D60(void *,void *,int,int);
extern void func_002A8598(int,int);
extern int func_00288E18(int,int);
extern int func_002ACBC8(void *,int);
extern void func_L00_0030C710(int);
extern void func_002B0A18(int,int);
extern void func_0029B3E0(int,int);
extern void func_L01_00324550(int,int,int);
extern void func_002AEC48(void *,void *,int,float,float);
extern float func_00282E80(void *,void *);
extern float func_00283248(float,float);
extern float func_00283C80(float,float);
extern float func_00282E20(void *);
extern int func_00282948(int *);
extern float func_002A7878(float,float);
extern int func_00283CF0(float);
extern void func_002AF1D0(void *,void *,int,int);
extern void func_00282CC0(void *,void *,void *);
extern void func_00282CF0(void *,void *,void *);
extern float func_00282DF0(void *);
extern void func_00288308(int);
extern float func_00283BE0(float,float);
extern void func_002AF000(float *,float,float,float);
extern void func_002AD860(int);

void func_L04_00434BB0(char *object)
{
    char *vars = *(char **)(object + 0x68);
    union { Quad q; float f[4]; } target, rotation, difference;
    float smoothing = 0.02f;
    int facing = 0, index;
    char *other;
    func_L04_00434AD0(object);

    switch ((u8)object[0x20]) {
    case 0:
        if (D_L04_001B2008 < 2) return;
        if (D_001A7B1F) goto finishPurchase;
        if (D_001397A0 & 0x8000000) {
            if (object[0x43] != 1) func_002A7470(object,1,0,10);
            func_002A7750(object,2,-1);
        }
        func_L01_003128C0(object);
        *(char **)(vars+0x11c) = func_0029EFD0(0xd99);
        other = *(char **)(vars+0x11c);
        if (other) {
            other[0x30] = object[0x30];
            UHALF(other,0x32) = UHALF(object,0x32);
            other[0x31] = 1;
            func_002A0F48(other);
            func_002AB650((u8 *)other);
        }
        func_002A7750(object,1,-1);
        if (D_001397A0 & 0x8000000) {
            if (object[0x43] != 1) func_002A7470(object,1,0,10);
            func_002A7750(object,4,-1);
            if (INT(vars,0x12c) != -1)
                func_0029F338(D_L04_001B24DC + INT(vars,0x12c)*256);
        }
        break;
    case 1:
        other = D_L04_001B24DC + INT(vars,0x12c)*256;
        if (func_L01_003245E0((u8 *)object,10,4.0f) &&
            (!other || other[0x20] == -2 || other[0x20] == -3)) {
            D_001395C9 = 1;
            FLOAT(object,0x48) = 1.0f;
            func_L01_003246D0((int)object);
            func_00288AA0((u8 *)D_L04_001BF880,59);
            func_00288BE8(D_L04_001BF880);
            func_002A7750(object,2,-1);
        }
        break;
    case 2:
        D_L04_001B2228 = 1;
        if (D_L04_001A8F00 == 2) { object[0x31]=0; UHALF(object,0x34)|=1; }
        if (!func_002F5D10()) {
            target.f[0]=338.0f; target.f[1]=366.81f; target.f[2]=63.0f;
            qcopy(&rotation, (object+0xf0));
            rotation.f[2]=func_00283B98(rotation.f[2],3.1415929794311523f);
            func_L00_002B9D60(&target,&rotation,0,1);
            D_L04_001B2228=0; object[0x31]=1; UHALF(object,0x34)&=0xfffe;

                if (object[0x43]!=1) func_002A7470(object,1,0,10);
                func_002A7750(object,D_001A79F8 < COST ? 3 : 4,-1);

        }
        break;
    case 5:
        D_L04_001B2228 = 1;
        if (D_L04_001A8F00 == 2) { object[0x31]=0; UHALF(object,0x34)|=1; }
        if (!func_002F5D10()) {
            target.f[0]=338.0f; target.f[1]=366.81f; target.f[2]=63.0f;
            qcopy(&rotation, (object+0xf0));
            rotation.f[2]=func_00283B98(rotation.f[2],-1.5707964897155762f);
            func_L00_002B9D60(&target,&rotation,0,1);
            D_L04_001B2228=0; object[0x31]=1; UHALF(object,0x34)&=0xfffe;

                if (object[0x21] != -1) func_002A8598(object[0x21],1);
                if (!D_001A7B1F) {
                    D_001A79F8 -= COST;
                    func_L00_0030C710(180);
                    func_00288308(39);
                    func_002AD860(39);
                    func_002B0A18(0x122a,-1);
                }
                if (INT(vars,0x128)!=-1) D_L04_001B24DC[INT(vars,0x128)*256+0xbc]=1;
                goto finishPurchase;

        }
        break;
    case 3:
        if (COST < D_001A79F8) func_002A7750(object,4,-1);
        else if (func_L01_003245E0((u8 *)object,10,2.5f)) {
            func_L00_0030C710(180); func_L01_00324550(0x27a0,COST,-1); func_L01_003246D0((int)object);
        }
        break;
    case 4:
        if (D_001A79F8 < COST) { func_L00_0030C710(180); func_002A7750(object,3,-1); }
        else if (func_L01_003245E0((u8 *)object,10,2.5f) && func_002ACBC8(D_00189E20.position,INT(vars,0x120))) {
            func_L00_0030C710(180); func_L01_00324550(0x279f,COST,-1); func_L01_003246D0((int)object);
            if (D_00138324 & 16) {
                func_00288AA0((u8 *)D_L04_001BF880,60); func_00288BE8(D_L04_001BF880); func_002A7750(object,5,-1);
            }
        }
        break;
    }
    if ((u8)object[0x20]<2) { FLOAT(object,0x48)=0.0f; FLOAT(object,0xf0)=-0.0872664749622345f; }
    else {
        FLOAT(object,0xf0)=0.0f;
        if (object[0x43]==1) {
            float distance, angle;
            facing=1;
            distance=func_00282E80(object+0x10,D_00189E20.position);
            if (distance<8.0f) {
                angle=func_00283248(D_00189E20.target[0]-FLOAT(object,0x10),D_00189E20.target[1]-FLOAT(object,0x14));
                if (func_00283C80(FLOAT(object,0xf8),angle)<1.5707964897155762f) {
                    if (func_00282DF0(D_00189E20.velocity)>0.01f) INT(vars,0x114)=120;
                    else func_00282948((int *)(vars+0x114));
                } else goto stopTracking;
            } else {
stopTracking:
                if (INT(vars,0x114)) { INT(vars,0x114)=0; qcopy((vars+0x100), (D_00189E20.target)); }
            }
            if (func_00282948((int *)(vars+0x118))) {
                float turn=0.01745329424738884f;
                INT(vars,0x118)=func_00283CF0(func_002A7878(180.0f,300.0f));
                angle=func_00283B98(FLOAT(object,0xf8),func_002A7878(-90.0f,90.0f)*turn);
                func_002AF000((float *)(vars+0x100),6.0f,angle,func_002A7878(0.0f,30.0f)*turn);
                func_00282CC0(vars+0x100,vars+0x100,object+0x10);
            }
            if (INT(vars,0x114)==0) qcopy(&target, (vars+0x100));
            else { qcopy(&target, (D_00189E20.target)); smoothing=0.04f; }
        }
    }
    if (facing) {
        float yaw,pitch;
        qcopy(&rotation, (object+0x10)); rotation.f[2]+=2.0f;
        func_00282CF0(&difference,&target,&rotation);
        yaw=func_00283BE0(func_00283248(difference.f[0],difference.f[1]),FLOAT(object,0xf8));
        pitch=-func_00283248(func_00282E20(&difference),difference.f[2]);
        if (yaw>1.5707964897155762f) yaw=1.5707964897155762f;
        else if(yaw< -1.5707964897155762f) yaw=-1.5707964897155762f;
        if(pitch>0.523598849773407f) pitch=0.523598849773407f;
        else if(pitch< -0.523598849773407f) pitch=-0.523598849773407f;
        FLOAT(vars,100)=pitch; FLOAT(vars,0x68)=yaw*0.6f; FLOAT(vars,0xe8)=yaw*0.4f;
    }
    if(D_001A7A40) FLOAT(vars,0x70)=2.75f;
    func_002AEC48(object,vars,0,smoothing,0.3f);
    func_002AEC48(object,vars+0x80,1,smoothing,0.3f);
    if(INT(vars,0x11c)) func_002AF1D0(object,*(char **)(vars+0x11c),2,0);
    return;
finishPurchase:
    other=D_L04_001B24DC+INT(vars,0x124)*256;
    other[0x20]=2; INT(*(char **)(other+0x68),0x9c)=0;
    index=HALF(other,0xb2);
    D_L04_0021DE64[index]=0; D_L04_0021EAD4[index]=0;
    D_0019B4A8[D_001A79F0*1024+(index>>1)] &= (index&1) ? 0x8f : 0xf8;
    if (object[0x20]==0) {
        if(INT(vars,0x12c)!=-1) func_0029F338(D_L04_001B24DC+INT(vars,0x12c)*256);
    } else { func_00288E18(0x9dc,0x33); func_0029B3E0(0,-1); }
    func_0029F338(object);
}
