/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections.
 * Reported final C / retail: 816 / 876 bytes; size equality is not a match.
 * us: 0/28 placements; 816/876 bytes.
 * us2: not run after us mismatch; no exact candidate.
 * pal: not run after us mismatch; no exact candidate.
 * Residual: Both text-overlay and texture-panel paths are retained with real 24-byte contexts and eight-argument panel drawing. The context field signedness and frame allocation differ.
 * Reopening condition: Qualify the text-context object layout and source scopes; retain all panel arguments and disabled-entry tests.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Not matched. boot: 816 bytes, expected 876.
 * Profile: -O2 -G0 -ffunction-sections
 * Both text-overlay and texture-panel paths are retained with real 24-byte contexts and eight-argument panel drawing. The context field signedness and frame allocation differ.
 * Reopen: Qualify the text-context object layout and source scopes; retain all panel arguments and disabled-entry tests.
 * US placement check: 0/28. No linked-build or runtime claim.
 */
#include "common.h"
typedef struct { u16 top,bottom,left,right,x,y,width,height,line,flags,extra0,extra1; } TextBox;
extern int D_001393E8,D_0013953C,D_00139544;
extern u8 D_001F2840[],D_001A7AF8[],D_00139588[];
extern s16 D_001A65E0,D_001A65E2;
extern int func_002B49C8(int),func_00288FB8(int);
extern void func_0027C540(int),func_0027C660(void);
extern void *func_00115484(void *,int,unsigned int);
extern void func_00280200(int,int,u8 *,int),func_00294C40(int);
extern void func_0027E018(int,int,int,int,int,int,int,int);
int func_002DA9A8(u8 *menu)
{
    TextBox draw,initial;
    int message,texture,height,index,type;
    u8 *text,*row,*owner;
    if (*(int *)(menu+0x58)<0 || func_002B49C8(6)) return 0;
    if (*(int *)(menu+0x44)<2) {
        if (!(*(u32 *)(menu+0x34)&0x100)) return 1;
        if (D_001393E8!=2) return 2;
        if (D_0013953C<3 && D_00139544<0 && *(int *)(D_001F2840+0x164)>10) return 2;
        func_0027C540(0);
        message=0x2e00;if (*(int *)(D_001F2840+0x138)) message=*(int *)(D_001F2840+0x13c);
        text=(u8 *)func_00288FB8(message);
        func_00115484(&initial,0,24);
        initial.bottom=*(s16 *)(menu+0x24)+1;initial.right=*(s16 *)(menu+0x20)+1;
        initial.left=1;initial.x=*(int *)(menu+0x20)>>1;initial.line=16;initial.flags=5;initial.top=1;initial.y=5;
        draw=initial;
        func_00280200((int)&draw,0x80000000,text,-1);
        height=(s16)draw.height;draw.y=(*(int *)(menu+0x24)-height)>>1;draw.flags^=4;
        func_00280200((int)&draw,0x80000000,text,-1);
        draw.top--;draw.bottom--;draw.left--;draw.right--;draw.x--;draw.y--;
        func_00280200((int)&draw,0x80ffa888,text,-1);
        func_0027C660();return 2;
    }
    if (*(u32 *)(menu+0x34)&4) {
        owner=*(u8 **)(D_001F2840+0x14);owner=*(u8 **)(owner+0xe8);
        index=*(int *)(menu+0x50+(*(int *)(menu+0x44)>=4)*4);
        row=*(u8 **)(owner+0x48)+index*10;
        type=*(s16 *)(row+4);
        if (!type && !D_001A7AF8[*(s16 *)(row+6)]) return 1;
        if (type==1 && !D_00139588[*(s16 *)(row+6)+0x30]) return 1;
    }
    func_0027C540(0);texture=*(int *)(menu+(*(int *)(menu+0x44)<4?0x48:0x4c));func_00294C40(texture);
    if (*(u32 *)(menu+0x10)&8) func_0027E018(*(int *)(menu+0x18),*(int *)(menu+0x1c),*(int *)(menu+0x20),*(int *)(menu+0x24),0,0,*(int *)(menu+0x38),*(int *)(menu+0x3c));
    else func_0027E018(0,0,D_001A65E0,D_001A65E2,0,0,*(int *)(menu+0x38),*(int *)(menu+0x3c));
    func_0027C660();return 16;
}
