/* func_00282890 - 40 bytes, 1 place (the boot), retail at 0x00282890:
   lui $at,0x3E80 ; lwc1 $f2,-0x76E4($gp) ; mtc1 $a0,$f1 ; mtc1 $at,$f3 ;
   cvt.s.w $f1,$f1 ; 0x46031818 ; 0x4602085C ; cvt.w.s $f1,$f1 ; jr $ra ;
   mfc1 $v0,$f1.  The two words in the middle are COP1 words of the
   single-precision group (CO=10000) with funct 0x18 and 0x1C: rabbitizer
   cannot name them and this cc1 never emits them (it emits funct 0x00 to
   0x07 for add.s to neg.s and 0x24 for cvt.w.s).  Decoded by their fields
   they are "$f0 = $f3 op $f3" and "$f1 = $f1 op $f2", so the first one is a
   dead computation ($f0 is never read again): a compiler would drop it.
   The candidate below is the same expression tree with the ordinary
   mul.s/add.s, and it is 44 bytes with the loads in another order.
   The body needs the -G8 profile, so it belongs in 0027F128-g8.c.
   What would unblock it: the source of a body that keeps those two words,
   or the proof that the body is handwritten assembly. */
typedef float f32;
typedef int s32;

extern float D_001A790C __attribute__((sda));

int func_00282890(s32 a0) { f32 t = (f32)a0; return (s32)(t * 0.25f + D_001A790C); }
