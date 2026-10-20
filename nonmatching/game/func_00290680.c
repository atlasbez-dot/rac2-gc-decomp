/* func_00290680, near miss (not linked): 152 bytes compiled against retail's 148, with the game
   compiler at -O2 -G8 (a -g8 unit). With the file's own sdk -O2 -G8 profile it is 156 bytes and
   almost every word differs (the sdk compiler ignores `sda`); the other three functions of
   src/game/00290670.c match under either compiler.

   The only difference is one nop between `mfc1 $a3,$f1` and `beqz $a3`. It is the assembler's,
   not the source's: cc1 writes `mfc1 $7,$f1`, then `.set noreorder`, then the branch, and gas
   pads the mfc1 load delay at the `.set noreorder` and keeps the nop because the branch reads
   $7. With `.set noreorder` moved in front of the mfc1 in cc1's output (by hand, scratch only)
   the object is 148 bytes and all 37 words equal retail, so nothing else is wrong. Spellings
   measured with no effect on the nop: early return, an inner-block temporary, a float
   temporary, -G0, the sdk profiles, -mips4 on cc1.

   Retail's assembler never pads an mfc1: 71 places in 34 boot functions (all still
   INCLUDE_ASM; three of them, func_00290680, func_002BA6A0 and func_002C4B50, branch on the
   mfc1 result as here) have an mfc1 followed at once by an instruction that reads its result,
   with no nop, while it does pad `c.*.s` before `bc1*` (1224 places, never direct) and `mtc1`
   before an FPU op that reads the register (571 places). What would unblock all of them is
   an assembler change for the R5900 in gas/config/tc-mips.c: no nop after `mfc1`
   (INSN_LOAD_COPROC_DELAY, in append_insn and in mips_emit_delays) when mips_cpu == 5900,
   leaving the compare and mtc1 cases alone. Not tried in a build. */
extern int D_001A9014 __attribute__((sda));
extern int D_001A9018 __attribute__((sda));
extern void func_0027DDC0(int, int, int, int);

void func_00290680(void)
{
    int n;
    int r;

    if (D_001A9018 != 0) {
        D_001A9018 = 0;
        n = D_001A9014 + 1;
        D_001A9014 = n;
        if (n >= 11)
            D_001A9014 = 10;
    } else {
        n = D_001A9014 - 1;
        D_001A9014 = n;
        if (n < 0)
            D_001A9014 = 0;
    }
    r = (int)((float)D_001A9014 * 0.1f * 48.0f);
    if (r != 0)
        func_0027DDC0(0, 0, 0, r);
}
