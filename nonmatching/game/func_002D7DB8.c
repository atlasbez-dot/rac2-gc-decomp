/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections.
 * Reported final C / retail: 820 / 872 bytes; size equality is not a match.
 * us: 0/28 placements; 820/872 bytes.
 * us2: not run after us mismatch; no exact candidate.
 * pal: not run after us mismatch; no exact candidate.
 * Residual: All three settings rows and both slider draw paths are retained. The ten-argument slider interface includes actual stack arguments336 and128, omitted by the decompiler. Frame allocation and preserved pointer lifetimes differ.
 * Reopening condition: Recover the original slider parameter lifetimes and full text-style bank behavior; do not omit stack arguments.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Not matched. boot: 820 bytes, expected 872.
 * Profile: -O2 -G0 -ffunction-sections
 * All three settings rows and both slider draw paths are retained. The ten-argument slider interface includes actual stack arguments336 and128, omitted by the decompiler. Frame allocation and preserved pointer lifetimes differ.
 * Reopen: Recover the original slider parameter lifetimes and full text-style bank behavior; do not omit stack arguments.
 * US placement check: 0/28. No linked-build or runtime claim.
 */
#include "common.h"
extern int D_001A7BA0,D_001A7B9C,D_001A7B98;
extern void func_0027C540(int),func_0027C660(void);
extern int func_00288FB8(int),func_0028E588(int,int);
extern void func_0027F980(int,int,int,u8 *,int),func_0027F538(int,int,int,u8 *,int);
extern void func_0028FC48(int,int,int,int,int,int);
extern void func_0028F788(int,int,int,int,int,int,int,int,int,int);
int func_002D7DB8(u8 *menu)
{
    int quarter=*(int *)(menu+0x24)>>2,half=*(int *)(menu+0x20)>>1;
    int labelX=half-8,barX=half+9,width,color,texture,row;
    func_0027C540(0);
    color=0x80ffa888;if (*(int *)(menu+0x40)==0) color=0x8020ffff;
    func_0027F980(labelX,quarter-8,color,(u8 *)func_00288FB8(0x2f0f),-1);
    func_0028FC48(half+7,quarter-8,*(int *)(menu+0x20)-63,quarter+8,0x80696969,0);
    func_0028FC48(barX,quarter-6,*(int *)(menu+0x20)-65,quarter+6,0x80383838,0);
    width=((*(int *)(menu+0x20)-(half+74))*D_001A7BA0)/1024;
    texture=func_0028E588(0xe99d,8);
    func_0028F788(texture,barX*16,(quarter-6)*16,(half+width+8)*16,(quarter+5)*16,0,160,496,336,128);
    color=0x8020ffff;if (*(int *)(menu+0x40)!=1) color=0x80ffa888;
    func_0027F980(labelX,quarter*2-8,color,(u8 *)func_00288FB8(0x2f10),-1);
    func_0028FC48(half+7,quarter*2-8,*(int *)(menu+0x20)-63,quarter*2+8,0x80696969,0);
    func_0028FC48(barX,quarter*2-6,*(int *)(menu+0x20)-65,quarter*2+6,0x80383838,0);
    width=((*(int *)(menu+0x20)-(half+74))*D_001A7B9C)/1024;
    texture=func_0028E588(0xe99d,9);
    func_0028F788(texture,barX*16,(quarter*2-6)*16,(half+width+8)*16,(quarter*2+5)*16,0,160,496,336,128);
    row=quarter*3-8;color=0x8020ffff;if (*(int *)(menu+0x40)!=2) color=0x80ffa888;
    func_0027F980(labelX,row,color,(u8 *)func_00288FB8(0x2f11),-1);
    func_0027F538(half+8,row,0x80ffa888,(u8 *)func_00288FB8(D_001A7B98?0x2f13:0x2f12),-1);
    func_0027C660();return 2;
}
