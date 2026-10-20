
/* SPDX-License-Identifier: MIT
 * MIT License
 * 
 * Copyright (c) 2026 RC2 decomp contributions
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "common.h"

extern void ref_L00_003CC030_00(s8 *p);
extern s64 ref_L00_003CC030_01(s8 *p);
extern f32 ref_L00_003CC030_02(f32 x, f32 y);
extern f32 ref_L00_003CC030_03(s8 *p, f32 *v);
extern void ref_L00_003CC030_04(f32 *matrix, f32 *quat);
extern void ref_L00_003CC030_05(s8 *p, f32 scale);
extern void ref_L00_003CC030_06(s8 *pkt, f32 *matrix, s32 mode);
struct L00AimVector {
    s8 pad_000[0x140];
    f32 x_140;
    f32 y_144;
    f32 z_148;
};
extern struct L00AimVector ref_L00_003CC030_07;

void func_L00_003CC030(s8 *pos, s32 a1, s32 a2, s8 *a3, s32 t0, f32 fA, f32 fB)
{
    s8 pkt[144];
    f32 m[16];
    f32 quat[4];
    s64 r;

    ref_L00_003CC030_00(pkt);
    r = ref_L00_003CC030_01(a3);

    *(s64 *)(pkt + 136) = ((s64)t0 << 2) | 0x8000000040LL;
    *(s64 *)(pkt + 128) = 280993940374112LL;
    *(s32 *)(pkt + 76) = a1 + (a2 << 24);
    *(s32 *)(pkt + 72) = a1 + (a2 << 24);
    *(s32 *)(pkt + 68) = a1 + (a2 << 24);
    *(s32 *)(pkt + 64) = a1 + (a2 << 24);
    *(s64 *)(pkt + 112) = 0LL;
    *(s64 *)(pkt + 120) = r;

    quat[3] = 0.0f;
    quat[2] = ref_L00_003CC030_02(ref_L00_003CC030_07.x_140 - *(f32 *)(pos + 0), ref_L00_003CC030_07.y_144 - *(f32 *)(pos + 4));
    quat[1] = -ref_L00_003CC030_02(ref_L00_003CC030_03(pos, &ref_L00_003CC030_07.x_140), ref_L00_003CC030_07.z_148 - *(f32 *)(pos + 8));
    quat[0] = fB;

    ref_L00_003CC030_04(m, quat);
    m[12] = *(f32 *)(pos + 0);
    m[13] = *(f32 *)(pos + 4);
    m[14] = *(f32 *)(pos + 8);
    m[15] = 1.0f;

    ref_L00_003CC030_05(pkt, fA);
    ref_L00_003CC030_06(pkt, m, 0);
}
