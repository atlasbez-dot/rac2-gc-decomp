/* 2026-10-23 C reconstruction. Measured with -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-
   barrier. us: 0/2 placements, 16_snivelak: 2148 bytes, expected 2152; us2: 0/2 placements,
   16_snivelak: 2148 bytes, expected 2152; pal: 0/2 placements, 16_snivelak: 2148 bytes, expected 2152.
   Complete multi-pass trail rendering reconstructed with the measured sixth-GPR object input and five
   explicitly unused/unqualified raw slots. Alias-lifetime source changes emitted identical code. A
   typed packet union shortened to2100 and changed the frame, so the2148-byte0x160-frame source is
   retained. UV temporary and pointer/register scheduling remain4bytes short. Reopen when: An exact
   centered-UV packet witness preserving the actual incoming object slot. Historical screening follows
   unchanged.
 */

/* func_L16_00405818 - 2152 bytes, 2 place(s), level 16_snivelak, retail at
   0x00405818. Screened with tools/w10_screen.py: 67 call(s)
   [func_L11_00458D00@00405854, func_00281DE8@00405868,
   func_00282CF0@004059B4, func_00282F20@004059C8, func_00282CC0@004059D8,
   func_00282DD8@004059E8, func_00282F20@004059F8, func_00282F20@00405A0C,
   func_00282CC0@00405A1C, func_00282CC0@00405A2C, func_00282CF0@00405A3C,
   func_00282CC0@00405A4C, func_00282CF0@00405A5C, func_00280B90@00405A6C,
   func_00282CC0@00405AB0, func_00282CC0@00405AC0, func_00280B90@00405AD0,
   func_00282F20@00405AE4, func_00283180@00405B18, func_00283198@00405B24,
   func_00283B98@00405BD0, func_00281DE8@00405BE8, func_00282F20@00405C54,
   func_00282F20@00405C68, func_00282CC0@00405C78, func_00282CC0@00405C88,
   func_00282CF0@00405C98, func_00282CC0@00405CA8, func_00282CC0@00405CB8,
   func_00282CC0@00405CC8, func_00282CF0@00405CD8, func_00280B90@00405CE8,
   func_00282F20@00405D4C, func_00282F20@00405D5C, func_00282CC0@00405D6C,
   func_00282CC0@00405D7C, func_00282CF0@00405D8C, func_00282CC0@00405D9C,
   func_00282CC0@00405DAC, func_00282CC0@00405DBC, func_00282CF0@00405DCC,
   func_00280B90@00405DDC, func_00282F20@00405E40, func_00282F20@00405E50,
   func_00282CC0@00405E60, func_00282CC0@00405E70, func_00282CF0@00405E80,
   func_00282CC0@00405E90, func_00282CC0@00405EA0, func_00282CC0@00405EB0,
   func_00282CF0@00405EC0, func_00280B90@00405ED0, func_00282F20@00405F34,
   func_00282F20@00405F44, func_00282CC0@00405F54, func_00282CC0@00405F64,
   func_00282CF0@00405F74, func_00282F20@00405F8C, func_00282CC0@00405F9C,
   func_00282CC0@00405FAC, func_00282CC0@00405FBC, func_00282CF0@00405FCC,
   func_00280B90@00405FDC, func_002A7940@00405FE4, func_00281EB8@00406004,
   func_002A7940@0040601C, func_00281EB8@00406040]; data addresses
   materialised [0x3dcc0000, 0x1c0000, 0x1b0000, 0x800000, 0x3c8e0000,
   0x3da30000, 0x1b0000, 0xbf190000, 0x3ecc0000, 0x80800000]; float
   constants [0x3f800000, 0x40e00000, 0x40800000, 0xc0800000, 0x3f800000,
   0x3f000000]; $gp-relative small data: no   saves: -; callee-saved
   registers saved [-]; words plain C cannot emit [LQ/SQ 7AC20000@0x027c,
   LQ/SQ 7FA20000@0x0280, LQ/SQ 7AE20000@0x0288, LQ/SQ 7C620000@0x028c].
   Head: addiu $sp, $sp, -0x160 ; sd $s0, 0x100($sp) ; daddu $a0, $sp, $zero
   ; sd $s1, 0x108($sp) ; daddu $s0, $t1, $zero ; sd $s2, 0x110($sp). Not
   matched in this wave: the 128-bit copy needs an `lq`/`sq` pair; plain C
   reaches it only through a `mode(TI)` local, and this cc1 folds the
   destination offset into the `sq` where retail materialises the pointer
   first. What would unblock it: the exact source expression tree, so this
   cc1 picks the same registers in the same order. */

#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef struct { u8 pad[0x70]; long f70,f78,f80,f88; } QuadPacket;
extern void func_00281DE8(QuadPacket *,int,int,int);
extern void func_00282CF0(void *,void *,void *);
extern void func_00282F20(void *,void *,float);
extern void func_00282CC0(void *,void *,void *);
extern void func_00282DD8(void *,void *,void *);
extern void func_00280B90(void *,void *,int);
extern void func_00281EB8(void *,int,u32,int,float,float,float);
extern float func_00283180(float);
extern float func_00283198(float);
extern float func_00283B98(float,float);
extern float func_002A7940(void);
extern float D_L16_001B9B00[4];
extern void func_L11_00458D00(char *);
extern float D_L16_001B1504 NOT_SDA;
extern float D_L16_001B1468 __attribute__((sda));
extern float D_L16_001B146C __attribute__((sda));
extern float D_L16_001B1470 __attribute__((sda));
extern float D_L16_001B1474 __attribute__((sda));
extern float D_L16_001B147C __attribute__((sda));
extern float D_L16_001B1490 __attribute__((sda));
extern float D_L16_001B1494 __attribute__((sda));
extern float D_L16_001B14F8 __attribute__((sda));
extern float D_L16_001B14FC __attribute__((sda));
extern u32 D_L16_001B1478 __attribute__((sda));
extern u32 D_L16_001B1480 __attribute__((sda));
extern u32 D_L16_001B1484 __attribute__((sda));
extern u32 D_L16_001B1488 __attribute__((sda));
extern u32 D_L16_001B148C __attribute__((sda));
extern u32 D_L16_001B1498 __attribute__((sda));
extern u32 D_L16_001B149C __attribute__((sda));
extern u32 D_L16_001B14A8 __attribute__((sda));
extern u32 D_L16_001B14AC __attribute__((sda));
extern u32 D_L16_001B14B0 __attribute__((sda));
extern u32 D_L16_001B14B4 __attribute__((sda));
extern u32 D_L16_001B14B8 __attribute__((sda));
extern u32 D_L16_001B14BC __attribute__((sda));
extern u32 D_L16_001B14C0 __attribute__((sda));
extern u32 D_L16_001B14C4 __attribute__((sda));
extern u32 D_L16_001B14C8 __attribute__((sda));
extern u32 D_L16_001B14CC __attribute__((sda));
extern u32 D_L16_001B14D0 __attribute__((sda));
extern u32 D_L16_001B14D8 __attribute__((sda));
extern u32 D_L16_001B14DC __attribute__((sda));
extern u32 D_L16_001B14E0 __attribute__((sda));
extern u32 D_L16_001B14E8 __attribute__((sda));
extern u32 D_L16_001B14EC __attribute__((sda));
extern u32 D_L16_001B14F0 __attribute__((sda));
/* Only the sixth GPR slot is observed: retail copies t1. The first five
   raw slots below are unused; their original semantic types remain unknown. */
void func_L16_00405818(u32 unused0,u32 unused1,u32 unused2,u32 unused3,u32 unused4,u8 *object)
{
    QuadPacket packet;
    float camera[4],back[4],rear[4],side[4],center[4];
    float *vertex;
    float *uv;
    u32 *color;
    u8 *state=*(u8 **)(object+0x68);
    float cosine,sine,x,y,angle,size;
    int i;
    (void)unused0; (void)unused1; (void)unused2; (void)unused3; (void)unused4;
    func_L11_00458D00((char *)&packet);
    func_00281DE8(&packet,D_L16_001B1498,1,0x80);
    vertex=(float *)packet.pad;
    uv=(float *)(packet.pad+0x50);
    color=(u32 *)(packet.pad+0x40);
    color[0]=color[1]=(D_L16_001B14B4<<24)|(D_L16_001B14B0<<16)|(D_L16_001B14AC<<8)|D_L16_001B14A8;
    color[2]=color[3]=(D_L16_001B14C4<<24)|(D_L16_001B14C0<<16)|(D_L16_001B14BC<<8)|D_L16_001B14B8;
    uv[0]=0.0f; uv[1]=0.0f; uv[2]=0.0f; uv[3]=1.0f;
    uv[4]=1.0f; uv[5]=0.0f; uv[6]=1.0f; uv[7]=1.0f;
    for (i=0;i<4;i++) {
        uv[i*2]-=*(float *)(state+0x28);
        if (uv[i*2]<=7.0f) uv[i*2]+=7.0f;
    }
    *(float *)(state+0x28)+=0.1f;
    if (*(float *)(state+0x28)>=4.0f) *(float *)(state+0x28)-=4.0f;
    func_00282CF0(camera,object+0x10,D_L16_001B9B00);
    func_00282F20(back,state,-D_L16_001B1494);
    func_00282CC0(rear,object+0x10,back);
    func_00282DD8(side,camera,back);
    func_00282F20(side,side,D_L16_001B1474);
    func_00282F20(center,state,D_L16_001B1504);
    func_00282CC0(center,object+0x10,center);
    func_00282CC0(vertex,center,side);
    func_00282CF0(vertex+4,center,side);
    func_00282CC0(vertex+8,rear,side);
    func_00282CF0(vertex+12,rear,side);
    func_00280B90(&packet,0,0);
    color[0]=color[2]; color[1]=color[3]; color[2]=color[3]=0x801010;
    *(Quad *)vertex=*(Quad *)(vertex+8);
    *(Quad *)(vertex+4)=*(Quad *)(vertex+12);
    func_00282CC0(vertex+8,vertex+8,back);
    func_00282CC0(vertex+12,vertex+12,back);
    func_00280B90(&packet,0,0);
    func_00282F20(back,state,-4.0f);
    uv[0]=0.0f; uv[1]=0.0f; uv[2]=0.0f; uv[3]=1.0f;
    uv[4]=1.0f; uv[5]=0.0f; uv[6]=1.0f; uv[7]=1.0f;
    cosine=func_00283180(*(float *)(state+0x1C));
    sine=func_00283198(*(float *)(state+0x1C));
    for (i=0;i<4;i++) {
        x=uv[i*2]-0.5f; y=uv[i*2+1]-0.5f;
        uv[i*2]=x*cosine-y*sine+0.5f;
        uv[i*2+1]=x*sine+y*cosine+0.5f;
    }
    *(float *)(state+0x1C)=func_00283B98(*(float *)(state+0x1C),D_L16_001B1490*0.017453294f);
    func_00281DE8(&packet,D_L16_001B149C,1,0x80);
    packet.f70=5;
    color[0]=color[1]=(D_L16_001B1484<<24)|(D_L16_001B14D0<<16)|(D_L16_001B14CC<<8)|D_L16_001B14C8;
    color[2]=color[3]=(D_L16_001B14E0<<16)|(D_L16_001B14DC<<8)|D_L16_001B14D8;
    func_00282F20(side,side,D_L16_001B1468);
    func_00282F20(center,state,D_L16_001B1504);
    func_00282CC0(center,object+0x10,center);
    func_00282CC0(vertex,center,side);
    func_00282CF0(vertex+4,center,side);
    func_00282CC0(rear,center,back);
    func_00282CC0(rear,rear,back);
    func_00282CC0(vertex+8,rear,side);
    func_00282CF0(vertex+12,rear,side);
    func_00280B90(&packet,0,0);
    color[0]=color[1]=(D_L16_001B1484<<24)|(D_L16_001B14D0<<16)|(D_L16_001B14CC<<8)|D_L16_001B14C8;
    color[2]=color[3]=(D_L16_001B14E0<<16)|(D_L16_001B14DC<<8)|D_L16_001B14D8;
    func_00282F20(side,side,D_L16_001B146C);
    func_00282F20(center,state,D_L16_001B14F8);
    func_00282CC0(center,object+0x10,center);
    func_00282CC0(vertex,center,side);
    func_00282CF0(vertex+4,center,side);
    func_00282CC0(rear,center,back);
    func_00282CC0(rear,rear,back);
    func_00282CC0(vertex+8,rear,side);
    func_00282CF0(vertex+12,rear,side);
    func_00280B90(&packet,0,0);
    color[0]=color[1]=(D_L16_001B148C<<24)|(D_L16_001B14D0<<16)|(D_L16_001B14CC<<8)|D_L16_001B14C8;
    color[2]=color[3]=(D_L16_001B14E0<<16)|(D_L16_001B14DC<<8)|D_L16_001B14D8;
    func_00282F20(side,side,D_L16_001B1470);
    func_00282F20(center,state,D_L16_001B14F8);
    func_00282CC0(center,object+0x10,center);
    func_00282CC0(vertex,center,side);
    func_00282CF0(vertex+4,center,side);
    func_00282CC0(rear,center,back);
    func_00282CC0(rear,rear,back);
    func_00282CC0(vertex+8,rear,side);
    func_00282CF0(vertex+12,rear,side);
    func_00280B90(&packet,0,0);
    color[0]=color[1]=(D_L16_001B1488<<24)|(D_L16_001B14F0<<16)|(D_L16_001B14EC<<8)|D_L16_001B14E8;
    color[2]=color[3]=(D_L16_001B14E0<<16)|(D_L16_001B14DC<<8)|D_L16_001B14D8;
    func_00282F20(side,side,D_L16_001B1468);
    func_00282F20(center,state,D_L16_001B14FC);
    func_00282CC0(center,object+0x10,center);
    func_00282CC0(vertex,center,side);
    func_00282CF0(vertex+4,center,side);
    func_00282F20(back,state,-0.6f);
    func_00282CC0(rear,center,back);
    func_00282CC0(rear,rear,back);
    func_00282CC0(vertex+8,rear,side);
    func_00282CF0(vertex+12,rear,side);
    func_00280B90(&packet,0,0);
    angle=func_002A7940();
    func_00281EB8(object+0x10,D_L16_001B1478,D_L16_001B1480,1,D_L16_001B147C,0.08f,angle);
    size=D_L16_001B147C*0.4f;
    angle=func_002A7940();
    func_00281EB8(object+0x10,D_L16_001B1478,0x80808080U,1,size,0.08f,angle);
}
