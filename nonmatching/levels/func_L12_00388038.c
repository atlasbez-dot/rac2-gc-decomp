/* 0 of 1 places match - last line: 12_todano: candidate is 108 bytes, expected 84
   The body is recovered: the two mode gates (0x001A8F00 == 2 and 0x001BDB30 == 5),
   the tracked pointer 0x001B2EA8 through $gp, the cleared word at +0x98, the two
   flag bits (| 0x41 & ~0x1000) at +0x34 and the walk of the chain at +0x28.
   What is left is the chain walk: retail enters the loop at the `lw $v1,0x28($v1)`
   and keeps `lhu $v0,0x34($v1)` in the delay slot of its `bnel` (84 bytes, no
   padding); this cc1 peels that load out of the loop, pads the loop head with
   alignment nops and leaves the load in the delay slot of the peeled copy, so the
   candidate is 24 bytes (6 instructions) longer. The `$gp` global needs the -g8
   sibling and the two absolute ones the `lui`/`lw` form, so the unit needs
   `-G8 -mno-split-addresses`; the load of 0x001B2EA8 also lands in the first
   branch's delay slot here and in the second one's there.
   Measured with nine spellings (the loop written as while / do-while / for, the
   pointer in a local or read inline, the function returning void or the loaded
   halfword): all 108, all peeling the same load. */

extern int D_L12_001A8F00 __attribute__((nosda));
extern int D_L12_001BDB30 __attribute__((nosda));
extern char *D_L12_001B2EA8 __attribute__((sda));

unsigned short func_L12_00388038(void) {
    char *v1 = D_L12_001B2EA8;
    unsigned short v0;

    if (D_L12_001A8F00 != 2) {
        return 0;
    }
    if (D_L12_001BDB30 != 5) {
        return 0;
    }
    if (v1 == 0) {
        return 0;
    }
    v0 = *(unsigned short *)(v1 + 0x34);
    *(int *)(v1 + 0x98) = 0;
    *(unsigned short *)(v1 + 0x34) = (v0 | 0x41) & 0xEFFF;
    while (v1 != 0) {
        v0 = *(unsigned short *)(v1 + 0x34);
        v1 = *(char **)(v1 + 0x28);
    }
    return v0;
}

/* wave 24, worker 03 (src/levels/12_todano/L12_002CF7B0-g8.c): the body is
   reached and the SIZE is the retail's - tools/check.py
   func_L12_00388038 prints "instruction at +0x4 differs", 21 instructions
   against the retail's 21 - with two findings the earlier note does not have.

   The function returns nothing.  The retail's exit block is a bare
   `jr $ra` with a nop in the delay slot, and the three early exits leave $v0
   holding the test constants (2, then the %hi of D_001BDB30), so no value is
   returned on any path: the body is `void`, and the exits are `return;`, not
   `return 0;`.  With `void` the three exits share the retail's one exit
   block at the end.

   The chain walk is a do-while, not a while: the retail's loop is the
   `sw $zero,0x98($v1) ; ori ; andi ; sh ; lw $v1,0x28($v1) ; bnel $v1,$zero,
   <top> ; lhu $v0,0x34($v1)` shape, i.e. the flag load of the NEXT node sits
   in the delay slot of the back edge and the loop label is on the store.  The
   pointer is read after the two mode gates, so the $gp load lands in the
   second test's delay slot as the retail has it.

   What is left is one instruction: this cc1 hoists the first test's constant
   above the load that feeds it, and the address form follows:

     retail   lui $v1, %hi(D_001A8F00)
              lw $v1, %lo(D_001A8F00)($v1)
              addiu $v0, $zero, 0x2
              bne $v1, $v0, .L00388084
     this cc1  lui $v0, %hi(D_001A8F00)
              addiu $a0, $zero, 0x2
              lw $v1, %lo(D_001A8F00)($v0)
              bne $v1, $a0, .L00388084

   the second test is the retail's in both (the %hi in $v0, the constant in
   $a0, the value in $v1), so only the first one differs.  Measured here, all
   of them compiling to the same three instructions: the globals read in the
   conditions and in locals before the tests; the constants 2 and 5 as
   literals, as locals and as unsigned; the tests swapped; the comparison
   written `2 != x` and `!(x == 2)`; a switch on the first global; and the
   pointer read in the condition of the third test.  -mno-split-addresses is
   wrong here (it gives the absolute `lw $3,D_L12_001A8F00` instead of the
   retail's %hi/%lo pair).  The rest of the body - the flag update, the word
   cleared at +0x98, the chain walk and the `bnel` with the load in its delay
   slot - is the retail's, instruction for instruction. */
