/* Near miss (M5): 544/544 B, 3 lines off at the 27 places: retail stores the 0xFF alpha
   byte right after the flags `lhu`, before `obj+0x10` and the work-pointer load; sched1
   here lifts both above it. Statement order and every mix of struct/byte views of the six
   head accesses tie. Solved: the body inside `if (object) { ... } return object;` (retail's
   null exit reaches `return object`), the failure arm `func_0029F338(object); return 0;`,
   D_0018C0B0 as an incomplete array (split %hi/%lo), and struct views of the work block
   and object. Profile `-O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier`. */
#include "include_asm.h"
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
extern char *D_0018C0B0[];
extern int D_L00_001AEFA8 __attribute__((sda));
extern int D_L00_001AEF48 __attribute__((sda));
extern unsigned char D_00139591;
extern unsigned char D_L00_00262570[][224];
typedef struct {
    Quadword velocity;
    Quadword basis[3];
    int f40, f44, handle;
    short f4C;
    signed char f4E;
    unsigned char f4F;
    int f50;
    int pad54;
    float f58;
    int pad5C;
    int f60, f64;
    void *owner;
    int pad6C;
    int f70;
} TrailWork;
typedef struct {
    char pad00[0x10];
    Quadword position;
    unsigned char state;
    char pad21[0xF];
    unsigned char alpha;
    char pad31;
    unsigned short drawMask;
    unsigned short flags;
    char pad36[0x32];
    TrailWork *work;
} TrailMoby;
char *func_L00_0038A748(void *owner,Vector4 *position,Vector4 *velocity)
{
    Vector4 direction, forward, quaternion, axis;
    Vector4 rotation[3];
    char *object=func_0029EFD0(0x1367);
    TrailWork *work;
    float angle;
    int initialState=255;
    if(object) {
        ((TrailMoby *)object)->flags|=0x100;
        work=((TrailMoby *)object)->work;
        ((TrailMoby *)object)->drawMask=initialState;
        ((TrailMoby *)object)->state=0;
        ((TrailMoby *)object)->alpha=initialState;
        ((TrailMoby *)object)->position=position->bits;
        work->velocity=velocity->bits;
        func_002833F0(object+0xC0,D_0018C0B0[0]+0xF0);
        func_002FE8D8(object+0x10,&direction);
        func_00282F20(&forward,object+0xE0,1);
        func_00282DD8(&axis,&forward,&direction);
        angle=func_00282DB0(&forward,&direction)*0.5f;
        func_00282D30(&quaternion,&axis,func_00283198(angle));
        quaternion.f[3]=func_00283180(angle);
        func_00283958(&quaternion,rotation);
        func_00283738(object+0xC0,rotation,object+0xC0);
        work->f64=0; work->f50=0; work->f44=0;
        work->f60=10;
        work->f4C=1; work->f40=D_L00_001AEFA8;
        func_00282C88(&work->basis[0]);
        *(float *)&work->basis[0]=1;
        work->basis[2]=work->basis[0];
        work->basis[1]=work->basis[0];
        work->f58=0.026179943f;
        work->owner=owner;
        work->handle=func_002FEC78((unsigned char *)object,0);
        if(work->handle==-1) { func_0029F338(object); return 0; }
        work->f4F=func_002FED90(object,0,1,1,1);
        work->f4E=-1; work->f70=0;
        func_002A0F48(object);
    }
    return object;
}
