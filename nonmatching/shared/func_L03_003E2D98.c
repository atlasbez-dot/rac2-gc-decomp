/* func_L03_003E2D98 (near miss, level 03 endako, 304 bytes at 8 places).
 *
 * The body is read from the retail bytes: it takes five arguments, the fifth
 * in $t0 (this compiler's convention for the fifth argument, as
 * func_L03_00419B10 shows for its fifth and sixth), reads the record at
 * a0+0x68, draws a start offset with func_002A77E0(6) and walks six entries
 * of the table at 0x0024A7B0 + a1, each four bytes.  For every entry it
 * looks for the value in the bytes at rec+0x20 (a2+2 of them) and in the
 * words at a3 (a4 of them); an entry that is found sends the walk on, one
 * that is not returns -1, and so does the end of the walk.
 *
 * Checked in the original unit (src/levels/shared/L03_003C5B28.c): 296 bytes
 * against retail's 304.  The division, its divide-by-zero check (beql with a
 * break 7 in the annulled slot - the divisor has to be a variable for that
 * shape) and the table address are right; what is left is the retail's
 * multiply of a1 by 24 (mult $s0,$s0,24), whose result no instruction uses
 * (the div overwrites $lo and $hi and nothing between them reads them), and
 * the mapping of the arguments to the saved registers (retail: a1 in $s0, the
 * fifth argument in $s1, a3 in $s2, a2 in $s3, the record in $s4).
 */

typedef unsigned char u8;

typedef unsigned int u32;

typedef int s32;

extern u32 D_0024A7B0;

extern s32 func_002A77E0(s32);

s32 func_L03_003E2D98(u8 *a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    u8 *rec = *(u8 **)(a0 + 0x68);
    s32 start = func_002A77E0(6);
    s32 six = 6;
    s32 i;
    u32 v;
    u32 found;

    for (i = 0; i < six; i++) {
        s32 index = (i + start) % six;
        u32 j;

        v = *(u32 *)((u8 *)&D_0024A7B0 + (a1 + index * 4));
        if (v == 0xFFFFFFFF)
            continue;
        found = 0;
        for (j = 0; j < a2 + 2; j++) {
            if (rec[0x20 + j] == v)
                found = 1;
        }
        for (j = 0; j < a4; j++) {
            if (((u32 *)a3)[j] == v)
                found = 1;
        }
        if (found == 0)
            return -1;
    }
    return -1;
}
