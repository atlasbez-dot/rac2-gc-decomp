/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections -mno-split-addresses.
 * Reported final C / retail: 1036 / 1048 bytes; size equality is not a match.
 * us: 0/28 placements; 1036/1048 bytes.
 * us2: not run after us mismatch; no exact candidate.
 * pal: not run after us mismatch; no exact candidate.
 * Residual: The0x30 frame matches. The existing D001393E0 partial layout was used to identify the real save-state root. Address materialization and branch sharing differ; -mno-split-addresses improves size without matching.
 * Reopening condition: Recover the root-field source expressions and close/back branch shape without artificial aliases or barriers.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Not matched. boot: 1036 bytes, expected 1048.
 * Profile: -O2 -G0 -ffunction-sections -mno-split-addresses
 * The0x30 frame matches. The existing D001393E0 partial layout was used to identify the real save-state root. Address materialization and branch sharing differ; -mno-split-addresses improves size without matching.
 * Reopen: Recover the root-field source expressions and close/back branch shape without artificial aliases or barriers.
 * US placement check: 0/28. No linked-build or runtime claim.
 */
#include "common.h"
extern u8 D_001F2840[],D_00138180[],D_001393E0[],D_001F2A40[],D_001C4FA0[];
extern u8 D_0025DB68[],D_00260DB8[];
extern u8 *D_001A8CFC;
extern int D_001B1A3C,D_001A7420,D_001A7424,D_001A8C88,D_001A7B98,D_001A79F0,D_00152C28,D_001A7C08;
extern u8 D_001A7BE8;
extern void func_00339790(u8 *,int),func_002E4860(void),func_00132938(int),func_002F64A8(void),func_002D5B38(int,int),func_0029ADA0(char *),func_002C9A78(void);
extern int func_002B49E0(int,int,int,int,u8 *),func_00287E70(void),func_002857B0(void),func_002E5E58(int,int,void *);
extern s16 func_002B7CE0(int);
int func_002DCFE8(u8 *menu)
{
    int previous=*(int *)(menu+0x40),destination;
    u32 buttons;
    u8 *owner;
    if (D_001A8CFC) func_00339790(D_001A8CFC+0x3caa8,previous);
    if (*(int *)(D_001F2840+0x138)) {
        if (*(int *)(D_001393E0+0x15c)>2 || *(int *)(D_001393E0+0x164)>=0 || *(int *)(D_001F2840+0x164)<11) return 0;
        *(int *)(D_001F2840+0x138)=0;
        if (!*(int *)(D_001393E0+0x16c) && !*(int *)(D_001393E0+0x10) && !D_001B1A3C) {
            *(int *)(D_001393E0+0x17c)=1;func_002E4860();func_002B7CE0(1);func_00132938(!D_001A7B98);
            if (D_001A79F0<1 && !D_001A7BE8) func_002F64A8();else func_002B49E0(6,2,5,D_001A79F0,0);
            D_00152C28=0;return 0;
        }
        *(int *)(D_001393E0+0x17c)=0;D_001A7424|=0x100;
        if (!func_002B49E0(4,1,1,*(int *)(D_001F2840+0x14),0)) return 0;
    }
    if ((*(u32 *)(D_00138180+0x1c4)&0x900) && !*(int *)(D_001F2840+0x134)) return 1;
    if (*(u32 *)(D_00138180+0x1c4)&16) goto close;
    if (D_001A7420==9) func_002D5B38(5,(int)(D_001A8C88?D_00260DB8:D_0025DB68));
    else if (D_001A7420!=16 && D_001A7420!=1) {
        if (func_00287E70() || func_002857B0()!=1) goto close;
        func_002B49E0(4,1,1,*(int *)(D_001F2840+0x14),0);
    }
    if (*(int *)(D_001393E0+0x15c)>2 || *(int *)(D_001393E0+0x164)>=0 || *(int *)(D_001F2840+0x164)<11 || *(int *)(D_001393E0+8)!=2) return 0;
    buttons=*(u32 *)(D_00138180+(*(u32 *)(menu+0x30)&1?0x1b4:0x1c4));
    *(int *)(menu+0x40)=D_001A7C08;
    if ((buttons&0x1000) && D_001A7C08) --*(int *)(menu+0x40);
    D_001A7C08=*(int *)(menu+0x40);
    if ((buttons&0x4000) && D_001A7C08<3) {*(int *)(menu+0x40)=D_001A7C08+1;D_001A7C08=*(int *)(menu+0x40);}
    if (buttons&64) {
        if (*(int *)(D_001393E0+8)==2 && *(int *)(D_001393E0+0x30+D_001A7C08*28)>=0) {
            func_002E5E58(4,0,0);*(int *)(D_001393E0+0x148)=0;*(u16 *)(D_001393E0+0x18)=*(u16 *)(menu+0x40);
            func_0029ADA0((char *)D_001F2A40);func_002C9A78();
            if (*(int *)(D_001393E0+0x164)<0) {*(int *)(D_001393E0+0x168)=0;*(int *)(D_001393E0+0x164)=13;}
            *(int *)(D_001F2840+0x138)=1;*(int *)(D_001F2840+0x13c)=0x2dfd;*(int *)(D_001C4FA0+0x10)=0;D_001B1A3C=0;
        } else func_002E5E58(5,0,0);
    }
    if (*(int *)(menu+0x40)!=previous) func_002E5E58(3,0,0);
    return 0;
close:
    owner=*(u8 **)(D_001F2840+0x14);destination=*(int *)(owner+0xe0);
    previous=*(int *)(D_001F2840+0x18);*(int *)(D_001F2840+0x18)=destination;
    if (!*(int *)(D_001F2840+0x18)) {
        *(int *)(D_001F2840+0x18)=previous;
        if (!*(int *)(D_001F2840+0x134)) return -1;
    }
    return 0;
}
