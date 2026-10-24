/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 572 / 572 bytes; size equality is not a match.
 * us: 0/4 placements.
 * us2: 0/4 placements.
 * pal: 0/4 placements.
 * Residual: 00_aranos_tutorial: instruction at +0x4 differs
 * Reopening condition: A faithful field/lifetime model explaining remaining stack, register or scheduling differences; no arbitrary padding/barriers.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Historical manual summary: The earlier automatic screen is superseded by the current manual reconstruction. Unordered floating comparisons must retain their observed behavior while allocation is investigated. The original map is retained privately; no extracted instruction, opcode, address or generated table is reproduced here. */

/*
 * Nonmatching manual reconstruction; retail size 572 bytes.
 * Final US check: 00_aranos_tutorial: instruction at +0x4 differs.
 * Reproduce at src/levels/shared/L00_00382CE8.c with:
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
extern unsigned char D_001B90C0[];
void func_L00_00382CE8(void *owner)
{
    int i, intensity, mode, component;
    float value;
    if (FIELD(int,D_001B90C0,4)==1) return;
    FIELD(void *,D_001B90C0,0)=owner;
    FIELD(int,D_001B90C0,4)=1;
    for(i=1;i<14;++i) {
        intensity=func_002A77E0(63)+1;
        mode=func_002A77E0(6);
        switch(mode) {
        case 0: FIELD(unsigned int,D_001B90C0,0x50+i*4)=intensity+0x202080-(intensity<<16); break;
        case 1: FIELD(unsigned int,D_001B90C0,0x50+i*4)=intensity+0x202080+(intensity<<8); break;
        case 2: FIELD(unsigned int,D_001B90C0,0x50+i*4)=(func_002A77E0(intensity)<<8)+intensity+0x202080; break;
        case 3:
            component=func_002A77E0(intensity);
            mode=func_002A77E0(intensity);
            FIELD(unsigned int,D_001B90C0,0x50+i*4)=(component<<16)+(mode<<8)+0x202080+intensity; break;
        default: FIELD(unsigned int,D_001B90C0,0x50+i*4)=0x202080; break;
        }
        FIELD(short,D_001B90C0,0x30+i*2)=func_002A77E0(30)/10+1;
        value=func_002A7878(-0.95f,2.4f);
        FIELD(float,D_001B90C0,0x90+i*4)=value;
        value=func_00282C48(func_00283180(func_00283C28(value+1)));
        FIELD(float,D_001B90C0,0xD0+i*4)=value*value*value*1.4f;
        FIELD(short,D_001B90C0,0x10+i*2)=32;
    }
    FIELD(short,D_001B90C0,0x10)=127;
    FIELD(float,D_001B90C0,0x90)=-1;
    FIELD(float,D_001B90C0,0xD0)=2;
    FIELD(unsigned int,D_001B90C0,0x50)=0x808080;
    FIELD(short,D_001B90C0,0x30)=0;
}
