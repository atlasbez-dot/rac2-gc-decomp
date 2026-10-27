/* Manual reconstruction, wave8 (2026-10-25). Nonmatching; no linked or runtime credit.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * Final checks: US 0/3; US2 0/3; PAL absent from catalogue.
 * The complete aligned velocity snapshot precedes the movement call; scale is saved and restored.
 * State setters take three integer-bank inputs. Floating guards preserve retail comparison polarity.
 * Selector lowering, branch scheduling and vector-address allocation still differ; text 1232/1260 bytes.
 * Reopen with a new control-flow or allocator explanation; the historical byte-versus-minus-one test is unchanged.
 */
#include "common.h"
typedef int Vector128 __attribute__((mode(TI)));
extern float func_0029F530(char *);
extern int func_L07_00321D68(char *,void *);
extern void func_00282CF0(void *,void *,void *);
extern void func_00282F20(void *,void *,float);
extern float func_00283248(float,float);
extern float func_002AAA00(float *,float *,int,float,float,float,float);
extern void func_00282D30(void *,void *,float);
extern void func_00282CC0(void *,void *,void *);
extern int func_L01_00321178(char *,char *);
extern void func_002B5278(unsigned char *,float);
extern void func_002B5258(char *);
extern int func_002B4FF0(char *,float *,float);
extern void func_002A7750(unsigned char *,int,int);
extern float func_L00_002EE290(void *);
extern void func_00283028(void *,void *,void *);
extern Vector128 D_L18_001BFC40;
void func_L18_003F6CA8(char *object)
{
    Vector128 local[1];
    char *state=*(char **)(object+0x68);
    unsigned int mode=*(unsigned char *)(object+0x42);
    float phase,scale,heading;
    *(int *)(state+0x138)&=~2;
    if(mode==(unsigned int)-1) mode=*(unsigned char *)(object+0x43);
    switch(mode) {
    case 0: case 1: case 2: case 3: case 6: case 7: case 8: case 10:
        if(*(unsigned char *)(object+0x20)==16 && *(unsigned char *)(object+0x42)==2) {
            phase=func_0029F530(object);
            if(phase>4.0f && phase<22.0f) {
                func_L07_00321D68(object,state+0x1a0);
                *(float *)(state+0x1a8)-=*(float *)(state+0x12c);
                return;
            }
            if(!(*(float *)(object+0x48)==-1.0f && phase<=4.0f)) return;
            func_002B5258(object);
            return;
        }
        if(*(unsigned char *)(object+0x20)==14) {
            if(*(unsigned char *)(object+0xbc)==0) return;
            func_00282CF0(local,state+0x230,object+0x10);
            func_00282F20(local,local,*(float *)(state+0x274)*0.016666668f);
            heading=func_00283248(*(float *)(state+0x230)-*(float *)(object+0x10),*(float *)(state+0x234)-*(float *)(object+0x14));
            func_002AAA00((float *)(object+0xf8),(float *)(state+0x1b4),0,heading,*(float *)(state+0x114),*(float *)(state+0x118),*(float *)(state+0x11c));
            func_L07_00321D68(object,local);
            return;
        }
        if(*(unsigned char *)(object+0x20)==9) return;
        if(*(short *)(state+0x290)!=0) func_002B5278((unsigned char *)object,*(float *)(state+0x264));
        else func_002B5258(object);
        return;
    case 4:
        func_002B4FF0(object,(float *)(state+0x230),*(float *)(state+0x24c));
        if(*(float *)(state+0x190)<=*(float *)(object+0x18) && *(float *)(state+0x1a8)>0.003333333647f) *(float *)(state+0x1a8)=0.003333333647f;
        if((unsigned int)(*(unsigned char *)(object+0x20)-11)>1) return;
        if(*(int *)(state+0x180)<16) return;
        if(*(float *)(state+0x1a8)<0.001f && *(int *)(state+0x184)==0) func_002A7750((unsigned char *)object,16,-1);
        return;
    case 5:
        phase=func_0029F530(object);
        if(phase>10.0f && phase<17.0f && (*(unsigned int *)(state+0x194)&15)==0 && *(int *)(state+0x180)==0 && *(short *)(state+0x1c2)==0) {

            func_00282D30(local,object+0xc0,10.0f);
            func_00282CC0(local,object+0x10,local);
            func_L01_00321178(object,(char *)local);
            if(!(*(float *)(state+0x190)<=*(float *)(object+0x18))) return;
            if(*(float *)(state+0x1a8)>0.003333333647f) *(float *)(state+0x1a8)=0.003333333647f;
            return;
        }
        if(*(short *)(state+0x290)!=0) func_002B5278((unsigned char *)object,*(float *)(state+0x264));
        else func_002B5258(object);
        return;
    case 9: {
        char *velocity=state+0x1a0;
        char *position;
        if(*(unsigned char *)(object+0x20)==2) return;
        scale=*(float *)(state+0x100);
        qcopy(local,velocity);
        if(*(short *)(state+0x2a6)==0) *(int *)(state+0x138)|=2;
        *(float *)(state+0x100)=(scale*(*(float *)(object+0x2c)))/(*(float *)(state+0x268));
        func_L07_00321D68(object,velocity);
        *(float *)(state+0x100)=scale;
        if(func_L00_002EE290(state+0x170)>0.0f && *(int *)(state+0x184)==0) {
            (*(short *)(state+0x294))++;
            position=object+0x10;
            func_00282CC0(position,position,state+0x170);
            func_00283028(velocity,local,&D_L18_001BFC40);
            func_00282D30(velocity,velocity,0.8f);
            func_00282CC0(position,position,velocity);
        }
        *(float *)(state+0x1a8)-=*(float *)(state+0x12c);
        return;
    }
    case 13:
        if(*(unsigned char *)(object+0x20)!=15) return;
        *(float *)(state+0x1a8)-=*(float *)(state+0x12c);
        func_L07_00321D68(object,state+0x1a0);
        return;
    }
}
