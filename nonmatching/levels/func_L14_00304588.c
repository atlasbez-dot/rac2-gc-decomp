/* Near miss from src/levels/14_aranos_prison/L14_00304190-g8.c - 332 bytes, the retail's
 * size, but the words differ in schedule and register allocation.
 *
 * Kept as a starting point; not linked, not counted.
 *
 * The function is the level-14 twin of the matched func_L04_0031D630
 * (src/levels/shared/L04_002CC748.c): it walks the list of mobs at D_001A79F0, gives
 * the ones of type 0xE29 the 0x800 flag, hands the ones of type 0xD54 to
 * func_002E64A0, and gives the ones of type 0xFA0 with a 0x68 pointer that
 * pointer's block (from +0xC) to func_L00_00326048.  The loop, the constants
 * (0x80AAAAD2, 0x80396464, 0.0610865355f) and the call order are the level-04 ones and
 * match retail word for word.
 *
 * The body below compiles to retail's 332 bytes and to retail's instruction count, and
 * the whole loop body (0x3045EC..0x304670) is byte identical.  What differs:
 *
 *   - the loop counter and the mob array pointer are in $s2/$s1 here and in $s1/$s2 in
 *     retail (allocation order of the two pseudos);
 *   - retail's count test is `blezl` (branch likely) with the $gp load of D_001A79F0
 *     in its annulled delay slot, and the load is not folded into the copy that makes
 *     $s3; this cc1 emits `blez` and folds the load into `lw $s3,0x0($gp)`;
 *   - the tail: retail's `bnel` puts the `ld $s0,0x0($sp)` of the epilogue in the
 *     annulled delay slot (so the state pointer is clobbered on the path that skips
 *     the block, and the last call gets the restored register), this cc1 keeps the
 *     pointer in $s0 to the call and restores $s0 after it;
 *   - the argument setup of the func_L00_00326048 call: retail moves $a0 before $a1.
 *
 * Tried here: the do/while form (retail does not rotate the loop, so a `for` is wrong),
 * the list pointer assigned before and inside the `if`, the mob pointer and the state
 * pointer as one variable (that is what makes the register count match: retail reuses
 * $s0, the mob pointer's register, for the state pointer), an explicit walking pointer
 * in the loop, and the count read from the absolute D_L14_001BD200 as the loop
 * condition.  The last two make it worse (340 and 344 bytes).
 *
 * The 0x194 field of the state is read through an uninitialised variable in the path
 * that skips the block, exactly as retail does; the C above spells it with the same
 * variable, so the machine code keeps the same shape.
 */
extern int D_001A79F0;

typedef struct {
    unsigned char pad00[0x34];
    unsigned short flags;
    unsigned char pad36[0x68 - 0x36];
    unsigned int p68;
    unsigned char pad6C[0xAA - 0x6C];
    short type;
} L14Mob;

typedef struct {
    unsigned char pad00[0x30];
    unsigned int field30;
    unsigned char pad34[0x44 - 0x34];
    short count;
    unsigned char pad46[0x18C - 0x46];
    unsigned int mobs[1];
    unsigned char pad190[0x194 - 0x190];
    unsigned int field194;
} L14MobList;

extern L14MobList D_L14_001BD200;

extern void func_L00_002FC980(void *a0);
extern void func_002E64A0(void *mob);
extern void func_L00_00326048(void *mob, void *p, int a2, int a3, float alpha);
extern void func_L08_0037E6D8(void);
extern void func_L03_00326458(void *a0);

void func_L14_00304588(void *a0) {
    L14MobList *list;
    L14Mob *mob;
    int i;

    func_L00_002FC980(a0);
    list = (L14MobList *)D_001A79F0;
    if (D_L14_001BD200.count > 0) {
        i = 0;
        do {
            mob = (L14Mob *)list->mobs[i];

            if (mob != 0 && mob->type == 0xE29) {
                mob->flags |= 0x800;
            }
            if (mob->type == 0xD54) {
                func_002E64A0(mob);
            }
            if (mob != 0 && mob->type == 0xFA0 && mob->p68 != 0) {
                func_L00_00326048(mob, (void *)((unsigned char *)mob->p68 + 0xC), 0x80AAAAD2,
                                  0x80396464, 0.0610865355f);
            }
            i++;
        } while (i < list->count);
    }
    if (D_001A79F0 == 0xE) {
        mob = (L14Mob *)&D_L14_001BD200;
        if (*(unsigned int *)((unsigned char *)mob + 0x30) == 0) {
            func_L08_0037E6D8();
        }
    }
    func_L03_00326458((void *)(long)*(unsigned int *)((unsigned char *)mob + 0x194));
}
