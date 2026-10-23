/* func_L01_00310BC0 - 360 bytes, 3 place(s) (levels 01_oozla, 06_notak, 08_tabora),
   retail at 0x00310BC0 in level 01.  Screened and decoded, not matched in this wave.

   Calls: func_00283BE0@00310BF8 (the level's 0x002E44A8), func_00282C48@00310C9C,
   @00310CB8, @00310CC8, @00310CE8 (the level's 0x002E33E0, four times) and
   func_00283B98@00310CFC (the level's 0x002E4460).
   Float constants materialised: 0x3F800000 (1.0), 0x40CBB7E3 (6.18), 0xBF800000 (-1.0).
   Data addresses: none.  $gp-relative small data: no.
   Saves: $s0, $ra.  Callee-saved registers saved [$s0].  Frame 0x40.
   Words plain C cannot emit: none (the body is plain FPU and integer code).

   The body, decoded:
     - the five float arguments arrive as f12..f16; they are moved to $f24 ($f12),
       $f22 ($f14), $f23 ($f15) and $f20 ($f16), and the call to func_00283BE0 gets
       (a0 = the pointer, f12 = the caller's f13, f13 = the caller's f12, f14, f15, f16):
       the first two float arguments are exchanged;
     - the result (in $f21) is multiplied by 6.18f and clamped to [-1, 1] with the
       retail's two shapes: the first clamp is `c.lt.s $f1,$f0 ; bc1tl` (the branch
       annuls its delay slot), the second `c.lt.s $f0,$f1 ; bc1fl` with the load of
       *p in the delay slot and a second copy of it after the branch;
     - the value becomes $f22 * t - $f23 * *p + *p;
     - $f20 (the caller's f16) decides: zero jumps past the store, otherwise the value
       is clamped against $f20 and -$f20 (`neg.s $f16,$f20`);
     - four calls to func_00282C48 and one to func_00283B98 follow, with the
       branches the retail's (`bc1f`, `bc1fl`, `bc1tl`).

   Not matched in this wave: the float expression tree, the two clamp spellings and
   the four calls have to come out of the same source to keep the FPU registers and
   the branch-likely forms, and the allocation of $f20..$f24 across the calls has to
   be the retail's.  What would unblock it: the source of the clamp of the result
   (the `c.lt.s`/`bc1tl` pair is this cc1's shape for `if (x > 1.0f) x = 1.0f;`, the
   `bc1fl` form for the lower clamp needs its own spelling) and the spelling of the
   final four calls.
 */
