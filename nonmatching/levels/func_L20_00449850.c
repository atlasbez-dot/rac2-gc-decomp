/* Best attempt for func_L20_00449850 (404 bytes, 1 place) - NOT MARKED.
   G8: this body reaches $gp-relative data (D_L20_001B23E0, D_L20_001B23E4,
   D_L20_001B2AC8) and needs the -G8 profile, so it belongs in the -G8
   sibling of its unit (src/levels/20_yeedil/L20_00449178-g8.c), not in
   L20_00449178.c.

   last check.py line: "20_yeedil: 396 bytes, expected 404"
   (8 bytes short: this cc1 needs two more callee-saved registers than
   retail, so the frame is 0x30 against retail's 0x20).

   The shape is right - the two-mode dispatch, the mode 0 reset block, the
   mode 2 call, the $gp and absolute reads of the same word (0x001B2AC8),
   the float path and the two tail calls are all the retail instructions.
   What differs:

   - the constant 1: retail materialises it three times ($v0 for the
     "mode == 1" test, $a1 for the state+0x24 store, $v0 for the
     state+0xAC store); this cc1 CSEs the two stores' 1 into one value
     that is live across the f_00339E70 call, so it lands in $s2 and the
     frame grows by the $s2 save.
   - the same happens with a float: retail has no FPR save at all, this
     cc1 keeps one in $f20.
   - the branch order around the mode tests differs: retail tests
     "mode == 1" first, then "mode >= 2", then "mode == 0", and reuses
     the "mode < 2" value ($v0 = 0) for the "mode == 2" test, which is
     a comparison the source can never make true on that path.

   Tried, all landing on the same 396 bytes: the mode 0 block before and
   after the mode 2 block, the float result in a variable and used
   directly, the "1" written as a cast, the state+0xAC word read twice
   (as retail does) and through a variable, and the mode dispatch written
   as a switch. */

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef int TI128 __attribute__((mode(TI)));

extern int D_L20_001A8F00 __attribute__((nosda));

extern float D_L20_001B23E0 __attribute__((sda));

extern float D_L20_001B23E4 __attribute__((sda));

extern int D_L20_001B2AC8 __attribute__((sda));

extern int D_1B2AC8 __attribute__((nosda));

extern void func_L20_00449A78(char *);

extern void func_L20_00449BB0(char *);

extern void func_L01_0031AB20(char *, char *, int, float, float, float);

extern void func_002A89A8(char *, char *, float);

extern float func_00282C48(float);

extern void func_00282948(char *);

void func_L20_00449850(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);
    u8 mode;
    int v;

    if (D_L20_001A8F00 != 2) {
        if (*(u8 *)(arg0 + 0x20) != 1) {
            func_L20_00449A78(arg0);
        }
    }
    mode = *(u8 *)(arg0 + 0x20);
    if (mode == 1) {
        return;
    }
    if (mode == 0) {
        *(u32 *)(state + 0x70) |= 6;
        *(float *)(state + 0x88) = D_L20_001B23E4;
        *(float *)(state + 0x20) = 1.0f;
        *(u16 *)(state + 0x24) = 1;
        *(float *)(state + 0x84) = D_L20_001B23E0;
        func_L20_00449A78(arg0);
        return;
    }
    if (mode == 2) {
        func_L01_0031AB20(arg0, state + 0x50, *(int *)(state + 0xA0), 0.0f, 0.5f,
                      0.6f);
    }
    v = D_L20_001B2AC8;
    if (*(int *)0x18A3E0 != (int)arg0) {
        *(int *)(state + 0xAC) = 1;
        v = D_1B2AC8;
    }
    if ((v & 0xF) == (((int)arg0 >> 8) & 0xF)) {
        func_002A89A8(arg0 + 0x10, 0, 0.5f);
        if (5.0f < func_00282C48(*(float *)(arg0 + 0x18) - 0.5f)) {
            goto L499B8;
        }
    }
    if (*(int *)(state + 0xAC) != 0) {
        func_00282948(state + 0xA8);
        if (*(int *)(state + 0xAC) != 0) {
            goto L499B8;
        }
        goto L499C8;
    }
L499C8:
    func_L20_00449BB0(arg0);
    return;
L499B8:
    func_L20_00449AE8(arg0);
}
