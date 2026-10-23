/* func_L11_0042F018 (10312 bytes, level 11 joba) -- NEAR MISS, not integrated.

   ELEVENTH PASS (worker 01): CASE 0's NESTING, THE "OTHER" PROBE'S SHARED
   (6,5) BLOCK, CASE 26's UNCONDITIONAL STORE, CASE 22's WIDE-ANGLE RECORD
   UPDATE, A SIGNED vi AND A SIX-ARGUMENT PROTOTYPE.

   check.py (11_joba), with the source below:

     11_joba: 10020 bytes, expected 10312
     func_L11_0042F018: 0 of 1 places match

   THE OBJECT IS 292 BYTES SHORT (the tenth pass's was 340).  The prologue
   and the %hi anchor now match the retail WORD FOR WORD, from 0042F018 to
   0042F070:

     0042F018  addiu      $sp, $sp, -0x110
     0042F01C  lui        $v1, %hi(D_1CAE40)
     ...
     0042F068  lui        $v0, %hi(D_189E20)
     0042F06C  addiu      $a0, $zero, 0x6F
     0042F070  daddu      $s1, $v0, $zero      <- the retail's register

   The first REAL difference (a %hi/%lo value, a branch offset and a call
   target normalised away) is now 0042F1F8, in case 0's tail:

     0042F1F8  ours   bnez $v0, . + 4 + (0x152 << 2)
             retail beqz $v0, . + 4 + (0x3 << 2)

   WHAT THIS PASS GOT RIGHT (all measured with tools/check.py)

   1. CASE 0's 0x29C TEST BELONGS INSIDE THE `if (func_002B3890(s3) != 0)`.
      The retail's block jumps over BOTH the func_002B60B0 block and the
      0x29C block (the branch-likely at 0042F108 targets .L0042F1B8, which
      is AFTER the 0x29C test); our source had the 0x29C test outside the
      `if`, so the branch-likely skipped only the func_002B60B0 block.
      Moving the test inside gives the retail's block, word for word:

        0042F100  jal func_002B3890
        0042F104  daddu $a0, $s3, $zero
        0042F108  beql $v0, $zero, .L0042F1B8
        0042F10C  lh $v1, 0x274($s4)      <- the delay slot loads 0x274
        ...
        0042F180  lw $v1, 0x29C($s4)
        0042F184  addiu $v0, $zero, -0x1  <- the -1 in a TEMP, not in $s0
        0042F188  beq $v1, $v0, .L0042F1B4
        0042F1B4  lh $v1, 0x274($s4)      <- the same load on the other path
        0042F1B8  addiu $v0, $zero, 0x2

      Note the two copies of `lh $v1, 0x274($s4)`: gcc put one in the
      branch-likely's delay slot (which runs only when the branch is TAKEN)
      and kept the other for the fall-through.

   2. THE "OTHER" PATH'S PROBE ENDS IN THE SHARED (6,5) BLOCK, NOT IN A
      COPY OF IT.  The retail's .L0042F288 (the 0x2AC probe) ends with
      `b .L0042F354` - the (6,5) block that case 0 and case 1 also use -
      and our source had a whole second copy of the (6,5) sequence
      (func_L11_0042EF90(6,5), func_002B60B0, func_002A7750(0x11,2), the
      store to s4+0x164).  The probe is also OUT OF LINE in the retail
      (`beqz $v0, .L0042F288` at 0042F228), so the source now has

        Lother:
            if (*(s16 *)(s4 + 0x276) == 0)
                goto Lprobe;
            func_002A7750(s3, 0xB, 1);
            ...
        Lprobe:
            idx = *(s32 *)(s4 + 0x2AC);
            ...
            goto L65;                 <- the shared (6,5) block

      This removed 11 instructions of duplicated code (the size went DOWN
      from 9976 to 9932) and made the probe's block the retail's.

   3. CASE 26 (AND CASE 15) STORE 0.00083333335f UNCONDITIONALLY.  The
      retail's store to s4+0x164 is in the DELAY SLOT of the `beqz` on
      0x27C (0043037C / 0043043C), so it runs on both paths: the source
      has to write the store BEFORE the test.

        00430374  mtc1 $at, $f0
        00430378  lw $v0, 0x27C($s4)
        0043037C  beqz $v0, .L004303D0
        00430380  swc1 $f0, 0x164($s4)    <- the delay slot: always stored

      The same shape is in case 15 (00430434..00430440).

   4. CASE 22's WIDE-ANGLE BRANCH (00430C70) DOES UPDATE THE RECORD.  Our
      source had the small-angle branch's record update but not the wide
      angle's; the retail has the same seven stores in both (00430DA0..
      00430DC4).  Adding them to the wide-angle branch gained 15
      instructions.

   5. `vi` MUST BE SIGNED.  The return of func_L00_002FCF18 is compared
      with `bltz $v1, .L00430DC8` in the retail (00430D80 and 00430C24);
      our `vi` was `u32`, so gcc deleted the branch as always false and
      the whole "the effect failed" path disappeared.  With `s32 vi;` the
      branch is back.

   6. func_L02_00331440 TAKES SIX ARGUMENTS.  Its prototype (in
      src/levels/shared/L02_002B5F50.c) is

          int func_L02_00331440(void *a0, void *a1, int a2,
                                float f12, float f13, float f14);

      Our declaration had five, so the retail's `mov.s $f14, $f13` (the
      sixth float argument, -1.0f) was missing.

   7. THE -1 CONSTANT IS MATERIALISED WITH `addiu $v0,$zero,-0x1` ONLY IF
      THE COMPARISON IS SIGNED.  The probe at 0042F28C is `addiu $v0,
      $zero, -0x1` in the retail; ours built 0xFFFFFFFF with lui/ori
      because `idx` was `u32` and the test was unsigned.

   THE COMPILER LEVERS THIS PASS FOUND

   - A BRANCH-LIKELY'S DELAY SLOT RUNS ONLY WHEN THE BRANCH IS TAKEN, so
     gcc may put a load there that is ALSO needed on the fall-through
     path; it then keeps a second copy for the other path.  That is how
     the retail has `lh $v1, 0x274($s4)` at both 0042F10C and 0042F1B4.
   - A STORE THAT THE RETAIL PUTS IN A BRANCH'S DELAY SLOT MUST BE
     WRITTEN BEFORE THE TEST IN THE SOURCE: the delay slot of a PLAIN
     branch always runs, so the store is unconditional.
   - A SIGNED LOCAL IS NEEDED FOR `bltz`: with an unsigned local gcc
     proves the test false and deletes the branch AND the block it
     guards.
   - THE FUNCTION'S REAL PROTOTYPE DECIDES THE FLOAT-ARGUMENT REGISTERS: a
     missing sixth argument removes a `mov.s $f14, $f13` and moves every
     later float argument.
   - "if (cond) goto Lelse;" LAYS THE BODY OUT AS THE FALL-THROUGH and
     puts the else block out of line.  The tenth pass found this for case
     1; this pass used it for the 0x276 probe (item 2).

   STILL OPEN (the next pass's list)

   - 292 bytes are still missing (10020 against 10312).  The gaps:
        0042F1F8..0042F230  the branch polarity and the layout of case 0's
                            (2,2) block: the retail has the call INLINE
                            at 0042F214 and a SEPARATE copy for case 1 at
                            0042F3C8, ours merges the two into one block
                            (gcc's cross-jumping).  Two identical calls in
                            two case bodies are NOT merged in the retail,
                            so the two source statements must differ in
                            some way that keeps gcc from merging them.
        0043024C..00430308  the tail of the d19/d26 blocks: the retail's
                            .L004301F4 builds a vector on the STACK
                            (sp+0x10, sp+0x20, sp+0x30, sp+0x60) and the
                            d26 case's buffer is at sp+0x0, ours uses
                            local arrays (vec, vec2, vec3, vec4, vec5).
                            The stack layout of the locals has to be
                            reproduced exactly.
        00430D78..00430DC4  the wide-angle branch's record update: now
                            present, but the retail computes the record's
                            address in $v1 and copies the 16 bytes with
                            `lq $v0,0($a1); sq $v0,0($a0)` (both
                            addresses in registers), ours uses
                            `lq $v1,0x230($s4); sq $v1,0x10($v0)`.
        0043141C..00431474, 0043158C..004315E4, 00431680..004316F0
                            case 22's SECOND window (9.0f..15.0f): the
                            retail keeps $s0 = s4+0x230, $s1 = s4+0x240,
                            $s2 = a copy of s4+0x240 and $s5 = a copy of
                            s4+0x230, and the vector for the three
                            func_002C2210 calls is on the stack at
                            sp+0x40 (copied from s4+0x240 with lq/sq, its
                            third float reduced by 0.1f).  The retail's
                            window A keeps $s0 = s4+0x240, $s1 = s4+0x230
                            and the same $s2/$s5.
        the D_L11_001A8F20 address: the retail re-materialises it at
                            every one of the ten func_002C2210 calls
                            (`lui $t1,%hi` + `addiu $t1`) because all six
                            callee-saved registers are taken ($s0, $s1,
                            $s2, $s5 for the four pointers, $s3 and $s4
                            for the object and its record).  Ours keeps it
                            in a register across the calls.
        the retail's SECOND copy of the %hi in case 15 ($s2 at 0042FD4C,
                            used at 0042FEA4): ours only has the address
                            of D_00189EA0, in $s0.  Writing the last
                            func_00282E80's argument as the SYMBOL
                            (D_00189EA0) instead of through the variable
                            reproduces the second %hi - but it costs the
                            %hi anchor of D_00189E20 its register ($s1 ->
                            $s2), because the extra value takes $s1.  The
                            eleventh pass kept the anchor in $s1 (the
                            retail's) and left the second %hi out.

   THE OTHER FUNCTIONS IN THE FILE still match after this pass:
     func_L11_0042A420: 1 of 1 places match
     func_L11_0042EF90: 1 of 1 places match
     func_L11_00431D50: 1 of 1 places match
     func_L11_00431E30: 1 of 1 places match

   --- the tenth pass and the ones before it follow ---

   TENTH PASS (worker 01): THE %hi OF D_00189E20 IS IN $s1, THE RETAIL'S
   REGISTER, AND FIVE TRANSCRIPTION DEFECTS ARE FIXED.

   check.py (11_joba), with the source below:

     11_joba: 9972 bytes, expected 10312
     func_L11_0042F018: 0 of 1 places match

   THE FIRST REAL DIFFERENCE IS STILL 0042F070's NEIGHBOURHOOD, BUT THE
   ANCHOR ITSELF IS NOW THE RETAIL'S:

     0042F068  lui   $v0, %hi(D_189E20)
     0042F06C  addiu $a0, $zero, 0x6F
     0042F070  daddu $s1, $v0, $zero      <- the retail's register (was $s2)

   The prologue is now the retail's, word for word, up to the branch at
   0042F060 (whose target only moves with the length of the body).

   WHAT THIS PASS GOT RIGHT (all measured with tools/check.py)

   1. THE %hi OF D_00189E20 IS IN $s1.  The ninth pass had it in $s2 and
      blamed the competition with the other callee-saved pseudos.  It was
      not the competition: it was FOUR EXTRA CALLS in case 15 and in case 1
      that made two more pseudos live across calls than the retail has.
      Removing them (items 2, 3 and 6 below) freed the register, and the
      anchor moved to $s1 by itself - no change to the anchor's live range
      or to its seven %lo references was needed.

      The lesson for the next pass: when an anchor's register is wrong,
      look for a PSEUDO THAT SHOULD NOT EXIST, not for a register that is
      taken.  A pseudo that the retail does not have takes a register and
      pushes the anchor one place down.

   2. CASE 15 (0x42FD40..0x42FEF4) HAD TWO CALLS THE RETAIL DOES NOT
      HAVE, AND TWO TESTS ON THE WRONG VALUE.

        - `func_L01_00321178(s3, D_00189EA0)' is NOT called in case 15.
          The retail calls f_0033E3F0 (func_L01_00321178) only at 0042FF48
          (case 19) and 00430130 (case 20).
        - the 20.0f test is on the RESULT of func_00282E80, not on
          func_00283C80(s3[0xF8]): the retail's `c.lt.s $f0,$f1' at
          0042FD84 compares what func_00282E80 returned (the call is at
          0042FD70).  The same holds for the 2.7f test at 0042FE20 and
          for the 2.1f test of case 19 at 0042FFAC.  The fifth pass had
          already noted that func_00282E80 returns a float; the source
          never used it.
        - the counter at s4+0x280 is incremented UNCONDITIONALLY: the
          retail's `sw $v0,0x280($s4)' is in the delay slot of the plain
          `beqz $v1', so the store runs on both paths.  The source now
          reads `*(s32 *)(s4+0x280) = *(s32 *)(s4+0x280) + 1;' before the
          test, and the block is the retail's, instruction for
          instruction, from 0042FD94 to 0042FDC4.
        - the "5 or 0xF" path of case 15 is only the func_L11_0042EF90
          call: the retail branches to the shared block at 0x4308C0
          (`b .L004308C0') and has no func_002B60B0 and no store of
          0.0069444445 there.  Both were ours.
        - the address of D_00189EA0 is a variable (`hp'), and the
          position is read through `(base - 0x80)' with the accesses at
          +0x80/+0x84, the retail's shape.

   3. CASE 1 (0x42F2CC..0x42F414) HAD AN INVERTED TEST AND A DUPLICATED
      TAIL.

        - the retail's .L0042F3DC is `bnel $v0,$zero,.L0042F868' with
          0x270 loaded in the delay slot: when s4[0x270] != 0 the case
          LEAVES the block.  Our source ran func_002A7750(1,0) and
          func_L11_0042EF90(5,4,0,0xC) when 0x270 != 0 - the opposite.
        - the tail after it (func_L11_0042EF90(1,1,0,0xA), the two
          func_002A7820(0x244,0x258), func_002A7750(0xB,0xC) and
          func_L11_0042EF90(4,3,0,0xC)) is the retail's .L0042F7FC, in
          CASE 3 - our case 1 had a copy of it.
        - the 0x274 test is unsigned: the retail has `sltiu $v0,$v0,0x2'
          at 0042F31C (and at 0042F4A0 in case 2), so the source needs
          `(u32)(hv - 1) < 2'.

   4. CASE 0's AND CASE 1's SHARED BLOCKS.  The retail has three blocks
      that both cases jump to, and the source had them inline:

        - .L0042F350: func_L11_0042EF90(s3, 6, 5, 0, 0xA), then
          func_002B60B0(0.016666667, 0.5, 0.001163553, 0.10471977), then
          func_002A7750(0x11, 2), then the store of 0.0055555557 to
          s4+0x164.  Case 0's "0x294 != -1" path jumps HERE (the retail's
          `bne $v1,$v0,.L0042F350' at 0042F1EC); our source jumped to
          the L720 block instead and lost the whole 6,5 block.
        - .L0042F3C0: func_L11_0042EF90(s3, 2, 2, 0, 0xA) and then the
          L720 block.
        - .L0042F720: func_002A7750(s3, 0xE, 2) - NOT 0xF.  The four
          callers set $a1 = 0xE in their delay slots (0042F204,
          0042F224, 0042F338, 0042F3D8).  Our source used 0xF and called
          the block twice on the 0x27C path.
        - the func_002B60B0 of the 6,5 block has f12 = 0.016666667
          (0x3C888889), not 0.06666667 (0x3D888889).

   5. CASE 19 (0x42FEF4..) HAD ITS CONSTANT AND ITS ORDER WRONG.

        - the 0.0069444445f that is stored to s4+0x164 is materialised
          BEFORE the func_002B60B0 call and stored in the call's delay
          slot (`swc1 $f0,0x164($s4)' at 0042FF38), so the source needs
          `f = 0.0069444445f;' first and the store after the call.
        - the argument of func_002A7E08 is read through the address
          variable (`lw $a1,0x2210($s0)' at 0042FF50), not through
          D_00189EA0 + 0x2210.
        - the counter is incremented between the two calls and stored in
          the delay slot of the func_00282E80 call (0042FF84..0042FF98).

   6. THE SHAPE OF A SHARED BLOCK IS SET BY THE ORDER OF THE SOURCE.
      The retail's case 1 ends with the "0x270 != 0" test in its own
      block (0x42F3DC), after the two shared blocks (0x42F350 and
      0x42F3C0).  Writing the source as

          if ((u32)(hv - 1) >= 2) goto Lc1other;
          ... the body ...
        L65:  ...
        L294: ...
        Lc1other: ...

      gives the retail's LAYOUT (the body falls through, the else block
      is out of line, and the two shared blocks sit between them).  With
      the plain `if ((u32)(hv - 1) < 2) { ... } else { ... }' gcc puts
      the ELSE block first and the body out of line - the opposite of
      the retail - and the block loses 23 matching instructions.  The
      same idiom gives the retail's `beql' + the delay slot.

      This is the lever to try on the other blocks whose layout is wrong.

   THE COMPILER LEVERS THIS PASS FOUND

   - A PSEUDO THE RETAIL DOES NOT HAVE COSTS A REGISTER.  Four extra
     calls in case 15 and case 1 meant four extra values live across
     calls, and the anchor's register moved down one place ($s1 -> $s2).
     Fixing the transcription moved the anchor back.  Count the calls,
     not the registers.
   - `if (cond) goto Lelse;' LAYS THE BODY OUT AS THE FALL-THROUGH and
     puts the else block out of line, which is what the retail does in
     case 1.  `if (cond) { body } else { other }' does the opposite.
   - A CONSTANT THAT IS STORED AND PASSED IS MATERIALISED BEFORE THE
     CALL and stored in the call's delay slot: `f = 0.0069444445f;' then
     the call then `*(f32 *)(s4+0x164) = f;'.
   - THE SIGN OF A COMPARISON AGAINST A HALFWORD IS THE SIGN OF THE
     EXPRESSION, NOT OF THE VARIABLE: `hv - 1 < 2' with a u16 hv is a
     signed comparison (`slti'); the retail's `sltiu' needs the cast
     `(u32)(hv - 1) < 2'.

   STILL OPEN (the next pass's list)

   - 340 bytes are still missing (9972 against 10312).  The transcription
     lost code that the retail has; the biggest gaps are
       0043024C..00430308  (48 instructions, the tail of case 20 and the
                            start of case 27)
       00430D78..00430DC4  (20 instructions, the record update of the
                            wide-angle branch of case 22 - the eighth
                            pass's item, still open)
       0043141C..00431474, 0043158C..004315E4, 00431680..004316F0
                            (the second window of case 22 and the blocks
                            after it)
       004308B0..00430904, 00430C1C..00430C48
                            (case 22's vectors)
   - The window's four callee-saved pointers.  The retail's window A
     keeps $s0 = s4+0x240, $s1 = s4+0x230, $s2 = a copy of s4+0x240 and
     $s5 = a copy of s4+0x230 (00430FA8, 00430FC0, 00430FCC, 00430FC8);
     ours keeps three and spends a callee-saved register on the
     %hi of D_L11_001A8F20 instead.
   - The D_L11_001A8F20 address: the retail re-materialises it at every
     one of the ten func_002C2210 calls (`lui $t1,%hi' + `addiu $t1'),
     ours keeps it in a register across the calls of a group (four
     %hi/%lo pairs instead of ten).
   - The retail's c2 block has `lw $v1,0x2AC($s4)' in the delay slot of
     the branch-likely AND a reload after the call; ours now has both
     (the c2 block matches), but the same shape is still missing in the
     other probe (the 0x2AC of the "other" path at 0042F288).
   - The func_002A8AF0 call of the "other" path takes its address from
     `D_L11_001FF580[idx]' with the shift by 4; the retail's c2 uses the
     same form, and ours matches there now.
   - The retail's case 15 and case 19 keep the address of D_00189EA0 in a
     callee-saved register ($s1 and $s0); ours keeps it in $s0 and in
     the same register as the anchor.  The retail's case 15 also copies
     the %hi into a second callee-saved register ($s2 at 0042FD4C) and
     rebuilds the address from it at 0042FEA4; ours does not.

   THE OTHER FUNCTIONS IN THE FILE still match after this pass:
     func_L11_0042A420: 1 of 1 places match
     func_L11_0042EF90: 1 of 1 places match
     func_L11_00431D50: 1 of 1 places match
     func_L11_00431E30: 1 of 1 places match

   --- the ninth pass and the ones before it follow ---

   NINTH PASS (worker 01): THE c2 BLOCK IS THE RETAIL'S, AND THE EFFECT
   BLOCK'S f20 IS THE CALL'S RESULT.

   check.py (11_joba), with the source below:

     11_joba: 10164 bytes, expected 10312
     func_L11_0042F018: 0 of 1 places match

   1792 of the retail's 2578 instructions now match (the call targets, the
   branch offsets and the %hi/%lo relocations normalised).  The eighth pass
   had 1688.

   THE FIRST REAL DIFFERENCE is still 0042F070, and it is still the
   register of the %hi of D_00189E20:

     0042F068  lui   $v0, %hi(D_189E20)
     0042F06C  addiu $a0, $zero, 0x6F
     0042F070  daddu $s5, $v0, $zero   |  daddu $s1, $v0, $zero

   (the %hi/%lo relocations print as 0 on our side, so 0042F01C, 0042F068
   and 0042F074 are not differences.)  The armed block's branch at
   0042F09C differs only in its offset (0x9BA against the retail's 0x9DF),
   i.e. the 148 bytes the body is still short.

   WHAT THIS PASS GOT RIGHT (all measured with tools/check.py)

   1. THE c2 BLOCK (0x42F414..0x42F5D8) WAS TRANSCRIBED WRONG IN SIX
      WAYS.  The retail's block is:

        0042F414  jal func_002B3890
        0042F41C  beql $v0,$zero,.L0042F460   (the delay slot loads 0x2AC)
        0042F460  addiu $s0,$zero,-0x1         (the -1 constant)
        0042F464  beq $v1,$s0,.L0042F498       (0x2AC == -1)
        0042F488  jal func_002A8AF0
        0042F490  bnel $v0,$zero,.L0042F868   (the probe: NON-ZERO leaves)
        0042F498  lhu $v0,0x274($s4) / sltiu  (0x274 - 1 < 2)
        0042F4A4  bnez $v0,.L0042F5D8         (delay: the D_00189E20 address)
        0042F4B4  beq $v1,$v0,.L0042F5D4      (0x11, 0x14, 0x10)
        0042F4CC  bnel $v1,$v0,.L0042F504     (0x13)
        0042F4E4  jal func_L11_0042EF90      (8, 0, 1, 3)
        0042F504  beql $v0,$s0,.L0042F548     (0x29C == -1; delay: the store)
        0042F510  bnel $v0,$s0,.L0042F548     (0x294 != -1; delay: the store)
        0042F518  the (5,4,0,0xC) / (5,1) block
        0042F540  b .L0042F5D8                (delay: the address)
        0042F548  the (3,1,0,0xC) / (0xB,1) block
        0042F5D4  addiu $v0,$s1,-0x61E0       (the address, its own block)
        0042F5D8  the f2294 == 0x31 test

      and the transcription had:
        - `if (idx == -1) goto Lsel2' (it must FALL THROUGH to the 0x274
          test) and the D_001A8AF0 probe INVERTED (the retail leaves the
          block when the probe is NON-zero, the transcription left it when
          the probe was zero);
        - a func_L11_0042EF90(s3, 6, 5, 0, 0xA) that the retail's c2 does
          not have at all;
        - the 0x11/0x14/0x10/0x13 test as ONE branch with a nested 0x29C
          test, instead of the retail's three branches to the f2294 block
          plus a separate 0x13 block;
        - the 0x29C/0x294 test as `a == -1 || b == -1', instead of the
          retail's `a == -1 || b != -1';
        - the 16-byte table copy read from D_L11_001A8F20, while the
          retail reads it from D_L11_001B368C through $gp
          (`lw $v1,0x469C($gp)' - 0x1AEFF0 + 0x469C = 0x1B368C);
        - the 0x274 test signed (`slti') instead of unsigned (`sltiu').

   2. THE FOUR MISSING USES OF D_00189E20 ARE IN, AND THE %hi's LIVE
      RANGE IS NOW THE RETAIL'S.  The object's relocations now show SEVEN
      %lo references to D_00189E20 (the prologue plus six), the same
      seven the retail has: 0042F1C4, 0042F4A8, 0042F500, 0042F544,
      0042F5D4, 0042F6E8 and 0042FCC0.  They are the ADDRESS
      MATERIALISATIONS in the delay slots of the branches that reach the
      f2294 test, and the last of them is the retail's own block
      .L0042F5D4.  (The %hi still lands in $s5 and not in $s1; see "still
      open" below.)

   3. THE EFFECT BLOCK'S f20 IS THE func_002A7878 RESULT, and the
      machine code is the authority: the call is at 00430E90 and the
      multiply `mul.s $f20,$f0,$f21' is at 00430E98, so $f0 is the
      RESULT of the call, not the z.  The seventh pass's item 9 (the
      result is discarded) was wrong.

      BUT THE MULTIPLY MUST BE A SEPARATE STATEMENT.  With

        f = func_002A7878(0.2f, 0.9f) * 0.2f;

      gcc's reload pass gives the call's result pseudo the stack slot of
      st0.z and the multiply then reads the reloaded z:

        00430EAC  swc1  $f0, 0x8($sp)
        00430EB0  lwc1  $f1, 0x8($sp)      <- the reload
        00430EBC  mul.s $f20, $f1, $f21    <- (z - 0.05f) * 0.2f

      With two statements

        f = func_002A7878(0.2f, 0.9f);
        f = f * 0.2f;

      the multiply uses the call's result, which is the retail's:

        00430EA8  jal   func_002A7878
        00430EAC   swc1 $f0, 0x8($sp)
        00430EB0  mul.s $f20, $f0, $f21
        00430EB4  addiu $a0, $zero, 0x2
        00430EB8  lwc1  $f0, 0x288($s4)
        00430EBC  jal   func_002A77E0
        00430EC0   mul.s $f20, $f20, $f0

      i.e. the effect block is now the retail's, instruction for
      instruction.

   4. A MULTI-DEF LOCAL KEEPS ITS REGISTER ACROSS EVERY CALL IN
      BETWEEN.  The D_L11_001FF580 entry was read into the shared
      variable `v', whose live range reaches from the c2 block to the
      L5d8 block, so gcc put it in $s2 (a callee-saved register) and the
      frame grew to 0x120 with EIGHT saved GPRs.  The retail keeps the
      pointer in $a1 (the argument register of func_002A8AF0) and reloads
      nothing.  Giving the value its own variable (pb in c2, pc in case
      0's Lother) gives the retail's shape AND brings the frame back to
      0x110 with six saved GPRs.  The same fix applies to the 0x2C4 and
      0x2BC values of the L5d8 block (pc and w8) and to the c3 block's
      func_002B1C20 result (w9): the retail keeps all of them in $v0/$v1.

   5. THE -1 CONSTANT IS ONE REGISTER ONLY IF ALL THREE COMPARISONS
      ARE SIGNED.  The retail keeps ONE -1 in $s0 for the 0x2AC, 0x29C
      and 0x294 tests.  With an unsigned comparison the literal -1
      becomes 0xFFFFFFFF, which gcc materialises with `lui' + `ori' (two
      instructions) and does NOT CSE with the signed -1 of the other two
      tests.  With the signed s32 variable the three tests share one
      pseudo and one `addiu $s0,$zero,-1'.  The same holds for the 0x2A4
      test, which the retail does with its own `addiu $v0,$zero,-1'.

   6. THE `||' OF TWO TESTS MUST BE WRITTEN AS TWO `if' BLOCKS.  With

        if (a == -1 || b != -1) { store; goto Lx; }

      gcc INVERTS the second test (it branches to the else part, and the
      store lands in the delay slot of a plain branch, so it also runs on
      the other path).  With two separate `if' blocks the retail's shape
      comes out exactly: a `beql' and a `bnel', both to the f2294 block's
      X block, both with the store in their delay slot, and the Y block
      between them.  (The branch-likely form comes from the RTL
      condition being NE: mostly_true_jump() returns 1 for NE and 0 for
      EQ, and a branch that is inverted to the NE form is printed as
      `beq' but still gets the NE prediction.)

   7. THE CASE-24 BLOCK'S BASE IS (D_00189EA0 - 0x61E0), NOT
      D_00189E20.  The retail computes it at run time as
      `addiu $s1,$s1,-0x61E0' from $s1 = D_00189EA0, and reads the
      position at 0x183D40/0x183D44.  The transcription read
      D_00189E20 + 0x80 (the hero's position) and, worse, kept the %hi
      of D_00189E20 alive into the case-22 block.

   THE COMPILER LEVERS THIS PASS FOUND

   - A CALL'S RESULT IN A COMPOUND EXPRESSION CAN BE GIVEN A STACK SLOT
     THAT BELONGS TO ANOTHER VARIABLE (the reload pass), and then the
     expression is computed from the reloaded value.  Splitting the
     expression into two statements keeps the result in the return
     register.  This is the same lever as the eighth pass's item 5, seen
     from the other side.
   - gcc's CSE merges the %hi of two symbols with the same high part
     (D_00189E20 and D_00189EA0 are both 0x19), so a block that uses
     D_00189EA0 keeps the %hi of D_00189E20 alive - unless the %hi's
     register is free by then, in which case gcc simply reuses it.
   - The branch-likely form needs the RTL condition to be NE; the
     printed `beq' can be the NE form (the inverted branch), so a `beql'
     in the retail does not mean the source used `!='.

   STILL OPEN (the next pass's list)

   - The %hi of D_00189E20 is in $s5 and not in $s1.  Its live range is
     now the retail's (the prologue to case 14 at 0042FCC0) and it has
     the retail's seven references, so the register is decided by the
     competition with the other callee-saved pseudos: $s0 is the -1
     constant, $s1 and $s2 are taken by the D_00189EA0 address and by
     other blocks' values.  The next pass has to free $s1 (the D_00189EA0
     address of the case-15 block is the obvious candidate: in the
     retail it gets $s1 only AFTER the %hi has died there).
   - 148 bytes are still missing (10164 against 10312).
   - The window's four callee-saved pointers.  The retail's window A
     keeps $s0 = s4+0x240, $s1 = s4+0x230, $s5 = a copy of s4+0x230 and
     $s2 = a copy of s4+0x240.  Writing four pointer variables costs
     TWO extra saved GPRs here ($s6 and $s7, the frame 0x120), because
     $s0/$s1/$s2 are taken by other pseudos; the pointers need the %hi
     of D_00189E20 to be dead before the window.
   - The wide-angle branch (00430C70..) still has no record update.
   - The D_L11_001A8F20 address: the retail re-materialises it at every
     one of the ten func_002C2210 calls (`lui $t1,%hi' + `addiu $t1'),
     ours keeps it in a register across the calls of a group (four
     %hi/%lo pairs instead of ten).
   - The func_002B3890 probe's `lw $v1,0x2AC($s4)' is in the retail's
     branch-likely's delay slot and is reloaded after the call; ours
     loads it after the call.

   THE OTHER FUNCTIONS IN THE FILE still match after this pass:
     func_L11_0042A420: 1 of 1 places match
     func_L11_0042EF90: 1 of 1 places match
     func_L11_00431D50: 1 of 1 places match
     func_L11_00431E30: 1 of 1 places match

   --- the eighth pass and the ones before it follow ---

   EIGHTH PASS (worker 01): THE PROLOGUE AND THE SAVE BLOCK MATCH, AND THE
   CASE-22 TAIL'S SHAPE IS THE RETAIL'S.

   check.py (11_joba), with the source below:

     11_joba: 10200 bytes, expected 10312
     func_L11_0042F018: 0 of 1 places match

   1686 of the retail's 2578 instructions now match (the call targets and
   the branch offsets normalised), 1352 of them textually.

   THE FIRST REAL DIFFERENCE is now 0042F070, and it is a register choice,
   not a shape:

     0042F068  lui   $v0, %hi(D_00189E20)
     0042F06C  addiu $a0, $zero, 0x6F
     0042F070  daddu $s5, $v0, $zero   |  daddu $s1, $v0, $zero

   the %hi of D_00189E20 lands in $s5 here and in $s1 in the retail.  (The
   two %hi/%lo relocations at 0042F01C and 0042F068 print as 0 on our side,
   so they are not differences.)  The armed block's branch at 0042F09C
   differs only in its offset (0x9C3 against the retail's 0x9DF, i.e. 28
   words = the 112 bytes the body is still short), so that one is fixed by
   the length alone.

   EVERYTHING BEFORE 0042F070 IS NOW THE RETAIL'S, WORD FOR WORD: the
   frame (0x110), the save block ($s0..$s5 and $ra at 0x90..0xC0, $f20..
   $f27 at 0xD0..0x108), the latch test, the arming block and the re-arm
   block.

   WHAT THIS PASS GOT RIGHT (all measured with tools/check.py)

   1. THE $s6 IS GONE.  The seventh pass's save block had SEVEN saved
      GPRs ($s0..$s6 and $ra) where the retail has six ($s0..$s5 and $ra):
      the extra one was the byte s4[0x35], which the transcription kept
      alive across the effect block's calls in a callee-saved register.
      The retail never keeps it across a call, and the fix is the same
      as item 2: the byte is loaded in the branch-likely's delay slot on
      one path and reloaded after the calls on the other.  With that, the
      save block is the retail's, word for word.

   2. THE beql AND THE BYTE'S PLACE.  The retail's

        00430DF8  beql  $v1, $v0, .L00430F6C
        00430DFC   lbu   $v0, 0x35($s4)

      needs the load INSIDE the branch's block, so the source is

        if (s3[0x42] == 0xA) {
            vb = s4[0x35];
            goto Lf6c;
        }

      and not a bare `if (s3[0x42] == 0xA) goto Lf6c;'.  With the load in
      the block, gcc moves it into the delay slot of the branch-likely
      (the branch is predicted likely, so the delay slot belongs to the
      target) and emits `beql'; with the load outside, the two loads are
      commoned and the branch stays a plain `beq' with a nop delay slot.
      The same source form also produces the retail's `bc1tl' with the
      `lw $v0,0x27C($s4)' in its delay slot.

   3. THE CONVERSION MUST BE OUTSIDE THE 3.0f TEST.  The retail converts
      the byte once, on both paths:

        00430F6C  c.le.s $f0, $f25
        00430F70  mtc1   $v0, $f27
        00430F74  nop
        00430F78  cvt.s.w $f27, $f27
        00430F7C  bc1f   .L00431260

      so the source is `f27 = (f32)vb;' BEFORE `if (3.0f <= f25) {'.  With
      the conversion inside the test, gcc sinks the load of the byte to
      the point of use (one load instead of the retail's two) and the
      conversion lands after the compare.

   4. THE EFFECT INDEX IS `idx--', NOT `idx = -1'.  The retail's

        00430EAC  daddu $s0, $v0, $zero
        00430EBC  addiu $v1, $s0, -0x1
        00430EC4  movn   $v1, $v0, $s0
        00430ECC  daddu $s0, $v1, $zero

      is what gcc emits for `if (idx == 0) idx--;' and NOT for
      `if (idx == 0) idx = -1;': with the literal -1 it materialises the
      constant 0xFFFFFFFF into a register of its own (a callee-saved one,
      in our build) and emits `movn $v1,$v0,$s0' with that constant;
      with `idx--' the "then" value is computed as idx-1 (which is -1 in
      that branch) and no constant is needed.  MEASURED on the compiler
      alone: `if (t == 0) t = -1;' gives `li $2,-1' + `movz $4,$2,$4',
      and `if (t == 0) t = t - 1;' gives `addu $16,$4,-1' + `movn $16,$4,$4',
      which is the retail's shape.  The same holds for the index of the
      five func_002C2210 calls of the window.

   5. A VALUE THAT IS THE CALL'S ARGUMENT DOES NOT LIVE ACROSS THE CALL.
      This is the lever that puts the retail's values in call-clobbered
      registers instead of callee-saved ones.  The retail's window:

        00430FAC  lui   $at, 0x3F80
        00430FB0  mtc1  $at, $f1
        00430FB4  lwc1  $f0, 0x298($s4)
        00430FC4  add.s $f0, $f0, $f1
        00430FD0  mov.s $f12, $f0
        00430FD4  jal   f_003007F8
        00430FD8   swc1  $f0, 0x298($s4)

      keeps the sum in $f0 (call-clobbered) and stores it in the delay
      slot.  With the source order `sum = ...; store; call(sum);' the sum
      is the call's ARGUMENT, so its live range ends at the call and it
      stays in $f0; with `sum = ...; call(sum); store;' the sum is used
      after the call, so it is live across it and gcc moves it to a
      callee-saved FPR ($f20 in our build).  The same rule explains the
      retail's use of $f0 after the func_002A7878 call in the effect
      block.

   6. THE func_00283248 OPERANDS IN THE 25.0f WINDOW.  The retail's

        0043099C  lwc1  $f0, 0x10($s3)
        004309A0  lwc1  $f1, 0x84($v0)
        004309A4  lwc1  $f12, 0x80($v0)
        004309A8  lwc1  $f13, 0x14($s3)
        004309AC  sub.s $f12, $f12, $f0
        004309B4   sub.s $f13, $f1, $f13

      is (HERO - OBJECT) in BOTH operands, the same shape as the effect
      branch's (other - object) at 00430B24.  The transcription had
      (object - hero) in both, and the record of the seventh pass (item
      5) claimed the opposite; the machine code is the authority and the
      source now reads (hero - object).

   THE COMPILER LEVERS THIS PASS FOUND

   - THE BRANCH-LIKELY FORMS COME FROM THE DELAY SLOT, NOT FROM A
     PREDICTION OF THE BRANCH ITSELF.  gcc 1.x has no "rematerialisation"
     and no branch-likely for a branch that is merely likely: the `l'
     suffix comes from INSN_ANNULLED_BRANCH_P, which reorg.c sets only in
     optimize_skip() (reorg.c:761) and in the delay-slot filling.  The
     practical rule that works here: when a conditional branch's block
     starts with a load and the branch is predicted likely, gcc moves the
     load into the delay slot and the branch becomes a branch-likely.
     The prediction itself comes from mostly_true_jump() (reorg.c:892),
     which returns 1 for a NE condition and 0 for an EQ one - so a
     `beq' is never predicted likely, but an INVERTED branch (the RTL
     `(if_then_else (ne a b) pc_rtx L)') is printed as `beq' by
     branch_zero (mips.md:8465) and still gets the NE prediction.  That
     is why the retail's `beql $v1,$v0' is possible at all.

   - A LOAD THAT IS USED ONLY ON ONE PATH IS DUPPLICATED, NOT COMMONED.
     Two `vb = s4[0x35];' in two different blocks become two loads (one
     in the beql's delay slot, one after the calls); the same two loads
     in the same block become one.

   WHAT IS STILL DIFFERENT (the next pass's list)

   - The %hi of D_00189E20 lands in $s5 here and in $s1 in the retail
     (0042F070).  The register is decided by the priority
     QTY_CMP_PRI = floor_log2(n_refs) * n_refs * size / (death - birth)
     (gcc/local-alloc.c): the %hi's priority rises with its number of
     references.  The retail uses D_00189E20 SEVEN times (the
     `addiu $v,$s1,-0x61E0' form at 0042F1C4, 0042F4A8, 0042F500,
     0042F544, 0042F5D4, 0042F6E8 and 0042FCC0) and the transcription
     only three times (the c0 and c4 blocks' f2294 test and the case-14
     block's f2290).  The four missing uses are in the c2 block
     (0042F4A8, 0042F500, 0042F544, 0042F5D4) and have to be
     transcribed from the retail: they are checks of
     D_00189E20+0x2294 that the transcription does not have at all.

   - The window's four callee-saved pointers.  The retail keeps
     $s0 = s4+0x240, $s1 = s4+0x230, $s2 = s4+0x240 and $s5 = s4+0x230
     (the last two are copies made by the CSE, `daddu $s5,$s1,$zero' and
     `daddu $s2,$s0,$zero'), and it REUSES the registers: $s0 becomes
     the effect index at 00431088, $s2 the D_001C0D20 address at
     00431030, $s5 the s4+0x230 copy, and $s1 the stack vector at
     0043108C.  The transcription keeps three of the four and needs a
     seventh saved GPR when the fourth is added, because
     D_L11_001A8F20's address is kept in a callee-saved register here
     while the retail re-materialises it at every one of the ten
     func_002C2210 calls (`lui $t1,%hi(D_001A8F20)' + `addiu').  That
     re-materialisation is what happens when the pseudo has no
     callee-saved register left, so the four pointers have to be in
     place first.

   - The effect block's f20: the retail computes (z - 0.05f) * 0.2f into
     $f20 from the value in $f0 (the z) and multiplies it by s4[0x288];
     the transcription reloads the z from the stack, because it uses the
     value after the func_002A7878 call instead of as its argument (the
     same lever as item 5).  The record of the seventh pass (item 9)
     says the func_002A7878 result is discarded; the machine code says
     the value in $f0 after the call is used, so the source is
     `f = func_002A7878(0.2f, 0.9f) * 0.2f;' and NOT
     `f = (st0.z - 0.05f) * 0.2f;'.  (Case 18's block at 00430694 does
     use the result: `mov.s $f22,$f0'.)

   - The wide-angle branch (00430C70..00430DC4) ends with the record
     update of the small-angle branch (the `bltz', the `lq'/`sq' and the
     seven stores at 00430D7C..00430DC4); the transcription's wide-angle
     branch has no record update at all.

   - 112 bytes are still missing (10200 against 10312).

   --- the seventh pass and the ones before it follow ---

   SEVENTH PASS (worker 01): BOTH TIMER WINDOWS ARE TRANSCRIBED.

   check.py (11_joba), with the source below:

     11_joba: 10188 bytes, expected 10312
     func_L11_0042F018: 0 of 1 places match

   The first difference is at 0042F09C, the armed block's branch to the
   epilogue: its offset depends on the length of the body, so it moves as
   long as the body is short.  The prologue (including the whole save
   block), the arming block and the re-arm block are now the retail's,
   word for word.

   WHAT THIS PASS GOT RIGHT

   1. THE ARMED BLOCK'S REGISTER.  The retail keeps the halfword in $v0
      and the constant 1 in $v1:

        0042F084  lhu   $v0,0x34($s3)
        0042F088  addiu $v1,$zero,0x1
        0042F08C  sb    $v1,0xBC($s3)
        0042F090  ori   $v0,$v0,0x41
        0042F094  sw    $zero,0x98($s3)
        0042F098  andi  $v0,$v0,0xEFFF
        0042F09C  b     .L0042F0A4
        0042F0A0  sh    $v0,0x34($s3)

      and the re-arm block keeps the same halfword in $v0.  The sixth
      pass used ONE variable for both blocks and got $a0.  The fix is
      TWO variables (h2 in the armed block, h3 in the re-arm block):
      gcc then gives each a register of its own and both land in $v0,
      because a value with a short live range is allocated first and
      $v0 is the lowest free register.  Measured: one variable -> $a0,
      two variables -> $v0 (the retail's) and the constant 1 -> $v1.

   2. THE RE-ARM BLOCK'S STATEMENT ORDER.  The retail loads the pointer
      before the and/or and clears s3[0xBC] after the value load:

        lhu $v0,0x34($s3) / sb $zero,0xBC($s3) / andi $v0,$v0,0xFFBE /
        lw $v1,0x24($s3) / ori $v0,$v0,0x1000 / sh $v0,0x34($s3) /
        lw $v0,0x10($v1) / sb $zero,0xBC($s3) / sw $v0,0x98($s3)

      so the source is

        h3 = *(u16 *)(s3 + 0x34);
        p2 = *(u32 *)(s3 + 0x24);
        h3 = (h3 & 0xFFBE) | 0x1000;
        *(u16 *)(s3 + 0x34) = h3;
        p3 = *(u32 *)(p2 + 0x10);
        s3[0xBC] = 0;
        *(u32 *)(s3 + 0x98) = p3;

      With the store of s3[0xBC] before the value load (the sixth pass's
      order) the instructions come out in a different order.

   3. THE CASE-22 BLOCK HAS TWO TIMER WINDOWS, AND THE TRANSCRIPTION
      HAD ONE WITH THE WRONG BODY.  The retail's case 22 (0x430908..
      0x4315EC) has

        0x430DC8  f25 = func_0029F530(s3)
        0x430DE8  if (f25 < 3.0f) goto the effect check (a branch-likely)
        0x430DF8  if (s3[0x42] == 0xA) goto 0x430F6C (a branch-likely)
        0x430E04  if (s4->0x27C == 0) goto 0x430F60
        0x430E08  the 0.2f/0.9f effect: func_0029FCC0, the products,
                  func_00282CC0, the z, func_002A7878(0.2f,0.9f), the
                  two func_002C2210 calls, s4->0x288 += 1.0f
        0x430F60  the 3.0f constant and the byte s4[0x35]
        0x430F6C  if (3.0f <= f25) {
        0x430F84    if (f25 < 9.0f) {          <- WINDOW A (0x430FA8)
        0x430F9C      if (s3[0x42] == 0xA) {
                      func_00282F20, func_002A8C00(f27), func_00282CC0,
                      func_002761F8, the D_L11_001C0D20 copy, FIVE
                      func_002C2210 calls, func_L00_002E6CF0, the record
                      update, and the jump BACK to the 9.0f test }
        0x431260  }
        0x431260  the loop head: if (9.0f <= f25) {
        0x43127C    if (f25 < 15.0f) {        <- WINDOW B (0x4312D4)
        0x43129C      if (s3[0x42] == 0xA) {
                      func_00282E80(s4+0x230,s4+0x240), the 1.6666667f
                      test, func_00282F20, func_002A8C00(f27),
                      func_00282CC0, func_002761F8, the D_L11_001C0D20
                      copy, an extra func_00282F20(sp+0x30, s4+0x250,
                      1.6666667f) and func_00282CC0(s4+0x230,s4+0x230,
                      sp+0x30), then THREE func_002C2210 calls,
                      func_L00_002E6CF0 and the record update }
        0x43154C  }
        0x43154C  the 15.0f test, and the release at 0x43156C.

      WINDOW A has FIVE func_002C2210 calls and WINDOW B has THREE; the
      sixth pass had WINDOW A's body under WINDOW B's test, so the block
      was both too short and in the wrong place.  Both windows are in the
      source below.

   4. THE HERO POSITION'S ADDRESS SHAPE.  The retail reads it as
      ($s1 - 0x80) + 0x80 and + 0x84, with $s1 = D_00189EA0:

        00430998  addiu $v0,$s1,-0x80
        004309A0  lwc1  $f1,0x84($v0)
        004309A4  lwc1  $f12,0x80($v0)

      That is not a constant address (gcc folds D+0x80 into one lui+load).
      It is a pointer variable holding (base - 0x80) with the accesses
      at +0x80/+0x84, and the source below writes it that way:

        q = (u8 *)s1 - 0x80;
        func_00283248(*(f32 *)(s3 + 0x10) - *(f32 *)(q + 0x80),
                      *(f32 *)(s3 + 0x14) - *(f32 *)(q + 0x84));

      which compiles to `l.s $f1,132($17)' + `l.s $f12,128($17)' with
      $17 = s1 - 0x80 - the retail's shape.  The same form with -0x61E0
      gives the other position (0x183D40/0x183D44), which is what the
      retail computes as `addiu $s0,$s1,-0x61E0'.

   5. THE func_00283248 OPERANDS ARE OBJECT - HERO, not hero - object.
      The retail's `sub.s $f12,$f12,$f1' with $f12 = the hero's x and
      $f1 = the object's x computes the object's x minus the hero's x.
      The transcription had it the other way round.

   6. D_L11_001A8F20 IS AN ARRAY, AND THE RETAIL PASSES ITS ADDRESS.
      The retail's fifth argument is `lui $t1,%hi(D_001A8F20) / addiu
      $t1,$t1,%lo(D_001A8F20)' - the address, not the value.  With
      `extern u32 D_L11_001A8F20;' the transcription passed the VALUE
      (a `lw' of the global) and kept it in a register across the five
      calls, which cost a callee-saved GPR.  With `extern u8
      D_L11_001A8F20[];' the address is a constant and is rematerialised
      at every call, as in the retail.

   7. func_002B38B8 TAKES ONE ARGUMENT AND RETURNS A VALUE.  The retail
      calls it as `jal f_0033C300' with only $a0 set and tests the
      result; the transcription's declaration had two arguments and no
      result.

   8. func_0029FCC0 IS ONE FUNCTION.  The transcription invented
      `func_0029FCC0_2' (a name no linker knows) and dropped a level of
      the chain: the retail reads (s4+0x27C) -> +0x68 -> +0x278, so the
      call is

        func_0029FCC0((u32)*(u8 **)(*(u32 *)(*(u32 *)(s4 + 0x27C) + 0x68)
                                   + 0x278), 0, &st0.x);

      (the src file already declares func_0029FCC0 as (u32, s32, f32 *),
      and the retail passes the pointer in $a0, so the cast is free).

   9. THE EFFECT BLOCK'S func_002A7878(0.2f,0.9f) RESULT IS DISCARDED.
      The retail's value is (z - 0.05f) * 0.2f * s4->0x288, computed
      from the vector's z, not from the call's result.  And the z is a
      FLOAT: the retail stores it with `swc1 $f0,0x8($sp)', so st0's
      third member is an f32, not an s32 (with an s32 the compiler emits
      a cvt.w.s and stores an int).

  10. THE EFFECT INDEX IS (v != 0) ? v : -1, not : 1.  The retail's
      `addiu $v1,$s0,-0x1' + `movn $v1,$v0,$s0' is the -1 form.

   THE COMPILER LEVERS THIS PASS FOUND (all measured)

   - THE BRANCH-LIKELY FORM OF THE 3.0f TEST.  The retail's
     `bc1tl .L00430E04' (the delay slot runs the effect check's load)
     comes from writing the test as

        if (f25 < 3.0f)
            goto Leffect;
        if (s3[0x42] == 0xA)
            goto Lf6c;
     Leffect:
        ...

     and not as `if (f25 >= 3.0f && s3[0x42] == 0xA) goto Lf6c;'.  The
     first form gives the retail's `c.lt.s $f25,$f0' + `bc1tl'; the
     second gives `c.le.s' + `bc1f'.

   - THE 3.0f CONSTANT MUST BE A LITERAL IN THE COMPARISON.  With a
     variable (f3 = 3.0f) gcc keeps the constant in a callee-saved FPR
     and materialises it BEFORE the call to func_0029F530; with the
     literal the constant stays in $f0 and is materialised after the
     call, as in the retail.

   - A LOAD BEFORE A BRANCH GOES INTO THE BRANCH'S DELAY SLOT.  The
     retail's `lbu $v0,0x35($s4)' is the delay slot of the `beql' that
     tests s3[0x42]; the source has to load the byte before that test.

   - __builtin_expect DOES NOT WORK ON MIPS IN THIS COMPILER: the
     expect_optab is empty (no `expect' pattern in config/mips/mips.md),
     so the branch-likely forms can only come from the prediction
     heuristics in reorg.c (mostly_true_jump).

   WHAT IS STILL DIFFERENT (the next pass's list)

   - The `beql' on s3[0x42] == 0xA: the retail predicts that branch as
     likely taken (so the delay slot can be annulled); ours is a plain
     `beq' with a nop in the delay slot.
   - The byte s4[0x35] is loaded in the retail's beql delay slot; ours
     loads it in the 0x430F60 block.
   - The 3.0f constant is materialised twice in the retail (0x430DD4 and
     0x430F60) and once in ours.
   - The window's pointers: the retail keeps four of them in callee-saved
     registers ($s0 = s4+0x240, $s1 = s4+0x230 then sp+0x30, $s2 =
     s4+0x240, $s5 = s4+0x230), so the source must have four pointer
     variables there; ours keeps three.
   - 124 bytes are still missing (10188 against 10312).

   THE OTHER FUNCTIONS IN THE FILE still match after this pass:
     func_L11_0042A420: 1 of 1 places match
     func_L11_0042EF90: 1 of 1 places match
     func_L11_00431D50: 1 of 1 places match
     func_L11_00431E30: 1 of 1 places match

   --- the sixth pass and the ones before it follow ---

   SIXTH PASS (worker 01): THE SAVE BLOCK MATCHES -- GPRs AND FPRs.

   check.py (11_joba), with the source below:

     11_joba: 9468 bytes, expected 10312
     func_L11_0042F018: 0 of 1 places match
     97 of 2578 instructions match (the whole prologue and the first case).

   The prologue is now the retail's, word for word:

     0042F018  addiu  $sp,$sp,-0x110     addiu  $sp,$sp,-0x110
     0042F01C  lui    $v1,%hi(D_1CAE40)  lui    $v1,%hi(D_1CAE40)
     0042F020  sd     $s3,0xA8($sp)      sd     $s3,0xA8($sp)
     0042F024  lw     $v0,%lo(D_1CAE40)  lw     $v0,%lo(D_1CAE40)
     0042F028  daddu  $s3,$a0,$zero      daddu  $s3,$a0,$zero
     0042F02C  sd     $s0,0x90($sp)      sd     $s0,0x90($sp)
     0042F030  sd     $s1,0x98($sp)      sd     $s1,0x98($sp)
     0042F034  sd     $s2,0xA0($sp)      sd     $s2,0xA0($sp)
     0042F038  sd     $s4,0xB0($sp)      sd     $s4,0xB0($sp)
     0042F03C  sd     $s5,0xB8($sp)      sd     $s5,0xB8($sp)
     0042F040  sd     $ra,0xC0($sp)      sd     $ra,0xC0($sp)
     0042F044  swc1   $f27,0x108($sp)    swc1   $f27,0x108($sp)
     ... f26, f25, f24, f23, f22, f21 ...
     0042F060  bnez   $v0,..             bnez   $v0,..
     0042F064  swc1   $f20,0xD0($sp)     swc1   $f20,0xD0($sp)

   (the %hi/%lo relocations print as 0 on our side, so the two sides are the
   raw object and the retail bytes: our lui would resolve to 0x1D and our
   addiu to -0x51C0.)

   THE FIRST REAL DIFFERENCE is now at 0042F084, the "armed" block, and it is
   a register choice, not a shape:

     0042F084  lhu   $a0,0x34($s3)   |  lhu   $v0,0x34($s3)
     0042F088  addiu $v0,$zero,0x1   |  addiu $v1,$zero,0x1
     0042F08C  sb    $v0,0xBC($s3)   |  sb    $v1,0xBC($s3)
     0042F090  ori   $a0,$a0,0x41    |  ori   $v0,$v0,0x41

   The retail keeps the halfword in $v0 and the constant 1 in $v1; ours keeps
   them in $a0 and $v0.  $v0/$v1 are not in the MIPS reg_alloc_order (which is
   $a0-$a3, $s0-$s7, $t8, $t9, $k0, $k1, $gp, $sp, $fp, $ra, $f0-$f31), so a
   value in $v0 is a RELOAD register: the retail's halfword is a pseudo that
   the reload phase put in a scratch register, ours is a local-allocated one.
   That is the next thing to look at.

   WHAT THIS PASS CHANGED, AND WHAT IT MEASURED

   1. THE FIVE func_002C2210 CALLS OF THE TIMER WINDOW HAVE THE SIGN
      PATTERN +, -, -, -, +.  The retail's a4 ($t0) is:

        004310FC  jal f_0034D250   daddu $t0,$s0,$zero   ; +idx
        00431104  negu $s0,$s0                          ; the register is negated
        00431154  jal f_0034D250   daddu $t0,$s0,$zero   ; -idx
        00431194  jal f_0034D250   daddu $t0,$s0,$zero   ; -idx
        004311C8  jal f_0034D250   daddu $t0,$s0,$zero   ; -idx
        004311FC  jal f_0034D250   negu   $t0,$s0        ; +idx

      so the source holds the NEGATED index in one register and negates it
      back on demand: `ei = -ei;' between the first and the second call, with
      the arguments ei, ei, ei, ei, -ei.  The transcription had ei, -ei, ei,
      ei, -ei, which made gcc keep TWO index registers alive across the calls
      - that was the extra callee-saved GPR the brief was looking for.

   2. THE CASE-22 HERO POSITION WAS READ FROM AN UNASSIGNED VARIABLE.  The
      source used `s1' in d21 without ever assigning it (d21 is the first
      block that uses it).  The retail's case 22 reads the position at
      D_00189EA0+0x00 and +0x04 (g_heroPos), so the fix is `s1 = D_00189EA0;'
      before the test.  With that assignment the variable's live range starts
      in d21 and the seventh callee-saved GPR disappears: the save block goes
      from (s3, s0, s1, s2, s4, s5, s6, ra) to the retail's (s3, s0, s1, s2,
      s4, s5, ra).

   3. THE product*0.2f OF THE THIRD func_002C2210 CALL IS NOT A VARIABLE.
      The retail computes it into the call-clobbered $f13 right before the
      call (0043116C mtc1 $at,$f13 / 00431174 mul.s $f13,$f21,$f13); the
      transcription kept it in a named float, which cost a callee-saved FPR.
      Inlining it into the argument (`f21 * 0.2f') gives the retail's shape
      and takes the saved FPRs from 9 to 8 - the retail's number.

   4. THE CASE-22 TAIL IS A LOOP.  The retail's window ends with
      00431218 bltz $v1,.L00431260, i.e. it jumps back to the 9.0f test, and
      the computed value (the retail's f25) is live from 00430DD0 to 00431550
      - across the whole tail.  The transcription had `goto Lend;' there, so
      the computed value died early and the loop was missing.  With the label
      at the 9.0f test and the jump back to it, the tail keeps the value
      alive and the FPR budget matches.

   5. THE REGISTER SHAPE "(reg - 0x80) + 0x80" (measured with the compiler
      alone, no game data):

        the retail's case 22:  00430998 addiu $v0,$s1,-0x80
                                004309A0 lwc1  $f1,0x84($v0)
                                004309A4 lwc1  $f12,0x80($v0)
      with $s1 = D_00189EA0.  That is NOT a constant address (gcc folds
      D_00189E20+0x80 into one lui+load, measured), it is a pointer variable
      holding (base - 0x80) with the accesses at +0x80/+0x84.  A test file
      with

        u8 *hp = D_00189EA0;  u8 *q = (u8 *)hp - 0x80;
        g1 = *(f32 *)(q + 0x80);  g2 = *(f32 *)(q + 0x84);

      compiles to exactly `addu $17,$5,-128' + `l.s $f1,132($17)' +
      `l.s $f0,128($17)' - the retail's shape.  The same shape with -0x61E0
      gives the retail's case-24 base (00431660 addiu $s1,$s1,-0x61E0).

      The transcription reads the position as `s1 + 0x0' / `s1 + 0x4', which
      is the right VALUE (D_00189EA0+0x00/+0x04) but the wrong shape; the
      next worker should write it as the two-statement form above.  Doing that
      with an extra variable costs a seventh GPR (measured), so it has to be
      done without one.

   6. THE CATALOGUE GAP STANDS: the case-24 block reads a position at
      0x183D40 and 0x183D44, which is (D_00189EA0 - 0x61E0) + 0x80/+0x84.  The
      base 0x183CC0 has NO symbol in the catalogue (the boot's symbols jump
      from D_00188714 to D_00189E00), and the retail computes it at run time
      as `addiu $s1,$s1,-0x61E0'.  The transcription spells it as the literal
      0x183CC0 (the macro L183CC0), which is right in value and wrong in
      shape.

   7. WHAT THE CASE-22 BLOCK IS STILL MISSING (this is where the remaining
      850 bytes are).  The retail's case 22 has TWO windows and a loop:

        00430DC8  f25 = func_0029F530(s3)
        00430DE8  if (f25 < 3.0f) { the 0.2f/0.9f effect }
        00430F6C  if (3.0f <= f25) {
        00430F84    if (f25 < 9.0f) {          <- WINDOW A (0x430FC0..0x431260)
        00430F9C      if (s3[0x42] == 0xA) {
                       func_00282F20, func_002A8C00(f27), func_00282CC0,
                       func_002761F8, the D_L11_001C0D20 copy, the five
                       func_002C2210 calls, func_L00_002E6CF0, the record
                       update, and the jump BACK to the 9.0f test }
        00431260    }
        0043126C    if (9.0f <= f25) {
        0043127C      if (f25 < 15.0f) {      <- WINDOW B (0x4312D4..0x431540)
        00431298        if (s3[0x42] == 0xA) {
                          the same calls again, with an extra func_00282F20
                          with the 1.6666667f argument, and a second
                          func_002A8C00(f27) }
        0043154C    }
        00431550    if (15.0f < f25) { if (s3[0x42] == 0xA) goto the release; }
        0043156C    the release: if (s4[0x2B0] >= 0) { func_00291450(s4+0x2B0);
                   s4[0x2B0] = -1; }

      The transcription has only ONE window (A) and no second one, which is
      why the (float)(s4[0x35]) value dies before the five func_002C2210
      calls in ours and lives across them in the retail (the retail's f27).
      Transcribing window B is the next big piece of work.

   THE OTHER FUNCTIONS IN THE FILE still match after this pass:
     func_L11_0042A420: 1 of 1 places match
     func_L11_0042EF90: 1 of 1 places match
     func_L11_00431D50: 1 of 1 places match
     func_L11_00431E30: 1 of 1 places match

   FIFTH PASS (worker 01): THE ANCHOR IS SOLVED -- THE %hi IS IN $s1.

   check.py (11_joba), with the source below:

     11_joba: 9464 bytes, expected 10312
     func_L11_0042F018: 0 of 1 places match
     the first difference is at 0042F020 (the save block), and the two
     instructions before it are the retail's:

       0042F018  addiu $sp, $sp, -0x110     addiu $sp, $sp, -0x110
       0042F01C  lui   $v1, %hi(D_1CAE40)  lui $v1, %hi(D_1CAE40)
       0042F020  sd    $s4, 0xB0($sp)      | sd $s3, 0xA8($sp)

   (the %hi/%lo relocations print as 0 on our side, so the two sides are the
   raw object and the retail bytes.)

   THE %hi OF D_00189E20 IS NOW IN $s1, the retail's register:

       0042F068  lui   $v0, %hi(D_189E20)
       0042F06C  addiu $a0, $zero, 0x6F
       0042F070  daddu $s1, $v0, $zero      <- the retail's
       0042F074  addiu $v0, $v0, %lo(D_189E20)
       0042F078  lw    $v1, 0x2294($v0)

   That was the wall of the four earlier passes.  What moved it, measured:

   1. THE STRUCT-CAST IDIOM ALONE DOES NOT MOVE IT.  With
      `((Actor *)D_00189E20)->f2294' everywhere (the brief's recipe, the same
      one that solved the sibling body) and NOTHING ELSE changed, the %hi
      stays in $s5 and the body is 8980 bytes.  The idiom gives the retail's
      SHAPE (one `lui %hi(D)', the address rebuilt with `addiu %lo(D)' at
      every use) - the fourth pass's `p = D_00189E20;' already gave that -
      but the REGISTER is decided by the allocation over the whole body, not
      by the spelling of the global.

   2. WHAT MOVES IT IS THE LIVE RANGE OF THE %hi.  The retail's %hi of
      D_00189E20 dies at case 14 (0x42FCC0, the last use); the fourth pass's
      transcription used D_00189E20 in case 22 as well, so the %hi lived to
      the end of the function, its priority
      (QTY_CMP_PRI = floor_log2(n_refs) * n_refs * size / (death - birth),
      gcc/local-alloc.c) was the lowest of the six, and it was allocated
      LAST ($s5).  With case 22 no longer using D_00189E20 the %hi's range
      ends at case 14, its priority rises above the other five, and it is
      allocated SECOND: $s1.  Measured: the same source with case 22 still
      reading D_00189E20 gives $s5; with the 0x183CC0 base it gives $s1.

      So the brief's two levers are really ONE lever: the base of the case-22
      block.  The struct-cast idiom is still worth keeping (it is the
      retail's spelling and it makes the address a common expression), but
      on its own it changes nothing.

   3. THE FRAME IS STILL RIGHT: 0x110, seven saved GPR slots plus ra, eight
      saved FPRs (f20..f27) - the retail's.

   WHAT IS STILL WRONG IN THE PROLOGUE: we save SEVEN callee-saved GPRs
   (s0..s6) where the retail saves six (s0..s5); the argument lands in $s4
   instead of $s3.  The retail's six, with what they hold:

     $s0  the constant -1 (and, after it dies, the effect index)
     $s1  the %hi of D_00189E20 (and, after it dies, the address of
          D_00189EA0)
     $s2  the %hi of D_00189EA0
     $s3  the argument
     $s4  s3+0x68
     $s5  s4+0x230 (or s4+0x240)

   and NO local value needs a callee-saved register: the local allocator
   finds room in $v0/$v1/$a0-$a3/$t0-$t9.

   Ours has one value too many: the multi-def local `v' (one variable used
   for every index, count and pointer in the case blocks) is ONE pseudo with
   30 definitions, so its live range spans all of them and crosses calls;
   the retail's source used a separate variable per block, and its values
   live in the scratch registers.  Splitting `v' into 24 variables was
   measured and made it WORSE (eight saved GPRs, frame 0x120): gcc 1.x
   gives every one of them a register of its own.  The next worker has to
   find the ONE value that is live across a call where the retail's is not.

   THE TRANSCRIPTION DEFECTS THIS PASS FOUND AND FIXED

   - func_002A7E08's SIGNATURE IS (u8 *a0, u32 a1, u32 a2, f32 f12, f32 f13,
     f32 f14).  The retail's case 14 (0x42FCC0) sets $a1 = *(D_00189E20 +
     0x2290) and $a2 = s4+0x284, and its case 19 (0x42FF7C) sets $a1 =
     *(D_00189EA0 + 0x2210) and $a2 = s4+0x284.  The fourth pass read the
     load at 0x42FCD0 as the fifth argument and lost the $a2 = s4+0x284.

   - func_00282E80 RETURNS A FLOAT.  The retail compares the return value
     with 25.0f (case 22), 10.0f (case 22 again) and 20.0f (case 15); the
     transcription compared func_00283C80(s3+0xF8) instead.

   - THE HERO POSITION IS AT D_00189EA0+0x00 AND +0x04, not at +0x80 and
     +0x84.  The retail reads it as ($s1 - 0x80) + 0x80 and ($s1 - 0x80) +
     0x84, where $s1 is the full address of D_00189EA0; the values are
     0x189EA0 and 0x189EA4 (g_heroPos).

   - THE CATALOGUE GAP: the case-22 block reads a position at 0x183D40 and
     0x183D44, which is (D_00189EA0 - 0x61E0) + 0x80/+0x84 - the base
     0x183CC0 has NO symbol in the catalogue (the boot's symbols jump from
     D_00188714 to D_00189E00), so the original source must have used a name
     the catalogue does not have.  The transcription uses D_00189E20 there,
     which is wrong; it is left as it is because the block is a stand-in
     anyway, but it is the reason the %hi's live range in ours runs to the
     end of the function while the retail's stops at case 14.  Giving the
     two blocks a SECOND name for the same address (D_00189E20_2, which the
     linker script does define) shortens the %hi's range to case 14
     and changes nothing else - measured, and left out of the source
     because it is a guess that buys nothing.

   - A CATALOGUE DEFECT: none.  The catalogue's row for func_L11_0042F018
     (size 10312, one place, 11:0042F018) is right.

   THE OTHER FUNCTIONS IN THE FILE still match after this pass:
     func_L11_0042A420: 1 of 1 places match
     func_L11_0042EF90: 1 of 1 places match
     func_L11_00431D50: 1 of 1 places match
     func_L11_00431E30: 1 of 1 places match

   --- THIRD PASS (worker 01): THE PROLOGUE'S GLOBAL LOAD IS RIGHT.

   check.py (11_joba), with the source below:

     11_joba: 8888 bytes, expected 10312
     func_L11_0042F018: 0 of 1 places match
     the first difference is now at 0042F070, and the 22 words of the prologue
     before it are the retail's (the %hi/%lo relocations print as 0 here, so
     the two sides are the raw object and the retail bytes):

       0042F018  addiu $sp, $sp, -0x110     addiu $sp, $sp, -0x110
       0042F01C  lui   $v, %hi(D_1CAE40)    lui $v, 0x1D
       0042F020  sd    $s3, 0xA8($sp)        sd $s3, 0xA8($sp)
       0042F024  lw    $v, 0x0($v)           lw $v, -0x51C0($v)
       0042F028  daddu $s3, $a0, $zero       daddu $s3, $a0, $zero
       0042F02C  sd    $s0, 0x90($sp)        sd $s0, 0x90($sp)
       ... the rest of the save block ...
       0042F060  bnez  $v, .+4+(8<<2)        bnez $v, .+4+(8<<2)
       0042F064  swc1  $f20, 0xD0($sp)       swc1 $f20, 0xD0($sp)
       0042F068  lui   $v, 0x0          |  lui $v, 0x19
       0042F06C  addiu $a0, $zero, 0x6F    addiu $a0, $zero, 0x6F
       0042F070  daddu $s5, $v, $zero  |  daddu $s1, $v, $zero
       0042F074  addiu $v, $v, 0x0     |  addiu $v, $v, -0x61E0
       0042F078  lw    $v, 0x2294($v)       lw $v, 0x2294($v)
       0042F07C  bnel  $v, $a0, .+4+(9<<2) bnel $v, $a0, .+4+(9<<2)
       0042F080  lbu   $v, 0xBC($s3)        lbu $v, 0xBC($s3)

   What the third pass changed, and what it measured:

   - THE LATCH IS A VALUE, NOT A POINTER.  The source read
     `*(s32 *)D_L11_001CAE40`, which is a double indirection: the object
     loaded the global and then dereferenced it.  The retail loads the global
     itself (`lw $v, %lo(D_1CAE40)($v)`).  With `D_L11_001CAE40 != 0` the
     load moves into the prologue, between the `sd $s3` and the
     `daddu $s3,$a0,$zero`, exactly where the retail has it.

   - THE PROLOGUE'S SHAPE IS A GOTO, NOT AN IF.  The retail's control flow is

         if (latch) goto armed;
         if (*(s32 *)(D_00189E20 + 0x2294) != 0x6F) goto rearm;
     armed:
         ...; return;                 (the branch to the epilogue, 0x42F09C)
     rearm:
         ...;                           (falls into the update)

     with `armed` reached from two places and placed between the two tests.
     A C `if` whose body ends in a `goto Lend` puts the body inline and emits
     `beq` instead of the retail's `bnez`; the goto form gives the retail's
     `bnez $v, .L0042F084` and the same block order.

   - THE HALFWORD AT s3+0x34 IS UNSIGNED.  With an `s16` variable the object
     emits `lh` and a 64-bit mask constant (`addiu $v,$zero,-0x1001` plus
     `and`); the retail has `lhu` and the 16-bit `andi $v,$v,0xEFFF`.  A
     separate `u16` variable for the s3+0x34 halfword (the s4+0x274 one stays
     `s16`, the retail loads it with `lh`) gives the retail's instructions
     and the four bytes that follow.

   - THE D_00189E20 ADDRESS IS MATERIALISED FROM A LOCAL POINTER.  The retail
     keeps the %hi of D_00189E20 in a callee-saved register and rebuilds the
     address with `addiu $v,$s1,-0x61E0` at every use (seven times).  A
     direct `D_00189E20 + 0x2294` in the source gives the folded form
     (`lui %hi(D+8852)` + `lw %lo(D+8852)($2)`), one instruction shorter but
     not the retail's.  A local pointer (`p = D_00189E20;` then
     `*(s32 *)(p + 0x2294)`) gives the retail's exact prologue:

         lui $v,%hi(D_00189E20)
         addiu $a0,$zero,0x6F
         daddu $s1,$v,$zero            <- the %hi keeps its own register
         addiu $v,$v,%lo(D_00189E20)  <- the full address, in a temporary
         lw $v,0x2294($v)

     and the %hi lives across the calls, so it takes a callee-saved register.
     The split form of the address is the compiler's (mips_split_addresses);
     the source only has to name the symbol.

   - WHAT IS STILL OFF IN THE PROLOGUE: the %hi of D_00189E20 lands in $s5
     here and in $s1 in the retail, and the halfword of the arming block in
     $v here and $v in the retail.  Both are register choices: the %hi
     pseudo is live across the whole function, so its priority
     (log2(n_refs)*n_refs*size/(death-birth)) is low and it takes a high
     callee-saved register; in the retail the source must have one less
     competing pseudo.

   - CORRECTIONS to the transcription (all measured against the retail):

       * D_L11_001C8A40 is 0x20 bytes per record, so the global is a BYTE
         array: `extern u8 D_L11_001C8A40[];` and the index is
         `D_L11_001C8A40 + idx * 0x20`.  Declared as `u32[]` the pointer
         arithmetic multiplied the stride by four (the object computed
         `sll $v,$v,7`, the retail has `sll $v,$v,5`).

       * func_002A8C00 takes (ptr, ptr, u32, ptr, f32): the retail sets a3 to
         a pointer and f12 to the float (`mov.s $f12,$f27`), the source had
         them the other way round.

       * func_00282F20 takes three arguments: the retail's case 27 calls it
         with (sp, s3+0xC0, -5.5f).

       * func_002AEB60 returns a value: the retail tests it (`beqz $v`).

       * case 22's "3,2" path needs the s4+0x2A0 counter at 3 or more
         (`slti $v,$v,3; bnez $v,<the 0x18 path>`), not below it.

   - CASE 22, THE BLOCK THAT IS STILL HALF TRANSCRIBED.  The retail's case 22
     is 0x430908..0x431550, about 3.1 kB, and it is the whole of the missing
     1.4 kB.  Its structure, in the retail's order:

     0x430908  if (s4+0x27C == 0) { func_002A7750(s3,0xF,-1);
                                     func_L11_0042EF90(s3,6,5,0,0xA); }
     0x430940  if ((s3[0x60] & 2) == 0) goto 0x430AF0;
               s0 = s3+0x10; s1 = D_00189EA0; func_00282E80(s0,s1);
     0x430964  if (func_00283C80(s3[0xF8]) < 25.0f) {
                     if (s4+0x27C != 0 && s4+0x2A0 < 3) {
                         func_00283248(s3[0x10]-D_189EA0[0x80],
                                       D_189EA0[0x84]-s3[0x14]);
                         if (0.087266475f < func_00283C80(s3[0xF8])) {
                             func_002A7750(s3,0x18,-1);
                             func_L11_0042EF90(s3,0xF,4,0,0xA);
                         } else {
                             func_L11_0042EF90(s3,9,6,0,0xA);
                             func_002A7750(s3,0x12,-1);
                         }
                         goto 0x430AD8;
                     }
                 }
     0x430A3C  func_00282E80(s0, D_00189EA0);
                if (10.0f < func_00283C80(s3[0xF8])) {
                    if (s4+0x27C != 0 && s4+0x2A0 >= 3 && s4+0x2BC == -1) {
                        func_L11_0042EF90(s3,3,2,0,0xA);
                        func_002A7750(s3,0x17,-1);
                        s4[0x2A0] = 0;
                        goto 0x430AD4;
                    }
                }
                func_002A7750(s3,0x18,-1);
                func_L11_0042EF90(s3,0xF,4,0,0xA);
     0x430AD4  if (s4+0x27C == 0) goto 0x4315EC;
                s4[0x2A0] += 1;

     0x430AF0  (the 0x60 flag is not set)
                if (func_002AEB60(s3,3.0f) == 0) goto 0x430DC8;
                if (s4+0x27C == 0) goto 0x430DC8;
                s0 = D_00189E20;
                func_00283248(D_189E20[0x80]-s3[0x10], D_189E20[0x84]-s3[0x14]);
                if (func_00283C80(s3[0xF8]) < 0.78539824f) {
     0x430B58    func_0029FCC0(*(u32 *)(*(u32 *)(s4+0x27C)+0x68)+0x278, 0, &vec);
                    vec[0] = func_00283180(s3[0xF8]) * 0.1f;
                    vec[1] = func_00283198(s3[0xF8]) * 0.1f;
                    vec[2] = 0.0f;
                    func_00282CC0(&vec, &vec, &vec2);
                    vec[2] -= 0.05f;
                    the 16 bytes to s4+0x230;  s4[0x298] = 0.0f;
                    func_L00_003294F0(s3, 0);
                    v = func_L00_002FCF18(s3, 5.0f, 0.0f, 1.0f, 0.0f, 0.0f);
                    if (v < 0) goto 0x430DC8;
                    s4[0x2B0] = v;
                    the record at D_L11_001C8A40 + v*0x20:
                        +0x10 = the 16 bytes of s4+0x230, +0x0C = 0.0f,
                        +0x1C = 5.0f, +0x00 = 1.0f, +0x04 = 0.0f,
                        +0x18 = record[0x18] + 1.0f, +0x08 = 0.0f
                } else {
     0x430C70    the same with 25.0f instead of 0.1f, then a second
                  func_00282CC0 and func_00282CF0(s4+0x250, &vec2, &vec),
                  and func_L00_002FCF18(s3+0x10, 5.0f, 0.0f, 1.0f, 0.0f, 0.0f)
                }

     0x430DC8  f25 = func_0029F530(s3);
                if (f25 < 3.0f) goto 0x430E04;
                if (s3[0x42] == 9) goto 0x430F6C;
     0x430E04  if (s4+0x27C == 0) goto 0x430F60;
                func_0029FCC0(..., &vec);
                vec[0] = func_00283180(s3[0xF8]) * 0.1f;
                vec[1] = func_00283198(s3[0xF8]) * 0.1f;
                vec[2] = 0.0f;
                func_00282CC0(&vec, &vec, &vec2);
                vec[2] -= 0.05f;
                f = func_002A7878(0.2f, 0.35f) * 0.2f * s4[0x288];
                v = func_002A77E0(2); if (v == 0) v = -1;
                func_002C2210(&vec, 2, 0x804020FF, 0,  v, D_001A8F20, 0,
                              f * 0.3f, f, 0.0f);
                func_002C2210(&vec, 2, 0x7F6F6FFF, 1, -v, D_001A8F20, 0,
                              f * 0.04f, f * 0.2f, 0.0f);
                s4[0x288] += 1.0f;
     0x430F60  f0 = 3.0f; f27 = (f32)s4[0x35];
     0x430F6C  if (3.0f <= f25) goto 0x431260;
                if (f25 < 9.0f) {
                    f = s4[0x298] + 1.0f; s4[0x298] = f;
                    func_00282F20(s4+0x240, s4+0x250, f);
                    func_002A8C00(&vec, s3, 1, s4+0x240, f27);
                    *(u16 *)(sp+0x1A) = *(u16 *)(s3+0xAA);
                    func_00282CC0(s4+0x240, s4+0x230, s4+0x240);
                    if (func_002761F8(s4+0x230, s4+0x240, 0, s3, &vec)) {
                        the 16 bytes of D_L11_001C0D20 to s4+0x240;
                        if (func_002B38B8(s3) == 0) {
                            func_L04_003E5830(D_L11_001C0D20, 6);
                            func_L00_003294F0(s3, 1);
                        }
                    }
                    f21 = func_002A7878(1.0f, 6.0f);
                    f23 = f21 * 0.3f; f22 = f21 * 0.04f; f20 = f21 * 0.2f;
                    f24 = 0.0f;
                    v = func_002A7820(0x19, 0x23); if (v == 0) v = -1;
                    the 16 bytes of s4+0x240 -> sp+0x30;
                    sp30[2] -= 0.1f;
                    func_002C2210(&sp30, 0x19, 0xFF000080, 0,  v, D_001A8F20, 0, f23, f21, f24);
                    func_002C2210(&sp30, 5,    0x7F6F6FFF, 1, -v, D_001A8F20, 0, f22, f20, f24);
                    func_002C2210(&sp30, 0x14, 0xFF4080FF, 1,  v, D_001A8F20, 0, f20, f20, f24);
                    func_002C2210(&s4230, 0xA, 0x80CA00CB, 0,  v, D_001A8F20, 0, f23, f21, f24);
                    func_002C2210(&s4230, 0xA, 0x7F6F6FFF, 1, -v, D_001A8F20, 0, f22, f20, f24);
                    func_L00_002E6CF0(func_L11_00431E30, s3);
                    if (s4[0x2B0] < 0) goto 0x431260;
                    the record at D_L11_001C8A40 + s4[0x2B0]*0x20:
                        +0x10 = the 16 bytes of s4+0x240, +0x0C = 0.0f,
                        +0x1C = 5.0f, +0x00 = 1.0f, +0x04 = 0.0f,
                        +0x18 = record[0x18] + 1.0f, +0x08 = 0.0f
                }
     0x431260  (f25 < 9.0f) the end of case 22
     0x43154C  (f25 >= 15.0f) the same window with 1.6666667 and 1.3
     0x4315EC  the end of case 22

     So case 22 has FIVE func_002C2210 calls, not four, and the values are
     the products of func_002A7878(1.0f, 6.0f) - the first pass's 0.2f, 0.3f,
     0.04f and 0.9f were a stand-in.  The 16-byte copies are `lq`/`sq` pairs,
     which need a TI-mode type (see docs/COMPILER-NOTES.md: a plain struct
     assignment gives `ldl`/`ldr`/`sdl`/`sdr`).

   - THE LOCALS OF THE RETAIL (from the stack traffic of the body): a 16-byte
     vector at sp+0x00 (case 22's vecA, and case 20's three-float struct),
     a 16-byte vector at sp+0x10 (case 20's func_0029FCC0 target and case
     22's vecB, with a halfword at sp+0x1A), vectors at sp+0x20 and sp+0x30,
     a 12-byte struct at sp+0x40 (a halfword at sp+0x4A), vectors at sp+0x50
     and sp+0x60, a 12-byte struct at sp+0x70 (a halfword at sp+0x7A) and a
     vector at sp+0x80.  The three halfwords at 0x1A, 0x4A and 0x7A are the
     same kind of local 0x30 apart.

   - THE FRAME IS A TRADE: the GPR and the FPR save areas together are 120
     bytes and the retail splits them 7/8 (s0..s5 + ra, then f20..f27).  The
     third pass transcribed case 22 in full and the split came out 9/6, so
     the case-22 source has two more pointers live than the retail's.  The
     retail's case 22 keeps the %hi of D_00189E20, D_00189EA0 and
     D_00189E20's full address in $s0, $s1, $s2 and $s5, and the record base
     in a temporary; the transcription has to keep one less pointer alive.

   SECOND PASS (worker 01): THE FRAME IS NOW RIGHT.

   check.py (11_joba), with the source below:
     11_joba: 8868 bytes, expected 10312
     func_L11_0042F018: 0 of 1 places match
     first difference at 0042F01C -- the prologue's global load, not the frame:
       0042F018  addiu $sp, $sp, -0x110               addiu $sp, $sp, -0x110
       0042F01C  lui   $v, 0x0                     | lui   $v, 0x1D
       0042F020  sd    $s3, 0xA8($sp)                 sd   $s3, 0xA8($sp)
       0042F024  sd    $s0, 0x90($sp)               | lw    $v, -0x51C0($v)
       0042F028  daddu $s3, $a0, $zero                daddu $s3, $a0, $zero
       0042F02C  sd    $s1, 0x98($sp)                 sd   $s0, 0x90($sp)
       ... the rest of the save block ...
       0042F040  swc1  $f27, 0x108($sp)             | sd   $ra, 0xC0($sp)
       0042F044  swc1  $f26, 0x100($sp)             | swc1 $f27, 0x108($sp)
       ... down to swc1 $f20, 0xD0($sp) ...
     (the two sides are the raw object and the retail bytes, so the %hi/%lo
     relocations show as 0 on our side: our object really does use the
     lui/%lo form now, see D_L11_001CAE40 below.)

   WHAT THE SECOND PASS ESTABLISHED (all measured):

   - THE FRAME IS EMERGENT, and the arithmetic is now known exactly.  With
     V = the bytes of locals, G = 8 * the number of saved GPRs, F = 8 * the
     number of saved FPRs:

         frame = align16(align16(V + G) + F)

     (align16 = round up to 16.)  Measured on a dozen test functions: the
     local area sits at the bottom of the frame, the GPR save area follows
     it, the FPR save area is 16-byte aligned after that, and the frame is
     rounded up to 16.  The retail's frame 0x110 = 272 is therefore
     V = 0x90 (144 bytes of locals), G = 0x38 (7 GPRs: s0..s5 + ra) and
     F = 0x40 (8 FPRs: f20..f27).  This pass reached exactly that:
     vars = 144, regs = 7/8, frame = 0x110, and the save block now has the
     retail's slots (s0 at 0x90 ... ra at 0xC0, f20 at 0xD0 ... f27 at 0x108).

   - The number of saved FPRs is the number of FP values that are live
     across a call, and GCC 1.x picks the register by the priority
     QTY_CMP_PRI = log2(n_refs) * n_refs * size / (death - birth): the
     SHORTEST live range is allocated FIRST and gets the LOWEST callee-saved
     FPR, ties go to the lower qty number (gcc/local-alloc.c,
     qty_compare_1 / find_free_reg).  This is why the retail has f20 = the
     4.0f multiplier of case 20 (the shortest range) and f27 = the longest.

   - A float constant that is used in two calls (a call in between) becomes
     a pseudo, and a pseudo that is live across a call is put in a
     callee-saved FPR and copied into the argument register.  That is the
     "mov.s $f14, $f20" shape of the retail.  A constant used once is
     loaded straight into the argument register and costs no FPR.

   - The retail's eight FPRs, with the values that hold them (from the
     disassembly, f20..f27):
       f20  0.1f / 4.0f / 0.001163553 / 0.10471977 (cases 20, 27, 17, 16)
       f21  0.001163553 / 0.10471977 / 0.1f / 0.05f
       f22  0.10471977 / 0.001163553 / 0.3f / 1.0f
       f23  0.0033333334 / 0.0f / 5.0f
       f24  0.3f (case 22)
       f25  the computed value of case 22
       f26  0.9f (case 22)
       f27  (float) of an int (case 22)
     So cases 16, 17, 18, 19, 20, 22 and 27 are the ones that keep FP values
     alive; the two dispatch tables and the other cases keep none.

   - D_L11_001CAE40 (the latch) is read with lui/%lo in the retail, so the
     declaration needs __attribute__((nosda)); with the plain declaration
     the compiler reaches it through $gp and the prologue gains two
     instructions and a register.  The retail's %hi is materialised
     INSIDE the save block (between the first two saves) and the %lo load
     sits between `sd $s3` and `daddu $s3,$a0,$zero`; ours puts both after
     the block.  That is the first difference now.

   - The retail's argument order of func_002B60B0 in case 20 is
     (0.004166667, 0.033333335, 0.001163553, 0.10471977) and in case 27
     (0.0011111111, 0.033333335, 0.001163553, 0.10471977); the first pass
     had the constants permuted.  In case 19 the value stored to
     s4+0x164 is 0.0069444445, NOT the 0.006666667 of the call: with the
     same constant in both places the compiler makes a pseudo and spends a
     callee-saved FPR on it, which the retail does not do.

   - The locals of the retail (sp+0x00 .. sp+0x8F) are, in declaration
     order: a 12-byte struct at 0x00, 16-byte vectors at 0x10, 0x20 and 0x30,
     a 12-byte struct at 0x40 (it holds {u8, u8, u16} at +8 and a
     float at +8), a vector at 0x50, a vector at 0x60, a 12-byte struct at
     0x70 ({u8, u8, u16} at +8) and a vector at 0x80.  GCC 1.x gives every
     aggregate (BLKmode) slot BIGGEST_ALIGNMENT (16) alignment and every
     scalar its own, so a 12-byte struct at 0x00 is followed by the next
     aggregate at 0x10.

   - What is still open: the case-22 block (the retail's 0x430908..0x431550,
     about 2400 bytes) is only half transcribed.  Its four func_002C2210
     calls with D_L11_001A8F20, the D_L11_001C8A40 record update and the
     f25/f26/f27 values are what the transcription is missing, and the
     d21b block is unreachable in the transcription (nothing branches to
     it), so its code is dropped by the compiler.  The source below adds
     a reconstruction of that block; the vec6 stores of 0.4f are a stand-in
     for the retail's real use of 0.4f (it is the constant of the second
     and third func_002C2210 call, and the retail keeps it in f20 across
     them) and are not the retail's own source.

   --- FIRST PASS (kept) ---

   /* func_L11_0042F018 (10312 bytes, level 11 joba) -- NEAR MISS, not integrated.
   state: the whole body is transcribed (both dispatch tables, all 5 + 27 cases, the
   shared tails and the epilogue) and it compiles, but it does not match: 7436 bytes
   against retail's 10312, and the first difference is the frame size in the very
   first instruction, so nothing after the prologue lines up yet.

   check.py (11_joba), with the source below:
     11_joba: 7436 bytes, expected 10312
     func_L11_0042F018: 0 of 1 places match
     2524 of 2578 instructions differ; first at 0042F018
       0042F018  addiu $sp, $sp, -0xA0    |  addiu $sp, $sp, -0x110
       0042F01C  lui   $v, 0x0           |  lui   $v, %hi(D_1CAE40)
       0042F020  sd    $s3, 0x48($sp)     |  sd    $s3, 0xA8($sp)
       0042F024  sd    $s0, 0x30($sp)     |  lw    $v, %lo(D_1CAE40)($v)
       0042F028  (no copy)               |  daddu $s3, $a0, $zero
       ... the rest of the save block ...
       0042F040  swc1  $f24, 0x90($sp)    |  sd    $ra, 0xC0($sp)
       0042F044  swc1  $f23, 0x88($sp)    |  swc1  $f27, 0x108($sp)
       ... down to swc1 $f20, 0xD0($sp) ...

   What is right and measured:
   - The two dispatch tables are the LEVEL's own data, so they are reachable from C
     with a computed goto and no compiler-generated jump table:
         extern void *jtbl_002BAF00[5];
         extern void *jtbl_002BAF20[27];
     both names are in build/11_joba/config/undefined_syms_auto.txt, and the build
     resolves them from the retail's lui %hi / addiu %lo pair.  A C `switch` cannot be
     used: cc1 puts its table in the object's .rdata, which tools/build.py discards.
     The case bodies are kept alive by a `static void * volatile` array of &&labels.
   - The range check the retail emits before the table is the one a computed goto
     needs written by hand: `addiu $a0,$v,-1` / `sltiu $v,$a0,0x1B` / `beqz $v,end`
     for the second table (values 1..27 of s3[0x20]), and `sltiu $v,$v,5` / `beqz`
     for the first (values 0..4 of s3[0x95]).
   - D_00189E20 is a boot-resident global (0x189E20 < 0x1A7C80) and is the same in
     every program: name it D_00189E20, not D_L11_.  The level's own globals
     (0x1CAE40, 0x1FF580, 0x1B359C, 0x1C8A40, 0x1C0D20, 0x1A8F20, 0x1AED04) are
     D_L11_XXXXXXXX.
   - The retail keeps the %hi of D_00189E20 in $s1 and rebuilds the address with
     `addiu $v,$s1,-0x61E0` at every use (four times).  That is the split-address
     form; a plain `D_00189E20` gives one register and one instruction less.
   - D_L11_001B359C is reached BOTH ways in the retail: through $gp
     (`lw $v,0x45AC($gp)` at 0x42F690) and through lui/%lo
     (`lui $v,%hi; lw $v,%lo($v)` at 0x42F9A4).  A second name with
     __attribute__((sda)) for the gp form and the plain name for the lui/lo form is
     what the source must have used.
   - Every float constant of the body is a single float, and the two near-0.1 values
     are one ULP apart from 0.1f: 0x3DCCCCCE = 0.10000001f and 0x3E4CCCCE =
     0.20000002f.  They are NOT 0.1f and 0.2f; the retail has 0x3DCCCCCD (= 0.1f) and
     0x3E4CCCCD (= 0.2f) elsewhere, so the source has both spellings.
   - The retail's branch-likelys run their delay slot when the branch is TAKEN
     (beql $v,$zero,.L0042F0D0 / lw $s4,0x68($s3) at 0x42F0A4: $s4 is only ever set
     by that delay slot on the taken path), so the "likely" form of the source's if
     is what the compiler has to produce.

   What is still open:
   - the frame.  Retail's is 0x110: the callee-saved GPRs s0..s5 and ra at
     0x90..0xC0, the callee-saved FPRs f20..f27 at 0xD0..0x108, and the locals in
     0x00..0x8F.  The transcription below only needs five FPRs and about 0x60 of
     locals, so it gets 0xA0.  The retail's locals are four 16-byte vectors
     (sp+0x10, sp+0x20, sp+0x30, sp+0x40) plus one at sp+0x60 and the scalars
     sp+0x00, sp+0x08, sp+0x18, sp+0x1C, sp+0x28, sp+0x2C, sp+0x38, sp+0x3C, sp+0x48,
     sp+0x49, sp+0x4A, sp+0x70, sp+0x78, sp+0x79, sp+0x7A.  Reproducing that layout
     is what buys the 0x110 frame and the eight saved FPRs.
   - the retail's prologue materialises the latch global's %hi INSIDE the save block
     (`lui $v,%hi(D_1CAE40)` between the first two saves) and copies the argument to
     $s3 with `daddu $s3,$a0,$zero`; the compiler puts both outside it here.  That
     is the "prologue insn chain" and it depends on the body that follows.
   - the 128-bit copies (`lq`/`sq` at 0x42F590, 0x430028, 0x4302C0, 0x430BE8, 0x431230)
     are the CSE tie documented in docs/COMPILER-NOTES.md; the source shape that
     keeps them is still to be found.

   THE BLOCK MAP (retail order; the labels in the source below are the same blocks).

     0x42F018  prologue: frame 0x110; s0..s5+ra saved at 0x90..0xC0, f20..f27 at
               0xD0..0x108; the latch D_L11_001CAE40 is loaded and tested
     0x42F068  the "not armed yet" path: $s1 = %hi(D_00189E20); read
               D_00189E20+0x2294; if it is not 0x6F, go to 0x42F0A4 (the delay slot
               loads s3[0xBC])
     0x42F084  the "already armed" path: s3[0x34] |= 0x41 then &= 0xEFFF; s3[0xBC]
               = 1; s3[0x98] = 0; branch straight to the epilogue
     0x42F0A4  the re-arm path: if s3[0xBC] != 0, s3[0x34] = (v & 0xFFBE) | 0x1000,
               s3[0x98] = *(u32 *)(*(u32 *)(s3+0x24) + 0x10), s3[0xBC] = 0; then
               s4 = *(u8 **)(s3+0x68)
     0x42F0D0  call func_L11_00431860(s3)
     0x42F0D8  DISPATCH 1: switch (s3[0x95]), 5 cases, table jtbl_002BAF00
     0x42F100  case 0: func_002B3890(s3); if it is non-zero, func_002B60B0 with
               (0.0022222223, 0.06666667, 0.001163553, 0.10471977) and, when
               *(f32 *)(s4+0x290) < 0.2, func_L11_0042EF90(s3,0,0,0,0xC); then, when
               *(s32 *)(s4+0x29C) != -1, func_L11_0042EF90(s3,5,4,0,0xC) and
               func_002A7750(s3,5,-1)
     0x42F1B4  the shared tail of case 0: h = *(s16 *)(s4+0x274); h != 2 branches away
     0x42F1C4  the "h == 2" path: D_00189E20+0x2294 must not be 0x6F and s4+0x2C8
               must be 0; then by s4+0x294 and s4+0x27C either
               func_L11_0042EF90(s3,6,5,0,0xA), or func_002A7750(s3,0xF,2), or
               func_L11_0042EF90(s3,2,2,0,0xA); all end at 0x42F720
     0x42F228  the "other" path: if s4+0x276 == 0 the D_L11_001FF580 / func_002A8AF0
               probe and the 0.0055555557 setup, else func_002A7750(s3,0xB,1) and
               the 0x12C timer
     0x42F288  (shared with case 2) the D_L11_001FF580 / func_002A8AF0 probe, then
               func_L11_0042EF90(s3,6,5,0,0xA)
     0x42F2CC  case 1: func_002B3890 / func_002B60B0(0.0033333334, 0.10000001,
               0.001163553, 0.10471977); then by s4+0x274 (values 1 or 2) and
               s4+0x27C / s4+0x294: func_002A7750(s3,0xF,2) with
               func_L11_0042EF90(s3,2,2,0,0xA), or func_L11_0042EF90(s3,6,5,0,0xA)
               with func_002B60B0(0.06666667, 0.5, ...) and
               func_002A7750(s3,0x11,2) and s4+0x164 = 0.0055555557
     0x42F3E4  case 1's other tail: func_002A7750(s3,1,0) and
               func_L11_0042EF90(s3,5,4,0,0xC); or func_L11_0042EF90(s3,1,1,0,0xA),
               func_002A7820(0x244,0x258), func_002A7750(s3,0xB,0xC) and
               func_L11_0042EF90(s3,4,3,0,0xC)
     0x42F414  case 2: func_002B3890 / func_002B60B0, the D_L11_001FF580 probe,
               func_L11_0042EF90(s3,6,5,0,0xA), the s3[0x20] test for 0x11/0x14/0x10/
               0x13, the 0x29C / 0x294 choice, the D_L11_001A8F20 table copy into
               s4+0x110, the 0x12C float, func_002A7820(0x4B0,0x514)
     0x42F5D8  the 0x31 check, the 0x2C4 table, func_002A7820(5,0xF),
               func_002A7470(s3,6,0,w), func_002A7750(s3,0xD,4), func_002B60B0, the
               D_L11_001B359C record test, func_002A7750(s3,4,0),
               func_L11_0042EF90(s3,4,1,0,0xF), func_002A7878(0.5,1.25) into s3+0x48
     0x42F6E8  case 4: the 0x31 check, func_002A7470(s3,6,0,0xA) unless s3[0x43] == 6,
               then func_002A7750(s3,0xF,2)
     0x42F730  case 3: func_002B1C20(s3, s4+0x60); bit 0: the D_L11_001AED04 counter,
               func_002A6C58(s3,0,3), func_L01_003E9CF8(s3,0,0), return
     0x42F77C  case 3's other bit: bit 2, the s4+0x274 test,
               func_L11_0042EF90(s3,6,5,0,0xA), func_002A7750(s3,0xF,2),
               func_002A7750(s3,0x18,-1), func_L11_0042EF90(s3,0xF,4,0,0xA); or the
               0xB / 0x244 path with func_002A7820(0x244,0x258)
     0x42F864  DISPATCH 2: switch (s3[0x20] - 1), 27 cases, table jtbl_002BAF20;
               the default and the out-of-range values go to 0x4317D0
     0x42F890  case 1: the 0.2 compare, func_00282948(s4+0x28C), func_002AA2E8 into
               s4+0x124, the s3[0x43] test, func_002A7820(0x78,0x2BC),
               func_L11_0042EF90, func_002A77E0(2), func_002AE8C0(s3,0.35,s4+0x110)
     0x42F99C  case 2: the D_L11_001B359C record at s4+0x2BC, func_002A7750(s3,3,-1),
               func_002A7470(s4+0x27C,0xB,0,0xF)
     0x42F9F4  case 3: s4+0x27C and its 0x60 flag, func_002A7750(s3,0xE,2)
     0x42FA18  case 5: D_L11_001FF580[s4+0x29C], func_002B6120,
               func_002A7750(s3,7,-1), func_L11_0042EF90(s3,4,3,0,0xA),
               func_002B6228, s4+0x2C0 = 1
     0x42FA98  case 6: the same with func_002B6228(...,1,0) and s4+0x2C0 = 0
     0x42FB14  case 7: the 0x60 flag, func_L11_0042EF90(s3,0xE,0xA,0,7),
               func_002A7750(s3,0x19,-1)
     0x42FB44  case 13: D_L11_001FF580[s4+0x2C4] and func_002B6120
     0x42FB6C  case 11: func_00282948(s4+0x28C), func_002AA2E8 with 0.0019444445,
               the s3[0x43] test, func_002A7820(0x78,0x2BC),
               func_L11_0042EF90(s3,6,5,0,0xC)
     0x42FC90  case 12: the 0x60 flag, func_L11_0042EF90(s3,5,4,0,0xC),
               func_002A7750(s3,5,-1)
     0x42FCC0  case 14: func_002A7E08(s3,0.001,0.01,0.1,s4+0x284),
               func_002A7750(s3,0x18,-1) / func_L11_0042EF90(s3,0xF,4,0,0xA), or
               func_002A7750(s3,0x13,-1) / func_L11_0042EF90(s3,7,5,0,0xA)
     0x42FD40  case 15: func_L01_00321178(s3, D_00189EA0), the s4+0x280 counter,
               func_00282E80(s3+0x10, D_00189EA0), the 20.0 and 0.17453295 tests,
               func_L11_0042EF90(s3,9,6,0,0xA), func_002A7750(s3,0x12,-1)
     0x42FDFC  case 15's other half: the 2.7 / 0.3490659 tests,
               func_L11_0042EF90(s3,0xC,0,0,5), func_002A7750(s3,0x15,-1), the 2.7
               re-test and the s3[0x42] 5 / 0xF test, func_L11_0042EF90(s3,6,5,0,4)
     0x42FEF4  case 19: func_002B60B0(0.006666667, 0.20000002, 0.001163553, 0.10471977),
               s4+0x164, func_L01_00321178, func_002A7E08, the s4+0x280 counter,
               func_00282E80, the 2.1 test, func_L11_0042EF90(s3,8,0,1,3),
               func_002A7750(s3,0x14,-1), s3+0x48 = 1.0, then the func_0029FCC0 /
               func_00283180 / func_00283198 / func_00282D30 / func_002A8C00 /
               func_00277F48 vector build
     0x4300A4  case 20: func_002B60B0(0.001163553, 0.10471977, 0.033333335, 0.004166667),
               the vector build, func_L01_00321178, the s4+0x280 counter, the 0x60
               flag, func_L11_0042EF90(s3,2,2,0,0xA), func_002A7750(s3,0x10,-1),
               func_00282E80, the 3.0 test, func_002A7470(s3+0x10,0,0xA),
               func_002A7750(s3,0x1B,-1), then the second vector build
     0x4302BC  case 27: func_002B60B0(0.001163553, 0.10471977, 0.033333335, 0.0011111111),
               func_00282F20(-5.5), func_00282CC0, func_00283248,
               func_L02_00331440(s3,...,0x10,...,-1.0), the 0x96 timer test, the
               0.00083333335 / func_L11_0042EF90 / func_002A7750 pair
     0x43041C  case 16: the 0x60 flag, 0.00083333335 into s4+0x164,
               func_002B60B0(0.0022222223, 0.06666667, ...),
               func_L11_0042EF90(s3,9,6,0,0xA), func_002A7750(s3,0x12,-1); or the
               0.10000001 variant with func_002A7750(s3,0xF,-1)
     0x4304FC  case 17: func_002B60B0(0.0033333334, 0.10000001, ...), the s4+0x294
               table, func_002B6120, func_002A7750(s3,0x18,-1),
               func_L11_0042EF90(s3,0xF,4,0,0xA), the second func_002B60B0,
               s4+0x164 = 0.00083333335, s4+0x2AC = -1, s4+0x294 = -1,
               func_002A7750(s3,0xE,2)
     0x4305E4  case 18: s4+0x27C, the s3[0x42] == 9 test, the func_0029FCC0 /
               func_00283180 / func_00283198 / func_00282CC0 vector,
               func_0029F530, the 0.05 sub, func_002A7878(0.2,f), the two
               func_002C2210 calls with D_L11_001A8F20, s4+0x288
     0x43077C  case 21: func_0029F530, the 0xC / 10.0 / 15.0 test, func_002A8D70, the
               0x60 flag, func_00282E80, the 2.7 / 0.3490659 tests,
               func_L11_0042EF90(s3,0xC,0,0,0xA), func_002A7750(s3,0x15,-1),
               func_002A7750(s3,0xF,-1), func_L11_0042EF90(s3,6,5,0,0xA)
     0x430908  case 22 (the big one): s4+0x27C, the 0x60 flag, func_00282E80, the 25.0
               test, the 0x2A0 counter, func_00283248, the 0.087266475 test,
               func_002A7750(s3,0x18,-1) / func_L11_0042EF90(s3,0xF,4,0,0xA) or
               func_L11_0042EF90(s3,9,6,0,0xA) / func_002A7750(s3,0x12,-1), the 10.0
               test, the 0x2BC test, func_L11_0042EF90(s3,3,2,0,0xA),
               func_002A7750(s3,0x17,-1), the s4+0x2A0 counter, then func_002AEB60
               (s3,3.0), the func_00282948 / func_0029FCC0 / func_00282CC0 vectors,
               the func_00282CF0 call, the func_L00_003294F0 / func_L00_002FCF18 pair,
               the D_L11_001C8A40 record update
     0x431260  case 22's tail: the 9.0 / 15.0 timer window, the s3[0x42] == 0xA test,
               the 1.6666667 / 1.3 vector build, the four func_002C2210 calls with
               D_L11_001A8F20, the func_L00_002E6CF0 registration, the
               D_L11_001C0D20 record
     0x43154C  case 22's tail 2: the 15.0 test, the 0x2BC / 0x2A0 / 0x294 test,
               func_0029F530
     0x43158C  case 23: the 0x60 flag, func_00282E80, the 25.0 test, the 0x2A0
               counter, the 0.087266475 test, func_002A7750(s3,0x18,-1) /
               func_L11_0042EF90(s3,0xF,4,0,0xA) or func_L11_0042EF90(s3,9,6,0,0xA) /
               func_002A7750(s3,0x12,-1)
     0x431660  case 24: the 0x61E0 base, func_00283248, the 0.087266475 test,
               func_L11_0042EF90(s3,9,6,0,0xA) / func_002A7750(s3,0x12,-1) or
               func_002B50E0
     0x431704  case 25: the 0x60 flag, the s4+0x2C0 test,
               func_L11_0042EF90(s3,5,4,0,0xC), func_002A7750(s3,6,-1) or
               func_002A7750(s3,5,-1)
     0x4317D0  the tail: func_L11_00431D50(s3); if *(f32 *)(s3+0x18) < 74.0:
               func_002A6C58(s3,0,3), the D_L11_001AED04 counter, func_0029F338
     0x43181C  the epilogue: restore s0..s5, ra and f20..f27

   The dN labels of the source are the second table's indices: dN is the case for
   s3[0x20] == N+1 (d0 is 0x42F890, d26 is 0x4302BC, d3 is the shared default at
   0x4317D0).  The cN labels are the first table's: c0 0x42F100, c1 0x42F2CC,
   c2 0x42F414, c3 0x42F730, c4 0x42F6E8.  The blocks between them (0x42F1B4, 0x42F1C4,
   0x42F228, 0x42F288, 0x42F3E4, 0x42F5D8) are the shared tails of case 0 and of the
   two dispatches.

   The fourth pass corrected the block map in three places: the case 14
   (0x42FCC0) and case 15 (0x42FD40) blocks are separate (they were one),
   the case 19 block (0x42FEF4) was written twice, and the second table's
   entries for the cases 23 (0x43158C), 24 (0x431660) and 25 (0x431704)
   were permuted.  The retail's order of the second dispatch's blocks is
   1, 2, 3, 5, 6, 7, 13, 11, 12, 14, 15, 19, 20, 27, 16, 17, 18, 21, 22,
   23, 24, 25, and the source's blocks are now in that order. */

extern s32 D_L11_001CAE40 __attribute__((nosda));

extern u8 D_00189E20[];

extern u8 D_00189EA0[];

extern u32 D_L11_001FF580[];

extern u8 D_L11_001C8A40[];

extern u32 D_L11_001C0D20[];

extern u8 D_L11_001A8F20[];

extern u32 D_L11_001AED04;

extern u8 *D_L11_001B359C;

extern u32 D_L11_001B359C_1 __attribute__((sda));

extern u8 *D_L11_001B368C __attribute__((sda));

extern void *jtbl_002BAF00[5];

extern void *jtbl_002BAF20[27];

extern void func_L11_00431860(u8 *a0);

extern s32 func_002B3890(u8 *a0);

extern void func_002B60B0(u8 *a0, f32 f12, f32 f13, f32 f14, f32 f15);

extern void func_002A7750(u8 *a0, u32 a1, s32 a2);

extern s32 func_002A7820(s32 a0, s32 a1);

extern s32 func_002A77E0(s32 a0);

extern f32 func_002A7878(f32 a0, f32 a1);

extern void func_002A7470(u8 *a0, u32 a1, u32 a2, u32 a3);

extern s32 func_002A8AF0(u8 *a0, u8 *a1, s32 a2);

extern void func_002A7E08(u8 *a0, u32 a1, u32 a2, f32 f12, f32 f13, f32 f14);

extern void func_002AA2E8(f32 *a0, f32 a1, f32 a2);

extern void func_002AE8C0(u8 *a0, f32 f12, u8 *a1);

extern void func_L01_00321178(u8 *a0, u8 *a1);

extern f32 func_00282E80(u8 *a0, u8 *a1);

extern void func_00283248(f32 f12, f32 f13);

extern f32 func_00283C80(f32 f12);

extern void func_00282948(u8 *a0);

extern f32 func_00283180(f32 f12);

extern f32 func_00283198(f32 f12);

extern void func_00282D30(f32 *a0, f32 *a1);

extern void func_002A8C00(f32 *a0, u8 *a1, u32 a2, u32 a3, f32 f12);

extern void func_00277F48(f32 *a0, u32 a1, u8 *a2);

extern void func_00282F20(f32 *a0, f32 *a1, f32 f12);


extern int func_L02_00331440(void *a0, void *a1, int a2, f32 f12, f32 f13, f32 f14);

extern void func_00282E80_1(f32 *a0, u8 *a1);

extern s32 func_002B6120(u8 *a0, u8 *a1);

extern void func_002B6228(u8 *a0, u8 *a1, u32 a2, u32 a3);

extern void func_L00_003294F0(u8 *a0, u32 a1);

extern s32 func_L00_002FCF18(u8 *a0, f32 f12, f32 f13, f32 f14, f32 f15, f32 f16);

extern void func_00291450(u32 *a0);

extern f32 func_0029F530(u8 *a0);

extern void func_002C2210(void *a0, u32 a1, u32 a2, u32 a3, s32 a4, s32 a5, s32 a6,
                          f32 f7, f32 f8, f32 f9);

extern s32 func_002B38B8(u8 *a0);

extern s32 func_002761F8(u8 *a0, u8 *a1, u8 *a2, u8 *a3, u8 *a4);

extern void func_L00_002E6CF0(void *a0, u8 *a1);

extern void func_0029F338(u8 *a0, u32 a1);

extern void func_002A6C58(u8 *a0, u32 a1, u32 a2);

extern void func_002B50E0(u8 *a0, u8 *a1, f32 a2);

extern s32 func_002AEB60(u8 *a0, f32 f12);

extern void func_L11_00432628(u8 *a0, u8 *a1);

extern s32 func_L04_003E5830(u8 *a0, u32 a1);

extern void func_L11_00431E30(u8 *a0);

extern s32 func_002B1C20(u8 *a0, u8 *a1);

extern void func_0029FCC0(u32 a0, s32 a1, f32 *a2);

extern void func_00282CF0(f32 *a0, u8 *a1, u8 *a2);

extern void func_002A6C58(u8 *a0, u32 a1, u32 a2);

extern void func_002A8D70(u8 *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5,
                          f32 f6, f32 f7, f32 f8);

typedef int TI128 __attribute__((mode(TI)));

/* The base of the block at 0x183CC0: the catalogue has no symbol for it (the
   boot's symbols jump from D_00188714 to D_00189E00), so it is spelled as the
   difference from D_00189EA0, which is how the retail computes it. */
#define L183CC0 ((u8 *)0x183CC0)

typedef struct {
    u8 pad80[0x80];
    f32 x;
    f32 y;
    u8 pad88[0x2290 - 0x88];
    u32 f2290;
    s32 f2294;
} Actor;

/* The object's per-frame update: a latch test, a five-way dispatch on the byte at 0x95
   and a twenty-seven-way dispatch on the byte at 0x20. */
void func_L11_0042F018(u8 *a0) {
    u8 *s3 = a0;
    u8 *s4;
    u8 *s1;
    u8 *p;
    u8 *s0;
    u8 *s2;
    u8 *s5;
    u32 v;
    u32 w;
    s32 w1;
    u32 w2;
    u32 w3;
    u32 w4;
    u32 w5;
    u32 w6;
    u32 w7;
    u32 w8;
    u32 w9;
    u8 vb20;
    u32 idx;
    u16 hv;
    s32 ei;
    s32 vi;
    s32 va;
    u32 rec;
    u8 vb;
    s16 h;
    u16 h2;
    u16 h3;
    u32 p2;
    u32 p3;
    u8 *q;
    u8 *pa;
    u32 pb;
    u32 pc;
    u8 *pd;
    u8 *hp;
    u8 *qd;
    f32 fz;
    f32 f;
    f32 f20;
    f32 f21;
    f32 f22;
    f32 f23;
    f32 f24;
    f32 f25;
    f32 f26;
    f32 f27;
    f32 f3;
    f32 fw;
    f32 fw2;
    struct { f32 x; f32 y; f32 z; } st0;
    f32 vec[4];
    f32 vec2[4];
    f32 vec3[4];
    f32 vec7[4];
    f32 vec4[4];
    f32 vec5[4];
    struct { f32 x; f32 y; struct { u8 a; u8 b; u16 c; } s; } st2;
    f32 vec6[4];
    static void * volatile tab1[] = { &&c0, &&c1, &&c2, &&c3, &&c4 };
    static void * volatile tab2[] = {
        &&d0, &&d1, &&d2, &&d3, &&d4, &&d5, &&d6, &&d3, &&d3, &&d3,
        &&d10, &&d11, &&d12, &&d13, &&d13b, &&d15, &&d16, &&d17, &&d18, &&d19,
        &&d20, &&d21, &&d24, &&d23, &&d22, &&d3, &&d26
    };

    /* The latch and the "not armed yet" flag both lead to the arming block; the
       re-arm block falls through into the update. */
    if (D_L11_001CAE40 != 0)
        goto Larmed;
    if (((Actor *)D_00189E20)->f2294 != 0x6F)
        goto Lrearm;
Larmed:
    h2 = *(u16 *)(s3 + 0x34);
    s3[0xBC] = 1;
    h2 |= 0x41;
    *(u32 *)(s3 + 0x98) = 0;
    h2 &= 0xEFFF;
    *(u16 *)(s3 + 0x34) = h2;
    return;
Lrearm:
    if (s3[0xBC] != 0) {
        h3 = *(u16 *)(s3 + 0x34);
        p2 = *(u32 *)(s3 + 0x24);
        h3 = (h3 & 0xFFBE) | 0x1000;
        *(u16 *)(s3 + 0x34) = h3;
        p3 = *(u32 *)(p2 + 0x10);
        s3[0xBC] = 0;
        *(u32 *)(s3 + 0x98) = p3;
    }
    s4 = *(u8 **)(s3 + 0x68);
    func_L11_00431860(s3);

    idx = s3[0x95];
    if (idx >= 5)
        goto Lsel2;
    goto *jtbl_002BAF00[idx];

c0:
    if (func_002B3890(s3) != 0) {
        func_002B60B0(s3, 0.0022222223f, 0.06666667f, 0.001163553f, 0.10471977f);
        if (*(f32 *)(s4 + 0x290) < 0.2f)
            func_L11_0042EF90(s3, 0, 0, 0, 0xC);
        if (*(s32 *)(s4 + 0x29C) != -1) {
            func_L11_0042EF90(s3, 5, 4, 0, 0xC);
            func_002A7750(s3, 5, -1);
        }
    }
    h = *(s16 *)(s4 + 0x274);
    if (h != 2)
        goto Lother;
    if (((Actor *)D_00189E20)->f2294 == 0x6F)
        goto Lother;
    if (*(s32 *)(s4 + 0x2C8) != 0)
        goto Lother;
    if (*(s32 *)(s4 + 0x294) != -1)
        goto L65;
    if (*(u32 *)(s4 + 0x27C) == 0) {
        func_L11_0042EF90(s3, 2, 2, 0, 0xA);
        goto L720;
    }
    goto L720;

Lother:
    if (*(s16 *)(s4 + 0x276) == 0)
        goto Lprobe;
    func_002A7750(s3, 0xB, 1);
    if (*(s16 *)(s4 + 0x270) < 0x12C) {
        *(s16 *)(s4 + 0x276) = 0;
        *(u16 *)(s4 + 0x270) = func_002A7820(0x1E0, 0x258);
    }
    if (*(s32 *)(s4 + 0x29C) == -1)
        goto Lsel2;
    func_002A7750(s3, 0xB, 0xC);
    func_L11_0042EF90(s3, 4, 3, 0, 0xC);
    goto Lsel2;

Lprobe:
    idx = *(s32 *)(s4 + 0x2AC);
    if (idx == -1)
        goto Lsel2;
    pc = D_L11_001FF580[idx];
    if (func_002A8AF0(D_00189EA0, (u8 *)pc + 0x10, *(u32 *)pc) == 0)
        goto Lsel2;
    goto L65;
    func_002A7750(s3, 0xB, 0xC);
    func_L11_0042EF90(s3, 4, 3, 0, 0xC);
    goto Lsel2;

c1:
    if (func_002B3890(s3) != 0)
        func_002B60B0(s3, 0.0033333334f, 0.10000001f, 0.001163553f, 0.10471977f);
    hv = *(u16 *)(s4 + 0x274);
    if ((u32)(hv - 1) >= 2)
        goto Lc1other;
    if (*(u32 *)(s4 + 0x27C) != 0) {
        goto L720;
    }
    if (*(s32 *)(s4 + 0x294) == -1) {
        goto L294;
    }
    goto L65;

L65:
    func_L11_0042EF90(s3, 6, 5, 0, 0xA);
    func_002B60B0(s3, 0.016666667f, 0.5f, 0.001163553f, 0.10471977f);
    f = 0.0055555557f;
    func_002A7750(s3, 0x11, 2);
    *(f32 *)(s4 + 0x164) = f;
    goto Lsel2;

L294:
    func_L11_0042EF90(s3, 2, 2, 0, 0xA);
    goto L720;

Lc1other:
    if (*(s16 *)(s4 + 0x270) == 0) {
        func_002A7750(s3, 1, 0);
        func_L11_0042EF90(s3, 5, 4, 0, 0xC);
    }
    goto Lsel2;

c2:
    if (func_002B3890(s3) != 0)
        func_002B60B0(s3, 0.0033333334f, 0.10000001f, 0.001163553f, 0.10471977f);
    w1 = *(s32 *)(s4 + 0x2AC);
    if (w1 == -1)
        goto L498;
    pb = D_L11_001FF580[w1];
    if (func_002A8AF0(D_00189EA0, (u8 *)pb + 0x10, *(u32 *)pb) != 0)
        goto Lsel2;
L498:
    if ((u32)(*(u16 *)(s4 + 0x274) - 1) < 2)
        goto L5d8;
    vb20 = s3[0x20];
    if (vb20 == 0x11 || vb20 == 0x14 || vb20 == 0x10)
        goto L5d8;
    if (vb20 == 0x13) {
        func_L11_0042EF90(s3, 8, 0, 1, 3);
        func_002A7750(s3, 0x14, -1);
        goto L5d8;
    }
    if (*(s32 *)(s4 + 0x29C) == -1) {
        *(s32 *)(s4 + 0x2A0) = 0;
        goto L548;
    }
    if (*(s32 *)(s4 + 0x294) != -1) {
        *(s32 *)(s4 + 0x2A0) = 0;
        goto L548;
    }
    func_L11_0042EF90(s3, 5, 4, 0, 0xC);
    func_002A7750(s3, 5, 1);
    goto L5d8;
L548:
    func_L11_0042EF90(s3, 3, 1, 0, 0xC);
    func_002A7750(s3, 0xB, 1);
    w1 = *(s32 *)(s4 + 0x2A4);
    if (w1 != -1) {
        *(TI128 *)(s4 + 0x110) = *(TI128 *)(D_L11_001B368C + w1 * 0x80 + 0x30);
        if (*(f32 *)(s4 + 0x12C) == 0.0f)
            *(f32 *)(s4 + 0x12C) = 4.0f;
    }    *(u16 *)(s4 + 0x270) = func_002A7820(0x4B0, 0x514);
L5d8:
    if (((Actor *)D_00189E20)->f2294 != 0x31) {
        pc = *(s32 *)(s4 + 0x2C4);
        if (pc != -1) {
            if (s3[0x43] == 6) {
                w2 = func_002A7820(5, 0xF);
                func_002A7470(s3, 6, 0, w2);
                func_002A7750(s3, 0xD, 4);
                func_002B60B0(s3, 0.0033333334f, 0.10000001f, 0.0033936962f, 0.26179942f);
            } else {
                func_002A7750(s3, 0xD, 4);
                func_002B60B0(s3, 0.0033333334f, 0.10000001f, 0.0033936962f, 0.26179942f);
            }
        }
    }
    w8 = *(s32 *)(s4 + 0x2BC);
    if (w8 == -1)
        goto Lsel2;
    if (*(s16 *)(s4 + 0x274) == 2)
        goto Lsel2;
    if (*(u32 *)(s4 + 0x27C) == 0)
        goto Lsel2;
    w3 = *(u32 *)D_L11_001B359C_1;
    w3 = w3 + w8 * 0x100;
    if (((u8 *)w3)[0x20] == 2)
        goto Lsel2;
    func_002A7750(s3, 4, 0);
    func_L11_0042EF90(s3, 4, 1, 0, 0xF);
    f = func_002A7878(0.5f, 1.25f);
    *(f32 *)(s3 + 0x48) = f;
    goto Lsel2;

c4:
    if (((Actor *)D_00189E20)->f2294 != 0x31) {
        if (s3[0x43] != 6)
            func_002A7470(s3, 6, 0, 0xA);
        func_002A7750(s3, 0xF, 2);
    }
    goto Lsel2;

L720:
    func_002A7750(s3, 0xE, 2);
    goto Lsel2;

c3:
    w9 = func_002B1C20(s3, s4 + 0x60);
    if (w9 & 1) {
        func_002A6C58(s3, 0, 3);
        D_L11_001AED04 = D_L11_001AED04 - 1;
        func_L01_003E9CF8(s3, 0, 0);
        goto Lret;
    }
    if (w9 & 2) {
        if (*(u16 *)(s4 + 0x274) - 1 < 2) {
            func_L11_0042EF90(s3, 6, 5, 0, 0xA);
            func_002A7750(s3, 0xF, 2);
            if (*(s32 *)(s4 + 0x2BC) == -1)
                goto Lsel2;
            func_002A7750(s3, 0x18, -1);
            func_L11_0042EF90(s3, 0xF, 4, 0, 0xA);
            goto Lsel2;
        }
        func_002A7750(s3, 0xB, 1);
        func_L11_0042EF90(s3, 1, 1, 0, 0xA);
        func_002A7820(0x244, 0x258);
        if (*(s32 *)(s4 + 0x29C) == -1)
            goto Lsel2;
        *(u16 *)(s4 + 0x270) = func_002A7820(0x244, 0x258);
        func_002A7750(s3, 0xB, 0xC);
        func_L11_0042EF90(s3, 4, 3, 0, 0xC);
        goto Lsel2;
    }
    goto Lsel2;

Lsel2:
    idx = s3[0x20];
    idx = idx - 1;
    if ((u32)idx >= 27)
        goto Lend;
    goto *jtbl_002BAF20[idx];

d0:
    if (0.2f < *(f32 *)(s4 + 0x290)) {
        func_00282948(s4 + 0x28C);
        if (*(s32 *)(s4 + 0x28C) < 0x15)
            func_002AA2E8((f32 *)(s4 + 0x124), 0.0f, 0.0011111111f);
        else
            *(f32 *)(s4 + 0x124) = 0.06666667f;
        if (s3[0x43] != 5 && s3[0x43] < 2) {
            if (*(s32 *)(s4 + 0x28C) == 0) {
                func_L11_0042EF90(s3, 1, 1, 0, 0xC);
                if (func_002A77E0(2) == 1)
                    func_L11_0042EF90(s3, 0, 0, 0, 0xC);
            }
        } else if ((s3[0x43] & 2) != 0) {
            *(s32 *)(s4 + 0x28C) = func_002A7820(0x78, 0x2BC);
            func_L11_0042EF90(s3, 5, 4, 0, 0xC);
        }
    } else {
        w4 = *(u32 *)(s4 + 0x27C);
        if (w4 == 0)
            goto Lend;
        if (((u8 *)w4)[0x43] == 0)
            goto Lend;
        func_L11_0042EF90(s3, 0, 0, 0, 0xC);
    }
    goto Lend;

d1:
    v = *(s32 *)(s4 + 0x2BC);
    w5 = *(u32 *)D_L11_001B359C;
    w5 = w5 + v * 0x100;
    if (((u8 *)w5)[0x20] != 2)
        goto Lend;
    if (*(u32 *)(s4 + 0x27C) == 0)
        goto Lend;
    func_002A7750(s3, 3, -1);
    w6 = *(u32 *)(s4 + 0x27C);
    func_002A7470(w6, 0xB, 0, 0xF);
    goto Lend;

d2:
    idx = *(u32 *)(s4 + 0x27C);
    if (idx == 0)
        goto Lend;
    if (((idx >> 8) & 2) != 0) {
        func_002A7750(s3, 0xE, 2);
        goto Lend;
    }
    func_002A7750(s3, 0xE, 2);
    goto Lend;

d4:
    v = *(s32 *)(s4 + 0x29C);
    if (v == -1)
        goto Lend;
    v = D_L11_001FF580[v];
    if (func_002B6120(s3, (u8 *)*(u32 *)v) == 0)
        goto Lend;
    func_002A7750(s3, 7, -1);
    func_L11_0042EF90(s3, 4, 3, 0, 0xA);
    v = *(s32 *)(s4 + 0x29C);
    func_002B6228(s3, *(u8 **)(D_L11_001FF580 + v * 4), 0, 1);
    *(s32 *)(s4 + 0x2C0) = 1;
    goto Lend;

d5:
    v = *(s32 *)(s4 + 0x29C);
    if (v == -1)
        goto Lend;
    v = D_L11_001FF580[v];
    if (func_002B6120(s3, (u8 *)*(u32 *)v) == 0)
        goto Lend;
    func_002A7750(s3, 7, -1);
    func_L11_0042EF90(s3, 4, 3, 0, 0xA);
    v = *(s32 *)(s4 + 0x29C);
    func_002B6228(s3, *(u8 **)(D_L11_001FF580 + v * 4), 1, 0);
    *(s32 *)(s4 + 0x2C0) = 0;
    goto Lend;

d6:
    if ((s3[0x60] & 2) == 0)
        goto Lend;
    func_L11_0042EF90(s3, 0xE, 0xA, 0, 7);
    func_002A7750(s3, 0x19, -1);
    goto Lend;

d12:
    v = *(s32 *)(s4 + 0x2C4);
    func_002B6120(s3, *(u8 **)(D_L11_001FF580 + v * 4));
    goto Lend;

d10:
    func_00282948(s4 + 0x28C);
    if (*(s32 *)(s4 + 0x28C) < 0x15)
        func_002AA2E8((f32 *)(s4 + 0x124), 0.06666667f, 0.0019444445f);
    else
        func_002AA2E8((f32 *)(s4 + 0x124), 0.0f, 0.0019444445f);
    if (s3[0x43] == 6) {
        if (*(s32 *)(s4 + 0x28C) == 0) {
            func_L11_0042EF90(s3, 3, 2, 0, 0xC);
            if (func_002A77E0(2) == 1)
                func_L11_0042EF90(s3, 4, 3, 0, 0xC);
        }
    } else if ((s3[0x43] & 0xFF) < 2) {
        if ((s3[0x60] & 2) != 0) {
            *(s32 *)(s4 + 0x28C) = func_002A7820(0x78, 0x2BC);
            func_L11_0042EF90(s3, 6, 5, 0, 0xC);
        }
    }
    goto Lend;

d11:
    if ((s3[0x60] & 2) == 0)
        goto Lend;
    func_L11_0042EF90(s3, 5, 4, 0, 0xC);
    func_002A7750(s3, 5, -1);
    goto Lend;

d13:
    func_002A7E08(s3, ((Actor *)D_00189E20)->f2290, s4 + 0x284, 0.001f, 0.01f, 0.1f);
    if (*(u32 *)(s4 + 0x27C) != 0) {
        func_002A7750(s3, 0x18, -1);
        func_L11_0042EF90(s3, 0xF, 4, 0, 0xA);
        goto Lend;
    }
    if (*(s32 *)(s4 + 0x2A8) != 0) {
        func_002A7750(s3, 0x13, -1);
        func_L11_0042EF90(s3, 7, 5, 0, 0xA);
        goto Lend;
    }
    func_002A7750(s3, 0xF, -1);
    func_L11_0042EF90(s3, 6, 5, 0, 0xA);
    goto Lend;

d13b:
    hp = D_00189EA0;
    func_L11_00432628(s3, hp);
    *(s32 *)(s4 + 0x280) = *(s32 *)(s4 + 0x280) + 1;
    if (*(u32 *)(s4 + 0x27C) != 0) {
        fz = func_00282E80(s3 + 0x10, hp);
        if (fz < 20.0f) {
            qd = (u8 *)hp - 0x80;
            func_00283248(*(f32 *)(qd + 0x80) - *(f32 *)(s3 + 0x10),
                          *(f32 *)(qd + 0x84) - *(f32 *)(s3 + 0x14));
            if (func_00283C80(*(f32 *)(s3 + 0xF8)) < 0.17453295f) {
                func_L11_0042EF90(s3, 9, 6, 0, 0xA);
                func_002A7750(s3, 0x12, -1);
            }
        }
    } else {
        s0 = s3 + 0x10;
        fz = func_00282E80(s0, hp);
        if (fz < 2.7f) {
            qd = (u8 *)hp - 0x80;
            func_00283248(*(f32 *)(qd + 0x80) - *(f32 *)(s3 + 0x10),
                          *(f32 *)(qd + 0x84) - *(f32 *)(s3 + 0x14));
            if (func_00283C80(*(f32 *)(s3 + 0xF8)) < 0.3490659f) {
                func_L11_0042EF90(s3, 0xC, 0, 0, 5);
                func_002A7750(s3, 0x15, -1);
            }
        }
        fz = func_00282E80(s0, hp);
        if (2.7f < fz) {
            v = s3[0x42];
            if (v == 5 || v == 0xF) {
                func_L11_0042EF90(s3, 6, 5, 0, 0x4);
            }
        }
    }
    goto Lend;

d18:
    f = 0.0069444445f;
    func_002B60B0(s3, 0.006666667f, 0.20000002f, 0.001163553f, 0.10471977f);
    *(f32 *)(s4 + 0x164) = f;
    s0 = D_00189EA0;
    func_L01_00321178(s3, s0);
    func_002A7E08(s3, *(u32 *)(s0 + 0x2210), s4 + 0x284, 0.001f, 0.01f, 0.1f);
    *(s32 *)(s4 + 0x280) = *(s32 *)(s4 + 0x280) + 1;
    fz = func_00282E80(s3 + 0x10, s0);
    if (fz < 2.1f) {
        func_L11_0042EF90(s3, 8, 0, 1, 3);
        f = 1.0f;
        func_002A7750(s3, 0x14, -1);
        *(f32 *)(s3 + 0x48) = f;
    }
    func_0029FCC0((u32)s3, 1, &vec[0]);
    f = func_00283180(*(f32 *)(s3 + 0xF8));
    f = func_00283198(*(f32 *)(s3 + 0xF8));
    vec[0] = f;
    vec[1] = 2.0f;
    vec[2] = f;
    vec[3] = 2.0f;
    func_00282D30(&vec[0], &vec[0]);
    f = 5627.925f;
    vec2[0] = f;
    func_002A8C00(&vec2[0], s3, 0x10001, (u32)&vec[0], *(f32 *)(s4 + 0x2B8));
    vec2[1] = 1.3f;
    vec2[2] = 1;
    vec2[3] = *(u16 *)(s3 + 0xAA);
    func_00277F48(&vec2[0], 0, s3);
    goto Lend;

d19:
    func_002B60B0(s3, 0.004166667f, 0.033333335f, 0.001163553f, 0.10471977f);
    s0 = s3 + 0x10;
    st0.x = func_00283180(*(f32 *)(s3 + 0xF8)) * 4.0f;
    st0.y = func_00283198(*(f32 *)(s3 + 0xF8)) * 4.0f;
    st0.z = 0;
    func_00282CC0(&st0.x, s3 + 0x10, &st0.x);
    func_L01_00321178(s3, D_00189EA0);
    v = *(s32 *)(s4 + 0x280) + 1;
    *(s32 *)(s4 + 0x280) = v;
    if ((s3[0x60] & 2) != 0) {
        func_L11_0042EF90(s3, 2, 2, 0, 0xA);
        func_002A7750(s3, 0x10, -1);
        func_00282E80(s0, D_00189EA0);
        if (func_00283C80(*(f32 *)(s3 + 0xF8)) < 3.0f) {
            func_002B60B0(s3, 0.0022222223f, 0.06666667f, 0.001163553f, 0.10471977f);
            if (s3[0x43] != 0x10)
                func_002A7470(s3, 0x10, 0, 0xA);
            func_002A7750(s3, 0x1B, -1);
        }
    }
    func_0029FCC0((u32)s3, 1, &vec[0]);
    f = func_00283180(*(f32 *)(s3 + 0xF8));
    f = func_00283198(*(f32 *)(s3 + 0xF8));
    vec3[0] = f;
    vec3[1] = f;
    vec3[2] = 2.0f;
    vec2[0] = vec3[0];
    vec2[1] = vec3[1];
    vec2[2] = vec3[2];
    f = 5627.925f;
    vec2[3] = f;
    func_00282D30(&vec2[0], &vec2[0]);
    f = 5627.925f;
    vec5[0] = f;
    func_002A8C00(&vec5[0], s3, 0x10001, (u32)&vec2[0], *(f32 *)(s4 + 0x2B8));
    vec5[1] = 1.3f;
    vec5[2] = 1;
    vec5[3] = *(u16 *)(s3 + 0xAA);
    st2.s.a = 0;
    st2.s.b = 1;
    st2.s.c = *(u16 *)(s3 + 0xAA);
    func_00277F48(&vec[0], 0, s3);
    goto Lend;

d26:
    func_002B60B0(s3, 0.0011111111f, 0.033333335f, 0.001163553f, 0.10471977f);
    func_00282F20(&vec[0], s3 + 0xC0, -5.5f);
    func_00282CC0(&vec[0], &vec[0], s3 + 0x10);
    func_00283248(vec[0] - *(f32 *)(s3 + 0x10), vec[1] - *(f32 *)(s3 + 0x14));
    func_L02_00331440(s3, (u8 *)&vec[0], 0x10, vec[0], -1.0f, -1.0f);
    if (*(u16 *)(s3 + 0x96) < 0x79)
        goto Lend;
    *(f32 *)(s4 + 0x164) = 0.00083333335f;
    if (*(u32 *)(s4 + 0x27C) == 0)
        goto Ld26else;
    func_002B60B0(s3, 0.0022222223f, 0.06666667f, 0.001163553f, 0.10471977f);
    func_L11_0042EF90(s3, 9, 6, 0, 0xA);
    func_002A7750(s3, 0x12, -1);
    goto Lend;
Ld26else:
    func_002B60B0(s3, 0.0033333334f, 0.10000001f, 0.001163553f, 0.10471977f);
    func_L11_0042EF90(s3, 6, 5, 0, 0xA);
    func_002A7750(s3, 0xF, -1);
    goto Lend;

d15:
    if ((s3[0x60] & 2) == 0)
        goto Lend;
    *(f32 *)(s4 + 0x164) = 0.00083333335f;
    if (*(u32 *)(s4 + 0x27C) == 0)
        goto Ld15else;
    func_002B60B0(s3, 0.0022222223f, 0.06666667f, 0.001163553f, 0.10471977f);
    func_L11_0042EF90(s3, 9, 6, 0, 0xA);
    func_002A7750(s3, 0x12, -1);
    goto Lend;
Ld15else:
    func_002B60B0(s3, 0.0033333334f, 0.10000001f, 0.001163553f, 0.10471977f);
    func_L11_0042EF90(s3, 6, 5, 0, 0xA);
    func_002A7750(s3, 0xF, -1);
    goto Lend;

d16:
    func_002B60B0(s3, 0.0033333334f, 0.10000001f, 0.001163553f, 0.10471977f);
    v = *(s32 *)(s4 + 0x294);
    if (func_002B6120(s3, *(u8 **)(D_L11_001FF580 + v * 4)) == 0)
        goto Lend;
    func_002A7750(s3, 0x18, -1);
    func_L11_0042EF90(s3, 0xF, 4, 0, 0xA);
    func_002B60B0(s3, 0.0033333334f, 0.10000001f, 0.001163553f, 0.10471977f);
    f = 0.00083333335f;
    *(f32 *)(s4 + 0x164) = f;
    *(s32 *)(s4 + 0x2AC) = -1;
    if (*(u32 *)(s4 + 0x27C) == 0)
        *(s32 *)(s4 + 0x294) = -1;
    else
        func_002A7750(s3, 0xE, 2);
    goto Lend;

d17:
    w7 = *(u32 *)(s4 + 0x27C);
    if (w7 == 0)
        goto L74c;
    if (s3[0x42] != 9) {
        v = *(u32 *)(w7 + 0x68);
        func_0029FCC0((u32)*(u8 **)(v + 0x278), 0, &vec[0]);
        f = func_00283180(*(f32 *)(s3 + 0xF8));
        f = f * 0.1f;
        f = func_00283198(*(f32 *)(s3 + 0xF8));
        f = f * 0.1f;
        vec[0] = f;
        vec[1] = f;
        vec[2] = 0.0f;
        vec[3] = 0.0f;
        func_00282CC0(&vec[0], &vec[0], &vec[0]);
        f = vec[2] - 0.05f;
        *(f32 *)(s3 + 0x8) = f;
        f = func_0029F530(s3);
        f = f - 0.05f;
        *(f32 *)(s3 + 0x8) = f;
        f = func_002A7878(0.2f, f);
        f = f * f;
        f = f * 0.3f;
        v = func_002A77E0(2);
        if (v == 0)
            v--;
        func_002C2210(&vec[0], 2, 0x804020FF, 0, v, (s32)D_L11_001A8F20, 0, f * 0.3f, f, 0.0f);
        func_002C2210(&vec[0], 2, 0x7F6F6FFF, 1, -v, (s32)D_L11_001A8F20, 0, f * 0.04f, f * 0.4f, 0.0f);
        *(f32 *)(s4 + 0x288) = f;
    }
L74c:
    if ((s3[0x60] & 2) == 0)
        goto Lend;
    func_L11_0042EF90(s3, 0xA, 7, 0, 0xA);
    func_002A7750(s3, 0x16, -1);
    goto Lend;

d20:
    f = func_0029F530(s3);
    if (s3[0x42] == 0xC && f >= 10.0f && f <= 15.0f)
        func_002A8D70(s3, 1, 1, 0, 1, 0, 1.0f, *(f32 *)(s4 + 0x2B4), 1.0f);
    if ((s3[0x60] & 2) == 0)
        goto Lend;
    s0 = D_00189EA0;
    func_00282E80(s3 + 0x10, s0);
    if (func_00283C80(*(f32 *)(s3 + 0xF8)) < 2.7f) {
        func_00283248(*(f32 *)(s3 + 0x10) - *(f32 *)(D_00189EA0 + 0x80),
                      *(f32 *)(D_00189EA0 + 0x84) - *(f32 *)(s3 + 0x14));
        if (func_00283C80(*(f32 *)(s3 + 0xF8)) < 0.3490659f) {
            func_L11_0042EF90(s3, 0xC, 0, 0, 0xA);
            func_002A7750(s3, 0x15, -1);
        }
    }
    func_002A7750(s3, 0xF, -1);
    func_L11_0042EF90(s3, 6, 5, 0, 0xA);
    goto Lend;

d21:
    /* 0x430908: the "case 22" block: the latch on the other object, the 0x60 flag,
       the two distance windows, the two effect vectors and the timer window. */
    if (*(u32 *)(s4 + 0x27C) == 0) {
        func_002A7750(s3, 0xF, -1);
        func_L11_0042EF90(s3, 6, 5, 0, 0xA);
    }
    if ((s3[0x60] & 2) != 0) {
        s0 = s3 + 0x10;
        s1 = D_00189EA0;
        if (func_00282E80(s0, D_00189EA0) < 25.0f) {
            if (*(u32 *)(s4 + 0x27C) != 0 && *(s32 *)(s4 + 0x2A0) < 3) {
                q = (u8 *)s1 - 0x80;
                func_00283248(*(f32 *)(q + 0x80) - *(f32 *)(s3 + 0x10),
                              *(f32 *)(q + 0x84) - *(f32 *)(s3 + 0x14));
                if (0.087266475f < func_00283C80(*(f32 *)(s3 + 0xF8))) {
                    func_002A7750(s3, 0x18, -1);
                    func_L11_0042EF90(s3, 0xF, 4, 0, 0xA);
                } else {
                    func_L11_0042EF90(s3, 9, 6, 0, 0xA);
                    func_002A7750(s3, 0x12, -1);
                }
                goto Lad8;
            }
        }
        f = func_00282E80(s0, D_00189EA0);
        if (10.0f < f) {
            if (*(u32 *)(s4 + 0x27C) != 0 && *(s32 *)(s4 + 0x2A0) >= 3
                && *(s32 *)(s4 + 0x2BC) == -1) {
                func_L11_0042EF90(s3, 3, 2, 0, 0xA);
                func_002A7750(s3, 0x17, -1);
                *(s32 *)(s4 + 0x2A0) = 0;
                goto Lad4;
            }
        }
        func_002A7750(s3, 0x18, -1);
        func_L11_0042EF90(s3, 0xF, 4, 0, 0xA);
    Lad4:
    Lad8:
        if (*(u32 *)(s4 + 0x27C) == 0)
            goto Lcase22end;
        *(s32 *)(s4 + 0x2A0) = *(s32 *)(s4 + 0x2A0) + 1;
    } else {
        /* 0x430AF0: the flag is not set: the other object builds the effect. */
        if (func_002AEB60(s3, 3.0f) == 0)
            goto Ltail22;
        if (*(u32 *)(s4 + 0x27C) == 0)
            goto Ltail22;
        q = (u8 *)s1 - 0x61E0;
        func_00283248(*(f32 *)(q + 0x80) - *(f32 *)(s3 + 0x10),
                      *(f32 *)(q + 0x84) - *(f32 *)(s3 + 0x14));
        if (func_00283C80(*(f32 *)(s3 + 0xF8)) < 0.78539824f) {
            /* 0x430B58: the small angle: one vector, then the record. */
            func_0029FCC0((u32)*(u8 **)(*(u32 *)(*(u32 *)(s4 + 0x27C) + 0x68) + 0x278), 0, &st0.x);
            vec[0] = func_00283180(*(f32 *)(s3 + 0xF8)) * 0.1f;
            vec[1] = func_00283198(*(f32 *)(s3 + 0xF8)) * 0.1f;
            vec[2] = 0.0f;
            func_00282CC0(&st0.x, &st0.x, &vec[0]);
            st0.z = st0.z - 0.05f;
            *(TI128 *)(s4 + 0x230) = *(TI128 *)&st0;
            func_00282CF0(s4 + 0x250, L183CC0 + 0xD0, &st0.x);
            *(f32 *)(s4 + 0x298) = 0.0f;
            func_L00_003294F0(s3, 0);
            vi = func_L00_002FCF18(s3 + 0x10, 5.0f, 0.0f, 1.0f, 0.0f, 0.0f);
            *(s32 *)(s4 + 0x2B0) = vi;
            if (vi < 0)
                goto Ltail22;
            rec = (u32)(D_L11_001C8A40 + vi * 0x20);
            *(TI128 *)(rec + 0x10) = *(TI128 *)(s4 + 0x230);
            *(f32 *)(rec + 0x0C) = 0.0f;
            *(f32 *)(rec + 0x1C) = 5.0f;
            *(f32 *)(rec + 0x00) = 1.0f;
            *(f32 *)(rec + 0x04) = 0.0f;
            *(f32 *)(rec + 0x18) = *(f32 *)(rec + 0x18) + 1.0f;
            *(f32 *)(rec + 0x08) = 0.0f;
        } else {
            /* 0x430C70: the wide angle: two vectors, no record. */
            func_0029FCC0((u32)*(u8 **)(*(u32 *)(*(u32 *)(s4 + 0x27C) + 0x68) + 0x278), 0, &st0.x);
            vec[0] = func_00283180(*(f32 *)(s3 + 0xF8)) * 0.1f;
            vec[1] = func_00283198(*(f32 *)(s3 + 0xF8)) * 0.1f;
            vec[2] = 0.0f;
            func_00282CC0(&st0.x, &st0.x, &vec[0]);
            st0.z = st0.z - 0.05f;
            *(TI128 *)(s4 + 0x230) = *(TI128 *)&st0;
            vec[0] = func_00283180(*(f32 *)(s3 + 0xF8)) * 25.0f;
            vec[1] = func_00283198(*(f32 *)(s3 + 0xF8)) * 25.0f;
            vec[2] = 0.0f;
            func_00282CC0(&vec[0], &vec[0], s3 + 0x10);
            func_00282CF0(s4 + 0x250, &vec[0], &st0.x);
            *(f32 *)(s4 + 0x298) = 0.0f;
            func_L00_003294F0(s3, 0);
            vi = func_L00_002FCF18(s3 + 0x10, 5.0f, 0.0f, 1.0f, 0.0f, 0.0f);
            *(s32 *)(s4 + 0x2B0) = vi;
            if (vi < 0)
                goto Ltail22;
            w = (u32)(D_L11_001C8A40 + vi * 0x20);
            *(TI128 *)(w + 0x10) = *(TI128 *)(s4 + 0x230);
            *(f32 *)(w + 0x0C) = 0.0f;
            *(f32 *)(w + 0x1C) = 5.0f;
            *(f32 *)(w + 0x00) = 1.0f;
            *(f32 *)(w + 0x04) = 0.0f;
            *(f32 *)(w + 0x18) = *(f32 *)(w + 0x18) + 1.0f;
            *(f32 *)(w + 0x08) = 0.0f;
        }
    }
Ltail22:
    /* 0x430DC8: the timer of the other object. */
    f25 = func_0029F530(s3);
    if (f25 < 3.0f)
        goto Leffect;
    if (s3[0x42] == 0xA) {
        vb = s4[0x35];
        goto Lf6c;
    }
Leffect:
    if (*(u32 *)(s4 + 0x27C) == 0)
        goto Lf60;
    /* 0x430E08: the 0.2f/0.9f effect. */
    func_0029FCC0((u32)*(u8 **)(*(u32 *)(*(u32 *)(s4 + 0x27C) + 0x68) + 0x278), 0, &st0.x);
    vec[0] = func_00283180(*(f32 *)(s3 + 0xF8)) * 0.1f;
    vec[1] = func_00283198(*(f32 *)(s3 + 0xF8)) * 0.1f;
    vec[2] = 0.0f;
    func_00282CC0(&st0.x, &st0.x, &vec[0]);
    st0.z = st0.z - 0.05f;
    f = func_002A7878(0.2f, 0.9f);
    f = f * 0.2f;
    f = f * *(f32 *)(s4 + 0x288);
    va = func_002A77E0(2);
    if (va == 0)
        va--;
    func_002C2210(&st0.x, 2, 0x804020FF, 0, va, (s32)D_L11_001A8F20, 0,
                  f * 0.3f, f, 0.0f);
    func_002C2210(&st0.x, 2, 0x7F6F6FFF, 1, -va, (s32)D_L11_001A8F20, 0,
                  f * 0.04f, f * 0.4f, 0.0f);
    *(f32 *)(s4 + 0x288) = *(f32 *)(s4 + 0x288) + 1.0f;
Lf60:
    /* 0x430F60 */
    vb = s4[0x35];
Lf6c:
    /* 0x430F6C */
    f27 = (f32)vb;
    if (3.0f <= f25) {
        /* 0x430F84: the window below 9.0f */
        if (f25 < 9.0f) {
            if (s3[0x42] == 0xA) {
                /* 0x430FA8: the 3.0f .. 9.0f window */
                pa = s4 + 0x240;
                pd = s4 + 0x240;
                fw = *(f32 *)(s4 + 0x298) + 1.0f;
                *(f32 *)(s4 + 0x298) = fw;
                func_00282F20(pa, s4 + 0x250, fw);
                func_002A8C00(&st0.x, s3, 1, pa, f27);
                *(u16 *)((u8 *)vec + 0xA) = *(u16 *)(s3 + 0xAA);
                func_00282CC0(pa, s4 + 0x230, pa);
                if (func_002761F8(s4 + 0x230, pa, 0, s3, &st0.x)) {
                    *(TI128 *)(s4 + 0x240) = *(TI128 *)D_L11_001C0D20;
                    if (func_002B38B8(s3) == 0) {
                        func_L04_003E5830(D_L11_001C0D20, 6);
                        func_L00_003294F0(s3, 1);
                    }
                }
                f21 = func_002A7878(1.0f, 6.0f);
                f26 = 1.0f;
                ei = func_002A7820(0x19, 0x23);
                if (ei == 0)
                    ei--;
                *(TI128 *)vec3 = *(TI128 *)pd;
                vec3[2] = vec3[2] - 0.1f;
                f23 = f21 * 0.3f;
                f24 = 0.0f;
                func_002C2210(&vec3[0], 0x19, 0xFF000080, 0, ei, (s32)D_L11_001A8F20,
                              0, f23, f21, f24);
                ei = -ei;
                f22 = f21 * 0.04f;
                f20 = f21 * 0.4f;
                func_002C2210(&vec3[0], 5, 0x7F6F6FFF, 1, ei, (s32)D_L11_001A8F20,
                              0, f22, f20, f24);
                func_002C2210(&vec3[0], 0x14, 0xFF4080FF, 1, ei, (s32)D_L11_001A8F20,
                              0, f20, f21 * 0.2f, f24);
                func_002C2210(s4 + 0x230, 0xA, 0x80CA00CB, 0, ei, (s32)D_L11_001A8F20,
                              0, f23, f21, f24);
                func_002C2210(s4 + 0x230, 0xA, 0x7F6F6FFF, 1, -ei, (s32)D_L11_001A8F20,
                              0, f22, f20, f24);
                func_L00_002E6CF0(func_L11_00431E30, s3);
                if (*(s32 *)(s4 + 0x2B0) < 0)
                    goto Lloop;
                w = (u32)(D_L11_001C8A40 + *(s32 *)(s4 + 0x2B0) * 0x20);
                *(TI128 *)(w + 0x10) = *(TI128 *)(s4 + 0x240);
                *(f32 *)(w + 0x0C) = f24;
                *(f32 *)(w + 0x1C) = 5.0f;
                *(f32 *)(w + 0x00) = f26;
                *(f32 *)(w + 0x04) = f24;
                *(f32 *)(w + 0x18) = *(f32 *)(w + 0x18) + f26;
                *(f32 *)(w + 0x08) = f24;
            }
        }
    }
Lloop:
    /* 0x431260: the 9.0f .. 15.0f window. */
    if (9.0f <= f25) {
        if (f25 < 15.0f) {
            if (s3[0x42] == 0xA) {
                f = func_00282E80(s4 + 0x230, s4 + 0x240);
                if (1.6666667f < f) {
                    /* 0x4312D4: the 9.0f .. 15.0f window */
                    fw2 = *(f32 *)(s4 + 0x298) + 1.0f;
                    *(f32 *)(s4 + 0x298) = fw2;
                    func_00282F20(s4 + 0x240, s4 + 0x250, fw2);
                    func_002A8C00(&st0.x, s3, 1, s4 + 0x240, f27);
                    *(u16 *)((u8 *)vec + 0xA) = *(u16 *)(s3 + 0xAA);
                    func_00282CC0(s4 + 0x240, s4 + 0x230, s4 + 0x240);
                    if (func_002761F8(s4 + 0x230, s4 + 0x240, 0, s3, &st0.x)) {
                        *(TI128 *)(s4 + 0x240) = *(TI128 *)D_L11_001C0D20;
                        if (func_002B38B8(s3) == 0) {
                            func_L04_003E5830(&vec3[0], 6);
                            func_L00_003294F0(s3, 1);
                        }
                    }
                    func_00282F20(&vec3[0], s4 + 0x250, 1.6666667f);
                    func_00282CC0(s4 + 0x230, s4 + 0x230, &vec3[0]);
                    f21 = func_002A7878(1.0f, 6.0f);
                    f23 = 1.0f;
                    ei = func_002A7820(0x19, 0x23);
                    if (ei == 0)
                        ei--;
                    *(TI128 *)vec4 = *(TI128 *)(s4 + 0x240);
                    vec4[2] = vec4[2] - 0.1f;
                    f22 = 0.0f;
                    func_002C2210(&vec4[0], 0x19, 0xFF000080, 0, ei, (s32)D_L11_001A8F20,
                                  0, f21 * 0.3f, f21, f22);
                    ei = -ei;
                    f20 = f21 * 0.4f;
                    func_002C2210(&vec4[0], 5, 0x7F6F6FFF, 1, ei, (s32)D_L11_001A8F20,
                                  0, f21 * 0.04f, f20, f22);
                    func_002C2210(&vec4[0], 0x14, 0xFF4080FF, 1, ei, (s32)D_L11_001A8F20,
                                  0, f20, f21 * 0.2f, f22);
                    func_L00_002E6CF0(func_L11_00431E30, s3);
                    if (*(s32 *)(s4 + 0x2B0) < 0)
                        goto Lend;
                    w = (u32)(D_L11_001C8A40 + *(s32 *)(s4 + 0x2B0) * 0x20);
                    *(TI128 *)(w + 0x10) = *(TI128 *)(s4 + 0x240);
                    *(f32 *)(w + 0x0C) = f22;
                    *(f32 *)(w + 0x1C) = 5.0f;
                    *(f32 *)(w + 0x00) = f23;
                    *(f32 *)(w + 0x04) = f22;
                    *(f32 *)(w + 0x18) = *(f32 *)(w + 0x18) + f23;
                    *(f32 *)(w + 0x08) = f22;
                    goto Lend;
                }
                goto Lrelease;
            }
        }
    }
    /* 0x431544: the 15.0f test */
    if (15.0f < f25) {
        if (s3[0x42] == 0xA)
            goto Lrelease;
    }
    goto Lend;
Lrelease:
    /* 0x43156C: the effect is released. */
    if (*(s32 *)(s4 + 0x2B0) >= 0) {
        func_00291450((u32 *)(s4 + 0x2B0));
        *(s32 *)(s4 + 0x2B0) = -1;
    }
    goto Lend;
Lcase22end:
    func_002A7750(s3, 0xF, -1);
    func_L11_0042EF90(s3, 6, 5, 0, 0xA);
    goto Lend;

d24:
    if (s3[0x43] == 0xE) {
        func_002B60B0(s3, 0.13333334f, 0.06666667f, 0.009696275f, 0.6981318f);
        v = *(s32 *)(s4 + 0x29C);
        func_002B6120(s3, *(u8 **)(D_L11_001FF580 + v * 4));
    }
    goto Lend;

d23:
    s1 = D_00189EA0;
    s1 = (u8 *)s1 - 0x61E0;
    func_00283248(*(f32 *)(s1 + 0x80) - *(f32 *)(s3 + 0x10),
                  *(f32 *)(s1 + 0x84) - *(f32 *)(s3 + 0x14));
    if (func_00283C80(*(f32 *)(s3 + 0xF8)) <= 0.087266475f) {
        func_L11_0042EF90(s3, 9, 6, 0, 0xA);
        func_002A7750(s3, 0x12, -1);
    } else {
        s0 = s3 + 0x10;
        func_00283248(*(f32 *)(s1 + 0x80) - *(f32 *)(s3 + 0x10),
                      *(f32 *)(s1 + 0x84) - *(f32 *)(s3 + 0x14));
        func_002B50E0(s3, s0, *(f32 *)(s1 + 0x80));
    }
    goto Lend;

d22:
    if ((s3[0x60] & 2) == 0)
        goto Lend;
    v = *(s32 *)(s4 + 0x2C0);
    if (v != 0) {
        func_L11_0042EF90(s3, 5, 4, 0, 0xC);
        func_002A7750(s3, 6, -1);
    } else {
        func_L11_0042EF90(s3, 5, 4, 0, 0xC);
        func_002A7750(s3, 5, -1);
    }
    goto Lend;

d3:
    goto Lend;

Lend:
    func_L11_00431D50(s3);
    if (*(f32 *)(s3 + 0x18) < 74.0f) {
        func_002A6C58(s3, 0, 3);
        D_L11_001AED04 = D_L11_001AED04 - 1;
        func_0029F338(s3, D_L11_001AED04);
    }
Lret:
    return;
}
