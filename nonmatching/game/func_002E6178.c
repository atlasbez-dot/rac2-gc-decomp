/* Retained complete manual C; no linked byte credit.
 * Profile: -O2 -G0 -ffunction-sections -fno-gcse
 * Compiled text: 816 bytes. us: 0/28, us2: 0/28, pal: 0/28.
 * Residual: The 0x60 frame agrees, but equipment-global address lifetime, count/array allocation and store scheduling differ.
 * Reopen: Recover original equipment/object field types and pointer lifetimes; previous direct indexing and allocation-result temporaries did not close the difference.
 */
#include "include_asm.h"
extern char *func_0029EFD0(int);
extern void func_002E6120(void);
extern char *D_00152C00;
extern unsigned int D_001A7AF0;
extern short D_001A8C28[],D_001A8C30[],D_001A8C38[],D_001A8C40[];
extern short D_001A8C48[],D_001A8C50[],D_001A8C58[];
extern char *D_00214920[];
#define H(p,o) (*(unsigned short *)((p)+(o)))
void func_002E6178(char *base)
{
    char **parts;
    char *state, *piece;
    unsigned int equipment;
    int chassis, partA, partB, partC, partD, partE, partF, count;
    if (!base) base=D_00152C00;
    func_002E6120();
    count=5;
    *(unsigned char *)(base+0x30)=255;
    parts=D_00214920;
    equipment=D_001A7AF0;
    chassis=(equipment>>2)&3;
    partA=(equipment>>4)&1;
    partB=(equipment>>6)&1;
    partC=(equipment>>7)&3;
    partD=(equipment>>9)&1;
    partE=(equipment>>10)&3;
    partF=(equipment>>14)&3;
    parts[0]=func_0029EFD0(D_001A8C28[chassis]);
    parts[1]=func_0029EFD0(D_001A8C28[chassis]);
    H(parts[1],0x34)|=0x8000;
    parts[2]=func_0029EFD0(D_001A8C30[partA]);
    parts[3]=func_0029EFD0(D_001A8C38[partB]);
    parts[4]=func_0029EFD0(D_001A8C38[partB]);
    H(parts[4],0x34)|=0x8000;
    if (D_001A8C40[partC]) {
        parts[5]=func_0029EFD0(D_001A8C40[partC]);
        parts[6]=func_0029EFD0(D_001A8C40[partC]);
        count=7;
        H(parts[6],0x34)|=0x8000;
    }
    parts[count++]=func_0029EFD0(D_001A8C48[partD]);
    piece=func_0029EFD0(D_001A8C48[partD]);
    parts[count++]=piece;
    H(piece,0x34)|=0x8000;
    parts[count++]=func_0029EFD0(D_001A8C50[partE]);
    piece=func_0029EFD0(D_001A8C50[partE]);
    parts[count++]=piece;
    H(piece,0x34)|=0x8000;
    if ((D_001A7AF0>>12)&1) parts[count++]=func_0029EFD0(0x10E2);
    if ((D_001A7AF0>>13)&1) parts[count++]=func_0029EFD0(0x10E4);
    if (partF) parts[count]=func_0029EFD0(D_001A8C58[partF]);
    if (*parts) {
        do {
            if (*(unsigned char *)(*parts+0x63)) (*parts)[0x63]=8;
            H(*parts,0x34)|=0x124;
            H(*parts,0x32)=0x1FF;
            state=*(char **)(*parts+0x68);
            *(char **)(state+8)=state+0x20;
            parts++;
        } while (*parts);
    }
    H(base,0x34)|=0x20;
    state=*(char **)(base+0x68);
    *(char **)(state+8)=state+0x20;
}
