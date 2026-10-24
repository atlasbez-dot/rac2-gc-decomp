/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections.
 * Reported final C / retail: 732 / 884 bytes; size equality is not a match.
 * us: 0/28 placements; 732/884 bytes.
 * us2: not run after us mismatch; no exact candidate.
 * pal: not run after us mismatch; no exact candidate.
 * Residual: The full texture-load state machine is retained.94D80 returns a 64-bit TEX0 value and is declared accordingly.29D0E0 has no live incoming argument after its initial dead read. Equivalent load branches are combined here, producing a smaller body.
 * Reopening condition: Recover the original load-branch structure and pointer lifetimes while preserving the64-bit TEX0 return and real relocation inputs.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Not matched. boot: 732 bytes, expected 884.
 * Profile: -O2 -G0 -ffunction-sections
 * The full texture-load state machine is retained.94D80 returns a 64-bit TEX0 value and is declared accordingly.29D0E0 has no live incoming argument after its initial dead read. Equivalent load branches are combined here, producing a smaller body.
 * Reopen: Recover the original load-branch structure and pointer lifetimes while preserving the64-bit TEX0 return and real relocation inputs.
 * US placement check: 0/28. No linked-build or runtime claim.
 */
#include "common.h"
extern u8 D_001F2840[],D_001C4FA0[];
extern int D_0013953C,D_00139544,D_0014B8AC,D_0014D11C;
extern u8 D_00139410[];
extern s16 D_001A63AC;
extern int func_002DE6F0(int),func_002DE750(int),func_002DE7A0(int),func_002B7B18(int,int,int),func_00282A18(int);
extern void func_0029D4D0(void *,void *),func_0029D0E0(void);
extern u64 func_00294D80(int,int,void *,void *,int,int);
int func_002D9DA0(u8 *menu)
{
    int index,mode,base,offset,accepted,logWidth,logHeight;
    int *row;
    u32 flags=*(u32 *)(menu+0x34);
    u8 *owner,*buffer;
    if (flags&1) {index=*(int *)(menu+0x58);if (index==-1) return 0;}
    else {
        index=*(int *)(D_001C4FA0+0x230);
        if (!(flags&2)) {
            owner=*(u8 **)(*(u8 **)(D_001F2840+0x14)+0xe8);
            if (flags&4) index=*(int *)(owner+0x3c);
            else {
                index=*(int *)(owner+0x40);if (index<0) index=0;
                if (flags&0x100) {
                    if (index>4) index=4;
                    if (D_0013953C<3 && D_00139544<0 && *(int *)(D_001F2840+0x164)>10) {
                        if (*(int *)(menu+0x44)==-1) *(int *)(menu+0x44)=0;
                        index=*(int *)(D_00139410+index*28);
                    } else *(int *)(menu+0x44)=-1;
                }
            }
        }
    }
    mode=*(int *)(menu+0x44);
    if (mode==1 || mode==3) {
        if (!D_001A63AC && (!(*(u32 *)(menu+0x34)&0x40000) || *(int *)(menu+0x5c)>4)) {
            func_002DE7A0(*(int *)(menu+0x48));
            buffer=*(u8 **)(menu+0x48);
            if (*(u32 *)(menu+0x34)&0x20) {func_0029D4D0(buffer+*(int *)(menu+0x60),buffer);*(int *)(menu+0x60)=0;buffer=*(u8 **)(menu+0x48);}
            logWidth=func_00282A18(*(int *)(buffer+8));logHeight=func_00282A18(*(int *)(buffer+12));
            *(u64 *)(D_001C4FA0+0x268)=func_00294D80(logWidth,logHeight,buffer+0x20,buffer+0x420,*(int *)(D_001C4FA0+0x250),*(int *)(D_001C4FA0+0x254));
            func_0029D0E0();*(int *)(menu+0x5c)=0;*(int *)(menu+0x44)=2;return 0;
        }
        goto age;
    }
    if (mode!=0 && mode!=2) return 0;
    if (index==*(int *)(menu+0x50) || !*(int *)(menu+0x48) || D_001A63AC) goto age;
    row=(int *)(*(u8 **)(menu+0x30)+index*8);if (!row[1]) goto age;
    buffer=*(u8 **)(menu+0x48);
    if (*(u32 *)(menu+0x34)&0x20) {offset=func_002DE6F0((int)buffer)-row[1]*2048;*(int *)(menu+0x60)=offset;buffer+=offset;}
    if (*(u32 *)(menu+0x34)&0x10000) base=D_0014D11C;else base=D_0014B8AC;
    accepted=func_002B7B18((int)buffer,row[0]+base,row[1]);
    if (!accepted) *(int *)(menu+0x44)=-1;
    else {func_002DE750(*(int *)(menu+0x48));*(int *)(menu+0x50)=index;++*(int *)(menu+0x44);}
    *(int *)(menu+0x5c)=0;return 0;
age:
    if (++*(int *)(menu+0x5c)>256) *(int *)(menu+0x5c)=256;
    return 0;
}
