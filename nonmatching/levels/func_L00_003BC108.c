/* func_L00_003BC108 (288 bytes, 27 places) - best attempt, NOT MATCHED.
 *
 * tools/check.py func_L00_003BC108 --diff:
 *   "00_aranos_tutorial: instruction at +0x0 differs" (the size is the retail's 288 bytes;
 *   the same for the other 26 places).
 *
 * What is right: the whole shape of the body.  The two early returns (the parameter equal
 * to 0.0f copies the first point, equal to 1.0f the second one), the `bc1f`/`bc1fl`
 * pair, the 16-byte copies as `lq`/`sq` with a zero displacement, the three components
 * and the fourth one set to zero - and, with the expression form of the result, the
 * OPERATION ORDER of all three components is the retail's, instruction for instruction.
 *
 * What is left is the allocation of the floating-point registers: the retail uses
 * $f8 for the zero, $f6 for a[0], $f4 for b[0], $f3 for c[0], $f2 for t*t*t, $f7 for the
 * difference of the differences, and this cc1 puts the same values in $f7, $f4, $f2,
 * $f3, $f6 and $f0.  The order of the operations is the retail's in all three
 * components, so only the register numbers differ.
 *
 * What was measured to get here (each step is a compile):
 *   - the zero of the fourth component is a float VARIABLE (`float zero = 0.0f;`), not a
 *     literal: the retail materialises it once in $f8 at the top of the body and uses it
 *     both in the first compare and in the last store;
 *   - the 16-byte copies need a `volatile` destination (`*(volatile TI128 *)out =
 *     *(TI128 *)p1;`), otherwise this cc1 sinks the `sq` into the `jr $ra` delay slot and
 *     the retail leaves a nop there (the same spelling as the matched func_002A8C00);
 *   - the three components have to be ONE expression each, not a sequence of named
 *     temporaries: with temporaries the scheduler moves the `b-c` subtraction and the
 *     `t*t*t` multiplication to other places, and the retail's order is only reproduced
 *     by the expression (the common subexpressions are then CSE'd by the compiler);
 *   - the arguments are (float t, void *out, void *p1, void *p2, void *p3, void *p4): the
 *     parameter is the first float (in $f12) and the five pointers take $a0-$a3 and $t0.
 *
 * To retake: a spelling of the three expressions whose floating-point temporaries get
 * the retail's register numbers.
 */

#ifndef RAC2_T_TI128_3BC108
#define RAC2_T_TI128_3BC108
typedef int TI128_3BC108 __attribute__((mode(TI)));
#endif

/* Blends the two points along the cubic that runs through the four given ones: the
   first two are copied whole when the parameter is 0 or 1, otherwise the curve is
   evaluated at the parameter. */
void func_L00_003BC108(float t, void *out, void *p1, void *p2, void *p3, void *p4)
{
    float *o = (float *)out;
    float *a = (float *)p1;
    float *b = (float *)p2;
    float *c = (float *)p3;
    float *d = (float *)p4;
    float zero = 0.0f;
    float t2;

    if (t == zero) {
        *(volatile TI128_3BC108 *)out = *(TI128_3BC108 *)p1;
        return;
    }
    if (t == 1.0f) {
        *(volatile TI128_3BC108 *)out = *(TI128_3BC108 *)p2;
        return;
    }

    t2 = t * t;
    o[0] = (((d[0] - b[0]) - (c[0] - a[0])) * (t2 * t)
           + ((c[0] - a[0]) - ((d[0] - b[0]) - (c[0] - a[0]))) * t2
           + (b[0] - c[0]) * t) + a[0];
    o[1] = (((d[1] - b[1]) - (c[1] - a[1])) * (t2 * t)
           + ((c[1] - a[1]) - ((d[1] - b[1]) - (c[1] - a[1]))) * t2
           + (b[1] - c[1]) * t) + a[1];
    o[2] = (((d[2] - b[2]) - (c[2] - a[2])) * (t2 * t)
           + ((c[2] - a[2]) - ((d[2] - b[2]) - (c[2] - a[2]))) * t2
           + (b[2] - c[2]) * t) + a[2];
    o[3] = zero;
}
