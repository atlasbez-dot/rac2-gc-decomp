#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;

extern u8 *D_L26_001B1C1C __attribute__((sda));

extern u16 *D_L26_001FA6E0[];

/* The walk below reads the group count and one word through $gp; the group table of id lists is
   absolute, and the entity base (D_L26_001B1C1C above, through $gp) is the bare `lui`/`lw` pair
   here, a second name sized over 8 bytes with `sda` in this -G8 unit. */
extern int D_L26_001B1C38 __attribute__((sda));

extern u8 *D_L26_001B1C1C_1[3] __attribute__((sda));

extern char D_L26_002967A0[];

extern int D_L26_001B0478 __attribute__((sda));

extern int D_L26_001B047C;

extern void func_00281A08(void *, int, void *, void *, int, int, int, int, float);

/* For every entity of the object's group, hands six slots of its private state (+0x80 and +0x100,
   the words at +0x190 and +0x194 and the float at +0x198) to the resident effect scheduler,
   together with the level's float template D_L26_002967A0 and the two words D_L26_001B0478 and
   D_L26_001B047C. */
void func_L26_003D4AE8(u8 *a0) {
    u16 *p;
    u8 *e;
    u8 *s;

    for (p = D_L26_001FA6E0[a0[0x21]];
         a0[0x21] != 0xFF && a0[0x21] <= D_L26_001B1C38 && p != 0 &&
         ((p != 0 && (short)p[-1] >= 0) || p == D_L26_001FA6E0[a0[0x21]]);
         p++) {
        e = D_L26_001B1C1C_1[0] + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        s = *(u8 **)(e + 0x68);
        func_00281A08(D_L26_002967A0, 6, s + 0x80, s + 0x100, *(int *)(s + 0x194),
                      *(int *)(s + 0x190), D_L26_001B0478, D_L26_001B047C, *(float *)(s + 0x198));
    }
}

/* Walks the record's live list and flags every entry whose id matches. */
INCLUDE_ASM("asm/levels", func_L26_003DC128);
