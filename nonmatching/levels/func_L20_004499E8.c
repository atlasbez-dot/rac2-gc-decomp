/* 0 of 1 places match - last line: 20_yeedil: 132 bytes, expected 140
   Every retail instruction is present in retail's order; the eight bytes are exactly the
   two `addiu` retail pays to materialise the two TI128 destinations, which this cc1 folds
   into the stores (`sq $zero,0x50($t0)` and `sq $v0,0x10($a3)` for retail's
   `addiu $a3,$a3,0x50; sq $zero,0x0($a3)` and `addiu $t0,$a0,0x10; sq $v0,0x0($t0)`) -
   the func_L11_003973F8 wall. A named TI128* per destination, `volatile` on both
   destinations (the spelling the matched src/game/002A7750.c uses) and a
   `__builtin_memcpy(arg0 + 0x10, arg2, 16)` (200 bytes) all still fold. Allocation differs
   too: this cc1 copies arg0 into $a3 and keeps the state in $t0 where retail keeps arg0 in
   $a0 and loads the state into $a3. Measured while here: an s32 field stored from
   `(s32)(float)` keeps the value in the FP register and comes out `cvt.w.s` + `swc1`, the
   shape retail has, where a float field with a `(float)(int)` cast round-trips through
   `mfc1`/`mtc1` (148 bytes). */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern float D_L20_001B23E8 __attribute__((sda));

extern void func_002A7750(char *, int, int);

/* Zeroes the state's 0xA4/0xA8/0xAC triple (arg1, D_L20_001B23E8 * 60 as a frame count,
   zero), clears the 0x34 flags' 0x40 bit, copies the caller's 16 bytes into arg0 + 0x10,
   nudges arg0's 0x18 float by 0.5f, zeroes the state's 16 bytes at 0x50 and asks for
   message 2-(-1). */
void func_L20_004499E8(char *arg0, char *arg1, char *arg2)
{
    char *state = *(char **)(arg0 + 0x68);

    *(s32 *)(state + 0xA8) = (s32)(D_L20_001B23E8 * 60.0f);
    *(char **)(state + 0xA4) = arg1;
    *(s32 *)(state + 0xAC) = 0;
    *(u16 *)(arg0 + 0x34) = (*(u16 *)(arg0 + 0x34) & 0xFFBE) | 0x1000;
    *(s32 *)(arg0 + 0x98) = *(s32 *)(*(char **)(arg0 + 0x24) + 0x10);
    *(TI128 *)(arg0 + 0x10) = *(TI128 *)arg2;
    *(f32 *)(arg0 + 0x18) = *(f32 *)(arg0 + 0x18) + 0.5f;
    *(TI128 *)(state + 0x50) = 0;
    func_002A7750(arg0, 2, -1);
}
