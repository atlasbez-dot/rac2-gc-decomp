/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -mno-split-addresses.
 * Reported final C / retail: 656 / 672 bytes; size equality is not a match.
 * us: 0/28 placements; 656/672 bytes.
 * us2: not run after us mismatch; no exact candidate.
 * pal: not run after us mismatch; no exact candidate.
 * Residual: Input/settings address grouping and clamp scheduling differ despite the correct 0x20 frame. The three selection states and complete confirm/back semantics are retained.
 * Reopening condition: Recover the natural input-block and settings declarations without changing their real widths.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Not matched. boot: 656 bytes, expected 672.
 * Profile: -O2 -G8 -ffunction-sections -mno-split-addresses
 * Input/settings address grouping and clamp scheduling differ despite the correct 0x20 frame. The three selection states and complete confirm/back semantics are retained.
 * Reopen: Recover the natural input-block and settings declarations without changing their real widths.
 * US placement check: 0/28. No linked-build or runtime claim.
 */
#include "common.h"
extern u8 D_00138180[];
extern u8 D_001F2840[];
extern int D_001A7B98 __attribute__((nosda));
extern int D_001A7B9C __attribute__((nosda));
extern int D_001A7BA0 __attribute__((nosda));
extern int *D_001AA4F0 __attribute__((sda));
extern void func_002DF190(int,int);
extern void func_00295C50(int);
extern void func_002E4860(void);
extern void func_00132938(int);
int func_002D7B18(u8 *menu)
{
    int previous,oldX,oldY,next;
    u8 *owner;
    if ((*(u32 *)(D_00138180+0x1c4)&0x900) && !*(int *)(D_001F2840+0x134)) return 1;
    if (*(u32 *)(D_00138180+0x1c4)&0x10) {
        owner=*(u8 **)(D_001F2840+0x14);
        next=*(int *)(owner+0xe0);
        if (next || *(int *)(D_001F2840+0x134)) {
            if (!next) next=*(int *)(D_001F2840+0x18);
            *(int *)(D_001F2840+0x18)=next;return 0;
        }
        return -1;
    }
    previous=*(int *)(menu+0x40);
    if (*(u32 *)(D_00138180+0x1c4)&0x1000) *(int *)(menu+0x40)=(*(int *)(menu+0x40)+2)%3;
    if (*(u32 *)(D_00138180+0x1c4)&0x4000) *(int *)(menu+0x40)=(*(int *)(menu+0x40)+1)%3;
    owner=*(u8 **)(D_001F2840+0x14);
    if (*(int *)(menu+0x40)!=previous || *(int *)(owner+0x128)) {
        func_002DF190(1,17);
        if (*(u32 *)(menu+0x30)&0x20) func_00295C50(D_001AA4F0[*(int *)(menu+0x40)]);
    }
    oldX=D_001A7B9C;oldY=D_001A7BA0;
    if (*(u32 *)(D_00138180+0x1c0)&0x2000) {
        if (*(int *)(menu+0x40)==0) {next=D_001A7BA0+3;D_001A7BA0=next<1025?next:1024;}
        if (*(int *)(menu+0x40)==1) {next=D_001A7B9C+3;D_001A7B9C=next<1025?next:1024;}
    }
    if (*(u32 *)(D_00138180+0x1c0)&0x8000) {
        if (*(int *)(menu+0x40)==0) {next=D_001A7BA0-3;D_001A7BA0=next>=0?next:0;}
        if (*(int *)(menu+0x40)==1) {next=D_001A7B9C-3;D_001A7B9C=next>=0?next:0;}
    }
    if (oldX!=D_001A7B9C || oldY!=D_001A7BA0) func_002E4860();
    if (*(u32 *)(D_00138180+0x1c4)&0x40) {
        if (*(int *)(menu+0x40)==2) D_001A7B98=!D_001A7B98;
        func_00132938(!D_001A7B98);
        func_002DF190(0,17);
    }
    return 0;
}
