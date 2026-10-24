/* 2026-10-23 C reconstruction. Measured with -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-
   barrier. us: 0/2 placements, 16_snivelak: 2128 bytes, expected 2132; us2: 0/2 placements,
   16_snivelak: 2128 bytes, expected 2132; pal: 0/2 placements, 16_snivelak: 2128 bytes, expected 2132.
   Complete multi-pass trail rendering reconstructed. Retail copies the live object from t1, the sixth
   GPR slot; the first five raw slots are unused and remain explicitly unqualified, not invented
   semantic arguments. Frame0x160 agrees; pointer lifetimes and UV temporary scheduling remain4bytes
   short. Reopen when: A matching draw-packet pointer-lifetime and centered-UV witness preserving the
   sixth-slot input. Historical screening follows unchanged.
 */

/* func_L16_00414038 - 2132 bytes, 2 place(s), level 16_snivelak, retail at
   0x00414038. Screened with tools/w10_screen.py: 67 call(s)
   [func_L11_0045FFB0@00414074, func_00281DE8@00414088,
   func_00282CF0@004141D4, func_00282F20@004141E8, func_00282CC0@004141F8,
   func_00282DD8@00414208, func_00282F20@00414218, func_00282F20@0041422C,
   func_00282CC0@0041423C, func_00282CC0@0041424C, func_00282CF0@0041425C,
   func_00282CC0@0041426C, func_00282CF0@0041427C, func_00280B90@0041428C,
   func_00282CC0@004142D0, func_00282CC0@004142E0, func_00280B90@004142F0,
   func_00282F20@00414304, func_00283180@00414338, func_00283198@00414344,
   func_00283B98@004143F0, func_00281DE8@00414408, func_00282F20@00414474,
   func_00282F20@00414488, func_00282CC0@00414498, func_00282CC0@004144A8,
   func_00282CF0@004144B8, func_00282CC0@004144C8, func_00282CC0@004144D8,
   func_00282CC0@004144E8, func_00282CF0@004144F8, func_00280B90@00414508,
   func_00282F20@0041456C, func_00282F20@0041457C, func_00282CC0@0041458C,
   func_00282CC0@0041459C, func_00282CF0@004145AC, func_00282CC0@004145BC,
   func_00282CC0@004145CC, func_00282CC0@004145DC, func_00282CF0@004145EC,
   func_00280B90@004145FC, func_00282F20@00414660, func_00282F20@00414670,
   func_00282CC0@00414680, func_00282CC0@00414690, func_00282CF0@004146A0,
   func_00282CC0@004146B0, func_00282CC0@004146C0, func_00282CC0@004146D0,
   func_00282CF0@004146E0, func_00280B90@004146F0, func_00282F20@00414740,
   func_00282F20@00414750, func_00282CC0@00414760, func_00282CC0@00414770,
   func_00282CF0@00414780, func_00282F20@00414798, func_00282CC0@004147A8,
   func_00282CC0@004147B8, func_00282CC0@004147C8, func_00282CF0@004147D8,
   func_00280B90@004147E8, func_002A7940@004147F0, func_00281EB8@00414810,
   func_002A7940@00414828, func_00281EB8@0041484C]; data addresses
   materialised [0x3dcc0000, 0x1c0000, 0x1b0000, 0x800000, 0x3c8e0000,
   0x3da30000, 0x1b0000, 0xff0000, 0xbf190000, 0x3ecc0000, 0x80800000];
   float constants [0x3f800000, 0x40e00000, 0x40800000, 0xc0800000,
   0x3f800000, 0x3f000000]; $gp-relative small data: no   saves: -; callee-
   saved registers saved [-]; words plain C cannot emit [LQ/SQ
   7AC20000@0x027c, LQ/SQ 7FA20000@0x0280, LQ/SQ 7AE20000@0x0288, LQ/SQ
   7C620000@0x028c]. Head: addiu $sp, $sp, -0x160 ; sd $s0, 0x100($sp) ;
   daddu $a0, $sp, $zero ; sd $s1, 0x108($sp) ; daddu $s0, $t1, $zero ; sd
   $s2, 0x110($sp). Not matched in this wave: the 128-bit copy needs an
   `lq`/`sq` pair; plain C reaches it only through a `mode(TI)` local, and
   this cc1 folds the destination offset into the `sq` where retail
   materialises the pointer first. What would unblock it: the exact source
   expression tree, so this cc1 picks the same registers in the same order. */

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
extern void func_L11_0045FFB0(char *);
extern float D_L16_001B199C NOT_SDA;
extern float D_L16_001B1910 __attribute__((sda));
extern float D_L16_001B1914 __attribute__((sda));
extern float D_L16_001B1918 __attribute__((sda));
extern float D_L16_001B191C __attribute__((sda));
extern float D_L16_001B1924 __attribute__((sda));
extern float D_L16_001B1938 __attribute__((sda));
extern float D_L16_001B193C __attribute__((sda));
extern float D_L16_001B19A0 __attribute__((sda));
extern float D_L16_001B19A4 __attribute__((sda));
extern u32 D_L16_001B1920 __attribute__((sda));
extern u32 D_L16_001B1928 __attribute__((sda));
extern u32 D_L16_001B192C __attribute__((sda));
extern u32 D_L16_001B1930 __attribute__((sda));
extern u32 D_L16_001B1934 __attribute__((sda));
extern u32 D_L16_001B1940 __attribute__((sda));
extern u32 D_L16_001B1944 __attribute__((sda));
extern u32 D_L16_001B1950 __attribute__((sda));
extern u32 D_L16_001B1954 __attribute__((sda));
extern u32 D_L16_001B1958 __attribute__((sda));
extern u32 D_L16_001B195C __attribute__((sda));
extern u32 D_L16_001B1960 __attribute__((sda));
extern u32 D_L16_001B1964 __attribute__((sda));
extern u32 D_L16_001B1968 __attribute__((sda));
extern u32 D_L16_001B196C __attribute__((sda));
extern u32 D_L16_001B1970 __attribute__((sda));
extern u32 D_L16_001B1974 __attribute__((sda));
extern u32 D_L16_001B1978 __attribute__((sda));
extern u32 D_L16_001B1980 __attribute__((sda));
extern u32 D_L16_001B1984 __attribute__((sda));
extern u32 D_L16_001B1988 __attribute__((sda));
extern u32 D_L16_001B1990 __attribute__((sda));
extern u32 D_L16_001B1994 __attribute__((sda));
extern u32 D_L16_001B1998 __attribute__((sda));
/* Only the sixth GPR slot is observed: retail copies t1. The first five
   raw slots below are unused; their original semantic types remain unknown. */
void func_L16_00414038(u32 unused0,u32 unused1,u32 unused2,u32 unused3,u32 unused4,u8 *object)
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
    func_L11_0045FFB0((char *)&packet);
    func_00281DE8(&packet,D_L16_001B1940,1,0x80);
    vertex=(float *)packet.pad;
    uv=(float *)(packet.pad+0x50);
    color=(u32 *)(packet.pad+0x40);
    color[0]=color[1]=(D_L16_001B195C<<24)|(D_L16_001B1958<<16)|(D_L16_001B1954<<8)|D_L16_001B1950;
    color[2]=color[3]=(D_L16_001B196C<<24)|(D_L16_001B1968<<16)|(D_L16_001B1964<<8)|D_L16_001B1960;
    uv[0]=0.0f; uv[1]=0.0f; uv[2]=0.0f; uv[3]=1.0f;
    uv[4]=1.0f; uv[5]=0.0f; uv[6]=1.0f; uv[7]=1.0f;
    for (i=0;i<4;i++) {
        uv[i*2]-=*(float *)(state+0x28);
        if (uv[i*2]<=7.0f) uv[i*2]+=7.0f;
    }
    *(float *)(state+0x28)+=0.1f;
    if (*(float *)(state+0x28)>=4.0f) *(float *)(state+0x28)-=4.0f;
    func_00282CF0(camera,object+0x10,D_L16_001B9B00);
    func_00282F20(back,state,-D_L16_001B193C);
    func_00282CC0(rear,object+0x10,back);
    func_00282DD8(side,camera,back);
    func_00282F20(side,side,D_L16_001B191C);
    func_00282F20(center,state,D_L16_001B199C);
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
    *(float *)(state+0x1C)=func_00283B98(*(float *)(state+0x1C),D_L16_001B1938*0.017453294f);
    func_00281DE8(&packet,D_L16_001B1944,1,0x80);
    packet.f70=5;
    color[0]=color[1]=(D_L16_001B192C<<24)|(D_L16_001B1978<<16)|(D_L16_001B1974<<8)|D_L16_001B1970;
    color[2]=color[3]=(D_L16_001B1988<<16)|(D_L16_001B1984<<8)|D_L16_001B1980;
    func_00282F20(side,side,D_L16_001B1910);
    func_00282F20(center,state,D_L16_001B199C);
    func_00282CC0(center,object+0x10,center);
    func_00282CC0(vertex,center,side);
    func_00282CF0(vertex+4,center,side);
    func_00282CC0(rear,center,back);
    func_00282CC0(rear,rear,back);
    func_00282CC0(vertex+8,rear,side);
    func_00282CF0(vertex+12,rear,side);
    func_00280B90(&packet,0,0);
    color[0]=color[1]=(D_L16_001B192C<<24)|(D_L16_001B1978<<16)|(D_L16_001B1974<<8)|D_L16_001B1970;
    color[2]=color[3]=(D_L16_001B1988<<16)|(D_L16_001B1984<<8)|D_L16_001B1980;
    func_00282F20(side,side,D_L16_001B1914);
    func_00282F20(center,state,D_L16_001B19A0);
    func_00282CC0(center,object+0x10,center);
    func_00282CC0(vertex,center,side);
    func_00282CF0(vertex+4,center,side);
    func_00282CC0(rear,center,back);
    func_00282CC0(rear,rear,back);
    func_00282CC0(vertex+8,rear,side);
    func_00282CF0(vertex+12,rear,side);
    func_00280B90(&packet,0,0);
    color[0]=color[1]=(D_L16_001B1934<<24)|(D_L16_001B1978<<16)|(D_L16_001B1974<<8)|D_L16_001B1970;
    color[2]=color[3]=(D_L16_001B1988<<16)|(D_L16_001B1984<<8)|D_L16_001B1980;
    func_00282F20(side,side,D_L16_001B1918);
    func_00282F20(center,state,D_L16_001B19A0);
    func_00282CC0(center,object+0x10,center);
    func_00282CC0(vertex,center,side);
    func_00282CF0(vertex+4,center,side);
    func_00282CC0(rear,center,back);
    func_00282CC0(rear,rear,back);
    func_00282CC0(vertex+8,rear,side);
    func_00282CF0(vertex+12,rear,side);
    func_00280B90(&packet,0,0);
    color[0]=color[1]=(D_L16_001B1930<<24)|0xFFFFFF;
    color[2]=color[3]=(D_L16_001B1988<<16)|(D_L16_001B1984<<8)|D_L16_001B1980;
    func_00282F20(side,side,D_L16_001B1910);
    func_00282F20(center,state,D_L16_001B19A4);
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
    func_00281EB8(object+0x10,D_L16_001B1920,D_L16_001B1928,1,D_L16_001B1924,0.08f,angle);
    size=D_L16_001B1924*0.4f;
    angle=func_002A7940();
    func_00281EB8(object+0x10,D_L16_001B1920,0x80808080U,1,size,0.08f,angle);
}
