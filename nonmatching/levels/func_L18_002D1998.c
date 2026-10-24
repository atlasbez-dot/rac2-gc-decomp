/* Measured profile: -O2 -G0 -ffunction-sections. us: 18_damosel: 820 bytes, expected 836; us2:
   18_damosel: 820 bytes, expected 836; pal: absent pal. 820 bytes versus 836, with an additional saved
   frame region. Collision normal/object/count use one partial record at their measured offsets.
   Remaining float lifetimes, branch ordering and resident address allocation need a new witness. No
   linked build or functional execution run. */

/* Historical screening below; superseded by the measured C reconstruction. */
/* func_L18_002D1998 - 836 bytes, 2 place(s), level 18_damosel, retail at
   0x002d1998. Screened with tools/w10_screen.py: 20 call(s)
   [func_L00_002D3A58@002D19D0, func_L00_002D36E0@002D1A68,
   func_L00_002D36E0@002D1A90, func_00282E20@002D1AA4,
   func_00282F20@002D1ADC, func_00282F20@002D1B04,
   func_L00_002D3B58@002D1B20, func_00282F20@002D1B34,
   func_00282D30@002D1B54, func_00282CC0@002D1B68, func_00282CC0@002D1B78,
   func_002761F8@002D1B94, func_00278E78@002D1BB0, func_002761F8@002D1BD4,
   func_L00_002D3EA8@002D1BF4, func_L00_002D3B58@002D1C5C,
   func_00282F20@002D1C70, func_00282DB0@002D1C7C, func_00282D30@002D1C98,
   func_00282CC0@002D1CA8]; data addresses materialised [0x190000,
   0x3ada0000, 0x3ebd0000, 0x3f330000, 0x3eb30000, 0x3e990000, 0x190000,
   0x3c230000, 0x190000, 0x3fb30000, 0x190000, 0x3fb30000, 0x1c0000,
   0x1c0000, 0x3f5f0000, 0x1c0000, 0x1c0000]; float constants [0x3f000000,
   0x3f800000]; $gp-relative small data: no   saves: -; callee-saved
   registers saved [-]; words plain C cannot emit [-]. Head: addiu $sp, $sp,
   -0x90 ; lui $v0, 0x19 ; sd $s0, 0x40($sp) ; sd $s1, 0x48($sp) ; addiu
   $s0, $v0, -0x60F0 ; sd $s2, 0x50($sp). Not matched in this wave: the body
   is straight-line code whose register allocation and the materialisation
   of its constant addresses have to be reproduced word for word. What would
   unblock it: the exact source expression tree, so this cc1 picks the same
   registers in the same order. */

#include "common.h"
typedef int V4_F6a70b950 __attribute__((mode(TI)));
typedef struct { u8 prefix[0x18]; s32 object; s32 count; u8 gap[0x20]; float normal[4]; } MotionCollision;
extern u8 D_00189E20[];
extern MotionCollision D_L18_001BFC00;
extern float func_L00_002D3A58(char *);
extern void func_L00_002D36E0(float *, s32, float, float, float);
extern float func_00282E20(void *);
extern void func_00282F20(void *, void *, float);
extern void func_L00_002D3B58(V4_F6a70b950 *, V4_F6a70b950 *, float);
extern void func_00282D30(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern s32 func_002761F8(void *, void *, s32, void *, void *);
extern s32 func_00278E78(void);
extern float func_L00_002D3EA8(void *);
extern float func_00282DB0(void *, void *);
void func_L18_002D1998(s32 force)
{
    float start[4], end[4], lowerStart[4], lowerEnd[4];
    u8 *base = D_00189E20;
    float height, reach, angle, dot;
    s32 material = -1;
    if (func_L00_002D3A58((char *)base + 0xF0) < 0.0016666668f) return;
    height = 0.37f;
    if ((u32)(*(s32 *)(base + 0x229C) - 17) < 2) {
        height = 0.0f;
        reach = 0.7f;
    } else {
        reach = 0.5f;
        if (base[0x22B4] == 4) height = 0.35f;
    }
    func_L00_002D36E0(start, 1, 0.0f, 0.0f, height);
    func_L00_002D36E0(lowerStart, 1, 0.0f, 0.0f, height * 0.3f);
    if (force || func_00282E20(base + 0xF0) < 0.01f) {
        func_00282F20(end, base, reach);
        func_00282F20(lowerEnd, base, reach * 1.4f);
    } else {
        func_L00_002D3B58((V4_F6a70b950 *)end, (V4_F6a70b950 *)(base + 0xF0), 0.0f);
        func_00282F20(end, end, reach);
        func_00282D30(lowerEnd, end, 1.4f);
    }
    func_00282CC0(end, end, start);
    func_00282CC0(lowerEnd, lowerEnd, lowerStart);
    if (func_002761F8(lowerStart, lowerEnd, 2, *(u8 **)(base + 0x2290), 0) && D_L18_001BFC00.count > 0) material = func_00278E78();
    angle = 0.0f;
    if (func_002761F8(start, end, 2, *(u8 **)(D_00189E20 + 0x2290), 0) && D_L18_001BFC00.count > 0) angle = func_L00_002D3EA8(D_L18_001BFC00.normal);
    if (angle >= 0.8726647f || material == 8 || material == 12) {
        *(s32 *)(D_00189E20 + 0x270) = D_L18_001BFC00.object;
        func_L00_002D3B58((V4_F6a70b950 *)D_L18_001BFC00.normal, (V4_F6a70b950 *)D_L18_001BFC00.normal, 0.0f);
        func_00282F20(D_L18_001BFC00.normal, D_L18_001BFC00.normal, 1.0f);
        dot = func_00282DB0(D_L18_001BFC00.normal, D_00189E20 + 0xF0);
        if (dot < 0.0f) {
            func_00282D30(D_L18_001BFC00.normal, D_L18_001BFC00.normal, -dot);
            func_00282CC0(D_00189E20 + 0xF0, D_00189E20 + 0xF0, D_L18_001BFC00.normal);
        }
    }
}
