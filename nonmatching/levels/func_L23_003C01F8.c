/* func_L23_003C01F8 (204 bytes, 1 place, level 23) -- Not a C row: MMI.

   Five 128-bit pairs the C front end never emits: 0x7A220000 (`lq $s1,0($v0)`),
   0x7FA20000 (`sq $sp,0($v0)`), 0x7E020000 (`sq $s0,0($v0)`), 0x78620000
   (`sq $v1,0($v0)`), 0x7E220000 (`sq $s1,0($v0)`). ASM_FUNC candidate, same family
   as func_L16_00411600.c and func_L22_003A2988.c.

   The rest is legible and worth having next to the ASM: it takes (s0 = arg0,
   s1 = arg1) and
     - returns early when `arg0[0x43] - 5 < 2` (i.e. 5 or 6) or when
       `arg0[0x20] == 2`;
     - otherwise calls func_L23_003BFFC0(0xA20($gp) float, 5, 0, 6, 1);
     - when arg1 != 0, builds two 16-byte vectors at $sp and $sp + 0x10 through
       func_L23_00418650 with constants -2.0f (0xC0000000) and 0.1f (0x3DCCCCCD),
       then calls func_002761F8(buf, $sp, 0x12, 0) and, on a non-zero result,
       copies 16 bytes to D_001C0AA0 and 16 bytes to s1 (both through lq/sq). */
