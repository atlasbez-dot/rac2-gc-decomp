/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections.
 * Reported final C / retail: 868 / 880 bytes; size equality is not a match.
 * us: 0/28 placements; 868/880 bytes.
 * us2: not run after us mismatch; no exact candidate.
 * pal: not run after us mismatch; no exact candidate.
 * Residual: The0x30 frame matches. Timer updates preserve signed tests and unsigned halfword arithmetic. Entry address temporaries, allocation and selection branches differ. Retail D5E38 forwards the int result from D5B58; its current void source signature needs a separate repair.
 * Reopening condition: Repair the real D5E38 forwarding interface, then recover timer/address lifetimes; the scalar callback result is four bytes, not a padding array.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Not matched. boot: 868 bytes, expected 880.
 * Profile: -O2 -G8 -ffunction-sections
 * The0x30 frame matches. Timer updates preserve signed tests and unsigned halfword arithmetic. Entry address temporaries, allocation and selection branches differ. Retail D5E38 forwards the int result from D5B58; its current void source signature needs a separate repair.
 * Reopen: Repair the real D5E38 forwarding interface, then recover timer/address lifetimes; the scalar callback result is four bytes, not a padding array.
 * US placement check: 0/28. No linked-build or runtime claim.
 */
#include "common.h"
typedef struct { s16 message; u16 action; int value; s16 flags; u16 timer; } MenuRow;
extern u8 D_001F2840[],D_00138180[];
extern int D_001AA440 __attribute__((sda));
extern int D_001A79F0;
extern u32 D_001A7424;
extern int *D_001AA4F0 __attribute__((sda));
extern void func_00295C50(int),func_0027D330(int),func_002C9C60(float);
extern int func_002D5E38(char *,int,int *),func_002E5E58(int,int,void *);
int func_002D5EC0(u8 *menu)
{
    int result,active,index=0,old,count,oldTimer;
    u32 flags,buttons;
    MenuRow *rows=*(MenuRow **)(menu+0x34);
    u8 *owner=*(u8 **)(D_001F2840+0x14);
    active=*(u8 **)(owner+0xe8)==menu;
    while(rows[index].message) {
        if (active && *(int *)(menu+0x40)==index) {
            if ((s16)rows[index].timer<32000) oldTimer=rows[index].timer+1;else oldTimer=32000;
            rows[index].timer=oldTimer;
        } else {
            rows=*(MenuRow **)(menu+0x34);
            if (D_001AA440<(s16)rows[index].timer) rows[index].timer=D_001AA440;
            rows=*(MenuRow **)(menu+0x34);
            if ((s16)rows[index].timer<1) oldTimer=0;else oldTimer=rows[index].timer-1;
            rows[index].timer=oldTimer;
        }
        rows=*(MenuRow **)(menu+0x34);index++;
    }
    if (!active) return 0;
    if (*(u32 *)(D_00138180+0x1c4)&0x900) {
        if (*(u32 *)(menu+0x30)&0x20) func_00295C50(D_001A79F0);
        return -1;
    }
    if (*(u32 *)(D_00138180+0x1c4)&16) {
        if (*(u32 *)(menu+0x30)&0x20) func_00295C50(D_001A79F0);
        owner=*(u8 **)(D_001F2840+0x14);result=*(int *)(owner+0xe0);
        if (!result) {if (!*(int *)(D_001F2840+0x134)) return -1;result=*(int *)(D_001F2840+0x18);}
        *(int *)(D_001F2840+0x18)=result;return 0;
    }
    if ((*(u32 *)(D_00138180+0x1c4)&64) && ((D_001A7424^1)&1)) {
        if (*(u32 *)(menu+0x30)&0x20) {func_0027D330(4);func_002C9C60(4.0f);}
        result=0;rows=*(MenuRow **)(menu+0x34);
        if (func_002D5E38((char *)menu,rows[*(int *)(menu+0x40)].action,&result)) return result;
    }
    rows=*(MenuRow **)(menu+0x34);count=0;while(rows[count].message) count++;
    old=*(int *)(menu+0x40);flags=*(u32 *)(menu+0x30);
    buttons=*(u32 *)(D_00138180+(flags&1?0x1b4:0x1c4));
    if ((buttons&0x1000) || ((flags&0x100) && (buttons&4))) {
        index=*(int *)(menu+0x40);
        if (!index) {if (flags&0x1000) *(int *)(menu+0x40)=count-1;else *(int *)(*(u8 **)(D_001F2840+0x14)+0x128)=*(int *)(menu+0x38);}
        else *(int *)(menu+0x40)=index-1;
    }
    if ((buttons&0x4000) || ((*(u32 *)(menu+0x30)&0x100) && (buttons&8))) {
        index=*(int *)(menu+0x40);rows=*(MenuRow **)(menu+0x34);
        if (!rows[index+1].message || !rows[index+1].action) {
            if (*(u32 *)(menu+0x30)&0x1000) *(int *)(menu+0x40)=0;
            else *(int *)(*(u8 **)(D_001F2840+0x14)+0x128)=*(int *)(menu+0x3c);
        } else *(int *)(menu+0x40)=index+1;
    }
    if (*(int *)(menu+0x40)!=old || *(int *)(*(u8 **)(D_001F2840+0x14)+0x128)) {
        func_002E5E58(3,0,0);
        if (*(u32 *)(menu+0x30)&0x20) func_00295C50(D_001AA4F0[*(int *)(menu+0x40)]);
    }
    return 0;
}
