/* func_L04_002E7C08 - 14304 bytes (3576 instructions), 1 placement (level 4, barlow).
    NOT MATCHED.  The C below is the attempt of wave 35, worker 02 (the eleventh
    pass).  The BLOCK MAP and the MEASUREMENTS are the record.

    ---------------------------------------------------------------------------
    WAVE 35, WORKER 02 - THE SECOND CHAIN IS NOT A SWITCH, AND EVERY ONE OF
    ITS BODIES WAS ONE POSITION OFF
    ---------------------------------------------------------------------------
        04_barlow: 14032 bytes, expected 14304      (wave 34: 13968)
        func_L04_002E7C08: 0 of 1 places match

    The first difference is STILL the branch displacement at 0x002E7C58 (the
    `bne $s1,$v0`), and the prologue still matches instruction for
    instruction.  The body is 272 bytes short (wave 34: 336).

    Measured with difflib over the two instruction columns of
    `tools/check.py --diff`, with the symbol names and the branch
    displacements normalised:

        wave 34   1943 instructions aligned equal   (their number)
        wave 35   2117 instructions aligned equal   (this attempt)

    ---------------------------------------------------------------------------
    THE FINDINGS OF THIS PASS
    ---------------------------------------------------------------------------

    1. THE CHAIN AT 0x002EA39C IS NOT A SWITCH.  It is an if/else chain of
       FOURTEEN tests over f2294, and the attempt's `switch` compiled to a
       jump table - which was most of the biggest hole in the body.

       The tests are read off the DELAY SLOTS, each of which loads the NEXT
       case's value:

           002EA3A0  addiu $v0, $zero, 0x7      ; the value the first test
           002EA3A8  bne  $v1, $v0, .L002EA3C0  ; compares against 7
           002EA3AC  addiu $v0, $zero, 0x6E     ; the next value
           002EA3C0  bne  $v1, $v0, .L002EA3D8  ; compares against 0x6E
           002EA3C4  addiu $v0, $zero, 0x81
           002EA3D8  bne  $v1, $v0, .L002EA3F0  ; 0x81
           002EA3DC  addiu $v0, $zero, 0x12
           002EA3F0  bne  $v1, $v0, .L002EA414  ; 0x12
           002EA3F4  addiu $v0, $zero, 0x9
           002EA414  bne  $v1, $v0, .L002EA45C  ; 9
           002EA418  addiu $v0, $zero, 0xA
           002EA45C  bne  $v1, $v0, .L002EA474  ; 0x0A
           002EA460  addiu $v0, $zero, 0x10
           002EA474  bne  $v1, $v0, .L002EA4DC  ; 0x10
           002EA478  addiu $v0, $zero, 0x1B
           002EA4DC  bne  $v1, $v0, .L002EA4F4  ; 0x1B
           002EA4E0  addiu $v0, $zero, 0x89
           002EA4F4  bne  $v1, $v0, .L002EA518  ; 0x89
           002EA4F8  addiu $v0, $zero, 0x11
           002EA518  bne  $v1, $v0, .L002EA530  ; 0x11
           002EA51C  addiu $v0, $zero, 0xD
           002EA530  bne  $v1, $v0, .L002EA548  ; 0x0D
           002EA534  addiu $v0, $zero, 0xE
           002EA548  bne  $v1, $v0, .L002EA578  ; 0x0E
           002EA54C  addiu $v0, $zero, 0xF
           002EA578  bne  $v1, $v0, .L002EA590  ; 0x0F
           002EA57C  addiu $v0, $zero, 0xB
           002EA590  bne  $v1, $v0, .L002EB268  ; 0x0B, else the tail

       so the case values are 7, 0x6E, 0x81, 0x12, 9, 0x0A, 0x10, 0x1B, 0x89,
       0x11, 0x0D, 0x0E, 0x0F, 0x0B - the same list the attempt had.

       THE BODIES, HOWEVER, WERE ALL ONE POSITION OFF (except the first
       three, which are the same body, and the last).  The body that FOLLOWS
       a test belongs to the value that test compares against - the constant
       the PREVIOUS test's delay slot loaded.  The correct map is:

           7     -> func_L00_002D2168(0x07, 0, 5.0f)
           0x6E  -> func_L00_002D2168(0x07, 0, 5.0f)
           0x81  -> func_L00_002D2168(0x07, 0, 5.0f)
           0x12  -> func_L00_002D2168(0x6B, 1, -1.0f)
           9     -> the fC38 block, then func_L00_002D2168(s, 0, 5.0f)
           0x0A  -> func_L00_002D2168(0x12, 0, 5.0f)
           0x10  -> the f22A4/f22A0/f1B8 test, then
                    func_L00_002D2168(0x26, 0, 8.0f) and f4AC += 3, or
                    func_L00_002D2168(0x26, 0, 5.0f)
           0x1B  -> func_L00_002D2168(0x22, 0, 4.0f)
           0x89  -> func_L00_002D2168(0x7D, 0x0B, 9.0f)
           0x11  -> func_L00_002D2168(0x23, 2, 7.0f)
           0x0D  -> func_L00_002D2168(0x11, 0, 5.0f)
           0x0E  -> func_L00_002D2168(0x16, 3, 7.0f) and fC20 = 0.8f
           0x0F  -> func_L00_002D2168(0x15, 0, 5.0f)   <- a body NO attempt had
           0x0B  -> the D_001A7A45 block, then the f22A4 == 4 test

       The attempt had the (0x6B, 1, -1.0f) body under 9, the fC38 block
       under 0x0A, and so on down to the (0x15, 0, 5.0f) body, which was
       missing entirely.

       PROOF FROM THE BODIES THEMSELVES: the retail's body at 0x002EA3F8 (the
       fall-through of the test that compares 0x12) is
       `lui 0xBF800000; mtc1; addiu $a0,0x6B; jal; addiu $a1,1`, i.e.
       (-1.0f, 0x6B, 1); the body at 0x002EA41C (the fall-through of the test
       that compares 9) is the fC38 block; and the body at 0x002EA464 (the
       fall-through of the test that compares 0x0A) is
       `lui 0x40A00000; mtc1; b .L002EB210; addiu $a0,0x12`.

    2. THE 0x3E CASE'S f24CC > 0 ARM COMES AFTER THE CASE'S MAIN PATH.
       The retail:

           002EAF28  lw    $v0, 0x24CC($s0)
           002EAF2C  bgtz  $v0, .L002EB024      ; if f24CC > 0, the ARM
           002EAF30  addiu $v0, $zero, 0x4D     ; the arm's f1DC = 0x4D
           002EAF34  <the float chain>
           ...
           002EB00C  addiu $v0, $zero, 0x46
           002EB010  addiu $v1, $zero, 0x96
           002EB014  sh    $v0, 0x1D0($s0)      ; f1D0 = 0x46
           002EB018  daddu $v0, $zero, $zero
           002EB01C  b     .L002EB3B8          ; return 0
           002EB020  sh    $v1, 0x1F4($s0)      ; f1F4 = 0x96 (delay slot)
           002EB024  <the arm>

       so the source is `if (f24CC <= 0) { <the chain>; ...; return 0; }`
       and the ARM FOLLOWS it - not `if (f24CC > 0) { <the arm> } else {...}`
       with the arm first.  The attempt had the arm before the chain.

    3. THE 0x0B BODY SWAPS TWO BYTES OF A WORD, AND THE RESULT IS THE
       CALL'S FIRST ARGUMENT.  The retail:

           002EA598  lw    $v0, 0x4D4($s0)
           002EA59C  lui   $v1, 0x1A
           002EA5A0  lbu   $v1, 0x7A45($v1)     ; D_001A7A45
           002EA5A4  beqz  $v1, .L002EA5C4
           002EA5A8  addiu $a0, $v0, 0x1C       ; a0 = f4D4 + 0x1C
           002EA5AC  addiu $v1, $zero, 0x1C
           002EA5B0  bne   $a0, $v1, .L002EA5C0
           002EA5B4  xori  $v0, $a0, 0x1D
           002EA5B8  b     .L002EA5C4
           002EA5BC  addiu $a0, $zero, 0x1D
           002EA5C0  movz  $a0, $v1, $v0

       There is no `andi` - the value is a WORD, not a byte - and the two
       constants 0x1C and 0x1D are SWAPPED.  The result is $a0, the first
       argument of the func_L00_002D2168 call that follows.  The attempt had
       a `u8` (so gcc emitted an `andi`) and three identical calls.

    4. THE 0x09 BODY'S TABLE BYTE IS AT 0x001A8DE0 = D_001A8DD8 + 8, and
       the argument starts at 8:

           002EA41C  lwc1      $f12, 0xC38($s0)
           002EA420  jal       f_0030FF98        ; func_00283CF0(fC38)
           002EA424  addiu     $s1, $zero, 0x8   ; the argument starts at 8
           002EA428  lbu       $a0, 0x42($s5)
           002EA42C  jal       f_002CC7D8        ; func_L00_002A4EF0(...)
           002EA430  daddu     $s0, $v0, $zero   ; the index
           002EA438  bne       $v0, $v1, .L002EA44C
           002EA440  addiu     $v0, $gp, -0x7210 ; 0x001A8DE0
           002EA444  addu      $v0, $s0, $v0
           002EA448  lbu       $s1, 0x0($v0)     ; the table byte

       so the source is

           s = 8;
           v = func_00283CF0(fC38);
           t = func_L00_002A4EF0(*(u8 *)(((u8 *)f2290) + 0x42));
           if (t == 4)
               s = *(u8 *)(((u8 *)D_001A8DD8) + 8 + v);
           func_L00_002D2168(s, 0, 5.0f);

    5. THE RETAIL USES $gp-RELATIVE ADDRESSING IN ELEVEN PLACES; FOUR OF
       THEM ARE DATA WORDS WITH NO NAME IN THE TREE YET:

           002E8294  lw    $a1, 0x3C88($gp)   = 0x001E3C78  (NO NAME)
           002E895C  addiu $v1, $gp, -0x7218   = 0x001A8DD8  D_001A8DD8
           002E8A30  addiu $v1, $gp, -0x7218   = 0x001A8DD8  D_001A8DD8
           002E9558  lw    $v0, -0x5FFC($gp)  = 0x001A3FF4  (NO NAME)
           002E9848  lwc1  $f2, -0x7318($gp)  = 0x001A7CD8  D_L04_001A7CD8
           002E9850  lwc1  $f1, -0x7314($gp)  = 0x001A7CDC  D_L04_001A7CDC
           002EA100  addiu $a1, $gp, -0x71F0  = 0x001A7E00  D_L04_001A7E00
           002EA440  addiu $v0, $gp, -0x7210  = 0x001A8DE0  D_001A8DD8 + 8
           002EA640  lw    $v1, -0x7C60($gp)  = 0x001A8390  (NO NAME)
           002EA898  lw    $v1, -0x7C60($gp)  = 0x001A8390  (NO NAME)
           002EAAB4  lw    $v1, -0x7C60($gp)  = 0x001A8390  (NO NAME)

       $gp is 0x001AFFF0.  0x001E3C78, 0x001A3FF4 and 0x001A8390 are inside
       unnamed blobs of the level-4 and boot data files, so they need a name
       before they can be written as C.

       MEASURED ABOUT `sda` IN A -G0 UNIT (worth knowing, it is a trap):
       `extern f32 D_L04_001A7CD8 __attribute__((sda));` makes cc1 emit
       `l.s $f0,D_L04_001A7CD8`, but gas expands `l.s` into lui/%lo because the
       symbol is UNDEFINED in the object - the object gets HI16+LO16, not
       GPREL16.  On an ARRAY whose ADDRESS is taken the same attribute does
       give GPREL16 (measured on src/levels/shared/L22_0039D708.c, whose
       D_L22_001B2AB4 gets one GPREL16 and five HI16/LO16 pairs).  So `sda`
       on a scalar float value load does NOT reproduce the retail's
       `lwc1 $f2, -0x7318($gp)`.

    6. THE SECOND BIG BLOCK'S COUNTER BLOCKS: the u16 counter is loaded
       ONCE and the s32 maximum is an UNSIGNED compare.  The retail:

           002EA634  lhu   $v1, 0xC($a3)
           002EA638  sltu  $v0, $t1, $v1        ; $t1 = 0xFFFE
           002EA63C  bnel  $v0, $zero, .L002EA654
           002EA640  lw    $v1, -0x7C60($gp)    ; the delay slot, dead
           002EA644  addiu $v0, $v1, 0x1
           002EA648  sh    $v0, 0xC($a3)
           ...
           002EA654  lw    $v0, 0x10($a3)
           002EA658  sltu  $v0, $v0, $v1        ; UNSIGNED
           002EA65C  bnel  $v0, $zero, .L002EA664
           002EA660  sw    $v1, 0x10($a3)      ; the delay slot

       so the source is `u16 c = *(u16 *)(p + 0x0C); if (c < 0xFFFF)
       *(u16 *)(p + 0x0C) = c + 1;` and
       `if ((u32)D_001A7390 > *(u32 *)(p + 0x10)) *(s32 *)(p + 0x10) =
       D_001A7390;`.

    7. THE 0x04 CASE'S TEST IS A NESTED `if` IN THE SOURCE.  The retail has
       THREE branches where the attempt's `&&` gives two:

           002E8BF4  lbu   $v0, 0x149A($s0)
           002E8BF8  beql  $v0, $zero, .L002E8C14
           002E8BFC  addiu $s0, $s4, -0x61E0
           002E8C00  lh    $v0, 0x34C($s0)
           002E8C04  bnez  $v0, .L002E8C14
           002E8C08  addiu $s0, $s4, -0x61E0
           002E8C0C  b     .L002E95A8          ; the call_76 tail
           002E8C10  addiu $a0, $zero, 0x76

       i.e. `if (f149A != 0) { if (f34C == 0) goto call_76; }`.

    8. THE RETAIL RE-MATERIALISES THE ACTOR'S ADDRESS 130 TIMES
       (`addiu $reg, $s4, -0x61E0`), the attempt keeps it in $s0.  That is
       the reload pass re-forming the split address after every call, and
       it is a function of the whole body's register pressure - it will not
       fall out of a local edit.

    9. THE BIG BLOCK'S 0x0F CASE DOES NOT STORE f444.  The retail's
       `addiu $a1, $gp, -0x71F0` (the address of D_L04_001A7E00) is DEAD in
       that block; the attempt's `f444 = D_L04_001A7E00;` is an extra store
       AND a wrong value (the retail uses the ADDRESS, not the value).

    ---------------------------------------------------------------------------
    WHERE THE REMAINING 272 BYTES ARE
    ---------------------------------------------------------------------------

    The biggest holes of the aligned diff (the retail's range, the number of
    retail instructions, and what it is):

        38  002E822C..002E82C0  case 0x36's f118 block
        35  002EB004..002EB08C  case 0x3E's f24CC > 0 arm
        31  002E852C..002E85A4  case 0x67's second counter block
        27  002EA880..002EA8E8  the second big block's case 0x14
        24  002E7EA0..002E7EFC  case 0x00's head
        24  002EA088..002EA0E4  the big block's case 0x0F
        23  002E8BD0..002E8C28  case 0x04's head
        22  002E815C..002E81B0  case 0x33's tail
        22  002E9414..002E9468  case 0x08's head
        21  002EA650..002EA6A0  the second big block's head
        20  002E9B38..002E9B84  the big block's case 0x6E
        16  002E8420..002E845C  case 0x35/0x67's boundary
        15  002EAE98..002EAED0  case 0x16's tail

    The chain at 0x002EA39C is now an if/else chain with the right bodies;
    what is left of it is that gcc CROSS-JUMPED the three identical
    (0x07, 0, 5.0f) bodies into one (the retail keeps three copies inline,
    8 instructions = 32 bytes).  Writing the chain as separate `if`s and as
    an `else if` chain makes NO difference (measured: the object is 14032
    bytes either way), so the lever is elsewhere.

    ---------------------------------------------------------------------------
    THE NEXT WORKER'S LIST
    ---------------------------------------------------------------------------

    * the three identical chain bodies.  The retail has

          002EA3B0  lui $at, 0x40A00000; mtc1 $at,$f12; b .L002EB210
          002EA3BC  addiu $a0, $zero, 0x7
          002EA3C8  lui $at, 0x40A00000; mtc1 $at,$f12; b .L002EB210
          002EA3D4  addiu $a0, $zero, 0x7
          002EA3E0  lui $at, 0x40A00000; mtc1 $at,$f12; b .L002EB210
          002EA3EC  addiu $a0, $zero, 0x7

      three times, inline.  The attempt gets one copy and two branches into
      it.  The bodies have to be made non-identical in a way that still
      assembles to the same bytes.

    * the big block's 0x0F case (retail 0x002EA01C..0x002EA120, 19
      instructions where the attempt has 8).  The store order there is
      f4AC f4B8 f4C8 f4CC f4D0 f50C f508 f518 f510 f51A f4A4 f526 f1D0
      f49D f4A8 f430 f52E f434 f438 f43C f440 - note f518 BEFORE f510, and
      NO f444.

    * the second big block's head (retail 0x002EA604..0x002EA6AC).  The
      `lw $v1, -0x7C60($gp)` (0x001A8390) is the word the two counter
      blocks' u16 test uses - it has NO NAME yet.

    * case 0x36's f118 block: the retail's func_002FD1B8 calls pass SEVEN
      arguments (three integers and four floats), so the prototype in this
      file has to be

          extern void func_002FD1B8(u32 a0, u32 a1, void *a2,
                                   f32 f12, f32 f13, f32 f14, f32 f15);

      and the second call's $a1 is the word at 0x001B3B78 ($gp+0x3C88),
      which has NO NAME in the tree yet.

    ---------------------------------------------------------------------------
    THE TOOLS THAT PRODUCED THIS
    ---------------------------------------------------------------------------

    * `python3 tools/check.py func_L04_002E7C08 --diff` - the two columns.
      NOTE: when the sizes differ, check.py prints the OBJECT's bytes, so
      every `%hi`/`%lo` shows as 0 and every `jal` as 0.  The script used
      here applies the relocations (the symbol values are known by name:
      build.Placement.expected); it is at /tmp/opencode/difftool.py.
    * the aligned diff: difflib over the two instruction columns with the
      branch displacements and the offsets normalised.
    * `python3 /tmp/opencode/range.py <lo> <hi>` - the retail listing of
      level 4 between two addresses (it reads
      build/04_barlow/asm/*.s).

*/

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;
typedef unsigned long long u64;
typedef int TI128 __attribute__((mode(TI)));

extern s32 D_001A8F00;
extern s32 D_001A7390;
extern s32 D_001A79F0;
extern u8 D_001A7A45;
extern s32 D_L04_001A93F4;
extern f32 D_L04_001A7CD8 __attribute__((sda));
extern f32 D_L04_001A7CDC __attribute__((sda));
extern u32 D_L04_001A7E00 __attribute__((sda));
extern u32 D_L04_001A7DE0;
extern s32 D_001A8DD8[] __attribute__((sda));
extern s32 D_001A7B90;
extern u8 D_00189F10[];
extern u8 D_00189F80[];
extern u8 D_0018A210[];
extern u8 D_0018C360[];
extern u8 D_0018C750[];
extern u8 D_L04_001B2C70[];
extern u8 D_L04_001B2C78[];
extern u8 D_L04_001B9540[];
extern u8 D_L04_00276890[];
extern u8 D_L04_00276A20[];
extern u8 D_L04_00276BB0[];

extern s32 func_L04_002CC748(s32 a0);
extern void func_L00_002D2168(s32 a0, s32 a1, f32 f12);
extern void func_L00_002A4EF8(s32 a0);
extern s32 func_L00_002A4EF0(u8 a0);
extern s32 func_00283CF0(f32 f12);
extern void func_00282C88(void *a0);
extern f32 func_00282C48(f32 f12);
extern void func_L00_002D6900(s32 a0);
extern f32 func_00283248(f32 f12, f32 f13);
extern void func_L00_002B9B88(s32 a0, s32 a1);
extern void func_L00_002AF7D0(void);
extern void func_002AC9F8(f32 f12, void *a0);
extern s32 func_002A7470(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_L00_002B75A0(f32 f12, f32 f13, f32 f14);
extern void func_L00_002B6118(f32 f12);
extern void func_L00_00322EC8(void *a0);
extern void func_L00_00322A98(void *a0, void *a1);
extern void *func_002A9640(void *a0, s32 a1, s32 a2);
extern f32 func_002A78D8(f32 f12, f32 f13);
extern f32 func_00283B98(f32 f12, f32 f13);
extern f32 func_00282E20(void *a0);
extern void func_L00_002D2470(s32 a0, s32 a1, s32 a2);
extern s32 func_L00_002ADE68(s32 a0);
extern s32 func_L00_002B3248(s32 a0);
extern void func_L00_002AABE0(s32 a0, s32 a1, s32 a2);
extern s32 func_L00_002A6708(s32 a0);
extern f32 func_002FD1B8(f32 f12, f32 f13, f32 f14, f32 f15);
extern f32 func_00283C80(f32 f12, f32 f13);
extern f32 func_L00_002D3A58(void *a0);
extern void func_L00_002D3B58(void *a0, void *a1, f32 f12);
extern s32 func_L00_002CAF20(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_L01_002C1988(s32 a0, void *a1);
extern s32 func_L00_002C3A78(void);
extern void func_L00_002BA508(s32 a0);
extern f32 func_L00_002B9B38(void *a0, void *a1);
extern s32 func_L00_002B39F0(s32 a0, f32 f12);
extern void func_L00_002AF3D8(s32 a0, s32 a1);
extern void func_L00_002AE070(s32 a0, s32 a1);
extern s32 func_L00_002ADF80(s32 a0);
extern s32 func_L00_002AB3E0(s32 a0, s32 a1, s32 a2);
extern s32 func_L00_002A61C8(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_L00_0035F5A0(s32 a0, s32 a1);
extern void func_L00_002D6940(void);
extern s32 func_002A7820(s32 a0, s32 a1);
extern f32 func_00283198(f32 f12);
extern f32 func_00283180(f32 f12);
extern void func_00282D30(void *a0, void *a1);
extern s32 func_00282CF0(void *a0, void *a1, void *a2);
extern f32 func_00282E48(void *a0, void *a1);
extern void func_L00_00322AC0(void *a0, s32 a1, s32 a2, f32 f12);
extern void func_L00_0041E958(f32 f12, f32 f13, f32 f14);

/* the level's actor update: a state machine over one actor's own fields, with the
   level's shared globals as the world state.  The case bodies below are the
   small ones, transcribed from the retail; the two big groups (0x002E94F0 and
   0x002EA604) are the field-table work and are described in the header note. */
typedef struct {
    f32 f0;
    u8 pad4[124];
    f32 f80;
    f32 f84;
    f32 f88;
    u8 pad8C[12];
    f32 f98;
    u8 pad9C[4];
    u8 fA0;
    u8 padA1[79];
    u8 fF0[16];
    u8 pad100[16];
    u8 f110[8];
    f32 f118;
    u8 pad11C[4];
    TI128 f120;
    u8 pad130[48];
    u8 f160[16];
    f32 f170;
    f32 f174;
    f32 f178;
    u8 pad17C[8];
    u8 f184;
    u8 pad185[11];
    u8 f190;
    u8 pad191[15];
    f32 f1A0;
    u8 pad1A4[16];
    f32 f1B4;
    s32 f1B8;
    s32 f1BC;
    s32 f1C0;
    s32 f1C4;
    u8 pad1C8[8];
    u16 f1D0;
    u8 pad1D2[10];
    u16 f1DC;
    u8 pad1DE[14];
    u16 f1EC;
    u8 pad1EE[2];
    u16 f1F0;
    s16 f1F2;
    u16 f1F4;
    u8 pad1F6[4];
    s16 f1FA;
    u8 pad1FC[10];
    u16 f206;
    u8 pad208[6];
    u16 f20E;
    u8 pad210[2];
    s16 f212;
    u8 pad214[264];
    f32 f31C;
    u8 pad320[16];
    f32 f330;
    u8 pad334[8];
    s32 f33C;
    u8 pad340[8];
    s16 f348;
    u8 pad34A[2];
    s16 f34C;
    u8 pad34E[182];
    s32 f404;
    f32 f408;
    u8 f40C;
    u8 pad40D[1];
    u8 f40E;
    u8 f40F;
    s32 f410;
    u8 pad414[28];
    s32 f430;
    s32 f434;
    f32 f438;
    f32 f43C;
    s32 f440;
    s32 f444;
    u8 f448;
    u8 pad449[11];
    f32 f454;
    s32 f458;
    u8 pad45C[20];
    u8 f470;
    u8 pad471[15];
    u8 f480;
    u8 pad481[15];
    f32 f490;
    u8 f494;
    u8 pad495[3];
    f32 f498;
    u8 f49C;
    u8 f49D;
    u8 f49E;
    u8 f49F;
    u8 f4A0;
    u8 pad4A1[3];
    f32 f4A4;
    f32 f4A8;
    u16 f4AC;
    u8 pad4AE[2];
    f32 f4B0;
    s32 f4B4;
    f32 f4B8;
    s32 f4BC;
    f32 f4C0;
    f32 f4C4;
    f32 f4C8;
    f32 f4CC;
    f32 f4D0;
    s32 f4D4;
    f32 f4D8;
    f32 f4DC;
    u8 f4E0;
    u8 pad4E1[15];
    u8 f4F0;
    u8 pad4F1[15];
    f32 f500;
    f32 f504;
    f32 f508;
    f32 f50C;
    f32 f510;
    f32 f514;
    u16 f518;
    u16 f51A;
    u8 pad51C[4];
    f32 f520;
    u16 f524;
    u16 f526;
    u16 f528;
    u16 f52A;
    u8 f52C;
    u8 f52D;
    u8 f52E;
    u8 f52F;
    u8 pad530[76];
    f32 f57C;
    f32 f580;
    u8 pad584[16];
    s32 f594;
    u8 pad598[12];
    s32 f5A4;
    s32 f5A8;
    u8 pad5AC[4];
    f32 f5B0;
    u8 pad5B4[4];
    f32 f5B8;
    u16 f5BC;
    u16 f5BE;
    u8 pad5C0[128];
    s32 f640;
    f32 f644;
    u8 pad648[44];
    s32 f674;
    u8 pad678[8];
    f32 f680;
    u8 pad684[24];
    f32 f69C;
    u8 pad6A0[36];
    s32 f6C4;
    u8 pad6C8[200];
    f32 f790;
    f32 f794;
    s32 f798;
    f32 f79C;
    f32 f7A0;
    u8 pad7A4[4];
    s32 f7A8;
    u8 pad7AC[628];
    s32 fA20;
    u8 padA24[16];
    s32 fA34;
    u8 padA38[4];
    s32 fA3C;
    u8 padA40[10];
    u16 fA4A;
    u8 padA4C[2];
    s16 fA4E;
    s32 fA50;
    u8 padA54[44];
    f32 fA80;
    f32 fA84;
    u8 padA88[8];
    f32 fA90;
    f32 fA94;
    u8 padA98[8];
    s32 fAA0;
    s32 fAA4;
    u8 padAA8[12];
    s32 fAB4;
    u8 padAB8[4];
    f32 fABC;
    u8 padAC0[16];
    s32 fAD0;
    s32 fAD4;
    u8 padAD8[4];
    u16 fADC;
    u16 fADE;
    f32 fAE0;
    f32 fAE4;
    f32 fAE8;
    f32 fAEC;
    f32 fAF0;
    f32 fAF4;
    f32 fAF8;
    u16 fAFC;
    u16 fAFE;
    f32 fB00;
    f32 fB04;
    f32 fB08;
    f32 fB0C;
    s32 fB10;
    u8 padB14[8];
    s32 fB1C;
    u8 padB20[160];
    u8 fBC0;
    u8 padBC1[15];
    u8 fBD0;
    u8 padBD1[15];
    u8 fBE0;
    u8 padBE1[3];
    s32 fBE4;
    s32 fBE8;
    f32 fBEC;
    f32 fBF0;
    f32 fBF4;
    u8 padBF8[4];
    u16 fBFC;
    u16 fBFE;
    s32 fC00;
    u8 padC04[8];
    u32 fC0C;
    u8 padC10[16];
    f32 fC20;
    u8 padC24[12];
    s32 fC30;
    s32 fC34;
    f32 fC38;
    u8 padC3C[1356];
    s32 f1188;
    u8 pad118C[20];
    s32 f11A0;
    u8 pad11A4[124];
    s32 f1220;
    u8 pad1224[36];
    s32 f1248;
    u8 pad124C[76];
    s32 f1298;
    u8 pad129C[420];
    u8 f1440;
    u8 pad1441[19];
    s16 f1454;
    u8 pad1456[2];
    f32 f1458;
    u8 pad145C[54];
    u8 f1492;
    u8 pad1493[1];
    u8 f1494;
    u8 pad1495[5];
    u8 f149A;
    u8 pad149B[2];
    u8 f149D;
    u8 pad149E[98];
    s32 f1500;
    u8 pad1504[812];
    s32 f1830;
    u8 pad1834[32];
    s32 f1854;
    u8 pad1858[136];
    u8 f18E0;
    u8 pad18E1[335];
    u8 f1A30;
    u8 pad1A31[2143];
    s32 f2290;
    s32 f2294;
    s32 f2298;
    s32 f229C;
    s32 f22A0;
    s32 f22A4;
    s32 f22A8;
    s32 f22AC;
    s32 f22B0;
    u8 f22B4;
    u8 f22B5;
    u8 pad22B6[1];
    u8 f22B7;
    u8 pad22B8[1];
    u8 f22B9;
    u8 f22BA;
    u8 pad22BB[1];
    u8 f22BC;
    u8 f22BD;
    u8 pad22BE[1];
    u8 f22BF;
    u8 pad22C0[2];
    u8 f22C2;
    u8 f22C3;
    u8 pad22C4[8];
    s32 f22CC;
    u8 pad22D0[48];
    s32 f2300;
    s32 f2304;
    u8 pad2308[20];
    s32 f231C;
    s32 f2320;
    u8 pad2324[380];
    s32 f24A0;
    u8 pad24A4[20];
    f32 f24B8;
    u8 pad24BC[8];
    f32 f24C4;
    s32 f24C8;
    s32 f24CC;
    u8 pad24D0[6];
    u16 f24D6;
    u16 f24D8;
    u8 f24DA;
    u8 f24DB;
    u8 pad24DC[19];
    u8 f24EF;
    u8 pad24F0[20];
    u16 f2504;
} Actor;
extern u8 D_00189E20[];

s32 func_L04_002E7C08(s32 a0, s32 a1) {
    s32 s1 = a0;
    s32 s3 = a1;
    s32 s2, s5, s6, t0;
    s32 v9;
    u8 b9;
    f32 f9;
    f32 f12v;

    /* 002E7C44: the level's own state; 0x14 is the state that wants 0x61/2 */
    if (((Actor *)D_00189E20)->f229C == 0x14) {
        if (s1 != 0x61)
            return 0;
        if (s3 != 2)
            return 0;
    }
    /* 002E7C6C: the world's state; 2 and 6 want the second argument to be 2 */
    if (D_001A8F00 == 2 || D_001A8F00 == 6) {
        if (s3 != 2)
            return 0;
    }
    /* 002E7C94 */
    if (((Actor *)D_00189E20)->f24CC != 0)
        goto t0_one;
    if (((Actor *)D_00189E20)->f229C == 2 || ((Actor *)D_00189E20)->f229C == 7) {
        if (s1 != 0x6 && s1 != 0x39 && s1 != 0x43 && s1 != 0x91 &&
            s1 != 0x5F && s1 != 0x74 && s1 != 0x78 && s1 != 0x79 &&
            s1 != 0x7C && s1 != 0x67 && s1 != 0x7D && s1 != 0x7F)
            return 0;
        goto t0_one;
    }
    t0 = 1;
    goto field_shift;
t0_one:
    t0 = 1;
field_shift:
    /* 002E7D24: the actor's own fields shift one slot along */
    ((Actor *)D_00189E20)->f22AC = ((Actor *)D_00189E20)->f22A0;
    ((Actor *)D_00189E20)->f22B0 = ((Actor *)D_00189E20)->f22A4;
    ((Actor *)D_00189E20)->f22A8 = ((Actor *)D_00189E20)->f1B8;
    ((Actor *)D_00189E20)->f22A0 = ((Actor *)D_00189E20)->f2294;
    ((Actor *)D_00189E20)->f22A4 = ((Actor *)D_00189E20)->f229C;
    ((Actor *)D_00189E20)->f2294 = s1;
    s2 = ((Actor *)D_00189E20)->f2298;
    ((Actor *)D_00189E20)->f2298 = 0;
    if (((Actor *)D_00189E20)->f22B5 == t0)
        ((Actor *)D_00189E20)->f22B5 = 0;
    s5 = ((Actor *)D_00189E20)->f2290;
    s6 = ((Actor *)D_00189E20)->f22B7;

    /* 002E7D6C: the reset of the actor's flags, then the two world calls */
    ((Actor *)D_00189E20)->f22BC = 0;
    if (((Actor *)D_00189E20)->f22B4 == 0) {
        *(s32 *)(((u8 *)((Actor *)D_00189E20)->f2290) + 0x9C) = 0;
        ((Actor *)D_00189E20)->f22BD = 0;
        ((Actor *)D_00189E20)->f22B7 = 0;
        ((Actor *)D_00189E20)->f22C2 = 0;
        ((Actor *)D_00189E20)->f22BF = 0;
        func_L00_00322EC8(&((Actor *)D_00189E20)->f18E0);
        ((Actor *)D_00189E20)->f2504 = 0;
    }
    if (((Actor *)D_00189E20)->f1FA == 0)
        func_L00_002D6940();
    func_L00_002AF3D8(((Actor *)D_00189E20)->f22A0, ((Actor *)D_00189E20)->f2294);
    ((Actor *)D_00189E20)->f1188 = 0;

    switch (s1) {
    /* 002E7DE4 */
    case 0x00:
        ((Actor *)D_00189E20)->f229C = 0;
        ((Actor *)D_00189E20)->f24A0 = 0;
        if (((Actor *)D_00189E20)->f1248 == 0x1A)
            func_L00_002AF7D0();
        func_002A7820(0x32, 0x64);
        ((Actor *)D_00189E20)->f24EF = 0;
        ((Actor *)D_00189E20)->f11A0 = func_L00_002AB3E0(0, 0, 0);
        if (((Actor *)D_00189E20)->f22B4 != 0) {
            func_L01_002C1988(0, &((Actor *)D_00189E20)->f160[0]);
            return 1;
        }
        *(TI128 *)&((Actor *)D_00189E20)->f160[0] = *(TI128 *)&((Actor *)D_00189E20)->f120;
        if (((Actor *)D_00189E20)->f1492 != 0) {
            if (0.008333334f < func_00282E20(&((Actor *)D_00189E20)->f160[0]))
                goto call_2e;
        }
        if (((Actor *)D_00189E20)->f149A != 0 &&
            ((Actor *)D_00189E20)->f34C == 0)
            goto call_76;
        ((Actor *)D_00189E20)->f1188 = 0x68;
        if (s3 == 0)
            goto tail_default;
        if (func_L04_002CC748(0) == 0x51) {
            func_L00_002D2168(func_L04_002CC748(0), 0, 18.0f);
            goto tail_default;
        }
        func_L00_002D2168(func_L04_002CC748(0), 0, -1.0f);
        goto tail_default;

    /* 002E7EEC */
    case 0x64:
        ((Actor *)D_00189E20)->f229C = 0;
        func_00282C88(&((Actor *)D_00189E20)->f160[0]);
        ((Actor *)D_00189E20)->f24A0 = 0;
        ((Actor *)D_00189E20)->f1188 = 0x68;
        if (s3 == 0)
            goto tail_default;
        if (func_L04_002CC748(0) == 0x51) {
            func_L00_002D2168(func_L04_002CC748(0), 0, 18.0f);
            goto tail_default;
        }
        func_L00_002D2168(func_L04_002CC748(0), 0, -1.0f);
        goto tail_default;

    /* 002E7F50 */
    case 0x3d:
        func_L00_002D2168(func_L04_002CC748(0), 0, 9.0f);
        if (((Actor *)D_00189E20)->f1854 != 0)
            func_002A7470(((Actor *)D_00189E20)->f1854, 0, 0, 9);
        goto tail_default;

    /* 002E7F90 */
    case 0x39:
        ((Actor *)D_00189E20)->f229C = 0x14;
        ((Actor *)D_00189E20)->f24A0 = 0;
        *(TI128 *)&((Actor *)D_00189E20)->f160[0] = *(TI128 *)&((Actor *)D_00189E20)->f120;
        if (s3 == 0)
            goto tail_default;
        func_L00_002D2168(0x45, 0, 12.0f);
        goto tail_default;

    /* 002E7FC8 */
    case 0x7c:
        ((Actor *)D_00189E20)->f229C = 0x14;
        ((Actor *)D_00189E20)->f24A0 = 0;
        ((Actor *)D_00189E20)->f79C = ((Actor *)D_00189E20)->f330 - 0.37f;
        ((Actor *)D_00189E20)->f24CC = 0;
        ((Actor *)D_00189E20)->f1F0 = 0x2710;
        ((Actor *)D_00189E20)->f794 = ((Actor *)D_00189E20)->f118 * 0.2f;
        if (((Actor *)D_00189E20)->f118 * 0.2f < -0.116666675f)
            ((Actor *)D_00189E20)->f794 = -0.116666675f;
        ((Actor *)D_00189E20)->f22B7 = 1;
        ((Actor *)D_00189E20)->f7A0 = 0;
        ((Actor *)D_00189E20)->f790 = ((Actor *)D_00189E20)->f88 -
                                       ((Actor *)D_00189E20)->f79C;
        if (s3 == 0)
            goto tail_default;
        func_L00_002D2168(0x6D, 0, 12.0f);
        goto tail_default;

    /* 002E805C */
    case 0x32:
        ((Actor *)D_00189E20)->f229C = 0x11;
        ((Actor *)D_00189E20)->f24A0 = 0x0B;
        ((Actor *)D_00189E20)->f22B7 = 1;
        if (((Actor *)D_00189E20)->f22A4 != 0x12) {
            ((Actor *)D_00189E20)->fA3C = 0;
            ((Actor *)D_00189E20)->fA34 = 0x2D;
        } else {
            func_L00_002B9B88(3, 0);
            ((Actor *)D_00189E20)->f2298 = 1;
        }
        ((Actor *)D_00189E20)->f1188 = 0x68;
        ((Actor *)D_00189E20)->fA20 = 0;
        if (s3 == 0)
            goto tail_default;
        func_L00_002D2168(0x3B, 0, 12.0f);
        goto tail_default;

    /* 002E80D4 */
    case 0x34:
        ((Actor *)D_00189E20)->f229C = 0x11;
        ((Actor *)D_00189E20)->f22B7 = 1;
        ((Actor *)D_00189E20)->fA34 = 0x3C;
        ((Actor *)D_00189E20)->f24A0 = 0x0B;
        if (((Actor *)D_00189E20)->f22A4 == 0x12) {
            func_L00_002B9B88(3, 0);
            ((Actor *)D_00189E20)->f2298 = 1;
        }
        ((Actor *)D_00189E20)->f1188 = 0x68;
        ((Actor *)D_00189E20)->fA20 = 0;
        if (s3 == 0)
            goto tail_default;
        if (((Actor *)D_00189E20)->f22A0 ^ 0x32)
            func_L00_002D2168(0x3D, 0, 11.0f);
        else
            func_L00_002D2168(0x3D, 0, 15.0f);
        goto tail_default;

    /* 002E8158 */
    case 0x33:
        ((Actor *)D_00189E20)->f229C = 0x11;
        ((Actor *)D_00189E20)->f24A0 = 0x0B;
        ((Actor *)D_00189E20)->f22B7 = 1;
        *(TI128 *)&((Actor *)D_00189E20)->f160[0] = *(TI128 *)&((Actor *)D_00189E20)->f120;
        ((Actor *)D_00189E20)->f1188 = 0x68;
        if (((Actor *)D_00189E20)->f22A0 ^ 0x34)
            func_L00_002D2168(0x3C, 0, -2.0f);
        else
            func_L00_002D2168(0x3C, 0, 35.0f);
        goto tail_default;

    /* 002E81B8 */
    case 0x36:
        ((Actor *)D_00189E20)->f229C = 0x12;
        ((Actor *)D_00189E20)->f24A0 = 0;
        ((Actor *)D_00189E20)->f22B7 = 1;
        if (((Actor *)D_00189E20)->f22A4 != 0x11) {
            ((Actor *)D_00189E20)->fA4A = 0;
            func_L00_002AABE0(3, 0x0A, 0);
        } else if (D_L04_001B2C70[0] != 0) {
            func_002FD1B8(((Actor *)D_00189E20)->f80, ((Actor *)D_00189E20)->f84, 0.4f, 0.3f);
        }
        /* 002E8234 */
        if (!(((Actor *)D_00189E20)->f118 < -0.008333334f)) {
            func_00282C48(0.0f);
            func_L00_002AABE0(3, (func_00283CF0(func_00282C48(0.0f) * 300.0f) < 0x29) ? 0x28 : 0x29, 1);
            if (D_L04_001B2C70[0] != 0)
                func_002FD1B8(((Actor *)D_00189E20)->f80, ((Actor *)D_00189E20)->f84, 0.4f, 0.3f);
        }
        /* 002E82C8 */
        ((Actor *)D_00189E20)->f794 = ((Actor *)D_00189E20)->f118 * 0.37f;
        if (((Actor *)D_00189E20)->f118 * 0.37f < -0.116666675f)
            ((Actor *)D_00189E20)->f794 = -0.116666675f;
        ((Actor *)D_00189E20)->f798 = 0;
        ((Actor *)D_00189E20)->f79C = ((Actor *)D_00189E20)->f330;
        ((Actor *)D_00189E20)->f7A0 = 0;
        ((Actor *)D_00189E20)->f790 = ((Actor *)D_00189E20)->f88 -
                                       ((Actor *)D_00189E20)->f330 + 0.09166667f;
        *(TI128 *)&((Actor *)D_00189E20)->f160[0] = *(TI128 *)&((Actor *)D_00189E20)->f120;
        *(s32 *)&((Actor *)D_00189E20)->f160[8] = 0;
        func_002AC9F8(0.09166667f, &((Actor *)D_00189E20)->fF0[0]);
        ((Actor *)D_00189E20)->f1188 = 0x68;
        if (s3 == 0)
            goto tail_default;
        func_L00_002D2168(0x3A, 0, 22.0f);
        goto tail_default;

    /* 002E8368 */
    case 0x72:
    case 0x73:
        ((Actor *)D_00189E20)->f229C = 7;
        ((Actor *)D_00189E20)->f24A0 = 0;
        func_L00_002B6118(0.5f);
        ((Actor *)D_00189E20)->f22B7 = 1;
        *(TI128 *)&((Actor *)D_00189E20)->fF0[0] = *(TI128 *)&((Actor *)D_00189E20)->f110[0];
        {
            void *p = func_002A9640((void *)((Actor *)D_00189E20)->f2290, 1, 0);
            if (p == 0) {
                func_L00_002A4EF8(1);
            } else {
                func_00283CF0(*(f32 *)((u8 *)p + 0x2C));
                func_L00_002A4EF8(p);
            }
        }
        if (s3 == 0)
            goto tail_default;
        ((Actor *)D_00189E20)->f1DC = 0x4D;
        if (((Actor *)D_00189E20)->f2294 == 0x72) {
            func_L00_002D2168(0x69, 3, -3.0f);
        } else {
            func_L00_002D2168(0x64, 3, -3.0f);
        }
        {
            f32 *tbl = (f32 *)((u8 *)D_L04_00276A20 +
                               ((Actor *)D_00189E20)->fC30 * 100 +
                               ((Actor *)D_00189E20)->fC34 * 4);
            *(f32 *)(((u8 *)((Actor *)D_00189E20)->f2290) + 0x44) = *tbl;
            ((Actor *)D_00189E20)->fC34 += 1;
        }
        goto tail_default;

    /* 002E8460 */
    case 0x35:
        ((Actor *)D_00189E20)->f229C = 0x12;
        ((Actor *)D_00189E20)->f1188 = 0x68;
        ((Actor *)D_00189E20)->f22B7 = 1;
        ((Actor *)D_00189E20)->f798 = 0x2D;
        ((Actor *)D_00189E20)->f24A0 = 0;
        ((Actor *)D_00189E20)->fA3C = 0;
        if (s3 == 0)
            goto tail_default;
        func_L00_002D2168(0x5E, 0, 16.0f);
        goto tail_default;

    /* 002E84A0 */
    case 0x67:
        ((Actor *)D_00189E20)->f229C = 0x14;
        ((Actor *)D_00189E20)->f22B7 = 1;
        ((Actor *)D_00189E20)->f24A0 = 0;
        if (((Actor *)D_00189E20)->fA4E < 0x33) {
            if (*(u16 *)(D_0018C750 + 0x90) < 0xFFFF)
                *(u16 *)(D_0018C750 + 0x90) += 1;
        }
        if (D_001A7390 > *(s32 *)(D_0018C750 + 0x94))
            *(s32 *)(D_0018C750 + 0x94) = D_001A7390;
        *(s32 *)(D_0018C750 + 0x98) |= 1 << D_001A79F0;
        *(s32 *)(D_0018C750 + 0x98) |= 0x80000000;
        if (((Actor *)D_00189E20)->fA50 < 3) {
            if (*(u16 *)(D_0018C750 + 0x15C) < 0xFFFF)
                *(u16 *)(D_0018C750 + 0x15C) += 1;
        }
        if (D_001A7390 > *(s32 *)(D_0018C750 + 0x160))
            *(s32 *)(D_0018C750 + 0x160) = D_001A7390;
        *(s32 *)(D_0018C750 + 0x164) |= 1 << D_001A79F0;
        *(s32 *)(D_0018C750 + 0x164) |= 0x80000000;
        *(TI128 *)D_00189F80 = *(TI128 *)(D_00189F80 - 0x40);
        if (s3 == 0)
            goto tail_default;
        func_L00_002D2168(0x58, 0, 10.0f);
        goto tail_default;

    /* 002E85C0 */
    case 0x7f:
        ((Actor *)D_00189E20)->f229C = 0x14;
        ((Actor *)D_00189E20)->f22B7 = 1;
        ((Actor *)D_00189E20)->f24A0 = 0;
        *(TI128 *)&((Actor *)D_00189E20)->f160[0] = *(TI128 *)&((Actor *)D_00189E20)->f120;
        if (s3 == 0)
            goto tail_default;
        func_L00_002D2168(0x79, 0, 10.0f);
        goto tail_default;

    /* 002E8600 */
    case 0x85:
        ((Actor *)D_00189E20)->f229C = 0x20;
        ((Actor *)D_00189E20)->f24A0 = 8;
        ((Actor *)D_00189E20)->f22C2 = 1;
        if (s3 == 0)
            goto case_85;
        ((Actor *)D_00189E20)->f22B7 = 1;
        func_L00_002D2168(0x4F, 0, 5.0f);
    case_85:
        ((Actor *)D_00189E20)->f98 = *(f32 *)(((u8 *)((Actor *)D_00189E20)->f1830) + 0xF8);
        *(TI128 *)&((Actor *)D_00189E20)->f80 = *(TI128 *)(((u8 *)((Actor *)D_00189E20)->f1830) + 0x10);
        func_00282C88(&((Actor *)D_00189E20)->fF0[0]);
        goto tail_default;

    /* 002E8664 */
    case 0x01:
        ((Actor *)D_00189E20)->f24A0 = 4;
        if (((Actor *)D_00189E20)->f22BA != 0)
            goto tail_default;
        ((Actor *)D_00189E20)->f229C = 0;
        if (func_L04_002CC748(1) == *(u8 *)(((u8 *)((Actor *)D_00189E20)->f2290) + 0x43))
            goto tail_default;
        if (s3 == 0)
            goto tail_default;
        func_L00_002D2168(0x00, 0, 18.0f);
        goto tail_default;

    /* 002E86B0 */
    case 0x2f:
        ((Actor *)D_00189E20)->f229C = 8;
        ((Actor *)D_00189E20)->f24A0 = 0;
        *(TI128 *)&((Actor *)D_00189E20)->f160[0] = *(TI128 *)&((Actor *)D_00189E20)->f110[0];
        func_L00_002D2168(func_L04_002CC748(0), 0, 5.0f);
        ((Actor *)D_00189E20)->f1EC = 7;
        goto tail_default;

    /* 002E86F8 */
    case 0x02:
    case 0x2e:
    case 0x70:
        ((Actor *)D_00189E20)->f229C = 1;
        ((Actor *)D_00189E20)->f24A0 = 0;
        if (((Actor *)D_00189E20)->f22A4 == 4) {
        } else if (((Actor *)D_00189E20)->f22B0 == 4) {
        } else {
            ((Actor *)D_00189E20)->f1B4 =
                func_L00_002D3A58(&((Actor *)D_00189E20)->f120);
        }
        *(TI128 *)D_0018A210 = *(TI128 *)(D_0018A210 - 0x3F0);
        if (0.116666675f < ((Actor *)D_00189E20)->f1B4) {
            ((Actor *)D_00189E20)->f408 = ((Actor *)D_00189E20)->f98;
            ((Actor *)D_00189E20)->f1B4 = 0.116666675f;
        }
        ((Actor *)D_00189E20)->f410 = 0;
        func_L00_002B39F0(0, 1.0f);
        ((Actor *)D_00189E20)->f40F = 0;
        if (0.19634954f < func_00283C80(((Actor *)D_00189E20)->f98,
                                       ((Actor *)D_00189E20)->f1A0)) {
            if (((Actor *)D_00189E20)->f22A4 != 4 &&
                (((Actor *)D_00189E20)->f22A0 == 3 ||
                 ((Actor *)D_00189E20)->f22AC == 3))
                ((Actor *)D_00189E20)->f1B4 = 0.0f;
        }
        ((Actor *)D_00189E20)->f1188 = 0x68;
        if (((Actor *)D_00189E20)->f149A != 0) {
            if (((Actor *)D_00189E20)->f34C == 0)
                goto call_76;
            if (((Actor *)D_00189E20)->f31C < 0.3f)
                goto call_76;
        }
        if (((Actor *)D_00189E20)->f1492 != 0) {
            if (0.12833333f < ((Actor *)D_00189E20)->f1B4) {
                ((Actor *)D_00189E20)->f1B4 = 0.12833333f;
                func_002AC9F8(0.12833333f, &((Actor *)D_00189E20)->fF0[0]);
                *(s32 *)&*(f32 *)&((Actor *)D_00189E20)->fF0[8] = 0;
                ((Actor *)D_00189E20)->f2294 = 0x2E;
                ((Actor *)D_00189E20)->f404 = 0;
                func_L00_002D2168(0x37, 0, 8.0f);
                goto tail_default;
            }
            ((Actor *)D_00189E20)->f2298 = 0;
            ((Actor *)D_00189E20)->f2294 = 0x70;
            func_L00_002D2168(0x59, 0, 8.0f);
            goto tail_default;
        }
        ((Actor *)D_00189E20)->f40C = 0;
        ((Actor *)D_00189E20)->f40E = 0;
        if (s3 == 0)
            goto tail_default;
        {
            s32 a2 = 8;
            if (((Actor *)D_00189E20)->f24CC == 1)
                a2 = 0xC;
            if (((Actor *)D_00189E20)->f22AC == 0x22)
                a2 = 0xF;
            else if (((Actor *)D_00189E20)->f22A0 == 0x22)
                a2 = 0xF;
            if (((Actor *)D_00189E20)->f22AC == 0x83)
                a2 = 0xF;
            else if (((Actor *)D_00189E20)->f22A0 == 0x83)
                a2 = 0xF;
            if (((Actor *)D_00189E20)->f22A0 == 0x13)
                a2 = 0xD;
            if (((Actor *)D_00189E20)->f22AC == 6 ||
                ((Actor *)D_00189E20)->f22AC == 0x2C)
                a2 = 0x12;
            if (((Actor *)D_00189E20)->f22B0 == 4 &&
                ((Actor *)D_00189E20)->f49C < 6)
                a2 = 0xD;
            f12v = (f32)a2;
        }
        goto table_call;

    /* 002E8974 */
    case 0x7b:
        ((Actor *)D_00189E20)->f229C = 0x1C;
        ((Actor *)D_00189E20)->f24A0 = 0;
        *(TI128 *)&((Actor *)D_00189E20)->fF0[0] = *(TI128 *)&((Actor *)D_00189E20)->f110[0];
        if (((Actor *)D_00189E20)->f1298 == 0x36) {
            ((Actor *)D_00189E20)->f22CC = 0x36;
            ((Actor *)D_00189E20)->f2304 = 0;
        }
        if (s3 == 0)
            goto tail_default;
        func_L00_002D2168(0x8B, 0, -2.0f);
        goto tail_default;

    /* 002E89D0 */
    case 0x62:
        ((Actor *)D_00189E20)->f229C = 1;
        ((Actor *)D_00189E20)->f24A0 = 0;
        ((Actor *)D_00189E20)->f1B4 = func_00282E20(&((Actor *)D_00189E20)->f120);
        ((Actor *)D_00189E20)->f22BC = 1;
        if (((Actor *)D_00189E20)->f22B4 == 0)
            func_L00_002AF7D0();
        if (s3 == 0)
            goto tail_default;
        if (((Actor *)D_00189E20)->f22B4 == 1) {
            func_L00_002D2168(0x02, 0, 8.0f);
            goto tail_default;
        }
        if (((Actor *)D_00189E20)->f22B4 != 0)
            goto tail_default;
        f12v = 8.0f;
    table_call:
        func_L00_002D2168(((Actor *)D_00189E20)->f2298 + 3,
                          D_001A8DD8[((Actor *)D_00189E20)->f2298], f12v);
        goto tail_default;

    /* 002E8A58 */
    case 0x03:
        ((Actor *)D_00189E20)->f229C = 1;
        ((Actor *)D_00189E20)->f24A0 = 0;
        *(TI128 *)&((Actor *)D_00189E20)->f160[0] = *(TI128 *)&((Actor *)D_00189E20)->f120;
        if (((Actor *)D_00189E20)->f1492 != 0)
            goto call_2e;
        if (((Actor *)D_00189E20)->f149A != 0 &&
            ((Actor *)D_00189E20)->f34C == 0)
            goto call_76;
        if (func_L00_002CAF20(0, 0, 0, 0) != 0)
            goto ret0;
        if (func_L04_002CC748(0) == 0x51) {
            if (s3 == 0)
                goto tail_default;
            if (func_L04_002E7C08(0, 0) == 0)
                goto ret0;
            func_L00_002D2168(func_L04_002CC748(0), 0, 18.0f);
            goto ret0;
        }
        /* 002E8AFC: the else arm jumps into case 0x63's shared tail */
        if (s3 == 0)
            goto tail_default;
        v9 = 6;
        b9 = *(u8 *)(((u8 *)((Actor *)D_00189E20)->f2290) + 0x42);
        f9 = ((Actor *)D_00189E20)->fC38;
        goto shared_9f;

    /* 002E8B14 */
    case 0x63:
        ((Actor *)D_00189E20)->f229C = 1;
        ((Actor *)D_00189E20)->f24A0 = 0;
        ((Actor *)D_00189E20)->f1B4 =
            func_L00_002D3A58(&((Actor *)D_00189E20)->f120);
        *(TI128 *)&((Actor *)D_00189E20)->f160[0] = *(TI128 *)&((Actor *)D_00189E20)->f120;
        if (s3 == 0)
            goto tail_default;
        v9 = 6;
        b9 = *(u8 *)(((u8 *)((Actor *)D_00189E20)->f2290) + 0x42);
        f9 = ((Actor *)D_00189E20)->fC38;
    shared_9f:
        /* 002E8B50 */
        if (func_L00_002A4EF0(b9) == 4) {
            /* 002E8B64: 3.0f < f9 < 16.0f keeps 6, otherwise 5 */
            if (3.0f < f9 && !(f9 < 16.0f))
                v9 = 5;
        }
        func_L00_002D2168(v9, 4, 9.0f);
        goto tail_default;

    /* 002E8BB8 */
    case 0x04:
        ((Actor *)D_00189E20)->f229C = 0x0C;
        ((Actor *)D_00189E20)->f24A0 = 0;
        {
            f32 r = func_00282E20(&((Actor *)D_00189E20)->f120);
            ((Actor *)D_00189E20)->f1B4 = r;
            if (0.116666675f < r)
                ((Actor *)D_00189E20)->f1B4 = 0.116666675f;
        }
        if (((Actor *)D_00189E20)->f149A != 0) {
            if (((Actor *)D_00189E20)->f34C == 0)
                goto call_76;
        }
        ((Actor *)D_00189E20)->f1188 = 0x68;
        *(TI128 *)&((Actor *)D_00189E20)->f160[0] = *(TI128 *)&((Actor *)D_00189E20)->f120;
        func_002AC9F8(0.116666675f, &((Actor *)D_00189E20)->fF0[0]);
        if (0.058333336f < ((Actor *)D_00189E20)->f178)
            func_L00_002B9B88(9, 0);
        if (s3 == 0)
            goto tail_default;
        if (*(u8 *)(s5 + 0x42) == func_L04_002CC748(0))
            func_L00_002D2168(0x0D, 2, 9.0f);
        else
            func_L00_002D2168(0x03, 2, 14.0f);
        func_L00_002D2470(0x03, 0x12, 0);
        goto tail_default;

    /* 002E8CC4 */
    case 0x8a: {
        u8 *p360 = D_0018C360;
        ((Actor *)D_00189E20)->f229C = 0x21;
        ((Actor *)D_00189E20)->f24A0 = 0;
        if (*(u16 *)(p360 + 0x9C) < 0xFFFF)
            *(u16 *)(p360 + 0x9C) += 1;
        if (D_001A7390 > *(s32 *)(p360 + 0xA0))
            *(s32 *)(p360 + 0xA0) = D_001A7390;
        *(s32 *)(p360 + 0xA4) |= 1 << D_001A79F0;
        *(s32 *)(p360 + 0xA4) |= 0x80000000;
        ((Actor *)D_00189E20)->f1A0 =
            func_00283248(*(f32 *)(((u8 *)((Actor *)D_00189E20)->fB10) + 0x10) -
                          ((Actor *)D_00189E20)->f80,
                          *(f32 *)(((u8 *)((Actor *)D_00189E20)->fB10) + 0x14) -
                          ((Actor *)D_00189E20)->f84);
        ((Actor *)D_00189E20)->fB1C = 0;
        goto tail_8a23;
    }

    /* 002E8D5C */
    case 0x8b:
        ((Actor *)D_00189E20)->f229C = 0x21;
        ((Actor *)D_00189E20)->f22BC = 1;
        ((Actor *)D_00189E20)->f24A0 = 0;
        goto tail_default;

    /* 002E8D78 */
    case 0x23: {
        u8 *p360 = D_0018C360;
        ((Actor *)D_00189E20)->f229C = 0x0D;
        ((Actor *)D_00189E20)->f24A0 = 7;
        if (*(u16 *)(p360 + 0x9C) < 0xFFFF)
            *(u16 *)(p360 + 0x9C) += 1;
        if (D_001A7390 > *(s32 *)(p360 + 0xA0))
            *(s32 *)(p360 + 0xA0) = D_001A7390;
        *(s32 *)(p360 + 0xA4) |= 1 << D_001A79F0;
        *(s32 *)(p360 + 0xA4) |= 0x80000000;
        ((Actor *)D_00189E20)->f1A0 =
            func_00283248(*(f32 *)(((u8 *)((Actor *)D_00189E20)->fAA4) + 0x10) -
                          ((Actor *)D_00189E20)->f80,
                          *(f32 *)(((u8 *)((Actor *)D_00189E20)->fAA4) + 0x14) -
                          ((Actor *)D_00189E20)->f84);
        if (((Actor *)D_00189E20)->f22A0 == 0x28) {
            *(TI128 *)&((Actor *)D_00189E20)->f160[0] = *(TI128 *)&((Actor *)D_00189E20)->fF0[0];
        }
    tail_8a23:
        if (s3 == 0)
            goto tail_default;
        func_L00_002D2168(0x2F, 2, 5.0f);
        func_L00_002D2470(0x0A, 0x0E, 0);
        goto tail_default;
    }

    /* 002E8E54 */
    case 0x24:
        ((Actor *)D_00189E20)->f229C = 0x0D;
        ((Actor *)D_00189E20)->f24A0 = 7;
        ((Actor *)D_00189E20)->f22BC = 1;
        ((Actor *)D_00189E20)->fAA0 = 0;
        ((Actor *)D_00189E20)->fAB4 = 0;
        if (s3 == 0)
            goto tail_default;
        func_L00_002D2168(0x30, 1, 10.0f);
        goto tail_default;

    /* 002E8E8C */
    case 0x25:
        ((Actor *)D_00189E20)->f229C = 0x0D;
        ((Actor *)D_00189E20)->f24A0 = 7;
        ((Actor *)D_00189E20)->f22BC = 1;
        ((Actor *)D_00189E20)->fAA0 = 0;
        ((Actor *)D_00189E20)->fAB4 = 0;
        {
            f32 r = func_00282E48(&((Actor *)D_00189E20)->f80,
                                  (void *)(((u8 *)((Actor *)D_00189E20)->fAA4) + 0x10));
            ((Actor *)D_00189E20)->fABC = r;
        }
        if (s3 == 0)
            goto tail_default;
        func_L00_002D2168(0x30, 1, 5.0f);
        goto tail_default;

    /* 002E8ED8 */
    case 0x2b:
        ((Actor *)D_00189E20)->f229C = 0x0E;
        ((Actor *)D_00189E20)->f24A0 = 7;
        if (*(u16 *)(D_0018C360 + 0x9C) < 0xFFFF)
            *(u16 *)(D_0018C360 + 0x9C) += 1;
        if (D_001A7390 > *(s32 *)(D_0018C360 + 0xA0))
            *(s32 *)(D_0018C360 + 0xA0) = D_001A7390;
        *(s32 *)(D_0018C360 + 0xA4) |= 1 << D_001A79F0;
        *(s32 *)(D_0018C360 + 0xA4) |= 0x80000000;
        ((Actor *)D_00189E20)->fAFE = 1;
        ((Actor *)D_00189E20)->fAE8 = 0.0f;
        ((Actor *)D_00189E20)->f22BC = 1;
        ((Actor *)D_00189E20)->fAD4 = ((Actor *)D_00189E20)->fAD0;
        ((Actor *)D_00189E20)->fADC = 0;
        ((Actor *)D_00189E20)->fAFC = 0;
        ((Actor *)D_00189E20)->fAF4 = 0.0f;
        ((Actor *)D_00189E20)->fAF8 = 0.0f;
        {
            u8 *q = *(u8 **)(((u8 *)((Actor *)D_00189E20)->fAD0) + 0x68);
            ((Actor *)D_00189E20)->fAE0 = *(f32 *)(q + 0x4);
            if (*(f32 *)(q + 0x10) != ((Actor *)D_00189E20)->fAE8)
                *(f32 *)(q + 0x10) = *(f32 *)(q + 0xC);
            *(f32 *)(q + 0x14) = *(f32 *)(q + 0x10);
        }
        ((Actor *)D_00189E20)->fB08 = 0.3300000131f;
        ((Actor *)D_00189E20)->fB0C = 0.1833333373f;
        ((Actor *)D_00189E20)->fB04 = 0.0250000004f;
        func_00282C88(&((Actor *)D_00189E20)->fA0);
        ((Actor *)D_00189E20)->f206 = 0x28;
        {
            u8 *q = *(u8 **)(((u8 *)((Actor *)D_00189E20)->fAD0) + 0x68);
            if (*(f32 *)(q + 0x24) != 0.0f)
                ((Actor *)D_00189E20)->fB04 = *(f32 *)(q + 0x24);
            if (*(f32 *)(q + 0x28) != 0.0f)
                ((Actor *)D_00189E20)->fB08 = *(f32 *)(q + 0x28);
            if (*(f32 *)(q + 0x2C) != 0.0f)
                ((Actor *)D_00189E20)->fB0C = *(f32 *)(q + 0x2C);
        }
        {
            s32 v = ((Actor *)D_00189E20)->fAD4;
            func_00283248(*(f32 *)(v + 0x10) - ((Actor *)D_00189E20)->f80,
                          *(f32 *)(v + 0x14) - ((Actor *)D_00189E20)->f84);
            ((Actor *)D_00189E20)->fAEC = ((Actor *)D_00189E20)->f80;
            func_00282E48(&((Actor *)D_00189E20)->f80, (void *)(v + 0x10));
            ((Actor *)D_00189E20)->fAE4 = ((Actor *)D_00189E20)->f80;
            ((Actor *)D_00189E20)->fAF0 = 0.0075000003f;
            if (((Actor *)D_00189E20)->f22A4 == 4) {
                ((Actor *)D_00189E20)->fAF0 = ((Actor *)D_00189E20)->f520;
            } else if (((Actor *)D_00189E20)->f22A4 == 2) {
                ((Actor *)D_00189E20)->fAF0 = ((Actor *)D_00189E20)->fA80;
            }
        }
        if (s3 == 0)
            goto tail_default;
        func_L00_002D2168(0x34, 0, 12.0f);
        ((Actor *)D_00189E20)->fC20 = 0.7f;
        goto tail_default;

    /* 002E90BC */
    case 0x2c:
        ((Actor *)D_00189E20)->f24A0 = 7;
        ((Actor *)D_00189E20)->f229C = 2;
        func_00282C88(&((Actor *)D_00189E20)->fA0);
        *(TI128 *)&((Actor *)D_00189E20)->fF0[0] = *(TI128 *)&((Actor *)D_00189E20)->f120;
        if (s3 == 0)
            goto tail_default;
        func_L00_002D2168(0x0B, 0, 15.0f);
        goto tail_default;

    /* 002E9100 */
    case 0x17:
        ((Actor *)D_00189E20)->f229C = 3;
        ((Actor *)D_00189E20)->f24A0 = 0x0D;
        ((Actor *)D_00189E20)->f57C = 0.0061111115f;
        ((Actor *)D_00189E20)->f580 = ((Actor *)D_00189E20)->f88;
        if (((Actor *)D_00189E20)->f22A4 == 4) {
            ((Actor *)D_00189E20)->f57C = ((Actor *)D_00189E20)->f520;
            ((Actor *)D_00189E20)->f580 = ((Actor *)D_00189E20)->f490;
        }
        ((Actor *)D_00189E20)->f22BC = 1;
        if (s3 == 0)
            goto tail_default;
        ((Actor *)D_00189E20)->f22BF = 1;
        if (0.9f < ((Actor *)D_00189E20)->f174) {
            func_L00_002D2168(0x20, 0, 9.0f);
            goto tail_default;
        }
        func_L00_002D2168(0x00, 0, 9.0f);
        goto tail_default;

    /* 002E919C */
    case 0x18:
        ((Actor *)D_00189E20)->f229C = 3;
        ((Actor *)D_00189E20)->f1188 = 0x68;
        ((Actor *)D_00189E20)->f24A0 = 0x0D;
        ((Actor *)D_00189E20)->f22BC = 1;
        ((Actor *)D_00189E20)->f22BF = 1;
        if (s3 == 0)
            goto tail_default;
        func_L00_002D2168(0x21, 0, 6.0f);
        goto tail_default;

    /* 002E91D8 */
    case 0x19:
        ((Actor *)D_00189E20)->f229C = 3;
        ((Actor *)D_00189E20)->f24A0 = 0x0D;
        ((Actor *)D_00189E20)->f22BC = 1;
        ((Actor *)D_00189E20)->f22BF = 1;
        if (s3 == 0)
            goto tail_default;
        func_L00_002D2168(0x24, 0, 6.0f);
        goto tail_default;

    /* 002E920C */
    case 0x1a:
        ((Actor *)D_00189E20)->f229C = 3;
        ((Actor *)D_00189E20)->f24A0 = 0x0D;
        ((Actor *)D_00189E20)->f22BC = 1;
        ((Actor *)D_00189E20)->f22BF = 1;
        if (s3 == 0)
            goto tail_default;
        func_L00_002D2168(0x25, 0, 6.0f);
        goto tail_default;

    /* 002E9240 */
    case 0x76:
        ((Actor *)D_00189E20)->f229C = 2;
        ((Actor *)D_00189E20)->f24A0 = 0;
        *(TI128 *)&((Actor *)D_00189E20)->fF0[0] = *(TI128 *)&((Actor *)D_00189E20)->f120;
        if (s3 == 0)
            goto tail_default;
        func_L00_002D2168(0x0B, 0, 20.0f);
        goto tail_default;

    /* 002E9278 */
    case 0x06:
    case 0x74:
        ((Actor *)D_00189E20)->f229C = 2;
        ((Actor *)D_00189E20)->f24A0 = 0;
        if (((Actor *)D_00189E20)->f2294 == 0x74) {
            if (((Actor *)D_00189E20)->f22B4 == 1) {
                ((Actor *)D_00189E20)->f229C = 0x14;
                if (D_001A79F0 == 3)
                    func_L00_0035F5A0(0x11, 0);
                else if (D_001A79F0 == 0x0E)
                    func_L00_0035F5A0(0x15, 0);
            }
        }
        ((Actor *)D_00189E20)->fA80 = 0.0061111115f;
        ((Actor *)D_00189E20)->fA84 = 0.0019444445f;
        if (((Actor *)D_00189E20)->f2294 == 0x74) {
            if (((Actor *)D_00189E20)->f22B4 == 0) {
                func_L00_002B9B88(0x0E, 0x20);
                ((Actor *)D_00189E20)->f24D6 = 0;
            } else {
                ((Actor *)D_00189E20)->fA90 = func_002A78D8(0.052359886f, 0.072722062f);
                ((Actor *)D_00189E20)->fA94 = func_002A78D8(0.052359886f, 0.072722062f);
            }
        }
        ((Actor *)D_00189E20)->f1188 = 0x68;
        ((Actor *)D_00189E20)->f2298 = 0;
        *(TI128 *)&((Actor *)D_00189E20)->fF0[0] = *(TI128 *)&((Actor *)D_00189E20)->f120;
        if (s3 == 0)
            goto tail_default;
        if (0.5f < ((Actor *)D_00189E20)->f31C) {
            func_L00_002D2168(0x0B, 0, 20.0f);
            ((Actor *)D_00189E20)->f2298 = 1;
            goto tail_default;
        }
        func_L00_002D2168(0x0A, 0, 10.0f);
        goto tail_default;

    /* 002E93E0 */
    case 0x82:
        ((Actor *)D_00189E20)->f229C = 0x1E;
        ((Actor *)D_00189E20)->f24A0 = 0;
        if (((Actor *)D_00189E20)->f22A0 != 0x16) {
            if (((Actor *)D_00189E20)->f5B8 == 0.0f) {
                ((Actor *)D_00189E20)->f5B0 = 50.0f;
                ((Actor *)D_00189E20)->f5B8 = 0.0f;
                ((Actor *)D_00189E20)->f5B0 = ((Actor *)D_00189E20)->f5B8;
            }
        }
        ((Actor *)D_00189E20)->f24EF = 1;
        ((Actor *)D_00189E20)->f1188 = 0x68;
        ((Actor *)D_00189E20)->f7A8 = 0;
        ((Actor *)D_00189E20)->f5BE = 0;
        ((Actor *)D_00189E20)->f5A8 = 0;
        ((Actor *)D_00189E20)->f5A4 = 0;
        *(TI128 *)&((Actor *)D_00189E20)->fF0[0] = *(TI128 *)&((Actor *)D_00189E20)->f110[0];
        if (s3 == 0)
            goto tail_default;
        ((Actor *)D_00189E20)->f5BC = 7;
        func_L00_002D2168(0x13, 0, -2.0f);
        goto tail_default;

    /* 002E947C */
    case 0x08:
        ((Actor *)D_00189E20)->f229C = 5;
        ((Actor *)D_00189E20)->f1188 = 0x68;
        ((Actor *)D_00189E20)->f24A0 = 0;
        if (0.01875f < ((Actor *)D_00189E20)->f170) {
            func_L00_002B6118(0.01875f / ((Actor *)D_00189E20)->f170);
        }
        ((Actor *)D_00189E20)->f24C8 = 0;
        *(TI128 *)&((Actor *)D_00189E20)->fF0[0] = *(TI128 *)&((Actor *)D_00189E20)->f110[0];
        if (s3 == 0)
            goto tail_default;
        func_L00_002D2168(0x13, 0, -2.0f);
        goto tail_default;

    /* 002E94F0: 24 case values share this body - the actor kind table */
    case 0x07:
    case 0x09:
    case 0x0a:
    case 0x0b:
    case 0x0c:
    case 0x0d:
    case 0x0e:
    case 0x0f:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x1b:
    case 0x28:
    case 0x29:
    case 0x38:
    case 0x45:
    case 0x48:
    case 0x5b:
    case 0x66:
    case 0x6e:
    case 0x81:
    case 0x89:
    case 0x92:
        /* 002E94F0: the 0x81 test, then the 0x33C one */
        if (((Actor *)D_00189E20)->f2294 != 0x81) {
            if (((Actor *)D_00189E20)->f33C != 0) {
                if (*(s16 *)(((u8 *)((Actor *)D_00189E20)->f2294 + 0xAA)) == 0x9B9 ||
                    *(s16 *)(((u8 *)((Actor *)D_00189E20)->f2294 + 0xAA)) == 0xF05) {
                    func_L04_002E7C08(0x81, 1);
                    return 0;
                }
            }
        }
        /* 002E9534: the 0x6E test */
        if (((Actor *)D_00189E20)->f2294 != 0x6E) {
            if (((Actor *)D_00189E20)->f348 == 1) {
                if (s1 != 0x0E && s1 != 0x38 && D_L04_001A93F4 == 0) {
                    func_L04_002E7C08(0x6E, 1);
                    return 0;
                }
            }
        }
        /* 002E9568: the 0x24DB counter */
        if (((Actor *)D_00189E20)->f22A0 == 0x11 && ((Actor *)D_00189E20)->f24DA == 0)
            ((Actor *)D_00189E20)->f24DB = ((Actor *)D_00189E20)->f24DB + 1;
        else
            ((Actor *)D_00189E20)->f24DB = 0;
        /* 002E9598: the 0x1F2 and 0x212 tests */
        if (((Actor *)D_00189E20)->f1F2 != 0) {
            func_L04_002E7C08(0x82, 1);
            return 0;
        }
        if (((Actor *)D_00189E20)->f212 != 0) {
            ((Actor *)D_00189E20)->f2294 = ((Actor *)D_00189E20)->f22A0;
            ((Actor *)D_00189E20)->f1B8 = ((Actor *)D_00189E20)->f22A8;
            ((Actor *)D_00189E20)->f2298 = s2;
            return 0;
        }
        /* 002E95DC: the state and the flag */
        if (s1 - 0x28 < 2) {
            ((Actor *)D_00189E20)->f229C = 4;
            ((Actor *)D_00189E20)->f24A0 = 3;
        } else {
            ((Actor *)D_00189E20)->f24A0 = 0x50;
        }
        /* 002E9600: the two world calls */
        if (((Actor *)D_00189E20)->f2294 == 7 ||
            ((Actor *)D_00189E20)->f2294 == 0x0F ||
            ((Actor *)D_00189E20)->f2294 == 0x0D ||
            (((Actor *)D_00189E20)->f2294 == 0x0B &&
             ((Actor *)D_00189E20)->f22A4 != 4)) {
            func_L00_002A61C8(((Actor *)D_00189E20)->f149D, 0, 0, 0x1E);
            func_L00_002A61C8(((Actor *)D_00189E20)->f149D, 1, 0, 0x1E);
        }
        /* 002E9670: the record copy */
        *(TI128 *)D_00189F10 = *(TI128 *)(D_00189F10 + 0x30);
        /* 002E9684: the 0x12 / 0x1494 tests */
        if (((Actor *)D_00189E20)->f2294 != 0x12 &&
            ((Actor *)D_00189E20)->f1494 != 0) {
            if (((Actor *)D_00189E20)->f88 < ((Actor *)D_00189E20)->f330 + 0.5f)
                func_L00_002AABE0(3, 0x10, 0);
        }
        /* 002E96D4: the common float table */
        ((Actor *)D_00189E20)->f490 = ((Actor *)D_00189E20)->f88;
        ((Actor *)D_00189E20)->f520 = 0.00825f;
        ((Actor *)D_00189E20)->f448 = -1;
        ((Actor *)D_00189E20)->f500 = 0.0055555556f;
        ((Actor *)D_00189E20)->f510 = 2.5f;
        ((Actor *)D_00189E20)->f528 = ((Actor *)D_00189E20)->f1492;
        ((Actor *)D_00189E20)->f51A = 0x50;
        ((Actor *)D_00189E20)->f494 = 0.2501639f;
        ((Actor *)D_00189E20)->f4A0 = 0.8333334f;
        ((Actor *)D_00189E20)->f49E = 0;
        ((Actor *)D_00189E20)->f49C = 0;
        *(s32 *)&((Actor *)D_00189E20)->f4B0 = 0;
        ((Actor *)D_00189E20)->f4B4 = 0;
        ((Actor *)D_00189E20)->f49D = 0;
        ((Actor *)D_00189E20)->f504 = 0.0030555557f;
        ((Actor *)D_00189E20)->f524 = 0;
        ((Actor *)D_00189E20)->f52C = 0;
        ((Actor *)D_00189E20)->f52E = 0;
        ((Actor *)D_00189E20)->f52F = 0;
        ((Actor *)D_00189E20)->f52A = 0x46;
        ((Actor *)D_00189E20)->f526 = 0;
        ((Actor *)D_00189E20)->f514 = 0.5f;
        ((Actor *)D_00189E20)->f4A4 = 0.09916667f;
        ((Actor *)D_00189E20)->f458 = 0;
        ((Actor *)D_00189E20)->f49F = 0;
        ((Actor *)D_00189E20)->f594 = 0;
        ((Actor *)D_00189E20)->f24D8 = 0;
        /* 002E97B8: the case 7 body, before the chain */
        if (((Actor *)D_00189E20)->f2294 == 7) {
            ((Actor *)D_00189E20)->f4AC = 5;
            ((Actor *)D_00189E20)->f458 = 0.0096525f;
            ((Actor *)D_00189E20)->f4B8 = 0.6f;
            ((Actor *)D_00189E20)->f4C8 = 18.0f;
            ((Actor *)D_00189E20)->f4CC = 30.0f;
            ((Actor *)D_00189E20)->f4D0 = 12.0f;
            ((Actor *)D_00189E20)->f50C = 2.3f;
            ((Actor *)D_00189E20)->f508 = 1.28f;
            ((Actor *)D_00189E20)->f518 = 0x0F;
            ((Actor *)D_00189E20)->f52F = 1;
            ((Actor *)D_00189E20)->f4A8 = 1.28f;
            goto tail_52c;
        }
        /* 002E983C: the actor kind */
        if (((Actor *)D_00189E20)->f2294 == 0x81) {
            /* 002E9848 */
            ((Actor *)D_00189E20)->f4AC = 5;
            ((Actor *)D_00189E20)->f4B8 = 0.6f;
            ((Actor *)D_00189E20)->f4C8 = 18.0f;
            ((Actor *)D_00189E20)->f4CC = 30.0f;
            ((Actor *)D_00189E20)->f4D0 = 12.0f;
            ((Actor *)D_00189E20)->f50C = D_L04_001A7CD8 + 300.0f;
            ((Actor *)D_00189E20)->f508 = D_L04_001A7CD8;
            ((Actor *)D_00189E20)->f518 = 0x0F;
            ((Actor *)D_00189E20)->f51A = 0x190;
            ((Actor *)D_00189E20)->f510 = 300.0f;
            ((Actor *)D_00189E20)->f520 = D_L04_001A7CDC * 0.00027777778f;
            ((Actor *)D_00189E20)->f52A = 0x4B0;
            ((Actor *)D_00189E20)->f4A4 = 0.116666675f;
            ((Actor *)D_00189E20)->f4A8 = D_L04_001A7CD8;
            ((Actor *)D_00189E20)->f526 = 0x4B0;
            if (D_001A79F0 == 0x10)
                ((Actor *)D_00189E20)->f4A4 = 0.0f;
            /* 002E98FC: the three world calls */
            func_L00_00322A98((void *)((Actor *)D_00189E20)->f2290, &((Actor *)D_00189E20)->f18E0);
            func_L00_00322AC0(&((Actor *)D_00189E20)->f18E0, 0x46, 2, 0.0f);
            func_L00_00322AC0(&((Actor *)D_00189E20)->f18E0, 0x23, 4, 0.0f);
            func_L00_00322AC0(&((Actor *)D_00189E20)->f18E0, 0x11, 6, 0.0f);
            goto tail_ea36c;
        }
        if (((Actor *)D_00189E20)->f2294 == 0x12) {
            /* 002E995C: the eight stores below are BEFORE the branch, so
               they are common to both arms; the f4C8 store is the delay slot
               of the bc1f.  The "1.95" values belong to the f24C4 < 1.25
               arm and the call to the other one. */
            ((Actor *)D_00189E20)->f4AC = 2;
            ((Actor *)D_00189E20)->f4B8 = 0.6f;
            ((Actor *)D_00189E20)->f4CC = 28.0f;
            ((Actor *)D_00189E20)->f4D0 = 14.0f;
            ((Actor *)D_00189E20)->f50C = 0.2f;
            ((Actor *)D_00189E20)->f508 = 0.1f;
            ((Actor *)D_00189E20)->f518 = 0x0A;
            ((Actor *)D_00189E20)->f4A8 = 0.1f;
            ((Actor *)D_00189E20)->f4C8 = 18.0f;
            if (((Actor *)D_00189E20)->f24C4 < 1.25f) {
                /* 002E99D8 */
                ((Actor *)D_00189E20)->f4A8 = 1.95f;
                ((Actor *)D_00189E20)->f4AC = 0x0F;
                ((Actor *)D_00189E20)->f50C = 1.98f;
                ((Actor *)D_00189E20)->f508 = 1.95f;
            } else {
                /* 002E9A08 */
                func_L00_002D3B58(&((Actor *)D_00189E20)->fF0[0], &((Actor *)D_00189E20)->fF0[0],
                                  ((Actor *)D_00189E20)->f4B0);
                ((Actor *)D_00189E20)->f444 = D_L04_00276BB0;
                ((Actor *)D_00189E20)->f49D = 1;
                ((Actor *)D_00189E20)->f430 = 2;
                ((Actor *)D_00189E20)->f434 = 0x25;
                ((Actor *)D_00189E20)->f438 = ((Actor *)D_00189E20)->f4B0;
                ((Actor *)D_00189E20)->f43C = 18.0f;
                ((Actor *)D_00189E20)->f440 = 0x28;
            }
            /* 002E9A50 */
            ((Actor *)D_00189E20)->f22B7 = 1;
            ((Actor *)D_00189E20)->f49F = 1;
            goto tail_ea368;
        }
        if (((Actor *)D_00189E20)->f2294 == 9) {
            /* 002E9A6C */
            ((Actor *)D_00189E20)->f52F = 1;
            ((Actor *)D_00189E20)->f4AC = 5;
            ((Actor *)D_00189E20)->f4B8 = 0.6f;
            ((Actor *)D_00189E20)->f4C8 = 18.0f;
            ((Actor *)D_00189E20)->f4CC = 29.0f;
            ((Actor *)D_00189E20)->f4D0 = 11.0f;
            ((Actor *)D_00189E20)->f50C = 2.7f;
            ((Actor *)D_00189E20)->f508 = 1.0f;
            ((Actor *)D_00189E20)->f518 = 0x0F;
            ((Actor *)D_00189E20)->f4A4 = 0.116666675f;
            ((Actor *)D_00189E20)->f4A8 = 1.0f;
        tail_52c:
            ((Actor *)D_00189E20)->f52C = 1;
            ((Actor *)D_00189E20)->f52E = 1;
            goto tail_ea368;
        }
        if (((Actor *)D_00189E20)->f2294 == 0x6E) {
            /* 002E9AE8 */
            ((Actor *)D_00189E20)->f508 = 2.7f;
            ((Actor *)D_00189E20)->f4AC = 5;
            ((Actor *)D_00189E20)->f4B8 = 0.6f;
            ((Actor *)D_00189E20)->f4C8 = 18.0f;
            ((Actor *)D_00189E20)->f4CC = 30.0f;
            ((Actor *)D_00189E20)->f4D0 = 12.0f;
            ((Actor *)D_00189E20)->f50C = 2.0f;
            ((Actor *)D_00189E20)->f518 = 5;
            ((Actor *)D_00189E20)->f49F = 1;
            ((Actor *)D_00189E20)->f4A4 = 0.116025f;
            ((Actor *)D_00189E20)->f4A8 = 2.7f;
            ((Actor *)D_00189E20)->f52C = 1;
            ((Actor *)D_00189E20)->f52E = 0;
            ((Actor *)D_00189E20)->f52F = 0;
            goto tail_ea368;
        }
        if (((Actor *)D_00189E20)->f2294 == 0x0A) {
            /* 002E9B78 */
            ((Actor *)D_00189E20)->f526 = 0x4B0;
            ((Actor *)D_00189E20)->f4AC = 5;
            ((Actor *)D_00189E20)->f4B8 = 0.6f;
            ((Actor *)D_00189E20)->f4C8 = 18.0f;
            ((Actor *)D_00189E20)->f4CC = 29.0f;
            ((Actor *)D_00189E20)->f4D0 = 10.0f;
            ((Actor *)D_00189E20)->f50C = 1.95f;
            ((Actor *)D_00189E20)->f508 = 1.3f;
            ((Actor *)D_00189E20)->f518 = 0x0E;
            ((Actor *)D_00189E20)->f520 = D_L04_001A7CD8 + 300.0f;
            ((Actor *)D_00189E20)->f52E = 1;
            ((Actor *)D_00189E20)->f51A = 0x78;
            ((Actor *)D_00189E20)->f52A = 0x5A;
            ((Actor *)D_00189E20)->f4A8 = 1.3f;
            goto tail_ea368;
        }
        if (((Actor *)D_00189E20)->f2294 == 0x10) {
            /* 002E9C0C */
            ((Actor *)D_00189E20)->f4C8 = 18.0f;
            ((Actor *)D_00189E20)->f4CC = 30.0f;
            ((Actor *)D_00189E20)->f4D0 = 11.0f;
            ((Actor *)D_00189E20)->f50C = 1.55f;
            ((Actor *)D_00189E20)->f4AC = 5;
            ((Actor *)D_00189E20)->f4B8 = 0.8f;
            ((Actor *)D_00189E20)->f508 = 1.5f;
            ((Actor *)D_00189E20)->f4A8 = 1.5f;
            func_L00_002D6900(0x14);
            ((Actor *)D_00189E20)->f518 = 1;
            /* 002E9C80: the three stores are unconditional (the f4A8 one is
               the delay slot of the bc1f); the three world calls are in the
               f184 >= 1/3 arm. */
            ((Actor *)D_00189E20)->f508 = 0.4f;
            ((Actor *)D_00189E20)->f50C = 0.9f;
            ((Actor *)D_00189E20)->f4A8 = 0.4f;
            if (((Actor *)D_00189E20)->f184 >= 0.33333334f) {
                /* 002E9CBC */
                func_L00_00322A98((void *)((Actor *)D_00189E20)->f2290,
                                  &((Actor *)D_00189E20)->f18E0);
                func_L00_00322AC0(&((Actor *)D_00189E20)->f18E0, 0x28, 2, 0.0f);
                func_L00_00322AC0(&((Actor *)D_00189E20)->f18E0, 0x14, 4, 0.0f);
                func_L00_00322AC0(&((Actor *)D_00189E20)->f18E0, 0x0A, 6, 0.0f);
            }
            /* 002E9D0C */
            ((Actor *)D_00189E20)->f52E = 1;
            ((Actor *)D_00189E20)->f454 = 0.19166668f;
            if (0.095f < ((Actor *)D_00189E20)->f31C)
                ((Actor *)D_00189E20)->f454 = 0.095f;
            ((Actor *)D_00189E20)->f520 = 0.002361111f;
            ((Actor *)D_00189E20)->f504 = 0.013888889f;
            ((Actor *)D_00189E20)->f500 = 0.012222223f;
            goto tail_ea368;
        }
        if (((Actor *)D_00189E20)->f2294 == 0x1B) {
            /* 002E9D80 */
            ((Actor *)D_00189E20)->f52E = 1;
            ((Actor *)D_00189E20)->f4AC = 9;
            ((Actor *)D_00189E20)->f4B8 = 0.85f;
            ((Actor *)D_00189E20)->f4C8 = 20.0f;
            ((Actor *)D_00189E20)->f4CC = 29.0f;
            ((Actor *)D_00189E20)->f4D0 = 19.0f;
            ((Actor *)D_00189E20)->f50C = 2.05f;
            ((Actor *)D_00189E20)->f508 = 2.0f;
            ((Actor *)D_00189E20)->f514 = 1.0f;
            ((Actor *)D_00189E20)->f520 = 0.0069444445f;
            ((Actor *)D_00189E20)->f4A8 = 2.0f;
            ((Actor *)D_00189E20)->f518 = 1;
            ((Actor *)D_00189E20)->f4BC = 0;
            ((Actor *)D_00189E20)->f49F = 1;
            ((Actor *)D_00189E20)->f22BF = 1;
            ((Actor *)D_00189E20)->f22BC = 1;
            goto tail_ea368;
        }
        if (((Actor *)D_00189E20)->f2294 == 0x11) {
            /* 002E9E1C */
            ((Actor *)D_00189E20)->f4B8 = 0.6f;
            ((Actor *)D_00189E20)->f4C8 = 12.0f;
            ((Actor *)D_00189E20)->f4CC = 20.0f;
            ((Actor *)D_00189E20)->f4D0 = 10.0f;
            ((Actor *)D_00189E20)->f4AC = 9;
            ((Actor *)D_00189E20)->f518 = 0x0C;
            if (((Actor *)D_00189E20)->f24DA != 0) {
                ((Actor *)D_00189E20)->f498 = 0.08166667f;
                ((Actor *)D_00189E20)->f508 = 3.3f;
                ((Actor *)D_00189E20)->f50C = 3.35f;
            } else {
                ((Actor *)D_00189E20)->f498 = 0.028333336f;
                ((Actor *)D_00189E20)->f508 = 1.8f;
                ((Actor *)D_00189E20)->f50C = 1.85f;
            }
            /* 002E9EC0 */
            ((Actor *)D_00189E20)->f49F = 1;
            ((Actor *)D_00189E20)->f4A8 = ((Actor *)D_00189E20)->f508;
            func_L00_002D6900(0x1B);
            ((Actor *)D_00189E20)->f52A = 0x50;
            ((Actor *)D_00189E20)->f520 = 0.0080555556f;
            *(TI128 *)&((Actor *)D_00189E20)->f4F0 =
                *(TI128 *)&((Actor *)D_00189E20)->f4E0;
            ((Actor *)D_00189E20)->f52C = 1;
            ((Actor *)D_00189E20)->f24D8 = 1;
            ((Actor *)D_00189E20)->f22B7 = 1;
            goto tail_ea368;
        }
        if (((Actor *)D_00189E20)->f2294 == 0x0D) {
            /* 002E9F20 */
            ((Actor *)D_00189E20)->f4C8 = 26.0f;
            ((Actor *)D_00189E20)->f4CC = 38.0f;
            ((Actor *)D_00189E20)->f4D0 = 18.0f;
            ((Actor *)D_00189E20)->f50C = 4.07f;
            ((Actor *)D_00189E20)->f4AC = 9;
            ((Actor *)D_00189E20)->f4B8 = 0.6f;
            ((Actor *)D_00189E20)->f508 = 4.0f;
            ((Actor *)D_00189E20)->f518 = 0x0E;
            func_L00_002D6900(0x14);
            ((Actor *)D_00189E20)->f4A8 = 4.0f;
            /* 002E9F90: the four stores are unconditional (the f526 one is
               the delay slot of the bc1f); the two world calls are in the
               f184 < 1/3 arm. */
            ((Actor *)D_00189E20)->f510 = 4.5f;
            ((Actor *)D_00189E20)->f51A = 0x78;
            ((Actor *)D_00189E20)->f4A4 = 0.031666668f;
            ((Actor *)D_00189E20)->f526 = 0x25;
            if (((Actor *)D_00189E20)->f184 < 0.33333334f) {
                func_L00_00322A98((void *)((Actor *)D_00189E20)->f2290,
                                  &((Actor *)D_00189E20)->f18E0);
                func_L00_00322AC0(&((Actor *)D_00189E20)->f18E0, 0x28, 3, 0.0f);
                func_L00_00322AC0(&((Actor *)D_00189E20)->f18E0, 0x14, 5, 0.0f);
            }
            /* 002EA010 */
            ((Actor *)D_00189E20)->f52E = 1;
            goto tail_ea368;
        }
        if (((Actor *)D_00189E20)->f2294 == 0x0F) {
            /* 002EA01C */
            ((Actor *)D_00189E20)->f4AC = 9;
            ((Actor *)D_00189E20)->f4B8 = 0.6f;
            ((Actor *)D_00189E20)->f4C8 = 50.0f;
            ((Actor *)D_00189E20)->f4CC = 64.0f;
            ((Actor *)D_00189E20)->f4D0 = 28.0f;
            ((Actor *)D_00189E20)->f50C = 1.7f;
            ((Actor *)D_00189E20)->f508 = 1.65f;
            ((Actor *)D_00189E20)->f510 = 4.5f;
            ((Actor *)D_00189E20)->f518 = 5;
            ((Actor *)D_00189E20)->f51A = 0x82;
            ((Actor *)D_00189E20)->f4A4 = 0.055000004f;
            ((Actor *)D_00189E20)->f526 = 0x55;
            ((Actor *)D_00189E20)->f1D0 = 0x46;
            ((Actor *)D_00189E20)->f49D = 1;
            /* the f4A8 store is the delay slot of the beqz: unconditional */
            ((Actor *)D_00189E20)->f4A8 = 1.65f;
            /* 002EA0E0 */
            ((Actor *)D_00189E20)->f430 = (D_001A7B90 == 0) ? 0x23 : 0x22;
            ((Actor *)D_00189E20)->f52E = 1;
            ((Actor *)D_00189E20)->f434 = ((Actor *)D_00189E20)->f430 + 0x24;
            ((Actor *)D_00189E20)->f438 = 29.0f;
            ((Actor *)D_00189E20)->f43C = 50.0f;
            ((Actor *)D_00189E20)->f440 = 0x56;
            ((Actor *)D_00189E20)->f444 = D_L04_001A7E00;
            goto tail_ea368;
        }
        if (((Actor *)D_00189E20)->f2294 == 0x0E) {
            /* 002EA128 */
            {
                f32 f508v = 0.7f;
                if (((Actor *)D_00189E20)->f31C < 2.0f)
                    f508v = 2.5f - ((Actor *)D_00189E20)->f31C * 0.5f + 0.7f;
                ((Actor *)D_00189E20)->f526 = 0x1E;
                ((Actor *)D_00189E20)->f4AC = -1;
                ((Actor *)D_00189E20)->f4B8 = 0.6f;
                ((Actor *)D_00189E20)->f4C8 = 32.0f;
                ((Actor *)D_00189E20)->f4CC = 43.0f;
                ((Actor *)D_00189E20)->f4D0 = 19.0f;
                ((Actor *)D_00189E20)->f50C = f508v + 0.05f;
                ((Actor *)D_00189E20)->f508 = f508v;
                ((Actor *)D_00189E20)->f518 = 0x0E;
                ((Actor *)D_00189E20)->f514 = 1.0f;
                ((Actor *)D_00189E20)->f4A4 = 0.07916667f;
                ((Actor *)D_00189E20)->f4A8 = f508v;
            }
            goto tail_ea368;
        }
        /* 002EA1F8: the default of the actor kind */
        ((Actor *)D_00189E20)->f52A = 0x32;
        ((Actor *)D_00189E20)->f4AC = 5;
        ((Actor *)D_00189E20)->f4B8 = 0.6f;
        ((Actor *)D_00189E20)->f4C8 = 18.0f;
        ((Actor *)D_00189E20)->f4CC = 31.0f;
        ((Actor *)D_00189E20)->f4D0 = 24.0f;
        ((Actor *)D_00189E20)->f50C = 3.25f;
        ((Actor *)D_00189E20)->f508 = 3.2f;
        ((Actor *)D_00189E20)->f518 = 0x0A;
        ((Actor *)D_00189E20)->f510 = 4.5f;
        ((Actor *)D_00189E20)->f514 = 1.0f;
        ((Actor *)D_00189E20)->f49F = 1;
        ((Actor *)D_00189E20)->f4A8 = 3.2f;
        func_L00_002AE070(0x0A, 1);
        ((Actor *)D_00189E20)->f4C4 = 24.0f;
        *(TI128 *)&((Actor *)D_00189E20)->f480 =
            *(TI128 *)&((Actor *)D_00189E20)->f0;
        ((Actor *)D_00189E20)->f4D4 = func_L00_002C3A78();
        ((Actor *)D_00189E20)->f4C0 = ((Actor *)D_00189E20)->f1A0;
        *(TI128 *)&((Actor *)D_00189E20)->f470 =
            *(TI128 *)&((Actor *)D_00189E20)->f190;
        /* 002EA2C4 */
        if (0.4f < ((Actor *)D_00189E20)->f174)
            ((Actor *)D_00189E20)->f4D8 = ((Actor *)D_00189E20)->f174;
        else
            ((Actor *)D_00189E20)->f4D8 = 0.0f;
        /* 002EA2EC */
        *(s32 *)&((Actor *)D_00189E20)->f4DC = 0;
        if (((Actor *)D_00189E20)->f1454 != 0) {
            ((Actor *)D_00189E20)->f52C = 1;
            if (0.3f < ((Actor *)D_00189E20)->f24B8) {
                ((Actor *)D_00189E20)->f4C0 = ((Actor *)D_00189E20)->f1458;
                *(TI128 *)&((Actor *)D_00189E20)->f470 =
                    *(TI128 *)&((Actor *)D_00189E20)->f1440;
                ((Actor *)D_00189E20)->f52D = 1;
                ((Actor *)D_00189E20)->f4DC = 0.083333336f;
            } else {
                ((Actor *)D_00189E20)->f52D = 0;
            }
        }
        ((Actor *)D_00189E20)->f52E = 1;
        /* 002EA368 */
    tail_ea368:
        /* 002EA36C: the 0x510 scale */
        if (((Actor *)D_00189E20)->f510 == 0.0f)
            ((Actor *)D_00189E20)->f510 = ((Actor *)D_00189E20)->f4A8 * 2.0f;
        /* 002EA39C: the chain over the actor kind.  It is an if/else chain,
           not a switch: the tests are 7, 0x6E, 0x81, 0x12, 9, 0x0A, 0x10,
           0x1B, 0x89, 0x11, 0x0D, 0x0E, 0x0F, 0x0B, and each test's DELAY
           SLOT loads the NEXT case's value, so the body that follows a test
           is the one of the value that test compares against. */
        if (s3 == 0)
            goto tail_default;
        if (((Actor *)D_00189E20)->f2294 == 7) {
            func_L00_002D2168(0x07, 0, 5.0f);
            goto tail_default;
        }
        if (((Actor *)D_00189E20)->f2294 == 0x6E) {
            func_L00_002D2168(0x07, 0, 5.0f);
            goto tail_default;
        }
        if (((Actor *)D_00189E20)->f2294 == 0x81) {
            func_L00_002D2168(0x07, 0, 5.0f);
            goto tail_default;
        }
        if (((Actor *)D_00189E20)->f2294 == 0x12) {
            func_L00_002D2168(0x6B, 1, -1.0f);
            goto tail_default;
        }
        if (((Actor *)D_00189E20)->f2294 == 9) {
            s32 s = 8;
            s32 v = func_00283CF0(((Actor *)D_00189E20)->fC38);
            s32 t = func_L00_002A4EF0(*(u8 *)(((u8 *)((Actor *)D_00189E20)->f2290) + 0x42));
            if (t == 4)
                s = *(u8 *)(((u8 *)D_001A8DD8) + 8 + v);
            func_L00_002D2168(s, 0, 5.0f);
            goto tail_default;
        }
        if (((Actor *)D_00189E20)->f2294 == 0x0A) {
            func_L00_002D2168(0x12, 0, 5.0f);
            goto tail_default;
        }
        if (((Actor *)D_00189E20)->f2294 == 0x10) {
            if (((Actor *)D_00189E20)->f22A4 == 4 ||
                (((Actor *)D_00189E20)->f22A0 == 4 &&
                 ((Actor *)D_00189E20)->f1B8 < 7)) {
                func_L00_002D2168(0x26, 0, 8.0f);
                ((Actor *)D_00189E20)->f4AC = ((Actor *)D_00189E20)->f4AC + 3;
            } else {
                func_L00_002D2168(0x26, 0, 5.0f);
            }
            goto tail_default;
        }
        if (((Actor *)D_00189E20)->f2294 == 0x1B) {
            func_L00_002D2168(0x22, 0, 4.0f);
            goto tail_default;
        }
        if (((Actor *)D_00189E20)->f2294 == 0x89) {
            func_L00_002D2168(0x7D, 0x0B, 9.0f);
            goto tail_default;
        }
        if (((Actor *)D_00189E20)->f2294 == 0x11) {
            func_L00_002D2168(0x23, 2, 7.0f);
            goto tail_default;
        }
        if (((Actor *)D_00189E20)->f2294 == 0x0D) {
            func_L00_002D2168(0x11, 0, 5.0f);
            goto tail_default;
        }
        if (((Actor *)D_00189E20)->f2294 == 0x0E) {
            func_L00_002D2168(0x16, 3, 7.0f);
            ((Actor *)D_00189E20)->fC20 = 0.8f;
            goto tail_default;
        }
        if (((Actor *)D_00189E20)->f2294 == 0x0F) {
            func_L00_002D2168(0x15, 0, 5.0f);
            goto tail_default;
        }
        if (((Actor *)D_00189E20)->f2294 == 0x0B) {
            s32 x = ((Actor *)D_00189E20)->f4D4 + 0x1C;
            if (D_001A7A45 != 0) {
                if (x == 0x1C)
                    x = 0x1D;
                else if (x == 0x1D)
                    x = 0x1C;
            }
            if (((Actor *)D_00189E20)->f22A4 == 4) {
                func_L00_002D2168(x, 1, 4.0f);
                ((Actor *)D_00189E20)->f4AC = 1;
            } else {
                func_L00_002D2168(x, 0, 5.0f);
            }
            goto tail_default;
        }
    tail_ea36c:
        goto tail_default;

    /* 002EA604: 8 case values share this body - the second behaviour table */
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x1f:
    case 0x22:
    case 0x4d:
    case 0x83:
    case 0x93:
        {
            u8 *p750 = D_0018C750;
            u8 *p360 = D_0018C360;
            /* 002EA604: f229C = 6 is in the delay slot of the beqz, so it
               always runs; the f1500 test only guards the counter block. */
            ((Actor *)D_00189E20)->f229C = 6;
            if (((Actor *)D_00189E20)->f1500 != 0) {
                if ((unsigned)(((Actor *)D_00189E20)->f2294 - 0x13) < 3) {
                    /* 002EA628: the two counter blocks */
                    {
                        u16 c = *(u16 *)(p750 + 0x0C);
                        if (c < 0xFFFF)
                            *(u16 *)(p750 + 0x0C) = c + 1;
                    }
                    if ((u32)D_001A7390 > *(u32 *)(p750 + 0x10))
                        *(s32 *)(p750 + 0x10) = D_001A7390;
                    *(s32 *)(p750 + 0x14) |= 1 << D_001A79F0;
                    *(s32 *)(p750 + 0x14) |= 0x80000000;
                    {
                        u16 c = *(u16 *)(p360 + 0x2A0);
                        if (c < 0xFFFF)
                            *(u16 *)(p360 + 0x2A0) = c + 1;
                    }
                    if ((u32)D_001A7390 > *(u32 *)(p360 + 0x2A4))
                        *(s32 *)(p360 + 0x2A4) = D_001A7390;
                    *(s32 *)(p360 + 0x2A8) |= 1 << D_001A79F0;
                    *(s32 *)(p360 + 0x2A8) |= 0x80000000;
                    /* the argument is the 0x80000000 the flags word just got */
                    func_L00_002BA508(0x80000000);
                    /* 002EA6DC */
                    ((Actor *)D_00189E20)->f2294 = ((Actor *)D_00189E20)->f22A0;
                    ((Actor *)D_00189E20)->f229C = ((Actor *)D_00189E20)->f22A4;
                    goto tail_default;
                }
            }
            /* 002EA6F0 */
            if (s1 != 0x83)
                ((Actor *)D_00189E20)->f24A0 = 0;
            /* 002EA700 */
            ((Actor *)D_00189E20)->fBF4 = 1.0f;
            ((Actor *)D_00189E20)->fBE8 = 0;
            ((Actor *)D_00189E20)->fBE4 = 0;
            ((Actor *)D_00189E20)->fBFE = 0;
            switch (((Actor *)D_00189E20)->f2294) {
            case 0x14:
                /* 002EA780 */
                if (*(u16 *)(p750 + 0x00) < 0xFFFF)
                    *(u16 *)(p750 + 0x00) += 1;
                if (D_001A7390 > *(s32 *)(p750 + 0x04))
                    *(s32 *)(p750 + 0x04) = D_001A7390;
                *(s32 *)(p750 + 0x08) |= 1 << D_001A79F0;
                *(s32 *)(p750 + 0x08) |= 0x80000000;
                /* 002EA7FC */
                ((Actor *)D_00189E20)->f24A0 = 0x50;
                ((Actor *)D_00189E20)->fBFC = 4;
                ((Actor *)D_00189E20)->f2300 = 0;
                func_L00_002B75A0(8.0f, 1.0471977f, -1.0f);
                if (s3 == 0)
                    goto tail_default;
                ((Actor *)D_00189E20)->fC00 = 0;
                {
                    s32 v = 0x0B;
                    s32 r;
                    if (((Actor *)D_00189E20)->f22A0 == 0x0B &&
                        ((Actor *)D_00189E20)->f22A8 > 0x29)
                        v = 0x11;
                    func_L00_002D2168(0x2B, 4, (f32)v);
                    r = func_L00_002ADE68(0);
                    if (func_L00_002B3248(r) == 0)
                        goto tail_default;
                    func_002A7470(r, 0x0A, 4, v + 2);
                }
                goto tail_default;
            case 0x15:
                /* 002EA880 */
                if (*(u16 *)(p750 + 0x0C) < 0xFFFF)
                    *(u16 *)(p750 + 0x0C) += 1;
                if (D_001A7390 > *(s32 *)(p750 + 0x10))
                    *(s32 *)(p750 + 0x10) = D_001A7390;
                *(s32 *)(p750 + 0x14) |= 1 << D_001A79F0;
                *(s32 *)(p750 + 0x14) |= 0x80000000;
                if (*(u16 *)(p360 + 0x2A0) < 0xFFFF)
                    *(u16 *)(p360 + 0x2A0) += 1;
                if (D_001A7390 > *(s32 *)(p360 + 0x2A4))
                    *(s32 *)(p360 + 0x2A4) = D_001A7390;
                *(s32 *)(p360 + 0x2A8) |= 1 << D_001A79F0;
                *(s32 *)(p360 + 0x2A8) |= 0x80000000;
                /* 002EA950 */
                ((Actor *)D_00189E20)->fBFC = 3;
                func_L00_002B75A0(14.0f, 0.52359885f, -1.0f);
                ((Actor *)D_00189E20)->f2300 = 0;
                ((Actor *)D_00189E20)->fC0C = ((Actor *)D_00189E20)->fC0C < 1;
                if (s3 == 0)
                    goto tail_default;
                {
                    s32 v = 0x0A;
                    if ((*(u8 *)(((u8 *)((Actor *)D_00189E20)->f2290 + 0x43)) ^ 0x1A) == 0)
                        v = 3;
                    if ((((Actor *)D_00189E20)->f22A0 ^ 1) == 0)
                        v = 0x11;
                    func_L00_002D2168(0x1A, 0, (f32)v);
                }
                func_L00_002D2470(6, 0x15, 0);
                goto tail_default;
            case 0x83:
                /* 002EA9C0 */
                func_L00_0041E958(64.0f, 0.17453295f, 0.3490659f);
                ((Actor *)D_00189E20)->fBFC = 3;
                if (s3 == 0)
                    goto tail_default;
                {
                    s32 v = 0x0A;
                    if ((*(u8 *)(((u8 *)((Actor *)D_00189E20)->f2290 + 0x43)) ^ 0x1A) == 0)
                        v = 3;
                    if ((((Actor *)D_00189E20)->f22A0 ^ 1) == 0)
                        v = 0x11;
                    func_L00_002D2168(0x1A, 0, (f32)v);
                }
                goto tail_default;
            case 0x1f:
                /* 002EAA34 */
                if (((Actor *)D_00189E20)->f1220 == 0)
                    goto tail_default;
                func_L00_002D6900(0x13);
                if (s3 != 0) {
                    func_L00_002D2168(0x60, 4, -1.0f);
                    func_002A7470(((Actor *)D_00189E20)->f1220, 3, 4, -1);
                }
                func_L00_002B75A0(11.0f, 0.8726647f, -1.0f);
                goto tail_default;
            case 0x13:
                /* 002EAA9C */
                if (*(u16 *)(p360 + 0x78) < 0xFFFF)
                    *(u16 *)(p360 + 0x78) += 1;
                if (D_001A7390 > *(s32 *)(p360 + 0x7C))
                    *(s32 *)(p360 + 0x7C) = D_001A7390;
                *(s32 *)(p360 + 0x80) |= 1 << D_001A79F0;
                *(s32 *)(p360 + 0x80) |= 0x80000000;
                /* 002EAB00 */
                {
                    s32 v1;
                    s32 rem = 0;
                    s32 idx = *(s16 *)&((Actor *)D_00189E20)->fBFC * 0x2C;
                    u8 *tbl = D_L04_00276890 + idx;
                    ((Actor *)D_00189E20)->f2300 = 0;
                    /* the retail keeps f22A0 in the register the table value
                       would go to, so the "no case matched" path uses it */
                    v1 = ((Actor *)D_00189E20)->f22A0;
                    if (((Actor *)D_00189E20)->f22A0 ==
                            ((Actor *)D_00189E20)->f2294 &&
                        ((Actor *)D_00189E20)->fC38 < (f32)*(s32 *)(tbl + 0x8))
                        v1 = *(s32 *)(tbl + 0x4);
                    else if (((Actor *)D_00189E20)->f22AC ==
                                 ((Actor *)D_00189E20)->f2294 &&
                             ((Actor *)D_00189E20)->f1B8 +
                             ((Actor *)D_00189E20)->f22A8 < 0x1B)
                        v1 = *(s32 *)(tbl + 0x4);
                    rem = (v1 + 1) % 3;
                    /* 002EAB84 */
                    ((Actor *)D_00189E20)->fBFC = rem;
                    func_L00_002B75A0(5.0f, 0.78539824f, 0.78539824f);
                    if (s3 == 0)
                        goto tail_default;
                    {
                        s32 s3v;
                        s32 s1v;
                        if (rem == 0) {
                            s1v = 0;
                            s3v = 5;
                        } else if (rem == 1) {
                            s1v = 2;
                            s3v = 7;
                        } else {
                            s1v = 4;
                            s3v = 7;
                        }
                        /* 002EABD4 */
                        if (((Actor *)D_00189E20)->fBE8 != 0) {
                            if (rem < 2) {
                                f32 rr;
                                if (((Actor *)D_00189E20)->f22C3 != 0)
                                    rr = func_L00_002B9B38(&((Actor *)D_00189E20)->fBC0, 0);
                                else
                                    rr = func_00283C80(((Actor *)D_00189E20)->fBEC,
                                                      ((Actor *)D_00189E20)->f98);
                                s3v += func_00283CF0(rr * 1.5f);
                            }
                        }
                        /* 002EAC28 */
                        {
                            s32 carry = s1v >> 31;
                            s32 a1 = s1v + carry;
                            func_L00_002D2168(rem + 0x17, a1 >> 1, (f32)s3v);
                        }
                        {
                            s32 r = func_L00_002ADE68(0);
                            if (func_L00_002B3248(r) == 0)
                                goto tail_default;
                            func_002A7470(r, rem + 3, a1 >> 1, s3v);
                        }
                    }
                }
                goto tail_default;
            case 0x22:
                /* 002EAC80 */
                if (s3 != 0)
                    func_L00_002D2168(0x2C, 7, 9.0f);
                if (((Actor *)D_00189E20)->f1248 == 0x0C &&
                    ((Actor *)D_00189E20)->fBE0 != 0) {
                    ((Actor *)D_00189E20)->fBE8 = 1;
                    func_00283248(*(f32 *)(((u8 *)((Actor *)D_00189E20)->fBE0) + 0x10) -
                                  ((Actor *)D_00189E20)->f80,
                                  *(f32 *)(((u8 *)((Actor *)D_00189E20)->fBE0) + 0x14) -
                                  ((Actor *)D_00189E20)->f84);
                    ((Actor *)D_00189E20)->fBEC = ((Actor *)D_00189E20)->f84;
                    func_00282CF0(&((Actor *)D_00189E20)->fBC0,
                                  ((u8 *)((Actor *)D_00189E20)->fBE0 + 0x10),
                                  &((Actor *)D_00189E20)->f80);
                }
                goto tail_default;
            default:
                goto tail_default;
            }
        }

    /* 002EACF4 */
    case 0x77:
        ((Actor *)D_00189E20)->f229C = 0x0A;
        ((Actor *)D_00189E20)->f24A0 = 0;
        ((Actor *)D_00189E20)->fBF0 = func_00283B98(((Actor *)D_00189E20)->f98, 3.141593f);
        func_00282D30(&((Actor *)D_00189E20)->fBD0, (void *)((Actor *)D_00189E20));
        ((Actor *)D_00189E20)->f1B4 = 0.15f;
        if (s3 == 0)
            goto tail_default;
        func_L00_002D2168(0x29, 5, 8.0f);
        goto tail_default;

    /* 002EAD60 */
    case 0x16:
        ((Actor *)D_00189E20)->f229C = 7;
        ((Actor *)D_00189E20)->f24A0 = 0;
        func_L00_002B6118(0.5f);
        func_L00_002D6900(0x12);
        ((Actor *)D_00189E20)->f20E = 0x2D;
        *(TI128 *)&((Actor *)D_00189E20)->fF0[0] = *(TI128 *)&((Actor *)D_00189E20)->f120;
        func_002AC9F8(0.116666675f, &((Actor *)D_00189E20)->fF0[0]);
        {
            void *p = func_002A9640((void *)((Actor *)D_00189E20)->f2290, 1, 0);
            if (p == 0) {
                func_L00_002A4EF8(1);
            } else {
                func_00283CF0(*(f32 *)((u8 *)p + 0x2C));
                func_L00_002A4EF8((s32)p);
            }
        }
        ((Actor *)D_00189E20)->f1DC = 0x4D;
        if (s3 == 0)
            goto tail_default;
        func_L00_002D2168(0x10, 3, -3.0f);
        goto tail_8c;

    /* 002EAE0C */
    case 0x8c:
        ((Actor *)D_00189E20)->f229C = 7;
        ((Actor *)D_00189E20)->f24A0 = 0;
        func_L00_002B6118(0.5f);
        func_L00_002D6900(0x12);
        ((Actor *)D_00189E20)->f22BC = 1;
        {
            void *p = func_002A9640((void *)((Actor *)D_00189E20)->f2290, 8, 0);
            if (p == 0) {
                func_L00_002A4EF8(1);
            } else {
                func_00283CF0(*(f32 *)((u8 *)p + 0x2C));
                func_L00_002A4EF8(p);
            }
        }
        ((Actor *)D_00189E20)->f1DC = 0x4D;
        if (s3 == 0)
            goto tail_default;
        func_L00_002D2168(0x96, 1, -3.0f);
    tail_8c:
        {
            f32 *tbl = (f32 *)((u8 *)D_L04_00276A20 +
                               ((Actor *)D_00189E20)->fC30 * 100 +
                               ((Actor *)D_00189E20)->fC34 * 4);
            *(f32 *)(((u8 *)((Actor *)D_00189E20)->f2290) + 0x44) = *tbl;
            ((Actor *)D_00189E20)->fC34 += 1;
        }
        goto tail_default;

    /* 002EAED4 */
    case 0x3e:
        ((Actor *)D_00189E20)->f229C = 0x0F;
        ((Actor *)D_00189E20)->f24A0 = 0;
        if (((Actor *)D_00189E20)->f640 != 0)
            goto case_3e_b;
        if (((Actor *)D_00189E20)->f6C4 != 0) {
            func_00283CF0(*(f32 *)((u8 *)((Actor *)D_00189E20)->f6C4 + 0x2C));
            func_L00_002A4EF8(((Actor *)D_00189E20)->f6C4);
            ((Actor *)D_00189E20)->f6C4 = 0;
        } else {
            func_L00_002A4EF8(1);
        }
    case_3e_b:
        func_L00_002B9B88(0x14, 0);
        if (((Actor *)D_00189E20)->f24CC <= 0) {
            {
                f32 r = func_00283248(*(f32 *)&((Actor *)D_00189E20)->fF0[0],
                                      *(f32 *)&((Actor *)D_00189E20)->fF0[4]);
                f32 a;
                r = func_00283B98(r, 3.14f);
                a = func_002A78D8(0.53f, 0.61f);
                r = func_00283B98(a, r);
                a = func_00283180(r);
                {
                    f32 x = a * ((Actor *)D_00189E20)->f644 * 0.7f;
                    f32 y = func_00283198(x);
                    *(f32 *)&((Actor *)D_00189E20)->f120 = x;
                    *(f32 *)((u8 *)&((Actor *)D_00189E20)->f120 + 4) =
                        y * ((Actor *)D_00189E20)->f644 * 0.7f;
                    *(f32 *)((u8 *)&((Actor *)D_00189E20)->f120 + 8) = 0.05f;
                }
            }
            if (((Actor *)D_00189E20)->f640 < 0x10) {
                if (((Actor *)D_00189E20)->f24CC < 2)
                    ((Actor *)D_00189E20)->f24CC = 2;
            }
            *(u8 *)(((u8 *)((Actor *)D_00189E20)->f2290) + 0xA8) = 0xFF;
            func_L04_002E7C08(0x16, 1);
            ((Actor *)D_00189E20)->f1D0 = 0x46;
            ((Actor *)D_00189E20)->f1F4 = 0x96;
            goto ret0;
        }
        /* 002EB024 */
        ((Actor *)D_00189E20)->f1DC = 0x4D;
        if (0.083333336f < ((Actor *)D_00189E20)->f680) {
            ((Actor *)D_00189E20)->f69C = 0.083333336f;
            ((Actor *)D_00189E20)->f680 = 0.083333336f;
        }
        func_00282C88(&((Actor *)D_00189E20)->fF0[0]);
        ((Actor *)D_00189E20)->f674 = 0;
        func_00282C88(&((Actor *)D_00189E20)->f110[0]);
        if (s3 == 0)
            goto tail_default;
        *(f32 *)&((Actor *)D_00189E20)->fF0[8] = 0.18333334f;
        func_L00_002D2168(0x10, 2, -3.0f);
        goto tail_default;

    /* 002EB090 */
    case 0x1c:
        ((Actor *)D_00189E20)->f22BC = 1;
        ((Actor *)D_00189E20)->f229C = 9;
        ((Actor *)D_00189E20)->f24A0 = 0;
        func_L00_002D2168(func_L04_002CC748(0), 0, 10.0f);
        goto tail_default;

    /* 002EB0C0 */
    case 0x1d:
        ((Actor *)D_00189E20)->f24A0 = 0x51;
        ((Actor *)D_00189E20)->f229C = 0;
        func_L00_002A4EF0(*(u8 *)(s5 + 0x42));
        if ((s32)(void *)&D_00189E20 == func_L04_002CC748(0))
            goto tail_default;
        func_L00_002D2168(func_L04_002CC748(0), 0, 5.0f);
        goto tail_default;

    /* 002EB108 */
    case 0x1e:
        ((Actor *)D_00189E20)->f229C = 9;
        ((Actor *)D_00189E20)->f24A0 = 0;
        func_L00_002D2168(func_L04_002CC748(0), 0, 10.0f);
        goto tail_default;

    /* 002EB130 */
    case 0x6f:
        ((Actor *)D_00189E20)->f229C = 9;
        ((Actor *)D_00189E20)->f24A0 = 0;
        ((Actor *)D_00189E20)->f22BC = 1;
        func_L00_002AF7D0();
        if (s3 == 0)
            goto tail_default;
        func_L00_002D2168(func_L04_002CC748(0), 0, 10.0f);
        goto tail_default;

    /* 002EB16C */
    case 0x26:
        ((Actor *)D_00189E20)->f229C = 8;
        ((Actor *)D_00189E20)->f24A0 = 0;
        func_L00_002D2168(func_L04_002CC748(0), 0, 10.0f);
        goto tail_default;

    /* 002EB194 */
    case 0x31:
        ((Actor *)D_00189E20)->f229C = 9;
        ((Actor *)D_00189E20)->f24A0 = 0;
        ((Actor *)D_00189E20)->f22BC = 1;
        ((Actor *)D_00189E20)->f22B7 = 1;
        ((Actor *)D_00189E20)->f22BD = 1;
        func_L00_00322EC8(&((Actor *)D_00189E20)->f1A30);
        if (s3 == 0)
            goto tail_default;
        func_L00_002D2168(func_L04_002CC748(0), 0, -1.0f);
        goto tail_default;

    /* 002EB1DC */
    case 0x75:
        ((Actor *)D_00189E20)->f22BC = 1;
        ((Actor *)D_00189E20)->f229C = 9;
        ((Actor *)D_00189E20)->f24A0 = 0;
        ((Actor *)D_00189E20)->f22B7 = 1;
        func_00282C88(&((Actor *)D_00189E20)->fF0[0]);
        if (s3 == 0)
            goto tail_default;
        func_L00_002D2168(0x0B, 0, -1.0f);
        goto tail_default;

    /* 002EB220 */
    case 0x60:
    case 0x61:
        ((Actor *)D_00189E20)->f229C = 0x18;
        ((Actor *)D_00189E20)->f22BC = 1;
        func_L00_00322EC8(&((Actor *)D_00189E20)->f1A30);
        func_L00_002AF7D0();
        if (s3 == 0)
            goto tail_default;
        func_L00_002D2168(func_L04_002CC748(0), 0, -1.0f);
        goto tail_default;
    default:
        goto tail_default;
    }

call_2e:
    func_L04_002E7C08(0x2E, 1);
    goto ret0;
call_76:
    func_L04_002E7C08(0x76, 1);
    goto ret0;
tail_default:
    if (s6 != 0) {
        if (((Actor *)D_00189E20)->f22B7 == 0)
            ((Actor *)D_00189E20)->f231C = 1;
    }
    if (((Actor *)D_00189E20)->f348 == 0) {
        if (((Actor *)D_00189E20)->f1298 == 0x13) {
            if (((Actor *)D_00189E20)->f2304 != 0)
                ((Actor *)D_00189E20)->f2320 = 1;
        }
    }
    if ((unsigned)(((Actor *)D_00189E20)->f229C - 0x0D) < 3) {
        if (((Actor *)D_00189E20)->f2294 == 6 &&
            ((Actor *)D_00189E20)->f22A0 == 0x24) {
        } else if (((Actor *)D_00189E20)->f1298 == 0x14) {
            if (((Actor *)D_00189E20)->f2304 != 0)
                ((Actor *)D_00189E20)->f2320 = 1;
        }
    }
    if (((Actor *)D_00189E20)->f229C == 0x14) {
        func_L00_002AF7D0();
        ((Actor *)D_00189E20)->f22BC = 1;
    }
    if (func_L00_002ADF80(0) != 0 &&
        ((Actor *)D_00189E20)->f229C == 0x12) {
        if (((Actor *)D_00189E20)->f330 < *(f32 *)(D_L04_001B9540 + 0x148)) {
            /* the likely branch skips the store */
        } else {
            *(s32 *)(D_L04_001B9540 + 0x400) = 0;
            if (((Actor *)D_00189E20)->f229C == 0)
                *(s32 *)(D_L04_001B9540 + 0x400) = 0;
        }
    }
    if (((Actor *)D_00189E20)->f229C == ((Actor *)D_00189E20)->f22A4) {
        ((Actor *)D_00189E20)->f1B8 = 0;
    } else {
        func_L00_002A6708(0);
        ((Actor *)D_00189E20)->f1B8 = 0;
    }
    ((Actor *)D_00189E20)->f1C0 = 0;
    if (((Actor *)D_00189E20)->f229C != ((Actor *)D_00189E20)->f22A4)
        ((Actor *)D_00189E20)->f1BC = 0;
    ((Actor *)D_00189E20)->f1C4 = 0;
    return 1;
ret0:
    return 0;
}
INCLUDE_ASM("asm/levels", func_L04_002EDBC8);
