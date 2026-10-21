/* Near miss for func_00292B20 (100 bytes, retail, 28 places: the boot and the 27 levels).
 *
 * The first 0x28 bytes are exact: the size is rounded up to sixteen with an
 * unsigned mask (0xFFFFFFF0, built with `lui`/`ori`), the test on it is a plain
 * `beqz` whose delay slot copies the object pointer into `$s0`, and the two
 * halves of the body are the loader call and the clearing of the object's entry.
 *
 * What is left is the register allocation of the two halves:
 *  - in the loader call, retail keeps the base of the loaded segment in `$a0`
 *    (re-using the register of the materialised address) and the chunk it holds
 *    in `$v1`, and adds them as `addu $a0,$v1,$a0`; this cc1 keeps the base in
 *    `$a2` and the chunk in `$a0`, and adds them the other way round;
 *  - in the second half, retail loads the table pointer into `$v0` (re-using the
 *    register of the materialised address) and scales the index into `$v1`, so
 *    the add is `addu $v0,$v0,$v1`; this cc1 scales the index into `$a0`, loads
 *    the pointer into `$a1` and adds them the other way round.
 *
 * Tried: the mask as a signed and as an unsigned constant, the pointer and the
 * index written in either order in the add, the table entry reached through a
 * `char *` offset and through an array index, and the base kept in a local or
 * read twice from the global.  The shape of the two adds is the only thing that
 * changes.
 *
 * The table pointer is a per-program address: 0x001B1BC8 in the boot and in the
 * levels, and the loaded segment is at 0x001A7288.
 */
typedef int s32;
typedef unsigned int u32;

extern s32 D_001A7288;
extern s32 *D_L00_001B1BC8;
extern void func_0029D4D0(int, int);

/* Hand the chunk of the loaded segment the object lives in back to the loader
   and clear the object's entry in the table of the loaded segments. */
void func_00292B20(int a0, int a1)
{
    int s0 = a0;
    u32 size = (a1 + 0xF) & 0xFFFFFFF0u;

    if (size) {
        int base = D_001A7288;
        int *t = (int *)((char *)base + s0 * 8);
        int v = t[8];
        func_0029D4D0(v + base, (int)size);
    }
    {
        s32 *b = D_L00_001B1BC8;
        s32 *q = b + s0;
        q[0x1D] = 0;
    }
}
