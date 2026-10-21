/* func_L14_00390EC0 (292 bytes, 1 place: 14_aranos_prison) -- NEAR MISS, not integrated.
   state: 296 bytes; the frame, the four row copies and the loop are the retail
   ones, but six callee-saved float registers are saved against retail's five.
   check.py (14_aranos_prison), with the source below:
     00390EC4  lui $v0,0x0          | por $v1,$zero,$zero
     00390EC8  sq $zero,0x0($sp)    | sd $s0,0x50($sp)
     00390EE4  swc1 $f25,0xA8($sp)  | swc1 $f24,0xA0($sp)
   The measured and right parts:
   - the matrix is D_L14_001AEE10, four 16-byte rows copied to the frame at
     +0x10, and the loop walks those rows and writes them to the first argument;
   - the vector at the frame's base is {1.0f, 0.0f, 0.0f, 1.0f} and is passed to
     func_002830C0 (the level's 0x328340) as its third argument;
   - the row's y and z components are scaled by the second and third float
     parameters, its w component is set to 1.0f, and func_002ACEC0 (0x2F6120)
     gets the row and the second argument;
   - the comparison is the float one (`c.eq.s`), with the boolean passed to
     func_002830C0 as its fourth argument.
   What is left is the register allocation of the floats: retail keeps $f20 =
   the third parameter, $f21 = the second, $f22 = the first, $f23 = the zero it
   compares against and $f24 = the one it writes, this cc1 gives the zero and
   the one registers of their own, so a sixth callee-saved float register is
   saved and the frame grows.
   The comparison's operand must be a variable the compiler cannot fold: retail
   compares against $f23, which it fills with `mtc1 $zero,$f23`, and does not
   fold the comparison although the value is zero.
   Tried and not enough: the zero as a local, as a parameter and as a literal;
     the comparison as `f23 == 0.0f`, as `f20 == 0.0f` and as `f23 != 0.0f`;
     the rows copied in a loop and one by one; the vector at the frame's base as
     a float array, as a TI128 and through a union. */

extern char D_L14_001AEE10[];

extern void func_328340(void *a, void *b, void *c, float d);

extern void func_2F6120(void *a, void *b, void *c);

/* A 16-byte vector: the compiler reaches lq/sq only through TImode. */
typedef int TI128 __attribute__((mode(TI)));

void func_L14_00390EC0(char *arg0, char *arg1, float f12, float f13, float f14) {
    char *s0 = arg0;
    char *s1;
    char *s2 = 0;
    char *s3 = arg1;
    float v0[4];
    TI128 rows[4];
    TI128 zero = 0;
    float f20 = f14;
    float f21 = f13;
    float f22 = f12;
    float f23 = 0.0f;
    float f24 = 1.0f;
    float f0;
    float f1;
    int i;

    *(TI128 *)v0 = zero;
    v0[0] = 1.0f;
    v0[3] = 1.0f;
    rows[0] = *(TI128 *)(D_L14_001AEE10);
    rows[1] = *(TI128 *)(D_L14_001AEE10 + 16);
    rows[2] = *(TI128 *)(D_L14_001AEE10 + 32);
    rows[3] = *(TI128 *)(D_L14_001AEE10 + 48);
    for (i = 0; i < 4; i++) {
        *(TI128 *)s0 = rows[i];
        f1 = *(float *)(s0 + 4);
        f0 = *(float *)(s0 + 8);
        f1 = f1 * f22;
        f0 = f0 * f21;
        *(float *)(s0 + 4) = f1;
        if (f23 != 0.0f) {
            func_328340(s0, s0, v0, f23 == 0.0f);
        }
        *(float *)(s0 + 8) = f0;
        *(float *)(s0 + 0xC) = f24;
        func_2F6120(s0, s0, s3);
        s0 = s0 + 16;
    }
}
