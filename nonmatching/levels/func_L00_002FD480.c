/* func_L00_002FD480 - NON MATCHEE (wave 8, agent w8-09).
 *
 * The body is understood: four 128-bit block copies (`lq`/`sq`, 0x1B001D20,
 * 0x1B001D30, 0x1B001D40, 0x1B001D50) of the source, advanced by 0x10 each
 * time, then the advanced source pointer stored in the cell at 0x1B1D60.
 *
 * Corrected symbol names (the previous draft had them wrong, so its
 * relocations could never check out): retail materialises the four
 * destinations with `lui $v1,0x1B ; addiu $v1,$v1,0x1D20` and the following
 * +0x10 steps, so the block base is 0x1B001D20 (not 0x1B1D20) and the pointer
 * cell is 0x1B1D60 (retail stores it with `sw $a0,0x2D70($gp)`, $gp being
 * 0x1AEFF0).
 *
 * What is left: the register assignment.  Retail keeps the destination address
 * in $v1 and the loaded block in $v0 and reuses $v1 for all four blocks, with
 * the `lui`/`addiu` pair materialising the address before the `lq`.  This cc1
 * loads the block into $v1, materialises each destination into a different
 * register ($a2, then a new one for each block) and emits the `lq` before the
 * address.  The size is exact (88 bytes).
 *
 * The $gp store of the advanced pointer needs a -G8 unit (measured in a
 * dedicated file: `-O2 -G8 -ffunction-sections`); the canonical
 * L00_002FC7A0.c is -G0 and turns the store into lui+sw, four bytes longer.
 * The four destinations are materialised absolutely in the retail bytes, so
 * they carry nosda.
 */

#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

extern TI128 D_L00_1B001D20 __attribute__((nosda));
extern TI128 D_L00_1B001D30 __attribute__((nosda));
extern TI128 D_L00_1B001D40 __attribute__((nosda));
extern TI128 D_L00_1B001D50 __attribute__((nosda));
extern TI128 *D_L00_1B1D60 __attribute__((sda));

/* copies four sixteen-byte blocks into the level's upload buffer and parks the
   advanced source pointer in the cell that follows them */
void func_L00_002FD480(TI128 *src)
{
    TI128 *dst;

    dst = &D_L00_1B001D20;
    *dst = *src++;
    dst = &D_L00_1B001D30;
    *dst = *src++;
    dst = &D_L00_1B001D40;
    *dst = *src++;
    dst = &D_L00_1B001D50;
    *dst = *src++;
    D_L00_1B1D60 = src;
}
