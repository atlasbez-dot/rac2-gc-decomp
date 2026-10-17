/* func_L02_003D1ED0 (208 bytes, 1 place) - TI128 destination wall, ASM_FUNC candidate.
 *
 * Readable: $s1 = a0, $s2 = *(void**)(s1+0x68), and when `*(u8*)(s1+0x31)` and
 * `*(void**)(s2+0x2E4)` are both nonzero the body clears the +0x2E4 handle
 * (`jal func_3144D8(*(void**)(s2+0x2E4))`, `sw $zero,0x2E4($s2)`), builds a stack vector at
 * sp+0x20 with func_31EA58(sp+0x20, 0.1f, 0.1666667f), calls func_2F1F70(sp+0x20, sp+0x20,
 * D_L02_001B8F20-ish) and then func_32B468 with nine arguments including two 128-bit copies
 * (`lq $v0,0x0($a1)` 0x78A20000 / `sq $v0,0x10($sp)` 0x7FA20010).
 * The wall is the same TI128 one worker 02 reconfirmed: that `sq $v0,0x10($sp)` has a
 * constant 0x10 destination displacement that this cc1 folds, where retail materialises the
 * destination pointer first.
 */
