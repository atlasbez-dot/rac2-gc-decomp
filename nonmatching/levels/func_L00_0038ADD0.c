/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 1068 / 1068 bytes; size equality is not a match.
 * us: 0/27 placements.
 * us2: 0/27 placements.
 * pal: 0/27 placements.
 * Residual: 00_aranos_tutorial: instruction at +0x8 differs
 * Reopening condition: A faithful field/lifetime model explaining remaining stack, register or scheduling differences; no arbitrary padding/barriers.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Historical manual summary: The old claim that an MMI instruction alone prevented C is superseded by the manual draft. Opcode presence alone does not justify handwritten-assembly classification. The original map is retained privately; no extracted instruction, opcode, address or generated table is reproduced here. */

/*
 * Nonmatching manual reconstruction; retail size 1068 bytes.
 * Final US check: 00_aranos_tutorial: instruction at +0x8 differs.
 * Reproduce at src/levels/shared/L00_0038ADD0.c with:
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
extern Vector4 D_001B8DC0;
void func_L00_0038ADD0(char *object)
{
    union { Quadword alignment; unsigned char b[144]; } first,second;
    Vector4 basis[4],start,end,origin,nearSize,farSize;
    char *work=FIELD(char *,object,0x68);
    unsigned int baseColor=0x103080;
    float width;
    func_0029FCC0(object,1,(char *)&origin);
    start.bits=origin.bits;
    func_00282F20(&end,work+0x30,func_002A7878(2,4));
    func_00283098(&end,&end,object+0xC0);
    func_00282CC0(&end,&end,&origin);
    func_L00_0038AAD0(object,&start);
    FIELD(unsigned long,first.b,0x78)=func_0027C878(23);
    FIELD(unsigned long,first.b,0x80)=0xFF9000000260UL;
    FIELD(unsigned long,first.b,0x70)=0;
    FIELD(unsigned long,first.b,0x88)=0x8000000048UL;
    FIELD(unsigned int,first.b,0x40)=baseColor+0x7F000000; FIELD(unsigned int,first.b,0x44)=baseColor+0x7F000000;
    FIELD(unsigned int,first.b,0x48)=baseColor; FIELD(unsigned int,first.b,0x4C)=baseColor;
    FIELD(unsigned long,second.b,0x78)=func_0027C878(23);
    nearSize.bits=0;farSize.bits=0;nearSize.f[3]=1;farSize.f[3]=1;
    FIELD(unsigned long,second.b,0x80)=0xFF9000000260UL;
    FIELD(unsigned long,second.b,0x88)=0x8000000048UL;
    FIELD(unsigned long,second.b,0x70)=0;
    FIELD(unsigned int,second.b,0x40)=baseColor+0x3F000000; FIELD(unsigned int,second.b,0x44)=baseColor+0x3F000000;
    FIELD(unsigned int,second.b,0x48)=baseColor; FIELD(unsigned int,second.b,0x4C)=baseColor;
    width=func_002A7878(0.1f,0.3f);nearSize.f[2]=width;farSize.f[2]=width+width;
    func_L00_0038AA40((char *)first.b);func_L00_0038AA40((char *)second.b);
    if(!(func_001163B0()&1)) {
        FIELD(float,first.b,0x50)=0;FIELD(float,first.b,0x54)=0;FIELD(float,first.b,0x58)=0;FIELD(float,first.b,0x5C)=1;
        FIELD(float,first.b,0x60)=1;FIELD(float,first.b,0x64)=0;FIELD(float,first.b,0x68)=1;FIELD(float,first.b,0x6C)=1;
        FIELD(float,second.b,0x50)=0;FIELD(float,second.b,0x54)=0;FIELD(float,second.b,0x58)=0;FIELD(float,second.b,0x5C)=1;
        FIELD(float,second.b,0x60)=1;FIELD(float,second.b,0x64)=0;FIELD(float,second.b,0x68)=1;FIELD(float,second.b,0x6C)=1;
    } else {
        FIELD(float,first.b,0x50)=0;FIELD(float,first.b,0x54)=1;FIELD(float,first.b,0x58)=0;FIELD(float,first.b,0x5C)=0;
        FIELD(float,first.b,0x60)=1;FIELD(float,first.b,0x64)=1;FIELD(float,first.b,0x68)=1;FIELD(float,first.b,0x6C)=0;
        FIELD(float,second.b,0x50)=0;FIELD(float,second.b,0x54)=1;FIELD(float,second.b,0x58)=0;FIELD(float,second.b,0x5C)=0;
        FIELD(float,second.b,0x60)=1;FIELD(float,second.b,0x64)=1;FIELD(float,second.b,0x68)=1;FIELD(float,second.b,0x6C)=0;
    }
    func_00282CF0(&basis[0],&end,&start);func_00282F20(&basis[0],&basis[0],1);
    func_00282CF0(&basis[1],&D_001B8DC0,&start);func_00282DD8(&basis[2],&basis[1],&basis[0]);
    func_00282F20(&basis[2],&basis[2],1);func_00282DD8(&basis[1],&basis[0],&basis[2]);
    basis[3].bits=start.bits;
    FIELD(Quadword,first.b,0)=nearSize.bits;FIELD(Quadword,second.b,0)=farSize.bits;
    func_00282D30(first.b+16,first.b,-1);func_00282D30(second.b+16,second.b,-1);
    func_002830C0(first.b,first.b,basis);func_002830C0(first.b+16,first.b+16,basis);
    func_002830C0(second.b,second.b,basis);func_002830C0(second.b+16,second.b+16,basis);
    basis[3].bits=end.bits; nearSize.f[2]*=0.15f;farSize.f[2]=nearSize.f[2]+nearSize.f[2];
    FIELD(Quadword,first.b,32)=nearSize.bits;FIELD(Quadword,second.b,32)=farSize.bits;
    func_00282D30(first.b+48,first.b+32,-1);func_00282D30(second.b+48,second.b+32,-1);
    func_002830C0(first.b+32,first.b+32,basis);func_002830C0(first.b+48,first.b+48,basis);
    func_002830C0(second.b+32,second.b+32,basis);func_002830C0(second.b+48,second.b+48,basis);
    func_00280B90(first.b,0,0);func_00280B90(second.b,0,0);
}
