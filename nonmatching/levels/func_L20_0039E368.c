/* func_L20_0039E368 (648 B, level 20 only): near miss, 3 instructions (argument-move order only).
 * M34 2026-10-26. Unit: src/levels/20_yeedil/L20_0039C448-g8.c (-O2 -G8 -ffunction-sections).
 * The computed goto through jtbl_002B4CA0 is now a real switch, one case per table entry
 * (1 -> return, 2..5 -> bodies, default -> func_L20_0039E770), case bodies in table-address
 * order with default before case 1 (retail 0x39E5CC, then the epilogue). The early exit
 * (D_L20_001A8F00 == 2 && D_L20_001BDCF0 >= 5) is one && test jumping to the shared
 * func_0029F338 tail. Every hex callee name is mapped through config/levels/functions.tsv.
 * Left: the three register moves before func_0032DA58 in case 5 come out a1, a0, a2(delay);
 * retail a2, a1, a0(delay). Same values; tried inline arg0 + 0x10 and a block-local pointer.
 * The previous historical variants are in git history (before M34).
 */
#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

extern void func_L20_0039E5F0(char *);
extern void func_L20_0039E770(char *);
extern s32 func_002B3868(char *);
extern void func_002A7470(char *, s32, s32, s32);
extern void func_0029FCC0(char *, s32, char *);
extern void func_0029FC20(char *, s32, char *);
extern void func_00282F20(char *, char *, float);
extern void func_L09_003AE8C8(char *, char *, char *, s32, s32, float, float, float, float);
extern void func_00282CF0(char *, void *, char *);
extern void func_0032DA58(char *, char *, char *, float);
extern void func_002A6C58(char *, s32, s32);
extern void func_0029F338(char *);

extern int D_L20_001A8F00;
extern int D_L20_001BDCF0 __attribute__((nosda));
extern int D_L20_001B2AC8;
extern void *D_L20_001B9FC0[];
extern float D_L20_001AED04 __attribute__((sda));
extern float D_L20_001AED08 __attribute__((sda));

void func_L20_0039E368(char *arg0)
{
    char bufA[0x10];
    char bufB[0x40];
    char bufC[0x10];
    char *state;
    u8 w;
    s32 mode;

    state = *(char **)(arg0 + 0x68);
    func_L20_0039E5F0(arg0);
    if (D_L20_001A8F00 == 2 && D_L20_001BDCF0 >= 5)
        goto finish;
    switch (*(u8 *)(arg0 + 0x20)) {
    case 2:
        if (func_002B3868(arg0) == 0) {
            w = *(u8 *)(arg0 + 0x31);
            goto L410;
        }
        if (*(u8 *)(arg0 + 0x43) != 0)
            func_002A7470(arg0, 0, 0, 0xA);
        w = *(u8 *)(arg0 + 0x31);
    L410:
        if (w == 0)
            break;
        if (*(u16 *)(arg0 + 0x96) < 0xB5)
            break;
        mode = 3;
        func_002A7750(arg0, mode, -1);
        break;
    case 3:
        if (func_002B3868(arg0) != 0) {
            if (*(u8 *)(arg0 + 0x43) != 1)
                func_002A7470(arg0, 1, 0, 0xF);
        }
        if ((D_L20_001B2AC8 & 0xF) != (((int)arg0 >> 8) & 0xF)) {
            w = *(u8 *)(arg0 + 0x31);
            goto L4FC;
        }
        func_0029FCC0(arg0, 2, bufA);
        func_0029FC20(arg0, 2, bufB);
        func_00282F20(bufC, bufB, D_L20_001AED04 * 0.016666668f);
        func_L09_003AE8C8(bufA, arg0, bufC, 1, 1, (float)*(u8 *)(state + 0x34),
                          D_L20_001AED08, 1.0f, 1.0f);
        w = *(u8 *)(arg0 + 0x31);
    L4FC:
        if (w == 0)
            goto L558;
        if (*(u16 *)(arg0 + 0x96) < 0xB5)
            break;
        mode = 2;
        func_002A7750(arg0, mode, -1);
        break;
    case 4:
        if (func_002B3868(arg0) != 0) {
            if (*(u8 *)(arg0 + 0x43) != 2)
                func_002A7470(arg0, 2, 0, 0xA);
        }
        if ((*(u8 *)(arg0 + 0x60) & 0x2) == 0)
            break;
    L558:
        mode = 2;
        func_002A7750(arg0, mode, -1);
        break;
    case 5:
        func_00282CF0(bufA, D_L20_001B9FC0, arg0 + 0x10);
        func_00282F20(bufA, bufA, 1.0f);
        func_0032DA58(arg0, arg0 + 0x10, bufA, 0.0f);
        func_002A6C58(arg0, 0, 3);
    finish:
        func_0029F338(arg0);
        return;
    default:
        break;
    case 1:
        return;
    }
    func_L20_0039E770(arg0);
}
