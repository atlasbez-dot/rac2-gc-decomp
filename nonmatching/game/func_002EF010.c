/* func_002EF010 - near miss (100 bytes of the retail 108).
 *
 * Walks a byte table downwards and subtracts every entry that still fits, so that a
 * value becomes the sum of the table's entries below it.
 *
 * Measured layout (the boot's copy at 0x002EF010, the same body in every program):
 *
 *   addiu  $v0, $a0, -0x20
 *   sltiu  $v0, $v0, 0x91
 *   xori   $v0, $v0, 0x1          <- the negated "inside the range" test
 *   bnez   $v0, +0x13            <- to the out-of-range block at the end
 *   slti   $v1, $a0, 0xB1        (delay slot: the ternary's condition, hoisted)
 *   lui    $v1, 0x1B
 *   lbu    $v1, -0x2FB5($v1)     <- the end byte, at 0x001AD04B in the boot
 *   slt    $v0, $a0, $v1
 *   bnez   $v0, +0x3             <- to the search loop
 *   addiu  $a1, $zero, 0x1B      (delay slot: the loop's first index)
 *   b      +0xE                  <- to the exit
 *   subu   $a0, $a0, $v1         (delay slot)
 *   addiu  $a1, $a1, -0x1
 *   bltz   $a1, +0xB
 *   nop
 *   addiu  $v0, $gp, -0x1FC0     <- the table, small data: 0x001AD030 in the boot
 *   addu   $v0, $a1, $v0
 *   lbu    $v0, 0x0($v0)
 *   slt    $v1, $a0, $v0
 *   bnez   $v1, -0x7
 *   addiu  $a1, $a1, -0x1        (delay slot)
 *   b      +0x3
 *   subu   $a0, $a0, $v0         (delay slot)
 *   addiu  $v0, $a0, -0x91
 *   movz   $a0, $v0, $v1         <- a0 = (a0 < 0xB1) ? a0 : a0 - 0x91
 *   jr     $ra
 *   daddu  $v0, $a0, $zero       (delay slot: the 64-bit return)
 *
 * The table's address differs from program to program (0x001AD030 in the boot,
 * 0x001AD370 in level 00), so it needs a ref_ name; the same holds for the end byte
 * (0x001AD04B in the boot, 0x001AD385 in level 00).  The table is reached through its
 * small-data address (gp - 0x1FC0 in the boot, gp - 0x1C80 in level 00) and is 28 bytes
 * long, so it needs the sda attribute on a declaration of at most 8 bytes to come out
 * gp-relative; the end byte is not in small data and needs nosda (lui + lbu, coalesced).
 *
 * What is still missing, against the 100 bytes this C compiles to:
 *
 *   1. the first branch: retail materialises the negated test (xori) and branches with
 *      bnez, this C branches with beqz on the test itself.  Spelling the test as
 *      ">= 0x91" or as "!(x < 0x91)" moves the xori in, but then the compiler puts the
 *      out-of-range block inline (and widens the parameter to 64 bits at the entry,
 *      which retail does not do), so the layout goes wrong instead.
 *   2. the second branch: retail computes "a0 < limit" in $v0 and branches with bnez
 *      to the loop, so the "a0 -= limit" block is the fall-through; this C computes it
 *      in $v1 and branches with beqz, so the loop is the fall-through.  Which of the two
 *      the compiler picks depends on the size of the blocks around it: with the end byte
 *      in small data (one instruction) the retail shape comes out, with it in lui + lbu
 *      (two instructions) it does not.
 *   3. retail recomputes the table's small-data address inside the loop, this C hoists
 *      it out (addiu $a2, $gp, 0x0 before the loop).  A pointer local inside the loop
 *      (unsigned char *p = table + i) does not change that.
 *   4. one nop too many (two here, one in retail).
 *
 * The body needs a -G8 unit (the table is reached through $gp), so it belongs in
 * 002EEB00-g8.c.
 */

extern unsigned char ref_L00_002EF010_00[8] __attribute__((sda));

extern unsigned char ref_L00_002EF010_01 __attribute__((nosda));

unsigned long func_002EF010(int a0)
{
    int i;
    unsigned char v;
    int limit;

    if ((unsigned int)(a0 - 0x20) < 0x91) {
        limit = ref_L00_002EF010_01;
        if (a0 < limit) {
            i = 0x1B;
            while (--i >= 0) {
                v = ref_L00_002EF010_00[i];
                if (a0 < v)
                    continue;
                a0 -= v;
                break;
            }
        } else {
            a0 -= limit;
        }
    } else {
        a0 = (a0 < 0xB1) ? a0 : a0 - 0x91;
    }
    return a0;
}
