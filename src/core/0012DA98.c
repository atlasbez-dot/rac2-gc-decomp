#include "include_asm.h"

typedef int s32;
typedef long long s64;

typedef struct {
    char pad0[0x8];
    int unk008;
    char pad1[0xAC - 0xC];
    int unk0AC;
    char pad2[0x118 - 0xB0];
    int unk118;
    char pad3[0x820 - 0x11C];
    int unk820;
} Obj40;

s32 func_0012DA98(void *arg0) {
    Obj40 *s = (Obj40 *)arg0;
    s32 r = 1;

    if (s->unk008 != 2) {
        s32 v = s->unk118;
        s->unk008 = 2;
        s->unk0AC = v;
    }
    s->unk820 = r;
    return r;
}

/* The MPEG library's picture timestamp and flags: the picture's presentation
   timestamp, its decoding timestamp and a packed word of the picture's coding
   fields. Carried from rac1-decomp's func_00129CA0 (src/core/00125630.c), the
   same library with this image's +0x3E20 core shift; func_00121AB8 is its
   __muldi3. */
extern s64 func_00121AB8(s64 a, s64 b);

s64 func_0012DAC0(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4) {
    char *s = arg0;
    char *t = arg1;
    s64 *o1 = arg2;
    s64 v;
    s64 packed;

    if (*(s32 *)(s + 0x70) != 0) {
        s32 base;
        v = *(s64 *)(t + 0x18);
        if (v >= 0 || (base = *(s32 *)(s + 0x80)) < 0) {
            *o1 = v;
        } else {
            s32 n = *(s64 *)(s + 0x88);
            s64 r = func_00121AB8(n & 1, *(s64 *)(s + 0x78) & 1);
            s32 cnt = *(s32 *)(s + 0x90);
            s32 a = func_00121AB8(r, cnt & 1);
            *o1 = base + ((s32)(func_00121AB8(*(s64 *)(s + 0x78), n) >> 1) + a);
            if (func_00121AB8(n & 1, *(s64 *)(s + 0x78) & 1)) {
                *(s32 *)(s + 0x90) = cnt + 1;
            }
        }
    } else {
        *o1 = *(s64 *)(t + 0x18);
    }
    if (*(s32 *)(s + 0xF8) == 2 && (v = *(s64 *)(s + 0xF0)) >= 0) {
        *o1 = v;
        *(s32 *)(s + 0xF8) = 0;
        *(s64 *)(s + 0xF0) = -1;
    }
    *(s64 *)arg3 = *(s64 *)(t + 0x20);
    packed = ((s64)*(s32 *)(t + 0x34) << 8) | ((s64)*(s32 *)(t + 0x38) << 7)
           | ((s64)*(s32 *)(t + 0x3C) << 6) | ((s64)*(s32 *)(t + 0x40) << 5)
           | ((s64)*(s32 *)(t + 0x30) << 3) | *(s32 *)(t + 0x2C);
    *(s64 *)arg4 = packed;
    return packed;
}

INCLUDE_ASM("asm/core", func_0012DC50);

ASM_FUNC("asm/core", func_0012DF18);
