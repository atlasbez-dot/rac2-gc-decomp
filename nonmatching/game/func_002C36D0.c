/* func_002C36D0 - near miss (not linked).
 *
 * Boot 0x002C36D0, 268 bytes, 28 places (boot + 27 levels).
 *
 * The shape is right: the frame (0x40), the six saved registers, the
 * materialised 16-byte copy, the colour constant, the two helper calls, the
 * `slti`/`movz` pair that clears the index, the byte table lookup and the
 * 127.0f division all come out as the retail has them.
 *
 * What still differs:
 *  - the register assignment: the retail puts the sub-object base in $s0 and
 *    the object in $s1, this version puts the object in $s0 and the base in
 *    $s3 (the parameters keep their relative order).  The local allocator
 *    (local-alloc.c, `qty_compare` / `QTY_CMP_PRI`) ranks the quantities by
 *    log2(refs) * refs * size / (death - birth) inside a basic block, so the
 *    base has to be born late in the RTL to outrank the object; every
 *    spelling tried (base assigned before the test, inside the test, as an
 *    initialiser, base used for the short store as well) keeps the object
 *    in the lower register.
 *  - the 16-byte copy is scheduled after the colour constant instead of
 *    before it.
 *  - the order of `swc1 $f0,0xC` and `sb $v1,3` around the 0xFF constant.
 *
 * The unit needs the `-frac2-qcopy` profile: the retail's copy keeps both
 * addresses in registers (`addiu $a0,$s1,0x10` / `lq $v0,0($s3)` /
 * `sq $v0,0($a0)`), the default profile folds the destination offset into
 * the `sq`.  The matched functions of 002BF6F0.c use the folded form, so the
 * creator family cannot live in that unit.
 */
extern char *func_002B9030(int size);
extern int func_00283CF0_6(float f);
extern int func_002A77E0(int v);
extern float func_00283CE0_2(int index);
extern unsigned char *D_001F2638;

char *func_002C36D0(char *p0, int p1, int p2, int p3)
{
    char *s0 = 0;
    char *s1 = func_002B9030(0x3E);
    int v;
    float f;

    s0 = s1 + 0x20;
    if (s1 != 0) {
        *(V4_Fc3cb9262 *)(s1 + 0x10) = *(V4_Fc3cb9262 *)p0;
        *(unsigned int *)(s1 + 4) = 0x7F7F4040;
        v = func_00283CF0_6(4.0f);
        *(float *)(s1 + 0xC) = 30000.0f;
        *(unsigned char *)(s1 + 1) = 0;
        *(unsigned char *)(s1 + 3) = 0x48;
        *(unsigned char *)(s1 + 9) = v + 0x40;
        v = func_002A77E0(0xFF);
        *(unsigned char *)(s1 + 8) = v;
        *(unsigned char *)(s0 + 2) = p2;
        if (p2 >= 2) {
            p2 = 0;
        }
        *(unsigned char *)(s0 + 3) = p3;
        *(unsigned char *)(s1 + 2) = D_001F2638[p2];
        f = func_00283CE0_2(p1);
        *(short *)(s0 + 0) = func_00283CF0_6(127.0f / f);
        *(short *)(s1 + 0xA) = p1;
    }
    return s1;
}
