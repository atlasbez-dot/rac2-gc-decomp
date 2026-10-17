/* func_L23_00418FD0 (160 bytes, 1 place) -- measured 0 of 1, "instruction at +0xc differs".
   (Recipe kept from wave 9 worker 16; not re-measured in wave 6.)

   This cc1 folds `state + 0x230 + arg1*4` into `addiu $a1,$a1,0x230` (the offset added
   to the INDEX), where retail adds it to the base:
     lw $v0,0x68($a0) ; addiu $v0,$v0,0x230 ; addu $s0,$v0,$a1
   `(s32 *)(state + 0x230) + arg1` is not enough to force the base add.
   The two absolute constants must come out as lui/addiu (the "unknown symbol" form) and
   not lui/ori, which naming D_002595C8 and D_001FF300 does give.
   func_L23_00419070(u64, s32), the second case of family 06b1995b, is already matched.
*/

extern unsigned char D_002595C8[];
extern unsigned char D_001FF300[];

typedef unsigned long long u64;
typedef int s32;

extern s32 func_L23_00419070(u64, s32);

s32 func_L23_00418FD0(char *arg0, s32 arg1, s32 arg2) {
    char *state = *(char **)(arg0 + 0x68);
    s32 *slot = (s32 *)(state + 0x230) + arg1;

    if (func_L23_00419070(*(u64 *)(D_002595C8 + slot[0] * 16), arg2) != 0)
        return 0;
    func_L23_00419070(*(u64 *)(D_002595C8 + slot[0] * 16 + 8), arg2);
    return **(s32 **)(D_001FF300 + slot[0] * 4) - 1;
}
