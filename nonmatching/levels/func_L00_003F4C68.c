/*
 * Retained manual near miss; not linked or counted.
 * Final measured profile: -O2 -G8 -ffunction-sections.
 * Final C / retail: 600 / 608 bytes.
 * us:0/27 placements, exit1; us2:0/27 placements, exit1.
 * pal: absent from catalogue, exit1; absence is not a match.
 * 4 bounded source/profile trials; three natural source forms tie.
 * Correct0x70 frame; mode/object-position saved-register allocation, header stores, tuning address formation and scheduling differ.
 * Reopen only with: Independent header/layout or source-lifetime evidence that changes the mode/position allocator competition.
 * Measured in the dedicated src unit before its marker/profile were restored; this body is retained unchanged modulo this comment.
 * Historical draft and trial variants remain private. Behavior and strict linked equality remain unverified.
 */

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
/* Only the measured header fields are viewed; this is not a whole-object size. */
typedef struct { char prefix[0x30]; unsigned char stamp,enabled; short tag; } HeaderView;
char *func_L00_003F4C68(char *position,char *velocity,int id,int mode)
{
    TI128 direction, previous;
    char *object,*state,*location;
    float frames;
    HeaderView *header;
    unsigned char stamp;
    if (id == -1 || func_002B4038(0xc04,id) == 0) return 0;
    object=func_0029EFD0(0xcf7);
    if (object != 0) {
        header=(HeaderView *)object;
        location=object+0x10;
        stamp=0xff;
        header->tag=stamp;
        header->enabled=1;
        header->stamp=stamp;
        state=*(char **)(object+0x68);
        qcopy(location,position);
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
        func_002AFFD8(location,&direction,1);
        func_00282D30(&direction,&direction,-1.0f);
        func_L00_003F51A0(object,(char *)&direction);
        if (D_L00_001B0934 > 3) D_L00_001B0934=0;
        *(short *)(state+0x18)=D_L00_001B0934;
        D_L00_001B0934=((int)(D_L00_001B0934+1))%3;
        func_L00_003F5F90(object);
        if (mode == 1) {
            qcopy(state+0x40,&D_L00_001B8DC0);
            func_00282F20(state+0x30,&D_L00_001B8FF0,func_00282DF0(velocity));
        }
        if (mode == 2) {
            qcopy(&previous,position);
            func_00282CC0(location,position,velocity);
            if (func_L00_003F5238(object,(char *)&previous) != 0) object[0x20]=2;
        }
    }
    return object;
}
