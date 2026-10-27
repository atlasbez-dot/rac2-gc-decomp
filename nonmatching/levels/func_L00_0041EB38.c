/* M13, 26 October 2026: 800/800 B under -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -g
 * (the nops before both div.s are -g statement boundaries). 24 words off: state and the
 * target+0x10 pointer swap s3/s4, the object+0x10 copy is placed after the 30.0 load, and
 * func_002FED90's a1 is loaded first instead of in the delay slot. Fixed: if(object)
 * wrapper, then-arm target test, hero fields through a pointer local (t0), qcopy of the
 * target position, a ShotState struct view, the shot-kind table as a 224-byte struct array.
 * Reopen: an allocation-order explanation for state vs point.
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
extern int func_002FED90(void *,void *,float,float,float);
extern void func_L00_002E6EF8(DrawCallback_r002E6EF8,void *);
extern void func_L00_0041F570(void *);
extern void func_002A0F48(void *);
typedef struct { char pad[0x50]; float speed; char rest[224-0x54]; } ShotKind;
extern ShotKind D_L00_00262570[];
extern char D_00139568[];
extern Quad128 D_00189EA0 __attribute__((nosda));
extern char D_00189E20[];
extern float D_L00_001B1498 __attribute__((sda)),D_L00_001B1494 __attribute__((sda));
extern unsigned int D_L00_001B1490 __attribute__((sda));
typedef struct {
    unsigned int slot;      /* 0x00 */
    int pad04[3];
    int frame;              /* 0x10 */
    int ownerIndex;         /* 0x14 */
    int ownerKind;          /* 0x18 */
    char *target;           /* 0x1C */
    float velocity[3];      /* 0x20 */
    float speed;            /* 0x2C */
    int pad30;
    int handle;             /* 0x34 */
    int count;              /* 0x38 */
    float step;             /* 0x3C */
    float fade;             /* 0x40 */
} ShotState;
char *func_L00_0041EB38(Quad128 *origin,char *owner,char *target)
{
    Quad128 normal,position;
    char *object,*collision,*hero;
    ShotState *state;
    float speed;
    int count,ownerIndex,ownerKind;
    object=func_0029EFD0(0xc89);
    if(object) {
    ((unsigned char *)object)[0x30]=255; *(short *)(object+0x34)=0x100; *(short *)(object+0x32)=255; object[0x31]=1;
    *(char **)(object+0xb8)=owner; object[0x20]=0;
    state=*(ShotState **)(object+0x68);
    speed=(D_L00_00262570+((unsigned char *)D_00139568)[0x16])->speed*0.016666668f;
    hero=D_00189E20;
    if(*(short *)(hero+0x24EC)==1) func_00282F20(state->velocity,owner+0xd0,-speed);
    else if(target) {
        char *point=target+0x10;
        qcopy(&position,point);
        collision=(char *)func_002AB1F0((u8 *)target);
        if(collision) {
            func_002AFFD8(point,(char *)&normal,1);
            func_00282D30(&normal,&normal,*(float *)(collision+0x10));
            func_00282CC0(&position,&position,&normal);
        }
        func_00282CF0(state->velocity,&position,origin); func_00282F20(state->velocity,state->velocity,speed);
    } else if(*(int *)(hero+0x1500)) func_L00_0037FA90(state->velocity,(char *)origin,speed,30.0f,0.3490658998f);
    else func_00282F20(state->velocity,hero+0x760,speed);
    *(Quad128 *)(object+0x10)=*origin;
    state->speed=speed;
    count=func_00283CF0(30.0f/speed)+1; state->count=count;
    state->step=1.0f/func_00283CE0(count);
    *(float *)(object+0x2c)=*(float *)(*(char **)(object+0x24)+0x24)*D_L00_001B1498;
    object[0x20]=0; state->target=target;
    if(target) {
        collision=(char *)func_002AB1F0((u8 *)target);
        if(collision) *(unsigned short *)(collision+0x1e)|=0x80;
    }
    state->fade=1;
    ownerIndex=*(short *)(*(char **)(owner+0x68)+0x12); state->ownerIndex=ownerIndex;
    ownerKind=*(short *)(owner+0xaa); state->ownerKind=ownerKind;
    if(!func_002B4038(ownerKind,ownerIndex)) { func_0029F338(object); return 0; }
    state->frame=0; D_L00_001B1494=0;
    if(D_L00_001B1490>15) D_L00_001B1490=0;
    state->slot=D_L00_001B1490; D_L00_001B1490++;
    if((int)D_L00_001B1490>15) D_L00_001B1490=0;
    position=*(Quad128 *)(object+0x10); *(Quad128 *)(object+0x10)=D_00189EA0;
    state->handle=func_002FED90(object,0,1.0f,1.0f,1.0f);
    *(Quad128 *)(object+0x10)=position;
    func_L00_002E6EF8(func_L00_0041F570,object); func_002A0F48(object);
    }
    return object;
}
