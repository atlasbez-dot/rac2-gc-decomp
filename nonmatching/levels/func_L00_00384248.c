/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 992 / 1072 bytes; size equality is not a match.
 * us: 0/27 placements; 992/1072 bytes.
 * us2: 0/27 placements; 992/1072 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: 00_aranos_tutorial: 992 bytes, expected 1072
 * Reopening condition: A faithful field/lifetime model explaining remaining stack, register or scheduling differences; no arbitrary padding/barriers.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Historical manual summary: The earlier automatic screen is superseded by the current manual reconstruction. Vector-copy address formation and store scheduling remain source-level questions. The original map is retained privately; no extracted instruction, opcode, address or generated table is reproduced here. */

/*
 * Nonmatching manual reconstruction; retail size 1072 bytes.
 * Final US check: 00_aranos_tutorial: 992 bytes, expected 1072.
 * Reproduce at src/levels/shared/L00_00384248.c with:
 * -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * Full body retained after bounded source/API/layout trials; no matching bytes
 * are claimed. Reopen when a truthful field or lifetime model explains the
 * remaining stack, register and scheduling differences.
 * US/US2/PAL coverage and catalogue absence are recorded in the private result.
 */
#include "common.h"
typedef int Quadword __attribute__((mode(TI)));
typedef union { Quadword bits; float f[4]; } Vector4;
#define FIELD(type,p,off) (*(type *)((char *)(p)+(off)))
extern void func_00282CF0(void *,void *,void *);
extern void func_00282CC0(void *,void *,void *);
extern void func_00282D30(void *,void *,float);
extern float func_00282DB0(void *,void *);
extern float func_00282DF0(void *);
extern float func_00282C48(float);
extern float func_00283C80(float,float);
extern float func_00283C28(float);
extern float func_00283180(float);
extern float func_002A7878(float,float);
extern float func_002A78D8(float,float);
extern float func_002A7940(void);
extern int func_002A77E0(int);
extern void func_002AF000(float *,float,float,float);
extern char *func_002C2210(void *,int,unsigned int,int,int,void *,int,float,float,float);
extern char *func_0029EFD0(int);
extern void func_002B37E8(void *,void *);
extern void func_002A7398(signed char *,int,int);
extern void func_002AEC18(void *,int);
extern void func_002833F0(void *,void *);
extern void func_002FE8D8(void *,void *);
extern void func_00282F20(void *,void *,float);
extern void func_00282DD8(void *,void *,void *);
extern float func_00283198(float);
extern void func_00283958(void *,void *);
extern void func_00283738(void *,void *,void *);
extern void func_00282C88(void *);
extern int func_002FEC78(unsigned char *,unsigned int);
extern int func_002FED90(void *,void *,float,float,float);
extern void func_0029F338(void *);
extern void func_002A0F48(void *);
extern void func_00283098(void *,void *,void *);
extern void func_002A05A8(char *);
extern float func_002AA2E8(float *,float,float);
extern int func_00282948(int *);
extern float func_00283CE0(int);
extern int func_00283CF0(float);
extern void *func_L00_00384CA8(void *,void *,void *,unsigned int);
extern int func_002E5CF8(int,int,char *);
/* The transform helper consumes three complete vector columns. */
extern Vector4 D_001B8FF0[3];
extern Vector4 D_001B8DC0;
extern float D_L00_001AEDA0[2] __attribute__((sda));
extern int D_L00_001AEDA8[2] __attribute__((sda));
extern float D_L00_001AEDB0 __attribute__((sda));
extern float D_L00_001AEDB4 __attribute__((sda));
extern float D_L00_001AEDBC __attribute__((sda));
extern int D_L00_001AEDD0[2] __attribute__((sda));
extern Vector4 D_L00_001AEDC0 __attribute__((sda));
extern unsigned char D_00138500[],D_00138180[];
extern int D_001B19C8;
void func_L00_00384248(char *owner)
{
    char *work=FIELD(char *,owner,0x68),*object,*control;
    Vector4 position,velocity;
    float scale,step,input,target,phase;
    int i,alpha;
    for(i=0;i<2;++i) {
        object=FIELD(char *,work,0x48+i*4);
        func_00283098(object+0x10,work+i*16,D_001B8FF0);
        object=FIELD(char *,work,0x48+i*4);
        func_00282CC0(object+0x10,object+0x10,&D_001B8DC0);
        object=FIELD(char *,work,0x48+i*4);
        FIELD(float,object,0x2C)=FIELD(float,FIELD(char *,object,0x24),0x24)*D_L00_001AEDA0[i];
        func_002AEC18(FIELD(char *,work,0x48+i*4),D_L00_001AEDA8[i]);
        func_002A05A8(FIELD(char *,work,0x48+i*4));
        func_002A0F48(FIELD(char *,work,0x48+i*4));
    }
    scale=D_L00_001AEDB0*0.016666668f;
    step=D_L00_001AEDBC*0.00027777778f;
    for(i=0;i<2;++i) {
        control=i?D_00138180:D_00138500;
        input=FIELD(float,control,0x10C);
        if(input==0)input=FIELD(float,control,0x11C)-FIELD(float,control,0x118);
        target=-input*scale;
        if(target!=0)func_002AA2E8((float *)(work+0x28+i*16),target,step);
        else func_002AA2E8((float *)(work+0x28+i*16),0,step+step);
        FIELD(float,work,8+i*16)+=FIELD(float,work,0x28+i*16);
        if(FIELD(float,work,8+i*16)>0.35f) {
            FIELD(float,work,8+i*16)=0.35f;
            if(FIELD(float,work,0x28+i*16)>0)FIELD(float,work,0x28+i*16)=0;
        }else if(FIELD(float,work,8+i*16)<-0.45f) {
            FIELD(float,work,8+i*16)=-0.45f;
            if(FIELD(float,work,0x28+i*16)<0)FIELD(float,work,0x28+i*16)=0;
        }
        if(func_00282948(&D_L00_001AEDD0[i]))FIELD(unsigned char,FIELD(char *,work,0x48+i*4),0x23)=128;
        else {
            phase=func_00283CE0(D_001B19C8%60);
            phase=(phase*6.2831855f)/func_00283CE0(60);
            alpha=func_00283CF0(func_00283198(phase-3.1415927f)*10)+20;
            FIELD(unsigned char,FIELD(char *,work,0x48+i*4),0x23)=alpha;
        }
        if(func_00282948((int *)(work+0x40+i*4)) &&
           FIELD(unsigned char,FIELD(char *,work,0x48+i*4),0x23)==128 && (FIELD(int,control,0x1A0)&0xE0)) {
            FIELD(int,work,0x40+i*4)=45;
            position.bits=D_L00_001AEDC0.bits;
            if(!i)position.f[1]-=0.05f;
            object=FIELD(char *,work,0x48+i*4);
            func_00283098(&position,&position,object+0xC0);
            func_00282CC0(&position,&position,FIELD(char *,work,0x48+i*4)+0x10);
            func_00282F20(&velocity,FIELD(char *,work,0x48+i*4)+0xC0,D_L00_001AEDB4*0.016666668f);
            func_L00_00384CA8(FIELD(char *,work,0x48+i*4),&position,&velocity,i);
            func_002E5CF8(0,0,FIELD(char *,work,0x48+i*4));
        }
    }
}
