/* 0 of 1 places match - last line: 09_dobbo: instruction at +0x20 differs (240 bytes, retail 240)
   Starts a record slot of the record-slot manager: it finds the slot that holds
   the id in either half, moves the slot's flag from 1 to 2 or from 4 to 3,
   copies 0x40 bytes into the slot's block, and copies the two ids' own 8 bytes
   into the slot's two vectors.  Needs the grouped quadword copy
   (-frac2-qcopy) for the two 8-byte copies.

   Measured with -O2 -G0 -ffunction-sections -frac2-qcopy: 31 of the 60 words
   differ, and every one of them is the same instruction with a different
   register; the shape is retail's word for word otherwise - the `beql`/`bnel`
   pair, the flag's two-step test (1 to 2, 4 to 3) with the stores in the
   delay slots, the frame (0x20), the save order and the 0x40/0x40/0x10/0x08
   strides.
   What differs: the register allocation of the loop's values.  Retail puts the
   index in $a2, the memcpy's destination in $a3 and the flag word's pointer in
   $v1, and the constants 1, 2, 4, 3 in $t3, $t2, $t0, $t1; this cc1 puts the
   memcpy's destination in $a2, the flag word's pointer in $a3, the index in
   $v1 and the constant 4 in $a3 - the index is again the value retail holds in
   an argument register and this cc1 holds in the last free one.
   The address materialisation is retail's: the block at 0x255F40 comes from
   0x255F10 + 0x30 in retail's own `addiu $s1,$v0,0x30`, so the source must
   name one symbol and add the offset.
   Tried (about six compiles): the flag value in a local, the copy's
   destination named as its own symbol and derived from 0x255F10 + 0x30, the
   index form against explicit pointer walks, `i <= 15`, and -frac2-qcopy with
   -mno-split-addresses, -fno-schedule-insns, -fno-gcse, -fno-strength-reduce
   and -mastra-keep-frame-order; none of them moves the index.
   Would unblock: a cc1 lever that gives the loop's induction variable an
   argument register. */
typedef int TI __attribute__((mode(TI)));

extern int D_L09_00255E90[];
extern int D_L09_001B35E0[];
extern unsigned char D_L09_00255F10[];
extern unsigned char D_L09_00256310[];
extern void func_00282B50(void *, void *, int);

int func_L09_003FB908(int id, void *src) {
    int i;
    for (i = 0; i < 16; i++) {
        if (D_L09_00255E90[i * 2] == id || D_L09_00255E90[i * 2 + 1] == id) {
            int f = D_L09_001B35E0[i];
            if (f == 1)
                D_L09_001B35E0[i] = 2;
            else if (f == 4)
                D_L09_001B35E0[i] = 3;
            func_00282B50(D_L09_00255F10 + i * 0x40, src, 0x40);
            *(TI *)(D_L09_00255F10 + i * 0x40 + 0x30) = *(TI *)(D_L09_00255E90[i * 2] + 0x10);
            *(TI *)(D_L09_00256310 + i * 0x10) = *(TI *)(D_L09_00255E90[i * 2 + 1] + 0x10);
            return 1;
        }
    }
    return 0;
}
