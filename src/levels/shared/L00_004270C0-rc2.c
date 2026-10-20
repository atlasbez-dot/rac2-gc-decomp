
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

extern f32 ref_L00_004270C0_00(s8 *, s8 *);
extern void ref_L00_004270C0_01(s8 *, s8 *, s8 *);
extern void ref_L00_004270C0_02(s8 *, s8 *, f32);
extern f32 ref_L00_004270C0_03(s8 *);
extern f32 ref_L00_004270C0_04(f32);
extern s8 D_00189E20[];
extern s8 ref_L00_004270C0_05[];

void func_L00_004270C0(s8 *arg0) {
    s8 sp[0x30];
    s8 *t0;
    s8 *d;
    s8 *b;
    s8 *b2;
    f32 f20;
    s32 v;

    d = D_00189E20;
    v = *(s32 *)(d + 0x24A0);
    if (v == 0x51) {
        goto end;
    }
    if (v == 4) {
        goto end;
    }
    b = ref_L00_004270C0_05;
    if (*(s16 *)(b + 0x290) != 0) {
        goto l44;
    }
    *(s8 *)(b + 0x293) = 0;
    *(s16 *)(arg0 + 0x7E) = 2;
    *(f32 *)(b + 0x2B4) = 0.018f;
    *(f32 *)(b + 0x2A8) = 0.018f;
    goto end;
l44:
    t0 = b + 0x1D0;
    ref_L00_004270C0_02(sp, t0, ref_L00_004270C0_00(t0, arg0));
    ref_L00_004270C0_01(sp + 0x10, arg0, sp);
    ref_L00_004270C0_02(sp, t0, ref_L00_004270C0_00(t0, *(s8 **)(d + 0x2290) + 0xC0));
    ref_L00_004270C0_01(sp + 0x20, *(s8 **)(d + 0x2290) + 0xC0, sp);
    f20 = ref_L00_004270C0_03(sp + 0x20);
    if (f20 == 0.0f) {
        goto fail;
    }
    f20 = f20 * ref_L00_004270C0_03(sp + 0x10);
    if (f20 == 0.0f) {
        goto fail;
    }
    if ((1.5707964f - ref_L00_004270C0_04(ref_L00_004270C0_00(sp + 0x20, sp + 0x10) / f20)) >= 1.3962636f) {
        *(s16 *)(b + 0x290) = 0;
        *(s16 *)(arg0 + 0x7E) = 4;
        goto end;
    }
fail:
    b2 = ref_L00_004270C0_05;
    *(s8 *)(b2 + 0x293) = 0;
    *(s16 *)(arg0 + 0x7E) = 2;
    *(f32 *)(b2 + 0x2B4) = 0.018f;
    *(f32 *)(b2 + 0x2A8) = 0.018f;
end:
    return;
}
