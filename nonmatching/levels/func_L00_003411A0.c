/* func_L00_003411A0 - 280 bytes, 27 places (every level), retail at 0x003411A0.
 *
 * The body is recovered: it creates an object of type 0x6D with func_002B9030,
 * copies two 16-byte records into it, fills the header fields and stores the
 * packed identifier in the parent word.  Two things keep it from matching:
 *
 * 1. The 16-byte copies.  Retail materialises the destination pointer and
 *    uses it as the base of the MMI store with an offset of zero:
 *        addiu $v1, $s1, 0x10      (in the delay slot of the beqz)
 *        lq   $v0, 0($s0)          (quad register $v0/$v1, base $s0 = a0)
 *        sq   $v0, 0($v1)          (base $v1 = s1 + 0x10, offset 0)
 *    the tested source forms folded a constant offset into the lq/sq pair, so it emits
 *    `sq $v0, 0x10($s1)` instead.  Twenty spellings were measured (plain
 *    cast assignment, a char* destination variable, a mode(TI)* destination
 *    variable, a mode(TI) temporary, the destination used twice, the offset
 *    in a variable, a phi of two assignments, the address through an
 *    integer cast): all of them fold the offset.  The only way to keep the
 *    address in a register is a pointer with two assignments, and that one
 *    costs a branch and an `addu` instead of the `addiu` retail has.
 *
 * 2. The guard.  Retail branches to the shared `daddu $v0, $s1, $zero` that
 *    returns the object pointer; this cc1 moves that copy into the
 *    fall-through path and branches straight to the epilogue, because in the
 *    taken path the value is already in $v0.
 *
 * tools/check.py func_L00_003411A0 --diff: 284 bytes, expected 280, and the
 * two lq/sq words differ as described.
 */
typedef int V4_F61e33ad9 __attribute__((mode(TI)));

extern char *func_002B9030(int kind);
extern int func_002A77E0(int a);
extern int func_002A7820(int a, int b);
extern char *D_L00_001FEAF4;
extern int func_00283CF0_2(float f);
extern int func_00283D38_1(int a, int b, float f);
extern float func_002A7878_3(float a, float b);

char *func_L00_003411A0(char *a0, char *a1, char *a2, float f)
{
    char *s1 = func_002B9030(0x6D);
    char *s0;
    float f2;

    if (s1) {
        s0 = s1 + 0x20;
        *(V4_F61e33ad9 *)(s1 + 0x10) = *(V4_F61e33ad9 *)a0;
        *(unsigned char *)(s1 + 3) = *(unsigned char *)a2;
        *(unsigned char *)(s1 + 1) = 0;
        *(unsigned char *)(s1 + 9) = func_00283CF0_2(4.0f) + 0x40;
        *(unsigned char *)(s1 + 8) = func_002A77E0(0xFF);
        *(unsigned char *)(s1 + 2) = *(unsigned char *)D_L00_001FEAF4;
        *(unsigned short *)(s1 + 0xA) = func_002A7820(5, 0x32);
        *(V4_F61e33ad9 *)(s0) = *(V4_F61e33ad9 *)a1;
        *(float *)(s1 + 0xC) = f * 131250.0f;
        *(unsigned int *)(s0 + 0x10) = func_002A7820(0x40, 0x80);
        f2 = func_002A7878_3(0.0f, 0.5f);
        *(unsigned int *)(s1 + 4) = func_00283D38_1(0x103080, 0, f2) |
                                    (*(unsigned int *)(s0 + 0x10) << 24);
    }
    return s1;
}
