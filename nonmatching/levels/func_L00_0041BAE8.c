/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections.
 * Reported final C / retail: 476 / 476 bytes; size equality is not a match.
 * us: 0/27 placements.
 * us2: 0/27 placements.
 * pal: absent from catalogue (not a match).
 * Residual: 476/476 bytes; earliest remaining US difference+0x94 after correct integer address/index addition. Explicit cached sum, do/while form, existing -g profile did not improve; restored no-g. Loop scheduling and call argument placement remain.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Historical screen/map retained privately. The current manual reconstruction and measured residual above supersede that screen; its extracted instruction, opcode and address lists establish neither matching nor handwritten-assembly status. */

/* Wave4 next-family manual reconstruction, 2026-10-23. Nonmatching.
   Historical screening above remains as history.
   Trial source: src/levels/shared/L00_0041BAE8-g8-next.c
   Profile: -O2 -G8 -ffunction-sections
   476/476 bytes; earliest remaining US difference+0x94 after correct integer address/index addition. Explicit cached sum, do/while form, existing -g profile did not improve; restored no-g. Loop scheduling and call argument placement remain.
   us: func_L00_0041BAE8: 0 of 27 places match (src/levels/shared/L00_0041BAE8-g8-next.c), exit 1; us2: func_L00_0041BAE8: 0 of 27 places match (src/levels/shared/L00_0041BAE8-g8-next.c), exit 1; pal: absent_from_catalogue, exit 1
*/
#include "common.h"
extern char *D_L00_001B1450 __attribute__((sda));
extern void func_00300190(void *,void *);
extern float func_002AA3A8(float *,float *,float,float,float,float);
extern int func_00282948(int *);
void func_L00_0041BAE8(void)
{
    int index,axis;
    char *record,*direction;
    float *position,*velocity,value;
    for(index=0;index<10;index++) {
        record=(char *)(index*0x530+(int)D_L00_001B1450);
        if(*(int *)(record+0x514)!=1) continue;
        velocity=(float *)(record+0x4f0);
        position=(float *)(record+0x500);
        direction=record+0x20;
        axis=1;
        do {
            func_00300190(direction,direction);
            value=*position+*velocity;
            *position=value;
            if(value<=-8.0f) *position=value+8.0f;
            velocity++; position++; axis--; direction+=16;
        } while(axis>=0);
        if(*(int *)(record+0x518)==0) {
            func_002AA3A8((float *)(record+0x510),(float *)(record+0x51c),0.5f,0.002f,0.0002f,0.02f);
            if(*(float *)(record+0x510)==0.5f) {
                *(int *)(record+0x520)=60;
                *(int *)(record+0x518)=2;
            }
        } else if(*(int *)(record+0x518)==1) {
            func_002AA3A8((float *)(record+0x510),(float *)(record+0x51c),0.0f,0.002f,0.0002f,0.02f);
            if(*(float *)(record+0x510)==0.0f) *(int *)(record+0x514)=0;
        } else if(func_00282948((int *)(record+0x520))) *(int *)(record+0x518)=1;
    }
}
