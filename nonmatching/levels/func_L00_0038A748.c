/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 544 / 544 bytes; size equality is not a match.
 * us: 0/27 placements.
 * us2: 0/27 placements.
 * pal: absent from catalogue (not a match).
 * Residual: 00_aranos_tutorial: instruction at +0x54 differs
 * Reopening condition: A faithful field/lifetime model explaining remaining stack, register or scheduling differences; no arbitrary padding/barriers.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Historical manual summary: The earlier automatic screen is superseded by the current manual reconstruction. Vector-copy address formation and allocation remain source-level questions. The original map is retained privately; no extracted instruction, opcode, address or generated table is reproduced here. */

/*
 * Nonmatching manual reconstruction; retail size 544 bytes.
 * Final US check: 00_aranos_tutorial: instruction at +0x54 differs.
 * Reproduce at src/levels/shared/L00_0038A748.c with:
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
extern char *D_0018C0B0;
extern int D_L00_001AEFA8 __attribute__((sda));
extern int D_L00_001AEF48 __attribute__((sda));
extern unsigned char D_00139591;
extern unsigned char D_L00_00262570[][224];
char *func_L00_0038A748(void *owner,Vector4 *position,Vector4 *velocity)
{
    Vector4 direction, forward, quaternion, axis;
    Vector4 rotation[3];
    char *object=func_0029EFD0(0x1367),*work;
    float angle;
    int initialState=255;
    if(!object) return 0;
    FIELD(unsigned char,object,0x30)=initialState;
    FIELD(unsigned short,object,0x34)|=0x100;
    work=FIELD(char *,object,0x68);
    FIELD(unsigned short,object,0x32)=initialState; FIELD(unsigned char,object,0x20)=0;
    FIELD(Quadword,object,0x10)=position->bits;
    FIELD(Quadword,work,0)=velocity->bits;
    func_002833F0(object+0xC0,D_0018C0B0+0xF0);
    func_002FE8D8(object+0x10,&direction);
    func_00282F20(&forward,object+0xE0,1);
    func_00282DD8(&axis,&forward,&direction);
    angle=func_00282DB0(&forward,&direction)*0.5f;
    func_00282D30(&quaternion,&axis,func_00283198(angle));
    quaternion.f[3]=func_00283180(angle);
    func_00283958(&quaternion,rotation);
    func_00283738(object+0xC0,rotation,object+0xC0);
    FIELD(int,work,0x64)=0; FIELD(int,work,0x50)=0; FIELD(int,work,0x44)=0;
    FIELD(int,work,0x60)=10;
    FIELD(short,work,0x4C)=1; FIELD(int,work,0x40)=D_L00_001AEFA8;
    func_00282C88(work+0x10);
    FIELD(float,work,0x10)=1;
    FIELD(Quadword,work,0x30)=FIELD(Quadword,work,0x10);
    FIELD(Quadword,work,0x20)=FIELD(Quadword,work,0x10);
    FIELD(float,work,0x58)=0.026179943f;
    FIELD(void *,work,0x68)=owner;
    FIELD(int,work,0x48)=func_002FEC78((unsigned char *)object,0);
    if(FIELD(int,work,0x48)==-1) { func_0029F338(object); return 0; }
    FIELD(unsigned char,work,0x4F)=func_002FED90(object,0,1,1,1);
    FIELD(signed char,work,0x4E)=-1; FIELD(int,work,0x70)=0;
    func_002A0F48(object);
    return object;
}
