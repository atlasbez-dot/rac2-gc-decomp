/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections.
 * Reported final C / retail: 1020 / 1064 bytes; size equality is not a match.
 * us: 0/28 placements; 1020/1064 bytes.
 * us2: not run after us mismatch; no exact candidate.
 * pal: not run after us mismatch; no exact candidate.
 * Residual: Complete page traversal, list selection, preview update and special-page launch are retained. Dynamic selection, bit-table indexing and scratchpad outputs preserve their actual inputs. Frame/register allocation differs.
 * Reopening condition: Recover the original selected-list and global-root pointer lifetimes, retaining the complete queue-view type and both scratchpad outputs.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Not matched. boot: 1020 bytes, expected 1064.
 * Profile: -O2 -G0 -ffunction-sections
 * Complete page traversal, list selection, preview update and special-page launch are retained. Dynamic selection, bit-table indexing and scratchpad outputs preserve their actual inputs. Frame/register allocation differs.
 * Reopen: Recover the original selected-list and global-root pointer lifetimes, retaining the complete queue-view type and both scratchpad outputs.
 * US placement check: 0/28. No linked-build or runtime claim.
 */
#include "common.h"
typedef struct { u8 prefix[0x30]; int field30,field34,field38,field3c,field40,field44; } BarlowUtilityQueueView;
extern u8 D_001F2840[],D_0025E680[],D_001A7BC8[],D_00139768[],D_0025A6E0[];
extern int D_001C51D0,D_001A79F0,D_0025A620,D_001A7478,D_001A72D4;
extern BarlowUtilityQueueView D_001BAD40;
extern int func_00295A10(int),func_002E5E58(int,int,void *),func_0029DB28(int *,int *,int *,int);
extern void func_00295C50(int),func_0029D830(void),func_002C9E60(int);
extern int func_00288AA0(u8 *,int),func_00288BE8(BarlowUtilityQueueView *);
extern u8 D_00138180[];
int func_002D7698(u8 *menu)
{
    int previous=D_001C51D0,index,next,count,old,*entry,mapped;
    u32 buttons;
    u8 *owner=*(u8 **)(D_001F2840+0x14);
    if (*(u8 **)(owner+0xe8)!=menu) {
        if (D_001C51D0<28) *(int *)(menu+0x30+D_001C51D0*4)=-1;
        return 0;
    }
    if ((*(u32 *)(D_00138180+0x1c4)&0xd00) && !*(int *)(D_001F2840+0x134) && owner!=D_0025E680) return 1;
    if (*(u32 *)(D_00138180+0x1c4)&8) {
        index=D_001C51D0;
        do {next=index+1;if (next>27) goto previous_page;index=next;} while (!D_001A7BC8[next] && D_001A79F0!=next);
        if (func_00295A10(next)<0) return 0;func_00295C50(next);
    }
previous_page:
    if (*(u32 *)(D_00138180+0x1c4)&4) {
        index=D_001C51D0;
        do {next=index-1;if (next<0) goto page_ready;index=next;} while (!D_001A7BC8[next] && D_001A79F0!=next);
        if (func_00295A10(next)<0) return 0;func_00295C50(next);
    }
page_ready:
    if (D_001C51D0!=previous) {func_002E5E58(3,0,0);func_0029D830();}
    count=func_0029DB28((int *)0x70000000,0,(int *)0x70000100,1);*(int *)(menu+0xa0)=count;
    buttons=*(u32 *)(D_00138180+0x1c4);
    if (!count) {*(int *)(D_0025A6E0+0x34)=0;D_0025A620=-1;}
    else {
        entry=(int *)(menu+0x30+D_001C51D0*4);old=*entry;
        if (buttons&0x1000) *entry=(old+count-1)%count;
        if (buttons&0x4000) {entry=(int *)(menu+0x30+D_001C51D0*4);*entry=(*entry+1)%*(int *)(menu+0xa0);}
        entry=(int *)(menu+0x30+D_001C51D0*4);
        if (*entry!=old) func_002E5E58(3,0,0);
        if ((buttons&0x5000) || D_001C51D0!=previous) {
            *(int *)(D_0025A6E0+0x3c)=-576;entry=(int *)(menu+0x30+D_001C51D0*4);
            *(int *)(D_0025A6E0+0x34)=((int *)0x70000000)[*entry];D_0025A620=((int *)0x70000100)[*entry];
        }
    }
    owner=*(u8 **)(D_001F2840+0x14);
    if ((*(u32 *)(D_00138180+0x1c4)&16) && owner!=D_0025E680) {
        next=*(int *)(owner+0xe0);
        if (!next) {if (!*(int *)(D_001F2840+0x134)) return -1;next=*(int *)(D_001F2840+0x18);}
        *(int *)(D_001F2840+0x18)=next;return 0;
    }
    if ((*(u32 *)(D_00138180+0x1c4)&32) && D_001C51D0>=0) {
        if (D_001F2840[0xdb]) return 0;
        mapped=21;if (D_001C51D0) {mapped=D_001C51D0;if (mapped==24) mapped=0;}
        if (D_001C51D0>=0 && (*(u32 *)(D_00139768+(mapped&~3u))&(1u<<(mapped&31)))) {
            D_001A72D4=*(int *)(D_001F2840+0x28);func_002C9E60(0);
            *(int *)(D_001F2840+0x140)=D_001A7478;*(u8 **)(D_001F2840+0x100)=*(u8 **)(D_001F2840+0x14);
            *(int *)(D_001F2840+0xf4)=D_001C51D0;*(int *)(D_001F2840+0x104)=*(int *)(D_001F2840+8);D_001A7478=2;
            func_00288AA0((u8 *)&D_001BAD40,mapped);func_00288BE8(&D_001BAD40);return 1;
        }
    }
    return 0;
}
