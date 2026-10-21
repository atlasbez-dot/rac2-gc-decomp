/* func_00325A88 - 156 bytes, 7 places (the boot and the six levels that place it),
   retail at 0x00325A88: the object at +0x68 holds a cursor; the function bumps the
   cursor, rounds it down, stores it back, grows the count when it is below four,
   calls func_002A91F0 with the table entry at +0x420 + cursor * 16 and the object's
   own field at +0xF0, and copies sixteen bytes from the object's +0x2A4 table into
   the table at +0x320 + cursor * 16.

   NEAR MISS, not integrated.  Checked in src/game/0031F210.c with
   `python3 tools/check.py func_00325A88 --diff`:

     boot: instruction at +0x6c differs
     00_aranos_tutorial: instruction at +0x6c differs
     ... (the same at 02_maktar_nebula, 07_siberius, 11_joba, 14_aranos_prison,
          26_jamming_array)
     func_00325A88: 0 of 7 places match (src/game/0031F210.c)

   The candidate is the exact size (156 bytes) and its first 26 instructions are
   retail's byte for byte: the `daddu $a3,$a0,$zero` copy of the object pointer, the
   `addiu $a0,$zero,-1` limit compared with `slt` (a variable of type long holding
   -1 is the spelling that keeps retail's shape; a literal -1 comes out as `slti`),
   the `movn $v0,$v1,$a0`, the `slti`/`beqz` pair with the store of 0x2B4 in the
   branch's delay slot, and the call setup.

   What differs is the tail.  Retail materialises both addresses and copies
   through a register:

     lw    $v1, 0x2B4($s0)      ; the cursor
     lw    $a0, 0x2A4($s0)      ; the source table
     sll   $v1, $v1, 4
     addu  $v1, $v1, $s0
     addiu $a0, $a0, 0x10       ; the source address
     addiu $v1, $v1, 0x320      ; the destination address
     lq    $v0, 0($a0)
     sq    $v0, 0($v1)

   this cc1 gives the same shape but allocates the three values one register
   further down (the cursor in $v0, the source in $v1, the lq/sq temporary in $a0
   where retail has them in $v1, $a0 and $v0), and it hoists the `ld $ra, 8($sp)`
   of the epilogue into the middle of the tail.  Measured spellings: the `mode(TI)`
   copy with and without `volatile` on either side, the same through a `mode(TI)`
   temporary at function scope or in a block, a 16-byte struct copy (that one turns
   into a library call), the pointers materialised or folded into the lq/sq
   offsets, the cursor reloaded into the earlier variables (that one makes the
   variable live across the call and changes the prologue), the copy written with
   the source first, and the whole copy as one expression with volatile reads.
   Twenty spellings measured; every one of them ends with the same three
   registers shifted by one.

   What would unblock it: a spelling that makes this cc1 allocate the lq/sq
   temporary to $v0 (it prefers the first free register for the pseudo that
   carries the copy), or a second assignment pass that renumbers the tail's
   registers.  The FPR and the rest of the body are not the problem here. */

typedef int TI128 __attribute__((mode(TI)));

extern void func_002A91F0(char *, char *);

void func_00325A88(char *a0)
{
    char *s0 = *(char **)(a0 + 0x68);
    int v0 = *(int *)(s0 + 0x2B4);
    int a2 = *(int *)(s0 + 0x2B0);
    int v1 = v0 + 1;
    long limit = -1;

    *(int *)(s0 + 0x2B8) = 0;
    v0 = v0 + 4;
    if (v1 > limit)
        v0 = v1;
    v0 = (v0 >> 2) << 2;
    v1 = v1 - v0;
    *(int *)(s0 + 0x2B4) = v1;
    if (a2 < 4)
        *(int *)(s0 + 0x2B0) = a2 + 1;
    func_002A91F0(s0 + 0x420 + (*(int *)(s0 + 0x2B4) << 4), a0 + 0xF0);
    {
        int index;
        char *src;
        char *dst;

        index = *(int *)(s0 + 0x2B4);
        src = (char *)(*(int *)(s0 + 0x2A4));
        src = src + 0x10;
        dst = s0 + (index << 4);
        dst = dst + 0x320;
        *(volatile TI128 *)dst = *(volatile TI128 *)src;
    }
}
