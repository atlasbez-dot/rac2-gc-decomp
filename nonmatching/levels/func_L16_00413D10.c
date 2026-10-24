/* -O2 -G8 -frac2-qcopy -frac2-qcopy-barrier -mno-split-addresses; US and US2: 16_snivelak: instruction at +0x4 differs; 0/1 each.
   PAL: absent from catalogue. Qcopy and qcopy barrier reconstruct grouped transfers. Default split-address profile first differed at +0x98; mno-split changes allocation from prologue onward. Reopen when repeated address materialization can match without artificial barriers. */
#include "common.h"
typedef int TI128 __attribute__((mode(TI)));
extern u8 *func_0029EFD0(s32);
extern void func_002833F0(void *);
extern float func_002A7878(float, float);
extern void func_002C2210(void *, s32, s32, s32, s32, void *, s32, float, float, float);
extern float D_L16_001B1998 __attribute__((sda));
extern s32 D_L16_001B1908 __attribute__((sda));
extern s32 D_L16_001B190C __attribute__((sda));
extern u8 D_L16_001A8F20[] __attribute__((nosda));

u8 *func_L16_00413D10(u8 *owner, TI128 *velocity, TI128 *position, float speed)
{
    u8 *obj;
    u8 *state;
    u8 *pos;
    float scale;
    float zero;
    obj = func_0029EFD0(0xF7A);
    if (obj) {
        obj[0x30] = 255;
        *(u16 *)(obj + 0x32) = 255;
        obj[0x31] = 1;
        obj[0x20] = 0;
        *(s64 *)(obj + 0x38) = *(s64 *)(owner + 0x38);
        pos = obj + 0x10;
        *(TI128 *)pos = *position;
        *(u16 *)(obj + 0x34) |= 0x41;
        state = *(u8 **)(obj + 0x68);
        *(TI128 *)state = *velocity;
        *(float *)(state + 0x14) = speed;
        *(float *)(state + 0x20) = 0.15f;
        *(u8 **)(state + 0x10) = owner;
        *(u16 *)(obj + 0x34) |= 0x208;
        *(TI128 *)(obj + 0xF0) = *(TI128 *)(owner + 0xF0);
        zero = 0.0f;
        func_002833F0(obj + 0xC0);
        obj[0x23] = 128;
        *(u16 *)(obj + 0x34) |= 0x100;
        *(float *)(obj + 0x2C) = D_L16_001B1998;
        *(s32 *)(state + 0x24) = 0;
        scale = func_002A7878(8.0f, 10.0f);
        func_002C2210(pos, 15, D_L16_001B1908, 0, 10, D_L16_001A8F20, 0, scale * 0.3f, scale, zero);
        func_002C2210(pos, 15, D_L16_001B190C, 1, -10, D_L16_001A8F20, 0, scale * 0.04f, scale * 0.4f, zero);
    }
    return obj;
}
