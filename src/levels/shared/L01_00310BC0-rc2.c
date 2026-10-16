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

f32 ref_L01_00310BC0_00(f32);
s32 ref_L01_00310BC0_01(f32, f32);
f32 ref_L01_00310BC0_02(f32, f32);

void func_L01_00310BC0(f32 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4) {
    f32 temp_f0;
    f32 temp_f0_2;

    f32 temp_f16 ;
    f32 temp_f3;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f1;

    temp_f0 = ref_L01_00310BC0_02(fparg1, fparg0);
    var_f1 = 1.0f;
    var_f0 = temp_f0 * 6.366197f;
    if ((var_f0 > 1.0f) || (var_f1 = -1.0f, (var_f0 < -1.0f))) {
        var_f0 = var_f1;
    }
    temp_f3 = *arg0;
    temp_f0_2 = temp_f3 + ((fparg2 * var_f0) - (fparg3 * temp_f3));
    *arg0 = temp_f0_2;
    if (fparg4 != 0.0f) {
        if (fparg4 < temp_f0_2) {
            *arg0 = fparg4;
        } else {
            temp_f16 = -fparg4;
            if (temp_f0_2 < temp_f16) {
                *arg0 = temp_f16;
            }
        }
    }
    if (ref_L01_00310BC0_00(temp_f0) < *arg0) {
        var_f0_2 = ref_L01_00310BC0_00(temp_f0);
        goto block_14;
    }
    if (*arg0 < -ref_L01_00310BC0_00(temp_f0)) {
        var_f0_2 = -ref_L01_00310BC0_00(temp_f0);
block_14:
        *arg0 = var_f0_2;
    }
    ref_L01_00310BC0_01(fparg0, *arg0);
}
