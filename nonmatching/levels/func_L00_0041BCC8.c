/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 832 / 1176 bytes; size equality is not a match.
 * us: 0/27 placements; 832/1176 bytes.
 * us2: 0/27 placements; 832/1176 bytes.
 * pal: 0/27 placements; 832/1176 bytes.
 * Residual: 832/1176 bytes. Four-basis-vector matrix, real packet/header64-bit fields and two banks reconstructed. Pointer spill/source expression tree remains far from retail; no artificial pressure or aliases added.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Historical screen/map retained privately. The current manual reconstruction and measured residual above supersede that screen; its extracted instruction, opcode and address lists establish neither matching nor handwritten-assembly status. */

/* Wave4 next-family manual reconstruction, 2026-10-23. Nonmatching.
   Historical screening above remains as history.
   Trial source: src/levels/shared/L00_0041BCC8-g8-qcopy-next.c
   Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
   832/1176 bytes. Four-basis-vector matrix, real packet/header64-bit fields and two banks reconstructed. Pointer spill/source expression tree remains far from retail; no artificial pressure or aliases added.
   us: func_L00_0041BCC8: 0 of 27 places match (src/levels/shared/L00_0041BCC8-g8-qcopy-next.c), exit 1; us2: func_L00_0041BCC8: 0 of 27 places match (src/levels/shared/L00_0041BCC8-g8-qcopy-next.c), exit 1; pal: func_L00_0041BCC8: 0 of 27 places match (src/levels/shared/L00_0041BCC8-g8-qcopy-next.c), exit 1
*/
#include "common.h"
typedef int Quad128 __attribute__((mode(TI)));
extern char *D_L00_001B1450 __attribute__((sda));
extern char D_L00_001B8DC0[];
extern int func_00283CF0(float);
extern void func_L00_0041C160(void *,float *,float *,int,float);
extern long long func_0027C878(int);
extern void func_00282CF0(void *,void *,void *);
extern void func_002AFFD8(char *,char *,int);
extern void func_00282F20(void *,void *,float);
extern void func_00282DD8(void *,void *,void *);
extern void func_00282D30(void *,void *,float);
extern void func_00280B90(void *,void *,int);
void func_L00_0041BCC8(void *unused)
{
    Quad128 matrix[4],eye,normal;
    char *record,*packet,*source,*position;
    int index,part,alpha;
    unsigned int color;
    float scroll,scale;
    for(index=0;index<10;index++) {
        record=(char *)(index*0x530+(int)D_L00_001B1450);
        if(*(int *)(record+0x514)!=1) continue;
        alpha=64;
        if(*(int *)(record+0x518)==1) { scale=*(float *)(record+0x510)*64.0f; alpha=func_00283CF0(scale+scale); }
        color=(unsigned int)alpha<<24;
        func_L00_0041C160(unused,(float *)(record+0x20),(float *)record,color|0x103080,0.35f);
        func_L00_0041C160(unused,(float *)(record+0x20),(float *)record,color|0xffffff,0.075f);
        for(part=0;part<2;part++) {
            packet=record+0x2a0+part*0x90; source=record+0x60+part*0x90; position=record+0x20+part*16;
            *(long long *)(packet+0x78)=func_0027C878(23);
            *(long long *)(packet+0x80)=0xff9000000260LL;
            *(unsigned int *)(packet+0x40)=color+0x103080; *(long long *)(packet+0x70)=0;
            *(unsigned int *)(packet+0x48)=color+0x103080; *(int *)(packet+0x4c)=0x103080; *(int *)(packet+0x44)=0x103080;
            *(unsigned long *)(packet+0x88)=((long)(part%2+1)<<2)|0x8000000040UL;
            scroll=*(float *)(record+0x500+part*4);
            if(*(int *)(record+0x4e0+part*4)==0) {
                *(float *)(packet+0x54)=1; *(float *)(packet+0x50)=scroll;
                *(float *)(packet+0x5c)=1; *(float *)(packet+0x58)=scroll+1;
                *(float *)(packet+0x64)=0; *(float *)(packet+0x60)=scroll; *(float *)(packet+0x6c)=0;
            } else {
                *(float *)(packet+0x54)=0; *(float *)(packet+0x50)=scroll;
                *(float *)(packet+0x5c)=0; *(float *)(packet+0x58)=scroll+1;
                *(float *)(packet+0x64)=1; *(float *)(packet+0x60)=scroll; *(float *)(packet+0x6c)=1;
            }
            *(float *)(packet+0x68)=scroll+1;
            func_00282CF0(&eye,D_L00_001B8DC0,position); func_002AFFD8(position,(char *)&normal,1);
            func_00282F20(&matrix[0],&eye,1.0f); func_00282DD8(&matrix[1],&matrix[0],&normal);
            func_00282F20(&matrix[1],&matrix[1],1.0f); func_00282DD8(&matrix[2],&matrix[1],&matrix[0]);
            ((float *)&matrix[3])[0]=((float *)position)[0]; ((float *)&matrix[3])[1]=((float *)position)[1]; ((float *)&matrix[3])[2]=((float *)position)[2]; ((float *)&matrix[3])[3]=1;
            if(*(int *)(record+0x518)==1) scale=0.5f; else scale=*(float *)(record+0x510);
            func_00282D30(packet,source,scale); func_00282D30(packet+16,source+16,scale);
            func_00282D30(packet+32,source+32,scale); func_00282D30(packet+48,source+48,scale);
            func_00280B90(packet,matrix,0);
        }
    }
}
