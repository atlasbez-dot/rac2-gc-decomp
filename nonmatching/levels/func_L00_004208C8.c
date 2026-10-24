/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 688 / 720 bytes; size equality is not a match.
 * us: 0/27 placements; 688/720 bytes.
 * us2: 0/27 placements; 688/720 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: 688/720 bytes. Moving support height correction, observed camera/statevectors and secondary correction retained. Partial object views do not infer full storage size.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Historical screen/map retained privately. The current manual reconstruction and measured residual above supersede that screen; its extracted instruction, opcode and address lists establish neither matching nor handwritten-assembly status. */

/* Wave4 next-family manual reconstruction, 2026-10-23. Nonmatching.
   Historical screening above remains as history.
   Trial source: src/levels/shared/L00_004208C8-qcopy-next.c
   Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
   688/720 bytes. Moving support height correction, observed camera/statevectors and secondary correction retained. Partial object views do not infer full storage size.
   us: func_L00_004208C8: 0 of 27 places match (src/levels/shared/L00_004208C8-qcopy-next.c), exit 1; us2: func_L00_004208C8: 0 of 27 places match (src/levels/shared/L00_004208C8-qcopy-next.c), exit 1; pal: absent_from_catalogue, exit 1
*/
#include "common.h"
typedef int Quad128 __attribute__((mode(TI)));
extern char D_00189E20[];
extern int D_L00_001A8FF0 __attribute__((nosda));
extern char D_L00_001B8E20[];
extern int D_L00_001B9084 __attribute__((nosda));
extern void func_00282CC0(void *,void *,void *);
extern void func_00282CF0(void *,void *,void *);
extern void func_00282D30(void *,void *,float);
extern float func_00282DB0(void *,void *);
void func_L00_004208C8(char *object,Quad128 *input)
{
    Quad128 delta=*input,projected,correction,remainder;
    char *player=D_00189E20,*state=*(char **)(object+0x70),*view=state+0x60;
    char *support=*(char **)(player+0x33c);
    float height;
    if(support && D_L00_001A8FF0==0 && *(short *)(player+0x348)==0) {
        if(support==*(char **)(view+0xf8)) {
            height=*(float *)(support+0x18)-*(float *)(view+0xfc);
            if(height>0.0f && ((float *)&delta)[2]<height) ((float *)&delta)[2]=height;
            *(float *)(view+0xfc)=*(float *)(*(char **)(player+0x33c)+0x18);
        } else {
            *(char **)(view+0xf8)=support;
            *(float *)(view+0xfc)=*(float *)(*(char **)(player+0x33c)+0x18);
        }
    } else *(int *)(view+0xf8)=0;
    func_00282CC0(object+0x30,&delta,object+0x30);
    func_00282CC0(view+0x60,&delta,view+0x60);
    func_00282CC0(view,&delta,view);
    func_00282CC0(view+0x90,&delta,view+0x90);
    func_00282CC0(view+0x30,&delta,view+0x30);
    func_00282CC0(state,&delta,state);
    func_00282D30(&projected,D_L00_001B8E20+0x30,func_00282DB0(&delta,D_L00_001B8E20+0x30));
    func_00282CC0(view+0x10,view+0x10,&projected);
    if(*(short *)(player+0x348)==0 && *(char **)(player+0x33c)!=0 && *(short *)(*(char **)(player+0x33c)+0xaa)==0x22d && D_L00_001B9084>=31)
        *(float *)(*(char **)(object+0x70)+0x1e0)=((float *)&delta)[3];
    if((unsigned int)(*(int *)(player+0x2294)-11)<2) {
        state=*(char **)(object+0x70); *(short *)(state+0x10)=0;
        func_00282D30(&correction,D_L00_001B8E20+0x80,*(float *)(D_L00_001B8E20+0xa4));
        func_00282D30(&remainder,D_L00_001B8E20+0x30,func_00282DB0(D_L00_001B8E20+0x30,&delta));
        func_00282CF0(&remainder,&delta,&remainder);
        func_00282CF0(&correction,&correction,&remainder);
        func_00282CC0(object+0x30,&correction,object+0x30);
        func_00282CC0(view+0x60,&correction,view+0x60);
        func_00282CC0(view,&correction,view);
        func_00282CC0(view+0x90,&correction,view+0x90);
        func_00282CC0(state,&correction,state);
    }
}
