#include "include_asm.h"

/* func_L11_002DE9E0 is in the sibling file L11_002DE9E0-decider.c (its own profile). */



typedef struct {
    unsigned char pad00[0x34];
    unsigned short flags;
    unsigned char pad36[0x68 - 0x36];
    unsigned int p68;
    unsigned char pad6C[0xAA - 0x6C];
    short type;
} Mob_L11_0030F060;

typedef struct {
    unsigned char pad00[0x30];
    int mode;
    unsigned char pad34[0x44 - 0x34];
    short count;
    unsigned char pad46[0x18C - 0x46];
    Mob_L11_0030F060 *mobs[1];
} MobList_L11_0030F060;

extern MobList_L11_0030F060 ref_L11_0030F060_00;
extern int D_001A79F0 __attribute__((sda));
extern void func_L00_002FC980(void);
extern void func_002E64A0(void *);
extern void func_L00_00326048(void *, void *, int, int, float);
extern void func_L00_002E6CF0(void *, void *);
extern void func_L11_0030ED58(void *);

/* Walks the level's list of mobs like func_L02_00300CE8; when the game state is 0xB and the
   list's word at +0x30 is 2 it queues func_L11_0030ED58. */
void func_L11_0030F060(void) {
    int i;

    func_L00_002FC980();
    for (i = 0; i < ref_L11_0030F060_00.count; i++) {
        Mob_L11_0030F060 *mob = ref_L11_0030F060_00.mobs[i];

        if (mob != 0 && mob->type == 0xE29)
            mob->flags |= 0x800;
        if (mob->type == 0xD54)
            func_002E64A0(mob);
        if (mob != 0 && mob->type == 0xFA0 && mob->p68 != 0)
            func_L00_00326048(mob, (unsigned char *)mob->p68 + 0xC, 0x80AAAAD2, 0x80396464, 0.0610865355f);
    }
    if (D_001A79F0 == 0xB && ref_L11_0030F060_00.mode == 2)
        func_L00_002E6CF0(func_L11_0030ED58, 0);
}



extern void func_00282CF0(void *, void *, void *);
extern void func_L02_00333480(char *, char *, void *);

INCLUDE_ASM("asm/levels", func_L11_00340500);

INCLUDE_ASM("asm/levels", func_L11_00369700);

INCLUDE_ASM("asm/levels", func_L11_00396DC8);

/* func_L11_003973F8 is matched in its own unit, src/levels/11_joba/L11_003973F8-qcopy.c (-frac2-qcopy -frac2-qcopy-barrier). */

INCLUDE_ASM("asm/levels", func_L11_003974A8);

INCLUDE_ASM("asm/levels", func_L11_00397820);
INCLUDE_ASM("asm/levels", func_L11_003982F0);

INCLUDE_ASM("asm/levels", func_L11_003983F0);

INCLUDE_ASM("asm/levels", func_L11_003A2FF0);

INCLUDE_ASM("asm/levels", func_L11_003A3408);

INCLUDE_ASM("asm/levels", func_L11_003A89E8);
