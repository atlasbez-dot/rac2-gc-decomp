/* 2026-10-23 canonical/ABI repair, retained and not linked.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * us: 0 of 27 places match (src/levels/shared/L00_003F4C68-g8-qcopy.c); us2: 0 of 27 places match (src/levels/shared/L00_003F4C68-g8-qcopy.c); pal: func_L00_003F4C68 is in neither catalogue of pal.
 * Current repaired draft: 596/608 bytes in US and US2, 0/27 in each; absent in PAL.
 * func_002B4038(int, int) returns the integer equality predicate tested here. The retail
 * callee at level-00 0032A060 ends in xor/sltiu; it does not return a pointer.
 * These measurements supersede the earlier draft with nonexistent func_L00_0032A060.
 * Object-header stores, tuning-table addresses and allocation/scheduling still differ.
 * Tried independent header values, typed tuning fields and signed-short/modulo ABI corrections.
 * Reopen with original layout and source-order evidence.
 * Historical note below is retained; its no-C-attempt statement predates this draft.
 */
/* from src/levels/shared/L00_003EE100.c: not written this wave. Retail 608 bytes, 27 place(s), first word at L00:003f4c68.
 * Rule: MMI/LQ/SQ (op 0x1e).
 * No C attempt was made (wave-5 tour-2 discard rule).
 * Retail opens with:
 *   0x003f4c68  addiu       $sp, $sp, -0x70
 *   0x003f4c6c  addiu       $v0, $zero, -0x1
 *   0x003f4c70  sd          $s0, 0x20($sp)
 *   0x003f4c74  sd          $s3, 0x38($sp)
 *   0x003f4c78  daddu       $s0, $a2, $zero
 *   0x003f4c7c  sd          $s5, 0x48($sp)
 * Kept as data for the maintainers. */

#include "common.h"
typedef int TI128 __attribute__((mode(TI)));
extern int func_002B4038(int,int);
extern char *func_0029EFD0(int);
extern void func_003001E0(void *,void *,void *);
extern int func_00283CF0(float);
extern float func_00283CE0(int);
extern char *func_L00_0032A088(int,int);
extern int func_002AFFD8(void *,void *,int);
extern void func_00282D30(void *,void *,float);
extern void func_L00_003F51A0(char *,char *);
extern void func_L00_003F5F90(char *);
extern float func_00282DF0(void *);
extern void func_00282F20(void *,void *,float);
extern void func_00282CC0(void *,void *,void *);
extern int func_L00_003F5238(char *,char *);
extern unsigned char D_0013957F;
typedef struct { char prefix[0x50]; float speed; char gap[0x1c]; float distance; char rest[0x6c]; } Tuning;
extern Tuning D_L00_00262570[];
extern unsigned short D_L00_001B0938 __attribute__((sda));
extern unsigned int D_L00_001B0934 __attribute__((sda));
extern TI128 D_L00_001B8DC0;
extern TI128 D_L00_001B8FF0;
char *func_L00_003F4C68(char *position,char *velocity,int id,int mode)
{
    TI128 direction, previous;
    char *object,*state;
    float frames;
    unsigned char stamp;
    if (id == -1 || func_002B4038(0xc04,id) == 0) return 0;
    object=func_0029EFD0(0xcf7);
    if (object != 0) {
        stamp=0xff;
        object[0x30]=stamp;
        *(short *)(object+0x32)=stamp;
        object[0x31]=1;
        state=*(char **)(object+0x68);
        *(TI128 *)(object+0x10)=*(TI128 *)position;
        object[0x20]=0;
        func_003001E0(state,velocity,position);
        *(int *)(state+0x10)=func_00283CF0(128.0f / (D_L00_00262570[D_0013957F].speed*0.016666668f));
        frames=func_00283CE0(*(int *)(state+0x10));
        *(short *)(state+0x1a)=id;
        *(float *)(state+0x14)=1.0f/frames;
        *(char **)(state+0x1c)=func_L00_0032A088(0xc04,id);
        *(short *)(state+0x20)=0;
        *(short *)(state+0x22)=D_L00_001B0938;
        frames=func_00283CE0((short)D_L00_001B0938);
        *(int *)(state+0x28)=mode;
        *(float *)(state+0x24)=1.0f/frames;
        func_002AFFD8(object+0x10,&direction,1);
        func_00282D30(&direction,&direction,-1.0f);
        func_L00_003F51A0(object,(char *)&direction);
        if (D_L00_001B0934 > 3) D_L00_001B0934=0;
        *(short *)(state+0x18)=D_L00_001B0934;
        D_L00_001B0934=((int)(D_L00_001B0934+1))%3;
        func_L00_003F5F90(object);
        if (mode == 1) {
            *(TI128 *)(state+0x40)=D_L00_001B8DC0;
            func_00282F20(state+0x30,&D_L00_001B8FF0,func_00282DF0(velocity));
        }
        if (mode == 2) {
            previous=*(TI128 *)position;
            func_00282CC0(object+0x10,position,velocity);
            if (func_L00_003F5238(object,(char *)&previous) != 0) object[0x20]=2;
        }
    }
    return object;
}
