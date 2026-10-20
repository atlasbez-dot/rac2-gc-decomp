/* EXACT under tools/check.py (1 of 1 places match), kept here because it needs one construct the
 * small-function rules forbid: a redundant `&& q != 0` written after the last conjunct of the
 * loop condition. 208 bytes, level 2 only. It belongs in
 * src/levels/02_maktar_nebula/L02_003DB310-g8.c (it reads D_L02_001B35B8 through $gp), in
 * address order, with its marker line taken out of L02_003DB310.c.
 *
 * What the function is: 0 when one of the entities of the 0x7FFF-masked u16 list hanging off
 * the object's group byte (+0x21) is class 0xAB0 and its state byte (+0x20) is not 6 or 7;
 * otherwise 1. The list is walked like the other "list walk" rows (func_L02_003CD8C0,
 * func_L02_003CEBB8, func_L02_003FB4D8, func_L20_0039E0A0): the walk goes on while the group byte
 * is not 0xFF, is not above the level's group count (D_L02_001B35B8), the pointer is not null,
 * and the entry just consumed was not the last one (bit 15 clear) or the pointer is back on the
 * table's first entry.
 *
 * Why that family stopped ~12 bytes and 40-50 differing lines short (measured 2026-10-20):
 *
 * 1. Retail's loop is not rotated: `b TEST`, the body, then the whole test chain at the bottom
 *    with the two `bgezl`/`beql` back branches. With the natural
 *    `while (A && B && C && (D || E))` this cc1 rotates it: jump.c copies the exit test in front
 *    of the loop (folding `q == first` away in the copy) and loop.c then hoists constants and
 *    loads, 220 bytes. The copy is skipped when the exit test holds a label at the first jump
 *    pass. A `||` group that is NOT last does that, an inlined helper does that, and so does ANY
 *    foldable conjunct written after the `||` group: `&& q != 0`, `&& q` and a repeated
 *    `D_L02_001B35B8 >= IDX` all give retail's layout, and cse deletes the redundant test
 *    afterwards so nothing of it is left in the bytes. (`&& IDX != 0xFF` as the tail, `!= 0`,
 *    `!!`, `== 1` and casts around the `||` group do not work.)
 * 2. The base load `lui $v1,%hi ; lw $v1,%lo($v1)` uses one register because it is a BARE
 *    symbol load that gas expands, not cc1's explicit high/lo pair (that one allocates two
 *    registers and shifts everything after it). In a -G8 unit the bare form needs the symbol
 *    declared `sda` AND with a size over 8, so that gas does not make it a $gp access:
 *    `char *X[3]`, read as `X[0]`.
 * 3. `e == 0` leaves the loop with `break` (retail branches straight to the shared
 *    `return 1`); the found-test keeps `return 0`, and cc1 moves that return block in front of
 *    the loop by itself, which is where retail has it (`ret 1`, `ret 0` right after the first
 *    branch).
 *
 * What needs a ruling is point 1. Without the tail test the best this file can do is 212 bytes
 * (46 differing lines). With it this function, func_L02_003EAD38 and func_L02_003CD8C0 (2 of 2
 * places in a scratch build, its two halfword stores written in the reverse order) are exact.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

extern char *D_L02_001B359C[3] __attribute__((sda));
extern int D_L02_001B35B8 __attribute__((sda));
extern u32 D_L02_001FC060[];

int func_L02_003EAFC8(char *arg0) {
    u16 *q;
    char *e;

    if (*(u8 *)(arg0 + 0x21) == 0xFF)
        return 1;
    q = (u16 *)D_L02_001FC060[*(u8 *)(arg0 + 0x21)];
    while (*(u8 *)(arg0 + 0x21) != 0xFF && D_L02_001B35B8 >= *(u8 *)(arg0 + 0x21) && q != 0 &&
           ((s16)q[-1] >= 0 || q == (u16 *)D_L02_001FC060[*(u8 *)(arg0 + 0x21)]) && q != 0) {
        e = D_L02_001B359C[0] + ((*q & 0x7FFF) << 8);
        if (e == 0)
            break;
        q++;
        if (*(s16 *)(e + 0xAA) == 0xAB0 && (u8)(*(u8 *)(e + 0x20) - 6) >= 2)
            return 0;
    }
    return 1;
}
