/* func_L10_0042E4D0 (192 bytes, 1 place) - TI128 destination wall, ASM_FUNC candidate.
 *
 * Readable: func_2FA1B0(a0+0x10, 16, 0.8f, *(void**)(a0+0x68)) decides the arm; two of the
 * three arms copy a 128-bit object through $v0 (`lq $v0,0x0($v1)` 0x78620000 then
 * `sq $v0,0x0($sp)` 0x7FA20000, or `lq $v0,0x0($sp)` 0x7BA20000 then
 * `sq $zero,0x0($s0)` 0x7E020000), and each arm then calls func_308E10 with a different
 * float constant (0x3F4CCCCD, 0x3E888889, 0x3D088889).
 * The wall is the same one worker 02 reconfirmed three times: this cc1 folds the constant
 * destination displacement into the `sq` where retail materialises the pointer with an
 * `addiu` first, so the 128-bit copies come out one instruction short each (retail's
 * `addiu $v1,$v1,0xC0` / `addiu $v1,$v1,-0x500` around the lq/sq pair).  Not retried here
 * beyond reading it, per that finding.
 */

/* Later worker (wave 24): the wall confirmed and one step further.  The candidate below
   reaches 180 bytes against retail's 192 with the frame, both calls, the branches, the field
   test and the lq/sq pairs all as retail has them; the first arm's address is materialised
   with `addiu $v0,$v0,0xC0` before the lq, as the note above asks for, when the source
   takes the address into a pointer first (`p = D_00141780 + 0xC0`) instead of indexing.
   What is left: (a) the $gp vector at 0x2790 is loaded twice here (once for the test, once
   for the address) where retail loads it once, in the delay slot of the `bne` that ends the
   field test; (b) the else branch is three words shorter - retail copies the destination
   into $a0 and then into $a1 for the call (`daddu $a0,$s0,$zero` / `daddu $a1,$a0,$zero`)
   and materialises the 0.03125f there, this cc1 reuses one register for the two arguments.
   The data needs the -G8 profile (the vector at 0x2790 is reached through $gp), so the body
   belongs in L10_00424028-g8.c; the pointer at 0x1BFAD8 is read with lui/lw, so it needs
   `nosda` there.
   check.py func_L10_0042E4D0: "10_hrugis_cloud: 180 bytes, expected 192". */
