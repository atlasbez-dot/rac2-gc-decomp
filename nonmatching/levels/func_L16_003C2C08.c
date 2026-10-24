/* 2026-10-23 C reconstruction. Measured with -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-
   barrier. us: 0/2 placements, 16_snivelak: 1728 bytes, expected 1776; us2: canonical name absent;
   pal: canonical name absent. Gate state machine, effects, dialogue and flashing color reconstructed.
   The color helper consumes live f12 and returns v0; the caller now uses root-qualified int
   func_L01_0031BC68(int,int,float), rather than the stale void two-int wrapper. Frame0x110 agrees;
   address modes and control flow remain48bytes short. Reopen when: A matching mixed GP/absolute
   global-access and state-machine witness; preserve the corrected color ABI. Historical screening
   follows unchanged.
 */

/* func_L16_003C2C08 - 1776 bytes, 2 place(s), level 16_snivelak, retail at
   0x003c2c08. Screened with tools/w10_screen.py: 40 call(s)
   [func_002A7750@003C2CE8, func_L16_003960E8@003C2D10,
   func_L14_004272D8@003C2D44, func_00282F20@003C2D6C,
   func_00282CC0@003C2D7C, func_002A8C28@003C2DC4, func_002E5CF8@003C2E4C,
   func_002E59F8@003C2E90, func_00288E18@003C2ED4,
   func_L00_002E6CF0@003C2F04, func_002A9640@003C2F2C,
   func_002E5CF8@003C2F40, func_002A7750@003C2F58, func_00282F20@003C2FA4,
   func_00282F20@003C2FC0, func_00282CC0@003C2FD8, func_002A8C28@003C3010,
   func_002E5CF8@003C3020, func_00282CF0@003C3038, func_00282F20@003C304C,
   func_0032DA58@003C3060, func_00282CC0@003C3070, func_002AB6D8@003C30C0,
   func_002B0A68@003C30F8, func_002A8508@003C3128, func_00288FB8@003C3144,
   0x115da8@003C315C, func_002A7750@003C316C, func_L00_0030DD70@003C3178,
   func_00288FB8@003C3188, func_L00_0030DD70@003C3194,
   func_002A7750@003C31A4, func_002E5CF8@003C31E0, func_00282948@003C31F0,
   func_00282948@003C3208, func_002A0430@003C3224, func_0029F338@003C322C,
   func_00283B98@003C326C, func_00283B98@003C32A0,
   func_L01_0031BC68@003C32BC]; data addresses materialised [0x2a0000,
   0x1a0000, 0x1a0000, 0x39980000, 0x1b0000, 0x40060000, 0x10000, 0x190000,
   0x1b0000, 0x1b0000, 0x3c0000, 0x1b0000, 0x10000, 0x190000, 0x1c0000,
   0x10000, 0x3dcc0000, 0x1c0000, 0x3e4c0000, 0x1b0000, 0x1b0000, 0x1b0000,
   0x39980000, 0x1b0000, 0x39980000, 0x1b0000]; float constants [0x40400000,
   0x3f800000, 0x3f800000, 0x190000, 0x3f800000, 0x3f800000, 0xc0000000,
   0x40a00000, 0x40c00000, 0x40400000, 0x3f800000, 0x3f800000, 0x41a00000,
   0x40000000, 0x40800000, 0x41200000, 0x1b0000]; $gp-relative small data:
   no   saves: -; callee-saved registers saved [-]; words plain C cannot
   emit [LQ/SQ 78620000@0x00ac, LQ/SQ 7C820000@0x00b0]. Head: addiu $sp,
   $sp, -0x110 ; sd $s3, 0xC8($sp) ; sd $s0, 0xB0($sp) ; daddu $s3, $a0,
   $zero ; sd $s1, 0xB8($sp) ; sd $s2, 0xC0($sp). Not matched in this wave:
   the 128-bit copy needs an `lq`/`sq` pair; plain C reaches it only through
   a `mode(TI)` local, and this cc1 folds the destination offset into the
   `sq` where retail materialises the pointer first. What would unblock it:
   the exact source expression tree, so this cc1 picks the same registers in
   the same order. */

#include "common.h"
typedef int Quad __attribute__((mode(TI)));
#define F(p,o) (*(float *)((u8 *)(p)+(o)))
#define I(p,o) (*(int *)((u8 *)(p)+(o)))
extern u8 D_0019B2E8[],D_00188660[];
extern int D_001A79F0 __attribute__((sda));
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
extern void func_002A7750(u8 *,u8,s32);
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
extern void func_002B0A68(char *,int,int,u8,float,float,float,float);
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
        *(Quad *)(state+0x10)=*(Quad *)(object+0x10);
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
            func_002B0A68((char *)object,0xFFF,(int)D_L16_001A8F20,255,2.0f,4.0f,10.0f,20.0f);
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
