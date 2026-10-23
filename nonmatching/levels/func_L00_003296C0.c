/* 96 bytes against retail's 112 (27 places): the closest candidate differs only in how often
 * the per-index table is re-materialised. Retail materialises the global twice (`lui $a1,0x1B;
 * lw $a1,0x1AFC($a1)` at +0x10, and again into $v1 at +0x40) and re-reads the block pointer
 * four times, once per store; this cc1 keeps the global in one register, folds the store into a
 * single address register and reuses it, and drops the `daddu $v0,$a1,$zero` / `daddu $t0,$a2,
 * $zero` argument copies at +0x04/+0x0C (the value argument also needs to be `s32`, not `u8`,
 * or the store gains an `andi $a2,$a2,0xFF`). Tried: one expression per statement (96 bytes),
 * one address local (96 bytes).
 *
 * What would unblock it: the measured nosda levier - two C names for the same address
 * (`ref_L00_001B1AFC_00` for the first group of stores, a second name for the last two), so the
 * address is re-materialised instead of kept. The body itself is settled: the count byte lives
 * at block +4 and picks the next eight-byte record, which stores the object pointer, the byte
 * value and a cleared halfword, then the count is bumped.
 *
 * Wave 8 (agent w8-08) measured the nosda lever: it works, but the declaration above is
 * WRONG in one point and the candidate still misses. The global at 0x001B1AFC holds a POINTER
 * to the table, not the table: retail does `lui $a1,0x1B ; lw $a1,0x1AFC($a1)` and then
 * `addu $a1,$a2,$a1 ; lw $v1,0($a1)`, i.e. it loads the pointer and indexes it. Declared
 * `extern u8 *ref_L00_001B1AFC_00[]` (an array) this cc1 emits `lui/addiu` of the array's own
 * address and the word load disappears; declared `extern u8 **ref_L00_001B1AFC_00` the load
 * appears and the shape matches retail.
 *
 * With `extern u8 **ref_L00_001B1AFC_00 __attribute__((nosda))` plus a second name
 * `ref_L00_001B1AFC_01` for the last two stores, the second `lui`/`lw` pair does appear (the
 * nosda keeps both out of $gp) and the four table re-reads appear, but the result is 124 bytes
 * against retail's 112: the argument copies land in $t0/$t1 instead of retail's $a3/$v0/$t0,
 * the sum `addu $v1,$a0,$v1` keeps the pointer first where retail has the integer first
 * (count*8 + block), and the block pointer is re-read through one address register where
 * retail recomputes `count*8 + block` each time. Adding `volatile` to the table and the
 * block (the spelling of nonmatching/levels/shared/func_L00_003296C0.c) reaches 112 bytes
 * but spills the block to the stack. The operand order of that sum is the same wall as
 * func_L00_0032A088 (index + base against retail's base + index).
 */
typedef int s32;
typedef unsigned char u8;

extern u8 **ref_L00_001B1AFC_00;

void func_L00_003296C0(char *object, s32 index, s32 value)
{
    s32 offset;

    if (object == 0)
        return;
    offset = *(u8 *)(ref_L00_001B1AFC_00[index] + 4) * 8;
    *(char **)(ref_L00_001B1AFC_00[index] + offset) = object;
    *(u8 *)(ref_L00_001B1AFC_00[index] + offset + 5) = value;
    *(unsigned short *)(ref_L00_001B1AFC_00[index] + offset + 6) = 0;
    ++*(u8 *)(ref_L00_001B1AFC_00[index] + 4);
}

