/* func_L10_004184F0, 140 bytes, 1 placement.  Nearest: exact 140 bytes, 6 differing words
   (the first at +0x40).
   func_37BA88(a0) result -> +0x148 = 2, func_37CCB0(a0, 1), then the state pointer
   *(a0+0x68): +0x268 = -1, +0x180 = 2.0f, a0+0x2C = 0.16f, a0+0x20 = 1, a0+0x30 = 0xFF,
   a0+0x32 = 0x1FF and a0+0x34 |= 0x100.  Retail materialises the two byte constants as
   $a1 = 1 then $a0 = 0xFF and stores 0x20, 0x30, 0x32, 0x34 in ascending order; this cc1
   always assigns $a0 = 1 / $a1 = 0xFF and schedules the 0x34 read-modify-write before the two
   byte stores.  Four source orders (0x20 first, 0x30 first, flag word as one s32, RMW first)
   all give the same six words. */

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;
typedef int s32;

extern char *func_37BA88(char *a0);
extern void func_37CCB0(char *a0, int a1);

void func_L10_004184F0(char *a0)
{
    char *s1 = *(char **)(a0 + 0x68);

    *(s32 *)(func_37BA88(a0) + 0x148) = 2;
    func_37CCB0(a0, 1);
    *(s32 *)(s1 + 0x268) = -1;
    *(f32 *)(s1 + 0x180) = 2.0f;
    *(f32 *)(a0 + 0x2C) = 0.16f;
    *(u8 *)(a0 + 0x20) = 1;
    *(u8 *)(a0 + 0x30) = 0xFF;
    *(u16 *)(a0 + 0x32) = 0x1FF;
    *(u16 *)(a0 + 0x34) |= 0x100;
}
