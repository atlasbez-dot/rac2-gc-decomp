/* func_L00_00409480 - NOT MATCHED, best attempt - 212 bytes expected, 27 places.
 * last check.py line: "func_L00_00409480: 0 of 27 places match (src/levels/shared/L00_003FFA70.c)"
 * with "00_aranos_tutorial: instruction at +0x40 differs" - the body is the exact
 * 212 bytes of the retail.
 *
 * The light lookup, the value 128 minus it (born in $a2, as in the retail), the
 * four effect calls and the two table reads all match. What is left is the order
 * of the four shifts and of the three ors that build the colour:
 *
 *   retail: sll $v0, $a2, 16 ; sll $s1, $a2, 24 ; sll $v1, $a2, 8 ;
 *           or $s1, $s1, $v0 ; or $s1, $s1, $v1 ; or $s1, $s1, $a2
 *   ours:   sll $v1, $a2, 16 ; sll $s1, $a2, 24 ; sll $v0, $a2, 8 ;
 *           or $s1, $s1, $a2 ; or $v0, $v0, $v1 ; or $s1, $s1, $v0
 *
 * this compiler reassociates the chain of ors and sorts the operands, so the
 * plain "c << 24 | c << 16 | c << 8 | c" and every grouping of it come out as
 * (c << 24 | c) | ((c << 8) | (c << 16)); the retail keeps the chain strictly
 * left-associative. Measured: all six orders of the four terms and the four
 * groupings of the expression give the same reassociated tree, so the order is
 * a property of the compiler's fold, not of the source. The single expression
 * (rather than four statements) is what puts the value in $a2 instead of $v1.
 * Measured since (wave 8): the left-associative tree IS reachable - at -O1 this
 * cc1 emits `or $s1,$s1,$v0 ; or $s1,$s1,$v1 ; or $s1,$s1,$a2` exactly like the
 * retail - but at -O1 the whole body is scheduled differently (the `subu` and the
 * argument moves move), so -O1 is not a route.  At -O2 neither -fno-gcse nor
 * -fno-expensive-optimizations nor -O3 changes the tree, and the four
 * statements give 216 bytes with the argument moves in another order.  The
 * fold is a property of the -O2 profile.
 */

extern int func_002EF250(float x);
extern void func_0037B508(int a, int b, int c);
extern void func_002E7DD8(int a, int b, int c, int d, int e);
extern short D_001A6480[];

void func_L00_00409480(char *arg)
{
    int *o = *(int **)(arg + 104);
    short *t;
    int c;
    int rgba;

    c = 128 - func_002EF250((float)(o[2] * 2));
    rgba = (c << 24) | (c << 16) | (c << 8) | c;
    func_0037B508(66, 72, c);
    t = D_001A6480;
    func_002E7DD8(0, t[0xA9], 0, t[0xA8], rgba);
    func_002E7DD8(0, t[0xA9], 0, t[0xA8], rgba);
    func_002E7DD8(0, t[0xA9], 0, t[0xA8], rgba);
    func_002E7DD8(0, t[0xA9], 0, t[0xA8], rgba);
}
