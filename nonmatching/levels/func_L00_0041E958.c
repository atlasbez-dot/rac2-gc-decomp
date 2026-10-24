/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 444 / 476 bytes; size equality is not a match.
 * us: 0/27 placements; 444/476 bytes.
 * us2: 0/27 placements; 444/476 bytes.
 * pal: 0/27 placements; 444/476 bytes.
 * Residual: 444/476 bytes. Callee AF580 audited:8 GPR plus5 FP arguments and actor pointer result; B39F0 computes floatf0; V4 exact current TI128 type. Register/address scheduling unresolved.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Historical screen/map retained privately. The current manual reconstruction and measured residual above supersede that screen; its extracted instruction, opcode and address lists establish neither matching nor handwritten-assembly status. */

/* Wave4 next-family manual reconstruction, 2026-10-23. Nonmatching.
   Historical screening above remains as history.
   Trial source: src/levels/shared/L00_0041E958-qcopy-next.c
   Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
   444/476 bytes. Callee AF580 audited:8 GPR plus5 FP arguments and actor pointer result; B39F0 computes floatf0; V4 exact current TI128 type. Register/address scheduling unresolved.
   us: func_L00_0041E958: 0 of 27 places match (src/levels/shared/L00_0041E958-qcopy-next.c), exit 1; us2: func_L00_0041E958: 0 of 27 places match (src/levels/shared/L00_0041E958-qcopy-next.c), exit 1; pal: func_L00_0041E958: 0 of 27 places match (src/levels/shared/L00_0041E958-qcopy-next.c), exit 1
*/
#include "common.h"
typedef int V4_F6a70b950 __attribute__((mode(TI)));
extern char D_00189E20[];
extern float func_L00_002B39F0(int,float);
extern char *func_002AF580(void *,void *,int *,void *,int,int,int,int,float,float,float,float,float);
extern float func_00283248(float,float);
extern void func_00282CF0(void *,void *,void *);
extern void func_L00_002D3B58(V4_F6a70b950 *,V4_F6a70b950 *,float);
void func_L00_0041E958(float range,float angle,float elevation)
{
    V4_F6a70b950 position;
    float heading;
    char *target,*player=D_00189E20;
    int count;
    if(*(int *)(player+0xbe8)!=0) return;
    heading=*(float *)(player+0x98);
    position=*(V4_F6a70b950 *)player;
    if(*(float *)(player+0x24b8)>0.5f && *(short *)(player+0x1454)==0) {
        target=*(char **)(player+0x1450);
        if(target==0 || *(unsigned char *)(target+0x20)==254 || *(unsigned char *)(target+0x20)==253) {
            func_L00_002B39F0(0,1.0f);
            heading=*(float *)(player+0x1a0);
            position=*(V4_F6a70b950 *)(player+0x190);
            *(int *)(player+0xbe4)=0; *(int *)(player+0xbe8)=1;
        }
    }
    target=*(char **)(player+0x1450);
    if(target==0 || *(unsigned char *)(target+0x20)==254 || *(unsigned char *)(target+0x20)==253)
        target=func_002AF580(player+0x80,&position,&count,0,0,0,1,0,angle,elevation,range,0.0f,0.0f);
    if(target) {
        if(*(int *)(player+0xbe4)==0 || *(int *)(player+0xbe8)!=0) {
            *(float *)(player+0xbec)=func_00283248(*(float *)(target+0x10)-*(float *)(player+0x80),*(float *)(target+0x14)-*(float *)(player+0x84));
            func_00282CF0(player+0xbc0,target+0x10,player+0x80);
            *(char **)(player+0xbe4)=target;
        }
    } else {
        *(float *)(player+0xbec)=heading;
        *(V4_F6a70b950 *)(player+0xbc0)=position;
    }
    func_L00_002D3B58((V4_F6a70b950 *)(player+0xbc0),(V4_F6a70b950 *)(player+0xbc0),0.0f);
}
