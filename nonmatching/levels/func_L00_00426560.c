/* func_L00_00426560 (284 bytes, 27 places) - the TI128 destination wall, four copies.
 *
 * Retail at 0x00426560 (level 00): the body holds four raw quadword copies, each with
 * its pointers materialised and the displacement folded to zero:
 *     0x7BA20000 / 0x7C820000   (lq $s2,0($sp) ; sq $v0,0($a0))
 *     0x7A220000 / 0x7C620000   (lq $v1,0($s1) ; sq $v0,0($v1))
 * and the two that follow the same shape at +0xC0 and +0xC8.
 *
 * A 16-byte copy reaches `lq`/`sq` only through a 128-bit integer type
 * (`typedef int TI128 __attribute__((mode(TI)));`); a plain struct assignment gives
 * ldl/ldr/sdl/sdr. What still blocks the copies is that this cc1 folds a CONSTANT
 * destination offset into the `sq` where retail materialises the pointer first - the
 * tie in `mips_address_cost` goes to the sum. The compiler-side lever that fixes it
 * is the per-file profile `-frac2-qcopy` (present in the master cc1): it keeps the
 * destination and source addresses in registers and groups the lq/sq with a $v0
 * scratch clobber. `-frac2-qcopy-barrier`, the companion switch of COMPILER-NOTES, is
 * NOT built here (the option is rejected by cc1).
 *
 * The rest of the body is plain C: the state byte at 0x22B4 of the global decides
 * between 9.5f, 0.75f and 0x4f (0x3FCCCCCD) for the func_2EE178 call on the 16-byte
 * block at +0x10 of the frame, func_2EE108 is called with the block at +0x30 of the
 * argument and 0x00189EA0, func_2EE220 with the block at +0x20 and the word read from
 * 0x001BF8E14, and the last two copies move the 16-byte block at +0x40 of the argument.
 */
