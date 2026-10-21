/* No attempt: the row is not a function. 52 bytes at 0x0012FB10 are
   `sw $v1,0x70($v0); nop; sw $a1,0xD8($v0); nop; lw $v0,0xCC($v1); nop;
   lw $v0,0xD0($v1); nop; addiu $v0,$v0,0xB4; nop; addiu $v0,$v0,0xB4; nop;
   sd $a1,0xF0($v1)`: no `jr $ra` anywhere, and it reads $v0 and $v1 that no
   entry sets. The block falls through into func_0012FB48 (_alalcInit), which
   is a complete function with its own `jr $ra` and a caller at 0x0012F7B0.
   The nop after every instruction is a MIPS I style the SDK compiler never
   emits (the matched neighbours use the branch delay slots), and the two
   `addiu $v0,$v0,0xB4` have no source: the second `lw` already overwrites
   the first, so the value they add to is dead.
   rac1-decomp keeps the same bytes as the linker remnant func_0012BCF0
   (LINKER_REMNANT; libmpeg's address delta is +0x3E20, so rac1 0x0012BCF0
   is rac2 0x0012FB10), and the USA v2.00 symbol table has no symbol at
   0x0012FB10 while it has _alalcInit at 0x0012FB48.
   Two C spellings measured with tools/check.py --diff: the plain one is 24
   bytes against retail's 52, the volatile one reaches 52 bytes with every
   word different (a frame, a spill of the third argument and a `jr $ra`
   where retail has none). A split-off remnant - fix in tools/levels.py. */
