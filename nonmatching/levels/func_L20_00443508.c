/* near-miss: func_L20_00443508 (20_yeedil, 148 bytes).
   Candidate is 136 bytes: the guard chain and all four call shapes are the ones retail
   uses, but the three early `return 0` arms collapse to three words fewer than retail's
   (retail materialises the return-zero constant in each branch's delay slot). The head
   load and the 0x1FF/0x200/0x1233 tests are the ones the disassembly shows. */
#include "common.h"

extern s32 func_L00_00329520(char *, s32);
extern s32 func_00312B58(char *);
extern s32 func_L03_003CA138(char *);
extern s32 func_L20_00449AD8(char *);

s32 func_L20_00443508(char *arg0, char *arg1)
{
    char *state = *(char **)(arg0 + 0x68);
    s16 v;

    if (func_L00_00329520(arg1 + 0x10, *(s32 *)(state + 0x220)) == 0)
        return 0;
    v = *(s16 *)(arg1 + 0xAA);
    if (v < 0x1FF)
        return 0;
    if (v < 0x201)
        return func_00312B58(arg1) == 0;
    if (v != 0x12D3)
        return 0;
    if (func_L03_003CA138(arg1) != 0)
        return 0;
    if (func_L20_00449AD8(arg1) != 0)
        return 0;
    return 1;
}
