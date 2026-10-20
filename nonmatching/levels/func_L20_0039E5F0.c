/* Near miss from src/levels/20_yeedil/L20_0039C448-g8.c (the -G8 unit).

   The body has the retail size (380 bytes) and the prologue, the first block
   and the epilogue match the retail instruction for instruction.  Three
   instructions are scheduled differently:

     +0x80  retail:  daddu a0,s0 / lwc1 f1,-0x2F0(gp) / addiu a1,zero,1 /
                     lwc1 f0,0x24(v0) / addiu a2,zero,-1 / mul.s f0,f0,f1
              here:   daddu a0,s0 / addiu a1,zero,1 / addiu a2,zero,-1 /
                     lwc1 f0,0x24(v0) / lwc1 f1,D_L20_001AED00(gp) /
                     mul.s f0,f0,f1
     +0xB4  retail:  daddu a2,zero,zero / daddu a3,zero,zero / mov.s f12,f21 /
                     jal f_0033ECF8 / mov.s f13,f21
              here:   daddu a2,zero,zero / mov.s f12,f21 / mov.s f13,f21 /
                     jal f_0033ECF8 / daddu a3,zero,zero
     +0xC4  retail:  lw v1,0x60(s1) / bnez v1 / lui v0,0x19 / lw v1,-0x3F50(v0)
              here:   lw v0,0x60(s1) / bnez v0 / lui v0,0x19 / lw v1,-0x3F50(v0)

   So the retail interleaves the setup of the f_0032F5B0 arguments with the
   float multiply, fills the delay slot of the f_0033ECF8 call with the
   `mov.s f13,f21` instead of the `daddu a3,zero,zero`, and keeps the word
   read from 0x60(s1) in $v1.

   What did work (and is in the attempt):
   - the prologue, the frame (0x30) and the two saved FPRs ($f21 for the zero,
     $f20 for the result) match exactly, so the zero of the f_0033ECF8 call
     and the comparison is a variable and not a literal.
   - D_L20_001AED00 carries `sda` (the retail reaches the float through $gp at
     0x1AEFF0-0x2F0) and D_0018C0B0 carries `nosda` (the retail reaches the word
     through $at: lui v0,0x19 / lw v1,-0x3F50(v0)).
   - the float at 0x2C is `*(f32 *)((char *) *(int *)(arg0 + 0x24) + 0x24)`: the
     retail's `lw v0,0x24(s0)` / `lwc1 f0,0x24(v0)` needs the +0x24 inside the
     load.
   - the first f_0032F5B0 call takes (arg0, 1, -1), not (arg0, 5, -1): the
     retail materialises $a1=1 and $a2=-1 before the float multiply.
   - the flags at 0x34 are written twice: first &= 0xFFFB, later
     (| 0x41) & 0xEFFF.

   Tried: the call before the float store, the constant in a local variable,
   the constant as the first operand of the multiply, the pointer to the float
   in a local variable, the order of the stores in the block, D_0018C0B0 with
   and without `nosda`, and the state pointer loaded before or after the
   first call.  The three differences above are what is left. */
#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00330A68(void *, int);

extern void func_0032F5B0(void *, int, int);

extern void func_0033ECF8(void *, int, int, int, float, float);

extern int func_00331BB8(void *, int, int);

extern float func_00331C18(void *, int);

/* 0x1AEFF0 - 0x2F0 : the float the retail body reaches through $gp. */
extern float D_L20_001AED00 __attribute__((sda));

/* 0x190000 - 0x3F50 : the word the retail body reaches through $at. */
extern int D_0018C0B0 __attribute__((nosda));

void func_L20_0039E5F0(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);

    if (*(u8 *)(arg0 + 0x20) == 0) {
        if (*(f32 *)(state + 0x20) == 0.0f) {
            *(u16 *)(state + 0x24) = 0x1E;
            *(f32 *)(state + 0x20) = 30.0f;
        }
        func_00330A68(arg0, 0xCBC);
        *(u16 *)(arg0 + 0x32) = 0xFF;
        *(u16 *)(arg0 + 0x34) &= 0xFFFB;
        *(f32 *)(arg0 + 0x2C) = *(f32 *)((char *) *(int *)(arg0 + 0x24) + 0x24) * D_L20_001AED00;
        *(int *)(state + 0x190) = 1;
        *(int *)(arg0 + 0x98) = 0;
        *(u16 *)(arg0 + 0x34) = (*(u16 *)(arg0 + 0x34) | 0x41) & 0xEFFF;
        func_0032F5B0(arg0, 1, -1);
    }
    {
        f32 zero = 0.0f;
        f32 r;

        func_0033ECF8(arg0, *(int *)(state + 0x80), 0, 0, zero, zero);
        if (*(int *)(state + 0x60) == 0) {
            *(int *)(state + 0x60) = D_0018C0B0;
        }
        r = func_00331C18(arg0, func_00331BB8(arg0, 0x10000, 0));
        {
            f32 d = *(f32 *)(state + 0x20) - r;

            if (d <= zero) {
                *(f32 *)(state + 0x20) = d;
                func_0032F5B0(arg0, 5, -1);
            }
        }
        if (5.0f <= r) {
            func_0032F5B0(arg0, 4, -1);
        }
    }
    *(u8 *)(arg0 + 0xA8) = 0xFF;
}
