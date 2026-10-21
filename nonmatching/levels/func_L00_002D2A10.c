/* Not attempted - screened, no C written: 1112 bytes, 22 places.

   The screening: every branch of the body stays inside its own bytes (the `jal`
   calls excepted), so the row is a whole function and not a catalogue fragment.
   Ten of the words are MMI (0x78/0x7A/0x7C/0x7E), five `lq`/`sq` pairs, which
   plain C reaches through a `mode(TI)` copy; no COP2 (VU0) word and no multiply or
   divide.  Nothing in the row looks like handwritten assembly.

   The body is the game's "the object the caller's argument names" handler in its
   long form: it builds several matrices, transforms vectors through them, and
   writes the results into the resident state.  At 1112 bytes it is three times the
   size of the body this wave matched, and its register allocation (seven
   callee-saved registers) and the order of its stores have to be reproduced word
   for word; the budget of this wave went to the smaller rows of the same file. */
