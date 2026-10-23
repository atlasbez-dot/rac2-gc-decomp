/* Retained C reconstruction: 228/240 bytes.
   Profile: -O2 -G0 -ffunction-sections.
   0/27 in us, pal and us2. Explicit countdown and reversed integer address addition still leave rotated increments and the counter/offset registers exchanged. The record table is D_00188660; the older draft named the wrong address.
   Reopen only with new source/type/lifetime evidence; bounded scheduling/profile variants did not close it. */

#include "include_asm.h"

typedef unsigned char u8;

extern char D_00189E20_2[];
extern char D_00188660[];
extern void func_002E59F8(int entry);

void func_L00_002A6708(void)
{
    char *base = D_00189E20_2;
    int *dst = (int *)(base + 0x242C);
    char *src = base + 0x2450;
    int i = 8;
    int offset = 0;

    do {
        int id = *(int *)(offset + (unsigned int)src);
        int cur = *dst;
        char *entry;

        if (id != 0) {
            if (cur == -1)
                goto clear;
            entry = D_00188660 + cur * 0x70;
            if (*(int *)(entry + 0x88) != id)
                goto clear;
        } else {
            if (cur == -1)
                goto clear;
            entry = D_00188660 + cur * 0x70;
            if (*(int *)(entry + 0x88) != *(int *)(base + 0x2290))
                goto clear;
        }
        if (*(u8 *)(entry + 0x74) == 0)
            goto clear;
        func_002E59F8(cur);
    clear:
        *dst = -1;
        dst++;
        offset += 4;
        i--;
    } while (i >= 0);
}
