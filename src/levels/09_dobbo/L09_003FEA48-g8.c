#include "common.h"

extern f32 D_L09_001B13F0 __attribute__((sda));
extern f32 D_L09_001B13F4 __attribute__((sda));
extern void func_L08_00316678(char *a, s32 b, s32 c, s32 d);

typedef union {
    u16 h;
    s32 w;
} U16S32;

extern U16S32 D_L09_001B13C0 __attribute__((sda));
extern void func_2EA110(char *p);

void func_L09_00404B90(char *a0, s32 a1) {
    char *v = a0;
    f32 f = D_L09_001B13F0 * 0.0166666675f;
    char *p = *(char **)(v + 0x68);
    *(f32 *)(p + 0x1D4) = 3.0f;
    *(f32 *)(p + 0x1D0) = f;
    if (*(u8 *)(v + 0x43) == 7) {
        return;
    }
    func_L08_00316678(a0, 7, 0, a1);
}

void func_L09_00404BF0(char *a0, s32 a1) {
    char *v = a0;
    f32 f = D_L09_001B13F4 * 0.0166666675f;
    char *p = *(char **)(v + 0x68);
    *(f32 *)(p + 0x1D4) = 1.75f;
    *(f32 *)(p + 0x1D0) = f;
    if (*(u8 *)(v + 0x43) == 6) {
        return;
    }
    func_L08_00316678(a0, 6, 0, a1);
}

void func_L09_004031D8(char *a0) {
    char *s1 = a0;
    char *s0 = *(char **)(s1 + 0x68);
    u16 n;
    if (*(s16 *)(s0 + 0x270) != 0
        || (*(s32 *)(s0 + 0x234) == 1 && *(s16 *)(s0 + 0x26C) < D_L09_001B13C0.w / 2)) {
        *(u16 *)(s0 + 0x26C) = D_L09_001B13C0.h;
        *(s16 *)(s0 + 0x270) = 0;
    }
    func_2EA110(s0 + 0x26C);
    func_2EA110(s0 + 0x26E);
    n = *(u16 *)(s1 + 0x96);
    if (n < 0xFFFF) {
        *(u16 *)(s1 + 0x96) = n + 1;
    }
}


/* Small-data handles: the resident mode word (-0x7600 -> 0x001A79F0), the resident
   release word (-0x5FB0 -> 0x001A9040) and the level's record table (0x386C ->
   0x001B285C), all read with $gp pinned at 0x001AEFF0. */
extern s32 D_L09_001A79F0 __attribute__((sda));
extern s32 D_L09_001A9040 __attribute__((sda));
extern char *D_L09_001B285C __attribute__((sda));

extern s32 func_323340(char *a0, char *a1, s32 a2);
extern char *func_L09_00326E90(char *a0);
extern void func_L09_003FE978(char *a0);
extern void func_326368(char *a0, s32 a1, s32 a2, s32 a3, f32 f12, f32 f13);

/* Drops the record the sub-object points at, once, when the resident mode word says 9,
   then rebuilds the sub-object's effect with both blend weights at zero. */
void func_L09_003FEA48(char *a0) {
    char *s0 = *(char **)(a0 + 0x68);
    s16 idx;

    if (func_323340(a0, s0 + 0x160, 0) != 0) {
        if (D_L09_001A79F0 == 9) {
            idx = *(s16 *)(s0 + 0x1D0);
            if (idx != -1) {
                if (func_L09_00326E90(D_L09_001B285C + (idx << 8)) == 0) {
                    D_L09_001A9040 = 0;
                }
                *(s16 *)(s0 + 0x1D0) = -1;
            }
        }
        func_L09_003FE978(a0);
    }
    func_326368(a0, *(s32 *)(s0 + 0x448), 0, 0, 0.0f, 0.0f);
}
