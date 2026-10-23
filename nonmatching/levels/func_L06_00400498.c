/* func_L06_00400498 (348 bytes, 1 place) -- SCREENED, no candidate compiled in this
   attempt; the body is decoded and the notes below are what a next worker needs.

   The function is the "a moby that has just come alive" handler.  It reads the moby's
   state block (the pointer at +0x68), and:

     - if the block is null it returns at once (retail's `beql $s0,$zero`, whose delay
       slot restores $s0);
     - it calls func_35A198(0, 0) with the moby as the first argument, zeroes the word
       at +0x48, sets the byte at +0x20 to 1, copies the float at +0x18 of the moby to
       +0x8 of the block and the float at +0x4 of the block to +0xC of it;
     - it looks the block's first word up in the level's table at D_L06_001B281C (the
       word at 0x1B281C, indexed with the word shifted left by eight, which is the
       same table the -g8 sibling file uses), takes the byte at +0x14 of the entry it
       finds and clears a flag when that byte is zero (`movn $s2,$zero,$v1`);
     - it calls func_32E6B8 with the float at +0xC of the block and compares the
       result with the level's float constant D_L06_001AFE40 (read through $gp, so the
       body needs the -G8 sibling) times 0x3998825C; the first comparison is a
       `c.lt.s`/`bc1tl` pair and the second a `c.lt.s`/`bc1fl` pair, and the two calls
       pass 0x4049FDC and 0.0f as the third argument;
     - it then calls func_3A0948(0, 0, moby), and, when the flag is clear, calls
       func_32E5D0 with the float at +0xC scaled by 0.3f (the constant at +0xE50 of
       $gp times 0x3998825C) and stores the result back at +0xC;
     - it calls func_32DBD0 with that float, doubles it, takes the float at +0x8 of the
       block, subtracts 2.0f and adds the doubled value, and writes the sum to +0x18
       of the moby.

   The two float constants of the file are the level's own: D_L06_001AFE40 (read
   through $gp) and the literal 0x3998825C that retail materialises with lui/ori.

   What blocks a candidate here: the function reads a global through $gp, so it has to
   live in the -G8 sibling file L06_0033BDC0-g8.c, next to the two functions of that
   unit that are already matched (func_L06_00402440 and func_L06_00403F60).  The
   branch-likely float comparisons (bc1tl / bc1fl with the comparison in the delay
   slot) and the two delay slots that hold the lwc1 of the constant are the parts
   that have to come out of one source spelling, as in the matched siblings. */
