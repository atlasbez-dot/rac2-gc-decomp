/* Near miss (wave 7, agent lvl7-03): size EXACT at 192 bytes / 27 places, one register apart.
 *
 * Decoded in full. Re-bases the three pointer blocks the record's header words select:
 *   +0x00 -> the block's address is published at 0x001BF200;
 *   +0x04 -> the block's address is published at 0x001B1AC0 (and 0x001B1AC0 is zeroed when
 *            the header word is 0);
 *   +0x08 -> the same with 0x001B1AC4.
 * Each non-zero block is walked `count` times adding its own base to the 16-byte-strided
 * pointer fields starting at +0x1C (`*q = (int)p + *q; q += 4;`), where `count` is re-read
 * from the block itself every iteration (retail reloads `lw $v0,0x0($v1)` in the loop tail).
 *
 * Unit: needs the -G8 sibling (src/levels/shared/L00_002FC7A0-g8.c) - level 0's $gp base is
 * 0x1AEFF0, so `sw $v1,0x2AD0($gp)` is 0x001B1AC0 and `sw $v1,0x2AD4($gp)` is 0x001B1AC4.
 * Each of those two addresses is therefore named twice: `__attribute__((sda))` for the $gp
 * store, `__attribute__((nosda))` for the absolute `lui $at` zeroing. 0x001BF200 is out of
 * $gp reach (offset 0x10210) and is declared as a sized array so cc1 keeps the plain
 * `lui $v0` form rather than the bare-symbol `$at` macro.
 *
 * MEASURED LEVER, wave-7 coordination: the absolute `lui $at; sw %lo($at)` zeroing only
 * appears with `-mno-split-addresses` (a `config/cflags.txt` line for the -g8 unit:
 * `src/levels/shared/L00_002FC7A0-g8.c<TAB>-O2 -G8 -ffunction-sections -mno-split-addresses`).
 * Under it the two neighbours func_L00_0030DC30/0030DC58 still measure 27 of 27 places each,
 * and this body drops to the single register difference below. Without the flag the two
 * blanket zeros come out `lui $v0` and the -g8 unit's own line is the plain default.
 *
 * What is left, and it is one register: retail computes the block base into `$v1`
 * (`addu $v1,$a0,$v0`), copies it to `$a1` (`daddu $a1,$v1,$zero`) and only then reuses `$v1`
 * for the 0x1C walk pointer; this cc1 computes the base straight into `$a1` and never copies,
 * so the `$gp` store then cannot land in the `blez` delay slot (it sits one instruction
 * earlier, and the delay slot takes the `nop`). Tried: the block base as a second named local,
 * the base re-derived inside the body, the walk pointer as `int *` against byte offsets,
 * with/without the `if (count > 0)` guard (the guard must go - retail stores the base
 * unconditionally, in the `blez` delay slot).
 *
 * Wave 8 re-measurement with the line above (the default profile gives 200 bytes, not 192):
 * the size is exact and the residual is three register differences, not one.  The first
 * block's base lands in `$v0` instead of `$v1` and its publish is materialised whole
 * instead of split (retail `lui $v0,0x1C ; sw $v1,-0xE00($v0)`, the low half of 0x1BFF200
 * fits the signed displacement); the second block publishes the base before the count
 * test instead of in the `blez` delay slot; the third block's counter lands in `$a2`
 * instead of `$a0`.  The order of the count read and the publish is the lever to try next:
 * retail reads the count first and lets the scheduler drop the publish into the delay slot.
 */

typedef unsigned char u8;

typedef unsigned int u32;

typedef signed int s32;

extern u32 D_L00_001BF200[4];

extern u32 D_L00_001B1AC0 __attribute__((nosda));

extern u32 D_L00_001B1AC0_1 __attribute__((sda));

extern u32 D_L00_001B1AC4 __attribute__((nosda));

extern u32 D_L00_001B1AC4_1 __attribute__((sda));

void func_L00_00300378(u8 *a0)
{
    u8 *p;
    int *q;
    int i;

    if (*(int *)(a0 + 0) != 0)
        D_L00_001BF200[0] = (u32)(a0 + *(int *)(a0 + 0));

    if (*(int *)(a0 + 4) != 0) {
        p = a0 + *(int *)(a0 + 4);
        D_L00_001B1AC0_1 = (u32)p;
        q = (int *)(p + 0x1C);
        for (i = 0; i < *(int *)p; i++) {
            *q = (int)p + *q;
            q += 4;
        }
    } else {
        D_L00_001B1AC0 = 0;
    }

    if (*(int *)(a0 + 8) != 0) {
        p = a0 + *(int *)(a0 + 8);
        D_L00_001B1AC4_1 = (u32)p;
        q = (int *)(p + 0x1C);
        for (i = 0; i < *(int *)p; i++) {
            *q = (int)p + *q;
            q += 4;
        }
    } else {
        D_L00_001B1AC4 = 0;
    }
}
