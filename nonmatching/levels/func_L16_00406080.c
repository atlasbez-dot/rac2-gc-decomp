/* Complete retained reconstruction; not linked.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Tested as src/levels/shared/L16_00406080.c.
 * us: 0/3 placements, exit 1.
 * us2: 0/3 placements, exit 1.
 * pal: explicit catalogue absence, no credit.
 * USA compiled 748 / retail 756 bytes.
 * Residual: Parameter saves, camera-base lifetime and packet header/scalar scheduling differ; retained748 versus756 bytes, with the correct C0 frame.
 * Reopen with: Independent source evidence for the parameter packet or camera-address lifetime, preserving all ten GPR parameters, the f12 size input, and the sphere-plus-float query.
 */

#include "common.h"
typedef int Vector128 __attribute__((mode(TI)));
extern char *func_0029EFD0(int);
extern void func_00282CF0(void *,void *,void *);
extern void func_00282F20(void *,void *,float);
extern void func_002AFFD8(char *,char *,int);
extern void func_00282DD8(void *,void *,void *);
extern int func_00283DB8(void *,float);
extern float func_00282E48(void *,void *);
extern float func_00282DB0(void *,void *);
extern float func_002831B0(float);
extern void func_L16_00406550(char *,char *);
extern char D_L16_001B9B00[];
extern float D_L16_001B9B20;
extern int D_L16_001B9B28;
extern int D_L16_001B9B2C;
extern float D_L16_001B9D30[4];
char *func_L16_00406080(float size,char *position,int trigger,int kind,int red,int green,int blue,int enabled,int flags,int extra,int control)
{
    Vector128 direction[1],up[1],sphere[1],difference[1];
    char *object=func_0029EFD0(0xec1);
    char *state;
    char *camera;
    float angle;
    if (object != 0) {
        camera=D_L16_001B9B00;
        state=*(char **)(object+0x68);
        *(unsigned char *)(object+0x30)=0xff;
        *(short *)(object+0x32)=0xff;
        object[0x20]=0;
        qcopy(object+0x10,position);
        *(float *)(object+0x1c)=1.0f;
        func_00282CF0(direction,camera,object+0x10);
        func_00282F20(direction,direction,1.0f);
        func_002AFFD8(object+0x10,(char *)up,1);
        qcopy(object+0xc0,direction);
        func_00282DD8(object+0xd0,object+0xc0,up);
        func_00282F20(object+0xd0,object+0xd0,1.0f);
        func_00282DD8(object+0xe0,object+0xd0,object+0xc0);
        *(float *)(object+0xcc)=0.0f;
        *(float *)(object+0xec)=0.0f;
        *(float *)(object+0xdc)=0.0f;
        *(short *)(state+2)=60;
        *(float *)(state+8)=size+size;
        *(float *)(state+12)=size*4.0f;
        *(int *)(state+0x20)=kind;
        *(int *)(state+0x24)=red;
        *(int *)(state+0x28)=green;
        *(int *)(state+0x2c)=blue;
        *(int *)(state+0x30)=enabled;
        *(int *)(state+0x34)=extra;
        *(int *)(state+0x1c)=control;
        *(short *)state=60;
        *(int *)(state+0x18)=flags;
        *(float *)(state+0x14)=size;
        qcopy(sphere,object+0x10);
        ((float *)sphere)[3]=size*3.0f;
        if (func_00283DB8(sphere,128.0f)==1) {
            *(short *)(state+4)=10;
            *(float *)(state+0x10)=0.1f;
            if (func_00282E48(position,camera)<48.0f && trigger!=0) {
                D_L16_001B9B2C=0;
                D_L16_001B9B20=0.075f;
                D_L16_001B9B28=40;
            }
            if (*(int *)(state+0x18)!=0) {
                func_00282CF0(difference,object+0x10,camera);
                func_00282F20(difference,difference,1.0f);
                angle=func_002831B0(func_00282DB0(difference,D_L16_001B9D30));
                if (1.5707963705f-angle<0.4537856579f) *(int *)(state+0x18)=1;
                else *(int *)(state+0x18)=0;
            }
        } else {
            *(int *)(state+0x18)=0;
            *(short *)(state+4)=0;
        }
        func_L16_00406550(object,(char *)up);
    }
    return object;
}
