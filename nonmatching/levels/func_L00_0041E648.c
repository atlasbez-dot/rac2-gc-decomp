/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 776 / 784 bytes; size equality is not a match.
 * us: 0/27 placements; 776/784 bytes.
 * us2: 0/27 placements; 776/784 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: 776/784 bytes. Preserves exact current144B QuadPacket API and natural payloadunion, real4 vertices/colors/UVpairs. FC560 parameter widths copied from current32/64-bit typedefs.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Historical screen/map retained privately. The current manual reconstruction and measured residual above supersede that screen; its extracted instruction, opcode and address lists establish neither matching nor handwritten-assembly status. */

/* Wave4 next-family manual reconstruction, 2026-10-23. Nonmatching.
   Historical screening above remains as history.
   Trial source: src/levels/shared/L00_0041E648-g8-qcopy-next.c
   Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
   776/784 bytes. Preserves exact current144B QuadPacket API and natural payloadunion, real4 vertices/colors/UVpairs. FC560 parameter widths copied from current32/64-bit typedefs.
   us: func_L00_0041E648: 0 of 27 places match (src/levels/shared/L00_0041E648-g8-qcopy-next.c), exit 1; us2: func_L00_0041E648: 0 of 27 places match (src/levels/shared/L00_0041E648-g8-qcopy-next.c), exit 1; pal: absent_from_catalogue, exit 1
*/
#include "common.h"
typedef int Quad128 __attribute__((mode(TI)));
typedef struct { u8 pad[0x70]; long f70,f78,f80,f88; } QuadPacket;
typedef struct { Quad128 vertices[4]; unsigned int colors[4]; float uv[4][2]; long header[4]; } StripPayload;
typedef union { QuadPacket raw; StripPayload view; } StripPacket;
typedef unsigned int Rac2Native_9da4b6b15b3cf4a0_RecordWord180;
typedef unsigned long long Rac2Native_9da4b6b15b3cf4a0_RecordValue180;
extern int func_L00_0032A088(int,int);
extern void func_002FEE50(int);
extern void func_0029F338(void *);
extern void func_002FC560(Rac2Native_9da4b6b15b3cf4a0_RecordWord180,Rac2Native_9da4b6b15b3cf4a0_RecordValue180);
extern void func_00281DE8(QuadPacket *,int,int,int);
extern float func_00283CE0(int);
extern int func_00283CF0(float);
extern void func_00282CF0(void *,void *,void *);
extern void func_00282DD8(void *,void *,void *);
extern void func_00282F20(void *,void *,float);
extern void func_00282CC0(void *,void *,void *);
extern void func_00280B90(void *,void *,int);
void func_L00_0041E648(void *self,int color,int alpha)
{
    StripPacket packet;
    Quad128 direction,side;
    char *object=self,*state=*(char **)(object+0x68);
    Quad128 **table;
    int index;
    float fraction,uvStep,width;
    table=(Quad128 **)func_L00_0032A088(*(int *)(state+0x50),*(int *)(state+0x3c));
    if(!table) { func_002FEE50(*(int *)(state+0x6c)); func_0029F338(object); return; }
    if(*(int *)(state+0x54)<3) return;
    func_002FC560(0x47,0x5360bULL);
    func_00281DE8(&packet.raw,11,1,128);
    packet.view.uv[0][0]=0; packet.view.uv[0][1]=0;
    packet.view.uv[1][0]=0; packet.view.uv[1][1]=1;
    packet.view.uv[2][0]=0.5f; packet.view.uv[2][1]=0;
    packet.view.uv[3][0]=0.5f; packet.view.uv[3][1]=1;
    if(*(short *)(state+0x10)>280) {
        fraction=func_00283CE0(300-*(short *)(state+0x10)); fraction/=func_00283CE0(20);
        alpha=func_00283CF0(func_00283CE0(alpha)*fraction);
    }
    color|=(unsigned int)alpha<<24;
    packet.view.colors[0]=color; packet.view.colors[3]=color; packet.view.colors[2]=color; packet.view.colors[1]=color;
    width=*(int *)(state+0x68)?0.5f:0.25f;
    func_00282CF0(&direction,object+0x10,table[*(int *)(state+0x30)]);
    func_00282DD8(&side,&direction,object+0xe0); func_00282F20(&side,&side,width);
    func_00282CC0(&packet.view.vertices[0],object+0x10,&side); func_00282CF0(&packet.view.vertices[1],object+0x10,&side);
    uvStep=0.5f/func_00283CE0(*(int *)(state+0x54)-2);
    for(index=0;index<*(int *)(state+0x54);index++) {
        if(index>0) func_00282CF0(&direction,table[*(int *)(state+0x30)]+index-1,table[*(int *)(state+0x30)]+index);
        func_00282DD8(&side,&direction,object+0xe0); func_00282F20(&side,&side,width);
        func_00282CC0(&packet.view.vertices[2],table[*(int *)(state+0x30)]+index,&side);
        func_00282CF0(&packet.view.vertices[3],table[*(int *)(state+0x30)]+index,&side);
        func_00280B90(&packet,0,0);
        packet.view.vertices[0]=packet.view.vertices[2]; packet.view.vertices[1]=packet.view.vertices[3];
        packet.view.uv[0][0]=packet.view.uv[2][0]; packet.view.uv[1][0]=packet.view.uv[3][0];
        packet.view.uv[2][0]+=uvStep; packet.view.uv[3][0]+=uvStep;
    }
}
