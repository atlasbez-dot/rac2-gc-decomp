/* func_L11_00437EA8 (292 bytes, 1 place) -- NEAR MISS, not integrated.
   state: 292 bytes, the retail's size; the prologue, the frame layout, the
   float blend and the thirteen rounds are the retail's; three instructions sit
   in another place.
   check.py (11_joba), with the source below:
     11_joba: instruction at +0x94 differs
     func_L11_00437EA8: 0 of 1 places match (src/levels/11_joba/L11_00432628.c)

   What is measured and right:
   - the body zeroes a sixteen-byte gravity vector and puts -1/720 into its
     third float (0xBAB60B61), then blends 0.97f and 0.98f with
     ((float)*(short *)(state + 0x378) - 2.0f) / 8.0f.  The blend is
     func_002AA140(a, b, t) = a + (b - a) * t and both int-to-float
     conversions are func_00283CE0, so the divisor is func_00283CE0(8) and not
     a literal 8.0f.
   - writing the blend's numerator as the compound assignment `(f20 -= 2.0f)`
     is what makes the retail's `sub.s $f20, $f20, $f1` come out; as a plain
     `(f20 - 2.0f)` the same cc1 puts the difference in $f14 and reads $f0.
   - the thirteen rounds are a Verlet step: the position is copied, the
     difference to the old position is scaled and the position is advanced
     with the gravity; the old position takes the copy.  The three helpers are
     the VU0 routines func_00282CF0 (difference), func_00282D30 (scale) and
     func_003004E0 (sum), not the boot's func_00282CC0.
   - the copy is a `mode(TI)` quadword copy (lq/sq), not a struct assignment
     (a struct assignment gives ldl/ldr/sdl/sdr) and not a scalar: a scalar
     `mode(TI)` local stays in a register pair and the frame comes out 0x60
     against the retail's 0x70.
   - the frame is the retail's: three sixteen-byte locals at 0x00, 0x10 and
     0x20, s0..s4 at 0x30..0x50, $ra at 0x58 and f20 at 0x60.

   What is left (the placement of three instructions):
   - the retail stores the copy right after the load (`lq $v0, 0x0($s1);
     sq $v0, 0x0($sp)`), this draft sets the three call arguments first and
     stores the copy after them.
   - the retail takes the second call's argument setup in its delay slot and
     keeps the loop counter's decrement in the loop's latch; this draft takes
     the decrement in the delay slot of the first call in the loop.
   - the retail computes the address of the second local after the call that
     fills f20; this draft computes it before.

   Tried and not enough: the loop as `i < 13`, `i >= 0` and `while (i != 0)`,
   the copy through a `mode(TI)` scalar, through a `volatile mode(TI)` scalar
   and through a `mode(TI)` array, the chain pointers as `char *` and as
   `mode(TI) *`, __builtin_memcpy for the copy (gives ldl/ldr/sdl/sdr), and
   the second local declared inside the loop. */

extern void func_00282C88(TI128 *a0);
extern void func_00282CF0(void *a0, void *a1, void *a2);
extern void func_003004E0(void *a0, void *a1, void *a2);
extern float func_00283CE0(int a0);
extern float func_002AA140(float a, float b, float t);
extern void func_00282D30(char *, char *, float);

typedef int TI128 __attribute__((mode(TI)));

void func_L11_00437EA8(char *p)
{
    char *state = *(char **)(p + 0x68);
    char *pos;
    char *old;
    TI128 tmp[1];
    TI128 d[1];
    TI128 grav[1];
    float f20;
    int i;

    func_00282C88(&grav[0]);
    pos = state + 0x100;
    old = state + 0x1D0;
    *(float *)((char *)&grav[0] + 8) = -1.0f / 720.0f;

    f20 = func_00283CE0(*(short *)(state + 0x378));
    f20 = func_002AA140(0.97f, 0.98f, (f20 -= 2.0f) / func_00283CE0(8));

    for (i = 0; i < 13; i++) {
        tmp[0] = *(TI128 *)pos;
        func_00282CF0(&d[0], pos, old);
        func_00282D30((char *)&d[0], (char *)&d[0], f20);
        func_003004E0(pos, pos, &d[0]);
        func_003004E0(pos, pos, &grav[0]);
        *(TI128 *)old = tmp[0];
        pos += 0x10;
        old += 0x10;
    }
}
