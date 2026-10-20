/* Near miss (wave 7 tour 2, agent lvl7-03): 156 bytes against retail's 184, level 20 only.
 *
 * The "list walk" family of L01_003CAFE0-g8.c / L04_00422A00-g8.c, with a counter and a
 * wrap-around tail. Decoded: index the slot table at 0x001FBB20 with the raw argument, bail
 * on `(arg & 0xFF) == 0xFF`, on `D_L20_001B2FB8 < arg` and on a null slot, then walk the
 * 0x7FFF-masked u16 id list hanging off that slot, `e = D_L20_001B2F9C + ((*p & 0x7FFF) << 8)`,
 * counting the entries whose class byte `e[0x20]` is not 6 (retail spells it `lbu`, so the
 * element pointer is `unsigned char *`), and return the count.
 *
 * Retail's loop tail is
 *     120 beq   $a2,$t2,END        ; (arg & 0xFF) == 0xFF -> exit
 *     124 movn  $a3,$v1,$v0        ; count += (e[0x20] != 6)
 *     128 bnez  $t0,END            ; $t0 is ZERO and never written
 *     12C nop
 *     130 beqz  $a1,END            ; $p is never null
 *     134 nop
 *     138 lh    $v0,-0x2($a1)      ; the entry just consumed
 *     13C bgezl $v0,LOOP           ; still inside the chain -> continue
 *     144 lw    $v0,0x0($a0)       ; the list head
 *     148 beql  $a1,$v0,LOOP       ; wrapped back to the head -> continue
 * i.e. `while (!((s16)p[-1] < 0 && p != list))`, plus THREE guards this cc1 folds away as
 * provably dead (retail materialises `$t0 = 0` and still tests it). That is the whole
 * 7-instruction / 28-byte gap; every other instruction matches. The two `continue` branches
 * are written as two separate `if (...) continue;` in the C below, which is what reproduces
 * the two backward branches, and `e` is `unsigned char *` for the `lbu`.
 *
 * What would unblock it: finding the construct that makes cc1 keep a guard test on a value it
 * proves is 0, and on a pointer it proves non-null. No call, volatile or memory read is
 * obvious in the body, so a macro or an inlined helper in the original is the likely source.
 */

extern char *D_L20_001FBB20[];

extern char *D_L20_001B2F9C;

extern int D_L20_001B2FB8;

int func_L20_0039E0A0(unsigned int a0)
{
    unsigned int slot = a0 & 0xFF;
    int count = 0;
    char *list;
    unsigned short *p;
    char *base;
    unsigned char *e;

    if (slot == 0xFF)
        return count;
    list = D_L20_001FBB20[a0];
    if (D_L20_001B2FB8 < (int)a0)
        return count;
    if (list == 0)
        return count;
    p = (unsigned short *)list;
    base = D_L20_001B2F9C;
    for (;;) {
        e = (unsigned char *)(base + ((*p & 0x7FFF) << 8));
        if (e == 0)
            break;
        if (e[0x20] != 6)
            count++;
        p++;
        if (slot == 0xFF)
            break;
        if ((short)*(p - 1) >= 0)
            continue;
        if ((char *)p == list)
            continue;
        break;
    }
    return count;
}

/* ---- second attempt (level-20 wave, 2026-10-20) ---------------------------------------
 * The same list walk, with the three guards the earlier attempt spelled as separate
 * `if (...) break;` statements inside the loop body and the element pointer computed
 * from the `u16` word of the current record.  Measured: still short -- the retail
 * materialises `$t0 = 0` and still tests it, and this compiler folds all three
 * provably-dead guards away.  Kept as the starting point; not linked, not counted.
 */

extern int D_L20_001B2FB8;

int func_L20_0039E0A0(int index)
{
    u16 *rec = (u16 *)D_L20_001FBB20[index];
    int count = 0;
    int x = index & 0xFF;
    int t = 0;
    u16 w;

    if (x == 0xFF) {
        return 0;
    }
    if (D_L20_001B2FB8 < index) {
        return 0;
    }
    if (rec == 0) {
        return 0;
    }
    w = *rec;
    do {
        char *p = D_L20_001B2F9C + ((w & 0x7FFF) << 8);

        if (p == 0) {
            break;
        }
        if (x == 0xFF) {
            break;
        }
        if (t != 0) {
            break;
        }
        if (*(u8 *)(p + 0x20) ^ 6) {
            count++;
        }
        rec++;
        if (rec == 0) {
            break;
        }
        w = *rec;
    } while (*(s16 *)(rec - 1) >= 0 || rec == (u16 *)D_L20_001FBB20[index]);
    return count;
}
