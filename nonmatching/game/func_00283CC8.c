/* func_00283CC8 - 24 bytes, 28 places (the boot and every level), retail at
   0x00283cc8: cvt.w.s $f0,$f12 ; cvt.s.w $f0,$f0 ; swc1 $f0,0($a0) ;
   sub.s $f0,$f12,$f0 ; jr $ra ; nop.  The store is to $a0 and the float
   argument is in $f12, so the prototype is (f32 *, f32).  Same wall as
   func_00283CB8: this cc1 moves the truncated integer through a GPR
   (mfc1/mtc1), so the candidate is 36 bytes, it keeps the truncated value
   in $f1 instead of $f0, and it sinks the store into the `jr $ra` delay
   slot instead of leaving a nop there.
   What would unblock it: a source whose float->int->float conversion stays
   in the FPU and whose store is not schedulable into the delay slot. */
typedef float f32;

f32 func_00283CC8(f32 *a0, f32 a1) { f32 b = (f32)(int)a1; *a0 = b; return a1 - b; }
