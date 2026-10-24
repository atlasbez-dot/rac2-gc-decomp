/* Retained complete manual C; no linked byte credit.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * Compiled text: 828 bytes. us: 0/28, us2: 0/28, pal: catalogue absent (no credit).
 * Residual: The 0xE0 frame and four stack-tail slots agree; GPR assignment, parameter spilling and conditional store/tail scheduling differ.
 * Reopen: Typed object/state-field evidence that changes real lifetimes; preserve all eight GPR, two FP and four stack inputs.
 */
#include "include_asm.h"

typedef struct { float x,y,z,w; } EffectVector __attribute__((aligned(16)));
typedef unsigned int EffectQuad __attribute__((mode(TI)));
extern char *func_0029EFD0(int);
extern void func_00282CF0(void *, const void *, const void *);
extern void func_00282F20(void *, const void *, float);
extern void func_00282DD8(void *, const void *, const void *);
extern void func_002AFFD8(char *, char *, int);
extern int func_002AD330(char *, char *, char *, char *);
extern int func_00283DB8(void *, float);
extern float func_00282E48(void *, void *);
extern float func_00282DB0(void *, void *);
extern float func_002831B0(float);
extern void func_0032CA40(char *, void *, void *, float);
extern char D_001B5200[];
extern EffectVector D_001B5340,D_001B5570;
#define INT_AT(p,o) (*(int *)((char *)(p)+(o)))
#define FLOAT_AT(p,o) (*(float *)((char *)(p)+(o)))
#define SHORT_AT(p,o) (*(short *)((char *)(p)+(o)))

char *func_0032C700(EffectVector *position, int flash, int n0, int n1,
                  int n2, int n3, int n4, int orient, float size, float distance,
                  int mode, int extra, int flags, char *owner)
{
    EffectVector delta, radial, attachment, sphere, direction;
    char *object, *state;
    float angle;
    object=func_0029EFD0(0x13A0);
    if (object) {
    *(unsigned char *)(object+0x30)=255;
    object[0x20]=0;
    SHORT_AT(object,0x32)=255;
    state=*(char **)(object+0x68);
    *(EffectQuad *)(object+0x10)=*(EffectQuad *)position;
    FLOAT_AT(object,0x1C)=1.0f;
    func_00282CF0(&delta,&D_001B5340,object+0x10);
    func_00282F20(&delta,&delta,1.0f);
    func_002AFFD8(object+0x10,(char *)&radial,1);
    *(EffectQuad *)(object+0xC0)=*(EffectQuad *)&delta;
    func_00282DD8(object+0xD0,object+0xC0,&radial);
    func_00282F20(object+0xD0,object+0xD0,1.0f);
    func_00282DD8(object+0xE0,object+0xD0,object+0xC0);
    FLOAT_AT(object,0xCC)=0.0f;
    FLOAT_AT(object,0xEC)=0.0f;
    FLOAT_AT(object,0xDC)=0.0f;
    INT_AT(state,0x20)=n0;
    INT_AT(state,0x24)=n1;
    INT_AT(state,0x28)=n2;
    INT_AT(state,0x2C)=n3;
    INT_AT(state,0x30)=n4;
    SHORT_AT(state,2)=60;
    FLOAT_AT(state,8)=size+size;
    FLOAT_AT(state,12)=size*4.0f;
    INT_AT(state,0x34)=mode;
    INT_AT(state,0x1C)=extra;
    INT_AT(state,0x38)=flags;
    FLOAT_AT(state,0x14)=size;
    INT_AT(state,0x18)=orient;
    SHORT_AT(state,0)=60;
    *(char **)(state+0x3C)=owner;
    *(EffectQuad *)&attachment=0;
    if (owner) func_002AD330(object,owner,object+0x10,(char *)&attachment);
    *(EffectQuad *)&sphere=*(EffectQuad *)(object+0x10);
    sphere.w=size*3.0f;
    if (func_00283DB8(&sphere,128.0f)==1) {
        SHORT_AT(state,4)=10;
        FLOAT_AT(state,0x10)=0.1f;
        if (func_00282E48(position,&D_001B5340)<48.0f && flash) {
            INT_AT(D_001B5200,0x16C)=0;
            FLOAT_AT(D_001B5200,0x160)=0.075f;
            INT_AT(D_001B5200,0x168)=40;
        }
        if (INT_AT(state,0x18)) {
            func_00282CF0(&direction,object+0x10,&D_001B5340);
            func_00282F20(&direction,&direction,1.0f);
            angle=1.5707963705062866f-func_002831B0(func_00282DB0(&direction,&D_001B5570));
            if (angle<0.45378565788269043f) INT_AT(state,0x18)=1;
            else INT_AT(state,0x18)=0;
        }
    } else {
        INT_AT(state,0x18)=0;
        SHORT_AT(state,4)=0;
    }
    func_0032CA40(object,&radial,&attachment,distance);
    }
    return object;
}
