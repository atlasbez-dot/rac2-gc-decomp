/* func_L00_003406E8 - 428 bytes, 27 places (every level), retail at 0x003406E8.
 *
 * The body is recovered: it rebuilds the child's position vector in a 16-byte
 * stack buffer, folds the frame time into the packed colour byte, scales the
 * vector through func_00282D30 and copies it into the object with
 * func_00282CC0, then releases the child when the probe returns non-zero.
 * Every call, every constant and every store is in the right place, and the
 * 16-byte buffer is built with the same three loads and three stores retail
 * uses.  What is left is the register allocation:
 *
 * - retail keeps three callee-saved GPRs: $s2 = the object pointer,
 *   $s1 = the object + 0x20 and $s0 = the address of the stack vector
 *   (materialised with `addiu $s0, $sp, 0x10` and used by the func_00282D30
 *   call).  This cc1 keeps two ($s1 = the object, $s0 = the object + 0x20)
 *   and folds the vector's address into the call as `addiu $a1, $sp, 0x10`,
 *   so the object pointer lands in $s1 instead of $s2.
 * - with the third GPR missing, the two scratch FPRs of the branch-B float
 *   code swap ($f0/$f1) and the quotient takes $f21 instead of $f20.
 * - the missing $s2 save and restore also make the guard branch likely
 *   (`beql` where retail has `beqz`).
 *
 * Measured without closing the gap: two 16-byte locals instead of one 32-byte
 * buffer, a `char *vec = buf + 0x10` pointer variable, the vector declared
 * before the output buffer, and the source order of the three vector stores.
 * The vector's address only comes out in a register when the pointer has two
 * assignments, and that costs a branch and an `addu` instead of retail's
 * `addiu`.
 *
 * tools/check.py func_L00_003406E8 --diff: 416 bytes, expected 428, the
 * differences are the registers described above.
 */
extern float func_00283CE0(int a);
extern int func_00283CF0_2(float f);
extern int func_00283D38_1(int a, int b, float f);
extern float func_002A7798(float f);
extern float func_002A7790(float f);
extern void func_00282D30_13(char *a, char *b, float f);
extern void func_00282CC0_13(char *a, char *b, char *c);
extern void func_00300190_1(char *a, char *b);
extern int func_00282978_3(char *p);
extern void func_002B9180_6(char *p);

void func_L00_003406E8(char *a0)
{
    char buf[32];
    char *s1 = a0 + 0x20;
    float f0, f1, f20, f21, f22;
    unsigned int v0, v1;

    *(float *)(buf + 0x10) = *(float *)(a0 + 0x20);
    *(float *)(buf + 0x14) = *(float *)(s1 + 4);
    *(float *)(buf + 0x18) = *(float *)(s1 + 8);
    *(int *)(buf + 0x1C) = 0;
    func_00300190_1(a0 + 0x10, a0 + 0x10);
    f20 = func_00283CE0(*(short *)(a0 + 0xA));
    f20 = f20 / func_00283CE0(*(unsigned char *)(s1 + 0x11));
    f22 = 1.0f - f20;
    if (*(unsigned char *)(s1 + 0x13) == 0) {
        v0 = func_00283D38_1(0x103080, *(int *)(s1 + 0xC), f22);
        v1 = *(unsigned char *)(s1 + 0x12);
        *(int *)(a0 + 4) = v0 | (v1 << 24);
        f1 = *(float *)(s1 + 0x14);
        f0 = *(float *)(s1 + 0x18);
        f0 = (f0 - f1) * f22;
        f1 = f1 + f0;
        *(float *)(a0 + 0xC) = f1;
        f0 = func_002A7798(f22);
        func_00282D30_13(buf, buf + 0x10, *(float *)(s1 + 0x1C) * f0);
    } else {
        f21 = func_00283CE0(*(unsigned char *)(s1 + 0x12));
        f20 = func_00283CE0(*(unsigned char *)(s1 + 0x12));
        f20 = f20 * func_002A7790(f22);
        v0 = func_00283CF0_2(f21 - f20);
        v1 = *(int *)(s1 + 0xC);
        *(int *)(a0 + 4) = v1 | (v0 << 24);
        func_00282D30_13(buf, buf + 0x10, *(float *)(s1 + 0x1C));
    }
    func_00282CC0_13(a0 + 0x10, buf, a0 + 0x10);
    v0 = *(unsigned char *)(a0 + 8) + *(unsigned char *)(s1 + 0x10);
    *(unsigned char *)(a0 + 8) = v0;
    if (func_00282978_3(a0 + 0xA) != 0) {
        if (*(unsigned char *)(s1 + 0x13) == 0) {
            *(unsigned char *)(s1 + 0x11) = 0x14;
            *(unsigned char *)(s1 + 0x13) = 1;
            *(short *)(a0 + 0xA) = 0x14;
        } else {
            func_002B9180_6(a0);
        }
    }
}
