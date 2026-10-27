/*
 * Retained complete manual C reconstruction; not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections -frac2-zero-ti-por -g
 * 1296/1336 bytes.
 * us: 0/7 placements; us2: 0/7 placements; pal: absent from catalogue.
 * Residual: Four complete144-byte packets, the64-byte affine frame,48-byte rotation, angle
 * clear and real position capture are retained. The frame is0x350 versus retail0x360. Separate
 * UV/color/vertex cursors shorten to1260 bytes with a0x340 frame and are not retained; inner-
 * loop induction and spill allocation still differ.
 * Reopen: Independent packet/UV/color cursor lifetime and scalar-spill evidence beyond the
 * measured simultaneous-cursor form; no fake local space or reduced packets.
 * Trial-only source markers and profiles are restored after checking.
 */

#include "common.h"

typedef int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } Vector;
typedef struct {
    Vector point[4];
    unsigned int color[4];
    float uv[8];
    u64 reserved, texture, setup, state;
} EffectPacket;
extern int ref_L02_00410F68_0 __attribute__((sda));
extern int ref_L02_00410F68_1 __attribute__((sda));
extern int ref_L02_00410F68_2 __attribute__((sda));
extern int ref_L02_00410F68_3 __attribute__((sda));
extern int ref_L02_00410F68_4 __attribute__((sda));
extern float ref_L02_00410F68_5 __attribute__((sda));
extern unsigned int ref_L02_00410F68_6[2] __attribute__((sda));
extern float ref_L02_00410F68_7[] __attribute__((sda));
extern float ref_L02_00410F68_8 __attribute__((sda));
extern float ref_L02_00410F68_9 __attribute__((sda));
extern u8 D_00189E20[];
extern float D_L02_001B1A8C[];
extern void func_00283658(void *,void *);
extern u64 func_0027C878(int);
extern void func_00282CF0(void *,void *,void *);
extern void func_002AC9F8(void *,float);
extern unsigned int func_00283D38(unsigned int,unsigned int,float);
extern void func_00282C90(void *);
extern void func_002833F0(void *,void *);
extern void func_L01_002E1510(void *,int,void *,int,void *);

/* Assemble four animated strips in the object's coordinate frame. */
void func_L02_00410F68(u8 *object)
{
    EffectPacket packet[4];
    Vector frame[4];
    Vector rotation[3];
    Vector angle;
    u8 *effect=*(u8 **)(object+0x68);
    EffectPacket *p;
    u8 *resident;
    float alpha,spread,shrink,time;
    int i,j;
    func_00283658(frame,object+0xC0);
    qcopy(&frame[3],object+0x10);
    p=packet;
    do {
        p->texture=func_0027C878(ref_L02_00410F68_0);
        p->setup=0xFF9000000260ULL;
        p->reserved=0;
        p->state=(long long)ref_L02_00410F68_1 | ((u64)(long long)ref_L02_00410F68_2<<2) | ((u64)(long long)ref_L02_00410F68_3<<4) | ((u64)(long long)ref_L02_00410F68_4<<6) | 0x8000000000ULL;
        p++;
    } while ((int)p<(int)(packet+4));
    time=*(float *)(effect+0x34);
    alpha=(1.95f-time)*2.0f;
    if(alpha>1.0f) alpha=1.0f;
    else if(alpha<0.0f) alpha=0.0f;
    spread=0.1f;
    if(time<1.15f) {
        resident=D_00189E20+0x100;
        func_00282CF0(resident,object+0x10,resident-0x80);
        resident-=0x100;
        *(float *)(resident+0x108)=0;
        func_002AC9F8(resident+0x100,0.016666668f);
        time=*(float *)(effect+0x34);
        shrink=1.15f-time;
        if(shrink<0) shrink=0;
        spread=(0.2f-time)*5.0f;
        if(spread<0) spread=0;
        if(*(int *)(effect+0x38)<0) ref_L02_00410F68_5=spread;
        spread=shrink+0.1f;
        if(time<0.65f) {
            float scale=time*1.538461566f;
            *(short *)(resident+0x2500)=1;
            *(float *)(resident+0x2024)=scale;
            *(float *)(resident+0x2020)=scale;
            *(float *)(resident+0x2028)=2.0f-scale;
        } else *(short *)(resident+0x2500)=0;
    }
    for(i=0;i<4;i++) {
        j=0;
        do {
            unsigned int color;
            packet[i].uv[j*2]=ref_L02_00410F68_7[j*2];
            packet[i].uv[j*2+1]=D_L02_001B1A8C[j*2];
            color=ref_L02_00410F68_6[i!=0];
            packet[i].color[j]=color;
            packet[i].color[j]=func_00283D38(color&0xFFFFFF,color,alpha);
            func_00282C90(&packet[i].point[j]);
            time=*(float *)(effect+0x34);
            if(i!=0) time+=0.01f;
            packet[i].point[j].f[0]=time;
            if(j&1) {
                switch(i) {
                case 0: packet[0].point[j].f[2]+=ref_L02_00410F68_8+spread; break;
                case 1: packet[1].point[j].f[2]+=ref_L02_00410F68_8+ref_L02_00410F68_9; break;
                case 2: packet[2].point[j].f[2]+=(ref_L02_00410F68_8-spread*0.8f)+ref_L02_00410F68_9; break;
                case 3: packet[3].point[j].f[2]+=(ref_L02_00410F68_8+spread*0.8f)+ref_L02_00410F68_9; break;
                }
            } else {
                switch(i) {
                case 0: packet[0].point[j].f[2]+=ref_L02_00410F68_8-spread; break;
                case 1: packet[1].point[j].f[2]+=ref_L02_00410F68_8-ref_L02_00410F68_9; break;
                case 2: packet[2].point[j].f[2]+=(ref_L02_00410F68_8-spread*0.8f)-ref_L02_00410F68_9; break;
                case 3: packet[3].point[j].f[2]+=(ref_L02_00410F68_8+spread*0.8f)-ref_L02_00410F68_9; break;
                }
            }
            j++;
        } while (j<4);
    }
    angle.q=0; angle.f[2]=0.19634955f;
    func_002833F0(rotation,&angle);
    func_L01_002E1510(packet,4,rotation,32,frame);
}
