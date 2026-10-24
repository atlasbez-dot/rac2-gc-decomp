/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 696 / 720 bytes; size equality is not a match.
 * us: 0/27 placements; 696/720 bytes.
 * us2: 0/27 placements; 696/720 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: 00_aranos_tutorial: 696 bytes, expected 720
 * Reopening condition: A faithful field/lifetime model explaining remaining stack, register or scheduling differences; no arbitrary padding/barriers.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Historical manual summary: The earlier automatic screen is superseded by the current manual reconstruction. Floating comparisons and state-path lifetimes remain source-level questions. The original map is retained privately; no extracted instruction, opcode, address or generated table is reproduced here. */

/*
 * Nonmatching manual reconstruction; retail size 720 bytes.
 * Final US check: 00_aranos_tutorial: 696 bytes, expected 720.
 * Reproduce at src/levels/shared/L00_00385370.c with:
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
extern void func_002830C0(void *,void *,void *);
extern int func_002A7820(int,int);
extern unsigned long func_0027C878(int);
extern void func_00280B90(void *,void *,int);
extern void func_L00_003883B8(char *);
extern void func_L00_0038AA40(char *);
extern void func_L00_00388490(void *,Vector4 *);
extern void func_L00_0038AAD0(void *,Vector4 *);
extern void func_0029FCC0(char *,int,char *);
extern int func_001163B0(void);
extern int func_00282948(int *);
extern float func_00283CE0(int);
extern int func_00283CF0(float);
extern float func_00282E48(void *,void *);
extern void func_00303210(void *);
extern void func_00303BF8(void *);
extern void func_00303AC8(void *);
extern void func_00302DA0(void *);
extern void func_00304128(void *);
extern void func_00303070(void *);
extern void func_L00_002E6DB8(void (*)(void *),void *);
extern void func_002A7750(unsigned char *,unsigned char,int);
extern int func_002B3868(unsigned char *);
extern float func_002AA548(float *,float *,float,float,float,float);
extern unsigned char D_L00_00232AC0[][32];
void func_L00_00385370(unsigned char *object)
{
    char *work=FIELD(char *,object,0x68);
    int i,ticks;
    switch(object[0x20]) {
    case 0:
        if(FIELD(int,work,0x1C)<=0)FIELD(int,work,0x1C)=20;
        ticks=FIELD(int,work,0x1C);
        FIELD(int,work,4)=0;
        FIELD(float,work,0x14)=(FIELD(float,work,0x18)+FIELD(float,work,0x18))/(float)ticks;
        FIELD(float,work,0)=FIELD(float,work,0x18)*4/(float)(ticks*ticks);
        func_00303210(object);
        FIELD(float,work,0x30)=1/FIELD(float,work,0x30);
        FIELD(int,work,0x8C)=FIELD(int,work,0x84);FIELD(int,work,0x98)=-1;
        if(!FIELD(int,work,0x40)) {
            object[0x30]=255;
            for(i=0;i<64;++i) {
                FIELD(float,D_L00_00232AC0[i],8)=func_002A7878(0.5f,2);
                FIELD(float,D_L00_00232AC0[i],12)=func_002A7878(0.002f,0.006f);
            }
        }
        func_002A7750(object,1,-1);return;
    case 1:
        if(func_002B3868(object)){FIELD(int,work,8)=0;FIELD(int,work,0x20)=FIELD(int,work,0x1C);}
        if(func_00282948((int *)(work+0x20)))func_002A7750(object,2,-1);
        func_002AA548((float *)(work+4),(float *)(work+8),FIELD(float,work,0x18),FIELD(float,work,0),FIELD(float,work,0),FIELD(float,work,0x14));
        break;
    case 2:
        if(func_002B3868(object)){FIELD(int,work,0x20)=FIELD(int,work,12);FIELD(float,work,4)=FIELD(float,work,0x18);}
        if(func_00282948((int *)(work+0x20)))func_002A7750(object,3,-1);
        break;
    case 3:
        if(func_002B3868(object)){FIELD(int,work,8)=0;FIELD(int,work,0x20)=FIELD(int,work,0x1C);}
        if(func_00282948((int *)(work+0x20)))func_002A7750(object,4,-1);
        func_002AA548((float *)(work+4),(float *)(work+8),0,FIELD(float,work,0),FIELD(float,work,0),FIELD(float,work,0x14));
        break;
    case 4:
        if(func_002B3868(object)){FIELD(int,work,4)=0;FIELD(int,work,0x20)=FIELD(int,work,16);}
        if(func_00282948((int *)(work+0x20)))func_002A7750(object,1,-1);
        break;
    case 5:break;
    default:return;
    }
    if(!FIELD(int,work,0x40))func_00303BF8(object);
    func_00303AC8(object);func_00302DA0(object);func_00304128(object);
    func_L00_002E6DB8(func_00303070,object);
}
