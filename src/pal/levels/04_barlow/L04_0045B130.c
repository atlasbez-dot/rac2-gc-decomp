#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
extern u8 D_L04_001395C7;
extern u8 D_L04_002CA518;
extern void func_0029F338(void *a0);
extern int func_002B38B8(u8 *a0);
extern void func_002A0430(u32 a0);
extern s32 func_00288AA0(u8 *a0, s32 a1);
extern s32 func_00288BE8(void *a0);
extern void func_002F5CC8(void);
extern u8 D_0019B2E8[];
extern int D_001A79F0 __attribute__((sda));
extern int D_L04_001B24DC __attribute__((sda));
extern u8 D_L04_001BF880[];
extern u8 D_L04_001B12B0[] __attribute__((sda));
extern u8 D_L04_001B12E8[] __attribute__((sda));
extern u8 D_L04_001B1300[] __attribute__((sda));
extern u8 D_L04_001B1330[] __attribute__((sda));
extern u8 D_L04_001B1348[] __attribute__((sda));
extern u8 D_L04_001B3280[] __attribute__((sda));
extern u8 D_L04_001B32B0[] __attribute__((sda));
extern u8 D_L04_001B32E0[] __attribute__((sda));
extern u8 D_L04_001B3300[] __attribute__((sda));
extern u8 D_L04_001B3320[] __attribute__((sda));
extern u8 D_L04_001B3330[] __attribute__((sda));
extern u8 D_L04_001B3360[] __attribute__((sda));
extern u8 D_L04_001B3378[] __attribute__((sda));
extern u8 D_L04_001B33A0[] __attribute__((sda));
extern u8 D_L04_001B33B0[] __attribute__((sda));
extern u8 D_L04_001B33B8[] __attribute__((sda));
extern u8 D_L04_001B33D8[] __attribute__((sda));
extern u8 D_L04_001B33E8[] __attribute__((sda));
extern u8 D_L04_001B3418[] __attribute__((sda));
extern u8 D_L04_001B3430[] __attribute__((sda));
extern u8 D_L04_001B3458[] __attribute__((sda));
extern u8 D_L04_001B3468[] __attribute__((sda));
extern u8 D_L04_001B3470[] __attribute__((sda));
extern u8 D_L04_001B3474[] __attribute__((sda));
extern u8 D_L04_001B3478[] __attribute__((sda));
extern u8 D_L04_001B347C[] __attribute__((sda));
extern u8 D_L04_001B3480[] __attribute__((sda));
extern u8 D_L04_001B3484[] __attribute__((sda));
extern u8 D_L04_001B3488[] __attribute__((sda));
extern u8 D_L04_0026D370[];
extern u8 D_L04_0026D3E0[];
extern u8 D_L04_0026D490[];
extern u8 D_L04_0026D4F0[];
extern u8 D_L04_002CA3E0[];
extern u8 D_L04_002CA438[];

/* Starts the object's encounter state and, once it is running, hands the level's
   camera table the object's slot and asks the frame helpers to update it. */
void func_PAL_L04_0045B130(u8 *a0) {
    u32 *a1 = *(u32 **)(a0 + 0x68);

    if (a0[0x20] == 0) {
        if (D_0019B2E8[a0[0xB0] + D_001A79F0 * 16] & 0x80) {
            func_0029F338(a0);
            return;
        }
        a0[0x20] = 1;
    }
    if (a0[0x20] == 1) {
        if (func_002B38B8((u8 *)(D_L04_001B24DC + (*a1 << 8)))) {
            func_002A0430(a0[0xB0]);
            func_00288AA0(D_L04_001BF880, 0x38);
            func_00288BE8(D_L04_001BF880);
            func_002F5CC8();
            func_0029F338(a0);
        }
    }
}

INCLUDE_ASM("asm/pal/levels", func_PAL_L04_0045C268);
