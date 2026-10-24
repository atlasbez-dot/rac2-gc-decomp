/* Bounded manual reconstruction, 2026-10-23; not linked.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * us: func_L16_00395ED0: 0 of 2 places match (src/levels/shared/L16_00395ED0-qcopy.c); us2: func_L16_00395ED0: 0 of 2 places match (src/levels/shared/L16_00395ED0-qcopy.c); pal: func_L16_00395ED0 is in neither catalogue of pal
 * 524/532 bytes; local/global register allocation and mixed GP/absolute component reads differ. Preserves real four-float vector objects, exact float constants and float return banks. Reopen with the original vector declaration and source-lifetime evidence.
 * Historical screening note below predates this C reconstruction.
 */
/* func_L16_00395ED0 - 532 bytes, 2 place(s), level 16_snivelak, retail at
   0x00395ed0. Screened with tools/w10_screen.py: 16 call(s)
   [func_002AA548@00395F4C, func_002833F0@00395F5C, func_00283248@00395F80,
   func_00283248@00395F98, func_00282E20@00395FA8, func_00282E20@00395FB8,
   func_002AA150@00395FDC, func_00283180@00395FF8, func_00283198@00396008,
   func_00283098@00396054, func_00282CC0@00396064, func_00283810@00396084,
   func_00283958@00396090, func_002AB6D8@003960A0, func_00335370@003960A8,
   func_003353C8@003960B0]; data addresses materialised [0x39410000,
   0x3c350000, 0x1b0000, 0x1b0000, 0x1b0000, 0x1b0000, 0x1b0000, 0x1b0000,
   0x1b0000, 0x1b0000]; float constants [0x3f800000, 0x1b0000, 0x1b0000];
   $gp-relative small data: no   saves: -; callee-saved registers saved [-];
   words plain C cannot emit [LQ/SQ 78620000@0x0170, LQ/SQ 7C820000@0x0174].
   Head: addiu $sp, $sp, -0xE0 ; addiu $v1, $zero, -0x1 ; sd $s1, 0x98($sp)
   ; sd $s2, 0xA0($sp) ; sd $ra, 0xA8($sp) ; swc1 $f24, 0xD0($sp). Not
   matched in this wave: the 128-bit copy needs an `lq`/`sq` pair; plain C
   reaches it only through a `mode(TI)` local, and this cc1 folds the
   destination offset into the `sq` where retail materialises the pointer
   first. What would unblock it: the exact source expression tree, so this
   cc1 picks the same registers in the same order. */

#include "common.h"
typedef int Vector128 __attribute__((mode(TI)));
typedef struct { Vector128 rotation[3], source[3], quaternion, angles, position; } BlendWorkspace;
extern void func_002AA548(float *,float *,float,float,float,float);
extern void func_002833F0(void *,void *);
extern float func_00283248(float,float);
extern float func_00282E20(void *);
extern float func_002AA150(float,float,float);
extern float func_00283180(float);
extern float func_00283198(float);
extern void func_00283098(void *,void *,void *);
extern void func_00282CC0(void *,void *,void *);
extern void func_00283810(void *,void *,void *,float);
extern void func_00283958(void *,void *);
extern void func_002AB6D8(float *,float *);
extern void func_00335370(void *);
extern void func_003353C8(void *);
extern float D_L16_001B3490[4];
extern float D_L16_001B34A0[4];
extern float D_L16_001B34B0[4];
extern float D_L16_001B34C0[4];
void func_L16_00395ED0(char *object)
{
    BlendWorkspace local;
    char *state=*(char **)(object+0x68);
    float startAngle,endAngle,startLength,endLength,startHeight,endHeight,angle,length;
    float *position=(float *)&local.position;
    if (*(int *)(state+4)==-1) return;
    if (*(float *)(state+0x4c)<1.0f) func_002AA548((float *)(state+0x4c),(float *)(state+0x50),1.0f,0.0001850000117f,0.0001850000117f,0.01110000070f);
    func_002833F0(local.source,state+0x20);
    if (*(float *)(state+0x4c)<1.0f) {
        startAngle=func_00283248(D_L16_001B34B0[0],D_L16_001B34B0[1]);
        endAngle=func_00283248(D_L16_001B34C0[0],D_L16_001B34C0[1]);
        startLength=func_00282E20(D_L16_001B34B0);
        endLength=func_00282E20(D_L16_001B34C0);
        startHeight=D_L16_001B34B0[2]; endHeight=D_L16_001B34C0[2];
        angle=func_002AA150(startAngle,endAngle,*(float *)(state+0x4c));
        length=(endLength-startLength)*(*(float *)(state+0x4c))+startLength;
        position[0]=func_00283180(angle)*length;
        position[1]=func_00283198(angle)*length;
        position[2]=0.0f;
        position[2]=(endHeight-startHeight)*(*(float *)(state+0x4c))+startHeight;
    } else *(Vector128 *)position=*(Vector128 *)D_L16_001B34C0;
    func_00283098(position,position,local.source);
    func_00282CC0(position,position,state+0x10);
    func_00283810(&local.quaternion,D_L16_001B3490,D_L16_001B34A0,*(float *)(state+0x4c));
    func_00283958(&local.quaternion,local.rotation);
    func_002AB6D8((float *)local.rotation,(float *)&local.angles);
    func_00335370(position);
    func_003353C8(&local.angles);
}
