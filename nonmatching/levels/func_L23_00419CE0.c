/* func_L23_00419CE0 (128 bytes, 1 place) -- measured 0 of 1: candidate is 136 bytes,
   four words over (four source shapes tried). (Wave 6, Docker-free ruler; provisional.)

   Retail walks the set bits of the incoming 64-bit mask and answers whether exactly
   one bit is set, at an index the shared predicate accepts:
     v1 = 0 (index, in the blez delay slot) ; a2 = 0 ; a1 = 0 (count)
     loop: bit = a0 & 1 (sign-extended through dsll32/dsra32)
           beql bit,0 -> index++ and continue      (the increment is annulled into the slot)
           count++ ; if (count >= 2) return 0      (slti $a1,0x2 + beqz)
           found = index (a2 = v1, in the branch's delay slot) ; index++
           if (index < 0x40) { a0 >>= 1; loop }
     beqz count -> return 0 ; if (count != 1) -> return 0
     jal func_L23_00419CA0(found) ; return (ret == 0)

   The `dsll32/dsra32` pair means the mask is a SIGNED 64-bit value (the 32-bit andi
   result sign-extends), and the two `index++` copies in the branch delay slots are
   likely-branch (reorg) duplications, so a single `i++` in the source is expected.
   Both s64 and u64 masks, do/while and for, and two declaration orders were measured;
   all land 8 bytes over, so the tail (the two count tests plus the call) is the part
   that still differs.
*/

typedef long long s64;
typedef int s32;

extern s32 func_L23_00419CA0(s32);

s32 func_L23_00419CE0(s64 arg0) {
    s32 i = 0;
    s32 count = 0;
    s32 found = 0;

    do {
        if ((arg0 & 1) != 0) {
            count++;
            if (count >= 2)
                return 0;
            found = i;
        }
        i++;
        arg0 >>= 1;
    } while (i < 0x40);

    if (count == 0)
        return 0;
    if (count != 1)
        return 0;
    if (func_L23_00419CA0(found) == 0)
        return 1;
    return 0;
}
