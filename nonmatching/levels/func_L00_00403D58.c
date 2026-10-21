/* func_L00_00403D58 - NOT MATCHED, best attempt - 240 bytes expected, 27 places.
 * last check.py line: "func_L00_00403D58: 0 of 27 places match (src/levels/shared/L00_003FFA70.c)"
 * with "00_aranos_tutorial: instruction at +0x54 differs" - the body is the exact
 * 240 bytes of the retail.
 *
 * The three states, the two calls that follow the copy, the effect helper and the
 * shared callback all match, and so does the whole prologue. What is left is the
 * address of the 128-bit copy:
 *
 *   retail: addiu $s0, $s1, 0x10 ; lq $v0, 0($s0) ; sq $v0, 0($sp)
 *   ours:   lq $v0, 0x10($s1) ; addiu $s0, $s1, 0x10 ; sq $v0, 0($sp)
 *
 * this cc1 folds the constant offset of the 128-bit load into the lq; retail
 * materialises the pointer (it is live across the two calls, so it is in the
 * saved register $s0) and loads through it. Measured: the same for every
 * spelling of the copy - a direct cast, a char* variable, a TI128* variable, a
 * second variable holding the pointer, the destination through a pointer
 * variable, a local of type TI128, the offset as a variable - so the folded lq
 * is a property of the compiler. The earlier deposit of this body used the
 * inline-assembly qcopy of include/common.h and matched byte for byte; that is
 * not a route under AGENTS.md's "Plain C" rule.
 */

typedef int TI128 __attribute__((mode(TI)));

extern void func_002EE108(char *a, int *b, char *c);
extern void func_0037F9A0(char *a, char *b);
extern void func_0037E1D8(int a, int *b, int c);
extern int func_002EDD48(char *a);
extern void func_002E6EF8(void (*f)(char *), char *arg);
extern void func_L00_00404168(char *arg);
extern void func_L00_00403F90(char *arg, void *p);
extern void func_0037E1B8(int a);
extern void func_00310440(char *arg);

void func_L00_00403D58(char *arg)
{
    int *o = *(int **)(arg + 104);
    unsigned char state = *(unsigned char *)(arg + 32);
    TI128 tmp;
    char *p;

    switch (state) {
    case 0:
        arg[32] = 1;
    case 1:
        p = arg + 16;
        *(TI128 *)&tmp = *(TI128 *)p;
        func_002EE108(p, o, p);
        func_0037F9A0(p, p);
        func_0037E1D8(o[7], o, 0);
        func_L00_00403F90(arg, &tmp);
        if (func_002EDD48((char *)o + 16) != 0)
            arg[32] = 2;
        break;
    case 2:
        func_0037E1B8(o[7]);
        func_00310440(arg);
        return;
    default:
        break;
    }
    func_002E6EF8(func_L00_00404168, arg);
}
