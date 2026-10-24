/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 692 / 684 bytes; size equality is not a match.
 * us: 0/27 placements; 692/684 bytes.
 * us2: 0/27 placements; 692/684 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: 692/684 bytes. History shifts use real16-byte vectors;40-entry logical countcap retained.32A088 audited2 GPR resource address result. Actual6GPR/3FP F820 call preserved.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Historical screen/map retained privately. The current manual reconstruction and measured residual above supersede that screen; its extracted instruction, opcode and address lists establish neither matching nor handwritten-assembly status. */

/* Wave4 next-family manual reconstruction, 2026-10-23. Nonmatching.
   Historical screening above remains as history.
   Trial source: src/levels/shared/L00_0041F570-g8-qcopy-next.c
   Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
   692/684 bytes. History shifts use real16-byte vectors;40-entry logical countcap retained.32A088 audited2 GPR resource address result. Actual6GPR/3FP F820 call preserved.
   us: func_L00_0041F570: 0 of 27 places match (src/levels/shared/L00_0041F570-g8-qcopy-next.c), exit 1; us2: func_L00_0041F570: 0 of 27 places match (src/levels/shared/L00_0041F570-g8-qcopy-next.c), exit 1; pal: absent_from_catalogue, exit 1
*/
#include "common.h"
typedef int Quad128 __attribute__((mode(TI)));
extern int func_L00_0032A088(int,int);
extern void func_002FEE50(int);
extern void func_0029F338(void *);
extern void func_00300190(void *,void *);
extern float func_00283CE0(int);
extern int func_00283CF0(float);
extern void func_L00_0041F820(Quad128 *,int,int,int,unsigned int,unsigned int,float,float,float);
extern float D_L00_001B1494 __attribute__((sda));
void func_L00_0041F570(void *self)
{
    char *object=self,*state=*(char **)(object+0x68);
    Quad128 **table,*history,*destination,*source;
    int bank=*(int *)state,index,count,firstCount,alpha=255,glow=64;
    unsigned int color,edge;
    float fraction;
    table=(Quad128 **)func_L00_0032A088(*(int *)(state+0x18),*(int *)(state+0x14));
    if(!table) { func_002FEE50(*(int *)(state+0x34)); func_0029F338(object); return; }
    for(index=0;index<*(int *)(state+0x10);index++) { history=table[bank]+index; func_00300190(history,history); }
    if(*(unsigned char *)(object+0x20)==0) {
        *(int *)(state+0x10)+=1;
        if(*(int *)(state+0x10)>=40) *(int *)(state+0x10)=40;
        count=*(int *)(state+0x10)-1;
        if(count>0) {
            history=table[bank]; destination=history+count; source=history+count-1;
            do { *destination=*source; source--; destination--; } while(--count>0);
        }
        history=table[bank]; *history=*(Quad128 *)(object+0x10); ((float *)history)[3]=0.05f;
    }
    D_L00_001B1494-=0.1f;
    if(D_L00_001B1494<=-7.0f) D_L00_001B1494+=7.0f;
    count=*(int *)(state+0x10); if(count<2) return;
    firstCount=count<20?count:20;
    if(*(unsigned char *)(object+0x20)==1) {
        fraction=func_00283CE0(*(int *)(state+0x38)); fraction/=func_00283CE0(6);
        alpha=func_00283CF0(func_00283CE0(255)*fraction);
        glow=func_00283CF0(func_00283CE0(64)*fraction);
    }
    color=((unsigned int)alpha<<24)|0xffffff; edge=((unsigned int)glow<<24)|0x2020ff;
    func_L00_0041F820(table[bank],23,14,firstCount,color,edge,0.0f,4.0f,D_L00_001B1494);
    if(*(int *)(state+0x10)>20) func_L00_0041F820(table[bank],23,14,*(int *)(state+0x10),color,edge,0.0f,4.0f,D_L00_001B1494);
}
