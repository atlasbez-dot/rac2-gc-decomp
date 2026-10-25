/* 0 of 1 places match - last line: 12_todano: 520 bytes, expected 508
   The state select, the emitter call, both animation tables and the two owner hand-offs are
   retail's, but this cc1 hoists the two $gp loads that feed the last two arguments above the
   branch (four `lwc1` against retail's two plus two inline), which costs the 12 bytes.
   Reopen with the argument spelling that keeps those two loads in the argument list.
   Below: the whole -G8 sibling source. */

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

/* The two rate pairs the state table selects and the four scales the emitter applies. */
extern f32 D_L12_001B17F4 __attribute__((sda));

extern f32 D_L12_001B17F8 __attribute__((sda));

extern f32 D_L12_001B17FC __attribute__((sda));

extern f32 D_L12_001B1800 __attribute__((sda));

extern f32 D_L12_001B1804 __attribute__((sda));

extern f32 D_L12_001B1808 __attribute__((sda));

extern void func_002B60B0(u8 *, s32, f32, f32, f32, f32);

extern void func_002A7470(void *, s32, s32, s32);

/* Fires the object's emitter for the new state, arms the two animation tables the state
   selects and doubles the object's rate before handing the state to both owners. */
void func_L12_00412E50(u8 *a0, s32 a1, s32 a2, s32 a3) {
    u8 *q = *(u8 **)(a0 + 0x68);
    f32 f0, f1;
    u32 *p;

    if (a1 == 12) {
        f0 = D_L12_001B17F4;
        f1 = D_L12_001B17F8;
    } else {
        f0 = D_L12_001B17FC;
        f1 = D_L12_001B1800;
    }
    func_002B60B0(a0, a1, f0 * 0.00027777778f, f1 * 0.016666668f,
                  D_L12_001B1804 * 4.8481375e-06f,
                  D_L12_001B1808 * 0.00029088824f);
    *(f32 *)(q + 0x118) = *(f32 *)(q + 0x118) * 2.0f;
    if ((u32)(a1 - 13) < 3) {
        q[0x66] = 0xF;
        q[0xC2] = 7;
        q[0xC3] = 0x13;
        q[0xC6] = 1;
        p = (u32 *)(q + 0x6C);
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p[4] = 0;
        q[0x61] = 0xF;
        q[0x62] = 0xF;
        q[0xBC] = 7;
        q[0xBD] = 0x13;
        q[0xBE] = 7;
        q[0xBF] = 0x13;
    } else if (a1 == 0x10) {
        *(f32 *)(q + 0x6C) = 0.36666667f;
        *(f32 *)(q + 0x70) = 0.11666667f;
        *(f32 *)(q + 0x78) = 0.008333334f;
        *(f32 *)(q + 0x7C) = 0.0041666669f;
        q[0x61] = 0x12;
        q[0x66] = 0x14;
        q[0xBC] = 5;
        q[0xBD] = 9;
        q[0xBE] = 4;
        q[0xBF] = 7;
        q[0xC2] = 0xA;
        q[0xC3] = 0x11;
        *(f32 *)(q + 0x74) = 0.0041666669f;
        q[0x62] = 0x11;
        q[0xC6] = 0;
    }
    if (*(u8 *)(a0 + 0x43) != a1)
        func_002A7470(a0, a1, a2, a3);
    p = *(u32 **)(q + 0x2F8);
    if (p != 0 && *((u8 *)p + 0x43) != a1)
        func_002A7470(p, a1, a2, a3);
}
