/* 0 of 27 places match - last line: 00_aranos_tutorial: 32 bytes, expected 36
   One instruction short: retail keeps the whole address materialisation before the ra
   save and leaves a `nop` in the jal's delay slot, this cc1 saves `$ra` first
   (`sd $ra,0x0($sp)` at +0x8 against retail's +0xc) and puts the `addiu $a0,$a0,%lo`
   of the `la` in the delay slot instead. Eleven call spellings (array, `&scalar`,
   local, volatile local, no prototype, pointer arithmetic, `&x[0]`, result assigned)
   and six flag sets (-fno-schedule-insns, -fno-schedule-insns2, both,
   -fno-delayed-branch, -fno-reorder-blocks rejected) all give the same 8 words.
   The three-call sibling func_L00_0037E5C0 matches, so the unit's profile is right;
   what differs here is where this cc1 schedules the argument setup against the frame
   save. A dedicated file with the retail unit's own flags may be the only route. */

extern unsigned char D_L00_001B26B4[];
extern int func_00282948(void *p);

void func_L00_0037E640(void)
{
    func_00282948(D_L00_001B26B4);
}
