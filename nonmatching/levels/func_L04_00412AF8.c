/* MMI (SPECIAL2) instruction: no C spelling. 348 bytes, level 04_barlow.
   Retail at 0x00412AF8 carries the SPECIAL2 word 0x700014A9 (+0x0004) - opcode
   0x1C, which rabbitizer prints as `INVALID`; it is the MMI family the sixth wave
   recorded for func_L18_003FCC48 and that no C spelling reaches. This cc1 emits
   `lq`/`sq` for a `mode(TI)` local and `ldl`/`ldr`/`sdl`/`sdr` for a struct
   assignment, never the packed copy: a `long long` copy comes out as `daddu`, a
   structure assignment as `dsll32`/`sdl`/`ldr`, a `mode(TI)` copy as `lq`/`sq`.
   The body also holds the two quadword stores 0x7FA20000 and 0x7FA20010 (+0x0068
   and +0x006C), which are the `sq` this cc1 does emit, and the float set-up
   (0x44172CCD, 0x444B2000, 0x43A3F99A, 0x3F5D4B6A, 0x3F00B439) that the MMI
   copies. ASM_FUNC candidate, as for the rest of the family. */
