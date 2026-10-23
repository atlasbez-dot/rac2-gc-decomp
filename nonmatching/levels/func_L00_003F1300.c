/* from src/levels/shared/L00_003EE100.c: not written this wave.
 *
 * func_L00_003F1300 (328 bytes, 27 places), retail's shape:
 *   - three calls to func_0029EFD0 with the ids 0xCE7, 0xCEB and 0xCEC, the first one
 *     guarded by the $gp word at +0x18E0 (read at the top, written back at the end);
 *   - two countdown loops that clear a word each, `addiu $a0,$zero,0xB` (eleven times)
 *     and `addiu $a0,$zero,0x7F` (128 times), each written as a decrement, three nops
 *     and a `bgez` back (the loop padding the compiler emits);
 *   - the global at 0x18C0B0 (lui 0x19 ; addiu -0x61E0 ; lw 0x2290) and the call to
 *     func_0019... with four zero float arguments.
 * No lq/sq here, so the quadword-copy profile does not apply: what blocks the match
 * is the loop padding and the $gp data, not the copies.
 */
