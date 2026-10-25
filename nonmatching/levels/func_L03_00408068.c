/* 0 of 2 places match - last line: 03_endako: instruction at +0x78 differs
   63 of 64 instructions. The switch dispatch, both stores at +0x7C and the whole second
   call's argument setup are retail's; only the `func_002E5CF8(0, 0, a0)` setup is
   ordered differently: retail emits `a0=0`, `a1=0`, the call, then `a2=$s0` in the delay
   slot, this C emits `a2=$s0` first and `a1=0` in the delay slot. Four source forms
   (local pointer, literal 0s, `char *` cast, nested call) and `-fno-schedule-insns2`
   were measured; the flag repairs this call and breaks the top of the function and the
   second call, so the profile is not the lever. Below: the whole -G8 sibling source. */

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

extern void func_002A7750(u8 *, int, int);

/* The two halfwords a spawn stores at +0x7C and the four floats and the word the countdown
   spawn passes on, all read through $gp. */
extern unsigned short D_L03_001B160C __attribute__((sda));

extern unsigned short D_L03_001B1610 __attribute__((sda));

extern int D_L03_001B1614 __attribute__((sda));

extern f32 D_L03_001B1618 __attribute__((sda));

extern f32 D_L03_001B161C __attribute__((sda));

extern f32 D_L03_001B1620 __attribute__((sda));

extern f32 D_L03_001B1624 __attribute__((sda));

extern u8 D_L03_001A8F20[];

extern int func_002A9640(u8 *, int, int);

extern void func_002E5CF8(int, int, u8 *);

extern void func_002B0A68(u8 *, int, u8 *, int, f32, f32, f32, f32);

extern int func_002B3868(u8 *);

extern void func_L00_003294F0(u8 *, int);

/* Advances the object's spawn state: state 0 arms the countdown with the shared halfword,
   state 1 starts it once the resident query answers and stores the particle description,
   state 2 finishes it and puts the object into step 0xF. */
void func_L03_00408068(u8 *a0) {
    switch (*(u8 *)(a0 + 0x20)) {
    case 0:
        *(unsigned short *)(a0 + 0x7C) = D_L03_001B160C;
        func_002A7750(a0, 1, -1);
        break;
    case 1:
        if (func_002A9640(a0, 0x10000, 0)) {
            func_002E5CF8(0, 0, a0);
            func_002B0A68(a0, D_L03_001B1614, D_L03_001A8F20, 0xFF,
                          D_L03_001B1618, D_L03_001B161C, D_L03_001B1620,
                          D_L03_001B1624);
            func_002A7750(a0, 2, -1);
        }
        break;
    case 2:
        if (func_002B3868(a0)) {
            *(unsigned short *)(a0 + 0x7C) = D_L03_001B1610;
            func_L00_003294F0(a0, 1);
            *(u32 *)(a0 + 0x9C) = 0xF;
        }
        break;
    }
}
