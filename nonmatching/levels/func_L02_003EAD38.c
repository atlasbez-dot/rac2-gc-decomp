/* EXACT under tools/check.py (1 of 1 places match), kept here because it needs the one construct
 * the small-function rules forbid: a redundant `&& q != 0` written after the last conjunct of
 * the loop condition. 216 bytes, level 2 only. It belongs in
 * src/levels/02_maktar_nebula/L02_003DB310-g8.c (it reads D_L02_001B35B8 through $gp), in
 * address order, with its marker line taken out of L02_003DB310.c.
 *
 * Sibling of func_L02_003EAFC8 (same list walk, same loop condition, the reasons are written up
 * in nonmatching/levels/func_L02_003EAFC8.c: the trailing test stops cc1 from rotating the
 * loop, and the base global is a bare `sda` symbol declared with a size over 8 so that gas
 * expands it to `lui $v1 ; lw $v1,%lo($v1)` in the one register). Here the body is the action
 * instead of the search: for each entity of the group's list that has class 0xAB0, byte +0x20 is
 * set from the first word of its private data (+0x68): 1 -> 6, 2 -> 7, anything else -> 3.
 * The idx byte (+0x21) is re-read at every iteration because the store to +0x20 may alias it
 * (retail keeps the object in $a3 for that and reloads it).
 *
 * Without the tail test the natural `while` is rotated and has its constants hoisted: 248 bytes
 * with a plain nosda base, 244 with the bare sda base. The one construct that keeps cc1 from
 * rotating without a redundant test is a hand-made loop entered with `goto test` into a
 * `for (;;)` whose test chain ends in `if (D) continue; if (E) continue; return;`. That gives
 * 216 bytes (retail's size) with 12 differing lines, all in the 8-instruction preamble before
 * `b test` (the table address `lui`/`addiu` pair lands in other registers and the copy of `hi`
 * into $t0 is scheduled before the `addiu` instead of in the branch's delay slot); 720
 * spellings of that preamble (compare and index from the memory byte or from a u8/u32/int
 * local, `if (idx != 0xFF) { ... }` wrapping, declaration order, three spellings of the 0x7FFF
 * walk, switch or ?: for the 6/7/3 store) did not move it. The same hand-made form does not
 * reach func_L02_003EAFC8 (200 to 204 bytes there: loop.c skips a loop entered in the middle, so
 * the hoisted copies and the return block layout of retail are missing).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

extern char *D_L02_001B359C[3] __attribute__((sda));
extern int D_L02_001B35B8 __attribute__((sda));
extern u32 D_L02_001FC060[];

void func_L02_003EAD38(char *arg0) {
    u16 *q;
    char *e;

    if (*(u8 *)(arg0 + 0x21) == 0xFF)
        return;
    q = (u16 *)D_L02_001FC060[*(u8 *)(arg0 + 0x21)];
    while (*(u8 *)(arg0 + 0x21) != 0xFF && D_L02_001B35B8 >= *(u8 *)(arg0 + 0x21) && q != 0 &&
           ((s16)q[-1] >= 0 || q == (u16 *)D_L02_001FC060[*(u8 *)(arg0 + 0x21)]) && q != 0) {
        e = D_L02_001B359C[0] + ((*q & 0x7FFF) << 8);
        if (e == 0)
            break;
        if (*(s16 *)(e + 0xAA) == 0xAB0) {
            int t = **(int **)(e + 0x68);

            *(u8 *)(e + 0x20) = (t == 1) ? 6 : ((t == 2) ? 7 : 3);
        }
        q++;
    }
}
