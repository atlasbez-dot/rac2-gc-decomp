#include "common.h"

/* Near miss: 220 bytes against the retail's 216, with the unit's flags
   -O2 -G8 -ffunction-sections (the two level tables are reached through $gp). */

extern float D_L12_001B1C00 __attribute__((sda));

extern float D_L12_001B1C10 __attribute__((sda));

extern void func_00283098(void *, void *, void *);

extern void func_00282CC0(void *, void *, void *);

extern f32 func_002A89A8(void *, void *, f32);

/* Runs the sub-object's two transforms when its state word is 0xFA5 and its stage byte is 5:
   the third argument takes the level's first table, the second one the second table, and the
   second argument's float at 0x8 grows by two before the update and is put back after it. */
s32 func_L12_00419D68(u8 *a0, void *a1, void *a2)
{
    u8 *s0 = a0;
    void *s1;
    void *s2 = a1;
    void *s3 = a2;

    if (*(s16 *)(s0 + 0xAA) == 0xFA5) {
        if (*(u8 *)(s0 + 0x20) == 5) {
            s1 = s0 + 0xC0;
            func_00283098(s3, &D_L12_001B1C00, s1);
            s0 = s0 + 0x10;
            func_00282CC0(s3, s3, s0);
            func_00283098(s2, &D_L12_001B1C10, s1);
            func_00282CC0(s2, s2, s0);
            *(f32 *)((u8 *)s2 + 8) = *(f32 *)((u8 *)s2 + 8) + 2.0f;
            *(f32 *)((u8 *)s2 + 8) = func_002A89A8(s2, 0, 0.5f);
            return 1;
        }
    }
    return 0;
}
