/* Not attempted - body read in full, no C written: a loop over seven slots, 508 bytes,
   27 places.

   The body: the state block's first object gets its halfword flag 0x34 set; the call
   to func_L00_002D6418 runs only on the first turn of the loop; the word at
   $gp-0x60F0 (0x001A8F00, the same word the `lui`/`addiu` pair loads a few words
   later) decides the branch; the two guards on the shorts at 0x001BCAC0+0x44 and at
   0x00152C00+0x20 pick the path; a walk over the table at 0x001BCAC0+0x18C keeps the
   last entry's flag with a `movz`; and the three pointers at the base of the state
   (+0x1220, +0x1224, +0x1228) each get their halfword flag 0x34 set when they are
   not null.

   The word at +0xF8 was rechecked during integration: it has rs=$s0, rt=$v0 and
   rd=$v1. R5900 mult supports a GPR destination, also described by the qualified
   GNU opcode table's `d,s,t` form with WR_d. Thus the following use of $v1 does not
   require mfhi/mflo and does not prove an unmatchable high-half multiply. The
   earlier two-operand disassembly omitted rd. No C candidate has been tested
   here, and this record does not establish a compiler limitation.
   The loop's other shapes (the `bnel`/`bnez`
   chain, the `sltiu` range test on the count, the `movz` of the walk) are ordinary
   C, and the word at $gp-0x60F0 needs the two-name pattern (an `sda` name for the
   $gp form and an absolute alias for the macro form) in a `-g8` unit. */
