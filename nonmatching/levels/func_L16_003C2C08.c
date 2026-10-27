/* Retained C reconstruction; not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections.
 * Compiled 1736 bytes; retail 1776 bytes.
 * us: 0/2 placements match (exit 1).
 * us2: canonical name absent; no check credit.
 * pal: canonical name absent; no check credit.
 * Remaining: The 0x110-byte frame agrees; state-machine branches, global access scheduling and
 * registers still differ. D_001A79F0 now correctly uses absolute addressing as retail does; this
 * grows the earlier 1728-byte source to 1736. The func_002A7750 second argument and
 * func_002B0A68 source pointer retain the current full-width and pointer interfaces.
 * Reopen: A matching mixed absolute/GP state-machine witness and original state-field liveness
 * evidence; preserve the repaired call contracts.
 */

#include "common.h"
typedef int Quad __attribute__((mode(TI)));
#define F(p,o) (*(float *)((u8 *)(p)+(o)))
#define I(p,o) (*(int *)((u8 *)(p)+(o)))
extern u8 D_0019B2E8[],D_00188660[];
extern int D_001A79F0 NOT_SDA;
extern u16 D_0018CC7C NOT_SDA;
extern int D_L16_001A8FF0 NOT_SDA;
extern u8 *D_L16_001B2B1C __attribute__((sda));
extern float D_L16_001B02B0 __attribute__((sda));
extern float D_L16_001B02B8 __attribute__((sda));
extern u32 D_L16_001B02C0 __attribute__((sda));
extern float D_L16_001B02BC NOT_SDA;
extern u32 D_L16_001B02C4 NOT_SDA,D_L16_001B02C8 NOT_SDA,D_L16_001B02CC NOT_SDA;
extern char D_L16_001B02D0[];
extern int D_L16_001B2648 __attribute__((sda));
extern int D_L16_001B3814 __attribute__((sda));
extern u8 D_L16_001B99C0[],D_L16_001A8F20[];
extern float D_L16_001B9B00[4];
extern void func_002A7750(u8 *,s32,s32);
extern float func_L16_003960E8(const u8 *);
extern void func_L14_004272D8(void *);
extern void func_00282F20(void *,void *,float);
extern void func_00282CC0(void *,void *,void *);
extern void func_002A8C28(u8 *,void *,int,int,int,int,float,float,float);
extern int func_002E5CF8(int,int,char *);
extern void func_002E59F8(s32);
extern int func_00288E18(int,int);
extern void func_L00_002E6CF0(void (*)(void *),void *);
extern void func_L16_003C32F8(void *);
extern void *func_002A9640(void *,u32,s32);
extern void func_00282CF0(void *,void *,void *);
extern void func_0032DA58(void *,void *,void *,float);
extern void func_002AB6D8(float *,float *);
extern void func_002B0A68(char *,int,float *,u8,float,float,float,float);
extern int func_002A8508(int,int);
extern s32 func_00288FB8(s32);
extern int func_00115DA8(char *,char *,...);
extern int func_L00_0030DD70(int,int);
extern int func_00282948(int *);
extern void func_002A0430(unsigned int);
extern void func_0029F338(void *);
extern float func_00283B98(float,float);
extern int func_L01_0031BC68(int,int,float);
void func_L16_003C2C08(u8 *object)
{
    float point[4],step[4],normal[4];
    char message[128];
    u8 *state=*(u8 **)(object+0x68),*sound;
    float amount,previous,rate;
    u32 first,second;
    int handle,count,i;
    u16 timer;
    switch (object[0x20]) {
    case 0:
        if (D_0019B2E8[D_001A79F0*16+object[0xB0]]&0x80) goto remove;
        object[0x30]=255;
        *(u16 *)(object+0x32)=0x113;
        *(u16 *)(object+0x34)|=0x4000;
        qcopy(state+0x10,object+0x10);
        F(state,0x48)=0.0f;
        I(state,0x44)=-1;
        F(state,0x24)=D_L16_001B02B8*0.00029088825f;
        func_002A7750(object,1,-1);
        break;
    case 1:
        if (!D_L16_001A8FF0) break;
        amount=func_L16_003960E8(D_L16_001B2B1C+(I(state,0)<<8));
        previous=F(state,0x48);
        if (amount!=0.0f || previous!=0.0f) {
            func_L14_004272D8(object);
            func_00282F20(point,object+0xE0,D_L16_001B02B0*amount*(F(object,0x2C)/F(*(u8 **)(object+0x24),0x24)));
            func_00282CC0(object+0x10,state+0x10,point);
            previous=F(state,0x48);
            if (amount<previous) func_002A8C28(object,object+0x10,0x10000,0,1,0,2.1f,3.0f,1.0f);
        }
        handle=I(state,0x44);
        sound=D_00188660+handle*0x70;
        if (amount==F(state,0x48) || amount==1.0f || amount==0.0f) {
            if (handle!=-1 && *(u8 **)(sound+0x88)==object && sound[0x74]) func_002E59F8(handle);
            I(state,0x44)=-1;
        } else if (*(u8 **)(sound+0x88)!=object || !sound[0x74]) I(state,0x44)=func_002E5CF8(2,4,(char *)object);
        if (amount==1.0f && F(state,0x48)!=1.0f) func_00288E18(0x9EC,67);
        F(state,0x48)=amount;
        if (D_L16_001B3814!=D_L16_001B2648) {
            D_L16_001B3814=D_L16_001B2648;
            func_L00_002E6CF0(func_L16_003C32F8,object);
        }
        if (amount>=1.0f) {
            if (func_002A9640(object,0x10000,0)) {
                func_002E5CF8(0,0,(char *)object);
                object[0xA8]=255;
                func_002A7750(object,2,-1);
                D_0018CC7C=65535;
            }
        } else object[0xA8]=255;
        break;
    case 2:
        timer=*(u16 *)(object+0x96);
        *(u16 *)(object+0x96)=timer+1;
        if (timer<60) {
            if (*(u16 *)(object+0x96)%20==10) func_002E5CF8(3,0,(char *)object);
        } else {
            func_00282F20(point,object+0xE0,-2.0f);
            func_00282F20(step,object+0xE0,5.0f);
            func_00282CC0(point,point,object+0x10);
            func_002A8C28(object,point,0x10000,0,1,0,6.0f,3.0f,1.0f);
            func_002E5CF8(1,0,(char *)object);
            for (i=1;i>=0;i--) {
                func_00282CF0(normal,D_L16_001B9B00,point);
                func_00282F20(normal,normal,1.0f);
                func_0032DA58(object,point,normal,0.0f);
                func_00282CC0(point,point,step);
            }
            F(D_L16_001B99C0,0x180)=0.1f;
            I(D_L16_001B99C0,0x188)=90;
            F(D_L16_001B99C0,0x160)=0.2f;
            I(D_L16_001B99C0,0x168)=60;
            I(D_L16_001B99C0,0x16C)=0;
            func_002AB6D8((float *)(object+0xC0),(float *)(object+0xF0));
            func_002B0A68((char *)object,0xFFF,(float *)D_L16_001A8F20,255,2.0f,4.0f,10.0f,20.0f);
            I(state,0x28)=0;
            I(state,0x2C)=180;
            I(state,0x40)=0;
            I(object,0x98)=0;
            *(u16 *)(object+0x34)=(*(u16 *)(object+0x34)&0xEFFF)|0x41;
            count=func_002A8508(object[0x21],-1);
            if (count-1==0) {
                handle=func_00288FB8(0x2F3B);
                func_L00_0030DD70(handle,180);
                func_002A7750(object,5,-1);
            } else {
                handle=func_00288FB8(0x2F3A);
                func_00115DA8(message,D_L16_001B02D0,(char *)handle,count-1);
                func_002A7750(object,4,-1);
                func_L00_0030DD70((int)message,180);
            }
        }
        break;
    case 4:
        if (func_00282948((int *)(state+0x2C))) goto remove;
        break;
    case 5:
        if (func_00282948((int *)(state+0x2C))) {
            if (object[0xB0]!=255) func_002A0430(object[0xB0]);
            goto remove;
        }
        break;
    }
    if (object[0x31]) {
        if (object[0x20]==2) {
            F(state,0x20)=func_00283B98(F(state,0x20),D_L16_001B02BC*0.00029088825f);
            first=D_L16_001B02C8; second=D_L16_001B02CC;
        } else {
            F(state,0x20)=func_00283B98(F(state,0x20),D_L16_001B02B8*0.00029088825f);
            first=D_L16_001B02C0; second=D_L16_001B02C4;
        }
        *(u32 *)(object+0x78)=func_L01_0031BC68(first,second,F(state,0x20));
    }
    return;
remove:
    func_0029F338(object);
}
