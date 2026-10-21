/* from src/game/00288D88.c: C that compiles close to the function but not to
   its bytes (tools/check.py: 0 of 28 places match, 100 bytes against 108).

   The function looks the key up in the table of sixteen-byte entries the level
   keeps and returns the index of the entry, or -1.  Retail re-reads the length
   of the table from memory on every pass of the loop and computes the entry
   address with a shift and an add instead of an induction variable, so the
   retained trial uses a volatile count to preserve reloads and tries to avoid
   strength reduction. This is a code-generation experiment, not evidence that
   the original count's type was volatile; it is not an accepted match.

   What still differs: retail keeps the high half of the length block's address
   in $t0 and re-materialises the address in the loop, this cc1 keeps the whole
   address in $a3; retail computes the entry address with "sll $v0,$a1,4;
   addu $v0,$v0,$a3; lw $v1,0x4($v0)", this cc1 strength-reduces it into an
   induction variable ("addiu $v1,$v1,0x10; lw $v0,0x0($v1)").  Eight wordings
   of the loop (a for loop, a while loop, an int array, a struct array, a
   2D array, the count through a pointer) all compile to the same bytes. */

typedef struct { int unk00; int key; int unk08; int unk0C; } SelectorEntry;

typedef struct { char pad00[0x2C]; int count; } SelectorCount;

extern volatile SelectorCount ref_L00_00288F48_00;
extern SelectorEntry *ref_L00_00288F48_01;

int func_00288F48(int key)
{
    int found = -1;
    int i = 0;
    SelectorEntry *table;

    if (ref_L00_00288F48_00.count > 0) {
        table = ref_L00_00288F48_01;
        if (table[0].key == key) {
            found = 0;
        } else {
            while (++i < ref_L00_00288F48_00.count) {
                if (table[i].key == key) {
                    found = i;
                    break;
                }
            }
        }
    }
    return found;
}
