/* Near miss for func_00294070 (80 bytes, retail, 28 places: the boot and the 27 levels).
 *
 * The first half is exact: the table base is materialised with `lui`/`addiu`, the
 * index is scaled by four, the entry is read at +0x74 and copied to +0x70 of the
 * table, the world update runs (its call sits in the delay slot of the copy) and
 * the two counters are added and stored back.
 *
 * What is left is four instructions, the two `lui` and the two `lw` of the sum:
 * retail materialises the first counter in `$v1` and the second in `$a0`, loads
 * the second into `$a0` (re-using its own base register) and the first into
 * `$v0`, the destination of the add; this cc1 materialises both in `$a0`/`$a1`,
 * loads them into `$v0`/`$v1` and adds them the other way round.  The order of
 * the two operands does not follow the source: with the globals, with a local
 * for either of them, and with the sum written in either order, this cc1 always
 * emits the same four words.
 *
 * The two globals are per-program addresses: 0x001B22B0 and 0x001BAED0 in the
 * boot, 0x001B2610 and 0x001BF150 in level 00, so the names carry the level.
 */
typedef int s32;

/* The table of the loaded segments: the current chunk and the per-object list. */
struct SegTable {
    s32 pad[0x1C];
    s32 cur;
    s32 entry[1];
};

extern struct SegTable D_L00_001BFCAC0;
extern s32 D_L00_001BF150;
extern s32 D_L00_001B2610;
extern void func_00293D30(void);

/* Copy one entry of the table at D_L00_001BFCAC0 into its first slot, let the
   world update run, then store the sum of the two counters in the same slot. */
void func_00294070(int index)
{
    struct SegTable *p = &D_L00_001BFCAC0;

    p->cur = p->entry[index];
    func_00293D30();
    p->cur = D_L00_001B2610 + D_L00_001BF150;
}
