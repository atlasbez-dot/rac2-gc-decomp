/* func_L02_003D18D8 (192 bytes, 1 place) - same family as func_L02_003CD5B0; first C
 * attempt measured at 184 bytes against 192 (scratch/wslcmp.py).
 *
 * Same u16 id list and same base table (D_L02_001FC060 indexed by `lbu 0x21($a0)`,
 * D_L02_001B359C as the base, both read through $gp - so a -G8 unit), same
 * `while ((s16)*p++ >= 0)` skeleton.  The predicate chain per entry is: reject
 * `*(u8*)(e+0x20) == 0xFE`, reject `== 0xFD`, require `*(s16*)(e+0xAA) == 0x9CA`,
 * require `*(u8*)(e+0x95) == 6`, then answer 1 when
 * `*(s16*)(*(u8**)(e+0x68) + 0x2F6) == 1`.
 * The residue is layout: this cc1 rematerialises `sll $a1,16` into every delay slot (retail
 * has it in all five), and the `beql $v0,$t3` at 0x003D1950 needs the shifted value annulled
 * on the fall-through so that `beq $v0,$t2` at 0x003D1958 still sees the `lbu` result - the
 * shape cc1 produced here reloaded instead and came out 2 words short.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;

extern u8 *D_L02_001B359C __attribute__((sda));
extern u8 *D_L02_001FC060[];

int func_L02_003D18D8(u8 *a0) {
    u8 *base = D_L02_001B359C;
    u16 *p;
    u8 *e;

    if (*(u8 *)(a0 + 0x21) == 0xFF)
        return 0;
    p = (u16 *)D_L02_001FC060[*(u8 *)(a0 + 0x21)];
    if (p == 0)
        return 0;
    do {
        e = base + ((*p & 0x7FFF) << 8);
        if (e != 0) {
            if (*(u8 *)(e + 0x20) == 0xFE)
                goto next;
            if (*(u8 *)(e + 0x20) == 0xFD)
                goto next;
            if (*(s16 *)(e + 0xAA) != 0x9CA)
                goto next;
            if (*(u8 *)(e + 0x95) != 6)
                goto next;
            if (*(s16 *)(*(u8 **)(e + 0x68) + 0x2F6) == 1)
                return 1;
        }
    next:
        ;
    } while ((s16)*p++ >= 0);
    return 0;
}
