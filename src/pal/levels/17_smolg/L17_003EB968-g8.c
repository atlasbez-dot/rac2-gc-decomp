#include "include_asm.h"
#include "common.h"
extern s32 func_L17_00340DD0(f32, s32, s32, s32);
extern f32 D_L17_001B04B8 __attribute__((sda));
extern void func_002A7750(void *, s32, s32);
extern s32 func_002A9640(void *, s32, s32);
extern void func_L00_0032A258(void *, void *, void *, void *, s32, s32, s32, s32, s32, s32, s32);
extern void func_0032C700(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32, s32);
extern void func_0029F338(void *);
extern s32 D_L17_001B1E00 __attribute__((sda));
extern s32 D_L17_001B1DE0 __attribute__((sda));
extern s32 D_L17_001B1DD8 __attribute__((sda));
extern s32 D_L17_001B1DD0 __attribute__((sda));

/* Sets the object's stage up: the first stage asks the level's own spawner for a child and
   gives up its handle, the second one only releases the handle. */
void func_PAL_L17_0041E460(s32 a0)
{
    u8 v = *(u8 *)(a0 + 0x20);

    switch (v) {
    case 0:
        func_002A7750(a0, 1, -1);
        break;
    case 1:
        if (func_002A9640(a0, 0x4010001, 0) != 0) {
            func_002A7750(a0, 2, -1);
            *(u8 *)(a0 + 0xA8) = 0xFF;
        }
        break;
    case 2:
        func_L00_0032A258(a0, &D_L17_001B1DE0, &D_L17_001B1DD8, &D_L17_001B1DD0,
                          0xFFFF, 0, D_L17_001B1E00, 0, 0xFFFF, 0xFF, 0);
        func_0032C700(a0 + 0x10, 0, 12, 10, 10, 10, 0, 0,
                      *(f32 *)(a0 + 0x2C) * 10.0f, 20.0f, 1, 0, 0, 0);
        func_0029F338(a0);
        break;
    }
}
