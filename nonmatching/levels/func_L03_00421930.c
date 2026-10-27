#include "include_asm.h"
#include "common.h"

extern char D_L03_00259A30[];
extern void func_L00_00322A98(u8 *, char *);
extern void func_L00_00322AC0(char *, s32, s32, float);
extern void func_L00_00322BE0(char *, s32);
extern void func_L00_00322EC8(char *);
extern void func_002A7750(u8 *, s32, s32);
extern s32 func_00273B70(u8 *);
extern void func_0029F338(u8 *);

#define REC(o) (&D_L03_00259A30[*(s16 *)(p + 0x36) * 0x150])

void func_L03_00421930(u8 *obj)
{
    u8 *p = *(u8 **)(obj + 0x68);

    switch (obj[0x20]) {
    case 0:
        func_L00_00322A98(obj, REC(obj));
        func_L00_00322AC0(REC(obj), 0x28, 2, 0.0f);
        func_L00_00322AC0(REC(obj), 0x14, 4, 0.0f);
        func_L00_00322AC0(REC(obj), 0xA, 6, 0.0f);
        func_002A7750(obj, 1, -1);
        break;
    case 1:
        func_L00_00322BE0(REC(obj), 0);
        if (func_00273B70(obj) != 0) {
            func_002A7750(obj, 2, -1);
            *(u16 *)(obj + 0x34) |= 0x2800;
        }
        break;
    case 2:
        func_00273B70(obj);
        func_L00_00322EC8(REC(obj));
        if (obj[0x23] >= 2) {
            obj[0x23] -= 2;
        } else {
            func_0029F338(obj);
        }
        break;
    }
}
