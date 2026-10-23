/* func_L09_002F8FD8 - 336 bytes, 1 place, level 09_dobbo, retail at 0x002F8FD8.
   Screened, not attempted in this wave: the body is understood, but no C was written
   for it, so nothing here is a measurement.

   The retail body, in order:
     - calls func_L00_002FC980 (level 09's copy at 0x002F8D70);
     - reads the signed halfword at 0x1BD744 (0x1BD700 + 0x44) and stops when it is
       not positive;
     - takes the table of pointers at (*(0x1A79F0) + 0x18C), stride 4, and walks it
       while the counter stays below that halfword:
         * reads the signed halfword at entry + 0xAA;
         * when it is 0xE29, sets bit 0x800 in the halfword at entry + 0x34;
         * when it is 0xD54, calls func_002E64A0(entry);
         * when it is 0xFA0, reads the pointer at entry + 0x68 and, when that is not
           0, calls func_L00_00326048(entry, pointer + 0xC, 0x80AAAAD2, 0x80396464,
           0x3D7A35E0f) - the two integers are built with lui/ori and the float with
           lui/ori into $at and mtc1, so they are plain constants;
       the walk's exit reloads the halfword at 0x1BD744 (the callees may change it);
     - after the walk, when the word at 0x1A79F0 is 9 and the word at 0x1BD730 is 1,
       calls func_L00_002E6CF0(0x2F8BA0, *(0x1BD894)) - 0x2F8BA0 is this file's own
       func_L09_002F8BA0, so the first argument is a function pointer.

   The two calls inside the walk are the level's copies of the boot bodies
   func_002E64A0 and the shared func_L00_00326048; the entry point's first argument is
   a pointer to a 0x100-byte object whose +0x68 holds a second pointer.

   What is left for the next worker: the branch shape around the 0xE29 / 0xD54 / 0xFA0
   tests. Retail's control flow is unusual and worth writing down before any C:
     002F903C  beqz  $s0, -> 002F905C      ; a null entry skips the 0xE29 test
     002F9040  lh    $v0, 0xAA($s0)        ; ... but the delay slot reads it anyway
     002F9044  bne   $v0, $s6, -> 002F905C  ; $s6 = 0xE29
     002F904C  lhu   $v0, 0x34($s0)
     002F9050  ori   $v0, $v0, 0x800
     002F9054  sh    $v0, 0x34($s0)
     002F9058  lh    $v0, 0xAA($s0)        ; reloaded: the store may alias
     002F905C  bne   $v0, $s5, -> 002F906C  ; $s5 = 0xD54
     002F9064  jal   func_002E64A0
     002F906C  beql  $s0, $zero, -> 002F90B4
     002F9074  lh    $v0, 0xAA($s0)
     002F9078  bnel  $v0, $s4, -> 002F90A8  ; $s4 = 0xFA0
   The load of +0xAA sits in the delay slot of the null test, so the code reads
   entry + 0xAA even for a null entry (a read of address 0xAA). Any C that keeps the
   null test and the load in that order reproduces it; a C that guards the load does
   not. The branch-likely instructions (beql, bnel) always run their delay slot on this
   hardware, so the source's `&&`/`||` spelling has to be measured, not assumed. */
