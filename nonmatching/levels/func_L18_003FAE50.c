/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G32 -Wa,-G32 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * -mno-split-addresses.
 * Prior worker coverage: US 0/3; US2 0/3; PAL 0/3.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/* Historical analysis (summary).
 * Historical screening catalogued calls, vector operations and data addressing without a
 * complete manual reconstruction. Its generated call/address lists and decoded instruction
 * header remain private. The dated manual reconstruction and recorded worker profile below
 * supersede that screening; no unsupported impossibility or handwritten classification is
 * carried forward.
 */

/* Wave4 manual reconstruction, 2026-10-23. Nonmatching; historical screening above
   is summarized; generated listings and unsupported classifications remain private.
   Trial source: src/levels/shared/L18_003FAE50-g32-qcopy.c
   Profile: -O2 -G32 -Wa,-G32 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -mno-split-addresses
   Packet preserves exact current144B QuadPacket API; union view contains actual four vertices, colors, UVs and headers. UV table32B and endpoint vectors11 retain observed extents.
   us: func_L18_003FAE50: 0 of 3 places match (src/levels/shared/L18_003FAE50-g32-qcopy.c), exit 1; us2: func_L18_003FAE50: 0 of 3 places match (src/levels/shared/L18_003FAE50-g32-qcopy.c), exit 1; pal: func_L18_003FAE50: 0 of 3 places match (src/levels/shared/L18_003FAE50-g32-qcopy.c), exit 1
*/
#include "common.h"
typedef int Vector128 __attribute__((mode(TI)));
/* Header interface from func_00281DE8; the union names its measured payload. */
typedef struct { unsigned char pad[0x70]; long f70,f78,f80,f88; } QuadPacket;
typedef struct { Vector128 vertices[4]; unsigned int colors[4]; float uv[4][2]; long header[4]; } QuadPayload;
typedef union { QuadPacket raw; QuadPayload view; } BeamPacket;
typedef struct { Vector128 start,next,ray,firstSide,secondSide,step; BeamPacket packet; Vector128 scratch; } BeamWorkspace;
extern Vector128 D_L18_002A08C0[11],D_L18_002A0970[11];
extern char D_L18_001B97C0[];
extern float D_L18_001B0530[4][2] __attribute__((sda));
extern unsigned int D_L18_001B0550 __attribute__((sda)),D_L18_001B0554 __attribute__((sda));
extern float D_L18_001B0558 __attribute__((sda)),D_L18_001B0560 __attribute__((sda)),D_L18_001B0564 __attribute__((nosda));
extern float D_L18_001B0568 __attribute__((sda)),D_L18_001B056C __attribute__((sda)),D_L18_001B0570 __attribute__((sda));
extern void func_00282CF0(void *,void *,void *);
extern void func_00282D30(void *,void *,float);
extern void func_00282CC0(void *,void *,void *);
extern float func_002A7878(float,float);
extern void func_00282DD8(void *,void *,void *);
extern void func_00282F20(void *,void *,float);
extern void func_00281DE8(QuadPacket *,int,int,int);
extern void func_00280B90(void *,void *,int);
void func_L18_003FAE50(char *object)
{
    BeamWorkspace local;
    char *state=*(char **)(object+0x68);
    unsigned int faded,rgb,startColor,endColor;
    float alpha;
    int beam,segment,i;
    for(beam=0;beam<11;beam++) {
        *(Vector128 *)&local.start=D_L18_002A08C0[beam];
        func_00282CF0(&local.step,&D_L18_002A0970[beam],&local.start);
        func_00282D30(&local.step,&local.step,1.0f/D_L18_001B0570);
        func_00282CC0(&local.next,&local.start,&local.step);
        alpha=func_002A7878(D_L18_001B0560,D_L18_001B0564);
        rgb=D_L18_001B0550&0xffffff;
        faded=rgb|((unsigned int)(int)(alpha*(float)(D_L18_001B0550>>24))<<24);
        for(segment=0;(float)segment<D_L18_001B0570;segment++) {
            func_00282CF0(&local.ray,&local.start,&local.next);
            func_00282CF0(&local.firstSide,&local.start,D_L18_001B97C0);
            func_00282CF0(&local.secondSide,&local.next,D_L18_001B97C0);
            func_00282DD8(&local.firstSide,&local.firstSide,&local.ray);
            func_00282DD8(&local.secondSide,&local.secondSide,&local.ray);
            func_00282F20(&local.firstSide,&local.firstSide,D_L18_001B0568);
            func_00282F20(&local.secondSide,&local.secondSide,D_L18_001B0568);
            func_00281DE8(&local.packet.raw,0x17,1,0x80);
            startColor=segment==0?rgb:faded;
            endColor=(segment!=0 && (float)segment==D_L18_001B0570-1.0f)?rgb:faded;
            local.packet.view.colors[1]=startColor;
            local.packet.view.colors[3]=endColor;
            for(i=0;i<4;i++) {
                local.packet.view.uv[i][0]=D_L18_001B0530[i][0]+*(float *)(state+0x8c);
                local.packet.view.uv[i][1]=D_L18_001B0530[i][1];
            }
            local.packet.view.colors[0]=startColor;
            local.packet.view.colors[2]=endColor;
            func_00282CF0(&local.scratch,&local.start,&local.firstSide);
            *(Vector128 *)&local.packet.view.vertices[0]=*(Vector128 *)&local.scratch;
            func_00282CC0(&local.scratch,&local.start,&local.firstSide);
            *(Vector128 *)&local.packet.view.vertices[1]=*(Vector128 *)&local.scratch;
            func_00282CF0(&local.scratch,&local.next,&local.secondSide);
            *(Vector128 *)&local.packet.view.vertices[2]=*(Vector128 *)&local.scratch;
            func_00282CC0(&local.scratch,&local.next,&local.secondSide);
            *(Vector128 *)&local.packet.view.vertices[3]=*(Vector128 *)&local.scratch;
            func_00280B90(&local.packet.raw,0,0);
            func_00282F20(&local.firstSide,&local.firstSide,D_L18_001B056C);
            func_00282F20(&local.secondSide,&local.secondSide,D_L18_001B056C);
            func_00282CF0(&local.scratch,&local.start,&local.firstSide);
            *(Vector128 *)&local.packet.view.vertices[0]=*(Vector128 *)&local.scratch;
            func_00282CC0(&local.scratch,&local.start,&local.firstSide);
            *(Vector128 *)&local.packet.view.vertices[1]=*(Vector128 *)&local.scratch;
            func_00282CF0(&local.scratch,&local.next,&local.secondSide);
            *(Vector128 *)&local.packet.view.vertices[2]=*(Vector128 *)&local.scratch;
            func_00282CC0(&local.scratch,&local.next,&local.secondSide);
            *(Vector128 *)&local.packet.view.vertices[3]=*(Vector128 *)&local.scratch;
            func_00281DE8(&local.packet.raw,0x2b,1,0x80);
            startColor=D_L18_001B0554;
            endColor=D_L18_001B0554;
            if(segment==0) startColor&=0xffffff;
            else if((float)segment==D_L18_001B0570-1.0f) endColor&=0xffffff;
            local.packet.view.colors[1]=startColor;
            local.packet.view.colors[3]=endColor;
            local.packet.view.colors[0]=startColor;
            local.packet.view.colors[2]=endColor;
            func_00280B90(&local.packet.raw,0,0);
            *(Vector128 *)&local.start=*(Vector128 *)&local.next;
            func_00282CC0(&local.next,&local.next,&local.step);
        }
    }
    *(float *)(state+0x8c)+=D_L18_001B0558;
    if(*(float *)(state+0x8c)>1.0f) *(float *)(state+0x8c)-=2.0f;
    if(*(float *)(state+0x8c)<-1.0f) *(float *)(state+0x8c)+=2.0f;
}
