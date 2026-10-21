#include "include_asm.h"

#include "common.h"

extern f32  D_L03_001B0340 __attribute__((sda));
extern void func_002A7750(char *a0, s32 a1, s32 a2);
extern s32  func_31BA30(s32 a0, s32 a1);
extern s32  func_31B9F0(s32 a0);
extern f32  func_2F0000(f32 a0, f32 a1);

void func_L03_003CA938(char *a0)
{
    if (*(u8 *)(a0 + 0x31) == 0) {
        return;
    }
    switch (*(u8 *)(a0 + 0x20)) {
    case 0:
        *(u8 *)(a0 + 0xBC) = (u8)func_31BA30(5, 10);
        if (func_31B9F0(2) != 0) {
            *(u8 *)(a0 + 0xBC) += 15;
        }
        func_002A7750(a0, 1, -1);
        break;
    case 1:
        *(f32 *)(a0 + 0xF8) = func_2F0000(*(f32 *)(a0 + 0xF8),
            D_L03_001B0340 * 0.000290888245f * (f32)(*(u8 *)(a0 + 0xBC) - 15));
        break;
    }
}

typedef int TI128 __attribute__((mode(TI)));

extern void func_L03_003CAD78(char *a0);
extern void func_31B920(char *a0, s32 a1, s32 a2);
extern void func_2E77F0(void *a0);
extern char *func_3113F0(s32 a0);
extern void func_32AA20(char *a0, char *a1);
extern f32  func_2EF670(f32 a0, f32 a1);
extern f32  func_2EF110(f32 *a0);

extern f32 D_L03_001B0350[] __attribute__((sda));
extern f32 D_L03_001B0648 __attribute__((sda));

/* case 0 lights the actor's motion, case 1 winds the three tracks down */
INCLUDE_ASM("asm/levels", func_L03_003CACA8);

/* spawns the actor and seeds its aim from the caller's vector */
INCLUDE_ASM("asm/levels", func_L03_003D18F8);

/* The object the level's state points at: the retail writes six floats, a run
   of bytes and shorts, and two counters into it. */
typedef struct {
    f32 f00;
    f32 f04;
    f32 f08;
    f32 f0C;
    f32 f10;
    f32 f14;
    u8  b18;
    u8  b19;
    u16 h1A;
    u16 pad1C;
    u8  b1E;
    u8  b1F;
    u8  pad20[0x10];
    u16 h30;
    u16 h32;
    s32 i34;
} L03_003D21F8_Obj;

/* The object pointer is small data (the retail reaches it through $gp in
   ordinary flow, not only in a delay slot), the state word is not: the retail
   reads it with an absolute lui/%lo pair and clears it from a delay slot. */
extern L03_003D21F8_Obj *D_L03_001B0670 __attribute__((sda));
extern u32 D_L03_001B3458;
extern void *func_L00_002D70A0(s32 size);

extern void func_00282CF0(char *a0, char *a1, char *a2);
extern void func_00282CC0(char *a0, char *a1, char *a2);
extern void func_00283098(char *a0, char *a1, char *a2);
extern void func_00283698(char *a0, char *a1);
extern s32  func_002B38B8(char *a0);
extern s32  func_002E5CF8(s32 a0, s32 a1, char *a2);
extern void func_002E59F8(s32 a0);
extern void func_L01_003115E8(int a0, int a1);
extern u8  *D_L03_001B2A1C;
extern u8   D_00188660[];
extern s32  D_L03_001B0438 __attribute__((sda));
extern f32  D_L03_001B043C __attribute__((sda));

/* The actor's per-frame update: state 0 spawns it and aims, state 2 looks the
   target up, states 3 and 4 turn it by a rate that decays; every other state
   does nothing.  The actor's angle is at 0xF4, its rate at 0x74 of the state. */
void func_L03_003CBE58(char *a0)
{
    char *s2 = a0;
    char *s1 = *(char **)(s2 + 0x68);
    char buf[0x40];
    char *s0;

    switch (*(u8 *)(s2 + 0x20)) {
    case 0:
        if (*(s32 *)(s1 + 0x70) != -1) {
            func_002A7750(s2, 2, -1);
            s0 = s1 + 0x60;
            func_00282CF0(s0, D_L03_001B2A1C + *(s32 *)(s1 + 0x70) * 0x100 + 0x10, s2 + 0x10);
            *(s32 *)(s1 + 0x7C) = -1;
            *(s32 *)(s1 + 0x78) = 0;
            func_00283698(buf, s2 + 0xC0);
            func_00283098(s0, s0, buf);
        } else {
            func_002A7750(s2, 1, -1);
        }
        break;
    case 2: {
        char *p;

        if (func_002B38B8(D_L03_001B2A1C + *(s32 *)(s1 + 0x70) * 0x100) == 0) {
            break;
        }
        p = D_00188660 + *(s32 *)(s1 + 0x7C) * 0x70;
        if (*(char **)(p + 0x88) != s2 || *(u8 *)(p + 0x74) == 0) {
            *(s32 *)(s1 + 0x7C) = func_002E5CF8(0, 4, s2);
        }
        func_L01_003115E8(*(u8 *)(s2 + 0x21), 4);
        func_002A7750(s2, 3, -1);
        break;
    }
    case 3: {
        char *p;
        char *q;
        f32 t;
        f32 v;

        *(f32 *)(s1 + 0x74) = *(f32 *)(s1 + 0x74)
            + (*(f32 *)(s2 + 0xF4) / (f32)D_L03_001B0438 + 9.69627508e-05f);
        t = *(f32 *)(s2 + 0xF4) + *(f32 *)(s1 + 0x74);
        *(f32 *)(s2 + 0xF4) = t;
        if (1.69646013f < t) {
            if (*(s32 *)(s1 + 0x78) < 5) {
                if (*(s32 *)(s1 + 0x7C) != -1) {
                    p = D_00188660 + *(s32 *)(s1 + 0x7C) * 0x70;
                    if (*(char **)(p + 0x88) == s2 && *(u8 *)(p + 0x74) != 0) {
                        func_002E59F8(*(s32 *)(s1 + 0x7C));
                    }
                }
                *(s32 *)(s1 + 0x7C) = -1;
                func_002E5CF8(1, 0, s2);
                (*(s32 *)(s1 + 0x78))++;
            }
            *(f32 *)(s2 + 0xF4) = 1.69646013f;
            v = *(f32 *)(s1 + 0x74);
            if (0.00058177649f < v) {
                *(f32 *)(s1 + 0x74) = v * -0.5f;
            } else {
                *(s32 *)(s1 + 0x74) = 0;    /* the retail stores the word, not the float */
                func_002A7750(s2, 5, -1);
            }
        }
        q = D_L03_001B2A1C + *(s32 *)(s1 + 0x70) * 0x100 + 0x10;
        func_00283098(q, s1 + 0x60, s2 + 0xC0);
        func_00282CC0(q, q, s2 + 0x10);
        break;
    }
    case 4: {
        f32 f3;
        f32 t;
        f32 v;

        f3 = D_L03_001B043C * 3.14159274f;
        *(f32 *)(s1 + 0x74) = *(f32 *)(s1 + 0x74)
            + (*(f32 *)(s2 + 0xF4) / (f32)D_L03_001B0438 + 9.69627508e-05f);
        t = *(f32 *)(s2 + 0xF4) + *(f32 *)(s1 + 0x74);
        *(f32 *)(s2 + 0xF4) = t;
        if (f3 < t) {
            *(f32 *)(s2 + 0xF4) = f3;
            v = *(f32 *)(s1 + 0x74);
            if (0.00058177649f < v) {
                *(f32 *)(s1 + 0x74) = v * -0.5f;
            } else {
                *(s32 *)(s1 + 0x74) = 0;    /* the retail stores the word, not the float */
                func_002A7750(s2, 5, -1);
            }
        }
        break;
    }
    }
}

/* case 0 spawns the object and points the actor at it; case 1 clears the
   object while the state word still reads zero, and clears the word otherwise */
void func_L03_003D21F8(char *a0)
{
    char *s0 = a0;

    switch (*(u8 *)(s0 + 0x20)) {
    case 0:
        D_L03_001B0670 = func_L00_002D70A0(4);
        func_002A7750(s0, 1, -1);
        *(u8 *)(s0 + 0x30) = 0xFF;
        break;
    case 1: {
        u32 v = D_L03_001B3458;

        if (v == 0) {
            D_L03_001B0670->f00 = -1.0f;
            D_L03_001B0670->f04 = -1.0f;
            D_L03_001B0670->f08 = -1.0f;
            D_L03_001B0670->f0C = -1.0f;
            D_L03_001B0670->f10 = -1.0f;
            D_L03_001B0670->f14 = -1.0f;
            D_L03_001B0670->b18 = 0;
            D_L03_001B0670->b19 = 0;
            D_L03_001B0670->h1A = 0;
            D_L03_001B0670->b1E = 0;
            D_L03_001B0670->b1F = 0;
            D_L03_001B0670->h30 = 0;
            D_L03_001B0670->i34 = 6;
            D_L03_001B0670->h32 = 120;
        } else {
            D_L03_001B3458 = 0;
        }
        break;
    }
    }
}
