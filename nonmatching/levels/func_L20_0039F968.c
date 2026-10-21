/* Not matched (worker 06, level-20 wave of 2026-10-20).

   This body belongs in the `-G8` unit: it reads a float through `$gp`
   (`lwc1 $f12,-0x2B4($gp)`), which only comes out of a file built with
   `-G8`, so it cannot live in the -G0 unit
   (src/levels/20_yeedil/L20_0039C448.c).

   Its one 128-bit copy is `lq $v0,0x0($a0)` / `sq $v0,0x0($a1)` - both
   sides are parameters, so this compiler does reproduce that form; the
   `$gp` access is what keeps it out of reach here.

   The body is 996 bytes with a frame of 0x250. */

/* ------------------------------------------------------------------
   Fourth note (worker 07, level-20 wave of 2026-10-20): the analysis of
   the wave, and where the wall of the note on func_L20_0039C448 in this
   directory bites.

   This body is one of the few of the level whose 128-bit copy is NOT
   behind the wall: the copy is in a loop whose pointers are incremented at
   the end of the body, so the address is a plain register and the
   retail's form falls out of the source:

       .L0039FA58:
       lq   $v0, 0x0($a0)      ; the address is a register, no offset
       sq   $v0, 0x0($a1)
       addiu $a0, $a0, -0x10
       addiu $a2, $a2, -0x1
       nop
       bgtz $a2, .L0039FA58
         addiu $a1, $a1, -0x10

   So it is the `$gp` access (the note above) that keeps it out of reach
   in the -G0 unit, and it belongs in L20_0039C448-g8.c.  The rest of the
   body is a table walk over D_L20_001B3870 with a 0x19-entry bound, the
   float helpers func_002A7878 / func_00283B98 / func_00283180 /
   func_00283198 (the same ones as func_L20_0039E1E8) and the same pi/180
   constant (0x3C8EFA36, which needs the literal 0.017453294f in this
   compiler - see the note on func_L20_0039E1E8).

   The other bodies of this wave are behind the wall:
     - func_L20_0039EBB8 (444 bytes): `addiu $s2, $s1, 0x10 ; lq $v0, 0x0($s2)`,
       `addiu $v1, $sp, 0x10 ; sq $v0, 0x0($v1)`, `addiu $v1, $s0, 0x60 ; lq $v0,
       0x0($v1)` - a register base with an offset, and a stack address;
     - func_L20_0039CF58 (996 bytes): `addiu $v1, $s1, 0x10 ; lq $v0, 0x0($v1)` and
       `addiu $a0, $sp, 0x20 ; sq $v0, 0x0($a0)`;
     - func_L20_0039EEC8 (836 bytes): `addiu $v1, $s6, 0x10 ; sq $v0, 0x0($v1)`,
       `addiu $v1, $s3, 0x10 ; sq $v0, 0x0($v1)` (its other two copies, `lq $v0,
       0x0($s0)` and `sq $v0, 0x0($s3)`, are plain registers and are fine);
     - func_L20_003E6FA0 (1804 bytes): `addiu $a0, $s1, 0x10 ; lq $v0, 0x0($a0)`,
       `addiu $v1, $sp, 0x230 ; sq $v0, 0x0($v1)`, `addiu $v1, $sp, 0x250 ; sq $v0,
       0x0($v1)`, `addiu $v1, $a1, 0x20 ; lq $v0, 0x0($v1)` (its other four copies
       are plain registers and are fine);
     - func_L20_0039C5D0 (756 bytes): `addiu $v1, $sp, 0x10 ; sq $v0, 0x0($v1)` - a
       stack address.
   ------------------------------------------------------------------ */

/* ------------------------------------------------------------------
   Fifth note (worker 05, level-20 wave 5, 2026-10-21): the gp offsets,
   measured, and the wall that is not a wall any more.

   The gp offsets of this body, $gp = 0x001AEFF0:

     -0x2B4 -> 0x001AED3C   float 0.0f    (0x00000000)
     -0x2B0 -> 0x001AED40   float 6.0f    (0x40C00000)
     -0x2AC -> 0x001AED44   int   0x20000000
     -0x2A8 -> 0x001AED48   int   0x207F7F7F
     -0x2A4 -> 0x001AED4C   int   0x20000000
     -0x2A0 -> 0x001AED50   float 3.0f    (0x40400000)
     -0x29C -> 0x001AED54   float 0.0f    (0x00000000)
     -0x298 -> 0x001AED58   float 4.0f    (0x40800000)

   The C names are D_L20_001AED3C and so on; the floats and the ints need
   __attribute__((sda)) so that they come out through $gp.

   For the colleague who owns func_L20_0039F560 (it is in worker 06's list),
   the gp offsets of that body are:

     -0x2D0 -> 0x001AED20   int   21       (0x00000015)
     -0x2CC -> 0x001AED24   float 20.0f    (0x41A00000)
     -0x2C8 -> 0x001AED28   float 0.3f     (0x3E99999A)
     -0x2C4 -> 0x001AED2C   float 1.125f   (0x3F900000)
     -0x2C0 -> 0x001AED30   int   0x18000000

   Two more bodies of this level reach a global through $gp and belong in the
   -G8 unit as well: func_L20_0039EEC8 (`lwc1 $f12,-0x2B0($gp)`, eight times,
   the level-20 address 0x001AED40, the float 6.0f) and func_L20_003E6FA0
   (`lwc1 $f26,0x1324($gp)`, eight times, the level-20 address 0x001A8FF4, the
   float 0.0f).  Both are in worker 05's list and both are left with their
   INCLUDE_ASM marker; the notes on them are in this directory.
   ------------------------------------------------------------------ */
