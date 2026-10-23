/* Retained near miss: 252/252 bytes and 0 of 2 placements, in a unit of its own built
   -O2 -G0 -ffunction-sections -frac2-qcopy -mno-split-addresses (the file was
   src/levels/shared/L18_00427BE0-qcopy.c with that line in config/cflags.txt).
   The frame, the save order, the divmod, the two func_002A77E0 calls, the table index and
   both quadword copies match; what is left is the allocation of the table base against the
   object's third vector: retail keeps the base in $s0 and the vector in $s2, this cc1 keeps
   the vector in $s0 and the base in $s2, and materialises the base after the vector where
   retail materialises it before. The declaration order, the assignment order, a local for the
   base and an inline vector were all tried. */

#include "include_asm.h"

typedef unsigned char u8;

typedef signed int s32;

typedef int TI128 __attribute__((mode(TI)));

extern s32 D_L18_001B2348;

extern u8 D_L18_002BD9B0[];

extern s32 func_002A77E0(s32);

extern void func_00283098(void *, const void *, const void *);

extern void func_00282CC0(void *, void *, void *);

extern void func_L18_0043F040(u8 *);

void func_L18_0043EF40(u8 *obj) {
    u8 *state;
    u8 *dst;
    u8 *src;
    TI128 scratch;
    s32 i;
    s32 v = D_L18_001B2348;
    s32 r = v % 60;

    state = *(u8 **)(obj + 0x68);
    if (r) {
        /* the level's frame counter has not reached its turn yet */
    } else {
        *(s32 *)(state + 0x160) = func_002A77E0(6);
        *(s32 *)(state + 0x164) = func_002A77E0(6);
    }
    dst = obj + 0x10;
    src = obj + 0xC0;
    i = *(s32 *)(state + 0x160);
    func_00283098(&scratch, D_L18_002BD9B0 + i * 16, src);
    func_00282CC0(&scratch, dst, &scratch);
    *(TI128 *)(state + 0x10) = *(TI128 *)&scratch;
    i = *(s32 *)(state + 0x164);
    func_00283098(&scratch, D_L18_002BD9B0 + i * 16, src);
    func_00282CC0(&scratch, dst, &scratch);
    *(TI128 *)(state + 0xB0) = *(TI128 *)&scratch;
    func_L18_0043F040(obj);
}
