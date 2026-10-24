/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 796 / 800 bytes; size equality is not a match.
 * us: 0/27 placements; 796/800 bytes.
 * us2: 0/27 placements; 796/800 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: 796/800 bytes. B4038 canonical int(int,int): secondargument is livea1 ownerstate+12, explicitly passed and returntested. AB1F0 retains canonical int result before addresscast. Specialarc constant corrected to exact0x3eb2b8c4. Register and copy scheduling unresolved.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Historical screen/map retained privately. The current manual reconstruction and measured residual above supersede that screen; its extracted instruction, opcode and address lists establish neither matching nor handwritten-assembly status. */

/* Wave4 next-family manual reconstruction, 2026-10-23. Nonmatching.
   Historical screening above remains as history.
   Trial source: src/levels/shared/L00_0041EB38-g8-qcopy-next.c
   Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
   796/800 bytes. B4038 canonical int(int,int): secondargument is livea1 ownerstate+12, explicitly passed and returntested. AB1F0 retains canonical int result before addresscast. Specialarc constant corrected to exact0x3eb2b8c4. Register and copy scheduling unresolved.
   us: func_L00_0041EB38: 0 of 27 places match (src/levels/shared/L00_0041EB38-g8-qcopy-next.c), exit 1; us2: func_L00_0041EB38: 0 of 27 places match (src/levels/shared/L00_0041EB38-g8-qcopy-next.c), exit 1; pal: absent_from_catalogue, exit 1
*/
#include "common.h"
typedef int Quad128 __attribute__((mode(TI)));
typedef void (*DrawCallback_r002E6EF8)(void *);
extern char *func_0029EFD0(int);
extern void func_00282F20(void *,void *,float);
extern int func_002AB1F0(u8 *);
extern void func_002AFFD8(char *,char *,int);
extern void func_00282D30(void *,void *,float);
extern void func_00282CC0(void *,void *,void *);
extern void func_00282CF0(void *,void *,void *);
extern void func_L00_0037FA90(char *,char *,float,float,float);
extern int func_00283CF0(float);
extern float func_00283CE0(int);
extern int func_002B4038(int,int);
extern void func_0029F338(void *);
extern int func_002FED90(void *,int,float,float,float);
extern void func_L00_002E6EF8(DrawCallback_r002E6EF8,void *);
extern void func_L00_0041F570(void *);
extern void func_002A0F48(void *);
extern char D_L00_00262570[],D_00139568[];
extern short D_0018C30C __attribute__((nosda));
extern int D_0018B320 __attribute__((nosda));
extern Quad128 D_0018A580 __attribute__((nosda)),D_00189EA0 __attribute__((nosda));
extern float D_L00_001B1498 __attribute__((sda)),D_L00_001B1494 __attribute__((sda));
extern unsigned int D_L00_001B1490 __attribute__((sda));
char *func_L00_0041EB38(Quad128 *origin,char *owner,char *target)
{
    Quad128 position,normal;
    char *object,*state,*collision;
    float speed;
    int count,ownerIndex,ownerKind;
    object=func_0029EFD0(0xc89);
    if(!object) return object;
    object[0x30]=255; *(short *)(object+0x34)=0x100; object[0x31]=1; *(short *)(object+0x32)=255;
    *(char **)(object+0xb8)=owner; object[0x20]=0;
    state=*(char **)(object+0x68);
    speed=*(float *)(D_L00_00262570+((unsigned char *)D_00139568)[0x16]*224+0x50)*0.016666668f;
    if(D_0018C30C==1) func_00282F20(state+0x20,owner+0xd0,-speed);
    else if(!target) {
        if(!D_0018B320) func_00282F20(state+0x20,&D_0018A580,speed);
        else func_L00_0037FA90(state+0x20,(char *)origin,speed,30.0f,0.3490658998f);
    } else {
        position=*(Quad128 *)(target+0x10);
        collision=(char *)func_002AB1F0((u8 *)target);
        if(collision) {
            func_002AFFD8(target+0x10,(char *)&normal,1);
            func_00282D30(&normal,&normal,*(float *)(collision+0x10));
            func_00282CC0(&position,&position,&normal);
        }
        func_00282CF0(state+0x20,&position,origin); func_00282F20(state+0x20,state+0x20,speed);
    }
    *(Quad128 *)(object+0x10)=*origin;
    *(float *)(state+0x2c)=speed;
    count=func_00283CF0(30.0f/speed)+1; *(int *)(state+0x38)=count;
    *(float *)(state+0x3c)=1.0f/func_00283CE0(count);
    *(float *)(object+0x2c)=*(float *)(*(char **)(object+0x24)+0x24)*D_L00_001B1498;
    object[0x20]=0; *(char **)(state+0x1c)=target;
    if(target) {
        collision=(char *)func_002AB1F0((u8 *)target);
        if(collision) *(unsigned short *)(collision+0x1e)|=0x80;
    }
    *(float *)(state+0x40)=1;
    ownerIndex=*(short *)(*(char **)(owner+0x68)+0x12); *(int *)(state+0x14)=ownerIndex;
    ownerKind=*(short *)(owner+0xaa); *(int *)(state+0x18)=ownerKind;
    if(!func_002B4038(ownerKind,ownerIndex)) { func_0029F338(object); return 0; }
    *(int *)(state+0x10)=0; D_L00_001B1494=0;
    if(D_L00_001B1490>15) D_L00_001B1490=0;
    *(unsigned int *)state=D_L00_001B1490; D_L00_001B1490++;
    if((int)D_L00_001B1490>15) D_L00_001B1490=0;
    position=*(Quad128 *)(object+0x10); *(Quad128 *)(object+0x10)=D_00189EA0;
    *(int *)(state+0x34)=func_002FED90(object,0,1.0f,1.0f,1.0f);
    *(Quad128 *)(object+0x10)=position;
    func_L00_002E6EF8(func_L00_0041F570,object); func_002A0F48(object);
    return object;
}
