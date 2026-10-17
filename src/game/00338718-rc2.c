
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

extern s32 func_00115DA8();
extern s32 func_00288FB8();
extern s32 func_00337E30(s32, s32, s32, f32, f32);

void func_00338718(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 var_f12;
    f32 var_f13;
    s32 temp_v0;
    s32 var_a0;
    s32 var_a1;
    s32 var_a2;
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;
    s32 var_s3;
    s32 var_v0;

    var_v0 = ~arg3;
    var_s0 = arg0;
    var_s0 += 0x1D6C;
    var_s2 = 0x78;
    var_s2 = (var_v0 != 0) ? arg3 : 0x78;
    var_a0 = arg1;
    var_s3 = arg2;
    var_s1 = arg0 + 0x1E14;
    temp_v0 = func_00288FB8(var_a0);
    var_a0 = var_s1;
    var_a2 = var_s3;
    var_a1 = temp_v0;
    func_00115DA8(var_a0, var_a1, var_a2);
    var_f12 = 255.0f;
    var_a0 = var_s0;
    var_f13 = 135.0f;
    var_a2 = var_s2;
    var_a1 = 1;
    func_00337E30(var_a0, 1, var_a2, 255.0f, 135.0f);
}
