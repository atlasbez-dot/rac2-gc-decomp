/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 488 / 504 bytes; size equality is not a match.
 * us: 0/27 placements; 488/504 bytes.
 * us2: 0/27 placements; 488/504 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: 00_aranos_tutorial: 488 bytes, expected 504
 * Reopening condition: A faithful field/lifetime model explaining remaining stack, register or scheduling differences; no arbitrary padding/barriers.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Historical manual summary: The earlier automatic screen is superseded by the current manual reconstruction. Copy-address lifetime and scheduling require source-level evidence; the old screen gives no matching or handwritten-assembly credit. The original map is retained privately; no extracted instruction, opcode, address or generated table is reproduced here. */

/*
 * Nonmatching manual reconstruction; retail size 504 bytes.
 * Final US check: 00_aranos_tutorial: 488 bytes, expected 504.
 * Reproduce at src/levels/shared/L00_0038B888.c with:
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
void func_L00_0038B888(Vector4 *position,int count)
{
    Vector4 velocity, saved;
    float size, heading, elevation, magnitude;
    int sign;
    if (count > 0) do {
        size=func_002A7878(0.1f,2.0f);
        sign=func_002A77E0(2);
        sign=sign ? sign : sign-1;
        heading=func_002A7940();
        elevation=func_002A7878(0.3490659f,1.5358899f);
        magnitude=func_002A7878(0.05f,0.1f);
        func_002AF000(velocity.f,magnitude,heading,elevation);
        saved.bits=position->bits;
        position->f[0]+=func_002A78D8(0,0.15f);
        position->f[1]+=func_002A78D8(0,0.15f);
        position->f[2]+=func_002A78D8(0,0.15f);
        func_002C2210(position,30,0x7F207F7F,0,sign,&velocity,0,size*0.1f,size,0.003f);
        func_002C2210(position,30,0x7F7F7F7F,1,-sign,&velocity,0,size*0.07f,size*0.7f,0.003f);
    } while (--count);
}
