/* func_L02_0042E2F8 - 900 bytes, 1 place (level 02): the same size as retail's; 16 of 225 words
   differ, none of them structure. Default flags (-O2 -G0 -ffunction-sections), no profile and no
   `-g8` unit. (Retail reads the counter D_L02_001AEC78 through $gp and writes it absolutely in kind
   0, and the reverse in kind 1; `extern s32 D_L02_001AEC78 __attribute__((sda))` in a -G0 unit
   gives those four forms exactly.)

   What differs:
   - the four 16-byte clears of the stack locals d (kind 0), d, e, f (kind 2): retail's `por`
     registers are t5, v0, a2, t2, this C gives v0, t2, t3, t4 (8 words, the `por` and its `sq`
     each); the same reload choice as in func_L02_0043E150 beside it (see there for what was tried);
   - kind 2, the call to func_L00_0032A258: retail pairs `sw $v0,0($sp)` with `addiu $a1,$sp,0x40`,
     then `sw $v1,8($sp)` with `sw $zero,0x10($sp)`, `addiu $t0,$zero,0xB` with `daddu $t1,$zero,
     $zero`, `addiu $t2,$zero,1` with `addiu $t3,$zero,5`; sched2 here issues `addiu $a1` first and
     pairs the rest differently (6 words, the same eleven moves in another order). The same callee
     in func_L02_0043E150 comes out as retail's;
   - kind 2, the call to func_00273730: retail sets $t2 (`daddu $t2,$s0,$zero`, the vector) before
     $t3 (`addiu $t3,$zero,0xFF`), this C the other way round (2 words). Moving the two floats of the
     prototype through all 45 positions did not change it.
   Tried without effect: all 24 orders of the four initialisation statements (a, b, c[0], c[1]) with
   and without a `kind` local (this order, A B C0 C1, is the best), the -frac2-zero-ti-barrier
   profile (alone or with -frac2-qcopy: worse). What the body needed: the tables declared `const`
   (the diff is larger without), `func_L00_0033E220` declared as returning a pointer, and the float
   constants spelled with retail's bits (409500.0 and 367500.0 for the two `lui`/`ori` pairs,
   -0.10000001, 0.025000002, 0.23333335). */

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed int s32;
typedef int TI128 __attribute__((mode(TI)));

extern void func_002A7750();
extern void func_00283098(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_0029F338(u8 *);
extern void *func_002A9640(void *, int, int);

struct Pair42E2F8 {
    float a;
    float b;
};

extern const struct Pair42E2F8 D_L02_001B23E0;
extern const struct Pair42E2F8 D_L02_001B23E8;
extern const TI128 D_L02_001B23F0[2];
extern s32 D_L02_001AEC78 __attribute__((sda));
extern void func_L00_0032A258(void *, void *, void *, void *, s32, s32, s32, s32, s32, s32, s32);
extern void *func_L00_0033E220(void *, void *, int, int, int, int, int, int, float, float);
extern void func_L00_00326110(void *, int, float);
extern void *func_00273730(void *, int, int, int, void *, void *, void *, int, float, float);
extern void func_L00_003263D0(void *, void *, float, int, int, void *, float, int, int, float, float);
extern void func_L02_0042E680(u8 *, float, float);

void func_L02_0042E2F8(u8 *a0) {
    u8 *state = *(u8 **)(a0 + 0x68);
    struct Pair42E2F8 a = D_L02_001B23E0;
    struct Pair42E2F8 b = D_L02_001B23E8;
    TI128 c[2];
    float d[4];
    float e[4];
    float f[4];

    c[0] = D_L02_001B23F0[0];
    c[1] = D_L02_001B23F0[1];
    switch (a0[0x20]) {
    case 0:
        *(TI128 *)d = 0;
        d[2] = 4.0f;
        func_L00_0033E220(d, a0, 0x28208080, -1, 0, -1, 0, 0x60, 409500.0f, 0.0f);
        func_L00_0033E220(d, a0, 0x20208080, -1, 1, -1, 0, 0x60, 367500.0f, 0.75f);
        if (*(s32 *)state != 0)
            D_L02_001AEC78 = D_L02_001AEC78 - 1;
        func_002A7750(a0, 1, -1);
        break;
    case 1:
        if (func_002A9640(a0, 0x4010000, 0) != 0 && *(s32 *)state == 0) {
            D_L02_001AEC78 = D_L02_001AEC78 - 1;
            func_002A7750(a0, 2, -1);
        }
        a0[0xA8] = 0xFF;
        break;
    case 2:
        func_L00_0032A258(a0, c, &b, &a, 0xB, 0, 1, 5, 0xFFFF, 0xFF, 0);
        func_L00_00326110(a0, 1, 4.0f);
        *(TI128 *)d = 0;
        d[1] = -0.10000001f;
        d[2] = 0.050000004f;
        func_00283098(d, d, a0 + 0xC0);
        func_00273730(a0, 1, *(s16 *)(a0 + 0xAA), 1, a0 + 0x10, a0 + 0xF0, d, 0xFF, 0.0f, 15.0f);
        *(TI128 *)e = 0;
        e[1] = 0.2f;
        e[2] = 4.3f;
        func_00283098(e, e, a0 + 0xC0);
        func_00282CC0(e, e, a0 + 0x10);
        *(TI128 *)f = 0;
        f[1] = 0.050000004f;
        f[2] = 0.025000002f;
        func_00283098(f, f, a0 + 0xC0);
        func_L00_003263D0(a0, e, 0.25f, 4, 1, f, 5.0f, 0x50404040, 0, 0.5f, 1.0f);
        func_L02_0042E680(a0, 0.016666668f, 0.23333335f);
        func_0029F338(a0);
        break;
    }
}
