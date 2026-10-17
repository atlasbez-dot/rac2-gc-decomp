#include "include_asm.h"

INCLUDE_ASM("asm/levels", func_L13_002D5ED8);

#ifndef RAC2_T_TABLE_389848
#define RAC2_T_TABLE_389848
typedef struct {
    int entries[64];    /* +0x000 */
    int count;          /* +0x100 */
} Table_389848;
#endif

#ifndef RAC2_T_OBJ_389848
#define RAC2_T_OBJ_389848
typedef struct {
    char pad[0xAA];
    short key;          /* +0xAA */
} Obj_389848;
#endif

extern Table_389848 ref_L13_00232450_00;

/* Adds the object's key to the level's list when it is not already there: the count at +0x100
 * bounds a linear search over the words at +0, and an absent key is appended at the count
 * before the count is bumped. */
void func_L13_00389848(Obj_389848 *object)
{
    int found = 0;
    int i;

    for (i = 0; i < ref_L13_00232450_00.count; i++) {
        if (ref_L13_00232450_00.entries[i] == object->key) {
            found = 1;
            break;
        }
    }
    if (found == 0) {
        ref_L13_00232450_00.entries[ref_L13_00232450_00.count] = object->key;
        ++ref_L13_00232450_00.count;
    }
}

INCLUDE_ASM("asm/levels", func_L13_0038C1B8);

INCLUDE_ASM("asm/levels", func_L13_003C5908);

INCLUDE_ASM("asm/levels", func_L13_003ECD48);

INCLUDE_ASM("asm/levels", func_L13_003ECEA8);

INCLUDE_ASM("asm/levels", func_L13_00406E30);
