/* 0 of 1 places match - last line: 01_oozla: 556 bytes, expected 552
   The four-arm switch, both argument lists and the tail are retail's; the object pointer
   and its 0x68 record land in $s1/$s0 instead of retail's $s0/$s1, and the speculative
   `lw -0x3B8($gp)` retail puts in the `beqz` delay slot is emitted later here (one extra
   instruction, 556 against 552). Below: the whole -G8 sibling source. */

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

/* The frame counter, the two size references and the countdown the level holds, read both
   through $gp and, for the counter, through its own absolute address. */
extern int D_L01_001B3468;

extern int D_001AEC38;

extern int D_L01_001AEC38 __attribute__((sda));

extern f32 D_L01_001B2090 __attribute__((sda));

extern f32 D_L01_001B208C __attribute__((sda));

extern int D_L01_001B3468_1[2] __attribute__((sda));

extern int D_L01_001B15E0 __attribute__((sda));

extern u8 D_L01_001A8F60[];

extern void func_002A7750(u8 *, int, int);

extern int func_002A9640(u8 *, int, int);

extern s32 func_002E5CF8(int, int, u8 *);

extern int func_002B3868(u8 *);

extern void func_002B0A68(u8 *, int, u8 *, int, f32, f32, f32, f32);

extern void func_L00_00326110(u8 *, int, f32);

extern int func_00282948(u8 *);

extern void func_0029F338(u8 *);

/* Runs the object's four-step placement: armed, waiting for the frame it is pinned to, the
   flash itself and the release. */
void func_L01_0040F118(u8 *a0) {
    u8 *q = *(u8 **)(a0 + 0x68);

    switch (*(u8 *)(a0 + 0x20)) {
    case 0:
        D_L01_001B3468 = 0;
        D_L01_001AEC38 = D_L01_001AEC38 + 1;
        func_002A7750(a0, 1, -1);
        break;
    case 1:
        if (func_002A9640(a0, 0x4010000, 0) != 0 && *(int *)(q + 0) == 0) {
            s32 n = D_001AEC38;

            func_002A7750(a0, 2, -1);
            D_L01_001AEC38 = n - 1;
        }
        *(u8 *)(a0 + 0xA8) = 0xFF;
        break;
    case 2:
        if (*(u8 *)(a0 + 0x31) != 0 && D_L01_001B2090 < 0.9f &&
            D_L01_001B208C < 0.9f && D_L01_001B3468_1[0] < D_L01_001B15E0)
            func_002B0A68(a0, 0x7F, D_L01_001A8F60, 0xFF, 8.0f, -6.0f, 8.0f, -6.0f);
        else
            func_002B0A68(a0, 0xD, D_L01_001A8F60, 0xFF, 8.0f, -6.0f, 8.0f, -6.0f);
        func_L00_00326110(a0, 4, 0.0f);
        func_002E5CF8(0, 0, a0);
        func_002A7750(a0, 3, -1);
        break;
    case 3:
        if (func_002B3868(a0) != 0) {
            *(u32 *)(q + 4) = 0x78;
            *(u8 *)(a0 + 0x31) = 0;
            *(u16 *)(a0 + 0x34) = *(u16 *)(a0 + 0x34) | 1;
            *(u32 *)(a0 + 0x98) = 0;
            D_L01_001B3468 = D_L01_001B3468 + 1;
            if (func_00282948(q + 4) != 0) {
                func_0029F338(a0);
                D_L01_001B3468_1[0] = D_L01_001B3468_1[0] - 1;
            }
        }
        break;
    }
}
