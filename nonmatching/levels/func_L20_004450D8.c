/* Near miss from src/levels/20_yeedil/L20_0043ECB0.c (wave 3, 20_yeedil, 2026-10-20,
   worker 02): 232 bytes of retail, 244 bytes of candidate.
 *
 * The body is recovered.  It is the id-list walk of L01_003CAFE0-g8.c /
 * L04_00422A00-g8.c with the walk's extra body:
 *
 *   void func_L20_004450D8(char *arg0) {
 *       u32 idx = *(u8 *)(arg0 + 0x21);          // the level's own index byte
 *       u16 *rec;
 *
 *       if (idx == 0xFF) return;
 *       rec = (u16 *)D_L20_001FBB20[idx];
 *       for (;;) {
 *           u32 idx2 = *(u8 *)(arg0 + 0x21);     // re-read every pass
 *           if (idx2 == 0xFF) break;
 *           if (D_L20_001B2FB8 < idx2) break;    // the limit through $gp
 *           if (rec == 0) break;
 *           if (*(s16 *)(rec - 1) < 0) {
 *               u32 *slot = (u32 *)((char *)D_L20_001FBB20 + idx2 * 4);
 *               if (rec != (u16 *)slot[0]) break;
 *           }
 *           {
 *               u16 w = *rec;
 *               char *e = (char *)D_L20_001B2F9C + ((w & 0x7FFF) << 8);
 *               rec++;
 *               if (e == 0) break;
 *               if (*(s16 *)(e + 0xAA) != 0xD0F) continue;
 *               {
 *                   char *o = *(char **)(e + 0x68);
 *                   if (o == 0) continue;
 *                   if (*(u8 *)(o + 0x302) & 1) {
 *                       if (*(u32 *)(o + 0x420) != 1) continue;
 *                       *(u8 *)(o + 0x302) = 2;
 *                       *(u16 *)(e + 0x34) &= 0xFFFD;
 *                   }
 *               }
 *           }
 *       }
 *   }
 *
 * The reading of the retail:
 *
 *   004450D8  daddu   $a3, $a0, $zero      the object
 *   004450DC  addiu   $v1, $zero, 0xFF
 *   004450E0  lbu     $v0, 0x21($a3)       the index byte
 *   004450E4  beq     $v0, $v1, END
 *   004450E8    lui    $v1, %hi(D_1FBB20) the table's %hi, in the delay slot
 *   004450EC  sll     $v0, $v0, 2
 *   004450F0  addiu   $a0, $v1, %lo(D_1FBB20)
 *   004450F4  addu    $v0, $v0, $a0
 *   004450F8  lw      $a2, 0x0($v0)        the record
 *   004450FC  b       .L00445170           the jump to the loop's test
 *   00445100    daddu  $t0, $v1, $zero     the %hi copied, in the delay slot
 *   .L00445108:                            the loop's body
 *   00445108  lui     $v1, %hi(D_1B2F9C)   the object bank
 *   0044510C  lw      $v1, %lo(D_1B2F9C)($v1)
 *   00445110  andi    $v0, $v0, 0x7FFF     the id
 *   00445114  sll     $v0, $v0, 8
 *   00445118  addu    $a1, $v1, $v0        the entry
 *   0044511C  beqz    $a1, END
 *   00445120    addiu  $v0, $zero, 0xD0F
 *   00445124  lh      $v1, 0xAA($a1)       the entry's id
 *   00445128  bnel    $v1, $v0, .L00445170
 *   0044512C    addiu  $a2, $a2, 0x2       the record advance, in the delay slot
 *   00445130  lw      $a0, 0x68($a1)       the entry's object
 *   00445134  beql    $a0, $zero, .L00445170
 *   00445138    addiu  $a2, $a2, 0x2
 *   0044513C  lbu     $v0, 0x302($a0)
 *   00445140  andi    $v0, $v0, 0x1
 *   00445144  beqz    $v0, .L0044516C
 *   00445148    addiu  $v0, $zero, 0x1
 *   0044514C  lw      $v1, 0x420($a0)
 *   00445150  bnel    $v1, $v0, .L00445170
 *   00445154    addiu  $a2, $a2, 0x2
 *   00445158  addiu   $v1, $zero, 0x2
 *   0044515C  sb      $v1, 0x302($a0)
 *   00445160  lhu     $v0, 0x34($a1)
 *   00445164  andi    $v0, $v0, 0xFFFD
 *   00445168  sh      $v0, 0x34($a1)
 *   .L0044516C:
 *   0044516C  addiu   $a2, $a2, 0x2       the record advance
 *   .L00445170:                            the loop's test
 *   00445170  lbu     $v1, 0x21($a3)       the index byte, read again
 *   00445174  addiu   $v0, $zero, 0xFF
 *   00445178  beq     $v1, $v0, END
 *   0044517C    lw     $v0, 0x3FC8($gp)   the limit through $gp, in the delay slot
 *   00445180  slt     $v0, $v0, $v1
 *   00445184  bnez    $v0, END
 *   00445188  nop
 *   0044518C  beqz    $a2, END
 *   00445190  nop
 *   00445194  lh      $v0, -0x2($a2)      the record just consumed
 *   00445198  bgezl   $v0, .L00445108
 *   0044519C    lhu    $v0, 0x0($a2)
 *   004451A0  sll     $v0, $v1, 2          the table lookup
 *   004451A4  addiu   $v1, $t0, %lo(D_1FBB20)
 *   004451A8  addu    $v0, $v0, $v1
 *   004451AC  lw      $a0, 0x0($v0)
 *   004451B0  beql    $a2, $a0, .L00445108
 *   004451B4    lhu    $v0, 0x0($a2)
 *   .L004451B8:
 *   004451B8  jr      $ra
 *   004451BC  nop
 *
 * What the candidate gets wrong is the LAYOUT, not the body: the retail's entry jumps
 * to the loop's TEST and the body's block sits BEFORE the test's block (the test is
 * the loop's header and the two back edges go back to the body), while this cc1
 * rotates the loop the other way and lays the test's block first.  The candidate is
 * 244 bytes against the retail's 232.
 *
 * Measured: the index byte must be read with `lbu` (`*(u8 *)`, not `char *` - the
 * compiler's `char` is signed and gives `lb`); the record advance has to sit BEFORE
 * the body's tests in the source (the retail duplicates it into the delay slots of
 * the three exits that skip it); the `& 0xD0F` test is on the SIGNED halfword at
 * 0xAA; the `0x302` byte test is `& 1`; the `0x420` word is compared against 1; the
 * `0x34` halfword is masked with 0xFFFD.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u32 D_L20_001FBB20[] __attribute__((nosda));

extern u32 D_L20_001B2F9C __attribute__((nosda));

extern u32 D_L20_001B2FB8 __attribute__((sda));

void func_L20_004450D8(char *arg0) {
    u32 idx = *(u8 *)(arg0 + 0x21);
    u16 *rec;
    u32 *slot;

    if (idx == 0xFF) {
        return;
    }
    rec = (u16 *)D_L20_001FBB20[idx];
    for (;;) {
        u32 idx2 = *(u8 *)(arg0 + 0x21);
        u16 w;

        if (idx2 == 0xFF) {
            break;
        }
        if (D_L20_001B2FB8 < idx2) {
            break;
        }
        if (rec == 0) {
            break;
        }
        if (*(s16 *)(rec - 1) < 0) {
            slot = (u32 *)((char *)D_L20_001FBB20 + idx2 * 4);
            if (rec != (u16 *)slot[0]) {
                break;
            }
        }
        w = *rec;
        rec++;
        {
            char *e = (char *)D_L20_001B2F9C + ((w & 0x7FFF) << 8);

            if (e == 0) {
                break;
            }
            if (*(s16 *)(e + 0xAA) != 0xD0F) {
                continue;
            }
            {
                char *o = *(char **)(e + 0x68);

                if (o == 0) {
                    continue;
                }
                if (*(u8 *)(o + 0x302) & 1) {
                    if (*(u32 *)(o + 0x420) != 1) {
                        continue;
                    }
                    *(u8 *)(o + 0x302) = 2;
                    *(u16 *)(e + 0x34) &= 0xFFFD;
                }
            }
        }
    }
}

/* Near miss from src/levels/20_yeedil/L20_0043ECB0.c (wave 4, 20_yeedil, 2026-10-20,
   worker 02): the body and the layout are recovered; the candidate is 240 bytes against
   retail's 232.

   What the wave-4 candidate settles:
   - The LAYOUT is retail's: the entry block computes the record and jumps to the loop's
     TEST, the BODY block sits BEFORE the test and the test's two back edges go to the body.
     A goto-loop reproduces that: `goto test;` at the entry, the body at a `body:` label
     that ends in `goto test;`, and the test at a `test:` label after it.  A `for` loop
     lays the test's block first and does not match.
   - The index byte must be read TWICE: the retail re-reads `arg0[0x21]` in the test block
     (`lbu $v1,0x21($a3)`).  Without `volatile` this cc1 keeps ONE copy of the index in a
     register across the branch (one instruction more than retail).  `idx = *(volatile u8 *)
     (arg0 + 0x21);` in the test block is what makes the second read happen.
   - The bank's global D_L20_001B2F9C must be a PLAIN declaration: retail loads it with
     the absolute single-register form `lui $v1,%hi(D_1B2F9C)` + `lw $v1,%lo(D_1B2F9C)($v1)`.
     `__attribute__((sda))` gives the $gp form (`lw $v1,off($gp)`, one instruction fewer)
     and `__attribute__((nosda))` gives `lui $v0,%hi(S)` + `lw $a0,%lo(S)($v0)` (the address
     in a register of its own).  The limit D_L20_001B2FB8 IS read through $gp
     (`lw $v0,0x3FC8($gp)`), so it keeps `__attribute__((sda))`.
   - The three exits that skip the body duplicate the record advance into their delay slots
     (`bnel`/`beql` + `addiu $a2,$a2,0x2`), and the body's own advance is its own block
     (`addiu $a2,$a2,0x2`) that falls into the test.  Writing the advance explicitly in
     each exit reproduces that.

   What still differs (240 against 232 bytes, and the register allocation with it):
   - The LAST test.  Retail: `lw $a0,0x0($v0)` ; `beql $a2,$a0,.L00445108` ;
     `lhu $v0,0x0($a2)`.  The candidate: `bne $a2,$a0,END` ; `nop` ; `b .L00445108` ;
     `lhu $v0,0x0($a2)`.  Two instructions against one.
     MEASURED: this cc1 has TWO branch-likely mechanisms.  (1) The ASTRA pass
     `mips_r5900_annul_dead_slots` (config/mips/mips.c) annuls a branch when the DELAY
     SLOT's destination register is the register the branch tests and the write is dead on
     the not-taken path (the retail `bnez v0,L; move v0,zero` shape).  That is what gives
     the FIRST test its `bgezl`: its delay slot overwrites the tested register $v0.  (2) The
     standard gcc rule (reorg.c's `optimize_skip`): a conditional branch that skips
     EXACTLY ONE instruction becomes a branch-likely with that instruction in its delay
     slot.  (2) is what produced a `beql` between two registers in a measured test
     (`if (rec == slot) { D_Y = *rec; goto body; } return;` with the body right after gives
     `beql $4,$5,$L9` and the store in the delay slot), so a `beql` between two registers is
     NOT out of reach; what is out of reach here is the SHAPE.  In the walk the "then"
     block is the load AND the jump back to the body, so the branch skips two instructions
     and (2) does not fire.  Measured and rejected for the second test: `||` instead of
     two tests, the `&&` chain, the swapped operands, a `u32` comparison, an explicit
     `else`, a `goto` to a label at the end, `w = *rec` inside the test and `w = *rec` once
     before the two tests (the load is then duplicated into the first branch's delay slot,
     but the second test still gets the plain `bne`), and the load moved into the body.
   - The branch-likely IS reachable with a comparison between two registers, and the
     recipe is measurable: `if (rec == slot) { D_Y = *rec; goto body; } return;` with the
     body right after gives `beql $4,$5,$L9` with the store in the delay slot.  The
     condition is that the conditional branch skips EXACTLY ONE instruction: the "then"
     block must be a single instruction and the block after it must be the "else"
     block's target.  In the walk the "then" block is the load AND the jump back to the
     body, so the branch skips two instructions and the optimisation does not fire; that
     is why the FIRST test (whose "then" block is the load and whose delay slot overwrites
     the tested register $v0) comes out as the retail's `bgezl` and the second does not.
   - The table's split address.  Retail keeps the %hi in $v1 and copies it into $t0 for the
     second use (`lui $v1,%hi(D_1FBB20)` ; `addiu $a0,$v1,%lo(D_1FBB20)` ;
     `daddu $t0,$v1,$zero` ; `addiu $v1,$t0,%lo(D_1FBB20)`).  The candidate materialises the
     whole address in one register and copies the %hi early (`daddu $t0,$v0,$zero` before
     the `addiu`), because its first use destroys the %hi register.  This is the same
     "split address" difference as func_L20_004431E0 and is not a per-function wall.

   The candidate (a -G8 unit: the limit is read through $gp):

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u32 D_L20_001FBB20[];

extern u32 D_L20_001B2F9C;

extern int D_L20_001B2FB8 __attribute__((sda));

void func_L20_004450D8(char *arg0) {
    u32 idx;
    u16 *rec;
    u16 w;
    char *e;
    char *o;
    u16 *slot;

    idx = *(u8 *)(arg0 + 0x21);
    if (idx == 0xFF) {
        return;
    }
    rec = (u16 *)D_L20_001FBB20[idx];
    goto test;

body:
    e = (char *)D_L20_001B2F9C + ((w & 0x7FFF) << 8);
    if (e == 0) {
        return;
    }
    if (*(s16 *)(e + 0xAA) != 0xD0F) {
        rec++;
        goto test;
    }
    o = *(char **)(e + 0x68);
    if (o == 0) {
        rec++;
        goto test;
    }
    if (*(u8 *)(o + 0x302) & 1) {
        if (*(u32 *)(o + 0x420) != 1) {
            rec++;
            goto test;
        }
        *(u8 *)(o + 0x302) = 2;
        *(u16 *)(e + 0x34) &= 0xFFFD;
    }
    rec++;
    goto test;

test:
    idx = *(volatile u8 *)(arg0 + 0x21);
    if (idx == 0xFF) {
        return;
    }
    if (D_L20_001B2FB8 < idx) {
        return;
    }
    if (rec == 0) {
        return;
    }
    if (*(s16 *)(rec - 1) >= 0) {
        w = *rec;
        goto body;
    }
    slot = (u16 *)D_L20_001FBB20[idx];
    if (rec == slot) {
        w = *rec;
        goto body;
    }
    return;
}

/* ---- wave 5 (20_yeedil, 2026-10-21, worker 03): the layout and the allocation ---
 *
 * The candidate above is the wave-4 one: 240 bytes against the retail's 232,
 * and the wave-4 candidate's own note names the residue as the LAST test.
 * This wave re-measured it and adds the following.
 *
 *  - The read `w = *rec` moved BEFORE the two tests of the test block gives
 *    EXACTLY 232 bytes - the retail's size - so the block layout, the
 *    instruction count and the loop's shape are then the retail's.  It is
 *    still not the retail: the last test comes out as
 *        beq $a2,$a1,END ; nop ; b body ; lhu $v0,0x0($a2)
 *    where the retail has
 *        beql $a2,$a0,body ; lhu $v0,0x0($a2) ; jr $ra
 *    and the register allocation is off (the retail keeps the object in $a3,
 *    the record in $a2 and the entry pointer in $a1; this cc1 keeps the
 *    argument in $a0, the record in $a1 and the entry pointer in $a2).
 *  - The allocation follows the "split address" of D_1FBB20, which is the
 *    known difference of func_L20_004431E0 and is not a per-function wall:
 *    the retail materialises the table's address in $a0
 *    (`lui $v1,%hi(D_1FBB20)` ; `addiu $a0,$v1,%lo(D_1FBB20)`) and copies the
 *    %hi into $t0 for the second use (`addiu $v1,$t0,%lo(D_1FBB20)`), while
 *    this cc1 keeps the %hi and the address in one register and copies the
 *    %hi early (`daddu $t0,$v0,$zero` before the `addiu`), because its first
 *    use destroys the %hi register.  That is also why the retail copies the
 *    object into $a3: $a0 holds the table's address.
 *  - The branch-likely of the last test: reorg.c's optimize_skip fires in
 *    two cases - the branch skips exactly ONE instruction, or the branch and
 *    the jump that follows it have the SAME label.  The retail's
 *    `beql $a2,$a0,body` with the read in the delay slot is the second case
 *    (the "then" block is the read and the jump back to the body).  The
 *    source shapes measured, all of which keep the plain `bne`:
 *        if (rec == slot) { w = *rec; goto body; } return;
 *        if (rec != slot) { return; } w = *rec; goto body;
 *        if (rec == slot) { w = *rec; } else { return; } goto body;
 *        w = *rec; if (rec == slot) { goto body; } return;   (232 bytes)
 *    The last one is the only one that changes the size, and it changes the
 *    first test too (it becomes a plain `bltz` instead of the retail's
 *    `bgezl`).
 *  - The index byte must be read twice and the second read must be volatile
 *    (the wave-4 note) - re-measured, that holds.
 */
