/* func_L00_002C3A40 (56 bytes, 27 places) -- NEAR MISS, not integrated.
   Wave 8 w8-10: the if-conversion wall of wave 5 w12 is confirmed and the retail's
   shape is now fully decoded.

   The retail body is: `s0 = 12` materialised in the `jal` delay slot, then
   `if (result == 2) s0 = 0;` and `return s0`. The conditional assignment sits in the
   delay slot of a branch-likely `beql $v1,$v0` (the state is compared with 2 held in
   $v0), and the slot's `daddu $s0,$zero,$zero` runs on the taken path (an integer
   branch-likely executes its slot when the branch is TAKEN). So the C is
   `int r = 12; if (f() == 2) r = 0; return r;` with the value held in a callee-saved
   register across the call.

   Measured here (four source forms, all 40 or 44 bytes):
   - `int r = 12; if (f() == 2) r = 0; return r;` -> 44 bytes;
   - the same with the result latched in a local first -> 44 bytes;
   - the two-goto/two-return spelling of section 16 of docs/MATCHING-BLOCKERS.md ->
     40 bytes;
   - every form goes through the if-conversion: `xori $v0,$v0,0x2` + `movz $v1,$zero,$v0`,
     the value 12 rematerialised after the call, no $s0 and no frame.
   The branch-likely form is reachable from ordinary C (see the matched
   func_L23_0042AC70, whose `beql` carries the epilogue restore in its slot), so the
   wall is the if-conversion, not the branch-likely: the assignment has to survive as a
   branch for the constant 12 to stay in a callee-saved register across the call.

   What would unblock it: a source shape that keeps the 12 in a register across the
   call AND keeps the conditional assignment as a branch - a memory destination keeps
   the branch (section 3) but the retail's destination is a register, and this cc1 has
   no option to turn the if-conversion off. */

extern int func_L00_002C3A78(void);

int func_L00_002C3A40(void)
{
    int r = 12;

    if (func_L00_002C3A78() == 2)
        r = 0;
    return r;
}
