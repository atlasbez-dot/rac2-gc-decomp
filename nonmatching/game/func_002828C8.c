/* func_002828C8 - 40 bytes, 1 place (the boot), retail at 0x002828c8:
   lui $at,0x3E80 ; lwc1 $f2,-0x76E0($gp) ; mtc1 $a0,$f1 ; mtc1 $at,$f3 ;
   cvt.s.w $f1,$f1 ; 0x46031818 ; 0x4602085C ; cvt.w.s $f1,$f1 ; jr $ra ;
   mfc1 $v0,$f1.  Same wall as func_00282890: the two words in the middle
   are COP1 words with funct 0x18 and 0x1C that this cc1 never emits, and
   the first of them computes a value ($f0) that is never read again.  The
   body needs the -G8 profile, so it belongs in 0027F128-g8.c. */
typedef float f32;
typedef int s32;

extern float D_001A7910 __attribute__((sda));

int func_002828C8(s32 a0) { f32 t = (f32)a0; return (s32)(t * 0.25f + D_001A7910); }
