/* near-miss: func_L20_004473B0 (20_yeedil, 656 bytes).
 *
 * The whole structure is recovered and every call, every float constant and every
 * field offset is retail's; the candidate is 624 bytes against retail's 656.
 *
 * WHAT IS MEASURED AND WORKS:
 *   - the level's own jump table IS reachable: `extern void *jtbl_002B59A0[];` with
 *     `goto *jtbl_002B59A0[sel];` and a `static void * volatile tab[]` of labels
 *     gives the retail's dispatch EXACTLY (lui %hi / sll / addiu %lo / addu / lw /
 *     jr), the `sel >= 5` guard and the whole five-case body.
 *   - the five cases: case 0 copies arg0+0x10 into state+0x60 and calls
 *     func_L00_003294F0(arg0, 1, state->0x5C | 1) and func_002A7750(arg0, 4, -1);
 *     cases 1 and 3 compute the float block (state->0x70 * 4.0f divided by
 *     (float)(state->0x74 * state->0x74), times (float)state->0x74) and call
 *     func_002AA548(arg0+0x18, state+0x88, ...); case 1 adds state->0x70 to
 *     state->0x68 for the third argument, case 3 does not; cases 2 and 4 only
 *     store into state->0x84 and call func_002A7750 with 3 and 1.
 *   - the tail: func_002B38B8, the `0.0f < state->0x8C` compare (c.olt.s + bc1f,
 *     the retail's polarity), func_L20_00447640, the constant -1000.0f (0xC47A0000,
 *     NOT -100000.0f), func_00282CF0 and func_002AD6F0.
 *   - the three 16-byte locals are at sp+0x00, sp+0x10 and sp+0x20.
 *
 * WHAT IS LEFT - the 128-bit copy wall:
 *   the retail materialises the two 16-byte destinations at the top of the function
 *     addiu $v1,$s2,0x10 ; lq $v0,0x0($v1) ; sq $v0,0x0($sp)
 *     addiu $v1,$s2,0xF0 ; lq $v0,0x0($v1) ; sq $v0,0x0($a0)
 *   and this cc1 folds both offsets into the load (`lq $v0,0x10($s2)`), which is
 *   the CSE's find_best_addr tie (see docs/COMPILER-NOTES.md).  Measured and not
 *   enough: the address through a `char *` local, through a `TI128 *` local, the
 *   address taken twice, the destination a `TI128` local (a stack slot - the
 *   destination is already the retail's zero-displacement `sq`).
 *   The 32 bytes that are missing are these two `addiu`s (8 bytes) and the register
 *   allocation that follows from them: the retail keeps the address of the second
 *   local in $s3 (a saved register, hence the 0x60 frame against this cc1's 0x50)
 *   and the float block in $f1/$f2 where this cc1 uses $f0/$f1.
 */

typedef int TI128 __attribute__((mode(TI)));

extern void *jtbl_002B59A0[];
extern void func_L00_003294F0(char *, int, int);
extern int func_002B3868(char *);
extern int func_00282948(char *);
extern void func_002AA548(char *, char *, float, float, float, float);
extern int func_002B38B8(char *);
extern void func_L20_00447640(char *);
extern void func_00282CF0(char *, char *, char *);
extern void func_002AD6F0(char *, char *, char *, char *);

void func_L20_004473B0(char *arg0) {
    static void * volatile tab[] = { &&c0, &&c1, &&c2, &&c3, &&c4 };
    char *state;
    TI128 a, b, c;
    unsigned char sel;
    int n;
    float f1, f12, f13, f14, f15;

    a = *(TI128 *)(arg0 + 0x10);
    b = *(TI128 *)(arg0 + 0xF0);
    state = *(char **)(arg0 + 0x68);
    sel = *(unsigned char *)(arg0 + 0x20);
    if (sel >= 5) {
        goto end;
    }
    goto *jtbl_002B59A0[sel];
c0:
    *(TI128 *)(state + 0x60) = *(TI128 *)(arg0 + 0x10);
    n = *(int *)(state + 0x5C) | 1;
    func_L00_003294F0(arg0, 1, n);
    *(int *)(state + 0x5C) = n;
    func_002A7750(arg0, 4, -1);
    goto end;
c1:
    if (func_002B3868(arg0) != 0) {
        *(int *)(state + 0x88) = 0;
        *(int *)(state + 0x84) = *(int *)(state + 0x74);
    }
    if (func_00282948(state + 0x84) != 0) {
        func_002A7750(arg0, 2, -1);
    }
    n = *(int *)(state + 0x74);
    f1 = *(float *)(state + 0x70) * 4.0f;
    f12 = *(float *)(state + 0x68) + *(float *)(state + 0x70);
    f15 = (float)n;
    f13 = f1 / (float)(n * n);
    f15 = f13 * f15;
    f14 = f13;
    func_002AA548(arg0 + 0x18, state + 0x88, f12, f13, f14, f15);
    goto end;
c2:
    if (func_002B3868(arg0) != 0) {
        *(int *)(state + 0x84) = *(int *)(state + 0x78);
    }
    if (func_00282948(state + 0x84) != 0) {
        func_002A7750(arg0, 3, -1);
    }
    goto end;
c3:
    if (func_002B3868(arg0) != 0) {
        *(int *)(state + 0x88) = 0;
        *(int *)(state + 0x84) = *(int *)(state + 0x7C);
    }
    if (func_00282948(state + 0x84) != 0) {
        func_002A7750(arg0, 4, -1);
    }
    n = *(int *)(state + 0x74);
    f1 = *(float *)(state + 0x70) * 4.0f;
    f12 = *(float *)(state + 0x68);
    f15 = (float)n;
    f13 = f1 / (float)(n * n);
    f15 = f13 * f15;
    f14 = f13;
    func_002AA548(arg0 + 0x18, state + 0x88, f12, f13, f14, f15);
    goto end;
c4:
    if (func_002B3868(arg0) != 0) {
        *(int *)(state + 0x84) = *(int *)(state + 0x80);
    }
    if (func_00282948(state + 0x84) != 0) {
        func_002A7750(arg0, 1, -1);
    }
    goto end;
end:
    if (func_002B38B8(arg0) == 0) {
        if (0.0f < *(float *)(state + 0x8C)) {
            func_L20_00447640(arg0);
            *(float *)(state + 0x8C) = -1000.0f;
        }
    }
    func_00282CF0((char *)&c, arg0 + 0x10, (char *)&a);
    func_002AD6F0(state + 0x20, (char *)&c, (char *)&b, arg0 + 0xF0);
}
