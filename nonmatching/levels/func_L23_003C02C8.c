/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Prior worker coverage: US 0/1; US2 0/1; PAL absent from catalogue.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/* Nonmatching manual reconstruction.
   Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
   1828 bytes, expected 1944; frame 0xA0 agrees, US and US2 fail.
   The target pointer is a live third argument to func_L23_003C0A60 (+0x60..0x80).
   The partial path views describe only the measured header/point and edge accesses.
   Reopen with a graph traversal allocation or branch-shape hypothesis.
*/
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef struct { u64 first,last; } L23PathLinks;
#define F(p,o) (*(float *)((u8 *)(p)+(o)))
#define I(p,o) (*(int *)((u8 *)(p)+(o)))
#define S(p,o) (*(s16 *)((u8 *)(p)+(o)))
extern float D_00189EA0[4];
extern float D_L23_001AFA50 __attribute__((sda));
extern int D_L23_001AFA54 __attribute__((sda));
extern u8 *D_L23_001C0A98;
extern int *D_L23_001B36A8;
extern u8 *D_L23_001FF300[];
extern L23PathLinks D_L23_002595C8[];
extern void func_L23_00418650(char *,float);
extern int func_L23_003C0A60(void *,void *,void *);
extern int func_L23_003C1420(void *);
extern void func_00282D30(void *,void *,float);
extern void func_00282CC0(void *,void *,void *);
extern int func_002761F8(void *,void *,int,void *,void *);
extern s32 func_002A77E0(s32);
extern void func_L23_003BFFC0(char *,int,int,int,int,float);
extern s32 func_002A7820(s32,s32);
extern int func_00282978(s16 *);
extern float func_00282E48(void *,void *);
extern void func_L23_003C0C78(void *,int);
extern f32 func_L00_0031BDC0(f32 *,const f32 *,const f32 *,const f32 *);
extern void func_L23_003C0F88(char *,u64,int,int);
extern void func_00282CF0(void *,void *,void *);
extern void func_00282F20(void *,void *,float);
extern int func_L02_00332630(char *,void *);
extern void func_L22_003300E8(void *,void *);
extern void func_L23_003C01F8(char *,int);
void func_L23_003C02C8(u8 *object)
{
    float destination[4],reference[4],node[4],direction[4];
    float *target;
    u8 *state=*(u8 **)(object+0x68),*path;
    int arrived,moving,allow,mode,choice,index,pathIndex,next,base;
    float side,first,second;
    target=*(float **)(state+0x320);
    *(Quad *)destination=*(Quad *)target;
    *(Quad *)reference=*(Quad *)target;
    func_L23_00418650((char *)reference,0.0f);
    arrived=target==D_00189EA0 ? S(state,0x324) : func_L23_003C0A60(object,object+0x10,target);
    moving=S(state,0x26C);
    if (arrived==0 && S(state,0x2B0)==0 && moving==0) S(state,0x2B0)=1;
    if (moving!=0) goto timer;
    allow=1;
    mode=S(state,0x2B0);
    if (mode==2) allow=0;
    else if (mode==4) allow=arrived==0;
    else if (target==D_00189EA0 && S(state,0x324)!=0) allow=0;
    else if ((mode==0 && arrived!=0) || mode==3) allow=0;
    if (allow) {
        if (func_L23_003C1420(object)) {
            *(Quad *)destination=*(Quad *)(state+0x2D0);
            *(Quad *)(state+0x2E0)=*(Quad *)(object+0x10);
            goto randomTimer;
        }
        goto follow;
    }
    S(state,0x326)=0;
    func_00282D30(node,object+0xC0,D_L23_001AFA50);
    func_00282CC0(node,node,object+0x10);
    if (func_002761F8(object+0x10,node,17,object,0) && D_L23_001C0A98 && *(s16 *)(D_L23_001C0A98+0xAA)==0x7E5) {
        choice=func_002A77E0(3);
        if (choice==1) { side=-1.0f; S(state,0x26C)=1; }
        else if (choice==0) { side=1.0f; S(state,0x26C)=1; }
        else {
            S(state,0x26C)=-1;
            func_L23_003BFFC0((char *)object,3,0,4,1,1.0f);
            side=0.0f;
        }
        if (side!=0.0f) {
            func_00282D30(direction,object+0xD0,side);
            func_00282CC0(direction,direction,object+0xC0);
            func_00282D30(direction,direction,12.0f);
            func_00282CC0(state+0x2D0,object+0x10,direction);
            func_L23_00418650((char *)state+0x2D0,0.0f);
        }
        S(state,0x2B0)=0;
        S(state,0x326)=1;
        goto randomTimer;
    }
    goto follow;
randomTimer:
    base=D_L23_001AFA54;
    S(state,0x26E)=base+func_002A7820(-base/2,base/2);
    goto follow;
timer:
    if (S(state,0x26E)) func_00282978((s16 *)(state+0x26E));
    if (!S(state,0x26E)) S(state,0x26C)=0;
    if (S(state,0x26C)==-1) return;
    *(Quad *)destination=*(Quad *)(state+0x2D0);
follow:
    mode=S(state,0x2B0);
    if (mode==2) {
        if (func_00282E48(object+0x10,state+0x2C0)<2.0f) { S(state,0x2B0)=3; goto update; }
    } else if (mode==1) {
        func_L23_003C0C78(object,1);
        index=S(state,0x2B6);
        path=D_L23_001FF300[D_L23_001B36A8[S(state,0x2B4)]];
        *(Quad *)node=*(Quad *)(path+0x10+index*16);
        S(state,0x2B0)=2;
        first=func_00282E48(path+0x10+index*16,reference);
        if (index==0) {
            second=func_00282E48(path+0x20,reference);
            if (second<first) {
                S(state,0x2B2)=1;
                func_L00_0031BDC0((float *)(state+0x2C0),node,(float *)(path+0x20+S(state,0x2B6)*16),(float *)(object+0x10));
            } else { S(state,0x2B2)=-1; *(Quad *)(state+0x2C0)=*(Quad *)node; }
        } else if (index==I(path,0)-1) {
            second=func_00282E48(path+I(path,0)*16-4*4,reference);
            if (second<first) {
                S(state,0x2B2)=-1;
                func_L00_0031BDC0((float *)(state+0x2C0),node,(float *)(path+S(state,0x2B6)*16),(float *)(object+0x10));
            } else { S(state,0x2B2)=1; *(Quad *)(state+0x2C0)=*(Quad *)node; }
        } else {
            first=func_00282E48(path+index*16,reference);
            second=func_00282E48(path+0x20+S(state,0x2B6)*16,reference);
            S(state,0x2B2)=first<second ? -1 : 1;
            func_L00_0031BDC0((float *)(state+0x2C0),node,(float *)(path+0x10+S(state,0x2B2)*16),(float *)(object+0x10));
        }
        func_L23_00418650((char *)state+0x2C0,0.0f);
        goto update;
    } else if (mode==3) {
        if (func_00282E48(state+0x300,reference)<20.0f && arrived) { S(state,0x2B0)=4; goto update; }
        if (func_00282E48(object+0x10,state+0x2C0)<2.0f) {
            next=S(state,0x2B6)+S(state,0x2B2);
            pathIndex=D_L23_001B36A8[S(state,0x2B4)];
            if (next<0) func_L23_003C0F88((char *)object,D_L23_002595C8[pathIndex].first,1,1);
            else if (next<I(D_L23_001FF300[pathIndex],0)) S(state,0x2B6)=next;
            else func_L23_003C0F88((char *)object,D_L23_002595C8[pathIndex].last,1,1);
            path=D_L23_001FF300[D_L23_001B36A8[S(state,0x2B4)]];
            *(Quad *)(state+0x2C0)=*(Quad *)(path+0x10+S(state,0x2B6)*16);
            func_L23_00418650((char *)state+0x2C0,0.0f);
        }
    } else if (mode==4) { S(state,0x2B0)=0; goto update; }
    else goto update;
    *(Quad *)destination=*(Quad *)(state+0x2C0);
update:
    func_00282CF0(node,destination,object+0x10);
    func_00282F20(node,node,F(state,0x2A8)*0.016666668f);
    func_L02_00332630((char *)object,destination);
    func_L22_003300E8(object,node);
    func_L23_003C01F8((char *)object,1);
}
