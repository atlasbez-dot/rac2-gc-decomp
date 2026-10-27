#include "include_asm.h"

typedef unsigned char u8;

extern u8 *D_L14_001B259C;
extern void func_L03_004199F0(u8 *);
extern int func_L02_0032EDD8(int, u8 *, int, int *);

/* Sets or clears the link flag between two entries of the object's table:
   finds the slot of key a1 and of key a2, then marks the matching neighbour
   byte in each slot's four-byte list. */
void func_L14_00420B10(int index, int a1, int a2, int set)
{
    u8 *obj = D_L14_001B259C + (index << 8);
    u8 *rec = *(u8 **)(obj + 0x68);
    u8 *tab;
    u8 *p;
    int slot[2];
    int i;
    int k0;
    int k1;

    if (obj[0x20] == 0)
        func_L03_004199F0(obj);
    slot[0] = -1;
    slot[1] = -1;
    if (func_L02_0032EDD8(a1, rec + 0x80, *(int *)(rec + 0x480), &slot[0]) == 0)
        return;
    if (func_L02_0032EDD8(a2, rec + 0x80, *(int *)(rec + 0x480), &slot[1]) == 0)
        return;
    if (slot[0] == slot[1])
        return;
    k0 = slot[0];
    k1 = slot[1];
    tab = rec + 0x84;
    p = tab + (k0 << 5);
    for (i = 0; i < 4; i++) {
        u8 b = p[i];

        if ((b & 0x7F) == k1) {
            if (set != 0)
                p[i] = b | 0x80;
            else
                p[i] = b & 0x7F;
        }
    }
    p = tab + (slot[1] << 5);
    k0 = slot[0];
    for (i = 0; i < 4; i++) {
        u8 b = p[i];

        if ((b & 0x7F) == k0) {
            if (set != 0)
                p[i] = b | 0x80;
            else
                p[i] = b & 0x7F;
        }
    }
}
