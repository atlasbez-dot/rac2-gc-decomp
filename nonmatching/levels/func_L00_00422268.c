/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections.
 * Reported final C / retail: 600 / 612 bytes; size equality is not a match.
 * us: 0/27 placements; 600/612 bytes.
 * us2: 0/27 placements; 600/612 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: 600/612 bytes. AA548 audited2 GPR/4FP returnsfloat;702C8 uses exact current1GPR/5FP signature. Actual measured fields and pointerreloads retained; named scalar defaults are partial observations, not inferred complete objects.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Historical screen/map retained privately. The current manual reconstruction and measured residual above supersede that screen; its extracted instruction, opcode and address lists establish neither matching nor handwritten-assembly status. */

/* Wave4 next-family manual reconstruction, 2026-10-23. Nonmatching.
   Historical screening above remains as history.
   Trial source: src/levels/shared/L00_00422268-g8-next.c
   Profile: -O2 -G8 -ffunction-sections
   600/612 bytes. AA548 audited2 GPR/4FP returnsfloat;702C8 uses exact current1GPR/5FP signature. Actual measured fields and pointerreloads retained; named scalar defaults are partial observations, not inferred complete objects.
   us: func_L00_00422268: 0 of 27 places match (src/levels/shared/L00_00422268-g8-next.c), exit 1; us2: func_L00_00422268: 0 of 27 places match (src/levels/shared/L00_00422268-g8-next.c), exit 1; pal: absent_from_catalogue, exit 1
*/
#include "common.h"
extern float D_001A8904 __attribute__((nosda));
extern char *D_L00_001BB040 __attribute__((nosda));
extern float D_L00_001B14F8 __attribute__((sda)),D_L00_001B14FC __attribute__((sda));
extern float D_L00_001B14A0 __attribute__((sda)),D_L00_001B14A4 __attribute__((sda));
extern unsigned short D_L00_001B1514 __attribute__((sda));
extern float D_L00_001B14DC __attribute__((sda)),D_L00_001B14D4 __attribute__((sda)),D_L00_001B14D8 __attribute__((sda));
extern int D_L00_001B1854 __attribute__((nosda));
extern float D_L00_001B1510 __attribute__((sda));
extern float func_002702C8(float *,float,float,float,float,float);
extern float func_002AA548(float *,float *,float,float,float,float);
void func_L00_00422268(char *object)
{
    char *state=*(char **)(object+0x70),*motion,*view,*defaults,*defaultView,*recoil,*temporary;
    temporary=state+0x1c0;
    *(float *)(temporary+0x14)=D_001A8904;
    *(int *)(temporary+0x1c)=0; *(int *)(temporary+0x20)=0;
    *(int *)(temporary+0x10)=0; *(int *)(temporary+0x24)=0;
    state=*(char **)(object+0x70);
    motion=state+0x160; view=state+0x60;
    defaultView=D_L00_001BB040+0x60; defaults=D_L00_001BB040+0x160;
    *(float *)(motion+0x2c)=func_002702C8((float *)(state+0x1a4),*(float *)(motion+0x2c),*(short *)(motion+0x3c)?*(float *)(motion+0x40):*(float *)(defaults+0x2c),*(float *)(motion+0x48),D_L00_001B14F8,*(float *)(temporary+0x1c));
    *(float *)(motion+0x30)=func_002702C8((float *)(motion+0x50),*(float *)(motion+0x30),*(short *)(motion+0x3e)?*(float *)(motion+0x4c):*(float *)(defaults+0x30),*(float *)(motion+0x54),D_L00_001B14FC,0.0f);
    *(float *)(view+0xb0)=func_002702C8((float *)(view+0xbc),*(float *)(view+0xb0),*(short *)(view+0xda)?*(float *)(view+0xb4):*(float *)(defaultView+0xb0),*(float *)(view+0xb8),0.2f,0.0f);
    *(short *)(motion+0x3c)=0; *(short *)(motion+0x3e)=0; *(int *)(motion+0x40)=0; *(int *)(motion+0x4c)=0;
    *(float *)(motion+0x58)=*(float *)(defaults+0x2c);
    *(short *)(view+0xda)=0; *(float *)(view+0xb4)=0;
    *(short *)(*(char **)(object+0x70)+0x10)=1;
    state=*(char **)(object+0x70); recoil=state+0x20;
    *(float *)(recoil+0x1c)=0.005f; *(float *)(recoil+0x20)=0.2f; *(short *)(recoil+2)=0;
    if(*(float *)(recoil+0x2c)!=0.0f)
        func_002AA548((float *)(state+0x48),(float *)(state+0x50),*(float *)(recoil+0x2c),*(float *)(recoil+0x34),*(float *)(recoil+0x38),1.0f);
    else if(*(float *)(recoil+0x28)!=0.0f)
        func_002AA548((float *)(state+0x48),(float *)(state+0x50),0.0f,*(float *)(recoil+0x34),*(float *)(recoil+0x38),1.0f);
    *(int *)(recoil+0x2c)=0;
    *(unsigned char *)(view+0xd6)=0;
    *(float *)(view+0xdc)=D_L00_001B14A0; *(float *)(view+0xe4)=D_L00_001B14A4;
    *(float *)(view+0xe8)=0.2f; *(float *)(view+0xe0)=0.2f; *(unsigned short *)(view+0xec)=D_L00_001B1514;
    temporary=*(char **)(object+0x70)+0x1f0;
    *(float *)(temporary+0x3c)=D_L00_001B14DC; *(float *)(temporary+0x44)=D_L00_001B14D4;
    *(float *)(temporary+0x40)=D_L00_001B14D8; *(int *)(temporary+0x48)=D_L00_001B1854; *(short *)(temporary+0x4e)=0;
    temporary=*(char **)(object+0x70)+0x240;
    *(float *)(temporary+0xc)=D_L00_001B1510; *(short *)(temporary+6)=0;
}
