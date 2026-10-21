/* func_00293F98 (216 bytes, 28 places) -- NEAR MISS, not integrated.
   state: 220 bytes, the instruction sequence follows retail from the first call on,
   but the register allocation does not: ours keeps four callee-saved registers
   (the frame is 0x30) where retail keeps two (0x20), and the arguments of the
   first call are loaded in the other order.

   Retail (boot 0x00293F98):
     00293FBC  addu   $a2, $v0, $v1     ; entry = D_0014B540 + index * 8
     00293FC8  lw     $a3, 0x3E28($a2) ; the third field of the entry
     00293FD4  lw     $a1, 0x3E24($v0) ; the first field of the table
     00293FD8  lw     $a2, 0x3E2C($v1) ; the fourth field of the entry
     00293FDC  lw     $a0, 0x70($s1)   ; the record of the world state
     00293FE4  addu   $a1, $a3, $a1    ; the sum, in the delay slot
   and the loop that fills the state with the offsets of the parts:
     00294030  addiu  $a1, $a1, 0x8    ; the record steps by eight bytes
     00294034  addiu  $v0, $v0, 0x800
     00294038  slti   $a0, $a3, 0x46   ; at most 0x46 entries
     00294040  sw     $v1, 0x0($a2)

   What is measured and right:
   - the table is D_0014B540, the world state D_001B8840, both below 0x1A7C80, so
     the same address in every program; the entry stride is eight bytes.
   - the sum that goes to the second argument is the entry's 0x3E28 plus the
     table's 0x3E24, and the third argument is the entry's 0x3E2C.
   - the state word at 0x30 takes the index, the word at 0x70 is the record, and
     the list of the part offsets starts at 0x74.
   - the three calls around the list are func_002B7CE0(0), func_0027D330(flag),
     func_002B7CE0(1).

   What is left:
   - the record pointer must be read again from the state in every step of the
     loop (the store into the list may alias it): keeping it in a local is what
     gives the extra frame and the extra $s3.
   - the order of the two loads that build the second argument (0x3E28 before
     0x3E24) decides which of them lands in the delay slot.
   Tried: the record in a local (the frame grows to 0x30, 220 bytes); the record
   read again in the loop (the frame shrinks, the argument order stays wrong). */

extern int F46b87d1_D_0014B540[];

extern int F46b43b72_D_001B8840[];

extern void F46b43b72_FUN_002B7B18();

extern void F46b43b72_FUN_002B7CE0(int value);

extern void func_0027D330(int);

/* The record the world state points at: the offset of its first part and the
   number of the parts that follow. */
struct PartRec {
    int flags;
    int count;
};

void func_00293F98(int index, int flag)
{
    char *entry = (char *)F46b87d1_D_0014B540 + (index << 3);
    char *state = (char *)F46b43b72_D_001B8840;
    struct PartRec *rec = *(struct PartRec **)(state + 0x70);
    int i;

    F46b43b72_FUN_002B7B18(*(int *)(state + 0x70),
                          *(int *)(entry + 0x3E28) + *(int *)((char *)F46b87d1_D_0014B540 + 0x3E24),
                          *(int *)(entry + 0x3E2C));
    if (flag != 0) {
        F46b43b72_FUN_002B7CE0(0);
        func_0027D330(flag);
        *(int *)(state + 0x30) = index;
        F46b43b72_FUN_002B7CE0(1);
        for (i = 0; i < 0x46 && rec->count != 0; i++) {
            *(int *)(state + 0x74 + 4 * i) = *(int *)(state + 0x70) + rec->flags + 0x800;
            rec = (struct PartRec *)((char *)rec + 8);
        }
    }
}
