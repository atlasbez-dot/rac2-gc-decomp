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
   `mfc1`/`mtc1` (148 bytes). 
   Second wave (20_yeedil, 2026-10-20) re-measured this one: the file has to be built
   with -G8 (the unit's -g8.c sibling) because the constant D_L20_001B23E8 is read
   through $gp (gp + 0x33F8 = 0x1B23E8); at -G0 the load comes out
   `lui $at ; lwc1 $f1,0x0($at)`. The `cvt.w.s` + `swc1` shape of the 0xA8 store is
   reproduced by `*(s32 *)(state + 0xA8) = (s32)(D * 60.0f);` - a float field with a
   `(float)(int)` cast round-trips through mfc1/mtc1 and is 16 bytes over. What is left
   is the allocation: retail gives $f0 to the loaded constant and $f1 to the 60.0f
   multiplier, this cc1 the opposite, keeps the state pointer in $a3 where retail
   loads it into $a3 from arg0 and keeps arg0 in $a0, and materialises the 0.5f early.
   Tried and not enough: eight source shapes (the union that reinterprets the int as a
   float, the int store, a float temporary for the constant, the multiplication written
   60.0f * D, the declaration order of the locals, the 16-byte copy with and without a
   temporary, the TI128 locals).*/
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
