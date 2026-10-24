/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 1004 / 1020 bytes; size equality is not a match.
 * us: 0/27 placements; 1004/1020 bytes.
 * us2: 0/27 placements; 1004/1020 bytes.
 * pal: 0/27 placements; 1004/1020 bytes.
 * Residual: 1004/1020 bytes. Two real144B packets, no false extent. 83D38 audited2GPR/1FP packedcolor result. Actual6GPR/3FP interface retains unused firstFP parameter.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Historical screen/map retained privately. The current manual reconstruction and measured residual above supersede that screen; its extracted instruction, opcode and address lists establish neither matching nor handwritten-assembly status. */

/* Wave4 next-family manual reconstruction, 2026-10-23. Nonmatching.
   Historical screening above remains as history.
   Trial source: src/levels/shared/L00_0041F820-qcopy-next.c
   Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
   1004/1020 bytes. Two real144B packets, no false extent. 83D38 audited2GPR/1FP packedcolor result. Actual6GPR/3FP interface retains unused firstFP parameter.
   us: func_L00_0041F820: 0 of 27 places match (src/levels/shared/L00_0041F820-qcopy-next.c), exit 1; us2: func_L00_0041F820: 0 of 27 places match (src/levels/shared/L00_0041F820-qcopy-next.c), exit 1; pal: func_L00_0041F820: 0 of 27 places match (src/levels/shared/L00_0041F820-qcopy-next.c), exit 1
*/
#include "common.h"
typedef int Quad128 __attribute__((mode(TI)));
typedef struct { u8 pad[0x70]; long f70,f78,f80,f88; } QuadPacket;
typedef struct { Quad128 vertices[4]; unsigned int colors[4]; float uv[4][2]; long header[4]; } RibbonPayload;
typedef union { QuadPacket raw; RibbonPayload view; } RibbonPacket;
extern void func_00281DE8(QuadPacket *,int,int,int);
extern void func_00282CF0(void *,void *,void *);
extern void func_00282DD8(void *,void *,void *);
extern void func_00282F20(void *,void *,float);
extern void func_00282D30(void *,void *,float);
extern void func_00282CC0(void *,void *,void *);
extern float func_00283CE0(int);
extern int func_00283CF0(float);
extern unsigned int func_00283D38(unsigned int,unsigned int,float);
extern void func_00280B90(void *,void *,int);
extern char D_L00_001B8DC0[];
void func_L00_0041F820(Quad128 *points,int firstTexture,int secondTexture,int count,unsigned int firstColor,unsigned int secondColor,float unused,float width,float uv)
{
    RibbonPacket first,second;
    Quad128 side,offset,eye,tangent;
    Quad128 *previous=points,*current=points+1;
    int index,alpha;
    float fade;
    unsigned int firstAlpha=firstColor>>24,secondAlpha=secondColor>>24;
    func_00281DE8(&first.raw,firstTexture,1,128);
    first.view.uv[0][0]=uv; first.view.uv[0][1]=0; first.view.uv[1][0]=uv; first.view.uv[1][1]=1;
    first.view.uv[2][0]=uv+1; first.view.uv[2][1]=0; first.view.uv[3][0]=uv+1; first.view.uv[3][1]=1;
    first.view.colors[0]=firstColor; first.view.colors[1]=firstColor; first.view.colors[2]=firstColor; first.view.colors[3]=firstColor;
    func_00281DE8(&second.raw,secondTexture,1,128);
    second.view.uv[0][0]=uv; second.view.uv[0][1]=0; second.view.uv[1][0]=uv; second.view.uv[1][1]=1;
    second.view.uv[2][0]=uv+1; second.view.uv[2][1]=0; second.view.uv[3][0]=uv+1; second.view.uv[3][1]=1;
    second.view.colors[0]=secondColor; second.view.colors[1]=secondColor; second.view.colors[2]=secondColor; second.view.colors[3]=secondColor;
    func_00282CF0(&eye,points,D_L00_001B8DC0); func_00282CF0(&tangent,current,points); func_00282DD8(&side,&tangent,&eye);
    func_00282F20(&offset,&side,((float *)points)[3]);
    func_00282CC0(&first.view.vertices[0],points,&offset); func_00282CF0(&first.view.vertices[1],points,&offset);
    func_00282D30(&offset,&offset,width);
    func_00282CC0(&second.view.vertices[0],points,&offset); func_00282CF0(&second.view.vertices[1],points,&offset);
    for(index=1;index<count;index++) {
        func_00282CF0(&eye,current,D_L00_001B8DC0); func_00282CF0(&tangent,current,previous); func_00282DD8(&side,&tangent,&eye);
        func_00282F20(&offset,&side,((float *)current)[3]);
        func_00282CC0(&first.view.vertices[2],current,&offset); func_00282CF0(&first.view.vertices[3],current,&offset);
        func_00282D30(&offset,&offset,width);
        func_00282CC0(&second.view.vertices[2],current,&offset); func_00282CF0(&second.view.vertices[3],current,&offset);
        fade=func_00283CE0(index); fade=1.0f-fade/func_00283CE0(count);
        alpha=func_00283CF0(func_00283CE0(firstAlpha)*fade);
        first.view.colors[2]=func_00283D38(0x1010ff,firstColor&0xffffff,fade)|((unsigned int)alpha<<24); first.view.colors[3]=first.view.colors[2];
        alpha=func_00283CF0(func_00283CE0(secondAlpha)*fade);
        second.view.colors[2]=func_00283D38(0x1010ff,secondColor&0xffffff,fade)|((unsigned int)alpha<<24); second.view.colors[3]=second.view.colors[2];
        func_00280B90(&first,0,0); func_00280B90(&second,0,0);
        first.view.vertices[0]=first.view.vertices[2]; first.view.vertices[1]=first.view.vertices[3];
        second.view.vertices[0]=second.view.vertices[2]; second.view.vertices[1]=second.view.vertices[3];
        first.view.colors[0]=first.view.colors[2]; first.view.colors[1]=first.view.colors[3];
        second.view.colors[0]=second.view.colors[2]; second.view.colors[1]=second.view.colors[3];
        previous++; current++;
    }
}
