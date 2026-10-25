/* Complete retained reconstruction; not linked.
 * Profile: -O2 -G16 -Wa,-G16 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Tested as src/levels/shared/L16_0040BED0.c.
 * us: 0/2 placements, exit 1.
 * us2: 0/2 placements, exit 1.
 * pal: explicit catalogue absence, no credit.
 * USA compiled 1732 / retail 1824 bytes.
 * Residual: Global-address construction and state-machine/sound-cleanup branch scheduling remain 92 bytes short; helpers and measured address-profile changes did not close it.
 * Reopen with: An independently supported resident/global owner representation and traversal/pool branch layout, preserving the complete 64-byte pool record and 16-byte settings object.
 */

#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef struct { float f0,f4,f8,f12,f16,f20; u8 f24,f25; s16 f26; u8 f28,f29,f30,f31,pad32[16]; s16 f48,f50; int f52,f56,f60; } PoolRecord64;
#define F(p,o) (*(float *)((u8 *)(p)+(o)))
#define I(p,o) (*(int *)((u8 *)(p)+(o)))
#define U(p,o) (*(u32 *)((u8 *)(p)+(o)))
extern u8 D_00189E20[],D_00188660[];
extern u32 D_001A79F0 __attribute__((sda));
extern u32 D_001A7390 __attribute__((sda));
extern int D_L16_001A8F00 NOT_SDA;
extern float D_L16_001A7CD8 __attribute__((sda));
extern float D_L16_001A7CDC NOT_SDA;
extern u32 D_L16_001B2648 __attribute__((sda));
extern u8 *D_L16_001B2B1C __attribute__((sda)),*D_L16_001B2C0C __attribute__((sda));
extern float D_L16_001B15B8 __attribute__((sda));
extern u32 D_L16_001B15BC __attribute__((sda)),D_L16_001B15C0 __attribute__((sda));
extern float D_L16_001B15C4 __attribute__((sda));
extern Quad D_L16_001B15D0;
extern void func_0029F338(void *);
extern float func_00283248(float,float);
extern void func_002A7750(u8 *,s32,s32);
extern void func_L16_0040C7E8(u8 *,void *);
extern int func_002E5CF8(int,int,char *);
extern float func_00282E80(void *,void *);
extern float func_00282E20(void *);
extern float func_00282C10(float);
extern void func_00282CF0(void *,void *,void *);
extern void func_00282F70(void *,void *,float);
extern float func_00282DB0(void *,void *);
extern PoolRecord64 *func_L00_002D70A0(int);
extern void func_L00_002D7140(u8 *);
extern void func_L16_0040C5F0(u8 *);
extern float func_L02_002F21C0(void *,void *);
extern int func_00288E18(int,int);
extern void func_002E59F8(s32);
void func_L16_0040BED0(u8 *object)
{
    float difference[4],value,distance,rate,multiplier;
    u8 *state=*(u8 **)(object+0x68),*target,*sound;
    PoolRecord64 *effect;
    int handle;
    if (D_L16_001A8F00==2) return;
    switch (object[0x20]) {
    case 0:
        if (D_001A79F0==16) D_L16_001A7CDC=D_L16_001B15B8;
        if (I(state,0)==-1) {
            if (I(state,4)==-1) { func_0029F338(object); return; }
            target=D_L16_001B2B1C+(I(state,4)<<8);
            F(object,0xF8)=func_00283248(F(object,0x10)-F(target,0x10),F(object,0x14)-F(target,0x14));
        } else {
            target=D_L16_001B2C0C+(I(state,0)<<7);
            F(object,0xF8)=func_00283248(F(object,0x10)-F(target,0x30),F(object,0x14)-F(target,0x34));
        }
        I(state,0x30)=-1;
        object[0x30]=255;
        *(u16 *)(object+0x34)|=0x2000;
        func_002A7750(object,1,-1);
        break;
    case 1:
        if (I(D_00189E20,0x33C)==(int)object) {
            func_L16_0040C7E8(object,state+0x20);
            D_L16_001A7CD8=(F(state,0x28)-F(D_00189E20,0x88))*2.5f;
            if (D_L16_001A7CD8<37.0f) D_L16_001A7CD8=37.0f;
        }
        if (I(D_00189E20,0x2294)==0x81) {
            if (I(D_00189E20,0x33C)==(int)object && F(D_00189E20,0xF8)>0.0f) {
                multiplier=0.5f;
                func_002E5CF8(1,0,(char *)object);
                if (D_001A79F0==16) multiplier=0.3f;
                distance=func_00282E80(D_00189E20+0x80,state+0x20);
                rate=D_L16_001A7CDC*distance*0.00027777778f*multiplier/D_L16_001A7CD8;
                value=func_00282C10((rate+rate)*distance);
                func_00282CF0(difference,state+0x20,D_00189E20+0x80);
                difference[2]=0.0f;
                func_00282F70(state+0x10,difference,value);
                func_00282F70(D_00189E20+0xF0,D_00189E20+0xF0,0.0f);
                F(state,0xC)=rate;
                func_002A7750(object,2,-1);
            }
        } else if ((D_L16_001B2648&15)==(((u32)object>>8)&15)) {
            if (I(state,4)!=-1 && (*(u16 *)(D_L16_001B2B1C+(I(state,4)<<8)+0x34)&1)) func_002A7750(object,3,-1);
        }
        break;
    case 2:
        if (I(D_00189E20,0x2294)!=0x81) {
            if (I(state,0x38)) {
                effect=*(PoolRecord64 **)(state+0x40);
                effect->f26=0;
                func_L00_002D7140((u8 *)effect);
                I(state,0x38)=0;
            }
            func_002A7750(object,1,-1);
            break;
        }
        value=func_00282E20(state+0x10);
        distance=func_00282E80(D_00189E20+0x80,state+0x20);
        if (distance<0.5f) value=0.0f;
        else if (value!=0.0f) {
            func_00282CF0(difference,state+0x20,D_00189E20+0x80);
            difference[2]=0.0f;
            if (func_00282DB0(difference,state+0x10)<0.0f) value=0.0f;
        }
        value-=F(state,0xC);
        func_00282F70(state+0x10,state+0x10,value);
        func_00282F70(D_00189E20+0xF0,D_00189E20+0xF0,0.0f);
        qcopy(D_00189E20+0x100,state+0x10);
        F(D_00189E20,0x10C)=0.0f;
        if (value!=0.0f) F(D_00189E20,0x1A0)=func_00283248(F(state,0x10),F(state,0x14));
        I(D_00189E20,0x1DC)=10;
        if (D_001A79F0==17 && !I(state,0x38)) {
            effect=func_L00_002D70A0(5);
            *(PoolRecord64 **)(state+0x40)=effect;
            if (effect) {
                I(state,0x38)=1;
                qcopy(effect->pad32,&D_L16_001B15D0);
                *(u32 *)&effect->f0=D_L16_001B15BC;
                *(u32 *)&effect->f4=D_L16_001B15C0;
                effect->f12=D_L16_001B15C4*0.017453294f;
                effect->f30=1;
                effect->f26=1;
            }
        }
        break;
    case 3:
        target=D_L16_001B2B1C+(I(state,4)<<8);
        if ((*(u16 *)(target+0x34)&1) && object[0x23]) {
            I(object,0x98)=0;
            if (object[0x23]<4) object[0x23]=0;
            else object[0x23]-=4;
        } else if (!(*(u16 *)(target+0x34)&1)) {
            if (object[0x23]<124) object[0x23]+=4;
            else {
                object[0x23]=128;
                func_002A7750(object,1,-1);
                I(object,0x98)=I(*(u8 **)(object+0x24),0x10);
            }
        }
        break;
    }
    if (object[0x31] && object[0x20]!=3) func_L16_0040C5F0(object);
    if (D_001A79F0==16 && func_L02_002F21C0(D_00189E20+0x80,object+0x10)<9.0f) {
        if (*(s16 *)(D_00189E20+0x2FDC)==0) {
            *(s16 *)(D_00189E20+0x2FDC)=1;
            if (U(D_00189E20,0x2FE0)<D_001A7390) U(D_00189E20,0x2FE0)=D_001A7390;
            U(D_00189E20,0x2FE4)|=(1U<<(D_001A79F0&31))|0x80000000U;
        } else if (D_001A7390-U(D_00189E20,0x2FE0)>1080 || U(D_00189E20,0x2FE0)==0) func_00288E18(0xA0C,99);
        else if (D_001A7390>U(D_00189E20,0x2FE0)) U(D_00189E20,0x2FE0)=D_001A7390;
    }
    if (object[0x20]==2) *(s16 *)(D_00189E20+0x2FDC)=-1;
    handle=I(state,0x30);
    sound=D_00188660+handle*0x70;
    if (!(*(u16 *)(object+0x34)&1) && I(object,0x98)!=0) {
        if (*(u8 **)(sound+0x88)==object && sound[0x74]) return;
        I(state,0x30)=func_002E5CF8(0,4,(char *)object);
        return;
    }
    if (handle!=-1 && *(u8 **)(sound+0x88)==object && sound[0x74]) func_002E59F8(handle);
    I(state,0x30)=-1;
}
