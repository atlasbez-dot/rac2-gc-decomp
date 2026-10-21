/* No attempt: the catalogue's extent for func_00335918 is 32 bytes too long at
   the front.  The extent starts on sw $zero, 0x118($a0) ; nop ; addiu $sp, $sp, 0x10 ; nop ; addiu $sp, $sp, 0x30 ; nop ; addiu $sp, $sp, 0x20 ; nop
   - the epilogue area of the previous function, which no C can produce at the
   start of a function - and the body starts at +0x20 with `addiu $sp, $sp, -0x10`.  The bytes in between belong to no
   catalogued function, the same catalogue defect as func_L00_00341798 and
   func_L00_002E6440.  A fix in tools/levels.py that moves the start of the
   extent to the prologue would make the function matchable. */
