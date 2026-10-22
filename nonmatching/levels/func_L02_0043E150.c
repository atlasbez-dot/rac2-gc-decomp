/* func_L02_0043E150 - 848 bytes, 1 place (level 02): the same size as retail's; 4 of 212 words
   differ, and only in register numbers. They are the two 16-byte clears of stack locals,
   `por $r,$zero,$zero` ... `sq $r,0x60($sp)` (+0x84/+0x8C) and the same at 0x70($sp)
   (+0x244/+0x258): retail uses $t4 for the first and $v0 for the second, this C gives $v0 and
   $t2. Everything else is retail's: frame, the order of the block copies and the two `lq`/`sq`,
   the switch tree, every call's argument order, the float constants. Default flags
   (-O2 -G0 -ffunction-sections), no profile, no `-g8` data.

   What the body needed (each measured on this file):
   - `func_0032C700` declared as returning a pointer (retail's version ends in `daddu $v0,$s4,$zero`);
   - `func_L00_002EC248` declared with its ints and floats interleaved,
     (void *, void *, float, void *, float, int, int, float, float, float): the two register files
     are separate, so only the caller's evaluation order moves. Of the 252 interleavings of its five
     ints and five floats this one gave the fewest differing words (the natural order was 10 more);
   - the three constant tables declared `const`, and the five initialisations written in the order
     a, b, c[0], c[1], d (three of the 120 orders reach the 4-word state, the rest are 8 to 24+ off).

   What differs: reload chooses the zero register. `*(TI128 *)d = 0` stays a (set (mem) (const_int
   0)) that no `movti_internal` alternative accepts, so reload gives it a register pair in
   potential_reload_regs order among the registers not live at that insn: this C gets (v0,v1);
   retail's pair is (t4,t5), so at retail's insn every lower pair had a live member. In all 120
   statement orders the first zero register is a1, v0, v1 or t1, never t4. Also tried, none closer:
   a pointer to each table, a named TI128 zero (cse folds it back into the store), four float
   stores instead of the TI clear (8 bytes bigger), -fno-gcse, -fno-schedule-insns,
   -fno-schedule-insns2, -fno-strength-reduce, -mno-split-addresses, -g, -frac2-qcopy,
   -frac2-zero-ti-barrier (alone or with qcopy: many words worse), -frac2-gcse-unsplit-edges,
   -frac2-keep-block-order, -frac2-hazard-labels. The retail zero registers (t4, v0 here; t5, v0,
   a2, t2 in func_L02_0042E2F8 beside it) look like operands the original's own 16-byte clear code
   left to the allocator; this reload does not reproduce them from C. */

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef int TI128 __attribute__((mode(TI)));

extern void func_002A7750();
extern void *func_0032C700(void *, int, int, int, int, int, int, int, float, float,
                           int, int, int, int);

struct Pair43E150 {
    float a;
    float b;
};

extern const struct Pair43E150 D_L02_001B29B0;
extern const struct Pair43E150 D_L02_001B29B8;
extern const TI128 D_L02_001B29C0[2];
extern void func_L00_0032A258(void *, void *, void *, void *, s32, s32, s32, s32, s32, s32, s32);
extern void func_L00_00324F18(void *, void *, float, float, float);
extern int func_00282948(void *);
extern void func_00283098(void *, void *, void *);
extern int func_002A7820(int, int);
extern void func_L00_002EC248(void *, void *, float, void *, float, int, int, float, float, float);

/* The state machine of an effect object (kind byte at +0x20, private block at +0x68): kind 0
   spawns the first burst and arms the first timer, kind 1 waits for that timer and arms the second,
   kind 2 waits for it (or for the counter to reach 0x5B) and throws two debris bursts. */
void func_L02_0043E150(u8 *a0) {
    u8 *state = *(u8 **)(a0 + 0x68);
    int kind = a0[0x20];
    struct Pair43E150 a = D_L02_001B29B0;
    struct Pair43E150 b = D_L02_001B29B8;
    TI128 c[2];
    float d[4];
    float e[4];

    c[0] = D_L02_001B29C0[0];
    c[1] = D_L02_001B29C0[1];
    *(TI128 *)d = 0;
    switch (kind) {
    case 0:
        func_L00_0032A258(a0, c, &b, &a, 0xFFFF, 0, -1, 0x10, 0xFFFF, 0xFF, 0);
        *(u32 *)(a0 + 0x98) = *(u32 *)(*(u8 **)(a0 + 0x24) + 0x10);
        *(u16 *)(a0 + 0x7C) = 0;
        func_L00_00324F18(a0, e, d[0], d[1], d[2]);
        func_0032C700(e, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 0, *(float *)(a0 + 0x2C) * 7.0f,
                      20.0f, 1, 1, 1, 0);
        *(s32 *)state = 0x14;
        func_002A7750(a0, 1, -1);
        break;
    case 1:
        if (func_00282948(state) != 0) {
            func_L00_00324F18(a0, e, d[0], d[1], d[2]);
            func_0032C700(e, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 0,
                          *(float *)(a0 + 0x2C) * 3.5f, 20.0f, 0, 0, 0, 0);
            *(s32 *)(state + 4) = 0x78;
            func_002A7750(a0, 2, -1);
        }
        break;
    case 2:
        if (func_00282948(state + 4) != 0 || *(s32 *)(state + 4) >= 0x5B) {
            *(TI128 *)e = 0;
            e[1] = -0.016666668f;
            e[2] = 0.050000004f;
            func_00283098(e, e, a0 + 0xC0);
            func_L00_002EC248(a0, d, 0.0f, e, 0.033333335f, func_002A7820(3, 6), 0, 0.5f, 15.0f,
                              2.0f);
            func_L00_002EC248(a0, d, 0.0f, e, 0.033333335f, func_002A7820(3, 6), 1, 0.5f, 15.0f,
                              2.0f);
            *(s32 *)(state + 4) = func_002A7820(0x2D, 0x5A);
        }
        break;
    }
}
