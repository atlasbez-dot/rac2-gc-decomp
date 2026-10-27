/* Retained C reconstruction; not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections -mno-split-addresses.
 * Compiled 492 bytes; retail 500 bytes.
 * us: 0/2 placements match (exit 1).
 * us2: 0/2 placements match (exit 1).
 * pal: canonical name absent; no check credit.
 * Remaining: Scoped normalization-loop counters give 492 bytes; the frame remains 0xD0 against
 * retail 0xC0. Three ordinary row assignments and shared qcopy each give 500 bytes with the same
 * frame discrepancy; whole aggregate assignment gives 524. Retail groups three loads before
 * stores; qcopy correctly keeps sequential transfers and therefore cannot reproduce that group.
 * NOT_SDA preserves the two measured absolute scalar loads.
 * Reopen: A verified triangle-source and loop-lifetime witness that avoids the persistent global
 * base and lifetime spill while retaining the actual 48-byte triangle.
 */

#include "common.h"
typedef int Vector128 __attribute__((mode(TI)));
typedef struct { Vector128 rows[3]; } Triangle;
extern float func_002A7878(float,float);
extern int func_002A7820(int,int);
extern void func_00282D30(void *,void *,float);
extern void func_00282CC0(void *,void *,void *);
extern void func_00283098(void *,void *,void *);
extern char *func_002C6DD8(void *,void *,int,float);
extern float D_L16_001B15F0 __attribute__((sda));
extern float D_L16_001B15F4 NOT_SDA;
extern int D_L16_001B15E8 __attribute__((sda));
extern int D_L16_001B15EC NOT_SDA;
extern int D_L16_001B15E0 __attribute__((sda));
extern int D_L16_001B15E4 NOT_SDA;
extern Triangle D_L16_001B1600;
extern char D_L16_001A8F20[];
void func_L16_0040C5F0(char *object)
{
    float weights[4];
    Vector128 point[1],temporary[1];
    Triangle triangle;
    int lifetime;
    float amount,reciprocal;
    char *effect;
    amount=-(func_002A7878(D_L16_001B15F0,D_L16_001B15F4)*0.0002777777845f);
    lifetime=func_002A7820(D_L16_001B15E8,D_L16_001B15EC);
    {
        float *weight=weights;
        int i;
        for(i=2;i>=0;i--) *weight++=func_002A7878(0.0f,1.0f);
    }
    reciprocal=1.0f/(weights[0]+weights[1]+weights[2]);
    {
        float *weight=weights;
        int i;
        for(i=2;i>=0;i--,weight++) *weight *= reciprocal;
    }
    triangle.rows[0]=D_L16_001B1600.rows[0];
    triangle.rows[1]=D_L16_001B1600.rows[1];
    triangle.rows[2]=D_L16_001B1600.rows[2];
    func_00282D30(point,&triangle.rows[0],weights[0]);
    func_00282D30(temporary,&triangle.rows[1],weights[1]);
    func_00282CC0(point,point,temporary);
    func_00282D30(temporary,&triangle.rows[2],weights[2]);
    func_00282CC0(point,point,temporary);
    func_00283098(point,point,object+0xc0);
    func_00282CC0(point,point,object+0x10);
    effect=func_002C6DD8(point,D_L16_001A8F20,lifetime,amount);
    if(effect!=0) {
        *(int *)(effect+4)=D_L16_001B15E0;
        *(int *)(effect+12)=D_L16_001B15E4;
    }
}
