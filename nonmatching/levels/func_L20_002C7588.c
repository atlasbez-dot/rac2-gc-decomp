/* Body map for func_L20_002C7588 (level 20, 876 bytes, 219 instructions).
   No C attempt: this worker ran out of budget after the other three map
   functions of this file.  The full retail body is below, so the next attempt
   does not have to map it again.  Not linked, not counted.

   The full retail body (the whole 219 instructions, read out of
   build/reference/20_yeedil.elf at 0x002C7588):

===== func_L20_002C7588 @ 002C7588 =====
    /* 6BEB8 002C7588 70FFBD27 */  addiu      $sp, $sp, -0x90
    /* 6BEBC 002C758C 1900023C */  lui        $v0, %hi(D_189F10)
    /* 6BEC0 002C7590 4000B0FF */  sd         $s0, 0x40($sp)
    /* 6BEC4 002C7594 4800B1FF */  sd         $s1, 0x48($sp)
    /* 6BEC8 002C7598 109F5024 */  addiu      $s0, $v0, %lo(D_189F10)
    /* 6BECC 002C759C 5000B2FF */  sd         $s2, 0x50($sp)
    /* 6BED0 002C75A0 2D888000 */  daddu      $s1, $a0, $zero
    /* 6BED4 002C75A4 5800B3FF */  sd         $s3, 0x58($sp)
    /* 6BED8 002C75A8 2D904000 */  daddu      $s2, $v0, $zero
    /* 6BEDC 002C75AC 6000B4FF */  sd         $s4, 0x60($sp)
    /* 6BEE0 002C75B0 2D200002 */  daddu      $a0, $s0, $zero
    /* 6BEE4 002C75B4 6800BFFF */  sd         $ra, 0x68($sp)
    /* 6BEE8 002C75B8 8000B6E7 */  swc1       $f22, 0x80($sp)
    /* 6BEEC 002C75BC 7800B5E7 */  swc1       $f21, 0x78($sp)
    /* 6BEF0 002C75C0 609E0B0C */  jal        f_002E7980
    /* 6BEF4 002C75C4 7000B4E7 */   swc1      $f20, 0x70($sp)
    /* 6BEF8 002C75C8 DA3A013C */  lui        $at, (0x3ADA740F >> 16)
    /* 6BEFC 002C75CC 0F742134 */  ori        $at, $at, (0x3ADA740F & 0xFFFF)
    /* 6BF00 002C75D0 00088144 */  mtc1       $at, $f1
    /* 6BF04 002C75D4 00000000 */  nop
    /* 6BF08 002C75D8 34000146 */  c.lt.s     $f0, $f1
    /* 6BF0C 002C75DC 00000000 */  nop
    /* 6BF10 002C75E0 BA000345 */  bc1tl      .L002C78CC
    /* 6BF14 002C75E4 4000B0DF */   ld        $s0, 0x40($sp)
    /* 6BF18 002C75E8 10FF0426 */  addiu      $a0, $s0, -0xF0
    /* 6BF1C 002C75EC BD3E013C */  lui        $at, (0x3EBD70A4 >> 16)
    /* 6BF20 002C75F0 A4702134 */  ori        $at, $at, (0x3EBD70A4 & 0xFFFF)
    /* 6BF24 002C75F4 00A88144 */  mtc1       $at, $f21
    /* 6BF28 002C75F8 9C22828C */  lw         $v0, 0x229C($a0)
    /* 6BF2C 002C75FC 003F013C */  lui        $at, (0x3F000000 >> 16)
    /* 6BF30 002C7600 00B08144 */  mtc1       $at, $f22
    /* 6BF34 002C7604 EFFF4224 */  addiu      $v0, $v0, -0x11
    /* 6BF38 002C7608 0200422C */  sltiu      $v0, $v0, 0x2
    /* 6BF3C 002C760C 07004050 */  beql       $v0, $zero, .L002C762C
    /* 6BF40 002C7610 B4228490 */   lbu       $a0, 0x22B4($a0)
    /* 6BF44 002C7614 00A88044 */  mtc1       $zero, $f21
    /* 6BF48 002C7618 333F013C */  lui        $at, (0x3F333333 >> 16)
    /* 6BF4C 002C761C 33332134 */  ori        $at, $at, (0x3F333333 & 0xFFFF)
    /* 6BF50 002C7620 00B08144 */  mtc1       $at, $f22
    /* 6BF54 002C7624 11000010 */  b          .L002C766C
    /* 6BF58 002C7628 00000000 */   nop
  .L002C762C:
    /* 6BF5C 002C762C 01000224 */  addiu      $v0, $zero, 0x1
    /* 6BF60 002C7630 09008214 */  bne        $a0, $v0, .L002C7658
    /* 6BF64 002C7634 04000224 */   addiu     $v0, $zero, 0x4
    /* 6BF68 002C7638 B33E013C */  lui        $at, (0x3EB33333 >> 16)
    /* 6BF6C 002C763C 33332134 */  ori        $at, $at, (0x3EB33333 & 0xFFFF)
    /* 6BF70 002C7640 00A88144 */  mtc1       $at, $f21
    /* 6BF74 002C7644 8A3E013C */  lui        $at, (0x3E8A3D71 >> 16)
    /* 6BF78 002C7648 713D2134 */  ori        $at, $at, (0x3E8A3D71 & 0xFFFF)
    /* 6BF7C 002C764C 00B08144 */  mtc1       $at, $f22
    /* 6BF80 002C7650 06000010 */  b          .L002C766C
    /* 6BF84 002C7654 00000000 */   nop
  .L002C7658:
    /* 6BF88 002C7658 04008214 */  bne        $a0, $v0, .L002C766C
    /* 6BF8C 002C765C 00000000 */   nop
    /* 6BF90 002C7660 B33E013C */  lui        $at, (0x3EB33333 >> 16)
    /* 6BF94 002C7664 33332134 */  ori        $at, $at, (0x3EB33333 & 0xFFFF)
    /* 6BF98 002C7668 00A88144 */  mtc1       $at, $f21
  .L002C766C:
    /* 6BF9C 002C766C 00A08044 */  mtc1       $zero, $f20
    /* 6BFA0 002C7670 86AB0046 */  mov.s      $f14, $f21
    /* 6BFA4 002C7674 2D20A003 */  daddu      $a0, $sp, $zero
    /* 6BFA8 002C7678 01000524 */  addiu      $a1, $zero, 0x1
    /* 6BFAC 002C767C 06A30046 */  mov.s      $f12, $f20
    /* 6BFB0 002C7680 829D0B0C */  jal        f_002E7608
    /* 6BFB4 002C7684 46A30046 */   mov.s     $f13, $f20
    /* 6BFB8 002C7688 993E013C */  lui        $at, (0x3E99999A >> 16)
    /* 6BFBC 002C768C 9A992134 */  ori        $at, $at, (0x3E99999A & 0xFFFF)
    /* 6BFC0 002C7690 00708144 */  mtc1       $at, $f14
    /* 6BFC4 002C7694 2000A427 */  addiu      $a0, $sp, 0x20
    /* 6BFC8 002C7698 2DA08000 */  daddu      $s4, $a0, $zero
    /* 6BFCC 002C769C 06A30046 */  mov.s      $f12, $f20
    /* 6BFD0 002C76A0 82AB0E46 */  mul.s      $f14, $f21, $f14
    /* 6BFD4 002C76A4 46A30046 */  mov.s      $f13, $f20
    /* 6BFD8 002C76A8 829D0B0C */  jal        f_002E7608
    /* 6BFDC 002C76AC 01000524 */   addiu     $a1, $zero, 0x1
    /* 6BFE0 002C76B0 0C002056 */  bnel       $s1, $zero, .L002C76E4
    /* 6BFE4 002C76B4 1900123C */   lui       $s2, %hi(D_189E20)
    /* 6BFE8 002C76B8 109F5126 */  addiu      $s1, $s2, -0x60F0
    /* 6BFEC 002C76BC F0080C0C */  jal        f_003023C0
    /* 6BFF0 002C76C0 2D202002 */   daddu     $a0, $s1, $zero
    /* 6BFF4 002C76C4 233C013C */  lui        $at, (0x3C23D70A >> 16)
    /* 6BFF8 002C76C8 0AD72134 */  ori        $at, $at, (0x3C23D70A & 0xFFFF)
    /* 6BFFC 002C76CC 00088144 */  mtc1       $at, $f1
    /* 6C000 002C76D0 00000000 */  nop
    /* 6C004 002C76D4 34000146 */  c.lt.s     $f0, $f1
    /* 6C008 002C76D8 00000000 */  nop
    /* 6C00C 002C76DC 13000045 */  bc1f       .L002C772C
    /* 6C010 002C76E0 1900123C */   lui       $s2, %hi(D_189E20)
  .L002C76E4:
    /* 6C014 002C76E4 1000B027 */  addiu      $s0, $sp, 0x10
    /* 6C018 002C76E8 209E5126 */  addiu      $s1, $s2, %lo(D_189E20)
    /* 6C01C 002C76EC 06B30046 */  mov.s      $f12, $f22
    /* 6C020 002C76F0 2D282002 */  daddu      $a1, $s1, $zero
    /* 6C024 002C76F4 52090C0C */  jal        f_00302548
    /* 6C028 002C76F8 2D200002 */   daddu     $a0, $s0, $zero
    /* 6C02C 002C76FC 2D980002 */  daddu      $s3, $s0, $zero
    /* 6C030 002C7700 B33F013C */  lui        $at, (0x3FB33333 >> 16)
    /* 6C034 002C7704 33332134 */  ori        $at, $at, (0x3FB33333 & 0xFFFF)
    /* 6C038 002C7708 00608144 */  mtc1       $at, $f12
    /* 6C03C 002C770C 3000A227 */  addiu      $v0, $sp, 0x30
    /* 6C040 002C7710 2D282002 */  daddu      $a1, $s1, $zero
    /* 6C044 002C7714 2D204000 */  daddu      $a0, $v0, $zero
    /* 6C048 002C7718 02B30C46 */  mul.s      $f12, $f22, $f12
    /* 6C04C 002C771C 52090C0C */  jal        f_00302548
    /* 6C050 002C7720 2D884000 */   daddu     $s1, $v0, $zero
    /* 6C054 002C7724 14000010 */  b          .L002C7778
    /* 6C058 002C7728 2D30A003 */   daddu     $a2, $sp, $zero
  .L002C772C:
    /* 6C05C 002C772C 1000B027 */  addiu      $s0, $sp, 0x10
    /* 6C060 002C7730 2D282002 */  daddu      $a1, $s1, $zero
    /* 6C064 002C7734 06A30046 */  mov.s      $f12, $f20
    /* 6C068 002C7738 A09E0B0C */  jal        f_002E7A80
    /* 6C06C 002C773C 2D200002 */   daddu     $a0, $s0, $zero
    /* 6C070 002C7740 06B30046 */  mov.s      $f12, $f22
    /* 6C074 002C7744 2D200002 */  daddu      $a0, $s0, $zero
    /* 6C078 002C7748 2D280002 */  daddu      $a1, $s0, $zero
    /* 6C07C 002C774C 52090C0C */  jal        f_00302548
    /* 6C080 002C7750 2D980002 */   daddu     $s3, $s0, $zero
    /* 6C084 002C7754 1900123C */  lui        $s2, %hi(D_189E20)
    /* 6C088 002C7758 3000B127 */  addiu      $s1, $sp, 0x30
    /* 6C08C 002C775C B33F013C */  lui        $at, (0x3FB33333 >> 16)
    /* 6C090 002C7760 33332134 */  ori        $at, $at, (0x3FB33333 & 0xFFFF)
    /* 6C094 002C7764 00608144 */  mtc1       $at, $f12
    /* 6C098 002C7768 2D202002 */  daddu      $a0, $s1, $zero
    /* 6C09C 002C776C B4080C0C */  jal        f_003022D0
    /* 6C0A0 002C7770 2D280002 */   daddu     $a1, $s0, $zero
    /* 6C0A4 002C7774 2D30A003 */  daddu      $a2, $sp, $zero
  .L002C7778:
    /* 6C0A8 002C7778 2D206002 */  daddu      $a0, $s3, $zero
    /* 6C0AC 002C777C 2D286002 */  daddu      $a1, $s3, $zero
    /* 6C0B0 002C7780 98080C0C */  jal        f_00302260
    /* 6C0B4 002C7784 FFFF1024 */   addiu     $s0, $zero, -0x1
    /* 6C0B8 002C7788 2D202002 */  daddu      $a0, $s1, $zero
    /* 6C0BC 002C778C 2D282002 */  daddu      $a1, $s1, $zero
    /* 6C0C0 002C7790 98080C0C */  jal        f_00302260
    /* 6C0C4 002C7794 2D308002 */   daddu     $a2, $s4, $zero
    /* 6C0C8 002C7798 209E4226 */  addiu      $v0, $s2, %lo(D_189E20)
    /* 6C0CC 002C779C 2D208002 */  daddu      $a0, $s4, $zero
    /* 6C0D0 002C77A0 9022478C */  lw         $a3, 0x2290($v0)
    /* 6C0D4 002C77A4 2D282002 */  daddu      $a1, $s1, $zero
    /* 6C0D8 002C77A8 02000624 */  addiu      $a2, $zero, 0x2
    /* 6C0DC 002C77AC 2EC90B0C */  jal        f_002F24B8
    /* 6C0E0 002C77B0 2D400000 */   daddu     $t0, $zero, $zero
    /* 6C0E4 002C77B4 07004010 */  beqz       $v0, .L002C77D4
    /* 6C0E8 002C77B8 1C00023C */   lui       $v0, %hi(D_1C041C)
    /* 6C0EC 002C77BC 1C04438C */  lw         $v1, %lo(D_1C041C)($v0)
    /* 6C0F0 002C77C0 05006018 */  blez       $v1, .L002C77D8
    /* 6C0F4 002C77C4 209E4226 */   addiu     $v0, $s2, %lo(D_189E20)
    /* 6C0F8 002C77C8 08D80B0C */  jal        f_002F6020
    /* 6C0FC 002C77CC 00000000 */   nop
    /* 6C100 002C77D0 2D804000 */  daddu      $s0, $v0, $zero
  .L002C77D4:
    /* 6C104 002C77D4 209E4226 */  addiu      $v0, $s2, %lo(D_189E20)
  .L002C77D8:
    /* 6C108 002C77D8 2D286002 */  daddu      $a1, $s3, $zero
    /* 6C10C 002C77DC 9022478C */  lw         $a3, 0x2290($v0)
    /* 6C110 002C77E0 2D20A003 */  daddu      $a0, $sp, $zero
    /* 6C114 002C77E4 00A08044 */  mtc1       $zero, $f20
    /* 6C118 002C77E8 02000624 */  addiu      $a2, $zero, 0x2
    /* 6C11C 002C77EC 2EC90B0C */  jal        f_002F24B8
    /* 6C120 002C77F0 2D400000 */   daddu     $t0, $zero, $zero
    /* 6C124 002C77F4 08004010 */  beqz       $v0, .L002C7818
    /* 6C128 002C77F8 1C00023C */   lui       $v0, %hi(D_1C0400)
    /* 6C12C 002C77FC 00044224 */  addiu      $v0, $v0, %lo(D_1C0400)
    /* 6C130 002C7800 1C00438C */  lw         $v1, 0x1C($v0)
    /* 6C134 002C7804 04006018 */  blez       $v1, .L002C7818
    /* 6C138 002C7808 00000000 */   nop
    /* 6C13C 002C780C 749F0B0C */  jal        f_002E7DD0
    /* 6C140 002C7810 40004424 */   addiu     $a0, $v0, 0x40
    /* 6C144 002C7814 06050046 */  mov.s      $f20, $f0
  .L002C7818:
    /* 6C148 002C7818 5F3F013C */  lui        $at, (0x3F5F66F4 >> 16)
    /* 6C14C 002C781C F4662134 */  ori        $at, $at, (0x3F5F66F4 & 0xFFFF)
    /* 6C150 002C7820 00008144 */  mtc1       $at, $f0
    /* 6C154 002C7824 00000000 */  nop
    /* 6C158 002C7828 36001446 */  c.le.s     $f0, $f20
    /* 6C15C 002C782C 00000000 */  nop
    /* 6C160 002C7830 07000145 */  bc1t       .L002C7850
    /* 6C164 002C7834 1C00023C */   lui       $v0, %hi(D_1C0400)
    /* 6C168 002C7838 08000224 */  addiu      $v0, $zero, 0x8
    /* 6C16C 002C783C 03000212 */  beq        $s0, $v0, .L002C784C
    /* 6C170 002C7840 0C000224 */   addiu     $v0, $zero, 0xC
    /* 6C174 002C7844 21000216 */  bne        $s0, $v0, .L002C78CC
    /* 6C178 002C7848 4000B0DF */   ld        $s0, 0x40($sp)
  .L002C784C:
    /* 6C17C 002C784C 1C00023C */  lui        $v0, %hi(D_1C0400)
  .L002C7850:
    /* 6C180 002C7850 209E4526 */  addiu      $a1, $s2, %lo(D_189E20)
    /* 6C184 002C7854 00044224 */  addiu      $v0, $v0, %lo(D_1C0400)
    /* 6C188 002C7858 00A08044 */  mtc1       $zero, $f20
    /* 6C18C 002C785C 1800438C */  lw         $v1, 0x18($v0)
    /* 6C190 002C7860 40005024 */  addiu      $s0, $v0, 0x40
    /* 6C194 002C7864 F000B124 */  addiu      $s1, $a1, 0xF0
    /* 6C198 002C7868 2D200002 */  daddu      $a0, $s0, $zero
    /* 6C19C 002C786C 7002A3AC */  sw         $v1, 0x270($a1)
    /* 6C1A0 002C7870 06A30046 */  mov.s      $f12, $f20
    /* 6C1A4 002C7874 A09E0B0C */  jal        f_002E7A80
    /* 6C1A8 002C7878 2D280002 */   daddu     $a1, $s0, $zero
    /* 6C1AC 002C787C 803F013C */  lui        $at, (0x3F800000 >> 16)
    /* 6C1B0 002C7880 00608144 */  mtc1       $at, $f12
    /* 6C1B4 002C7884 2D200002 */  daddu      $a0, $s0, $zero
    /* 6C1B8 002C7888 52090C0C */  jal        f_00302548
    /* 6C1BC 002C788C 2D280002 */   daddu     $a1, $s0, $zero
    /* 6C1C0 002C7890 2D200002 */  daddu      $a0, $s0, $zero
    /* 6C1C4 002C7894 D4080C0C */  jal        f_00302350
    /* 6C1C8 002C7898 2D282002 */   daddu     $a1, $s1, $zero
    /* 6C1CC 002C789C 34001446 */  c.lt.s     $f0, $f20
    /* 6C1D0 002C78A0 00000000 */  nop
    /* 6C1D4 002C78A4 08000045 */  bc1f       .L002C78C8
    /* 6C1D8 002C78A8 2D200002 */   daddu     $a0, $s0, $zero
    /* 6C1DC 002C78AC 07030046 */  neg.s      $f12, $f0
    /* 6C1E0 002C78B0 B4080C0C */  jal        f_003022D0
    /* 6C1E4 002C78B4 2D280002 */   daddu     $a1, $s0, $zero
    /* 6C1E8 002C78B8 2D202002 */  daddu      $a0, $s1, $zero
    /* 6C1EC 002C78BC 2D300002 */  daddu      $a2, $s0, $zero
    /* 6C1F0 002C78C0 98080C0C */  jal        f_00302260
    /* 6C1F4 002C78C4 2D288000 */   daddu     $a1, $a0, $zero
  .L002C78C8:
    /* 6C1F8 002C78C8 4000B0DF */  ld         $s0, 0x40($sp)
  .L002C78CC:
    /* 6C1FC 002C78CC 4800B1DF */  ld         $s1, 0x48($sp)
    /* 6C200 002C78D0 5000B2DF */  ld         $s2, 0x50($sp)
    /* 6C204 002C78D4 5800B3DF */  ld         $s3, 0x58($sp)
    /* 6C208 002C78D8 6000B4DF */  ld         $s4, 0x60($sp)
    /* 6C20C 002C78DC 6800BFDF */  ld         $ra, 0x68($sp)
    /* 6C210 002C78E0 8000B6C7 */  lwc1       $f22, 0x80($sp)
    /* 6C214 002C78E4 7800B5C7 */  lwc1       $f21, 0x78($sp)
    /* 6C218 002C78E8 7000B4C7 */  lwc1       $f20, 0x70($sp)
    /* 6C21C 002C78EC 0800E003 */  jr         $ra
    /* 6C220 002C78F0 9000BD27 */   addiu     $sp, $sp, 0x90


   What the body needs from the compiler:

    - the address of D_00189F10 in two shapes out of one lui: the address in a
      register ("addiu $s0,$v0,%lo(D_189F10)") and the %hi copied out
      ("daddu $s2,$v0,$zero") with the %lo added at every use.  A `long` is
      64 bit in this ABI, a pointer is 32 bit.
    - the float constants must be spelled exactly (these are the values the
      retail's hex holds and the literals this compiler turns into that hex):
      0x3ADA740F = 0.0016666668 -> 0.0016666668f, 0x3EBD70A4 = 0.37 ->
      0.37f, 0x3F000000 = 0.5 (NOT 1.0f!), 0x3F333333 = 0.7, 0x3F199999 =
      0.599999964 -> 0.59999996f, 0x3E99999A = 0.3 -> 0.3f, 0x3D888889 =
      0.06666667 -> 0.06666667f, 0x3CA3D70A = 0.02 -> 0.02f.
    - the float branch is the branch-LIKELY form ("c.lt.s" + "bc1tl"); a
      negated comparison with the operands swapped selects its polarity
      ("if (!(a > b)) {} else { x = 1; }" emits "c.lt.s b,a" + "bc1tl", the
      plain "if (a < b)" emits "c.lt.s a,b" + "bc1fl").
    - the frame is 0x90 with $s0..$s4 and $f20..$f22 spilled; the argument
      is widened into $s1 ("daddu $s1,$a0,$zero") and the %hi copy into $s2.
   */
