/* Not attempted (wave 4, worker 10 of the level 20 wave): only the structure
   was mapped, for the next worker.

   func_L20_0044A1C8 (1168 bytes) reaches NO global through $gp, so it can
   live in the -G0 unit (src/levels/20_yeedil/L20_00449178.c).  Its only
   16-byte copy is `lq $v0,0x0($v1) ; sq $v0,0x0($s1)` with the
   destination in a register ($s1 = $s3 + 0x140), so the 128-bit copy wall
   does NOT stand here either.

   The shape: the frame is 0x80 with $s0-$s3 saved and $f20-$f22 spilled
   to the stack.  It starts with the usual `D_001A8F00 != 2` guard, then
   dispatches on the byte at +0x20 of the object: 3 goes to .L0044A2C8, 4
   to .L0044A258, 5 to .L0044A454, and the values below 4 are split again
   (4 is tested twice).  The paths call f_0044A658, f_0044A8F0, f_0033E788,
   f_0032F2D0, f_004448A8, f_0032F680, f_0032F778, f_00303270, f_0032F718,
   f_00302858, f_00302870, f_00302260 and f_003253A8.

   Two things to watch when the body is written:
   - there is a `bc1tl` whose delay slot holds a store (`swc1 $f22,
     0x198($s3)`), and a `c.eq.s` test against a float loaded from
     D_189E20 + 0x2D8; the delay slot of a branch-likely is part of the
     body, so the store belongs to the branch's own block.
   - the float constants are in the listing: 0x3DCCCCCD (0.1f), 0x428C0000
     (70.0f), 0x41A00000 (20.0f), 0x3C8EFA36 (0.017453292f), 0x41700000
     (15.0f), 0x40A00000 (5.0f), 0x3FC00000 (1.5f), 0x40200000 (2.5f).

   ------------------------------------------------------------------
   Wave 5 (worker 10), 2026-10-21: the wave-4 note above is right about
   the shape but WRONG about the $gp: the body DOES reach level data
   through $gp, so it needs a -G8 unit of its own (a file named
   *-g8.c), not the -G0 unit:

       0044A574  addiu $a1, $gp, 0x3440     -> D_L20_001B2430
       0044A5A8  lwc1  $f0, 0x3430($gp)     -> D_L20_001B2420

   ($gp = 0x001AEFF0, so the offsets are 0x1B2430 and 0x1B2420.)  The
   other globals of the body are read absolute: D_189E20 (0x00189E20,
   below 0x1A7C80, so the same in every program), D_L20_001B9E80
   (`lui $s0,%hi` + `addiu $s0,$s0,%lo`) and D_L20_001B2AC8
   (`lui`+`lw`).

   The 128-bit copy of the body is `lq $v0,0x0($v1) ; sq $v0,0x0($s1)`
   with the destination in a register ($s1 = $s3 + 0x140), so the copy
   wall does not stand here either.
*/
