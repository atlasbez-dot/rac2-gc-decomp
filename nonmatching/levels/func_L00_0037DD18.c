/* 0 of 27 places match - candidate is 112 bytes against 100.
 *
 * What is now known about the body (from the sibling file L00_0037DD80.c, which holds
 * the matched function of the same family):
 *   - the table is 32 sixteen-byte records at D_L00_00231340, with the words used here
 *     at +0 (field00), +4 (field04, the free marker) and +8 (field08);
 *   - retail keeps 0x230000 in $t2 (the page the records sit in, at +0x1340) and the
 *     record array at 0x231340 in $v0, stores the peeled entry as `sw $a1,0x1340($t2)`
 *     and, in the loop, `addiu $t1,$t2,0x1340` plus `sll $a3,$t0,4` (the index scaled
 *     per iteration, no walking pointer).
 *
 * What this cc1 does instead: it strength-reduces `entry[i]` into a pointer walk
 * (`addiu $t1,$t1,0x10`), which costs the 12 extra bytes. With -fno-strength-reduce
 * the candidate is 108 bytes and the index stays scaled, but the loop shape is still not
 * retail's (retail's test is at the top of the body with the increment in the branch's
 * delay slot, ours is at the bottom).
 *
 * Tried: the record array as a member of a page struct at 0x230000 and as the symbol
 * D_L00_00231340, the page computed as D_L00_00231340-0x1340, the store orders
 * (field00, field04, field08) and (field08, field04, field00), a for loop and a
 * while loop with the increment in the body, and -fno-strength-reduce.
 *
 * To retake: the source form that keeps the scaled index (`sll $a3,$t0,4`) and the
 * base re-materialised inside the loop (`addiu $t1,$t2,0x1340`), plus the loop test
 * at the top of the body.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

typedef struct {
    u32 field00, field04;
    s32 field08;
    u8 gap0c[4];
} Entry;

typedef struct {
    u8 pad00[0x1340];
    Entry entry[32];
} Page;

extern u8 D_L00_00231340[];

void func_L00_0037DD18(int a0, int a1, int a2)
{
    Page *page = (Page *)((u8 *)D_L00_00231340 - 0x1340);
    int i;

    if (page->entry[0].field04 == 0) {
        page->entry[0].field00 = a1;
        page->entry[0].field08 = a2;
        page->entry[0].field04 = a0;
        return;
    }
    for (i = 1; i < 32; i++) {
        if (page->entry[i].field04 == 0) {
            page->entry[i].field08 = a2;
            page->entry[i].field04 = a0;
            page->entry[i].field00 = a1;
            return;
        }
    }
}
