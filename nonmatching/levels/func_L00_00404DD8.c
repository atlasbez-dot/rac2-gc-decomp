/* func_L00_00404DD8 - NOT MATCHED, best attempt - 256 bytes expected, 27 places.
 * last check.py line: "func_L00_00404DD8: 0 of 27 places match (src/levels/shared/L00_003FFA70.c)"
 * with "00_aranos_tutorial: 244 bytes, expected 256".
 *
 * The six range tests, the release of the record, the lookup and the effect
 * helper all match. What is left is the address of the 16-byte pattern the
 * lookup writes over the record's vector:
 *
 *   retail: lui $v1, 0x1C ; addiu $v1, $v1, -0xDE0 ; lq $v0, 0($v1) ;
 *           sq $v0, 0($s1)
 *   ours:   lui $v1, 0x1C ; addiu $v1, $v1, -0xDE0 ; lq $v0, 0($v1) ;
 *           sq $v1, 0x10($s0)
 *
 * retail keeps the record's vector pointer in the saved register $s1 (it is live
 * across the lookup) and stores through it; this compiler folds the constant
 * offset into the sq (sq $v1, 0x10($s0)) and needs no saved register for it,
 * which is why the frame is 0x10 here and 0x20 in the retail. Measured: the same
 * for every spelling (a char* pointer, a TI128* pointer, a void* pointer, the
 * guard reading through a float pointer, the source through a pointer variable) -
 * the folded sq is a property of the compiler. The earlier deposit of this body
 * used the inline-assembly qcopy of include/common.h and matched byte for byte;
 * that is not a route under AGENTS.md's "Plain C" rule.
 */

typedef int TI128 __attribute__((mode(TI)));

extern void func_0035F450(int a, int b, void *c, int d);
extern int func_002DE4B0(void *a, void *b, int c, void *d, int e);
extern void func_00310440(char *arg);
extern TI128 D_L00_001BF220;

void func_L00_00404DD8(char *arg, void *a1)
{
    char *p;

    if (*(float *)(arg + 16) < 2.0f || *(float *)(arg + 16) > 1021.0f ||
        *(float *)(arg + 20) < 2.0f || *(float *)(arg + 20) > 1021.0f ||
        *(float *)(arg + 24) < 2.0f || *(float *)(arg + 24) > 1021.0f) {
        func_00310440(arg);
        return;
    }
    p = arg + 16;
    if (func_002DE4B0(a1, p, 0, arg, 0) != 0) {
        *(TI128 *)p = D_L00_001BF220;
        arg[32] = 2;
        func_0035F450(5, 0, arg, 3705);
    }
}
