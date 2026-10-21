/* Not attempted - screened, no C written: 1316 bytes, 27 places.

   The screening: every branch of the body stays inside its own bytes, so the row is
   a whole function and not a catalogue fragment.  No MMI word (0x78/0x7A/0x7C/0x7E)
   and no COP2 (VU0) word; two multiplies, at +0xA4 (`mult $v0,$a0`) and +0x438
   (`mult $a1,$v1`).  Nothing in the row looks like handwritten assembly.

   The body is the state block's own update: it reads the resident block at
   0x00189E20, walks its tables, and writes the aim vector, the counter and the
   object's fields back.  At 1316 bytes it is the largest row of the file; its
   register allocation and the order of its stores have to be reproduced word for
   word, and the budget of this wave went to the smaller rows of the same file. */
