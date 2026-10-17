/* func_L18_003F7AB8 (196 bytes, 3 places) -- NEAR MISS, not integrated.  Needs the
   -G8 unit (the resident count word is lw 0x3848($gp)); the id table at
   0x001FB320 and the bank at 0x001B281C stay absolute.
   Walks the entry's 0x7FFF id list, calling func_L18_003F7A88 on each object, but
   re-validates the class and the list on every pass: the 0xFF class, the resident
   count, a null list and (for the terminator) the table slot all end the walk, and
   a non-terminating id whose slot still matches continues it.
   Both spellings tried (guards as a while condition and as a for(;;) with breaks)
   compile identically to 236 bytes against 196; the excess is structural - this
   cc1 keeps several copies of the 0xFF and table-slot guards in separate blocks
   where retail folds them into one chain that ends in the two annulled continue
   branches (bgezl/bgeql) into the walk step. */
#include "common.h"

extern u16 *D_L18_001FB320[];
extern s32 D_L18_001B281C;
extern s32 D_L18_001B2838 __attribute__((sda));
extern void func_L18_003F7A88(void *);

void func_L18_003F7AB8(u8 *a0)
{
    u16 *q;
    u8 *e;

    if (a0[0x21] == 0xFF)
        return;
    q = (u16 *)D_L18_001FB320[a0[0x21]];
    while (a0[0x21] != 0xFF && D_L18_001B2838 >= a0[0x21] && q != 0
           && ((s16)*(q - 1) >= 0 || q == (u16 *)D_L18_001FB320[a0[0x21]])) {
        e = (u8 *)(D_L18_001B281C + (*q & 0x7FFF) * 256);
        if (e == 0)
            break;
        func_L18_003F7A88(e);
        q++;
    }
}
