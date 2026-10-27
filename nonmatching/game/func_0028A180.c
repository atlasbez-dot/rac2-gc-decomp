#include "include_asm.h"

typedef unsigned char u8;

/* The ring of the last seven recorded pairs: two parallel halfword tables, a
   count and the index of the oldest entry. */
extern short D_001B1848[];
extern short D_001B1858[];
extern u8 D_001B1866;
extern u8 D_001B1867;

/* Records the pair (a, b) unless a is already in the ring or the ring is full. */
void func_0028A180(int a, int b)
{
    int i;
    short *q;

    if (D_001B1866 < 7) {
        for (i = D_001B1866 - 1; i >= 0; i--) {
            if (D_001B1848[(D_001B1867 + i) % 7] == a)
                return;
        }
        D_001B1848[(D_001B1867 + D_001B1866) % 7] = a;
        q = D_001B1858;
        q[(D_001B1867 + D_001B1866) % 7] = b;
        D_001B1866++;
    }
}
