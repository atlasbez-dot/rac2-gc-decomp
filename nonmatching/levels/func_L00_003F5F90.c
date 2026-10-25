/*
 * Retained manual near miss; not linked or counted.
 * Final measured profile: -O2 -G8 -ffunction-sections -frac2-zero-ti-por.
 * Final C / retail: 480 / 468 bytes.
 * us:0/27 placements, exit1; us2:0/27 placements, exit1.
 * pal: absent from catalogue, exit1; absence is not a match.
 * 7 bounded source/profile trials; three natural source forms tie.
 * 480/468 bytes with the correct0x70 frame; guard/base allocation, repeated index/address calculation and scalar-store scheduling differ. An earlier qzero helper trial was476 bytes but used a different zero instruction form; the union-field trial was488 bytes/frame0x80. Neither is the retained480-byte measurement.
 * Reopen only with: Independent record/state-aliasing or zero/local-lifetime evidence. Do not repeat tied source/profile forms.
 * Measured in the dedicated src unit before its marker/profile were restored; this body is retained unchanged modulo this comment.
 * Historical draft and trial variants remain private. Behavior and strict linked equality remain unverified.
 */

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
    TI128 direction,normal;
    char *state = *(char **)(object+0x68);
    char *base;
    char *position;
    if (D_0018C0B4 == 0x1d) return;
    position = object+0x10;
    base=func_L00_0032A088(0xc04,*(short *)(state+0x1a));
    base+=*(int *)func_L00_0032A0B8(0xc04,*(short *)(state+0x1a));
    func_00282F20(&direction,state,1.0f);
    {
    TI128 up=0;
    ((float *)&up)[2]=1.0f;
    ((float *)&up)[3]=1.0f;
    if (D_L00_001A8FF0 != 0) func_002AFFD8(position,&up,1);
    func_00282DD8(&normal,&direction,&up);
    }
    func_00282F20(&normal,&normal,1.0f);
    func_00282DD8(RECORD+0x40,&normal,&direction);
    qcopy(RECORD+0x30,&direction);
    qcopy(RECORD,position);
    func_00282CC0(RECORD+0x10,position,state);
    qcopy(RECORD+0x20,RECORD+0x10);
    *(short *)(RECORD+0x52)=D_L00_001B0998;
    *(float *)(RECORD+0x5c)=1.0f/(float)*(short *)(RECORD+0x52);
    *(int *)(RECORD+0x54)=0;
    *(int *)(RECORD+0x58)=0;
    *(short *)(RECORD+0x50)=1;
}
#undef RECORD
