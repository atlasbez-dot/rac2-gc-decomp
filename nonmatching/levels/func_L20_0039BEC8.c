/* func_L20_0039BEC8 (1252 bytes, 313 instructions, level 20 only) -- MAPPING,
   not integrated.

   This body reaches small data through $gp (twelve accesses, six of them
   floats), so it belongs in the -G8 unit:
   src/levels/20_yeedil/L20_002DEBE0-g8.c.  The marker is back in place
   there.

   WHAT IT IS.  The second half of the yeedil emitter: the first half is
   func_L20_0039BB18 (which builds a velocity vector and hands it over); this
   one draws the object's trail - it fills two arrays of four positions each
   with a rolling history, moving the old values down and computing the new
   one at the head.

   THE PROLOGUE (0x0039BEC8 .. 0x0039BF38):

     0x0039BEC8  addiu  $sp,$sp,-0x1D0        the frame is 0x1D0
     0x0039BECC  sw     $a0,0x140($sp)       the argument is spilled
     0x0039BED0  sd     $s0,0x170($sp)       the saved GPRs $s0..$s7, $fp, $ra
     0x0039BED4  sd     $s1,0x178($sp)       at 0x170..0x1B8 and the saved
     0x0039BED8  addiu  $s0,$sp,0x90          FPRs $f21, $f20 at 0x1C8, 0x1C0
     0x0039BEDC  sd     $s2,0x180($sp)
     0x00310E04  sd     $s3,0x188($sp)       (the $s0 = sp+0x90 is a pointer
     0x0039BEE4  sd     $s4,0x190($sp)        to the first of the two arrays)
     0x0039BEE8  sd     $s5,0x198($sp)
     0x0039BEEC  sd     $s6,0x1A0($sp)
     0x0039BEF0  sd     $s7,0x1A8($sp)
     0x0039BEF4  sd     $fp,0x1B0($sp)
     0x0039BEF8  sd     $ra,0x1B8($sp)
     0x0039BEFC  swc1   $f21,0x1C8($sp)
     0x0039BF00  swc1   $f20,0x1C0($sp)
     0x0039BF04  lw     $v1,0x140($sp)       the argument again
     0x0039BF08  lw     $v0,0x68($a0)        the object's field at +0x68
     0x0039BF0C  daddu  $a0,$s0,$zero        the first array (sp+0x90)
     0x0039BF10  addiu  $a1,$v1,0xC0        the object's field at +0xC0
     0x0039BF14  jal    func_00302D30       the set-up call
     0x0039BF18  sw     $v0,0x144($sp)       the field is spilled to 0x144
     0x0039BF1C  lw     $v0,0x140($sp)
     0x0039BF20  addiu  $a0,$sp,0xC0        a 16-byte copy of the object
     0x0039BF24  addiu  $v1,$v0,0x10
     0x0039BF28  lq     $v0,0x0($v1)        (the lq/sq pair, the 128-bit
     0x0039BF2C  sq     $v0,0x0($a0)         copy wall)
     0x0039BF30  lw     $a0,-0x384($gp)      = 0x001AEC6C, a small global
     0x0039BF38  daddu  $s3,$zero,$zero      $s3 = 0, the loop counter

   THE FIRST LOOP (0x0039BFC8 .. 0x0039C054), four iterations over the
   history of the first array:

     0x0039BFC8  lwc1   $f1,0x0($s4)        the old x
     0x0039BFCC  andi   $s0,$s3,0x1         the parity of the index
     0x0039BFD0  lwc1   $f0,0x0($s6)        the old y
     0x0039BFD8  swc1   $f1,0x0($s5)        the new x into the array
     0x0039BFDC  addiu  $v1,$gp,-0x380      a table of four ints in the small
     0x0039BFE4  movn   $v0,$zero,$s0       data, indexed by the parity
     0x0039BFE8  addu   $v0,$v0,$v1
     0x0039BFEC  lw     $a0,0x0($v0)        the chosen int
     0x0039BFEC  swc1   $f0,0x0($s7)        the new y into the array
     0x0039C000  jal    func_00303410       the call that draws the segment
     0x0039C00C  jal    func_00302230       a second, tiny call
     0x0039C014  lwc1   $f0,-0x374($gp)     = 0x001AEC7C, a float constant
     0x0039C018  bnez   $s0,...             the parity decides the constant
     0x0039C020  lwc1   $f0,-0x378($gp)     = 0x001AEC78
     0x0039C030  addiu  $s3,$s3,0x1         the counter
     0x0039C034  addiu  $s1,$s1,0x10        the pointers walk on
     0x0039C038  addiu  $s2,$s2,0x4
     0x0039C048  slti   $v0,$s3,0x4         four iterations
     0x0039C050  addiu  $s4,$s4,0x8

   THE SECOND LOOP (0x0039C130 .. 0x0039C1D0) is the same shape for the
   other array, with the extra test `slti $v0,$s3,0x2` and a different
   constant.

   THE TAIL (0x0039C1D4 .. 0x0039C3A8):

     0x0039C1D4  lq     $v0,0x0($a0)        another 128-bit copy
     0x0039C1D8  sq     $v0,0x0($v1)
     0x0039C254  add.s  $f0,$f0,$f1        the value at +0x138 grows
     0x0039C284  jal    func_0032F718       func_002A7878, the random float
     0x0039C298  jal    func_00303410
     0x0039C2B8  jal    func_0032F7E0       func_002A7940, the angle
     0x0039C2D8  jal    func_00300FE8       func_00281EB8
     0x0039C2E4  jal    func_0032F718
     0x0039C348  jal    func_0032F7E0
     0x0039C36C  jal    func_00300FE8
     0x0039C3A4  the restores of $s0..$s7, $fp, $ra and $f20, $f21

   THE CALLS: 26 in all, to 13 distinct callees - func_00302D30, func_002FA720
   (twice), func_00303410 (five times), func_00302230, func_00302AC8,
   func_00300058, func_00302290, func_003396D8, func_00302548 (twice),
   func_00280B90 (twice), func_0032F718 (twice), func_0032F7E0 (three times),
   func_00300FE8 (three times).

   THE $gp ACCESSES (twelve, which is why the body needs -G8; the floats are
   the -0x374/-0x378/-0x33C/-0x308 ones, the ints the -0x384/-0x350/-0x318
   ones):

     0x0039BF30  lw    $a0,-0x384($gp)   = 0x001AEC6C
     0x0039C014  lwc1  $f0,-0x374($gp)   = 0x001AEC7C
     0x0039C020  lwc1  $f0,-0x378($gp)   = 0x001AEC78
     0x0039C10C  lw    $a0,-0x350($gp)   = 0x001AECA0
     0x0039C18C  lwc1  $f12,-0x374($gp)  = 0x001AEC7C
     0x0039C190  lwc1  $f12,-0x33C($gp)  = 0x001AECB4
     0x0039C1A8  lwc1  $f0,-0x378($gp)   = 0x001AEC78
     0x0039C1F8  lwc1  $f0,-0x374($gp)   = 0x001AEC7C
     0x0039C1FC  lwc1  $f0,-0x33C($gp)   = 0x001AECB4
     0x0039C21C  lwc1  $f0,-0x378($gp)   = 0x001AEC78
     0x0039C28C  lw    $a0,-0x318($gp)   = 0x001AECD8
     0x0039C2C8  lwc1  $f12,-0x308($gp)  = 0x001AECE8

   The two `lq`/`sq` pairs at 0x0039BF28 and 0x0039C1D4 are the 128-bit
   copy of the 16-byte object, and the ones at 0x0039C0FC, 0x0039C130 and
   0x0039C234 are the four-float arrays; they are the 128-bit copy wall the
   compiler profile has (see nonmatching/levels/func_L20_0039BB18.c).

*/

   ------------------------------------------------------------------
   2026-10-21, worker 13 of the level-20 wave (wave 5): the map, finer.

   THE LOCALS (the frame is 0x1D0):

       sp+0x70  16 bytes, zeroed with `sd $zero,0x70($sp)`
       sp+0x78  8 bytes: the object's field at +0x68 (`sd $v0,0x78($sp)`)
       sp+0x80  8 bytes: 0xFF900260
       sp+0x88  8 bytes: 0x80000048
       sp+0x90  the first history array, 4 x 16 bytes ($s0 = sp+0x90)
       sp+0xC0  16 bytes: the copy of the object's +0x10 (the lq/sq pair
                at 0x0039BF28)
       sp+0xD0  the second history array, 4 x 16 bytes
       sp+0x110 4 floats (the +0x110 and +0x114 ones are read at
                0x0039C0E4 and 0x0039C0EC)
       sp+0x120 4 ints (sp+0x120 is the copy's destination at 0x0039C1D4)
       sp+0x130 16 bytes: the vector (0x0039C0FC, 0x0039C110, 0x0039C234)
       sp+0x138 a float that grows by 0.666f (0x3EAA7EFA) at 0x0039C284
       sp+0x140 the argument (spilled)
       sp+0x144 the object's field at +0x68 (spilled)
       sp+0x148..0x16C the pointers that the prologue computes and spills
       0x170..0x1B8 the saved GPRs, 0x1C0 and 0x1C8 the saved $f20/$f21

   THE PROLOGUE.  It spills the argument to sp+0x140 and the field at
   +0x68 to sp+0x144, sets $s0 = sp+0x90 (the first array), $s1 = sp,
   $s3 = 0 (the loop counter) and $fp = 0xFFFFFFFF (the mask), calls
   func_00302D30 (with $a0 = the first array and $a1 = the argument's
   +0xC0), copies 16 bytes from the argument's +0x10 to sp+0xC0, and
   spills eight pointers to 0x148..0x168 (sp+0x40, sp+0x50, sp+0x54,
   sp+0xD0, sp+0x100, sp+0x110, sp+0x120, sp+0x130).

   THE FIRST LOOP (0x0039BFC8 .. 0x0039C050), four iterations:

       0x0039BFC8  lwc1  $f1, 0x0($s4)      the old x ($s4 = $gp-0x370)
       0x0039BFCC  andi  $s0, $s3, 0x1     the parity of the counter
       0x0039BFD0  lwc1  $f0, 0x0($s6)      the old y ($s6 = D_001AEC84)
       0x0039BFD4  addiu $v0, $zero, 0x4
       0x0039BFD8  swc1  $f1, 0x0($s5)      the new x into the array
       0x0039BFDC  addiu $v1, $gp, -0x380  the table of four ints
       0x0039BFE0  movn  $v0, $zero, $s0   4 or 0, by the parity
       0x0039BFE4  addu  $v0, $v0, $v1
       0x0039BFE8  lw    $a0, 0x0($v0)      the chosen int
       0x0039BFEC  swc1  $f0, 0x0($s7)      the new y into the array
       0x0039BFF0  sw    $a0, 0x0($s2)      the int into the int array
       0x0039BFF4  daddu $a1, $a0, $zero
       0x0039BFF8  and   $a0, $a0, $fp      the int & 0xFFFFFFFF
       0x0039BFFC  lw    $v0, 0x144($sp)    the field at +0x68
       0x0039C000  jal   f_00303410         func_00283410(int, int, float)
       0x0039C004   lwc1  $f12, 0x0($v0)
       0x0039C008  sw    $v0, 0x0($s2)      the field's value into the array
       0x0039C00C  jal   f_00302230         func_00282230(int)
       0x0039C010   daddu $a0, $s1, $zero
       0x0039C014  lwc1  $f0, -0x374($gp)   0x001AEC7C
       0x0039C018  bnez  $s0, .L0039C02C    the parity decides the constant
       0x0039C01C   swc1  $f0, 0x0($s1)
       0x0039C020  lwc1  $f0, -0x378($gp)   0x001AEC78
       0x0039C024  b     .L0039C030
       0x0039C028   swc1  $f0, 0x8($s1)
       .L0039C02C:
       0x0039C02C  sw    $zero, 0x8($s1)
       .L0039C030:
       0x0039C030  addiu $s3, $s3, 0x1
       0x0039C034  addiu $s1, $s1, 0x10
       0x0039C038  addiu $s2, $s2, 0x4
       0x0039C03C  addiu $s7, $s7, 0x8
       0x0039C040  addiu $s6, $s6, 0x8
       0x0039C044  addiu $s5, $s5, 0x8
       0x0039C048  slti  $v0, $s3, 0x4
       0x0039C04C  bnez  $v0, .L0039BFC8
       0x0039C050   addiu $s4, $s4, 0x8

   THE MIDDLE (0x0039C054 .. 0x0039C12C): the argument is read again, a
   16-byte zero is built at sp+0x100 (`por $v1,$zero,$zero ; sq $v1,
   0x100($sp)`), 0x3E490FDB (pi/4) is stored at sp+0x108, and
   func_00302AC8, func_00300058 (with 1 and 0x20), func_00302290 (with
   D_1B9FC0), func_003396D8 and func_002FA720 are called; a 16-byte
   vector is built at sp+0x130 (the negated float at +0x110, the one at
   +0x114, 1.0f at +0x13C and the negated value at +0x134) and copied to
   sp+0x120.

   THE SECOND LOOP (0x0039C130 .. 0x0039C1D0) is the same shape for the
   other array, with three differences: the old x comes from $s4 (now
   $gp-0x338), the y is added to the x (`add.s $f0,$f0,$f1`), the int
   table is at $gp-0x348, and the test is `slti $v0,$s3,0x2` (the
   constant of the branch-likely is 0x001AEC7C or 0x001AECB4).

   THE TAIL (0x0039C1D4 .. 0x0039C3A8): the 16-byte copy from sp+0x120
   to sp+0x130's slot, then a THIRD loop (0x0039C1F0 .. 0x0039C230, four
   iterations, with the same 0x001AEC7C / 0x001AECB4 choice), then
   func_00282548 (f_00302548) twice, the float at sp+0x138 grown by
   0.666f, and the long tail of calls: func_0032F718 (the random float)
   twice, func_0032F7E0 (the angle) twice, func_00300FE8 twice,
   func_00303410 four times, with D_001AECDC, D_001AECE0, D_001AECE4 and
   D_001AECEC (a float) as the arguments.

   THE $gp ACCESSES, again with their addresses: -0x384 (0x001AEC6C),
   -0x380 (a table of four ints), -0x374 (0x001AEC7C), -0x378
   (0x001AEC78), -0x370, -0x348, -0x338, -0x33C (0x001AECB4), -0x350
   (0x001AECA0), -0x318 (0x001AECD8), -0x308 (0x001AECE8).
