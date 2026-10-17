/* Not C with this cc1: 204 bytes, level 20 (1 place).
   The third instruction of the body is `.word 0x700014A9` - opcode 0x1C, the MMI window -
   and it is not a stray: it sits between the `sd $s0,0x30($sp)` and the `daddu $s0,$a0`
   argument copy, exactly the class the near miss of func_L11_00397A30 records (whose entry
   names func_L00_003A8E28 as the first to document this same word). The body also carries a
   quadword store, `.word 0x7FA20020` = `sq $v0,0x20($sp)`, next to the `addiu $a0,$sp,0x20`
   that feeds the first of the three calls. ASM_FUNC candidate, as for that family.
   The rest is ordinary and decoded: a 0x3E99999A (0.3f) constant stored at $sp+0x28, the
   calls func_00283098(sp+0x20, sp+0x20, a0+0xC0), func_00282CC0(sp+0x20, sp+0x20, a0+0x10)
   and func_0032C700(sp+0x20, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 0) with the 0x3F2A7EFA and
   0x41A0 float arguments, then the 0x1B8 handle released through func_002E59F8 and set to -1. */
