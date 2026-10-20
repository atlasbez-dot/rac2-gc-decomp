
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

typedef int TI __attribute__((mode(TI)));
extern void ref_L00_003ECB38_00(void *, void *, void *);
extern void ref_L00_003ECB38_01(void *, s32, f32);
extern f32 ref_L00_003ECB38_02(void *, s32);
extern f32 ref_L00_003ECB38_03(void *);
extern f32 ref_L00_003ECB38_04(f32);
extern void ref_L00_003ECB38_05(void *, f32, s32, s32, f32, f32, f32);
extern s8 D_00189E20[];

void func_L00_003ECB38(s8 *arg0, void *arg1, s32 arg2, f32 fparg0, f32 fparg1, f32 fparg2)
{
    TI vec[2];
    s8 *base;
    s8 *vp;
    f32 f0a;
    f32 temp_f20;
    f32 temp_f0;
    f32 var_f20;

    ref_L00_003ECB38_00(vec, arg1, arg0 + 0x10);
    base = D_00189E20;
    f0a = ref_L00_003ECB38_02(vec, *(s32 *)(base + 0x2290) + 0xE0);
    vp = (s8 *)vec + 0x10;
    ref_L00_003ECB38_01(vp, *(s32 *)(base + 0x2290) + 0xE0, f0a);
    ref_L00_003ECB38_00(vec, vec, vp);
    temp_f20 = ref_L00_003ECB38_02(vec, *(s32 *)(base + 0x2290) + 0xC0);
    temp_f0 = ref_L00_003ECB38_03(vec);
    if (temp_f0 != 0.0f) {
        var_f20 = 1.5707964f - ref_L00_003ECB38_04(temp_f20 / temp_f0);
        if (ref_L00_003ECB38_02(vec, *(s32 *)(base + 0x2290) + 0xD0) < 0.0f) {
            var_f20 = -var_f20;
        }
        ref_L00_003ECB38_05(arg0 + 0xF8, var_f20, arg2, 0, fparg0, fparg1, fparg2);
    }
}
