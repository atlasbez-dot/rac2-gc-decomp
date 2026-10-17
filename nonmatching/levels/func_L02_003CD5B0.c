/* func_L02_003CD5B0 (184 bytes, 1 place) - structure read, first C attempt measured at
 * 152 bytes against 184 (scratch/wslcmp.py; `check.py` not run - the size is already wrong).
 *
 * This is the "id list" family the sixth wave's sibling recipe describes: a u16 array whose
 * entries are `(id & 0x7FFF) << 8` offsets into the base at D_L02_001B359C, walked with
 * `while ((s16)*p++ >= 0)`, which is what produces the `lh -0x2($s0)` + `bgezl` pair at
 * 0x003CD640/0x003CD644.  Entry guards: `lbu 0x21($a0) == 0xFF` -> 0,
 * `D_L02_001B35B8 < a0` -> 0, `D_L02_001FC060[a0] == 0` -> 0; an extra `beql $a1,$v0`
 * back-edge compares the cursor with that same table slot.
 * What the first attempt missed (those 8 missing words): the loop also carries an
 * `a2 == 0xFF` re-test inside the body (`beq $a2,$t1` at 0x003CD628) and two always-taken
 * dead guards (`bnez $a3` at 0x003CD630 with $a3 forced to 0 at 0x003CD600, and
 * `beqz $a1` at 0x003CD638 right after `addiu $a1,$a1,0x2`), so the original is a hand
 * rolled `for (;;)` with explicit breaks rather than a plain do-while; the reachable guards
 * were not enough to make cc1 lay those two blocks out.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;

extern u8 *D_L02_001B359C __attribute__((sda));
extern unsigned D_L02_001B35B8;
extern u8 *D_L02_001FC060[];

u8 *func_L02_003CD5B0(unsigned a0) {
    u8 *base = D_L02_001B359C;
    unsigned idx = a0 & 0xFF;
    u16 *p;
    u8 *e;

    if (idx == 0xFF)
        return 0;
    if (D_L02_001B35B8 < a0)
        return 0;
    p = (u16 *)D_L02_001FC060[a0];
    if (p == 0)
        return 0;
    do {
        e = base + ((*p & 0x7FFF) << 8);
        if (e == 0)
            return 0;
        if (*(u8 *)(e + 0x20) == 0x17)
            return e;
        if (idx == 0xFF)
            return 0;
        if (p == (u16 *)D_L02_001FC060[a0])
            continue;
    } while ((s16)*p++ >= 0);
    return 0;
}
