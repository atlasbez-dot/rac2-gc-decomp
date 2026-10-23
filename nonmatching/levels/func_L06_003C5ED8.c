/* func_L06_003C5ED8 (308 bytes, 1 place) -- SCREENED, no candidate compiled in this
   attempt; the body is decoded and the notes below are what a next worker needs.

   The function is a state machine over the byte at +0x20 of its argument, with a
   common tail.  It reads the state into $v1 and branches on it:

     - state 1: it calls func_35CBA0(self, 0x4010000, 0) (the 0x4010000 is the
       integer 0x4010000, retail's `lui $a1,0x401`), and when that returns zero it
       takes the word at +0 of the pointer at +0x68 of its argument and, if that word
       is not zero, calls func_35A550(self, 2, -1); the byte it leaves in $v0 is
       0xFF in both of those cases;
     - state 0: it calls func_35A550(self, 1, -1);
     - any other state: it returns at once (the `b` to the epilogue).

   All three paths converge on the common tail, which is:

     - it stores the byte in $v0 at +0xA8 of the argument;
     - it materialises -0.05f (0xBD4CCCCE), 1.5f (0x3FC00000), 3.0f (0x40400000),
       0.75f (0x3F400000) and 0x80404040 in $t1;
     - it calls func_3664A0(self, self + 0x10, 0x12, 1, 1.5f, 3.0f, 0.75f, 1.5f) with a
       128-bit value in the outgoing argument area (retail's `sq $v0,0($sp)`) and
       -0.05f above it (retail's `swc1 $f0,0x8($sp)`), which is the PS2 calling
       convention for the arguments past the eighth;
     - it calls func_3661E0(self, 1), then func_3A0948(0, 0, self) and finally
       func_350388(self).

   The frame is 0x30 with $s0 (the argument) and $s1 (the pointer at +0x68) saved.

   What blocks a candidate here: the call to func_3664A0 passes a 128-bit value and a
   float in the outgoing area, so the source has to build the quadword the way the
   matched sibling func_L02_0038DA60 does (a `mode(TI)` union), and the constant
   0x80404040 is dead in retail (it is $a1 before the delay slot overwrites $a1 with
   self + 0x10), which is the kind of leftover a next worker has to reproduce rather
   than clean up. */
