/* 0 of 4 places match - instruction at +0x14 differs; candidate is 68 bytes against 60.
   The loop itself is exact: five iterations of `sw $zero,0($v1); addiu $v0,$v0,-1; sw $zero,0($a0);
   addiu $v1,$v1,4; nop; bgez $v0,loop; addiu $a0,$a0,4`, with both pointers starting at their bases
   and the counter counting 4 down to -1. What differs is the register allocation and one hoist:
   retail puts the counter in $v0 and the two blocks in $a0 (0x1B2FA0) and $v1 (0x1B3018) and stores
   the $gp flag first; this cc1 gives the counter $a0, keeps the blocks in $v1/$v0 and materialises
   both block bases before the flag store.
   Needs the -g8 unit (it stores $zero,0xCC8($gp) - L05_0037B6D0-g8.c) with
   `extern int D_L05_001AFBF8 __attribute__((sda));`.
   Tried: counter declared before/after the pointers, do/while against for, both store orders. */

void func_L05_003D1E20(void)
{
    int i = 4;
    int *q = D_L05_001B2FA0;
    int *p = D_L05_001B3018;

    D_L05_001AFBF8 = 0;
    do {
        *p = 0;
        *q = 0;
        p++;
        q++;
        i--;
    } while (i >= 0);
}
