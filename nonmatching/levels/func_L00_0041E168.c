/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 856 / 832 bytes; size equality is not a match.
 * us: 0/27 placements; 856/832 bytes.
 * us2: 0/27 placements; 856/832 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: 856/832 bytes. C2210 audited7 GPR plus3 FP, actor pointer result. Five actual quad locals; previous-position copy may be eliminated by compiler. Jitter mutates callerorigin as retail does.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Historical screen/map retained privately. The current manual reconstruction and measured residual above supersede that screen; its extracted instruction, opcode and address lists establish neither matching nor handwritten-assembly status. */

/* Wave4 next-family manual reconstruction, 2026-10-23. Nonmatching.
   Historical screening above remains as history.
   Trial source: src/levels/shared/L00_0041E168-g8-qcopy-next.c
   Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
   856/832 bytes. C2210 audited7 GPR plus3 FP, actor pointer result. Five actual quad locals; previous-position copy may be eliminated by compiler. Jitter mutates callerorigin as retail does.
   us: func_L00_0041E168: 0 of 27 places match (src/levels/shared/L00_0041E168-g8-qcopy-next.c), exit 1; us2: func_L00_0041E168: 0 of 27 places match (src/levels/shared/L00_0041E168-g8-qcopy-next.c), exit 1; pal: absent_from_catalogue, exit 1
*/
#include "common.h"
typedef int Quad128 __attribute__((mode(TI)));
extern char D_L00_001B8DC0[],D_00189ED0[],D_00139568[],D_L00_00262570[];
extern int D_L00_001A8FF0 __attribute__((nosda));
extern float D_L00_001B1488 __attribute__((sda)),D_L00_001B148C __attribute__((sda));
extern float D_L00_001B1474 __attribute__((sda)),D_L00_001B1478 __attribute__((sda));
extern float D_L00_001B147C __attribute__((sda)),D_L00_001B1480 __attribute__((sda)),D_L00_001B1484 __attribute__((sda));
extern void func_00282CF0(void *,void *,void *);
extern void func_00282F20(void *,void *,float);
extern float func_00282DB0(void *,void *);
extern void func_00282D30(void *,void *,float);
extern float func_002A7878(float,float),func_002A78D8(float,float);
extern int func_002A77E0(int),func_00283CF0(float);
extern void func_002ACEC0(void *,void *,void *,float);
extern char *func_002C2210(void *,int,unsigned int,int,int,void *,int,float,float,float);
void func_L00_0041E168(float *origin,int count,int mode)
{
    Quad128 velocity,previous,difference,axis,projection;
    float size,rotation;
    int direction;
    unsigned int color;
    char *particle;
    func_00282CF0(&difference,D_L00_001B8DC0,origin);
    if(D_L00_001A8FF0==0) {
        ((float *)&difference)[2]=0;
        ((float *)&axis)[0]=0; ((float *)&axis)[1]=0; ((float *)&axis)[2]=1; ((float *)&axis)[3]=1;
    } else {
        func_00282CF0(&projection,origin,D_00189ED0);
        func_00282F20(&axis,&projection,1.0f);
        func_00282D30(&projection,&axis,func_00282DB0(&axis,&difference));
        func_00282CF0(&difference,&difference,&projection);
    }
    if(count<=0) return;
    do {
        size=func_002A7878(D_L00_001B1488,D_L00_001B148C);
        direction=func_002A77E0(2); if(direction==0) direction=-1;
        rotation=func_002A7878(-1.0471977f,1.0471977f);
        func_002ACEC0(&velocity,&difference,&axis,rotation);
        func_00282F20(&velocity,&velocity,func_002A7878(D_L00_001B1474,D_L00_001B1478)*0.016666668f);
        ((float *)&velocity)[2]=func_002A7878(D_L00_001B147C,D_L00_001B1480)*0.016666668f;
        previous=*(Quad128 *)origin;
        origin[0]+=func_002A78D8(0.0f,0.15f); origin[1]+=func_002A78D8(0.0f,0.15f); origin[2]+=func_002A78D8(0.0f,0.15f);
        if(*(unsigned char *)(D_L00_00262570+((unsigned char *)D_00139568)[0x16]*224+4)) color=mode?0x802080:0x802020;
        else color=0x202080;
        particle=func_002C2210(origin,60,color|0x7f000000,0,direction,&velocity,1,size*0.1f,size,D_L00_001B1484);
        if(particle) particle[9]=func_00283CF0(4.0f)+112;
        particle=func_002C2210(origin,60,0x7f7f7f7f,1,-direction,&velocity,1,size*0.07f,size*0.7f,D_L00_001B1484);
        if(particle) particle[9]=func_00283CF0(4.0f)+112;
    } while(--count);
}
