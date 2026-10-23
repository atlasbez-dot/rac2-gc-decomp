/* func_L16_00410FA8 (296 bytes, 1 place) -- NEAR MISS, not integrated.
   state: 276 bytes against retail's 296; the frame and the two early exits differ.
   check.py (16_snivelak), with the source below:
     16_snivelak: 276 bytes, expected 296
   The table is reached through $gp (retail: `addiu $s2, $gp, 0x2720`), so the body
   needs a -G8 unit: `extern s16 D_L16_001B1710[4] __attribute__((sda));` gives that
   one instruction (a sized declaration is required; an incomplete type comes out
   absolute, and an oversized one likewise).
   What is measured and right:
   - the sign of the mask has to be signed: retail shifts it with `srav`, an unsigned
     mask gives `srlv`.
   - the shifted bit of the table value has to be its own variable: retail computes
     `sllv $v0, $t7, $v1` once per row and ORs it in the next step, so
     `acc |= bit;` with `bit = 1 << v;` at the end of the body is the shape.
   - the two early exits are one `||` chain each, and the value of the handle's second
     word is loaded in the delay slots, so the source reads `p[0x7E]` inside the branch
     body instead of keeping it in a variable.
   Not matched: retail's frame keeps the table base, its copy and -1 in $s0/$s1/$s2,
   while this source keeps them in caller-saved registers; retail's inner loop reads
   the table through `addu $a0, $t4, $s1` (the base plus the row offset recomputed
   per row), this source walks a pointer. Both are register-allocation differences
   that the source shape has not pinned down yet.
   Next idea: express the row element as `tbl[i * 4 + j]` with the table base copied
   into a local, so the row offset and the base are two separate induction variables. */

typedef unsigned char u8;

typedef unsigned int u32;

typedef signed short s16;

typedef signed int s32;

extern s16 D_L16_001B1710[4] __attribute__((sda));

/* Looks the two measured words of the handle up in the level's table of short rows:
   a row is scanned when its index bit is set, and the rows reached feed the next pass. */
void func_L16_00410FA8(u8 *arg0)
{
    u32 *p;
    u32 val;
    u32 idx;
    u32 w1;
    u32 w2;
    s32 mask;
    s32 acc;
    s32 bit;
    s32 i;
    s32 j;
    s16 v;
    s16 *tbl;
    s16 *row;

    p = *(u32 **)(arg0 + 0x68);
    val = p[0x7D];
    w1 = p[0x88];
    w2 = p[0x89];
    if (val == w1 || val == w2) {
        p[0x8A] = val;
        p[0x8B] = p[0x7E];
        return;
    }
    idx = p[0x7E];
    if (idx == w1 || idx == w2) {
        p[0x8A] = idx;
        p[0x8B] = val;
        return;
    }
    tbl = D_L16_001B1710;
    mask = (1 << val) | (1 << idx);
    acc = 0;
    for (;;) {
        for (i = 0; i < 8; i++) {
            if ((mask >> i) & 1) {
                row = tbl + i * 4;
                v = row[0];
                if (v != -1) {
                    j = 0;
                    bit = 1 << v;
                    for (;;) {
                        if (v == w1) {
                            p[0x8A] = v;
                            p[0x8B] = i;
                            return;
                        }
                        acc |= bit;
                        if (v == w2) {
                            p[0x8A] = v;
                            p[0x8B] = i;
                            return;
                        }
                        j++;
                        if (j == 4)
                            break;
                        v = row[j];
                        if (v == -1)
                            break;
                        bit = 1 << v;
                    }
                }
            }
        }
        mask |= acc;
    }
}
