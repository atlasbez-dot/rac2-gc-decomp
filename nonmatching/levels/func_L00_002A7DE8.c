/* Retained C reconstruction: 120/120 bytes.
   Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
   0/27 in us, pal and us2; first bound difference +0x30. The grouped quadword copy is exact, but three indexed stores use different addu operand/register choices.
   Reopen only with new source/type/lifetime evidence; bounded scheduling/profile variants did not close it. */

#include "include_asm.h"
typedef int Quad __attribute__((mode(TI)));
extern char D_00189E20[];
extern void func_L00_002A7A10(void);
void func_L00_002A7DE8(Quad *src, int value, float first, float second)
{
    char *base = D_00189E20;
    char *ring = base + 0x2080;
    char *slot;
    int index = *(short *)(base + 0x2160);
    *(Quad *)(ring + index * 16) = *src;
    slot = (char *)((index << 2) + (unsigned int)base);
    *(int *)(slot + 0x2100) = value;
    slot = (char *)((*(short *)(base + 0x2160) << 2) + (unsigned int)base);
    *(float *)(slot + 0x2120) = first;
    slot = (char *)((*(short *)(base + 0x2160) << 2) + (unsigned int)base);
    *(float *)(slot + 0x2140) = second;
    func_L00_002A7A10();
    *(unsigned short *)(base + 0x2160) += 1;
}
