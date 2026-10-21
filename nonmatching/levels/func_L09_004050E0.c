/* MMI (SPECIAL2) instructions: no C spelling. 280 bytes, level 09_dobbo.
 *
 * Retail at 0x004050E0 carries two words rabbitizer prints as `INVALID`:
 *
 *   +0x0048  0x700014A9   opcode 0x1C (SPECIAL2), the pcpyld family
 *   +0x004C  0x7FA20010   opcode 0x1F (MMI), the `sq $v0,0x10($sp)` of the
 *                          packed 128-bit copy
 *
 * They stand where a 128-bit local is built in the stack frame: right after
 * `mtc1 $at,$f0` with 1.0f and before `daddu $a0,$sp,$zero ; addiu $a1,$sp,0x10 ;
 * swc1 $f0,0x18($sp) ; jal func_2EA930`.  This cc1 emits `lq`/`sq` for a
 * `mode(TI)` local and `ldl`/`ldr`/`sdl`/`sdr` for a struct assignment, never
 * the packed MMI copy, so plain C cannot reach these two words.  ASM_FUNC
 * candidate, as for the rest of the family (level 09 holds 150 of the
 * 0x700014A9 words and 72 of the 0x7FA20010 ones).
 *
 * The rest of the body is ordinary code and is recorded here so that a worker
 * with the MMI spelled out does not have to read the disassembly again:
 *
 *   func_315E60(0, 0, 3)                     a1 = 0, a2 = 3
 *   func_35C830(1, 0, s1)
 *   f0 = 1.0f                                (0x3F400000)
 *   <the two MMI words>
 *   func_2EA930(sp, sp + 0x10, s1 + 0xC0)
 *   func_2EA470(sp, sp, s1 + 0x10)
 *   func_31C378(s1, sp, -1, 0.32f, 0.0f)     (0x3EAA7EFA, f13 = f20 = 0.0f)
 *   func_2EA4A0(sp + 0x20, s1 + 0x10, 0x199EA0)
 *   func_2EA750(sp + 0x20, sp + 0x20, 0.1f)   (0x3DCCCCCE)
 *   func_322708(s1, 0x1F, sp + 0x20, 0xFF, 3.0f, 6.0f, 3.0f, 6.0f)
 *   func_30C790(s1)
 *
 * The frame is 0x60 bytes; $s0 = sp + 0x20, $s1 = the argument, $s2 = the
 * argument + 0x10; $f20 holds 0.0f.
 */
