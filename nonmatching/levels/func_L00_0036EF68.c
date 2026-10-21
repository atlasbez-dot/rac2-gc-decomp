/* 0 of 14 places match - last line: 00_aranos_tutorial: 236 bytes, expected 248
 *
 * The attribute writer of func_L00_0036EF68. The body packs three six-bit
 * fields into the block's three words, sets a bit in a byte, and then walks the
 * slot list the block points at, writing the packed value into each slot.
 *
 * What was measured and works:
 *  - the block's own table is reached with `lw $at, 0x3534($gp)`, which only
 *    comes out of a -G8 unit with an `sda` declaration (in a -G0 unit the same
 *    access comes out as lui+addiu+lw, one instruction too many);
 *  - the mask is `~0x3F` written with a signed int, so the constant is -64 and
 *    comes out as `addiu $v1,$zero,-0x40` in a register; `0xFFFFFFC0u` would
 *    come out as lui+ori;
 *  - the three arguments are shifted in place (`srl $a1,$a1,2`) and the packed
 *    value reuses them (`sll $a1,$a1,2`), so the source shifts the parameters
 *    once and uses the shifted values in both places;
 *  - the loop is a do-while with the decrement at the top of the body and the
 *    test at the bottom, guarded by the 16-bit value read at record+0x78.
 *
 * What still differs (12 bytes):
 *  - this cc1 copies the block pointer with `daddu $t1,$a0,$zero` (a 64-bit
 *    copy) and then uses $t1 for every field access, where retail keeps the
 *    pointer in $a0 and loads into $at/$v0/$v1; the copy appears with a
 *    struct pointer, with an int * and with a char * parameter alike;
 *  - the shifts of the arguments land in $t3/$t4 instead of in place, and the
 *    schedule of the first part is one load short of retail's.
 */
extern unsigned int ref_L00_0036EF68_00 __attribute__((sda));

extern unsigned int D_L00_00226700[];

/* The record the block points at: a base pointer and the list of slots. */
typedef struct {
    unsigned char pad00[0x34];
    unsigned int f34;
} Record;

/* The table the block indexes: rows of 16 bytes. */
typedef struct {
    unsigned char pad00[16];
} Row;

void func_L00_0036EF68(int *a, unsigned int a1, unsigned int a2, unsigned int a3)
{
    unsigned int value;
    unsigned int base;
    Row *rows;
    Record *record;
    unsigned short *q;
    unsigned int off;
    int index;
    int n;
    int count;

    a[0] = (a[0] & ~0x3F) | (a1 >>= 2);
    a[1] = (a[1] & ~0x3F) | (a2 >>= 2);
    a[2] = (a[2] & ~0x3F) | (a3 >>= 2);
    *(unsigned char *)((char *)a + 0x1E) |= 2;
    if (*(unsigned short *)((char *)a + 0x14) == 0xFFFF)
        return;

    index = *(unsigned short *)((char *)a + 0x14);
    rows = (Row *)(*(unsigned int *)ref_L00_0036EF68_00);
    base = (unsigned int)(rows + index);
    record = (Record *)D_L00_00226700[*(unsigned char *)((char *)a + 0x1D)];
    value = (a1 << 2) | (a2 << 10) | (a3 << 18) | 0x8000u;

    n = *(unsigned short *)((unsigned char *)record + *(unsigned char *)((char *)a + 0x1F) * 2 + 0x78);
    q = (unsigned short *)(record->f34 + n);
    if (n != 0) {
        count = q[0];
        off = q[1];
        q += 2;
        do {
            count--;
            *(unsigned int *)(base + off) = value;
            off = *q++;
        } while (count > 0);
    }
}
