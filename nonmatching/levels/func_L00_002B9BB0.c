/* Retained plain-C attempt: 160/168 bytes; first difference +0x0.
 * us: 0/27, pal: 0/27, us2: 0/27.
 * Profile: -O2 -G0 -ffunction-sections -g.
 * The resident high half is not retained across the call, shrinking the frame and removing the second base completion. Corrected stale D_00188860 to the measured D_00188660 and replaced the stale func_35F3A8 alias with canonical func_002E5CF8(int,int,object). Next: lifetime evidence for the shared high half.
 */
#include "include_asm.h"

extern char D_00189E20_2[];
extern char D_00188660[];
extern int func_002E5CF8(int index, int mode, void *object);

void func_L00_002B9BB0(int index, int wanted, int handle)
{
    char *base = D_00189E20_2;
    int *slot = (int *)(base + 0x242C) + index;
    char *record = D_00188660 + *slot * 0x70;

    if (*(int *)(record + 0x88) != wanted || *(unsigned char *)(record + 0x74) == 0)
        *slot = func_002E5CF8(handle, 4, (void *)wanted);
    *(int *)(D_00189E20_2 + 0x2450 + index * 4) = wanted;
}
