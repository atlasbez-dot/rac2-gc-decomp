/* func_002F0FA0 - near miss (112 bytes of the retail 108).
 *
 * Clears the flags of every record of a list of 0x20-byte records.
 *
 * The retail (the boot's copy at 0x002F0FA0, the same body in every program):
 *
 *   lui    $v0, 0x1C
 *   lui    $a1, 0x1B
 *   lw     $a1, 0x21B4($a1)      <- the first record, 0x001B21B4 in the boot
 *   lw     $v1, -0x512C($v0)     <- the value, 0x001BAED4 in the boot
 *   lui    $a0, 0x1B
 *   lw     $a0, 0x21B8($a0)      <- the end of the list, 0x001B21B8 in the boot
 *   lui    $at, 0x1B
 *   sw     $v1, 0x21C4($at)      <- the value is copied here, 0x001B21C4
 *   lui    $at, 0x1B
 *   sw     $zero, 0x21E0($at)    <- 0x001B21E0 cleared
 *   lui    $at, 0x1B
 *   sw     $zero, 0x21E4($at)    <- 0x001B21E4 cleared
 *   beq    $a1, $a0, +0xC        <- an empty list: done
 *   sw     $zero, 0x31F8($gp)    <- one more global cleared, through $gp
 *   ori    $a0, $zero, 0xFFFF
 *   addiu  $v1, $zero, 0xFF
 *   sb     $v1, 0x1F($a1)        <- the record's byte at +0x1F
 *   nop
 *   sh     $zero, 0x16($a1)      <- the record's halfword at +0x16
 *   sh     $a0, 0x14($a1)        <- the record's halfword at +0x14
 *   lui    $v0, 0x1B
 *   lw     $v0, 0x21B8($v0)      <- the end of the list, read again
 *   addiu  $a1, $a1, 0x20
 *   bnel   $a1, $v0, -0x6        <- the loop, branch likely
 *   sb     $v1, 0x1F($a1)        <- the next record's byte, in the delay slot
 *   jr     $ra
 *   nop
 *
 * The list's addresses differ from program to program (they are all above the boot's
 * resident area), so the globals need ref_ names; the one at $gp - 0x31F8 is small
 * data and needs the sda attribute, the others are read with the coalesced lui + lw
 * of a -G8 unit (no attribute: nosda would give the two-register split instead).
 *
 * What is still missing, against the 112 bytes this C compiles to:
 *
 *   1. the register allocation: the retail keeps the record pointer in $a1 and the end
 *      of the list in $a0, this C keeps the pointer in $a0 and the end in $v1.  The
 *      declaration order does not move it (the end first, the pointer second and the
 *      value third were all measured).
 *   2. the two constants: the retail has 0xFFFF in $a0 and 0xFF in $v1, this C has
 *      0xFF in $a1 and 0xFFFF in $v1.
 *   3. the load order: the retail loads the pointer, the value and the end, this C
 *      loads them in another order whatever the source order is.
 *   4. one nop too many: the retail schedules the reload of the end of the list before
 *      the increment of the pointer, so the delay slot of the branch holds the store
 *      and no nop is needed.
 *
 * The body needs a -G8 unit (one global is reached through $gp), so it belongs in
 * 002EEB00-g8.c.
 */

extern int ref_L00_002F0FA0_00;

extern int ref_L00_002F0FA0_01;

extern int ref_L00_002F0FA0_02;

extern int ref_L00_002F0FA0_03;

extern int ref_L00_002F0FA0_04;

extern int ref_L00_002F0FA0_05;

extern int ref_L00_002F0FA0_06 __attribute__((sda));

/* Clears the flags of every record of the list. */
void func_002F0FA0(void)
{
    char *end = (char *)ref_L00_002F0FA0_01;
    char *p = (char *)ref_L00_002F0FA0_00;
    int v = ref_L00_002F0FA0_02;

    ref_L00_002F0FA0_03 = v;
    ref_L00_002F0FA0_04 = 0;
    ref_L00_002F0FA0_05 = 0;
    ref_L00_002F0FA0_06 = 0;

    if (p == end)
        return;

    do {
        *(unsigned char *)(p + 0x1F) = 0xFF;
        *(unsigned short *)(p + 0x16) = 0;
        *(unsigned short *)(p + 0x14) = 0xFFFF;
        p += 0x20;
    } while (p != (char *)ref_L00_002F0FA0_01);
}
