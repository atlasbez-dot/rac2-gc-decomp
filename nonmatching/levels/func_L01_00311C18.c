/* func_L01_00311C18 - 344 bytes, 7 place(s) (levels 01_oozla, 02_maktar_nebula,
   04_barlow, 08_tabora, 10_hrugis_cloud, 11_joba, 16_snivelak), retail at
   0x00311C18 in level 01.  Screened and decoded, not matched in this wave.

   Calls: func_00282CF0@00311C4C, @00311C5C, @00311C94 (the level's 0x002E34A0, three
   times), func_00282CC0@00311C84, @00311D30 (the level's 0x002E3470, twice),
   func_00282C48@00311CB8 (the level's 0x002E33E0) and func_00282D30@00311D20
   (the level's 0x002E34E0).
   Float constants: 0x38D1B717, 0x3F800000 (1.0).
   Data addresses: none.  $gp-relative small data: no.
   Saves: $s0, $s1, $s2, $s3, $ra.  Callee-saved registers saved [$s0, $s1, $s2, $s3].
   Frame 0x80.  Words plain C cannot emit: none, but the 16-byte copy at 0x00311D40
   (LQ/SQ) needs a `mode(TI)` local, and the two `min.s`/`max.s` (0x00311D1C and
   0x00311D24) need -ffast-math, which the shared unit of the function does not
   carry.

   The body, decoded:
     - the four arguments (a0, a1, a2, a3) are the two vectors to work on;
     - func_00282CF0 is called three times to build the two cross products and the
       dot product (its results are read back from the frame at sp+0x00, sp+0x10 and
       sp+0x20);
     - the cross product's two components are multiplied by the dot product and
       subtracted (`mul.s $f1,$f1,$f3 ; mul.s $f0,$f0,$f2 ; sub.s $f21,$f1,$f0`),
       the result is scaled by 1/0x38D1B717 and clamped to [-1, 1] with
       `max.s`/`min.s` against 0.0f and 1.0f;
     - the clamped value is then written back into the second argument with
       func_00282CC0 and the first argument is given the 16 bytes of the second
       (`lq $v0,0($s2) ; sq $v0,0($s3)`).

   Not matched in this wave: the float expression tree has to come out of one source
   to keep the FPU registers ($f20, $f21) over the calls, the 16-byte copy needs a
   `mode(TI)` local, and `min.s`/`max.s` need -ffast-math, which changes every other
   body of the shared unit - the function would have to move to a unit of its own in
   config/cflags.txt.  What would unblock it: the source of the two cross products
   and of the clamp, and the type of the 16-byte fields.
 */
