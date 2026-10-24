/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections -mno-split-addresses.
 * Reported final C / retail: 1084 / 1168 bytes; size equality is not a match.
 * us: 0/28 placements; 1084/1168 bytes.
 * us2: not run after us mismatch; no exact candidate.
 * pal: not run after us mismatch; no exact candidate.
 * Residual: The0x30 frame matches. Save slots use a measured 28-byte stride with four-byte alignment, including the 64-bit timestamp. State persistence, overwrite selection and close/back paths remain nonmatching.
 * Reopening condition: Recover the save-root and record-slot source grouping; retain packed timestamp access rather than an unaligned scalar-pointer cast.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Not matched. boot: 1084 bytes, expected 1168.
 * Profile: -O2 -G0 -ffunction-sections -mno-split-addresses
 * The0x30 frame matches. Save slots use a measured 28-byte stride with four-byte alignment, including the 64-bit timestamp. State persistence, overwrite selection and close/back paths remain nonmatching.
 * Reopen: Recover the save-root and record-slot source grouping; retain packed timestamp access rather than an unaligned scalar-pointer cast.
 * US placement check: 0/28. No linked-build or runtime claim.
 */
#include "common.h"
/* Four-byte slot alignment and the28-byte stride are measured retail layout. */
typedef struct __attribute__((packed,aligned(4))) { int stage,balance,status,ticks; u64 stamp; int tail; } SaveSlot;
extern u8 D_001F2840[],D_00138180[],D_001393E0[],D_0025E870[],D_0025DA38[],D_00260EE8[],D_001A7A08[];
extern u8 *D_001A8CFC;
extern int D_001B1A3C,D_001A7420,D_001A7424,D_001A8C88,D_001A7C08,D_001A79F0,D_001A79F8,D_001A7BC0;
extern u64 D_001A7360;
extern void func_00339790(u8 *,int),func_002DE858(int,int),func_00287E98(void),func_002D5B38(int,int);
extern int func_002B49E0(int,int,int,int,u8 *),func_00287E70(void),func_002857B0(void),func_002E5E58(int,int,void *);
int func_002DCB58(u8 *menu)
{
    u8 *owner=*(u8 **)(D_001F2840+0x14);
    SaveSlot *slot;
    int previous,destination;
    u32 buttons;
    if (*(u8 **)(owner+0xe8)!=menu) return 0;
    if (D_001A8CFC) func_00339790(D_001A8CFC+0x3caa8,*(int *)(menu+0x40));
    if (!*(int *)(menu+0x4c) && *(u8 **)(D_001F2840+0xe0)==D_0025E870 && *(int *)(D_0025E870+0x12c)) *(int *)(menu+0x4c)=1;
    if (*(int *)(menu+0x4c)==1) {
        func_002DE858(*(int *)(menu+0x48),*(int *)(menu+0x40));
        *(int *)(D_001F2840+0x13c)=0x2dfc;*(int *)(D_001F2840+0x138)=1;D_001B1A3C=0;
    }
    *(int *)(menu+0x4c)=2;previous=*(int *)(menu+0x40);
    if (*(int *)(D_001F2840+0x138)) {
        if (*(int *)(D_001393E0+0x15c)>2 || *(int *)(D_001393E0+0x164)>=0 || *(int *)(D_001F2840+0x164)<11) return 0;
        *(int *)(D_001F2840+0x138)=0;
        if (!*(int *)(D_001393E0+0x16c) && !*(int *)(D_001393E0+0x10) && !D_001B1A3C) {
            *(int *)(D_001393E0+0x17c)=1;slot=(SaveSlot *)(D_001393E0+0x30)+*(s16 *)(D_001393E0+0x18);
            slot->balance=D_001A79F8;slot->stage=D_001A79F0;slot->ticks=D_001A7BC0;slot->stamp=D_001A7360;slot->status=D_001A7A08[2];
        } else {
            D_001A7424|=0x80;if (*(int *)(D_001393E0+0x17c)) {*(int *)(D_001393E0+0x17c)=0;func_00287E98();}
            if (!func_002B49E0(4,1,1,*(int *)(D_001F2840+0x14),0)) return 0;
        }
    }
    if ((*(u32 *)(D_00138180+0x1c4)&0x900) && !*(int *)(D_001F2840+0x134)) return 1;
    if (*(u32 *)(D_00138180+0x1c4)&16) goto close;
    if (D_001A7420==9) func_002D5B38(4,(int)(D_001A8C88?D_00260EE8:D_0025DA38));
    else if (D_001A7420!=16 && D_001A7420!=1) {
        if (func_00287E70() || func_002857B0()!=1) goto close;
        func_002B49E0(4,1,1,*(int *)(D_001F2840+0x14),0);
    }
    if (*(int *)(D_001393E0+0x15c)>2 || *(int *)(D_001393E0+0x164)>=0 || *(int *)(D_001F2840+0x164)<11 || *(int *)(D_001393E0+8)!=2) return 0;
    buttons=*(u32 *)(D_00138180+(*(u32 *)(menu+0x30)&1?0x1b4:0x1c4));
    *(int *)(menu+0x40)=D_001A7C08;if ((buttons&0x1000) && D_001A7C08) --*(int *)(menu+0x40);
    if ((buttons&0x4000) && *(int *)(menu+0x40)<3) ++*(int *)(menu+0x40);
    D_001A7C08=*(int *)(menu+0x40);
    if ((buttons&64) && *(int *)(D_001393E0+8)==2) {
        func_002E5E58(4,0,0);
        if (*(int *)(D_001393E0+0x30+*(int *)(menu+0x40)*28)==-1) *(int *)(menu+0x4c)=1;
        else {*(int *)(D_001F2840+0xe4)=0;*(u8 **)(D_001F2840+0x18)=D_0025E870;*(int *)(D_0025E870+0x170)=*(int *)(menu+0x40);}
    }
    if (*(int *)(menu+0x40)!=previous) func_002E5E58(3,0,0);return 0;
close:
    owner=*(u8 **)(D_001F2840+0x14);destination=*(int *)(owner+0xe0);
    previous=*(int *)(D_001F2840+0x18);*(int *)(D_001F2840+0x18)=destination;
    if (!*(int *)(D_001F2840+0x18)) {
        *(int *)(D_001F2840+0x18)=previous;
        if (!*(int *)(D_001F2840+0x134)) return -1;
    }
    return 0;
}
