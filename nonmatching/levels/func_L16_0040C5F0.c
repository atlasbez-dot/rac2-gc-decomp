/* Bounded manual reconstruction, 2026-10-23; not linked.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -mno-split-addresses.
 * us: func_L16_0040C5F0: 0 of 2 places match (src/levels/shared/L16_0040C5F0-g8-qcopy.c); us2: func_L16_0040C5F0: 0 of 2 places match (src/levels/shared/L16_0040C5F0-g8-qcopy.c); pal: func_L16_0040C5F0 is in neither catalogue of pal
 * 508/500 bytes; triangle copies and loop/pointer lifetimes differ. A whole triangle assignment gave 524 bytes; explicit quadword row copies gave 508. Reopen with compiler-supported three-row block-copy lowering and loop-lifetime evidence.
 * Historical screening note below predates this C reconstruction.
 */
/* func_L16_0040C5F0 - 500 bytes, 2 place(s), level 16_snivelak, retail at
   0x0040c5f0. Screened with tools/w10_screen.py: 11 call(s)
   [func_002A7878@0040C630, func_002A7820@0040C654, func_002A7878@0040C684,
   func_00282D30@0040C714, func_00282D30@0040C724, func_00282CC0@0040C734,
   func_00282D30@0040C744, func_00282CC0@0040C754, func_00283098@0040C764,
   func_00282CC0@0040C774, func_002C6DD8@0040C78C]; data addresses
   materialised [0x1b0000, 0x39910000, 0x1b0000, 0x1b0000, 0x1b0000,
   0x1b0000]; float constants [0x3f800000, 0x3f800000]; $gp-relative small
   data: no   saves: -; callee-saved registers saved [-]; words plain C
   cannot emit [LQ/SQ 78660000@0x010c, LQ/SQ 78670020@0x0114, LQ/SQ
   78620010@0x0118, LQ/SQ 7FA60030@0x011c, LQ/SQ 7FA20040@0x0120, LQ/SQ
   7FA70050@0x0128]. Head: addiu $sp, $sp, -0xC0 ; lwc1 $f12, 0x2600($gp) ;
   sd $s4, 0x80($sp) ; lui $at, 0x1B ; lwc1 $f13, 0x15F4($at) ; daddu $s4,
   $a0, $zero. Not matched in this wave: the 128-bit copy needs an `lq`/`sq`
   pair; plain C reaches it only through a `mode(TI)` local, and this cc1
   folds the destination offset into the `sq` where retail materialises the
   pointer first. What would unblock it: the exact source expression tree,
   so this cc1 picks the same registers in the same order. */

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
extern float D_L16_001B15F4 __attribute__((nosda));
extern int D_L16_001B15E8 __attribute__((sda));
extern int D_L16_001B15EC __attribute__((nosda));
extern int D_L16_001B15E0 __attribute__((sda));
extern int D_L16_001B15E4 __attribute__((nosda));
extern Triangle D_L16_001B1600;
extern char D_L16_001A8F20[];
void func_L16_0040C5F0(char *object)
{
    float weights[4];
    Vector128 point[1],temporary[1];
    Triangle triangle;
    int i,lifetime;
    float amount,reciprocal;
    float *weight;
    char *effect;
    amount=-(func_002A7878(D_L16_001B15F0,D_L16_001B15F4)*0.0002777777845f);
    lifetime=func_002A7820(D_L16_001B15E8,D_L16_001B15EC);
    weight=weights;
    for(i=2;i>=0;i--) *weight++=func_002A7878(0.0f,1.0f);
    reciprocal=1.0f/(weights[0]+weights[1]+weights[2]);
    weight=weights;
    for(i=2;i>=0;i--,weight++) *weight *= reciprocal;
    *(Vector128 *)&triangle.rows[0]=*(Vector128 *)&D_L16_001B1600.rows[0];
    *(Vector128 *)&triangle.rows[1]=*(Vector128 *)&D_L16_001B1600.rows[1];
    *(Vector128 *)&triangle.rows[2]=*(Vector128 *)&D_L16_001B1600.rows[2];
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
