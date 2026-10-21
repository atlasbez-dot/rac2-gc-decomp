/* Near miss from src/levels/26_jamming_array/L26_002EC840-g8.c: the build refuses this body at its
   place — instruction at +0x0 differs. Kept as a starting point;
   not linked, not counted. */

/* Standalone declarations recovered from src/levels/26_jamming_array/L26_002EC840-g8.c. */
typedef unsigned char u8;

typedef unsigned short u16;

extern u8 *D_L26_001B1C1C __attribute__((sda));

extern unsigned char D_L26_001FA6E0[];

void func_L26_003DC128(u8 *a0) {
    u8 st = *(u8 *)(a0 + 0x21);

    if (st != 0xFF) {
        u8 *v0 = *(u8 **)(D_L26_001FA6E0 + (st << 2));

        if (v0 != 0) {
            u8 *a2 = D_L26_001B1C1C;
            int t0 = 0xC8E;

            do {
                int a1 = (int)(a2 + (((*(u16 *)v0) & 0x7FFF) << 8));

                if (*(signed char *)(a1 + 0x20) >= 0 && *(short *)(a1 + 0xAA) == t0)
                    *(short *)(*(int *)(a1 + 0x68) + 0x226) = 1;
                v0 += 2;
            } while (*(short *)v0 >= 0);
        }
    }
}

/* ---------------------------------------------------------------------------
 * wave 24, worker 14: the loop matches byte for byte and the body is 124 bytes,
 * the retail's size; check.py: "instruction at +0x10 differs".  What matches: the
 * branch-likely pair `bltzl`/`bnel` with the `lh` in both delay slots, the `bgez`
 * with the `addiu $a0,$a0,0x2` in its slot, the `sh $a3,0x226($v0)`, the table
 * entry copied into the loop pointer (`daddu $a0,$v0,$zero`) and the base global
 * read in the beqz delay slot (`lw $a2,0x2C2C($gp)`).
 * What differs is one instruction in the prologue.  Retail keeps the index in a
 * register of its own (a copy of the byte, `daddu $v1,$v0,$zero`) and reuses $v0
 * for the table's %hi; this cc1 folds the index into the byte's register and
 * shifts it in place, so the table address ends up in $v0 and the index in $v1.
 * The front end does create the copy (rtl: `(set 96 89)` before the `ashift`),
 * but cse propagates it: the comparison's value and the index's value are both
 * the `zero_extend` of the same byte load, so cse merges them and the copy dies.
 * Retail's two values must be structurally different.  Because the prologue is one
 * instruction shorter, this cc1's loop lands one word early and the assembler's
 * `.p2align 3` before the loop fills the gap with a `nop` (the retail's loop
 * starts aligned, so it has none).
 * Tried: the index as u8, as int, as a copy of a u8 local, the byte read twice
 * (the front end then makes two zero_extend values and cse merges them anyway),
 * the table entry in a separate `u32 *` variable (that part matches retail), the
 * base global loaded after the table lookup (that part matches too).
 * What would unblock it: a spelling that keeps the comparison's value and the
 * index's value apart, so that the copy survives cse.
 */

typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;

void func_L26_003DC128_w24(u8 *a0) {
    u32 *entry;
    u8 *base;
    u8 *rec;
    u8 *r;
    int idx;
    s16 cur;

    if (a0[0x21] == 0xFF) return;
    idx = a0[0x21];
    entry = *(u32 **)(D_L26_001FA6E0 + 4 * idx);
    base = D_L26_001B1C1C;
    if (entry == 0) return;
    rec = (u8 *)entry;
    for (;;) {
        r = base + ((*(u16 *)rec & 0x7FFF) << 8);
        if (*(s8 *)(r + 0x20) >= 0) {
            if (*(s16 *)(r + 0xAA) == 0xC8E) {
                *(u16 *)(*(u32 *)(r + 0x68) + 0x226) = 1;
            }
        }
        cur = *(s16 *)rec;
        rec += 2;
        if (cur >= 0) continue;
        break;
    }
}
