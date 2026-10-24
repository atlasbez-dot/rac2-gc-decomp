/* 2026-10-23 bounded reconstruction, not linked.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-por.
 * us: 0 of 27 places match (src/levels/shared/L00_003F5F90-g8-qcopy.c); us2: 0 of 27 places match (src/levels/shared/L00_003F5F90-g8-qcopy.c); pal: func_L00_003F5F90 is in neither catalogue of pal.
 * 476/468 bytes; remaining differences include state/base allocation and extra index reloads around copies. Tried a readable typed local-vector initialization and direct record access. Reopen with independently measured record/state aliasing.
 * Historical note below is retained; its no-C-attempt statement predates this draft.
 */
/* from src/levels/shared/L00_003EE100.c: not written this wave. Retail 468 bytes, 27 place(s), first word at L00:003f5f90.
 * Rule: MMI/LQ/SQ (op 0x1c).
 * No C attempt was made (wave-5 tour-2 discard rule).
 * Retail opens with:
 *   0x003f5f90  addiu       $sp, $sp, -0x70
 *   0x003f5f94  lui         $v0, 0x19
 *   0x003f5f98  sd          $s0, 0x30($sp)
 *   0x003f5f9c  addiu       $v1, $zero, 0x1D
 *   0x003f5fa0  daddu       $s0, $a0, $zero
 *   0x003f5fa4  sd          $s1, 0x38($sp)
 * Kept as data for the maintainers. */

#include "common.h"
typedef int TI128 __attribute__((mode(TI)));
extern int D_0018C0B4;
extern int D_L00_001A8FF0;
extern unsigned short D_L00_001B0998 __attribute__((sda));
extern char *func_L00_0032A088(int,int);
extern char *func_L00_0032A0B8(int,int);
extern void func_00282F20(void *,void *,float);
extern int func_002AFFD8(void *,void *,int);
extern void func_00282DD8(void *,void *,void *);
extern void func_00282CC0(void *,void *,void *);
#define RECORD (base + *(short *)(state + 0x18)*0x60)
void func_L00_003F5F90(char *object)
{
    TI128 direction,up,normal;
    char *state = *(char **)(object+0x68);
    char *base;
    char *position;
    if (D_0018C0B4 == 0x1d) return;
    position = object+0x10;
    base=func_L00_0032A088(0xc04,*(short *)(state+0x1a));
    base+=*(int *)func_L00_0032A0B8(0xc04,*(short *)(state+0x1a));
    func_00282F20(&direction,state,1.0f);
    up=0;
    ((float *)&up)[2]=1.0f;
    ((float *)&up)[3]=1.0f;
    if (D_L00_001A8FF0 != 0) func_002AFFD8(position,&up,1);
    func_00282DD8(&normal,&direction,&up);
    func_00282F20(&normal,&normal,1.0f);
    func_00282DD8(RECORD+0x40,&normal,&direction);
    *(TI128 *)(RECORD+0x30)=direction;
    *(TI128 *)RECORD=*(TI128 *)position;
    func_00282CC0(RECORD+0x10,position,state);
    *(TI128 *)(RECORD+0x20)=*(TI128 *)(RECORD+0x10);
    *(short *)(RECORD+0x52)=D_L00_001B0998;
    *(float *)(RECORD+0x5c)=1.0f/(float)*(short *)(RECORD+0x52);
    *(int *)(RECORD+0x54)=0;
    *(int *)(RECORD+0x58)=0;
    *(short *)(RECORD+0x50)=1;
}
#undef RECORD
