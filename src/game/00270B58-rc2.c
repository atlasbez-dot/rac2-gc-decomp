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

struct Out {
    f32 f0;
    f32 f4;
    f32 f8;
};

extern s32 func_00282CF0();
extern f32 func_00282DB0(s8 *, s8 *);
extern f32 func_00282DF0(s8 *);
extern s32 func_00282F20(s8 *, s8 *, f32);
extern f32 func_002831B0(f32);
extern s32 func_002ACEC0(s8 *, s8 *, s8 *, f32);

void func_00270B58(struct Out *arg0, s32 arg1, s32 arg2, s8 *arg3, s8 *arg4, s8 *arg5) {
    s32 sp[4];
    s32 sp10[4];
    s32 sp20[4];
    s32 sp30[4];
    s32 sp40[4];
    f32 temp_f22;
    f32 temp_f20;
    f32 var_f0;
    f32 var_f20;
    f32 temp_f20_2;
    f32 var_f0_2;
    f32 temp_f21;
    f32 var_f20_2;

    func_00282CF0(sp);
    temp_f22 = func_00282DB0(sp, arg5);
    func_00282F20(sp10, arg5, temp_f22);
    func_00282CF0(sp20, sp, sp10);
    temp_f20 = func_00282DB0(arg3, sp20);
    var_f0 = func_00282DF0(sp20);
    if (var_f0 == 0.0f) {
        var_f0 = 0.0001f;
    }
    var_f20 = 1.5707964f - func_002831B0(temp_f20 / var_f0);
    func_00282F20(sp30, sp20, 1.0f);
    if (func_00282DB0(arg4, sp30) < 0.0f) {
        var_f20 = -var_f20;
    }
    arg0->f0 = var_f20;
    func_002ACEC0(sp40, arg3, arg5, var_f20);
    temp_f20_2 = func_00282DB0(sp40, sp);
    var_f0_2 = func_00282DF0(sp);
    if (var_f0_2 == 0.0f) {
        var_f0_2 = 0.0001f;
    }
    temp_f21 = 1.5707964f - func_002831B0(temp_f20_2 / var_f0_2);
    func_00282F20(sp30, sp, 1.0f);
    var_f20_2 = -temp_f21;
    if (func_00282DB0(arg5, sp30) < 0.0f) {
        var_f20_2 = temp_f21;
    }
    arg0->f4 = var_f20_2;
    arg0->f8 = func_00282DF0(sp);
}
