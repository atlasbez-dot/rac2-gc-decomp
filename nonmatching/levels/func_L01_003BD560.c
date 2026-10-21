/* func_L01_003BD560 (136 bytes, 1 place) -- NEAR MISS, not integrated.
   Builds two quads from the argument, stores a random-free clamp into the second
   one's third float and calls the engine helper with (quad1, quad0, 2, 0, 0).
   Blocked on the FPU min/max opcodes: retail is min.s $f0,$f15,$f12 for the clamp
   and max.s $f0,$f20,$f0 on the failure path (COP1 funct 0x29/0x28), which this
   cc1 does not emit from C - the ternary/if forms measured here give
   c.olt.s + bc1f/bc1tl with mov.s/`movn` instead, and the candidate comes out 152
   bytes against 136. Same wall as func_L08_00425328/00425398 (COMPILER-NOTES).
   Everything else (the two lq/sq pairs via TI128, the delay-slot store of f12,
   the bnez/return shape, the lui+lwc1 of D_L01_001BF928) is instruction-exact. */
typedef int TI128 __attribute__((mode(TI)));

extern int func_002761F8(void *, void *, int, int, int);
extern float D_L01_001BF928;

float func_L01_003BD560(void *a0, float a1, float a2, float a3, float a4)
{
    float buf0[4];
    float buf1[4];
    float out = a3;
    float t = a1;

    *(TI128 *)buf0 = *(TI128 *)a0;
    buf0[2] = a2;
    *(TI128 *)buf1 = *(TI128 *)a0;
    if (a4 != 0.0f) {
        t = a4 < a1 ? a4 : a1;
    }
    buf1[2] = t;
    if (func_002761F8(buf1, buf0, 2, 0, 0) != 0) {
        out = out > D_L01_001BF928 ? out : D_L01_001BF928;
    }
    return out;
}

/* Wave 24 (worker 09) -- the min/max wall above is NOT a wall: this cc1 does
   emit min.s and max.s, but only with -ffast-math.  fold-const.c builds a
   float MIN_EXPR/MAX_EXPR out of `a < b ? a : b' only when the float format is
   not IEEE or flag_fast_math is set (the IEEE guard in fold()), so
   `a4 < a1 ? a4 : a1' gives c.olt.s + bc1f without the flag and
   min.s $f0, $f15, $f12 with it.  The file src/levels/01_oozla/L01_003BB9D0.c
   therefore needs -ffast-math (config/cflags.txt); the five functions already
   matched in that file are unaffected by the flag (checked).

   With the flag the two FPU opcodes come out exactly, and the rest of the body
   is close: 112 bytes against 136, with these differences left:
   - the retail's second quad store goes through a register
     (addiu $v1, $sp, 0x10 ; sq $v0, 0x0($v1)) and this cc1 folds the offset
     into the store (sq $v0, 0x10($sp)); the earlier note's claim that the
     lq/sq pairs are instruction-exact does not reproduce here, with a char
     array, with two float arrays or with a pointer variable (all measured);
   - this cc1 hoists the compare of the `a4 != 0.0f' test (mtc1 $zero, $f0 ;
     c.eq.s $f15, $f0) to the top of the body, retail keeps it after the two
     copies;
   - the clamp's second operand is $f1 here and $f0 in retail's max.s, and the
     store of the clamped value is a plain swc1 here and the delay slot of
     retail's bc1tl there.

   Checked with: python3 tools/check.py func_L01_003BD560 --diff
   Last line: func_L01_003BD560: 0 of 1 places match (src/levels/01_oozla/L01_003BB9D0.c) */
