/*
 * Retained complete manual C reconstruction; not linked or counted.
 * Profile: -O2 -G16 -ffunction-sections -Wa,-G16
 * 1356/1428 bytes; 0/1 placements in us, us2 and pal.
 * Residual: The two contacts, eight-region scan, two phase/drift pairs and complete history
 * transfers are retained. Loop/base materialization and scalar/store scheduling remain
 * different.
 * Reopen: Independent layer/contact/history field lifetimes and allocation evidence; keep the
 * bounded two-pair 16-byte spans and true GP accesses, without undersized globals.
 * Trial-only source markers and profiles are restored after checking.
 */

#include "common.h"
typedef int Quad __attribute__((mode(TI)));
#define I32(p,o) (*(int *)((p)+(o)))
#define F32(p,o) (*(float *)((p)+(o)))
#define S16(p,o) (*(short *)((p)+(o)))
extern u8 D_00189E20[],D_00189EA0[];
extern float D_001A7928;
extern int func_002ACBC8(void *,int);
extern void func_00282CF0(void *,void *,void *),func_00282D30(void *,void *,float);
extern int func_00283CF0(float);
extern float func_00283CE0(int),func_00283198(float);
extern void func_L00_002E6DB8(void (*)(void *),void *);
extern Quad D_L01_001B2FC0 __attribute__((sda));
extern u8 D_L01_001B94C0[];
extern u8 *D_L01_001B264C;
/* Bounded views of the two accessed layers, not whole-global extent claims. */
typedef struct { float u, v; } LayerPair;
extern LayerPair D_L01_001B2FD0[2];
typedef struct { float speed[2]; } LayerSpeedPrefix;
extern LayerSpeedPrefix D_L01_001AFDF0 __attribute__((sda));
extern LayerPair D_L01_001AFE00[2] __attribute__((sda));
extern float D_L01_001AFE18 __attribute__((sda)),D_L01_001AFE1C __attribute__((sda));

extern int D_L01_001B2088;
extern float *D_L01_001A9164;
extern void func_L01_003BAFB8(void *);
void func_L01_003BB9D0(u8 *object)
{
    u8 *state=*(u8 **)(object+0x68);
    float delta[4] __attribute__((aligned(16))),scaled[4] __attribute__((aligned(16)));
    int i,index;
    if(object[0x20]==0) {
        object[0x30]=255; object[0x20]=1;
        I32(state,0)=0x80103030; I32(state,4)=0x800c1006;
        I32(state,0xc)=0x50106060; I32(state,0x10)=0x106060;
        F32(state,0x28)=224.0f;
        for(i=1;i>=0;i--) { D_L01_001B2FD0[i].u=0.0f;D_L01_001B2FD0[i].v=0.0f; }
        qcopy(&D_L01_001B2FC0, D_L01_001B94C0);
        D_L01_001AFE1C=F32(state,0x14);
        return;
    }
    for(i=0;i<2;i++) {
        index=I32(state,0x30+i*4);
        if(index==-1) continue;
        if(I32(D_00189E20,0x2294)==28 && func_002ACBC8(D_L01_001B94C0,index)) {
            S16(D_00189E20,0x1fe)=0;
            return;
        }
        if(func_002ACBC8(D_00189EA0,index)) {
            S16(D_00189EA0,0x17e)=0;
            return;
        }
    }
    D_L01_001AFE1C=F32(state,0x14);
    for(i=0;i<8;i++) {
        index=I32(state,0x40+i*4);
        if(index==-1) continue;
        if((I32(D_00189E20,0x2294)==28 && func_002ACBC8(D_L01_001B94C0,index)) || func_002ACBC8(D_00189EA0,index)) {
            D_L01_001AFE1C=F32(D_L01_001B264C+index*128,0x38)+0.15f;
            break;
        }
    }
    S16(D_00189E20,0x1fe)=2;
    func_00282CF0(delta,D_L01_001B94C0,&D_L01_001B2FC0);
    qcopy(&D_L01_001B2FC0, D_L01_001B94C0);
    if(!(F32(state,0x20)<F32(D_L01_001B94C0,8))) return;
    for(i=0;i<2;i++) {
        func_00282D30(scaled,delta,(D_L01_001AFDF0.speed[i]+D_L01_001AFDF0.speed[i])/(F32(state,0x18)*5.0f));
        if(1.0f<scaled[0] || scaled[0]<1.0f) scaled[0]-=func_00283CE0(func_00283CF0(scaled[0]));
        if(1.0f<scaled[1] || scaled[1]<1.0f) scaled[1]-=func_00283CE0(func_00283CF0(scaled[1]));
        D_L01_001B2FD0[i].u+=scaled[0];
        D_L01_001B2FD0[i].v+=scaled[1];
        if(1.0f<D_L01_001B2FD0[i].u) D_L01_001B2FD0[i].u-=1.0f;
        if(D_L01_001B2FD0[i].u<-1.0f) D_L01_001B2FD0[i].u+=1.0f;
        if(1.0f<D_L01_001B2FD0[i].v) D_L01_001B2FD0[i].v-=1.0f;
        if(D_L01_001B2FD0[i].v<-1.0f) D_L01_001B2FD0[i].v+=1.0f;
    }
    D_L01_001AFE18=D_L01_001AFE1C+func_00283198(func_00283CE0(D_L01_001B2088%360)*0.017444444820284843f-3.140000104904175f)*0.1f;
    D_L01_001A9164=&D_L01_001AFE18;
    for(i=0;i<2;i++) {
        D_L01_001B2FD0[i].u+=D_L01_001AFE00[i].u*D_001A7928;
        if(1.0f<D_L01_001B2FD0[i].u) D_L01_001B2FD0[i].u-=1.0f;
        if(D_L01_001B2FD0[i].u<-1.0f) D_L01_001B2FD0[i].u+=1.0f;
        D_L01_001B2FD0[i].v+=D_L01_001AFE00[i].v*D_001A7928;
        if(1.0f<D_L01_001B2FD0[i].v) D_L01_001B2FD0[i].v-=1.0f;
        if(D_L01_001B2FD0[i].v<-1.0f) D_L01_001B2FD0[i].v+=1.0f;
    }
    func_L00_002E6DB8(func_L01_003BAFB8,object);
}
