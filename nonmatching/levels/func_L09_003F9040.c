/* func_L09_003F9040, 200 bytes, 2 places (09_dobbo, 20_yeedil).
 * NEAR MISS - the candidate is retail's exact size and every instruction is right, but the
 * first block orders three of them differently: retail keeps the `lw` of D_001A79F0 right
 * after its `lui` and saves $s1 before copying the parameter into $s0, this cc1 puts the
 * load two words later (after the first save and the switch's first case value) and
 * copies the parameter before the second save.  The dispatch itself is exact: the `switch`
 * (its `default` written first, so the case blocks stay out of line and the conditional
 * jump to the next block survives) gives retail's `beq`/`beq`/`b` chain with the level's
 * word loaded in the second comparison's delay slot.
 *
 * What is needed: a source shape whose prologue keeps the %hi/%lo pair of the mode word
 * together and emits the two callee-saved saves before the parameter copy.  The shape here
 * is a `switch` on the mode word; an if/else-if chain with the same bodies gives the
 * right instruction sequence but a different block order (the first case becomes the
 * fall-through and the conditional jump to it is deleted).
 *
 * Drafts marked G8 need a `-g8.c` source unit when checked again: the level's four
 * packed words are read through $gp, so this unit must be built with -G8.
 */

#include "include_asm.h"

typedef unsigned int u32;

/* the resident mode word: read through its absolute address, not through $gp */
extern int D_001A79F0 __attribute__((nosda));

/* the level's four packed words, in small data */
extern u32 D_L09_001B0F64 __attribute__((sda));
extern u32 D_L09_001B0F68 __attribute__((sda));
extern u32 D_L09_001B0F6C __attribute__((sda));
extern u32 D_L09_001B0F70 __attribute__((sda));

extern void func_002A0488(char *object, int a, int b, int c);

/* Hands the mode's packed word to the colour setter and raises the object's dirty flag. */
void func_L09_003F9040(char *object)
{
    int mode = D_001A79F0;
    int mask;
    int packed;
    int word;

    switch (mode) {
    default:
        return;
    case 8:
        packed = D_L09_001B0F64;
        mask = (int)0xFF000000;
        if (packed & mask)
            func_002A0488(object, packed & 0xFF, (packed >> 8) & 0xFF,
                          (packed >> 16) & 0xFF);
        word = D_L09_001B0F68;
        break;
    case 0x14:
        packed = D_L09_001B0F6C;
        mask = (int)0xFF000000;
        if (packed & mask)
            func_002A0488(object, packed & 0xFF, (packed >> 8) & 0xFF,
                          (packed >> 16) & 0xFF);
        word = D_L09_001B0F70;
        break;
    }
    if (word & mask) {
        *(unsigned short *)(object + 0x34) |= 0x10;
        *(u32 *)(object + 0x78) = word;
    }
}
