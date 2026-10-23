/* func_L01_00331CA0 - 356 bytes, 3 place(s) (levels 01_oozla, 15_gorn, 19_grelbin),
   retail at 0x00331CA0 in level 01.  Screened and decoded, not matched in this wave.

   Calls: func_002B9030@00331CD8 (the level's 0x00325768), func_002A7878@00331D20,
   @00331D40, @00331DB8 (the level's 0x00310580, three times) and func_00283CF0@00331D6C
   (the level's 0x002E45B8).
   Data addresses materialised: 0x200000 (the `lui $a0, 0x20` before the load of
   0x1FF164 at 0x00331D98).
   Float constants: 0x3E800000 (0.25), 0x3DF5C28F (0.12), 0x3F800000 (1.0),
   0x3F000000 (0.5), 0x40800000 (4.0), 0x484D1400, 0x43B40000.
   Saves: $s0, $s1, $s2, $s3, $ra.  Callee-saved registers saved [$s0, $s1, $s2, $s3].
   Frame 0x50.  Words plain C cannot emit: none, but the two 16-byte copies
   (LQ/SQ at 0x00331DCC and 0x00331DD4) need a `mode(TI)` local.

   The body, decoded:
     - the third argument is a 16-byte value copied into the frame (`lq $v0,0($a2)` ;
       `sq $v0,0($sp)`), and the object is built with func_002B9030(0x49), the
       result in $s0;
     - the second argument selects a case: 0 gives (0.25f, 0.12f), 1 gives
       (1.0f, 0.5f) and anything else (0.0f, 0.0f) with the argument in $a0;
     - the object is then filled in: 0x37 at +0x0A, a word built from 0x0D and
       0xFFFF at +0x04, 0x20 at +0x09, 0x48 at +0x03, 0 at +0x01, the byte of the
       table at 0x1FF164 + the second argument at +0x02, the product of the case's
       second constant and 0x484D1400 at +0x0C, the truncated product at +0x08, the
       first argument's 16 bytes at +0x10 and the frame's 16 bytes at +0x20, and the
       caller's f12 at +0x2C.

   Not matched in this wave: the body is straight-line code whose register allocation
   and the materialisation of its constant addresses have to be reproduced word for
   word, and the two 16-byte copies need the `lq`/`sq` pair (a `mode(TI)` local), which
   this cc1 folds into the instruction where the retail materialises the address.
   What would unblock it: the source of the object fill (the order of the stores and
   the type of the 16-byte fields) and the spelling of the case selection.
 */
