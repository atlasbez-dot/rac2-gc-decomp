/* func_L05_00420E28, 388 bytes, 1 placement (level 05).  -G8 unit, 388 bytes like retail.
   M30: the callees are the real ones now (the old draft named them by level-0
   addresses), the count is a counted for loop (retail's blezl entry test and the
   reversed counter), and the record at 0x221D10 is an int array.  Left: the loop
   reads the record's high part from its own `lui $s2` where retail copies the
   outer one (`daddu $s2,$s4`), and the base, the owner and the id constant sit
   in $s6/$s5/$s4 here against retail's $s4/$s6/$s5.  Queued for the permuter. */

#include "include_asm.h"
#include "common.h"

extern int func_00282948(void *);
extern void func_002B7320(void);
extern void func_L05_0037B210(void);
extern void func_L05_00379F18(int);
extern u8 **func_L05_00379EB8(void);
extern s32 func_L00_004272A0(void);
extern void func_L05_0037B280(char *, int);
extern void func_L05_0037CEE0(void *, void *, f32);
extern void func_L05_0037D608(void *, void *, f32);
extern void func_L05_00420788(u8 *a0, s32 a1);
extern void func_L05_004209D8(u8 *a0, s32 a1);

extern s32 D_001B1364 __attribute__((sda));
extern s32 D_L05_001B2048 __attribute__((sda));
extern int D_L05_00221D10[];
extern s32 D_L05_001B3550;
extern u8 *D_001B2614;

/* Arms the timer once, then points every live 0x10F5 object at the current record and hands
   over to the next state when the record is done (or the timer runs out). */
void func_L05_00420E28(u8 *arg0)
{
    u8 *owner = *(u8 **)(arg0 + 0x68);
    u8 **list;
    s32 count;
    s32 i;

    func_00282948(&D_L05_001B3550);
    if (D_001B1364 == 0) {
        D_L05_00221D10[11] = 0;
        D_L05_001B3550 = 0x1C20;
        *(s32 *)(owner + 0x44) = 0x1C20;
        D_001B1364 = 1;
        func_002B7320();
    }
    func_L05_0037B210();
    func_L05_00379F18(0);
    list = func_L05_00379EB8();
    count = func_L00_004272A0();
    for (i = 0; i < count; i++) {
        if (*(s16 *)(list[i] + 0xAA) == 0x10F5) {
            func_L05_0037B280((char *)list[i], 1);
            func_L05_0037CEE0(list[i], D_001B2614 + (D_L05_00221D10[0] << 7) + 0x30, 64.0f);
            func_L05_0037D608(list[i], D_001B2614 + (D_L05_00221D10[0] << 7) + 0x30, 64.0f);
        }
    }
    if (D_L05_00221D10[4] == 0 && D_L05_001B2048 >= 6) {
        func_L05_00420788(arg0, 1);
        return;
    }
    if (func_00282948(owner + 0x44) != 0)
        func_L05_004209D8(arg0, 1);
}
