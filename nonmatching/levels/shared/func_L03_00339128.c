/* No attempt: the body cannot be produced by plain C with this ABI. The function takes
   seven arguments, but the last three do not arrive on the stack: the callers put them in
   the caller-saved temporaries $t0, $t1 and $t2 right before the call.

   At 03:00419898 (func_L03_00419850) the caller sets $t0 = 0x20, $t1 = 2 and $t2 = 0xFF
   (the last one in the call's delay slot) and then calls it; at 06:00382764 it sets
   $t0 = 0x7F, $t1 = the high half of a word and $t2 = 0xFF the same way, and the seven
   other call sites of level 06 do the same. The callee reads them: `andi $s1, $t0, 0xFF`,
   `sll $t1, $t1, 16` with the matching `sra $s7, $t1, 16`, and `andi $s2, $t2, 0xFF`.

   The frame tells the rest: it is 0x60 bytes and the callee saves $s1..$s7, $fp, $ra and
   $f20 from 0x08 to 0x50, so it reads no incoming stack argument at all (the fifth
   argument of the o32 ABI would be at 0x10 above the incoming $sp). The callers have no
   room for stack arguments either: their frames are 0x20 bytes and their $ra sits where
   the first stack argument would go.

   So the pair uses a convention where the fifth, sixth and seventh arguments travel in
   $t0, $t1 and $t2. The compiler this project reconstructs implements the o32 ABI, where
   those arguments are passed on the stack, so no C spelling of this function emits these
   instructions. The marker stays; the convention is the thing a caller needs to know. */
