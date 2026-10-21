/* func_00283678 - 32 bytes, 28 places (the boot and every level), retail at
   0x00283678: lq $1,0($a1) ; lq $2,0x10($a1) ; lq $3,0x20($a1) ;
   sq $1,0($a0) ; sq $2,0x10($a0) ; sq $3,0x20($a0) ; jr $ra ; nop.
   The MMI lq/sq words carry their base register in bits 25-21, their quad
   register in bits 20-16 and their offset in bits 10-0, so the body is a
   48-byte copy from $a1 to $a0 - two pointer arguments, not three.
   The candidate below is that copy, but three things differ: this cc1
   allocates the quad registers $2, $3 and $6 instead of $1, $2 and $3; it
   emits the loads and the stores in another order (with
   -fno-schedule-insns the order comes out right); and it sinks the last
   store into the `jr $ra` delay slot instead of leaving a nop there.
   What would unblock it: the quad register allocation and an empty delay
   slot. */
typedef int TI128 __attribute__((mode(TI)));
typedef unsigned char u8;

void func_00283678(void *a0, void *a1) {
    TI128 t0, t1, t2;
    t0 = *(TI128 *)a1;
    t1 = *(TI128 *)((u8 *)a1 + 0x10);
    t2 = *(TI128 *)((u8 *)a1 + 0x20);
    *(TI128 *)a0 = t0;
    *((TI128 *)((u8 *)a0 + 0x10)) = t1;
    *((TI128 *)((u8 *)a0 + 0x20)) = t2;
}
