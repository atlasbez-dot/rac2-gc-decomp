/* Nonmatching: 240/240 bytes.
 * Profile: -O2 -G0 -ffunction-sections.
 * Placement checks: US: 0/1; US2: 0/1; PAL: 0/1.
 * 240/240 bytes. The source keeps real actor-pointer pairs,64-byte record blocks and16-byte secondary vectors with incomplete outer extents. Separate field cursors recover the frame and main loop, but initial global materialization, the registers for constants1/2 and cursor-increment scheduling differ.
 * Reopen with actual manager-column cursor lifetimes and allocator evidence. Do not permute prototypes, invent extents or add loop padding.
 */
#include "common.h"

typedef int Quad __attribute__((mode(TI)));
typedef struct { char *first, *second; } RecordActors;
typedef struct { unsigned char fields[0x30]; Quad position; } RecordBlock;
extern RecordActors D_L09_00255E90[];
extern int D_L09_001B35E0[];
extern RecordBlock D_L09_00255F10[];
extern Quad D_L09_00256310[];
extern void func_00282B50(void *, void *, int);

int func_L09_003FB908(char *object, void *src)
{
    RecordActors *actors = D_L09_00255E90;
    RecordBlock *block = D_L09_00255F10;
    Quad *position = &block->position;
    Quad *secondary = D_L09_00256310;
    int *flag = D_L09_001B35E0;
    int i;
    for (i = 0; i < 16; i++, actors++, block++, flag++, secondary++,
                             position = (Quad *)((char *)position + 0x40)) {
        if (actors->first == object || actors->second == object) {
            if (*flag == 1)
                *flag = 2;
            else if (*flag == 4)
                *flag = 3;
            func_00282B50(block, src, 0x40);
            qcopy(position, actors->first + 0x10);
            qcopy(secondary, actors->second + 0x10);
            return 1;
        }
    }
    return 0;
}
