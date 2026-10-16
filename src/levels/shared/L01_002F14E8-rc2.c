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

extern void ref_L01_002F14E8_00(s8 *, s8 *, s32);
extern s8 ref_L01_002F14E8_01[];
extern s8 ref_L01_002F14E8_02[];
extern s32 ref_L01_002F14E8_03 __attribute__((sda));
extern f32 ref_L01_002F14E8_04 __attribute__((sda));
extern s32 ref_L01_002F14E8_05 __attribute__((sda));
extern s32 ref_L01_002F14E8_06 __attribute__((sda));

void func_L01_002F14E8(s32 arg0, s32 arg1, f32 fparg0) {
    f32 var_f0;

    if (ref_L01_002F14E8_03 == 0) {
        ref_L01_002F14E8_00(ref_L01_002F14E8_01, ref_L01_002F14E8_02, 0);
    }
    var_f0 = 1.0f;
    ref_L01_002F14E8_03 = 5;
    ref_L01_002F14E8_04 = fparg0;
    if ((fparg0 > 1.0f) || (var_f0 = 0.0f, (fparg0 < 0.0f))) {
        ref_L01_002F14E8_04 = var_f0;
    }
    ref_L01_002F14E8_06 = arg1;
    ref_L01_002F14E8_05 = arg0;
}
