/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections.
 * Reported final C / retail: 752 / 784 bytes; size equality is not a match.
 * us: 0/28 placements; 752/784 bytes.
 * us2: not run after us mismatch; no exact candidate.
 * pal: not run after us mismatch; no exact candidate.
 * Residual: The24-byte text contexts, renderer-mutated metrics, selected-row scrolling and icon clipping are retained. The0xA0 frame matches; context-copy/sign-extension and register allocation differ.
 * Reopening condition: Recover the exact text-context field signedness and lexical lifetimes from the renderer interface.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Not matched. boot: 752 bytes, expected 784.
 * Profile: -O2 -G8 -ffunction-sections
 * The24-byte text contexts, renderer-mutated metrics, selected-row scrolling and icon clipping are retained. The0xA0 frame matches; context-copy/sign-extension and register allocation differ.
 * Reopen: Recover the exact text-context field signedness and lexical lifetimes from the renderer interface.
 * US placement check: 0/28. No linked-build or runtime claim.
 */
#include "common.h"
typedef struct { u16 top,bottom,left,right,x,y,width,height,line,flags,extra0,extra1; } TextBox;
extern int D_001AB910 __attribute__((sda));
extern int D_001ABB28 __attribute__((sda));
extern u8 D_001C4FA0[];
extern void func_0027C540(int);
extern int func_0029DB28(int *,int *,int *,int);
extern void func_002FC560(unsigned int,unsigned long long);
extern int func_00288FB8(int);
extern void func_0027F538(int,int,int,u8 *,int);
extern void *func_00115484(void *,int,unsigned int);
extern void func_0027EB88(int,int,int,int,int,int);
extern void func_0027F120(void),func_0027F110(void),func_0027C660(void);
extern void func_00280200(int,int,u8 *,int);
extern void func_002D9CF8(int,int,int);
int func_002D99E8(u8 *menu)
{
    TextBox draw,initial;
    int mask=0,iconX;
    int x=4,y=4,count,i,selected,color,rows,iconY;
    int *item;
    func_0027C540(0);
    count=func_0029DB28((int *)0x70000000,&mask,0,0);
    func_002FC560(0x42,0x44);func_002FC560(0x47,0x10b);
    if (!D_001AB910) {x=*(int *)(menu+0x18);y=*(int *)(menu+0x1c);}
    func_0027F538(x,y,0x80ffa888,(u8 *)func_00288FB8(0x2dc5),-1);
    y+=20;
    func_00115484(&initial,0,24);
    initial.right=*(s16 *)(menu+0x20);initial.bottom=*(s16 *)(menu+0x24);
    initial.line=16;initial.top=y;initial.left=x;
    draw=initial;
    if (D_001ABB28) func_0027EB88(y,*(int *)(menu+0x24),x,*(int *)(menu+0x20),64,0x202020);
    iconX=x+4;
    item=(int *)0x70000000;
    for(i=0;i<count;i++,item++) {
        selected=*(int *)(menu+0x30+*(int *)(D_001C4FA0+0x230)*4)==i;
        color=0x80ffa888;if (selected) {color=0x8020ffff;func_0027F120();}
        draw.x=x+16;draw.y=y-*(s16 *)(menu+0xa4);
        func_00280200((int)&draw,color,(u8 *)func_00288FB8(*item),-1);
        if (selected) {
            if ((s16)draw.y<(s16)draw.top+4) *(int *)(menu+0xa4)-=4;
            if ((s16)draw.bottom-(s16)draw.height-4<(s16)draw.y) *(int *)(menu+0xa4)+=4;
            func_0027F110();
        }
        rows=(s16)draw.height/(s16)draw.line;
        iconY=y+10;if (rows==2) iconY=y+16;
        iconY-=*(int *)(menu+0xa4);
        if ((s16)draw.top+4<=iconY && iconY<=(s16)draw.bottom-4) func_002D9CF8(iconX+5,iconY,(mask>>i)&1);
        y+=rows*16;
    }
    func_0027C660();return 2;
}
