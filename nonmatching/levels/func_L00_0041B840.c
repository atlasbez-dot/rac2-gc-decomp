/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 656 / 680 bytes; size equality is not a match.
 * us: 0/27 placements; 656/680 bytes.
 * us2: 0/27 placements; 656/680 bytes.
 * pal: 0/27 placements; 656/680 bytes.
 * Residual: 656/680 bytes. Two records per pool slot, two144-byte packet blocks initialized with actual current helper; true quad copies use TI128. No extra padding or register pins.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Historical screen/map retained privately. The current manual reconstruction and measured residual above supersede that screen; its extracted instruction, opcode and address lists establish neither matching nor handwritten-assembly status. */

/* Wave4 next-family manual reconstruction, 2026-10-23. Nonmatching.
   Historical screening above remains as history.
   Trial source: src/levels/shared/L00_0041B840-g8-qcopy-next.c
   Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
   656/680 bytes. Two records per pool slot, two144-byte packet blocks initialized with actual current helper; true quad copies use TI128. No extra padding or register pins.
   us: func_L00_0041B840: 0 of 27 places match (src/levels/shared/L00_0041B840-g8-qcopy-next.c), exit 1; us2: func_L00_0041B840: 0 of 27 places match (src/levels/shared/L00_0041B840-g8-qcopy-next.c), exit 1; pal: func_L00_0041B840: 0 of 27 places match (src/levels/shared/L00_0041B840-g8-qcopy-next.c), exit 1
*/
#include "common.h"
typedef int Quad128 __attribute__((mode(TI)));
extern char *D_L00_001B1450 __attribute__((sda));
extern void func_L00_0041AF60(char *);
extern float func_002A7878(float,float);
extern int func_001163B0(void);
void func_L00_0041B840(void *unused,float *origin,Quad128 *first,Quad128 *second)
{
    char *record,*view,*matrix;
    float value,*scroll,*velocity;
    int index,part,*phase;
    Quad128 *position;
    for(index=0;index<10;index++) {
        record=(char *)(index*0x530+(int)D_L00_001B1450);
        if(*(int *)(record+0x514)!=0) continue;
        scroll=(float *)(record+0x500); velocity=(float *)(record+0x4f0);
        phase=(int *)(record+0x4e0); position=(Quad128 *)(record+0x20);
        for(part=0;part<2;part++) {
            view=record+part*0x90;
            func_L00_0041AF60(record+part*0x90+0x2a0);
            matrix=record+part*0x90+0x60;
            func_L00_0041AF60(matrix);
            value=func_002A7878(0.3f,0.5f);
            *(float *)(view+0x64)*=value; *(float *)(view+0x74)*=value;
            *(float *)(view+0x84)*=value; *(float *)(view+0x94)*=value;
            value=func_002A7878(0.9f,1.0f);
            *(float *)(view+0x78)*=value; *(float *)(view+0x98)*=value;
            *(float *)(view+0x74)*=0.4f; *(float *)(view+0x94)*=0.4f;
            ((float *)position)[0]=origin[0]+func_002A7878(-0.1f,0.1f);
            ((float *)position)[1]=origin[1]+func_002A7878(-0.1f,0.1f);
            ((float *)position)[2]=origin[2]; ((float *)position)[3]=1.0f;
            *velocity=func_002A7878(-0.02f,-0.01f);
            position++; velocity++;
            *scroll=func_002A7878(-7.99f,0.0f); scroll++;
            *phase=func_001163B0()%2; phase++;
        }
        *(int *)(record+0x51c)=0; *(int *)(record+0x514)=1;
        *(int *)(record+0x510)=0; *(int *)(record+0x518)=0;
        *(Quad128 *)(record+0x10)=*second; *(Quad128 *)record=*first;
        return;
    }
}
