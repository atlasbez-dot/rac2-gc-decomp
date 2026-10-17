/* from src/levels/shared/L00_003EE100.c: not written this wave. Retail 644 bytes, 12 place(s), first word at L00:003f3518.
 * Rule: MMI/LQ/SQ (op 0x1e).
 * No C attempt was made (wave-5 tour-2 discard rule).
 * Retail opens with:
 *   0x003f3518  addiu       $sp, $sp, -0x640
 *   0x003f351c  lui         $v1, 0x1B
 *   0x003f3520  lw          $v1, -0x6FEC($v1)
 *   0x003f3524  sd          $s0, 0x5F0($sp)
 *   0x003f3528  sd          $s1, 0x5F8($sp)
 *   0x003f352c  sd          $s3, 0x608($sp)
 * Kept as data for the maintainers. */
