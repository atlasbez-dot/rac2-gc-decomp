#include "include_asm.h"
#include "common.h"

extern s32 D_L10_001B0F44 __attribute__((sda));
extern s32 D_L10_001B0F48 __attribute__((sda));

s32 func_L10_004176A0(void) {
    s32 v = D_L10_001B0F44;
    D_L10_001B0F44 = 0;
    return v;
}

s32 func_L10_004176B0(void) {
    s32 v = D_L10_001B0F48;
    D_L10_001B0F48 = 0;
    return v;
}

extern s32 D_L10_001B0F44 __attribute__((sda));
extern s32 D_L10_001B0F48 __attribute__((sda));
extern u8 D_L10_00265BA0[];
extern u8 *D_L10_001FB1E0[];
extern u8 *D_001B251C;

/* Clears the arena's 128 records of 0x60 bytes and then walks the entry's two-byte
   id list, flagging every live object of one class. */
void func_L10_00417440(u8 *arg0) {
    s32 *p;
    s32 i;
    u8 *q;
    u16 *r;
    u8 *e;

    D_L10_001B0F44 = 0;
    p = (s32 *)D_L10_00265BA0;
    D_L10_001B0F48 = 0;
    p = (s32 *)((u8 *)p + 0x2FE0);
    for (i = 0x7F; i >= 0; i--) {
        *p = 0;
        p -= 0x18;
    }
    q = D_L10_001FB1E0[arg0[0x21]];
    if (q == 0)
        return;
    r = (u16 *)q;
    do {
        e = D_001B251C + ((*r & 0x7FFF) << 8);
        e[0x20] = 1;
        if ((s16)*r < 0)
            break;
        r++;
    } while (1);
}
