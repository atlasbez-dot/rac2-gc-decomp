/* 0 of 1 places match - last line: 01_oozla: 240 bytes, expected 248
   The body is recovered: the state word at 0x68, the object word at 0x50, the
   0xAA half-word test against the state's 0x54 word and the 0x20 state byte
   (0xFE and 0xFD go to func_0029F338, the rest runs the body), the call to
   func_0029FCC0 (skipped when the state's 0x5C word is -1), the call to
   func_002A9640, the 36-byte record copied field by field from the result
   (the 0x2C float times the state's 0x58 float) and the call to func_002A8E20
   that takes it; the state's 0xA8 byte ends up 0xFF.  What is left: the last
   guard is retail's branch-likely `bnel $v1,$v0` (to the body, with the
   state's 0x5C word in its annulled slot) where this cc1 emits a plain `beq` to
   the call, and the 16-byte copy is materialised in retail
   (`addiu $v1,$a2,0x10` then `lq $v0,0($v1)`) where this cc1 folds the offset
   into the load (`lq $v0,0x10($a0)`) - the CSE tie of docs/COMPILER-NOTES.md.
   Spellings measured for the guard: the positive and the negated condition,
   the empty then arm, the inverted test, the call in the then arm and in the
   else arm, and the record written inside and outside the body (the last one
   gives the 252-byte candidate, four bytes over).  A `||` chain of two tests is
   what makes this cc1 emit a branch-likely form at all, but this guard is a
   four-term chain with no such shape. */

#include "include_asm.h"
#include "common.h"

typedef unsigned int TI128 __attribute__((mode(TI)));

extern void func_0029F338(void *);

extern void func_0029FCC0(void *, int, void *);

extern void *func_002A9640(void *, int, int);

extern void func_002A8E20(void *, void *);

typedef struct {
    TI128 f00;
    u32 f10;
    u32 f14;
    u8 f18;
    u8 f19;
    u16 f1A;
    f32 f1C;
    u32 f20;
} L01_003A6350_Params;

void func_L01_003A6350(u8 *arg0) {
    u8 *s0 = *(u8 **)(arg0 + 0x68);
    u8 *a0 = *(u8 **)(s0 + 0x50);
    L01_003A6350_Params p;
    void *r;

    if (a0 != 0 && *(s16 *)(a0 + 0xAA) == *(s32 *)(s0 + 0x54) &&
        a0[0x20] != 0xFE && a0[0x20] != 0xFD) {
        if (*(s32 *)(s0 + 0x5C) != -1) {
            func_0029FCC0(*(u32 *)(s0 + 0x50), *(s32 *)(s0 + 0x5C), arg0 + 0x10);
        }
        r = func_002A9640(arg0, -1, 0);
        if (r != 0) {
            p.f00 = *(TI128 *)((u8 *)r + 0x10);
            p.f10 = *(u32 *)((u8 *)r + 0x20);
            p.f14 = *(u32 *)((u8 *)r + 0x24);
            p.f18 = ((u8 *)r)[0x28];
            p.f19 = ((u8 *)r)[0x29];
            p.f1A = *(u16 *)((u8 *)r + 0x2A);
            p.f1C = *(f32 *)((u8 *)r + 0x2C) * *(f32 *)(s0 + 0x58);
            p.f20 = *(u32 *)((u8 *)r + 0x30);
            func_002A8E20(*(u32 *)(s0 + 0x50), &p);
        }
        arg0[0xA8] = 0xFF;
    } else {
        func_0029F338(arg0);
    }
}
