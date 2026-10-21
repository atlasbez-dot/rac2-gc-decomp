#include "include_asm.h"

/* Near miss (wave 13, worker g3): 160 bytes of retail; the body is reproduced word for
   word except for two instructions of the prologue that are swapped.

   What matches, word for word, in the boot and in every level:

     * the guard: `lui $v0,%hi(D_001A8CFC)` / `lw $v0,%lo($v0)($v0)` / `beqz $v0,end`
       with the constant 1 in the delay slot;
     * the store of the 1 into the cell at 0x1F2848 (the boot's D_001F2848) and the
       table pointer (the boot's D_0026185A) with the `lui`/`addiu` pair;
     * the mask (D_00139768) and the flag byte (D_001A7A0A) with their `lui`/`lbu`;
     * the whole loop, word for word: the `bnel` with `sh $t0,0($a2)` in its delay
       slot, the `lh`/`srl`/`sll`/`andi`/`addu`/`sllv`/`lw`/`and` chain of the bit
       test, the `beqz`/`b`/`sh` pair, the three increments and the `slt` test.

   What differs, in every program, is only the order of two instructions of the
   prologue:

     retail: addiu $t0,$zero,0x1   (the constant 1)   at +0x38
             addiu $a2,$v1,0x8     (the destination)  at +0x3C
     this C: addiu $a2,$v1,0x8                       at +0x38
             addiu $t0,$zero,0x1                     at +0x3C

   Everything else is identical, including every register: $v0 holds the cell and
   the constant, $v1 the table and the index, $a0 the cell's address and the loaded
   short, $a1 the source, $a2 the destination, $a3 the byte counter, $t0 the
   constant 1 of the loop, $t1 the flag byte, $t2 the clear base, $t3 the end of
   the table, $t4 the mask.

   Measured: `tools/check.py func_002D0F00 --diff` gives "instruction at +0x38
   differs" in the boot and in every level; the size is right (160).

   The body needs the -G8 unit (002CD8C0-g8.c): only there does a word load of a
   global give the base and the value the same register (`lui $v0,%hi(X)` /
   `lw $v0,%lo(X)($v0)`), which the retail has; in a -G0 unit the load keeps two
   registers.

   The three data cells have one name for the boot and for the levels: they sit
   above the resident data, so every level has its own copy at its own address and
   the build reads the value from the retail bytes.

   The flag byte is read through a non-volatile alias of D_001A7A0A: the retail
   loads it once, before the loop, and compares it as a byte, so the source must
   not be the volatile declaration of the file (a volatile read needs a zero
   extension, one instruction more) and must not be an array (an array of unknown
   size keeps the load's base in a second register).

   The clear address is computed as an integer sum (`off + clr`) so that the two
   operands come out in the retail's order (`addu $v0,$a3,$t2`); a pointer sum
   gives the base first.

   What was tried and did not help: the order of the statements (the "one" before
   or after the byte counter, the source before or after the destination), the
   guard written as `goto done` or as `if (...) { ... }`, `short *` instead of
   `char *` for the table pointers, the literal 1 instead of the variable in the
   loop, an `unsigned int` for the constant, and the byte counter declared before
   or after the constant. */

extern char *D_001A8CFC;

extern int D_001F2848[];

extern short D_0026185A[];

extern unsigned int D_00139768[];

extern unsigned char D_001A7A0A_plain __asm__("D_001A7A0A");

int func_002D0F00(void)
{
    unsigned int *mask;
    unsigned char flag;
    char *table;
    char *end;
    int clr;
    char *src;
    char *dst;
    int off;
    int one;

    if (D_001A8CFC == 0)
        goto done;
    D_001F2848[0] = 1;
    table = (char *)D_0026185A;
    mask = D_00139768;
    flag = D_001A7A0A_plain;
    end = table + 0xC6;
    clr = (int)table + 2;
    one = 1;
    src = table + 6;
    dst = table + 8;
    off = 6;
    do {
        int v;
        if (flag != 0) {
            *(short *)dst = one;
        } else {
            v = *(short *)src;
            if (mask[(unsigned int)v >> 2] & (one << (v & 31)))
                *(short *)dst = one;
            else
                *(short *)(off + clr) = 0;
        }
        src += 6;
        dst += 6;
        off += 6;
    } while ((int)src < (int)end);
done:
    return 0;
}
