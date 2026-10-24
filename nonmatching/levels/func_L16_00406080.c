/* Bounded manual reconstruction, 2026-10-23; not linked.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * us: func_L16_00406080: 0 of 3 places match (src/levels/shared/L16_00406080-qcopy.c); us2: func_L16_00406080: 0 of 3 places match (src/levels/shared/L16_00406080-qcopy.c); pal: func_L16_00406080 is in neither catalogue of pal
 * 748/756 bytes; parameter storage, header/field scheduling and allocation differ. The sphere query reads both a0 (sphere) and f12 (threshold), verified from retail and preserved; Ghidra omits a0. Reopen with original parameter-packet or calling-interface evidence, without inventing varargs.
 * Historical screening note below predates this C reconstruction.
 */
/* func_L16_00406080 - 756 bytes, 3 place(s), level 16_snivelak, retail at
   0x00406080. Screened with tools/w10_screen.py: 14 call(s)
   [func_0029EFD0@004060D8, func_00282CF0@0040612C, func_00282F20@0040613C,
   func_002AFFD8@00406150, func_00282DD8@0040616C, func_00282F20@0040617C,
   func_00282DD8@0040618C, func_00283DB8@0040622C, func_00282E48@0040625C,
   func_00282CF0@004062BC, func_00282F20@004062D0, func_00282DB0@004062DC,
   func_002831B0@004062E4, func_L16_00406550@00406330]; data addresses
   materialised [0x1c0000, 0x3dcc0000, 0x3d990000, 0x3fc90000, 0x3ee80000];
   float constants [0x3f800000, 0x40800000, 0x40400000, 0x43000000,
   0x42400000, 0x3f800000]; $gp-relative small data: no   saves: -; callee-
   saved registers saved [-]; words plain C cannot emit [LQ/SQ
   7BC20000@0x0084, LQ/SQ 7E420000@0x0088, LQ/SQ 7BA20000@0x00d8, LQ/SQ
   7E220000@0x00dc, LQ/SQ 7A420000@0x0190, LQ/SQ 7C820000@0x0194]. Head:
   addiu $sp, $sp, -0xC0 ; sd $fp, 0xA0($sp) ; swc1 $f21, 0xB8($sp) ; daddu
   $fp, $a0, $zero ; sd $s6, 0x90($sp) ; mov.s $f21, $f12. Not matched in
   this wave: the 128-bit copy needs an `lq`/`sq` pair; plain C reaches it
   only through a `mode(TI)` local, and this cc1 folds the destination
   offset into the `sq` where retail materialises the pointer first. What
   would unblock it: the exact source expression tree, so this cc1 picks the
   same registers in the same order. */

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
    float angle;
    if (object != 0) {
        state=*(char **)(object+0x68);
        *(unsigned char *)(object+0x30)=0xff;
        *(short *)(object+0x32)=0xff;
        object[0x20]=0;
        *(Vector128 *)(object+0x10)=*(Vector128 *)position;
        *(float *)(object+0x1c)=1.0f;
        func_00282CF0(direction,D_L16_001B9B00,object+0x10);
        func_00282F20(direction,direction,1.0f);
        func_002AFFD8(object+0x10,(char *)up,1);
        *(Vector128 *)(object+0xc0)=*direction;
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
        *(Vector128 *)sphere=*(Vector128 *)(object+0x10);
        ((float *)sphere)[3]=size*3.0f;
        if (func_00283DB8(sphere,128.0f)==1) {
            *(short *)(state+4)=10;
            *(float *)(state+0x10)=0.1f;
            if (func_00282E48(position,D_L16_001B9B00)<48.0f && trigger!=0) {
                D_L16_001B9B2C=0;
                D_L16_001B9B20=0.075f;
                D_L16_001B9B28=40;
            }
            if (*(int *)(state+0x18)!=0) {
                func_00282CF0(difference,object+0x10,D_L16_001B9B00);
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
