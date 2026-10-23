/* from src/levels/shared/L00_002E5918.c: retail, 40 bytes, 27 places:
   lui $at,0x3E80 ; lwc1 $f2,-0x76DC($gp) ; mtc1 $a0,$f1 ; mtc1 $at,$f3 ;
   cvt.s.w $f1,$f1 ; 0x46031818 ; 0x4602085C ; cvt.w.s $f1,$f1 ; jr $ra ;
   mfc1 $v0,$f1.
   The two unknown words are R5900 single-precision instructions: funct 0x18
   is ADDA.S and funct 0x1C is MADD.S (the same group the game's assembler
   names `max.s` at 0x28 and `min.s` at 0x29; it assembles `madd.s fd,fs,ft`
   to 0x460D601C, so the retail's 0x4602085C is `madd.s $f1,$f1,$f2`).
   They drive the R5900 FP accumulator: ADDA.S $f0,$f3,$f3 loads it with
   0.25f*0.25f = 0.0625f, MADD.S $f1,$f1,$f2 adds the scaled value, and the
   function returns (int)(value * scale + 0.0625f) - the scale is D_001A7914.
   The candidate below is that expression with the ordinary mul.s/add.s: it is
   48 bytes against the retail's 40.
   Not reachable in plain C with this toolchain, measured this wave
   (wave 8 w06): the compiler's machine description has a `madd.s` pattern
   for (set f (plus (mult f1 f2) f3)), i.e. `a*b + c`, but it is gated on
   `mips_isa >= 4`, so it needs -mips4; with -mips4 the cc1 prints the
   four-operand form `madd.s %0,%3,%1,%2`, which the game's assembler refuses
   ("illegal operands `madd.s`"), and there is no `adda.s` in the compiler's
   machine description nor in the assembler at all.  Marked G8. */
extern float D_001A7914 __attribute__((sda));

int func_L00_002EDD00(int value) {
    return (int)((float)value * D_001A7914 + 0.0625f);
}
