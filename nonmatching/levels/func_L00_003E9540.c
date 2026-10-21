/* func_L00_003E9540 (288 bytes, 27 places) -- NEAR MISS, not integrated.
   state: the whole instruction sequence is retail's; the fault is the
   floating-point register allocation.
   check.py (00_aranos_tutorial), with the source below:
     003E9580  lwc1  $f4, 0x0($a3)    |  lwc1  $f3, 0x0($a3)   (p2.x)
     003E9594  mul.s $f6, $f12, $f12  |  mul.s $f5, $f12, $f12  (t*t)
     003E9598  lwc1  $f5, 0x0($a1)    |  lwc1  $f6, 0x0($a1)   (p0.x)
     003E959C  lwc1  $f2, 0x0($a2)    |  lwc1  $f4, 0x0($a2)   (p1.x)
     003E95A8  mul.s $f3, $f6, $f12   |  mul.s $f2, $f5, $f12  (t*t*t)
   Every opcode, every offset, every branch, the 16-byte `lq`/`sq` copies at
   the two phase tests and the `bc1fl` whose annulled slot holds the load of
   p2.x are retail's; only the FPR numbers differ, and the difference is a
   permutation of five values over $f2..$f6:
     retail  f2=t^3  f3=p2.x f4=p1.x f5=t^2  f6=p0.x
     this    f2=p1.x f3=t^3  f4=p2.x f5=p0.x f6=t^2
   $f0 (p3.x and the accumulator), $f1 (a and a-c), $f7 (c) and $f8 (the 0.0
   of the first phase test) are already retail's.

   What is measured and right:
   - the formula: out = c*t^3 + (a-c)*t^2 + (p1-p2)*t + p0, summed left to
     right, with c = (p3-p1) - a and a = p2-p0; the fourth component is 0.0.
   - the 16-byte copies at the two phase tests are `lq`/`sq`, which only this
     compiler reaches through a 128-bit integer type, not through a struct.
   - the copies must be volatile: without the qualifier the compiler moves the
     `sq` into the branch delay slot and the two blocks come out two words short.
   - the phase parameter is the 6th argument in $f12 and the fourth control
     point is the 5th in $t0 (this ABI puts the 5th and 6th integer arguments
     in $t0/$t1).
   - naming `a` (p2-p0) does NOT change the allocation: this cc1 folds the
     name away and the pseudo disappears.  Naming `a` AND `b` (p3-p1) does
     change it, because then `a` stays live across the read of p1.x:
       this  f2=p1.x f3=t^3  f4=p0.x f5=t^2  f6=p1.x(again) f7=a f6=c
     which moves t^2 into retail's $f5 but moves a and c out of $f1 and $f7.
   - naming `d` (p1-p2) as well gives retail's $f5 (t^2), $f3 (p2.x), $f2 (t^3)
     and $f0 (p3.x), but it changes the instruction order: the `(p1-p2)`
     subtraction is then scheduled before the `(p3-p1)` one, where retail has
     it after.
   Tried and not enough: eleven spellings (the near miss of
   nonmatching/levels/func_L00_0031AA28.c measured nine: a, b, c, d named or
   inline, t^2 and t^3 named or inline, the vectors as a struct or as a float
   array, the float argument first in the signature); wave 14 w2 added the
   named-a, named-b, named-a-and-b, named-a-and-d and named-a-and-b-and-d
   shapes, and the reordering of the t^2/t^3 statements.  The five values move
   as a block.
   Next idea: a shape where the `(p1-p2)` term keeps retail's position (after
   the `(p3-p1)` subtraction) while `a` and `b` are both live across the read
   of p1.x, so that the allocator takes $f2 for t^3 and $f1 for a. */

typedef int TI128 __attribute__((mode(TI)));

typedef struct {
    float x, y, z, w;
} V4;

/* cubic curve through four control vectors: at a phase of zero the first is copied and
   at one the second, in between the three first components follow the cubic built from
   the four vectors and the fourth component is cleared */
void func_L00_003E9540(V4 *out, V4 *p0, V4 *p1, V4 *p2, float *p3, float t)
{
    float t2;
    float t3;
    float c;
    float a;

    if (t == 0.0f) {
        *(volatile TI128 *)out = *(TI128 *)p0;
        return;
    }
    if (t == 1.0f) {
        *(volatile TI128 *)out = *(TI128 *)p1;
        return;
    }
    t2 = t * t;
    t3 = t2 * t;
    a = p2->x - p0->x;
    c = (p3[0] - p1->x) - a;
    out->x = c * t3 + (a - c) * t2 + (p1->x - p2->x) * t + p0->x;
    c = (p3[1] - p1->y) - (p2->y - p0->y);
    out->y = c * t3 + ((p2->y - p0->y) - c) * t2 + (p1->y - p2->y) * t + p0->y;
    c = (p3[2] - p1->z) - (p2->z - p0->z);
    out->z = c * t3 + ((p2->z - p0->z) - c) * t2 + (p1->z - p2->z) * t + p0->z;
    out->w = 0.0f;
}
