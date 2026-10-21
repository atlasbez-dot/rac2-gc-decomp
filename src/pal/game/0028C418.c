#include "include_asm.h"

typedef struct {
    char pad0[0x8];
    int unk08;
    int *unk0C;
    char pad10[0x38];
    short unk48;
    short unk4A;
    char pad4C[0x4];
    int unk50;
    int unk54;
    int w;
    int h;
    int flags;
    char pad64[0x8];
    int unk6C;
    unsigned char cnt[4];
    int unk74;
    int unk78;
    int unk7C;
    void *unk80;
} HudElem;
typedef unsigned char u8;

void func_PAL_0028C418(HudElem *a0) { a0->unk7C = 0xB4; a0->unk48 = 0; a0->unk4A = 0; func_0028B950((u8 *)a0); }

INCLUDE_ASM("asm/pal/game", func_PAL_0028C450);
