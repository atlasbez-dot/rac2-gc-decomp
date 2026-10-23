/* func_L00_00403CB8 - NOT MATCHED, best attempt - 160 bytes expected, 27 places.
 * last check.py line: "func_L00_00403CB8: 0 of 27 places match (src/levels/shared/L00_003FFA70.c)"
 * with "00_aranos_tutorial: instruction at +0x4 differs" - the body is the exact
 * 160 bytes of the retail.
 *
 * The shape is right: the found-slot loop, the two calls of the busy path and the
 * store of the record back all match, and the two pointers of the loop (one that
 * is read, one that is written) are what gives the two induction variables the
 * retail has. What is left is the register allocation, which is rotated by one:
 *
 *   retail: sd $s1 ; sd $s0 ; daddu $s1, $a0 ; daddu $a1, $zero ; lui $a0 ;
 *           daddu $a2, $a0
 *   ours:   sd $s0 ; sd $s1 ; daddu $s0, $a0 ; daddu $a0, $zero ; lui $a1 ;
 *           daddu $v1, $a1
 *
 * the record pointer is in $s1 in the retail and in $s0 here, the table pointer
 * is in $a0 there and in $a1 here, the counter is in $a1 there and in $a0 here.
 * Measured: the same for every spelling (one pointer or two, the pointers
 * declared before or after the counter, at the function scope or in the branch, a
 * for loop or a while loop, p++ or p = p + 1). The earlier deposit of this body
 * also called func_L00_00403C30 with an argument, which does not compile: the
 * function takes none.
 * Measured since (wave 8): the retail's q++ comes before its p++ in the source
 * (the store's pointer is the one the loop advances first, the read's pointer is
 * advanced in the branch's delay slot) and the two statements swapped do not
 * change the allocation; the argument and pointer types (`int **` against
 * `char **`, the parameter against `int *`) do not either; the opt-in
 * quadword-copy profile does not apply (the body has no 16-byte copy) and
 * -mastra-keep-frame-order changes nothing.  The wall is the allocation, not a
 * spelling. */

extern int D_L00_001B2C30[] __attribute__((sda));

extern int func_L00_00403C30(void);
extern int func_002A77E0(int n);
extern void func_003320F0(int v);
extern void func_003323F0(int v);

void func_L00_00403CB8(char *arg)
{
    if (func_L00_00403C30() == 0) {
        int i;
        int **p = D_L00_001B2C30;
        int **q = D_L00_001B2C30;

        for (i = 0; i < 16; i++) {
            if (*p == 0) {
                *q = (int *)arg;
                return;
            }
            p++;
            q++;
        }
    } else {
        int **slot = &D_L00_001B2C30[func_002A77E0(16)];
        int *v = *slot;

        func_003320F0((int)v);
        func_003323F0((int)v);
        *slot = v;
    }
}
