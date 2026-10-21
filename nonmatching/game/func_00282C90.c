/* func_00282C90 - 8 bytes, 28 places (the boot and every level), retail at
   0x00282c90: jr $ra ; sdc2 $0, 0($a0).  The store is a VU0 double store
   (opcode 111110, the base register in bits 25-21, the register in bits
   20-16 and the offset in bits 10-0); this cc1 stores a double through a
   GPR pair (`sd $a1,0($a0)`), because it passes the double in $a1/$a2
   instead of $f0/$f1.  Not matched: no C emits the VU's sdc2.
   What would unblock it: a source that keeps the double in the FPU's
   $f0/$f1 pair, or the proof that the body is VU0 assembly. */
void func_00282C90(double *a0, double a1) { *a0 = a1; }
