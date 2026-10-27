/* func_L01_0040F118: near miss, same size, about 8 instructions off in case 3 only. States 0 to 2 and the two func_002B0A68 calls match exactly under -O2 -G8 -mno-split-addresses (the call takes the 0xFF flag after its four floats, which is what puts it in the delay slot; the same variable is read both gp-relative and absolute, hence the _1 alias). Left: retail loads the absolute counter (0x1B3468) before the halfword flag store and keeps the 0x78 constant in $a0 with the counter in $v1; this build loads it after the sw. Own unit. */
#include "common.h"

extern s32 D_L01_001AEC38 __attribute__((sda));
extern s32 D_L01_001AEC38_1;
extern s32 D_L01_001B3468 __attribute__((sda));
extern s32 D_L01_001B3468_1;
extern float D_L01_001B2090 __attribute__((sda));
extern float D_L01_001B208C __attribute__((sda));
extern s32 D_L01_001B15E0 __attribute__((sda));
extern char D_L01_001A8F60 __attribute__((nosda));

extern s32 func_00282948(char *);
extern void func_0029F338(char *);
extern void func_002A7750(char *, s32, s32);
extern s32 func_002A9640(char *, s32, s32);
extern void func_002B0A68(char *, s32, char *, float, float, float, float, s32);
extern s32 func_002B3868(char *);
extern void func_002E5CF8(s32, s32, char *);
extern void func_L00_00326110(char *, s32, float);

/* Counts the objects of its kind: arms on the first tick, waits for the trigger, plays the sound on the third and retires once its timer runs out. */
void func_L01_0040F118(char *obj)
{
    char *rec = *(char **)(obj + 0x68);

    switch (*(u8 *)(obj + 0x20)) {
    case 0:
        D_L01_001B3468_1 = 0;
        D_L01_001AEC38 = D_L01_001AEC38 + 1;
        func_002A7750(obj, 1, -1);
        return;
    case 1:
        if (func_002A9640(obj, 0x04010000, 0) != 0 && *(s32 *)rec == 0) {
            D_L01_001AEC38 = D_L01_001AEC38_1 - 1;
            func_002A7750(obj, 2, -1);
        }
        *(u8 *)(obj + 0xA8) = 0xFF;
        return;
    case 2:
        if (*(u8 *)(obj + 0x31) != 0 && D_L01_001B2090 < 0.9f && D_L01_001B208C < 0.9f && D_L01_001B3468 < D_L01_001B15E0)
            func_002B0A68(obj, 0x7F, &D_L01_001A8F60, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF);
        else
            func_002B0A68(obj, 0xD, &D_L01_001A8F60, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF);
        func_L00_00326110(obj, 4, 0.0f);
        func_002E5CF8(0, 0, obj);
        func_002A7750(obj, 3, -1);
        return;
    case 3:
        if (func_002B3868(obj) != 0) {
            *(u8 *)(obj + 0x31) = 0;
            *(s32 *)(obj + 0x98) = 0;
            *(unsigned short *)(obj + 0x34) |= 1;
            *(s32 *)(rec + 4) = 0x78;
            D_L01_001B3468_1 = D_L01_001B3468_1 + 1;
        }
        if (func_00282948(rec + 4) != 0) {
            D_L01_001B3468 = D_L01_001B3468 - 1;
            func_0029F338(obj);
        }
        return;
    }
}
