/* func_L09_003FB650 (300 bytes, 1 place) -- NEAR MISS, not integrated.
   state: 304 bytes, 4 over retail's 300; the two searches, the ten stores and the nine
   induction variables are retail's, the register allocation of the arguments and of the
   nine table addresses is not.
   check.py (09_dobbo), with the source below:
     09_dobbo: 304 bytes, expected 300
   Retail's body: a first pass over sixteen eight-byte slots that returns 1 as soon as the
   id is live in either half, then a second pass that takes the first free slot, writes
   the id and the value into it and fills the nine parallel int[16] tables, and returns 0
   when every slot is taken. The second pass keeps nine pointers, one per table, and
   advances them in the loop's increment block; this cc1 does the same.

   What is measured and right:
   - the slot table is a pair of ints (stride 8): `lw $v0,0($v1)` and `lw $v0,4($v1)`
     with $v1 stepping by 8, so the source indexes a two-int struct.
   - the nine tables are int[16] each, at 0x1B35E0, 0x1B3620, 0x1B3660, 0x1B36A0,
     0x1B36E0, 0x1B3720, 0x1B3760, 0x1B37A0 and 0x1B37E0 (0x40 apart, 0x1B35E0 first),
     and the two handles among them (0x1B36E0 and 0x1B3720) are the ones the matched
     func_L09_003FB788 gives back.
   - retail writes the slot's second half first and its first half in the middle of the
     block, and the last table's zero lands in the exit branch's delay slot; the order of
     the ten stores in the source does not decide that, the scheduler does.
   Tried and not enough: the ten stores in retail's order (304 bytes, same as the order
     below); the table as a flat int array instead of a struct of two ints.
   Next idea: the register allocation. Retail keeps the id, the third and the fourth
   argument in $a0, $a2 and $a3 and copies only the value into $s0 (because $a1 is
   reused for the -1 constant), while this cc1 copies all four arguments into $t5, $t9,
     $s0 and $s1 and puts three of the nine table pointers in $a0-$a3. A source that
     needs fewer live values in the second pass (fewer table addresses materialised at
   once, or the tables reached through one base) would change that. */

typedef struct {
    int first;
    int second;
} Slot_L09_00255E90;

extern Slot_L09_00255E90 D_L09_00255E90[];
extern int D_L09_001B35E0[];
extern int D_L09_001B3620[];
extern int D_L09_001B3660[];
extern int D_L09_001B36A0[];
extern int D_L09_001B36E0[];
extern int D_L09_001B3720[];
extern int D_L09_001B3760[];
extern int D_L09_001B37A0[];
extern int D_L09_001B37E0[];

/* Starts a record slot: the first pass returns 1 when the id is already live in either
   half of a slot, the second takes the first free slot, fills its eight parallel tables
   and returns 1; 0 when every slot is taken. */
int func_L09_003FB650(int id, int value, int third, int fourth)
{
    int i;

    for (i = 0; i < 16; i++) {
        if (D_L09_00255E90[i].first == id)
            return 1;
        if (D_L09_00255E90[i].second == id)
            return 1;
    }
    for (i = 0; i < 16; i++) {
        if (D_L09_00255E90[i].first == 0) {
            D_L09_00255E90[i].second = value;
            D_L09_001B3720[i] = -1;
            D_L09_001B3760[i] = third;
            D_L09_001B37A0[i] = fourth;
            D_L09_001B35E0[i] = 1;
            D_L09_00255E90[i].first = id;
            D_L09_001B3620[i] = 0;
            D_L09_001B3660[i] = 0;
            D_L09_001B36A0[i] = 0;
            D_L09_001B36E0[i] = -1;
            D_L09_001B37E0[i] = 0;
            break;
        }
    }
    return 0;
}
