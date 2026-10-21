/* func_00282C50 - 8 bytes, 28 places (the boot and every level), retail at
   0x00282c50: jr $ra ; 0x460D6029.  The second word is a COP1 word of the
   single-precision group (CO=10000, funct 0x29): rabbitizer cannot name it
   and this cc1 never emits it - it emits add.s/sub.s/mul.s/div.s/abs.s/
   mov.s/neg.s (funct 0x00..0x07), cvt.w.s (funct 0x24) and cvt.s.w
   (CO=10100, funct 0x20).  The closest C gives `jr $ra ; abs.s $f0,$f13`.
   Not matched: the word is outside this compiler's repertoire.
   What would unblock it: a source that makes cc1 emit that word, or the
   proof that the body is VU0/FPU assembly. */
typedef float f32;

f32 func_00282C50(f32 a0, f32 a1) { return __builtin_fabsf(a1); }
