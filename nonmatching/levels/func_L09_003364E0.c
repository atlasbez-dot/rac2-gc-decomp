/* Nonmatching: 276/280 bytes.
 * Profile: -O2 -G0 -ffunction-sections.
 * Placement checks: US: 0/5; US2: 0/5; PAL: 0/5.
 * 276/280 bytes. Saved-register allocation and branch/copy address setup differ. The typed slot is independently qualified: func_002B9038 returns a pointer/null, uses a 64-byte allocation stride and clears four complete quadwords. Header16, position16, previous-position16 and context16 therefore describe the real storage without padding. The conversion result plus32 supplies byte9, and the second copy is common to both index branches. The earlier complete280-byte variant is archived privately.
 * Reopen with actual slot/position/context lifetimes and allocator conflicts. One complete typed64-byte form was measured; do not add references or change parameter order to manipulate priorities.
 */
#include "common.h"

typedef union {
    u32 words[4];
    u8 bytes[16];
} ParticleHeader;

typedef struct {
    char *object;
    int index;
    int class_id;
    float scale;
} ParticleContext;

/* B9038 allocates at a 64-byte stride and clears all four quadwords. */
typedef struct {
    ParticleHeader header;
    float position[4];
    float previous_position[4];
    ParticleContext context;
} __attribute__((aligned(16))) ParticleSlot;

extern u8 *D_L09_001FF65C;
extern void *func_002B9030(int);
extern int func_00283CF0(float);
extern void func_0029FCC0(char *, int, char *);

char *func_L09_003364E0(char *object, int index, u32 value, int parameter,
                      float first_scale, float second_scale)
{
    ParticleSlot *slot = func_002B9030(0x37);
    float *position;

    if (slot != 0) {
        slot->header.words[1] = value;
        slot->header.words[3] = parameter;
        slot->header.bytes[9] = (u8)(func_00283CF0(0.4f) + 0x20);
        slot->header.bytes[3] = 0x48;
        slot->header.bytes[1] = 3;
        slot->header.bytes[2] = D_L09_001FF65C[0];
        if (index > 0) {
            position = slot->position;
            func_0029FCC0(object, index, (char *)position);
        } else {
            position = slot->position;
            qcopy(position, object + 0x10);
        }
        qcopy(slot->previous_position, position);
        slot->previous_position[3] = second_scale;
        slot->position[3] = first_scale;
        slot->context.object = object;
        slot->context.scale = first_scale;
        slot->context.class_id = *(short *)(object + 0xAA);
        slot->context.index = index;
    }
    return (char *)slot;
}
