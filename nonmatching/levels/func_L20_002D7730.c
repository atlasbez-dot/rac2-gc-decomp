/* func_L20_002D7730 (level 20, yeedil) - A MAP, NOT AN ATTEMPT.

   Nothing was written for this body: at 19548 bytes (4887 instructions) it
   is far past what a single worker should sink a wave into, and the split
   64-bit address wall (see func_L20_002D6488.c in this directory, the note
   above the "wave 3" section) had to be understood first.  What follows is
   the map, so the next attempt starts from the structure and not from zero.

   THE SHAPE.  277 basic blocks, 238 calls to 62 distinct callees, and NOT
   ONE back edge: the body is a straight-line dispatch, not a loop.  It is
   the level's message handler: func_L20_002DC390 (in L20_002D6488.c) picks
   a variant of it and calls it with (0,1), (0x3F,1) or (0x8D,1), and the
   body itself calls itself four more times.

   THE ARGUMENTS.  $a0 = the message/state id, $a1 = the mode.  In the
   prologue: $s1 = the first argument, $s2 = the second.

   THE PROLOGUE (0x002D7730).
     - frame 0xA0; the GPR saves $s0-$s6 at 0x50,0x58,0x60,0x68,0x70,0x78,
       0x80, $ra at 0x88; $f21 at 0x98 and $f20 at 0x90; the locals at
       0x00-0x50.
     - lui $v0,%hi(D_189E20) ; daddu $s4,$v0,$zero ; addiu $v0,$v0,%lo(D_189E20)
       - the split form: $s4 keeps the %hi half and the plain address is
       re-made at every use ("addiu $s0,$s4,%lo(D_189E20)"), exactly the
       shape the note in func_L20_002D6488.c describes.

   THE ENTRY.
     1. 0x002D776C: the state D[0x229C]; if it is not 0x14, go to .L002D7794.
     2. 0x002D7774: when the state is 0x14, $a0 must be 0x61 and $a1 must be
        2, else the function returns 0 (.L002DC35C).
     3. .L002D7794 (0x002D7794): the mode word D_001A8F00.  If it is 2 then
        $a1 must be 2 (else return 0); if it is 6 the body falls through as
        well; any other value falls through to .L002D77BC.
     4. .L002D77BC (0x002D77BC): the flag D[0x24CC]; when it is set the id
        dispatch is skipped (.L002D7848).  Otherwise the state is read
        again: 2 and 7 lead into the id test, every other state goes on at
        .L002D784C with $t0 = 0.
     5. THE ID DISPATCH (0x002D77E0-0x002D7840), a chain of "beq $s1,$v0":
        0x6, 0x39, 0x43, 0x91, 0x5F, 0x74, 0x78, 0x79, 0x7C, 0x67 and 0x7D
        all reach .L002D7844, the common continuation (which sets $s0 to
        the address of D_00189E20); 0x7F and 0x61 return 0.
     6. A SECOND DISPATCH at 0x002D9380: the ids 0xE and 0x38 reach
        .L002D9398.

   THE JOIN POINTS (the labels many branches fall into).
     .L002DC15C  x67  the tail of most cases: "jal f_002E6090" (the sound
                        helper) with $a0 = the previous result, then
                        .L002DC20C.
     .L002DC20C  x38  the shared tail: when $s6 is 0 and D[0x22B7] is 0,
                        D[0x231C] = 1; then the tests on D[0x348],
                        D[0x1298] (0x13) and D[0x2304], which set
                        D[0x2320] = 1.
     .L002DA7DC  x16, .L002DBCF4 x7, .L002DB378 x5, .L002DBCBC x3.

   THE EXITS.
     .L002DC35C  x8   the "return 0" exit: "daddu $v0,$zero,$zero".
     0x002DC318-0x002DC354  the normal end: the counters D[0x1B8],
                        D[0x1C0], D[0x1BC] and D[0x1C4] are cleared and
                        the function returns 1 ("addiu $v0,$zero,0x1"),
                        then the epilogue at 0x002DC35C-0x002DC38C.

   THE CALLS (238 in all, 62 distinct).
     f_002E6090 x40  the sound/effect helper, the most called.
     f_002B7A48 x20, f_002B7B10 x10, f_002CCCD8 x9, f_00302920 x8,
     f_00337CF8 x8, f_003023C0 x7, f_00302228 x7, f_0032F2D0 x7,
     f_00335558 x7, f_003033C8 x7, f_002C9268 x7, f_002EA8A0 x6,
     f_002C2560 x5, f_002CA6F0 x5, f_002C6340 x5, f_00303358 x4,
     f_00303270 x4, f_002C0BF8 x4, f_002B7B08 x4, f_00338100 x3, ...
     f_002D7730 x4   the body is recursive: (0,0) at 0x002D86C8 (when $a1
                      is 0 and a helper returned 0x51), (0x39,1) at
                      0x002D99B0, (0x94,1) at 0x002DBCF4, (0x16,1) at
                      0x002DBF50.
     f_002DC390 x1   at 0x002D7950: the variant picker, which calls this
                      function back.

   THE DATA.  D_00189E20 (the state block, x23), D_18C750 and D_18C360
   (x12 each), D_00268F20 (x10), D_00268D90 (x8), D_001B3730/D_001B3738,
   D_00189F10, D_0018A210, D_001A8F00 (the mode word), D_00189F80,
   D_002690B0, D_001A9010, D_001A8F20, D_001B9E80.  The level's own data
   needs the D_L20_ names; the boot-resident data keeps the D_ names.

   THE $gp ACCESSES, so the body belongs in a -G8 unit
   (L20_002D7730-g8.c): -0x7C60($gp) = 0x001A7390 (x3), -0x5FFC($gp) =
   0x001A8FF4 (x1), 0x4748($gp) = 0x001B3738 (x1).  The symbols that are
   read both absolutely and through $gp need two names (sda and nosda).

   THE WALL FOR THE NEXT ATTEMPT.  The same split-address form as in
   func_L20_002D6488 (the %hi half in a callee-saved register, the address
   re-made at every use), so the same recipe applies: give every global the
   retail re-materialises a second C name.  Beyond that the body is 4887
   instructions of dispatch, and it wants its own -G8 unit; it is not a
   wave-3-sized job.
*/

   ------------------------------------------------------------------
   WAVE 5 (worker 14, 21 October 2026): THE MAP, PUSHED FURTHER
   ------------------------------------------------------------------

   Nothing was written for this body in wave 5 either: at 4887
   instructions it is not a one-worker job.  What the wave did is measure
   the map above against the retail byte for byte and fill in the parts
   that were missing: the jump table that carries the dispatch, the exact
   predecessor counts of the join points, the exits, the callees with
   their C names, and the registers.  Everything below was read out of
   build/20_yeedil/asm/5B0B0.s (the body is 0x002D7730-0x002DC38C) and
   build/20_yeedil/asm/data/BAC0.data.s (the table).

   THE COUNTS, measured:

     4887 instructions, 277 labels and so 278 basic blocks (the entry
     block plus the 277 labelled ones), NOT ONE back edge (the body is
     a straight-line dispatch), 238 calls to 62 distinct callees, one
     computed "jr $a0" and one "jr $ra" (the epilogue at 0x002DC384).

   THE DISPATCH IS A COMPUTED GOTO THROUGH THE LEVEL'S OWN TABLE.
   This is the big fact the wave-3 map was missing.  At 0x002D78E4:

       sltiu   $v0, $s1, 0x95        ; the id must be below 0x95
       beqz    $v0, .L002DC20C       ; else the shared tail
       lui     $v0, %hi(jtbl_002B2A40)
       sll     $v1, $s1, 2
       addiu   $v0, $v0, %lo(jtbl_002B2A40)
       addu    $v1, $v1, $v0
       lw      $a0, 0x0($v1)
       jr      $a0                   ; the case body

   The table lives in the level's own data at 0x002B2A40 and holds 152
   words: 149 of them are the ids 0x00-0x94 (the ones the guard lets
   through) and the last three (0x95-0x97) are zero padding.  The 149
   entries point at 81 DISTINCT case bodies; the other 68 ids share a
   body with another id.  The name that resolves is "jtbl_002B2A40" (it
   is in build/20_yeedil/config/undefined_syms_auto.txt and in
   undefined_symbols.ld); a "D_L20_" spelling of it does NOT resolve.
   From C it is

       extern void *jtbl_002B2A40[149];
       ...
       goto *jtbl_002B2A40[id];

   and the case bodies have to be kept alive with a
   "static void * volatile tab[] = { &&c0, &&c1, ... };" (no code; it
   lands in the discarded .data), exactly as the common file says for
   the other tables of this level.

   THE IDS AND THEIR BODIES (the id is the message id in $a0):

     0x002DC20C  35 ids  0x05 0x20 0x21 0x2D 0x3A 0x3B 0x3C 0x4C 0x4F-0x5A
                         0x5C-0x5F 0x68-0x6C 0x71 0x7E 0x80 0x84 0x87 0x88
                 (the shared tail itself)
     0x002D9324  23 ids  0x07 0x09-0x12 0x1B 0x28 0x29 0x38 0x45 0x48 0x5B
                         0x66 0x6E 0x81 0x89 0x92
                 (the "default" case; it re-dispatches on the id, see
                 below)
     0x002DAB6C   8 ids  0x13 0x14 0x15 0x1F 0x22 0x4D 0x83 0x93
     0x002D82A4   3 ids  0x02 0x2E 0x70
     0x002D9068   2 ids  0x06 0x74
     0x002DC1C4   2 ids  0x60 0x61
     0x002D7EE0   2 ids  0x72 0x73
     the other 67 bodies have one id each: 0x002D790C (0x00), 0x002D8210
     (0x01), 0x002D8658 (0x03), 0x002D87FC (0x04), 0x002D92B0 (0x08),
     0x002DB544 (0x16), 0x002D8EF0 (0x17), 0x002D8F8C (0x18),
     0x002D8FC8 (0x19), 0x002D8FFC (0x1A), 0x002DBFDC (0x1C),
     0x002DC00C (0x1D), 0x002DC054 (0x1E), 0x002D89BC (0x23),
     0x002D8A98 (0x24), 0x002D8AD0 (0x25), 0x002DC0B8 (0x26),
     0x002D8D44 (0x27), 0x002DB450 (0x2A), 0x002D8B1C (0x2B),
     0x002D8D00 (0x2C), 0x002D825C (0x2F), 0x002D8604 (0x30),
     0x002DC0E0 (0x31), 0x002D7BD4 (0x32), 0x002D7CD0 (0x33),
     0x002D7C4C (0x34), 0x002D7FD8 (0x35), 0x002D7D30 (0x36),
     0x002DC16C (0x37), 0x002D7AB8 (0x39), 0x002D7A78 (0x3D),
     0x002DBE20 (0x3E), 0x002DB7FC (0x3F), 0x002DB9D8 (0x40),
     0x002DB89C (0x41), 0x002DB940 (0x42), 0x002DBA58 (0x43),
     0x002DB8E4 (0x44), 0x002DBA94 (0x46), 0x002DBAFC (0x47),
     0x002DBB24 (0x49), 0x002DBB4C (0x4A), 0x002DB834 (0x4B),
     0x002DB908 (0x4E), 0x002D857C (0x62), 0x002D8768 (0x63),
     0x002D7A14 (0x64), 0x002DB6C8 (0x65), 0x002D8018 (0x67),
     0x002DB388 (0x6D), 0x002DC07C (0x6F), 0x002DC128 (0x75),
     0x002D9030 (0x76), 0x002DB4D8 (0x77), 0x002DB718 (0x78),
     0x002DB758 (0x79), 0x002DB7A0 (0x7A), 0x002D8520 (0x7B),
     0x002D7B40 (0x7C), 0x002D7AF0 (0x7D), 0x002D8138 (0x7F),
     0x002D9214 (0x82), 0x002D8178 (0x85), 0x002D81DC (0x86),
     0x002D8908 (0x8A), 0x002D89A0 (0x8B), 0x002DB618 (0x8C),
     0x002DBB74 (0x8D), 0x002DBCD4 (0x8E), 0x002DBBAC (0x8F),
     0x002DBC2C (0x90), 0x002DBD50 (0x91), 0x002DBBF4 (0x94).

   So there are THREE dispatches, not two:

     1. the entry tests (0x002D776C-0x002D77B4): the state D[0x229C]
        must not be 0x14 unless the id is 0x61 and the mode is 2; the
        mode word D_001A8F00 must not be 2 unless the mode is 2;
     2. a comparison chain at 0x002D77E0 (only reached when the state is
        2 or 7): the ids 0x6 0x39 0x43 0x91 0x5F 0x74 0x78 0x79 0x7C
        0x67 0x7D all fall into the common continuation .L002D7844, the
        id 0x7F returns 0, and everything else falls through to the jump
        table;
     3. the jump table itself at 0x002D78F0 (149 ids, 81 bodies).

   The case body 0x002D9324 (23 ids) DISPATCHES AGAIN: at 0x002D9380
   the ids 0x0E and 0x38 go to .L002D9398 and the rest go on to
   .L002D93C8.  The wave-3 map called this "a second dispatch"; it is
   really the body of one table case.

   THE JOIN POINTS, with the number of predecessors measured (the
   wave-3 map's counts were right for the first four):

     .L002DC15C  67 preds  the tail of most cases: "jal f_002E6090"
                           (the sound helper) with $a0 = the previous
                           result and $a1 = 0, then .L002DC20C
     .L002DC20C  38 preds  the shared tail (see below)
     .L002DA7DC  16 preds  "addiu $s0,$s4,%lo(D_189E20)" - the state
                           block is re-made here
     .L002DC35C   8 preds  the epilogue (the map above called it the
                           "return 0" exit; it is the function's end and
                           the return value is in $v0)
     .L002DBCF4   7 preds  "jal f_002D7730" with $a0 = 0x94, $a1 = 1 -
                           the recursive call, and the return value 0
     .L002DB378   5 preds  "jal f_002E6090" with $a1 = 1, then
                           .L002DC20C
     .L002DA7E0   3 preds  (the float block that follows .L002DA7DC)
     .L002DBCBC   3 preds  the float store "swc1 $f0,0x44($a2)" and the
                           branch to .L002DC20C
     .L002D7E40, .L002D8758, .L002D87EC, .L002D9EF8, .L002D9F00,
     .L002DA8C0, .L002DB534                          2 preds each

   THE SHARED TAIL .L002DC20C, in order:

       beqz   $s6, .L002DC228          ; $s6 = D[0x22B7]
       lbu    $v0, 0x22B7($v1)        ; the byte again
       bnez   $v0, .L002DC22C
       sw     $v0(=1), 0x231C($v1)    ; D[0x231C] = 1
     .L002DC228:
       lh     $v0, 0x348($a0)         ; D[0x348]
       lw     $v1, 0x1298($a0)        ; D[0x1298] (compared with 0x13)
       lw     $v0, 0x2304($a0)        ; D[0x2304]
       sw     $v0(=1), 0x2320($a0)    ; D[0x2320] = 1
     .L002DC25C:
       lw     $v0, 0x229C($a0)        ; the state
       addiu  $v0, $v0, -0xD ; sltiu $v0,$v0,3   ; the state in 13..15
       ...    the tests on D[0x2294], D[0x22A0], D[0x1298] and D[0x2304]
       jal    f_002C2560              ; when the state is 0x14
       jal    f_002C0D10
       ...    the float test against D_001B9E80[0x148] and D[0x330]
     .L002DC324:
       lw     $v1, 0x229C($s0) ; lw $v0, 0x22A4($s0)
       beql   $v1, $v0, .L002DC348
       sw     $zero, 0x1B8($s0)
       jal    f_002B9610
       ...
     .L002DC348:
       sw     $zero, 0x1C0($s0)
       sw     $zero, 0x1BC($s0)
     .L002DC354:
       sw     $zero, 0x1C4($s0)
       addiu  $v0, $zero, 0x1        ; the return value 1

   THE EXITS, measured.  There are TEN branches to the epilogue
   .L002DC35C; eight are unconditional, two are conditional and return 0:

     0x002D77B0  bne  $s2,$a0 -> the exit   (delay slot: $v0 = 0)
     0x002D783C  bne  $s1,$v0 -> the exit   (delay slot: $v0 = 0)
     0x002D7958  b    -> the exit           (delay slot: $v0 = 1)
     0x002D86F4  b    -> the exit           (delay slot: $v0 = 0)
     0x002D91A4  b    -> the exit           (delay slot: $v0 = 1)
     0x002D91C8  b    -> the exit           (delay slot: $v0 = 1)
     0x002D93F8  b    -> the exit           (the delay slot stores $s3)
     0x002D99B8  b    -> the exit           (delay slot: $v0 = 0)
     0x002DBCFC  b    -> the exit           (delay slot: $v0 = 0)
     0x002DBF68  b    -> the exit           (delay slot: $v0 = 0)

   The function returns 1 through the shared tail (the counters D[0x1B8],
   D[0x1C0], D[0x1BC] and D[0x1C4] are cleared at 0x002DC324-0x002DC358
   and $v0 is set to 1) and 0 through the ten branches above.

   THE REGISTERS (the map above had only $s1 and $s2):

     $s0  the state block D_00189E20, in the SPLIT form: the %hi half
          lives in $s4 and the address is re-made at every use
          ("addiu $s0,$s4,%lo(D_189E20)")
     $s1  the message id ($a0, moved in the prologue with
          "daddu $s1,$a0,$zero")
     $s2  the mode ($a1)
     $s3  D[0x2298]
     $s4  the %hi half of D_00189E20
     $s5  D[0x2290]
     $s6  D[0x22B7]
     $f20, $f21 are saved at 0x90 and 0x98; the frame is 0xA0 and the
     GPRs $s0-$s6 are at 0x50-0x80, $ra at 0x88.

   THE CALLEES, with the C names the catalogue gives them (the retail
   label is the LEVEL-20 address; the C name is the catalogue's):

     f_002E6090 x40  func_L00_002D2168   the sound/effect helper
     f_002B7A48 x20  func_L20_002B7A48
     f_002B7B10 x10  func_L00_002A4EF8
     f_002CCCD8 x9   func_L00_002B9B88
     f_00302920 x8   func_00283248      (boot)
     f_00337CF8 x8   func_L00_00322AC0
     f_002C9268 x7   func_L00_002B6118
     f_00302228 x7   func_00282C88      (boot)
     f_003023C0 x7   func_00282E20      (boot)
     f_003033C8 x7   func_00283CF0      (boot)
     f_0032F2D0 x7   func_002A7470      (boot)
     f_00335558 x7   func_002AC9F8      (boot)
     f_002EA8A0 x6   func_L00_002D6900
     f_002C2560 x5   func_L00_002AF7D0
     f_002C6340 x5   func_L00_002B3248
     f_002CA6F0 x5   func_L00_002B75A0
     f_002B7B08 x4   func_L00_002A4EF0
     f_002C0BF8 x4   func_L00_002ADE68
     f_002D7730 x4   func_L20_002D7730  the body itself
     f_00303270 x4   func_00283B98      (boot)
     f_00303358 x4   func_00283C80      (boot)
     f_002BDAE0 x3   func_L00_002AABE0
     f_002E6398 x3   func_L00_002D2470
     f_00302408 x3   func_00282E48      (boot)
     f_0032F778 x3   func_002A78D8      (boot)
     f_00331BB8 x3   func_002A9640      (boot)
     f_00337CD0 x3   func_L00_00322A98
     f_00338100 x3   func_L00_00322EC8
     f_002B8DE0 x2   func_L00_002A61C8
     f_002E7980 x2   func_L00_002D3A58
     f_00302290 x2   func_00282CF0      (boot)
     f_00375678 x2   func_L00_0035F5A0
     f_003926D0 x2   func_002FD1B8      (boot)
     and once each: f_002B9610 (func_L00_002A6708), f_002BE2E0
     (func_L00_002AB3E0), f_002C0D10 (func_L00_002ADF80), f_002C0E00
     (func_L00_002AE070), f_002C2168 (func_L00_002AF3D8), f_002C59C8
     (func_L00_002B2BD0), f_002C6B20 (func_L00_002B39F0), f_002CCC88
     (func_L00_002B9B38), f_002CD658 (func_L00_002BA508), f_002D6EC8
     (func_L00_002C3A78), f_002DC390 (func_L20_002DC390), f_002DE758
     (func_L00_002CAF20), f_002E7A80 (func_L00_002D3B58), f_002EA8E0
     (func_L00_002D6940), f_00301FE8 (func_00282A60), f_003021D0
     (func_00282C48), f_003022D0 (func_00282D30), f_00302350
     (func_00282DB0), f_00302390 (func_00282DF0), f_00302548
     (func_00282F20), f_00302858 (func_00283180), f_00302870
     (func_00283198), f_0032F6C0 (func_002A7820), f_00334408
     (func_002ABBB8), f_003578A0 (func_L00_00341820), f_00375480
     (func_002E5CF8), f_004364D8 (func_L18_004283F0), f_004367B8
     (func_L18_004286D0), f_00455AC8 (func_L00_0041E958).

   THE RECURSIVE CALLS, all four measured:

     0x002D86C8  f_002D7730(0, 0)     when $a1 is 0 and a helper
                                    returned 0x51
     0x002D99B0  f_002D7730(0x39, 1)
     0x002DBCF4  f_002D7730(0x94, 1)
     0x002DBF50  f_002D7730(0x16, 1)

   THE DATA, with the number of instructions that mention each symbol
   (one count per instruction):

     D_189E20 x23   the state block (the split form)
     D_18C750 x12   D_18C360 x12   (the two resident tables)
     D_00268F20 x10 D_00268D90 x8  (the level's own tables)
     D_001B3730 x4  D_00189F10 x4  D_0018A210 x3
     D_001A8F00 x2  D_001A8F20 x2  D_001A9010 x2  D_00189F80 x2
     D_002690B0 x2  D_001B3738 x2  D_001B9E80 x2
     jtbl_002B2A40 x2

   The level's own data needs the D_L20_ names; the boot-resident data
   (below 0x1A7C80) keeps the D_ names.  jtbl_002B2A40 is the exception:
   it is a level symbol with no D_ name, and the linker resolves it under
   that name.

   THE $gp ACCESSES - seven, three distinct symbols, so the body
   belongs in a -G8 unit (src/levels/20_yeedil/L20_002D7730-g8.c):

     0x002D7E0C  lw    $a1, 0x4748($gp)  = 0x001B3738
     0x002D938C  lw    $v0, -0x5FFC($gp) = 0x001A8FF4
     0x002D9688  lwc1  $f2, -0x7318($gp) = 0x001A7CD8
     0x002D9690  lwc1  $f1, -0x7314($gp) = 0x001A7CDC
     0x002DABA8  lw    $v1, -0x7C60($gp) = 0x001A7390
     0x002DAE24  lw    $v1, -0x7C60($gp) = 0x001A7390
     0x002DB044  lw    $v1, -0x7C60($gp) = 0x001A7390

   A symbol that is read both absolutely and through $gp needs two names
   (sda and nosda).

   THE WALL FOR THE NEXT ATTEMPT, corrected.  The wave-3 note said the
   split address needs "a second C name for the same global".  That is
   NOT the rule: a second name is merged by the CSE and changes nothing.
   The rule, measured on func_L20_002D6488 in this wave and confirmed by
   the matched witness src/levels/shared/L18_002C4000-g8.c, is a SECOND
   ASSIGNMENT of the same symbol in a place the CSE cannot merge it
   with the first one (after a nested block), with the global used more
   than once.  The %hi half then lives in a callee-saved register and
   the low half is re-made at every use.

   Beyond that the body is 4887 instructions of dispatch with 81 case
   bodies and a jump table that has to be reached from C; it is not a
   one-wave job and it wants its own -G8 unit.
