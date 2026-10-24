/* Manual reconstruction, 2026-10-23; retained, not linked.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -mno-split-addresses.
 * us: 16_snivelak: 1432 bytes, expected 1396; func_L16_00417210: 0 of 1 places match (src/levels/16_snivelak/L16_00417210-g8-qcopy.c)
 * us2: 16_snivelak: 1432 bytes, expected 1396; func_L16_00417210: 0 of 1 places match (src/levels/16_snivelak/L16_00417210-g8-qcopy.c)
 * pal: func_L16_00417210 is in neither catalogue of pal; func_L16_00417210 is in neither catalogue of pal
 * 1432/1396 bytes in both USA releases. Rate-selection, clamp-temporary and global/FP scheduling remain different. The yaw helper receives both the heading and state+0x80 (the latter is omitted in Ghidra). Reopen with original settings and lifetime evidence.
 */
#include "common.h"
typedef int Vector128 __attribute__((mode(TI)));
typedef struct { Vector128 position,angles; union { float bounds[2]; Vector128 delta; } work; float limits[2]; } SteeringWorkspace;
typedef struct { unsigned char active; char reserved[19]; char *owner; char tail[88]; } SoundRecord;
extern SoundRecord D_001886D4[];
extern float D_0018BDD0 __attribute__((nosda)),D_0018BDD4 __attribute__((nosda));
extern float D_L16_001B1B50 __attribute__((sda)),D_L16_001B1B54 __attribute__((nosda));
extern float D_L16_001B1B10 __attribute__((sda)),D_L16_001B1B14 __attribute__((nosda));
extern float D_L16_001B1B18 __attribute__((sda)),D_L16_001B1B1C __attribute__((nosda));
extern float D_L16_001B1B20 __attribute__((sda));
extern float D_L16_001B1B28 __attribute__((sda)),D_L16_001B1B2C __attribute__((nosda));
extern float D_L16_001B1B30 __attribute__((sda)),D_L16_001B1B34 __attribute__((nosda));
extern float D_L16_001B1B38 __attribute__((sda));
extern float D_L16_001B1B40 __attribute__((sda)),D_L16_001B1B44 __attribute__((nosda));
extern float func_00282C48(float);
extern float func_002AA2E8(float *,float,float);
extern float func_00283B98(float,float);
extern void func_L16_00317C90(float *,float,float);
extern int func_002E5CF8(int,int,char *);
extern void func_002E59F8(int);
extern void func_00282CF0(void *,void *,void *);
extern void func_002AD6F0(void *,void *,void *,void *);
void func_L16_00417210(char *object)
{
    SteeringWorkspace local;
    char *state=*(char **)(object+0x68);
    float acceleration,target,deceleration,oldMagnitude,newMagnitude;
    int handle;
    SoundRecord *sound;
    *(Vector128 *)&local.position=*(Vector128 *)(object+0x10);
    *(Vector128 *)&local.angles=*(Vector128 *)(object+0xf0);
    if(func_00282C48(D_0018BDD0)<D_L16_001B1B50) D_L16_001B1B50=func_00282C48(D_0018BDD0);
    else if(D_L16_001B1B50 < -func_00282C48(D_0018BDD0)) D_L16_001B1B50=-func_00282C48(D_0018BDD0);
    if(func_00282C48(D_0018BDD4)<D_L16_001B1B54) D_L16_001B1B54=func_00282C48(D_0018BDD4);
    else if(D_L16_001B1B54 < -func_00282C48(D_0018BDD4)) D_L16_001B1B54=-func_00282C48(D_0018BDD4);
    func_002AA2E8(&D_L16_001B1B50,D_0018BDD0,0.15f);
    func_002AA2E8(&D_L16_001B1B54,D_0018BDD4,0.15f);
    deceleration=D_L16_001B1B20*0.000004848137451f;
    if(D_L16_001B1B50==0.0f) { acceleration=0.0f; target=0.0f; }
    else if(func_00282C48(D_L16_001B1B50)>=1.0f) {
        acceleration=D_L16_001B1B14*0.000004848137451f;
        target=D_L16_001B1B1C*(-D_L16_001B1B50)*0.0002908882452f;
    } else {
        acceleration=D_L16_001B1B10*func_00282C48(D_L16_001B1B50)*0.000004848137451f;
        target=D_L16_001B1B18*(-D_L16_001B1B50)*0.0002908882452f;
    }
    oldMagnitude=func_00282C48(*(float *)(state+0x80));
    newMagnitude=func_00282C48(target);
    if(newMagnitude<oldMagnitude) func_002AA2E8((float *)(state+0x80),target,deceleration);
    else func_002AA2E8((float *)(state+0x80),target,acceleration);
    deceleration=D_L16_001B1B38*0.000004848137451f;
    if(D_L16_001B1B54==0.0f) { acceleration=0.0f; target=0.0f; }
    else if(func_00282C48(D_L16_001B1B54)>=1.0f) {
        acceleration=D_L16_001B1B2C*0.000004848137451f;
        target=D_L16_001B1B34*(-D_L16_001B1B54)*0.0002908882452f;
    } else {
        acceleration=D_L16_001B1B28*func_00282C48(D_L16_001B1B54)*0.000004848137451f;
        target=D_L16_001B1B30*(-D_L16_001B1B54)*0.0002908882452f;
    }
    oldMagnitude=func_00282C48(*(float *)(state+0x84));
    newMagnitude=func_00282C48(target);
    if(newMagnitude<oldMagnitude) func_002AA2E8((float *)(state+0x84),target,deceleration);
    else func_002AA2E8((float *)(state+0x84),target,acceleration);
    if(*(float *)(state+0x80)!=0.0f) *(float *)(object+0xf8)=func_00283B98(*(float *)(object+0xf8),*(float *)(state+0x80));
    if(*(float *)(state+0x84)!=0.0f) {
        local.limits[0]=D_L16_001B1B40*0.017453294f;
        local.limits[1]=D_L16_001B1B44*0.017453294f;
        local.work.bounds[0]=local.limits[0]; local.work.bounds[1]=local.limits[1];
        func_L16_00317C90((float *)(state+0x84),local.work.bounds[0]-*(float *)(state+0x90),deceleration);
        func_L16_00317C90((float *)(state+0x84),local.work.bounds[1]-*(float *)(state+0x90),deceleration);
        *(float *)(state+0x90)=func_00283B98(*(float *)(state+0x90),*(float *)(state+0x84));
        if(*(float *)(state+0x90)>local.work.bounds[0]) {
            *(float *)(state+0x90)=local.work.bounds[0]; *(float *)(state+0x84)=0.0f;
        } else if(*(float *)(state+0x90)<local.work.bounds[1]) {
            *(float *)(state+0x90)=local.work.bounds[1]; *(float *)(state+0x84)=0.0f;
        }
    }
    handle=*(int *)(state+0xa4);
    if(func_00282C48(*(float *)(state+0x80))>0.0f || func_00282C48(*(float *)(state+0x84))>0.0f) {
        sound=D_001886D4+handle;
        if(sound->owner!=object || sound->active==0) *(int *)(state+0xa4)=func_002E5CF8(4,4,object);
    } else {
        if(handle!=-1 && D_001886D4[handle].owner==object && D_001886D4[handle].active!=0) func_002E59F8(handle);
        *(int *)(state+0xa4)=-1;
    }
    func_00282CF0(&local.work.delta,object+0x10,&local.position);
    func_002AD6F0(state+0x20,&local.work.delta,&local.angles,object+0xf0);
}
