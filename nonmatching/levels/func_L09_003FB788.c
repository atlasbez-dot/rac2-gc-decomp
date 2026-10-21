/* 0 of 1 places match - last line: 09_dobbo: instruction at +0x20 differs (216 bytes, retail 216)
   Releases the first slot of the record-slot manager that holds the id in
   either half: both halves of the slot table, the slot's flag word and the two
   live handles (0x1B36E0 and 0x1B3720) are cleared, and each live handle is
   given back to func_00291450. 1 when a slot was found.

   Measured: 23 of the 54 words differ, and every one of them is the same
   instruction with a different register; the shape is retail's word for word
   otherwise - the `beql`/`bnel` pair with the id compare and the index
   increment in the delay slot, the `sll` of the index for the 0x1B3720 table,
   the two zero stores of the slot table in retail's order, the frame (0x30) and
   the save order (s2, s3, s0, s1).
   What differs: the register allocation of the three induction variables.
   Retail puts the loop index in $a1, the flag word's pointer in $a2 and the
   slot table's pointer in $v1; this cc1 puts the flag word's pointer in $a1,
   the slot table's pointer in $a2 and the index in $v1 - the same three
   registers, rotated by one, with the index last.  The index is the value
   retail holds in an argument register and this cc1 holds in the last free one.
   Tried (about ten compiles): the index form with `i * 2` and `i * 2 + 1`, a
   struct of two ints for the slot table, explicit pointer variables walked by
   hand, a while loop with the increment in the body, `i <= 15` instead of
   `i < 16`, unsigned tables and id, the two zero stores in both orders, and
   three statement orders for the found block; all of them give the same
   allocation and the same 23 words.
   Would unblock: a cc1 lever that gives the loop's induction variable an
   argument register, or a source shape that makes the index a real induction
   variable of the loop rather than a strength-reduced one. */
extern int D_L09_00255E90[];
extern int D_L09_001B35E0[];
extern int D_L09_001B36E0[];
extern int D_L09_001B3720[];

extern void func_00291450(int);

int func_L09_003FB788(int id) {
    int i;
    for (i = 0; i < 16; i++) {
        if (D_L09_00255E90[i * 2] == id || D_L09_00255E90[i * 2 + 1] == id) {
            D_L09_001B35E0[i] = 0;
            D_L09_00255E90[i * 2] = 0;
            D_L09_00255E90[i * 2 + 1] = 0;
            if (D_L09_001B36E0[i] != -1) {
                func_00291450(D_L09_001B36E0[i]);
                D_L09_001B36E0[i] = -1;
            }
            if (D_L09_001B3720[i] != -1) {
                func_00291450(D_L09_001B3720[i]);
                D_L09_001B3720[i] = -1;
            }
            return 1;
        }
    }
    return 0;
}
