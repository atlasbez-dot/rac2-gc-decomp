/* Near miss: func_002C9C90 (104 bytes in every program).
 *
 * The body is the game's initialiser for the global record at 0x001B5200 plus
 * the two 16-byte records at 0x001B5580 and 0x001B5590.  The best C found is
 * below; it compiles to 100 bytes and differs from retail in three ways:
 *
 *  1. The three 16-byte clears.  Retail stores them as
 *       sq $zero,0($v1)   (address in a register, value the zero register)
 *     The compiler's rac2_fold_zero_ti_store pass only folds a materialised
 *     zero into a store whose address is a plain register, and only when the
 *     zero's register dies at that store.  Here the C gives
 *       por $v1,$zero,$zero ; sq $v1,0x370($v0)
 *     - the address keeps a displacement, so the fold does not apply, and the
 *     three clears share one materialised zero, so at most one of them could
 *     fold.  retail materialises the address of the first clear into $v1
 *     ("addiu $v1,$v0,0x370") and gives each clear its own zero.
 *
 *  2. The record's base address.  Retail materialises 0x001B5200 twice (once
 *     for the first group of stores, once for the last group); this cc1 CSEs
 *     the symbol address into one register and keeps it (the "CSEs symbol
 *     addresses" habit recorded in docs/COMPILER-NOTES.md).
 *
 *  3. The order of the stores.  The scheduler interleaves the 1.0f stores with
 *     the 256.0f/64.0f ones; retail keeps the groups apart.  With
 *     -fno-schedule-insns the groups come out in retail's order, so the
 *     scheduler is what moves them, but the other two differences remain.
 */
#include "include_asm.h"

typedef int TI16 __attribute__((mode(TI)));

extern char D_001B5200[];
extern char D_001B5580[];
extern char D_001B5590[];

void func_002C9C90(void)
{
    float *p = (float *)D_001B5200;

    p[0x144 / 4] = 256.0f;
    p[0x148 / 4] = 64.0f;
    p[0x140 / 4] = 256.0f;
    *(TI16 *)((char *)p + 0x370) = (TI16)0;
    *(TI16 *)D_001B5580 = (TI16)0;
    *(TI16 *)D_001B5590 = (TI16)0;
    p[0x39C / 4] = 1.0f;
    p[0x370 / 4] = 1.0f;
    p[0x384 / 4] = 1.0f;
    p[0x398 / 4] = 1.0f;
}
