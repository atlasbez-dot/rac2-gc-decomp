#include "include_asm.h"
#include "common.h"
extern f32 D_L09_001B13F0 __attribute__((sda));
extern f32 D_L09_001B13F4 __attribute__((sda));
extern s32 D_L09_001A79F0 __attribute__((sda));
extern s32 D_L09_001A9040 __attribute__((sda));
extern char *D_L09_001B285C __attribute__((sda));
extern s32 func_323340(char *a0, char *a1, s32 a2);
extern char *func_L09_00326E90(char *a0);
extern s32 D_001A79F0;
extern void func_L09_00404C50(void);
extern float func_00282E48(char *a0, char *a1);
extern void func_002A93B0(void *a0);
extern s32 func_002B0ED8(char *a0, char *a1, s32 a2);
extern void func_L09_00405060(char *a0);
extern void func_L09_004050E0(char *a0);
extern s32 func_002B3BA8(char *a0, s32 a1, s32 a2, s32 a3, f32 f12, f32 f13);
extern char D_L09_001B9A00[];
extern s32 D_L09_001B2878;
extern u8 *D_L09_001B285C_1;
extern s32 D_L09_001B1420[2];
extern s32 func_00283D38(s32, s32, f32);
extern s32 D_L09_001B2388;
extern f32 func_00283B98(f32, f32);
extern f32 func_00283198(f32);

/* Releases the record the sub-object holds once the resident mode word says 9, then
   rebuilds the sub-object's effect. */
void func_PAL_L09_00409DC8(char *a0) {
    char *s0 = a0;
    char *s1 = *(char **)(s0 + 0x68);
    s32 s2;
    s16 idx;

    if (*(u8 *)(s0 + 0x20) == 0) {
        func_L09_00404C50();
    }
    if (*(u8 *)(s0 + 0x31) != 0) {
        if (func_00282E48(s0 + 0x10, D_L09_001B9A00) < 24.0f) {
            func_002A93B0(s0);
            *(u8 *)(s0 + 0x6F) = 0x16;
        }
    }
    s2 = func_002B0ED8(s0, s1 + 0x50, 0);
    if (D_001A79F0 == 9) {
        idx = *(s16 *)(s1 + 0xC0);
        if (idx != -1) {
            if (func_L09_00326E90(D_L09_001B285C + (idx << 8)) == 0) {
                D_L09_001A9040 = 0;
            }
            *(s16 *)(s1 + 0xC0) = -1;
        }
    }
    if (s2 != 0) {
        func_L09_00405060(s0);
        if (s2 >= 4) {
            func_L09_004050E0(s0);
        }
    }
    if (*(u8 *)(s0 + 0x95) != 3 && *(u8 *)(s0 + 0x95) != 4) {
        *(s16 *)(s1 + 0x334) = func_002B3BA8(s0, *(s32 *)(s1 + 0x230), 0, 0, 16.0f, 0.0f);
    }
}
