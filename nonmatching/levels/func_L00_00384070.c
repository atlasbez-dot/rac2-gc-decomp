/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G32 -Wa,-G32 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 468 / 472 bytes; size equality is not a match.
 * us: 0/27 placements; 468/472 bytes.
 * us2: 0/27 placements; 468/472 bytes.
 * pal: 0/27 placements; 468/472 bytes.
 * Residual: 00_aranos_tutorial: 468 bytes, expected 472
 * Reopening condition: A faithful field/lifetime model explaining remaining stack, register or scheduling differences; no arbitrary padding/barriers.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Historical manual summary: An earlier copy-lowering exclusion is superseded by the current manual reconstruction. The original map is retained privately; no extracted instruction, opcode, address or generated table is reproduced here. */

/*
 * Nonmatching manual reconstruction; retail size 472 bytes.
 * Final US check: 00_aranos_tutorial: 468 bytes, expected 472.
 * Reproduce at src/levels/shared/L00_00384070.c with:
 * -O2 -G32 -Wa,-G32 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
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
extern Vector4 D_L00_001AED70[2] __attribute__((sda));
extern Vector4 D_L00_001AED90 __attribute__((sda));
extern float D_L00_001AEDA0[2] __attribute__((sda));
extern int D_L00_001AEDA8[2] __attribute__((sda));
extern Vector4 D_L00_001AED50 __attribute__((sda));
extern char *D_L00_00232A60[24];
int func_L00_00384070(char *owner)
{
    char *work=FIELD(char *,owner,0x68);
    char **slot=(char **)(work+0x48);
    Vector4 *position=(Vector4 *)work,*zero=(Vector4 *)(work+0x20);
    Vector4 *original=D_L00_001AED70;
    float *scale=D_L00_001AEDA0;
    int *animation=D_L00_001AEDA8;
    int i=0,result=0;
    FIELD(int,work,0x68)=func_002A77E0(255);
    do {
        *slot=func_0029EFD0(0xCB2);
        func_002B37E8(*slot,0);
        func_002A7398((signed char *)*slot,1,0);
        FIELD(unsigned short,*slot,0x34)|=0x4002;
        FIELD(unsigned char,*slot,0xBC)=i;
        FIELD(Quadword,*slot,0xF0)=D_L00_001AED90.bits;
        position->bits=original->bits;
        zero->bits=0;
        FIELD(float,*slot,0x2C)=FIELD(float,FIELD(char *,*slot,0x24),0x24)*(*scale);
        func_002AEC18(*slot,*animation);
        ++i;++slot;++position;++zero;++original;++scale;++animation;
    }while(i<2);
    FIELD(float,work,0x74)=0.5f;
    slot=D_L00_00232A60;i=23;
    do {
        *slot=func_0029EFD0(0xE7D);
        if(*slot) {
            func_002B37E8(*slot,0);
            result=func_002A77E0(FIELD(unsigned char,FIELD(char *,FIELD(char *,*slot,0x24),0x50),0x10));
            func_002A7398((signed char *)*slot,2,result);
            FIELD(unsigned short,*slot,0x34)|=0x4002;
            FIELD(Quadword,*slot,0xF0)=D_L00_001AED50.bits;
        }
        --i;++slot;
    }while(i>=0);
    result=0;
    if(FIELD(char *,work,0x48)!=0) {
        result=1;
        if(FIELD(char *,work,0x4C)==0)result=0;
    }
    return result;
}
